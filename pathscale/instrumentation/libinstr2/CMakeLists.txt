# CFLAGS should be like
# #g++ -m64 -D_SGI_SOURCE -D_LANGUAGE_C_PLUS_PLUS -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -D_NOTHREADS -c           -Dsgi -Dlonglong -D_LONGLONG -D_SVR4_SOURCE -D_USE_PROFILE_ERROR_ROUTINES  -I../../instrumentation/libinstr2 -I../../common/instrument -I../../common/com -DFE_GNU_4_2_0  -DTARG_X8664 -DKEY  -Werror   -I../include  -g -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD -O2 -fno-exceptions -nostdinc++ -fno-unwind-tables -D_INCLUDED_FROM_LIBINSTR_ ../../instrumentation/libinstr2/profile_interface.cxx -o profile_interface.cxx

SET(PATHSCALE_INSTR2_SRCS       "dump.cxx"
				"profile.cxx"
				"../../common/instrument/profile_errors.cxx"
				"profile_interface.cxx")

INCLUDE_DIRECTORIES(
	.
	../../common/instrument
	../../common/com
	../include)

add_library(instr STATIC ${PATHSCALE_INSTR2_SRCS})
