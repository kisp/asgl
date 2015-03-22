#! /bin/sh
":"; exec emacs --no-site-file --script "$0" -- "$@" # -*-emacs-lisp-*-
(setq argv (cdr argv))

(load "~/.emacs")

;; (setq debug-on-error t)

(defvar dont-indent nil)

(setq find-file-hook (remove 'vc-find-file-hook find-file-hook))

(defun cleanup-file (file)
  (message "Opening %s..." file)
  (find-file file)
  (unless (member major-mode '(diff-mode))
    (unless dont-indent
      (indent-region (point-min) (point-max) nil))
    (whitespace-cleanup)
    (save-buffer))
  (kill-buffer))

(custom-set-default 'indent-tabs-mode nil)

(dolist (arg argv)
  (cleanup-file arg))
