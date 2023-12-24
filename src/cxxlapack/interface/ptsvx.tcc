/*
 *   Copyright (c) 2012, Michael Lehn, Klaus Pototzky
 *
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1) Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2) Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *   3) Neither the name of the FLENS development group nor the names of
 *      its contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CXXLAPACK_INTERFACE_PTSVX_TCC
#define CXXLAPACK_INTERFACE_PTSVX_TCC 1

#include <cxxstd/iostream.h>
#include <cxxlapack/interface/interface.h>
#include <cxxlapack/netlib/netlib.h>

namespace cxxlapack {

template <typename IndexType>
IndexType
ptsvx(char                  fact,
      IndexType             n,
      IndexType             nRhs,
      const float           *d,
      const float           *e,
      float                 *df,
      float                 *ef,
      const float           *B,
      IndexType             ldB,
      float                 *X,
      IndexType             ldX,
      float                 &rCond,
      float                 *ferr,
      float                 *berr,
      float                 *work)
{
    CXXLAPACK_DEBUG_OUT("sptsvx");

    IndexType info;
    LAPACK_IMPL(sptsvx)(&fact,
                        &n,
                        &nRhs,
                        d,
                        e,
                        df,
                        ef,
                        B,
                        &ldB,
                        X,
                        &ldX,
                        &rCond,
                        ferr,
                        berr,
                        work,
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}


template <typename IndexType>
IndexType
ptsvx(char                  fact,
      IndexType             n,
      IndexType             nRhs,
      const double          *d,
      const double          *e,
      double                *df,
      double                *ef,
      const double          *B,
      IndexType             ldB,
      double                *X,
      IndexType             ldX,
      double                &rCond,
      double                *ferr,
      double                *berr,
      double                *work)
{
    CXXLAPACK_DEBUG_OUT("dptsvx");

    IndexType info;
    LAPACK_IMPL(dptsvx)(&fact,
                        &n,
                        &nRhs,
                        d,
                        e,
                        df,
                        ef,
                        B,
                        &ldB,
                        X,
                        &ldX,
                        &rCond,
                        ferr,
                        berr,
                        work,
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}

template <typename IndexType>
IndexType
ptsvx(char                        fact,
      IndexType                   n,
      IndexType                   nRhs,
      const float                 *d,
      const std::complex<float >  *e,
      double                      *df,
      std::complex<float >        *ef,
      const std::complex<float >  *B,
      IndexType                   ldB,
      std::complex<float >        *X,
      IndexType                   ldX,
      float                       &rCond,
      float                       *ferr,
      float                       *berr,
      std::complex<float >        *work)
{
    CXXLAPACK_DEBUG_OUT("cptsvx");

    IndexType info;
    LAPACK_IMPL(cptsvx)(&fact,
                        &n,
                        &nRhs,
                        d,
                        reinterpret_cast<const float  *>(e),
                        df,
                        reinterpret_cast<float  *>(ef),
                        reinterpret_cast<const float  *>(B),
                        &ldB,
                        reinterpret_cast<float  *>(X),
                        &ldX,
                        &rCond,
                        ferr,
                        berr,
                        reinterpret_cast<float  *>(work),
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}

template <typename IndexType>
IndexType
ptsvx(char                        fact,
      IndexType                   n,
      IndexType                   nRhs,
      const double                *d,
      const std::complex<double>  *e,
      double                      *df,
      std::complex<double>        *ef,
      const std::complex<double>  *B,
      IndexType                   ldB,
      std::complex<double>        *X,
      IndexType                   ldX,
      double                      &rCond,
      double                      *ferr,
      double                      *berr,
      std::complex<double>        *work)
{
    CXXLAPACK_DEBUG_OUT("zptsvx");

    IndexType info;
    LAPACK_IMPL(zptsvx)(&fact,
                        &n,
                        &nRhs,
                        d,
                        reinterpret_cast<const double *>(e),
                        df,
                        reinterpret_cast<double *>(ef),
                        reinterpret_cast<const double *>(B),
                        &ldB,
                        reinterpret_cast<double *>(X),
                        &ldX,
                        &rCond,
                        ferr,
                        berr,
                        reinterpret_cast<double *>(work),
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}

} // namespace cxxlapack

#endif // CXXLAPACK_INTERFACE_PTSVX_TCC
