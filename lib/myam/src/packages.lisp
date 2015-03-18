;; -*- lisp -*-

;;;; * Introduction

;;;; myam is a testing framework. It takes care of all the boring
;;;; bookkeeping associated with managing a test framework allowing
;;;; the developer to focus on writing tests and code.

;;;; myam was designed with the following premises:

;;;; - Defining tests should be about writing tests, not
;;;; infrastructure. The developer should be able to focus on what
;;;; they're testing, not the testing framework.

;;;; - Interactive testing is the norm. Common Lisp is an interactive
;;;; development environment, the testing environment should allow the
;;;; developer to quickly and easily redefine, change, remove and run
;;;; tests.

(defpackage :myam
  (:use :common-lisp :alexandria :arnesi-list-match)
  (:export ;; creating tests and test-suites
   #:make-suite
   #:defsuite
   #:defsuite*
   #:in-suite
   #:in-suite*
   #:make-test
   #:deftest
   #:get-test
   #:rem-test
   #:test-names
   ;; running checks
   #:is
   #:is-every
   #:is-true
   #:is-false
   #:signals
   #:finishes
   #:skip
   #:skip*
   #:pass
   #:fail
   #:*test-dribble*
   #:for-all
   #:gen-integer
   #:gen-float
   #:gen-character
   #:gen-string
   #:gen-list
   #:gen-tree
   #:gen-buffer
   #:gen-one-element
   #:gen-member
   #:gen-funcall
   #:*myam-print-length*
   #:*myam-print-level*
   ;; running tests
   #:run
   #:run-all-tests
   #:explain
   #:explain!
   #:*default-explainer*
   #:simple-text-explainer
   #:detailed-text-explainer
   #:run!
   #:debug!
   #:*run-test-when-defined*
   #:*debug-on-error*
   #:*debug-on-failure*
   #:*verbose-failures*
   #:results-status
   ;;
   #:actual-condition
   #:test-passed-p
   #:test-skipped-p
   #:test-failure-p
   #:*max-trials*
   #:*num-trials*
   #:*force-dribble-output*
   #:load-and-run!
   #:*default-compile-at*))

;;;; You can use #+myam to put your test-defining code inline with your
;;;; other code - and not require people to have myam to run your
;;;; package.

(pushnew :myam *features*)
