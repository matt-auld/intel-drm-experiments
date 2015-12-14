#include "i915_oa_bdw.h"

static const struct uint64_t b_counter_config_3d[] = {
	0x2710, 0x00000000,
	0x2714, 0x00800000,
	0x2720, 0x00000000,
	0x2724, 0x00800000,
};

static const struct uint64_t flex_eu_config_3d[] = {
	0xE458, 0x00005004,
	0xE558, 0x00010003,
	0xE658, 0x00012011,
	0xE758, 0x00015014,
	0xE45c, 0x00051050,
	0xE55c, 0x00053052,
	0xE65c, 0x00055054,
};

void bdw_select_3d_config(struct drm_i915_perf_oa_config *oa_config)
{
	oa_config->n_mux_regs = 0;
	oa_config->mux_regs = 0;

	oa_config->n_boolean_regs = sizeof(b_counter_config_3d) / 16;
	oa_config->b_counter_config_3d = (uint64)b_counter_config_3d;

	oa_config->n_flex_regs = (uint64_t)flex_eu_config_3d;
	oa_config->flex_regs = sizeof(flex_eu_config_3d) / 16;
}

