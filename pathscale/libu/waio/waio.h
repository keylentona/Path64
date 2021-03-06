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


/* USMID @(#) libu/waio/waio.h	92.0	10/08/98 14:57:41 */

 
#include <ffio.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/iosw.h>
 
/*
 * Define the max number of total datasets that can be opened by the
 * WAIO, DRIO, and MSIO packages combined.
 */
extern int	_dsnmax_d;	/* tunable DRIO max value */
extern int	_dsnmax_w;	/* tunable WAIO/MSIO value */
extern int	G@DSNMAXW;	/* WAIO/MSIO max location*/
extern int	G@DSNMAXD;	/* DRIO max location */
#define DSNMAX	(G@DSNMAXW + G@DSNMAXD)

#define NWPBLK		512	/* Buffer block size in words		*/
#define L2NWPBLK	9	/* Log base 2 of NWPBLK                 */
#define NBPBLK		4096	/* Buffer block size in bytes		*/
#define L2NBPBLK	12	/* Log base 2 of NBPBLK			*/
#define NBPW		8	/* Number of bytes per word		*/
#define WA_NAMLEN	8	/* No. of characters of name stored	*/

#define MAXRECALL	1000000

#define WAIO_ERROR(x)	((x)->wa_iosw.sw_error)

/*
 * Note that we need to check both sw_flag and FFSTAT, because we might
 * be doing 'real' syscalls.
 */

#ifdef	_CRAY2
#define WAIO_BUSY(x)	((x)->wa_iosw.sw_flag == 0)
#else
#define WAIO_BUSY(x)	((x)->wa_iosw.sw_flag == 0 || FFSTAT((x)->wa_iosw) == 0)
#endif

#define WAITWAIO(f) {							\
		int  wt_ct = 0;						\
/*									\
 *	If i/o is still busy, go into recall until the request		\
 *	has been completed.						\
 */									\
		while ( WAIO_BUSY(f) ) {				\
			if (f->wa_fdc != 0) {				\
				struct fdinfo *fio;			\
				struct ffsw locstat;			\
				fio = GETIOB(f->wa_fd);			\
				XRCALL(fio, fcntlrtn)			\
					fio, FC_RECALL,			\
					&f->wa_iosw, &locstat);		\
			}						\
			else {						\
				struct iosw	*status;		\
				status = (struct iosw *)&(f->wa_iosw);	\
				(void) recall(f->wa_fd, 1, &status);	\
			}						\
			if (wt_ct++ > MAXRECALL) {			\
				_lerror(_LELVL_ABORT, FEINTUNK);	\
			}						\
		}							\
	}

/*
 *	Word Addressable File Table
 */
typedef struct {
	int		wa_fd;	 	/* System file descriptor */
	char	     wa_idn[WA_NAMLEN];	/* Internal file name for error 
					 * messages.  Null terminated, unless
					 * the name is a full 8 characters. */
	char		*wa_buffer;	/* Pointer to waio file buffer */
	struct fflistreq wa_list;	/* Re-used list for listio requests */
	struct ffsw	wa_iosw;	/* Status word for asynch i/o */

	int		wa_fdc;		/* Flag use of FDC routines in WA */
	void		*wa_up;		/* Pointer to entry in unit table */
} WAFIL;

extern	WAFIL 	*wafils;

extern	void	_errwa();
extern	void	_errwa_abort();
