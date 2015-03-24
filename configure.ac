AC_INIT

CFLAGS="-std=iso9899:1990"

AC_LANG_PUSH([C++])

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
AC_LANG_POP

if test x"$ac_cv_header_gmp_h" != x"yes" ; then
    AC_MSG_ERROR([Please install libgmp. Could be `apt-get install libgmp-dev'.])
fi

cp confdefs.h asgl_config.h

AC_OUTPUT
