;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

(in-package :cl-user)

(defun make-boolvar (space)
  (ffi:c-inline (space) (:pointer-void) :pointer-void
    "
v1::Foo* foo = ((v1::Foo*)(#0));

@(return 0) = new Gecode::BoolVar(*foo, 0, 1);

"))

(defun post-imp (space i j)
  "Post i ---> j."
  (ffi:c-inline (space i j) (:pointer-void :int :int) :void
    "{

v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVarArray vars = *(foo->getVars());

int i = #1;
int j = #2;

rel(*foo, vars[i], Gecode::BOT_IMP, vars[j], 1);

}"))

(defun post-eqv (space i j)
  "Post i ---> j."
  (ffi:c-inline (space i j) (:pointer-void :int :int) :void
    "{

v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVarArray vars = *(foo->getVars());

int i = #1;
int j = #2;

rel(*foo, vars[i], Gecode::BOT_EQV, vars[j], 1);

}"))

(defun boolvar-post-true (space boolvar)
  (ffi:c-inline (space boolvar) (:pointer-void :pointer-void) :void
    "
v1::Foo* foo = ((v1::Foo*)(#0));

rel(*foo, *((Gecode::BoolVar*)(#1)), Gecode::IRT_EQ, 1);

"))

(defun boolvar-post-false (space boolvar)
  (ffi:c-inline (space boolvar) (:pointer-void :pointer-void) :void
    "
v1::Foo* foo = ((v1::Foo*)(#0));

rel(*foo, *((Gecode::BoolVar*)(#1)), Gecode::IRT_EQ, 0);

"))

(defun post-multi-grandparents (space node grandparents)
  "Post node ---> U(grandparents)."
  (ffi:c-inline
      (space node grandparents)
      (:pointer-void :int :object)
      :void
    "{

v1::Foo* foo = ((v1::Foo*)(#0));

Gecode::BoolVarArray vars = *(foo->getVars());

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

Gecode::BoolVar u(*foo, 0, 1);

rel(*foo, Gecode::BOT_OR, a, u);

rel(*foo, vars[i], Gecode::BOT_IMP, u, 1);

}"))

(defun foo-getn (foo)
  (ffi:c-inline (foo) (:pointer-void) :int "{ @(return 0) = ((v1::Foo*)(#0))->getN(); }"))

(defun space-print-to-string (space)
  (let ((status (space-status space)))
    (format nil "#<!!SPACE ~S ~{~S~^ ~}>"
            status
            (mapcar #'boolvar-domain (space-vars-as-list space)))))

(defun cart-product (n)
  (let ((solutions (dfs-search-all (make-foo n))))
    (prog1
        (mapcar #'space-to-list solutions)
      (mapc #'delete-foo solutions))))

(defun conflict-free-all (graph)
  (check-array-is-square graph)
  (let ((order (order graph)))
    (let ((space (make-foo order)))
      (do-edges (edge graph)
        (post-nand space (first edge) (second edge)))
      (let ((solutions (dfs-search-all space)))
        (prog1
            (mapcar #'bits-to-set (mapcar #'space-to-list solutions))
          (mapc #'delete-foo solutions))))))

(defun constr2-all (graph)
  (check-array-is-square graph)
  (let ((order (order graph)))
    (let ((space (make-foo order)))
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
          (mapc #'delete-foo solutions))))))

(defun constr3-all (graph)
  (check-array-is-square graph)
  (let ((order (order graph)))
    (let ((space (make-foo order)))
      (dolist (node (nodes graph))
        (when (null (collect-parents graph node))
          (post-must-be-true space node)))
      (let ((solutions (dfs-search-all space)))
        (prog1
            (mapcar #'bits-to-set (mapcar #'space-to-list solutions))
          (mapc #'delete-foo solutions))))))

(defun constr4-all (graph)
  (check-array-is-square graph)
  (let ((order (order graph)))
    (let ((space (make-foo order)))

      (let ((solutions (dfs-search-all space)))
        (prog1
            (mapcar #'bits-to-set (mapcar #'space-to-list solutions))
          (mapc #'delete-foo solutions))))))

(defun constrain-not-attacked-are-in (graph constrain-must-be-true)
  (do-parents (node parents graph)
    (when (null parents)
      (funcall constrain-must-be-true node))))
