INCLUDE_DIRECTORIES(BEFORE SYSTEM ${CMAKE_CURRENT_BINARY_DIR}/include
                                  ${CMAKE_CURRENT_SOURCE_DIR}/include)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/pathscale_defs.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/include/pathscale_defs.h)

ADD_SUBDIRECTORY(driver)
