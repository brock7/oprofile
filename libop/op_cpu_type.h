/**
 * @file op_cpu_type.h
 * CPU type determination
 *
 * @remark Copyright 2002 OProfile authors
 * @remark Read the file COPYING
 *
 * @author John Levon
 * @author Philippe Elie
 */

#ifndef OP_CPU_TYPE_H
#define OP_CPU_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Supported cpu type.  Always add new CPU types at the very end.
 */
typedef enum {
	CPU_NO_GOOD = -1, /**< unsupported CPU type */
	CPU_PPRO, /**< Pentium Pro */
	CPU_PII, /**< Pentium II series */
	CPU_PIII, /**< Pentium III series */
	CPU_ATHLON, /**< AMD P6 series */
        CPU_TIMER_INT, /**< CPU using the timer interrupt */
	CPU_P4,  /**< Pentium 4 / Xeon series */
	CPU_HAMMER, /**< AMD Hammer family */
	CPU_P4_HT2, /**< Pentium 4 / Xeon series with 2 hyper-threads */
	CPU_AXP_EV67, /**< Alpha EV67 family */
	CPU_P6_MOBILE, /**< Pentium M series */
	CPU_ARM_XSCALE1, /**< ARM XScale 1 */
	CPU_ARM_XSCALE2, /**< ARM XScale 2 */
	CPU_PPC64_POWER4, /**< ppc64 POWER4 family */
	CPU_PPC64_POWER5, /**< ppc64 POWER5 family */
	CPU_PPC64_POWER5p, /**< ppc64 Power5+ family */
	CPU_PPC64_970, /**< ppc64 970 family */
	CPU_MIPS_20K, /**< MIPS 20K */
	CPU_MIPS_24K, /**< MIPS 24K */
	CPU_MIPS_25K, /**< MIPS 25K */
	CPU_MIPS_34K, /**< MIPS 34K */
	CPU_MIPS_5K, /**< MIPS 5K */
	CPU_MIPS_R10000, /**< MIPS R10000 */
	CPU_MIPS_R12000, /**< MIPS R12000 */
	CPU_MIPS_RM7000, /**< QED  RM7000 */
	CPU_MIPS_RM9000, /**< PMC-Sierra RM9000 */
	CPU_MIPS_SB1, /**< Broadcom SB1 */
	CPU_MIPS_VR5432, /**< NEC VR5432 */
	CPU_MIPS_VR5500, /**< MIPS VR5500, VR5532 and VR7701 */
	CPU_PPC_E500,	/**< e500 */
	CPU_PPC_E500_2,	/**< e500v2 */
	CPU_CORE, /**< Core Solo / Duo series */
	CPU_PPC_7450, /**< PowerPC G4 */
	CPU_CORE_2, /**< Intel Core 2 */
	CPU_PPC64_POWER6, /**< ppc64 POWER6 family */
	CPU_PPC64_970MP, /**< ppc64 970MP */
	CPU_FAMILY10, /**< AMD family 10 */
	CPU_ARM_MPCORE, /**< ARM MPCore */
	CPU_ARM_V6, /**< ARM V6 */
	CPU_PPC64_POWER5pp,  /**< ppc64 Power5++ family */
	CPU_PPC_E300, /**< e300 */
	CPU_ARM_V7, /**< ARM Cortex-A8 */
 	CPU_ARCH_PERFMON, /**< Intel architectural perfmon */
	CPU_FAMILY11H, /**< AMD family 11h */
	CPU_PPC64_POWER7, /**< ppc64 POWER7 family */
   	CPU_CORE_I7, /* Intel Core i7, Nehalem */
   	CPU_ATOM, /* First generation Intel Atom */
	CPU_MIPS_LOONGSON2, /* < loongson2 family */
	CPU_NEHALEM, /* Intel Nehalem microarchitecture */
	CPU_ARM_V7_CA9, /**< ARM Cortex-A9 */
	CPU_MIPS_74K, /**< MIPS 74K */
	CPU_MIPS_1004K, /**< MIPS 1004K */
	CPU_FAMILY12H, /**< AMD family 12h */
	CPU_FAMILY14H, /**< AMD family 14h */
	CPU_FAMILY15H, /**< AMD family 15h */
	CPU_WESTMERE, /* Intel Westmere microarchitecture */
	CPU_ARM_SCORPION, /**< ARM SCORPION */
	CPU_ARM_SCORPIONMP, /**< ARM SCORPIONMP */
	CPU_SANDYBRIDGE, /* Intel Sandy-Bridge microarchitecture */
	CPU_TILE_TILE64, /**< Tilera TILE64 family */
	CPU_TILE_TILEPRO, /**< Tilera TILEPro family (Pro64 or Pro36) */
	CPU_TILE_TILEGX, /**< Tilera TILE-GX family */
	CPU_S390_Z10, /* IBM System z10 */
	CPU_S390_Z196, /* IBM zEnterprise z196 */
	CPU_IVYBRIDGE, /* Intel Ivy-Bridge microarchitecture */
	CPU_ARM_V7_CA5, /**< ARM Cortex-A5 */
	CPU_ARM_V7_CA7, /**< ARM Cortex-A7 */
	CPU_ARM_V7_CA15, /**< ARM Cortex-A15 */
	CPU_HASWELL, /** < Intel Haswell microarchitecture */
	CPU_S390_ZEC12, /**< IBM zEnterprise EC12 */	CPU_AMD64_GENERIC, /**< AMD64 Generic */
	CPU_PPC64_ARCH_V1, /** < IBM Power architected events version 1 */
	CPU_PPC64_POWER8, /**< ppc64 POWER8 family */
	CPU_PPC_E500MC, /**< e500mc */
	CPU_PPC_E6500, /**< e6500 */
	CPU_SILVERMONT, /** < Intel Silvermont microarchitecture */
	CPU_ARM_KRAIT, /**< ARM KRAIT */
	CPU_ARM_V8_APM_XGENE, /* APM X-Gene */
	CPU_BROADWELL, /** < Intel Broadwell (Core-M) microarchitecture */
	CPU_ARM_V8_CA57, /* ARM Cortex-A57 */
	CPU_ARM_V8_CA53, /* ARM Cortex-A53 */
	MAX_CPU_TYPE
} op_cpu;

/**
 * the CPU lowest common denominator
 *
 * returns 1 if there are variations for the base cpu type;
 */
int op_cpu_variations(op_cpu cpu_type);

/**
 * get the CPU lowest common denominator
 *
 * returns cpu_type if cpu_type does not have a lowest common denominator.
 */
op_cpu op_cpu_base_type(op_cpu cpu_type);

/**
 * get the CPU type from the kernel
 *
 * returns CPU_NO_GOOD if the CPU could not be identified.
 * This function can not work if the module is not loaded
 */
op_cpu op_get_cpu_type(void);

/**
 * get the cpu number based on string
 * @param cpu_string with either the cpu type identifier or cpu type number
 *
 * The function returns CPU_NO_GOOD if no matching string was found.
 */
op_cpu op_get_cpu_number(char const * cpu_string);

/**
 * get the cpu string.
 * @param cpu_type the cpu type identifier
 *
 * The function always return a valid char const * the core cpu denomination
 * or "invalid cpu type" if cpu_type is not valid.
 */
char const * op_get_cpu_type_str(op_cpu cpu_type);

/**
 * op_get_cpu_name - get the cpu name
 * @param cpu_type  the cpu identifier name
 *
 * The function always return a valid char const *
 * Return the OProfile CPU name, e.g. "i386/pii"
 */
char const * op_get_cpu_name(op_cpu cpu_type);

#if defined(__i386__) || defined(__x86_64__)
int op_is_cpu_vendor(char * vendor);
#endif

/**
 * compute the number of counters available
 * @param cpu_type numeric processor type
 *
 * returns 0 if the CPU could not be identified
 */
int op_get_nr_counters(op_cpu cpu_type);

#ifdef __cplusplus
}
#endif

#endif /* OP_CPU_TYPE_H */
