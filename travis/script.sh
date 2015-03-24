#!/bin/bash

set -e

function standard {
    export ASGL_HOME=`pwd`

    make test-$VARIANT
    ./bin/asgl --cover-report
    make clean | tail
}

function dist {
    cd ./user/asgl
    echo ===========================
    echo will run ./build in `pwd`
    echo ===========================
    ./build
}

if [ "$VARIANT" == "dist" ]; then
    dist
else
    standard
fi
