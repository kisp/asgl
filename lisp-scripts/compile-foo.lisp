;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

(require 'cmp)

(setq *debugger-hook* (lambda (c old) (format t "ERROR: ~A~%" c) (ext:quit 1)))

(setq c::*delete-files* nil)

(let ((c::*ld-bundle-flags*
        (format nil "~A -L~A -lfoo -lgecodesearch -lgecodeint -lgecodekernel -lgecodesupport -lgecodegist"
                c::*ld-bundle-flags*
                *default-pathname-defaults*)))
  ;; (delete-file "foo.fas")
  (compile-file "hello.lisp" :system-p t)
  (unless (probe-file "hello.o")
    (error "hello.o does not exist")))

(ext:quit)
