/*
 *  Copyright (C) 2007. QLogic Corporation. All Rights Reserved.
 */
/*
 * Copyright 2002, 2003, 2004, 2005, 2006 PathScale, Inc.  All Rights Reserved.
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


#pragma ident "@(#) libu/util/timef.c	92.1	07/07/99 13:18:33"

#include <fortran.h>
#include <unistd.h>
#include <sys/time.h>
/* In Linux <sys/time.h> this is ifdef'ed out */
#if 0 /* defined(KEY) && ! defined(BUILD_OS_DARWIN) */
/* It's unknown if OSX still requires this and BUILD_OS_DARWIN seems confusing to be required for Linux */
struct timezone
  {
    int tz_minuteswest;		/* Minutes west of GMT.  */
    int tz_dsttime;		/* Nonzero if DST is ever in effect.  */
  };
#endif

#ifndef	_WORD32
typedef long int64;
#else
typedef long long int64;
#endif

#ifdef _UNICOS
double		_sec_per_clock;		/* Seconds per clock tick */
#define MSECPERCLK ( _sec_per_clock * 1000.0 )
#elif  ! defined(__mips)
#define MSECPERCLK ( (double).001 )	/* gettimeofday has 1000000 ticks/sec */
#endif

/*
 *	TIMEF returns the elapsed wall-clock time in floating-point 
 *	milliseconds since the first call to TIMEF.  
 *
 *	NOTE (YMP systems):
 *
 *		Because the real-time clock value may exceed 48 bits, the 
 *		floating-point conversion done here often loses some precision.
 * 		The greatest possible error in the value returned by TIMEF is
 *		N seconds, where N is approximated by:
 *
 *		N = (machine clock period time in nanoseconds) * (1.4E-6)
 *
 *	Called from Fortran:
 *
 *		REAL TIMEF
 *
 *		x = TIMEF();
 *	or	CALL TIMEF(x)		UNICOS systems only
 */

#ifndef	__mips
_f_real
#ifdef	_UNICOS
TIMEF(_f_real *time)
#else
timef_(void)
#endif
{
	static int64	initial_rt = -1; /* Clock value from initial call */
	int64		rt, rtdif;
	double		retval;

#ifdef	_UNICOS
        if (_sec_per_clock == 0.0)
                _sec_per_clock = 1.0 / (double) sysconf(_SC_CLK_TCK);

	rt	= _rtc();
#else
	{
        struct timeval  buf;
	struct timezone	buf2;
	(void) gettimeofday (&buf, &buf2);
        rt = (long long)buf.tv_sec * 1000000LL + buf.tv_usec;
	}
#endif

	if (initial_rt < 0) {
		initial_rt	= rt;
		rtdif		= 0;
		/*
		 * force rtdif to 0 to prevent anomalies due to possible
		 * race conditions between 2 or more tasks calling TIMEF
		 * concurrently on the initial call.
		 */
	}
	else
		rtdif		= rt - initial_rt;

/*
 *	On pre-7.0 UNICOS CX/CEA systems and on all CRAY-2 systems the 
 *	real-time hardware clock is set to 0 on reboot.  If a restarted 
 *	process had called TIMEF before the system was brought down 
 *	and then after reboot, a negative difference in the real-time 
 *	clock value would be observed.  To minimize the impact of
 *	wrong timings being returned, we return 0 when this situation is 
 *	detected.
 */
	if (rtdif < 0) {
		initial_rt	= rt;
		rtdif		= 0;
	}

	retval	= (double) rtdif * MSECPERCLK;

#ifdef	_UNICOS
	if (_numargs() > 0)
		*time	= (_f_real) retval;
#endif

	return( (_f_real) retval);
}

#ifdef KEY /* Bug 12813 */
_f_real8
_Timef(void)
{
	static int64	initial_rt = -1; /* Clock value from initial call */
	int64		rt, rtdif;
	double		retval;

	{
        struct timeval  buf;
	struct timezone	buf2;
	(void) gettimeofday (&buf, &buf2);
        rt = (long long)buf.tv_sec * 1000000LL + buf.tv_usec;
	}

	if (initial_rt < 0) {
		initial_rt	= rt;
		rtdif		= 0;
		/*
		 * force rtdif to 0 to prevent anomalies due to possible
		 * race conditions between 2 or more tasks calling TIMEF
		 * concurrently on the initial call.
		 */
	}
	else
		rtdif		= rt - initial_rt;

/*
 *	On pre-7.0 UNICOS CX/CEA systems and on all CRAY-2 systems the 
 *	real-time hardware clock is set to 0 on reboot.  If a restarted 
 *	process had called TIMEF before the system was brought down 
 *	and then after reboot, a negative difference in the real-time 
 *	clock value would be observed.  To minimize the impact of
 *	wrong timings being returned, we return 0 when this situation is 
 *	detected.
 */
	if (rtdif < 0) {
		initial_rt	= rt;
		rtdif		= 0;
	}

	return (_f_real8) rtdif * MSECPERCLK;
}
#endif	/* KEY Bug 12813 */
#endif	/* ! __mips */

/*
 *	MIPS version is different from Sparc version.
 */
#ifdef	__mips 

extern double _nowrap_cycles_per_sec;

_f_real8
timef_(void)
{
	static int64	initial_rt = -1; /* Clock value from initial call */
	int64		rt, rtdif;
        static double msec_per_cycle;    /* reciprocal so we can multiply */

        if (msec_per_cycle == 0.0) {
                _init_hw_clock();
                msec_per_cycle = 1000.0 / _nowrap_cycles_per_sec;
        }

	rt = _sysclock_nowrap();

	if (initial_rt < 0) {
		initial_rt	= rt;
		rtdif		= 0;
		/*
		 * force rtdif to 0 to prevent anomalies due to possible
		 * race conditions between 2 or more tasks calling TIMEF
		 * concurrently on the initial call.
		 */
	}
	else
		rtdif		= rt - initial_rt;

	return  (_f_real8)rtdif * msec_per_cycle;
}

#endif	/* __mips */
