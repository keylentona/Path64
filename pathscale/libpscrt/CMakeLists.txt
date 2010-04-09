project(libpscrt)

set(pscrt_sources
  memset_em64t.s
  memset_opteron.s
  memcpy_em64t.c
  memcpy_opteron.c
  malloc_opt.c
  )

# TODO: Enable ASM language.  For now we just tell CMake to run the C
# compiler (gcc) and add some flags.
set_source_files_properties(
  memset_em64t.s
  memset_opteron.s
  PROPERTIES
  LANGUAGE C
  COMPILE_FLAGS "-x assembler-with-cpp"
  )

add_library(pscrt-static STATIC ${pscrt_sources})
set_property(TARGET pscrt-static PROPERTY OUTPUT_NAME pscrt)

add_library(pscrt_p STATIC ${pscrt_sources})
set_property(TARGET pscrt_p PROPERTY COMPILE_FLAGS -pg)

add_library(pscrt SHARED ${pscrt_sources})
set_property(TARGET pscrt PROPERTY SOVERSION 1)
set_property(TARGET pscrt PROPERTY LINK_FLAGS -Wl,--version-script="${libpscrt_SOURCE_DIR}/libpscrt.vs")
