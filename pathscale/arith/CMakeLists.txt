# build arith.a and a couple custom commands
#cp -f $compiler/arith/arith.cat $LIB/
#cp -f $compiler/arith/arith.i $LIB/arith.msgs

# gcc -D_SGI_SOURCE -D_LANGUAGE_C -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -c      -I../../arith  -ansi -DTARG_IA64 -I. -I../../clibinc -D_LITTLE_ENDIAN -D__mips -DCROSS_COMPILATION -DFE_GNU_4_2_0   -DTARG_X8664 -DKEY  -Werror -std=gnu99 -D_GNU_SOURCE  -I../include  -g -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD ../../arith/cray1_sim.c -o cray1_sim.c
# /opt/pathscale/bin/pathf90 -DMIPSEL -DTARG_LINUX -g  -c ../../arith/fintrin_dc_irix_tmp.f
# /opt/pathscale/bin/pathf90 -DMIPSEL -DTARG_LINUX -g  -c ../../arith/fintrin_irix_tmp.f
# ar cru arith.a

SET(PATHSCALE_ARITH_SRCS        "bits.c"
				"compare.c"
				"convert.c"
				"cray_fadd.c"
				"cray_fdiv.c"
				"cray_fmul.c"
				"cvt.c"
				"edition.c"
				"ieee_fadd.c"
				"ieee_fdiv.c"
				"ieee_fmul.c"
				"ieee_norm.c"
				"ieee_sqrt.c"
				"intrin.c"
				"math.c"
				"miscmath.c"
				"strcvt.c"
				"native.c"
				"test_ar_intrin.c"
				"cray1_sim.c"
				"fintrin_dc_irix_tmp.c"
				"fintrin_irix_tmp.c")

add_library(arith STATIC ${PATHSCALE_ARITH_SRCS})
