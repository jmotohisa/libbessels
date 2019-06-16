/* toms644_wrap.c */

/* Warpper library TOMS 644 Complex Bessel library 
     Complex Bessel Functions J_nue(z)/Y_nue(z)/I_nue(z)/K_nue(z)/H_nue^{1}(z)/H_nue^{2}
	 with complex argurment z
	 with non-negative nue
 */

#include <complex.h>
#include <math.h>
#include <libguile.h>

#define GLOBAL_VALUE_DEFINE
#include "toms644_wrap.h"

#define FUNC_CBESSEL_N(j,J)					\
  float complex cBessel_##J##n(int n, float complex z)	\
  {												\
  int nn,kode=1;								\
  float complex cy; 									\
  int nz=0;										\
  float fnu;									\
  int ierr;									\
  fnu=n;										\
  cbes##j##_(&z, &fnu, &kode, &nn, &cy, &nz, &ierr);	\
  return(cy);										\
}

#define FUNC_CBESSEL(j,J)						\
  float complex cBessel_##J(float fnu, float complex z)		\
  {												\
	int nn=1,kode=1;							\
	float complex cy;									\
	int nz=0;										\
	int ierr;										\
	cbes##j##_(&z, &fnu, &kode, &nn, &cy, &nz, &ierr);	\
	return(cy);											\
  }

#define FUNC_CBESSELH_N(i)							\
  float complex cBessel_H##i##n(int n, float complex z)		\
  {												\
	int nn=1,kode=1,m;							\
	float complex cy;									\
	int nz=0;									\
	float fnu;									\
	int ierr;									\
	m=i;											\
	fnu=n;												\
	cbesh_(&z, &fnu, &kode, &m, &nn, &cy, &nz, &ierr);	\
	return(cy);											\
  }

#define FUNC_CBESSELH(i)						\
  float complex cBessel_H##i(float fnu, float complex z)		\
  {												\
	int nn=1,kode=1,m=i;							\
	float complex cy;										\
	int nz=0;											\
	int ierr;											\
	cbesh_(&z, &fnu, &kode, &m,&nn, &cy, &nz, &ierr);	\
	return(cy);											\
  }

#define FUNC_ZBESSEL_N(j,J)											\
  double complex zBessel_##J##n(int n, double complex z)			\
  {																	\
	int nn=1,kode=1;												\
	double complex cyr;											\
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
  double complex zBessel_##J(double fnu, double complex z)			\
  {														\
	int nn=1,kode=1;									\
	double complex cyr;										\
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
  double complex zBessel_H##i##n(int n, double complex z)				\
  {															\
	int nn=1,kode=1,m=i;									\
	double complex cyr;											\
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
  double complex zBessel_H##i(double fnu, double complex z)				\
  {															\
	int nn=1,kode=1,m=i;										\
	double complex cyr;												\
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

float complex cAiry(float complex z)
{
  int id=0;
  int kode=1,nz=0;
  int ierr;
  float complex ai;
  cairy_(&z, &id, &kode, &ai, &nz, &ierr);
  return(ai);
}

float complex cAirydz(float complex z)
{
  int id=1;
  int kode=1,nz=0;
  int ierr;
  float complex ai;
  cairy_(&z, &id, &kode, &ai, &nz, &ierr);
  return(ai);
}

float complex cBiry(float complex z)
{
  int id=0;
  int kode=1,nz=0;
  int ierr;
  float complex ai;
  cbiry_(&z, &id, &kode, &ai, &ierr);
  return(ai);
}

float complex cbirydz(float complex z)
{
  int id=1;
  int kode=1,nz=0;
  int ierr;
  float complex ai;
  cbiry_(&z, &id, &kode, &ai, &ierr);
  return(ai);
}

float complex cBessel_Yn(int n, float complex z)
{
  int nn=1,kode=1;
  float complex cy,cwrk;
  int nz=0;
  int ierr;
  float fnu;
  fnu=n;
  cbesy_(&z, &fnu, &kode, &nn, &cy, &nz, &cwrk,&ierr);
  return(cy);
}

float complex cBessel_Y(float fnu, float complex z)
{
  int nn=1,kode=1;
  float complex cy,cwrk;
  int ierr;
  int nz=0;
  cbesy_(&z, &fnu, &kode, &nn, &cy, &nz, &cwrk,&ierr);
  return(cy);
}

double complex zBessel_Yn(int n, double complex z)
{
  int nn=1,kode=1;
  double complex cyr;
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

double complex zBessel_Y(double fnu, double complex z)
{
  int nn=1,kode=1;
  double complex cyr;
  int nz=0;
  int ierr;
  double complex z0,cyr0;
  double z0re,z0im,cyr0re,cyr0im;
  double cwrkre,cwrkim;
  z0re=creal(z);\
  z0im=cimag(z);\
  zbesy_(&z0re, &z0im, &fnu, &kode, &nn, &cyr0re, &cyr0im, &nz, &cwrkre, &cwrkim,&ierr);
  cyr=(cyr0re+I*cyr0im);\
  return(cyr);
}

double complex zAiry(double complex z)
{
  int id=0;
  int kode=1,nz=0;
  int ierr;
  double complex ai;
  double z0re,z0im,ai0re,ai0im;
  z0re=creal(z);
  z0im=cimag(z);
  zairy_(&z0re, &z0im, &id, &kode, &ai0re, &ai0im, &nz, &ierr);
  ai=ai0re+I*ai0im;
  return(ai);
}

double complex zAirydz(double complex z)
{
  int id=1;
  int kode=1,nz=0;
  int ierr;
  double complex ai;
  double z0re,z0im,ai0re,ai0im;
  z0re=creal(z);
  z0im=cimag(z);
  zairy_(&z0re, &z0im, &id, &kode, &ai0re, &ai0im, &nz, &ierr);
  ai=ai0re+I*ai0im;
  return(ai);
}

double complex zBiry(double complex z)
{
  int id=0;
  int kode=1;
  int ierr;
  double complex ai;
  double z0re,z0im,ai0re,ai0im;
  z0re=creal(z);
  z0im=cimag(z);
  zbiry_(&z0re, &z0im, &id, &kode, &ai0re, &ai0im, &ierr);
  ai=ai0re+I*ai0im;
  return(ai);
}

double complex zBirydz(double complex z)
{
  int id=1;
  int kode=1;
  int ierr;
  double complex ai;
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

/* double complex toMydouble complex(double complex z) */
/* { */
/*   my_double complex z0; */
/*   z0.re=re_complex(z); */
/*   z0.im=im_complex(z); */
/*   return(z0); */
/* } */

/* double complex fromMydouble complex(my_double complex z0) */
/* { */
/*   double complex z; */
/*   z=cmplx(z0.re,z0.im); */
/*   return(z); */
/* } */
