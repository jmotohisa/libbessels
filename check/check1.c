// check libbessels

#include <complex.h>
#include <stdio.h>
#include <math.h>

#include "../dbessel.h"
#include "../bessel_wrap/gsl_bessel_wrap.h"
#include "../bessel_wrap/hankel_gsl_wrap.h"
#include "../bessel_wrap/toms644_wrap.h"

#define NX 51
#define NY 51
#define N 1

int
main()
{
  double _Complex z,jn,yn,in,kn;
  double x,y,dx,dy;
  int i,j;

  dx=2./(NX-1);
  dy=2./(NY-1);
  for(i=1;i<NX;i++)
	{
	  x=dx*i-1;
	  for(j=1;j<NY;j++)
		{
		  y=dy*j-1;
		  z=x+I*y;
		  jn=zBessel_Jn(N,z);
		  yn=zBessel_Yn(N,z);
		  in=zBessel_In(N,z);
		  kn=zBessel_Kn(N,z);
		  printf("%lf\t\%lf\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\n",
				 x,y,
				 creal(jn),cimag(jn),
				 creal(yn),cimag(yn),
				 creal(in),cimag(in),
				 creal(kn),cimag(kn));
		}
	  printf("\n");
	}
  return 0;
}
