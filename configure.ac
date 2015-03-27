AC_INIT

CFLAGS="-std=iso9899:1990"

AC_LANG_PUSH([C++])

AC_ARG_VAR(ASGL_COVER, Settings this to yes has same effect as --enable-cover)
AC_ARG_ENABLE([cover], AS_HELP_STRING([--enable-cover], [Enable feature cover]))
AS_IF([test "x$enableval" = "xyes"], [AC_DEFINE([ENABLE_COVER])])
AS_IF([test "x$ASGL_COVER" = "xyes"], [AC_DEFINE([ENABLE_COVER])])

AC_ARG_VAR(ASGL_TIMING, Settings this to yes has same effect as --enable-timing)
AC_ARG_ENABLE([timing], AS_HELP_STRING([--enable-timing], [Enable feature timing]))
AS_IF([test "x$enableval" = "xyes"], [AC_DEFINE([ENABLE_TIMING])])
AS_IF([test "x$ASGL_TIMING" = "xyes"], [AC_DEFINE([ENABLE_TIMING])])

AC_ARG_VAR(ASGL_LOGGING, Settings this to yes has same effect as --enable-logging)
AC_ARG_ENABLE([logging], AS_HELP_STRING([--enable-logging], [Enable feature logging]))
AS_IF([test "x$enableval" = "xyes"], [AC_DEFINE([ENABLE_LOGGING])])
AS_IF([test "x$ASGL_LOGGING" = "xyes"], [AC_DEFINE([ENABLE_LOGGING])])

AC_ARG_WITH([gist],
    AS_HELP_STRING([--without-gist], [Ignore presence of gist and disable it]))

AS_IF([test "x$with_gist" != "xno"],
      [AC_CHECK_HEADERS([gecode/gist.hh], [have_gist=yes], [have_gist=no])],
      [have_gist=no])

AS_IF([test "x$have_gist" = "xyes"],
      [],
      [AS_IF([test "x$with_gist" = "xyes"],
             [AC_MSG_ERROR([gist requested but not found])
      ])
])

AC_CHECK_HEADERS([gmp.h])
if test x"$ac_cv_header_gmp_h" != x"yes" ; then
    AC_MSG_ERROR([Please install libgmp. Could be `apt-get install libgmp-dev'.])
fi

AC_CHECK_HEADERS([ecl/ecl.h])
if test "x$ac_cv_header_ecl_ecl_h" != x"yes" ; then
    AC_MSG_ERROR([Cannot find header ecl/ecl.h. This is unexpected.])
fi

AC_CHECK_HEADERS([gecode/int.hh])
if test "x$ac_cv_header_gecode_int_hh" != x"yes" ; then
    AC_MSG_ERROR([Cannot find header gecode/int.hh. This is unexpected.])
fi

cp confdefs.h asgl_config.h

AC_LANG_POP

AC_OUTPUT
