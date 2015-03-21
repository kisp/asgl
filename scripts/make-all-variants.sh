#!/bin/bash

set -e

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
bash scripts/generate-make-mk.sh
make install-gr1
make test-gr1

make clean
echo DONE
