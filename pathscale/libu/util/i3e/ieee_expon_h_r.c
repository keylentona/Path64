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


#pragma ident "@(#) libu/util/i3e/ieee_expon_h_r.c	92.1	07/07/99 14:37:09"
#include <fenv.h>
#include <fp.h>
#include "i3eintrin.h"

extern float _IEEE_EXPONENT_H_R(double x);
/* _IEEE_EXPONENT_H_R - IEEE EXPONENT returns the exponent part of the
 *                       64-bit argument in 32-bit float result.
 *
 * IEEE_EXPONENT(X,Y_R4) returns real(kind=4)result
 */
#pragma _CRI duplicate _IEEE_EXPONENT_H_R as _IEEE_LOGB_H_R
float
_IEEE_EXPONENT_H_R(double x)
{
	/* Union defined to work with IEEE 32 bit floating point. */
	union _ieee_float {
		float	dword;
		int	lword;
		struct {
#if defined(_LITTLE_ENDIAN)
			unsigned int mantissa	: IEEE_32_MANT_BITS;
			unsigned int exponent	: IEEE_32_EXPO_BITS;
			unsigned int sign	: 1;
#else
			unsigned int sign	: 1;
			unsigned int exponent	: IEEE_32_EXPO_BITS;
			unsigned int mantissa	: IEEE_32_MANT_BITS;
#endif
		} fparts;
	};
	union _ieee_double {
		double	dwrd;
		long long lwrd;
		struct {
#if defined(_LITTLE_ENDIAN)
			unsigned int mantissa	: IEEE_64_MANT_BITS;
			unsigned int expon	: IEEE_64_EXPO_BITS;
			unsigned int sgn	: 1;
#else
			unsigned int sgn	: 1;
			unsigned int expon	: IEEE_64_EXPO_BITS;
			unsigned int mantissa	: IEEE_64_MANT_BITS;
#endif
		} parts;
	};
	switch (_fpclassify(x)) {
		case FP_NAN:
			{
			union _ieee_float x_val;
			x_val.lword	= _HALF_NaN;
			return(x_val.dword);
			}
		case FP_INFINITE:
			{
			union _ieee_float x_val;
			x_val.lword	= IEEE_32_INFINITY;
			return(x_val.dword);
			}
		case FP_NORMAL:
			{
			union _ieee_double x_val;
			x_val.dwrd	= x;
			return(x_val.parts.expon - IEEE_64_EXPO_BIAS);
			}
		case FP_SUBNORMAL:
			{
			union _ieee_double x_val;
			int y;
			x_val.dwrd	= x;

			/* _leadz returns number of zeros before first 1
			 * in mantissa. Add IEEE_64_EXPO_BITS to exclude
			 * exponent bits, but count sign bit since
			 * implicit bit needs to be counted.
			 */
			return(-IEEE_64_EXPO_BIAS -
				_leadz(x_val.parts.mantissa) +
				IEEE_64_EXPO_BITS);
			}

		case FP_ZERO:
			{
			int j;
			union _ieee_float x_val;
			/* raise divide-by-zero exception */
			j		= FE_DIVBYZERO;
			feraiseexcept(j);

			/* return negative infinity */
			x_val.lword	= IEEE_32_INFINITY;
			x_val.fparts.sign	= 1;
			return(x_val.dword);
			}
	}
}
