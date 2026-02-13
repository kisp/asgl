#!/bin/bash

set -euxo pipefail

make data/iccma15_solutions data/iccma15_testcases

nix-shell \
    --pure --run 'ASGL_HOME=`pwd` make test'
