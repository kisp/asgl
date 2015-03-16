all: foo

foo.o: foo.lisp
	rm -f foo.o
	ecl -norc -eval '(compile-file "foo.lisp" :system-p t)' -eval '(quit)'

foo: foo.o
	ecl -norc -eval '(require "cmp")' -eval '(c:build-program "foo" :lisp-files (list "foo.o") :epilogue-code '\''(cl-user::main))' -eval '(quit)'

install: all
	cp foo bin/foo

clean:
	rm -f foo bin/foo foo.o
