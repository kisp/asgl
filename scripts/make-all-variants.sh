#!/bin/bash

set -e

make clean
make install-ref
make test-ref

make clean
make install-v1
make test-v1

make clean
make install-gr1
make test-gr1

make clean
echo DONE
