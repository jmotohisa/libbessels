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

#ifdef __COMPLEX__
#ifndef Complex
#define Complex _Complex float
#endif
#ifndef ZComplex
#define ZComplex _Complex double 
#endif
#ifndef re_complex
#define re_complex(c) creal(c)
#endif
#ifndef im_complex
#define im_complex(c) cimag(c)
#endif
#ifndef _CMPLX
#define cmplx(x,y) ((x)+I*(y))
#endif

#else // if complex is not defined

#define Complex my_Complex 
#define ZComplex my_ZComplex 
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
GLOBAL Complex cBesselh1_n(int , Complex );
GLOBAL Complex cBesselh2_n(int , Complex );
GLOBAL Complex cBesseli_n(int , Complex );
GLOBAL Complex cBesselj_n(int , Complex );
GLOBAL Complex cBesselk_n(int , Complex );
GLOBAL Complex cBessely_n(int , Complex );

GLOBAL Complex cBesselh1(float , Complex );
GLOBAL Complex cBesselh2(float , Complex );
GLOBAL Complex cBesseli(float , Complex );
GLOBAL Complex cBesselj(float , Complex );
GLOBAL Complex cBesselk(float , Complex );
GLOBAL Complex cBessely(float , Complex );

GLOBAL Complex cAiry(Complex );
GLOBAL Complex cAirydz(Complex );
GLOBAL Complex cBiry(Complex );
GLOBAL Complex cBirydz(Complex );

// double complex
GLOBAL ZComplex zBesselh1_n(int , ZComplex );
GLOBAL ZComplex zBesselh2_n(int , ZComplex );
GLOBAL ZComplex zBesseli_n(int , ZComplex );
GLOBAL ZComplex zBesselj_n(int , ZComplex );
GLOBAL ZComplex zBesselk_n(int , ZComplex );
GLOBAL ZComplex zBessely_n(int , ZComplex );
  
GLOBAL ZComplex zBesselh1(double , ZComplex );
GLOBAL ZComplex zBesselh2(double , ZComplex );
GLOBAL ZComplex zBesseli(double , ZComplex );
GLOBAL ZComplex zbesselj(double , ZComplex );
GLOBAL ZComplex zBesselk(double , ZComplex );
GLOBAL ZComplex zBessely(double , ZComplex );

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