PROJECT(PATHSCALE)

SET(CMAKE_C_FLAGS "-D_LANGUAGE_C ${CMAKE_C_FLAGS}")
SET(CMAKE_CXX_FLAGS "-D_LANGUAGE_C_PLUS_PLUS ${CMAKE_CXX_FLAGS}")

INCLUDE(includes.cmake)

# This kills the libpathfortran build at pathscale/libu/numconv/mpp/defgu2s.c
#ADD_DEFINITIONS(-D_GNU_SOURCE)

ADD_SUBDIRECTORY(driver)
ADD_SUBDIRECTORY(libcif)
ADD_SUBDIRECTORY(libcmplrs)
ADD_SUBDIRECTORY(libdwarf)
ADD_SUBDIRECTORY(libelf)
ADD_SUBDIRECTORY(common/targ_info)
ADD_SUBDIRECTORY(common/util)
ADD_SUBDIRECTORY(be)
ADD_SUBDIRECTORY(libpscrt)
ADD_SUBDIRECTORY(wgen)
ADD_SUBDIRECTORY(ipa)
ADD_SUBDIRECTORY(ipa_link)
ADD_SUBDIRECTORY(libopenmp)
ADD_SUBDIRECTORY(libfi)
# All the math stuff seems to be built from libmpath
#ADD_SUBDIRECTORY(libm)
ADD_SUBDIRECTORY(libmpath)
ADD_SUBDIRECTORY(instrumentation)
ADD_SUBDIRECTORY(arith)
# TODO : Can't determine linking method
#ADD_SUBDIRECTORY(f95_coco)
ADD_SUBDIRECTORY(crayf90)
ADD_SUBDIRECTORY(ir_tools)
ADD_SUBDIRECTORY(libpathfortran)
# libu removed from subdirectories
