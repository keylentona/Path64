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


/* $Header$ */

#include <cmplrs/host.h>

int32
i_sign (int32 *a, int32 *b)
{
    int32 x;
    x = (*a >= 0 ? *a : - *a);
    return( *b >= 0 ? x : -x);
}

int32
__isign (int32 a, int32 b)
{
    int32 x;
    x = (a >= 0 ? a : - a);
    return( b >= 0 ? x : -x);
}
