// Hankel functions
// with gsl

#include <complex.h>
#include <gsl/gsl_sf_bessel.h>

#define GLOBAL_VALUE_DEFINE
#include "hankel_gsl_wrap.h"

// double argument, double Complex results
ZComplex z0Bessel_H1n(int n, double x)
{
  return(cmplx(gsl_sf_bessel_Jn(n,x),gsl_sf_bessel_Yn(n,x)));
}

ZComplex z0Bessel_H2n(int n, double x)
{
  return(cmplx(gsl_sf_bessel_Jn(n,x),-gsl_sf_bessel_Yn(n,x)));
}
