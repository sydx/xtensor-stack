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

#ifndef CXXLAPACK_INTERFACE_SPGVX_H
#define CXXLAPACK_INTERFACE_SPGVX_H 1

#include <cxxstd/complex.h>

namespace cxxlapack {

template <typename IndexType>
    IndexType
    spgvx(IndexType             itype,
          char                  jobz,
          char                  range,
          char                  uplo,
          IndexType             n,
          float                 *Ap,
          float                 *Bp,
          float                 vl,
          float                 vu,
          IndexType             il,
          IndexType             iu,
          float                 abstol,
          IndexType             &m,
          float                 *w,
          float                 *Z,
          IndexType             ldZ,
          float                 *work,
          IndexType             *iWork,
          IndexType             *ifail);

template <typename IndexType>
    IndexType
    spgvx(IndexType             itype,
          char                  jobz,
          char                  range,
          char                  uplo,
          IndexType             n,
          double                *Ap,
          double                *Bp,
          double                vl,
          double                vu,
          IndexType             il,
          IndexType             iu,
          double                abstol,
          IndexType             &m,
          double                *w,
          double                *Z,
          IndexType             ldZ,
          double                *work,
          IndexType             *iWork,
          IndexType             *ifail);

} // namespace cxxlapack

#endif // CXXLAPACK_INTERFACE_SPGVX_H
