      INTEGER FUNCTION ILAZLR( M, N, A, LDA )
      IMPLICIT NONE
*
*  -- LAPACK auxiliary routine (version 3.3.1)                        --
*  -- LAPACK is a software package provided by Univ. of Tennessee,    --
*  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
*  -- April 2011                                                      --
*     .. Scalar Arguments ..
      INTEGER            M, N, LDA
*     ..
*     .. Array Arguments ..
      COMPLEX*16         A( LDA, * )
*     ..
*
*  Purpose
*  =======
*
*  ILAZLR scans A for its last non-zero row.
*
*  Arguments
*  =========
*
*  M       (input) INTEGER
*          The number of rows of the matrix A.
*
*  N       (input) INTEGER
*          The number of columns of the matrix A.
*
*  A       (input) COMPLEX*16 array, dimension (LDA,N)
*          The m by n matrix A.
*
*  LDA     (input) INTEGER
*          The leading dimension of the array A. LDA >= max(1,M).
*
*  =====================================================================
*
*     .. Parameters ..
      COMPLEX*16       ZERO
      PARAMETER ( ZERO = (0.0D+0, 0.0D+0) )
*     ..
*     .. Local Scalars ..
      INTEGER I, J
*     ..
*     .. Executable Statements ..
*
*     Quick test for the common case where one corner is non-zero.
      IF( M.EQ.0 ) THEN
         ILAZLR = M
      ELSE IF( A(M, 1).NE.ZERO .OR. A(M, N).NE.ZERO ) THEN
         ILAZLR = M
      ELSE
*     Scan up each column tracking the last zero row seen.
         ILAZLR = 0
         DO J = 1, N
            I=M
            DO WHILE ((A(I,J).EQ.ZERO).AND.(I.GE.1))
              I=I-1
            ENDDO         
            ILAZLR = MAX( ILAZLR, I )
         END DO
      END IF
      RETURN
      END
