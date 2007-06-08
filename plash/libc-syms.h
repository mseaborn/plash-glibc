

int kernel_close(int fd);
int kernel_dup(int fd);
int kernel_dup2(int old_fd, int new_fd);
//int kernel_fstat(int fd, struct stat *st);
//int kernel_fstat64(int fd, struct stat64 *st);
int kernel_fxstat(int ver, int fd, struct stat *st);
int kernel_fxstat64(int ver, int fd, struct stat64 *st);


#include "shlib-compat.h"
#include "libc-symbols.h"

#define export_weak_alias(name, aliasname) \
  weak_alias(name, aliasname)

#define export(name, aliasname) \
  strong_alias(name, aliasname)


#if !defined(IS_IN_rtld)

#define export_versioned_symbol(lib, local, symbol, version) \
  versioned_symbol(lib, local, symbol, version)
#define export_compat_symbol(lib, local, symbol, version) \
  compat_symbol(lib, local, symbol, version)

#endif
