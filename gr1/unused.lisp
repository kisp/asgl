;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

(in-package :cl-user)

(defun make-boolvar (space)
  (ffi:c-inline (space) (:pointer-void) :pointer-void
    "
gr1::Sp* sp = ((gr1::Sp*)(#0));

@(return 0) = new Gecode::BoolVar(*sp, 0, 1);

"))

(defun expr-not (space boolvar)
  "Return a new boolvar that is constrained to be the NOT of boolvar."
  (ffi:c-inline (space boolvar) (:pointer-void :pointer-void) :pointer-void
    "
gr1::Sp* sp = ((gr1::Sp*)(#0));

Gecode::BoolVar* a = ((Gecode::BoolVar*)(#1));

Gecode::BoolVar* u = new Gecode::BoolVar(*sp, 0, 1);

rel(*sp, *a, Gecode::IRT_NQ, *u);

@(return 0) = u;

"))

(defun post-imp (space i j)
  "Post i ---> j."
  (ffi:c-inline (space i j) (:pointer-void :int :int) :void
    "{

gr1::Sp* sp = ((gr1::Sp*)(#0));

Gecode::BoolVarArray vars = *(sp->getVars());

int i = #1;
int j = #2;

rel(*sp, vars[i], Gecode::BOT_IMP, vars[j], 1);

}"))

(defun assert-imp (space a b)
  "BoolVar a --> BoolVar b."
  (ffi:c-inline (space a b) (:pointer-void :pointer-void :pointer-void) :void
    "{

gr1::Sp* sp = ((gr1::Sp*)(#0));

Gecode::BoolVar* a = (Gecode::BoolVar*)#1;
Gecode::BoolVar* b = (Gecode::BoolVar*)#2;

rel(*sp, *a, Gecode::BOT_IMP, *b, 1);

}"))

(defun post-eqv (space i j)
  "Post i ---> j."
  (ffi:c-inline (space i j) (:pointer-void :int :int) :void
    "{

gr1::Sp* sp = ((gr1::Sp*)(#0));

Gecode::BoolVarArray vars = *(sp->getVars());

int i = #1;
int j = #2;

rel(*sp, vars[i], Gecode::BOT_EQV, vars[j], 1);

}"))

(defun boolvar-post-true (space boolvar)
  (ffi:c-inline (space boolvar) (:pointer-void :pointer-void) :void
    "
gr1::Sp* sp = ((gr1::Sp*)(#0));

rel(*sp, *((Gecode::BoolVar*)(#1)), Gecode::IRT_EQ, 1);

"))

(defun boolvar-post-false (space boolvar)
  (ffi:c-inline (space boolvar) (:pointer-void :pointer-void) :void
    "
gr1::Sp* sp = ((gr1::Sp*)(#0));

rel(*sp, *((Gecode::BoolVar*)(#1)), Gecode::IRT_EQ, 0);

"))

(defun post-multi-grandparents (space node grandparents)
  "Post node ---> U(grandparents)."
  (ffi:c-inline
      (space node grandparents)
      (:pointer-void :int :object)
      :void
    "{

gr1::Sp* sp = ((gr1::Sp*)(#0));

Gecode::BoolVarArray vars = *(sp->getVars());

int i = #1;

int len = (int)ecl_length(#2);
Gecode::BoolVarArgs a(len);

cl_object mylist = #2;
int __i = 0;
while (!Null(mylist)) {
  cl_object mycar = ecl_car(mylist);
  a[__i] = vars[ecl_to_int(mycar)];
  mylist = ecl_cdr(mylist);
  __i++;
}

Gecode::BoolVar u(*sp, 0, 1);

rel(*sp, Gecode::BOT_OR, a, u);

rel(*sp, vars[i], Gecode::BOT_IMP, u, 1);

}"))

(defun sp-getn (sp)
  (ffi:c-inline (sp) (:pointer-void) :int "{ @(return 0) = ((gr1::Sp*)(#0))->getN(); }"))

(defun space-print-to-string (space)
  (let ((status (space-status space)))
    (format nil "#<!!SPACE ~S ~{~S~^ ~}>"
            status
            (mapcar #'boolvar-domain (space-vars-as-list space)))))

(defun space-indices-that-are-in (space &key delete)
  (prog1
      (bits-to-set (space-to-list space))
    (when delete
      (delete-sp space))))

(defun space-indices-that-are-in-and-delete (space)
  (space-indices-that-are-in space :delete t))

(defun conflict-free-all (graph)
  (check-array-is-square graph)
  (let ((order (order graph)))
    (let ((space (make-sp order)))
      (do-edges (edge graph)
        (post-nand space (first edge) (second edge)))
      (let ((solutions (dfs-search-all space)))
        (prog1
            (mapcar #'bits-to-set (mapcar #'space-to-list solutions))
          (mapc #'delete-sp solutions))))))

(defun constr2-all (graph)
  (check-array-is-square graph)
  (let ((order (order graph)))
    (let ((space (make-sp order)))
      (do-grandparents (node grandparents graph)
        (cond
          ((null grandparents)
           (post-must-be-false space node))
          ((null (cdr grandparents))
           (post-imp space node (first grandparents)))
          (t
           (post-multi-grandparents space node grandparents))))
      (let ((solutions (dfs-search-all space)))
        (prog1
            (mapcar #'bits-to-set (mapcar #'space-to-list solutions))
          (mapc #'delete-sp solutions))))))

(defun constr3-all (graph)
  (check-array-is-square graph)
  (let ((order (order graph)))
    (let ((space (make-sp order)))
      (dolist (node (nodes graph))
        (when (null (collect-parents graph node))
          (post-must-be-true space node)))
      (let ((solutions (dfs-search-all space)))
        (prog1
            (mapcar #'bits-to-set (mapcar #'space-to-list solutions))
          (mapc #'delete-sp solutions))))))

(defun constr4-all (graph)
  (check-array-is-square graph)
  (let ((order (order graph)))
    (let ((space (make-sp order)))

      (let ((solutions (dfs-search-all space)))
        (prog1
            (mapcar #'bits-to-set (mapcar #'space-to-list solutions))
          (mapc #'delete-sp solutions))))))

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

(defun constrain-not-attacked-are-in (graph constrain-must-be-true)
  (do-parents (node parents graph)
    (when (null parents)
      (funcall constrain-must-be-true node))))
