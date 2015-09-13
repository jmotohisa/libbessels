// Hankel functions
// with gsl

#include <complex.h>
#include <gsl/gsl_sf_bessel.h>

#define GLOBAL_VALUE_DEFINE
#include "hankel_gsl_wrap.h"

// double argument, double Complex results
double _Complex z0Bessel_H1n(int n, double x)
{
  return(gsl_sf_bessel_Jn(n,x)+I*gsl_sf_bessel_Yn(n,x));
}

double _Complex z0Bessel_H2n(int n, double x)
{
  return(gsl_sf_bessel_Jn(n,x)-I*gsl_sf_bessel_Yn(n,x));
}
