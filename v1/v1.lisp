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
  (check-type n alexandria:non-negative-fixnum)
  ;; c-inline00001
  (ffi:c-inline (n) (:int) :pointer-void "{ @(return 0) = new v1::Foo(#0); }"))

(defun make-pr-bab-space (n)
  (check-type n alexandria:non-negative-fixnum)
  ;; c-inline00002
  (ffi:c-inline (n) (:int) :pointer-void
                "{ @(return 0) = new v1::PrBABSpace(#0); }"))

(defun expr-or (space boolvars)
  "Return a new boolvar that is constrained to be the OR of boolvars."
  ;; c-inline00003
  (check-type space SI:FOREIGN-DATA)
  (check-type boolvars list)
  (dolist (b boolvars) (check-type b SI:FOREIGN-DATA))
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
  ;; c-inline00004
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
  ;; c-inline00005
  (ffi:c-inline (space boolvar) (:pointer-void :pointer-void) :pointer-void
                "
v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVar* a = ((Gecode::BoolVar*)(#1));

Gecode::BoolVar* u = new Gecode::BoolVar(*foo, 0, 1);

rel(*foo, *a, Gecode::IRT_NQ, *u);

@(return 0) = u;

"))

(defun post-nand (space i j)
  ;; c-inline00006
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
  ;; c-inline00007
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
                "{

v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVar* a = (Gecode::BoolVar*)#1;
Gecode::BoolVar* b = (Gecode::BoolVar*)#2;

rel(*foo, *a, Gecode::BOT_IMP, *b, 1);

}"))

(defun post-must-be-false (space i)
  "Post that i can only be 0."
  ;; c-inline00008
  (ffi:c-inline (space i) (:pointer-void :int) :void
                "{

v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVarArray vars = *(foo->getVars());

int i = #1;

rel(*foo, vars[i], Gecode::IRT_EQ, 0);

}"))

(defun post-must-be-true (space i)
  "Post that i can only be 1."
  ;; c-inline00009
  (ffi:c-inline (space i) (:pointer-void :int) :void
                "{

v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVarArray vars = *(foo->getVars());

int i = #1;

rel(*foo, vars[i], Gecode::IRT_EQ, 1);

}"))

(defun boolvar-post-eql (space a b)
  "Boolvar a eql boolvar b."
  ;; c-inline00010
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
                "
v1::Foo* foo = ((v1::Foo*)(#0));

rel(*foo, *((Gecode::BoolVar*)(#1)), Gecode::IRT_EQ, *((Gecode::BoolVar*)(#2)));

"))

(defun constrain-not-subset (space other)
  ;; c-inline00011
  (ffi:c-inline (space other) (:pointer-void :pointer-void) :void
                "
v1::PrBABSpace* s = ((v1::PrBABSpace*)(#0));
v1::PrBABSpace* o = ((v1::PrBABSpace*)(#1));

s->constrain_not_subset(*o);

"))

(defun delete-foo (foo)
  ;; c-inline00012
  (ffi:c-inline (foo) (:pointer-void) :void
                "{ delete ((v1::Foo*)#0); }")
  nil)

(defun clone-foo (foo)
  ;; c-inline00013
  (ffi:c-inline (foo) (:pointer-void) :pointer-void
                "{ @(return 0) = ((v1::Foo*)#0)->clone(); }"))

(defun foo-branch/l/int-var-degree-max/int-val-min (foo)
  ;; c-inline00014
  (ffi:c-inline
   (foo)
   (:pointer-void) :void
   "{ ((v1::Foo*)(#0))->branch__l__int_var_degree_max__int_val_min(); }"))

(defun foo-branch/l/int-var-degree-max/int-val-max (foo)
  ;; c-inline00015
  (ffi:c-inline
   (foo) (:pointer-void) :void
   "{ ((v1::Foo*)(#0))->branch__l__int_var_degree_max__int_val_max(); }"))

(defun space-status (space)
  (let ((status
          ;; c-inline00016
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

(defun space-to-list (space)
  (mapcar #'boolvar-domain (space-vars-as-list space)))

(defun boolvar-min (boolvar)
  ;; c-inline00017
  (ffi:c-inline (boolvar) (:pointer-void) :int
                "{ @(return 0) = ((Gecode::BoolVar*)(#0))->min(); }"))

(defun boolvar-max (boolvar)
  ;; c-inline00018
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
  ;; c-inline00019
  (ffi:c-inline (space) (:pointer-void) :pointer-void
                "{ @(return 0) = (void*)(((v1::Foo*)(#0))->getVars());}"))

(defun vars-size (vars)
  ;; c-inline00020
  (ffi:c-inline (vars) (:pointer-void) :int
                "{ @(return 0) = ((Gecode::BoolVarArray*)(#0))->size(); }"))

(defun vars-nth (vars n)
  ;; c-inline00021
  (ffi:c-inline
   (vars n) (:pointer-void :int) :pointer-void
   "{ @(return 0) = (void*)(&((*((Gecode::BoolVarArray*)(#0)))[#1])); }"))

(defun make-dfs (space)
  ;; c-inline00022
  (ffi:c-inline (space) (:pointer-void) :pointer-void
                "{ @(return 0) = new Gecode::DFS<v1::Foo>(((v1::Foo*)(#0)));}"))

(defun dfs-next (dfs)
  (let ((solution
          ;; c-inline00023
          (ffi:c-inline (dfs) (:pointer-void) :pointer-void
                "{ @(return 0) = ((Gecode::DFS<v1::Foo>*)(#0))->next(); }")))
    (if (si:null-pointer-p solution)
        nil
        solution)))

(defun make-bab (space)
  ;; c-inline00024
  (ffi:c-inline (space) (:pointer-void) :pointer-void
                "{ @(return 0) = new Gecode::BAB<v1::Foo>(((v1::Foo*)(#0)));}"))

(defun delete-bab (bab)
  ;; c-inline00025
  (ffi:c-inline (bab) (:pointer-void) :void
                "{ delete ((Gecode::BAB<v1::Foo>*)#0); }")
  nil)

(defun bab-best (bab)
  (labels
      ((bab-next (bab)
         ;; c-inline00026
         (ffi:c-inline
          (bab) (:pointer-void) :pointer-void
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
      ;; c-inline00027
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
          ;; c-inline000028
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
  (check-type space symbol)             ;keep this one
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
                                    (expr-or space
                                             (mapcar #'!!var!! indices))))))))
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
           #:translate-problem))

(in-package :oo)

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

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

(defclass decision-task (task)
  ((hash :accessor task-hash :initform nil)
   (arg-name :reader task-arg-name :initarg :arg-name)
   (no-solution-found-means-yes :reader no-solution-found-means-yes)))

(defclass ee-task (task) ())
(defclass se-task (task) ())

(defclass dc-task (decision-task)
  ((no-solution-found-means-yes :initform nil)))

(defclass ds-task (decision-task)
  ((no-solution-found-means-yes :initform t)))

(defmethod (setf task-hash) (value (task task)))

(defmethod task-arg ((task decision-task))
  (gethash (task-arg-name task) (task-hash task)))

(defun prepare-space (input task semantic)
  (multiple-value-bind (graph vector hash)
      (read-graph-input input)
    (setf (task-hash task) hash)
    (let ((space (make-initial-space graph task semantic)))
      (cl-user::with-post-env-setup (space)
        (constrain-space space semantic task graph)
        (constrain-arg-if-needed space semantic task))
      (branch-space space task semantic)
      (values space vector))))

(defclass search-all-driver ()
  ())

(defclass search-one-driver ()
  ())

(defclass search-one-decision-driver ()
  ((no-solution-found-means-yes
    :reader no-solution-found-means-yes
    :initarg :no-solution-found-means-yes)))

(defmethod make-driver (semantic (task ee-task))
  (make-instance 'search-all-driver))

(defmethod make-driver (semantic (task se-task))
  (make-instance 'search-one-driver))

(defmethod make-driver (semantic (task dc-task))
  (make-instance 'search-one-decision-driver
                 :no-solution-found-means-yes nil))

(defmethod make-driver (semantic (task ds-task))
  (make-instance 'search-one-decision-driver
                 :no-solution-found-means-yes t))

(defmethod make-driver ((semantic grounded) (task decision-task))
  (make-instance 'search-one-decision-driver
                 :no-solution-found-means-yes t))

(defun print-answer (input task semantic)
  (multiple-value-bind (space vector)
      (prepare-space input task semantic)
    (let ((engine (make-search-engine space task semantic vector))
          (driver (make-driver semantic task)))
      (drive-search-and-print driver engine))))

(defun collect-answer (input task semantic)
  (multiple-value-bind (space vector)
      (prepare-space input task semantic)
    (let ((engine (make-search-engine space task semantic vector))
          (driver (make-driver semantic task)))
      (drive-search-and-collect driver engine))))

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

(defmethod make-initial-space (graph (task task) (semantic semantic))
  (cl-user::make-foo (order graph)))

(defmethod make-initial-space (graph (task se-task) (semantic preferred))
  (cl-user::make-pr-bab-space (order graph)))

(defmethod make-initial-space (graph (task ee-task) (semantic preferred))
  (cl-user::make-pr-bab-space (order graph)))

(defmethod constrain-space (space (semantic complete) task graph)
  (cl-user::constrain-complete graph))

(defmethod constrain-space :after (space (semantic stable) task graph)
  (cl-user::constrain-stable graph))

(defmethod constrain-arg-if-needed (space semantic task)
  ;; noop
  )

(defmethod constrain-arg-if-needed (space semantic (task decision-task))
  (constrain-arg space semantic task))

(defmethod constrain-arg (space (semantic grounded) (task decision-task))
  (log* "constrain arg not to be in")
  (log* "task arg is ~S" (task-arg task))
  (cl-user::post-must-be-false space (task-arg task)))

(defmethod constrain-arg (space semantic (task ds-task))
  (log* "constrain arg not to be in")
  (log* "task arg is ~S" (task-arg task))
  (cl-user::post-must-be-false space (task-arg task)))

(defmethod constrain-arg (space semantic (task dc-task))
  (log* "constrain arg to be in")
  (log* "task arg is ~S" (task-arg task))
  (cl-user::post-must-be-true space (task-arg task)))

(defmethod branch-space (space task semantic)
  (cl-user::foo-branch/l/int-var-degree-max/int-val-min space))

(defmethod branch-space (space (task se-task) (semantic preferred))
  (cl-user::foo-branch/l/int-var-degree-max/int-val-max space))

(defmethod branch-space (space (task ee-task) (semantic preferred))
  (cl-user::foo-branch/l/int-var-degree-max/int-val-max space))

(defmethod make-search-engine (space (task ee-task) (semantic preferred) vector)
  (make-instance 'preferred-all-engine
                 :sub-engine (make-search-engine space task
                                                 (make-semantic :co) vector)))

(defmethod make-search-engine (space task semantic vector)
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
                                        :gecode-engine (cl-user::make-bab space)
                                        :engine-vector vector
                                        :space (progn
                                                 (cl-user::space-status space)
                                                 (cl-user::clone-foo space))))
                        (t (make-instance
                            'search-engine
                            :gecode-engine (cl-user::make-dfs space)
                            :engine-vector vector))))
             (se-task (typecase semantic
                        (preferred
                         (make-instance 'search-engine
                                        :gecode-engine (cl-user::make-bab space)
                                        :engine-vector vector
                                        :next-solution-fn #'cl-user::bab-best))
                        (t
                         (make-instance 'search-engine
                                        :gecode-engine (cl-user::make-dfs space)
                                        :engine-vector vector))))
             (dc-task (make-instance 'search-engine
                                     :gecode-engine (cl-user::make-dfs space)))
             (ds-task (make-instance 'search-engine
                                     :gecode-engine (cl-user::make-dfs space))))
         (cl-user::delete-foo space)))))

(defclass search-engine ()
  ((gecode-engine    :reader gecode-engine    :initarg :gecode-engine)
   (engine-vector    :reader engine-vector    :initarg :engine-vector)
   (next-solution-fn :reader next-solution-fn :initarg :next-solution-fn)
   (space-delete-fn  :reader space-delete-fn  :initarg :space-delete-fn)
   (space-print-fn   :reader space-print-fn   :initarg :space-print-fn)
   (space-collect-fn :reader space-collect-fn :initarg :space-collect-fn))
  (:default-initargs
   :next-solution-fn #'cl-user::dfs-next
   :space-delete-fn  #'cl-user::delete-foo
   :space-print-fn   #'cl-user::space-print-in
   :space-collect-fn #'cl-user::space-collect-in))

(defstruct gecode-engine-space-wrapper
  space)

(defun gecode-engine-space-wrapper-next (wrapper)
  (let ((space (gecode-engine-space-wrapper-space wrapper)))
    (when space
      (prog1
          (case (cl-user::space-status space)
            (:failed (cl-user::delete-foo space))
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

(defclass multi-bab-engine ()
  ((gecode-engine :reader gecode-engine :initarg :gecode-engine)
   (engine-vector :reader engine-vector :initarg :engine-vector)
   (space :reader engine-space :initarg :space)))

(defclass preferred-all-engine ()
  ((sub-engine :reader sub-engine :initarg :sub-engine)))

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

(defmethod drive-search-and-print ((task search-one-decision-driver) engine)
  (let* ((gecode-engine (gecode-engine engine))
         (next-solution-fn (next-solution-fn engine))
         (space-delete-fn (space-delete-fn engine))
         (solution (funcall next-solution-fn gecode-engine))
         (no-solution-found-means-yes
           (no-solution-found-means-yes task)))
    (if (null solution)
        (write-string (if no-solution-found-means-yes
                          "YES"
                          "NO"))
        (progn
          (write-string (if no-solution-found-means-yes
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
         (no-solution-found-means-yes
           (no-solution-found-means-yes task)))
    (if (null solution)
        no-solution-found-means-yes
        (prog1
            (not no-solution-found-means-yes)
          (funcall space-delete-fn solution)))))

(macrolet ((translate ((from-task from-semantic) arrow (to-task to-semantic))
             (declare (ignore arrow))
             (let ((from-task-type (type-of (make-task from-task)))
                   (from-semantic-type (type-of (make-semantic from-semantic)))
                   (task-change (not (eql from-task to-task)))
                   (semantic-change (not (eql from-semantic to-semantic))))
               `(defmethod translate-problem ((task ,from-task-type)
                                              (semantic ,from-semantic-type))
                  (values ,(if task-change
                               (if (subtypep from-task-type 'decision-task)
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
           (oo:print-answer f
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

(defun print-informational-message ()
  (format t "ASGL version ~A~%"
          #.(multiple-value-bind (stream exit-code)
                (ext:run-program "git" '("describe" "HEAD"))
              (assert (zerop exit-code))
              (prog1
                  (read-line stream)
                (close stream))))
  (write-line "Kilian Sprotte <kilian.sprotte@gmail.com>")
  (terpri)
  (write-line "configuration options: ")
  (write-line #.(multiple-value-bind (stream exit-code)
                    (ext:run-program "./config.status" '("--config"))
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
        (quit 1))))

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
         ((equal "--check" (second ext:*command-args*))
          (run-self-check (cddr ext:*command-args*)))
         (t (apply #'main% (adopt-keywords (cdr ext:*command-args*)))))
    #+cover
    (cover:save-points *cover-file*)))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
