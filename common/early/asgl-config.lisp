;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(in-package #:early)

(ffi:clines "#include \"../../asgl_config.h\"")

(defun HAVE-GECODE-GIST-HH ()
  (zerop
   (ffi:c-inline () () :int
                 "{
int res;
#ifdef HAVE_GECODE_GIST_HH
res = 0;
#else
res = 1;
#endif
@(return 0) = res;
}")))

(when (HAVE-GECODE-GIST-HH)
  (push :gist *features*))
