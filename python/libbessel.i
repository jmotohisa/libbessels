%module libbessel

%{
#define SWIG_FILE_WITH_INIT
#include <complex.h>
/* #include <gsl/gsl_sf_bessel.h> */
  
extern double Bessel_Jn(int, double );
extern double Bessel_Yn(int, double );
extern double Bessel_In(int, double );
extern double Bessel_Kn(int, double );
extern double complex z0Bessel_H1n(int , double );
extern double complex z0Bessel_H2n(int , double );

extern double dBessel_Jn(int , double );
extern double dBessel_Yn(int , double );
extern double dBessel_In(int , double );
extern double dBessel_Kn(int , double );

extern double complex zBessel_Jn(int , double complex );
extern double complex zBessel_Yn(int , double complex );
extern double complex zBessel_In(int , double complex );
extern double complex zBessel_Kn(int , double complex );
extern double complex zBessel_H1n(int , double complex );
extern double complex zBessel_H2n(int , double complex );

extern double complex z0dBessel_H1n(int , double );
extern double complex z0dBessel_H2n(int , double );

extern double complex zdBessel_Jn(int , double complex );
extern double complex zdBessel_Yn(int , double complex );
extern double complex zdBessel_In(int , double complex );
extern double complex zdBessel_Kn(int , double complex );
extern double complex zdBessel_H1n(int , double complex );
extern double complex zdBessel_H2n(int , double complex );
/* #include "libbessel.h" */
/* #include "../dbessel.h" */
/* #include "../bessel_wrap/gsl_bessel_wrap.h" */
/* #include "../bessel_wrap/hankel_gsl_wrap.h" */
/* #include "../bessel_wrap/toms644_wrap.h" */
%}
%include "complex.i"
/* %include "numpy.i" */

extern double Bessel_Jn(int, double );
extern double Bessel_Yn(int, double );
extern double Bessel_In(int, double );
extern double Bessel_Kn(int, double );
extern double complex z0Bessel_H1n(int , double );
extern double complex z0Bessel_H2n(int , double );

extern double dBessel_Jn(int , double );
extern double dBessel_Yn(int , double );
extern double dBessel_In(int , double );
extern double dBessel_Kn(int , double );

extern double complex zBessel_Jn(int , double complex );
extern double complex zBessel_Yn(int , double complex );
extern double complex zBessel_In(int , double complex );
extern double complex zBessel_Kn(int , double complex );
extern double complex zBessel_H1n(int , double complex );
extern double complex zBessel_H2n(int , double complex );

extern double complex z0dBessel_H1n(int , double );
extern double complex z0dBessel_H2n(int , double );

extern double complex zdBessel_Jn(int , double complex );
extern double complex zdBessel_Yn(int , double complex );
extern double complex zdBessel_In(int , double complex );
extern double complex zdBessel_Kn(int , double complex );
extern double complex zdBessel_H1n(int , double complex );
extern double complex zdBessel_H2n(int , double complex );
