CMAKE_MINIMUM_REQUIRED(VERSION 2.8.1 FATAL_ERROR)
PROJECT(Path64)

# Disallow in-source build
IF("${Path64_SOURCE_DIR}" STREQUAL "${Path64_BINARY_DIR}")
  MESSAGE(FATAL_ERROR "Path64 must be built out-of-source.  Remove files from the source tree that were created by this attempt:
  rm -rf CMakeFiles CMakeCache.txt
Then create a separate build directory and run CMake there.
  mkdir ../Path64-build
  cd ../Path64-build
  cmake ../Path64
This approach keeps the source tree pristine.")
ENDIF()

# Define a user option whether to build the Fortran compiler.
OPTION(PATH64_ENABLE_FORTRAN "Build Fortran compiler" ON)
IF(PATH64_ENABLE_FORTRAN)
  INCLUDE(${Path64_SOURCE_DIR}/cmake/Modules/CheckFortran.cmake)
  IF(CMAKE_Fortran_COMPILER)
    ENABLE_LANGUAGE(Fortran)
  ELSE()
    MESSAGE(STATUS "No working Fortran compiler is available")
    SET(PATH64_ENABLE_FORTRAN 0)
  ENDIF()
ENDIF()

# Set default install prefix (instead of CMake's /usr/local default).
IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX "/opt/path64" CACHE PATH "Installation root prefix" FORCE)
ENDIF()

# Tell GCC_XML that we are providing gccxml_cc1plus for it.
SET(GCCXML_NATIVE_CC1PLUS 1)

INCLUDE(${CMAKE_SOURCE_DIR}/cmake/Modules/GCCVersion.cmake)

#SET(CMAKE_C_FLAGS "$(BUILD_OPTIMIZE) -DTARG_X8664 -DKEY -DFE_GNU_4_2_0   -DIs_True_On -W -Wall -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes -Wold-style-definition -Wmissing-format-attribute -DHAVE_CONFIG_H")

set(BUILD_TARGET_DIR x8664) # TODO: Make option, better name
#set(BUILD_TARGET_DIR mips)

# Place all targets near the top of the build tree by default.
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Path64_BINARY_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${Path64_BINARY_DIR}/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${Path64_BINARY_DIR}/lib)

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
