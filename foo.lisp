  ;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

  ;;; ASGL an abstract argumentation solver in ECL and GECODE.
  ;;; Copyright (C) 2015  Kilian Sprotte

  ;;; This program is free software: you can redistribute it and/or modify
  ;;; it under the terms of the GNU General Public License as published by
  ;;; the Free Software Foundation, either version 3 of the License, or
  ;;; (at your option) any later version.

  ;;; This program is distributed in the hope that it will be useful,
  ;;; but WITHOUT ANY WARRANTY; without even the implied warranty of
  ;;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ;;; GNU General Public License for more details.

  ;;; You should have received a copy of the GNU General Public License
  ;;; along with this program.  If not, see <http://www.gnu.org/licenses/>.


  (defpackage :asgl
    (:use :cl :early :alexandria :gecode))

  (in-package :asgl)


  (declaim (optimize (debug 3) (safety 3) (speed 0)))
  #+nil(declaim (optimize (debug 0) (safety 1) (speed 3) (space 0)))


  (eval-when (:compile-toplevel :execute)
    (cover:annotate t))


   (defmacro sortf2 (a b)
     `(unless (< ,a ,b)
        (rotatef ,a ,b)))


   (defun safe-sort (list)
     (check-type list list)
     (sort (copy-list list) #'<))


   (defun subclasses (class)
     (cons class
           (mappend #'subclasses
                    (clos:class-direct-subclasses class))))


   (defun proper-subclasses (class)
     (cdr (subclasses class)))


   (defvar *use-gist* nil)


   (defvar *space*)


   (defvar *vars-vector*)


   (defvar *nand-table*)


   (defvar *expr-or-table*)


   (defvar *imp-or-table*)


   #++cover
   (defvar *cover-file*
     (merge-pathnames "cover.data" (asgl-home)))


   (defgeneric constrain-space (strategy space graph))


   (defgeneric constrain-arg-if-needed (space semantic task))


   (defgeneric constrain-arg (space semantic task))


   (defgeneric branch-space (space task semantic))


   (defgeneric make-search-engine (strategy space task semantic vector))


   (defgeneric drive-search-and-print (task engine))


   (defgeneric drive-search-and-collect (task engine))


   (defgeneric translate-problem (task semantic))


   (defgeneric search-statistics (engine))


   (defgeneric strategy-driver-initargs (strategy) (:method-combination append))


   (defgeneric strategy-driver-class (strategy))


   (eval-when (:compile-toplevel :load-toplevel :execute)
     (defun make-semantic (semantic)
       (ecase semantic
         (:co (make-instance 'complete))
         (:gr (make-instance 'grounded))
         (:st (make-instance 'stable))
         (:pr (make-instance 'preferred))))

     (defun make-task (task &optional arg)
       (check-type arg (or null string non-negative-fixnum))
       (ecase task
         (:ee (make-instance 'ee-task))
         (:se (make-instance 'se-task))
         (:dc (make-instance 'dc-task :arg-name arg))
         (:ds (make-instance 'ds-task :arg-name arg)))))


    (defclass abstract-space ()
      ((foreign-constructor :allocation :class)
       (foreign-space       :reader     foreign-space)
       (number-of-variables :reader number-of-variables :initarg :n)))

    (defmethod foreign-space ((x si:foreign-data))
      x)


    (defclass bool-space (abstract-space)
      ((foreign-constructor :initform #'make-bool-space)))


    (defclass pr-bab-space (abstract-space)
      ((foreign-constructor :initform #'make-pr-bab-space)))


    (defclass semantic () ())


    (defclass complete (semantic) ())


    (defclass grounded (complete) ())


    (defclass preferred (complete) ())


    (defclass stable (preferred) ())


    (defclass task () ())


    (defclass extension-task (task) ())


    (defclass ee-task (extension-task) ())


    (defclass se-task (extension-task) ())


    (defclass decision-task (task)
      ((hash :accessor task-hash :initform nil)
       (arg-name :reader task-arg-name :initarg :arg-name)
       (no-solution-means-inferred :reader no-solution-means-inferred)))


    (defclass dc-task (decision-task)
      ((no-solution-means-inferred :initform nil)))


    (defclass ds-task (decision-task)
      ((no-solution-means-inferred :initform t)))


    (defclass driver () ())


    (defclass search-one-driver (driver)
      ())


    (defclass search-one-decision-driver (driver)
      ((no-solution-means-inferred
        :reader no-solution-means-inferred
        :initarg :no-solution-means-inferred)))


    (defclass search-all-driver (driver)
      ())


    (defclass engine () ())


    (defclass search-engine (engine)
      ((gecode-engine    :reader gecode-engine    :initarg :gecode-engine)
       (engine-vector    :reader engine-vector    :initarg :engine-vector)
       (next-solution-fn :reader next-solution-fn :initarg :next-solution-fn)
       (space-delete-fn  :reader space-delete-fn  :initarg :space-delete-fn)
       (space-print-fn   :reader space-print-fn   :initarg :space-print-fn)
       (space-collect-fn :reader space-collect-fn :initarg :space-collect-fn))
      (:default-initargs
       :next-solution-fn #'dfs-next
       :space-delete-fn  #'delete-space
       :space-print-fn   #'space-print-in
       :space-collect-fn #'space-collect-in))


    (defclass propagate-only-engine (search-engine)
      ()
      (:default-initargs :next-solution-fn #'gecode-engine-space-wrapper-next))


    (defclass multi-bab-engine (engine)
      ((gecode-engine :reader gecode-engine :initarg :gecode-engine)
       (engine-vector :reader engine-vector :initarg :engine-vector)
       (space :reader engine-space :initarg :space)))


    (defclass preferred-all-engine (engine)
      ((sub-engine :reader sub-engine :initarg :sub-engine)))


    (defclass ds-pr-engine (engine)
      ((task :initarg :task :reader engine-task)
       (space :initarg :space :reader engine-space)
       (vector :initarg :vector :reader engine-vector)))


    (defclass strategy () ())


    (macrolet ((frob (tasks semantics)
                 `(progn
                    ,@(map-product (lambda (task semantic)
                                     `(frob2 ,task ,semantic))
                                   tasks semantics)))
               (frob2 (task semantic)
                 (let ((name (symbolicate task "-" semantic "-STRATEGY"))
                       (task-type (type-of (make-task task)))
                       (semantic-type (type-of (make-semantic semantic))))
                   `(progn
                      (defclass ,name (,task-type ,semantic-type strategy)
                        ())
                      ))))
      (frob (:ee :se :dc :ds)
            (:co :pr :gr :st)))


   (defmethod initialize-instance :after ((space abstract-space) &key n)
     (setf (slot-value space 'foreign-space)
           (funcall (slot-value space 'foreign-constructor) n)))


   (defmethod initialize-instance :after ((propagate-only-engine propagate-only-engine) &key space)
     (setf (slot-value propagate-only-engine 'gecode-engine)
           (make-gecode-engine-space-wrapper :space space)))


   (defmethod print-object ((driver search-one-decision-driver) stream)
     (print-unreadable-object (driver stream :identity nil :type t)
       (format stream "no-solution-means-inferred ~A"
               (no-solution-means-inferred driver))))


   (defmethod print-object ((engine search-engine) stream)
     (print-unreadable-object (engine stream :identity t :type t)
       (let ((*standard-output* stream))
         (pprint-logical-block
             (*standard-output*
              (list (list :next-solution-fn (next-solution-fn engine))
                    (list :space-delete-fn (space-delete-fn engine))
                    (list :space-print-fn (space-print-fn engine))
                    (list :space-collect-fn (space-collect-fn engine))))
           (loop
             for item = (pprint-pop)
             do (format t "~20A~A ~_" (first item) (second item))
             do (pprint-exit-if-list-exhausted))))))


  (defmethod space-branch ((space abstract-space)
                           (var si:foreign-data)
                           (val si:foreign-data))
    (branch (foreign-space space) var val))


  (defclass gecode-engine ()
    ((gecode-engine :reader   gecode-engine :initarg :gecode-engine)
     (space         :reader   engine-space  :initarg :space)
     (vector        :reader   engine-vector :initarg :vector)))

  (defclass dfs-engine (gecode-engine)
    ())


  (defun make-engine (class space &key vector)
    (let ((vector (or vector
                      (coerce (iota (number-of-variables space))
                              'vector)))
          (gecode-engine (prog1
                             (gecode:make-dfs-engine
                              (foreign-space space))
                           (delete-space (foreign-space space)))))
      (make-instance 'dfs-engine
                     :space space
                     :vector vector
                     :gecode-engine gecode-engine)))


  (defmethod map-solutions ((engine dfs-engine) fn &key on-no-solution)
    "Call fn on every solution found. If on-no-solution is given, this
  is always called with no arguments: When no solution is found.

  Map-solutions ensures to finalize engine."
    (let (statistics)
      (unwind-protect
           (loop
             (let ((space (gecode:dfs-next (gecode-engine engine))))
               (if (null space)
                   (progn
                     (when on-no-solution
                       (funcall on-no-solution))
                     (return))
                   (progn
                     (funcall fn (gecode::space-collect-in space (engine-vector engine)))
                     (gecode:delete-space space)))))
        (setq statistics (finalize-gecode-engine engine)))
      statistics))


  (defun list-solutions (engine)
    (let (list)
      (map-solutions engine (lambda (x) (push x list)))
      (nreverse list)))


  (defmethod first-solution ((engine dfs-engine))
    (block nil
      (map-solutions
       engine
       (lambda (x)
         (return (values x t (engine-statistics engine))))
       :on-no-solution
       (lambda ()
         (return (values nil nil (engine-statistics engine)))))))


  (defmethod last-solution ((engine dfs-engine))
    (let (solution exists statistics)
      (map-solutions
       engine
       (lambda (x)
         (setq solution x
               exists t
               statistics (engine-statistics engine)))
       :on-no-solution
       (lambda ()
         (unless exists
           (setq statistics (engine-statistics engine)))))
      (values solution exists statistics)))


  (defmethod first-solution-exists-p ((engine dfs-engine))
    (multiple-value-bind (solution exists statistics)
        (first-solution engine)
      (values exists statistics)))


  (defmethod print-solutions ((engine dfs-engine) stream)
    (let (statistics)    
      (unwind-protect
           (progn
             (write-line "[" stream)
             (loop for first-time = t then nil
                   do (let ((space (gecode:dfs-next (gecode-engine engine))))
                        (if (null space)
                            (progn                     
                              (return))
                            (progn
                              (unless first-time
                                (write-char #\, stream))
                              (gecode::space-print-in space (engine-vector engine) stream)
                              (terpri stream)
                              (gecode:delete-space space)))))
             (write-line "]" stream))
        (setq statistics (finalize-gecode-engine engine)))
      statistics))


  (defmethod print-first-solution ((engine dfs-engine) stream)
    (let ((space (gecode:dfs-next (gecode-engine engine))))
      (multiple-value-prog1
          (if (null space)
              (values nil (engine-statistics engine))
              (progn          
                (gecode::space-print-in space (engine-vector engine) stream)
                (terpri stream)
                (gecode:delete-space space)
                (values t (engine-statistics engine))))
        (finalize-gecode-engine engine))))


  (defmethod print-last-solution ((engine dfs-engine) stream)
    (let ((space (gecode:dfs-next (gecode-engine engine))))
      (multiple-value-prog1
          (if (null space)
              (values nil (engine-statistics engine))
              (let ((last space))
                (loop for next = (gecode:dfs-next (gecode-engine engine))
                      until (null next)
                      do (gecode:delete-space last)
                      do (setq last next))
                (gecode::space-print-in last (engine-vector engine) stream)
                (terpri stream)
                (gecode:delete-space last)
                (values t (engine-statistics engine))))
        (finalize-gecode-engine engine))))


  (defmethod engine-statistics ((engine gecode-engine))
    (gecode:dfs-statistics (gecode-engine engine)))


   (defmethod finalize-gecode-engine ((engine dfs-engine))
     (prog1
         (dfs-statistics (gecode-engine engine))
       (gecode:delete-dfs (gecode-engine engine))))


   (defmacro e-class-by-strategy (class)
     `(let ((class (find-class ,class)))
        (unless (eql class (strategy-engine-class strategy))
          (error "(strategy-engine-class strategy) for ~S suggests ~S ~% but should be ~S"
                 strategy (strategy-engine-class strategy) class))
        class))


   (defun make-dfs-engine-or-gist (space)
     (if (not *use-gist*)
         (make-dfs-engine space)
         (make-dfs-engine
          ;; go interactive. When user is done, we just continue with
          ;; normal search. Space is returned unchanged.
          (dfs-search-gist space))))


   (defun make-bab-engine-or-gist (space)
     (if (not *use-gist*)
         (make-bab-engine space)
         (make-bab-engine
          ;; go interactive. When user is done, we just continue with
          ;; normal search. Space is returned unchanged.
          (bab-search-gist space))))


   (defmacro with-post-env-setup ((space) &body body)
     (once-only
      (space)
      `(let ((*space* ,space)
             (*vars-vector* (coerce (space-vars-as-list ,space) 'vector))
             (*nand-table* (make-hash-table :test #'equal))
             (*expr-or-table* (make-hash-table :test #'equal))
             (*imp-or-table* (make-hash-table :test #'equal)))
         ,@body)))


   (defmacro with-local-post-env ((space-var space) &body body)
     ;; we only pretend a user could choose a space-var other than space
     (assert (eql space-var 'space))
     `(let ((,space-var ,space)
            (vars-vector *vars-vector*)
            (nand-table *nand-table*)
            (expr-or-table *expr-or-table*)
            (imp-or-table *imp-or-table*))
        (assert (eql ,space-var *space*))
        (macrolet ((%%var%% (i) `(aref vars-vector ,i)))
          (labels ((!!var!! (i) (%%var%% i))
                   (!!post-nand!! (a b)
                     (sortf2 a b)
                     (let ((key (list a b)))
                       (unless (gethash key nand-table)
                         (log* 3 "NAND ~D ~D" a b)
                         (post-nand space a b)
                         (setf (gethash key nand-table) t))))
                   (!!expr-or!! (indices)
                     (if (eql 1 (length indices))
                         (%%var%% (first indices))
                         (let ((key (safe-sort indices)))
                           (or (gethash key expr-or-table)
                               (progn
                                 (log* 3 "EXPR-OR ~D ~A" (length key) key)
                                 (setf (gethash key expr-or-table)
                                       (expr-or space
                                                (mapcar #'!!var!! indices))))))))
                   (!!expr-and-vars!! (vars)
                     (log* 3 "EXPR-AND-VARS ~D ..." (length vars))
                     (expr-and space vars))
                   (!!imp-or!! (index indices)
                     (let ((key (cons index (safe-sort indices))))
                       (unless (gethash key imp-or-table)
                         (assert-imp space (%%var%% index) (!!expr-or!! indices))
                         (setf (gethash key imp-or-table) t)))))
            ,@body))))


   (defun constrain-conflict-free (graph constrain-nand)
     (check-type graph graph)
     (check-type constrain-nand function)
     (with-timing
         (do-edges (from to graph)
           (funcall constrain-nand from to))))


   (defun constrain-in-eqv-acceptable (graph
                                       post-must-be-false
                                       post-must-be-true
                                       post-eql-indices
                                       post-eql-vars
                                       expr-and-vars
                                       expr-or
                                       var)
     (check-type graph graph)
     (check-type post-must-be-false function)
     (check-type post-must-be-true function)
     (check-type post-eql-indices function)
     (check-type post-eql-vars function)
     (check-type expr-and-vars function)
     (check-type expr-or function)
     (check-type var function)
     (with-timing
         (do-parents-grandparents (node pg graph)
           (cond
             ((equal `((,node ,node)) pg)
              (funcall post-must-be-false node))
             ((null pg)
              (funcall post-must-be-true node))
             ((some #'null (mapcar #'cdr pg))
              (funcall post-must-be-false node))
             ((and (eql 1 (length pg))
                   (eql 1 (length (cdr (first pg)))))
              (funcall post-eql-indices node (second (first pg))))
             ((eql 1 (length pg))
              (destructuring-bind ((parent . grandparents)) pg
                (declare (ignore parent))
                (funcall post-eql-vars
                         (funcall expr-or grandparents)
                         (funcall var node))))
             (t
              (funcall post-eql-vars
                       (funcall expr-and-vars
                                (mapcar expr-or (mapcar #'cdr pg)))
                       (funcall var node)))))))


   (defun constrain-complete (space graph)
     (check-type graph graph)
     (with-local-post-env (space (foreign-space space))
       (constrain-conflict-free graph #'!!post-nand!!)
       #++nil
       (constrain-not-attacked-are-in
        graph (lambda (node) (post-must-be-true space node)))
       (flet ((post-must-be-false (node)
                (post-must-be-false space node))
              (post-must-be-true (node)
                (post-must-be-true space node))
              (post-eql-indices (a b)
                (boolvar-post-eql
                 space
                 (!!var!! a)
                 (!!var!! b)))
              (post-eql-vars (a b)
                (boolvar-post-eql space a b)))
         (constrain-in-eqv-acceptable
          graph
          #'post-must-be-false
          #'post-must-be-true
          #'post-eql-indices
          #'post-eql-vars
          #'!!expr-and-vars!!
          #'!!expr-or!!
          #'!!var!!))))


   (defun constrain-stable (space graph)
     (check-type graph graph)
     (with-local-post-env (space (foreign-space space))
       (with-timing
           (do-parents (node parents graph)
             (when parents
               (assert-imp
                space
                (expr-not space (!!var!! node))
                (!!expr-or!! parents)))))))


   (deftype input () '(or string pathname vector cons))


   (defmethod (setf task-hash) (value (task task))
     (check-type value hash-table)
     ;; noop
     )


   (defmethod task-arg ((task decision-task))
     (or (gethash (task-arg-name task) (task-hash task))
         (error "task-arg-name ~S not found in task-hash ~S containing~%~S"
                (task-arg-name task) (task-hash task)
                (hash-table-alist (task-hash task)))))


   (defun prepare-space (strategy input task semantic)
     (check-type input input)
     (check-type task task)
     (check-type semantic semantic)
     (multiple-value-bind (graph vector hash)
         (with-timing (read-graph-input input))
       (setf (task-hash task) hash)
       (log* 1 "input AF consisting of ~A arguments and ~A attacks"
             (order graph) (size graph))
       (log* 2 "indegrees:  ~A" (summary (indegrees graph)))
       (log* 2 "outdegrees: ~A" (summary (outdegrees graph)))
       (let ((space (strategy-make-space strategy (order graph))))
         (check-type space abstract-space)
         (with-post-env-setup ((foreign-space space))
           #++nil(error "here")
           (dolist (constraint (strategy-constraints strategy))
             (funcall constraint space graph))
           #++nil(error "here2")
           (let ((constraint-arg (strategy-constraint-arg strategy)))
             (when constraint-arg
               (funcall constraint-arg
                        (foreign-space space) (task-arg task))))
           #++nil(error "here3"))
         (branch-space (foreign-space space) task semantic)      
         (values space vector))))


    (defun solve (strategy input task semantic drive-fn)
      (check-type strategy strategy)
      (check-type input input)
      (check-type task task)
      (check-type semantic semantic)
      (check-type drive-fn function)
      (multiple-value-bind (space vector)
          (with-timing (prepare-space strategy input task semantic))
        (let ((engine (with-timing (make-search-engine strategy space task semantic vector)))
              (driver (strategy-make-driver strategy)))
          (log* 1 "driver: ~A" driver)
          (log* 1 "engine: ~A" engine)
          (log* 1 "STARTING SEARCH")
          (with-timing (funcall drive-fn driver engine)))))


    (defun print-answer (strategy input task semantic)
      (solve strategy input task semantic
             #'drive-search-and-print))


    (defun collect-answer (strategy input task semantic)
      (solve strategy input task semantic
             #'drive-search-and-collect))


    (defmethod constrain-arg-if-needed ((space abstract-space) (semantic semantic) (task task))
      (constrain-arg-if-needed (foreign-space space) semantic task))


    (defmethod constrain-arg-if-needed ((space abstract-space) (semantic semantic) (task task))
      (check-type space SI:FOREIGN-DATA)
      (check-type semantic semantic)
      (check-type task task)
      ;; noop
      )


    (defmethod constrain-arg-if-needed ((space abstract-space) (semantic semantic) (task decision-task))
      (check-type space SI:FOREIGN-DATA)
      (check-type semantic semantic)
      (check-type task task)
      (constrain-arg space semantic task))


    (defmethod constrain-arg ((space SI:FOREIGN-DATA) (semantic grounded) (task decision-task))
      (check-type space SI:FOREIGN-DATA)
      (check-type semantic semantic)
      (check-type task task)
      (log* 1 "constrain arg not to be in")
      (log* 3 "task arg is ~S" (task-arg task))
      (post-must-be-false space (task-arg task)))


    (defmethod constrain-arg ((space si:foreign-data) (semantic semantic) (task ds-task))
      (check-type space SI:FOREIGN-DATA)
      (check-type semantic semantic)
      (check-type task task)
      (log* 1 "constrain arg not to be in")
      (log* 3 "task arg is ~S" (task-arg task))
      (post-must-be-false space (task-arg task)))


    (defmethod constrain-arg ((space si:foreign-data) (semantic semantic) (task dc-task))
      (check-type space SI:FOREIGN-DATA)
      (check-type semantic semantic)
      (check-type task task)
      (log* 1 "constrain arg to be in")
      (log* 3 "task arg is ~S" (task-arg task))
      (post-must-be-true space (task-arg task)))


   (defmacro branch-with-logging (space &body body)
     `(let*-heap (,@body)
                 (log* 1 "branch ~{~A~^ ~}" ',body)
                 (branch ,space var val)))


  #++nil
  (defmethod branch-space ((space abstract-space) (task task) (semantic semantic))
    (branch-space (foreign-space space) task semantic))


    (defmethod branch-space ((space si:foreign-data) (task task) (semantic semantic))
      (branch-with-logging space
                           (var (int-var-degree-max))
                           (val (int-val-min))))


    (defmethod branch-space ((space si:foreign-data) (task se-task) (semantic preferred))
      (branch-with-logging space
                           (var (int-var-degree-max))
                           (val (int-val-max))))


    (defmethod branch-space ((space si:foreign-data) (task ee-task) (semantic preferred))
      (branch-with-logging space
                           (var (int-var-degree-max))
                           (val (int-val-max))))


    (defmethod make-search-engine ((strategy strategy) (space abstract-space) (task task) (semantic semantic) (vector vector))
      (make-search-engine strategy (foreign-space space) task semantic vector))


    (defmethod make-search-engine ((strategy ds-st-strategy) (space abstract-space) (task task) (semantic semantic) (vector vector))
      (make-search-engine strategy (foreign-space space) task semantic vector))


    (defmethod make-search-engine ((strategy ee-st-strategy) (space abstract-space) (task task) (semantic semantic) (vector vector))
      (make-search-engine strategy (foreign-space space) task semantic vector))


    (defmethod make-search-engine ((strategy ee-pr-strategy) (space abstract-space) (task ee-task) (semantic preferred) (vector vector))
      (check-type semantic semantic)
      (check-type task task)
      (check-type vector vector)
      (make-instance (e-class-by-strategy 'preferred-all-engine)
                     :sub-engine (let ((task task)
                                       (semantic (make-semantic :co)))
                                   (make-search-engine (choose-strategy* task semantic)
                                                       space task
                                                       (make-semantic :co) vector))))


    (defmethod make-search-engine ((strategy ds-st-strategy)
                                   (space abstract-space) (task task) (semantic semantic) (vector vector))
      (make-normal-engine strategy space vector))


    (defmethod make-search-engine ((strategy ee-st-strategy)
                                   (space abstract-space) (task task) (semantic semantic) (vector vector))
      (make-normal-engine strategy space vector))


    (defmethod make-search-engine (strategy space task semantic vector)
      (check-type space SI:FOREIGN-DATA)
      (check-type semantic semantic)
      (check-type task task)
      (check-type vector vector)
      (typecase semantic
        (grounded
         (make-instance (e-class-by-strategy 'propagate-only-engine)
                        :space space
                        :engine-vector vector))
        (t (prog1
               (etypecase task
                 (ee-task (typecase semantic
                            (preferred
                             (make-instance 'multi-bab-engine
                                            :gecode-engine (make-bab-engine-or-gist space)
                                            :engine-vector vector
                                            :space (progn
                                                     (space-status space)
                                                     (clone-space space))))
                            (t (make-instance
                                'search-engine
                                :gecode-engine (make-dfs-engine-or-gist space)
                                :engine-vector vector))))
                 (se-task (typecase semantic
                            (preferred
                             (make-normal-engine-bab strategy space vector))
                            (t
                             (make-normal-engine strategy space vector))))
                 (dc-task (make-normal-engine strategy space vector))
                 (ds-task (make-normal-engine strategy space vector)))
             (delete-space space)))))


  (defmethod make-search-engine (strategy space (task ds-task) (semantic preferred) vector)
      (check-type space SI:FOREIGN-DATA)
      (check-type semantic semantic)
      (check-type task task)
      (check-type vector vector)
    (make-instance 'ds-pr-engine :task task :space space :vector vector))


   (defun make-normal-engine (strategy space vector)
     (make-instance (e-class-by-strategy 'search-engine)
                    :gecode-engine (make-dfs-engine-or-gist space)
                    :engine-vector vector))


   (defun make-normal-engine-bab (strategy space vector)
     (make-instance (e-class-by-strategy 'search-engine)
                    :gecode-engine (make-bab-engine-or-gist space)
                    :engine-vector vector
                    :next-solution-fn #'bab-best))


   (defstruct gecode-engine-space-wrapper
     space)


   (defun gecode-engine-space-wrapper-next (wrapper)
     (check-type wrapper gecode-engine-space-wrapper)
     (let ((space (gecode-engine-space-wrapper-space wrapper)))
       (when space
         (prog1
             (case (space-status space)
               (:failed (delete-space space))
               (t space))
           (setf (gecode-engine-space-wrapper-space wrapper)
                 nil)))))


    (defmethod search-statistics ((engine search-engine))
      (dfs-statistics (gecode-engine engine)))


    (defmethod search-statistics ((engine preferred-all-engine))
      (search-statistics (sub-engine engine)))


    (defmethod search-statistics ((engine propagate-only-engine))
      nil)


    (defmethod search-statistics ((engine ds-pr-engine))
      ;; for now
      nil)


     (defmethod drive-search-and-print :around ((driver driver) (engine engine))
       (check-type driver driver)
       (check-type engine engine)
       (call-next-method)
       (let ((statistics (search-statistics engine)))
         (log* 1 "search statistics: ~A" statistics)
         (values statistics driver engine)))


     (defmethod drive-search-and-collect :around ((driver driver) (engine engine))
       (check-type driver driver)
       (check-type engine engine)
       (multiple-value-bind (extension exists-p)
           (call-next-method)
         (values
          extension
          exists-p
          (search-statistics engine)
          driver
          engine)))


     (defmethod drive-search-and-print ((task search-all-driver)
                                        (engine preferred-all-engine))
       (write-line "[")
       (loop
         with first-time = t
         for solution in (drive-search-and-collect task engine)
         do (if first-time
                (setq first-time nil)
                (write-char #\,))
         do (format t "[~{~A~^,~}]" solution)
         do (terpri))
       (write-line "]"))


     (defmethod drive-search-and-collect ((task search-all-driver)
                                          (engine preferred-all-engine))
       (let ((complete-all (drive-search-and-collect task (sub-engine engine))))
         (remove-duplicates
          (sort complete-all #'< :key #'length)
          :test #'subsetp)))


     (defmethod drive-search-and-print ((driver search-all-driver) (engine engine))
       (let ((gecode-engine (gecode-engine engine))
             (engine-vector (engine-vector engine))
             (next-solution-fn (next-solution-fn engine))
             (space-delete-fn (space-delete-fn engine))
             (space-print-fn (space-print-fn engine)))
         (write-line "[")
         (loop
           with first-time = t
           for solution = (funcall next-solution-fn gecode-engine)
           until (null solution)
           do (if first-time
                  (setq first-time nil)
                  (write-char #\,))
           do (funcall space-print-fn solution engine-vector)
           do (funcall space-delete-fn solution)
           do (terpri))
         (write-line "]")
         nil))


     (defmethod drive-search-and-collect ((driver search-all-driver) (engine engine))
       (let ((gecode-engine (gecode-engine engine))
             (engine-vector (engine-vector engine))
             (next-solution-fn (next-solution-fn engine))
             (space-delete-fn (space-delete-fn engine))
             (space-collect-fn (space-collect-fn engine)))
         (loop
           for solution = (funcall next-solution-fn gecode-engine)
           until (null solution)
           collect (funcall space-collect-fn solution engine-vector)
           do (funcall space-delete-fn solution))))


     (defmethod drive-search-and-print ((driver search-one-driver) (engine engine))
       (let ((gecode-engine (gecode-engine engine))
             (engine-vector (engine-vector engine))
             (next-solution-fn (next-solution-fn engine))
             (space-delete-fn (space-delete-fn engine))
             (space-print-fn (space-print-fn engine)))
         (let ((space (funcall next-solution-fn gecode-engine)))
           (if (null space)
               (write-string "NO")
               (progn
                 (funcall space-print-fn space engine-vector)
                 (funcall space-delete-fn space))))
         (terpri)
         nil))


     (defmethod drive-search-and-collect ((driver search-one-driver) (engine engine))
       (let ((gecode-engine (gecode-engine engine))
             (engine-vector (engine-vector engine))
             (next-solution-fn (next-solution-fn engine))
             (space-delete-fn (space-delete-fn engine))
             (space-collect-fn (space-collect-fn engine)))
         (let ((space (funcall next-solution-fn gecode-engine)))
           (if (null space)
               (values nil nil)
               (values (prog1
                           (funcall space-collect-fn space engine-vector)
                         (funcall space-delete-fn space))
                       t)))))


     (defmethod drive-search-and-print ((task task) (engine multi-bab-engine))
       (multi-bab-search-and-print engine))


   (defmethod drive-search-and-collect ((task task) (engine multi-bab-engine))
     (multi-bab-search-and-collect engine))


   (defmethod drive-search-and-print ((task search-all-driver) (engine multi-bab-engine))
     (multi-bab-search-and-print engine))


   (defmethod drive-search-and-collect ((task search-all-driver) (engine multi-bab-engine))
     (multi-bab-search-and-collect engine))


   (defmethod drive-search-and-print ((task search-one-decision-driver) (engine engine))
       (let* ((gecode-engine (gecode-engine engine))
              (next-solution-fn (next-solution-fn engine))
              (space-delete-fn (space-delete-fn engine))
              (solution (funcall next-solution-fn gecode-engine))
              (no-solution-means-inferred
                (no-solution-means-inferred task)))
         (if (null solution)
             (write-string (if no-solution-means-inferred
                               "YES"
                               "NO"))
             (progn
               (write-string (if no-solution-means-inferred
                                 "NO"
                                 "YES"))
               (funcall space-delete-fn solution)))
         (terpri)
         nil))


   (defmethod drive-search-and-collect ((task search-one-decision-driver) (engine engine))
       (let* ((gecode-engine (gecode-engine engine))
              (next-solution-fn (next-solution-fn engine))
              (space-delete-fn (space-delete-fn engine))
              (solution (funcall next-solution-fn gecode-engine))
              (no-solution-means-inferred
                (no-solution-means-inferred task)))
         (if (null solution)
             no-solution-means-inferred
             (prog1
                 (not no-solution-means-inferred)
               (funcall space-delete-fn solution)))))


    (defun multi-bab-helper (engine fn)
      (let ((gecode-engine (gecode-engine engine))
            (engine-vector (engine-vector engine)))
        (step1 gecode-engine fn t engine-vector (engine-space engine))))


    (defun multi-bab-search-and-print (engine)
      (write-line "[")
      (multi-bab-helper
       engine
       (lambda (next vector first-time)
         (unless first-time
           (write-char #\,))
         (space-print-in next vector)
         (terpri)))
      (write-line "]"))


    (defun multi-bab-search-and-collect (engine)
      (let (list)
        (multi-bab-helper
         engine
         (lambda (next vector first-time)
           (declare (ignore first-time))
           (push (space-collect-in next vector) list)))
        list))


    (defun step1 (bab fn first-time vector master)
      (let ((next (bab-best bab)))
        (when next
          (funcall fn next vector first-time)
          (when first-time
            (setq first-time nil))
          (constrain-not-subset master next)
          (let ((status (prog1
                            (space-status master)
                          (delete-space next))))
            (ecase status
              (:failed)
              (:solved
               (funcall fn master vector first-time))
              (:branch
               (let ((slave (clone-bool-space master)))
                 (delete-bab bab)
                 (step1 (prog1
                            (make-bab-engine-or-gist slave)
                          (delete-space slave))
                        fn first-time vector master))))))))


   (defmethod constrain-arg-if-needed ((space abstract-space) (semantic preferred) (task ds-task))
     ;; noop
     )


   (defmethod gecode-engine ((engine ds-pr-engine))
     engine)


   (defmethod next-solution-fn ((ds-pr-engine ds-pr-engine))
     (let ((engine (make-search-engine
                    (choose-strategy* (make-task :ee)
                                      (make-semantic :pr))
                    (engine-space ds-pr-engine)
                    (make-task :ee)
                    (make-semantic :pr)
                    (coerce (iota (length (engine-vector ds-pr-engine)))
                            'vector))))
       (lambda (arg)
         (declare (ignore arg))
         ;; give t here if you can find a preferred extension that does
         ;; not contain arg
         (let ((solutions
                 (drive-search-and-collect
                  (make-instance 'search-all-driver) engine))
               (arg (task-arg (engine-task ds-pr-engine))))
           (some (lambda (solution) (not (member arg solution)))
                 solutions)))))


   (defmethod space-delete-fn ((engine ds-pr-engine))
     (lambda (arg) (declare (ignore arg))))


   (macrolet ((translate ((from-task from-semantic) arrow (to-task to-semantic))
                (declare (ignore arrow))
                (let ((from-task-type (type-of (make-task from-task)))
                      (from-semantic-type (type-of (make-semantic from-semantic)))
                      (task-change (not (eql from-task to-task)))
                      (semantic-change (not (eql from-semantic to-semantic))))
                  `(defmethod translate-problem ((task ,from-task-type)
                                                 (semantic ,from-semantic-type))
                     (let ((new-task
                             ,(if task-change
                                  (if (subtypep from-task-type 'decision-task)
                                      `(make-task ,to-task (task-arg-name task))
                                      `(make-task ,to-task))
                                  'task))
                           (new-semantic
                             ,(if semantic-change
                                  `(make-semantic ,to-semantic)
                                  'semantic)))
                       ,@ (when (or task-change semantic-change)
                            '((log* 1 "translate from ~A ~A to ~A ~A"
                               (type-of task) (type-of semantic)
                               (type-of new-task) (type-of new-semantic))))
                       (values new-task new-semantic))))))
     (translate (:se :co) -> (:se :gr))
     (translate (:ds :co) -> (:ds :gr))
     (translate (:dc :pr) -> (:dc :co))
       ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
     ;; standard
       ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
     ;; co
     (translate (:dc :co) -> (:dc :co))
     (translate (:ee :co) -> (:ee :co))
     ;; gr
     (translate (:dc :gr) -> (:dc :gr))
     (translate (:ds :gr) -> (:ds :gr))
     (translate (:ee :gr) -> (:ee :gr))
     (translate (:se :gr) -> (:se :gr))
     ;; pr
     (translate (:ds :pr) -> (:ds :pr))
     (translate (:ee :pr) -> (:ee :pr))
     (translate (:se :pr) -> (:se :pr))
     ;; st
     (translate (:dc :st) -> (:dc :st))
     (translate (:ds :st) -> (:ds :st))
     (translate (:ee :st) -> (:ee :st))
     (translate (:se :st) -> (:se :st)))


    (defmethod strategy-task-class ((strategy ee-task)) (find-class 'ee-task))


    (defmethod strategy-task-class ((strategy se-task)) (find-class 'se-task))


    (defmethod strategy-task-class ((strategy dc-task)) (find-class 'dc-task))


    (defmethod strategy-task-class ((strategy ds-task)) (find-class 'ds-task))


    (defmethod strategy-semantic-class ((strategy complete)) (find-class 'complete))


    (defmethod strategy-semantic-class ((strategy preferred)) (find-class 'preferred))


    (defmethod strategy-semantic-class ((strategy grounded)) (find-class 'grounded))


    (defmethod strategy-semantic-class ((strategy stable)) (find-class 'stable))


    (defmethod strategy-driver-class ((strategy ee-task)) (find-class 'search-all-driver))


    (defmethod strategy-driver-class ((strategy se-task)) (find-class 'search-one-driver))


    (defmethod strategy-driver-class ((strategy decision-task)) (find-class 'search-one-decision-driver))


    (defmethod strategy-driver-initargs append ((strategy extension-task)) nil)


    (defmethod strategy-driver-initargs append ((strategy dc-task))
      '(:no-solution-means-inferred nil))


    (defmethod strategy-driver-initargs append ((strategy ds-task))
      '(:no-solution-means-inferred t))


    (defmethod strategy-constraints ((strategy complete))
      (list 'constrain-complete))


    (defmethod strategy-constraints ((strategy stable))
      (list 'constrain-complete 'constrain-stable))


    (defmethod strategy-constraint-arg ((strategy strategy))
      nil)


    (defmethod strategy-constraint-arg ((strategy dc-task))
      'post-must-be-true)


    (defmethod strategy-constraint-arg ((strategy ds-task))
      'post-must-be-false)


    (defun strategy-make-driver (strategy)
      (apply #'make-instance (strategy-driver-class strategy)
             (strategy-driver-initargs strategy)))


    (defun strategy-make-space (strategy number-of-variables)
      (make-instance (strategy-space-class strategy) :n number-of-variables))


    (defmethod strategy-driver-initargs append ((strategy dc-gr-strategy))
      '(:no-solution-means-inferred t))


     (defmethod strategy-space-class ((strategy se-pr-strategy))
       (find-class 'pr-bab-space))


    (defmethod strategy-space-class ((strategy strategy))
      (find-class 'bool-space))


    (defmethod strategy-constraint-arg ((strategy dc-gr-strategy))
      'post-must-be-false)


    (defmethod strategy-constraint-arg ((strategy ds-pr-strategy))
      nil)


    (defmethod strategy-engine-class ((strategy ds-pr-strategy))
      (find-class 'ds-pr-engine))


    (defmethod strategy-engine-class ((strategy ee-pr-strategy))
      (find-class 'preferred-all-engine))


    (defmethod strategy-engine-class ((strategy strategy))
      (find-class 'search-engine))


    (defmethod strategy-engine-class ((strategy grounded))
      (find-class 'propagate-only-engine))


    (defun list-strategy-classes ()
      (proper-subclasses (find-class 'strategy)))


    (defun list-strategies ()
      (mapcar #'make-instance (list-strategy-classes)))


    (defmethod find-applicable-strategies ((task standard-class) (semantic standard-class))
      (remove-if (lambda (strategy)
                   (or (not (eql task (strategy-task-class strategy)))
                       (not (eql semantic (strategy-semantic-class strategy)))))
                 (list-strategies)))


    (defmethod find-applicable-strategies ((task task) (semantic semantic))
      (find-applicable-strategies (class-of task) (class-of semantic)))


    (defun choose-strategy (task semantic)
      (let ((strategies (find-applicable-strategies task semantic)))
        (when (null strategies)
          (error "no strategies found"))
        (unless (eql 1 (length strategies))
          (cerror "take first" "more than one strategy ~S" strategies))
        (first strategies)))


    (defun choose-strategy* (task semantic)
      (handler-bind ((error (lambda (c) (continue c))))
        (choose-strategy task semantic)))


    (defmethod describe-object ((strategy strategy) stream)
      (format stream "~S~%~@{  ~A~30T~A~%~}"
              (type-of strategy)
              ;; 'strategy-task-class (strategy-task-class strategy)
              ;; 'strategy-semantic-class (strategy-semantic-class strategy)
              'strategy-driver-class (strategy-driver-class strategy)
              'strategy-driver-initargs (strategy-driver-initargs strategy)
              'strategy-space-class (strategy-space-class strategy)
              'strategy-constraints (strategy-constraints strategy)
              'strategy-constraint-arg (strategy-constraint-arg strategy)
              'strategy-engine-class (strategy-engine-class strategy)))


    (defun describe-strategies (&optional (strategies (list-strategies)))
      (mapc #'describe strategies)
      nil)


    (defun describe-all-strategies-or-for-problem (problem)
      (if problem
          (multiple-value-bind (task semantic) (parse-problem problem)
            (describe-strategies
             (find-applicable-strategies (make-task task)
                                         (make-semantic semantic))))
          (describe-strategies)))


    (defun print-informational-message ()
      (write-line "ASGL version 0.1.4")
      (write-line "Kilian Sprotte <kilian.sprotte@gmail.com>")
      (terpri)
      (write-line "Copyright (C) 2015  Kilian Sprotte")
      (write-line "This program comes with ABSOLUTELY NO WARRANTY.")
      (write-line "This is free software, and you are welcome to redistribute it")
      (write-line "under certain conditions."))


    (defun print-supported-graph-formats ()
      (write-line "[apx]"))


    (defun print-supported-problems ()
      (format t "[DC-CO, DC-GR, DC-PR, DC-ST, ~
                    DS-CO, DS-GR, DS-PR, DS-ST, ~
                    EE-CO, EE-GR, EE-PR, EE-ST, ~
                    SE-CO, SE-GR, SE-PR, SE-ST]"))


    (defun run-repl ()
      (let ((init-file (merge-pathnames ".asglrc" (user-homedir-pathname))))
        (when (probe-file init-file)
          (load init-file))
        (si:top-level)))


    (defun run-self-check (test-files)
      (dolist (file (directory
                     (merge-pathnames "tests/support/*.lisp"
                                      (asgl-home))))
        (compile-file-if-needed file t))
      (let ((test-files (or test-files
                            (directory
                             (merge-pathnames "tests/*.lisp"
                                              (asgl-home))))))
        (dolist (file test-files)
          (load file)))
      (format t "Running self-check... This will take around 5 min.~%")
      (if (myam:run! :tests)
          (format t "~&SELF-CHECK PASSED SUCCESSFULLY~%")
          (progn
            (format t "~&**********************************~%")
            (format t "~&SELF-CHECK FAILED something is wrong~%")
            (format t "~&**********************************~%")
            (ext:quit 1))))


    (defun adopt-keywords (list)
      (check-type list list)
      (mapcar (lambda (x)
                (if (char= #\- (char x 0))
                    (intern (string-upcase (subseq x 1)) "KEYWORD")
                    x))
              list))


    (defun parse-g-arg (string)
      (let ((form (read-from-string string)))
        (cond
          ((floatp form)
           (let ((pos (position #\. string)))
             (assert pos)
             (cons (parse-integer string :end pos)
                   (parse-integer string :start (1+ pos)))))
          (t form))))


    (defun parse-problem (string)
      (check-type string string)
      (let ((pos (position #\- string)))
        (values
         (intern (string-upcase (subseq string 0 pos)) "KEYWORD")
         (intern (string-upcase (subseq string (1+ pos))) "KEYWORD"))))


    (defun main%% (input p a)
      (multiple-value-bind (task semantic) (parse-problem p)
        (let ((task (make-task task a))
              (semantic (make-semantic semantic)))
          (multiple-value-bind (task semantic)
              (translate-problem task semantic)
            (let ((strategy (choose-strategy* task semantic)))
              (with-timing (print-answer strategy input task semantic)))))))


    (defun main% (&key (fo "apx") f p a g (gist "nil")
                    (log-level "1") (timing "t")
                    (eval "nil") (load nil))
      (assert (equal fo "apx"))
      (assert (xor f g))
      (let* ((*use-gist* (read-from-string gist))
             (*log-level* (read-from-string log-level))
             (*with-timing* (read-from-string timing))
             (g (when g (parse-g-arg g)))
             (input (or f g))
             (a (when a
                  (if g (parse-integer a) a)))
             (eval (read-from-string eval)))
        (check-type *log-level* log-level)
        (when load (load load))
        (when eval (eval eval))
        (main%% input p a)))


  (defun cl-user::main ()
    (setq *debugger-hook* (lambda (c old)
                            (declare (ignore old))
                            (let ((*print-length* 3)
                                  (*print-level* 3))
                              (ext:dump-c-backtrace 32)
                              (terpri *error-output*)
                              (print-error-log *error-output* c)
                              (format t "ERROR: ~A~%" c)
                              (ext:quit 1))))
    (setq *package* (find-package :asgl))
    (ext:install-bytecodes-compiler)
    (let ((*error-output* (make-broadcast-stream))
          (*standard-output* (make-broadcast-stream))
          (*trace-output* (make-broadcast-stream))
          (*terminal-io* (make-broadcast-stream))
          (*debug-io* (make-broadcast-stream))
          (*query-io* (make-broadcast-stream)))
      (load "/home/paul/unis/github/asgl/foo.lisp"))
    #++cover
    (when (probe-file *cover-file*)
      (cover:load-points *cover-file*))
    (unwind-protect
         (cond
           ((null (cdr ext:*command-args*))
            (print-informational-message))
           ((equal "--formats" (second ext:*command-args*))
            (print-supported-graph-formats))
           ((equal "--problems" (second ext:*command-args*))
            (print-supported-problems))
           ((equal "--strategies" (second ext:*command-args*))
            (describe-all-strategies-or-for-problem
             (third ext:*command-args*)))
           #++cover
           ((equal "--cover-report" (second ext:*command-args*))
            (cover:report :out *standard-output*
                          :all (find "--all" (cdr ext:*command-args*)
                                     :test #'equal))
            (terpri *standard-output*))
           ((equal "--repl" (second ext:*command-args*))
            (run-repl))
           ((equal "--check" (second ext:*command-args*))
            (run-self-check (cddr ext:*command-args*)))
           (t (apply #'main% (adopt-keywords (cdr ext:*command-args*)))))
      #++cover
      (cover:save-points *cover-file*)))


   (eval-when (:compile-toplevel :execute)
     (cover:annotate nil))


