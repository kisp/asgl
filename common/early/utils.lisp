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
  (let ((var (or (ext:getenv "ASGL_HOME")
                 #.(ext:getenv "ASGL_HOME_PREC"))))
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
(defvar *with-timing* #+timing t #-timing nil)

#+timing
(defvar *timing-stack* (list nil))

#+timing
(defun call-with-timing (form thunk)
  (labels ((spaces (x)
             (make-string (* 2 x) :initial-element #\space))
           (prepare-result-output (level timing-stack)
             (when (car timing-stack)
               (format *error-output* "~&~A<~D " (spaces level) level))))
    (if (not *with-timing*)
        (funcall thunk)
        (progn
          ;; whatever happens, let the others below in the call stack
          ;; know that call-with-timing was attempted
          (setf (car *timing-stack*) t)
          (let ((*print-length* 3)
                (*print-level* 2)
                (level (1- (length *timing-stack*))))
            (format *error-output* "~&~A~D> Calling ~S " (spaces level) level form)
            (force-output *error-output*)
            (let ((ok)
                  (*timing-stack* (cons nil *timing-stack*))
                  (start (get-internal-real-time)))
              (unwind-protect
                   (multiple-value-prog1
                       (funcall thunk)
                     (let ((end (get-internal-real-time)))
                       (setq ok t)
                       (prepare-result-output level *timing-stack*)
                       (format *error-output*
                               "done (~5,3F s)~%"
                               (/ (- end start)
                                  internal-time-units-per-second))))
                (unless ok
                  (prepare-result-output level *timing-stack*)
                  (format *error-output* " (aborted by a non-local toc)~%")))))))))

(defmacro with-timing (form)
  #+timing
  `(call-with-timing ',form (lambda () ,form))
  #-timing
  form)

;;; logging
(defvar *with-logging* #+logging t #-logging nil)

(defmacro log* (&rest args)
  #+logging
  `(when *with-logging*
     (fresh-line *error-output*)
     (write-string "[log] " *error-output*)
     (format *error-output* ,@args)
     (terpri *error-output*)
     nil)
  #-logging
  nil)

;;; backtrace
(defun print-error-log (eout e)
  (format eout "Unhandled error detected: ~%")
  (format eout "~A~%" e)
  (format eout "Backtrace: ~%")
  (loop for x from (- (si::ihs-top) 2) downto 1
     do
       (format eout "~A~%" (si::ihs-fun x))
       (format eout " Args:~%")
       (let ((env (si::decode-ihs-env (si::ihs-env x))))
         (dolist (ip env)
           (format eout "      ~A= ~A~%" (car ip) (cdr ip))))
       (format eout "~%"))
  (format eout "~%"))

;;; compile-file-if-needed
(defun requires-compile-p (source-file)
  (labels ((file-newer-p (new-file old-file)
             (> (file-write-date new-file)
                (file-write-date old-file))))
    (let ((fasl-file (probe-file (compile-file-pathname source-file))))
      (or (not fasl-file)
          (file-newer-p source-file fasl-file)))))

(defun compile-file-if-needed (filename loadp)
  (when (requires-compile-p filename)
    (compile-file filename))
  (when loadp
    (load (compile-file-pathname filename)))
  (compile-file-pathname filename))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
