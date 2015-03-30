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
