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

(DEFTEST READ-GRAPH-INPUT.CONS.1
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(1 . 1))
      (IS (EQUALP #((0)) GRAPH))
      (IS (EQUALP #(0) VECTOR))
      (IS (ALIST-EQL '((0 . 0)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.2
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(1 . 0))
      (IS (EQUALP #(NIL) GRAPH))
      (IS (EQUALP #(0) VECTOR))
      (IS (ALIST-EQL '((0 . 0)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.3
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(2 . 15))
      (IS (EQUALP #((1 0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.4
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(2 . 13))
      (IS (EQUALP #((0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.5
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(2 . 9))
      (IS (EQUALP #((0) (1)) GRAPH))
      (IS (EQUALP #(0 1) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.6
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(2 . 14))
      (IS (EQUALP #((1 0) (0)) GRAPH))
      (IS (EQUALP #(0 1) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.7
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(2 . 6))
      (IS (EQUALP #((1) (0)) GRAPH))
      (IS (EQUALP #(0 1) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.8
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(2 . 10))
      (IS (EQUALP #((1 0) NIL) GRAPH))
      (IS (EQUALP #(0 1) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.9
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(2 . 12))
      (IS (EQUALP #((0) (0)) GRAPH))
      (IS (EQUALP #(0 1) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.10
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(2 . 4))
      (IS (EQUALP #(NIL (0)) GRAPH))
      (IS (EQUALP #(0 1) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.11
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(2 . 8))
      (IS (EQUALP #((0) NIL) GRAPH))
      (IS (EQUALP #(0 1) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.12
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(2 . 0))
      (IS (EQUALP #(NIL NIL) GRAPH))
      (IS (EQUALP #(0 1) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.13
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 511))
      (IS (EQUALP #((2 1 0) (2 1 0) (2 1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.14
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 509))
      (IS (EQUALP #((2 1 0) (1 0) (2 1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.15
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 475))
      (IS (EQUALP #((0) (2 1 0) (2 1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.16
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 499))
      (IS (EQUALP #((1 0) (2 1 0) (2 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.17
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 413))
      (IS (EQUALP #((2 0) (1 0) (2 1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.18
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 501))
      (IS (EQUALP #((2 1 0) (1 0) (2 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.19
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 437))
      (IS (EQUALP #((2 1 0) (1 0) (2)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.20
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 505))
      (IS (EQUALP #((1 0) (1 0) (2 1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.21
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 473))
      (IS (EQUALP #((0) (1 0) (2 1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.22
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 403))
      (IS (EQUALP #((0) (2 1 0) (2)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.23
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 497))
      (IS (EQUALP #((1 0) (1 0) (2 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.24
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 409))
      (IS (EQUALP #((0) (1 0) (2 1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.25
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 433))
      (IS (EQUALP #((1 0) (1 0) (2)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.26
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 465))
      (IS (EQUALP #((0) (1 0) (2 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.27
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 401))
      (IS (EQUALP #((0) (1 0) (2)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.28
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 273))
      (IS (EQUALP #((0) (1) (2)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.29
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 510))
      (IS (EQUALP #((2 1 0) (2 1 0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.30
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 491))
      (IS (EQUALP #((1 0) (2 0) (2 1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.31
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 427))
      (IS (EQUALP #((1 0) (2 0) (2 1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.32
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 494))
      (IS (EQUALP #((2 1 0) (2 0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.33
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 238))
      (IS (EQUALP #((2 1) (2 0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.34
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 502))
      (IS (EQUALP #((2 1 0) (2 1 0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.35
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 430))
      (IS (EQUALP #((2 1 0) (2 0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.36
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 429))
      (IS (EQUALP #((2 1 0) (0) (2 1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.37
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 438))
      (IS (EQUALP #((2 1 0) (2 1 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.38
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 489))
      (IS (EQUALP #((1 0) (0) (2 1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.39
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 302))
      (IS (EQUALP #((2 1 0) (2) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.40
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 425))
      (IS (EQUALP #((1 0) (0) (2 1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.41
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 406))
      (IS (EQUALP #((2 0) (2 1 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.42
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 297))
      (IS (EQUALP #((1 0) NIL (2 1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.43
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 508))
      (IS (EQUALP #((2 1 0) (1 0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.44
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 490))
      (IS (EQUALP #((1 0) (2 0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.45
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 474))
      (IS (EQUALP #((0) (2 1 0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.46
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 458))
      (IS (EQUALP #((0) (2 0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.47
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 498))
      (IS (EQUALP #((1 0) (2 1 0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.48
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 466))
      (IS (EQUALP #((0) (2 1 0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.49
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 483))
      (IS (EQUALP #((1 0) (2 0) (2 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.50
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 398))
      (IS (EQUALP #((2 0) (2 0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.51
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 419))
      (IS (EQUALP #((1 0) (2 0) (2)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.52
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 412))
      (IS (EQUALP #((2 0) (1 0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.53
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 393))
      (IS (EQUALP #((0) (0) (2 1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.54
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 492))
      (IS (EQUALP #((2 1 0) (0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.55
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 236))
      (IS (EQUALP #((2 1) (0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.56
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 422))
      (IS (EQUALP #((2 1 0) (2 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.57
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 202))
      (IS (EQUALP #(NIL (2 0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.58
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 428))
      (IS (EQUALP #((2 1 0) (0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.59
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 300))
      (IS (EQUALP #((2 1 0) NIL (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.60
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 482))
      (IS (EQUALP #((1 0) (2 0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.61
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 226))
      (IS (EQUALP #((1) (2 0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.62
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 396))
      (IS (EQUALP #((2 0) (0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.63
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 140))
      (IS (EQUALP #((2) (0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.64
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 500))
      (IS (EQUALP #((2 1 0) (1 0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.65
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 426))
      (IS (EQUALP #((1 0) (2 0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.66
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 421))
      (IS (EQUALP #((2 1 0) (0) (2)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.67
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 394))
      (IS (EQUALP #((0) (2 0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.68
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 436))
      (IS (EQUALP #((2 1 0) (1 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.69
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 418))
      (IS (EQUALP #((1 0) (2 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.70
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 402))
      (IS (EQUALP #((0) (2 1 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.71
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 481))
      (IS (EQUALP #((1 0) (0) (2 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.72
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 298))
      (IS (EQUALP #((1 0) (2) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.73
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 417))
      (IS (EQUALP #((1 0) (0) (2)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.74
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 266))
      (IS (EQUALP #((0) (2) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.75
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 404))
      (IS (EQUALP #((2 0) (1 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.76
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 290))
      (IS (EQUALP #((1 0) (2) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.77
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 289))
      (IS (EQUALP #((1 0) NIL (2)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.78
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 484))
      (IS (EQUALP #((2 1 0) (0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.79
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 228))
      (IS (EQUALP #((2 1) (0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.80
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 420))
      (IS (EQUALP #((2 1 0) (0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.81
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 164))
      (IS (EQUALP #((2 1) (0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.82
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 292))
      (IS (EQUALP #((2 1 0) NIL NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.83
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 504))
      (IS (EQUALP #((1 0) (1 0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.84
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 472))
      (IS (EQUALP #((0) (1 0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.85
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 387))
      (IS (EQUALP #((0) (2 0) (2)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.86
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 488))
      (IS (EQUALP #((1 0) (0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.87
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 232))
      (IS (EQUALP #((1) (0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.88
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 390))
      (IS (EQUALP #((2 0) (2 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.89
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 456))
      (IS (EQUALP #((0) (0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.90
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 200))
      (IS (EQUALP #(NIL (0) (1 0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.91
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 386))
      (IS (EQUALP #((0) (2 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.92
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 130))
      (IS (EQUALP #(NIL (2 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.93
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 496))
      (IS (EQUALP #((1 0) (1 0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.94
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 424))
      (IS (EQUALP #((1 0) (0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.95
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 408))
      (IS (EQUALP #((0) (1 0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.96
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 392))
      (IS (EQUALP #((0) (0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.97
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 432))
      (IS (EQUALP #((1 0) (1 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.98
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 464))
      (IS (EQUALP #((0) (1 0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.99
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 296))
      (IS (EQUALP #((1 0) NIL (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.100
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 385))
      (IS (EQUALP #((0) (0) (2)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.101
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 264))
      (IS (EQUALP #((0) NIL (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.102
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 400))
      (IS (EQUALP #((0) (1 0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.103
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 272))
      (IS (EQUALP #((0) (1) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.104
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 480))
      (IS (EQUALP #((1 0) (0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.105
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 224))
      (IS (EQUALP #((1) (0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.106
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 388))
      (IS (EQUALP #((2 0) (0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.107
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 136))
      (IS (EQUALP #(NIL (0) (1)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.108
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 416))
      (IS (EQUALP #((1 0) (0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.109
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 160))
      (IS (EQUALP #((1) (0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.110
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 288))
      (IS (EQUALP #((1 0) NIL NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.111
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 448))
      (IS (EQUALP #((0) (0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.112
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 192))
      (IS (EQUALP #(NIL (0) (0)) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.113
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 384))
      (IS (EQUALP #((0) (0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.114
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 128))
      (IS (EQUALP #(NIL (0) NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.115
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 256))
      (IS (EQUALP #((0) NIL NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))

(DEFTEST READ-GRAPH-INPUT.CONS.116
    (MULTIPLE-VALUE-BIND (GRAPH VECTOR HASH)
        (READ-GRAPH-INPUT '(3 . 0))
      (IS (EQUALP #(NIL NIL NIL) GRAPH))
      (IS (EQUALP #(0 1 2) VECTOR))
      (IS (ALIST-EQL '((0 . 0) (1 . 1) (2 . 2)) (HASH-TABLE-ALIST HASH)))))
