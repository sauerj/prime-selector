#
# Autoconf
#
AC_INIT([PRIMEselector], [0.1], [jsauer65@gmail.com])
AC_CONFIG_SRCDIR([src/prime-selector.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])

#
# Automake
#
AM_INIT_AUTOMAKE([-Wall -Werror foreign dist-bzip2])

#
# Check for programs and libraries
#
AC_PROG_CC
PKG_CHECK_MODULES([GTK], [gtk+-3.0])
AC_CHECK_PROG(PRIMESELECT_CHECK, prime-select, yes)
if test x"${PRIMESELECT_CHECK}" != x"yes" ; then
    AC_MSG_ERROR([Please install prime-select before trying to build prime-selector.])
fi

AC_CONFIG_FILES([
 Makefile
 src/Makefile
 data/Makefile
 data/desktop/Makefile
 data/icons/Makefile
 data/icons/hicolor/Makefile
 data/icons/hicolor/16x16/Makefile
 data/icons/hicolor/16x16/apps/Makefile
 data/icons/hicolor/24x24/Makefile
 data/icons/hicolor/24x24/apps/Makefile
 data/icons/hicolor/36x36/Makefile
 data/icons/hicolor/36x36/apps/Makefile
 data/icons/hicolor/48x48/Makefile
 data/icons/hicolor/48x48/apps/Makefile
 data/icons/hicolor/64x64/Makefile
 data/icons/hicolor/64x64/apps/Makefile
 data/icons/hicolor/128x128/Makefile
 data/icons/hicolor/128x128/apps/Makefile
 data/icons/hicolor/scalable/Makefile
 data/icons/hicolor/scalable/apps/Makefile
])
AC_OUTPUT
