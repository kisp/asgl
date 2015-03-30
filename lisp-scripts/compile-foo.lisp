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

(require 'cmp)

(setq *debugger-hook* (lambda (c old) (format t "ERROR: ~A~%" c) (ext:quit 1)))

(setq c::*delete-files* nil)

(load "lisp-scripts/compile-file-system-p.lisp")

(let ((c::*ld-bundle-flags*
       (format nil "~A -L~A -lfoo -lgecodesearch -lgecodeint -lgecodeset -lgecodeminimodel -lgecodekernel -lgecodesupport -lgecodegist"
               c::*ld-bundle-flags*
               *default-pathname-defaults*)))
  (compile-file-system-p "v1/v1.lisp"))

(ext:quit)
