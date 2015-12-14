#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>

#include "i915_oa_drm.h"
#include "i915_oa_hsw.h"

#define ARRAY_SIZE(arr) (sizeof arr / sizeof arr[0])

static int open_render_node()
{
	static char *name = "/dev/dri/renderD128";
	return open(name, O_RDWR);
}

// TODO: we assume hsw here
static int add_oa_configs(int drm_fd)
{
	char *uuid = "oa-config-33";

	struct drm_i915_perf_oa_config oa_config = {
		.uuid = (uint64_t)uuid,
		.n_mux_regs = sizeof(mux_config_3d) / 16,
		.mux_regs = (uint64_t)mux_config_3d,

		.n_boolean_regs = sizeof(b_counter_config_3d) / 16,
		.boolean_regs = (uint64_t)b_counter_config_3d,

		.n_flex_regs = 0,
		.flex_regs = 0,
	};

	int ret;
	ret = ioctl(drm_fd, I915_IOCTL_PERF_ADD_CONFIG, &oa_config);

	if (ret) {
		fprintf(stderr, "Failed to add OA config %d\n", ret);
		return 0;
	}

	return oa_config.id;
}

static int open_oa_query(int drm_fd, int metric_set)
{
	int ret;
	struct i915_perf_open_param param;
	int period_exponent = 16;

	uint64_t properties[] = {
		DRM_I915_PERF_SAMPLE_OA_PROP, true,
		DRM_I915_PERF_OA_METRICS_SET_PROP, metric_set,
		DRM_I915_PERF_OA_FORMAT_PROP, I915_OA_FORMAT_A45_B8_C8,
		DRM_I915_PERF_OA_EXPONENT_PROP, period_exponent,
	};

	param.flags = 0;
	param.flags |= I915_PERF_FLAG_FD_CLOEXEC;
	param.flags |= I915_PERF_FLAG_FD_NONBLOCK;

	param.properties = (uint64_t)properties;
	param.n_properties = sizeof(properties) / 16;

	ret = ioctl(drm_fd, I915_IOCTL_PERF_OPEN, &param);

	if (ret)
		fprintf(stderr, "Failed to open perf OA query\n");

	return ret;
}

static int close_oa_query(int param_fd)
{
	close(param_fd);
}

/*
 *
 * Smoke test the the i915_PERF_ADD_CONFIG ioctl
 * TODO: this should probably eventually go into igt
 * when we get around to it
 */
int main(void)
{
	int drm_fd = open_render_node();
	if (drm_fd == -1) {
		fprintf(stderr, "Failed to open render node\n");
		return 1;
	}

	int id = add_oa_configs(drm_fd);
	open_oa_query(drm_fd, id);

	close(drm_fd);

	return 0;
}
