;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(in-package #:early)

(defun vector2hash-table (vector)
  (let ((hash (make-hash-table :test #'eql)))
    (dotimes (i (length vector)
                hash)
      (setf (gethash (aref vector i) hash) i))))

(defmacro with-apx-readtable (() &body body)
  `(let ((*readtable* (copy-readtable nil)))
     (set-macro-character #\, (lambda (stream char) (values)))
     ,@body))

(defun read-apx-line (string)
  (with-input-from-string (input string)
    (read input)
    (read input)))

(defun read-apx-file (pathname)
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
