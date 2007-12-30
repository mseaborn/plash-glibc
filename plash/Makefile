
subdir := plash

all:

include ../Makeconfig

routines = filesysobj region comms cap-protocol cap-call-return marshal-pack \
	   cap-utils serialise \
	   libc-comms libc-misc libc-stat libc-truncate libc-utime \
	   libc-connect libc-fork-exec libc-at-calls \
	   kernel_close kernel_dup kernel_dup2 \
	   have-truncate64 have-statfs64

include ../Rules
