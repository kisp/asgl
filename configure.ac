AC_INIT

CFLAGS="-std=iso9899:1990"

AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([gecode/gist.hh])
AC_CHECK_HEADERS([gmp.h])
AC_LANG_POP

if test x"$ac_cv_header_gmp_h" != x"yes" ; then
    AC_MSG_ERROR([Please install libgmp. Could be `apt-get install libgmp-dev'.])
fi

cp confdefs.h asgl_config.h

AC_OUTPUT
