// toms644_wrap.h

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _toms644_wrap_H
#define _toms644_wrap_H

#include <complex.h>

#ifdef	GLOBAL_VALUE_DEFINE
#define	GLOBAL
#else
#define	GLOBAL extern
#endif


/* #ifndef _my_Complex_DEFINED */
/* #define _my_Complex_DEFINED */
/* typedef struct { float re, im; } my_Complex; /\* complex numbers (conventional style)! *\/ */
/* #endif */
/* #ifndef _my_ZComplex_DEFINED */
/* #define _my_ZComplex_DEFINED */
/* typedef struct { double re, im; } my_ZComplex; /\* complex numbers  (conventional style)! *\/ */
/* #endif */

/* #if defined(__COMPLEX__) || defined(_COMPLEX_H) */
/*  #ifndef Complex */
/*   #define Complex float _Complex */
/*  #endif */
/*  #ifndef ZComplex */
/*   #define ZComplex double complex */
/*  #endif */
/*  #ifndef re_complex */
/*   #define re_complex(c) creal(c) */
/*  #endif */
/*  #ifndef im_complex */
/*   #define im_complex(c) cimag(c) */
/*  #endif */
/*  #ifndef _CMPLX */
/*   #define cmplx(x,y) ((x)+I*(y)) */
/*   #define zcmplx(x,y) ((x)+I*(y)) */
/*  #endif */
/* #else */
/* #ifndef Complex */
/*  typedef struct { float re, im; } Complex; /\* complex numbers! *\/ */
/* #endif */
/* #ifndef Zcomlex */
/*  typedef struct { double re, im; } ZComplex; /\* complex numbers! *\/ */
/* #endif */
/*  #define re_complex(c) ((c).re) */
/*  #define im_complex(c) ((c).im) */
/*  #ifndef _CMPLX */
/*   #define _CMPLX */
/* Complex cmplx(float x, float y) */
/* { */
/*   Complex z; */
/*   z.re = x; */
/*   z.im = y; */
/*   return (z); */
/* } */

/* ZComplex zcmplx(double x, double y) */
/* { */
/*   ZComplex z; */
/*   z.re = x; */
/*   z.im = y; */
/*   return (z); */
/* } */
/*  #endif */
/* #endif */

// TOMS 644 libraries (f77)
extern void cairy_(float complex *, int *, int *, float complex *, int *, int *);
extern void cbesh_(float complex *, float *, int *, int *, int *, float complex *, int *, int *);
extern void cbesi_(float complex *, float *, int *, int *, float complex *, int *, int *);
extern void cbesj_(float complex *, float *, int *, int *, float complex *, int *, int *);
extern void cbesk_(float complex *, float *, int *, int *, float complex *, int *, int *);
extern void cbesy_(float complex *, float *, int *, int *, float complex *, int *, float complex *, int *);
extern void cbiry_(float complex *, int *, int *, float complex *, int *);

extern void zairy_(double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesh_(double *, double *, double *, int *, int *, int *, double *, double *, int *, int *);
extern void zbesi_(double *, double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesj_(double *, double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesk_(double *, double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesy_(double *, double *, double *, int *, int *, double *, double *, int *, double *, double *, int *);
extern void zbiry_(double *, double *, int *, int *, double *, double *, int *);

// Complex version
GLOBAL float complex cBessel_H1n(int , float complex );
GLOBAL float complex cBessel_H2n(int , float complex );
GLOBAL float complex cBessel_In(int , float complex );
GLOBAL float complex cBessel_Jn(int , float complex );
GLOBAL float complex cBessel_Kn(int , float complex );
GLOBAL float complex cBessel_Yn(int , float complex );

GLOBAL float complex cBessel_H1(float , float complex );
GLOBAL float complex cBessel_H2(float , float complex );
GLOBAL float complex cBessel_I(float , float complex );
GLOBAL float complex cBessel_J(float , float complex );
GLOBAL float complex cBessel_K(float , float complex );
GLOBAL float complex cBessel_Y(float , float complex );

GLOBAL float complex cAiry(float complex );
GLOBAL float complex cAirydz(float complex );
GLOBAL float complex cBiry(float complex );
GLOBAL float complex cBirydz(float complex );

// double complex
GLOBAL double complex zBessel_H1n(int , double complex );
GLOBAL double complex zBessel_H2n(int , double complex );
GLOBAL double complex zBessel_Jn(int , double complex );
GLOBAL double complex zBessel_Yn(int , double complex );
GLOBAL double complex zBessel_In(int , double complex );
GLOBAL double complex zBessel_Kn(int , double complex );
  
GLOBAL double complex zBessel_H1(double , double complex );
GLOBAL double complex zBessel_H2(double , double complex );
GLOBAL double complex zBessel_I(double , double complex );
GLOBAL double complex zbessel_J(double , double complex );
GLOBAL double complex zBessel_K(double , double complex );
GLOBAL double complex zBessel_Y(double , double complex );

GLOBAL double complex zAiry(double complex );
GLOBAL double complex zAirydz(double complex );
GLOBAL double complex zBiry(double complex );
GLOBAL double complex zBirydz(double complex );

/* GLOBAL my_double complex toMydouble complex(double complex ); */
/* GLOBAL double complex fromMydouble complex(my_double complex ); */

#undef GLOBAL_VALUE_DEFINE
#undef GLOBAL

#endif

#ifdef __cplusplus
}
#endif

