# IJG auto-configuration source file.
# Process this file with autoconf to produce a configure script.

#
# Configure script for IJG libjpeg
#

AC_INIT([jpeg-client], [9.0.0])

# Directory where autotools helper scripts lives.
AC_CONFIG_AUX_DIR([autotools])
AC_CONFIG_MACRO_DIR([autotools/m4])

# Check system type
AC_CANONICAL_TARGET

# Initialize Automake
# Don't require all the GNU mandated files
AM_INIT_AUTOMAKE([-Wall -Werror no-dist foreign])

# Make --enable-silent-rules the default.
# To get verbose build output you may configure
# with --disable-silent-rules or use "make V=1".
AM_SILENT_RULES([yes])

# Add configure option --enable-maintainer-mode which enables
# dependency checking and generation useful to package maintainers.
# This is made an option to avoid confusing end users.
AM_MAINTAINER_MODE

# Check for programs
AC_PROG_CC
AC_PROG_CC_STDC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_LN_S
AM_PROG_AR


# Configure libtool
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL

# Extract the library version IDs from jpeglib.h.
AC_MSG_CHECKING([libjpeg version number])
[major=`sed -ne 's/^#define JPEG_LIB_VERSION_MAJOR *\([0-9][0-9]*\).*$/\1/p' $srcdir/../jpeg-9/jpeglib.h`
minor=`sed -ne 's/^#define JPEG_LIB_VERSION_MINOR *\([0-9][0-9]*\).*$/\1/p' $srcdir/../jpeg-9/jpeglib.h`]
AC_SUBST([JPEG_LIB_VERSION],
         [`expr $major + $minor`:0:$minor])
AC_MSG_RESULT([$JPEG_LIB_VERSION])

# Get hybris library
AC_ARG_WITH([hybris-common-lib-path],
  [AS_HELP_STRING([--with-hybris-common-lib-path], [location of the hybris-common library])],
  [HYBRIS_LIBS="-L$withval -lhybris-common"],
  [HYBRIS_LIBS='-lhybris-common'])
AC_SUBST([HYBRIS_LIBS])


AC_CHECK_LIB([hybris-common], [android_dlsym])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
