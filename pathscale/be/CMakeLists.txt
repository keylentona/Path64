INCLUDE_DIRECTORIES(
  ${PATHSCALE_BINARY_DIR}/common/targ_info
  ${PATHSCALE_BINARY_DIR}/be
  be
  cg
  com
  lno
  opt
  prompf_anl
  region
  vho
  whirl2c
  whirl2f

  ../ipa/common
  ../ipa/local
  ../ipa/main/analyze
  ../ipa/main/optimize

  ../common/com
  ../common/com/${BUILD_TARGET_DIR}
  ../common/instrument
  ../common/targ_info/access
  ../common/util
  )

ADD_DEFINITIONS(
  -DNO_VALGRIND # TODO: Make option
  -DMONGOOSE_BE
  -DBACK_END

  -D__MIPS_AND_IA64_ELF_H
  -D_SUPPORT_IPA
  )

ADD_SUBDIRECTORY(be)
