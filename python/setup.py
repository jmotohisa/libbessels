#!/usr/bin/env python
# -*- coding: utf-8 -*-

# from numpy.distutils.core import setup
# from numpy.distutils.misc_util import Configuration
# import sys
# import os.path
# from setuptools import setup, Extension
from numpy.distutils.core import setup, Extension

ext_libbessel = Extension(
    '_libbessel',
    sources=['gsl_wrapper.c',
             '../dbessel.c',
             '../bessel_wrap/toms644_wrap.c',
             '../bessel_wrap/hankel_gsl_wrap.c',
             '../bessel_wrap/toms644/cbsubs.f',
             '../bessel_wrap/toms644/zbsubs.f',
             '../bessel_wrap/toms644/xerror.f',
             '../bessel_wrap/toms644/i1mach.f',
             '../bessel_wrap/toms644/r1mach.f',
             '../bessel_wrap/toms644/d1mach.f'],
    libraries=['gsl', 'gslcblas'],
)

if __name__ == '__main__':
    setup(
        name="libbessel",
        version="0.0.0",
        description="Besel function library by jm",
        ext_modules=[ext_libbessel],
        py_modules=['libbessel'],
    )

# config = Configuration()

# libbessel_sources = ['../dbessel.c',
#                      '../bessel_wrap/toms644_wrap.c',
#                      '../bessel_wrap/hankel_gsl_wrap.c',
#                      '../bessel_wrap/toms644/cbsubs.f',
#                      '../bessel_wrap/toms644/zbsubs.f',
#                      '../bessel_wrap/toms644/xerror.f',
#                      '../bessel_wrap/toms644/i1mach.f',
#                      '../bessel_wrap/toms644/r1mach.f',
#                      '../bessel_wrap/toms644/d1mach.f']

# config.add_library("libbessel", sources=libbessel_sources)
# config.add_extension("libbessel",
#                      sources=["libbessel.pyf"],
#                      libraries=["libbessel"], depends=libbessel_sources)

# setup(**config.todict())
