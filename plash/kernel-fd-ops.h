
int kernel_close(int fd);
int kernel_dup(int fd);
int kernel_dup2(int old_fd, int new_fd);
int kernel_fxstat(int ver, int fd, struct stat *st);
int kernel_fxstat64(int ver, int fd, struct stat64 *st);
