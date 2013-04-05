SUBDIRS = bessel_wrap

lib_LTLIBRARIES = libbessels.la
libbessels_la_SOURCES = dbessel.c \
          bessel_wrap/toms644_wrap.c bessel_wrap/hankel_gsl_wrap.c \
          bessel_wrap/toms644/cbsubs.f bessel_wrap/toms644/zbsubs.f \
          bessel_wrap/toms644/machcon.f bessel_wrap/toms644/xerror.f
libbessels_la_LIBADD = $(FLIBS)

include_HEADERS = libbessels.h
libbesselsdir = $(includedir)/libbessels
libbessels_HEADERS = dbessel.h

