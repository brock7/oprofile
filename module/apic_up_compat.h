#ifndef APIC_UP_COMPAT_H
#define APIC_UP_COMPAT_H

#define	APIC_DEFAULT_PHYS_BASE	0xfee00000
#define	APIC_SPIV		0xF0
#define APIC_ESR		0x280
#define	APIC_LVTT		0x320
#define	APIC_LVT0		0x350
#define	APIC_LVT_MASKED		(1<<16)
#define	APIC_LVT_LEVEL_TRIGGER	(1<<15)
#define	APIC_MODE_NMI		0x4
#define	APIC_MODE_EXINT		0x7
#define	GET_APIC_DELIVERY_MODE(x)	(((x)>>8)&0x7)
#define	SET_APIC_DELIVERY_MODE(x,y)	(((x)&~0x700)|((y)<<8))
#define APIC_LVT1		0x360
#define	APIC_SEND_PENDING	(1<<12)
#define	APIC_TDCR		0x3E0
#define	APIC_TDR_DIV_1		0xB

/* when !CONFIG_X86_LOCAL_APIC we need to provide a valid va to map the
 * the pa of APIC onto. This va must be un-cachable/un-swapable*/
#ifndef CONFIG_X86_LOCAL_APIC
extern unsigned long virt_apic_base;
#define	APIC_BASE	virt_apic_base
#else
#define APIC_BASE (fix_to_virt(FIX_APIC_BASE))
#endif

static __inline void apic_write(unsigned long reg, unsigned long v)
{
	*((volatile unsigned long *)(APIC_BASE+reg)) = v;
}

static __inline unsigned long apic_read(unsigned long reg)
{
	return *((volatile unsigned long *)(APIC_BASE+reg));
}

#endif /* APIC_UP_COMPAT_H */
