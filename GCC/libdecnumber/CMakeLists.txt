
FILE(COPY ${GCC_SOURCE_DIR}/ungenerated/common/gstdint.h DESTINATION ${GCC_BINARY_DIR}/libdecnumber)
FILE(COPY ${GCC_SOURCE_DIR}/ungenerated/common/gstdint.h DESTINATION ${GCC_BINARY_DIR}/gcc)

INCLUDE_DIRECTORIES(BEFORE
  ${GCC_SOURCE_DIR}/include
  ${GCC_SOURCE_DIR}/libdecnumber/include
  ${GCC_BINARY_DIR}/libdecnumber
  )
SET(decnumber_SRCS
    decContext.c   decNumber.c  decUtility.c  decimal128.c
     decimal32.c   decimal64.c
 # source file count: 6
  )
ADD_LIBRARY(decnumber ${decnumber_SRCS})
#TARGET_LINK_LIBRARIES(decnumber iberty)
