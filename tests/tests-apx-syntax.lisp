;; -*- paul-nice-on-save:nil -*-

;;; The syntax of apx, as the two Ragel grammars in common/early read it:
;;; count_args.rl counts the arguments, ragel_apx_parse.rl reads them and
;;; the attacks. Each case is a text and what READ-APX-FILE makes of it:
;;;
;;;   (:accept ARGS ATTACKS)  ARGS in the order of the vector, ATTACKS as
;;;                           (attacker attacked) pairs in any order
;;;   (:reject :count-args)   count_args refuses the text
;;;   (:reject :parse)        count_args accepts it, ragel_apx_parse not
;;;   (:reject :undeclared)   the syntax is apx, but an attack names an
;;;                           argument that no arg(...) declares
;;;   (:crash :count-mismatch) the vector of names overflows: what
;;;                           ragel_apx_parse found was sized by count_args
;;;                           (no case expects it since the parse sizes it)
;;;
;;; Change a grammar and run this suite first: an expectation that changes
;;; is a change of the language ASGL reads.
;;;
;;; In a case's text and names, <LF>, <CR> and <TAB> stand for newline,
;;; carriage return and tab, and the file holds exactly the text: no newline
;;; is added.

(in-package :tests)

(defsuite* :tests.apx-syntax :in :tests)

(defparameter *apx-text-tokens*
  (list (cons "<LF>" (string #\Newline))
        (cons "<CR>" (string (code-char 13)))
        (cons "<TAB>" (string #\Tab))))

(defun unescape-apx-text (text)
  (with-output-to-string (out)
    (loop with i = 0
          while (< i (length text))
          do (let ((token (find-if (lambda (token)
                                     (string= (car token) text
                                              :start2 i
                                              :end2 (min (length text)
                                                         (+ i (length (car token))))))
                                   *apx-text-tokens*)))
               (cond (token
                      (write-string (cdr token) out)
                      (incf i (length (car token))))
                     (t
                      (write-char (char text i) out)
                      (incf i)))))))

(defun write-apx-bytes (text pathname)
  "Write TEXT to PATHNAME byte for byte, whatever the external format."
  (with-open-file (out pathname
                       :direction :output
                       :if-exists :supersede
                       :element-type '(unsigned-byte 8))
    (loop for char across text
          do (write-byte (char-code char) out))))

(defun apx-syntax-verdict (text)
  "What READ-APX-FILE makes of TEXT, in the notation of the cases."
  (with-tmp-file (pathname "tmp-syntax.apx")
    (write-apx-bytes (unescape-apx-text text) pathname)
    (handler-case
        (multiple-value-bind (graph vector)
            (early::read-apx-file pathname)
          (list :accept
                (coerce vector 'list)
                (loop for attacked below (length graph)
                      append (loop for attacker in (aref graph attacked)
                                   collect (list (aref vector attacker)
                                                 (aref vector attacked))))))
      (apx-error ()
        (list :reject :undeclared))
      (type-error ()
        (list :crash :count-mismatch))
      (simple-error (condition)
        (let ((control (simple-condition-format-control condition)))
          (cond ((search "(count_args)" control)
                 (list :reject :count-args))
                ((search "(ragel_apx_parse)" control)
                 (list :reject :parse))
                (t
                 (list :error (princ-to-string condition)))))))))

(defun apx-verdict-equal (expected actual)
  (if (and (eq :accept (first expected))
           (eq :accept (first actual)))
      (and (equal (second expected) (second actual))
           (set-equal (third expected) (third actual) :test #'equal))
      (equal expected actual)))

(defun unescape-apx-name (name)
  "NAME with its tokens replaced; NIL, an empty slot, stays NIL."
  (if (stringp name)
      (unescape-apx-text name)
      name))

(defun unescape-apx-verdict (verdict)
  (if (eq :accept (first verdict))
      (list :accept
            (mapcar #'unescape-apx-name (second verdict))
            (mapcar (lambda (attack)
                      (mapcar #'unescape-apx-name attack))
                    (third verdict)))
      verdict))

(defmacro define-apx-syntax-cases (&body cases)
  `(progn
     ,@(loop for (name text expected) in cases
             collect `(deftest ,(intern (format nil "APX-SYNTAX.~A" name))
                        (let ((actual (apx-syntax-verdict ,text))
                              (expected (unescape-apx-verdict ',expected)))
                          (unless (apx-verdict-equal expected actual)
                            (format t "~&apx-syntax ~A: ~S~%  expected ~S~%  got      ~S~%"
                                    ',name ,text expected actual))
                          (is (apx-verdict-equal expected actual)))))))

;;; Accepted: statements, and the whitespace around them

(define-apx-syntax-cases
  (one-arg "arg(a)." (:accept ("a") ()))
  (one-arg-newline "arg(a).<LF>" (:accept ("a") ()))
  (two-args "arg(a).<LF>arg(b).<LF>" (:accept ("a" "b") ()))
  (attack "arg(a).<LF>arg(b).<LF>att(a,b).<LF>" (:accept ("a" "b") (("a" "b"))))
  (self-attack "arg(a).<LF>att(a,a).<LF>" (:accept ("a") (("a" "a"))))
  (mutual-attack "arg(a).<LF>arg(b).<LF>att(a,b).<LF>att(b,a).<LF>"
                 (:accept ("a" "b") (("a" "b") ("b" "a"))))
  (attack-first "att(a,b).<LF>arg(a).<LF>arg(b).<LF>" (:accept ("a" "b") (("a" "b"))))
  (leading-newlines "<LF><LF>arg(a).<LF>" (:accept ("a") ()))
  (trailing-newlines "arg(a).<LF><LF><LF>" (:accept ("a") ()))
  (leading-spaces " arg(a).<LF>" (:accept ("a") ()))
  (trailing-spaces "arg(a).  <LF>" (:accept ("a") ()))
  (blank-line-of-spaces "arg(a).<LF>   <LF>arg(b).<LF>" (:accept ("a" "b") ()))
  (one-line-with-spaces "arg(a). arg(b). att(a,b)."
                        (:accept ("a" "b") (("a" "b"))))
  (space-before-paren "arg (a).<LF>att (a,a).<LF>" (:accept ("a") (("a" "a"))))
  (space-before-dot "arg(a) .<LF>att(a,a) .<LF>" (:accept ("a") (("a" "a"))))
  (space-inside-arg "arg( a ).<LF>" (:accept ("a") ()))
  (space-around-comma "arg(a).<LF>arg(b).<LF>att( a , b).<LF>"
                      (:accept ("a" "b") (("a" "b"))))
  (name-digits "arg(1).<LF>arg(22).<LF>att(1,22).<LF>" (:accept ("1" "22") (("1" "22"))))
  (name-with-dot "arg(1.1).<LF>" (:accept ("1.1") ()))
  (name-quoted "arg('a').<LF>" (:accept ("'a'") ()))
  (name-punctuation "arg(!a).<LF>arg(b_2).<LF>arg($c).<LF>" (:accept ("!a" "b_2" "$c") ())))

;;; Statements need no separator; whitespace is space, tab, CR and LF,
;;; anywhere between the tokens. (Until this suite's second commit all of
;;; these were rejected: the grammar wanted space or newline between statements,
;;; knew no tab or CR, and no space before an attack's closing parenthesis.)

(define-apx-syntax-cases
  (one-line-without-spaces "arg(a).arg(b)." (:accept ("a" "b") ()))
  (one-line-attack-without-spaces "arg(a).arg(b).att(a,b)."
                                  (:accept ("a" "b") (("a" "b"))))
  (one-line-mixed "arg(a). arg(b).att(b,a). att(a,b)."
                  (:accept ("a" "b") (("b" "a") ("a" "b"))))
  (tab-between "arg(a).<TAB>arg(b).<LF>" (:accept ("a" "b") ()))
  (tab-in-front "<TAB>arg(a).<LF>" (:accept ("a") ()))
  (tab-inside "arg(<TAB>a<TAB>).<LF>att(<TAB>a<TAB>,<TAB>a<TAB>).<LF>"
              (:accept ("a") (("a" "a"))))
  (crlf "arg(a).<CR><LF>arg(b).<CR><LF>" (:accept ("a" "b") ()))
  (crlf-attack "arg(a).<CR><LF>arg(b).<CR><LF>att(a,b).<CR><LF>"
               (:accept ("a" "b") (("a" "b"))))
  (space-before-attack-close "arg(a).<LF>arg(b).<LF>att(a,b ).<LF>"
                             (:accept ("a" "b") (("a" "b"))))
  (newline-inside-statement "arg(<LF>a<LF>).<LF>" (:accept ("a") ())))

;;; A name holds no whitespace. (Before, VAL was [^), ]+: a tab became part
;;; of a name, and a newline made the end of a name ambiguous, so
;;; ragel_apx_parse found more names than count_args counted and crashed.)

(define-apx-syntax-cases
  (tab-in-name "arg(a<TAB>b).<LF>" (:reject :count-args))
  (newline-in-name "arg(a<LF>b).<LF>" (:reject :count-args))
  (cr-in-name "arg(a<CR>b).<LF>" (:reject :count-args)))

;;; Names declared twice are one argument; a name that only an attack
;;; mentions is refused. (Before, the vector of names was sized by the
;;; number of arg(...) statements: a duplicate left a NIL argument,
;;; [[a,NIL]], and an undeclared name overflowed it.)

(define-apx-syntax-cases
  (duplicate-arg "arg(a).<LF>arg(a).<LF>" (:accept ("a") ()))
  (duplicate-arg-with-attack "arg(a).<LF>arg(b).<LF>arg(a).<LF>att(b,a).<LF>"
                             (:accept ("a" "b") (("b" "a"))))
  (duplicate-attack "arg(a).<LF>arg(b).<LF>att(a,b).<LF>att(a,b).<LF>"
                    (:accept ("a" "b") (("a" "b") ("a" "b"))))
  (undeclared-in-attack "arg(a).<LF>att(a,b).<LF>" (:reject :undeclared))
  (undeclared-attacker "arg(b).<LF>att(a,b).<LF>" (:reject :undeclared))
  (only-attacks "att(a,b).<LF>" (:reject :undeclared)))

;;; Rejected: not apx

(define-apx-syntax-cases
  (empty "" (:reject :count-args))
  (only-whitespace "  <LF><LF>" (:reject :count-args))
  (only-dot "." (:reject :count-args))
  (missing-dot "arg(a)" (:reject :count-args))
  (missing-dot-between "arg(a) arg(b)." (:reject :count-args))
  (missing-close "arg(a.<LF>" (:reject :count-args))
  (missing-open "arga).<LF>" (:reject :count-args))
  (empty-name "arg().<LF>" (:reject :count-args))
  (arg-with-two-names "arg(a,b).<LF>" (:reject :count-args))
  (attack-with-one-name "att(a).<LF>" (:reject :count-args))
  (attack-with-three-names "att(a,b,c).<LF>" (:reject :count-args))
  (unknown-keyword "ar(a).<LF>" (:reject :count-args))
  (uppercase-keyword "ARG(a).<LF>" (:reject :count-args))
  (trailing-junk "arg(a).junk" (:reject :count-args))
  (trailing-junk-after-space "arg(a). junk" (:reject :count-args))
  (comment "% a comment<LF>arg(a).<LF>" (:reject :count-args))
  (nested-paren "arg(a(b)).<LF>" (:reject :count-args)))
