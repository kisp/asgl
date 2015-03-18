;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; Coding:utf-8 -*-

(in-package #:common-lisp-user)

(defun format* (&rest args)
  (write-string "[INFO] " *error-output*)
  (apply #'format *error-output* args)
  (fresh-line *error-output*))

(defun mappend (function &rest lists)
  (loop for results in (apply #'mapcar function lists)
        append results))

(defun items-upto (list x)
  (subseq list 0 (position x list)))

(defun topological-sort (objects constraints tie-breaker)
  (declare (list objects constraints)
           (function tie-breaker))
  (let ((obj-info (make-hash-table :size (length objects)))
        (free-objs nil)
        (result nil))
    (dolist (constraint constraints)
      (let ((obj1 (car constraint))
            (obj2 (cdr constraint)))
        (let ((info2 (gethash obj2 obj-info)))
          (if info2
              (incf (first info2))
              (setf (gethash obj2 obj-info) (list 1))))
        (let ((info1 (gethash obj1 obj-info)))
          (if info1
              (push obj2 (rest info1))
              (setf (gethash obj1 obj-info) (list 0 obj2))))))
    (dolist (obj objects)
      (let ((info (gethash obj obj-info)))
        (when (or (not info) (zerop (first info)))
          (push obj free-objs))))
    (loop
      (flet ((next-result (obj)
               (push obj result)
               (dolist (successor (rest (gethash obj obj-info)))
                 (let* ((successor-info (gethash successor obj-info))
                        (count (1- (first successor-info))))
                   (setf (first successor-info) count)
                   (when (zerop count)
                     (push successor free-objs))))))
        (cond ((endp free-objs)
               (let ((n-table-874 obj-info))
                 (with-hash-table-iterator (gen872 n-table-874)
                   (loop
                     (multiple-value-bind (n-more-873 obj info)
                         (gen872)
                       (unless n-more-873 (return nil))
                       (unless (zerop (first info))
                         (error "Topological sort failed due to constraint on ~S." OBJ))))))
               (return (nreverse result)))
              ((endp (rest free-objs))
               (next-result (pop free-objs)))
              (t
               (let ((obj (funcall tie-breaker free-objs result)))
                 (setf free-objs (remove obj free-objs))
                 (next-result obj))))))))

(defun component-rules (component)
  (let ((components (asdf/component:module-components
                     (asdf/component:component-parent component))))
    (let ((dependencies
            (mapcar (lambda (name)
                      (find name components
                            :key #'asdf/component:component-name
                            :test #'equal))
                    (asdf/component:component-sideway-dependencies component))))
      (assert (every #'identity dependencies))
      (mapcar (lambda (dependency) (cons dependency component)) dependencies))))

(defun sort-components (components)
  (topological-sort
   components
   (mappend #'component-rules components)
   (lambda (a b) (declare (ignore b)) (first a))))

(defun asd-paths (args)
  (let ((pos
          (or (position "--" args :test #'equal)
              (error "-- not found"))))
    (mapcar #'parse-namestring (nthcdr (1+ pos) args))))

(defun populate-registry (asd-paths)
  (dolist (x asd-paths)
    (push (merge-pathnames (make-pathname :name nil :type nil :defaults x)) asdf:*central-registry*)))

(defun asd-paths-find-systems (asd-paths)
  (loop for x in asd-paths
        collect (asdf/system:find-system (pathname-name x) t)))

(defun filter-test-systems (systems)
  (remove-if
   (lambda (system)
     (search "test" (asdf/component:component-name system)))
   systems))

(defun system-lisp-files (system)
  (asdf/component:sub-components system :type 'asdf/lisp-action:cl-source-file))

(defun check-same-parent (components)
  (let ((parents
          (remove-duplicates (mapcar #'asdf/component:component-parent components))))
    (unless (eql 1 (length parents))
      (error "more than one parent: ~S" parents))))

(defun component-pathname (component)
  (let ((path (asdf/component:component-find-path component)))
    (make-pathname
     :name (asdf/component:component-name component)
     :type "lisp"
     :directory `(:relative ,@(butlast path)))))

(defun format-load-line (component)
  (format t "~C  -load ~A \\~%"
          #\tab
          (component-pathname component)))

(defun format-rule (target prerequisites recipe)
  (format t "~A: ~{~A~^ ~}~%" target prerequisites)
  (let ((*print-case* :downcase))
    (labels ((indent (&optional (level 0))
               (format t "~C~A" #\tab (make-string level :initial-element #\space)))
             (format-args (x)
               (format t "~{~A~^ ~}" x))
             (format-command (x)
               (indent)
               (format-args x)
               (terpri))
             (format-multiline (x)
               (loop for tail on x
                     for c = (car tail)
                     for level = 0 then 2
                     do (indent level)
                     do (format-args c)
                     when (cdr tail)
                       do (format t " \\")
                     do (terpri)))
             (format-exp (x)
               (if (consp (car x))
                   (format-multiline x)
                   (format-command x))))
      (dolist (x recipe)
        (format-exp x)))))

(defun o-pathname (pathname)
  (make-pathname :type "o" :defaults pathname))

#|

#(:file "io" :depends-on ("package" "macros" "lists" "types"))
alexandria/io.o: alexandria/io.lisp
rm -f alexandria/io.o
ecl -norc \
-load alexandria/package.lisp \
-load alexandria/definitions.lisp \
-load alexandria/binding.lisp \
-load alexandria/strings.lisp \
-load alexandria/conditions.lisp \
-load alexandria/hash-tables.lisp \
-load alexandria/symbols.lisp \
-load alexandria/macros.lisp \
-load alexandria/control-flow.lisp \
-load alexandria/features.lisp \
-load alexandria/functions.lisp \
-load alexandria/lists.lisp \
-load alexandria/types.lisp \
-s -compile alexandria/io.lisp
test -f alexandria/io.o
|#


#|

foo/foo.fas: foo/package.o foo/a.o foo/b.o
ecl -norc \
-eval "(require 'cmp)" \
-eval "(defvar *lisp-files* nil)" \
-eval '(push "foo/package.o" *lisp-files*)' \
-eval '(push "foo/a.o" *lisp-files*)' \
-eval '(push "foo/b.o" *lisp-files*)' \
-eval '(setq *lisp-files* (nreverse *lisp-files*))' \
-eval '(c:build-fasl "foo/foo.fas" :lisp-files *lisp-files*)' \
-eval '(quit)'

foo/libfoo.a: foo/package.o foo/a.o foo/b.o
ecl -norc \
-eval "(require 'cmp)" \
-eval "(defvar *lisp-files* nil)" \
-eval '(push "foo/package.o" *lisp-files*)' \
-eval '(push "foo/a.o" *lisp-files*)' \
-eval '(push "foo/b.o" *lisp-files*)' \
-eval '(setq *lisp-files* (nreverse *lisp-files*))' \
-eval '(c:build-static-library "foo/foo" :lisp-files *lisp-files*)' \
-eval '(quit)'


|#

(defun !rm-f (pathname)
  `(rm -f ,pathname))

(defun !test-f (pathname)
  `(test -f ,pathname))

(defun !ecl-s-compile (loads source)
  `((ecl -norc)
    ,@(mapcar (lambda (x) `(-load ,(component-pathname x))) loads)
    (-s -compile ,(component-pathname source))))

(defun %static-lib-rule (sorted-components)
  (let* ((system (asdf/component:component-system (first sorted-components)))
         (fas-pathname (make-pathname
                        :name (format nil "lib~A" (asdf/component:component-name system))
                        :type "a"
                        :defaults (enough-namestring (asdf/component:component-pathname system))))
         (inputs (mapcar #'o-pathname
                         (mapcar #'component-pathname sorted-components))))
    (format-rule fas-pathname
                 inputs
                 `(((ecl -norc)
                    (-eval "\"(require 'cmp)\"")
                    (-eval "\"(defvar *lisp-files* nil)\"")
                    ,@(mapcar
                       (lambda (o)
                         `(-eval ,(format nil "'(push ~S *lisp-files*)'" (namestring o))))
                       inputs)
                    (-eval "'(setq *lisp-files* (nreverse *lisp-files*))'")
                    (-eval ,(format nil "'(c:build-static-library ~S :lisp-files *lisp-files*)'" (namestring fas-pathname)))
                    (-eval "'(quit)'"))))
    (terpri)))

(defun %fas-rule (sorted-components)
  (let* ((system (asdf/component:component-system (first sorted-components)))
         (fas-pathname (make-pathname
                        :name (asdf/component:component-name system)
                        :type "fas"
                        :defaults (enough-namestring (asdf/component:component-pathname system))))
         (inputs (mapcar #'o-pathname
                         (mapcar #'component-pathname sorted-components))))
    (format-rule fas-pathname
                 inputs
                 `(((ecl -norc)
                    (-eval "\"(require 'cmp)\"")
                    (-eval "\"(defvar *lisp-files* nil)\"")
                    ,@(mapcar
                       (lambda (o)
                         `(-eval ,(format nil "'(push ~S *lisp-files*)'" (namestring o))))
                       inputs)
                    (-eval "'(setq *lisp-files* (nreverse *lisp-files*))'")
                    (-eval ,(format nil "'(c:build-fasl ~S :lisp-files *lisp-files*)'" (namestring fas-pathname)))
                    (-eval "'(quit)'"))))
    (terpri)))

(defun %o-rule (component sorted-components)
  (let* ((pathname (component-pathname component))
         (o-pathname (o-pathname pathname))
         (loads (items-upto sorted-components component)))
    (format-rule o-pathname
                 (cons (component-pathname component)
                       (mapcar #'component-pathname loads))
                 `(,(!rm-f o-pathname)
                   ,(!ecl-s-compile loads component)
                   ,(!test-f o-pathname)))
    (terpri)))

(defun process-system (system)
  (let ((components (system-lisp-files system)))
    (check-same-parent components)
    (with-open-file (*standard-output*
                     (make-pathname
                      :name "make"
                      :type "mk"
                      :defaults (enough-namestring (asdf/component:component-pathname system)))
                     :direction :output
                     :if-exists :supersede)
      (let ((sorted-components (sort-components components)))
        (%static-lib-rule sorted-components)
        (%fas-rule sorted-components)
        (dolist (component sorted-components)
          (%o-rule component sorted-components))))))

(defun main ()
  (format* "~S~%" ext:*command-args*)
  (let ((asd-paths (asd-paths ext:*command-args*)))
    (format* "~S~%" asd-paths)
    (populate-registry asd-paths)
    (format* "~S~%" (filter-test-systems (asd-paths-find-systems asd-paths)))
    (let ((systems (filter-test-systems (asd-paths-find-systems asd-paths))))
      (dolist (system systems)
        (format* "processing ~A" system)
        (process-system system)))
    (quit)))
