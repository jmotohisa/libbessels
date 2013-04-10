// gsl_bessel_wrap.h

#ifndef _GSL_BESSEL_WRAP_H
#define _GSL_BESSEL_WRAP_H

#ifdef __GSL_SF_BESSEL_H__
#define Bessel_Jn(n,x) gsl_sf_bessel_Jn(n,x)
#define Bessel_Yn(n,x) gsl_sf_bessel_Yn(n,x)
#define Bessel_In(n,x) gsl_sf_bessel_In(n,x)
#define Bessel_Kn(n,x) gsl_sf_bessel_Kn(n,x)
#endif

#endif
