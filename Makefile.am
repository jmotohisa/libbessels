SUBDIRS = bessel_wrap guile check

lib_LTLIBRARIES = libbessels.la
libbessels_la_SOURCES = dbessel.c \
          bessel_wrap/toms644_wrap.c bessel_wrap/hankel_gsl_wrap.c \
          bessel_wrap/toms644/cbsubs.f bessel_wrap/toms644/zbsubs.f bessel_wrap/toms644/xerror.f \
          bessel_wrap/toms644/i1mach.f bessel_wrap/toms644/r1mach.f bessel_wrap/toms644/d1mach.f 
libbessels_la_LIBADD = $(FLIBS)

include_HEADERS = libbessels.h
libbesselsdir = $(includedir)/libbessels
libbessels_HEADERS = dbessel.h

# noinst_LIBRARIES = libbessels.a
# libbessels_a_SOURCES = dbessel.c \
#           bessel_wrap/toms644_wrap.c bessel_wrap/hankel_gsl_wrap.c \
#           bessel_wrap/toms644/cbsubs.f bessel_wrap/toms644/zbsubs.f \
#           bessel_wrap/toms644/machcon.f bessel_wrap/toms644/xerror.f
# # libbessels_a_LIBADD = $(FLIBS)
