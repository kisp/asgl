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

(defpackage :gecode
  (:use :cl :early :alexandria)
  (:export
   #:make-bool-space
   #:make-pr-bab-space
   #:make-int-space
   #:branch
   #:space-status
   #:clone-space
   #:delete-space)
  (:export
   #:make-dfs-engine
   #:make-bab-engine
   #:dfs-next
   #:dfs-count
   #:dfs-statistics
   #:delete-dfs
   #:delete-bab)
  (:export
   #:let*-heap)
  (:export
   #:post-must-be-true
   #:post-must-be-false
   #:post-nand)
  (:export
   #:assert-imp)
  (:export
   #:expr-or
   #:expr-and
   #:expr-not)
  (:export
   #:boolvar-post-eql)
  (:export #:rnd)
  (:export
   #:int-var-none
   #:int-var-degree-max
   #:int-var-rnd)
  (:export
   #:int-val-rnd
   #:int-val-min
   #:int-val-max)
  (:export
   #:int-space-ins
   #:pr-bab-space-ins
   #:bool-space-ins)
  ;; deprecated
  (:export
   #:space-vars-as-list
   #:space-print-in
   #:space-collect-in
   #:bab-best
   #:space-to-list))

(in-package :gecode)

#+nil(declaim (optimize (debug 3) (safety 3) (speed 0)))
(declaim (optimize (debug 0) (safety 1) (speed 3) (space 0)))

(ffi:clines "#include \"BoolSpace.h\"")
(ffi:clines "#include \"PrBABSpace.h\"")
(ffi:clines "#include \"IntSpace.h\"")

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

(defmacro define-foreign-constructor ((name cname &key tag) &body args)
  (labels ((arg-var (arg) (first arg))
           (arg-ctype (arg) (second arg))
           (arg-type (arg) (let ((type (second arg)))
                             (if (stringp (arg-ctype arg))
                                 :pointer-void
                                 (arg-ctype arg)))))
    `(defun ,name ,(mapcar #'arg-var args)
       (ffi:c-inline
        (',tag ,@(mapcar #'arg-var args))
        (:object ,@(mapcar #'arg-type args))
        :object
        ,(format nil "ecl_make_foreign_data(#0,0,new ~A(~{~A~^,~}))"
                 cname
                 (loop for i upfrom 1
                       for arg in args
                       collect (format
                                nil "~@[(~A)~](#~D)"
                                (when (eql :pointer-void (arg-type arg))
                                  (arg-ctype arg))
                                i)))
        :one-liner t))))

(define-foreign-constructor (make-int-space
                             "IntSpace" :tag :int-space)
    (n :int) (from :int) (to :int))

(define-foreign-constructor (make-bool-space
                             "BoolSpace" :tag :bool-space)
    (n :int))

(define-foreign-constructor (make-pr-bab-space
                             "PrBABSpace" :tag :pr-bab-space)
    (n :int))

(define-foreign-constructor (make-dfs-engine
                             "Gecode::DFS<Gecode::Space>" :tag :dfs-engine)
    (space "Gecode::Space*"))

(define-foreign-constructor (make-bab-engine
                             "Gecode::BAB<Gecode::Space>" :tag :bab-engine)
    (space "Gecode::Space*"))

(defun dfs-next (dfs)
  (let ((solution
          (ffi:c-inline (dfs) (:pointer-void) :pointer-void
                        "((Gecode::DFS<Gecode::Space>*)(#0))->next()"
                                              :one-liner t)))
    (if (si:null-pointer-p solution)
        nil
        solution)))

(defun dfs-count (dfs)
  (ffi:c-inline (dfs) (:pointer-void) :int
                "{
Gecode::DFS<Gecode::Space> *dfs = (Gecode::DFS<Gecode::Space>*)(#0);
int n = 0;
Gecode::Space *s;
while(s = dfs->next()) {
  n++;
  delete s;
}
@(return 0) = n;
}"))



(defun bool-space-ins (space)
  (ffi:c-inline (space) (:pointer-void) :object
                "{
BoolSpace *space = ((BoolSpace*)(#0));

Gecode::BoolVarArray vars = *(space->getVars());

int n = vars.size();

cl_object result = ECL_NIL;

for(int i; i<n; i++) {
Gecode::BoolVar var = vars[i];
int min = var.min();
int max = var.max();
cl_object list;
if (min != max)
  list = cl_list(2, ecl_make_fixnum(min), ecl_make_fixnum(max));
else
  list = ecl_make_fixnum(min);
result = ecl_cons(list, result);
}

@(return 0) = cl_nreverse(result);

}"))

(defun int-space-ins (space)
  (ffi:c-inline (space) (:pointer-void) :object
                "{
IntSpace *space = ((IntSpace*)(#0));

Gecode::IntVarArray vars = *(space->getVars());

int n = vars.size();

cl_object result = ECL_NIL;

for(int i; i<n; i++) {
Gecode::IntVar var = vars[i];
int min = var.min();
int max = var.max();
cl_object list;
if (min != max)
  list = cl_list(2, ecl_make_fixnum(min), ecl_make_fixnum(max));
else
  list = ecl_make_fixnum(min);
result = ecl_cons(list, result);
}

@(return 0) = cl_nreverse(result);

}"))

(defun pr-bab-space-ins (space)
  (ffi:c-inline (space) (:pointer-void) :object
                "{
PrBABSpace *space = ((PrBABSpace*)(#0));

Gecode::BoolVarArray vars = *(space->getVars());

int n = vars.size();

cl_object result = ECL_NIL;

for(int i; i<n; i++) {
Gecode::BoolVar var = vars[i];
int min = var.min();
int max = var.max();
cl_object list;
if (min != max)
  list = cl_list(2, ecl_make_fixnum(min), ecl_make_fixnum(max));
else
  list = ecl_make_fixnum(min);
result = ecl_cons(list, result);
}

@(return 0) = cl_nreverse(result);

}"))

(defun int-val-min () (error "only within let*-heap"))
(defun %int-val-min (k)
  (ffi:c-inline (k) (:object) :void "
Gecode::IntValBranch foo = Gecode::INT_VAL_MIN();
cl_object toll = ecl_make_pointer((void*)&foo);
ecl_function_dispatch(cl_env_copy,#0)(1, toll);"))

(defun int-val-max () (error "only within let*-heap"))
(defun %int-val-max (k)
  (ffi:c-inline (k) (:object) :void "
Gecode::IntValBranch foo = Gecode::INT_VAL_MAX();
cl_object toll = ecl_make_pointer((void*)&foo);
ecl_function_dispatch(cl_env_copy,#0)(1, toll);"))

(defun int-var-degree-max () (error "only within let*-heap"))
(defun %int-var-degree-max (k)
  (ffi:c-inline (k) (:object) :void "
Gecode::IntVarBranch obj = Gecode::INT_VAR_DEGREE_MAX();
ecl_function_dispatch(cl_env_copy,#0)(1, ecl_make_pointer((void*)&obj));"))

(defun int-var-none () (error "only within let*-heap"))
(defun %int-var-none (k)
  (ffi:c-inline (k) (:object) :void "
Gecode::IntVarBranch obj = Gecode::INT_VAR_NONE();
ecl_function_dispatch(cl_env_copy,#0)(1, ecl_make_pointer((void*)&obj));"))

(defun int-var-rnd (rnd) (declare (ignore rnd)) (error "only within let*-heap"))
(defun %int-var-rnd (rnd k)
  (ffi:c-inline (rnd k) (:pointer-void :object) :void "
Gecode::Rnd* rnd = ((Gecode::Rnd*)(#0));
Gecode::IntVarBranch obj = Gecode::INT_VAR_RND(*rnd);
ecl_function_dispatch(cl_env_copy,#1)(1, ecl_make_pointer((void*)&obj));"))

(defun int-val-rnd (rnd) (declare (ignore rnd)) (error "only within let*-heap"))
(defun %int-val-rnd (rnd k)
  (ffi:c-inline (rnd k) (:pointer-void :object) :void "
Gecode::Rnd* rnd = ((Gecode::Rnd*)(#0));
Gecode::IntValBranch obj = Gecode::INT_VAL_RND(*rnd);
ecl_function_dispatch(cl_env_copy,#1)(1, ecl_make_pointer((void*)&obj));"))

(defun rnd (seed) (declare (ignore seed)) (error "only within let*-heap"))
(defun %rnd (seed k)
  (ffi:c-inline (k seed) (:object :unsigned-int) :void "
Gecode::Rnd obj = Gecode::Rnd(#1);
ecl_function_dispatch(cl_env_copy,#0)(1, ecl_make_pointer((void*)&obj));"))

(defmacro let*-heap (bindings &body body)
  (labels ((%symbol (symbol)
             (let ((*package* (symbol-package symbol)))
               (symbolicate "%" symbol))))
    (if (null bindings)
        `(progn ,@body)
        (destructuring-bind ((variable (fn . args)) . rest)
            bindings
          `(,(%symbol fn) ,@args
            (lambda (,variable)
              (let*-heap ,rest
                ,@body)))))))

(defun branch (space a b)
  (ecase (si:foreign-data-tag space)
    ((:bool-space :pr-bab-space)
     (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
                   "{
Gecode::IntVarBranch* var = ((Gecode::IntVarBranch*)(#1));
Gecode::IntValBranch* val = ((Gecode::IntValBranch*)(#2));

BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVarArray vars = *(boolSpace->getVars());

Gecode::branch(*boolSpace, vars, *var, *val);}"))
    (:int-space
     (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
                   "{
Gecode::IntVarBranch* var = ((Gecode::IntVarBranch*)(#1));
Gecode::IntValBranch* val = ((Gecode::IntValBranch*)(#2));

IntSpace* intSpace = ((IntSpace*)(#0));

Gecode::IntVarArray vars = *(intSpace->getVars());

Gecode::branch(*intSpace, vars, *var, *val);}"))))

(defun expr-or (space boolvars)
  "Return a new boolvar that is constrained to be the OR of boolvars."
  ;; c-inline00003
  (check-type space SI:FOREIGN-DATA)
  (check-type boolvars list)
  (dolist (b boolvars) (check-type b SI:FOREIGN-DATA))
  (ffi:c-inline (space boolvars) (:pointer-void :object) :pointer-void
                "
BoolSpace* boolSpace = ((BoolSpace*)(#0));

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

Gecode::BoolVar* u = new Gecode::BoolVar(*boolSpace, 0, 1);

rel(*boolSpace, Gecode::BOT_OR, a, *u);

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
BoolSpace* boolSpace = ((BoolSpace*)(#0));

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

Gecode::BoolVar* u = new Gecode::BoolVar(*boolSpace, 0, 1);

rel(*boolSpace, Gecode::BOT_AND, a, *u);

@(return 0) = u;

"))

(defun expr-not (space boolvar)
  "Return a new boolvar that is constrained to be the NOT of boolvar."
  ;; c-inline00005
  (check-type space SI:FOREIGN-DATA)
  (check-type boolvar SI:FOREIGN-DATA)
  (ffi:c-inline (space boolvar) (:pointer-void :pointer-void) :pointer-void
                "
BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVar* a = ((Gecode::BoolVar*)(#1));

Gecode::BoolVar* u = new Gecode::BoolVar(*boolSpace, 0, 1);

rel(*boolSpace, *a, Gecode::IRT_NQ, *u);

@(return 0) = u;

"))

(defun post-nand (space i j)
  ;; c-inline00006
  (check-type space SI:FOREIGN-DATA)
  (check-type i non-negative-fixnum)
  (check-type j non-negative-fixnum)
  (ffi:c-inline (space i j) (:pointer-void :int :int) :void
                "{

BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVarArray vars = *(boolSpace->getVars());

int i = #1;
int j = #2;

rel(*boolSpace, vars[i], Gecode::BOT_AND, vars[j], 0);

}"))

(defun assert-imp (space a b)
  "BoolVar a --> BoolVar b."
  ;; c-inline00007
  (check-type space SI:FOREIGN-DATA)
  (check-type a SI:FOREIGN-DATA)
  (check-type b SI:FOREIGN-DATA)
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
                "{

BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVar* a = (Gecode::BoolVar*)#1;
Gecode::BoolVar* b = (Gecode::BoolVar*)#2;

rel(*boolSpace, *a, Gecode::BOT_IMP, *b, 1);

}"))

(defun post-must-be-false (space i)
  "Post that i can only be 0."
  ;; c-inline00008
  (check-type space SI:FOREIGN-DATA)
  (check-type i non-negative-fixnum)
  (ffi:c-inline (space i) (:pointer-void :int) :void
                "{

BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVarArray vars = *(boolSpace->getVars());

int i = #1;

rel(*boolSpace, vars[i], Gecode::IRT_EQ, 0);

}"))

(defun post-must-be-true (space i)
  "Post that i can only be 1."
  ;; c-inline00009
  (check-type space SI:FOREIGN-DATA)
  (check-type i non-negative-fixnum)
  (ffi:c-inline (space i) (:pointer-void :int) :void
                "{

BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVarArray vars = *(boolSpace->getVars());

int i = #1;

rel(*boolSpace, vars[i], Gecode::IRT_EQ, 1);

}"))

(defun boolvar-post-eql (space a b)
  "Boolvar a eql boolvar b."
  ;; c-inline00010
  (check-type space SI:FOREIGN-DATA)
  (check-type a SI:FOREIGN-DATA)
  (check-type b SI:FOREIGN-DATA)
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
                "
BoolSpace* boolSpace = ((BoolSpace*)(#0));

rel(*boolSpace, *((Gecode::BoolVar*)(#1)), Gecode::IRT_EQ,
               *((Gecode::BoolVar*)(#2)));
"))

(defun constrain-not-subset (space other)
  ;; c-inline00011
  (check-type space SI:FOREIGN-DATA)
  (check-type other SI:FOREIGN-DATA)
  (ffi:c-inline (space other) (:pointer-void :pointer-void) :void
                "
PrBABSpace* s = ((PrBABSpace*)(#0));
PrBABSpace* o = ((PrBABSpace*)(#1));

s->constrain_not_subset(*o);

"))

(defun delete-space (space)
  ;; c-inline00012
  (check-type space SI:FOREIGN-DATA)
  (ffi:c-inline (space) (:pointer-void) :void
                "{ delete ((Gecode::Space*)#0); }")
  nil)

(defun clone-bool-space (space)
  ;; c-inline00013
  (check-type space SI:FOREIGN-DATA)
  (assert (eql :bool-space (si:foreign-data-tag space)))
  (ffi:c-inline (space) (:pointer-void) :pointer-void
    "{ @(return 0) = ((BoolSpace*)#0)->clone(); }"))

(defun clone-space (space)
  (ffi:c-inline ((si:foreign-data-tag space) space)
      (:object :pointer-void)
      :object
    "ecl_make_foreign_data(#0,0,((Gecode::Space*)#1)->clone())"
    :one-liner t))

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
                                       non-negative-fixnum)))
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
                                       non-negative-fixnum)))
         vector)
  (loop for tail on (space-to-list space)
        for i upfrom 0
        when (eql 1 (car tail))
          collect (aref vector i)))

(defun space-vars (space)
  ;; c-inline00019
  (check-type space SI:FOREIGN-DATA)
  (ffi:c-inline (space) (:pointer-void) :pointer-void
                "{ @(return 0) = (void*)(((BoolSpace*)(#0))->getVars());}"))

(defun vars-size (vars)
  ;; c-inline00020
  (check-type vars SI:FOREIGN-DATA)
  (ffi:c-inline (vars) (:pointer-void) :int
                "{ @(return 0) = ((Gecode::BoolVarArray*)(#0))->size(); }"))

(defun vars-nth (vars n)
  ;; c-inline00021
  (check-type vars SI:FOREIGN-DATA)
  (check-type n non-negative-fixnum)
  (ffi:c-inline
   (vars n) (:pointer-void :int) :pointer-void
   "{ @(return 0) = (void*)(&((*((Gecode::BoolVarArray*)(#0)))[#1])); }"))


(defun delete-dfs (dfs)
  ;; c-inline00025
  (check-type dfs SI:FOREIGN-DATA)
  (ffi:c-inline (dfs) (:pointer-void) :void
                "{ delete ((Gecode::DFS<BoolSpace>*)#0); }")
  nil)

(defun delete-bab (bab)
  ;; c-inline00025
  (check-type bab SI:FOREIGN-DATA)
  (ffi:c-inline (bab) (:pointer-void) :void
                "{ delete ((Gecode::BAB<BoolSpace>*)#0); }")
  nil)

(defun bab-best (bab)
  (check-type bab SI:FOREIGN-DATA)
  (labels
      ((bab-next (bab)
         ;; c-inline00026
         (ffi:c-inline
          (bab) (:pointer-void) :pointer-void
          "{ @(return 0) = ((Gecode::BAB<BoolSpace>*)(#0))->next(); }")))
    (declare (inline bab-next))
    (loop
      for prev-solution = nil then
                              (progn (when prev-solution
                                       (delete-space prev-solution))
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
Gecode::DFS<BoolSpace>* dfs = (Gecode::DFS<BoolSpace>*)(#0);

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
BoolSpace* boolSpace = ((BoolSpace*)(#0));
Gecode::Gist::Print<BoolSpace> p(\"Print solution\");
Gecode::Gist::Options o;
o.inspect.click(&p);
Gecode::Gist::dfs(boolSpace,o);
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
BoolSpace* boolSpace = ((BoolSpace*)(#0));
Gecode::Gist::Print<BoolSpace> p(\"Print solution\");
Gecode::Gist::Options o;
o.inspect.click(&p);
Gecode::Gist::bab(boolSpace,o);
res = 1;
#else
res = 7;
#endif
@(return 0) = res;
")))
    (unless (eql 1 status)
      (error "Perhaps gist is not enabled? (status is ~S)" status)))
  space)

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
