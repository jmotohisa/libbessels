#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libbessels],[0.1a],[motohisa@ist.hokudai.ac.jp])
AC_CONFIG_SRCDIR([bessel_wrap/toms644/zbsubs.f])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE

SHARED_VERSION_INFO="1:0:0" # CURRENT:REVISION:AGE
AC_SUBST(SHARED_VERSION_INFO)
# need shared libraries for python interfaces
AC_ENABLE_SHARED


# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_CHECK_PROGS(F77, f77 xlf77 cf77 fort77 f90 xlf90 gfortran g95)
AC_PROG_F77
# AC_F77_LIBRARY_LDFLAGS

AC_PROG_INSTALL
# AC_PROG_RANLIB

# Checks for libraries.
LT_INIT

AC_CHECK_LIB([g2c], [main])
AC_CHECK_LIB([m], [main])

# If we have a Fortran compiler, link to its libraries, since these
# are probably needed to link with the BLAS/LAPACK libraries.
if test x != x"$F77"; then
	AC_F77_LIBRARY_LDFLAGS
	AC_F77_WRAPPERS
fi

##############################################################################
# GNU Scientific Library

AC_CHECK_FUNC(cblas_cgemm, [], [AC_CHECK_LIB(gslcblas, cblas_cgemm)])

AC_CHECK_LIB(gsl, gsl_sf_bessel_Jn, [],
	[AC_MSG_ERROR([GNU GSL library does not exist.])])
	
##############################################################################

##############################################################################

AC_ARG_WITH(libctl, [AS_HELP_STRING([--with-libctl=<dir>],[specify libctl directory])], with_libctl=$withval, with_libctl=yes)
if test "x$with_libctl" = "xno"; then
        :
elif test "x$with_libctl" != "xyes"; then
	LIBCTL_DIR="$with_libctl"
fi

AM_CONDITIONAL(WITH_LIBCTL, test "x$with_libctl" != xno)

AC_ARG_WITH(scheme, [AS_HELP_STRING([--without-scheme],[compile without Scheme interface])],
            with_scheme=$withval, with_scheme=yes)
AM_CONDITIONAL(WITH_SCHEME, test x"$with_scheme" = "xyes")

##############################################################################
# Check for Guile library and its behavior (for libctl front end):

if test "x$with_libctl" != xno -a "x$with_scheme" = "xyes"; then

save_LIBS=$LIBS
save_CPPFLAGS=$CPPFLAGS

AC_CHECK_PROG(GUILE_CONFIG, guile-config, guile-config, unknown)
if test "x$GUILE_CONFIG" = "xunknown"; then
  AC_CHECK_LIB(readline, readline)
  AC_CHECK_LIB(dl, dlopen)
  AC_CHECK_LIB(guile-ltdl, scm_lt_dlinit, [], [AC_CHECK_LIB(ltdl, dlopen)])
  AC_CHECK_LIB(guile, gh_eval_str, [],
    [AC_CHECK_LIB(guile, scm_eval_string, [],
    [AC_MSG_ERROR([linking to guile failed])])])
  GUILE_LIBS="-lguile -lguile-ltdl -lreadline"
  GUILE_CPPFLAGS=""
else
  GUILE_LIBS=`$GUILE_CONFIG link`
  GUILE_CPPFLAGS=`$GUILE_CONFIG compile`
  CPPFLAGS="$CPPFLAGS $GUILE_CPPFLAGS"
  LIBS="$GUILE_LIBS $LIBS"
  AC_MSG_CHECKING([if linking to guile works])
  AC_TRY_LINK_FUNC(gh_enter, AC_MSG_RESULT(yes),
    [AC_TRY_LINK_FUNC(scm_boot_guile, AC_MSG_RESULT(yes),
    [AC_MSG_RESULT(no)
     AC_MSG_ERROR([guile-config is broken])])])
fi
AC_CHECK_HEADERS([libguile.h guile/gh.h])

# Check how smob types work in this Guile version:

AC_CHECK_FUNCS(scm_make_smob_type)
AC_MSG_CHECKING([for SCM_SMOB_PREDICATE])
AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <guile/gh.h>
#include <libguile/smob.h>]], [[int x; SCM_SMOB_PREDICATE(1,x);]])],[ok=yes],[ok=no])
AC_MSG_RESULT($ok)
if test $ok = yes; then
	AC_DEFINE(HAVE_SCM_SMOB_PREDICATE, 1, [define if we have SCM_SMOB_PREDICATE])
fi
AC_MSG_CHECKING([for SCM_SMOB_DATA])
AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <guile/gh.h>
#include <libguile/smob.h>]], [[int x; SCM_SMOB_DATA(x);]])],[ok=yes],[ok=no])
AC_MSG_RESULT($ok)
if test $ok = yes; then
	AC_DEFINE(HAVE_SCM_SMOB_DATA, 1, [define if we have SCM_SMOB_DATA])
fi
AC_MSG_CHECKING([for SCM_NEWSMOB])
AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <guile/gh.h>
#include <libguile/smob.h>]], [[int x; SCM_NEWSMOB(x,1,0);]])],[ok=yes],[ok=no])
AC_MSG_RESULT($ok)
if test $ok = yes; then
	AC_DEFINE(HAVE_SCM_NEWSMOB, 1, [define if we have SCM_NEWSMOB])
fi

# Check how to activate Guile readline support:

ACTIVATE_READLINE=""
if test "x$cross_compiling" = xno; then
AC_MSG_CHECKING(how to activate readline in Guile)
ractivate="(use-modules (readline-activator)) (activate-readline)"
if guile -c "$ractivate" > /dev/null 2>&1; then
	AC_MSG_RESULT(readline-activator)
	ACTIVATE_READLINE="$ractivate"
else
	ractivate="(use-modules (ice-9 readline)) (activate-readline)"
	if guile -c "$ractivate" >& /dev/null; then
	        AC_MSG_RESULT(ice-9 readline)
	        ACTIVATE_READLINE="$ractivate"
	else
		AC_MSG_RESULT(cannot)
		ACTIVATE_READLINE=""
	fi
fi
fi
AC_SUBST(ACTIVATE_READLINE)

AC_SUBST(GUILE_LIBS)
AC_SUBST(GUILE_CPPFLAGS)
LIBS=$save_LIBS
CPPFLAGS=$save_CPPFLAGS

##############################################################################
# Check for libctl library and files

save_LIBS=$LIBS
save_CPPFLAGS=$CPPFLAGS
LIBS="$GUILE_LIBS $LIBS"
CPPFLAGS="$CPPFLAGS $GUILE_CPPFLAGS"

AC_MSG_CHECKING([for libctl dir])
if test x != x"$LIBCTL_DIR" -a -r "$LIBCTL_DIR/share/libctl/base/ctl.scm"; then
	LIBCTL_DIR="$LIBCTL_DIR/share/libctl"
fi
if test x != x"$LIBCTL_DIR" -a ! -r "$LIBCTL_DIR/base/ctl.scm"; then
	LIBCTL_DIR=""
fi
if test x = x"$LIBCTL_DIR" -a -r /usr/local/share/libctl/base/ctl.scm; then
	LIBCTL_DIR="/usr/local/share/libctl"
fi
if test x = x"$LIBCTL_DIR" -a -r /usr/share/libctl3/base/ctl.scm; then
        LIBCTL_DIR="/usr/share/libctl3"
fi
if test x = x"$LIBCTL_DIR" -a -r /usr/share/libctl/base/ctl.scm; then
        LIBCTL_DIR="/usr/share/libctl"
fi
if test x = x"$LIBCTL_DIR"; then
	AC_MSG_ERROR([could not find libctl files; use --with-libctl=<dir>])
fi
AC_MSG_RESULT($LIBCTL_DIR)
AC_SUBST(LIBCTL_DIR)

AC_CHECK_PROGS(GEN_CTL_IO, gen-ctl-io, echo)
if test x"$GEN_CTL_IO" = xecho; then
	AC_MSG_ERROR([could not find gen-ctl-io program; check your PATH])
fi

# check for -lctl:
AC_CHECK_LIB(ctl, ctl_get_vector3, [], [AC_MSG_ERROR([Couldn't find the required libctl library.])])

# check for ctl.h (Fedora puts it in /usr/include/ctl, grrr)
CTL_H_CPPFLAG=""
AC_CHECK_HEADER(ctl.h, [CTL_H_CPPFLAG=" "], [
  save_CPPFLAGS=$CPPFLAGS
  AC_MSG_CHECKING([for alternate ctl.h location])
  for ctl_h_path in /usr/include/ctl /usr/local/include/ctl; do
     CPPFLAGS="$save_CPPFLAGS -I$ctl_h_path"
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <ctl.h>]],[])], [CTL_H_CPPFLAG=-I$ctl_h_path; break])
  done
  AC_MSG_RESULT([$CTL_H_CPPFLAG])
  CPPFLAGS=$save_CPPFLAGS])
if test "x$CTL_H_CPPFLAG" = "x"; then
  AC_MSG_ERROR([Couldn't find the ctl.h header file for libctl.])
fi
AC_SUBST(CTL_H_CPPFLAG)

save_CPPFLAGS=$CPPFLAGS
CPPFLAGS="$CPPFLAGS $CTL_H_CPPFLAG"
# Check libctl version >= LIBCTL_MAJOR.LIBCTL_MINOR.LIBCTL_BUGFIX
LIBCTL_MAJOR=4; LIBCTL_MINOR=2; LIBCTL_BUGFIX=0
AC_MSG_CHECKING([whether libctl version is at least ${LIBCTL_MAJOR}.${LIBCTL_MINOR}.${LIBCTL_BUGFIX}])
AC_EGREP_CPP(yes, [[
#include <ctl.h>
#if LIBCTL_MAJOR_VERSION > $LIBCTL_MAJOR || (LIBCTL_MAJOR_VERSION == $LIBCTL_MAJOR && (LIBCTL_MINOR_VERSION > $LIBCTL_MINOR || (LIBCTL_MINOR_VERSION == $LIBCTL_MINOR && LIBCTL_BUGFIX_VERSION >= $LIBCTL_BUGFIX)))
  yes
#endif
]], [AC_MSG_RESULT(ok)], [AC_MSG_ERROR([libctl version ${LIBCTL_MAJOR}.${LIBCTL_MINOR}.${LIBCTL_BUGFIX} or later is required])])
CPPFLAGS=$save_CPPFLAGS

# Check for libctl_quiet feature (in libctl 3.1.1 or later):
AC_MSG_CHECKING([for libctl_quiet feature])
if grep libctl_quiet "$LIBCTL_DIR/base/main.c" 2>&1 > /dev/null; then
   AC_MSG_RESULT(yes)
   AC_DEFINE([HAVE_LIBCTL_QUIET], [1], [If we have the libctl_quiet variable])
else
   AC_MSG_RESULT(no)
fi

LIBS=$save_LIBS
CPPFLAGS=$save_CPPFLAGS

LIBCTL_LIBS="-lctl $GUILE_LIBS"
LIBCTL_CPPFLAGS="$GUILE_CPPFLAGS"

fi # if with_libctl && with_scheme

##############################################################################

AC_SUBST(LIBCTL_LIBS)
AC_SUBST(LIBCTL_CPPFLAGS)

##############################################################################

# check for -lctlgeom:
AC_CHECK_LIB(ctlgeom, vector3_dot, [have_libctlgeom=yes; LIBS="-lctlgeom $LIBS"], [have_libctlgeom=no])
AM_CONDITIONAL(WITH_LIBCTLGEOM, test x"$have_libctlgeom" = "xyes")
# check for ctl_printf_callback
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <ctlgeom.h>]], [ctl_printf_callback = 0;])],
  AC_DEFINE([HAVE_CTL_PRINTF_CALLBACK], [1], [If we have the ctl_printf_callback variable]))

##############################################################################
# check for libGDSII
AC_CHECK_HEADER(libGDSII.h, [have_gdsii=maybe], [have_gdsii=no])
if test "x$have_gdsii" = xmaybe; then
  AC_CHECK_LIB(GDSII, libGDSIIExists)
  if test "x$ac_cv_lib_GDSII_libGDSIIExists" = xyes; then
    AC_MSG_CHECKING([for libGDSII::GetLayers])
    have_gdsii_getlayers=no
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <libGDSII.h>]], [libGDSII::GetLayers("foo")])],
      [have_gdsii_getlayers=yes
       AC_DEFINE([HAVE_GDSII_GETLAYERS], [1], [If we have libGDSII::GetLayers])])
    AC_MSG_RESULT($have_gdsii_getlayers)
  fi
fi

LIBCTL_LIBS=$LIBS
AC_SUBST(LIBCTL_LIBS)
LIBS=$libbessels_save_LIBS

##################################################
# Checks for header files.
dnl m4_warn([obsolete],
dnl [The preprocessor macro `STDC_HEADERS' is obsolete.
dnl   Except in unusual embedded environments, you can safely include all
dnl   ISO C90 headers unconditionally.])dnl
# Autoupdate added the next two lines to ensure that your configure
# script's behavior did not change.  They are probably safe to remove.
# AC_CHECK_INCLUDES_DEFAULT
AC_PROG_EGREP

AC_CHECK_HEADERS([math.h complex.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([pow sqrt])

AC_CONFIG_FILES([Makefile bessel_wrap/Makefile bessel_wrap/toms644/Makefile guile/Makefile guile/include_libbessels.scm check/Makefile])

AC_OUTPUT
