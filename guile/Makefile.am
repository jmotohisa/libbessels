lib_LTLIBRARIES = libbessels_guileext.la

libbessels_guileext_la_SOURCES = guileextensions.c
#../dbessels.c
#          ../bessel_wrap/toms644_wrap.c ../bessel_wrap/hankel_gsl_wrap.c \
#          ../bessel_wrap/toms644/cbsubs.f ../bessel_wrap/toms644/zbsubs.f \
#          ../bessel_wrap/toms644/machcon.f ../bessel_wrap/toms644/xerror.f
libbessels_guileext_la_LIBADD = ../libbessels.la  # $(FLIBS)
pkgdata_DATA = include_libbessels.scm
