#!/bin/bash

set -e

function standard {
    export ASGL_HOME=`pwd`

    make test-$VARIANT
    ./bin/asgl --cover-report
    make clean | tail
}

function dist {
    echo dist
}

if [ "$VARIANT" == "dist" ]; then
    dist
else
    standard
fi
