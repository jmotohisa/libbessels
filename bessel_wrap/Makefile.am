SUBDIRS = toms644

# for static libraries
# noinst_LIBRARIES = libbesselwrap.a
# libbesselwrap_a_SOURCES = toms644_wrap.c hankel_gsl_wrap.c
## gsl_bessel_wrap.h hankel_gsl_wrap.h toms644_wrap.h

# for shared (dynamic ?) libraries
# noinst_LTLIBRARIES = libbesselwrap.la
lib_LTLIBRARIES = libbesselwrap.la
libbesselwrap_la_SOURCES = toms644_wrap.c hankel_gsl_wrap.c

#nobase_include_HEADERS = libbessels/gsl_bessel_wrap.h libbessels/hankel_gsl_wrap.h libbessels/toms644_wrap.h
#nobase_include_HEADERS = gsl_bessel_wrap.h hankel_gsl_wrap.h toms644_wrap.h

libbesselsdir = $(includedir)/libbessels
libbessels_HEADERS = gsl_bessel_wrap.h hankel_gsl_wrap.h toms644_wrap.h
