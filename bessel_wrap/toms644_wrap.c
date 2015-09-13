/* toms644_wrap.c */

/* Warpper library TOMS 644 Complex Bessel library 
     Complex Bessel Functions J_nue(z)/Y_nue(z)/I_nue(z)/K_nue(z)/H_nue^{1}(z)/H_nue^{2}
	 with complex argurment z
	 with non-negative nue
 */

#include <complex.h>
#include <math.h>

#define GLOBAL_VALUE_DEFINE
#include "toms644_wrap.h"

#define FUNC_CBESSEL_N(j,J)					\
  _Complex cBessel_##J##n(int n, _Complex z)	\
  {												\
  int nn,kode=1;								\
  _Complex cy; 									\
  int nz=0;										\
  float fnu;									\
  int ierr;									\
  fnu=n;										\
  cbes##j##_(&z, &fnu, &kode, &nn, &cy, &nz, &ierr);	\
  return(cy);										\
}

#define FUNC_CBESSEL(j,J)						\
  _Complex cBessel_##J(float fnu, _Complex z)		\
  {												\
	int nn=1,kode=1;							\
	_Complex cy;									\
	int nz=0;										\
	int ierr;										\
	cbes##j##_(&z, &fnu, &kode, &nn, &cy, &nz, &ierr);	\
	return(cy);											\
  }

#define FUNC_CBESSELH_N(i)							\
  _Complex cBessel_H##i##n(int n, _Complex z)		\
  {												\
	int nn=1,kode=1,m;							\
	_Complex cy;									\
	int nz=0;									\
	float fnu;									\
	int ierr;									\
	m=i;											\
	fnu=n;												\
	cbesh_(&z, &fnu, &kode, &m, &nn, &cy, &nz, &ierr);	\
	return(cy);											\
  }

#define FUNC_CBESSELH(i)						\
  _Complex cBessel_H##i(float fnu, _Complex z)		\
  {												\
	int nn=1,kode=1,m=i;							\
	_Complex cy;										\
	int nz=0;											\
	int ierr;											\
	cbesh_(&z, &fnu, &kode, &m,&nn, &cy, &nz, &ierr);	\
	return(cy);											\
  }

#define FUNC_ZBESSEL_N(j,J)											\
  double _Complex zBessel_##J##n(int n, double _Complex z)			\
  {																	\
	int nn=1,kode=1;												\
	double _Complex cyr;											\
	int nz=0;														\
	double fnu;															\
	int ierr;															\
	double z0re,z0im,cyr0re,cyr0im;										\
	fnu=n;																\
	z0re=creal(z);														\
	z0im=cimag(z);														\
	zbes##j##_(&z0re, &z0im, &fnu, &kode, &nn, &cyr0re, &cyr0im, &nz, &ierr); \
	  cyr=cyr0re+I*cyr0im;												\
	  return(cyr);														\
  }

#define FUNC_ZBESSEL(j,J)								\
  double _Complex zBessel_##J(double fnu, double _Complex z)			\
  {														\
	int nn=1,kode=1;									\
	double _Complex cyr;										\
	double z0re,z0im,cyr0re,cyr0im;										\
    int ierr;											\
	int nz=0;															\
	z0re=creal(z);														\
	z0im=cimag(z);														\
	zbes##j##_(&z0re, &z0im, &fnu, &kode, &nn, &cyr0re, &cyr0im, &nz, &ierr); \
	  cyr=cyr0re+I*cyr0im;												\
	return(cyr);														\
  }

#define FUNC_ZBESSELH_N(i)									\
  double _Complex zBessel_H##i##n(int n, double _Complex z)				\
  {															\
	int nn=1,kode=1,m=i;									\
	double _Complex cyr;											\
	int nz=0;												\
    int ierr;												\
	double fnu;														\
	double z0re,z0im,cyr0re,cyr0im;										\
	fnu=n;															\
	z0re=creal(z);														\
	z0im=cimag(z);														\
	zbesh_(&z0re, &z0im, &fnu, &kode, &m, &nn, &cyr0re, &cyr0im, &nz, &ierr); \
	cyr=cyr0re+I*cyr0im;													\
	return(cyr);														\
  }

#define FUNC_ZBESSELH(i)									\
  double _Complex zBessel_H##i(double fnu, double _Complex z)				\
  {															\
	int nn=1,kode=1,m=i;										\
	double _Complex cyr;												\
    int ierr;														\
	int nz=0;															\
	double z0re,z0im,cyr0re,cyr0im;											\
	int n;																\
	fnu=n;															\
	z0re=creal(z);														\
	z0im=cimag(z);														\
	zbesh_(&z0re, &z0im, &fnu, &kode, &m, &nn, &cyr0re, &cyr0im, &nz, &ierr); \
	cyr=cyr0re+I*cyr0im;													\
	return(cyr);														\
  }

FUNC_CBESSELH_N(1);
FUNC_CBESSELH_N(2);
FUNC_CBESSELH(1);
FUNC_CBESSELH(2);

FUNC_CBESSEL_N(j,J);
//FUNC_CBESSEL_N(y,Y);
FUNC_CBESSEL_N(i,I);
FUNC_CBESSEL_N(k,K);

FUNC_CBESSEL(j,J);
//FUNC_CBESSEL(y,Y);
FUNC_CBESSEL(i,I);
FUNC_CBESSEL(k,K);

FUNC_ZBESSEL_N(j,J);
//FUNC_ZBESSEL_N(y,Y);
FUNC_ZBESSEL_N(i,I);
FUNC_ZBESSEL_N(k,K);

FUNC_ZBESSEL(j,J);
//FUNC_ZBESSEL(y,Y);
FUNC_ZBESSEL(i,I);
FUNC_ZBESSEL(k,K);

FUNC_ZBESSELH_N(1);
FUNC_ZBESSELH_N(2);
FUNC_ZBESSELH(1);
FUNC_ZBESSELH(2);

_Complex cAiry(_Complex z)
{
  int id=0;
  int kode=1,nz=0;
  int ierr;
  _Complex ai;
  cairy_(&z, &id, &kode, &ai, &nz, &ierr);
  return(ai);
}

_Complex cAirydz(_Complex z)
{
  int id=1;
  int kode=1,nz=0;
  int ierr;
  _Complex ai;
  cairy_(&z, &id, &kode, &ai, &nz, &ierr);
  return(ai);
}

_Complex cBiry(_Complex z)
{
  int id=0;
  int kode=1,nz=0;
  int ierr;
  _Complex ai;
  cbiry_(&z, &id, &kode, &ai, &ierr);
  return(ai);
}

_Complex cbirydz(_Complex z)
{
  int id=1;
  int kode=1,nz=0;
  int ierr;
  _Complex ai;
  cbiry_(&z, &id, &kode, &ai, &ierr);
  return(ai);
}

_Complex cBessel_Yn(int n, _Complex z)
{
  int nn=1,kode=1;
  _Complex cy,cwrk;
  int nz=0;
  int ierr;
  float fnu;
  fnu=n;
  cbesy_(&z, &fnu, &kode, &nn, &cy, &nz, &cwrk,&ierr);
  return(cy);
}

_Complex cBessel_Y(float fnu, _Complex z)
{
  int nn=1,kode=1;
  _Complex cy,cwrk;
  int ierr;
  int nz=0;
  cbesy_(&z, &fnu, &kode, &nn, &cy, &nz, &cwrk,&ierr);
  return(cy);
}

double _Complex zBessel_Yn(int n, double _Complex z)
{
  int nn=1,kode=1;
  double _Complex cyr;
  int nz=0;
  int ierr;
  double fnu;
  double z0re,z0im,cyr0re,cyr0im;
  double cwrkre,cwrkim;
  fnu=n;
  z0re=creal(z);
  z0im=cimag(z);
  zbesy_(&z0re, &z0im, &fnu, &kode, &nn, &cyr0re, &cyr0im, &nz, &cwrkre, &cwrkim, &ierr);
  cyr=(cyr0re+I*cyr0im);
  return(cyr);
}

double _Complex zBessel_Y(double fnu, double _Complex z)
{
  int nn=1,kode=1;
  double _Complex cyr;
  int nz=0;
  int ierr;
  double _Complex z0,cyr0;
  double z0re,z0im,cyr0re,cyr0im;
  double cwrkre,cwrkim;
  z0re=creal(z);\
  z0im=cimag(z);\
  zbesy_(&z0re, &z0im, &fnu, &kode, &nn, &cyr0re, &cyr0im, &nz, &cwrkre, &cwrkim,&ierr);
  cyr=(cyr0re+I*cyr0im);\
  return(cyr);
}

double _Complex zAiry(double _Complex z)
{
  int id=0;
  int kode=1,nz=0;
  int ierr;
  double _Complex ai;
  double z0re,z0im,ai0re,ai0im;
  z0re=creal(z);
  z0im=cimag(z);
  zairy_(&z0re, &z0im, &id, &kode, &ai0re, &ai0im, &nz, &ierr);
  ai=ai0re+I*ai0im;
  return(ai);
}

double _Complex zAirydz(double _Complex z)
{
  int id=1;
  int kode=1,nz=0;
  int ierr;
  double _Complex ai;
  double z0re,z0im,ai0re,ai0im;
  z0re=creal(z);
  z0im=cimag(z);
  zairy_(&z0re, &z0im, &id, &kode, &ai0re, &ai0im, &nz, &ierr);
  ai=ai0re+I*ai0im;
  return(ai);
}

double _Complex zBiry(double _Complex z)
{
  int id=0;
  int kode=1;
  int ierr;
  double _Complex ai;
  double z0re,z0im,ai0re,ai0im;
  z0re=creal(z);
  z0im=cimag(z);
  zbiry_(&z0re, &z0im, &id, &kode, &ai0re, &ai0im, &ierr);
  ai=ai0re+I*ai0im;
  return(ai);
}

double _Complex zBirydz(double _Complex z)
{
  int id=1;
  int kode=1;
  int ierr;
  double _Complex ai;
  double z0re,z0im,ai0re,ai0im;
  z0re=creal(z);
  z0im=cimag(z);
  zbiry_(&z0re, &z0im, &id, &kode, &ai0re, &ai0im, &ierr);
  ai=ai0re+I*ai0im;
  return(ai);
}

/*
my_Complex toMyComplex(Complex z)
{
  my_Complex z0;
  z0.re=re_Complex(z);
  z0.im=im_Complex(z);
  return(z0);
}

Complex fromMyComplex(my_Complex z0)
{
  Complex z;
  z=cmplx(z0.re,r0.im);
  return(z);
}
*/

/* double _Complex toMydouble _Complex(double _Complex z) */
/* { */
/*   my_double _Complex z0; */
/*   z0.re=re_complex(z); */
/*   z0.im=im_complex(z); */
/*   return(z0); */
/* } */

/* double _Complex fromMydouble _Complex(my_double _Complex z0) */
/* { */
/*   double _Complex z; */
/*   z=cmplx(z0.re,z0.im); */
/*   return(z); */
/* } */
