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
  (:use :cl :early :alexandria :gecode :af-constraints))

(in-package :asgl)

#+nil(declaim (optimize (debug 3) (safety 3) (speed 0)))
(declaim (optimize (debug 0) (safety 1) (speed 3) (space 0)))

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

(defvar *use-gist* nil)

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

(defun adopt-keywords (list)
  (check-type list list)
  (mapcar (lambda (x)
            (if (char= #\- (char x 0))
                (intern (string-upcase (subseq x 1)) "KEYWORD")
                x))
          list))

(defun parse-problem (string)
  (check-type string string)
  (let ((pos (position #\- string)))
    (values
     (intern (string-upcase (subseq string 0 pos)) "KEYWORD")
     (intern (string-upcase (subseq string (1+ pos))) "KEYWORD"))))

(defun parse-problem* (string)
  (multiple-value-bind (task semantic)
      (parse-problem string)
    (values (make-task task)
            (make-semantic semantic))))

(defun task-semantic-format-as-cli-argument (task semantic)
  (format nil "~A-~A"
          (etypecase task (ee-task "EE") (se-task "SE")
                     (ds-task "DS") (dc-task "DC"))
          (etypecase semantic (complete "CO") (preferred "PR")
                     (stable "ST") (grounded "GR"))))

(deftype input () '(or string pathname vector cons))

(defgeneric make-initial-space (graph task semantic))

(defgeneric constrain-space (space semantic task graph))
(defgeneric constrain-arg-if-needed (space semantic task))
(defgeneric constrain-arg (space semantic task))

(defgeneric branch-space (space task semantic))

(defgeneric make-search-engine (space task semantic vector))
(defgeneric make-driver (semantic task))

(defgeneric drive-search-and-print (task engine))
(defgeneric drive-search-and-collect (task engine))

(defgeneric translate-problem (task semantic))

(defclass task () ())
(defclass semantic () ())

(defclass complete (semantic) ())
(defclass grounded (complete) ())
(defclass preferred (complete) ())
(defclass stable (preferred) ())

(defclass extension-task (task) ())
(defclass ee-task (extension-task) ())
(defclass se-task (extension-task) ())

(defmethod (setf task-hash) (value (task task))
  (check-type value hash-table)
  ;; nothing to do here
  )

(defclass decision-task (task)
  ((hash :accessor task-hash :initform nil)
   (arg-name :reader task-arg-name :initarg :arg-name)
   (inferred-on-no-solution :reader inferred-on-no-solution)))

(defclass dc-task (decision-task)
  ((inferred-on-no-solution :initform nil)))

(defclass ds-task (decision-task)
  ((inferred-on-no-solution :initform t)))

(defmethod task-arg ((task decision-task))
  (or (gethash (task-arg-name task) (task-hash task))
      (error "task-arg-name ~S not found in task-hash ~S containing~%~S"
             (task-arg-name task) (task-hash task)
             (hash-table-alist (task-hash task)))))

(defun prepare-space (input task semantic)
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
    (let ((space (make-initial-space graph task semantic)))
      (with-post-env-setup (space)
        (constrain-space space semantic task graph)
        (constrain-arg-if-needed space semantic task))
      (branch-space space task semantic)
      (values space vector))))



;;; problem
(defgeneric name (object)
  (:documentation "Retrieve name of object."))

(defmethod name ((object asgl::task)) (type-of object))
(defmethod name ((object asgl::semantic)) (type-of object))

(defclass problem ()
  ((graph               :reader problem-graph               :initarg :graph)
   (query-argument      :reader problem-query-argument      :initarg :query-argument)
   (query-argument-name :reader problem-query-argument-name :initarg :query-argument-name)
   (argument-names      :reader problem-argument-names      :initarg :argument-names)
   (task                :reader problem-task                :initarg :task)
   (semantic            :reader problem-semantic            :initarg :semantic)))

(defmethod print-object ((problem problem) stream)
  (print-unreadable-object (problem stream :type t)
    (format stream "~A~@[ (arg ~A)~] of AF with ~r argument~:P, ~r attack~:P"
            (asgl::task-semantic-format-as-cli-argument
             (problem-task problem)
             (problem-semantic problem))
            (problem-query-argument-name problem)
            (asgl::order (problem-graph problem))
            (asgl::size (problem-graph problem)))))

(defclass problem-with-result-printed (problem)
  ())

(defun make-problem (&key graph-input task-semantic query-argument-name
                       (class 'problem-with-result-printed))
  "problem constructor."
  (typecase graph-input
    ((or string pathname)
     (unless (probe-file graph-input)
       (error "graph-input ~S does not exist" graph-input))))
  (multiple-value-bind (graph vector hash)
      (asgl::read-graph-input graph-input)
    (when query-argument-name
      (unless (gethash query-argument-name hash)
        (error "argument ~S is not part of AF" query-argument-name)))
    (multiple-value-bind (task semantic)
        (asgl::parse-problem* (string task-semantic))
      (if (typep task 'asgl::decision-task)
          (or query-argument-name
              (error "no argument given for ~S" task))
          (or (not query-argument-name)
              (error "argument given for ~S. expected none." task)))
      (make-instance class
                     :graph graph
                     :query-argument (gethash query-argument-name hash)
                     :query-argument-name query-argument-name
                     :argument-names vector
                     :task task
                     :semantic semantic))))



(defclass driver () ())

(defclass search-all-driver (driver)
  ())

(defclass search-one-driver (driver)
  ())

(defclass search-one-decision-driver (driver)
  ((inferred-on-no-solution
    :reader inferred-on-no-solution
    :initarg :inferred-on-no-solution)))

(defmethod print-object ((driver search-one-decision-driver) stream)
  (print-unreadable-object (driver stream :identity nil :type t)
    (format stream "inferred-on-no-solution ~A"
            (inferred-on-no-solution driver))))

(defmethod make-driver (semantic (task ee-task))
  (check-type semantic semantic)
  (make-instance 'search-all-driver))

(defmethod make-driver (semantic (task se-task))
  (check-type semantic semantic)
  (make-instance 'search-one-driver))

(defmethod make-driver (semantic (task dc-task))
  (check-type semantic semantic)
  (make-instance 'search-one-decision-driver
                 :inferred-on-no-solution nil))

(defmethod make-driver (semantic (task ds-task))
  (check-type semantic semantic)
  (make-instance 'search-one-decision-driver
                 :inferred-on-no-solution t))

(defmethod make-driver ((semantic grounded) (task decision-task))
  (make-instance 'search-one-decision-driver
                 :inferred-on-no-solution t))

(defun solve (input task semantic drive-fn)
  (check-type input input)
  (check-type task task)
  (check-type semantic semantic)
  (check-type drive-fn function)
  #+fobj-leak-checks(gecode::pool-start)
  (multiple-value-bind (space vector)
      (with-timing (prepare-space input task semantic))
    (let ((engine (with-timing (make-search-engine space task semantic vector)))
          (driver (with-timing (make-driver semantic task))))
      (log* 1 "driver: ~A" driver)
      (log* 1 "engine: ~A" engine)
      (log* 1 "STARTING SEARCH")
      (multiple-value-prog1
          (with-timing (funcall drive-fn driver engine))
        #+fobj-leak-checks
        (gecode::pool-check (format nil "~S ~S ~S ~S"
                                    input task semantic drive-fn))))))

;;; ================================================================================
;;; sketches
;;; ================================================================================

(defmacro with-space ((space-var form) &body body)
  `(let ((,space-var ,form))
     (unwind-protect
          (progn ,@body)
       (when ,space-var
         (delete-space ,space-var)))))

(defmacro with-leak-checks ((msg) &body body)
  #-fobj-leak-checks(declare (ignore msg))
  `(progn
     #+fobj-leak-checks(gecode::pool-start)
     (multiple-value-prog1
         (progn ,@body)
       #+fobj-leak-checks
       (gecode::pool-check ,msg))))

(defmacro defun-leak-checks (name args &body body)
  `(defun ,name ,args
     (with-leak-checks (,(princ-to-string name))
       ,@body)))

(defun-leak-checks solve-se-gr (graph-input &key print)
  (multiple-value-bind (graph argument-names)
      (read-graph-input graph-input)
    (with-space (space (make-bool-space (order graph)))
      (with-post-env-setup (space)
        (constrain-complete graph))
      (assert (eql :solved (space-status space)))
      (if print
          (progn
            (space-print-in space argument-names)
            (terpri))
          (values (space-collect-in space argument-names)
                  t)))))

;;; ////////////////////////////////////////////////////////////////////////////////
;;; END sketches
;;; ////////////////////////////////////////////////////////////////////////////////

(defun print-answer (input task semantic)
  (cond
    ((and (typep task 'se-task)
          (typep semantic 'grounded))
     (solve-se-gr input :print t))
    (t (solve input task semantic
              #'drive-search-and-print))))

(defun collect-answer (input task semantic)
  (cond
    ((and (typep task 'se-task)
          (typep semantic 'grounded))
     (solve-se-gr input :print nil))
    (t (solve input task semantic
              #'drive-search-and-collect))))

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

(defmethod make-initial-space (graph (task task) (semantic semantic))
  (check-type graph graph)
  (log* 1 "creating initial bool-space")
  (make-bool-space (order graph)))

(defmethod make-initial-space (graph (task se-task) (semantic preferred))
  (check-type graph graph)
  (log* 1 "creating initial pr-bab-space")
  (make-pr-bab-space (order graph)))

(defmethod make-initial-space (graph (task ee-task) (semantic preferred))
  (check-type graph graph)
  (log* 1 "creating initial pr-bab-space")
  (make-pr-bab-space (order graph)))

(defmethod constrain-space (space (semantic complete) task graph)
  (check-type space SI:FOREIGN-DATA)
  (check-type task task)
  (check-type graph graph)
  (log* 1 "constrain-complete")
  (constrain-complete graph))

(defmethod constrain-space :after (space (semantic stable) task graph)
  (check-type space SI:FOREIGN-DATA)
  (check-type task task)
  (check-type graph graph)
  (log* 1 "constrain-stable")
  (constrain-stable graph))

(defmethod constrain-arg-if-needed (space semantic task)
  (check-type space SI:FOREIGN-DATA)
  (check-type semantic semantic)
  (check-type task task)
  ;; nothing to do here
  )

(defmethod constrain-arg-if-needed (space semantic (task decision-task))
  (check-type space SI:FOREIGN-DATA)
  (check-type semantic semantic)
  (check-type task task)
  (constrain-arg space semantic task))

(defmethod constrain-arg (space (semantic grounded) (task decision-task))
  (check-type space SI:FOREIGN-DATA)
  (check-type semantic semantic)
  (check-type task task)
  (log* 1 "constrain arg not to be in")
  (log* 3 "task arg is ~S" (task-arg task))
  (post-must-be-false space (task-arg task)))

(defmethod constrain-arg (space semantic (task ds-task))
  (check-type space SI:FOREIGN-DATA)
  (check-type semantic semantic)
  (check-type task task)
  (log* 1 "constrain arg not to be in")
  (log* 3 "task arg is ~S" (task-arg task))
  (post-must-be-false space (task-arg task)))

(defmethod constrain-arg (space semantic (task dc-task))
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

(defmethod branch-space (space task semantic)
  (branch-with-logging space
                       (var (int-var-degree-max))
                       (val (int-val-min))))

(defmethod branch-space (space (task se-task) (semantic preferred))
  (branch-with-logging space
                       (var (int-var-degree-max))
                       (val (int-val-max))))

(defmethod branch-space (space (task ee-task) (semantic preferred))
  (branch-with-logging space
                       (var (int-var-degree-max))
                       (val (int-val-max))))

(defmethod make-search-engine (space (task ee-task) (semantic preferred) vector)
  (check-type space SI:FOREIGN-DATA)
  (check-type semantic semantic)
  (check-type task task)
  (check-type vector vector)
  (make-instance 'preferred-all-engine
                 :sub-engine (make-search-engine space task
                                                 (make-semantic :co) vector)))

(defmethod make-search-engine (space task semantic vector)
  (check-type space SI:FOREIGN-DATA)
  (check-type semantic semantic)
  (check-type task task)
  (check-type vector vector)
  (typecase semantic
    (grounded
     (make-instance 'propagate-only-engine
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
                                                 (clone-bool-space space))))
                        (t (make-instance
                            'search-engine
                            :gecode-engine (make-dfs-engine-or-gist space)
                            :engine-vector vector))))
             (se-task (typecase semantic
                        (preferred
                         (make-instance 'search-engine
                                        :gecode-engine (make-bab-engine-or-gist space)
                                        :engine-vector vector
                                        :next-solution-fn #'bab-best))
                        (t
                         (make-instance 'search-engine
                                        :gecode-engine (make-dfs-engine-or-gist space)
                                        :engine-vector vector))))
             (dc-task (make-instance 'search-engine
                                     :gecode-engine (make-dfs-engine-or-gist space)))
             (ds-task (make-instance 'search-engine
                                     :gecode-engine (make-dfs-engine-or-gist space))))
         (delete-space space)))))

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

(defclass propagate-only-engine (search-engine)
  ()
  (:default-initargs :next-solution-fn #'gecode-engine-space-wrapper-next))

(defmethod initialize-instance :after
    ((propagate-only-engine propagate-only-engine) &key space)
  (setf (slot-value propagate-only-engine 'gecode-engine)
        (make-gecode-engine-space-wrapper :space space)))

(defclass multi-bab-engine (engine)
  ((gecode-engine :reader gecode-engine :initarg :gecode-engine)
   (engine-vector :reader engine-vector :initarg :engine-vector)
   (space :reader engine-space :initarg :space)))

(defclass preferred-all-engine (engine)
  ((sub-engine :reader sub-engine :initarg :sub-engine)))

(defgeneric search-statistics (engine))

(defmethod search-statistics ((engine search-engine))
  (when (gecode-engine engine)
    (prog1
        (dfs-statistics (gecode-engine engine))
      (when (and (gecode-engine engine)
                 (typep (gecode-engine engine) 'si:foreign-data))
        (ecase (si:foreign-data-tag (gecode-engine engine))
          (:dfs-engine (delete-dfs (gecode-engine engine)))
          (:bab-engine (delete-bab (gecode-engine engine))))
        (setf (slot-value engine 'gecode-engine) nil)))))

(defmethod search-statistics ((engine preferred-all-engine))
  (search-statistics (sub-engine engine)))

(defmethod search-statistics ((engine propagate-only-engine))
  nil)

(defmethod drive-search-and-print :around (driver engine)
  (check-type driver driver)
  (check-type engine engine)
  (call-next-method)
  (let ((statistics (search-statistics engine)))
    (log* 1 "search statistics: ~A" statistics)
    (values statistics driver engine)))

(defmethod drive-search-and-collect :around (driver engine)
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

(defmethod drive-search-and-print ((driver search-all-driver) engine)
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

(defmethod drive-search-and-collect ((driver search-all-driver) engine)
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

(defmethod drive-search-and-print ((driver search-one-driver) engine)
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

(defmethod drive-search-and-collect ((driver search-one-driver) engine)
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

(defun multi-bab-helper (engine fn)
  (let ((gecode-engine (gecode-engine engine))
        (engine-vector (engine-vector engine)))
    (step1 gecode-engine fn t engine-vector (engine-space engine))))

(defmethod drive-search-and-print (task (engine multi-bab-engine))
  (write-line "[")
  (multi-bab-helper
   engine
   (lambda (next vector first-time)
     (unless first-time
       (write-char #\,))
     (space-print-in next vector)
     (terpri)))
  (write-line "]"))

(defmethod drive-search-and-collect (task (engine multi-bab-engine))
  (let (list)
    (multi-bab-helper
     engine
     (lambda (next vector first-time)
       (declare (ignore first-time))
       (push (space-collect-in next vector) list)))
    list))

(defmethod drive-search-and-print ((task search-one-decision-driver) engine)
  (let* ((gecode-engine (gecode-engine engine))
         (next-solution-fn (next-solution-fn engine))
         (space-delete-fn (space-delete-fn engine))
         (solution (funcall next-solution-fn gecode-engine))
         (inferred-on-no-solution
           (inferred-on-no-solution task)))
    (if (null solution)
        (write-string (if inferred-on-no-solution
                          "YES"
                          "NO"))
        (progn
          (write-string (if inferred-on-no-solution
                            "NO"
                            "YES"))
          (funcall space-delete-fn solution)))
    (terpri)
    nil))

(defmethod drive-search-and-collect ((task search-one-decision-driver) engine)
  (let* ((gecode-engine (gecode-engine engine))
         (next-solution-fn (next-solution-fn engine))
         (space-delete-fn (space-delete-fn engine))
         (solution (funcall next-solution-fn gecode-engine))
         (inferred-on-no-solution
           (inferred-on-no-solution task)))
    (if (null solution)
        inferred-on-no-solution
        (prog1
            (not inferred-on-no-solution)
          (funcall space-delete-fn solution)))))

;;; DS-PR
(defmethod make-search-engine (space (task ds-task) (semantic preferred) vector)
  (check-type space SI:FOREIGN-DATA)
  (check-type semantic semantic)
  (check-type task task)
  (check-type vector vector)
  (make-instance 'ds-pr-engine :task task :space space :vector vector))

(defmethod constrain-arg-if-needed
    (space (semantic preferred) (task ds-task))
  ;; nothing to do here
  )

(defclass ds-pr-engine (engine)
  ((task :initarg :task :reader engine-task)
   (space :initarg :space :reader engine-space)
   (vector :initarg :vector :reader engine-vector)))

(defmethod gecode-engine ((engine ds-pr-engine))
  engine)

(defmethod next-solution-fn ((ds-pr-engine ds-pr-engine))
  (let ((engine (make-search-engine
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

(defmethod search-statistics ((engine ds-pr-engine))
  ;; for now
  nil)
;;; END DS-PR


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

(defun no-translate-problem (a b)
  (values a b))

(defun parse-g-arg (string)
  (let ((form (read-from-string string)))
    (cond
      ((floatp form)
       (let ((pos (position #\. string)))
         (assert pos)
         (cons (parse-integer string :end pos)
               (parse-integer string :start (1+ pos)))))
      (t form))))

(defun main% (&key (fo "apx") f p a g (gist "nil")
                (log-level "1") (timing "t")
                (eval "nil") (load nil))
  (unless (equal fo "apx")
    (error "unsupported format ~S" fo))
  (unless (xor f g)
    (error "exactly one of -f or -g must be given"))
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
    (make-problem :graph-input input
                  :task-semantic p
                  :query-argument-name a)
    (multiple-value-bind (task semantic) (parse-problem p)
      (let ((task (make-task task a))
            (semantic (make-semantic semantic)))
        (multiple-value-bind (task semantic)
            (no-translate-problem task semantic)
          (with-timing (print-answer input task semantic)))))))

#+cover
(defvar *cover-file*
  (merge-pathnames "cover.data" (asgl-home)))

(defun print-informational-message ()
  (format t "ASGL version ~A~%"
          #.(multiple-value-bind (stream exit-code)
                (ext:run-program "git" '("describe" "HEAD") :error nil)
              (assert (zerop exit-code))
              (prog1
                  (read-line stream)
                (close stream))))
  (write-line "Kilian Sprotte <kilian.sprotte@gmail.com>")
  (terpri)
  (write-line "configuration options: ")
  (write-line #.(multiple-value-bind (stream exit-code)
                    (ext:run-program "./config.status" '("--config") :error nil)
                  (assert (zerop exit-code))
                  (prog1
                      (read-line stream)
                    (close stream))))
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
              SE-CO, SE-GR, SE-PR, SE-ST]~%"))

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
  #+cover
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
         #+cover
         ((equal "--cover-report" (second ext:*command-args*))
          (cover:report :out *standard-output*
                        :all (find "--all" (cdr ext:*command-args*)
                                   :test #'equal))
          (terpri *standard-output*))
         ((equal "--repl" (second ext:*command-args*))
          (run-repl))
         ((equal "--load" (second ext:*command-args*))
          (load (third ext:*command-args*)))
         ((equal "--check" (second ext:*command-args*))
          (run-self-check (cddr ext:*command-args*)))
         (t (apply #'main% (adopt-keywords (cdr ext:*command-args*)))))
    #+cover
    (cover:save-points *cover-file*)))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
