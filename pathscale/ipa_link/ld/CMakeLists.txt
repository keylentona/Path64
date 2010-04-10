ADD_DEFINITIONS(-DHAVE_CONFIG_H=1)
INCLUDE_DIRECTORIES(BEFORE
  ${BFD_SOURCE_DIR}/include
)
#  ${GCC_BINARY_DIR}/libiberty
#)

SET(LD_SRCS
ldgram.c 
ldlex.c 
lexsup.c
ldlang.c
mri.c
ldctor.c
ldwrite.c
ldexp.c
ldemul.c
ldver.c
ldmisc.c
ldfile.c
ldcref.c
  )

# ldmain.c is special
#-DDEFAULT_EMULATION='"elf_x86_64"' \
#    -DSCRIPTDIR='"/opt/pathscale/x86_64-unknown-linux-gnu/lib"' -DBINDIR='"/opt/pathscale/bin"' \
#    -DTOOLBINDIR='"/opt/pathscale/x86_64-unknown-linux-gnu/bin"' \
#    -DTARGET='"x86_64-unknown-linux-gnu"' -DTARGET_SYSTEM_ROOT=\"\" \
#    ../../../ipa_link/ld/ldmain.c



# I don't know if this is needed to pull in libiberty
FOREACH(f
    ASPRINTF ATEXIT BASENAME BCMP BCOPY BSEARCH BZERO CALLOC CLOCK GETCWD
    GETPAGESIZE INDEX INSQUE MKSTEMPS MEMCHR MEMCMP MEMCPY MEMMOVE MEMPCPY
    MEMSET PUTENV RANDOM RENAME RINDEX SIGSETMASK STRCASECMP SETENV STPCPY
    STPNCPY STRCHR STRDUP STRNCASECMP STRNDUP STRRCHR STRSTR STRTOD STRTOL
    STRTOUL STRVERSCMP TMPNAM VASPRINTF VFPRINTF VPRINTF VSPRINTF STRERROR
    STRSIGNAL FFS SNPRINTF VSNPRINTF
    )
  # Removed from above list:
  #   WAITPID WAIT3 WAIT4 SYSMP __FSETLOCKING GETRUSAGE ON_EXIT TIMES
  #   PSTAT_GETSTATIC PSTAT_GETDYNAMIC GETSYSINFO TABLE PSIGNAL SYSCONF
  #   REALPATH SYSCTL SBRK CANONICALIZE_FILE_NAME GETTIMEOFDAY
  IF(NOT HAVE_${f})
    STRING(TOLOWER "${f}" SRC)
    LIST(APPEND iberty_SRCS ${SRC}.c)
  ENDIF(NOT HAVE_${f})
ENDFOREACH(f)

#ADD_LIBRARY(iberty ${iberty_SRCS})
add_executable(ld ${LD_SRCS})
target_link_libraries(ld bfd iberty)
