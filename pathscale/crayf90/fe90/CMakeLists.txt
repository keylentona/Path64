SET(PATHSCALE_FE90_SRCS "cifcmnrecs.c"
			"cifftnrecs.c"
			"cmd_line.c"
			"cond_comp.c"
			"debug.c"
			"fecif.c"
			"fold_drive.c"
			"fortout.c"
			"i_cvrt.c"
			"inline.c"
			"ir.c"
			"lex.c"
			"main.c"
			"messages.c"
			"module.c"
			"nameres.c"
			"p_asg_expr.c"
			"p_ctl_flow.c"
			"p_dcl_attr.c"
			"p_dcl_pu.c"
			"p_dcl_util.c"
			"p_dcls.c"
			"p_directiv.c"
			"p_driver.c"
			"p_end.c"
			"p_io.c"
			"p_utils.c"
			"release.c"
			"s_asg_expr.c"
			"s_call.c"
			"s_cnstrct.c"
			"s_ctl_flow.c"
			"s_data.c"
			"s_dcl_pu.c"
			"s_dcls.c"
			"s_directiv.c"
			"s_driver.c"
			"s_end.c"
			"s_interoperable.c"
			"s_intrin.c"
			"s_io.c"
			"s_rcnstrct.c"
			"s_typ_init.c"
			"s_utils.c"
			"src_input.c"
			"sytb.c"
			"utils.c")

SET(PATHSCALE_FE90_FORTRAN_SRCS
			"fold.f")

INCLUDE_DIRECTORIES(
	"../../crayf90/fe90"
	"../../arith"
	"../../common/com"
	"../../common/com/x8664"
	"../../linux/mfef90_includes"
	"../../clibinc/cray"
)

ADD_DEFINITIONS(
	-std=gnu99)

add_library(fe90 STATIC ${PATHSCALE_FE90_SRCS})
add_library(fe90-fortran STATIC ${PATHSCALE_FE90_FORTRAN_SRCS})
