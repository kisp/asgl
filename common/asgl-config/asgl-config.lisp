;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(defpackage #:asgl-config
  (:use #:cl))

(in-package #:asgl-config)

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

(defun ENABLE-COVER ()
  (zerop
   (ffi:c-inline () () :int
                 "{
int res;
#ifdef ENABLE_COVER
res = 0;
#else
res = 1;
#endif
@(return 0) = res;
}")))

(when (ENABLE-COVER)
  (push :cover *features*))

(defun ENABLE-TIMING ()
  (zerop
   (ffi:c-inline () () :int
                 "{
int res;
#ifdef ENABLE_TIMING
res = 0;
#else
res = 1;
#endif
@(return 0) = res;
}")))

(when (ENABLE-TIMING)
  (push :timing *features*))

(defun ENABLE-LOGGING ()
  (zerop
   (ffi:c-inline () () :int
                 "{
int res;
#ifdef ENABLE_LOGGING
res = 0;
#else
res = 1;
#endif
@(return 0) = res;
}")))

(when (ENABLE-LOGGING)
  (push :logging *features*))
