#!/bin/bash

set -e

function standard {
    export ASGL_HOME=`pwd`

    make test-$VARIANT

    if [ -n "$ASGL_COVER" ]; then
        ./bin/asgl --cover-report
    fi

    make clean | tail
}

function dist {
    cd ./user/asgl
    echo ===========================
    echo will run ./build in `pwd`
    echo ===========================
    ./build
    file bin/asgl
    file bin/asgl_kernel
    ldd bin/asgl_kernel
}

if [ "$VARIANT" == "dist" ]; then
    dist
else
    standard
fi
