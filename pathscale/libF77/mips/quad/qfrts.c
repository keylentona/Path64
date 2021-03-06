/*

  Copyright (C) 2000, 2001 Silicon Graphics, Inc.  All Rights Reserved.

   Path64 is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

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


#include <stdarg.h>
#include <cmplrs/host.h>

#ifdef MFEF77_C
	/* include these only if support for mfef77 ftn->c is needed */
#include <libftn.h>

long double __qmax(int argcnt, ...)
{
  long double  arg, maxarg;
  va_list ap;

  va_start(ap, argcnt);
  maxarg = va_arg(ap, double);
  while (--argcnt > 0) {
    arg = va_arg(ap, double);
    if (arg > maxarg) maxarg = arg;
  }  /* while */
  va_end(ap);
  return maxarg;
}  /* __qmax */

long double __qmin(int argcnt, ...)
{
  long double  arg, minarg;
  va_list ap;

  va_start(ap, argcnt);
  minarg = va_arg(ap, double);
  while (--argcnt > 0) {
    arg = va_arg(ap, double);
    if (arg < minarg) minarg = arg;
  }  /* while */
  va_end(ap);
  return minarg;
}  /* __qmin */

struct _cpx_float _cpx_make_float_from_long_double(struct _cpx_long_double q)
{
  struct _cpx_float t;
  t.r = q.r;
  t.i = q.i;
  return t;
}  /* _cpx_make_float_from_long_double */

struct _cpx_double _cpx_make_double_from_long_double(struct _cpx_long_double q)
{
  struct _cpx_double t;
  t.r = q.r;
  t.i = q.i;
  return t;
}  /* _cpx_make_double_from_long_double */

int _xeq_long_double(struct _cpx_long_double a, struct _cpx_long_double b)
{
  return a.r == b.r && a.i == b.i;
}  /* _xeq_long_double */

int _xne_long_double(struct _cpx_long_double a, struct _cpx_long_double b)
{
  return a.r != b.r || a.i != b.i;
}  /* _xne_long_double */

struct _cpx_long_double _cpx_long_double(long double r, long double i)
{
  struct _cpx_long_double t;
  t.r = r;
  t.i = i;
  return t;
}  /* _cpx_long_double */

struct _cpx_long_double _cpx_make_long_double_from_float(struct _cpx_float f)
{
  struct _cpx_long_double t;
  t.r = f.r;
  t.i = f.i;
  return t;
}  /* _cpx_make_long_double_from_float */

struct _cpx_long_double _cpx_make_long_double_from_double(struct _cpx_double d)
{
  struct _cpx_long_double t;
  t.r = d.r;
  t.i = d.i;
  return t;
}  /* _cpx_make_long_double_from_double */

struct _cpx_long_double _xnegate_long_double(struct _cpx_long_double a)
{
  struct _cpx_long_double t;
  t.r = -a.r;
  t.i = -a.i;
  return t;
}  /* _xnegate_long_double */

struct _cpx_long_double _xadd_long_double(struct _cpx_long_double a, struct _cpx_long_double b)
{
  struct _cpx_long_double t;
  t.r = a.r + b.r;
  t.i = a.i + b.i;
  return t;
}  /* _xadd_long_double */

struct _cpx_long_double _xsubtract_long_double(struct _cpx_long_double a, struct _cpx_long_double b)
{
  struct _cpx_long_double t;
  t.r = a.r - b.r;
  t.i = a.i - b.i;
  return t;
}  /* _xsubtract_long_double */

struct _cpx_long_double _xmultiply_long_double(struct _cpx_long_double a, struct _cpx_long_double b)
{
  struct _cpx_long_double t;
  t.r = a.r*b.r - a.i*b.i;
  t.i = a.i*b.r + a.r*b.i;
  return t;
}  /* _xmultiply_long_double */

struct _cpx_long_double _xdivide_long_double(struct _cpx_long_double a, struct _cpx_long_double b)
{
  struct _cpx_long_double t;
  long double d = b.r*b.r+b.i*b.i;
  t.r = (a.r*b.r+a.i*b.i)/d;
  t.i = (a.i*b.r-a.r*b.i)/d;
  return t;
}  /* _xdivide_long_double */

/* Hack alert:  The complex exponentation functions take a pointer to the
   result as the first parameter.  Since c_gen_be.c doesn't realize it's
   a complex exponentiation until it's already put out the left hand side
   of the assignment statement, it was easiest to just code these stub
   routines to call the real functions. */

struct _cpx_long_double pow_cqi_stub(struct _cpx_long_double *a, int *b)
{
struct _cpx_long_double temp;
__pow_cqi(&temp,a,b);
return temp;
}

struct _cpx_long_double pow_cql_stub(struct _cpx_long_double *a, long long *b)
{
struct _cpx_long_double temp;
__pow_cql(&temp,a,b);
return temp;
}

struct _cpx_long_double pow_cq_stub(struct _cpx_long_double *a, struct _cpx_long_double *b)
{
struct _cpx_long_double temp;
__cq_pow(&temp,a,b);
return temp;
}
#endif /* MFEF77_C */

