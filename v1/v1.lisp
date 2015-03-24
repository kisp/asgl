;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

(in-package :cl-user)

(declaim (optimize (debug 3) (safety 3) (speed 0)))

(ffi:clines "#include \"Foo.h\"")

(eval-when (:compile-toplevel :load-toplevel :execute)
  (use-package :early))

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

(defun make-foo (x)
  (ffi:c-inline (x) (:int) :pointer-void "{ @(return 0) = new v1::Foo(#0); }"))

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

(defun delete-foo (foo)
  (ffi:c-inline (foo) (:pointer-void) :void
                "{ delete ((v1::Foo*)#0); }"))

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
  (ffi:c-inline (dfs) (:pointer-void) :pointer-void
                "{ @(return 0) = ((Gecode::DFS<v1::Foo>*)(#0))->next(); }"))

(defun dfs-statistics (dfs)
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

"))

(defun dfs-search-all (space)
  (let ((dfs (make-dfs space)))
    (delete-foo space)
    (values
     (loop for solution = (dfs-next dfs)
        until (si:null-pointer-p solution)
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

(defun space-indices-that-are-in-otherwise-out-and-delete (space)
  (prog1
      (bits-to-set (space-to-list space) :unassigned-permitted-as-out t)
    (delete-foo space)))

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
  (clear-graph-caches)
  (let* ((order (order graph))
         (space (with-timing (make-foo order))))
    (with-post-env-setup (space)
      (constrain-complete graph))
    (dfs-search-gist-or-list-ins space gist)))

(defun grounded-all (graph &key gist)
  (when gist (error "gist does not make sense here"))
  (clear-graph-caches)
  (let* ((order (order graph))
         (space (with-timing (make-foo order))))
    (with-post-env-setup (space)
      (constrain-complete graph))
    (with-timing (space-status space))
    (list (space-indices-that-are-in-otherwise-out-and-delete space))))

(defun preferred-all (graph &key gist)
  (declare (ignore gist))
  (remove-duplicates
   (sort (complete-all graph) #'< :key #'length)
   :test #'subsetp))

(defun stable-all (graph &key gist)
  (clear-graph-caches)
  (let* ((order (order graph))
         (space (with-timing (make-foo order))))
    (with-post-env-setup (space)
      (constrain-complete graph)
      (constrain-stable graph))
    (dfs-search-gist-or-list-ins space gist)))

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

(defun list-first-if-se (task extensions)
  (values
   (ecase task
     (:se (list (first extensions)))
     (:ee extensions))
   (and (eql task :se) (null extensions))))

(defun all-for-semantic (graph semantic)
  (ecase semantic
    (:co (complete-all graph))
    (:st (stable-all graph))
    (:gr (grounded-all graph))
    (:pr (preferred-all graph))))

(defun ee-se (graph task semantic vector)
  (when (eql task :ee) (write-char #\[))
  (multiple-value-bind (extensions se-no?)
      (list-first-if-se
       task
       (all-for-semantic graph semantic))
    (if se-no?
        (write-string "NO")
        (loop for tail on extensions
           for extension = (car tail)
           do (format t "[~{~A~^,~}]"
                      (mapcar (lambda (index) (aref vector index)) extension))
           unless (null (cdr tail))
           do (write-char #\,))))
  (when (eql task :ee) (write-char #\])))

(defun dc-ds (graph task semantic hash arg)
  (let ((arg-index (gethash arg hash)))
    (flet ((contains-arg-p (extension)
             (member arg-index extension)))
      (let ((extensions (all-for-semantic graph semantic)))
        (if (ecase task
              (:ds (every #'contains-arg-p extensions))
              (:dc (some #'contains-arg-p extensions)))
            (write-string "YES")
            (write-string "NO"))))))

(defun main% (&key (fo "apx") f p a)
  (assert (equal fo "apx"))
  (multiple-value-bind (task semantic) (parse-problem p)
    (let ((*print-case* :downcase))
      (multiple-value-bind (graph vector hash)
          (read-apx-file f)
        (ecase task
          ((:ee :se) (ee-se graph task semantic vector))
          ((:dc :ds) (dc-ds graph task semantic hash a)))
        (terpri)))))

(defvar *cover-file*
  (merge-pathnames "cover.data" (asgl-home)))

(defun main ()
  (setq *debugger-hook* (lambda (c old)
                          (declare (ignore old))
                          (ext:dump-c-backtrace 32)
                          (terpri *error-output*)
                          (print-error-log *error-output* c)
                          (format t "ERROR: ~A~%" c)
                          (ext:quit 1)))
  (format *error-output* "~S~%" ext:*command-args*)
  (when (probe-file *cover-file*)
    (cover:load-points *cover-file*))
  (unwind-protect
       (cond
         ((null (cdr ext:*command-args*))
          (write-line "ASGL v0.0.1")
          (write-line "Kilian Sprotte <kilian.sprotte@gmail.com>"))
         ((equal "--formats" (second ext:*command-args*))
          (write-line "[apx, tgf]"))
         ((equal "--problems" (second ext:*command-args*))
          (write-line "[DC-CO, DC-GR, DC-PR, DC-ST, DS-CO, DS-GR, DS-PR, DS-ST, EE-CO, EE-GR, EE-PR, EE-ST, SE-CO, SE-GR, SE-PR, SE-ST]"))
         ((equal "--cover-report" (second ext:*command-args*))
          (cover:report :out *error-output*)
          (terpri *error-output*))
         (t (apply #'main% (adopt-keywords (cdr ext:*command-args*)))))
    (cover:save-points *cover-file*)))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
