/* Copyright (C) 2000, 2003, 2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <errno.h>
#include <unistd.h>

#include <sysdep.h>
#include <sys/syscall.h>

#include <kernel-features.h>

#ifdef __NR_getuid32
# if __ASSUME_32BITUIDS == 0
/* This variable is shared with all files that need to check for 32bit
   uids.  This is the definition.
   -1 if libc does not know yet whether kernel has 32bit uids or not.
   0 if it does have them.
   1 if it does not have them.  */
int __libc_missing_32bit_uids attribute_hidden = -1;
# endif
#endif /* __NR_getuid32 */

uid_t
kernel_getuid (void)
{
  INTERNAL_SYSCALL_DECL (err);
#if __ASSUME_32BITUIDS > 0
  /* No error checking.  */
  return INTERNAL_SYSCALL (getuid32, err, 0);
#else
# ifdef __NR_getuid32
  if (__libc_missing_32bit_uids <= 0)
    {
      int result;

      result = INTERNAL_SYSCALL (getuid32, err, 0);
      if (! INTERNAL_SYSCALL_ERROR_P (result, err)
	  || INTERNAL_SYSCALL_ERRNO (result, err) != ENOSYS)
	return result;

      __libc_missing_32bit_uids = 1;
    }
# endif /* __NR_getuid32 */

  /* No error checking.  */
  return INTERNAL_SYSCALL (getuid, err, 0);
#endif
}

#if 0
weak_alias (__getuid, getuid)
#endif
