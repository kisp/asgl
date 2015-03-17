all: test-gr1

# ref
install-ref:
	rm -f bin/asgl
	echo '#!/bin/bash' >> bin/asgl
	echo 'exec java -jar $$(dirname $$0)/libexec/tweetysolver-v1.1.1.jar $$*' >> bin/asgl
	chmod +x bin/asgl

test-ref:
	bundle exec cucumber --tags ~@notref


# v1
hello.o: gecode hello.lisp
	rm -f hello.o
	ecl -norc -load lisp-scripts/compile-foo.lisp

hello-lisp: hello.o Foo.o
	ecl -norc -eval '(require "cmp")' -eval '(c:build-program "hello-lisp" :lisp-files (list "hello.o") :ld-flags (list "Foo.o" "-lgecodesearch" "-lgecodeint" "-lgecodekernel" "-lgecodesupport" "-lgecodegist") :epilogue-code '\''(cl-user::main))' -eval '(quit)'

install-v1: hello-lisp
	cp hello-lisp bin/asgl

test-v1:
	bundle exec cucumber

# gr1
gr1/gr1.o: gecode gr1/gr1.lisp
	rm -f gr1/gr1.o
	ecl -norc -load lisp-scripts/compile-gr1.lisp

gr1/gr1: gr1/Sp.o gr1/gr1.o
	ecl -norc -eval '(require "cmp")' -eval '(c:build-program "gr1/gr1" :lisp-files (list "gr1/gr1.o") :ld-flags (list "gr1/Sp.o" "-lgecodesearch" "-lgecodeint" "-lgecodekernel" "-lgecodesupport" "-lgecodegist") :epilogue-code '\''(cl-user::main))' -eval '(quit)'

install-gr1: gr1/gr1
	cp gr1/gr1 bin/asgl

test-gr1: install-gr1
	bundle exec cucumber

# gecode
gecode: gecode-patched-headers.tgz
	rm -rf gecode
	tar xfz gecode-patched-headers.tgz
	touch gecode

# clean
clean:
	rm -f hello-lisp bin/asgl hello.o Foo.o hello.data hello.eclh hello.c
	rm -f gr1/*.o gr1/gr1 gr1/gr1.c gr1/gr1.data gr1/gr1.eclh
	rm -rf gecode tmp
	[ -z "`git clean -nxd`" ]
