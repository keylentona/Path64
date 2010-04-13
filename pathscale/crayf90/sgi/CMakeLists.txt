# This should build mfef95
# If mfef95 is not installed then build with gfortran
# If you build with gfortran, build mfef95-fake that links against
# libgfortran first and then use mfef95-fake to build mfef95 that
# links against libpathfortran
# Right now config.cxx and many other files are built twice or even four times because of strange -D defines

set(PATHSCALE_MFEF95_SRCS       "../../common/com/config.cxx"
				"../../common/com/const.cxx"
				"../../common/com/controls.cxx"
				"../../common/com/dwarf_DST.cxx"
				"../../common/com/dwarf_DST_dump.cxx"
				"../../common/com/dwarf_DST_mem.cxx"
				"../../common/com/dwarf_DST_producer.cxx"
				"../../common/com/err_host.cxx"
				"../../common/com/f90_utils.cxx"
				"../../common/com/glob.cxx"
				"../../common/com/ir_bcom.cxx"
				"../../common/com/ir_bwrite.cxx"
				"../../common/com/ir_reader.cxx"
				"../../common/com/irbdata.cxx"
				"../../common/com/mtypes.cxx"
				"../../common/com/opcode.cxx"
				"../../common/com/opcode_core.cxx"
				"../../common/com/pu_info.cxx"
				"../../common/com/strtab.cxx"
				"../../common/com/symtab.cxx"
				"../../common/com/symtab_verify.cxx"
				"../../common/com/ttype.cxx"
				"../../common/com/wn.cxx"
				"../../common/com/wn_map.cxx"
				"../../common/com/wn_pragmas.cxx"
				"../../common/com/wn_simp.cxx"
				"../../common/com/wn_util.cxx"
				"../../common/com/wutil.cxx"
				"../../common/com/x8664/config_targ.cxx"
				"../../common/com/x8664/config_elf_targ.cxx"
				"../../common/com/x8664/targ_const.cxx"
				"../../common/com/x8664/targ_sim.cxx"
				"../../crayf90/sgi/cwh_unimp.cxx"
				"../../crayf90/sgi/cwh_addr.cxx"
				"../../crayf90/sgi/cwh_auxst.cxx"
				"../../crayf90/sgi/cwh_block.cxx"
				"../../crayf90/sgi/cwh_data.cxx"
				"../../crayf90/sgi/cwh_directive.cxx"
				"../../crayf90/sgi/cwh_dope.cxx"
				"../../crayf90/sgi/cwh_dst.cxx"
				"../../crayf90/sgi/cwh_expr.cxx"
				"../../crayf90/sgi/cwh_intrin.cxx"
				"../../crayf90/sgi/cwh_io.cxx"
				"../../crayf90/sgi/cwh_mkdepend.cxx"
				"../../crayf90/sgi/cwh_pdgcs.cxx"
				"../../crayf90/sgi/cwh_preg.cxx"
				"../../crayf90/sgi/cwh_types.cxx"
				"../../crayf90/sgi/cwh_stab.cxx"
				"../../crayf90/sgi/cwh_stmt.cxx"
				"../../crayf90/sgi/cwh_stk.cxx"
				"../../crayf90/sgi/decorate_utils.cxx"
				"../../crayf90/sgi/f2c_abi_utils.cxx"
				"../../crayf90/sgi/sgi_cmd_line.cxx"
				"../../crayf90/sgi/sgi_cmd_line.h
				"../../crayf90/sgi/path_intrinsic_list.cxx"
				"../../crayf90/sgi/make_depend.cxx"
				"../../common/com/x8664/config_host.c"
				"../../common/com/x8664/config_platform.c")

# final linking command
# gcc -D_SGI_SOURCE -D_LANGUAGE_C -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -c     -DSGI_DIRS -Dlonglong -DSGI_MONGOOSE -DFRONT_END -DFRONT_F90 -D_PDGCS  -DUSE_STANDARD_TYPES -D __MIPS_AND_IA64_ELF_H -Dlinux -D__USE_BSD -D_GNU_SOURCE -D_LONGLONG -D_SVR4_SOURCE   -D_SGI_SGI -D_TARGET_MONGOOSE -D_SGI_WHIRLCONVERT -I../../../crayf90/fe90 -I../../../crayf90/sgi -I../../../common/com -I../../../common/util -I../../../common/com/x8664 -I. -I../../../include -I../../../linux/mfef90_includes -I../../../linux/include -I../../include/cmplrs -I/usr/include -DCROSS_COMPILATION -DFE_GNU_4_2_0   -DTARG_X8664 -DKEY  -Werror -std=gnu99 -D_GNU_SOURCE  -I../../include  -g -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD compiler_build_date.c -o compiler_build_date.c
# g++ -D_SGI_SOURCE -D_LANGUAGE_C_PLUS_PLUS -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -D_NOTHREADS       -DSGI_DIRS -Dlonglong -DSGI_MONGOOSE -DFRONT_END -DFRONT_F90 -D_PDGCS  -DUSE_STANDARD_TYPES -D __MIPS_AND_IA64_ELF_H -Dlinux -D__USE_BSD -D_GNU_SOURCE -D_LONGLONG -D_SVR4_SOURCE   -D_SGI_SGI -D_TARGET_MONGOOSE -D_SGI_WHIRLCONVERT -I../../../crayf90/fe90 -I../../../crayf90/sgi -I../../../common/com -I../../../common/util -I../../../common/com/x8664 -I. -I../../../include -I../../../linux/mfef90_includes -I../../../linux/include -I../../include/cmplrs -I/usr/include -DCROSS_COMPILATION -DFE_GNU_4_2_0   -DTARG_X8664 -DKEY  -Werror     -I../../include  -g -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD -o mfef95  config.c const.c controls.c dwarf_DST.c dwarf_DST_dump.c dwarf_DST_mem.c dwarf_DST_producer.c err_host.c f90_utils.c glob.c ir_bcom.c ir_bwrite.c ir_reader.c irbdata.c mtypes.c opcode.c opcode_core.c pu_info.c strtab.c symtab.c symtab_verify.c ttype.c wn.c wn_map.c wn_pragmas.c wn_simp.c wn_util.c wutil.c config_targ.c config_elf_targ.c targ_const.c targ_sim.c cwh_unimp.c cwh_addr.c cwh_auxst.c cwh_block.c cwh_data.c cwh_directive.c cwh_dope.c cwh_dst.c cwh_expr.c cwh_intrin.c cwh_io.c cwh_mkdepend.c cwh_pdgcs.c cwh_preg.c cwh_types.c cwh_stab.c cwh_stmt.c cwh_stk.c decorate_utils.c f2c_abi_utils.c sgi_cmd_line.c path_intrinsic_list.c make_depend.c config_host.c config_platform.c        compiler_build_date.c  -L./    

# Linking libs
# ../../libcomutil/libcomutil.a ../fe90/fe90.a ../../arith/arith.a ../../libcif/libcif.a /usr/local/src/cb/path64-hg/pathscale/targx8664_builtonia32/libm/libmpath.a /usr/local/src/cb/path64-hg/pathscale/targx8664_builtonia32/libfoobar/libpathfortran.a -L/usr/ia32-sgi-linux/bin -lm   -D_MIPSEL -DTARG_LINUX /usr/local/src/cb/path64-hg/pathscale/targx8664_builtonia32/libm/libmpath.a /usr/local/src/cb/path64-hg/pathscale/targx8664_builtonia32/libfoobar/libpathfortran.a 

add_executable (mfef95 ${PATHSCALE_MFEF95_SRCS})
target_link_libraries (mfef95 comutil fe90 arith cif mpath pathfortran m)
