/* Copyright (C) 1991, 1995, 1996, 1997, 2001, 2004, 2006, 2007
   Free Software Foundation, Inc.
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

#include <stdarg.h>
#include <stdio.h>
#include "../libio/libioP.h"


/* Write formatted output to FP from the format string FORMAT.  */
int
___fprintf_chk (FILE *fp, int flag, const char *format, ...)
{
  va_list ap;
  int done;

  _IO_acquire_lock_clear_flags2 (fp);
  if (flag > 0)
    fp->_flags2 |= _IO_FLAGS2_FORTIFY;

  va_start (ap, format);
  done = vfprintf (fp, format, ap);
  va_end (ap);

  if (flag > 0)
    fp->_flags2 &= ~_IO_FLAGS2_FORTIFY;
  _IO_release_lock (fp);

  return done;
}
ldbl_strong_alias (___fprintf_chk, __fprintf_chk)
