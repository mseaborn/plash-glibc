
/* Taken from sysdeps/unix/sysv/linux/truncate64.c */

#include <sysdep.h>
#include <sys/syscall.h>

#include <kernel-features.h>

#ifdef __NR_truncate64
#ifndef __ASSUME_TRUNCATE64_SYSCALL
/* The variable is shared between all wrappers around *truncate64 calls.  */
int __have_no_truncate64;
#endif
#endif
