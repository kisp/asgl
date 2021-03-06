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

;;; primitives
(deftype %%graph () 'simple-array)
(deftype %%node () 'fixnum)

(declaim (inline %%order %%parents (setf %%parents) %%parents-add))

(cl:defun %%order (graph)
  (declare (type %%graph graph))
  (length graph))

(cl:defun %%parents (graph node)
  (declare (type %%graph graph)
           (type %%node node))
  (aref graph node))

(cl:defun (setf %%parents) (value graph node)
  (declare (type %%graph graph)
           (type %%node node))
  (setf (aref graph node) value))

(defmacro do-%%parents ((node parents &optional return)
                        &body body)
  `(dolist (,node ,parents ,return)
     ,@body body))

(cl:defun %%parents-add (node parents)
  (declare (type %%node node))
  (cons node parents))

(defmacro %%push-parents (obj place &environment env)
  (multiple-value-bind (dummies vals newval setter getter)
      (get-setf-expansion place env)
    (let ((g (gensym)))
      `(let* ((,g ,obj)
              ,@(mapcar #'list dummies vals)
              (,(car newval) (%%parents-add ,g ,getter))
              ,@(cdr newval))
         ,setter))))

;;; api
(deftype graph () 'simple-array)

(defun order (graph)
  (%%order graph))

(defun size (graph)
  (reduce #'+ graph :key #'length))

(defun indegrees (graph)
  (map 'vector #'length graph))

(defmacro do-edges ((from to graph) &body body)
  `(map-edges (lambda (,from ,to) ,@body) ,graph))

(defmacro do-parents ((node parents graph) &body body)
  `(map-parents (lambda (,node ,parents) ,@body) ,graph))

(defmacro do-parents-grandparents ((node parents-grandparents graph) &body body)
  `(map-parents-grandparents (lambda (,node ,parents-grandparents) ,@body) ,graph))

(defun outdegrees (graph)
  (let ((vector (make-array (order graph) :initial-element 0)))
    (do-edges (from to graph)
      (declare (ignore to))
      (incf (aref vector from)))
    vector))

(defun add-edge (graph from to)
  (%%push-parents from (%%parents graph to)))

(defun make-graph-from-adj (adj)
  (let* ((order (array-dimension adj 0))
         (graph (make-array order)))
    (dotimes (i order)
      (dotimes (j order)
        (when (eql 1 (aref adj i j))
          (add-edge graph i j))))
    graph))

;;; support
(cl:defun map-nodes (fn graph)
  (declare (optimize speed (safety 0) (debug 0)))
  (dotimes (node (%%order graph))
    (funcall fn node)))

(defmacro do-nodes ((node graph) &body body)
  `(map-nodes (lambda (,node) ,@body) ,graph))

(cl:defun map-edges (fn graph)
  (declare (optimize speed (safety 0) (debug 0)))
  (dotimes (i (%%order graph))
    (do-%%parents (j (%%parents graph i))
      (funcall fn j i))))

(defun map-parents (fn graph)
  "Call FN with node and list of parents."
  (do-nodes (node graph)
    (funcall fn node (%%parents graph node))))

(defun map-parents-grandparents (fn graph)
  "Call FN with node and list of grandparents."
  (do-parents (node parents graph)
    (funcall fn node
             (mapcar #'cons
                     parents
                     (mapcar (lambda (parent) (%%parents graph parent)) parents)))))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
