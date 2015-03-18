;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

(in-package :myam)

(export 'growl-explainer)

(defun growlnotify (title message)
  #-sbcl(asdf:run-shell-command "growlnotify -m '~A' '~A'" message title)
  #+sbcl(sb-ext:run-program "growlnotify" (list "-m" message title)
                            :wait nil :search t))

(defclass growl-explainer (explainer)
  ())

(defmethod explain ((explainer growl-explainer) results &optional stream recursive-depth)
  (multiple-value-bind (num-checks passed num-passed passed%
                                   skipped num-skipped skipped%
                                   failed num-failed failed%
                                   unknown num-unknown unknown%)
      (partition-results results)
    ;; (declare (ignore passed passed% skipped skipped% failed failed% unknown unknown%))
    (let ((title (if failed "We have failures" "All checks passed"))
          (message #+sfjdkls(format nil "Pass: ~5D ~3D %~%Skip: ~3D %~%Fail: ~3D %~%"
                                    num-passed passed% skipped% failed%)
                   (with-output-to-string (out)
                     (format out "Pass: ~8D   ( ~3D % )~%" num-passed passed%)
                     (format out "Skip: ~8D   ( ~3D % )~%" num-skipped skipped%)
                     (format out "Fail: ~8D   ( ~3D % )~%" num-failed failed%))))
      (growlnotify title message))))
