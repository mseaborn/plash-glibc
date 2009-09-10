/* Initialize CPU feature data.
   This file is part of the GNU C Library.
   Copyright (C) 2008 Free Software Foundation, Inc.
   Contributed by Ulrich Drepper <drepper@redhat.com>.

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

#include "init-arch.h"


struct cpu_features __cpu_features attribute_hidden;


void
__init_cpu_features (void)
{
  unsigned int ebx;
  unsigned int ecx;
  unsigned int edx;

  asm volatile ("cpuid"
		: "=a" (__cpu_features.max_cpuid), "=b" (ebx), "=c" (ecx),
		  "=d" (edx)
		: "0" (0));

  /* This spells out "GenuineIntel".  */
  if (ebx == 0x756e6547 && ecx == 0x6c65746e && edx == 0x49656e69)
    {
      __cpu_features.kind = arch_kind_intel;

      asm volatile ("cpuid"
		    : "=a" (__cpu_features.cpuid[INTEL_CPUID_INDEX_1].eax),
		      "=b" (__cpu_features.cpuid[INTEL_CPUID_INDEX_1].ebx),
		      "=c" (__cpu_features.cpuid[INTEL_CPUID_INDEX_1].ecx),
		      "=d" (__cpu_features.cpuid[INTEL_CPUID_INDEX_1].edx)
		    : "0" (1));
    }
  /* This spells out "AuthenticAMD".  */
  else if (ebx == 0x68747541 && ecx == 0x444d4163 && edx == 0x69746e65)
    {
      __cpu_features.kind = arch_kind_amd;

      asm volatile ("cpuid"
		    : "=a" (__cpu_features.cpuid[AMD_CPUID_INDEX_1].eax),
		      "=b" (__cpu_features.cpuid[AMD_CPUID_INDEX_1].ebx),
		      "=c" (__cpu_features.cpuid[AMD_CPUID_INDEX_1].ecx),
		      "=d" (__cpu_features.cpuid[AMD_CPUID_INDEX_1].edx)
		    : "0" (1));
    }
  else
    __cpu_features.kind = arch_kind_other;
}
