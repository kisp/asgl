;;; -*- Mode:Lisp; Syntax:ANSI-Common-Lisp; -*-

(in-package :asdf)

(defsystem :myam
  :author "Kilian Sprotte / Edward Marco Baringer"
  :version #.(with-open-file
                 (vers (merge-pathnames "version.lisp-expr" *load-truename*))
               (read vers))
  :properties ((:test-suite-name . :myam-test))
  :depends-on (:alexandria :arnesi-list-match)
  :components ((:static-file "myam.asd")
               (:module :src
                :components
                ((:file "utils" :depends-on ("packages"))
                 (:file "check" :depends-on ("utils"))
                 (:file "classes" :depends-on ("packages"))
                 (:file "explain"
                  :depends-on ("classes" "packages" "check"))
                 (:file "packages")
                 (:file "run"
                  :depends-on ("packages" "classes" "test"
                                          "suite" "check"))
                 (:file "suite"
                  :depends-on ("packages" "test" "classes"))
                 (:file "random" :depends-on ("packages" "check"))
                 (:file "test" :depends-on ("packages" "classes"))))))

(defsystem :myam-test
  :components
  ((:module :t
    :components
    ((:file "tests")
     (:file "more-tests" :depends-on ("tests")))))
  :depends-on (:myam))

(defmethod perform ((op asdf:test-op) (system (eql (find-system :myam))))
  (asdf:oos 'asdf:load-op :myam-test)
  (funcall (intern "RUN!" "MYAM") :myam-test))

(defmethod perform ((op asdf:test-op) (system (eql (find-system :myam-test))))
  (perform op (find-system :myam)))
