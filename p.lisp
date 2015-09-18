(in-package :asgl)

;; (let ((v (make-array 100000)))
;;   (push 0 (aref v 1))
;;   (push 1 (aref v 0))
;;   (dotimes (i 50000) (assert (eql 3 (length (collect-answer v (make-task :ee) (make-semantic :co)))))))

;; (dolist (task '(:ee :se))
;;   (dolist (sem '(:co :st :pr :gr))
;;     (print (list task sem))
;;     (dotimes (i 50000) (collect-answer '(5 . 7) (make-task task) (make-semantic sem)))))

(dolist (task '(:dc :ds))
  (dolist (sem '(:co :st :pr :gr))
    (print (list task sem))
    (dotimes (i 50000) (collect-answer '(5 . 7) (make-task task 0) (make-semantic sem)))))
