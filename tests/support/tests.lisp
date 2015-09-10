;; -*- paul-nice-on-save:nil -*-

(defpackage :tests (:use :cl :myam :alexandria :early))

(in-package :tests)

(defsuite* :tests)

(setq *default-compile-at* :definition-time)

(defun xteql (expected result)
  (is (set-equal expected result :test #'set-equal)
      "expected ~S~%but got ~S" expected result))

(defun alist-eql (expected result)
  (is (set-equal expected result :test #'equal)
      "expected ~S~%but got ~S" expected result))

(defun check-semantic (graph expected all-fn one-fn dc-fn ds-fn)
  (let ((solutions (funcall all-fn graph)))
    (is (setp solutions :test #'set-equal)
        "solutions are not a set under set-equal:~%~S" solutions)
    (xteql expected solutions)
    ;; one
    (multiple-value-bind (extension exists-p)
        (funcall one-fn graph)
      (is (eql (not (null solutions)) exists-p))
      (if exists-p
          (is (member extension solutions :test #'set-equal))
          (is (null extension))))
    (dotimes (a (early:order graph))
      (is (eql (not (null (some (lambda (solution) (member a solution)) solutions)))
               (funcall dc-fn graph a)))
      (is (eql (every (lambda (solution) (member a solution)) solutions)
               (funcall ds-fn graph a))))))

(in-package :cl-user)

(macrolet ((frob (name semantic task)
             `(defun ,name ,(if (eql 2 (length task))
                                '(graph a)
                                '(graph))
                (let ((task (oo:make-task ,@task))
                      (semantic (oo:make-semantic ,semantic)))
                  (multiple-value-bind (task semantic)
                      (oo:translate-problem task semantic)
                    (oo:collect-answer graph
                                       task
                                       semantic))))))
  ;; all
  (frob $$complete-all :co (:ee))
  (frob $$stable-all :st (:ee))
  (frob $$grounded-all :gr (:ee))
  (frob $$preferred-all :pr (:ee))
  ;; one
  (frob $$complete-one :co (:se))
  (frob $$stable-one :st (:se))
  (frob $$grounded-one :gr (:se))
  (frob $$preferred-one :pr (:se))
  ;; dc
  (frob $$complete-dc :co (:dc a))
  (frob $$stable-dc :st (:dc a))
  (frob $$grounded-dc :gr (:dc a))
  (frob $$preferred-dc :pr (:dc a))
  ;; ds
  (frob $$complete-ds :co (:ds a))
  (frob $$stable-ds :st (:ds a))
  (frob $$grounded-ds :gr (:ds a)))

(defun $$preferred-ds (graph a) (dc-ds1 graph :ds :pr a))

(in-package :tests)

(defun check-complete (expected graph)
  (check-semantic (early:make-graph-from-adj graph) expected
                  #'cl-user::$$complete-all
                  #'cl-user::$$complete-one
                  #'cl-user::$$complete-dc
                  #'cl-user::$$complete-ds))

(defun check-grounded (expected graph)
  (check-semantic (early:make-graph-from-adj graph) expected
                  #'cl-user::$$grounded-all
                  #'cl-user::$$grounded-one
                  #'cl-user::$$grounded-dc
                  #'cl-user::$$grounded-ds))

(defun check-preferred (expected graph)
  (check-semantic (early:make-graph-from-adj graph) expected
                  #'cl-user::$$preferred-all
                  #'cl-user::$$preferred-one
                  #'cl-user::$$preferred-dc
                  #'cl-user::$$preferred-ds))

(defun check-stable (expected graph)
  (check-semantic (early:make-graph-from-adj graph) expected
                  #'cl-user::$$stable-all
                  #'cl-user::$$stable-one
                  #'cl-user::$$stable-dc
                  #'cl-user::$$stable-ds))

(defun seql (a b)
  (assert (alexandria:setp a))
  (assert (alexandria:setp b))
  (alexandria:set-equal a b :test #'alexandria:set-equal))

(defun read-extensions (stream)
  (let ((*readtable* (copy-readtable nil)))
    (set-macro-character
     #\,
     (lambda (stream char)
       (declare (ignore stream char))
       (values)))
    (set-macro-character
     #\[
     (lambda (stream char)
       (declare (ignore char))
       (read-delimited-list #\] stream t)))
    (set-macro-character #\] (get-macro-character #\)))
    (read stream)))

(defun read-extensions-from-string (string)
  (with-input-from-string (input string)
    (read-extensions input)))

(defmacro with-tmp-file ((pathname name) &body body)
  (check-type pathname symbol)
  `(let ((,pathname (merge-pathnames ,name (early:asgl-home))))
     (unwind-protect
          (progn ,@body)
       (when (probe-file ,pathname)
         (delete-file ,pathname)))))

(defmacro with-tmp-file-of-lines ((pathname lines) &body body)
  (check-type pathname symbol)
  `(with-tmp-file (,pathname "tmp.apx")
     (with-open-file (output ,pathname :direction :output)
       (dolist (line ,lines)
         (write-line line output)))
     ,@body))

(defun check-extensions (problem expexted lines)
  (let ((*default-pathname-defaults*
         (early:asgl-home)))
    (with-tmp-file-of-lines (pathname lines)
      (let ((result
             (with-output-to-string (*standard-output*)
               (cl-user::main% :fo "apx" :p problem :f pathname))))
        (myam:is
         (seql (read-extensions-from-string
                expexted)
               (read-extensions-from-string
                result)))))))
