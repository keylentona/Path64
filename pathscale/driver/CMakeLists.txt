Set(PATHSCALE_COMMON_DRIVER_SRCS "errors.c"
                                 "file_utils.c"
                                 "lang_defs.c"
                                 "string_utils.c"
   )

Set(PATHSCALE_DRIVER_SRCS ${PATHSCALE_COMMON_DRIVER_SRCS}
                          ${CMAKE_CURRENT_BINARY_DIR}/check_combos.c
                          ${CMAKE_CURRENT_BINARY_DIR}/implicits.c
                          "main.c"
                          "options.c"
                          "option_seen.c"
                          "get_options.c"
                          "opt_actions.c"
                          "file_names.c"
                          "objects.c"
                          "phases.c"
                          "run.c"
                          "special_options.c"
                          ${CMAKE_CURRENT_BINARY_DIR}/version_hg.c
                          "license.c"
   )

set(PATHSCALE_TABLE_SRCS  ${PATHSCALE_COMMON_DRIVER_SRCS}
                          "table.c"
   )

add_executable(table ${PATHSCALE_TABLE_SRCS})

#GET_TARGET_PROPERTY(TABLE_EXE table LOCATION)

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/OPTIONS.P
        COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/sort_options.sh ${CMAKE_CURRENT_SOURCE_DIR} OPTIONS -DX8664 -DPSC_PRODNAME='"Compiler"' -DKEY  -DPSC_BUILD_DATE='"xxxx-xx-xx/xx:xx:xx"' -DLITTLE_ENDIAN_HOST -DHOST_IA32 -DNOOPT > ${CMAKE_CURRENT_BINARY_DIR}/OPTIONS.P 
        DEPENDS sort_options.sh OPTIONS
        )

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/check_combos.c ${CMAKE_CURRENT_BINARY_DIR}/implicits.c
        COMMAND table < ${CMAKE_CURRENT_BINARY_DIR}/OPTIONS.P
        DEPENDS table ${CMAKE_CURRENT_BINARY_DIR}/OPTIONS.P
        )


add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/version_hg.c
        COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/gen_version.sh > ${CMAKE_CURRENT_BINARY_DIR}/version_hg.c
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/gen_version.sh
        )


include_directories(.
                    ../common/com
                    ${CMAKE_CURRENT_BINARY_DIR})


# TODO: set proper build date and time 
add_definitions(-std=gnu99
                -DPSC_BUILD_DATE='"xxxx-xx-xx/xx:xx:xx"'
                -DLITTLE_ENDIAN_HOST
                -DHOST_IA32
                -DNOOPT
                )

add_executable(driver ${PATHSCALE_DRIVER_SRCS})

