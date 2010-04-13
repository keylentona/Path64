# this should build coco
# FFLAGS
# /opt/pathscale/bin/pathf90 -DMIPSEL -DTARG_LINUX        -I../include  -g -D_MIPSEL -DTARG_LINUX -D_LONGLONG -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32 -D_MIPS_SZLONG=32 -MMD -o coco coco.o        -D_MIPSEL -DTARG_LINUX

add_executable (coco "coco.F90")
