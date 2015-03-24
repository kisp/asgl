;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

(require 'cmp)

(setq *debugger-hook* (lambda (c old) (format t "ERROR: ~A~%" c) (ext:quit 1)))

(setq c::*delete-files* nil)

(load "lisp-scripts/compile-file-system-p.lisp")

(let ((c::*ld-bundle-flags*
        (format nil "~A -L~A -lfoo -lgecodesearch -lgecodeint -lgecodekernel -lgecodesupport -lgecodegist"
                c::*ld-bundle-flags*
                *default-pathname-defaults*)))
  (compile-file-system-p "v1/v1.lisp"))

(ext:quit)
