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
double dBessel_Jn(int m, double z)
{
  if(m==0)
	return( - Bessel_Jn(1,z));
  else
	return((Bessel_Jn(m-1,z)-Bessel_Jn(m+1,z))/2.);
}

double dBessel_Yn(int m, double z)
{
  if(m==0)
	return( - Bessel_Yn(1,z)); 
  else
	return((Bessel_Yn(m-1,z)-Bessel_Yn(m+1,z))/2.);
}

double dBessel_Kn(int m, double z)
{
  if(m==0)
	return( - Bessel_Kn(1,z));
  else
	return((-Bessel_Kn(m-1,z)-Bessel_Kn(m+1,z))/2.);
}

double dBessel_In(int m, double z)
{
  if(m==0)
	return( Bessel_In(1,z));
  else
	return(( Bessel_In(m-1,z) + Bessel_In(m+1,z))/2.);
}

// Hankel Functions: argunemt : double, result: double Complex
double _Complex dz0Bessel_H1n(int m, double z)
{
  if(m==0)
	return( - z0Bessel_H1n(1,z)); 
  else
	return((z0Bessel_H1n(m-1,z)-z0Bessel_H1n(m+1,z))/2.);
}

double _Complex dz0Bessel_H2n(int m, double z)
{
  if(m==0)
	return( - z0Bessel_H2n(1,z)); 
  else
	return((z0Bessel_H2n(m-1,z)-z0Bessel_H2n(m+1,z))/2.);
}

// 
// double complex
// double
double _Complex dzBessel_Jn(int m, double _Complex z)
{
  if(m==0)
	return( - zBessel_Jn(1,z));
  else
	return((zBessel_Jn(m-1,z)-zBessel_Jn(m+1,z))/2.);
}

double _Complex dzBessel_Yn(int m, double _Complex z)
{
  if(m==0)
	return( - zBessel_Yn(1,z)); 
  else
	return((zBessel_Yn(m-1,z)-zBessel_Yn(m+1,z))/2.);
}

double _Complex dzBessel_Kn(int m, double _Complex z)
{
  if(m==0)
	return( - zBessel_Kn(1,z));
  else
	return((-zBessel_Kn(m-1,z)-zBessel_Kn(m+1,z))/2.);
}

double _Complex dzBessel_In(int m, double _Complex z)
{
  if(m==0)
	return( zBessel_In(1,z));
  else
	return(( zBessel_In(m-1,z) + zBessel_In(m+1,z))/2.);
}

double _Complex dzBessel_H1n(int m, double _Complex z)
{
  if(m==0)
	return( - zBessel_H1n(1,z)); 
  else
	return(( zBessel_H1n(m-1,z)-zBessel_H1n(m+1,z))/2.);
}

double _Complex dzBessel_H2n(int m, double _Complex z)
{
  if(m==0)
	return( - zBessel_H2n(1,z)); 
  else
	return(( zBessel_H2n(m-1,z)-zBessel_H2n(m+1,z))/2.);
}
