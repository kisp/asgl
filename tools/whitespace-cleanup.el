#! /bin/sh
":"; exec emacs --no-site-file --script "$0" -- "$@" # -*-emacs-lisp-*-
(setq argv (cdr argv))

(defun cleanup-file (file)
  (message "Opening %s..." file)
  (find-file file)
  (whitespace-cleanup)
  (save-buffer)
  (kill-buffer))

(custom-set-default 'indent-tabs-mode nil)

(dolist (arg argv)
  (cleanup-file arg))
