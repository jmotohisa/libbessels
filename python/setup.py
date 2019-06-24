#!/usr/bin/env python
# -*- coding: utf-8 -*-

from numpy.distutils.core import setup, Extension
# from numpy.distutils.misc_util import Configuration

libbessel_sources = [
    'gsl_wrapper.c',
    # 'libbessel.i',
    '../dbessel.c',
    '../bessel_wrap/toms644_wrap.c',
    '../bessel_wrap/hankel_gsl_wrap.c',
    '../bessel_wrap/toms644/cbsubs.f',
    '../bessel_wrap/toms644/zbsubs.f',
    '../bessel_wrap/toms644/xerror.f',
    '../bessel_wrap/toms644/i1mach.f',
    '../bessel_wrap/toms644/r1mach.f',
    '../bessel_wrap/toms644/d1mach.f']

ext_libbessel = Extension(
    '_libbessel',
    sources=libbessel_sources,
    libraries=['gsl', 'gslcblas'],
    library_dirs=['/opt/local/lib'],
)

if __name__ == '__main__':
    setup(
        name="libbessel",
        version="0.0.0",
        description="Besel function library by jm",
        ext_modules=[ext_libbessel],
        py_modules=['libbessel'],
    )


# config.add_library("libbessel", sources=libbessel_sources)
# config.add_extension("libbessel_f2py",
#                      sources=["libbessel.pyf"],
#                      libraries=["libbessel"], depends=libbessel_sources)

# config = Configuration()

# config.add_library("libbessel", sources=libbessel_sources)
# config.add_extension("libbessel_f2py",
#                      sources=[libbessel_f2py.pyf],
#                      libraries=["libbessel"], depends=libbessel_sources)

# setup(**config.todict())
