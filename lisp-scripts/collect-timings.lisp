#!/usr/bin/sbcl --script

(defun benchmark-files ()
  (sort (directory "data/**/*.apx") #'string< :key #'file-namestring))

(defun run-benchmark (input-file problem &key (timeout "1s"))
  (let* ((start (get-internal-real-time))
         (process
          (sb-ext:run-program
           "timeout"
           (list timeout
                 "./bin/asgl" "-fo" "apx" "-f" (namestring input-file) "-p" (string problem))
           :search t
           :output nil)))
    (if (zerop (sb-ext:process-exit-code process))
        (- (get-internal-real-time) start)
        :timeout)))

(defun read-version (version)
  (let* ((first-dot (position #\. version))
         (second-dot (position #\. version :start (1+ first-dot))))
    (list (parse-integer version :start 0 :end first-dot)
          (parse-integer version :start (1+ first-dot) :end second-dot)
          (parse-integer version :start (1+ second-dot)))))

(defun timings-file-name (version timeout repeats)
  (merge-pathnames
   (make-pathname
    :name (format nil "timings-~A-r~A-~{~3,'0D~^-~}"
                  timeout repeats
                  (read-version version))
    :type "txt")
   "timings/"))

(defun format-dur (dur)
  (format nil "~2,'0D:~2,'0D:~2,'0D"
          (mod (truncate dur (* 60 60)) 60)
          (mod (truncate dur 60) 60)
          (mod dur 60)))

(defvar *start* (get-universal-time))
(format t ";start benchmarking~%")
(sb-int:format-universal-time t *start*)
(terpri)

(destructuring-bind (timeout version &optional (repeats "1"))
    (cdr sb-ext:*posix-argv*)
  (let ((repeats (parse-integer repeats)))
    (with-open-file (output (timings-file-name version timeout repeats)
                            :direction :output
                            :if-exists :error)
      (format output "    file problem time~%")
      (let ((count 0))
        (dolist (file (benchmark-files))
          (format t ";benchmarking ~A~%" file)
          ;; cache warmup
          (run-benchmark file "grounded" :timeout timeout)
          (dotimes (i repeats)
            (dolist (problem '(:ee-gr :se-gr
                               :ee-co :se-co
                               :ee-st :se-st
                               :ee-pr :se-pr))
              (let ((time (run-benchmark file problem :timeout timeout)))
                (format output "~D ~A ~A ~A~%"
                        (incf count)
                        (file-namestring file)
                        problem
                        (if (eql time :timeout) "NA" time))))))))))

(defvar *end* (get-universal-time))
(format t ";done benchmarking (~A)~%"
        (format-dur (- *end* *start*)))
(sb-int:format-universal-time t *end*)
(terpri)
