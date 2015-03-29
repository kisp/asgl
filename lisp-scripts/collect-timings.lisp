#!/usr/bin/sbcl --script

(defvar *start*)
(defvar *end*)
(defvar *count*)

(defstruct benchmark input-file problem)

(defun benchmark-files ()
  (sort (directory "data/**/*.apx") #'string< :key #'file-namestring))

(defun all-benchmarks ()
  (let (list)
    (dolist (file (benchmark-files))
      (dolist (problem '(:ee-gr :se-gr
                         :ee-co :se-co
                         :ee-st :se-st
                         :ee-pr :se-pr))
        (let ((benchmark (make-benchmark :input-file file :problem problem)))
          (push benchmark list))))
    (nreverse list)))

(defun benchmarks-from-list (benchmarks-list benchmarks-dir)
  (with-open-file (input benchmarks-list)
    (loop
      for line = (read-line input nil)
      while line
      collect
      (with-input-from-string (in line)
        (make-benchmark
         :problem (intern (read in) "KEYWORD")
         :input-file
         (let ((pathname (merge-pathnames (parse-namestring (read in))
                                          benchmarks-dir)))
           (or (probe-file pathname)
               (error "missing input file ~A" pathname))))))))

(defun run-benchmark (benchmark &key (timeout "1s"))
  (let* ((input-file (benchmark-input-file benchmark))
         (problem (benchmark-problem benchmark))
         (start (get-internal-real-time))
         (process
           (sb-ext:run-program
            "timeout"
            (list timeout
                  "./bin/asgl" "-fo" "apx" "-f"
                  (namestring input-file) "-p" (string problem))
            :search t
            :output nil)))
    (let ((end (get-internal-real-time))
          (exit-code (sb-ext:process-exit-code process)))
      (values (- end start)
              exit-code))))

(defun read-version (version)
  (let* ((first-dot (position #\. version))
         (second-dot (position #\. version :start (1+ first-dot))))
    (list (parse-integer version :start 0 :end first-dot)
          (parse-integer version :start (1+ first-dot) :end second-dot)
          (parse-integer version :start (1+ second-dot)))))

(defun timings-file-name (version timeout)
  (merge-pathnames
   (make-pathname
    :name (format nil "timings-~A-~{~3,'0D~^-~}"
                  timeout
                  (read-version version))
    :type "txt")
   "timings/"))

(defun format-dur (dur)
  (format nil "~2,'0D:~2,'0D:~2,'0D"
          (mod (truncate dur (* 60 60)) 60)
          (mod (truncate dur 60) 60)
          (mod dur 60)))


(defun echo-start-benchmarking ()
  (setq *start* (get-universal-time))
  (format t ";start benchmarking~%")
  (sb-int:format-universal-time t *start*)
  (terpri))

(defun echo-done-benchmarking ()
  (setq *end* (get-universal-time))
  (format t ";done benchmarking (~A)~%"
          (format-dur (- *end* *start*)))
  (sb-int:format-universal-time t *end*)
  (terpri))

(defun echo-benchmarking-file (file)
  (format t ";benchmarking ~A~%" file))

(defun run-and-output-benchmark (benchmark timeout output)
  (echo-benchmarking-file (benchmark-input-file benchmark))
  ;; cache warmup
  (run-benchmark benchmark :timeout "0.4s")
  (multiple-value-bind (time exit-status)
      (run-benchmark benchmark :timeout timeout)
    (format output "~D ~A ~A ~A ~A~%"
            (incf *count*)
            (file-namestring (benchmark-input-file benchmark))
            (benchmark-problem benchmark)
            time
            exit-status)
    (finish-output output)))

(defun adopt-keywords (list)
  (mapcar (lambda (x)
            (if (char= #\- (char x 0))
                (intern (string-upcase (subseq x 1)) "KEYWORD")
                x))
          list))

(defun main ()
  (let ((args (cdr sb-ext:*posix-argv*)))
    (destructuring-bind #1=(&key help
                                 (timeout "10s")
                                 (version "0.0.0")
                                 (results-file (timings-file-name version timeout))
                                 overwrite-results
                                 benchmarks-list
                                 (benchmarks-dir "data/iccma15_testcases/"))
      (adopt-keywords args)
      (cond
        ((or (null args) help)
         (format t "Usage: collect-timings ~S~%" '#1#)
         (sb-ext:exit :code 1))
        (t
         (echo-start-benchmarking)
         (with-open-file (output results-file
                                 :direction :output
                                 :if-exists (if overwrite-results
                                                :supersede
                                                :error))
           (format output "    file problem time exit-status~%")
           (let ((*count* 0))
             (dolist (benchmark (if benchmarks-list
                                    (benchmarks-from-list
                                     benchmarks-list
                                     (merge-pathnames benchmarks-dir))
                                    (all-benchmarks)))
               (run-and-output-benchmark benchmark timeout output))))
         (echo-done-benchmarking))))))

(main)
