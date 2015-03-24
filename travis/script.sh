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
    ldd bin/asgl
}

if [ "$VARIANT" == "dist" ]; then
    dist
else
    standard
fi
