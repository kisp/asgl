;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(in-package #:early)

(declaim (optimize (debug 3) (safety 3) (speed 0)))

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
(defun clear-graph-caches ()
  )

(defun order (graph)
  (%%order graph))

(defmacro do-edges ((from to graph) &body body)
  `(map-edges (lambda (,from ,to) ,@body) ,graph))

(defmacro do-parents ((node parents graph) &body body)
  `(map-parents (lambda (,node ,parents) ,@body) ,graph))

(defmacro do-parents-grandparents ((node parents-grandparents graph) &body body)
  `(map-parents-grandparents (lambda (,node ,parents-grandparents) ,@body) ,graph))

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
