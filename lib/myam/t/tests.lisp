;;;; -*- lisp -*-

(in-package :myam)

(defsuite* :myam-test)

(defsuite test-suite :description "Suite for tests which should fail.")

(defmacro with-test-results ((results test-name) &body body)
  `(let ((,results (with-test-dribble ((make-broadcast-stream))
                     (run ',test-name))))
     ,@body))

;;;; Test the checks

(deftest (is1 :suite test-suite)
  (is (plusp 1))
  (is (< 0 1))
  (is (not (plusp -1)))
  (is (not (< 1 0)))
  (is-true t)
  (is-false nil))

(deftest signals/finishes
  (signals error
    (error "an error"))
  (finishes
    (signals error
      (error "an error"))))

(deftest pass
  (pass))

(deftest (fail1 :suite test-suite)
  (fail "This is supposed to fail"))

(deftest fail
  (with-test-results (results fail1)
    (is (= 1 (length results)))
    (is (test-failure-p (first results)))))

;;;; non top level checks

(deftest foo-bar
  (let ((state 0))
    (is (= 0 state))
    (is (= 1 (incf state)))))

;;;; Test dependencies

(deftest (ok :suite test-suite)
  (pass))

(deftest (not-ok :suite test-suite)
  (fail "This is supposed to fail."))

(deftest (and1 :depends-on (and ok not-ok) :suite test-suite)
  (fail))

(deftest (and2 :depends-on (and ok) :suite test-suite)
  (pass))

(deftest dep-and
  (with-test-results (results and1)
    (is (= 3 (length results)))
    ;; we should have one skippedw one failed and one passed
    (is (some #'test-passed-p results))
    (is (some #'test-skipped-p results))
    (is (some #'test-failure-p results)))
  (with-test-results (results and2)
    (is (= 2 (length results)))
    (is (every #'test-passed-p results))))

(deftest (or1 :depends-on (or ok not-ok) :suite test-suite)
  (pass))

(deftest (or2 :depends-on (or not-ok ok) :suite test-suite)
  (pass))

(deftest dep-or
  (with-test-results (results or1)
    (is (= 2 (length results)))
    (is (every #'test-passed-p results)))
  (with-test-results (results or2)
    (is (= 3 (length results)))
    (is (= 2 (length (remove-if-not #'test-passed-p results))))))

(deftest (not1 :depends-on (not not-ok) :suite test-suite)
  (pass))

(deftest (not2 :depends-on (not ok) :suite test-suite)
  (fail))

(deftest not
  (with-test-results (results not1)
    (is (= 2 (length results)))
    (is (some #'test-passed-p results))
    (is (some #'test-failure-p results)))
  (with-test-results (results not2)
    (is (= 2 (length results)))
    (is (some #'test-passed-p results))
    (is (some #'test-skipped-p results))))

(deftest (nested-logic :depends-on (and ok (not not-ok) (not not-ok))
                       :suite test-suite)
  (pass))

(deftest dep-nested
  (with-test-results (results nested-logic)
    (is (= 3 (length results)))
    (is (= 2 (length (remove-if-not #'test-passed-p results))))
    (is (= 1 (length (remove-if-not #'test-failure-p results))))))

(deftest (circular-0 :depends-on (and circular-1 circular-2 or1)
                     :suite test-suite)
  (fail "we depend on a circular dependency, we should not be tested."))

(deftest (circular-1 :depends-on (and circular-2)
                     :suite test-suite)
  (fail "we have a circular depednency, we should not be tested."))

(deftest (circular-2 :depends-on (and circular-1)
                     :suite test-suite)
  (fail "we have a circular depednency, we should not be tested."))

(deftest circular
  (signals circular-dependency
    (run 'circular-0))
  (signals circular-dependency
    (run 'circular-1))
  (signals circular-dependency
    (run 'circular-2)))


(defsuite before-test-suite :description "Suite for before test")

(deftest (before-0 :suite before-test-suite)
  (pass))

(deftest (before-1 :depends-on (:before before-0)
                   :suite before-test-suite)
  (fail))

(defsuite before-test-suite-2 :description "Suite for before test")

(deftest (before-2 :depends-on (:before before-3)
                   :suite before-test-suite-2)
  (pass))

(deftest (before-3 :suite before-test-suite-2)
  (pass))

(deftest before
  (with-test-results (results before-test-suite)
    (is (some #'test-skipped-p results)))
  (with-test-results (results before-test-suite-2)
    (is (every #'test-passed-p results))))

;;;; dependencies with symbol
(deftest (dep-with-symbol-first :suite test-suite)
  (pass))

(deftest (dep-with-symbol-dependencies-not-met
          :depends-on (not dep-with-symbol-first)
          :suite test-suite)
  (fail "Error in the test of the test, this should not ever happen"))

(deftest (dep-with-symbol-depends-on-ok
          :depends-on dep-with-symbol-first :suite test-suite)
  (pass))

(deftest (dep-with-symbol-depends-on-failed-dependency
          :depends-on dep-with-symbol-dependencies-not-met
          :suite test-suite)
  (fail "No, I should not be tested becuase I depend on a test that in
  its turn has a failed dependecy."))

(deftest dependencies-with-symbol
  (with-test-results (results dep-with-symbol-first)
    (is (some #'test-passed-p results)))

  (with-test-results (results dep-with-symbol-depends-on-ok)
    (is (some #'test-passed-p results)))

  (with-test-results (results dep-with-symbol-dependencies-not-met)
    (is (some #'test-skipped-p results)))

  ;; No failure here, because it means the test was run.
  (with-test-results (results dep-with-symbol-depends-on-failed-dependency)
    (is (not (some #'test-failure-p results)))))


;;;; test for-all

(deftest gen-integer
  (for-all ((a (gen-integer)))
    (is (integerp a))))

(deftest for-all-guarded
  (for-all ((less (gen-integer))
            (more (gen-integer) (< less more)))
    (is (< less more))))

(deftest gen-float
  (macrolet ((test-gen-float (type)
               `(for-all ((unbounded (gen-float :type ',type))
                          (bounded   (gen-float :type ',type :bound 42)))
                  (is (typep unbounded ',type))
                  (is (typep bounded ',type))
                  (is (<= (abs bounded) 42)))))
    (test-gen-float single-float)
    (test-gen-float short-float)
    (test-gen-float double-float)
    (test-gen-float long-float)))

(deftest gen-character
  (for-all ((c (gen-character)))
    (is (characterp c)))
  (for-all ((c (gen-character :code (gen-integer :min 32 :max 40))))
    (is (characterp c))
    (member c (list #\Space #\! #\" #\# #\$ #\% #\& #\' #\())))

(deftest gen-string
  (for-all ((s (gen-string)))
    (is (stringp s)))
  (for-all ((s (gen-string :length (gen-integer :min 0 :max 2))))
    (is (<= (length s) 2)))
  (for-all ((s (gen-string
                :elements (gen-character :code (gen-integer :min 0 :max 0))
                :length (constantly 2))))
    (is (= 2 (length s)))
    (is (every (curry #'char= #\Null) s))))

(defun dummy-mv-generator ()
  (lambda ()
    (list 1 1)))

(deftest for-all-destructuring-bind
  (for-all (((a b) (dummy-mv-generator)))
    (is (= 1 a))
    (is (= 1 b))))

(defsuite skip-test-suite :description "Suite for skip test")

(deftest (skip-0 :suite skip-test-suite)
  (skip))

(deftest skip
  (with-test-results (results skip-test-suite)
    (is (some #'test-skipped-p results))))
