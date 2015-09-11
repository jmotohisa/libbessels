// guileextensions.c

#include <complex.h>
#include <tgmath.h>
#include <gsl/gsl_sf_bessel.h>
#include <libguile.h>
#include <stdio.h>
#include <stdlib.h>
#include "../bessel_wrap/gsl_bessel_wrap.h"
#include "../bessel_wrap/hankel_gsl_wrap.h"
#include "../bessel_wrap/toms644_wrap.h"
#include "../dbessel.h"

#define MAXLEN 100

// for GSL function (double input, integer order, double ouput)
#define GSL_BESSEL_DND_WRAPPER(J)										\
  SCM																	\
  Bessel_##J##n_guile_wrapper (SCM n, SCM x)							\
  {																		\
	return scm_from_double (gsl_sf_bessel_##J##n (scm_to_int(n),scm_to_double (x))); \
  }

// for GSL function (double input, integer order, double ouput)
#define BESSEL_DND_WRAPPER(FUNC)										\
  SCM																	\
  FUNC##_guile_wrapper (SCM n, SCM x)									\
  {																		\
	return scm_from_double (FUNC(scm_to_int(n),scm_to_double (x)));		\
  }

// for doube input, integer order, double complex output
#define BESSEL_ZND_WRAPPER(FUNC)										\
  SCM																	\
  FUNC##_guile_wrapper (SCM n, SCM x)									\
  {																		\
	double _Complex zout;												\
	zout= FUNC(scm_to_int(n),scm_to_double(x));							\
	return scm_from_complex (creal(zout),cimag(zout));					\
  }

// for doube complex input, integer order, double complex output
#define BESSEL_ZNZ_WRAPPER(FUNC)				\
  SCM											\
  FUNC##_guile_wrapper (SCM n, SCM x)									\
  {																		\
	double _Complex zin,zout;											\
	zin=scm_c_real_part(x)+I*scm_c_imag_part(x);						\
	zout= FUNC(scm_to_int(n),zin);										\
	return scm_from_complex (creal(zout),cimag(zout));					\
  }

#define EXPORT_FUNC(func,i)										\
  snprintf(funcname,sizeof(funcname),"%s",#func);				\
  scm_c_define_gsubr (funcname, i, 0, 0, func##_guile_wrapper); \
  scm_c_export(funcname, NULL);

/* SCM */
/* BesselJn_guile_wrapper (SCM n, SCM x) */
/* { */
/*   return scm_from_double (gsl_sf_bessel_Jn (scm_to_int(n),scm_to_double (x))); */
/* } */

GSL_BESSEL_DND_WRAPPER(J);
GSL_BESSEL_DND_WRAPPER(Y);
// GSL_BESSEL_WRAPPER(I);

SCM
Bessel_In_guile_wrapper (SCM n, SCM x)
{
  return scm_from_double (gsl_sf_bessel_In (scm_to_int(n),scm_to_double (x)));
}

GSL_BESSEL_DND_WRAPPER(K);
BESSEL_ZND_WRAPPER(z0Bessel_H1n);
BESSEL_ZND_WRAPPER(z0Bessel_H2n);

BESSEL_DND_WRAPPER(dBessel_Jn);
BESSEL_DND_WRAPPER(dBessel_Yn);
BESSEL_DND_WRAPPER(dBessel_In);
BESSEL_DND_WRAPPER(dBessel_Kn);
BESSEL_ZND_WRAPPER(dz0Bessel_H1n);
BESSEL_ZND_WRAPPER(dz0Bessel_H2n);
				   
BESSEL_ZNZ_WRAPPER(zBessel_Jn);
BESSEL_ZNZ_WRAPPER(zBessel_Yn);
BESSEL_ZNZ_WRAPPER(zBessel_In);
BESSEL_ZNZ_WRAPPER(zBessel_Kn);
BESSEL_ZNZ_WRAPPER(zBessel_H1n);
BESSEL_ZNZ_WRAPPER(zBessel_H2n);

BESSEL_ZNZ_WRAPPER(dzBessel_Jn);
BESSEL_ZNZ_WRAPPER(dzBessel_Yn);
BESSEL_ZNZ_WRAPPER(dzBessel_In);
BESSEL_ZNZ_WRAPPER(dzBessel_Kn);
BESSEL_ZNZ_WRAPPER(dzBessel_H1n);
BESSEL_ZNZ_WRAPPER(dzBessel_H2n);

void
init_math_bessel ()
{
  char funcname[MAXLEN];
  /* scm_c_define_gsubr ("BesselJn", 2, 0, 0, BesselJn_guile_wrapper); */
  /* scm_c_export("BesselJn", NULL); */
  EXPORT_FUNC(Bessel_Jn,2);
  EXPORT_FUNC(Bessel_Yn,2);
  EXPORT_FUNC(Bessel_In,2);
  EXPORT_FUNC(Bessel_Kn,2);
  EXPORT_FUNC(z0Bessel_H1n,2);
  EXPORT_FUNC(z0Bessel_H2n,2);

  EXPORT_FUNC(zBessel_Jn,2);
  EXPORT_FUNC(zBessel_Yn,2);
  EXPORT_FUNC(zBessel_In,2);
  EXPORT_FUNC(zBessel_Kn,2);
  EXPORT_FUNC(zBessel_H1n,2);
  EXPORT_FUNC(zBessel_H2n,2);

  EXPORT_FUNC(dBessel_Jn,2);
  EXPORT_FUNC(dBessel_Yn,2);
  EXPORT_FUNC(dBessel_In,2);
  EXPORT_FUNC(dBessel_Kn,2);
  EXPORT_FUNC(dz0Bessel_H1n,2);
  EXPORT_FUNC(dz0Bessel_H2n,2);

  EXPORT_FUNC(dzBessel_Jn,2);
  EXPORT_FUNC(dzBessel_Yn,2);
  EXPORT_FUNC(dzBessel_In,2);
  EXPORT_FUNC(dzBessel_Kn,2);
  EXPORT_FUNC(dzBessel_H1n,2);
  EXPORT_FUNC(dzBessel_H2n,2);
}

void
scm_init_math_bessel_module ()
{
  scm_c_define_module ("math bessel", init_math_bessel, NULL);
}

