;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

;;; ASGL an abstract argumentation solver in ECL and GECODE.
;;; Copyright (C) 2015  Kilian Sprotte

;;; This program is free software: you can redistribute it and/or modify
;;; it under the terms of the GNU General Public License as published by
;;; the Free Software Foundation, either version 3 of the License, or
;;; (at your option) any later version.

;;; This program is distributed in the hope that it will be useful,
;;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;; GNU General Public License for more details.

;;; You should have received a copy of the GNU General Public License
;;; along with this program.  If not, see <http://www.gnu.org/licenses/>.

(defpackage :af-constraints
  (:use :cl :early :alexandria :gecode)
  (:export
   #:with-post-env-setup
   #:with-local-post-env
   #:constrain-complete
   #:constrain-stable))

(in-package :af-constraints)

#+nil(declaim (optimize (debug 3) (safety 3) (speed 0)))
(declaim (optimize (debug 0) (safety 1) (speed 3) (space 0)))

(cover:annotate t)

(defvar *space*)
(defvar *vars-vector*)
(defvar *nand-table*)
(defvar *expr-or-table*)
(defvar *imp-or-table*)

(defmacro sortf2 (a b)
  `(unless (< ,a ,b)
     (rotatef ,a ,b)))

(defun safe-sort (list)
  (check-type list list)
  (sort (copy-list list) #'<))

(defun constrain-conflict-free (graph constrain-nand)
  (check-type graph graph)
  (check-type constrain-nand function)
  (with-timing
      (do-edges (from to graph)
        (funcall constrain-nand from to))))

(defun constrain-in-eqv-acceptable (graph
                                    post-must-be-false
                                    post-must-be-true
                                    post-eql-indices
                                    post-eql-vars
                                    expr-and-vars
                                    expr-or
                                    var)
  (check-type graph graph)
  (check-type post-must-be-false function)
  (check-type post-must-be-true function)
  (check-type post-eql-indices function)
  (check-type post-eql-vars function)
  (check-type expr-and-vars function)
  (check-type expr-or function)
  (check-type var function)
  (with-timing
      (do-parents-grandparents (node pg graph)
        (cond
          ((equal `((,node ,node)) pg)
           (funcall post-must-be-false node))
          ((null pg)
           (funcall post-must-be-true node))
          ((some #'null (mapcar #'cdr pg))
           (funcall post-must-be-false node))
          ((and (eql 1 (length pg))
                (eql 1 (length (cdr (first pg)))))
           (funcall post-eql-indices node (second (first pg))))
          ((eql 1 (length pg))
           (destructuring-bind ((parent . grandparents)) pg
             (declare (ignore parent))
             (funcall post-eql-vars
                      (funcall expr-or grandparents)
                      (funcall var node))))
          (t
           (funcall post-eql-vars
                    (funcall expr-and-vars
                             (mapcar expr-or (mapcar #'cdr pg)))
                    (funcall var node)))))))

;;; API
(defmacro with-post-env-setup ((space) &body body)
  (once-only
   (space)
   `(let ((*space* ,space)
          (*vars-vector* (coerce (space-vars-as-list ,space) 'vector))
          (*nand-table* (make-hash-table :test #'equal))
          (*expr-or-table* (make-hash-table :test #'equal))
          (*imp-or-table* (make-hash-table :test #'equal)))
      ,@body)))

(defmacro with-local-post-env (() &body body)
  `(let ((space *space*)
         (vars-vector *vars-vector*)
         (nand-table *nand-table*)
         (expr-or-table *expr-or-table*)
         (imp-or-table *imp-or-table*))
     (macrolet ((%%var%% (i) `(aref vars-vector ,i)))
       (labels ((!!var!! (i) (%%var%% i))
                (!!post-nand!! (a b)
                  (sortf2 a b)
                  (let ((key (list a b)))
                    (unless (gethash key nand-table)
                      (log* 3 "NAND ~D ~D" a b)
                      (post-nand space a b)
                      (setf (gethash key nand-table) t))))
                (!!expr-or!! (indices)
                  (if (eql 1 (length indices))
                      (%%var%% (first indices))
                      (let ((key (safe-sort indices)))
                        (or (gethash key expr-or-table)
                            (progn
                              (log* 3 "EXPR-OR ~D ~A" (length key) key)
                              (setf (gethash key expr-or-table)
                                    (expr-or space
                                             (mapcar #'!!var!! indices))))))))
                (!!expr-and-vars!! (vars)
                  (log* 3 "EXPR-AND-VARS ~D ..." (length vars))
                  (expr-and space vars))
                (!!imp-or!! (index indices)
                  (let ((key (cons index (safe-sort indices))))
                    (unless (gethash key imp-or-table)
                      (assert-imp space (%%var%% index) (!!expr-or!! indices))
                      (setf (gethash key imp-or-table) t)))))
         ,@body))))

(defun constrain-complete (graph)
  (check-type graph graph)
  (with-local-post-env ()
    (constrain-conflict-free graph #'!!post-nand!!)
    #+nil
    (constrain-not-attacked-are-in
     graph (lambda (node) (post-must-be-true space node)))
    (flet ((post-must-be-false (node)
             (post-must-be-false space node))
           (post-must-be-true (node)
             (post-must-be-true space node))
           (post-eql-indices (a b)
             (boolvar-post-eql
              space
              (!!var!! a)
              (!!var!! b)))
           (post-eql-vars (a b)
             (boolvar-post-eql space a b)))
      (constrain-in-eqv-acceptable
       graph
       #'post-must-be-false
       #'post-must-be-true
       #'post-eql-indices
       #'post-eql-vars
       #'!!expr-and-vars!!
       #'!!expr-or!!
       #'!!var!!))))

(defun constrain-stable (graph)
  (check-type graph graph)
  (with-local-post-env ()
    (with-timing
        (do-parents (node parents graph)
          (when parents
            (assert-imp
             space
             (expr-not space (!!var!! node))
             (!!expr-or!! parents)))))))

(cover:annotate nil)
