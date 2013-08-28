
AC_INIT([libjpeg-bridge], [1.0.0])

# Directory where autotools helper scripts lives.
AC_CONFIG_AUX_DIR([autotools])

# Initialize Automake
# Don't require all the GNU mandated files
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_CONFIG_MACRO_DIR([autotools/m4])

AC_PROG_CC
AM_PROG_AR

AC_PROG_LIBTOOL

# Get hybris library include location
AC_ARG_WITH([hybris-internal-include-path],
  [AS_HELP_STRING([--with-hybris-internal-include-path],
    [location of the hybris internal headers, defaults to /usr/local/include/hybris])],
  [HYBRIS_CFLAGS="-I$withval"],
  [HYBRIS_CFLAGS='-I/usr/local/include/hybris'])
AC_SUBST([HYBRIS_CFLAGS])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
