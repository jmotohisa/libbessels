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

GLOBAL double dBesselj_n(int , double );
GLOBAL double dBessely_n(int , double );
GLOBAL double dBesseli_n(int , double );
GLOBAL double dBesselk_n(int , double );

GLOBAL ZComplex dBesselh1_n(int , double );
GLOBAL ZComplex dBesselh2_n(int , double );

//double complex
GLOBAL ZComplex zdBesselj_n(int , ZComplex );
GLOBAL ZComplex zdBessely_n(int , ZComplex );
GLOBAL ZComplex zdBesseli_n(int , ZComplex );
GLOBAL ZComplex zdBesselk_n(int , ZComplex );
GLOBAL ZComplex zdBesselh1_n(int , ZComplex );
GLOBAL ZComplex zdBesselh2_n(int , ZComplex );

#ifdef __cplusplus
}
#endif

#undef GLOBAL_VALUE_DEFINE
#undef GLOBAL

#endif
