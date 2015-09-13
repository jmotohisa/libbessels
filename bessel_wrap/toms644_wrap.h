// toms644_wrap.h

#ifndef _toms644_wrap_H
#define _toms644_wrap_H

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
/*   #define ZComplex double _Complex */
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

#ifdef __cplusplus
extern "C" {
#endif

// TOMS 644 libraries (f77)
extern void cairy_(_Complex *, int *, int *, _Complex *, int *, int *);
extern void cbesh_(_Complex *, float *, int *, int *, int *, _Complex *, int *, int *);
extern void cbesi_(_Complex *, float *, int *, int *, _Complex *, int *, int *);
extern void cbesj_(_Complex *, float *, int *, int *, _Complex *, int *, int *);
extern void cbesk_(_Complex *, float *, int *, int *, _Complex *, int *, int *);
extern void cbesy_(_Complex *, float *, int *, int *, _Complex *, int *, _Complex *, int *);
extern void cbiry_(_Complex *, int *, int *, _Complex *, int *);

extern void zairy_(double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesh_(double *, double *, double *, int *, int *, int *, double *, double *, int *, int *);
extern void zbesi_(double *, double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesj_(double *, double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesk_(double *, double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesy_(double *, double *, double *, int *, int *, double *, double *, int *, double *, double *, int *);
extern void zbiry_(double *, double *, int *, int *, double *, double *, int *);

// Complex version
GLOBAL _Complex cBessel_H1n(int , _Complex );
GLOBAL _Complex cBessel_H2n(int , _Complex );
GLOBAL _Complex cBessel_In(int , _Complex );
GLOBAL _Complex cBessel_Jn(int , _Complex );
GLOBAL _Complex cBessel_Kn(int , _Complex );
GLOBAL _Complex cBessel_Yn(int , _Complex );

GLOBAL _Complex cBessel_H1(float , _Complex );
GLOBAL _Complex cBessel_H2(float , _Complex );
GLOBAL _Complex cBessel_I(float , _Complex );
GLOBAL _Complex cBessel_J(float , _Complex );
GLOBAL _Complex cBessel_K(float , _Complex );
GLOBAL _Complex cBessel_Y(float , _Complex );

GLOBAL _Complex cAiry(_Complex );
GLOBAL _Complex cAirydz(_Complex );
GLOBAL _Complex cBiry(_Complex );
GLOBAL _Complex cBirydz(_Complex );

// double complex
GLOBAL double _Complex zBessel_H1n(int , double _Complex );
GLOBAL double _Complex zBessel_H2n(int , double _Complex );
GLOBAL double _Complex zBessel_Jn(int , double _Complex );
GLOBAL double _Complex zBessel_Yn(int , double _Complex );
GLOBAL double _Complex zBessel_In(int , double _Complex );
GLOBAL double _Complex zBessel_Kn(int , double _Complex );
  
GLOBAL double _Complex zBessel_H1(double , double _Complex );
GLOBAL double _Complex zBessel_H2(double , double _Complex );
GLOBAL double _Complex zBessel_I(double , double _Complex );
GLOBAL double _Complex zbessel_J(double , double _Complex );
GLOBAL double _Complex zBessel_K(double , double _Complex );
GLOBAL double _Complex zBessel_Y(double , double _Complex );

GLOBAL double _Complex zAiry(double _Complex );
GLOBAL double _Complex zAirydz(double _Complex );
GLOBAL double _Complex zBiry(double _Complex );
GLOBAL double _Complex zBirydz(double _Complex );

/* GLOBAL my_double _Complex toMydouble _Complex(double _Complex ); */
/* GLOBAL double _Complex fromMydouble _Complex(my_double _Complex ); */

#ifdef __cplusplus
}
#endif

#undef GLOBAL_VALUE_DEFINE
#undef GLOBAL

#endif
