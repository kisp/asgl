# -*- indent-tabs:t; dont-indent:t -*-

source-files = $(shell cat tools/source-files.txt)

all: test-v1

# ref
install-ref:
	rm -f bin/asgl
	cp support/ref-wrapper.sh bin/asgl
	chmod +x bin/asgl

test-ref: install-ref data/iccma15_solutions data/iccma15_testcases
	bundle exec cucumber --tags ~@notref --tags ~@big ${CUKE_ARGS}


# v1
v1/v1.o: gecode v1/v1.lisp common/asgl-config/asgl-config.fas common/early/early.fas \
	  lib/myam/myam.fas lib/alexandria/alexandria.fas lib/arnesi-list-match/arnesi-list-match.fas
	rm -f v1/v1.o
	ecl -norc \
	  -load common/asgl-config/asgl-config.fas \
	  -load common/early/early.fas \
	  -load lib/alexandria/alexandria.fas \
	  -load lib/arnesi-list-match/arnesi-list-match.fas \
	  -load lib/myam/myam.fas \
	  -load lisp-scripts/compile-foo.lisp

v1/v1: v1/v1.o v1/Foo.o common/early/libearly.a common/asgl-config/libasgl-config.a \
	  common/asgl-config/asgl-config.fas lib/myam/libmyam.a lib/alexandria/libalexandria.a \
	  lib/arnesi-list-match/libarnesi-list-match.a
	ecl -norc -eval '(require "cmp")' \
	  -load common/asgl-config/asgl-config.fas \
	  -eval '(c:build-program "v1/v1" :lisp-files (list "common/asgl-config/libasgl-config.a" "common/early/libearly.a" "lib/alexandria/libalexandria.a" "lib/arnesi-list-match/libarnesi-list-match.a" "lib/myam/libmyam.a" "v1/v1.o") :ld-flags (list "common/early/libmyfoo.a" "v1/Foo.o" "-lgecodesearch" "-lgecodeint" "-lgecodekernel" "-lgecodesupport" #+gist"-lgecodegist") :epilogue-code '\''(cl-user::main))' \
	  -eval '(quit)'

v1/Foo.o: v1/Foo.cpp v1/Foo.h asgl_config.h
	g++ -O2 -Wall -Werror -fPIC -c v1/Foo.cpp -o v1/Foo.o

install-v1: v1/v1
	cp v1/v1 bin/asgl

test-v1: install-v1 data/iccma15_solutions data/iccma15_testcases
	bundle exec cucumber ${CUKE_ARGS}

common/early/myfoo.cpp: common/early/myfoo.rl
	ragel -G2 common/early/myfoo.rl -o common/early/myfoo.cpp

common/early/count_args.cpp: common/early/count_args.rl
	ragel -G2 common/early/count_args.rl -o common/early/count_args.cpp

common/early/libmyfoo.a: common/early/myfoo.o common/early/slurp.o \
	  common/early/count_args.o
	ar rcs common/early/libmyfoo.a common/early/myfoo.o common/early/slurp.o \
	  common/early/count_args.o

common/early/myfoo.o: common/early/myfoo.cpp common/early/myfoo.h
	g++ -O2 -Wall -Werror -fPIC -c common/early/myfoo.cpp -o common/early/myfoo.o

common/early/slurp.o: common/early/slurp.cpp common/early/myfoo.h
	g++ -O2 -Wall -Werror -fPIC -c common/early/slurp.cpp -o common/early/slurp.o

common/early/count_args.o: common/early/count_args.cpp common/early/myfoo.h
	g++ -O2 -Wall -Werror -fPIC -c common/early/count_args.cpp -o common/early/count_args.o


# gecode
gecode: support/gecode-patched-headers.tgz
	rm -rf gecode
	tar xfz support/gecode-patched-headers.tgz
	touch gecode

data/iccma15_solutions: data/iccma15_testcases \
			data/iccma15_solutions.tar.xz \
			data/real-ee-gr-solutions \
			support/fixes.sh
	rm -rf data/iccma15_solutions
	tar xf data/iccma15_solutions.tar.xz
	bash support/fixes.sh
	touch data/iccma15_solutions

data/iccma15_testcases: data/iccma15_testcases.tar.xz
	rm -rf data/iccma15_testcases
	tar xf data/iccma15_testcases.tar.xz
	touch data/iccma15_testcases

data/real-ee-gr-solutions: data/real-ee-gr-solutions.tar.xz
	rm -rf data/real-ee-gr-solutions
	tar -C data -xf data/real-ee-gr-solutions.tar.xz
	touch data/real-ee-gr-solutions

# tags
TAGS: $(source-files)
	etags $(source-files)

# clean
clean: lib/arnesi-list-match/clean lib/alexandria/clean lib/myam/clean \
	  common/early/clean common/asgl-config/clean
	rm -f bin/asgl
	rm -f v1/v1 v1/v1.o v1/Foo.o v1/v1.data v1/v1.eclh v1/v1.c
	rm -rf gecode tmp
	rm -rf data/iccma15_solutions data/iccma15_testcases data/real-ee-gr-solutions
	rm -f cover.data
	rm -f TAGS
	rm -fr dist build bin/ragel
	rm -f common/asgl-config/asgl-config.c common/asgl-config/asgl-config.data \
	  common/asgl-config/asgl-config.eclh
	rm -f asgl_config.h config.log config.status configure
	rm -rf autom4te.cache
	if [ -n "`git clean -nxd`" ]; then git clean -nxd; exit 1; fi

# dist
.PHONY: dist
dist:
	make clean | tail
	mkdir -p dist/asgl
	git ls-files | xargs -I% install -D % dist/asgl/%
	rm -r dist/asgl/bin/libexec
	bash scripts/generate-make-mk.sh
	find -name make.mk | xargs -I% install -D % dist/asgl/%
	make common/early/myfoo.cpp
	make common/early/count_args.cpp
	ls -1 common/early/myfoo.cpp common/early/count_args.cpp | \
	  xargs -I% install -D % dist/asgl/%
	make bin/ragel
	make build
	ls -1 bin/ragel build | xargs -I% install -D % dist/asgl/%
	autoconf
	install configure dist/asgl/configure
	echo DIST PREPARED
#(cd dist/asgl && ./build )
	( cd dist && tar -cf asgl.tar.gz asgl/* )
	du -h dist/asgl.tar.gz

bin/ragel:
	echo '#!/bin/sh' >>bin/ragel
	echo 'echo Ragel SHOULD NOT BE CALLED' >>bin/ragel
	echo 'echo Ragel files were pre-compiled for the dist,' >>bin/ragel
	echo 'echo so Ragel should not be needed.' >>bin/ragel
	echo 'exit 1' >>bin/ragel
	chmod +x bin/ragel

build:
	echo '#!/bin/bash' >>build
	echo 'set -e' >>build
	echo 'echo WILL START BUILD...' >>build
	echo 'export ASGL_HOME_PREC=`pwd`' >>build
	echo 'export PATH=`pwd`/bin:$$PATH' >>build
	echo './configure' >>build
	echo 'make install-v1' >>build
	echo 'make check' >>build
	echo 'echo BUILD FINISHED SUCCESSFULLY!' >>build
	echo 'echo You can start the solver with ./bin/asgl' >>build
	chmod +x build

check:
	timeout 5s ./bin/asgl
	timeout 10s ./bin/asgl --check

common/asgl-config/asgl-config.o: asgl_config.h

include common/asgl-config/make.mk
include common/early/make.mk
include lib/myam/make.mk
include lib/alexandria/make.mk
include lib/arnesi-list-match/make.mk
