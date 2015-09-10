;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

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

(in-package #:early)

#+nil(declaim (optimize (debug 3) (safety 3) (speed 0)))
(declaim (optimize (debug 0) (safety 1) (speed 3) (space 0)))

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

(defgeneric read-graph-input (input))

(defmethod read-graph-input ((input pathname))
  (read-apx-file input))

(defmethod read-graph-input ((input string))
  (read-apx-file input))

(defmethod read-graph-input ((input vector))
  (let* ((graph input)
         (items (loop for i below (order graph) collect i)))
    (values graph
            (make-array (order graph) :initial-contents items)
            (let ((hash (make-hash-table)))
              (dolist (item items)
                (setf (gethash item hash) item))
              hash))))

(defun cons2vector (cons)
  (destructuring-bind (order . integer) cons
    (let* ((length (* order order))
           (array (make-array length :element-type 'bit)))
      (dotimes (i length)
        (setf (aref array (- (1- length) i))
              (if (logbitp i integer) 1 0)))
      array)))

(defmethod read-graph-input ((input cons))
  (let ((order (car input)))
    (read-graph-input
     (make-graph-from-adj
      (make-array (list order order)
                  :displaced-to (cons2vector input)
                  :element-type 'bit)))))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
