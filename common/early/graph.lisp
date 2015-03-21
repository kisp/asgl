;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(in-package #:early)

(defvar *nodes-cache* nil)
(defvar *edges-cache* nil)
(defvar *collect-parents-cache* nil)

(defun clear-graph-caches ()
  (setq *nodes-cache* nil)
  (setq *edges-cache* nil)
  (setq *collect-parents-cache* nil))

(defun order (graph)
  (array-dimension graph 0))

(defun %nodes% (graph)
  (loop for i from 0 below (order graph)
     collect i))

(defun nodes (graph)
  (if *nodes-cache*
      (progn
        (assert (eq graph (car *nodes-cache*)))
        (cdr *nodes-cache*))
      (cdr (setq *nodes-cache* (cons graph (%nodes% graph))))))

(defun map-nodes (fn graph)
  (dolist (node (nodes graph))
    (funcall fn node)))

(defmacro do-nodes ((node graph) &body body)
  `(map-nodes (lambda (,node) ,@body) ,graph))

(defun %edges% (graph)
  (let (list)
    (dotimes (i (order graph) list)
      (dotimes (j (order graph))
        (when (eql 1 (aref graph i j))
          (push (list i j) list))))))

(defun edges (graph)
  (if *edges-cache*
      (progn
        (assert (eq graph (car *edges-cache*)))
        (cdr *edges-cache*))
      (cdr (setq *edges-cache* (cons graph (%edges% graph))))))

(defun map-edges (fn graph)
  (dolist (edge (edges graph))
    (funcall fn edge)))

(defmacro do-edges ((edge graph) &body body)
  `(map-edges (lambda (,edge) ,@body) ,graph))

(defun %collect-parents% (graph node)
  (let (result)
    (map-edges (lambda (edge)
                 (when (eql (second edge) node)
                   (push (first edge) result)))
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

(defun map-grandparents (fn graph)
  "Call FN with node and list of grandparents."
  (map-edges (lambda (edge)
               (funcall fn
                        (second edge)
                        (collect-parents graph (first edge))))
             graph))

(defmacro do-grandparents ((node grandparents graph) &body body)
  `(map-grandparents (lambda (,node ,grandparents) ,@body) ,graph))

(defun map-parents (fn graph)
  "Call FN with node and list of parents."
  (dolist (node (nodes graph))
    (funcall fn node (collect-parents graph node))))

(defmacro do-parents ((node parents graph) &body body)
  `(map-parents (lambda (,node ,parents) ,@body) ,graph))

(defun map-parents-grandparents (fn graph)
  "Call FN with node and list of grandparents."
  (do-parents (node parents graph)
    (funcall fn node
             (mapcar #'cons
                     parents
                     (mapcar (lambda (parent) (collect-parents graph parent)) parents)))))

(defmacro do-parents-grandparents ((node parents-grandparents graph) &body body)
  `(map-parents-grandparents (lambda (,node ,parents-grandparents) ,@body) ,graph))
