;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

(require 'cmp)

(setq *debugger-hook* (lambda (c old) (format t "ERROR: ~A~%" c) (ext:quit 1)))

(setq c::*delete-files* nil)

(let ((c::*ld-bundle-flags*
       (format nil "~A -L~A -lfoo -lgecodesearch -lgecodeint -lgecodekernel -lgecodesupport -lgecodegist"
               c::*ld-bundle-flags*
               *default-pathname-defaults*)))
  (compile-file "v1/v1.lisp" :system-p t)
  (unless (probe-file "v1/v1.o")
    (error "v1/v1.o does not exist")))

(ext:quit)
