# noinst_PROGRAMS = check1
# check1_SOURCES = check1.c \
# 	../dbessel.c \
# 	../bessel_wrap/toms644_wrap.c ../bessel_wrap/hankel_gsl_wrap.c \
# 	../bessel_wrap/toms644/cbsubs.f ../bessel_wrap/toms644/zbsubs.f \
# 	../bessel_wrap/toms644/machcon.f ../bessel_wrap/toms644/xerror.f
# check1_LDADD = $(FLIBS)

# MY_SOURCES = check1.c \
# 	../dbessel.c \
# 	../bessel_wrap/toms644_wrap.c ../bessel_wrap/hankel_gsl_wrap.c \
# 	../bessel_wrap/toms644/cbsubs.f ../bessel_wrap/toms644/zbsubs.f \
# 	../bessel_wrap/toms644/machcon.f ../bessel_wrap/toms644/xerror.f

# MY_LIBS    =         # extra libs you need go here
# MY_LDFLAGS =         # extra -L flags go here
# MY_CPPFLAGS =        # extra -I include flags go here
# MY_DEFS =            # extra -D define flags go here
# MY_CFLAGS = -Wall -gdwarf-2
# MY_FFLAGS = -Wall -gdwarf-2 -fno-second-underscore

# CHECK1_SOURCES = $(MY_SOURCES)
# # nodist_CHECK1_SOURCES = main.c ctl-io.h ctl-io.c
# # BUILT_SOURCES = $(nodist_CHECK1_SOURCES)
# CHECK1_LDADD = $(MY_LIBS)
# CHECK1_LDFLAGS = $(MY_LDFLAGS)
# CHECK1_CFLAGS = $(CFLAGS) $(MY_CFLAGS)
# CHECK1_CPPFLAGS = $(MY_CPPFLAGS) $(MY_DEFS)
# CHECK1_FFLAGS = $(MY_FFLAGS)

#####
CHECK1_OBJECTS = check1.o \
	../dbessel.o \
	../bessel_wrap/toms644_wrap.o ../bessel_wrap/hankel_gsl_wrap.o \
	../bessel_wrap/toms644/cbsubs.o ../bessel_wrap/toms644/zbsubs.o  ../bessel_wrap/toms644/xerror.o \
        ../bessel_wrap/toms644/i1mach.o ../bessel_wrap/toms644/r1mach.o ../bessel_wrap/toms644/d1mach.o 
####

check1: $(CHECK1_OBJECTS)
	$(F77) $(LDFLGAS) $(CFLAGS) $(CHECK1_OBJECTS) $(LIBS) -o $@

.c.o: $(HEADERS) ctl-io.h
	$(CC) -c $(DEFS) $(CPPFLAGS) $(CFLAGS) $< -o $@

.f.o: $(FHEADERS)
	$(F77) -c $(FDEFS) $(FFLAGS) $<

