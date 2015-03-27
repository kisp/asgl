;; -*- paul-nice-on-save:nil -*-

(in-package :tests)

(defsuite* :tests.apx :in :tests)

(deftest apx.11
  (check-extensions
   "EE-CO" "[[],[a1],[a2]]"
   '("arg(a1)."
     "att(a1, a2)."
     "arg(a2)."
     "att(a2,a1).")))

(deftest apx.12
  (check-extensions
   "EE-GR" "[[]]"
   '("arg(a1)."
     "att(a1, a2)."
     "arg(a2)."
     "att(a2,a1).")))

(deftest apx.13
  (check-extensions
   "EE-ST" "[[a2],[a1]]"
   '("arg(a1)."
     "att(a1, a2)."
     "arg(a2)."
     "att(a2,a1).")))

(deftest apx.14
  (check-extensions
   "EE-CO" "[[a,b,d]]"
   '("arg(a)."
     "arg(b)."
     "arg(c)."
     "arg(d)."
     "att(a, c)."
     "att(b, c)."
     "att(c, d).")))

(deftest apx.15
  (check-extensions
   "EE-PR" "[[b,d],[b,c],[a,d],[a,c]]"
   '("arg(a)."
     "arg(b)."
     "arg(c)."
     "arg(d)."
     "att(a, b)."
     "att(b, a)."
     "att(c, d)."
     "att(d, c).")))

(deftest apx.16
  (check-extensions
   "EE-CO" "[[a,b,c,d,f]]"
   '("arg(a)."
     "arg(b)."
     "arg(c)."
     "arg(d)."
     "arg(e)."
     "arg(f)."
     "att(a, e)."
     "att(b, e)."
     "att(c, e)."
     "att(d, e)."
     "att(e, f).")))

(deftest apx.17
  (check-extensions
   "EE-ST" "[]"
   '("arg(a)."
     "att(a, a).")))
