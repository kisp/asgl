;; -*- paul-nice-on-save:nil -*-

;; emacs: (put 'deftest 'common-lisp-indent-function 1)
;; emacs: (put 'let*-heap 'common-lisp-indent-function '(as let))

(in-package :asgl)

(use-package :myam)

(defsuite* :tests.engine :in :tests)

(deftest engine.make-instance.1
  (let ((space (make-instance 'bool-space :n 5))
        (vector #(1 2 3 4 5)))
    (finishes (make-engine 'dfs-engine space :vector vector))))

(deftest engine.make-instance.2
  (let ((space (make-instance 'bool-space :n 5)))
    (finishes (make-engine 'dfs-engine space))))

(deftest engine.make-instance.3
  (let ((space (make-instance 'bool-space :n 5)))
    (finishes (make-engine 'bab-engine space))))

(deftest engine.map-solutions.1
  (let ((space (make-instance 'bool-space :n 5)))
    (let ((engine (make-engine 'dfs-engine space)))
      (finishes
       (map-solutions engine
                      (lambda (x) x))))))

(deftest engine.map-solutions.2
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (let ((engine (make-engine 'dfs-engine space)))
      (is (equal '(() (1) (0) (0 1))
                 (let (list)
                   (map-solutions engine (lambda (x) (push x list)))
                   (nreverse list)))))))

(deftest engine.map-solutions.3
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (let ((engine (make-engine 'dfs-engine space)))
      (is (equal '(:FAIL 0 :NODE 7 :DEPTH 2 :RESTART 0 :NOGOOD 0)
                 (map-solutions engine (lambda (x) x)))))))

(deftest engine.list-solutions.1
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (let ((engine (make-engine 'dfs-engine space)))
      (is (equal '(() (1) (0) (0 1))
                 (list-solutions engine))))))

(deftest engine.engine-statistics.1
  (let ((space (make-instance 'bool-space :n 2)))
    (let ((engine (make-engine 'dfs-engine space)))
      (is (equal '(:FAIL 0 :NODE 0 :DEPTH 0 :RESTART 0 :NOGOOD 0)
                 (engine-statistics engine))))))

(deftest engine.engine-statistics.2
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (let ((engine (make-engine 'dfs-engine space)))
      (block nil
        (map-solutions engine
                       (lambda (x)
                         (declare (ignore x))
                         (is (equal '(:FAIL 0 :NODE 3 :DEPTH 2 :RESTART 0 :NOGOOD 0)
                                    (engine-statistics engine)))
                         (return)))))))

(deftest engine.first-solution.1
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (let ((engine (make-engine 'dfs-engine space)))
      (multiple-value-bind (solution exists statistics)
          (first-solution engine)
        (is (null solution))
        (is-true exists)
        (is (equal '(:FAIL 0 :NODE 3 :DEPTH 2 :RESTART 0 :NOGOOD 0)
                   statistics))))))

(deftest engine.first-solution.2
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (post-must-be-false (foreign-space space) 0)
    (post-must-be-true (foreign-space space) 0)
    (let ((engine (make-engine 'dfs-engine space)))
      (multiple-value-bind (solution exists statistics)
          (first-solution engine)
        (is (null solution))
        (is-false exists)
        (is (equal '(:FAIL 1 :NODE 0 :DEPTH 0 :RESTART 0 :NOGOOD 0)
                   statistics))))))

(deftest engine.last-solution.1
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (let ((engine (make-engine 'dfs-engine space)))
      (multiple-value-bind (solution exists statistics)
          (last-solution engine)
        (is (equal '(0 1) solution))
        (is-true exists)
        (is (equal '(:FAIL 0 :NODE 7 :DEPTH 2 :RESTART 0 :NOGOOD 0)
                   statistics))))))

(deftest engine.last-solution.2
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (post-must-be-false (foreign-space space) 0)
    (post-must-be-true (foreign-space space) 0)
    (let ((engine (make-engine 'dfs-engine space)))
      (multiple-value-bind (solution exists statistics)
          (last-solution engine)
        (is (null solution))
        (is-false exists)
        (is (equal '(:FAIL 1 :NODE 0 :DEPTH 0 :RESTART 0 :NOGOOD 0)
                   statistics))))))

(deftest engine.first-solution-exists-p.1
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (let ((engine (make-engine 'dfs-engine space)))
      (multiple-value-bind (exists statistics)
          (first-solution-exists-p engine)
        (is-true exists)
        (is (equal '(:FAIL 0 :NODE 3 :DEPTH 2 :RESTART 0 :NOGOOD 0)
                   statistics))))))

(deftest engine.first-solution-exists-p.2
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (post-must-be-false (foreign-space space) 0)
    (post-must-be-true (foreign-space space) 0)
    (let ((engine (make-engine 'dfs-engine space)))
      (multiple-value-bind (exists statistics)
          (first-solution-exists-p engine)
        (is-false exists)
        (is (equal '(:FAIL 1 :NODE 0 :DEPTH 0 :RESTART 0 :NOGOOD 0)
                   statistics))))))

(deftest engine.print-solutions.1
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (let ((engine (make-engine 'dfs-engine space)))
      (let (output statistics)
        (setq output
              (with-output-to-string (stream)
                (setq statistics
                      (print-solutions engine stream))))
        (is (equal (format nil "[~%[]~%,[1]~%,[0]~%,[0,1]~%]~%") output))
        (is (equal '(:FAIL 0 :NODE 7 :DEPTH 2 :RESTART 0 :NOGOOD 0)
                   statistics))))))

(deftest engine.print-solutions.2
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (post-must-be-false (foreign-space space) 0)
    (post-must-be-true (foreign-space space) 0)
    (let ((engine (make-engine 'dfs-engine space)))
      (let (output statistics)
        (setq output
              (with-output-to-string (stream)
                (setq statistics
                      (print-solutions engine stream))))
        (is (equal (format nil "[~%]~%") output))
        (is (equal '(:FAIL 1 :NODE 0 :DEPTH 0 :RESTART 0 :NOGOOD 0)
                   statistics))))))

(deftest engine.print-first-solution.1
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (let ((engine (make-engine 'dfs-engine space)))
      (let (output exists statistics)
        (setq output
              (with-output-to-string (stream)
                (multiple-value-setq (exists statistics)
                  (print-first-solution engine stream))))
        (is (equal (format nil "[]~%") output))
        (is-true exists)
        (is (equal '(:FAIL 0 :NODE 3 :DEPTH 2 :RESTART 0 :NOGOOD 0)
                   statistics))))))

(deftest engine.print-first-solution.2
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (post-must-be-false (foreign-space space) 0)
    (post-must-be-true (foreign-space space) 0)
    (let ((engine (make-engine 'dfs-engine space)))
      (let (output exists statistics)
        (setq output
              (with-output-to-string (stream)
                (multiple-value-setq (exists statistics)
                  (print-first-solution engine stream))))
        (is (equal (format nil "") output))
        (is-false exists)
        (is (equal '(:FAIL 1 :NODE 0 :DEPTH 0 :RESTART 0 :NOGOOD 0)
                   statistics))))))

(deftest engine.print-last-solution.1
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (let ((engine (make-engine 'dfs-engine space)))
      (let (output exists statistics)
        (setq output
              (with-output-to-string (stream)
                (multiple-value-setq (exists statistics)
                  (print-last-solution engine stream))))
        (is (equal (format nil "[0,1]~%") output))
        (is-true exists)
        (is (equal '(:FAIL 0 :NODE 7 :DEPTH 2 :RESTART 0 :NOGOOD 0)
                   statistics))))))

(deftest engine.print-last-solution.2
  (let ((space (make-instance 'bool-space :n 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
               (space-branch space var val))
    (post-must-be-false (foreign-space space) 0)
    (post-must-be-true (foreign-space space) 0)
    (let ((engine (make-engine 'dfs-engine space)))
      (let (output exists statistics)
        (setq output
              (with-output-to-string (stream)
                (multiple-value-setq (exists statistics)
                  (print-last-solution engine stream))))
        (is (equal (format nil "") output))
        (is-false exists)
        (is (equal '(:FAIL 1 :NODE 0 :DEPTH 0 :RESTART 0 :NOGOOD 0)
                   statistics))))))
