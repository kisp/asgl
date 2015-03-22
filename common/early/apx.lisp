;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(ffi:clines "#include \"myfoo.h\"")

(in-package #:early)

(declaim (optimize (debug 3) (safety 3) (speed 0)))

(eval-when (:compile-toplevel :execute)
  (cover:annotate t))

#+nil
(defun vector2hash-table (vector)
  (let ((hash (make-hash-table :test #'eql)))
    (dotimes (i (length vector)
              hash)
      (setf (gethash (aref vector i) hash) i))))

(defun hash-table2vector (hash vector)
  (loop for k being the hash-keys in hash using (hash-value v)
     do (setf (aref vector v) k)))

(defmacro with-apx-readtable (() &body body)
  `(let ((*readtable* (copy-readtable nil)))
     (set-macro-character #\, (lambda (stream char) (values)))
     ,@body))

#+nil
(defun read-apx-line (string)
  (with-input-from-string (input string)
    (read input)
    (read input)))

(defun read-apx-file (pathname)
  (let ()
    (multiple-value-bind (buffer size)
        (ffi:c-inline
         ((coerce (namestring (merge-pathnames pathname)) 'base-string))
         (:object) (values :pointer-void :long)
         "{
long msize = 99;

@(return 0) = slurp_file(#0, &msize);
@(return 1) = msize;
}")
      (let ((arg-count
             (ffi:c-inline (buffer size) (:pointer-void :long) :int
                           "{ @(return 0) = count_args((char*)#0, #1); }")))
        (let ((adj (make-array (list arg-count arg-count) :initial-element 0))
              (vector (make-array arg-count))
              (hash (make-hash-table :test #'equal)))
          (ffi:c-inline (buffer size hash adj)
                        (:pointer-void :long :object :object)
                        :void
                        "{ myfoo((char*)#0, #1, #2, #3); }")
          (hash-table2vector hash vector)
          (values (make-graph-from-adj adj) vector hash)))))
  #+nil
  (let ((table (make-hash-table :test #'equal)))
    (time
     (ffi:c-inline
      ((coerce (namestring (merge-pathnames pathname)) 'base-string)
       table)
      (:object :object) :void "{ myfoo(#0,#1); }"))
    #+nil(describe table)
    #+nil(format t "here are all the keys:~%")
    #+nil(loop for key being the hash-keys of table
            do (format t "~S~%" key))
    (format t "the table count is ~S~%"
            (hash-table-count table))
    #+nil(assert (not (zerop (hash-table-count table)))))
  #+nil
  (let (nodes edges)
    (with-apx-readtable ()
      (with-open-file (input pathname)
        (loop for line = (read-line input nil)
           while line
           do (let ((item (read-apx-line line)))
                (if (null (cdr item))
                    (push (first item) nodes)
                    (push item edges))))))
    (let* ((vector (coerce (nreverse nodes) 'vector))
           (adj (make-array (list (length vector) (length vector))
                            :initial-element 0))
           (hash (vector2hash-table vector)))
      (dolist (edge edges)
        (destructuring-bind (a b) edge
          (setf (aref adj (gethash a hash) (gethash b hash))
                1)))
      (values
       adj
       vector
       hash))))

(eval-when (:compile-toplevel :execute)
  (cover:annotate nil))
