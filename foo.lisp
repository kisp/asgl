(defun lines ()
  (with-open-file (input (second ext:*command-args*))
    (loop for line = (read-line input nil)
          while line
          collect line)))

(defun main ()
  ;; (format *error-output* "received: ~S~%" ext:*command-args*)
  (format t "~A~%" (length (lines))))
