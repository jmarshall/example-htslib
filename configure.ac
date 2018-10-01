AC_INIT([tinycount], [1.0])
AC_CONFIG_SRCDIR([tinycount.c])

m4_include([m4/ax_with_htslib.m4])

AC_PROG_CC

AX_WITH_HTSLIB
if test "$ax_cv_htslib" != yes; then
  AC_MSG_ERROR([HTSlib development files not found])
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
