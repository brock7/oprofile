/* COPYRIGHT (C) 2002 Philippe Elie, based on discussion with John Levon
 * stuff here come from various source, linux kernel header, John's trick etc.
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef COMPAT24_H
#define COMPAT24_H

#include <linux/version.h>

#include <asm/apic.h>
#include <asm/apicdef.h>
#include <asm/mpspec.h>
 
#include "apic_up_compat.h"
 
#define lock_rtc(f) spin_lock_irqsave(&rtc_lock, f)
#define unlock_rtc(f) spin_unlock_irqrestore(&rtc_lock, f)
#define wind_dentries(d, v, r, m) wind_dentries_2_4(d, v, r, m)
#define hash_path(f) do_path_hash_2_4((f)->f_dentry, (f)->f_vfsmnt)
#define request_region_check request_region
#define op_cpu_id() cpu_number_map(smp_processor_id())
#define pte_page_address(x) page_address(pte_page(x))
#define GET_VM_OFFSET(v) ((v)->vm_pgoff << PAGE_SHIFT)
#define PTRACE_OFF(t) ((t)->ptrace &= ~PT_DTRACE)
#define lock_execve() do { } while (0)
#define unlock_execve() do { } while (0)
#define op_nmi op_nmi24
#define HAVE_MMAP2
#define HAVE_FILE_OPERATIONS_OWNER

/* ->owner field in 2.4 */
#define INC_USE_COUNT_MAYBE
#define DEC_USE_COUNT_MAYBE

/* no global waitqueue spinlock in 2.4 */
#define wq_is_lockable() (1)
 
/* 2.4.3 introduced rw mmap semaphore  */
#if VATLEAST(2,4,3)
	#define take_mmap_sem(mm) down_read(&mm->mmap_sem)
	#define release_mmap_sem(mm) up_read(&mm->mmap_sem)
#else
	#define take_mmap_sem(mm) down(&mm->mmap_sem)
	#define release_mmap_sem(mm) up(&mm->mmap_sem)
#endif

#if VBEFORE(2,4,10)
	/* 2.4.10 introduced MODULE_LICENSE */
	#define MODULE_LICENSE(x)
	/* 2.4.10 introduced APIC setup under normal APIC config */
	#ifndef CONFIG_X86_UP_APIC
		#define NEED_FIXMAP_HACK
	#endif
#endif /* VBEFORE(2,4,10) */

#endif /* COMPAT24_H */