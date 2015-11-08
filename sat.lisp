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

(defpackage :sat
  (:use :cl :alexandria)
  (:export
   #:with-solver
   #:with-added-clause
   #:add-literals
   #:satisfiablep
   #:unsatisfiablep
   #:save-solution))

(in-package :sat)

#+nil(declaim (optimize (debug 3) (safety 3) (speed 0)))
(declaim (optimize (debug 0) (safety 1) (speed 3) (space 0)))

(ffi:clines "extern \"C\" {
  #include \"lingeling/code/lglib.h\"
}")

(cover:annotate t)

(defun lglinit ()
  (ffi:c-inline () () :pointer-void"lglinit()" :one-liner t))

(defun lglclone (lgl)
  (ffi:c-inline (lgl) (:pointer-void) :pointer-void "lglclone((LGL*)#0)" :one-liner t))

(defun lglsat (lgl)
  (let ((code (ffi:c-inline (lgl) (:pointer-void) :int
                            "lglsat((LGL*)#0)" :one-liner t)))
    (case code
      (10 t)
      (20 nil)
      (t (error "lglsat returned ~S" code)))))

(declaim (inline lgladd-positive lgladd-negative))
(defun lgladd-positive (lgl lit)
  (ffi:c-inline (lgl lit) (:pointer-void :int) :void
                "lgladd((LGL*)#0,#1+1)" :one-liner t))

(defun lgladd-negative (lgl lit)
  (ffi:c-inline (lgl lit) (:pointer-void :int) :void
                "lgladd((LGL*)#0,-(#1+1))" :one-liner t))

(defun lglclause-end (lgl)
  (ffi:c-inline (lgl) (:pointer-void) :void
                "lgladd((LGL*)#0,0)" :one-liner t))

(declaim (inline lglfreeze))
(defun lglfreeze (lgl lit)
  (ffi:c-inline (lgl lit) (:pointer-void :int) :void
                "lglfreeze((LGL*)#0,#1+1)" :one-liner t))

(declaim (inline lglderef))
(defun lglderef (lgl lit)
  (ffi:c-inline (lgl lit) (:pointer-void :int) :bool
                "lglderef((LGL*)#0,#1+1) > 0" :one-liner t))

(defun lglrelease (lgl)
  (ffi:c-inline (lgl) (:pointer-void) :void "lglrelease((LGL*)#0)" :one-liner t))

(defmacro with-solver ((solver) &body body)
  `(let ((,solver (lglinit)))
     (unwind-protect
          (progn ,@body)
       (lglrelease ,solver))))

(defmacro with-added-clause ((solver) &body body)
  `(multiple-value-prog1
       (progn ,@body)
     (lglclause-end ,solver)))

(defmacro add-literals (solver &rest args)
  (let (state positive negative)
    (labels ((process-arg (arg)
               (case arg
                 ((:positive :negative)
                  (setq state arg))
                 (t
                  (assert state)
                  (case state
                    (:positive (push arg positive))
                    (:negative (push arg negative)))))))
      (mapc #'process-arg args)
      `(progn
         ,@(mapcar (lambda (x) `(lgladd-positive ,solver ,x)) positive)
         ,@(mapcar (lambda (x) `(lgladd-negative ,solver ,x)) negative)
         nil))))

(defun satisfiablep (solver)
  (lglsat solver))

(defun unsatisfiablep (solver)
  (not (lglsat solver)))

(defun save-solution (solver vector)
  (dotimes (i (length vector) vector)
    (setf (aref vector i)
          (lglderef solver i))))

(cover:annotate nil)
