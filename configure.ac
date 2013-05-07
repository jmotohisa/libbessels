#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(libbessels, 0.1a, motohisa@ist.hokudai.ac.jp)
AC_CONFIG_SRCDIR([bessel_wrap/toms644/zbsubs.f])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_CHECK_PROGS(F77, f77 xlf77 cf77 fort77 f90 xlf90 gfortran g95)
AC_PROG_F77
# AC_F77_LIBRARY_LDFLAGS

AC_PROG_INSTALL
AC_PROG_RANLIB

# Checks for libraries.
AM_PROG_LIBTOOL

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

# AC_CHECK_FUNC(cblas_cgemm, [], [AC_CHECK_LIB(gslcblas, cblas_cgemm)])

AC_CHECK_LIB(gsl, gsl_sf_bessel_Jn, [],
	[AC_MSG_ERROR([GNU GSL library does not exist.])])
# Find Guile library, flags, etcetera:

AC_CHECK_PROG(GUILE, guile, guile, unknown)
if test x"$guile_ok" = xunknown; then
	AC_MSG_ERROR([could not find guile program; check your PATH])
fi
AC_SUBST(GUILE)

AC_CHECK_PROG(GUILE_CONFIG, guile-config, guile-config, unknown)
if test "x$GUILE_CONFIG" = "xunknown"; then
	AC_CHECK_LIB(m, sqrt)
	AC_CHECK_LIB(readline, readline)
	AC_CHECK_LIB(dl, dlopen)
	AC_CHECK_LIB(guile, gh_eval_str)
else
	CPPFLAGS="$CPPFLAGS `$GUILE_CONFIG compile`"
	LIBS="$LIBS `$GUILE_CONFIG link`"
fi

AC_MSG_CHECKING([if linking to guile works])
AC_TRY_LINK_FUNC(gh_enter, AC_MSG_RESULT(yes), [
AC_MSG_RESULT(no)
AC_MSG_ERROR(Guile could not be found)
])

###########################################################################
# Checks for Guile features:

AC_MSG_CHECKING([for gh_load])
ok=yes
AC_TRY_LINK([#include <guile/gh.h>
], [gh_load(0);], [AC_DEFINE(HAVE_GH_LOAD, 1, [Define if we have gh_load.])], ok=no)
AC_MSG_RESULT($ok)

AC_MSG_CHECKING([for gh_bool2scm])
ok=yes
AC_TRY_LINK([#include <guile/gh.h>
], [gh_bool2scm(0);], [AC_DEFINE(HAVE_GH_BOOL2SCM, 1, [Define if we have gh_bool2scm])], ok=no)
AC_MSG_RESULT($ok)

AC_MSG_CHECKING([for gh_vector_ref])
ok=yes
AC_TRY_LINK([#include <guile/gh.h>
], [gh_vector_ref(0,0);], [AC_DEFINE(HAVE_GH_VECTOR_REF, 1, [Define if we have gh_vector_ref])], ok=no)
AC_MSG_RESULT($ok)

AC_MSG_CHECKING([for gh_list_ref])
ok=yes
AC_TRY_LINK([#include <guile/gh.h>
], [gh_list_ref(0,0);], [AC_DEFINE(HAVE_GH_LIST_REF, 1, [Define if we have gh_list_ref])], ok=no)
AC_MSG_RESULT($ok)

AC_MSG_CHECKING([for gh_length])
ok=yes
AC_TRY_LINK([#include <guile/gh.h>
], [gh_length(0);], [AC_DEFINE(HAVE_GH_LENGTH, 1, [Define if we have gh_length])], ok=no)
AC_MSG_RESULT($ok)

AC_MSG_CHECKING([for scm_flush_all_ports])
ok=yes
AC_TRY_LINK([#include <guile/gh.h>
], [scm_flush_all_ports();], [AC_DEFINE(HAVE_SCM_FLUSH_ALL_PORTS, 1, [Define if we have scm_flush_all_ports])], ok=no)
AC_MSG_RESULT($ok)

AC_CHECK_FUNCS(scm_make_complex scm_variable_set_x scm_c_lookup scm_c_make_vector)

AC_MSG_CHECKING([for SCM_COMPLEXP])
ok=yes
AC_TRY_LINK([#include <guile/gh.h>
], [SCM x; SCM_COMPLEXP(x);], [AC_DEFINE(HAVE_SCM_COMPLEXP, 1, [Define if we have SCM_COMPLEXP])], ok=no)
AC_MSG_RESULT($ok)

AC_MSG_CHECKING([whether gh_lookup works properly])
ok=yes
AC_TRY_RUN([
#include <stdlib.h>
#include <guile/gh.h>
void main_entry(int argc, char *argv[])
{
     gh_eval_str("(define foo 3.14159)");
     if (SCM_UNDEFINED == gh_lookup("foo"))
          exit(EXIT_FAILURE);
}
int main (int argc, char *argv[])
{
     gh_enter (argc, argv, main_entry);
     return EXIT_SUCCESS;
}
], [AC_DEFINE(GH_LOOKUP_OK, 1, [Define if gh_lookup works])], ok=no, ok=no)
AC_MSG_RESULT($ok)

##################################################
# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([math.h complex.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([pow sqrt])

AC_CONFIG_FILES([Makefile bessel_wrap/Makefile bessel_wrap/toms644/Makefile guile/Makefile guile/include_libbessels.scm check/Makefile])

AC_OUTPUT
