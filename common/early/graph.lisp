;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(in-package #:early)

(declaim (optimize (debug 3) (safety 3) (speed 0)))

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

(defvar *collect-parents-cache* nil)

;;; primitives
(defun %%order (graph)
  (length graph))

(defun %%parents (graph node)
  (aref graph node))

(defun (setf %%parents) (value graph node)
  (setf (aref graph node) value))

(defmacro do-%%parents ((node parents &optional return)
                        &body body)
  `(dolist (,node ,parents ,return)
     ,@body body))

(defun %%parents-add (node parents)
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
  (setq *collect-parents-cache* nil))

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
(defun map-nodes (fn graph)
  (dotimes (node (order graph))
    (funcall fn node)))

(defmacro do-nodes ((node graph) &body body)
  `(map-nodes (lambda (,node) ,@body) ,graph))

(defun map-edges (fn graph)
  (dotimes (i (%%order graph))
    (do-%%parents (j (%%parents graph i))
      (funcall fn j i))))

(defun %collect-parents% (graph node)
  (let (result)
    (map-edges (lambda (from to)
                 (when (eql to node)
                   (push from result)))
               graph)
    (nreverse result)))

(defun collect-parents (graph node)
  (when (null *collect-parents-cache*)
    (setq *collect-parents-cache*
          (cons graph (make-hash-table))))
  (assert (eq graph (car *collect-parents-cache*)))
  (aif (gethash node (cdr *collect-parents-cache*))
       (cdr it)
       (let ((parents (%collect-parents% graph node)))
         (setf (gethash node (cdr *collect-parents-cache*))
               (cons t parents))
         parents)))

(defun map-parents (fn graph)
  "Call FN with node and list of parents."
  (do-nodes (node graph)
    (funcall fn node (collect-parents graph node))))

(defun map-parents-grandparents (fn graph)
  "Call FN with node and list of grandparents."
  (do-parents (node parents graph)
    (funcall fn node
             (mapcar #'cons
                     parents
                     (mapcar (lambda (parent) (collect-parents graph parent)) parents)))))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
