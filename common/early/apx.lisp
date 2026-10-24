;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

;;; ASGL an abstract argumentation solver in ECL and GECODE.
;;; Copyright (C) 2015-2026  Kilian Sprotte

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

(ffi:clines "#include \"ragel_apx_parse.h\"")

(in-package #:early)

#+nil(declaim (optimize (debug 3) (safety 3) (speed 0)))
(declaim (optimize (debug 0) (safety 1) (speed 3) (space 0)))

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

#+nil
(defun vector2hash-table (vector)
  (let ((hash (make-hash-table :test #'eql)))
    (dotimes (i (length vector)
              hash)
      (setf (gethash (aref vector i) hash) i))))

(defun hash-table2vector (hash vector)
  (loop for k being the hash-keys in hash using (hash-value v)
     do (setf (aref vector v) k)))

(defmacro with-apx-readtable (() &body body)
  `(let ((*readtable* (copy-readtable nil)))
     (set-macro-character #\, (lambda (stream char) (values)))
     ,@body))

#+nil
(defun read-apx-line (string)
  (with-input-from-string (input string)
    (read input)
    (read input)))

(define-condition apx-error (simple-error) ()
  (:documentation "Text that is apx in its syntax, but not a framework."))

(defun read-apx-file (pathname)
  (unless (probe-file pathname)
    (error "file ~S does not exist" pathname))
  (let ()
    (multiple-value-bind (buffer size)
        (ffi:c-inline
         ((coerce (namestring (merge-pathnames pathname)) 'base-string))
         (:object) (values :pointer-void :long)
         "{
long msize = 99;

@(return 0) = slurp_file(#0, &msize);
@(return 1) = msize;
}")
      ;; count_args checks the syntax; its count is the number of arg(...)
      ;; statements, not of names, so the sizes come from the parse
      (ffi:c-inline (buffer size) (:pointer-void :long) :int
                    "{ @(return 0) = count_args((char*)#0, #1); }")
      (let ((hash (make-hash-table :test #'equal))
            (declared (make-hash-table :test #'equal))
            (edges '()))
        (ffi:c-inline (buffer size hash declared
                              (lambda (from to)
                                (push (cons from to) edges)))
                      (:pointer-void :long :object :object :object)
                      :void
                      "{ ragel_apx_parse((char*)#0, #1, #2, #3, #4); }")
        (let ((undeclared (sort (loop for name being the hash-keys in hash
                                      unless (gethash name declared)
                                        collect name)
                                #'< :key (lambda (name) (gethash name hash)))))
          (when undeclared
            (error 'apx-error
                   :format-control "an attack names ~{~A~^, ~}, which no arg(...) declares"
                   :format-arguments (list undeclared))))
        (let* ((count (hash-table-count hash))
               (vector (make-array count))
               ;; TODO use graph api
               (graph (make-array count :initial-element nil)))
          (dolist (edge (nreverse edges))
            (add-edge graph (car edge) (cdr edge)))
          (hash-table2vector hash vector)
          (values graph vector hash)))))
  #+nil
  (let ((table (make-hash-table :test #'equal)))
    (time
     (ffi:c-inline
      ((coerce (namestring (merge-pathnames pathname)) 'base-string)
       table)
      (:object :object) :void "{ ragel_apx_parse(#0,#1); }"))
    #+nil(describe table)
    #+nil(format t "here are all the keys:~%")
    #+nil(loop for key being the hash-keys of table
            do (format t "~S~%" key))
    (format t "the table count is ~S~%"
            (hash-table-count table))
    #+nil(assert (not (zerop (hash-table-count table)))))
  #+nil
  (let (nodes edges)
    (with-apx-readtable ()
      (with-open-file (input pathname)
        (loop for line = (read-line input nil)
           while line
           do (let ((item (read-apx-line line)))
                (if (null (cdr item))
                    (push (first item) nodes)
                    (push item edges))))))
    (let* ((vector (coerce (nreverse nodes) 'vector))
           (adj (make-array (list (length vector) (length vector))
                            :initial-element 0))
           (hash (vector2hash-table vector)))
      (dolist (edge edges)
        (destructuring-bind (a b) edge
          (setf (aref adj (gethash a hash) (gethash b hash))
                1)))
      (values
       adj
       vector
       hash))))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
