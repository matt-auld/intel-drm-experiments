/*
 * Autogenerated file, DO NOT EDIT manually!
 *
 * Copyright (c) 2015 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#include "i915_oa_drm.h"
#include <stdint.h>

static const uint32_t b_counter_config_memory_writes[] = {
	0x2724, 0xf0800000,
	0x2720, 0x00000000,
	0x2714, 0xf0800000,
	0x2710, 0x00000000,
	0x274c, 0x76543298,
	0x2748, 0x98989898,
	0x2744, 0x000000e4,
	0x2740, 0x00000000,
	0x275c, 0xbabababa,
	0x2758, 0x88888888,
	0x2754, 0x000c5500,
	0x2750, 0x00000000,
	0x2770, 0x0007f81a,
	0x2774, 0x0000fc00,
	0x2778, 0x0007f82a,
	0x277c, 0x0000fc00,
	0x2780, 0x0007f822,
	0x2784, 0x0000fc00,
	0x2788, 0x0007f8ba,
	0x278c, 0x0000fc00,
	0x2790, 0x0007f87a,
	0x2794, 0x0000fc00,
	0x2798, 0x0007f8ea,
	0x279c, 0x0000fc00,
	0x27a0, 0x0007f8e2,
	0x27a4, 0x0000fc00,
	0x27a8, 0x0007f8f2,
	0x27ac, 0x0000fc00,
};

static const uint32_t mux_config_memory_writes[] = {
	0x253A4, 0x34300000,
	0x25440, 0x01500000,
	0x25444, 0x00000120,
	0x25128, 0x0C200000,
	0x25380, 0x00000450,
	0x25390, 0x00052C43,
	0x25384, 0x00000000,
	0x25400, 0x00007184,
	0x25408, 0x0A418820,
	0x2540C, 0x000820E6,
	0x25404, 0xFF500000,
	0x25100, 0x000005D6,
	0x2510C, 0x1E700000,
	0x25104, 0x00000000,
	0x25420, 0x02108421,
	0x25424, 0x00008421,
	0x2541C, 0x00000000,
	0x25428, 0x00000000,
};

void hsw_select_memory_writes(struct drm_i915_perf_oa_config *oa_config)
{
	oa_config->n_mux_regs = sizeof(mux_config_memory_writes) / 8;
	oa_config->mux_regs = (uint64_t)mux_config_memory_writes;

	oa_config->n_boolean_regs = sizeof(b_counter_config_memory_writes) / 8;
	oa_config->boolean_regs = (uint64_t)b_counter_config_memory_writes;

	oa_config->n_flex_regs = 0;
	oa_config->flex_regs = 0;
}
