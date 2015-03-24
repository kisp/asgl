#!/bin/bash

set -e

export ASGL_HOME=`pwd`

make test-$VARIANT
./bin/asgl --cover-report
make clean | tail
