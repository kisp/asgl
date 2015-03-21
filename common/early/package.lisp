;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(defpackage #:early
  (:use #:cl)
  (:export #:with-timing #:format* #:aif #:it)
  ;; graph
  (:export
   #:clear-graph-caches
   #:order
   #:do-edges
   #:do-parents
   #:do-parents-grandparents
   )
  ;; apx
  (:export #:read-apx-file))
