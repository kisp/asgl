#!/usr/local/bin/sbcl-wrap cl-jenny table-printer --

(in-package :cl-jenny)

;; (setq *debugger-hook* nil)
;; (setq sb-ext:*invoke-debugger-hook* nil)

(setq sb-ext:*invoke-debugger-hook*
      (lambda (c old)
        (declare (ignore old))
        (format *error-output* "ERROR: ~A~%" c)
        (sb-ext:exit :code 1)))
(setq *debugger-hook* sb-ext:*invoke-debugger-hook*)

(use-package :table-printer)

;;; just for printing
(defpackage :asgl (:use :cl))

(defun rule** (form) (eval `(rule* ,form)))

(defun shorten-symbol (symbol)
  (subseq (string symbol) 0 (min 15 (length (string symbol)))))

(defun imp (a b) (if a b t))
(defun eqv (a b) (and (imp a b) (imp b a)))

;;; domains
(defvar *domains* nil)

(defstruct domain name values)

(defun add-domain (name values)
  (setf *domains*
        (append *domains* (list (make-domain :name name :values values)))))

(defun list-domains ()
  (loop for domain in *domains*
        collect `(,(domain-name domain) ,@(domain-values domain))))

(defun domain-names ()
  (mapcar #'domain-name *domains*))

(defmacro define-domain (name values)
  `(add-domain ',name ',values))

;;; constraint

(defvar *constraints* nil)

(defmacro define-constraint (condition)
  `(push ',condition *constraints*))

(defun constraint-rules ()
  (mapcar #'rule** *constraints*))

;;; errors
(defvar *errors* nil)

(defstruct err name condition)

(defun add-error (name condition)
  (setf *errors*
        (append *errors*
                (list (make-err :name name :condition condition)))))

(defun error-names ()
  (mapcar #'err-name *errors*))

(defun condition-eqv-error-name-rule (err)
  (rule** `(eqv ,(err-condition err) (eql error ',(err-name err)))))

(defun condition-eqv-error-name-rules ()
  (mapcar #'condition-eqv-error-name-rule *errors*))

(defun errors-forbidden-rules ()
  (mapcar #'rule**
          (mapcar (lambda (x) `(not ,x))
                  (mapcar #'err-condition *errors*))))

(defmacro define-error (name condition)
  `(add-error ',name ',condition))

(define-domain task (xx ee se dc ds))
(define-domain semantic (yy co pr st gr))
(define-domain task-semantic-type (string symbol))
(define-domain graph-input-type (string pathname cons vector))
(define-domain arg-type (integer string null))
(define-domain arg-contained-in-graph (t nil no-arg))
(define-domain graph-input-file-exists (t nil no-file-input))

(defmacro with-domains-from-plist ((plist) &body body)
  `(let ,(mapcar (lambda (domain) `(,domain (getf ,plist ',domain)))
                 (domain-names))
     ,@body))

(define-constraint (eqv (member graph-input-type '(cons vector))
                        (eql graph-input-file-exists 'no-file-input)))

(define-constraint (eqv (eql arg-type 'null)
                        (eql arg-contained-in-graph 'no-arg)))

;;; bei file input kein integer
(define-constraint (imp (not (eql graph-input-file-exists 'no-file-input))
                        (not (eql arg-type 'integer))))
;;; bei kein file input kein string
(define-constraint (imp (eql graph-input-file-exists 'no-file-input)
                        (not (eql arg-type 'string))))
;;; bei string file input
(define-constraint (imp (eql arg-type 'string)
                        (not (eql graph-input-file-exists 'no-file-input))))
;;; bei integer kein file input
(define-constraint (imp (eql arg-type 'integer)
                        (eql graph-input-file-exists 'no-file-input)))

(define-error task-xx-error (eql task 'xx))
(define-error sem-yy-error (eql semantic 'yy))
(define-error arg-not-in-graph-error (eql arg-contained-in-graph nil))
(define-error non-existing-file-error (eql graph-input-file-exists nil))
(define-error enum-w/-arg-error (and (member task '(ee se))
                                     (not (eql arg-type 'null))))
(define-error decision-w/o-arg-error (and (member task '(dc ds))
                                          (eql arg-type 'null)))

(defvar *error-tests*
  (apply #'jenny-rules
         `(,@ (list-domains)
              (error ,@ (error-names)))
         1
         :plist
         (append (constraint-rules)
                 (condition-eqv-error-name-rules))))

(defvar *tests*
  (apply #'jenny-rules
         `(,@ (list-domains))
         2
         :plist
         (append (constraint-rules)
                 (errors-forbidden-rules))))


(write-line "(in-package :asgl)")
(write-line "(use-package :myam)")
(write-line "(in-suite :tests)")

(write-line "#|")
(princ-table
 (cons (append (mapcar #'shorten-symbol (domain-names)) (list 'error))
       (mapcar (lambda (x) (mapcar #'cdr (alexandria:plist-alist x))) *error-tests*)))
(write-line "|#")

(terpri)

(write-line "#|")
(princ-table
 (cons (append (mapcar #'shorten-symbol (domain-names)))
       (mapcar (lambda (x) (mapcar #'cdr (alexandria:plist-alist x))) *tests*)))
(write-line "|#")


(terpri)

;;; error gen
(let ((i 0))
  (dolist (test *error-tests*)
    (with-domains-from-plist (test)
      (let ((make-problem-form
              `(signals error
                        (make-problem
                         :graph-input ,(ecase graph-input-type
                                         (pathname 'pathname)
                                         (string `(namestring pathname))
                                         (vector #(() (0)))
                                         (cons ''(3 . 1)))
                         :task-semantic ,(ecase task-semantic-type
                                           (string (format nil "~A-~A" task semantic))
                                           (symbol (intern (format nil "~A-~A" task semantic)
                                                           "KEYWORD")))
                         :query-argument-name
                         ,(ecase arg-contained-in-graph
                            ((t) (ecase arg-type
                                   (integer 0)
                                   (string "foo")))
                            ((nil) (ecase arg-type
                                     (integer 7)
                                     (string "xxx")))
                            (no-arg nil))))))
        (pprint
         `(deftest ,(alexandria:symbolicate
                     "MAKE-PROBLEM.CLI.COMB.ERROR."
                     (princ-to-string (incf i)))
            ,(format nil "~%~{~S:~30T~S~%~}" test)
            ,(case graph-input-file-exists
               ((t)
                `(with-tmp-file-containing
                     ("arg(foo)." "arg(bar)." "att(foo,bar).")
                   pathname
                   (assert (pathnamep pathname))
                   ,make-problem-form))
               (t make-problem-form))))
        (terpri)))))

(terpri)

;;; tests gen
(let ((i 0))
  (dolist (test *tests*)
    (with-domains-from-plist (test)
      (let ((make-problem-form
              `(let ((problem
                       (make-problem
                        :graph-input ,(ecase graph-input-type
                                        (pathname 'pathname)
                                        (string `(namestring pathname))
                                        (vector #(() (0)))
                                        (cons ''(2 . 4)))
                        :task-semantic ,(ecase task-semantic-type
                                          (string (format nil "~A-~A" task semantic))
                                          (symbol (intern (format nil "~A-~A" task semantic)
                                                          "KEYWORD")))
                        :query-argument-name
                        ,(ecase arg-contained-in-graph
                           ((t) (ecase arg-type
                                  (integer 0)
                                  (string "foo")))
                           ((nil) (ecase arg-type
                                    (integer 7)
                                    (string "xxx")))
                           (no-arg nil)))))
                 (is-true (typep problem 'problem-with-result-printed))
                 (is (equalp #(() (0)) (problem-graph problem)))
                 (is (eql ,(if (eql 'null arg-type)
                               nil
                               0)
                          (problem-query-argument problem)))
                 (is (equal ,(if (eql 'null arg-type)
                                 nil
                                 (ecase graph-input-type
                                   ((string pathname)
                                    "foo")
                                   ((cons vector)
                                    0)))
                            (problem-query-argument-name problem)))
                 (is (equalp ,(ecase graph-input-type
                                ((string pathname) #("foo" "bar"))
                                ((cons vector) #(0 1)))
                             (problem-argument-names problem)))
                 (is (eql ,(ecase task
                             (se ''asgl::se-task)
                             (ee ''asgl::ee-task)
                             (dc ''asgl::dc-task)
                             (ds ''asgl::ds-task))
                          (name (problem-task problem))))
                 (is (eql ,(ecase semantic
                             (pr ''asgl::preferred)
                             (co ''asgl::complete)
                             (st ''asgl::stable)
                             (gr ''asgl::grounded))
                          (name (problem-semantic problem)))))))
        (pprint
         `(deftest ,(alexandria:symbolicate
                     "MAKE-PROBLEM.CLI.COMB."
                     (princ-to-string (incf i)))
            ,(format nil "~%~{~S:~30T~S~%~}" test)
            ,(case graph-input-type
               ((pathname string)
                `(with-tmp-file-containing
                     ("arg(foo)." "arg(bar)." "att(foo,bar).")
                   pathname
                   (assert (pathnamep pathname))
                   ,make-problem-form))
               (t make-problem-form))))
        (terpri)))))

(terpri)
