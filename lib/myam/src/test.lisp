;; -*- lisp -*-

(in-package :myam)

;;;; * Tests

;;;; While executing checks and collecting the results is the core job
;;;; of a testing framework it is also important to be able to
;;;; organize checks into groups, myam provides two mechanisms for
;;;; organizing checks: tests and test suites. A test is a named
;;;; collection of checks which can be run and a test suite is a named
;;;; collection of tests and test suites.

(defvar *test* (make-hash-table :test 'eql)
  "lookup table mapping test (and test suite) names to objects.")

(defun get-test (key &optional default)
  (gethash key *test* default))

(defun (setf get-test) (value key)
  (setf (gethash key *test*) value))

(defun rem-test (key) (remhash key *test*))

(defun test-names ()
  (loop for test being the hash-keys of *test*
        collect test))

(deftype compile-at () '(member :run-time :definition-time))

(declaim (type compile-at *default-compile-at*))
(defvar *default-compile-at* :run-time
  "Default setting for compile-at option in deftest.")

(defmacro deftest (name &body body)
  "Create a test named NAME. If NAME is a list it must be of the
form:

  (name &key depends-on suite compile-at)

NAME is the symbol which names the test.

DEPENDS-ON is a list of the form:

 (AND . test-names) - This test is run only if all of the tests
 in TEST-NAMES have passed, otherwise a single test-skipped
 result is generated.

 (OR . test-names) - If any of TEST-NAMES has passed this test is
 run, otherwise a test-skipped result is generated.

 (NOT test-name) - This is test is run only if TEST-NAME failed.

AND, OR and NOT can be combined to produce complex dependencies.

If DEPENDS-ON is a symbol it is interpreted as `(AND
,depends-on), this is accomadate the common case of one test
depending on another."
  (let* ((tmp (gensym))
         (suite-arg (getf (cdr (ensure-list name)) :suite tmp))
         (suite-form (cond
                       ((eq tmp suite-arg) '*suite*)
                       (t                  `(get-test ',suite-arg)))))
    (when (consp name)
      (remf (cdr name) :suite))
    (destructuring-bind (name &key depends-on (compile-at *default-compile-at*))
        (ensure-list name)
      (declare (type compile-at compile-at))
      (let ((description (if (stringp (car body))
                             (pop body)
                             "")))
        (setq body
              `((block test-body
                  (locally
                      (declare #+sbcl(sb-ext:muffle-conditions
                                      sb-ext:code-deletion-note))
                    ,@body))))
        `(progn
           (when (get-test ',name)
             (warn "Redefining test ~S" ',name))
           (setf (get-test ',name)
                 (make-instance
                  'test-case
                  :name ',name
                  :runtime-package
                  #-ecl ,*package*
                  #+ecl (find-package ,(package-name *package*))
                  :test-lambda
                  (lambda ()
                    ,@(ecase
                          compile-at
                        (:run-time
                         `((funcall
                            (let ((*package* (find-package
                                              ',(package-name *package*))))
                              (compile nil '(lambda ()
                                             ,@body))))))
                        (:definition-time
                         body)))
                  :description ,description
                  :depends-on ',depends-on))
           (setf (gethash ',name (tests ,suite-form)) ',name)
           (if *run-test-when-defined*
               (run! ',name)
               ',name))))))

(defvar *run-test-when-defined* nil
  "When non-NIL tests are run as soon as they are defined.")
