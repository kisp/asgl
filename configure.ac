AC_INIT

CFLAGS="-std=iso9899:1990"

AC_LANG_PUSH([C++])
AC_CHECK_HEADER(gecode/gist.hh)
AC_CHECK_HEADER(gmp.h)
AC_LANG_POP

AC_CHECK_PROG(FFMPEG_CHECK,ffmpeg,yes)
if test x"$ac_cv_header_gmp_h" != x"yes" ; then
    AC_MSG_ERROR([Please install libgmp. Could be `apt-get install libgmp-dev'.])
fi

cp confdefs.h asgl_config.h

AC_OUTPUT
