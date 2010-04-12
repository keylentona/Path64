CMAKE_MINIMUM_REQUIRED(VERSION 2.6.3 FATAL_ERROR)
PROJECT(Path64)

# Tell GCC_XML that we are providing gccxml_cc1plus for it.
SET(GCCXML_NATIVE_CC1PLUS 1)

INCLUDE(${CMAKE_SOURCE_DIR}/cmake/Modules/GCCVersion.cmake)

#SET(CMAKE_C_FLAGS "$(BUILD_OPTIMIZE) -DTARG_X8664 -DKEY -DFE_GNU_4_2_0   -DIs_True_On -W -Wall -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes -Wold-style-definition -Wmissing-format-attribute -DHAVE_CONFIG_H")

set(BUILD_TARGET_DIR x8664) # TODO: Make option, better name
#set(BUILD_TARGET_DIR mips)

# Place both gccxml_cc1plus and the GCC_XML executables next to each
# other.

SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin" CACHE PATH
  "Single output directory for all executables.")

SET(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib" CACHE PATH
  "Single output directory for all libraries.")

MARK_AS_ADVANCED(EXECUTABLE_OUTPUT_PATH LIBRARY_OUTPUT_PATH)

# TODO: set proper value here
SET(PATH64_PKG_VERSION version)

SET(PATH64_LIB_PATH lib/${PATH64_PKG_VERSION})

# Tell GCC where to install relative to the CMAKE_INSTALL_PREFIX.
SET(PATH64_GCC_INSTALL_PATH ${PATH64_LIB_PATH})


ADD_DEFINITIONS(-D_SGI_SOURCE
                -D__GNU_BUG_WORKAROUND
                -DTARG_X8664
                -DKEY
                -DFE_GNU_4_2_0
                -DLONGLONG
                -D_MIPSEL
                -DTARG_LINUX
                -D_MIPS_SZINT=32
                -D_MIPS_SZPTR=32
                -D_MIPS_SZLONG=32
               )

# Build GCC and pathscale.
ADD_SUBDIRECTORY(GCC)
ADD_SUBDIRECTORY(pathscale)
