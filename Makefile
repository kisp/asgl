all: test-gr1

# ref
install-ref:
	rm -f bin/asgl
	echo '#!/bin/bash' >> bin/asgl
	echo 'exec java -jar $$(dirname $$0)/libexec/tweetysolver-v1.1.1.jar $$*' >> bin/asgl
	chmod +x bin/asgl

test-ref: install-ref
	bundle exec cucumber --tags ~@notref --tags ~@big


# v1
v1/v1.o: gecode v1/v1.lisp
	rm -f v1/v1.o
	ecl -norc -load lisp-scripts/compile-foo.lisp

v1/v1: v1/v1.o v1/Foo.o
	ecl -norc -eval '(require "cmp")' -eval '(c:build-program "v1/v1" :lisp-files (list "v1/v1.o") :ld-flags (list "v1/Foo.o" "-lgecodesearch" "-lgecodeint" "-lgecodekernel" "-lgecodesupport" "-lgecodegist") :epilogue-code '\''(cl-user::main))' -eval '(quit)'

install-v1: v1/v1
	cp v1/v1 bin/asgl

test-v1: install-v1
	bundle exec cucumber --tags ~@big

# gr1
gr1/gr1.o: gecode gr1/gr1.lisp
	rm -f gr1/gr1.o
	ecl -norc \
	  -load lisp-scripts/compile-gr1.lisp

gr1/gr1: gr1/Sp.o gr1/gr1.o
	ecl -norc -eval '(require "cmp")' -eval '(c:build-program "gr1/gr1" :lisp-files (list "gr1/gr1.o") :ld-flags (list "gr1/Sp.o" "-lgecodesearch" "-lgecodeint" "-lgecodekernel" "-lgecodesupport" "-lgecodegist") :epilogue-code '\''(cl-user::main))' -eval '(quit)'

install-gr1: gr1/gr1
	cp gr1/gr1 bin/asgl

test-gr1: install-gr1
	bundle exec cucumber --tags ~@co --tags ~@st --tags ~@pr

# gecode
gecode: support/gecode-patched-headers.tgz
	rm -rf gecode
	tar xfz support/gecode-patched-headers.tgz
	touch gecode

# clean
clean: lib/arnesi-list-match/clean lib/alexandria/clean lib/myam/clean
	rm -f bin/asgl
	rm -f v1/v1 v1/v1.o v1/Foo.o v1/v1.data v1/v1.eclh v1/v1.c
	rm -f gr1/*.o gr1/gr1 gr1/gr1.c gr1/gr1.data gr1/gr1.eclh
	rm -rf gecode tmp
	[ -z "`git clean -nxd`" ]

%/alexandria/make.mk %/arnesi-list-match/make.mk %/myam/make.mk:
	ecl -norc -load support/asdf.lisp -load lisp-scripts/deps.lisp -eval '(main)' -- lib/*/*.asd

include lib/myam/make.mk
include lib/alexandria/make.mk
include lib/arnesi-list-match/make.mk
