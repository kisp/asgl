all: foo hello-lisp

foo.o: foo.lisp
	rm -f foo.o
	ecl -norc -eval '(compile-file "foo.lisp" :system-p t)' -eval '(quit)'

foo: foo.o
	ecl -norc -eval '(require "cmp")' -eval '(c:build-program "foo" :lisp-files (list "foo.o") :epilogue-code '\''(cl-user::main))' -eval '(quit)'

install: all
	cp foo bin/foo
	cp hello-lisp bin/hello-lisp

clean:
	rm -f foo bin/foo foo.o
	rm -f hello-lisp bin/hello-lisp hello.o Foo.o hello.data hello.eclh hello.c

hello.o: hello.lisp
#ecl -norc -eval '(compile-file "hello.lisp" :system-p t)' -eval '(quit)'
	rm -f hello.o
	ecl -norc -load lisp-scripts/compile-foo.lisp

hello-lisp: hello.o Foo.o
	ecl -norc -eval '(require "cmp")' -eval '(c:build-program "hello-lisp" :lisp-files (list "hello.o") :ld-flags (list "Foo.o" "-lgecodesearch" "-lgecodeint" "-lgecodekernel" "-lgecodesupport" "-lgecodegist") :epilogue-code '\''(cl-user::main))' -eval '(quit)'