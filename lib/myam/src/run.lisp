;; -*- lisp -*-

(in-package :myam)

;;;; * Running Tests

;;;; Once the programmer has defined what the tests are these need to
;;;; be run and the expected effects should be compared with the
;;;; actual effects. myam provides the function RUN for this purpose,
;;;; RUN executes a number of tests and collects the results of each
;;;; individual check into a list which is then returned. There are
;;;; three types of test results: passed, failed and skipped, these
;;;; are represented by TEST-RESULT objects.

;;;; Generally running a test will return normally, but there are two
;;;; exceptional situations which can occur:

;;;; - An exception is signaled while running the test. If the
;;;;   variable *debug-on-error* is T than myam will enter the
;;;;   debugger, otherwise a test failure (of type
;;;;   unexpected-test-failure) is returned. When entering the
;;;;   debugger two restarts are made available, one simply reruns the
;;;;   current test and another signals a test-failure and continues
;;;;   with the remaining tests.

;;;; - A circular dependency is detected. An error is signaled and a
;;;;   restart is made available which signals a test-skipped and
;;;;   continues with the remaining tests. This restart also sets the
;;;;   dependency status of the test to nil, so any tests which depend
;;;;   on this one (even if the dependency is not circular) will be
;;;;   skipped.

;;;; The function RUN! is a convenient wrapper around RUN and EXPLAIN.

(defparameter *debug-on-error* nil
  "T if we should drop into a debugger on error, NIL otherwise.")

(defparameter *debug-on-failure* nil
  "T if we should drop into a debugger on a failing check, NIL otherwise.")

(defparameter *default-explainer* 'detailed-text-explainer
  "The explainer to be used by EXPLAIN!. Can be any object for which
an EXPLAIN method is implemented. A symbol will be treated as naming a
class, which is instantiated with no initargs.")

(defvar *run-with-dribble-output* nil
  "Whether RUN should output information while running tests.")

(defun default-explainer ()
  (typecase *default-explainer*
    (symbol (make-instance *default-explainer*))
    (t *default-explainer*)))

(define-condition circular-dependency (error)
  ((test-case :initarg :test-case))
  (:report (lambda (cd stream)
             (format stream "A circular dependency wes detected in ~S."
                     (slot-value cd 'test-case))))
  (:documentation "Condition signaled when a circular dependency
between test-cases has been detected."))

(defgeneric run-resolving-dependencies (test)
  (:documentation "Given a dependency spec determine if the spec
is satisfied or not, this will generally involve running other
tests. If the dependency spec can be satisfied the test is alos
run."))

(defmethod run-resolving-dependencies ((test test-case))
  "Return true if this test, and its dependencies, are satisfied,
  NIL otherwise."
  (case (status test)
    (:unknown
     (setf (status test) :resolving)
     (if (or (not (depends-on test))
             (eql t (resolve-dependencies (depends-on test))))
         (progn
           (run-test-lambda test)
           (status test))
         (with-run-state (result-list)
           (unless (eql :circular (status test))
             (push (make-instance 'test-skipped
                                  :test-case test
                                  :reason "Dependencies not satisfied")
                   result-list)
             (setf (status test) :depends-not-satisfied)))))
    (:resolving
     (restart-case
         (error 'circular-dependency :test-case test)
       (skip ()
         :report (lambda (s)
                   (format s "Skip the test ~S and all its dependencies."
                           (name test)))
         (with-run-state (result-list)
           (push (make-instance 'test-skipped :reason "Circular dependencies"
                                              :test-case test)
                 result-list))
         (setf (status test) :circular))))
    (t (status test))))

(defgeneric resolve-dependencies (depends-on))

(defmethod resolve-dependencies ((depends-on symbol))
  "A test which depends on a symbol is interpreted as `(AND
  ,DEPENDS-ON)."
  (run-resolving-dependencies (get-test depends-on)))

(defmethod resolve-dependencies ((depends-on list))
  "Return true if the dependency spec DEPENDS-ON is satisfied,
  nil otherwise."
  (if (null depends-on)
      t
      (flet ((satisfies-depends-p (test)
               (funcall test (lambda (dep)
                               (eql t (resolve-dependencies dep)))
                        (cdr depends-on))))
        (ecase (car depends-on)
          (and (satisfies-depends-p #'every))
          (or  (satisfies-depends-p #'some))
          (not (satisfies-depends-p #'notany))
          (:before (every #'(lambda (dep)
                              (let ((status (status (get-test dep))))
                                (eql :unknown status)))
                          (cdr depends-on)))))))

(defun results-status (result-list)
  "Given a list of test results (generated while running a test)
  return true if all of the results are of type TEST-PASSED, fail
  otherwise."
  (every (lambda (res)
           (typep res 'test-passed))
         result-list))

(defgeneric run-test-lambda (test))

(defmethod run-test-lambda ((test test-case))
  (with-run-state (result-list)
    (bind-run-state ((current-test test))
                    (labels ((abort-test (e)
                               (add-result 'unexpected-test-failure
                                           :test-expr nil
                                           :test-case test
                                           :reason (format-reason-to-string
                                                    "Unexpected Error: ~S~%~A." e e)
                                           :condition e))
                             (run-it ()
                               (let ((result-list '()))
                                 (declare (special result-list))
                                 (handler-bind ((check-failure
                                                  (lambda (e)
                                                    (declare (ignore e))
                                                    (unless *debug-on-failure*
                                                      (invoke-restart
                                                       (find-restart 'ignore-failure)))))
                                                (error
                                                  (lambda (e)
                                                    (unless (or *debug-on-error*
                                                                (typep e 'check-failure))
                                                      (abort-test e)
                                                      (return-from run-it result-list)))))
                                   (restart-case
                                       (let ((*readtable* (copy-readtable))
                                             (*package* (runtime-package test)))
                                         (funcall (test-lambda test)))
                                     (retest ()
                                       :report (lambda (stream)
                                                 (format stream "~@<Rerun the test ~S~@:>"
                                                         test))
                                       (return-from run-it (run-it)))
                                     (ignore ()
                                       :report (lambda (stream)
                                                 (format stream "~@<Signal an exceptional ~
                                     test failure and abort the test ~S.~@:>"
                                                         test))
                                       (abort-test (make-instance
                                                    'test-failure
                                                    :test-case test
                                                    :reason "Failure restart."))))
                                   result-list))))
                      (let ((results (run-it)))
                        (setf (status test) (results-status results)
                              result-list (nconc result-list results)))))))

(defgeneric %run (test-spec)
  (:documentation "Internal method for running a test. Does not update
the status of the tests."))

(defmethod %run ((test test-case))
  (let ((*package* (runtime-package test)))
    (format *test-dribble* "~&; ~S: " (name test)))
  (run-resolving-dependencies test))

(defmethod %run ((tests list))
  (mapc #'%run tests))

(defmethod %run ((suite test-suite))
  (let ((suite-results '()))
    (flet ((run-tests ()
             (loop
               for test being the hash-values of (tests suite)
               do (%run test))))
      (unwind-protect
           (bind-run-state ((result-list '()))
                           (run-tests)
                           (setf suite-results result-list
                                 (status suite) (every (lambda (res)
                                                         (typep res 'test-passed))
                                                       suite-results)))
        (with-run-state (result-list)
          (setf result-list (nconc result-list suite-results)))))))

(defmethod %run ((test-name symbol))
  (when-let ((test (get-test test-name)))
    (%run test)))

;;;; ** Public entry points

(defun run! (&optional (test-spec *suite*))
  "Equivalent to (explain! (run TEST-SPEC))."
  (flet ((failure-count (results)
           (count-if (lambda (res) (typep res 'test-failure)) results)))
    (with-test-dribble ()
      (let ((results (run test-spec)))
        (explain! results)
        (and results
             (zerop (failure-count results)))))))

#+asdf
(defun load-and-run! (name)
  "Convenience function to first reload the test-system and then run
the tests."
  (let ((name (string-upcase (string name))))
    (asdf::load-system (string-downcase name))
    (run! (make-keyword name))))

(defun explain! (result-list)
  "Explain the results of RESULT-LIST using default-explainer with
output going to *test-dribble*"
  (with-test-dribble ()
    (explain (default-explainer) result-list *test-dribble*)))

(defun debug! (&optional (test-spec *suite*))
  "Calls (run! test-spec) but enters the debugger if any kind of error
happens."
  (let ((*debug-on-error* t)
        (*debug-on-failure* t))
    (run! test-spec)))

(defun run (test-spec)
  "Run the test specified by TEST-SPEC.

TEST-SPEC can be either a symbol naming a test or test suite, or a
testable-object object."
  (dolist (test (test-names))
    (setf (status (get-test test)) :unknown))
  (bind-run-state ((result-list '()))
                  (with-test-dribble ((if *run-with-dribble-output*
                                          *test-dribble*
                                          (make-broadcast-stream)))
                    (with-simple-restart (explain "Ignore the rest of the tests ~
                                     and explain current results")
                      (%run test-spec)))
                  result-list))
