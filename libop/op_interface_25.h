/**
 * @file op_interface_25.h
 *
 * Module / user space interface for the new OProfile patch
 *
 * @remark Copyright 2002 OProfile authors
 * @remark Read the file COPYING
 *
 * @author John Levon
 * @author Philippe Elie
 */

#ifndef OP_INTERFACE_25_H
#define OP_INTERFACE_25_H

#include "op_config.h"
#include "op_types.h"

#define CTX_SWITCH_CODE			1
#define CPU_SWITCH_CODE			2
#define COOKIE_SWITCH_CODE		3
#define KERNEL_ENTER_SWITCH_CODE	4
#define KERNEL_EXIT_SWITCH_CODE		5
#define MODULE_LOADED_CODE              6
#define CTX_TGID_CODE			7
#define LAST_CODE			8
 
#endif /* OP_INTERFACE_25_H */
