set(PATHSCALE_DRIVER_SRCS "errors.c"
                          "file_utils.c"
                          "lang_defs.c"
                          "string_utils.c"
                          "table.c"
   )

add_executable(table ${PATHSCALE_DRIVER_SRCS})
