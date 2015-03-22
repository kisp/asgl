(in-package :arnesi-list-match)

;;;; ** Simple list matching based on code from Paul Graham's On Lisp.

(defmacro acond2 (&rest clauses)
  (if (null clauses)
      nil
      (with-unique-names (val foundp)
        (destructuring-bind ((test &rest progn) &rest others)
            clauses
          `(multiple-value-bind (,val ,foundp)
               ,test
             (if (or ,val ,foundp)
                 (let ((it ,val))
                   (declare (ignorable it))
                   ,@progn)
                 (acond2 ,@others)))))))

(defun varsymp (x)
  (and (symbolp x) (eq (aref (symbol-name x) 0) #\?)))

(defun binding (x binds)
  (labels ((recbind (x binds)
             (if-let ((it (assoc x binds)))
               (or (recbind (cdr it) binds)
                   it))))
    (let ((b (recbind x binds)))
      (values (cdr b) b))))

(defun list-match (x y &optional binds)
  (acond2
   ((or (eql x y) (eql x :_) (eql y :_))
    (values binds t))
   ((binding x binds) (list-match it y binds))
   ((binding y binds) (list-match x it binds))
   ((varsymp x) (values (cons (cons x y) binds) t))
   ((varsymp y) (values (cons (cons y x) binds) t))
   ((and (consp x) (consp y) (list-match (car x) (car y) binds))
    (list-match (cdr x) (cdr y) it))
   (t (values nil nil))))

(defun vars (match-spec)
  (let ((vars nil))
    (labels ((find-vars (spec)
               (cond
                 ((null spec) nil)
                 ((varsymp spec) (push spec vars))
                 ((consp spec)
                  (find-vars (car spec))
                  (find-vars (cdr spec))))))
      (find-vars match-spec))
    (delete-duplicates vars)))

(defmacro list-match-case (target &body clauses)
  (if clauses
      (destructuring-bind ((test &rest progn) &rest others)
          clauses
        (with-unique-names (tgt binds success)
          `(let ((,tgt ,target))
             (multiple-value-bind (,binds ,success)
                 (list-match ,tgt ',test)
               (declare (ignorable ,binds))
               (if ,success
                   (let ,(mapcar (lambda (var)
                                   `(,var (cdr (assoc ',var ,binds))))
                                 (vars test))
                     (declare (ignorable ,@(vars test)))
                     ,@progn)
                   (list-match-case ,tgt ,@others))))))
      nil))

(defun incf-pattern (pattern hash)
  (incf (gethash pattern hash 0)))

(defmacro list-match-case-stats (hash target &body clauses)
  `(list-match-case ,target
     ,@(mapcar (lambda (clause)
                 (destructuring-bind (pattern . body)
                     clause
                   `(,pattern
                     (incf-pattern ',pattern ,hash)
                     ,@body)))
               clauses)))
