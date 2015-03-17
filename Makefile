all: hello-lisp

install: all
	cp hello-lisp bin/asgl

clean:
	rm -f hello-lisp bin/asgl hello.o Foo.o hello.data hello.eclh hello.c
	rm -rf gecode

hello.o: gecode hello.lisp
#ecl -norc -eval '(compile-file "hello.lisp" :system-p t)' -eval '(quit)'
	rm -f hello.o
	ecl -norc -load lisp-scripts/compile-foo.lisp

hello-lisp: hello.o Foo.o
	ecl -norc -eval '(require "cmp")' -eval '(c:build-program "hello-lisp" :lisp-files (list "hello.o") :ld-flags (list "Foo.o" "-lgecodesearch" "-lgecodeint" "-lgecodekernel" "-lgecodesupport" "-lgecodegist") :epilogue-code '\''(cl-user::main))' -eval '(quit)'

gecode: gecode-patched-headers.tgz
	rm -rf gecode
	tar xfz gecode-patched-headers.tgz
	touch gecode

install-v1: install

install-ref:
	rm -f bin/asgl
	echo '#!/bin/bash' >> bin/asgl
	echo 'exec java -jar $$(dirname $$0)/libexec/tweetysolver-v1.1.1.jar $$*' >> bin/asgl
	chmod +x bin/asgl

test:
	bundle exec cucumber

test-v1: test

test-ref:
	bundle exec cucumber --tags ~@notref
