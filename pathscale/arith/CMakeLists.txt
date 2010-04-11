# build arith.a and a couple custom commands
#cp -f $compiler/arith/arith.cat $LIB/
#cp -f $compiler/arith/arith.i $LIB/arith.msgs

# gcc -D_SGI_SOURCE -D_LANGUAGE_C -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -c      -I../../arith  -ansi -DTARG_IA64 -I. -I../../clibinc -D_LITTLE_ENDIAN -D__mips -DCROSS_COMPILATION -DFE_GNU_4_2_0   -DTARG_X8664 -DKEY  -Werror -std=gnu99 -D_GNU_SOURCE  -I../include  -g -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD ../../arith/cray1_sim.c -o cray1_sim.o
# /opt/pathscale/bin/pathf90 -DMIPSEL -DTARG_LINUX -g  -c ../../arith/fintrin_dc_irix_tmp.f
# /opt/pathscale/bin/pathf90 -DMIPSEL -DTARG_LINUX -g  -c ../../arith/fintrin_irix_tmp.f
# ar cru arith.a bits.o compare.o convert.o cray_fadd.o cray_fdiv.o cray_fmul.o cvt.o edition.o ieee_fadd.o ieee_fdiv.o ieee_fmul.o ieee_norm.o ieee_sqrt.o intrin.o math.o miscmath.o strcvt.o native.o test_ar_intrin.o cray1_sim.o fintrin_dc_irix_tmp.o fintrin_irix_tmp.o
