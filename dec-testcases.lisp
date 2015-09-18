;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(in-package #:asgl)

(defstruct case
  sem-a task-a
  solution
  sem-b task-b)

(defun make-case* (sem-a task-a solution sem-b task-b)
  (make-case :sem-a sem-a :task-a task-a :solution solution :sem-b sem-b :task-b task-b))

(defun case-satisfied (graph arg case)
  (let ((ee-a (collect-answer graph
                              (make-task (case-task-a case) arg)
                              (make-semantic (case-sem-a case))))
        (ee-b (collect-answer graph
                              (make-task (case-task-b case) arg)
                              (make-semantic (case-sem-b case)))))
    (and (eql (case-solution case) ee-a)
         (not (eql ee-a ee-b)))))

(defun satisfied-cases (graph cases)
  (let ((order (car graph)))
    (remove-duplicates
     (mapcan (lambda (arg)
               (copy-list (remove-if-not (curry #'case-satisfied graph arg) cases)))
             (iota order)))))

(defun impossible-case (case)
  (or
   (equal (list (case-task-a case) (case-sem-a case))
          (list (case-task-b case) (case-sem-b case)))
   (and (eql :ds (case-task-a case))
        (eql :dc (case-task-b case))
        (eql (case-sem-a case)
             (case-sem-b case)))
   ;; ;; nur stable kann 0 sein
   ;; (and (not (eql :st (case-sem-a case)))
   ;;      (eql 0 (case-len-a case)))
   ;; ;; gr ist immer 1
   ;; (and (eql :gr (case-sem-a case))
   ;;      (not (eql 1 (case-len-a case))))
   ;; ;; gleich semantik ist gleich
   ;; (eql (case-sem-a case) (case-sem-b case))
   ;; ;; co 1 kann nicht ungleich gr sein
   ;; (and (eql 1 (case-len-a case))
   ;;      (eql :co (case-sem-a case))
   ;;      (eql :gr (case-sem-b case)))
   ;; co 1 kann nicht ungleich pr sein
   ;; (and (eql 1 (case-len-a case))
   ;;      (eql :co (case-sem-a case))
   ;;      (eql :pr (case-sem-b case)))
   ))

(defun generate-cases ()
  (remove-if #'impossible-case
             (map-product #'make-case*
                          '(:co :pr :st :gr)
                          '(:dc :ds)
                          '(t nil)
                          '(:co :pr :st :gr)
                          '(:dc :ds))))

(defun random-graph-01 ()
  (let ((n (+ 2 (random 25))))
    (cons n (random (expt 2 (* n n))))))

(defun run ()
  (let ((missing-cases (generate-cases))
        graphs)
    (restart-case
        (loop for i upfrom 0
              for graph = (random-graph-01)        
              for good = (satisfied-cases graph missing-cases)
              when good do (push graph graphs)
                do (setf missing-cases
                         (set-difference missing-cases good))
              when (zerop (mod i 50))
                do (warn "still ~D missing" (length missing-cases))
              when (zerop (mod i 500))
                do (warn "graphs so far ~S" graphs)
              until (null missing-cases))
      (return-missing () (values missing-cases graphs)))))

(defvar *run1*
  '())

(defun graph-file-name (cons)
  (destructuring-bind (order . bits) cons
    (string-downcase
     (with-output-to-string (*standard-output*)
       (princ order)
       (princ "-")
       (let ((*print-base* 36))
         (princ bits))))))

(defun graph-print-apx (cons)
  (let ((graph (read-graph-input cons)))
    (dotimes (i (order graph))
      (format t "arg(arg~A).~%" i))
    (do-edges (a b graph)
      (format t "att(arg~A,arg~A).~%" a b))))

(defun print-solutions (solutions)
  (write-string "[")
  (let ((first-time t))
    (dolist (x solutions)
      (unless first-time
        (write-char #\,))
      (when first-time (setq first-time nil))
      (format t "[~{arg~A~^,~}]" x)))
  (write-line "]")
  nil)

(defun output-graph-files ()
  (let ((*default-pathname-defaults*
          (ensure-directories-exist #p"/home/paul/unis/github/asgl/data/apx/")))
    (dolist (x *run1*)
      (with-open-file (*standard-output*
                       (format nil "~a.apx" (graph-file-name x))
                       :direction :output
                       :if-exists :supersede)
        (graph-print-apx x))
      (dolist (sem '(:gr :co :pr :st))
        (with-open-file (*standard-output*
                         (format nil "~a.EE-~A" (graph-file-name x) sem)
                         :direction :output
                         :if-exists :supersede)
          (print-solutions
           (collect-answer x (make-task :ee) (make-semantic sem))))))))

(defun output-tests ()
  (let ((i 0))
    (dolist (x *run1*)
      (dolist (sem '(:gr :co :pr :st))
        (let ((solution
                (collect-answer x (make-task :ee) (make-semantic sem))))
          (print `(DEFTEST ,(symbolicate "QUICK-" sem "." (princ-to-string (incf i)))
                      (,(ecase sem
                          (:co 'CHECK-COMPLETE)
                          (:gr 'CHECK-GROUNDED)
                          (:st 'CHECK-STABLE)
                          (:pr 'CHECK-PREFERRED))
                       ',solution ',x)))
          (terpri))))))

(run)
