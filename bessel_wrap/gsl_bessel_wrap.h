// gsl_bessel_wrap.h

#ifndef _GSL_BESSEL_WRAP_H
#define _GSL_BESSEL_WRAP_H

#ifdef __GSL_SF_BESSEL_H__
#define Besselj_n(n,x) gsl_sf_bessel_Jn(n,x)
#define Bessely_n(n,x) gsl_sf_bessel_Yn(n,x)
#define Besseli_n(n,x) gsl_sf_bessel_In(n,x)
#define Besselk_n(n,x) gsl_sf_bessel_Kn(n,x)
#endif

#endif
