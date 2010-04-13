# This should build mfef95
# If mfef95 is not installed then build with gfortran
	# If you build with gfortran, build mfef95-fake that links against
	# libgfortran first and then use mfef95-fake to build mfef95 that
	# links against libpathfortran

set(PATHSCALE_MFEF95_SRCS       "config.cxx"
				"const.cxx"
				"controls.cxx"
				"dwarf_DST.cxx"
				"dwarf_DST_dump.cxx"
				"dwarf_DST_mem.cxx"
				"dwarf_DST_producer.cxx"
				"err_host.cxx"
				"f90_utils.cxx"
				"glob.cxx"
				"ir_bcom.cxx"
				"ir_bwrite.cxx"
				"ir_reader.cxx"
				"irbdata.cxx"
				"mtypes.cxx"
				"opcode.cxx"
				"opcode_core.cxx"
				"pu_info.cxx"
				"strtab.cxx"
				"symtab.cxx"
				"symtab_verify.cxx"
				"ttype.cxx"
				"wn.cxx"
				"wn_map.cxx"
				"wn_pragmas.cxx"
				"wn_simp.cxx"
				"wn_util.cxx"
				"wutil.cxx"
				"config_targ.cxx"
				"config_elf_targ.cxx"
				"targ_const.cxx"
				"targ_sim.cxx"
				"cwh_unimp.cxx"
				"cwh_addr.cxx"
				"cwh_auxst.cxx"
				"cwh_block.cxx"
				"cwh_data.cxx"
				"cwh_directive.cxx"
				"cwh_dope.cxx"
				"cwh_dst.cxx"
				"cwh_expr.cxx"
				"cwh_intrin.cxx"
				"cwh_io.cxx"
				"cwh_mkdepend.cxx"
				"cwh_pdgcs.cxx"
				"cwh_preg.cxx"
				"cwh_types.cxx"
				"cwh_stab.cxx"
				"cwh_stmt.cxx"
				"cwh_stk.cxx"
				"decorate_utils.cxx"
				"f2c_abi_utils.cxx"
				"sgi_cmd_line.cxx"
				"path_intrinsic_list.cxx"
				"make_depend.cxx"
				"config_host.cxx"
				"config_platform.cxx")

# final linking command
# gcc -D_SGI_SOURCE -D_LANGUAGE_C -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -c     -DSGI_DIRS -Dlonglong -DSGI_MONGOOSE -DFRONT_END -DFRONT_F90 -D_PDGCS  -DUSE_STANDARD_TYPES -D __MIPS_AND_IA64_ELF_H -Dlinux -D__USE_BSD -D_GNU_SOURCE -D_LONGLONG -D_SVR4_SOURCE   -D_SGI_SGI -D_TARGET_MONGOOSE -D_SGI_WHIRLCONVERT -I../../../crayf90/fe90 -I../../../crayf90/sgi -I../../../common/com -I../../../common/util -I../../../common/com/x8664 -I. -I../../../include -I../../../linux/mfef90_includes -I../../../linux/include -I../../include/cmplrs -I/usr/include -DCROSS_COMPILATION -DFE_GNU_4_2_0   -DTARG_X8664 -DKEY  -Werror -std=gnu99 -D_GNU_SOURCE  -I../../include  -g -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD compiler_build_date.cxx -o compiler_build_date.cxx
# g++ -D_SGI_SOURCE -D_LANGUAGE_C_PLUS_PLUS -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -D_NOTHREADS       -DSGI_DIRS -Dlonglong -DSGI_MONGOOSE -DFRONT_END -DFRONT_F90 -D_PDGCS  -DUSE_STANDARD_TYPES -D __MIPS_AND_IA64_ELF_H -Dlinux -D__USE_BSD -D_GNU_SOURCE -D_LONGLONG -D_SVR4_SOURCE   -D_SGI_SGI -D_TARGET_MONGOOSE -D_SGI_WHIRLCONVERT -I../../../crayf90/fe90 -I../../../crayf90/sgi -I../../../common/com -I../../../common/util -I../../../common/com/x8664 -I. -I../../../include -I../../../linux/mfef90_includes -I../../../linux/include -I../../include/cmplrs -I/usr/include -DCROSS_COMPILATION -DFE_GNU_4_2_0   -DTARG_X8664 -DKEY  -Werror     -I../../include  -g -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD -o mfef95  config.cxx const.cxx controls.cxx dwarf_DST.cxx dwarf_DST_dump.cxx dwarf_DST_mem.cxx dwarf_DST_producer.cxx err_host.cxx f90_utils.cxx glob.cxx ir_bcom.cxx ir_bwrite.cxx ir_reader.cxx irbdata.cxx mtypes.cxx opcode.cxx opcode_core.cxx pu_info.cxx strtab.cxx symtab.cxx symtab_verify.cxx ttype.cxx wn.cxx wn_map.cxx wn_pragmas.cxx wn_simp.cxx wn_util.cxx wutil.cxx config_targ.cxx config_elf_targ.cxx targ_const.cxx targ_sim.cxx cwh_unimp.cxx cwh_addr.cxx cwh_auxst.cxx cwh_block.cxx cwh_data.cxx cwh_directive.cxx cwh_dope.cxx cwh_dst.cxx cwh_expr.cxx cwh_intrin.cxx cwh_io.cxx cwh_mkdepend.cxx cwh_pdgcs.cxx cwh_preg.cxx cwh_types.cxx cwh_stab.cxx cwh_stmt.cxx cwh_stk.cxx decorate_utils.cxx f2c_abi_utils.cxx sgi_cmd_line.cxx path_intrinsic_list.cxx make_depend.cxx config_host.cxx config_platform.cxx        compiler_build_date.cxx  -L./    

# Linking libs
# ../../libcomutil/libcomutil.a ../fe90/fe90.a ../../arith/arith.a ../../libcif/libcif.a /usr/local/src/cb/path64-hg/pathscale/targx8664_builtonia32/libm/libmpath.a /usr/local/src/cb/path64-hg/pathscale/targx8664_builtonia32/libfoobar/libpathfortran.a -L/usr/ia32-sgi-linux/bin -lm   -D_MIPSEL -DTARG_LINUX /usr/local/src/cb/path64-hg/pathscale/targx8664_builtonia32/libm/libmpath.a /usr/local/src/cb/path64-hg/pathscale/targx8664_builtonia32/libfoobar/libpathfortran.a 

add_executable (mfef95 ${PATHSCALE_MFEF95_SRCS})
target_link_libraries (mfef95 comutil fe90 arith cif mpath pathfortran m)
