;; -*- paul-nice-on-save:nil -*-

;; emacs: (put 'deftest 'common-lisp-indent-function 1)
;; emacs: (put 'let*-heap 'common-lisp-indent-function '(as let))
;; emacs: (put 'let-delete 'common-lisp-indent-function '(as let))

(in-package :asgl)

(use-package :myam)

(defsuite* :tests.gecode :in :tests)

#+nil
(deftest huhu
  (dotimes (i 500)
    (let ((space (make-bool-space 1000000)))
      (format t "~A~%" i)
      (delete-space space))))

(deftest make-bool-space.1
  (let (space)
    (finishes (setq space (make-bool-space 3)))
    (delete-space space)))

(deftest make-bool-space.2
  (let ((space (make-bool-space 3)))
    (is (eql :solved (space-status space)))
    (delete-space space)))

(deftest make-bool-space.3
  (let ((space (make-bool-space 3)))
    (is (eql :solved (space-status space)))
    (is (equal '((0 1) (0 1) (0 1))
               (bool-space-ins space)))
    (delete-space space)))

(deftest make-bool-space.4
  (let ((space (make-bool-space 3)))
    (post-must-be-true space 0)
    (is (eql :solved (space-status space)))
    (is (equal '(1 (0 1) (0 1))
               (bool-space-ins space)))
    (delete-space space)))

(deftest make-bool-space.5
  (let ((space (make-bool-space 5)))
    (post-must-be-true space 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (is (eql 16 (dfs-count (make-dfs-engine space))))
    (delete-space space)))

(deftest make-bool-space.6
  (let ((space (make-bool-space 8)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (is (eql 256 (dfs-count (make-dfs-engine space))))
    (delete-space space)))

(deftest make-bool-space.7
  (let ((space (make-bool-space 8)))
    (let*-heap ((rnd (rnd 7))
                (var (int-var-rnd rnd))
                (val (int-val-min)))
      (branch space var val))
    (is (eql 256 (dfs-count (make-dfs-engine space))))
    (delete-space space)))

(deftest make-bool-space.8
  (let ((space (make-bool-space 8)))
    (let*-heap ((rnd (rnd 7))
                (var (int-var-none))
                (val (int-val-rnd rnd)))
      (branch space var val))
    (is (eql 256 (dfs-count (make-dfs-engine space))))
    (delete-space space)))

(deftest make-pr-bab-space.1
  (let (space)
    (finishes (setq space (make-pr-bab-space 3)))
    (delete-space space)))

(deftest make-pr-bab-space.2
  (let ((space (make-pr-bab-space 3)))
    (is (eql :solved (space-status space)))
    (is (equal '((0 1) (0 1) (0 1))
               (pr-bab-space-ins space)))
    (delete-space space)))

(deftest make-pr-bab-space.3
  (let ((space (make-pr-bab-space 3)))
    (post-must-be-true space 0)
    (is (eql :solved (space-status space)))
    (is (equal '(1 (0 1) (0 1))
               (pr-bab-space-ins space)))
    (delete-space space)))

(deftest make-pr-bab-space.4
  (let ((space (make-pr-bab-space 8)))
    (let*-heap ((rnd (rnd 7))
                (var (int-var-none))
                (val (int-val-rnd rnd)))
      (branch space var val))
    (is (eql 256 (dfs-count (make-dfs-engine space))))
    (delete-space space)))

(deftest make-int-space.1
  (let (space)
    (finishes (setq space (make-int-space 3 1 7)))
    (delete-space space)))

(deftest make-int-space.2
  (let ((space (make-int-space 3 7 11)))
    (is (eql :solved (space-status space)))
    (is (equal '((7 11) (7 11) (7 11))
               (int-space-ins space)))
    (delete-space space)))

(deftest foo3
  (let ((space (make-bool-space 3)))
    (let*-heap ((foo (int-var-none))
                (foo2 (int-val-max)))
      (branch space foo foo2))
    (let ((space (dfs-next (make-dfs-engine space))))
      (is (equal '(1 1 1) (space-to-list space)))
      (delete-space space))
    (delete-space space)))

(deftest rnd.1
  (let ((space (make-bool-space 3)))
    (let*-heap ((r (rnd 0))
                (var-selection (int-var-rnd r))
                (val-selection (int-val-max)))
      (branch space var-selection val-selection))
    (let ((dfs (make-dfs-engine space)))
      (is (equal '(1 1 1) (let ((space (dfs-next dfs)))
                            (prog1
                                (space-to-list space)
                              (delete-space space)))))
      (is (equal '(1 0 1) (let ((space (dfs-next dfs)))
                            (prog1
                                (space-to-list space)
                              (delete-space space)))))
      (delete-dfs dfs))
    (delete-space space)))

(deftest rnd.2
  (let ((space (make-bool-space 3)))
    (let*-heap ((r (rnd 78))
                (var-selection (int-var-none))
                (val-selection (int-val-rnd r)))
      (branch space var-selection val-selection))
    (let ((dfs (make-dfs-engine space)))
      (is (equal '(1 0 1) (let ((space (dfs-next dfs)))
                            (prog1
                                (space-to-list space)
                              (delete-space space)))))
      (is (equal '(1 0 0) (let ((space (dfs-next dfs)))
                            (prog1
                                (space-to-list space)
                              (delete-space space)))))
      (delete-dfs dfs))
    (delete-space space)))

(deftest int-space.1
  (let ((space (make-int-space 3 1 3)))
    (let*-heap ((var (int-var-none))
                (val (int-val-max)))
      (branch space var val))
    (let ((engine (make-dfs-engine space)))
      (is (not (null (dfs-next engine)))))))

(deftest int-space.2
  (let ((space (make-int-space 7 1 3)))
    (let*-heap ((var (int-var-none))
                (val (int-val-max)))
      (branch space var val))
    (is (eql 2187 (dfs-count (make-dfs-engine space))))))

(deftest int-space.3
  (let ((space (make-int-space 7 1 3)))
    (let*-heap ((rnd (rnd 7))
                (var (int-var-rnd rnd))
                (val (int-val-max)))
      (branch space var val))
    (is (eql 2187 (dfs-count (make-dfs-engine space))))))

(deftest int-space.4
  (let ((space (make-int-space 7 1 3)))
    (let*-heap ((rnd (rnd 7))
                (var (int-var-none))
                (val (int-val-rnd rnd)))
      (branch space var val))
    (is (eql 2187 (dfs-count (make-dfs-engine space))))))

(deftest assert-clause.1
  (let ((space (gecode::make-bool-space 2)))
    (gecode::assert-clause space (gecode::space-vars-as-list space) nil)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-dfs-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::dfs-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0 1) (1 0) (1 1)) solutions)))
      (gecode::delete-dfs dfs))))

(deftest assert-clause.2
  (let ((space (gecode::make-bool-space 2)))
    (gecode::assert-clause space nil (gecode::space-vars-as-list space))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-dfs-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::dfs-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0 0) (0 1) (1 0)) solutions)))
      (gecode::delete-dfs dfs))))

(deftest bab-next.1
  (let ((space (gecode::make-pr-bab-space 2)))
    (gecode::assert-clause space nil (gecode::space-vars-as-list space))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-bab-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::bab-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0 0) (0 1)) solutions)))
      (gecode::delete-dfs dfs))))

(deftest bab-next.2
  (let ((space (gecode::make-pr-bab-space 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-bab-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::bab-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0 0) (0 1) (1 1)) solutions)))
      (gecode::delete-dfs dfs))))

(deftest bab-best.1
  (let ((space (gecode::make-pr-bab-space 2)))
    (gecode::assert-clause space nil (gecode::space-vars-as-list space))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-bab-engine space)))
      (gecode::delete-space space)
      (is (equal '(0 1)
                 (gecode::space-to-list (gecode::bab-best dfs))))
      (gecode::delete-dfs dfs))))

(deftest bab-best.2
  (let ((space (gecode::make-pr-bab-space 2)))
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-bab-engine space)))
      (gecode::delete-space space)
      (is (equal '(1 1)
                 (gecode::space-to-list (gecode::bab-best dfs))))
      (gecode::delete-dfs dfs))))

(deftest post-ored-vars-eql-neg-var.1
  (let ((space (gecode::make-bool-space 1)))
    (gecode:post-ored-vars-eql-neg-var space nil 0)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-dfs-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::dfs-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((1)) solutions)))
      (gecode::delete-dfs dfs))))

(deftest post-ored-vars-eql-neg-var.2
  (let ((space (gecode::make-bool-space 2)))
    (gecode:post-ored-vars-eql-neg-var space '(0) 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-dfs-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::dfs-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0 1) (1 0)) solutions)))
      (gecode::delete-dfs dfs))))

(deftest post-ored-vars-eql-neg-var.3
  (let ((space (gecode::make-bool-space 3)))
    (gecode:post-ored-vars-eql-neg-var space '(0 1) 2)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-dfs-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::dfs-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0 0 1) (0 1 0) (1 0 0) (1 1 0)) solutions)))
      (gecode::delete-dfs dfs))))

(deftest post-ored-vars-eql-neg-var.4
  (let ((space (gecode::make-bool-space 4)))
    (gecode:post-ored-vars-eql-neg-var space '(0 1 2) 3)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-dfs-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::dfs-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0 0 0 1) (0 0 1 0) (0 1 0 0) (0 1 1 0)
                     (1 0 0 0) (1 0 1 0) (1 1 0 0) (1 1 1 0))
                   solutions)))
      (gecode::delete-dfs dfs))))

(deftest post-ored-vars-eql-neg-var.5
  (let ((space (gecode::make-bool-space 3)))
    (gecode:post-ored-vars-eql-neg-var space '(0 1 2) 2)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-dfs-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::dfs-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0 1 0) (1 0 0) (1 1 0))
                   solutions)))
      (gecode::delete-dfs dfs))))

(deftest post-ored-vars-imp-neg-var.1
  (let ((space (gecode::make-bool-space 1)))
    (gecode:post-ored-vars-imp-neg-var space nil 0)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-dfs-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::dfs-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0) (1)) solutions)))
      (gecode::delete-dfs dfs))))

(deftest post-ored-vars-imp-neg-var.2
  (let ((space (gecode::make-bool-space 2)))
    (gecode:post-ored-vars-imp-neg-var space '(0) 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-dfs-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::dfs-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0 0) (0 1) (1 0)) solutions)))
      (gecode::delete-dfs dfs))))

(deftest post-ored-vars-imp-neg-var.3
  (let ((space (gecode::make-bool-space 3)))
    (gecode:post-ored-vars-imp-neg-var space '(0 1) 2)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-dfs-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::dfs-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0 0 0) (0 0 1) (0 1 0) (1 0 0) (1 1 0)) solutions)))
      (gecode::delete-dfs dfs))))

(deftest post-ored-vars-imp-neg-var.4
  (let ((space (gecode::make-bool-space 4)))
    (gecode:post-ored-vars-imp-neg-var space '(0 1 2) 3)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let ((dfs (gecode::make-dfs-engine space)))
      (gecode::delete-space space)
      (let ((solutions (loop for solution = (gecode::dfs-next dfs)
                             while solution
                             collect (gecode::space-to-list solution)
                             do (gecode::delete-space solution))))
        (is (equal '((0 0 0 0) (0 0 0 1) (0 0 1 0) (0 1 0 0) (0 1 1 0) (1 0 0 0) (1 0 1 0)
                     (1 1 0 0) (1 1 1 0))
                   solutions)))
      (gecode::delete-dfs dfs))))

;;; search-options
(deftest make-default-search-options.1
  ;; note: not deleted
  (finishes (make-default-search-options)))

(deftest make-default-search-options.2
  (finishes (delete-generic (make-default-search-options))))

(deftest search-options-clone.1
  (with-default-search-options (options)
    (is-true (search-options-clone options))))

(deftest search-options-clone.2
  (with-default-search-options (options)
    (setf (search-options-clone options) nil)
    (is-false (search-options-clone options))
    (setf (search-options-clone options) t)
    (is-true (search-options-clone options))))

(deftest search-options-threads.1
  (with-default-search-options (options)
    (is (= 1 (search-options-threads options)))))

(deftest search-options-threads.2
  (with-default-search-options (options)
    (setf (search-options-threads options) 2)
    (is (= 2 (search-options-threads options)))))

(deftest search-options-stop.1
  (with-default-search-options (options)
    (is (eql nil (search-options-stop options)))))

(deftest search-options-stop.2
  (with-default-search-options (options)
    (is (eql nil (search-options-stop options)))
    (let ((stop (make-node-stop 77)))
      (setf (search-options-stop options) stop)
      (is-true (search-options-stop options))
      (delete-generic stop))))

(deftest search-options-commit-distance.1
  (with-default-search-options (options)
    (is (eql 8 (search-options-commit-distance options)))))

(deftest search-options-commit-distance.2
  (with-default-search-options (options)
    (setf (search-options-commit-distance options) 16)
    (is (eql 16 (search-options-commit-distance options)))))

(deftest search-options-adaptive-distance.1
  (with-default-search-options (options)
    (is (eql 2 (search-options-adaptive-distance options)))))

(deftest search-options-adaptive-distance.2
  (with-default-search-options (options)
    (setf (search-options-adaptive-distance options) 16)
    (is (eql 16 (search-options-adaptive-distance options)))))

(deftest search-options-nogoods-limit.1
  (with-default-search-options (options)
    (is (eql 0 (search-options-nogoods-limit options)))))

(deftest search-options-nogoods-limit.2
  (with-default-search-options (options)
    (setf (search-options-nogoods-limit options) 16)
    (is (eql 16 (search-options-nogoods-limit options)))))

;;; stop objects
(deftest stop.1
  (with-space (space (make-bool-space 5))
    (post-must-be-true space 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (with-default-search-options (options)
      (is (eql 16 (dfs-count (make-dfs-engine-with-options space options)
                             :delete-engine t))))))

(deftest node-stop.1
  (with-space (space (make-bool-space 5))
    (post-must-be-true space 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let-delete ((options (make-default-search-options))
                 (stop (make-node-stop 77)))
      (setf (search-options-stop options) stop)
      (is (eql 16 (dfs-count (make-dfs-engine-with-options space options)
                             :delete-engine t))))))

(deftest node-stop.2
  (with-space (space (make-bool-space 10))
    (post-must-be-true space 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let-delete ((options (make-default-search-options))
                 (stop (make-node-stop 2305843009213693951)))
      (setf (search-options-stop options) stop)
      (let ((engine (make-dfs-engine-with-options space options)))
        (multiple-value-bind (count stopped)
            (dfs-count engine :error-on-stopped nil)
          (is (eql 512 count))
          (is-false stopped))
        (is (eql 1023 (getf (dfs-statistics engine) :node)))
        (delete-dfs engine)))))

(deftest node-stop.3
  (with-space (space (make-bool-space 10))
    (post-must-be-true space 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let-delete ((options (make-default-search-options))
                 (stop (make-node-stop 50)))
      (setf (search-options-stop options) stop)
      (let ((engine (make-dfs-engine-with-options space options)))
        (multiple-value-bind (count stopped)
            (dfs-count engine :error-on-stopped nil)
          (is (eql 23 count))
          (is-true stopped))
        (is (eql 51 (getf (dfs-statistics engine) :node)))
        (delete-dfs engine)))))

(deftest time-stop.1
  (with-space (space (make-bool-space 10))
    (post-must-be-true space 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let-delete ((options (make-default-search-options))
                 (stop (make-time-stop 2305843009213693951)))
      (setf (search-options-stop options) stop)
      (let-delete ((engine (make-dfs-engine-with-options space options)))
        (multiple-value-bind (count stopped)
            (dfs-count engine :error-on-stopped nil)
          (is (eql 512 count))
          (is-false stopped))
        (is (eql 1023 (getf (dfs-statistics engine) :node)))))))

(deftest fail-stop.1
  (with-space (space (make-bool-space 10))
    (post-must-be-true space 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let-delete ((options (make-default-search-options))
                 (stop (make-fail-stop 1)))
      (setf (search-options-stop options) stop)
      (let ((engine (make-dfs-engine-with-options space options)))
        (multiple-value-bind (count stopped)
            (dfs-count engine :error-on-stopped nil)
          (is (eql 512 count))
          (is-false stopped))
        (is (eql 0 (getf (dfs-statistics engine) :fail)))
        (delete-dfs engine)))))

(deftest dfs-next.1
  (with-space (space (make-bool-space 10))
    (post-must-be-true space 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let-delete ((options (make-default-search-options))
                 (stop (make-node-stop 2)))
      (setf (search-options-stop options) stop)
      (let ((engine (make-dfs-engine-with-options space options)))
        (signals engine-stopped (dfs-next engine))
        (is (eql 3 (getf (dfs-statistics engine) :node)))
        (delete-dfs engine)))))

(deftest bab-next.3
  (with-space (space (make-pr-bab-space 10))
    (post-must-be-true space 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let-delete ((options (make-default-search-options))
                 (stop (make-node-stop 2)))
      (setf (search-options-stop options) stop)
      (let ((engine (make-bab-engine-with-options space options)))
        (signals engine-stopped (bab-next engine))
        (is (eql 3 (getf (bab-statistics engine) :node)))
        (delete-bab engine)))))

(deftest bab-best.3
  (with-space (space (make-pr-bab-space 10))
    (post-must-be-true space 1)
    (let*-heap ((var (int-var-none))
                (val (int-val-min)))
      (branch space var val))
    (let-delete ((options (make-default-search-options))
                 (stop (make-node-stop 2)))
      (setf (search-options-stop options) stop)
      (let ((engine (make-bab-engine-with-options space options)))
        (signals engine-stopped (bab-best engine))
        (is (eql 3 (getf (bab-statistics engine) :node)))
        (delete-bab engine)))))
