;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(in-package #:asgl)

(defun seql (a b)
  (alexandria:set-equal a b :test #'alexandria:set-equal))

(defstruct case sem-a len-a sem-b)

(defun make-case* (sem-a len-a sem-b)
  (make-case :sem-a sem-a :len-a len-a :sem-b sem-b))

(defun good-length (len spec)
  (cond
    ((integerp spec)
     (= len spec))
    ((consp spec)
     (funcall (first spec) len (second spec)))
    (t
     (error "what to do with ~S?" spec))))

(defun case-satisfied (graph case)
  (let ((ee-a (collect-answer graph
                              (make-task :ee)
                              (make-semantic (case-sem-a case))))
        (ee-b (collect-answer graph
                              (make-task :ee)
                              (make-semantic (case-sem-b case)))))
    (and (good-length (length ee-a) (case-len-a case))
         (not (seql ee-a ee-b)))))

(defun satisfied-cases (graph cases)
  (remove-if-not (curry #'case-satisfied graph) cases))

(defun impossible-case (case)
  (or
   ;; nur stable kann 0 sein
   (and (not (eql :st (case-sem-a case)))
        (eql 0 (case-len-a case)))
   ;; gr ist immer 1
   (and (eql :gr (case-sem-a case))
        (not (eql 1 (case-len-a case))))
   ;; gleich semantik ist gleich
   (eql (case-sem-a case) (case-sem-b case))
   ;; co 1 kann nicht ungleich gr sein
   (and (eql 1 (case-len-a case))
        (eql :co (case-sem-a case))
        (eql :gr (case-sem-b case)))
   ;; co 1 kann nicht ungleich pr sein
   (and (eql 1 (case-len-a case))
        (eql :co (case-sem-a case))
        (eql :pr (case-sem-b case)))))

(defun generate-cases ()
  (remove-if #'impossible-case
             (map-product #'make-case* '(:co :pr :st :gr) '(0 1 2 3 4 (> 4)) '(:co :pr :st :gr))))

(defun random-graph-01 ()
  (let ((n (+ 2 (random 12))))
    (cons n (random (expt 2 (* n n))))))

(defun run ()
  (let ((missing-cases (generate-cases)))
    (loop for i upfrom 0
          for graph = (random-graph-01)
          for good = (satisfied-cases graph missing-cases)
          when good collect graph
            do (setf missing-cases
                     (set-difference missing-cases good))
          when (zerop (mod i 200))
            do (warn "still ~D missing" (length missing-cases))
          until (null missing-cases))))

(defvar *run1*
  '((11 . 301992957378586253197174681733325491) (3 . 111) (5 . 27356534)
    (9 . 687817436252285621005939) (5 . 1786260) (5 . 22273086)
    (10 . 862888436660299517449962964339) (10 . 596777465861733603614638104240)
    (9 . 2375402216629620167358728)
    (13 . 743697891089790209730804976928582147180695825001282)
    (10 . 394169984622845774147552952774)
    (12 . 8137751797062868522571401785579323320965319)))

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
