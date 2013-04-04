ACLOCAL_AMFLAGS=-I m4

SUBDIRS = bessel_wrap

#noinst_LIBRARIES = libbessels.a
lib_LIBRARIES = libbessels.a

libbessels_a_SOURCES = dbessel.c
# dbessel.h

#libbessels_a_LDADD = ./bessel_wrap/libbesselwrap.a ./bessel_wrap/toms644/libtoms644.a
libbessels_a_LIBADD = ./bessel_wrap/toms644_wrap.o ./bessel_wrap/hankel_gsl_wrap.o \
./bessel_wrap/toms644/cbsubs.o ./bessel_wrap/toms644/machcon.o ./bessel_wrap/toms644/zbsubs.o ./bessel_wrap/toms644/xerror.o 
# $(FLIBS)

# nobase_include_HEADERS = libbessels.h dbessel.h
include_HEADERS = libbessels.h

libbesselsdir = $(includedir)/libbessels
libbessels_HEADERS = dbessel.h

# EXTRA_DIST = COPYRIGHT TODO m4
