(in-package :asdf)

(defsystem :arnesi-list-match
  :depends-on (:alexandria)
  :version "0.0.2"
  :serial t
  :components
  ((:file "package")
   (:file "list-match")))
