;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(in-package #:early)

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

;;; from cl-fad
(defun component-present-p (value)
  "Helper function for DIRECTORY-PATHNAME-P which checks whether VALUE
   is neither NIL nor the keyword :UNSPECIFIC."
  (and value (not (eql value :unspecific))))

(defun directory-pathname-p (pathspec)
  "Returns NIL if PATHSPEC \(a pathname designator) does not designate
a directory, PATHSPEC otherwise.  It is irrelevant whether file or
directory designated by PATHSPEC does actually exist."
  (and
   (not (component-present-p (pathname-name pathspec)))
   (not (component-present-p (pathname-type pathspec)))
   pathspec))

;;; config
(defun asgl-home ()
  (let ((var (ext:getenv "ASGL_HOME")))
    (unless var
      (error "ASGL_HOME is not set"))
    (let ((home (probe-file var)))
      (unless (and home (directory-pathname-p home))
        (error "ASGL_HOME does not point to an existing directory: ~S"
               (ext:getenv "ASGL_HOME")))
      home)))

;;; general
(defmacro aif (test then &optional else)
  `(let ((it ,test))
     (if it ,then ,else)))

;;; timing
(defvar *with-timing* nil)

(defun call-with-timing (form thunk)
  (if (not *with-timing*)
      (funcall thunk)
      (let ((*print-length* 3)
            (*print-level* 2))
        (format *trace-output* "~&Calling ~S..." form)
        (force-output *trace-output*)
        (let ((ok)
              (start (get-internal-real-time)))
          (unwind-protect
               (multiple-value-prog1
                   (funcall thunk)
                 (let ((end (get-internal-real-time)))
                   (setq ok t)
                   (format *trace-output*
                           "done (~5,3F s)~%"
                           (/ (- end start)
                              internal-time-units-per-second))))
            (unless ok
              (format *trace-output* " (aborted by a non-local toc)~%")))))))

(defmacro with-timing (form)
  `(call-with-timing ',form (lambda () ,form)))

;;; logging
(defvar *with-logging* nil)

(defmacro format* (&rest args)
  `(when *with-logging* (format ,@args)))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
