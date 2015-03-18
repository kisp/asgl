lib/alexandria/libalexandria.a: alexandria/package.o alexandria/definitions.o alexandria/binding.o alexandria/strings.o alexandria/conditions.o alexandria/hash-tables.o alexandria/symbols.o alexandria/macros.o alexandria/control-flow.o alexandria/features.o alexandria/functions.o alexandria/lists.o alexandria/types.o alexandria/io.o alexandria/arrays.o alexandria/sequences.o alexandria/numbers.o
	ecl -norc \
	  -eval "(require 'cmp)" \
	  -eval "(defvar *lisp-files* nil)" \
	  -eval '(push "alexandria/package.o" *lisp-files*)' \
	  -eval '(push "alexandria/definitions.o" *lisp-files*)' \
	  -eval '(push "alexandria/binding.o" *lisp-files*)' \
	  -eval '(push "alexandria/strings.o" *lisp-files*)' \
	  -eval '(push "alexandria/conditions.o" *lisp-files*)' \
	  -eval '(push "alexandria/hash-tables.o" *lisp-files*)' \
	  -eval '(push "alexandria/symbols.o" *lisp-files*)' \
	  -eval '(push "alexandria/macros.o" *lisp-files*)' \
	  -eval '(push "alexandria/control-flow.o" *lisp-files*)' \
	  -eval '(push "alexandria/features.o" *lisp-files*)' \
	  -eval '(push "alexandria/functions.o" *lisp-files*)' \
	  -eval '(push "alexandria/lists.o" *lisp-files*)' \
	  -eval '(push "alexandria/types.o" *lisp-files*)' \
	  -eval '(push "alexandria/io.o" *lisp-files*)' \
	  -eval '(push "alexandria/arrays.o" *lisp-files*)' \
	  -eval '(push "alexandria/sequences.o" *lisp-files*)' \
	  -eval '(push "alexandria/numbers.o" *lisp-files*)' \
	  -eval '(setq *lisp-files* (nreverse *lisp-files*))' \
	  -eval '(c:build-static-library "lib/alexandria/libalexandria.a" :lisp-files *lisp-files*)' \
	  -eval '(quit)'

lib/alexandria/alexandria.fas: alexandria/package.o alexandria/definitions.o alexandria/binding.o alexandria/strings.o alexandria/conditions.o alexandria/hash-tables.o alexandria/symbols.o alexandria/macros.o alexandria/control-flow.o alexandria/features.o alexandria/functions.o alexandria/lists.o alexandria/types.o alexandria/io.o alexandria/arrays.o alexandria/sequences.o alexandria/numbers.o
	ecl -norc \
	  -eval "(require 'cmp)" \
	  -eval "(defvar *lisp-files* nil)" \
	  -eval '(push "alexandria/package.o" *lisp-files*)' \
	  -eval '(push "alexandria/definitions.o" *lisp-files*)' \
	  -eval '(push "alexandria/binding.o" *lisp-files*)' \
	  -eval '(push "alexandria/strings.o" *lisp-files*)' \
	  -eval '(push "alexandria/conditions.o" *lisp-files*)' \
	  -eval '(push "alexandria/hash-tables.o" *lisp-files*)' \
	  -eval '(push "alexandria/symbols.o" *lisp-files*)' \
	  -eval '(push "alexandria/macros.o" *lisp-files*)' \
	  -eval '(push "alexandria/control-flow.o" *lisp-files*)' \
	  -eval '(push "alexandria/features.o" *lisp-files*)' \
	  -eval '(push "alexandria/functions.o" *lisp-files*)' \
	  -eval '(push "alexandria/lists.o" *lisp-files*)' \
	  -eval '(push "alexandria/types.o" *lisp-files*)' \
	  -eval '(push "alexandria/io.o" *lisp-files*)' \
	  -eval '(push "alexandria/arrays.o" *lisp-files*)' \
	  -eval '(push "alexandria/sequences.o" *lisp-files*)' \
	  -eval '(push "alexandria/numbers.o" *lisp-files*)' \
	  -eval '(setq *lisp-files* (nreverse *lisp-files*))' \
	  -eval '(c:build-fasl "lib/alexandria/alexandria.fas" :lisp-files *lisp-files*)' \
	  -eval '(quit)'

alexandria/package.o: alexandria/package.lisp
	rm -f alexandria/package.o
	ecl -norc \
	  -s -compile alexandria/package.lisp
	test -f alexandria/package.o

alexandria/definitions.o: alexandria/definitions.lisp alexandria/package.lisp
	rm -f alexandria/definitions.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -s -compile alexandria/definitions.lisp
	test -f alexandria/definitions.o

alexandria/binding.o: alexandria/binding.lisp alexandria/package.lisp alexandria/definitions.lisp
	rm -f alexandria/binding.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -s -compile alexandria/binding.lisp
	test -f alexandria/binding.o

alexandria/strings.o: alexandria/strings.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp
	rm -f alexandria/strings.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -s -compile alexandria/strings.lisp
	test -f alexandria/strings.o

alexandria/conditions.o: alexandria/conditions.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp
	rm -f alexandria/conditions.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -s -compile alexandria/conditions.lisp
	test -f alexandria/conditions.o

alexandria/hash-tables.o: alexandria/hash-tables.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp
	rm -f alexandria/hash-tables.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -s -compile alexandria/hash-tables.lisp
	test -f alexandria/hash-tables.o

alexandria/symbols.o: alexandria/symbols.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp alexandria/hash-tables.lisp
	rm -f alexandria/symbols.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -load alexandria/hash-tables.lisp \
	  -s -compile alexandria/symbols.lisp
	test -f alexandria/symbols.o

alexandria/macros.o: alexandria/macros.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp alexandria/hash-tables.lisp alexandria/symbols.lisp
	rm -f alexandria/macros.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -load alexandria/hash-tables.lisp \
	  -load alexandria/symbols.lisp \
	  -s -compile alexandria/macros.lisp
	test -f alexandria/macros.o

alexandria/control-flow.o: alexandria/control-flow.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp alexandria/hash-tables.lisp alexandria/symbols.lisp alexandria/macros.lisp
	rm -f alexandria/control-flow.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -load alexandria/hash-tables.lisp \
	  -load alexandria/symbols.lisp \
	  -load alexandria/macros.lisp \
	  -s -compile alexandria/control-flow.lisp
	test -f alexandria/control-flow.o

alexandria/features.o: alexandria/features.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp alexandria/hash-tables.lisp alexandria/symbols.lisp alexandria/macros.lisp alexandria/control-flow.lisp
	rm -f alexandria/features.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -load alexandria/hash-tables.lisp \
	  -load alexandria/symbols.lisp \
	  -load alexandria/macros.lisp \
	  -load alexandria/control-flow.lisp \
	  -s -compile alexandria/features.lisp
	test -f alexandria/features.o

alexandria/functions.o: alexandria/functions.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp alexandria/hash-tables.lisp alexandria/symbols.lisp alexandria/macros.lisp alexandria/control-flow.lisp alexandria/features.lisp
	rm -f alexandria/functions.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -load alexandria/hash-tables.lisp \
	  -load alexandria/symbols.lisp \
	  -load alexandria/macros.lisp \
	  -load alexandria/control-flow.lisp \
	  -load alexandria/features.lisp \
	  -s -compile alexandria/functions.lisp
	test -f alexandria/functions.o

alexandria/lists.o: alexandria/lists.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp alexandria/hash-tables.lisp alexandria/symbols.lisp alexandria/macros.lisp alexandria/control-flow.lisp alexandria/features.lisp alexandria/functions.lisp
	rm -f alexandria/lists.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -load alexandria/hash-tables.lisp \
	  -load alexandria/symbols.lisp \
	  -load alexandria/macros.lisp \
	  -load alexandria/control-flow.lisp \
	  -load alexandria/features.lisp \
	  -load alexandria/functions.lisp \
	  -s -compile alexandria/lists.lisp
	test -f alexandria/lists.o

alexandria/types.o: alexandria/types.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp alexandria/hash-tables.lisp alexandria/symbols.lisp alexandria/macros.lisp alexandria/control-flow.lisp alexandria/features.lisp alexandria/functions.lisp alexandria/lists.lisp
	rm -f alexandria/types.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -load alexandria/hash-tables.lisp \
	  -load alexandria/symbols.lisp \
	  -load alexandria/macros.lisp \
	  -load alexandria/control-flow.lisp \
	  -load alexandria/features.lisp \
	  -load alexandria/functions.lisp \
	  -load alexandria/lists.lisp \
	  -s -compile alexandria/types.lisp
	test -f alexandria/types.o

alexandria/io.o: alexandria/io.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp alexandria/hash-tables.lisp alexandria/symbols.lisp alexandria/macros.lisp alexandria/control-flow.lisp alexandria/features.lisp alexandria/functions.lisp alexandria/lists.lisp alexandria/types.lisp
	rm -f alexandria/io.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -load alexandria/hash-tables.lisp \
	  -load alexandria/symbols.lisp \
	  -load alexandria/macros.lisp \
	  -load alexandria/control-flow.lisp \
	  -load alexandria/features.lisp \
	  -load alexandria/functions.lisp \
	  -load alexandria/lists.lisp \
	  -load alexandria/types.lisp \
	  -s -compile alexandria/io.lisp
	test -f alexandria/io.o

alexandria/arrays.o: alexandria/arrays.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp alexandria/hash-tables.lisp alexandria/symbols.lisp alexandria/macros.lisp alexandria/control-flow.lisp alexandria/features.lisp alexandria/functions.lisp alexandria/lists.lisp alexandria/types.lisp alexandria/io.lisp
	rm -f alexandria/arrays.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -load alexandria/hash-tables.lisp \
	  -load alexandria/symbols.lisp \
	  -load alexandria/macros.lisp \
	  -load alexandria/control-flow.lisp \
	  -load alexandria/features.lisp \
	  -load alexandria/functions.lisp \
	  -load alexandria/lists.lisp \
	  -load alexandria/types.lisp \
	  -load alexandria/io.lisp \
	  -s -compile alexandria/arrays.lisp
	test -f alexandria/arrays.o

alexandria/sequences.o: alexandria/sequences.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp alexandria/hash-tables.lisp alexandria/symbols.lisp alexandria/macros.lisp alexandria/control-flow.lisp alexandria/features.lisp alexandria/functions.lisp alexandria/lists.lisp alexandria/types.lisp alexandria/io.lisp alexandria/arrays.lisp
	rm -f alexandria/sequences.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -load alexandria/hash-tables.lisp \
	  -load alexandria/symbols.lisp \
	  -load alexandria/macros.lisp \
	  -load alexandria/control-flow.lisp \
	  -load alexandria/features.lisp \
	  -load alexandria/functions.lisp \
	  -load alexandria/lists.lisp \
	  -load alexandria/types.lisp \
	  -load alexandria/io.lisp \
	  -load alexandria/arrays.lisp \
	  -s -compile alexandria/sequences.lisp
	test -f alexandria/sequences.o

alexandria/numbers.o: alexandria/numbers.lisp alexandria/package.lisp alexandria/definitions.lisp alexandria/binding.lisp alexandria/strings.lisp alexandria/conditions.lisp alexandria/hash-tables.lisp alexandria/symbols.lisp alexandria/macros.lisp alexandria/control-flow.lisp alexandria/features.lisp alexandria/functions.lisp alexandria/lists.lisp alexandria/types.lisp alexandria/io.lisp alexandria/arrays.lisp alexandria/sequences.lisp
	rm -f alexandria/numbers.o
	ecl -norc \
	  -load alexandria/package.lisp \
	  -load alexandria/definitions.lisp \
	  -load alexandria/binding.lisp \
	  -load alexandria/strings.lisp \
	  -load alexandria/conditions.lisp \
	  -load alexandria/hash-tables.lisp \
	  -load alexandria/symbols.lisp \
	  -load alexandria/macros.lisp \
	  -load alexandria/control-flow.lisp \
	  -load alexandria/features.lisp \
	  -load alexandria/functions.lisp \
	  -load alexandria/lists.lisp \
	  -load alexandria/types.lisp \
	  -load alexandria/io.lisp \
	  -load alexandria/arrays.lisp \
	  -load alexandria/sequences.lisp \
	  -s -compile alexandria/numbers.lisp
	test -f alexandria/numbers.o

