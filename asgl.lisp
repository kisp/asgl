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

(defpackage :asgl
  (:use :cl :early :alexandria :gecode))

(in-package :asgl)

(defun cl-user::main ()
  (setq *debugger-hook* (lambda (c old)
                          (declare (ignore old))
                          (let ((*print-length* 3)
                                (*print-level* 3))
                            (ext:dump-c-backtrace 32)
                            (terpri *error-output*)
                            (print-error-log *error-output* c)
                            (format t "ERROR: ~A~%" c)
                            (ext:quit 1))))
  (setq *package* (find-package :asgl))
  (ext:install-bytecodes-compiler)
  (let ((*error-output* (make-broadcast-stream))
        (*standard-output* (make-broadcast-stream))
        (*trace-output* (make-broadcast-stream))
        (*terminal-io* (make-broadcast-stream))
        (*debug-io* (make-broadcast-stream))
        (*query-io* (make-broadcast-stream)))
    (load "/home/paul/unis/github/asgl/foo.lisp"))
  #+cover
  (when (probe-file *cover-file*)
    (cover:load-points *cover-file*))
  (unwind-protect
       (cond
         ((null (cdr ext:*command-args*))
          (print-informational-message))
         ((equal "--formats" (second ext:*command-args*))
          (print-supported-graph-formats))
         ((equal "--problems" (second ext:*command-args*))
          (print-supported-problems))
         ((equal "--strategies" (second ext:*command-args*))
          (describe-all-strategies-or-for-problem
           (third ext:*command-args*)))
         #+cover
         ((equal "--cover-report" (second ext:*command-args*))
          (cover:report :out *standard-output*
                        :all (find "--all" (cdr ext:*command-args*)
                                   :test #'equal))
          (terpri *standard-output*))
         ((equal "--repl" (second ext:*command-args*))
          (run-repl))
         ((equal "--check" (second ext:*command-args*))
          (run-self-check (cddr ext:*command-args*)))
         (t (apply #'main% (adopt-keywords (cdr ext:*command-args*)))))
    #+cover
    (cover:save-points *cover-file*)))

