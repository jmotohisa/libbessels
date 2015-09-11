// toms644_wrap.h

#ifndef _toms644_wrap_H
#define _toms644_wrap_H

#ifdef	GLOBAL_VALUE_DEFINE
#define	GLOBAL
#else
#define	GLOBAL extern
#endif

#ifndef _my_Complex_DEFINED
#define _my_Complex_DEFINED
typedef struct { float re, im; } my_Complex; /* complex numbers (conventional style)! */
#endif
#ifndef _my_ZComplex_DEFINED
#define _my_ZComplex_DEFINED
typedef struct { double re, im; } my_ZComplex; /* complex numbers  (conventional style)! */
#endif

#if defined(__COMPLEX__) || defined(_COMPLEX_H)
 #ifndef Complex
  #define Complex float _Complex
 #endif
 #ifndef ZComplex
  #define ZComplex double _Complex
 #endif
 #ifndef re_complex
  #define re_complex(c) creal(c)
 #endif
 #ifndef im_complex
  #define im_complex(c) cimag(c)
 #endif
 #ifndef _CMPLX
  #define cmplx(x,y) ((x)+I*(y))
  #define zcmplx(x,y) ((x)+I*(y))
 #endif
#else
#ifndef Complex
 typedef struct { float re, im; } Complex; /* complex numbers! */
#endif
#ifndef Zcomlex
 typedef struct { double re, im; } ZComplex; /* complex numbers! */
#endif
 #define re_complex(c) ((c).re)
 #define im_complex(c) ((c).im)
 #ifndef _CMPLX
  #define _CMPLX
Complex cmplx(float x, float y)
{
  Complex z;
  z.re = x;
  z.im = y;
  return (z);
}

ZComplex zcmplx(double x, double y)
{
  ZComplex z;
  z.re = x;
  z.im = y;
  return (z);
}
 #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

// TOMS 644 libraries (f77)
extern void cairy_(Complex *, int *, int *, Complex *, int *, int *);
extern void cbesh_(Complex *, float *, int *, int *, int *, Complex *, int *, int *);
extern void cbesi_(Complex *, float *, int *, int *, Complex *, int *, int *);
extern void cbesj_(Complex *, float *, int *, int *, Complex *, int *, int *);
extern void cbesk_(Complex *, float *, int *, int *, Complex *, int *, int *);
extern void cbesy_(Complex *, float *, int *, int *, Complex *, int *, Complex *, int *);
extern void cbiry_(Complex *, int *, int *, Complex *, int *);

extern void zairy_(double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesh_(double *, double *, double *, int *, int *, int *, double *, double *, int *, int *);
extern void zbesi_(double *, double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesj_(double *, double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesk_(double *, double *, double *, int *, int *, double *, double *, int *, int *);
extern void zbesy_(double *, double *, double *, int *, int *, double *, double *, int *, double *, double *, int *);
extern void zbiry_(double *, double *, int *, int *, double *, double *, int *);

// Complex version
GLOBAL Complex cBessel_H1n(int , Complex );
GLOBAL Complex cBessel_H2n(int , Complex );
GLOBAL Complex cBessel_In(int , Complex );
GLOBAL Complex cBessel_Jn(int , Complex );
GLOBAL Complex cBessel_Kn(int , Complex );
GLOBAL Complex cBessel_Yn(int , Complex );

GLOBAL Complex cBessel_H1(float , Complex );
GLOBAL Complex cBessel_H2(float , Complex );
GLOBAL Complex cBessel_I(float , Complex );
GLOBAL Complex cBessel_J(float , Complex );
GLOBAL Complex cBessel_K(float , Complex );
GLOBAL Complex cBessel_Y(float , Complex );

GLOBAL Complex cAiry(Complex );
GLOBAL Complex cAirydz(Complex );
GLOBAL Complex cBiry(Complex );
GLOBAL Complex cBirydz(Complex );

// double complex
GLOBAL ZComplex zBessel_H1n(int , ZComplex );
GLOBAL ZComplex zBessel_H2n(int , ZComplex );
GLOBAL ZComplex zBessel_Jn(int , ZComplex );
GLOBAL ZComplex zBessel_Yn(int , ZComplex );
GLOBAL ZComplex zBessel_In(int , ZComplex );
GLOBAL ZComplex zBessel_Kn(int , ZComplex );
  
GLOBAL ZComplex zBessel_H1(double , ZComplex );
GLOBAL ZComplex zBessel_H2(double , ZComplex );
GLOBAL ZComplex zBessel_I(double , ZComplex );
GLOBAL ZComplex zbessel_J(double , ZComplex );
GLOBAL ZComplex zBessel_K(double , ZComplex );
GLOBAL ZComplex zBessel_Y(double , ZComplex );

GLOBAL ZComplex zAiry(ZComplex );
GLOBAL ZComplex zAirydz(ZComplex );
GLOBAL ZComplex zBiry(ZComplex );
GLOBAL ZComplex zBirydz(ZComplex );

GLOBAL my_ZComplex toMyZComplex(ZComplex );
GLOBAL ZComplex fromMyZComplex(my_ZComplex );

#ifdef __cplusplus
}
#endif

#undef GLOBAL_VALUE_DEFINE
#undef GLOBAL

#endif
