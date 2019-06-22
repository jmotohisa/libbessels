/*
 *  libbessel.h - last saved: Time-stamp: <Sat Jun 22 20:39:22 JST 2019>
 *
 *   Copyright (c) 2019  jmotohisa (Junichi Motohisa)  <motohisa@ist.hokudai.ac.jp>
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  $Id: libbessel.h 2019-06-01 13:27:44 jmotohisa $
 */

/*! 
  @file libbessel.h 
  @brief 
  @author J. Motohisa
*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _LIBBESSEL_H
#define _LIBBESSEL_H

double Bessel_Jn(int, double );
double Bessel_Yn(int, double );
double Bessel_In(int, double );
double Bessel_Kn(int, double );

double complex z0Bessel_H1n(int , double );
double complex z0Bessel_H2n(int , double );

double dBessel_Jn(int , double );
double dBessel_Yn(int , double );
double dBessel_In(int , double );
double dBessel_Kn(int , double );

double complex zBessel_H1n(int , double complex );
double complex zBessel_H2n(int , double complex );
double complex zBessel_Jn(int , double complex );
double complex zBessel_Yn(int , double complex );
double complex zBessel_In(int , double complex );
double complex zBessel_Kn(int , double complex );

double complex z0dBessel_H1n(int , double );
double complex z0dBessel_H2n(int , double );

double complex zdBessel_Jn(int , double complex );
double complex zdBessel_Yn(int , double complex );
double complex zdBessel_In(int , double complex );
double complex zdBessel_Kn(int , double complex );
double complex zdBessel_H1n(int , double complex );
double complex zdBessel_H2n(int , double complex );

#endif  // _LIBBESSEL_H

#ifdef __cplusplus
}
#endif
