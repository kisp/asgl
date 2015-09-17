;; -*- paul-nice-on-save:nil -*-

;; emacs: (put 'deftest 'common-lisp-indent-function 1)

(in-package :asgl)

(use-package :myam)

(in-suite :tests)

(deftest read-graph-input.1
  (with-tmp-file-containing ("arg(foo).") pathname
    (is (equalp #(nil)
                (asgl::read-graph-input pathname)))))

(deftest read-graph-input.2
  (with-tmp-file-containing ("arg(foo)." "att(foo,foo).") pathname
    (is (equalp #((0))
                (asgl::read-graph-input pathname)))))

(deftest read-graph-input.3
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (equalp #(() (0))
                (asgl::read-graph-input pathname)))))

(deftest make-problem.cli.1
  (signals error
           (make-problem :graph-input "nonexisting.apx"
                         :task-semantic "EE-CO")))

(deftest make-problem.cli.2
  (with-tmp-file-containing ("arg(foo).") pathname
    (finishes
     (make-problem :graph-input pathname
                   :task-semantic "EE-CO"))))

(deftest make-problem.cli.3
  (with-tmp-file-containing ("arg(foo).") pathname
    (is-true (typep (make-problem :graph-input pathname
                                  :task-semantic "EE-CO")
                    'problem))))

(deftest make-problem.cli.4
  (with-tmp-file-containing ("arg(foo).") pathname
    (is-true (typep (make-problem :graph-input pathname
                                  :task-semantic "EE-CO")
                    'problem-with-result-printed))))

(deftest make-problem.cli.5
  (with-tmp-file-containing ("arg(foo).") pathname
    (is (equalp #(())
                (problem-graph
                 (make-problem :graph-input pathname
                               :task-semantic "EE-CO"))))))

(deftest make-problem.cli.6
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (equalp #(() (0))
                (problem-graph
                 (make-problem :graph-input pathname
                               :task-semantic "EE-CO"))))))

(deftest make-problem.cli.7
  ;; argument does not exist
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (signals error
             (make-problem :graph-input pathname
                           :task-semantic "DC-CO"
                           :query-argument-name "a574389"))))

(deftest make-problem.cli.8
  ;; argument *does* exist
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (finishes
     (make-problem :graph-input pathname
                   :task-semantic "DC-CO"
                   :query-argument-name "foo"))))

(deftest make-problem.cli.9
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (equal 0
               (problem-query-argument
                (make-problem :graph-input pathname
                              :task-semantic "DC-CO"
                              :query-argument-name "foo"))))))

(deftest make-problem.cli.10
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (equalp #("foo" "bar")
                (problem-argument-names
                 (make-problem :graph-input pathname
                               :task-semantic "EE-CO"))))))

(deftest make-problem.cli.11
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (eql 'asgl::complete
             (name
              (problem-semantic
               (make-problem :graph-input pathname
                             :task-semantic "DS-CO"
                             :query-argument-name "foo")))))))

(deftest make-problem.cli.12
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (eql 'asgl::stable
             (name
              (problem-semantic
               (make-problem :graph-input pathname
                             :task-semantic "EE-ST")))))))

(deftest make-problem.cli.13
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (eql 'asgl::grounded
             (name
              (problem-semantic
               (make-problem :graph-input pathname
                             :task-semantic "EE-GR")))))))

(deftest make-problem.cli.13b
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (eql 'asgl::preferred
             (name
              (problem-semantic
               (make-problem :graph-input pathname
                             :task-semantic "DS-PR"
                             :query-argument-name "foo")))))))

(deftest make-problem.cli.14
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (eql 'asgl::ee-task
             (name
              (problem-task
               (make-problem :graph-input pathname
                             :task-semantic "EE-PR")))))))

(deftest make-problem.cli.15
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (eql 'asgl::se-task
             (name
              (problem-task
               (make-problem :graph-input pathname
                             :task-semantic "SE-PR")))))))

(deftest make-problem.cli.16
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (eql 'asgl::dc-task
             (name
              (problem-task
               (make-problem :graph-input pathname
                             :task-semantic "DC-PR"
                             :query-argument-name "foo")))))))

(deftest make-problem.cli.17
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (eql 'asgl::ds-task
             (name
              (problem-task
               (make-problem :graph-input pathname
                             :task-semantic "DS-PR"
                             :query-argument-name "foo")))))))

(deftest make-problem.cli.19
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (eql 'problem
             (type-of
              (make-problem :graph-input pathname
                            :task-semantic "DS-PR"
                            :query-argument-name "foo"
                            :class 'problem))))))

(deftest make-problem.cli.20
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (equal "#<problem-with-result-printed DS-CO (arg foo) of AF with two arguments, one attack>"
               (princ-to-string
                (make-problem :graph-input pathname
                              :task-semantic "DS-PR"
                              :query-argument-name "foo"))))))

(deftest make-problem.cli.21
  ;; missing argument
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (signals error
             (make-problem :graph-input pathname
                           :task-semantic "DS-PR"))))

(deftest make-problem.cli.22
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (is (equal "#<problem-with-result-printed EE-CO of AF with two arguments, one attack>"
               (princ-to-string
                (make-problem :graph-input pathname
                              :task-semantic "EE-CO"))))))

(deftest make-problem.cli.23
  (with-tmp-file-containing ("arg(foo)." "arg(bar)." "att(foo,bar).") pathname
    (signals error
             (make-problem :graph-input pathname
                           :task-semantic "EE-CO"
                           :query-argument-name "foo"))))

