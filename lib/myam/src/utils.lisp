(in-package :myam)

;;; * miscellaneous
(defun check-required (name vars required)
  (dolist (var required)
    (assert (member var vars)
            (var)
            "Unrecognized symbol ~S in ~S." var name)))

(defmacro dolist* ((iterator list &optional return-value) &body body)
  "Like DOLIST but destructuring-binds the elements of LIST.

If ITERATOR is a symbol then dolist* is just like dolist EXCEPT
that it creates a fresh binding."
  (if (listp iterator)
      (let ((i (gensym "DOLIST*-I-")))
        `(dolist (,i ,list ,return-value)
           (destructuring-bind ,iterator ,i
             ,@body)))
      `(dolist (,iterator ,list ,return-value)
         (let ((,iterator ,iterator))
           ,@body))))

(defun make-collector (&optional initial-value)
  "Create a collector function.

A Collector function will collect, into a list, all the values
passed to it in the order in which they were passed. If the
callector function is called without arguments it returns the
current list of values."
  (let ((value initial-value)
        (cdr (last initial-value)))
    (lambda (&rest items)
      (if items
          (progn
            (if value
                (if cdr
                    (setf (cdr cdr) items
                          cdr (last items))
                    (setf cdr (last items)))
                (setf value items
                      cdr (last items)))
            items)
          value))))

(defun partitionx (list &rest lambdas)
  "Partitions LIST according to LAMBDAS. Each lambda can be a function
or t or otherwise, in which case the function becomes (constantly t)."
  (let ((collectors (mapcar (lambda (l)
                              (cons (if (and (symbolp l)
                                             (member l (list :otherwise t)
                                                     :test #'string=))
                                        (constantly t)
                                        l)
                                    (make-collector)))
                            lambdas)))
    (dolist (item list)
      (block item
        (dolist* ((test-func . collector-func) collectors)
          (when (funcall test-func item)
            (funcall collector-func item)
            (return-from item)))))
    (mapcar #'funcall (mapcar #'cdr collectors))))

(defvar *myam-print-length* 20)
(defvar *myam-print-level* 5)

(defun format-reason-to-string (control-string &rest format-arguments)
  (let ((*print-length* *myam-print-length*)
        (*print-level* *myam-print-level*))
    (apply #'format nil control-string format-arguments)))
