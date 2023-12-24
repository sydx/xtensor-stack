# xtensor-stack
The xtensor, xtensor-blas, and all the dependencies packaged as a single conda package.

This project consists of modified versions of:

* https://github.com/xtensor-stack/xtensor/
* https://github.com/xtensor-stack/xtensor-blas
* https://github.com/xtensor-stack/xtl/
* https://github.com/michael-lehn/FLENS

where the static libraries lapack, blas, and cblas are built from Fortran source.

# Usage

    conda build xtensor-stack/
