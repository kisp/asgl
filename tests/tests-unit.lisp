;; -*- paul-nice-on-save:nil -*-

(in-package :tests)

(defsuite* :tests.unit :in :tests)

(deftest read-graph-input.1
  (multiple-value-bind (graph vector hash)
      (read-graph-input #())
    (is (equalp #() graph))
    (is (equalp #() vector))
    (is (set-equal '() (hash-table-alist hash)))))

(deftest read-graph-input.2
  (multiple-value-bind (graph vector hash)
      (read-graph-input #(()))
    (is (equalp #(nil) graph))
    (is (equalp #(0) vector))
    (is (alist-eql '((0 . 0)) (hash-table-alist hash)))))

(deftest read-graph-input.3
  (multiple-value-bind (graph vector hash)
      (read-graph-input #((0)))
    (is (equalp #((0)) graph))
    (is (equalp #(0) vector))
    (is (alist-eql '((0 . 0)) (hash-table-alist hash)))))

(deftest read-graph-input.4
  (multiple-value-bind (graph vector hash)
      (read-graph-input #((1) (0)))
    (is (equalp #((1) (0)) graph))
    (is (equalp #(0 1) vector))
    (is (alist-eql '((0 . 0) (1 . 1)) (hash-table-alist hash)))))

(deftest read-graph-input.5
  (with-tmp-file-of-lines
      (pathname
       (list "arg(foo)."))
    (multiple-value-bind (graph vector hash)
        (read-graph-input pathname)
      (is (equalp #(()) graph))
      (is (equalp #("foo") vector))
      (is (alist-eql '(("foo" . 0)) (hash-table-alist hash))))))

(deftest read-graph-input.6
  (with-tmp-file-of-lines
      (pathname
       (list "arg(foo)."
             "arg(bar)."))
    (multiple-value-bind (graph vector hash)
        (read-graph-input pathname)
      (is (equalp #(() ()) graph))
      (is (equalp #("foo" "bar") vector))
      (is (alist-eql '(("foo" . 0) ("bar" . 1)) (hash-table-alist hash))))))

(deftest read-graph-input.7
  (with-tmp-file-of-lines
      (pathname
       (list "arg(foo)."
             "arg(bar)."
             "att(bar, foo)."))
    (multiple-value-bind (graph vector hash)
        (read-graph-input pathname)
      (is (equalp #((1) ()) graph))
      (is (equalp #("foo" "bar") vector))
      (is (alist-eql '(("foo" . 0) ("bar" . 1)) (hash-table-alist hash))))))

(deftest read-graph-input.8
  (with-tmp-file-of-lines
      (pathname
       (list "arg(foo)."
             "arg(bar)."
             "att(foo, bar)."))
    (multiple-value-bind (graph vector hash)
        (read-graph-input pathname)
      (is (equalp #(() (0)) graph))
      (is (equalp #("foo" "bar") vector))
      (is (alist-eql '(("foo" . 0) ("bar" . 1)) (hash-table-alist hash))))))

(deftest read-graph-input.9
  (with-tmp-file-of-lines
      (pathname
       (list "foo"))
    (signals error (read-graph-input pathname))))
