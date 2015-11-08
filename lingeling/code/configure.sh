#!/bin/sh

check=undefined
chksol=undefined
coverage=undefined
debug=no
log=undefined
lto=no
olevel=none
other=none
picosat=no
druplig=no
profile=undefined
static=no
aiger=undefined
double=no
yalsat=undefined

##########################################################################

die () {
  echo "*** configure.sh: $*" 1>&2
  exit 1
}

##########################################################################

while [ $# -gt 0 ]
do
  case $1 in
    -h|--help) 
       echo "usage: configure.sh [<option> ...]"
       echo
       echo "where <option> is one of the following"
       echo
       echo "-h | --help"
       echo "-g | --debug    include debugging code and symbols"
       echo "-l | --log      include logging code (default with '-g')"
       echo "-c | --check    include checking code (default with '-g')"
       echo "-p | --profile  compile with '-pg' for profiling"
       echo "--coverage      compile with coverage options"
       echo "--no-check      no checking code (overwrite default for '-g')"
       echo "--chksol        always check solution (default for '-c')"
       echo "--no-chksol     do not check solution"
       echo "--softfloats    use software floats"
       echo "--double        use hardware floats (of 'double' type)"
       echo "--no-log        no logging code (overwrite default for '-g')"
       echo "-O[0-4]         set optimization level unless '-g' specified"
       echo "-flto           enable link time optimization"
       echo "--picosat       add checking code depending on PicoSAT"
       echo "--druplig       add checking code depending on Druplig"
       echo "-f...|-m...     add other compiler options"
       echo "--aiger=<dir>   specify AIGER directory (default '../aiger')"
       echo "--no-aiger      no targets requiring AIGER library"
       echo "--yalsat=<dir>  specify YalSAT directory (default '../yalsat')"
       echo "--no-yalsat     do not include YalSAT code"
       exit 0
       ;;
    -g|--debug) debug=yes;;
    -l|--log) log=yes;;
    -c|--check) check=yes;;
    --chksol) chksol=yes;;
    --no-chksol|--nchksol) chksol=no;;
    --no-check) check=no;;
    --no-log) log=no;;
    -p|--profile) profile=yes;;
    --softfloats) double=no;;
    --double) double=yes;;
    --coverage) coverage=yes;;
    --picosat) picosat=yes;;
    --druplig) druplig=yes;;
    -O) debug=no;;
    -O0|-O1|-O2|-O3|-O4) olevel=$1;;
    -lto|-flto|--lto|--flto) lto=yes;;
    -static) static=yes;;
    --aiger=*) aiger=`echo "$1"|sed -e 's,^--aiger=,,' `;;
    --no-aiger) aiger=no;;
    --yalsat=*) yalsat=`echo "$1"|sed -e 's,^--yalsat=,,' `;;
    --no-yalsat) yalsat=no;;
    -f*|-m*) if [ $other = none ]; then other=$1; else other="$other $1"; fi;;
    *) echo "*** configure.sh: invalid command line option '$1'"; exit 1;;
  esac
  shift
done

##########################################################################

if [ x"$aiger" = xundefined ]
then
  if [ -d ../aiger ]
  then
    aiger="../aiger"
  fi
fi

if [ x"$aiger" = xundefined ]
then
  aiger=no
elif [ ! x"$aiger" = xno ]
then
  if [ ! -d "$aiger" ]
  then
    die "'$aiger' not a directory (use '--aiger' or '--no-aiger')"
  elif [ ! -f "$aiger/aiger.h" ]
  then
    die "can not find '$aiger/aiger.h'"
  elif [ ! -f "$aiger/aiger.o" ]
  then
    die "can not find '$aiger/aiger.o'"
  fi
fi

##########################################################################

if [ x"$yalsat" = xundefined ]
then
  if [ -d ../yalsat ]
  then
    yalsat="../yalsat"
    echo "using $yalsat"
  fi
fi

if [ x"$yalsat" = xundefined ]
then
  yalsat=no
elif [ ! x"$yalsat" = xno ]
then
  if [ ! -d "$yalsat" ]
  then
    die "'$yalsat' not a directory (use '--yalsat' or '--no-yalsat')"
  elif [ ! -f "$yalsat/yals.h" ]
  then
    die "can not find '$yalssat/yals.h'"
  elif [ ! -f "$yalsat/libyals.a" ]
  then
    die "can not find '$yalsat/libyals.a'"
  fi
fi

##########################################################################

[ $log = undefined ] && log=$debug
[ $check = undefined ] && check=$debug

for CNF in profile.cnf.gz \
           /data/cnf/sc2009/applications/simon-s03-fifo8-300.cnf \
           /data/cnf/cmu/longmult12.dimacs \
	   log/prime65537.in \
	   none
do
  [ -f $CNF ] && break;
done

##########################################################################

[ x"$CC" = x ] && CC=gcc

CFLAGS="-Wall"
if [ $debug = yes ]
then
  CFLAGS="$CFLAGS -g3"
  [ $olevel = none ] || CFLAGS="$CFLAGS $olevel"
else
  [ $olevel = none ] && olevel=-O3
  CFLAGS="$CFLAGS $olevel"
  [ $lto = yes ] && CFLAGS="$CFLAGS -flto -fwhole-program"
fi

[ $double = no ] && CFLAGS="$CFLAGS -DNDBLSCR"

LIBS="-lm"
if [ $picosat = yes ]
then
  if [ ! -d ../picosat ]
  then
    echo "*** configure.sh: can not find '../picosat'"
    exit 1;
  elif [ ! -f ../picosat/picosat.h ]
  then
    echo "*** configure.sh: can not find '../picosat/picosat.h'"
    exit 1;
  elif [ ! -f ../picosat/libpicosat.a ]
  then
    echo "*** configure.sh: can not find '../picosat/libpicosat.a'"
    exit 1;
  else
    HDEPS="../picosat/picosat.h"
    LDEPS="../picosat/libpicosat.a"
    LIBS="$LIBS -L../picosat -lpicosat"
    CFLAGS="$CFLAGS -I../picosat"
  fi
else
  HDEPS=""
  LDEPS=""
fi

if [ $druplig = yes ]
then
  if [ ! -d ../druplig ]
  then
    echo "*** configure.sh: can not find '../druplig'"
    exit 1;
  elif [ ! -f ../druplig/druplig.h ]
  then
    echo "*** configure.sh: can not find '../druplig/druplig.h'"
    exit 1;
  elif [ ! -f ../druplig/libdruplig.a ]
  then
    echo "*** configure.sh: can not find '../druplig/libdruplig.a'"
    exit 1;
  else
    HDEPS="../druplig/druplig.h"
    LDEPS="../druplig/libdruplig.a"
    LIBS="$LIBS -L../druplig -ldruplig"
    CFLAGS="$CFLAGS -I../druplig"
  fi
else
  HDEPS=""
  LDEPS=""
fi

if [ "$aiger" = no ]
then
  AIGERTARGETS=""
  AIGER=""
else
  AIGERTARGETS="blimc"
  AIGER="$aiger"
fi

if [ ! "$yalsat" = no ]
then
  [ x"$HDEPS" = x ] || HDEPS="${HDEPS} "
  HDEPS="${HDEPS}$yalsat/yals.h"
  [ x"$LDEPS" = x ] || LDEPS="${LDEPS} "
  LDEPS="${LDEPS}$yalsat/libyals.a"
  [ x"$LIBS" = x ] || LIBS="${LIBS} "
  LIBS="${LIBS} -L$yalsat -lyals"
  [ x"$CFLAGS" = x ] || CFLAGS="${CFLAGS} "
  CFLAGS="${CFLAGS} -I$yalsat"
fi

[ $chksol = undefined ] && chksol=$check
[ $static = yes ] && CFLAGS="$CFLAGS -static"
[ $profile = yes ] && CFLAGS="$CFLAGS -pg"
[ $coverage = yes ] && CFLAGS="$CFLAGS -ftest-coverage -fprofile-arcs"
[ $other = none ] || CFLAGS="$CFLAGS $other"
[ $log = no ] && CFLAGS="$CFLAGS -DNLGLOG"
[ $check = no ] && CFLAGS="$CFLAGS -DNDEBUG"
[ $chksol = no ] && CFLAGS="$CFLAGS -DNCHKSOL"
[ $picosat = no ] && CFLAGS="$CFLAGS -DNLGLPICOSAT"
[ $druplig = no ] && CFLAGS="$CFLAGS -DNLGLDRUPLIG"
[ $yalsat = no ] && CFLAGS="$CFLAGS -DNLGLYALSAT"

echo "$CC $CFLAGS"

##########################################################################

rm -f makefile
sed \
  -e "s,@CC@,$CC," \
  -e "s,@CFLAGS@,$CFLAGS," \
  -e "s,@HDEPS@,$HDEPS," \
  -e "s,@LDEPS@,$LDEPS," \
  -e "s,@AIGERTARGETS@,$AIGERTARGETS," \
  -e "s,@AIGER@,$AIGER," \
  -e "s,@CNF@,$CNF," \
  -e "s,@LIBS@,$LIBS," \
  makefile.in > makefile
