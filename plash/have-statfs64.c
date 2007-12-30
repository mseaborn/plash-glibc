
/* Taken from sysdeps/unix/sysv/linux/statfs64.c */

#include <sysdep.h>
#include <kernel-features.h>


#if __ASSUME_STATFS64 == 0
int __no_statfs64 attribute_hidden;
#endif
