#!/bin/bash

set -e

function standard {
    export ASGL_HOME=`pwd`

    time make check
    time make test-$VARIANT

    make clean | tail
}

function cover_for {
    rm -f cover.data
    if [[ $1 =~ ^D ]]; then
        ./bin/asgl -p $1 -f af.apx -a 0
    else
        ./bin/asgl -p $1 -f af.apx
    fi

    ./bin/asgl --cover-report --all >report

    echo =====================================================================
    echo ===================================
    echo $1 used
    echo ===================================
    grep '^;+' report

    echo ===================================
    echo $1 unused
    echo ===================================
    grep '^;-' report
}

function standard_cover {
    export ASGL_HOME=`pwd`

    cat >af.apx <<EOF
arg(0).
arg(1).
arg(2).
arg(3).
arg(4).
att(4,2).
att(3,4).
att(2,3).
att(1,0).
att(0,2).
att(0,1).
EOF

    cover_for SE-GR
    cover_for EE-GR
    cover_for DC-GR
    cover_for DS-GR

    cover_for SE-CO
    cover_for EE-CO
    cover_for DC-CO
    cover_for DS-CO

    cover_for SE-ST
    cover_for EE-ST
    cover_for DC-ST
    cover_for DS-ST

    cover_for SE-PR
    cover_for EE-PR
    cover_for DC-PR
    cover_for DS-PR

    time make test-$VARIANT
    ./bin/asgl --cover-report >report-test

    time make check
    ./bin/asgl --cover-report >report-both

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
