#! /bin/sh
":"; exec emacs --no-site-file --script "$0" -- "$@" # -*-emacs-lisp-*-
(setq argv (cdr argv))

(defun cleanup-file (file)
  (message "Opening %s..." file)
  (find-file file)
  (setq indent-tabs-mode nil)
  (whitespace-cleanup)
  (save-buffer)
  (kill-buffer))

(dolist (arg argv)
  (cleanup-file arg))
