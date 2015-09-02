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
