#!/bin/bash

set -e

if [ -z "$ASGL_HOME" ]; then
    export ASGL_HOME=`pwd`
fi

bash scripts/generate-make-mk.sh

make clean
bash scripts/generate-make-mk.sh
make install-ref
make test-ref

make clean
bash scripts/generate-make-mk.sh
make install-v1
make test-v1

make clean
echo DONE
