;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

(cl:defpackage :myam-clim
  (:use :clim :clim-lisp :myam)
  (:export #:myam))

(cl:in-package :myam-clim)

(defun shorten-string (string)
  (if (> (length string) 16)
      (concatenate 'string (subseq string 0 7)
                   ".."
                   (subseq string (- (length string) 7)))
      string))

(define-command-table myam-cmds)

(eval-when (:compile-toplevel :load-toplevel :execute)
  (define-presentation-type entry () :inherit-from 'expression)
  (define-presentation-type run-entry () :inherit-from 'entry)
  (define-presentation-type successful-entry () :inherit-from 'run-entry)
  (define-presentation-type failed-entry () :inherit-from 'run-entry)
  (define-presentation-type skiped-entry () :inherit-from 'run-entry)
  (define-presentation-type descriptive-entry () :inherit-from 'run-entry))

;;; presentation methods

;;; entry
(define-presentation-method accept ((type entry) stream (view textual-view) &key)
  (let ((entry (accept 'expression
                       :stream stream
                       :view view
                       :history 'generic-function
                       :prompt nil)))
    (if (get-test entry)
        entry
        (simple-parse-error "~S is not the name of a test entry." entry))))

(define-presentation-method presentation-typep (object (type entry))
  (get-test object))

(define-presentation-method present (entry (type entry)
                                           stream (view textual-view)
                                           &key &allow-other-keys)
  (write-string (shorten-string (symbol-name entry)) stream)
  (terpri stream))

;;; run-entry
(define-presentation-method present (entry (type run-entry)
                                           stream (view textual-view)
                                           &key &allow-other-keys)
  (let ((results (run entry)))
    (cond ((some #'test-failure-p results)
           (present entry 'failed-entry :stream stream :view view))
          ((some #'test-skipped-p results)
           (present entry 'skiped-entry :stream stream :view view))
          (t
           (present entry 'successful-entry :stream stream :view view)))
    (setf (tests-failed *application-frame*)
          (or (tests-failed *application-frame*)
              (some #'test-failure-p results)))))

;;; successful-entry
(define-presentation-method present (entry (type successful-entry)
                                           stream (view textual-view)
                                           &key &allow-other-keys)
  (present entry 'entry :stream stream :view view))

;;; failed-entry
(define-presentation-method present (entry (type failed-entry)
                                           stream (view textual-view)
                                           &key &allow-other-keys)
  (with-drawing-options (stream :ink +red+)
    (present entry 'entry :stream stream :view view)))

;;; skiped-entry
(define-presentation-method present (entry (type skiped-entry)
                                           stream (view textual-view)
                                           &key &allow-other-keys)
  (with-drawing-options (stream :ink +grey80+)
    (present entry 'entry :stream stream :view view)))

;;; descriptive-entry
(define-presentation-method present (entry (type descriptive-entry)
                                           stream (view textual-view)
                                           &key &allow-other-keys)
  (invoke-load-op *application-frame*)
  (let ((*test-dribble* stream))
    (run! entry)))

;;; commands & translators
(define-command (com-show-test-result :name "Show Test Result"
                                      :command-table myam-cmds
                                      :provide-output-destination-keyword nil)
    ((test 'entry :prompt "Test"))
  (setf (displaying-result *application-frame*) test)
  (setf (pane-needs-redisplay (get-frame-pane *application-frame* 'test-details))
        t))

(define-presentation-to-command-translator show-test-result-translator
    (entry com-show-test-result myam-cmds :gesture :select)
  (object)
  (list object))

(define-command (com-run-tests :name "Run All Tests"
                               :command-table myam-cmds
                               :menu t)
    ()
  (setf (tests-failed *application-frame*) nil)
  (setf (pane-needs-redisplay (get-frame-pane *application-frame* 'test-results)) t)
  (setf (pane-needs-redisplay (get-frame-pane *application-frame* 'bar)) t))

(define-command (com-exit :name "Exit"
                          :command-table myam-cmds)
    ()
  (frame-exit *application-frame*))

;;; app frame

(define-application-frame myam ()
  ((tests-failed      :accessor tests-failed      :initform nil)
   (displaying-result :accessor displaying-result :initform nil)
   (system            :accessor autoload-system   :initform nil))
  (:panes (system       :text-field :width '(18 :character)
                        :id 'system)
          (start-button :push-button :label ">" :id 'start)
          (exit-button :push-button :label "X" :id 'exit)
          (bar          :application
                        :display-function #'display-bar
                        :scroll-bars nil)
          (test-details :application
                        :display-function #'show-test
                        :display-time nil
                        :scroll-bars t)
          (test-results :application
                        :display-function #'run-all-tests
                        :display-time nil
                        :scroll-bars t)
          (doc :pointer-documentation))
  (:command-table (myam :inherit-from (myam-cmds)))
  (:layouts (default
                (vertically ()
                            (horizontally ()
                                          system
                                          +fill+
                                          start-button
                                          exit-button))
                (20 bar)
              (+fill+ (horizontally ()
                                    test-results
                                    test-details))
              doc)))

;;; app frame redisplay functions
(defun run-all-tests (frame stream)
  (declare (ignore frame))
  (invoke-load-op *application-frame*)
  (format-items (sort
                 (delete-if-not (lambda (obj) (typep obj 'myam::test-case))
                                (test-names)
                                :key #'get-test)
                 #'string<
                 :key #'symbol-name)
                :stream stream :presentation-type 'run-entry)
  (force-output stream))

(defun show-test (frame stream)
  (declare (ignore frame))
  (when (displaying-result *application-frame*)
    (present (displaying-result *application-frame*)
             'descriptive-entry :stream stream))
  (force-output stream))

(defun display-bar (frame stream)
  (if (tests-failed frame)
      (setf (medium-background stream) +red+)
      (setf (medium-background stream) +green+))
  (window-clear stream))

(defmethod activate-callback ((button push-button) (client myam) (gadget-id (eql 'start)))
  (com-run-tests)
  (redisplay-frame-panes client))

(defmethod activate-callback ((button push-button) (client myam) (gadget-id (eql 'exit)))
  (com-exit))

(defmethod activate-callback (text-field (client myam) (gadget-id (eql 'system)))
  (setf (autoload-system *application-frame*)
        (asdf:find-system (gadget-value text-field) nil))
  (setf (gadget-value text-field)
        (if (autoload-system *application-frame*)
            (asdf:component-name (autoload-system *application-frame*))
            "")))

(defun invoke-load-op (frame)
  (when (autoload-system frame)
    (asdf:oos 'asdf:load-op (autoload-system frame))))

(defun myam (&key new-process)
  (flet ((run ()
           (run-frame-top-level (make-application-frame 'myam))))
    (if new-process
        (sb-thread:make-thread #'run :name "myam-clim")
        (run))))
