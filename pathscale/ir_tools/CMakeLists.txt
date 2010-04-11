
set(IR_B2A_SRCS 
"ir_size.cxx"
"config.cxx"
"config_elf_targ.cxx"
"const.cxx"
"dwarf_DST.cxx"
"dwarf_DST_dump.cxx"
"dwarf_DST_mem.cxx"
"glob.cxx"
"ir_bcom.cxx"
"ir_bread.cxx"
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
"wn.cxx"
"wn_map.cxx"
"wn_pragmas.cxx"
"wn_simp.cxx"
"wn_util.cxx"
"wutil.cxx"
"xstats.cxx"
"config_targ.cxx"
"targ_const.cxx"
"targ_sim.cxx"
"config_host.cxx"
"config_platform.cxx"
)

#INCLUDE_DIRECTORIES(lib
#                    .)

#ADD_DEFINITIONS(-DHAVE_CONFIG_H)

#ADD_LIBRARY(comutil)
ADD_EXECUTABLE(ir_b2a ${IR_B2A_SRCS})
target_link_libraries(ir_b2a comutil m)
