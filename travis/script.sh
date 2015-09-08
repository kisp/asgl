#!/bin/bash

set -e

function standard {
    export ASGL_HOME=`pwd`

    time make check
    time make test-$VARIANT

    make clean | tail
}

function standard_cover {
    export ASGL_HOME=`pwd`

    time make test-$VARIANT
    ./bin/asgl --cover-report &>report-test

    time make check
    ./bin/asgl --cover-report &>report-both

    echo ===================================
    echo make test coverage
    echo ===================================
    cat report-test

    echo ===================================
    echo make test AND make check coverage
    echo ===================================
    cat report-both

    echo ===================================
    echo diff -u report-both report-test
    echo ===================================
    diff -u report-both report-test || true

    rm report-test
    rm report-both
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
    env LD_LIBRARY_PATH=`pwd`/local/lib:$LD_LIBRARY_PATH ldd bin/asgl_kernel
    cd ../..
    export ASGL_HOME=`pwd`
    make test-dist
}

if [ "$VARIANT" == "dist" ]; then
    dist
elif [ -n "$ASGL_COVER" ]; then
    standard_cover
else
    standard
fi
