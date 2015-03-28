;; -*- lisp -*-

(in-package :myam)

;;;; * Analyzing the results

(defparameter *verbose-failures* nil
  "T if we should print the expression failing, NIL otherwise.")

;;;; Just as important as defining and runnig the tests is
;;;; understanding the results. myam provides the function EXPLAIN
;;;; which prints a human readable summary (number passed, number
;;;; failed, what failed and why, etc.) of a list of test results.

(defun safe-subseq (sequence start end)
  (subseq sequence start (min end (length sequence))))

(defgeneric explain (explainer results &optional stream recursive-depth))

(defmethod explain ((exp detailed-text-explainer) results
                    &optional (stream *test-dribble*) (recursive-depth 0))
  #| "Given a list of test results report write to stream detailed
  human readable statistics regarding the results." |#
  (multiple-value-bind (num-checks passed num-passed passed%
                        skipped num-skipped skipped%
                        failed num-failed failed%
                        unknown num-unknown unknown%)
      (partition-results results)
    (declare (ignore passed))
    (flet ((output (&rest format-args)
             (format stream "~&~vT" recursive-depth)
             (apply #'format stream format-args)))
      (when (zerop num-checks)
        (output "Didn't run anything...huh?")
        (return-from explain nil))
      (terpri stream)
      (terpri stream)
      (when failed
        (output "Failure Details (limited to max 10):~%")
        (dolist (f (safe-subseq failed 0 10))
          (output "--------------------------------~%")
          (output "~A ~@{[~A]~}: ~%"
                  (name (test-case f))
                  (description (test-case f)))
          (output "     ~A.~%" (reason f))
          (when (for-all-test-failed-p f)
            (output "Results collected with failure data:~%")
            (explain exp (slot-value f 'result-list)
                     stream (+ 4 recursive-depth)))
          (when (and *verbose-failures* (test-expr f))
            (output "    ~S~%" (test-expr f)))
          (output "--------------------------------~%"))
        (terpri stream))
      (when skipped
        (output "Skip Details:~%")
        (dolist (f skipped)
          (output "~A ~@{[~A]~}: ~%"
                  (name (test-case f))
                  (description (test-case f)))
          (output "    ~A.~%" (reason f)))
        (terpri stream))
      (output "Did ~D check~P.~%" num-checks num-checks)
      (output "   Pass: ~8D   ( ~3D % )~%" num-passed passed%)
      (output "   Skip: ~8D   ( ~3D % )~%" num-skipped skipped%)
      (output "   Fail: ~8D   ( ~3D % )~%" num-failed failed%)
      (when unknown
        (output "   UNKNOWN RESULTS: ~D (~2D)~%" num-unknown unknown%))
      )))

(defmethod explain ((exp simple-text-explainer) results
                    &optional (stream *test-dribble*) (recursive-depth 0))
  (multiple-value-bind (num-checks passed num-passed passed%
                        skipped num-skipped skipped%
                        failed num-failed failed%
                        unknown num-unknown unknown%)
      (partition-results results)
    (declare (ignore passed passed% skipped skipped% failed failed%
                     unknown unknown%))
    (format stream "~&~vTRan ~D checks, ~D passed"
            recursive-depth num-checks num-passed)
    (when (plusp num-skipped)
      (format stream ", ~D skipped " num-skipped))
    (format stream " and ~D failed.~%" num-failed)
    (when (plusp num-unknown)
      (format stream "~vT~D UNKNOWN RESULTS.~%" recursive-depth num-unknown))))

(defun partition-results (results-list)
  (let ((num-checks (length results-list)))
    (destructuring-bind (passed skipped failed unknown)
        (partitionx results-list
                    (lambda (res)
                      (typep res 'test-passed))
                    (lambda (res)
                      (typep res 'test-skipped))
                    (lambda (res)
                      (typep res 'test-failure))
                    t)
      (if (zerop num-checks)
          (values 0
                  nil 0 0
                  nil 0 0
                  nil 0 0
                  nil 0 0)
          (values
           num-checks
           passed (length passed)
           (floor (* 100 (/ (length passed) num-checks)))
           skipped (length skipped)
           (floor (* 100 (/ (length skipped) num-checks)))
           failed (length failed)
           (floor (* 100 (/ (length failed) num-checks)))
           unknown (length unknown)
           (floor (* 100 (/ (length failed) num-checks))))))))
