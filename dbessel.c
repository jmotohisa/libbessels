/*
  Derivative of bessel functions
  requires: GSL, TOMS644 libs

  based on
     dbessel.f in md-libctl project
     dbessel.ipf of Igor Procedures
	 mybessel progject in Fortran Subs

  revision history
  2013/04/03: ver 0.02: diretory organization changed, use with warpper libraries
  for bessel functions and bessel functions with complex argument
  2012/12/02: ver 0.01: converted from f and ipf version
  
c derivative of bessel function
*/

#include <math.h>
#include <complex.h>
#include <gsl/gsl_sf_bessel.h>
#include "bessel_wrap/gsl_bessel_wrap.h"
#include "bessel_wrap/toms644_wrap.h"
/* #include <gsl/gsl_math.h> */
/* #include <gsl/gsl_const_mksa.h> */
/* #include <gsl/gsl_sf_bessel.h> */
#include "dbessel.h"

// double
double dBesselj_n(int m, double z)
{
  if(m==0)
	return( - Besselj_n(1,z));
  else
	return((Besselj_n(m-1,z)-Besselj_n(m+1,z))/2.);
}

double dBessely_n(int m, double z)
{
  if(m==0)
	return( - Bessely_n(1,z)); 
  else
	return((Bessely_n(m-1,z)-Bessely_n(m+1,z))/2.);
}

double dBesselk_n(int m, double z)
{
  if(m==0)
	return( - Besselk_n(1,z));
  else
	return((-Besselk_n(m-1,z)-Besselk_n(m+1,z))/2.);
}

double dBesseli_n(int m, double z)
{
  if(m==0)
	return( Besseli_n(1,z));
  else
	return(( Besseli_n(m-1,z) + Besseli_n(m+1,z))/2.);
}

// Hankel Functions: argunemt : double, result: double Complex
ZComplex dz0Besselh1_n(int m, double z)
{
  if(m==0)
	return( - z0Besselh1_n(1,z)); 
  else
	return((z0Besselh1_n(m-1,z)-z0Besselh1_n(m+1,z))/2.);
}

ZComplex dz0Besselh2_n(int m, double z)
{
  if(m==0)
	return( - z0Besselh2_n(1,z)); 
  else
	return((z0Besselh2_n(m-1,z)-z0Besselh2_n(m+1,z))/2.);
}

// 
// double complex
// double
ZComplex dzBesselj_n(int m, ZComplex z)
{
  if(m==0)
	return( - zBesselj_n(1,z));
  else
	return((zBesselj_n(m-1,z)-zBesselj_n(m+1,z))/2.);
}

ZComplex dzBessely_n(int m, ZComplex z)
{
  if(m==0)
	return( - zBessely_n(1,z)); 
  else
	return((zBessely_n(m-1,z)-zBessely_n(m+1,z))/2.);
}

ZComplex dzBesselk_n(int m, ZComplex z)
{
  if(m==0)
	return( - zBesselk_n(1,z));
  else
	return((-zBesselk_n(m-1,z)-zBesselk_n(m+1,z))/2.);
}

ZComplex dzBesseli_n(int m, ZComplex z)
{
  if(m==0)
	return( zBesseli_n(1,z));
  else
	return(( zBesseli_n(m-1,z) + zBesseli_n(m+1,z))/2.);
}

ZComplex dzBesselh1_n(int m, ZComplex z)
{
  if(m==0)
	return( - zBesselh1_n(1,z)); 
  else
	return(( zBesselh1_n(m-1,z)-zBesselh1_n(m+1,z))/2.);
}

ZComplex dzBesselh2_n(int m, ZComplex z)
{
  if(m==0)
	return( - zBesselh2_n(1,z)); 
  else
	return(( zBesselh2_n(m-1,z)-zBesselh2_n(m+1,z))/2.);
}


