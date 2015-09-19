;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(in-package #:asgl)

(defstruct case
  sem-a task-a len-a
  solution
  sem-b task-b)

(defun make-case* (sem-a task-a len-a solution sem-b task-b)
  (make-case :len-a len-a :sem-a sem-a :task-a task-a :solution solution :sem-b sem-b :task-b task-b))

(defun good-length (len spec)
  (cond
    ((integerp spec)
     (= len spec))
    ((consp spec)
     (funcall (first spec) len (second spec)))
    (t
     (error "what to do with ~S?" spec))))

(defun case-satisfied (graph arg case)
  (let ((ee-a (collect-answer graph
                              (make-task (case-task-a case) arg)
                              (make-semantic (case-sem-a case))))
        (ee-b (collect-answer graph
                              (make-task (case-task-b case) arg)
                              (make-semantic (case-sem-b case)))))
    (and (good-length (length (collect-answer graph
                                              (make-task :ee)
                                              (make-semantic (case-sem-a case))))
                      (case-len-a case))
         (eql (case-solution case) ee-a)
         (not (eql ee-a ee-b)))))

(defun satisfied-cases (graph cases)
  (let ((order (car graph)))
    (remove-duplicates
     (mapcan (lambda (arg)
               (copy-list (remove-if-not (curry #'case-satisfied graph arg) cases)))
             (iota order)))))

(defun impossible-case (case)
  (or
   (and (not (eql :st (case-sem-a case)))
        (eql 0 (case-len-a case)))
   ;; gr ist immer 1
   (and (eql :gr (case-sem-a case))
        (not (eql 1 (case-len-a case))))
   ;; __
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
                          '(0 1 2 3 4 (> 4))
                          '(t nil)
                          '(:co :pr :st :gr)
                          '(:dc :ds))))

(defun random-graph-01 ()
  (let ((n (+ 2 (random 15))))
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
  '((16
     . 21986662678879831189164097506798841974342902557529880327601970125784646972084)
    (15 . 23039291271581752259774374568959599721271384016326735968337034119182)
    (15 . 16732989810799198537586418927246787171670928751905345352344111529712)
    (12 . 9110912541835491977928959812949873088681483)
    (11 . 1617521932581545726045649812499374127) (5 . 1549667)
    (12 . 10796957734979254510899121272181508688593956) (7 . 32784905478717)
    (9 . 730881638060827310541504)
    (12 . 9796860388933589609277231139812943089409155)
    (10 . 318357102218757900091811947475)
    (12 . 14025707832639381248652884340685669093597031) (5 . 7631653)
    (6 . 13689129595) (8 . 16681780660952381435) (4 . 33668)
    (13 . 190618062043881309494897266359779897512318473315212)
    (9 . 2277651917719387406340778) (4 . 2217)
    (13 . 9453564958372887198542733408796545989078273784846) (3 . 452)
    (10 . 251053740904157686988750337426) (7 . 388375475042466)))

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
          (ensure-directories-exist #p"/tmp/apx/")))
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

;;;
;; (run)
