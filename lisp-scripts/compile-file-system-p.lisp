;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

(in-package :cl-user)

(require 'cmp)

(defun compile-file-system-p (pathname)
  (let ((c::*delete-files* nil)
        (source pathname)
        (o-pathname (make-pathname :type "o" :defaults pathname)))
    (multiple-value-bind (fasl warnings-p failure-p)
        (compile-file source :system-p t)
      (declare (ignore fasl))
      (handler-case
          (progn
            (when warnings-p
              (error "warnings for compile-file ~A" source))
            (when failure-p
              (error "compile-file failed for ~A" source)))
        (error (c)
          (when (probe-file o-pathname)
            (delete-file o-pathname))
          (error c))))
    (unless (probe-file o-pathname)
      (error "~A does not exist" o-pathname))))
