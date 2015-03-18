lib/arnesi-list-match/libarnesi-list-match.a: arnesi-list-match/package.o arnesi-list-match/list-match.o
	ecl -norc \
	  -eval "(require 'cmp)" \
	  -eval "(defvar *lisp-files* nil)" \
	  -eval '(push "arnesi-list-match/package.o" *lisp-files*)' \
	  -eval '(push "arnesi-list-match/list-match.o" *lisp-files*)' \
	  -eval '(setq *lisp-files* (nreverse *lisp-files*))' \
	  -eval '(c:build-static-library "lib/arnesi-list-match/libarnesi-list-match.a" :lisp-files *lisp-files*)' \
	  -eval '(quit)'

lib/arnesi-list-match/arnesi-list-match.fas: arnesi-list-match/package.o arnesi-list-match/list-match.o
	ecl -norc \
	  -eval "(require 'cmp)" \
	  -eval "(defvar *lisp-files* nil)" \
	  -eval '(push "arnesi-list-match/package.o" *lisp-files*)' \
	  -eval '(push "arnesi-list-match/list-match.o" *lisp-files*)' \
	  -eval '(setq *lisp-files* (nreverse *lisp-files*))' \
	  -eval '(c:build-fasl "lib/arnesi-list-match/arnesi-list-match.fas" :lisp-files *lisp-files*)' \
	  -eval '(quit)'

arnesi-list-match/package.o: arnesi-list-match/package.lisp
	rm -f arnesi-list-match/package.o
	ecl -norc \
	  -s -compile arnesi-list-match/package.lisp
	test -f arnesi-list-match/package.o

arnesi-list-match/list-match.o: arnesi-list-match/list-match.lisp arnesi-list-match/package.lisp
	rm -f arnesi-list-match/list-match.o
	ecl -norc \
	  -load arnesi-list-match/package.lisp \
	  -s -compile arnesi-list-match/list-match.lisp
	test -f arnesi-list-match/list-match.o

