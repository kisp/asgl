#!/bin/bash

set -e
set -x

PACKAGE_HOST=http://kisp.github.io/asgl/files

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

    curl --no-progress-bar --retry 10 -o "gecode.tar.bz2" -L "$PACKAGE_HOST/gecode-4.3.3-complete-amd64.tar.bz2"
    md5sum gecode.tar.bz2
    sudo tar -C / -xjf "gecode.tar.bz2"
    rm gecode.tar.bz2

    curl --no-progress-bar --retry 10 -o "ecl.tar.bz2" -L "$PACKAGE_HOST/ecl-16.1.2-amd64.tar.bz2"
    md5sum ecl.tar.bz2
    sudo tar -C / -xf "ecl.tar.bz2"
    rm ecl.tar.bz2

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

    bundle install

    curl --no-progress-bar --retry 10 -o "ecl.tar.bz2" -L "$PACKAGE_HOST/ecl-16.1.2-amd64.tar.bz2"
    md5sum ecl.tar.bz2
    mkdir tmpecl
    tar --strip-components=2 -C tmpecl -xf ecl.tar.bz2
    mv tmpecl/bin/ecl tmpecl/bin/ecl_r
    cat >tmpecl/bin/ecl<<'EOF'
#!/bin/bash
if [ ! -d  "$ECL_R_SYS_DIR" ]; then
  echo ECL_R_SYS_DIR not set or does not exist
  exit 7
fi
exec ecl_r -dir "$ECL_R_SYS_DIR" "$@"
EOF
    chmod +x tmpecl/bin/ecl
    rm ecl.tar.bz2

    env PATH=`pwd`/tmpecl/bin:$PATH \
        LD_LIBRARY_PATH=`pwd`/tmpecl/lib \
        ECL_R_SYS_DIR=`pwd`/tmpecl/lib/ecl-16.1.2 \
        bash scripts/generate-make-mk.sh

    cp Makefile.in Makefile

    env PATH=`pwd`/tmpecl/bin:$PATH \
        LD_LIBRARY_PATH=`pwd`/tmpecl/lib \
        ECL_R_SYS_DIR=`pwd`/tmpecl/lib/ecl-16.1.2 \
        make dist

    rm -r tmpecl

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
