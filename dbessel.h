// dbessel.h

#ifndef _DBESSEL_H
#define _DBESSEL_H

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
#else // if complex is not defined
typedef struct { float re, im; } Complex; /* complex numbers! */
typedef struct { double re, im; } ZComplex; /* complex numbers! */
#endif

#ifdef __cplusplus
extern "C" {
#endif

GLOBAL double dBessel_Jn(int , double );
GLOBAL double dBessel_Yn(int , double );
GLOBAL double dBessel_In(int , double );
GLOBAL double dBessel_Kn(int , double );

GLOBAL ZComplex dz0Bessel_H1n(int , double );
GLOBAL ZComplex dz0Bessel_H2n(int , double );

//double complex
GLOBAL ZComplex zdBessel_Jn(int , ZComplex );
GLOBAL ZComplex zdBessel_Yn(int , ZComplex );
GLOBAL ZComplex zdBessel_In(int , ZComplex );
GLOBAL ZComplex zdBessel_Kn(int , ZComplex );
GLOBAL ZComplex zdBessel_H1n(int , ZComplex );
GLOBAL ZComplex zdBessel_H2n(int , ZComplex );

#ifdef __cplusplus
}
#endif

#undef GLOBAL_VALUE_DEFINE
#undef GLOBAL

#endif
