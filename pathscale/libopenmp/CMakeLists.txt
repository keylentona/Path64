# gcc -m64 -D_SGI_SOURCE -D_LANGUAGE_C -Wformat -funsigned-char -D__GNU_BUG_WORKAROUND -c     -D_GNU_SOURCE -DKEY -Werror -Wno-format  -I../../include -I../../libopenmp   -I../include  -O3 -DNDEBUG -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD -fno-strict-aliasing -Wall -Werror ../../libopenmp/utils.c -o utils.c
# ar cru libopenmp.a affinity.c atomic.c cpuid.c lock.c loop.c manager.c omp.c schedule.c stack.c team.c thread.c utils.c

SET(PATHSCALE_OPENMP_SRCS       "affinity.c"
				"atomic.c"
				"cpuid.c"
				"lock.c"
				"loop.c"
				"manager.c"
				"omp.c"
				"schedule.c"
				"stack.c"
				"team.c"
				"thread.c"
				"utils.c")

add_library (openmp STATIC ${PATHSCALE_OPENMP_SRCS})
#add_library (openmp SHARED ${PATHSCALE_OPENMP_SRCS})
# examples since I know we'll need the version script
#set_property(TARGET pscrt PROPERTY SOVERSION 1)
#set_property(TARGET pscrt PROPERTY LINK_FLAGS -Wl,--version-script="${libpscrt_SOURCE_DIR}/libpscrt.vs")

# install(TARGETS pscrt-static pscrt_p pscrt
#        LIBRARY DESTINATION ${PATH64_LIB_PATH}
#        ARCHIVE DESTINATION ${PATH64_LIB_PATH})
