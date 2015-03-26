#!/bin/bash

set -e

function standard {
    sudo apt-get update
    sudo apt-get install libgmp-dev
    sudo apt-get install libmpfr-dev
    sudo apt-get install libffi-dev
    # sudo apt-get install flex
    # sudo apt-get install bison
    # sudo apt-get install libqt4-dev

    g++ --version
    as --version
    ld --version
    ragel --version

    curl --no-progress-bar --retry 10 -o "gecode.tar.bz2" -L "http://178.62.230.106/packages/gecode-4.3.3-complete-amd64.tar.bz2"
    md5sum gecode.tar.bz2
    sudo tar -C / -xjf "gecode.tar.bz2"
    rm gecode.tar.bz2

    curl --no-progress-bar --retry 10 -o "ecl.tar.gz" -L "http://178.62.230.106/packages/ecl-13.5.1-amd64.tgz"
    md5sum ecl.tar.gz
    sudo tar -C / -xzf "ecl.tar.gz"
    rm ecl.tar.gz

    sudo ldconfig

    bundle install

    export ASGL_HOME=`pwd`

    bash scripts/generate-make-mk.sh

    autoconf

    ./configure

    make install-$VARIANT
}

function dist {
    sudo apt-get update
    sudo apt-get install libgmp-dev

    curl --no-progress-bar --retry 10 -o "ecl.tar.gz" -L "http://178.62.230.106/packages/ecl-13.5.1-amd64.tgz"
    md5sum ecl.tar.gz
    mkdir tmpecl
    tar --strip-components=2 -C tmpecl -xf ecl.tar.gz
    rm ecl.tar.gz
    env PATH=`pwd`/tmpecl/bin:$PATH \
        LD_LIBRARY_PATH=`pwd`/tmpecl/lib \
        bash scripts/generate-make-mk.sh
    rm -r tmpecl

    make dist
    mv dist/asgl.tar.gz .
    rm -r dist
    mkdir user
    cd ./user
    tar xf ../asgl.tar.gz
}

if [ "$VARIANT" == "dist" ]; then
    dist
else
    standard
fi
