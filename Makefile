all: test-gr1

# ref
install-ref:
	rm -f bin/asgl
	echo '#!/bin/bash' >> bin/asgl
	echo 'exec java -jar $$(dirname $$0)/libexec/tweetysolver-v1.1.1.jar $$*' >> bin/asgl
	chmod +x bin/asgl

test-ref: install-ref data/iccma15_solutions data/iccma15_testcases
	bundle exec cucumber --tags ~@notref --tags ~@big ${CUKE_ARGS}


# v1
v1/v1.o: gecode v1/v1.lisp common/early/early.fas
	rm -f v1/v1.o
	ecl -norc \
	  -load common/early/early.fas \
	  -load lisp-scripts/compile-foo.lisp

v1/v1: v1/v1.o v1/Foo.o common/early/libearly.a
	ecl -norc -eval '(require "cmp")' -eval '(c:build-program "v1/v1" :lisp-files (list "common/early/libearly.a" "v1/v1.o") :ld-flags (list "common/early/libmyfoo.a" "v1/Foo.o" "-lgecodesearch" "-lgecodeint" "-lgecodekernel" "-lgecodesupport" "-lgecodegist") :epilogue-code '\''(cl-user::main))' -eval '(quit)'

install-v1: v1/v1
	cp v1/v1 bin/asgl

test-v1: install-v1 data/iccma15_solutions data/iccma15_testcases
	bundle exec cucumber --tags ~@big ${CUKE_ARGS}

# gr1
gr1/gr1.o: gecode gr1/gr1.lisp common/early/early.fas
	rm -f gr1/gr1.o
	ecl -norc \
	  -load common/early/early.fas \
	  -load lisp-scripts/compile-gr1.lisp


common/early/myfoo.cpp: common/early/myfoo.rl
	ragel -G2 common/early/myfoo.rl -o common/early/myfoo.cpp

common/early/count_args.cpp: common/early/count_args.rl
	ragel -G2 common/early/count_args.rl -o common/early/count_args.cpp

common/early/libmyfoo.a: common/early/myfoo.o common/early/slurp.o common/early/count_args.o
	ar rcs common/early/libmyfoo.a common/early/myfoo.o common/early/slurp.o \
	  common/early/count_args.o

common/early/myfoo.o: common/early/myfoo.cpp common/early/myfoo.h
	g++ -O2 -Wall -fPIC -c common/early/myfoo.cpp -o common/early/myfoo.o

common/early/slurp.o: common/early/slurp.cpp common/early/myfoo.h
	g++ -O2 -Wall -fPIC -c common/early/slurp.cpp -o common/early/slurp.o

common/early/count_args.o: common/early/count_args.cpp common/early/myfoo.h
	g++ -O2 -Wall -fPIC -c common/early/count_args.cpp -o common/early/count_args.o



gr1/gr1: gr1/Sp.o gr1/gr1.o common/early/libearly.a common/early/libmyfoo.a
	ecl -norc -eval '(require "cmp")' -eval '(c:build-program "gr1/gr1" :lisp-files (list "common/early/libearly.a" "gr1/gr1.o") :ld-flags (list "common/early/libmyfoo.a" "gr1/Sp.o" "-lgecodesearch" "-lgecodeint" "-lgecodekernel" "-lgecodesupport" "-lgecodegist") :epilogue-code '\''(cl-user::main))' -eval '(quit)'

install-gr1: gr1/gr1
	cp gr1/gr1 bin/asgl

test-gr1: install-gr1 data/iccma15_solutions data/iccma15_testcases
	bundle exec cucumber --tags ~@co --tags ~@st --tags ~@pr --tags ~@big ${CUKE_ARGS}

# gecode
gecode: support/gecode-patched-headers.tgz
	rm -rf gecode
	tar xfz support/gecode-patched-headers.tgz
	touch gecode

data/iccma15_solutions: data/iccma15_solutions.tar.xz
	rm -rf data/iccma15_solutions
	tar xf data/iccma15_solutions.tar.xz
	touch data/iccma15_solutions

data/iccma15_testcases: data/iccma15_testcases.tar.xz
	rm -rf data/iccma15_testcases
	tar xf data/iccma15_testcases.tar.xz
	touch data/iccma15_testcases

# clean
clean: lib/arnesi-list-match/clean lib/alexandria/clean lib/myam/clean common/early/clean
	rm -f bin/asgl
	rm -f v1/v1 v1/v1.o v1/Foo.o v1/v1.data v1/v1.eclh v1/v1.c
	rm -f gr1/*.o gr1/gr1 gr1/gr1.c gr1/gr1.data gr1/gr1.eclh
	rm -rf gecode tmp
	rm -rf data/iccma15_solutions data/iccma15_testcases
	rm -f cover.data
	if [ -n "`git clean -nxd`" ]; then git clean -nxd; exit 1; fi

include common/early/make.mk
include lib/myam/make.mk
include lib/alexandria/make.mk
include lib/arnesi-list-match/make.mk
