/*
 * Copyright (C) 2007. PathScale, LLC. All Rights Reserved.
 */
/*
 * Copyright 2004, 2005, 2006 PathScale, Inc.  All Rights Reserved.
 */

/*

  Copyright (C) 2000, 2001 Silicon Graphics, Inc.  All Rights Reserved.

   Path64 is free software; you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation version 2.1

   Path64 is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with Path64; see the file COPYING.  If not, write to the Free
   Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.

   Special thanks goes to SGI for their continued support to open source

*/


#pragma ident "@(#) libfi/matrix/matmul_c4i1.c	92.1	07/09/99 15:18:08"
#include "matmul.h"

/*
 * Name of this entry point
 */
#if defined(BUILD_COMPILER_GNU)
#define NAME underscore_matmul_c4i1
#else /* defined(BUILD_COMPILER_GNU) */
#define NAME _MATMUL_C4I1
#endif /* defined(BUILD_COMPILER_GNU) */
/*
 * Name of routine called do computation (if any)
 */
#if defined(BUILD_COMPILER_GNU) && defined(BUILD_OS_DARWIN)
#define SUBNAME underscore_i1s4gemmx__
#else /* defined(BUILD_COMPILER_GNU) && defined(BUILD_OS_DARWIN) */
#define SUBNAME _i1s4gemmx__
#endif /* defined(BUILD_COMPILER_GNU) && defined(BUILD_OS_DARWIN) */

/*
 * Type of constants alpha and beta
 */
#define RESULTTYPE	_f_real4

#if defined(_UNICOS)
#pragma _CRI duplicate _MATMUL_CI as MATMUL_CI@
#endif
void
NAME(DopeVectorType *RESULT, DopeVectorType *MATRIX_A, 
	DopeVectorType *MATRIX_B)
{
    void    SUBNAME();
    const RESULTTYPE   one =  (RESULTTYPE) 1.0;
    const RESULTTYPE   zero = (RESULTTYPE) 0.0;
    RESULTTYPE *Ar, *Ai;
    RESULTTYPE *Cr, *Ci;
    MatrixDimenType matdimdata, *MATDIM;

        MATDIM = (MatrixDimenType *) &matdimdata;

    /*
     * Parse dope vectors, and perform error checking.
     */

    _premult(RESULT, MATRIX_A, MATRIX_B, MATDIM);

    /*
     * Do real and imaginary parts separately.
     */

    Ar = (RESULTTYPE *) MATDIM->A;
    Ai = Ar + 1;
    MATDIM->inc1a *= 2;
    MATDIM->inc2a *= 2;

    Cr = (RESULTTYPE *) MATDIM->C;
    Ci = Cr + 1;
    MATDIM->inc1c *= 2;
    MATDIM->inc2c *= 2;

    /*
     * Perform the matrix multiplication.
     * Do the transposed problem C' = B'*A'
     */

    /* real part */
    SUBNAME(&MATDIM->n, &MATDIM->m, &MATDIM->k, &one, MATDIM->B, &MATDIM->inc2b,
    	    &MATDIM->inc1b, Ar,&MATDIM->inc2a,&MATDIM->inc1a,
	    &zero, Cr,&MATDIM->inc2c,&MATDIM->inc1c);
    /* imaginary part */
    SUBNAME(&MATDIM->n, &MATDIM->m, &MATDIM->k, &one, MATDIM->B, &MATDIM->inc2b,
    	    &MATDIM->inc1b, Ai,&MATDIM->inc2a,&MATDIM->inc1a,
	    &zero, Ci,&MATDIM->inc2c,&MATDIM->inc1c);
    return;
}
