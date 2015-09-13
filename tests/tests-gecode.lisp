;; -*- paul-nice-on-save:nil -*-

;; emacs: (put 'deftest 'common-lisp-indent-function 1)
;; emacs: (put 'let*-heap 'common-lisp-indent-function '(as let))

(in-package :tests)

(defsuite* :tests.gecode :in :tests)

#+nil
(deftest huhu
  (dotimes (i 500)
    (let ((space (asgl::make-bool-space 1000000)))
      (format t "~A~%" i)
      (asgl::delete-space space))))

(deftest make-bool-space.1
  (let (space)
    (finishes (setq space (asgl::make-bool-space 3)))
    (asgl::delete-space space)))

(deftest make-bool-space.2
  (let ((space (asgl::make-bool-space 3)))
    (is (eql :solved (asgl::space-status space)))
    (asgl::delete-space space)))

(deftest make-bool-space.3
  (let ((space (asgl::make-bool-space 3)))
    (is (eql :solved (asgl::space-status space)))
    (is (equal '((0 1) (0 1) (0 1))
               (asgl::bool-space-ins space)))
    (asgl::delete-space space)))

(deftest make-bool-space.4
  (let ((space (asgl::make-bool-space 3)))
    (asgl::post-must-be-true space 0)
    (is (eql :solved (asgl::space-status space)))
    (is (equal '(1 (0 1) (0 1))
               (asgl::bool-space-ins space)))
    (asgl::delete-space space)))

(deftest make-bool-space.5
  (let ((space (asgl::make-bool-space 5)))
    (asgl::post-must-be-true space 1)
    (asgl::let*-heap ((var (asgl::int-var-none))
                      (val (asgl::int-val-min)))
      (asgl::branch space var val))
    (is (eql 16 (asgl::dfs-count (asgl::make-dfs-engine space))))
    (asgl::delete-space space)))

(deftest make-bool-space.6
  (let ((space (asgl::make-bool-space 8)))
    (asgl::let*-heap ((var (asgl::int-var-none))
                      (val (asgl::int-val-min)))
      (asgl::branch space var val))
    (is (eql 256 (asgl::dfs-count (asgl::make-dfs-engine space))))
    (asgl::delete-space space)))

(deftest make-bool-space.7
  (let ((space (asgl::make-bool-space 8)))
    (asgl::let*-heap ((rnd (asgl::rnd 7))
                      (var (asgl::int-var-rnd rnd))
                      (val (asgl::int-val-min)))
      (asgl::branch space var val))
    (is (eql 256 (asgl::dfs-count (asgl::make-dfs-engine space))))
    (asgl::delete-space space)))

(deftest make-bool-space.8
  (let ((space (asgl::make-bool-space 8)))
    (asgl::let*-heap ((rnd (asgl::rnd 7))
                      (var (asgl::int-var-none))
                      (val (asgl::int-val-rnd rnd)))
      (asgl::branch space var val))
    (is (eql 256 (asgl::dfs-count (asgl::make-dfs-engine space))))
    (asgl::delete-space space)))

(deftest make-pr-bab-space.1
  (let (space)
    (finishes (setq space (asgl::make-pr-bab-space 3)))
    (asgl::delete-space space)))

(deftest make-pr-bab-space.2
  (let ((space (asgl::make-pr-bab-space 3)))
    (is (eql :solved (asgl::space-status space)))
    (is (equal '((0 1) (0 1) (0 1))
               (asgl::pr-bab-space-ins space)))
    (asgl::delete-space space)))

(deftest make-pr-bab-space.3
  (let ((space (asgl::make-pr-bab-space 3)))
    (asgl::post-must-be-true space 0)
    (is (eql :solved (asgl::space-status space)))
    (is (equal '(1 (0 1) (0 1))
               (asgl::pr-bab-space-ins space)))
    (asgl::delete-space space)))

(deftest make-pr-bab-space.4
  (let ((space (asgl::make-pr-bab-space 8)))
    (asgl::let*-heap ((rnd (asgl::rnd 7))
                      (var (asgl::int-var-none))
                      (val (asgl::int-val-rnd rnd)))
      (asgl::branch space var val))
    (is (eql 256 (asgl::dfs-count (asgl::make-dfs-engine space))))
    (asgl::delete-space space)))

(deftest make-int-space.1
  (let (space)
    (finishes (setq space (asgl::make-int-space 3 1 7)))
    (asgl::delete-space space)))

(deftest make-int-space.2
  (let ((space (asgl::make-int-space 3 7 11)))
    (is (eql :solved (asgl::space-status space)))
    (is (equal '((7 11) (7 11) (7 11))
               (asgl::int-space-ins space)))
    (asgl::delete-space space)))

(deftest foo3
  (let ((space (asgl::make-bool-space 3)))
    (asgl::let*-heap ((foo (asgl::int-var-none))
                      (foo2 (asgl::int-val-max)))
      (asgl::branch space foo foo2))
    (let ((space (asgl::dfs-next (asgl::make-dfs-engine space))))
      (is (equal '(1 1 1) (asgl::space-to-list space)))
      (asgl::delete-space space))
    (asgl::delete-space space)))

(deftest rnd.1
  (let ((space (asgl::make-bool-space 3)))
    (asgl::let*-heap ((r (asgl::rnd 0))
                      (var-selection (asgl::int-var-rnd r))
                      (val-selection (asgl::int-val-max)))
      (asgl::branch space var-selection val-selection))
    (let ((dfs (asgl::make-dfs-engine space)))
      (is (equal '(1 1 1) (let ((space (asgl::dfs-next dfs)))
                            (prog1
                                (asgl::space-to-list space)
                              (asgl::delete-space space)))))
      (is (equal '(1 0 1) (let ((space (asgl::dfs-next dfs)))
                            (prog1
                                (asgl::space-to-list space)
                              (asgl::delete-space space)))))
      (asgl::delete-dfs dfs))
    (asgl::delete-space space)))

(deftest rnd.2
  (let ((space (asgl::make-bool-space 3)))
    (asgl::let*-heap ((r (asgl::rnd 78))
                      (var-selection (asgl::int-var-none))
                      (val-selection (asgl::int-val-rnd r)))
      (asgl::branch space var-selection val-selection))
    (let ((dfs (asgl::make-dfs-engine space)))
      (is (equal '(1 0 1) (let ((space (asgl::dfs-next dfs)))
                            (prog1
                                (asgl::space-to-list space)
                              (asgl::delete-space space)))))
      (is (equal '(1 0 0) (let ((space (asgl::dfs-next dfs)))
                            (prog1
                                (asgl::space-to-list space)
                              (asgl::delete-space space)))))
      (asgl::delete-dfs dfs))
    (asgl::delete-space space)))

(deftest int-space.1
  (let ((space (asgl::make-int-space 3 1 3)))
    (asgl::let*-heap ((var (asgl::int-var-none))
                      (val (asgl::int-val-max)))
      (asgl::branch space var val))
    (let ((engine (asgl::make-dfs-engine space)))
      (is (not (null (asgl::dfs-next engine)))))))

(deftest int-space.2
  (let ((space (asgl::make-int-space 7 1 3)))
    (asgl::let*-heap ((var (asgl::int-var-none))
                      (val (asgl::int-val-max)))
      (asgl::branch space var val))
    (is (eql 2187 (asgl::dfs-count (asgl::make-dfs-engine space))))))

(deftest int-space.3
  (let ((space (asgl::make-int-space 7 1 3)))
    (asgl::let*-heap ((rnd (asgl::rnd 7))
                      (var (asgl::int-var-rnd rnd))
                      (val (asgl::int-val-max)))
      (asgl::branch space var val))
    (is (eql 2187 (asgl::dfs-count (asgl::make-dfs-engine space))))))

(deftest int-space.4
  (let ((space (asgl::make-int-space 7 1 3)))
    (asgl::let*-heap ((rnd (asgl::rnd 7))
                      (var (asgl::int-var-none))
                      (val (asgl::int-val-rnd rnd)))
      (asgl::branch space var val))
    (is (eql 2187 (asgl::dfs-count (asgl::make-dfs-engine space))))))
