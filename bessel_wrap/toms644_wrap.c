/* toms644_wrap.c */

/* Warpper library TOMS 644 Complex Bessel library 
     Complex Bessel Functions with complex argurment
 */

#include <complex.h>
#include <math.h>

#define GLOBAL_VALUE_DEFINE
#include "toms644_wrap.h"

#define FUNC_CBESSEL_N(j)						\
  Complex cBessel##j##_n(int n, Complex z)	\
  {												\
  int nn=1,kode=1;								\
  Complex cy;									\
  int nz=0;										\
  float fnu;									\
  int *ierr;									\
  fnu=n;										\
  cbes##j##_(&z, &fnu, &kode, &nn, &cy, &nz, ierr);	\
  return(cy);										\
}

#define FUNC_CBESSEL(j)						\
  Complex cBessel##j(float fnu, Complex z)		\
  {												\
	int nn=1,kode=1;							\
	Complex cy;									\
	int nz=0;										\
	int *ierr;										\
	cbes##j##_(&z, &fnu, &kode, &nn, &cy, &nz, ierr);	\
	return(cy);											\
  }

#define FUNC_CBESSELH_N(j)						\
  Complex cBesselh##j##_n(int n, Complex z)		\
  {												\
	int nn=1,kode=1,m;							\
	Complex cy;									\
	int nz=0;									\
	float fnu;									\
	int *ierr;									\
	m=j;											\
	fnu=n;												\
	cbesh_(&z, &fnu, &kode, &m, &nn, &cy, &nz, ierr);	\
	return(cy);											\
  }

#define FUNC_CBESSELH(j)						\
  Complex cBesselh##j(float fnu, Complex z)		\
  {												\
	int nn=1,kode=1,m=j;							\
	Complex cy;										\
	int nz=0;											\
	int *ierr;											\
	cbesh_(&z, &fnu, &kode, &m,&nn, &cy, &nz, ierr);	\
	return(cy);											\
  }

#define FUNC_ZBESSEL_N(j)								\
  ZComplex zBessel##j##_n(int n, ZComplex z)			\
  {														\
	int nn=1,kode=1;									\
	ZComplex cyr;										\
	int nz=0;											\
	double fnu;											\
	int *ierr;											\
	my_ZComplex z0,cyr0;								\
	fnu=n;																\
	z0=toMyZComplex(z);													\
	zbes##j##_(&z0.re, &z0.im, &fnu, &kode, &nn, &cyr0.re, &cyr0.im, &nz, ierr); \
	cyr=fromMyZComplex(cyr0);											\
	return(cyr);														\
  }

#define FUNC_ZBESSEL(j)									\
  ZComplex zBessel##j(double fnu, ZComplex z)			\
  {														\
	int nn=1,kode=1;									\
	ZComplex cyr;										\
	my_ZComplex z0,cyr0;								\
    int *ierr;											\
	int nz=0;															\
	z0=toMyZComplex(z);													\
	zbes##j##_(&z0.re, &z0.im, &fnu, &kode, &nn, &cyr0.re, &cyr0.im, &nz, ierr); \
	cyr=fromMyZComplex(cyr0);											\
	return(cyr);														\
  }


#define FUNC_ZBESSELH_N(j)									\
  ZComplex zBesselh##j##_n(int n, ZComplex z)				\
  {															\
	int nn=1,kode=1,m=j;									\
	ZComplex cy;											\
	int nz=0;												\
    int *ierr;												\
	double fnu;														\
	my_ZComplex z0,cy0;												\
	fnu=n;															\
	z0=toMyZComplex(z);													\
	zbesh_(&z0.re, &z0.im, &fnu, &kode, &m, &nn, &cy0.re, &cy0.im, &nz, ierr); \
	cy=fromMyZComplex(cy0);												\
	return(cy);															\
  }

#define FUNC_ZBESSELH(j)									\
  ZComplex zBesselh##j(double fnu, ZComplex z)				\
  {															\
	int nn=1,kode=1,m=j;										\
	ZComplex cy;												\
    int *ierr;														\
	int nz=0;														\
	my_ZComplex z0,cy0;												\
	z0=toMyZComplex(z);													\
	zbesh_(&z0.re, &z0.im, &fnu, &kode, &m, &nn, &cy0.re, &cy0.im, &nz, ierr); \
	cy=fromMyZComplex(cy0);												\
	return(cy);															\
  }

FUNC_CBESSELH_N(1);
FUNC_CBESSELH_N(2);
FUNC_CBESSELH(1);
FUNC_CBESSELH(2);

FUNC_CBESSEL_N(i);
FUNC_CBESSEL_N(j);
FUNC_CBESSEL_N(k);

FUNC_CBESSEL(i);
FUNC_CBESSEL(j);
FUNC_CBESSEL(k);

FUNC_ZBESSEL_N(i);
FUNC_ZBESSEL_N(j);
FUNC_ZBESSEL_N(k);

FUNC_ZBESSEL(i);
FUNC_ZBESSEL(j);
FUNC_ZBESSEL(k);

FUNC_ZBESSELH_N(1);
FUNC_ZBESSELH_N(2);
FUNC_ZBESSELH(1);
FUNC_ZBESSELH(2);

Complex cAiry(Complex z)
{
  int id=0;
  int kode=1,nz=0;
  int *ierr;
  Complex ai;
  cairy_(&z, &id, &kode, &ai, &nz, ierr);
  return(ai);
}

Complex cAirydz(Complex z)
{
  int id=1;
  int kode=1,nz=0;
  int *ierr;
  Complex ai;
  cairy_(&z, &id, &kode, &ai, &nz, ierr);
  return(ai);
}

Complex cBiry(Complex z)
{
  int id=0;
  int kode=1,nz=0;
  int *ierr;
  Complex ai;
  cbiry_(&z, &id, &kode, &ai, ierr);
  return(ai);
}

Complex cbirydz(Complex z)
{
  int id=1;
  int kode=1,nz=0;
  int *ierr;
  Complex ai;
  cbiry_(&z, &id, &kode, &ai, ierr);
  return(ai);
}

Complex cBessely_n(int n, Complex z)
{
  int nn=1,kode=1;
  Complex cy,cwrk;
  int nz=0;
  int *ierr;
  float fnu;
  fnu=n;
  cbesy_(&z, &fnu, &kode, &nn, &cy, &nz, &cwrk,ierr);
  return(cy);
}

Complex cBessely(float fnu, Complex z)
{
  int nn=1,kode=1;
  Complex cy,cwrk;
  int *ierr;
  int nz=0;
  cbesy_(&z, &fnu, &kode, &nn, &cy, &nz, &cwrk,ierr);
  return(cy);
}

ZComplex zBessely_n(int n, ZComplex z)
{
  int nn=1,kode=1;
  ZComplex cyr;
  my_ZComplex cwrk;
  int nz=0;
  int *ierr;
  double fnu;
  my_ZComplex z0,cyr0;
  fnu=n;
  z0=toMyZComplex(z);\
  zbesy_(&z0.re, &z0.im, &fnu, &kode, &nn, &cyr0.re, &cyr0.im, &nz, &cwrk.re, &cwrk.im,ierr);
  cyr=fromMyZComplex(cyr0);\
  return(cyr);
}

ZComplex zBessely(double fnu, ZComplex z)
{
  int nn=1,kode=1;
  ZComplex cyr;
  my_ZComplex cwrk;
  int nz=0;
  int *ierr;
  my_ZComplex z0,cyr0;
  z0=toMyZComplex(z);\
  zbesy_(&z0.re, &z0.im, &fnu, &kode, &nn, &cyr0.re, &cyr0.im, &nz, &cwrk.re, &cwrk.im,ierr);
  cyr=fromMyZComplex(cyr0);\
  return(cyr);
}

ZComplex zAiry(ZComplex z)
{
  int id=0;
  int kode=1,nz=0;
  int *ierr;
  ZComplex ai;
  my_ZComplex z0,ai0;
  z0=toMyZComplex(z);\
  zairy_(&z0.re, &z0.im, &id, &kode, &ai0.re, &ai0.im, &nz, ierr);
  ai=fromMyZComplex(ai0);\
  return(ai);
}

ZComplex zAirydz(ZComplex z)
{
  int id=1;
  int kode=1,nz=0;
  int *ierr;
  ZComplex ai;
  my_ZComplex z0,ai0;
  z0=toMyZComplex(z);\
  zairy_(&z0.re, &z0.im, &id, &kode, &ai0.re, &ai0.im, &nz, ierr);
  ai=fromMyZComplex(ai0);\
  return(ai);
}

ZComplex zBiry(ZComplex z)
{
  int id=0;
  int kode=1;
  int *ierr;
  ZComplex ai;
  my_ZComplex z0,ai0;
  z0=toMyZComplex(z);\
  zbiry_(&z0.re, &z0.im, &id, &kode, &ai0.re, &ai0.im, ierr);
  ai=fromMyZComplex(ai0);\
  return(ai);
}

ZComplex zBirydz(ZComplex z)
{
  int id=1;
  int kode=1;
  int *ierr;
  ZComplex ai;
  my_ZComplex z0,ai0;
  z0=toMyZComplex(z);\
  zbiry_(&z0.re, &z0.im, &id, &kode, &ai0.re, &ai0.im, ierr);
  ai=fromMyZComplex(ai0);\
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

my_ZComplex toMyZComplex(ZComplex z)
{
  my_ZComplex z0;
  z0.re=re_complex(z);
  z0.im=im_complex(z);
  return(z0);
}

ZComplex fromMyZComplex(my_ZComplex z0)
{
  ZComplex z;
  z=cmplx(z0.re,z0.im);
  return(z);
}