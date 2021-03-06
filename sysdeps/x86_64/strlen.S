/* strlen(str) -- determine the length of the string STR.
   Copyright (C) 2009 Free Software Foundation, Inc.
   Contributed by Ulrich Drepper <drepper@redhat.com>.
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

#include <sysdep.h>


	.text
ENTRY(strlen)
	movq	%rdi, %rcx
	movq	%rdi, %r8
	andq	$~15, %rdi
	pxor	%xmm1, %xmm1
	orl	$0xffffffff, %esi
	movdqa	(%rdi), %xmm0
	subq	%rdi, %rcx
	leaq	16(%rdi), %rdi
	pcmpeqb	%xmm1, %xmm0
	shl	%cl, %esi
	pmovmskb %xmm0, %edx
	xorl	%eax, %eax
	negq	%r8
	andl	%esi, %edx
	jnz	1f

2:	movdqa	(%rdi), %xmm0
	leaq	16(%rdi), %rdi
	pcmpeqb	%xmm1, %xmm0
	pmovmskb %xmm0, %edx
	testl	%edx, %edx
	jz	2b

1:	leaq	-16(%rdi,%r8), %rdi
	bsfl	%edx, %eax
	addq	%rdi, %rax
	ret
END(strlen)
libc_hidden_builtin_def (strlen)
