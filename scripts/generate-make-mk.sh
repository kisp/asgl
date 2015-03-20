#!/bin/bash

set -e

ecl -norc -load support/asdf.lisp -load lisp-scripts/deps.lisp -eval '(main)' -- lib/*/*.asd common/*/*.asd

patch -p1 <common/early/make.mk.patch
