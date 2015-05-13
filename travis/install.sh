#!/bin/bash

set -e

PACKAGE_HOST=http://pub47300999.s3-website.eu-central-1.amazonaws.com

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

    curl --no-progress-bar --retry 10 -o "ecl.tar.gz" -L "$PACKAGE_HOST/ecl-13.5.1-amd64.tgz"
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

    bundle install

    curl --no-progress-bar --retry 10 -o "ecl.tar.gz" -L "$PACKAGE_HOST/ecl-13.5.1-amd64.tgz"
    md5sum ecl.tar.gz
    mkdir tmpecl
    tar --strip-components=2 -C tmpecl -xf ecl.tar.gz
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
    rm ecl.tar.gz

    env PATH=`pwd`/tmpecl/bin:$PATH \
        LD_LIBRARY_PATH=`pwd`/tmpecl/lib \
        ECL_R_SYS_DIR=`pwd`/tmpecl/lib/ecl-13.5.1 \
        bash scripts/generate-make-mk.sh

    env PATH=`pwd`/tmpecl/bin:$PATH \
        LD_LIBRARY_PATH=`pwd`/tmpecl/lib \
        ECL_R_SYS_DIR=`pwd`/tmpecl/lib/ecl-13.5.1 \
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
