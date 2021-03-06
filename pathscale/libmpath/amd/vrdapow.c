/*
Copyright (c) 2005 PathScale, Inc.  All rights reserved.
Unpublished -- rights reserved under the copyright laws of the United
States. USE OF A COPYRIGHT NOTICE DOES NOT IMPLY PUBLICATION OR
DISCLOSURE. THIS SOFTWARE CONTAINS CONFIDENTIAL INFORMATION AND TRADE
SECRETS OF PATHSCALE, INC. USE, DISCLOSURE, OR REPRODUCTION IS
PROHIBITED WITHOUT THE PRIOR EXPRESS WRITTEN PERMISSION OF PATHSCALE,
INC.

U.S. Government Restricted Rights:
The Software is a "commercial item," as that term is defined at 48
C.F.R. 2.101 (OCT 1995), consisting of "commercial computer software"
and "commercial computer software documentation," as such terms are used
in 48 C.F.R. 12.212 (SEPT 1995).  Consistent with 48 C.F.R. 12.212 and
48 C.F.R. 227-7202-1 through 227-7202-4 (JUNE 1995), all U.S. Government
End Users acquire the Software with only those rights set forth in the
accompanying license agreement. PathScale, Inc. 477 N. Mathilda Ave;
Sunnyvale, CA 94085.
*/

/* In the absence of an assembly version of vrda_pow, this is a simple
 * vector wrapper around fastpow. */

#include "libm_amd.h"

extern double fastpow (double x, double y);

void __vrda_pow (long n, double *x, double *y, double *z)
{
  long i;
  for (i=0; i<n; i++) {
    z[i] = fastpow(x[i], y[i]);
  }
}

void vrda_pow (long n, double *x, double *y, double *z)
     __attribute__ ((weak, alias("__vrda_pow")));
