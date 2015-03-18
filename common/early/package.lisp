;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(defpackage #:early
  (:use #:cl)
  (:export #:with-timing #:format* #:aif #:it)
  ;; graph
  (:export #:clear-graph-caches
           #:order
           #:nodes
           #:do-nodes #:do-edges
           #:do-parents #:do-grandparents #:do-parents-grandparents
           #:map-triangles #:do-triangles)
  ;; apx
  (:export #:read-apx-file))