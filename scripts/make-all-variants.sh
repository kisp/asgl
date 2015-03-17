#!/bin/bash

set -e

make clean
make install-ref
make test-ref

make clean
make install-v1
make test-v1
