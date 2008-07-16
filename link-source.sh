#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Usage: $0 <plash-source-directory>"
  exit 1
fi

PLASH_DIR="$1"

set -e

files="
cap-call-return.c
cap-protocol.c
cap-protocol.h
cap-utils.c
cap-utils.h
cap-utils-libc.c
comms.c
comms.h
filesysobj.c
filesysobj.h
libc-at-calls.c
libc-comms.c
libc-comms.h
libc-connect.c
libc-errno.h
libc-fds.h
libc-fork-exec.c
libc-getsockopt.c
libc-getuid.c
libc-inotify.c
libc-misc.c
libc-preload-import.c
libc-stat.c
libc-truncate.c
libc-utime.c
marshal.h
marshal-pack.c
marshal-pack.h
plash-libc.h
region.c
region.h
serialise.c
serialise.h
utils.c
"

gen_files="
out-marshal.h
out-vtable-cap-call-return.h
out-vtable-cap-protocol.h
out-vtable-filesysobj.h
"

for file in $files; do
  ln -sf $PLASH_DIR/src/$file plash/
done

for file in $gen_files; do
  ln -sf $PLASH_DIR/gensrc/$file plash/
done

empty_files="
access.c
chdir.c
chmod.c
chown.c
close.c
closedir.c
creat.c
creat64.c
dirfd.c
dup2.c
faccessat.c
fchdir.c
fchmodat.c
fchownat.c
fdopendir.c
futimesat.c
fxstatat.c
fxstatat64.c
getcwd.c
getdents.c
getdents64.c
getdents64.c
getxattr.c
lchmod.c
lchown.c
lchown.c
lgetxattr.c
link.c
linkat.c
listxattr.c
llistxattr.c
lremovexattr.c
lsetxattr.c
lutimes.c
lxstat.c
lxstat64.c
mkdir.c
mkdirat.c
mkfifo.c
mkfifoat.c
open.c
open64.c
openat.c
openat64.c
opendir.c
readdir.c
readdir64.c
readdir64.c
readdir64_r.c
readdir64_r.c
readdir_r.c
readlink.c
readlinkat.c
removexattr.c
rename.c
renameat.c
rewinddir.c
rmdir.c
seekdir.c
setxattr.c
statfs.c
statfs64.c
symlink.c
symlinkat.c
telldir.c
truncate.c
truncate64.c
unlink.c
unlinkat.c
utimes.c
vfork.c
xmknod.c
xmknodat.c
xstat.c
xstat64.c
getuid.c
getgid.c
geteuid.c
getegid.c
setuid.c
setgid.c
seteuid.c
setegid.c
setreuid.c
setregid.c
setresuid.c
setresgid.c
"

overrides_dir=plash/sysdeps/overrides
rm -rf $overrides_dir
mkdir -p $overrides_dir
for file1 in $empty_files; do
  file=$overrides_dir/$file1
  if ! [ -e $file ]; then
    touch $file
  fi
done
