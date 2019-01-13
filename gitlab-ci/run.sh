#!/bin/bash

set -e

function autoconf_step {
    autoconf
}

function configure_step {
    ./configure "$@"
}

function make_mk_step {
    ./scripts/generate-make-mk.sh
}

function make_step {
    make
}

function greeting_step {
    export ASGL_HOME=`pwd`
    ./bin/asgl
}

function check_step {        
        case $1 in
        full)
            for test in tests/*.lisp; do
                ./bin/asgl --check $test
            done
            ;;
        light)
            for test in tests/*.lisp; do
                if [[ $test =~ tests-(complete|grounded|preferred|stable) ]]; then
                    continue
                fi                
                ./bin/asgl --check $test
            done
            ;;
        none)
            ;;
        *)
            echo unknown test mode $1
            exit 7
    esac
}

function cucumber_step {
    case $1 in
        full)
            make data/iccma15_solutions data/iccma15_testcases
            cucumber
            ;;
        light)
            cucumber --tags ~@slow
            ;;
        none)
            ;;
        *)
            echo unknown test mode $1
            exit 7
    esac
}

function cover_report_step {
    while [ $# -gt 0 ]; do
        case $1 in
            --enable-cover)
                ./bin/asgl --cover-report |& tee cover-report.txt
                return 0
                ;;
        esac
        shift        
    done
}

function s3put_step {
    TRIM="$@"
    TRIM=${TRIM//--/}
    TRIM=${TRIM// /_}
    xz -k bin/asgl
    du -h bin/*
    s3put bin/asgl.xz bin/$(git describe)/$TRIM/asgl.xz
        while [ $# -gt 0 ]; do
        case $1 in
            --enable-cover)
                xz -k cover-report.txt
                s3put cover-report.txt.xz bin/$(git describe)/$TRIM/cover-report.txt.xz
                return 0
                ;;
        esac
        shift        
    done
}

echo RUNNING "$@"

TEST_MODE=$1
shift
CONFIG_ARGS="--without-gist $@"

set -x
autoconf_step
configure_step $CONFIG_ARGS
make_mk_step
make_step
greeting_step
check_step $TEST_MODE
cucumber_step $TEST_MODE
cover_report_step $CONFIG_ARGS
#s3put_step $CONFIG_ARGS
