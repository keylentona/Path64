# Example cflags
# gcc -m64 -D_SGI_SOURCE -D_LANGUAGE_C -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -DCOMPILING_LOG10 -c     -D_IP_NAN_SETS_ERRNO -D_HDW_SQRT -DNO_LONG_DOUBLE -DPIC -I../include -I../../libmpath -I../../libmpath/../libm -I../../libmpath/amd -DFE_GNU_4_2_0  -DTARG_X8664 -DKEY  -Werror -std=gnu99 -D_GNU_SOURCE --include ../../libmpath/amd/hidden.h -D_libm_weak=1  -I../include  -O3 -LNO:vintr=0 -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD ../../libmpath/amd/w_logf.c -o w_log10f.c

SET(PATHSCALE_MPATH_SRCS        "w_copysignf.c"
				"w_copysign.c"
				"w_finitef.c"
				"w_finite.c"
				"w_fmaxf.c"
				"w_fmax.c"
				"w_fminf.c"
				"w_fmin.c"
				"w_fastcos.c"
				"w_fastexp.c"
				"w_fastexpf.c"
				"w_fastlog.c"
				"w_fastlogf.c"
				"w_fastlog10.c"
				"w_fastpow.c"
				"w_fastpowf.c"
				"w_fastsin.c"
				"w_fastsincos.c"
				"w_pow.c"
				"cis.c"
				"cisf.c"
				"pow_errorl.c"
				"remainder_piby2d2f.c"
				"s_atan2.c"
				"s_atan2f.c"
				"s_atan.c"
				"s_atanf.c"
				"s_ceil.c"
				"s_ceilf.c"
				"s_fdim.c"
				"s_fdimf.c"
				"s_floor.c"
				"s_floorf.c"
				"s_fma.c"
				"s_fmaf.c"
				"s_logb.c"
				"s_logbf.c"
				"s_modf.c"
				"s_modff.c"
				"s_tan.c"
				"s_tanf.c"
				"s_trunc.c"
				"s_truncf.c"
				"w_acos.c"
				"w_acosf.c"
				"w_asin.c"
				"w_asinf.c"
				"w_cosh.c"
				"w_coshf.c"
				"w_exp10.c"
				"w_exp10f.c"
				"w_exp2.c"
				"w_exp2f.c"
				"w_exp.c"
				"w_expf.c"
				"w_hypot.c"
				"w_hypotf.c"
				"w_powf.c"
				"w_remainder.c"
				"w_remainderf.c"
				"w_remainder_piby2.c"
				"w_remainder_piby2f.c"
				"w_sincos.c"
				"w_sincosf.c"
				"w_sinh.c"
				"w_sinhf.c"
				"w_tanh.c"
				"w_tanhf.c"
				"w_log2.c"
				"w_log2f.c"
				"w_log10.c"
				"w_log10f.c")

add_library(mpath STATIC ${PATHSCALE_MPATH_SRCS})
#set_property(TARGET pscrt-static PROPERTY OUTPUT_NAME pscrt)
# gcc -m64 -D_SGI_SOURCE -D_LANGUAGE_C -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -fpic -c     -D_IP_NAN_SETS_ERRNO -D_HDW_SQRT -DNO_LONG_DOUBLE -D_SW_PIPELINE -DPIC -I../include -I../../libmpath -I../../libmpath/../libm -I../../libmpath/amd -DFE_GNU_4_2_0  -DTARG_X8664 -DKEY   -std=gnu99 -D_GNU_SOURCE   -I../include  -O3 -LNO:vintr=0 -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD ../../libmpath/amd/vrsapowf.c -o vrsapowf.pic.o
# gcc -m64       -shared   -Wl,-x -Wl,-soname=libmv.so.1 -Wl,--version-script=../../libmpath/libmv.vs -o libmv.so.1 vrdacos.pic.o vrdaexp.pic.o vrdalog.pic.o vrdalog10.pic.o vrdasin.pic.o vrdasincos.pic.o vrsaexpf.pic.o vrsalogf.pic.o vrd2cos.pic.o vrd2cosh.pic.o vrd2exp.pic.o vrd2log.pic.o vrd2log10.pic.o vrd2pow.pic.o vrd4pow.pic.o vrd2sin.pic.o vrd2sincos.pic.o vrd2sinh.pic.o vrd4cos.pic.o vrd4exp.pic.o vrd4log.pic.o vrd4log10.pic.o vrd4sin.pic.o vrs4cosf.pic.o vrs4expf.pic.o vrs4log10f.pic.o vrs4logf.pic.o vrs4powf.pic.o vrs4sinf.pic.o vrs8expf.pic.o vrs8logf.pic.o vrs8powf.pic.o vacos.pic.o vacosf.pic.o vasin.pic.o vasinf.pic.o vatan.pic.o vatanf.pic.o vcis.pic.o vcisf.pic.o vcos.pic.o vcosf.pic.o vexp.pic.o vexpf.pic.o vlog.pic.o vlog10.pic.o vlog10f.pic.o vlogf.pic.o vsin.pic.o vsinf.pic.o vsqrt.pic.o vsqrtf.pic.o vtan.pic.o vtanf.pic.o vrdapow.pic.o vrsapowf.pic.o -lm
#ln -sf libmv.so.1 libmv.so

# gcc -m64 -D_SGI_SOURCE -D_LANGUAGE_C -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -c     -D_IP_NAN_SETS_ERRNO -D_HDW_SQRT -DNO_LONG_DOUBLE -D_SW_PIPELINE -DPIC -I../include -I../../libmpath -I../../libmpath/../libm -I../../libmpath/amd -DFE_GNU_4_2_0  -DTARG_X8664 -DKEY   -std=gnu99 -D_GNU_SOURCE   -I../include  -O3 -LNO:vintr=0 -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD ../../libmpath/amd/vrsapowf.c -o vrsapowf.o

# ar cru libmv.a vrdacos.o vrdaexp.o vrdalog.o vrdalog10.o vrdasin.o vrdasincos.o vrsaexpf.o vrsalogf.o vrd2cos.o vrd2cosh.o vrd2exp.o vrd2log.o vrd2log10.o vrd2pow.o vrd4pow.o vrd2sin.o vrd2sincos.o vrd2sinh.o vrd4cos.o vrd4exp.o vrd4log.o vrd4log10.o vrd4sin.o vrs4cosf.o vrs4expf.o vrs4log10f.o vrs4logf.o vrs4powf.o vrs4sinf.o vrs8expf.o vrs8logf.o vrs8powf.o vacos.o vacosf.o vasin.o vasinf.o vatan.o vatanf.o vcis.o vcisf.o vcos.o vcosf.o vexp.o vexpf.o vlog.o vlog10.o vlog10f.o vlogf.o vsin.o vsinf.o vsqrt.o vsqrtf.o vtan.o vtanf.o vrdapow.o vrsapowf.o

# gcc -m64 -D_SGI_SOURCE -D_LANGUAGE_C -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -pg -c     -D_IP_NAN_SETS_ERRNO -D_HDW_SQRT -DNO_LONG_DOUBLE -D_SW_PIPELINE -DPIC -I../include -I../../libmpath -I../../libmpath/../libm -I../../libmpath/amd -DFE_GNU_4_2_0  -DTARG_X8664 -DKEY   -std=gnu99 -D_GNU_SOURCE   -I../include  -O3 -LNO:vintr=0 -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD ../../libmpath/amd/vrsapowf.c -o vrsapowf.pg.o
# ar cru libmv_p.a vrdacos.pg.o vrdaexp.pg.o vrdalog.pg.o vrdalog10.pg.o vrdasin.pg.o vrdasincos.pg.o vrsaexpf.pg.o vrsalogf.pg.o vrd2cos.pg.o vrd2cosh.pg.o vrd2exp.pg.o vrd2log.pg.o vrd2log10.pg.o vrd2pow.pg.o vrd4pow.pg.o vrd2sin.pg.o vrd2sincos.pg.o vrd2sinh.pg.o vrd4cos.pg.o vrd4exp.pg.o vrd4log.pg.o vrd4log10.pg.o vrd4sin.pg.o vrs4cosf.pg.o vrs4expf.pg.o vrs4log10f.pg.o vrs4logf.pg.o vrs4powf.pg.o vrs4sinf.pg.o vrs8expf.pg.o vrs8logf.pg.o vrs8powf.pg.o vacos.pg.o vacosf.pg.o vasin.pg.o vasinf.pg.o vatan.pg.o vatanf.pg.o vcis.pg.o vcisf.pg.o vcos.pg.o vcosf.pg.o vexp.pg.o vexpf.pg.o vlog.pg.o vlog10.pg.o vlog10f.pg.o vlogf.pg.o vsin.pg.o vsinf.pg.o vsqrt.pg.o vsqrtf.pg.o vtan.pg.o vtanf.pg.o vrdapow.pg.o vrsapowf.pg.o
