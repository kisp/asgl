[![Build Status](https://travis-ci.org/kisp/asgl.svg?branch=master)](https://travis-ci.org/kisp/asgl)
[![Docker Build Status](http://hubstatus.container42.com/kisp/asgl)](https://registry.hub.docker.com/u/kisp/asgl)

# ASGL

[ASGL](https://github.com/kisp/asgl#asgl) is an abstract argumentation
solver implemented in
[Embeddable Common Lisp (ECL)](http://cliki.net/ecl) and
[GECODE](http://www.gecode.org/), a toolkit for developing
constraint-based systems and applications. The interface conforms to
[ICCMA15](http://argumentationcompetition.org/2015/rules.html).

    Copyright (C) 2015  Kilian Sprotte
    This program comes with ABSOLUTELY NO WARRANTY.
    This is free software, and you are welcome to redistribute it
    under certain conditions.

# Building

## autoconf

Run `autoconf` to create the `configure` script from `configure.ac`.

## configure

Run `./configure`. Depending on your GECODE installation, you might want to pass `--without-gist`.

Files involved:

- Makefile.in
- lisp-scripts/compile-v1.lisp.in

## generate make .mk files

Run `./scripts/generate-make-mk.sh` to generate .mk files.

Files involved:

- common/asgl-config/asgl-config.asd                                                       
- common/early/early.asd                                                                   
- common/early/make.mk.patch                                                               
- lib/alexandria/alexandria.asd                                                            
- lib/arnesi-list-match/arnesi-list-match.asd                                              
- lib/myam/version.lisp-expr                                                               
- lisp-scripts/deps.lisp                                                                   
- support/asdf.lisp                                                                        


## make

Run `make`.

Files involved:

- common/asgl-config/asgl-config.lisp
- common/early/apx.lisp
- common/early/count_args.rl
- common/early/cover.lisp
- common/early/graph.lisp
- common/early/ragel_apx_parse.h
- common/early/ragel_apx_parse.rl
- common/early/package.lisp
- common/early/slurp.cpp
- common/early/utils.lisp
- lib/alexandria/arrays.lisp
- lib/alexandria/binding.lisp
- lib/alexandria/conditions.lisp
- lib/alexandria/control-flow.lisp
- lib/alexandria/definitions.lisp
- lib/alexandria/features.lisp
- lib/alexandria/functions.lisp
- lib/alexandria/hash-tables.lisp
- lib/alexandria/io.lisp
- lib/alexandria/lists.lisp
- lib/alexandria/macros.lisp
- lib/alexandria/numbers.lisp
- lib/alexandria/package.lisp
- lib/alexandria/sequences.lisp
- lib/alexandria/strings.lisp
- lib/alexandria/symbols.lisp
- lib/alexandria/types.lisp
- lib/arnesi-list-match/list-match.lisp
- lib/arnesi-list-match/package.lisp
- lib/myam/myam.asd
- lib/myam/src/check.lisp
- lib/myam/src/classes.lisp
- lib/myam/src/explain.lisp
- lib/myam/src/packages.lisp
- lib/myam/src/random.lisp
- lib/myam/src/run.lisp
- lib/myam/src/suite.lisp
- lib/myam/src/test.lisp
- lib/myam/src/utils.lisp
- lisp-scripts/compile-file-system-p.lisp
- support/gecode-patched-headers.tgz
- v1/DfsSpace.cpp
- v1/DfsSpace.h
- v1/PrBABSpace.cpp
- v1/PrBABSpace.h
- v1/v1.lisp


## make test

Run ```ASGL_HOME=`pwd` make test``` or alternatively
```ASGL_HOME=`pwd` CUKE_ARGS="--tags '~@slow'" make test``` (skipping
some long running tests).

# Notes

## Loading via fas files

At some point in time, it was possible to load ASGL via fas files.

``` lisp
(load "common/asgl-config/asgl-config.fas")
(load "common/early/early.fas")
(load "lib/alexandria/alexandria.fas")
(load "lib/arnesi-list-match/arnesi-list-match.fas")
(load "lib/myam/myam.fas")
(let ((lib-dir "/nix/store/n8s5yghc01vvs9lmlkkn1k0mg6g7zyb8-gecode-4.3.3/lib/"))
  (dolist (lib '("libgecodesearch.so.40"
                 "libgecodeint.so.40"
                 "libgecodeset.so.40"
                 "libgecodeminimodel.so.40"
                 "libgecodekernel.so.40"
                 "libgecodesupport.so.40"
                 "libgecodegist.so.40"))
    (ffi:load-foreign-library (merge-pathnames lib lib-dir))))
(load "v1/v1.fas")
```
