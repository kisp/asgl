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

(in-package :cl-user)

#+nil(declaim (optimize (debug 3) (safety 3) (speed 0)))
(declaim (optimize (debug 0) (safety 1) (speed 3) (space 0)))

(ffi:clines "#include \"Foo.h\"")
(ffi:clines "#include \"PrBABSpace.h\"")

(eval-when (:compile-toplevel :load-toplevel :execute)
  (use-package :early))

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

(defun make-foo (n)
  (ffi:c-inline (n) (:int) :pointer-void "{ @(return 0) = new v1::Foo(#0); }"))

(defun make-pr-bab-space (n)
  (ffi:c-inline (n) (:int) :pointer-void "{ @(return 0) = new v1::PrBABSpace(#0); }"))

(defun expr-or (space boolvars)
  "Return a new boolvar that is constrained to be the OR of boolvars."
  (ffi:c-inline (space boolvars) (:pointer-void :object) :pointer-void
                "
v1::Foo* foo = ((v1::Foo*)(#0));

int len = (int)ecl_length(#1);
Gecode::BoolVarArgs a(len);

cl_object mylist = #1;
int __i = 0;
while (!Null(mylist)) {
  cl_object mycar = ecl_car(mylist);
  a[__i] = *((Gecode::BoolVar*)ecl_to_pointer(mycar));
  mylist = ecl_cdr(mylist);
  __i++;
}

Gecode::BoolVar* u = new Gecode::BoolVar(*foo, 0, 1);

rel(*foo, Gecode::BOT_OR, a, *u);

@(return 0) = u;

"))

(defun expr-and (space boolvars)
  "Return a new boolvar that is constrained to be the AND of boolvars."
  (ffi:c-inline (space boolvars) (:pointer-void :object) :pointer-void
                "
v1::Foo* foo = ((v1::Foo*)(#0));

int len = (int)ecl_length(#1);
Gecode::BoolVarArgs a(len);

cl_object mylist = #1;
int __i = 0;
while (!Null(mylist)) {
  cl_object mycar = ecl_car(mylist);
  a[__i] = *((Gecode::BoolVar*)ecl_to_pointer(mycar));
  mylist = ecl_cdr(mylist);
  __i++;
}

Gecode::BoolVar* u = new Gecode::BoolVar(*foo, 0, 1);

rel(*foo, Gecode::BOT_AND, a, *u);

@(return 0) = u;

"))

(defun expr-not (space boolvar)
  "Return a new boolvar that is constrained to be the NOT of boolvar."
  (ffi:c-inline (space boolvar) (:pointer-void :pointer-void) :pointer-void
                "
v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVar* a = ((Gecode::BoolVar*)(#1));

Gecode::BoolVar* u = new Gecode::BoolVar(*foo, 0, 1);

rel(*foo, *a, Gecode::IRT_NQ, *u);

@(return 0) = u;

"))

(defun post-nand (space i j)
  (ffi:c-inline (space i j) (:pointer-void :int :int) :void
                "{

v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVarArray vars = *(foo->getVars());

int i = #1;
int j = #2;

rel(*foo, vars[i], Gecode::BOT_AND, vars[j], 0);

}"))

(defun assert-imp (space a b)
  "BoolVar a --> BoolVar b."
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
                "{

v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVar* a = (Gecode::BoolVar*)#1;
Gecode::BoolVar* b = (Gecode::BoolVar*)#2;

rel(*foo, *a, Gecode::BOT_IMP, *b, 1);

}"))

(defun post-must-be-false (space i)
  "Post that i can only be 0."
  (ffi:c-inline (space i) (:pointer-void :int) :void
                "{

v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVarArray vars = *(foo->getVars());

int i = #1;

rel(*foo, vars[i], Gecode::IRT_EQ, 0);

}"))

(defun post-must-be-true (space i)
  "Post that i can only be 1."
  (ffi:c-inline (space i) (:pointer-void :int) :void
                "{

v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVarArray vars = *(foo->getVars());

int i = #1;

rel(*foo, vars[i], Gecode::IRT_EQ, 1);

}"))

(defun boolvar-post-eql (space a b)
  "Boolvar a eql boolvar b."
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
                "
v1::Foo* foo = ((v1::Foo*)(#0));

rel(*foo, *((Gecode::BoolVar*)(#1)), Gecode::IRT_EQ, *((Gecode::BoolVar*)(#2)));

"))

(defun constrain-not-subset (space other)
  (ffi:c-inline (space other) (:pointer-void :pointer-void) :void
                "
v1::PrBABSpace* s = ((v1::PrBABSpace*)(#0));
v1::PrBABSpace* o = ((v1::PrBABSpace*)(#1));

s->constrain_not_subset(*o);

"))

(defun delete-foo (foo)
  (ffi:c-inline (foo) (:pointer-void) :void
                "{ delete ((v1::Foo*)#0); }"))

(defun clone-foo (foo)
  (ffi:c-inline (foo) (:pointer-void) :pointer-void
                "{ @(return 0) = ((v1::Foo*)#0)->clone(); }"))

(defun foo-branch/l/int-var-degree-max/int-val-min (foo)
  (ffi:c-inline (foo) (:pointer-void) :void
                "{ ((v1::Foo*)(#0))->branch__l__int_var_degree_max__int_val_min(); }"))

(defun foo-branch/l/int-var-degree-max/int-val-max (foo)
  (ffi:c-inline (foo) (:pointer-void) :void
                "{ ((v1::Foo*)(#0))->branch__l__int_var_degree_max__int_val_max(); }"))

(defun space-status (space)
  (let ((status
         (ffi:c-inline (space) (:pointer-void) :int
                       "{
Gecode::SpaceStatus status = (((Gecode::Space*)(#0))->status());

switch (status) {
case Gecode::SS_FAILED: @(return 0) = 1; break;
case Gecode::SS_SOLVED: @(return 0) = 2; break;
case Gecode::SS_BRANCH: @(return 0) = 3; break;
default: @(return 0) = 100; break;
}


}")))
    (ecase status
      (1 :failed)
      (2 :solved)
      (3 :branch))))

(defun space-propagate-assert-not-failed (space)
  (let ((status (space-status space)))
    (assert (not (eql :failed status)))
    space))

(defun space-to-list (space)
  (mapcar #'boolvar-domain (space-vars-as-list space)))

(defun boolvar-min (boolvar)
  (ffi:c-inline (boolvar) (:pointer-void) :int
                "{ @(return 0) = ((Gecode::BoolVar*)(#0))->min(); }"))

(defun boolvar-max (boolvar)
  (ffi:c-inline (boolvar) (:pointer-void) :int
                "{ @(return 0) = ((Gecode::BoolVar*)(#0))->max(); }"))

(defun boolvar-domain (boolvar)
  (let ((min (boolvar-min boolvar))
        (max (boolvar-max boolvar)))
    (if (eql min max)
        min
        (list min max))))

(defun space-vars-as-list (space)
  (let ((vars (space-vars space)))
    (loop for i from 0 below (vars-size vars)
       collect (vars-nth vars i))))

(defun space-print-in (space vector)
  (write-string "[")
  (loop with first-time = t
     for tail on (space-to-list space)
     for i upfrom 0
     do (when (eql 1 (car tail))
          (if first-time
              (setq first-time nil)
              (write-string ","))
          (write-string (aref vector i))))
  (write-string "]"))

(defun space-collect-in (space vector)
  (loop for tail on (space-to-list space)
     for i upfrom 0
     when (eql 1 (car tail))
     collect (aref vector i)))

(defun space-vars (space)
  (ffi:c-inline (space) (:pointer-void) :pointer-void
                "{ @(return 0) = (void*)(((v1::Foo*)(#0))->getVars());}"))

(defun vars-size (vars)
  (ffi:c-inline (vars) (:pointer-void) :int
                "{ @(return 0) = ((Gecode::BoolVarArray*)(#0))->size(); }"))

(defun vars-nth (vars n)
  (ffi:c-inline (vars n) (:pointer-void :int) :pointer-void
                "{ @(return 0) = (void*)(&((*((Gecode::BoolVarArray*)(#0)))[#1])); }"))

(defun make-dfs (space)
  (ffi:c-inline (space) (:pointer-void) :pointer-void
                "{ @(return 0) = new Gecode::DFS<v1::Foo>(((v1::Foo*)(#0)));}"))

(defun dfs-next (dfs)
  (let ((solution
          (ffi:c-inline (dfs) (:pointer-void) :pointer-void
                "{ @(return 0) = ((Gecode::DFS<v1::Foo>*)(#0))->next(); }")))
    (if (si:null-pointer-p solution)
        nil
        solution)))

(defun make-bab (space)
  (ffi:c-inline (space) (:pointer-void) :pointer-void
                "{ @(return 0) = new Gecode::BAB<v1::Foo>(((v1::Foo*)(#0)));}"))

(defun delete-bab (bab)
  (ffi:c-inline (bab) (:pointer-void) :void
                "{ delete ((Gecode::BAB<v1::Foo>*)#0); }"))

(defun bab-best (bab)
  (labels
      ((bab-next (bab)
         (ffi:c-inline (bab) (:pointer-void) :pointer-void
                       "{ @(return 0) = ((Gecode::BAB<v1::Foo>*)(#0))->next(); }")))
    (declare (inline bab-next))
    (loop
      for prev-solution = nil then
                              (progn (when prev-solution
                                       (delete-foo prev-solution))
                                     solution)
      for solution = (bab-next bab)
      until (si:null-pointer-p solution)
      finally (return prev-solution))))

(defun dfs-statistics (dfs)
  (multiple-value-bind (fail node depth restart nogood)
      (ffi:c-inline (dfs) (:pointer-void)
                    (values :unsigned-long-long
                            :unsigned-long-long
                            :unsigned-long-long
                            :unsigned-long-long
                            :unsigned-long-long)
                    "
Gecode::DFS<v1::Foo>* dfs = (Gecode::DFS<v1::Foo>*)(#0);

Gecode::Search::Statistics s = dfs->statistics();

@(return 0) = s.fail;
@(return 1) = s.node;
@(return 2) = s.depth;
@(return 3) = s.restart;
@(return 4) = s.nogood;

")
    (values :fail fail :node node
            :depth depth :restart restart
            :nogood nogood)))

(defun dfs-search-all (space)
  (let ((dfs (make-dfs space)))
    (delete-foo space)
    (values
     (loop for solution = (dfs-next dfs)
        until (null solution)
        collect solution)
     (multiple-value-list
      (dfs-statistics dfs)))))

(defun dfs-search-gist (space)
  (let ((status
         (ffi:c-inline (space) (:pointer-void) :int
                       "
int res = 0;
#ifdef HAVE_GECODE_GIST_HH
v1::Foo* foo = ((v1::Foo*)(#0));
Gecode::Gist::Print<v1::Foo> p(\"Print solution\");
Gecode::Gist::Options o;
o.inspect.click(&p);
Gecode::Gist::dfs(foo,o);
res = 1;
#else
res = 7;
#endif
@(return 0) = res;
")))
    (unless (eql 1 status)
      (error "Perhaps gist is not enabled? (status is ~S)" status)))
  (delete-foo space))

(defvar *space*)
(defvar *vars-vector*)
(defvar *nand-table*)
(defvar *expr-or-table*)
(defvar *imp-or-table*)

(defmacro with-post-env-setup ((space) &body body)
  (check-type space symbol)
  `(let ((*space* ,space)
         (*vars-vector* (coerce (space-vars-as-list ,space) 'vector))
         (*nand-table* (make-hash-table :test #'equal))
         (*expr-or-table* (make-hash-table :test #'equal))
         (*imp-or-table* (make-hash-table :test #'equal)))
     ,@body))

(defmacro with-local-post-env (() &body body)
  `(let ((space *space*)
         (vars-vector *vars-vector*)
         (nand-table *nand-table*)
         (expr-or-table *expr-or-table*)
         (imp-or-table *imp-or-table*))
     (macrolet ((%%var%% (i) `(aref vars-vector ,i)))
       (labels ((!!var!! (i) (%%var%% i))
                (!!post-nand!! (a b)
                  (sortf2 a b)
                  (let ((key (list a b)))
                    (unless (gethash key nand-table)
                      (log* "NAND ~D ~D" a b)
                      (post-nand space a b)
                      (setf (gethash key nand-table) t))))
                (!!expr-or!! (indices)
                  (if (eql 1 (length indices))
                      (%%var%% (first indices))
                      (let ((key (safe-sort indices)))
                        (or (gethash key expr-or-table)
                            (progn
                              (log* "EXPR-OR ~D ~A" (length key) key)
                              (setf (gethash key expr-or-table)
                                    (expr-or space (mapcar #'!!var!! indices))))))))
                (!!expr-and-vars!! (vars)
                  (log* "EXPR-AND-VARS ~D ..." (length vars))
                  (expr-and space vars))
                (!!imp-or!! (index indices)
                  (let ((key (cons index (safe-sort indices))))
                    (unless (gethash key imp-or-table)
                      (assert-imp space (%%var%% index) (!!expr-or!! indices))
                      (setf (gethash key imp-or-table) t)))))
         ,@body))))

(defun bits-to-set (list &key (unassigned-permitted-as-out nil))
  (if unassigned-permitted-as-out
      (loop for x in list
         for i upfrom 0
         when (eql x 1)
         collect i)
      (loop for x in list
         for i upfrom 0
         do (assert (or (eql 1 x) (eql 0 x)))
         when (eql x 1)
         collect i)))

(defun space-indices-that-are-in (space &key delete)
  (prog1
      (bits-to-set (space-to-list space))
    (when delete
      (delete-foo space))))

(defun space-indices-that-are-in-and-delete (space)
  (space-indices-that-are-in space :delete t))

(defmacro sortf2 (a b)
  `(unless (< ,a ,b)
     (rotatef ,a ,b)))

(defun safe-sort (list)
  (sort (copy-list list) #'<))

(defun dfs-search-all-and-list-ins (space)
  (multiple-value-bind (solutions statistics)
      (with-timing (dfs-search-all space))
    (values
     (mapcar #'space-indices-that-are-in-and-delete solutions)
     statistics)))

(defun dfs-search-gist-or-list-ins (space gist)
  (if gist
      (dfs-search-gist space)
      (dfs-search-all-and-list-ins space)))

(defun constrain-conflict-free (graph constrain-nand)
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

(defun constrain-complete (graph)
  (with-local-post-env ()
    (constrain-conflict-free graph #'!!post-nand!!)
    #+nil
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

(defun constrain-stable (graph)
  (with-local-post-env ()
    (with-timing
        (do-parents (node parents graph)
          (when parents
            (assert-imp
             space
             (expr-not space (!!var!! node))
             (!!expr-or!! parents)))))))

(defun complete-all (graph &key gist)
  (let* ((order (order graph))
         (space (with-timing (make-foo order))))
    (with-post-env-setup (space)
      (constrain-complete graph))
    (foo-branch/l/int-var-degree-max/int-val-min space)
    (dfs-search-gist-or-list-ins space gist)))

(defun preferred-all (graph &key gist)
  (declare (ignore gist))
  (remove-duplicates
   (sort (complete-all graph) #'< :key #'length)
   :test #'subsetp))

(defun adopt-keywords (list)
  (mapcar (lambda (x)
            (if (char= #\- (char x 0))
                (intern (string-upcase (subseq x 1)) "KEYWORD")
                x))
          list))

(defun parse-problem (string)
  (let ((pos (position #\- string)))
    (values
     (intern (string-upcase (subseq string 0 pos)) "KEYWORD")
     (intern (string-upcase (subseq string (1+ pos))) "KEYWORD"))))

(defun all-for-semantic (graph semantic)
  (ecase semantic
    (:co (complete-all graph))
    (:st (stable-all graph))
    (:gr (grounded-all graph))
    (:pr (preferred-all graph))))

(defun dc-ds1 (graph task semantic arg-index)
  (flet ((contains-arg-p (extension)
           (member arg-index extension)))
    (let ((extensions (all-for-semantic graph semantic)))
      (ecase task
        (:ds (every #'contains-arg-p extensions))
        (:dc (not (null (some #'contains-arg-p extensions))))))))

(defun dc-ds (graph task semantic hash arg)
  (let ((arg-index (gethash arg hash)))
    (if (dc-ds1 graph task semantic arg-index)
        (write-string "YES")
        (write-string "NO"))))

(defpackage :oo
  (:use :cl :early)
  (:export #:print-answer
           #:collect-answer
           #:make-semantic
           #:make-task
           #:make-graph-input
           #:translate-problem))

(in-package :oo)

(defclass graph-input () ())
(defclass task () ())
(defclass semantic () ())

(defclass complete (semantic) ())
(defclass grounded (complete) ())
(defclass preferred (complete) ())
(defclass stable (preferred) ())

(defclass d-task (task)
  ((hash :accessor task-hash :initform nil)
   (arg-name :reader task-arg-name :initarg :arg-name)))

(defclass ee-task (task) ())
(defclass se-task (task) ())
(defclass dc-task (d-task) ())
(defclass ds-task (d-task) ())

(defmethod (setf task-hash) (value (task task)))

(defmethod task-arg ((task d-task))
  (gethash (task-arg-name task) (task-hash task)))

(defclass apx-input (graph-input)
  ((pathname :reader apx-pathname :initarg :pathname)))

(defclass vector-input (graph-input)
  ((vector :reader graph-input-vector :initarg :vector)))

(defun prepare-space (input task semantic)
  (multiple-value-bind (graph vector hash)
      (read-graph-input input)
    (setf (task-hash task) hash)
    (let ((space (make-initial-space graph task semantic)))
      (cl-user::with-post-env-setup (space)
        (constrain-space space graph task semantic)
        (constrain-arg space task semantic))
      (branch-space space task semantic)
      (values space vector))))

(defun build-engine (input task semantic)
  (multiple-value-bind (space vector)
      (prepare-space input task semantic)
    (make-search-engine space task semantic vector)))

(defmethod print-answer ((input graph-input)
                         (task task)
                         (semantic semantic))
  (let ((engine (build-engine input task semantic)))
    (drive-search-and-print task engine)))

(defmethod collect-answer ((input graph-input)
                           (task task)
                           (semantic semantic))
  (let ((engine (build-engine input task semantic)))
    (drive-search-and-collect task engine)))

(eval-when (:compile-toplevel :load-toplevel :execute)
  (defun make-semantic (semantic)
    (ecase semantic
      (:co (make-instance 'complete))
      (:gr (make-instance 'grounded))
      (:st (make-instance 'stable))
      (:pr (make-instance 'preferred))))

  (defun make-task (task &optional arg)
    (ecase task
      (:ee (make-instance 'ee-task))
      (:se (make-instance 'se-task))
      (:dc (make-instance 'dc-task :arg-name arg))
      (:ds (make-instance 'ds-task :arg-name arg)))))

(defun make-graph-input (input)
  (typecase input
    ((or pathname string) (make-instance 'apx-input :pathname input))
    (vector (make-instance 'vector-input :vector input))))

(defmethod read-graph-input ((input apx-input))
  (read-apx-file (apx-pathname input)))

(defmethod read-graph-input ((input vector-input))
  (let* ((graph (graph-input-vector input))
         (items (alexandria:iota (order graph))))
    (values graph
            (make-array (order graph) :initial-contents items)
            (alexandria:alist-hash-table
             (mapcar #'cons items items)))))

(defmethod make-initial-space (graph (task task) (semantic semantic))
  (cl-user::make-foo (order graph)))

(defmethod make-initial-space (graph (task se-task) (semantic preferred))
  (cl-user::make-pr-bab-space (order graph)))

(defmethod make-initial-space (graph (task ee-task) (semantic preferred))
  (cl-user::make-pr-bab-space (order graph)))

(defmethod constrain-space (space graph task (semantic complete))
  (cl-user::constrain-complete graph))

(defmethod constrain-space :after (space graph task (semantic stable))
  (cl-user::constrain-stable graph))

(defmethod constrain-arg (space task semantic)
  (log* "constrain arg is noop for ~A" task))

(defmethod constrain-arg (space (task ds-task) semantic)
  (log* "constrain arg not to be in")
  (log* "task arg is ~S" (task-arg task))
  (cl-user::post-must-be-false space (task-arg task)))

(defmethod constrain-arg (space (task dc-task) semantic)
  (log* "constrain arg to be in")
  (log* "task arg is ~S" (task-arg task))
  (cl-user::post-must-be-true space (task-arg task)))

(defmethod constrain-arg :around (space task (semantic grounded))
  (log* "constrain arg is a noop for grounded"))

(defmethod branch-space (space task semantic)
  (cl-user::foo-branch/l/int-var-degree-max/int-val-min space))

(defmethod branch-space (space (task se-task) (semantic preferred))
  (cl-user::foo-branch/l/int-var-degree-max/int-val-max space))

(defmethod branch-space (space (task ee-task) (semantic preferred))
  (cl-user::foo-branch/l/int-var-degree-max/int-val-max space))

(defmethod make-search-engine (space (task ee-task) (semantic preferred) vector)
  (make-instance 'preferred-all-engine
                 :sub-engine (make-search-engine space task (make-semantic :co) vector)))

(defmethod make-search-engine (space task semantic vector)
  (typecase semantic
    (grounded
     (etypecase task       
       ((or ee-task se-task) (make-instance 'propagate-only-engine
                                         :space space
                                         :engine-vector vector))
       (dc-task (make-instance 'dc-engine-grounded
                               :space space))
       (ds-task (make-instance 'ds-engine-grounded
                               :space space))))
    (t (prog1
           (etypecase task
             (ee-task (typecase semantic
                        (preferred
                         (make-instance 'multi-bab-engine
                                        :gecode-engine (cl-user::make-bab space)
                                        :engine-vector vector
                                        :space (progn
                                                 (cl-user::space-status space)
                                                 (cl-user::clone-foo space))))
                        (t (make-instance 'ee-engine
                                          :gecode-engine (cl-user::make-dfs space)
                                          :engine-vector vector))))
             (se-task (typecase semantic
                        (preferred
                         (make-instance 'ee-engine
                                        :gecode-engine (cl-user::make-bab space)
                                        :engine-vector vector
                                        :next-solution-fn #'cl-user::bab-best))
                        (t
                         (make-instance 'ee-engine
                                        :gecode-engine (cl-user::make-dfs space)
                                        :engine-vector vector))))
             (dc-task (make-instance 'dc-engine
                                     :gecode-engine (cl-user::make-dfs space)))
             (ds-task (make-instance 'ds-engine
                                     :gecode-engine (cl-user::make-dfs space))))
         (cl-user::delete-foo space)))))

(defclass dc-engine-grounded ()
  ((space :reader engine-space :initarg :space)))

(defclass ds-engine-grounded ()
  ((space :reader engine-space :initarg :space)))

(defclass ee-engine ()
  ((gecode-engine :reader gecode-engine :initarg :gecode-engine)
   (engine-vector :reader engine-vector :initarg :engine-vector)
   (next-solution-fn :reader next-solution-fn :initform #'cl-user::dfs-next
                     :initarg :next-solution-fn)
   (space-delete-fn :reader space-delete-fn :initform #'cl-user::delete-foo)
   (space-print-fn :reader space-print-fn :initform #'cl-user::space-print-in)
   (space-collect-fn :reader space-collect-fn :initform #'cl-user::space-collect-in)))

(defstruct gecode-engine-space-wrapper
  space)

(defun gecode-engine-space-wrapper-next (wrapper)
  (let ((space (gecode-engine-space-wrapper-space wrapper)))
    (when space
      (prog1
          (cl-user::space-propagate-assert-not-failed space)
        (setf (gecode-engine-space-wrapper-space wrapper)
              nil)))))

(defclass propagate-only-engine (ee-engine)
  ((next-solution-fn :initform #'gecode-engine-space-wrapper-next)))

(defmethod initialize-instance :after ((propagate-only-engine propagate-only-engine)
                                       &key space)
  (setf (slot-value propagate-only-engine 'gecode-engine)
        (make-gecode-engine-space-wrapper :space space)))

(defclass multi-bab-engine ()
  ((gecode-engine :reader gecode-engine :initarg :gecode-engine)
   (engine-vector :reader engine-vector :initarg :engine-vector)
   (space :reader engine-space :initarg :space)))

(defclass dc-engine ()
  ((gecode-engine :reader gecode-engine :initarg :gecode-engine)))

(defclass ds-engine ()
  ((gecode-engine :reader gecode-engine :initarg :gecode-engine)))

(defclass preferred-all-engine ()
  ((sub-engine :reader sub-engine :initarg :sub-engine)))

(defmethod drive-search-and-print (task (engine preferred-all-engine))
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

(defmethod drive-search-and-collect (task (engine preferred-all-engine))
  (let ((complete-all (drive-search-and-collect task (sub-engine engine))))
    (remove-duplicates
     (sort complete-all #'< :key #'length)
     :test #'subsetp)))

(defmethod drive-search-and-print (task (engine ee-engine))
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

(defmethod drive-search-and-collect (task (engine ee-engine))
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

(defmethod drive-search-and-print ((task se-task) (engine ee-engine))
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

(defmethod drive-search-and-collect ((task se-task) (engine ee-engine))
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
  (let ((next (cl-user::bab-best bab)))
    (when next
      (funcall fn next vector first-time)
      (when first-time
        (setq first-time nil))
      (cl-user::constrain-not-subset master next)
      (let ((status (prog1
                        (cl-user::space-status master)
                      (cl-user::delete-foo next))))
        (ecase status
          (:failed)
          (:solved
           (funcall fn master vector first-time))
          (:branch
           (let ((slave (cl-user::clone-foo master)))
             (cl-user::delete-bab bab)
             (step1 (prog1
                        (cl-user::make-bab slave)
                      (cl-user::delete-foo slave))
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
     (cl-user::space-print-in next vector)
     (terpri)))
  (write-line "]"))

(defmethod drive-search-and-collect (task (engine multi-bab-engine))
  (let (list)
    (multi-bab-helper
     engine
     (lambda (next vector first-time)
       (declare (ignore first-time))
       (push (cl-user::space-collect-in next vector) list)))
    list))

(defmethod drive-search-and-print (task (engine dc-engine))
  (let ((gecode-engine (gecode-engine engine)))
    (let ((space (cl-user::dfs-next gecode-engine)))
      (if (null space)
          (write-string "NO")
          (progn
            (write-string "YES")
            (cl-user::delete-foo space))))
    (terpri)
    nil))

(defmethod drive-search-and-collect (task (engine dc-engine))
  (let ((gecode-engine (gecode-engine engine)))
    (let ((space (cl-user::dfs-next gecode-engine)))
      (if (null space)
          nil
          (prog1
              t
            (cl-user::delete-foo space))))))

(defmethod drive-search-and-print (task (engine ds-engine))
  (let ((gecode-engine (gecode-engine engine)))
    (let ((space (cl-user::dfs-next gecode-engine)))
      (if (null space)
          (write-string "YES")
          (progn
            (write-string "NO")
            (cl-user::delete-foo space))))
    (terpri)
    nil))

(defmethod drive-search-and-collect (task (engine ds-engine))
  (let ((gecode-engine (gecode-engine engine)))
    (let ((space (cl-user::dfs-next gecode-engine)))
      (if (null space)
          t
          (prog1
              nil
            (cl-user::delete-foo space))))))

(defmethod drive-search-and-print (task (engine dc-engine-grounded))
  (let ((space (engine-space engine)))
    (cl-user::space-status space)
    (log* "arg is ~S" (task-arg task))
    (cl-user::post-must-be-false space (task-arg task))
    (let ((status (cl-user::space-status space)))
      (log* "space status is ~S" status)
      (if (eql :failed status)
          (write-string "YES")
          (write-string "NO"))
      (cl-user::delete-foo space)
      (terpri))))

(defmethod drive-search-and-collect (task (engine dc-engine-grounded))
  (let ((space (engine-space engine)))
    (cl-user::space-status space)
    (log* "arg is ~S" (task-arg task))
    (cl-user::post-must-be-false space (task-arg task))
    (let ((status (cl-user::space-status space)))
      (log* "space status is ~S" status)
      (prog1
          (if (eql :failed status)
              t
              nil)
        (cl-user::delete-foo space)))))

(defmethod drive-search-and-print (task (engine ds-engine-grounded))
  (let ((space (engine-space engine)))
    (cl-user::space-status space)
    (log* "arg is ~S" (task-arg task))
    (cl-user::post-must-be-false space (task-arg task))
    (let ((status (cl-user::space-status space)))
      (log* "space status is ~S" status)
      (if (eql :failed status)
          (write-string "YES")
          (write-string "NO"))
      (cl-user::delete-foo space)
      (terpri))))

(defmethod drive-search-and-collect (task (engine ds-engine-grounded))
  (let ((space (engine-space engine)))
    (cl-user::space-status space)
    (log* "arg is ~S" (task-arg task))
    (cl-user::post-must-be-false space (task-arg task))
    (let ((status (cl-user::space-status space)))
      (log* "space status is ~S" status)
      (prog1
          (if (eql :failed status)
              t
              nil)
        (cl-user::delete-foo space)))))

(macrolet ((translate ((from-task from-semantic) arrow (to-task to-semantic))
             (declare (ignore arrow))
             (let ((from-task-type (type-of (make-task from-task)))
                   (from-semantic-type (type-of (make-semantic from-semantic)))
                   (task-change (not (eql from-task to-task)))
                   (semantic-change (not (eql from-semantic to-semantic))))
               `(defmethod translate-problem ((task ,from-task-type)
                                              (semantic ,from-semantic-type))
                  (values ,(if task-change
                               (if (subtypep from-task-type 'd-task)
                                   `(make-task ,to-task (task-arg-name task))
                                   `(make-task ,to-task))
                               'task)
                          ,(if semantic-change
                               `(make-semantic ,to-semantic)
                               'semantic))))))
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

(in-package :cl-user)

(macrolet ((frob (name semantic task)
             `(defun ,name ,(if (eql 2 (length task))
                                '(graph a)
                                '(graph))
                (let ((task (oo:make-task ,@task))
                      (semantic (oo:make-semantic ,semantic)))
                  (multiple-value-bind (task semantic)
                      (oo:translate-problem task semantic)
                    (oo:collect-answer (oo:make-graph-input graph)
                                       task
                                       semantic))))))
  ;; all
  (frob $$complete-all :co (:ee))
  (frob $$stable-all :st (:ee))
  (frob $$grounded-all :gr (:ee))
  (frob $$preferred-all :pr (:ee))
  ;; one
  (frob $$complete-one :co (:se))
  (frob $$stable-one :st (:se))
  (frob $$grounded-one :gr (:se))
  (frob $$preferred-one :pr (:se))
  ;; dc
  (frob $$complete-dc :co (:dc a))
  (frob $$stable-dc :st (:dc a))
  (frob $$grounded-dc :gr (:dc a))
  (frob $$preferred-dc :pr (:dc a))
  ;; ds
  (frob $$complete-ds :co (:ds a))
  (frob $$stable-ds :st (:ds a))
  (frob $$grounded-ds :gr (:ds a)))

(defun $$preferred-ds (graph a) (dc-ds1 graph :ds :pr a))

(defun main% (&key (fo "apx") f p a)
  (assert (equal fo "apx"))
  (multiple-value-bind (task semantic) (parse-problem p)
    (cond
      ((or (not (eql :pr semantic))
           (and #+nil(eql :pr semantic)
                (eql :se task))
           (and #+nil(eql :pr semantic)
                (eql :ee task))
           (and #+nil(eql :pr semantic)
                (eql :dc task)))
       (let ((task (oo:make-task task a))
             (semantic (oo:make-semantic semantic)))
         (multiple-value-bind (task semantic)
             (oo:translate-problem task semantic)
           (oo:print-answer (oo:make-graph-input f)
                            task
                            semantic))))
      (t
       (let ((*print-case* :downcase))
         (multiple-value-bind (graph vector hash)
             (read-apx-file f)
           (declare (ignore vector))
           (ecase task          
             ((:dc :ds) (dc-ds graph task semantic hash a)))
           (terpri)))))))

#+cover
(defvar *cover-file*
  (merge-pathnames "cover.data" (asgl-home)))

(defun main ()
  (setq *debugger-hook* (lambda (c old)
                          (declare (ignore old))
                          (let ((*print-length* 3)
                                (*print-level* 3))
                            (ext:dump-c-backtrace 32)
                            (terpri *error-output*)
                            (print-error-log *error-output* c)
                            (format t "ERROR: ~A~%" c)
                            (ext:quit 1))))
  (log* "~S" ext:*command-args*)
  #+cover
  (when (probe-file *cover-file*)
    (cover:load-points *cover-file*))
  (unwind-protect
       (cond
         ((null (cdr ext:*command-args*))
          (write-line "ASGL version 0.1.3")
          (write-line "Kilian Sprotte <kilian.sprotte@gmail.com>")
          (terpri)
          (write-line "Copyright (C) 2015  Kilian Sprotte")
          (write-line "This program comes with ABSOLUTELY NO WARRANTY.")
          (write-line "This is free software, and you are welcome to redistribute it")
          (write-line "under certain conditions."))
         ((equal "--formats" (second ext:*command-args*))
          (write-line "[apx]"))
         ((equal "--problems" (second ext:*command-args*))
          (write-line "[DC-CO, DC-GR, DC-PR, DC-ST, DS-CO, DS-GR, DS-PR, DS-ST, EE-CO, EE-GR, EE-PR, EE-ST, SE-CO, SE-GR, SE-PR, SE-ST]"))
         #+cover
         ((equal "--cover-report" (second ext:*command-args*))
          (cover:report :out *error-output*)
          (terpri *error-output*))
         ((equal "--repl" (second ext:*command-args*))
          (let ((init-file (merge-pathnames ".asglrc" (user-homedir-pathname))))
            (when (probe-file init-file)
              (load init-file))
            (si:top-level)))
         ((equal "--check" (second ext:*command-args*))
          (let ((*default-pathname-defaults* (merge-pathnames "tests/" (asgl-home))))
            (load "tests.lisp")
            (load "tests-apx.lisp")
            (load "tests-complete.lisp")
            (load "tests-grounded.lisp")
            (load "tests-stable.lisp")
            (load "tests-preferred.lisp"))
          (format t "Running self-check... This will take around 5 min.~%")
          (if (myam:run! :tests)
              (format t "~&SELF-CHECK PASSED SUCCESSFULLY~%")
              (progn
                (format t "~&**********************************~%")
                (format t "~&SELF-CHECK FAILED something is wrong~%")
                (format t "~&**********************************~%")
                (quit 1))))
         (t (apply #'main% (adopt-keywords (cdr ext:*command-args*)))))
    #+cover
    (cover:save-points *cover-file*)))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
