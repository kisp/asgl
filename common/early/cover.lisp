;;; -*-syntax:COMMON-LISP; Mode: LISP-*-

(defpackage :cover
  (:use :cl)
  (:shadow #:defun #:defmethod #+nil #:defmacro)
  (:export #:annotate
           #+cover #:report
           #+cover #:reset
           #+cover #:forget
           #+cover #:forget-all
           #+cover #:*line-limit*
           #+cover #:save-points
           #+cover #:load-points))

(in-package :cover)

;;; This is the September 15, 1991 version of
;;; Richard Waters' test case coverage checker

;;; with adoptions.


#|----------------------------------------------------------------------------|
| Copyright 1991 by the Massachusetts Institute of Technology, Cambridge MA. |
|                                                                            |
| Permission  to  use,  copy, modify, and distribute this software  and  its |
| documentation for any purpose  and without fee is hereby granted, provided |
| that this copyright  and  permission  notice  appear  in  all  copies  and |
| supporting  documentation,  and  that  the  name  of M.I.T. not be used in |
| advertising or  publicity  pertaining  to  distribution  of  the  software |
| without   specific,   written   prior   permission.      M.I.T.  makes  no |
| representations  about  the  suitability of this software for any purpose. |
| It is provided "as is" without express or implied warranty.                |
|                                                                            |
|  M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  INCLUDING  |
|  ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  |
|  M.I.T. BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAMAGES  OR  |
|  ANY  DAMAGES  WHATSOEVER  RESULTING  FROM  LOSS OF USE, DATA OR PROFITS,  |
|  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER  TORTIOUS  ACTION,  |
|  ARISING  OUT  OF  OR  IN  CONNECTION WITH THE USE OR PERFORMANCE OF THIS  |
|  SOFTWARE.                                                                 |
|----------------------------------------------------------------------------|#

#+cover
(defstruct (point (:conc-name nil)
                  (:type list))
  (hit 0)
  (id nil)
  (status :show)
  (name nil)
  (subs nil))

#+cover
(defvar *count* 0)
#+cover
(defvar *hit* 1)
#+cover
(defvar *points* nil)

#+cover
(defvar *annotating* nil)

#+cover
(cl:defun save-points (pathname)
  (let ((pathname (merge-pathnames pathname)))
    (macrolet ((frob (x)
                 `(pprint `(setq ,',x ',,x) output)))
      (format *error-output* ";;; Save cover data ~A~%" pathname)
      (with-open-file (output pathname
                              :direction :output
                              :if-exists :supersede)
        (with-standard-io-syntax
          (frob *count*)
          (frob *hit*)
          (frob *points*))
        t))))

#+cover
(cl:defun load-points (pathname)
  (let ((pathname (merge-pathnames pathname))
        (*load-verbose* nil))
    (format *error-output* ";;; Load cover data ~A~%" pathname)
    (load pathname)))

#+cover
(cl:defun forget (&rest ids)
  (forget1 ids *points*)
  t)

#+cover
(cl:defun forget1 (names ps)
  (dolist (p ps)
    (when (member (id p) names)
      (setf (status p) :forgotten))
    (forget1 names (subs p))))

#+cover
(cl:defun forget-all ()
  (setq *points* nil)
  (setq *hit* 1)
  (setq *count* 0)
  t)

#+cover
(cl:defun reset () (incf *hit*) t)

#+cover
(cl:defun add-top-point (p)
  (setq p (copy-tree p))
  (let ((old (find (fn-name p) *points*
                   :key #'fn-name)))
    (cond (old (setf (id p) (id old))
               (nsubstitute p old *points*))
          (t (setf (id p) (incf *count*))
             (setq *points*
                   (nconc *points*
                          (list p)))))))

#+cover
(cl:defun record-hit (p)
  (unless (= (hit p) *hit*)
    (setf (hit p) *hit*)
    (let ((old (locate (name p))))
      (if old
          (setf (hit old) *hit*)
          (add-point p)))))

#+cover
(cl:defun locate (name)
  (find name
        (if (not (cdr name))
            *points*
            (let ((p (locate (cdr name))))
              (if p (subs p))))
        :key #'name :test #'equal))

#+cover
(cl:defun add-point (p)
  (let ((sup (locate (cdr (name p)))))
    (when sup
      (setq p (copy-tree p))
      (setf (subs sup)
            (nconc (subs sup) (list p)))
      (setf (id p) (incf *count*))
      (dolist (p (subs p))
        (setf (id p) (incf *count*))))))

#+cover
(defvar *line-limit* 100)

#+cover
(declaim (special *depth* *all* *out* *done*))

#+cover
(cl:defun report
    (&key (fn nil)
       (out *standard-output*)
       (all nil))
  (let (p)
    (cond
      ((not (streamp out))
       (with-open-file
           (s out :direction :output)
         (report :fn fn :all all :out s)))
      ((null *points*)
       (format out
               "~%No definitions annotated."))
      ((not fn)
       (report1 *points* all out))
      ((setq p (find fn *points*
                     :key #'fn-name))
       (report1 (list p) all out))
      (t (format out "~%~A is not annotated."
                 fn))))
  (values))

#+cover
(cl:defun fn-name (p)
  (let ((form (cadr (car (name p)))))
    (and (consp form)
         (consp (cdr form))
         (cadr form))))

#+cover
(cl:defun report1 (ps *all* *out*)
  (let ((*depth* 0) (*done* t))
    (mapc #'report2 ps)
    (when *done*
      (format *out*
              "~%;All points exercised."))))

#+cover
(cl:defun report2 (p)
  (case (status p)
    (:forgotten nil)
    (:hidden (mapc #'report2 (subs p)))
    (:show
     (cond ((reportable-subs p)
            (report3 p)
            (let ((*depth* (1+ *depth*)))
              (mapc #'report2 (subs p))))
           ((reportable p)
            (report3 p))))))

#+cover
(cl:defun reportable (p)
  (and (eq (status p) :show)
       (or *all*
           (not (= (hit p) *hit*)))))

#+cover
(cl:defun reportable-subs (p)
  (and (not (eq (status p) :forgotten))
       (or *all* (not (reportable p)))
       (some #'(lambda (s)
                 (or (reportable s)
                     (reportable-subs s)))
             (subs p))))

#+cover
(cl:defun report3 (p)
  (setq *done* nil)
  (let* ((*print-pretty* nil)
         (*print-level* 3)
         (*print-length* nil)
         (m (format nil
                    ";~V@T~:[-~;+~]~{ ~S~}"
                    *depth*
                    (= (hit p) *hit*)
                    (car (name p))))
         (limit (- *line-limit* 8)))
    (when (> (length m) limit)
      (setq m (subseq m 0 limit)))
    (format *out* "~%~A  <~S>" m (id p))))

(cl:defmacro annotate (t-or-nil)
  #-cover (declare (ignore t-or-nil))
  #+cover
  `(eval-when (eval load compile)
     (annotate1 ,t-or-nil))
  #-cover
  nil)

#+cover
(cl:defun annotate1 (flag)
  (shadowing-import
   (set-difference '(defun defmethod #+nil defmacro)
                   (package-shadowing-symbols *package*)))
  (when flag
    (format *error-output* "Coverage annotation applied.~%"))
  (setq *annotating* (not (null flag))))

#+cover
(cl:defmacro defun (n argl &body b)
  (process 'defun 'cl:defun n argl b))

#+cover
(cl:defmacro defmethod (&rest args)
  (labels ((car-or-atom (x)
             (if (atom x)
                 x
                 (car x)))
           (second-or-t (x)
             (if (atom x)
                 t
                 (second x)))
           (handler1 (args)
                (destructuring-bind (name qualifier lambda-list &rest body) args
                  (assert (or (symbolp name)
                              (and (consp name)
                                   (eql 'setf (car name)))))
                  (assert (symbolp qualifier))
                  (assert (listp lambda-list))
                  (list name (list qualifier) lambda-list body)))
           (handler2 (args)
             (destructuring-bind (name lambda-list &rest body) args
               (assert (or (symbolp name)
                           (and (consp name)
                                (eql 'setf (car name)))))
               (assert (listp lambda-list))
               (list name nil lambda-list body)))
           (argument-names (lambda-list)
             (set-difference (mapcar #'car-or-atom lambda-list)
                             lambda-list-keywords))
           (type-names (lambda-list)
             (set-difference (mapcar #'second-or-t lambda-list)
                             lambda-list-keywords)))
    (destructuring-bind (name qualifiers lambda-list body)
        ;; poor man's pattern matching
        (or (ignore-errors (handler1 args))
            (ignore-errors (handler2 args)))
      (let ((defun-name (gensym (format nil "~A ~{~A~^ ~} ~A "
                                        name qualifiers (type-names lambda-list))))
            (arguments (argument-names lambda-list)))
        `(progn
           (defun ,defun-name ,arguments
             (declare (ignorable ,@arguments))
             ,@body)
           (cl:defmethod ,name ,@qualifiers ,lambda-list
             (,defun-name ,@arguments)))))))

#+nil
(cl:defmacro defmacro (n a &body b)
  (process 'defmacro 'cl:defmacro n a b))

#+cover
(cl:defun parse-body (body)
  (let ((decls nil))
    (when (stringp (car body))
      (push (pop body) decls))
    (loop (unless (and (consp (car body))
                       (eq (caar body)
                           'declare))
            (return nil))
       (push (pop body) decls))
    (values (nreverse decls) body)))

#+cover
(defvar *check*
  '((or . c-or) (and . c-and)
    (if . c-if) (when . c-when)
    (unless . c-unless)
    (cond . c-cond) (case . c-case)
    (typecase . c-typecase)))

#+cover
(cl:defun process (cdef def fn argl b)
  (if (not (or *annotating*
               (find fn
                     *points*
                     :key #'fn-name)))
      `(,def ,fn ,argl ., b)
      (multiple-value-bind (decls b)
          (parse-body b)
        ;; (setq b (sublis *check* b))
        (let ((name
               `((:reach
                  (,cdef ,fn ,argl)))))
          `(eval-when (eval load compile)
             (add-top-point
              ',(make-point :name name))
             (,def ,fn ,argl ,@ decls
                   ,(c0 (make-point :name
                                    name)
                        name b)))))))

#+cover
(defvar *fix*
  '((c-or . or) (c-and . and) (c-if . if)
    (c-when . when) (c-unless . unless)
    (c-cond . cond) (c-case . case)
    (c-typecase . typecase)))

#+cover
(declaim (special *subs* *sup*))

#+cover
(cl:defmacro sup-mac () nil)

#+cover
(cl:defmacro def (name args form)
  `(cl:defmacro ,name (&whole w ,@ args
                       &environment env)
     (let* ((*subs* nil)
            (*sup*
             `((:reach ,(sublis *fix* w))
               .,(macroexpand-1
                  (list 'sup-mac) env)))
            (p (make-point :name *sup*))
            (form ,form))
       (setf (subs p) (nreverse *subs*))
       (c0 p *sup* (list form)))))

#+cover
(cl:defmacro c (body &rest msg)
  (c1 `(list ,body) msg :show))

#+cover
(cl:defmacro c-hide (b)
  (c1 `(list ,b) (list :reach b) :hidden))

#+cover
(eval-when (eval load compile)

  (cl:defun c1 (b m s)
    `(let ((n (cons (sublis *fix*
                            (list .,m))
                    *sup*)))
       (push (make-point :name n :status ,s)
             *subs*)
       (c0 (make-point :name n :status ,s)
           n ,b)))

  (cl:defun c0 (p sup b)
    `(macrolet ((sup-mac () ',sup))
       (record-hit ',p)
       .,b)) )

#+cover
(def c-case (key &rest cs)
  `(case ,(c-hide key)
     .,(c-case0 cs)))

#+cover
(def c-typecase (key &rest cs)
  `(typecase ,(c-hide key)
     .,(c-case0 cs)))

#+cover
(cl:defun c-case0 (cs)
  (let ((stuff (mapcar #'c-case1 cs)))
    (when (not (member (caar (last cs))
                       '(t otherwise)))
      (setq stuff
            (nconc stuff
                   `((t ,(c nil :select-none))))))
    stuff))

#+cover
(cl:defun c-case1 (clause)
  `(,(car clause)
     ,(c `(progn ., (cdr clause)) :select
         (car clause))))

#+cover
(def c-if (pred then &optional (else nil))
  `(if ,(c-hide pred)
       ,(c then :non-null pred)
       ,(c else :null pred)))

#+cover
(def c-when (pred &rest actions)
  `(if ,(c-hide pred)
       ,(c `(progn ., actions)
           :non-null pred)
       ,(c nil :null pred)))

#+cover
(def c-unless (pred &rest actions)
  `(if (not ,(c-hide pred))
       ,(c `(progn ., actions) :null pred)
       ,(c nil :non-null pred)))

#+cover
(def c-cond (&rest cs)
  (c-cond0 (gensym) cs))

#+cover
(cl:defun c-cond0 (var cs)
  (cond ((null cs) (c nil :all-null))
        ((eq (caar cs) t)
         (c (if (cdar cs)
                `(progn .,(cdar cs))
                t)
            :first-non-null t))
        ((cdar cs)
         `(if ,(c-hide (caar cs))
              ,(c `(progn .,(cdar cs))
                  :first-non-null
                  (caar cs))
              ,(c-cond0 var (cdr cs))))
        (t `(let ((,var
                   ,(c-hide (caar cs))))
              (if ,var
                  ,(c var :first-non-null
                      (caar cs))
                  ,(c-cond0 var
                            (cdr cs)))))))

#+cover
(def c-or (&rest ps) (c-or0 ps))

#+cover
(cl:defun c-or0 (ps)
  (if (null (cdr ps))
      (c (car ps) :eval-all (car ps))
      (let ((var (gensym)))
        `(let ((,var ,(c-hide (car ps))))
           (if ,var
               ,(c var :first-non-null
                   (car ps))
               ,(c-or0 (cdr ps)))))))

#+cover
(def c-and (&rest ps)
  `(cond .,(maplist #'c-and0
                    (or ps (list t)))))

#+cover
(cl:defun c-and0 (ps)
  (if (null (cdr ps))
      `(t ,(c (car ps) :eval-all (car ps)))
      `((not ,(c-hide (car ps)))
        ,(c nil :first-null (car ps)))))

#+cover
(deftype c-and (&rest b) `(and ., b))

#+cover
(deftype c-or (&rest b) `(or ., b))

#|----------------------------------------------------------------------------|
| Copyright 1991 by the Massachusetts Institute of Technology, Cambridge MA. |
|                                                                            |
| Permission  to  use,  copy, modify, and distribute this software  and  its |
| documentation for any purpose  and without fee is hereby granted, provided |
| that this copyright  and  permission  notice  appear  in  all  copies  and |
| supporting  documentation,  and  that  the  name  of M.I.T. not be used in |
| advertising or  publicity  pertaining  to  distribution  of  the  software |
| without   specific,   written   prior   permission.      M.I.T.  makes  no |
| representations  about  the  suitability of this software for any purpose. |
| It is provided "as is" without express or implied warranty.                |
|                                                                            |
|  M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  INCLUDING  |
|  ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  |
|  M.I.T. BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAMAGES  OR  |
|  ANY  DAMAGES  WHATSOEVER  RESULTING  FROM  LOSS OF USE, DATA OR PROFITS,  |
|  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER  TORTIOUS  ACTION,  |
|  ARISING  OUT  OF  OR  IN  CONNECTION WITH THE USE OR PERFORMANCE OF THIS  |
|  SOFTWARE.                                                                 |
|----------------------------------------------------------------------------|#
