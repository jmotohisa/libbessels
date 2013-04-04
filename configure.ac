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
AC_CHECK_PROGS(F77, f77 xlf77 cf77 fort77 f90 xlf90 gfortran)
AC_PROG_F77
AC_F77_LIBRARY_LDFLAGS

AC_PROG_INSTALL
AC_PROG_RANLIB

# Checks for libraries.
AM_PROG_LIBTOOL

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

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([math.h complex.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([pow sqrt])

AC_CONFIG_FILES([Makefile bessel_wrap/Makefile bessel_wrap/toms644/Makefile])

AC_OUTPUT
