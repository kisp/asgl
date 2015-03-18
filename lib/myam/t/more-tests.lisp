;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(in-package :myam)

(in-suite :myam-test)

;;; skipped-test-output
(deftest (a-skipped-test :suite test-suite)
  (skip "some reason"))

(deftest skipped-test-output
  (is (equal "; A-SKIPPED-TEST: s"
             (with-output-to-string (*test-dribble*)
               (let ((*run-with-dribble-output* t))
                 (run 'a-skipped-test))))))

;;; test for (unexpected-test-failure (force-output-char *test-dribble* #\X))
(deftest (an-unexpectedly-failing-test :suite test-suite)
  (eval (read-from-string "(/ 1 0)"))
  (pass "some reason"))

(deftest unexpected-test-failure
  (is (equal "; AN-UNEXPECTEDLY-FAILING-TEST: X"
             (with-output-to-string (*test-dribble*)
               (let ((*run-with-dribble-output* t))
                 (run 'an-unexpectedly-failing-test))))))

;;; is.consp
(deftest is.consp
  (signals error (macroexpand '(is 123))))

;;; is with values
(deftest is.values
  (signals error (macroexpand '(is (foo= (values 1 2 3) (values a)))))
  (signals error (macroexpand '(is (foo= b (values a)))))
  (finishes (macroexpand '(is (foo= (values a) b)))))

(deftest (floor-2-3 :suite test-suite)
  (is (equal (values 0 2) (floor 2 3)))
  (is (equal (values 0 *) (floor 2 3)))
  (is (equal (values 0 *) (floor 7 13)))
  (is (equal (values * 2) (floor 2 3)))
  (is (equal (values * *) (floor 2 3)))
  (is (not (equal (values * 3) (floor 2 3))))
  (is (not (equal (values *) (floor 2 3)))))

(deftest is.values.2
  (with-test-results (results floor-2-3)
    (is (every #'test-passed-p results))))

;;; not numberp
(deftest (not-numberp :suite test-suite)
  (is (not (numberp 'a))))

(deftest is.not-predicate
  (with-test-results (results not-numberp)
    (is (every #'test-passed-p results))))

;;; long predicate
(defun long-predicate (a b c d e f g)
  (and a b c d e f g))

(deftest (long-predicate :suite test-suite)
  (is (long-predicate 1 2 3 4 5 6 7))
  (is (not (long-predicate 1 2 3 4 5 6 nil))))

(deftest (long-predicate2 :suite test-suite)
  (is (long-predicate 1 2 3 4 5 6 nil)))

(deftest is.long-predicate
  (with-test-results (results long-predicate)
    (is (every #'test-passed-p results))))

(deftest is.long-predicate2
  (with-test-results (results long-predicate2)
    (is (every #'test-failure-p results))))

;;; is-every
(deftest (is-every :suite test-suite)
  (is-every eql
    (2 (+ 1 1))
    (5 (+ 2 3))
    (3 (+ 1 2))))

(deftest is-every.1
  (with-test-results (results is-every)
    (is (every #'test-passed-p results))))

(deftest (is-every.2 :suite test-suite)
  (is-every eql
    2 (+ 1 1)
    5 (+ 2 3)
    3 (+ 1 2)))

(deftest is-every.3
  (with-test-results (results is-every.2)
    (is (every #'test-passed-p results))))

(deftest is-every.4
  (signals error (macroexpand '(is-every eql 1 2 3))))

;;;; is typep
;;; is-typep.demo.1
(deftest (is-typep.demo.1 :suite test-suite)
  (is (typep 432 '(integer 0 5))))

(deftest is-typep.1
  (let ((result (first (run 'is-typep.demo.1))))
    (is (equal "432 evaluated to
432,
which is not of type
(INTEGER 0 5)." (reason result)))))

;;; is-typep.demo.2
(deftest (is-typep.demo.2 :suite test-suite)
  (is (not (typep 2 '(integer 0 5)))))

(deftest is-typep.2
  (let ((result (first (run 'is-typep.demo.2))))
    (is (equal "2 evaluated to
2,
which is of type
(INTEGER 0 5) (it should not)." (reason result)))))

;;; is-typep.demo.3
(deftest (is-typep.demo.3 :suite test-suite)
  (is (typep (+ 100 200) '(integer 0 5))))

(deftest is-typep.3
  (let ((result (first (run 'is-typep.demo.3))))
    (is (equal "(+ 100 200) evaluated to
300,
which is not of type
(INTEGER 0 5)." (reason result)))))

;;; is-typep.demo.4
(deftest (is-typep.demo.4 :suite test-suite)
  (is (not (typep (+ 0 2) '(integer 0 5)))))

(deftest is-typep.4
  (let ((result (first (run 'is-typep.demo.4))))
    (is (equal "(+ 0 2) evaluated to
2,
which is of type
(INTEGER 0 5) (it should not)." (reason result)))))

;;; is-true / if-false
(deftest (is-true/is-false :suite test-suite)
  (is-true (zerop 0))
  (is-true (zerop 0) "custom reason")
  (is-false (zerop 1))
  (is-false (zerop 1) "custom reason"))

(deftest is-true/is-false.2
  (with-test-results (results is-true/is-false)
    (is (every #'test-passed-p results))))

;;; signals
(deftest (signals :suite test-suite)
  (signals error (eval (read-from-string "(/ 1 0)")))
  (signals (error "custom reason")
    (eval (read-from-string "(/ 1 0)"))))

(deftest signals.2
  (with-test-results (results signals)
    (is (every #'test-passed-p results))))

;;; compile-at
(defmacro compile-at-test-m1 ()
  123)

(deftest (compile-at-test1 :suite test-suite)
  (is (eql 123 (compile-at-test-m1))))

(deftest (compile-at-test2 :suite test-suite
                           :compile-at :definition-time)
  (is (eql 123 (compile-at-test-m1))))

(deftest compile-at.1
  (skip*)
  (with-test-results (results compile-at-test1)
    (is (every #'test-passed-p results)))
  (with-test-results (results compile-at-test2)
    (is (every #'test-passed-p results)))
  ;; redefine the macro
  (defmacro compile-at-test-m1 ()
    0)
  (with-test-results (results compile-at-test1)
    (is (every #'test-failure-p results)))
  (with-test-results (results compile-at-test2)
    (is (every #'test-passed-p results))))

;;; compile-at default behavior can be changed
(defmacro compile-at2-test-m1 ()
  123)

(eval-when (:compile-toplevel :load-toplevel :execute)
  (setq *default-compile-at* :definition-time))

(deftest (compile-at2-test2 :suite test-suite)
  (is (eql 123 (compile-at2-test-m1))))

(eval-when (:compile-toplevel :load-toplevel :execute)
  (setq *default-compile-at* :run-time))

(deftest compile-at.2
  (with-test-results (results compile-at2-test2)
    (is (every #'test-passed-p results)))
  ;; redefine the macro
  (defmacro compile-at2-test-m1 ()
    0)
  (with-test-results (results compile-at2-test2)
    (is (every #'test-passed-p results))))
