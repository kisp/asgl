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
  ;; conditions
  (:export #:engine-stopped)
  (:export
   #:make-bool-space
   #:make-pr-bab-space
   #:make-int-space
   #:branch
   #:space-status
   #:space-propagators
   #:clone-space
   #:delete-space
   #:with-space)
  (:export
   #:make-dfs-engine
   #:make-dfs-engine-with-options
   #:make-bab-engine
   #:make-bab-engine-with-options
   #:dfs-next
   #:bab-next
   #:dfs-count
   #:dfs-statistics
   #:bab-statistics
   #:delete-dfs
   #:delete-bab)
  (:export #:make-default-search-options
           #:with-default-search-options
           #:search-options-clone
           #:search-options-threads
           #:search-options-commit-distance
           #:search-options-adaptive-distance
           #:search-options-nogoods-limit
           #:search-options-stop
           ;; #:search-options-cutoff
           )
  (:export #:make-node-stop
           #:make-fail-stop
           #:make-time-stop)
  (:export
   #:let*-heap)
  (:export
   #:post-must-be-true
   #:post-must-be-false
   #:post-nand
   #:post-ored-vars-eql-neg-var
   #:post-ored-vars-imp-neg-var)
  (:export
   #:assert-imp
   #:assert-nand
   #:assert-true
   #:assert-false)
  (:export
   #:vector-indices-bot-eql-var
   #:vector-indices-bot-eql-const)
  (:export
   #:expr-or
   #:expr-and
   #:expr-not)
  (:export #:make-boolvar-array)
  (:export #:delete-boolvar)
  (:export
   #:boolvar-post-eql)
  (:export #:rnd)
  (:export
   #:int-var-none
   #:int-var-degree-max
   #:int-var-activity-max
   #:int-var-afc-max
   #:int-var-rnd
   #:int-var-merit-min
   #:int-var-merit-max
   #:tiebreak)
  (:export
   #:int-val-rnd
   #:int-val-min
   #:int-val-max)
  (:export
   #:int-space-ins
   #:pr-bab-space-ins
   #:bool-space-ins)
  (:export #:constrain-not-subset)
  (:export #:dfs-search-gist
           #:bab-search-gist)
  (:export #:delete-generic
           #:let-delete
           #:let*-delete)
  ;; deprecated
  (:export
   #:space-vars-as-list
   #:space-vars-as-vector
   #:space-print-in
   #:space-collect-in
   #:bab-best
   #:space-to-list)
  ;; ============================================================
  ;; clause
  ;; ============================================================
  (:export #:assert-clause))

(in-package :gecode)

#+nil(declaim (optimize (debug 3) (safety 3) (speed 0)))
(declaim (optimize (debug 0) (safety 1) (speed 3) (space 0)))

(ffi:clines "#include \"BoolSpace.h\"")
(ffi:clines "#include \"PrBABSpace.h\"")
(ffi:clines "#include \"IntSpace.h\"")

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

#+fobj-leak-checks
(progn
  (defvar *pool* nil)

  (defun pool-start ()
    (setq *pool* nil))

  (defun pool-check (msg)
    (unless (null *pool*)
      (error (format nil "~A~%~S" msg *pool*)))))

(defmacro define-foreign-constructor ((name cname &key tag) &body args)
  (labels ((arg-var (arg) (first arg))
           (arg-ctype (arg) (second arg))
           (arg-type (arg) (let ((type (second arg)))
                             (if (stringp (arg-ctype arg))
                                 :pointer-void
                                 (arg-ctype arg))))
           (arg-options (arg) (cddr arg))
           (arg-deref (arg) (getf (arg-options arg) :deref nil)))
    `(defun ,name ,(mapcar #'arg-var args)
       (let ((obj
               (ffi:c-inline
                   (',tag ,@(mapcar #'arg-var args))
                   (:object ,@(mapcar #'arg-type args))
                   :object
                 ,(format nil "ecl_make_foreign_data(#0,0,new ~A(~{~A~^,~}))"
                          cname
                          (loop for i upfrom 1
                                for arg in args
                                collect (format
                                         nil "~@[~A~](#~D)"
                                         (when (eql :pointer-void (arg-type arg))
                                           (format nil "~:[~;*~](~A)"
                                                   (arg-deref arg) (arg-ctype arg)))
                                         i)))
                 :one-liner t)))
         #+fobj-leak-checks(push obj *pool*)
         obj))))

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

(define-foreign-constructor (make-dfs-engine-with-options
                             "Gecode::DFS<Gecode::Space>" :tag :dfs-engine)
    (space "Gecode::Space*")
  (options "Gecode::Search::Options*" :deref t))

(define-foreign-constructor (make-bab-engine
                             "Gecode::BAB<Gecode::Space>" :tag :bab-engine)
    (space "Gecode::Space*"))

(define-foreign-constructor (make-bab-engine-with-options
                             "Gecode::BAB<Gecode::Space>" :tag :bab-engine)
    (space "Gecode::Space*")
  (options "Gecode::Search::Options*" :deref t))

(define-foreign-constructor (make-default-search-options
                             "Gecode::Search::Options" :tag :search-options))

(define-foreign-constructor (make-node-stop
                             "Gecode::Search::NodeStop" :tag :node-stop)
    (l :unsigned-long-long))

(define-foreign-constructor (make-fail-stop
                             "Gecode::Search::FailStop" :tag :fail-stop)
    (l :unsigned-long-long))

(define-foreign-constructor (make-time-stop
                             "Gecode::Search::TimeStop" :tag :time-stop)
    (l :unsigned-long-long))

(defmacro with-default-search-options ((options) &body body)
  `(let ((,options (make-default-search-options)))
     (unwind-protect
          (progn ,@body)
       (delete-generic ,options))))

(defun search-options-clone (search-options)
  (ffi:c-inline (search-options) (:pointer-void) :bool
    "(*(Gecode::Search::Options*)(#0)).clone"
    :one-liner t))

(defun (setf search-options-clone) (value search-options)
  (ffi:c-inline (search-options value) (:pointer-void :bool) :void
    "(*(Gecode::Search::Options*)(#0)).clone = #1"
    :one-liner t)
  value)

(defun search-options-threads (search-options)
  (ffi:c-inline (search-options) (:pointer-void) :double
    "(*(Gecode::Search::Options*)(#0)).threads"
    :one-liner t))

(defun (setf search-options-threads) (value search-options)
  (ffi:c-inline (search-options value) (:pointer-void :double) :void
    "(*(Gecode::Search::Options*)(#0)).threads = #1"
    :one-liner t))

(defun search-options-commit-distance (search-options)
  (ffi:c-inline (search-options) (:pointer-void) :unsigned-int
    "(*(Gecode::Search::Options*)(#0)).c_d"
    :one-liner t))

(defun (setf search-options-commit-distance) (value search-options)
  (ffi:c-inline (search-options value) (:pointer-void :unsigned-int) :void
    "(*(Gecode::Search::Options*)(#0)).c_d = #1"
    :one-liner t))

(defun search-options-adaptive-distance (search-options)
  (ffi:c-inline (search-options) (:pointer-void) :unsigned-int
    "(*(Gecode::Search::Options*)(#0)).a_d"
    :one-liner t))

(defun (setf search-options-adaptive-distance) (value search-options)
  (ffi:c-inline (search-options value) (:pointer-void :unsigned-int) :void
    "(*(Gecode::Search::Options*)(#0)).a_d = #1"
    :one-liner t))

(defun search-options-nogoods-limit (search-options)
  (ffi:c-inline (search-options) (:pointer-void) :unsigned-int
    "(*(Gecode::Search::Options*)(#0)).nogoods_limit"
    :one-liner t))

(defun (setf search-options-nogoods-limit) (value search-options)
  (ffi:c-inline (search-options value) (:pointer-void :unsigned-int) :void
    "(*(Gecode::Search::Options*)(#0)).nogoods_limit = #1"
    :one-liner t))

(defun search-options-stop (search-options)
  (let ((pointer
          (ffi:c-inline (search-options) (:pointer-void) :pointer-void
            "(*(Gecode::Search::Options*)(#0)).stop"
            :one-liner t)))
    (unless (si:null-pointer-p pointer)
      pointer)))

(defun (setf search-options-stop) (value search-options)
  (ffi:c-inline (search-options value) (:pointer-void :pointer-void) :void
    "(*(Gecode::Search::Options*)(#0)).stop = (Gecode::Search::Stop*)(#1)"
    :one-liner t))

(define-condition engine-stopped ()
  ())

(defun dfs-next (dfs)
  (multiple-value-bind (solution stopped)
      (ffi:c-inline (dfs) (:pointer-void) (values :pointer-void :bool)
        "
Gecode::DFS<Gecode::Space> *dfs = ((Gecode::DFS<Gecode::Space>*)(#0));
@(return 0) = dfs->next();
@(return 1) = dfs->stopped();")
    (when stopped
      (error 'engine-stopped))
    (if (si:null-pointer-p solution)
        nil
        (prog1
            solution
          #+fobj-leak-checks(push solution *pool*)))))

(declaim (inline bab-next))
(defun bab-next (bab)
  (multiple-value-bind (solution stopped)
      (ffi:c-inline (bab) (:pointer-void) (values :pointer-void :bool)
        "
Gecode::BAB<Gecode::Space> *bab = ((Gecode::BAB<Gecode::Space>*)(#0));
@(return 0) = bab->next();
@(return 1) = bab->stopped();")
    (when stopped
      (error 'engine-stopped))
    (if (si:null-pointer-p solution)
        nil
        (prog1
            solution
          #+fobj-leak-checks(push solution *pool*)))))

(defun dfs-count (dfs &key (error-on-stopped t) delete-engine)
  (multiple-value-bind (n stopped)
      (ffi:c-inline (dfs) (:pointer-void) (values :int :bool)
        "{
Gecode::DFS<Gecode::Space> *dfs = (Gecode::DFS<Gecode::Space>*)(#0);
int n = 0;
Gecode::Space *s;
while(s = dfs->next()) {
  n++;
  delete s;
}
@(return 0) = n;
@(return 1) = dfs->stopped();
}")
    (when (and error-on-stopped stopped)
      (error "engine was stopped"))
    (multiple-value-prog1
        (values n stopped)
      (when delete-engine
        (delete-dfs dfs)))))

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

(defun int-var-activity-max (decay) (declare (ignore decay)) (error "only within let*-heap"))
(defun %int-var-activity-max (decay k)
  (ffi:c-inline (k decay) (:object :double) :void "
Gecode::IntVarBranch obj = Gecode::INT_VAR_ACTIVITY_MAX(#1);
ecl_function_dispatch(cl_env_copy,#0)(1, ecl_make_pointer((void*)&obj));"))

(defun int-var-afc-max (decay) (declare (ignore decay)) (error "only within let*-heap"))
(defun %int-var-afc-max (decay k)
  (ffi:c-inline (k decay) (:object :double) :void "
Gecode::IntVarBranch obj = Gecode::INT_VAR_AFC_MAX(#1);
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

(defun int-var-merit-min (fn) (declare (ignore fn)) (error "only within let*-heap"))
(defun %int-var-merit-min (fn k)
  (ffi:c-inline (fn k) (:pointer-void :object) :void "
Gecode::IntVarBranch obj = Gecode::INT_VAR_MERIT_MIN((Gecode::BoolBranchMerit)#0);
ecl_function_dispatch(cl_env_copy,#1)(1, ecl_make_pointer((void*)&obj));"))

(defun int-var-merit-max (fn) (declare (ignore fn)) (error "only within let*-heap"))
(defun %int-var-merit-max (fn k)
  (ffi:c-inline (fn k) (:pointer-void :object) :void "
Gecode::IntVarBranch obj = Gecode::INT_VAR_MERIT_MAX((Gecode::BoolBranchMerit)#0);
ecl_function_dispatch(cl_env_copy,#1)(1, ecl_make_pointer((void*)&obj));"))

(defun tiebreak (a b) (declare (ignore a b)) (error "only within let*-heap"))
(defun %tiebreak (a b k)
  (ffi:c-inline (a b k) (:pointer-void :pointer-void :object) :void "
Gecode::TieBreak<Gecode::IntVarBranch> obj =
  Gecode::tiebreak(*(Gecode::IntVarBranch*)#0, *(Gecode::IntVarBranch*)#1);
ecl_function_dispatch(cl_env_copy,#2)(1, ecl_make_pointer((void*)&obj));"))

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
        (with-gensyms (k)
          (destructuring-bind ((variable (fn . args)) . rest)
              bindings
            `(let ((,k (lambda (,variable)
                         (let*-heap ,rest
                           ,@body))))
               ,(case fn
                  (ecase
                      (destructuring-bind (keyform . alternatives)
                          args
                        `(ecase ,keyform
                           ,@(mapcar (lambda (alternative)
                                       (destructuring-bind (values form) alternative
                                         `(,values ,(destructuring-bind (fn . args) form
                                                      `(,(%symbol fn) ,@args ,k)))))
                              alternatives))))
                  (case
                      (destructuring-bind (keyform . alternatives)
                          args
                        `(case ,keyform
                           ,@(mapcar (lambda (alternative)
                                       (destructuring-bind (values form) alternative
                                         `(,values ,(destructuring-bind (fn . args) form
                                                      `(,(%symbol fn) ,@args ,k)))))
                              alternatives)
                           (t (funcall ,k nil)))))
                  (t `(,(%symbol fn) ,@args ,k)))))))))

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
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type boolvars list)
  ;; (dolist (b boolvars) (check-type b SI:FOREIGN-DATA))
  (let ((var
          (ffi:c-inline (space boolvars) (:pointer-void :object) :object
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

@(return 0) = ecl_make_foreign_data(ecl_make_keyword(\"BOOLVAR\"), 0, u);

")))
    #+fobj-leak-checks(push var *pool*)
    var))

(defun make-boolvar-array (space n)
  (let ((vector (make-array n)))
    (ffi:c-inline (space n vector) (:pointer-void :int :object) :void
      "{

BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVarArray a(*boolSpace, #1, 0, 1);

cl_object v = #2;

for(int i = 0; i<#1; i++)
  ecl_aset_unsafe(v,i,ecl_make_pointer((void*)(&a[i])));

}")
    vector))

(defun delete-boolvar (boolvar)
  #+fobj-leak-checks
  (progn
    (assert (member boolvar *pool*))
    (setq *pool* (delete boolvar *pool*)))
  (ffi:c-inline (boolvar) (:pointer-void) :void
    "delete ((Gecode::BoolVar*)(#0))"
    :one-liner t))

(defun expr-and (space boolvars)
  "Return a new boolvar that is constrained to be the AND of boolvars."
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type boolvars list)
  ;; (dolist (b boolvars) (check-type b SI:FOREIGN-DATA))
  (let ((var
          (ffi:c-inline (space boolvars) (:pointer-void :object) :object
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

@(return 0) = ecl_make_foreign_data(ecl_make_keyword(\"BOOLVAR\"), 0, u);

")))
    #+fobj-leak-checks(push var *pool*)
    var))

(defun expr-not (space boolvar)
  "Return a new boolvar that is constrained to be the NOT of boolvar."
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type boolvar SI:FOREIGN-DATA)
  (let ((var
          (ffi:c-inline (space boolvar) (:pointer-void :pointer-void) :object
            "
BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVar* a = ((Gecode::BoolVar*)(#1));

Gecode::BoolVar* u = new Gecode::BoolVar(*boolSpace, 0, 1);

rel(*boolSpace, *a, Gecode::IRT_NQ, *u);

@(return 0) = ecl_make_foreign_data(ecl_make_keyword(\"BOOLVAR\"), 0, u);

")))
    #+fobj-leak-checks(push var *pool*)
    var))

(defun post-nand (space i j)
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type i non-negative-fixnum)
  ;; (check-type j non-negative-fixnum)
  (ffi:c-inline (space i j) (:pointer-void :int :int) :void
    "{

BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVarArray vars = *(boolSpace->getVars());

int i = #1;
int j = #2;

rel(*boolSpace, vars[i], Gecode::BOT_AND, vars[j], 0);

}"))

(defun post-ored-vars-eql-neg-var (space vars var)
  (ffi:c-inline (space vars var) (:pointer-void :object :object) :void
    "{

BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVarArray vars = *(boolSpace->getVars());

int len = (int)ecl_length(#1);
Gecode::BoolVarArgs a(len);

cl_object mylist = #1;
int __i = 0;
while (!Null(mylist)) {
  cl_object mycar = ecl_car(mylist);
  a[__i] = vars[ecl_fixnum(mycar)];
  mylist = ecl_cdr(mylist);
  __i++;
}

Gecode::BoolVarArgs none;
clause(*boolSpace, Gecode::BOT_AND, none, a, vars[ecl_fixnum(#2)]);

}"))

(defun post-ored-vars-imp-neg-var (space vars var)
  (let ((length (length vars)))
    (cond
      ((zerop length)
       ;; nothing to do
       )
      ((eql 1 length)
       (post-nand space (first vars) var))
      ((eql 2 length)
       (post-nand space (first vars) var)
       (post-nand space (second vars) var))
      (t (ffi:c-inline (space vars var) (:pointer-void :object :object) :void
           "{

BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVarArray vars = *(boolSpace->getVars());

int len = (int)ecl_length(#1);
Gecode::BoolVarArgs a(len);

cl_object mylist = #1;
int __i = 0;
while (!Null(mylist)) {
  cl_object mycar = ecl_car(mylist);
  a[__i] = vars[ecl_fixnum(mycar)];
  mylist = ecl_cdr(mylist);
  __i++;
}

Gecode::BoolVar u(*boolSpace, 0, 1);
rel(*boolSpace, u, Gecode::IRT_NQ, vars[ecl_fixnum(#2)]);

rel(*boolSpace, a, Gecode::IRT_LQ, u);

}")))))

(defun assert-imp (space a b)
  "BoolVar a --> BoolVar b."
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type a SI:FOREIGN-DATA)
  ;; (check-type b SI:FOREIGN-DATA)
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
    "rel(*((BoolSpace*)(#0)), *(Gecode::BoolVar*)#1, Gecode::BOT_IMP, *(Gecode::BoolVar*)#2, 1)"
    :one-liner t))

(defun assert-nand (space a b)
  "!(BoolVar a && BoolVar b)."
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type a SI:FOREIGN-DATA)
  ;; (check-type b SI:FOREIGN-DATA)
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
    "rel(*((BoolSpace*)(#0)), *(Gecode::BoolVar*)#1, Gecode::BOT_AND, *(Gecode::BoolVar*)#2, 0)"
    :one-liner t))

(defun assert-false (space a)
  "Post that a can only be 0."
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type a SI:FOREIGN-DATA)
  (ffi:c-inline (space a) (:pointer-void :pointer-void) :void
    "rel(*((BoolSpace*)(#0)), *(Gecode::BoolVar*)#1, Gecode::IRT_EQ, 0)"
    :one-liner t))

(defun assert-true (space a)
  "Post that a can only be 1."
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type a SI:FOREIGN-DATA)
  (ffi:c-inline (space a) (:pointer-void :pointer-void) :void
    "rel(*((BoolSpace*)(#0)), *(Gecode::BoolVar*)#1, Gecode::IRT_EQ, 1)"
    :one-liner t))

(defun post-must-be-false (space i)
  "Post that i can only be 0."
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type i non-negative-fixnum)
  (ffi:c-inline (space i) (:pointer-void :int) :void
    "{

BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVarArray vars = *(boolSpace->getVars());

int i = #1;

rel(*boolSpace, vars[i], Gecode::IRT_EQ, 0);

}"))

(defun post-must-be-true (space i)
  "Post that i can only be 1."
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type i non-negative-fixnum)
  (ffi:c-inline (space i) (:pointer-void :int) :void
    "{

BoolSpace* boolSpace = ((BoolSpace*)(#0));

Gecode::BoolVarArray vars = *(boolSpace->getVars());

int i = #1;

rel(*boolSpace, vars[i], Gecode::IRT_EQ, 1);

}"))

(defun boolvar-post-eql (space a b)
  "Boolvar a eql boolvar b."
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type a SI:FOREIGN-DATA)
  ;; (check-type b SI:FOREIGN-DATA)
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
    "
BoolSpace* boolSpace = ((BoolSpace*)(#0));

rel(*boolSpace, *((Gecode::BoolVar*)(#1)), Gecode::IRT_EQ,
               *((Gecode::BoolVar*)(#2)));
"))

(defun constrain-not-subset (space other)
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type other SI:FOREIGN-DATA)
  (ffi:c-inline (space other) (:pointer-void :pointer-void) :void
    "
PrBABSpace* s = ((PrBABSpace*)(#0));
PrBABSpace* o = ((PrBABSpace*)(#1));

s->constrain_not_subset(*o);

"))

(defmacro with-space ((space form) &body body)
  `(let ((,space ,form))
     (unwind-protect
          (progn ,@body)
       (delete-space ,space))))

(defun delete-space (space)
  ;; (check-type space SI:FOREIGN-DATA)
  #+fobj-leak-checks
  (progn
    (assert (member space *pool*))
    (setq *pool* (delete space *pool*)))
  (ffi:c-inline (space) (:pointer-void) :void
    "{ delete ((Gecode::Space*)#0); }")
  nil)

(defun clone-space (space)
  ;; space-status must have been called, before calling this. Also,
  ;; space must not be failed.
  (let ((obj
          (ffi:c-inline ((si:foreign-data-tag space) space)
              (:object :pointer-void)
              :object
            "ecl_make_foreign_data(#0,0,((Gecode::Space*)#1)->clone())"
            :one-liner t)))
    #+fobj-leak-checks(push obj *pool*)
    obj))

(defun space-status (space)
  ;; (check-type space SI:FOREIGN-DATA)
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

(defun space-propagators (space)
  (ffi:c-inline (space) (:pointer-void) :unsigned-int "
((Gecode::Space*)#0)->propagators()" :one-liner t))

(defun space-to-list (space)
  ;; (check-type space SI:FOREIGN-DATA)
  (mapcar #'boolvar-domain (space-vars-as-list space)))

(defun boolvar-min (boolvar)
  ;; (check-type boolvar SI:FOREIGN-DATA)
  (ffi:c-inline (boolvar) (:pointer-void) :int
    "{ @(return 0) = ((Gecode::BoolVar*)(#0))->min(); }"))

(defun boolvar-max (boolvar)
  ;; (check-type boolvar SI:FOREIGN-DATA)
  (ffi:c-inline (boolvar) (:pointer-void) :int
    "{ @(return 0) = ((Gecode::BoolVar*)(#0))->max(); }"))

(defun boolvar-domain (boolvar)
  ;; (check-type boolvar SI:FOREIGN-DATA)
  (let ((min (boolvar-min boolvar))
        (max (boolvar-max boolvar)))
    (if (eql min max)
        min
        (list min max))))

(defun space-vars-as-list (space)
  ;; (check-type space SI:FOREIGN-DATA)
  (let ((vars (space-vars space)))
    (loop for i from 0 below (vars-size vars)
          collect (vars-nth vars i))))

(defun space-vars-as-vector (space)
  ;; (check-type space SI:FOREIGN-DATA)
  (let* ((vars (space-vars space))
         (size (vars-size vars))
         (vector (make-array size)))
    (loop for i from 0 below size
          do (setf (aref vector i) (vars-nth vars i)))
    vector))

(defun space-print-in (space vector
                       &optional (stream *standard-output*))
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type vector vector)
  ;; (every (lambda (x)  (check-type x (or string non-negative-fixnum))) vector)
  (write-string "[" stream)
  (loop with first-time = t
        for tail on (space-to-list space)
        for i upfrom 0
        do (when (eql 1 (car tail))
             (if first-time
                 (setq first-time nil)
                 (write-string "," stream))
             (princ (aref vector i) stream)))
  (write-string "]" stream)
  nil)

(defun space-collect-in (space vector)
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type vector vector)
  ;; (every (lambda (x) (check-type x (or string non-negative-fixnum))) vector)
  (loop for tail on (space-to-list space)
        for i upfrom 0
        when (eql 1 (car tail))
          collect (aref vector i)))

(defun space-vars (space)
  ;; (check-type space SI:FOREIGN-DATA)
  (ffi:c-inline (space) (:pointer-void) :pointer-void
    "{ @(return 0) = (void*)(((BoolSpace*)(#0))->getVars());}"))

(defun vars-size (vars)
  ;; (check-type vars SI:FOREIGN-DATA)
  (ffi:c-inline (vars) (:pointer-void) :int
    "{ @(return 0) = ((Gecode::BoolVarArray*)(#0))->size(); }"))

(defun vars-nth (vars n)
  ;; (check-type vars SI:FOREIGN-DATA)
  ;; (check-type n non-negative-fixnum)
  (ffi:c-inline
      (vars n) (:pointer-void :int) :pointer-void
    "{ @(return 0) = (void*)(&((*((Gecode::BoolVarArray*)(#0)))[#1])); }"))

(defun delete-dfs (dfs)
  ;; (check-type dfs SI:FOREIGN-DATA)
  #+fobj-leak-checks
  (progn
    (assert (member dfs *pool*))
    (setq *pool* (delete dfs *pool*)))
  (ffi:c-inline (dfs) (:pointer-void) :void
    "{ delete ((Gecode::DFS<BoolSpace>*)#0); }")
  nil)

(defun delete-bab (bab)
  ;; (check-type bab SI:FOREIGN-DATA)
  #+fobj-leak-checks
  (progn
    (assert (member bab *pool*))
    (setq *pool* (delete bab *pool*)))
  (ffi:c-inline (bab) (:pointer-void) :void
    "{ delete ((Gecode::BAB<BoolSpace>*)#0); }")
  nil)

(defun bab-best (bab)
  (loop
    for prev-solution = nil then
                            (progn (when prev-solution
                                     (delete-space prev-solution))
                                   solution)
    for solution = (bab-next bab)
    until (null solution)
    finally (return prev-solution)))

(defun dfs-statistics (dfs)
  ;; (check-type dfs SI:FOREIGN-DATA)
  (multiple-value-bind (fail node depth restart nogood)
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

(defun bab-statistics (bab)
  (multiple-value-bind (fail node depth restart nogood)
      (ffi:c-inline (bab) (:pointer-void)
          (values :unsigned-long-long
                  :unsigned-long-long
                  :unsigned-long-long
                  :unsigned-long-long
                  :unsigned-long-long)
        "
Gecode::BAB<Gecode::Space>* bab = (Gecode::BAB<Gecode::Space>*)(#0);

Gecode::Search::Statistics s = bab->statistics();

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
  ;; (check-type space SI:FOREIGN-DATA)
  (let ((status
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
  ;; (check-type space SI:FOREIGN-DATA)
  (let ((status
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

;;; ============================================================
;;; clause
;;; ============================================================

(defun assert-clause (space pos-boolvars neg-boolvars)
  ;; (check-type space SI:FOREIGN-DATA)
  ;; (check-type pos-boolvars list)
  ;; (dolist (b pos-boolvars) (check-type b SI:FOREIGN-DATA))
  ;; (check-type neg-boolvars list)
  ;; (dolist (b neg-boolvars) (check-type b SI:FOREIGN-DATA))
  (ffi:c-inline (space pos-boolvars neg-boolvars) (:pointer-void :object :object) :void
    "
BoolSpace* boolSpace = ((BoolSpace*)(#0));

cl_object mylist = NULL;
int __i = 0;
int len = 0;

len = (int)ecl_length(#1);
Gecode::BoolVarArgs a(len);
mylist = #1;
__i = 0;
while (!Null(mylist)) {
  cl_object mycar = ecl_car(mylist);
  a[__i] = *((Gecode::BoolVar*)ecl_to_pointer(mycar));
  mylist = ecl_cdr(mylist);
  __i++;
}

len = (int)ecl_length(#2);
Gecode::BoolVarArgs b(len);
mylist = #2;
__i = 0;
while (!Null(mylist)) {
  cl_object mycar = ecl_car(mylist);
  b[__i] = *((Gecode::BoolVar*)ecl_to_pointer(mycar));
  mylist = ecl_cdr(mylist);
  __i++;
}

clause(*boolSpace, Gecode::BOT_OR, a, b, 1);
"))

;;; ============================================================
;;; vector-indices-bot-eql-var
;;; ============================================================

(defun lookup-bot (bot)
  (ecase bot
    (:bot-and
     (ffi:c-inline () () :int "Gecode::BOT_AND" :one-liner t))
    (:bot-or
     (ffi:c-inline () () :int "Gecode::BOT_OR" :one-liner t))
    (:bot-imp
     (ffi:c-inline () () :int "Gecode::BOT_IMP" :one-liner t))
    (:bot-eqv
     (ffi:c-inline () () :int "Gecode::BOT_EQV" :one-liner t))
    (:bot-xor
     (ffi:c-inline () () :int "Gecode::BOT_XOR" :one-liner t))))

(defun vector-indices-bot-eql-var (space vector indices bot var)
  (ffi:c-inline (space vector indices (lookup-bot bot) var)
      (:pointer-void :object :object :int :pointer-void) :void
    "
BoolSpace* boolSpace = ((BoolSpace*)(#0));

int len = (int)ecl_length(#2);
Gecode::BoolVarArgs a(len);

cl_object list = #2;

for(int count = 0; count<len; count++) {
  cl_fixnum i = ecl_fixnum(ECL_CONS_CAR(list));
  a[count] = *(Gecode::BoolVar*)ecl_to_pointer(ecl_aref_unsafe(#1,i));
  list = ECL_CONS_CDR(list);
}

rel(*boolSpace, (Gecode::BoolOpType)#3, a, *(Gecode::BoolVar*)(#4));
"))

(defun vector-indices-bot-eql-const (space vector indices bot const)
  (ffi:c-inline (space vector indices (lookup-bot bot) const)
      (:pointer-void :object :object :int :bool) :void
    "
BoolSpace* boolSpace = ((BoolSpace*)(#0));

int len = (int)ecl_length(#2);
Gecode::BoolVarArgs a(len);

cl_object list = #2;

for(int count = 0; count<len; count++) {
  cl_fixnum i = ecl_fixnum(ECL_CONS_CAR(list));
  a[count] = *(Gecode::BoolVar*)ecl_to_pointer(ecl_aref_unsafe(#1,i));
  list = ECL_CONS_CDR(list);
}

rel(*boolSpace, (Gecode::BoolOpType)#3, a, #4);
"))

;;; delete-generic
(defun delete-generic (object)
  (ecase (si:foreign-data-tag object)
    (:search-options (ffi:c-inline (object) (:pointer-void) :void
                       "delete (Gecode::Search::Options*)#0" :one-liner t))
    (:node-stop (ffi:c-inline (object) (:pointer-void) :void
                  "delete (Gecode::Search::NodeStop*)#0" :one-liner t))
    (:fail-stop (ffi:c-inline (object) (:pointer-void) :void
                  "delete (Gecode::Search::FailStop*)#0" :one-liner t))
    (:time-stop (ffi:c-inline (object) (:pointer-void) :void
                  "delete (Gecode::Search::TimeStop*)#0" :one-liner t))
    (:dfs-engine (delete-dfs object))))

(defmacro let-delete ((&rest bindings) &body body)
  `(let ,bindings
     (unwind-protect
          (progn ,@body)
       ,@(mapcar (lambda (x)
                   `(when ,(first x) (delete-generic ,(first x))))
                 bindings))))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
