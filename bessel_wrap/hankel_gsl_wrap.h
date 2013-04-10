// hankel_gsl_warp.h

#ifndef _HANKEL_GLS_WRAP_H
#define _HANKEL_GLS_WRAP_H

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

  GLOBAL ZComplex z0Bessel_H1n(int , double );
  GLOBAL ZComplex z0Bessel_H2n(int , double );
  //  GLOBAL ZComplex zBessel_H1n(int , ZComplex );
  //  GLOBAL ZComplex zBessel_H2n(int , ZComplex );

#ifdef __cplusplus
}
#endif

#undef GLOBAL_VALUE_DEFINE
#undef GLOBAL

#endif
