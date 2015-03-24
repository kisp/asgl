(in-package :asdf)

(defsystem :early
  :depends-on ()
  :components
  ((:file "package")
   (:file "asgl-config" :depends-on ("package"))
   (:file "utils" :depends-on ("package" "cover"))
   (:file "graph" :depends-on ("utils" "cover"))
   (:file "apx" :depends-on ("graph" "cover"))
   (:file "cover" :depends-on ())))
