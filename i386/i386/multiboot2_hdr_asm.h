/*
 * Copyright (c) 2026 Free Software Foundation
 *
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 *
 * FSF ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  FSF DISCLAIMS ANY LIABILITY OF ANY KIND FOR
 * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 */

#include <mach/machine/multiboot2.h>

/* The multiboot2 header must be 8 byte aligned */
	P2ALIGN(3)
multiboot2_hdr:
	.long	MULTIBOOT2_HEADER_MAGIC
	.long	MULTIBOOT2_ARCHITECTURE_I386
	.long	(multiboot2_hdr_end - multiboot2_hdr)
	.long	(0 \
	        - MULTIBOOT2_HEADER_MAGIC \
	        - MULTIBOOT2_ARCHITECTURE_I386 \
	        - (multiboot2_hdr_end - multiboot2_hdr))
	/* These are the tags that we expect to receive in the
	  information structure. Each tag also needs to be 8 byte
	  aligned with padding if required. */
	.short MULTIBOOT2_HEADER_TAG_INFORMATION_REQUEST
	.short 0
	.long 40
	.long MULTIBOOT2_TAG_TYPE_MMAP
	.long MULTIBOOT2_TAG_TYPE_BASIC_MEMINFO
	.long MULTIBOOT2_TAG_TYPE_CMDLINE
	.long MULTIBOOT2_TAG_TYPE_MODULE
	.long MULTIBOOT2_TAG_TYPE_ELF_SECTIONS
	.long MULTIBOOT2_TAG_TYPE_ACPI_OLD
	.long MULTIBOOT2_TAG_TYPE_ACPI_NEW
	.long MULTIBOOT2_TAG_TYPE_EFI64
	/* Align modules on page boundaries */
	.short MULTIBOOT2_HEADER_TAG_MODULE_ALIGN
	.short 0
	.long  8
	/* Frame buffer specified with no preference for width, height
	   and depth. */
	.short MULTIBOOT2_HEADER_TAG_FRAMEBUFFER
	.short 0
	.long  20
	.long  0 /* No preference. */
	.long  0 /* No preference. */
	.long  0 /* No preference. */
	.long  0 /* Padding */
	/* There must always be an 'end' (empty) tag */
	.short MULTIBOOT2_HEADER_TAG_END
	.short 0
	.long  8
multiboot2_hdr_end:
