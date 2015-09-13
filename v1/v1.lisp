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
  (:use :cl :early))

(in-package :asgl)

(declaim (optimize (debug 3) (safety 3) (speed 0)))
#+nil(declaim (optimize (debug 0) (safety 1) (speed 3) (space 0)))

(ffi:clines "#include \"DfsSpace.h\"")
(ffi:clines "#include \"PrBABSpace.h\"")

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

(defvar *use-gist* nil)

(defun make-dfs-space (n)
  (check-type n alexandria:non-negative-fixnum)
  ;; c-inline00001
  (ffi:c-inline (n) (:int) :pointer-void
                "{ @(return 0) = new v1::DfsSpace(#0); }"))

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
v1::DfsSpace* dfsSpace = ((v1::DfsSpace*)(#0));

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

Gecode::BoolVar* u = new Gecode::BoolVar(*dfsSpace, 0, 1);

rel(*dfsSpace, Gecode::BOT_OR, a, *u);

@(return 0) = u;

"))

(defun expr-and (space boolvars)
  "Return a new boolvar that is constrained to be the AND of boolvars."
  ;; c-inline00004
  (check-type space SI:FOREIGN-DATA)
  (check-type boolvars list)
  (dolist (b boolvars) (check-type b SI:FOREIGN-DATA))
  (ffi:c-inline (space boolvars) (:pointer-void :object) :pointer-void
                "
v1::DfsSpace* dfsSpace = ((v1::DfsSpace*)(#0));

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

Gecode::BoolVar* u = new Gecode::BoolVar(*dfsSpace, 0, 1);

rel(*dfsSpace, Gecode::BOT_AND, a, *u);

@(return 0) = u;

"))

(defun expr-not (space boolvar)
  "Return a new boolvar that is constrained to be the NOT of boolvar."
  ;; c-inline00005
  (check-type space SI:FOREIGN-DATA)
  (check-type boolvar SI:FOREIGN-DATA)
  (ffi:c-inline (space boolvar) (:pointer-void :pointer-void) :pointer-void
                "
v1::DfsSpace* dfsSpace = ((v1::DfsSpace*)(#0));

Gecode::BoolVar* a = ((Gecode::BoolVar*)(#1));

Gecode::BoolVar* u = new Gecode::BoolVar(*dfsSpace, 0, 1);

rel(*dfsSpace, *a, Gecode::IRT_NQ, *u);

@(return 0) = u;

"))

(defun post-nand (space i j)
  ;; c-inline00006
  (check-type space SI:FOREIGN-DATA)
  (check-type i alexandria:non-negative-fixnum)
  (check-type j alexandria:non-negative-fixnum)
  (ffi:c-inline (space i j) (:pointer-void :int :int) :void
                "{

v1::DfsSpace* dfsSpace = ((v1::DfsSpace*)(#0));

Gecode::BoolVarArray vars = *(dfsSpace->getVars());

int i = #1;
int j = #2;

rel(*dfsSpace, vars[i], Gecode::BOT_AND, vars[j], 0);

}"))

(defun assert-imp (space a b)
  "BoolVar a --> BoolVar b."
  ;; c-inline00007
  (check-type space SI:FOREIGN-DATA)
  (check-type a SI:FOREIGN-DATA)
  (check-type b SI:FOREIGN-DATA)
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
                "{

v1::DfsSpace* dfsSpace = ((v1::DfsSpace*)(#0));

Gecode::BoolVar* a = (Gecode::BoolVar*)#1;
Gecode::BoolVar* b = (Gecode::BoolVar*)#2;

rel(*dfsSpace, *a, Gecode::BOT_IMP, *b, 1);

}"))

(defun post-must-be-false (space i)
  "Post that i can only be 0."
  ;; c-inline00008
  (check-type space SI:FOREIGN-DATA)
  (check-type i alexandria:non-negative-fixnum)
  (ffi:c-inline (space i) (:pointer-void :int) :void
                "{

v1::DfsSpace* dfsSpace = ((v1::DfsSpace*)(#0));

Gecode::BoolVarArray vars = *(dfsSpace->getVars());

int i = #1;

rel(*dfsSpace, vars[i], Gecode::IRT_EQ, 0);

}"))

(defun post-must-be-true (space i)
  "Post that i can only be 1."
  ;; c-inline00009
  (check-type space SI:FOREIGN-DATA)
  (check-type i alexandria:non-negative-fixnum)
  (ffi:c-inline (space i) (:pointer-void :int) :void
                "{

v1::DfsSpace* dfsSpace = ((v1::DfsSpace*)(#0));

Gecode::BoolVarArray vars = *(dfsSpace->getVars());

int i = #1;

rel(*dfsSpace, vars[i], Gecode::IRT_EQ, 1);

}"))

(defun boolvar-post-eql (space a b)
  "Boolvar a eql boolvar b."
  ;; c-inline00010
  (check-type space SI:FOREIGN-DATA)
  (check-type a SI:FOREIGN-DATA)
  (check-type b SI:FOREIGN-DATA)
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
                "
v1::DfsSpace* dfsSpace = ((v1::DfsSpace*)(#0));

rel(*dfsSpace, *((Gecode::BoolVar*)(#1)), Gecode::IRT_EQ,
               *((Gecode::BoolVar*)(#2)));
"))

(defun constrain-not-subset (space other)
  ;; c-inline00011
  (check-type space SI:FOREIGN-DATA)
  (check-type other SI:FOREIGN-DATA)
  (ffi:c-inline (space other) (:pointer-void :pointer-void) :void
                "
v1::PrBABSpace* s = ((v1::PrBABSpace*)(#0));
v1::PrBABSpace* o = ((v1::PrBABSpace*)(#1));

s->constrain_not_subset(*o);

"))

(defun delete-dfs-space (space)
  ;; c-inline00012
  (check-type space SI:FOREIGN-DATA)
  (ffi:c-inline (space) (:pointer-void) :void
                "{ delete ((v1::DfsSpace*)#0); }")
  nil)

(defun clone-dfs-space (space)
  ;; c-inline00013
  (check-type space SI:FOREIGN-DATA)
  (ffi:c-inline (space) (:pointer-void) :pointer-void
                "{ @(return 0) = ((v1::DfsSpace*)#0)->clone(); }"))

(defun dfs-space-branch/l/int-var-degree-max/int-val-min (space)
  ;; c-inline00014
  (check-type space SI:FOREIGN-DATA)
  (ffi:c-inline
   (space)
   (:pointer-void) :void
   "{ ((v1::DfsSpace*)(#0))->branch__l__int_var_degree_max__int_val_min(); }"))

(defun dfs-space-branch/l/int-var-degree-max/int-val-max (space)
  ;; c-inline00015
  (check-type space SI:FOREIGN-DATA)
  (ffi:c-inline
   (space) (:pointer-void) :void
   "{ ((v1::DfsSpace*)(#0))->branch__l__int_var_degree_max__int_val_max(); }"))

(defun space-status (space)
  (check-type space SI:FOREIGN-DATA)
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
  (check-type space SI:FOREIGN-DATA)
  (mapcar #'boolvar-domain (space-vars-as-list space)))

(defun boolvar-min (boolvar)
  ;; c-inline00017
  (check-type boolvar SI:FOREIGN-DATA)
  (ffi:c-inline (boolvar) (:pointer-void) :int
                "{ @(return 0) = ((Gecode::BoolVar*)(#0))->min(); }"))

(defun boolvar-max (boolvar)
  ;; c-inline00018
  (check-type boolvar SI:FOREIGN-DATA)
  (ffi:c-inline (boolvar) (:pointer-void) :int
                "{ @(return 0) = ((Gecode::BoolVar*)(#0))->max(); }"))

(defun boolvar-domain (boolvar)
  (check-type boolvar SI:FOREIGN-DATA)
  (let ((min (boolvar-min boolvar))
        (max (boolvar-max boolvar)))
    (if (eql min max)
        min
        (list min max))))

(defun space-vars-as-list (space)
  (check-type space SI:FOREIGN-DATA)
  (let ((vars (space-vars space)))
    (loop for i from 0 below (vars-size vars)
       collect (vars-nth vars i))))

(defun space-print-in (space vector)
  (check-type space SI:FOREIGN-DATA)
  (check-type vector vector)
  (every (lambda (x) (check-type x (or string
                                       alexandria:non-negative-fixnum)))
         vector)
  (write-string "[")
  (loop with first-time = t
     for tail on (space-to-list space)
     for i upfrom 0
     do (when (eql 1 (car tail))
          (if first-time
              (setq first-time nil)
              (write-string ","))
          (princ (aref vector i))))
  (write-string "]"))

(defun space-collect-in (space vector)
  (check-type space SI:FOREIGN-DATA)
  (check-type vector vector)
  (every (lambda (x) (check-type x (or string
                                       alexandria:non-negative-fixnum)))
         vector)
  (loop for tail on (space-to-list space)
     for i upfrom 0
     when (eql 1 (car tail))
     collect (aref vector i)))

(defun space-vars (space)
  ;; c-inline00019
  (check-type space SI:FOREIGN-DATA)
  (ffi:c-inline (space) (:pointer-void) :pointer-void
                "{ @(return 0) = (void*)(((v1::DfsSpace*)(#0))->getVars());}"))

(defun vars-size (vars)
  ;; c-inline00020
  (check-type vars SI:FOREIGN-DATA)
  (ffi:c-inline (vars) (:pointer-void) :int
                "{ @(return 0) = ((Gecode::BoolVarArray*)(#0))->size(); }"))

(defun vars-nth (vars n)
  ;; c-inline00021
  (check-type vars SI:FOREIGN-DATA)
  (check-type n alexandria:non-negative-fixnum)
  (ffi:c-inline
   (vars n) (:pointer-void :int) :pointer-void
   "{ @(return 0) = (void*)(&((*((Gecode::BoolVarArray*)(#0)))[#1])); }"))

(defun make-dfs (space)
  ;; c-inline00022
  (check-type space SI:FOREIGN-DATA)
  (ffi:c-inline (space) (:pointer-void) :pointer-void
                "
{ @(return 0) = new Gecode::DFS<v1::DfsSpace>(((v1::DfsSpace*)(#0)));}"))

(defun make-dfs-or-gist (space)
  (if (not *use-gist*)
      (make-dfs space)
      (make-dfs
       ;; go interactive. When user is done, we just continue with
       ;; normal search. Space is returned unchanged.
       (dfs-search-gist space))))

(defun dfs-next (dfs)
  (check-type dfs SI:FOREIGN-DATA)
  (let ((solution
          ;; c-inline00023
          (ffi:c-inline (dfs) (:pointer-void) :pointer-void
                        "
{ @(return 0) = ((Gecode::DFS<v1::DfsSpace>*)(#0))->next(); }")))
    (if (si:null-pointer-p solution)
        nil
        solution)))

(defun make-bab (space)
  ;; c-inline00024
  (check-type space SI:FOREIGN-DATA)
  (ffi:c-inline (space) (:pointer-void) :pointer-void
                "
{ @(return 0) = new Gecode::BAB<v1::DfsSpace>(((v1::DfsSpace*)(#0)));}"))

(defun make-bab-or-gist (space)
  (if (not *use-gist*)
      (make-bab space)
      (make-bab
       ;; go interactive. When user is done, we just continue with
       ;; normal search. Space is returned unchanged.
       (bab-search-gist space))))

(defun delete-bab (bab)
  ;; c-inline00025
  (check-type bab SI:FOREIGN-DATA)
  (ffi:c-inline (bab) (:pointer-void) :void
                "{ delete ((Gecode::BAB<v1::DfsSpace>*)#0); }")
  nil)

(defun bab-best (bab)
  (check-type bab SI:FOREIGN-DATA)
  (labels
      ((bab-next (bab)
         ;; c-inline00026
         (ffi:c-inline
          (bab) (:pointer-void) :pointer-void
          "{ @(return 0) = ((Gecode::BAB<v1::DfsSpace>*)(#0))->next(); }")))
    (declare (inline bab-next))
    (loop
      for prev-solution = nil then
                              (progn (when prev-solution
                                       (delete-dfs-space prev-solution))
                                     solution)
      for solution = (bab-next bab)
      until (si:null-pointer-p solution)
      finally (return prev-solution))))

(defun dfs-statistics (dfs)
  (check-type dfs SI:FOREIGN-DATA)
  (multiple-value-bind (fail node depth restart nogood)
      ;; c-inline00027
      (ffi:c-inline (dfs) (:pointer-void)
                    (values :unsigned-long-long
                            :unsigned-long-long
                            :unsigned-long-long
                            :unsigned-long-long
                            :unsigned-long-long)
                    "
Gecode::DFS<v1::DfsSpace>* dfs = (Gecode::DFS<v1::DfsSpace>*)(#0);

Gecode::Search::Statistics s = dfs->statistics();

@(return 0) = s.fail;
@(return 1) = s.node;
@(return 2) = s.depth;
@(return 3) = s.restart;
@(return 4) = s.nogood;

")
    (list :fail fail :node node
          :depth depth :restart restart
          :nogood nogood)))

(defun dfs-search-gist (space)
  (check-type space SI:FOREIGN-DATA)
  (let ((status
          ;; c-inline000028
          (ffi:c-inline (space) (:pointer-void) :int
                       "
int res = 0;
#ifdef HAVE_GECODE_GIST_HH
v1::DfsSpace* dfsSpace = ((v1::DfsSpace*)(#0));
Gecode::Gist::Print<v1::DfsSpace> p(\"Print solution\");
Gecode::Gist::Options o;
o.inspect.click(&p);
Gecode::Gist::dfs(dfsSpace,o);
res = 1;
#else
res = 7;
#endif
@(return 0) = res;
")))
    (unless (eql 1 status)
      (error "Perhaps gist is not enabled? (status is ~S)" status)))
  space)

(defun bab-search-gist (space)
  (check-type space SI:FOREIGN-DATA)
  (let ((status
          ;; c-inline000028
          (ffi:c-inline (space) (:pointer-void) :int
                       "
int res = 0;
#ifdef HAVE_GECODE_GIST_HH
v1::DfsSpace* dfsSpace = ((v1::DfsSpace*)(#0));
Gecode::Gist::Print<v1::DfsSpace> p(\"Print solution\");
Gecode::Gist::Options o;
o.inspect.click(&p);
Gecode::Gist::bab(dfsSpace,o);
res = 1;
#else
res = 7;
#endif
@(return 0) = res;
")))
    (unless (eql 1 status)
      (error "Perhaps gist is not enabled? (status is ~S)" status)))
  space)

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

(defmacro sortf2 (a b)
  `(unless (< ,a ,b)
     (rotatef ,a ,b)))

(defun safe-sort (list)
  (check-type list list)
  (sort (copy-list list) #'<))



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

(defun constrain-complete (graph)
  (check-type graph graph)
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
  (check-type graph graph)
  (with-local-post-env ()
    (with-timing
        (do-parents (node parents graph)
          (when parents
            (assert-imp
             space
             (expr-not space (!!var!! node))
             (!!expr-or!! parents)))))))

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

(defclass ee-task (task) ())
(defclass se-task (task) ())

(defmethod (setf task-hash) (value (task task))
  (check-type value hash-table)
  ;; noop
  )

(defclass decision-task (task)
  ((hash :accessor task-hash :initform nil)
   (arg-name :reader task-arg-name :initarg :arg-name)
   (no-solution-found-means-yes :reader no-solution-found-means-yes)))

(defclass dc-task (decision-task)
  ((no-solution-found-means-yes :initform nil)))

(defclass ds-task (decision-task)
  ((no-solution-found-means-yes :initform t)))

(defmethod task-arg ((task decision-task))
  (or (gethash (task-arg-name task) (task-hash task))
      (error "task-arg-name ~S not found in task-hash ~S containing~%~S"
             (task-arg-name task) (task-hash task)
             (alexandria:hash-table-alist (task-hash task)))))

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

(defclass driver () ())

(defclass search-all-driver (driver)
  ())

(defclass search-one-driver (driver)
  ())

(defclass search-one-decision-driver (driver)
  ((no-solution-found-means-yes
    :reader no-solution-found-means-yes
    :initarg :no-solution-found-means-yes)))

(defmethod make-driver (semantic (task ee-task))
  (check-type semantic semantic)
  (make-instance 'search-all-driver))

(defmethod make-driver (semantic (task se-task))
  (check-type semantic semantic)
  (make-instance 'search-one-driver))

(defmethod make-driver (semantic (task dc-task))
  (check-type semantic semantic)
  (make-instance 'search-one-decision-driver
                 :no-solution-found-means-yes nil))

(defmethod make-driver (semantic (task ds-task))
  (check-type semantic semantic)
  (make-instance 'search-one-decision-driver
                 :no-solution-found-means-yes t))

(defmethod make-driver ((semantic grounded) (task decision-task))
  (make-instance 'search-one-decision-driver
                 :no-solution-found-means-yes t))

(defun solve (input task semantic drive-fn)
  (check-type input input)
  (check-type task task)
  (check-type semantic semantic)
  (check-type drive-fn function)
  (multiple-value-bind (space vector)
      (with-timing (prepare-space input task semantic))
    (let ((engine (with-timing (make-search-engine space task semantic vector)))
          (driver (with-timing (make-driver semantic task))))
      (log* 1 "driver: ~A" driver)
      (log* 1 "engine: ~A" engine)
      (log* 1 "STARTING SEARCH")
      (with-timing (funcall drive-fn driver engine)))))

(defun print-answer (input task semantic)
  (solve input task semantic
         #'drive-search-and-print))

(defun collect-answer (input task semantic)
  (solve input task semantic
         #'drive-search-and-collect))

(eval-when (:compile-toplevel :load-toplevel :execute)
  (defun make-semantic (semantic)
    (ecase semantic
      (:co (make-instance 'complete))
      (:gr (make-instance 'grounded))
      (:st (make-instance 'stable))
      (:pr (make-instance 'preferred))))

  (defun make-task (task &optional arg)
    (check-type arg (or null string alexandria:non-negative-fixnum))
    (ecase task
      (:ee (make-instance 'ee-task))
      (:se (make-instance 'se-task))
      (:dc (make-instance 'dc-task :arg-name arg))
      (:ds (make-instance 'ds-task :arg-name arg)))))

(defmethod make-initial-space (graph (task task) (semantic semantic))
  (check-type graph graph)
  (log* 1 "creating initial dfs-space")
  (make-dfs-space (order graph)))

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
  ;; noop
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

(defmethod branch-space (space task semantic)
  (check-type space SI:FOREIGN-DATA)
  (check-type semantic semantic)
  (check-type task task)
  (log* 1 "dfs-space-branch/l/int-var-degree-max/int-val-min")
  (dfs-space-branch/l/int-var-degree-max/int-val-min space))

(defmethod branch-space (space (task se-task) (semantic preferred))
  (check-type space SI:FOREIGN-DATA)
  (check-type semantic semantic)
  (check-type task task)
  (log* 1 "dfs-space-branch/l/int-var-degree-max/int-val-max")
  (dfs-space-branch/l/int-var-degree-max/int-val-max space))

(defmethod branch-space (space (task ee-task) (semantic preferred))
  (check-type space SI:FOREIGN-DATA)
  (check-type semantic semantic)
  (check-type task task)
  (log* 1 "dfs-space-branch/l/int-var-degree-max/int-val-max")
  (dfs-space-branch/l/int-var-degree-max/int-val-max space))

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
                                        :gecode-engine (make-bab-or-gist space)
                                        :engine-vector vector
                                        :space (progn
                                                 (space-status space)
                                                 (clone-dfs-space space))))
                        (t (make-instance
                            'search-engine
                            :gecode-engine (make-dfs-or-gist space)
                            :engine-vector vector))))
             (se-task (typecase semantic
                        (preferred
                         (make-instance 'search-engine
                                        :gecode-engine (make-bab-or-gist space)
                                        :engine-vector vector
                                        :next-solution-fn #'bab-best))
                        (t
                         (make-instance 'search-engine
                                        :gecode-engine (make-dfs-or-gist space)
                                        :engine-vector vector))))
             (dc-task (make-instance 'search-engine
                                     :gecode-engine (make-dfs-or-gist space)))
             (ds-task (make-instance 'search-engine
                                     :gecode-engine (make-dfs-or-gist space))))
         (delete-dfs-space space)))))

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
   :space-delete-fn  #'delete-dfs-space
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
            (:failed (delete-dfs-space space))
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
  (dfs-statistics (gecode-engine engine)))

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
                      (delete-dfs-space next))))
        (ecase status
          (:failed)
          (:solved
           (funcall fn master vector first-time))
          (:branch
           (let ((slave (clone-dfs-space master)))
             (delete-bab bab)
             (step1 (prog1
                        (make-bab-or-gist slave)
                      (delete-dfs-space slave))
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

;;; DS-PR
(defmethod make-search-engine (space (task ds-task) (semantic preferred) vector)
  (check-type space SI:FOREIGN-DATA)
  (check-type semantic semantic)
  (check-type task task)
  (check-type vector vector)
  (make-instance 'ds-pr-engine :task task :space space :vector vector))

(defmethod constrain-arg-if-needed
    (space (semantic preferred) (task ds-task))
  ;; noop
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
                 (coerce (alexandria:iota (length (engine-vector ds-pr-engine)))
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
  (assert (equal fo "apx"))
  (assert (alexandria:xor f g))
  (let* ((*use-gist* (read-from-string gist))
         (*log-level* (read-from-string log-level))
         (*with-timing* (read-from-string timing))
         (g (when g (parse-g-arg g)))
         (f (or f g))
         (a (when a
              (if g (parse-integer a) a)))
         (eval (read-from-string eval)))
    (check-type *log-level* log-level)
    (when load (load load))
    (when eval (eval eval))
    (multiple-value-bind (task semantic) (parse-problem p)
      (let ((task (make-task task a))
            (semantic (make-semantic semantic)))
        (multiple-value-bind (task semantic)
            (translate-problem task semantic)
          (with-timing
              (print-answer f
                               task
                               semantic)))))))

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
         ((equal "--check" (second ext:*command-args*))
          (run-self-check (cddr ext:*command-args*)))
         (t (apply #'main% (adopt-keywords (cdr ext:*command-args*)))))
    #+cover
    (cover:save-points *cover-file*)))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
