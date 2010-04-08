# Hide generator binaries away from the rest of the compiler.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

macro(gen_info type name)
  add_executable(${name}_gen ${name}_gen.cxx ../${type}/${BUILD_TARGET_DIR}/${name}.cxx)
  target_link_libraries(${name}_gen ${ARGN})
  add_custom_command(
    OUTPUT targ_${name}.c targ_${name}.h
    COMMAND ${name}_gen
    DEPENDS ${name}_gen
    )
  add_library(targ_${name} targ_${name}.c targ_${name}.h)
  add_dependencies(targ_info targ_${name})
endmacro()

#-----------------------------------------------------------------------------
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

# Define one target to generate all target information.
add_custom_target(targ_info)

add_library(gen_util STATIC gen_util.cxx)

add_executable(isa_gen isa_gen.cxx ../isa/${BUILD_TARGET_DIR}/isa.cxx)
target_link_libraries(isa_gen gen_util)
add_custom_command(
  OUTPUT topcode.c topcode.h
  COMMAND isa_gen
  DEPENDS isa_gen
  )
add_library(isa_gen_topcode STATIC topcode.c topcode.h)
target_link_libraries(isa_gen_topcode gen_util)

gen_info(isa isa_enums        gen_util)
gen_info(isa isa_lits         isa_gen_topcode)

gen_info(isa isa_properties   isa_gen_topcode)
gen_info(isa isa_pack         targ_isa_properties isa_gen_topcode)
gen_info(isa isa_print        targ_isa_properties isa_gen_topcode)
gen_info(isa isa_bundle       targ_isa_properties isa_gen_topcode)
gen_info(isa isa_decode       targ_isa_bundle isa_gen_topcode)

gen_info(isa isa_subset       isa_gen_topcode)
gen_info(isa isa_hazards      targ_isa_subset isa_gen_topcode)
gen_info(isa isa_registers    targ_isa_subset isa_gen_topcode)
target_link_libraries(targ_isa_registers targ_isa_subset)

gen_info(isa isa_operands     targ_isa_registers targ_isa_enums isa_gen_topcode)
gen_info(isa isa_pseudo       targ_isa_operands targ_isa_registers targ_isa_enums isa_gen_topcode)

gen_info(proc proc            gen_util)
gen_info(proc proc_properties targ_proc gen_util)
gen_info(abi  abi_properties  targ_isa_subset targ_isa_registers gen_util)
