(in-package :asdf)

(defsystem :early
  :depends-on ()
  :components
  ((:file "package")
   (:file "utils" :depends-on ("package"))
   (:file "graph" :depends-on ("utils"))))
