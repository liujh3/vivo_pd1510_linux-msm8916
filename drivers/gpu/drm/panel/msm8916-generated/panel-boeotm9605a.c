// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2026 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct boeotm9605a {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data boeotm9605a_supplies[] = {
	{ .supply = "vsn" },
	{ .supply = "vsp" },
};

static inline struct boeotm9605a *to_boeotm9605a(struct drm_panel *panel)
{
	return container_of_const(panel, struct boeotm9605a, panel);
}

static void boeotm9605a_reset(struct boeotm9605a *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
}

static int boeotm9605a_on(struct boeotm9605a *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x96, 0x05, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x96, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x92);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x10, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x89);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x36, 0x66);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb1);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x28);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x9c);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x87);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5,
					 0x15, 0x00, 0x15, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x93);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc5);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x91);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x79);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x92);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8, 0x47, 0x47);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0,
					 0x00, 0x44, 0x00, 0x00, 0x00, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe1,
					 0x00, 0x04, 0x09, 0x0f, 0x06, 0x0e,
					 0x0b, 0x09, 0x03, 0x07, 0x10, 0x09,
					 0x10, 0x12, 0x0b, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe2,
					 0x00, 0x04, 0x09, 0x0e, 0x07, 0x0e,
					 0x0b, 0x0a, 0x04, 0x07, 0x10, 0x09,
					 0x0f, 0x12, 0x0b, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xec,
					 0x40, 0x44, 0x44, 0x44, 0x44, 0x44,
					 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
					 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
					 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
					 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
					 0x44, 0x44, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xed,
					 0x40, 0x44, 0x43, 0x44, 0x44, 0x43,
					 0x44, 0x44, 0x34, 0x44, 0x44, 0x34,
					 0x44, 0x44, 0x34, 0x44, 0x44, 0x44,
					 0x43, 0x44, 0x44, 0x43, 0x44, 0x44,
					 0x34, 0x44, 0x44, 0x34, 0x44, 0x44,
					 0x34, 0x44, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xee,
					 0x40, 0x44, 0x44, 0x44, 0x44, 0x44,
					 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
					 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
					 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
					 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
					 0x44, 0x44, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x04, 0x04, 0x04, 0x04,
					 0x04, 0x04, 0x04, 0x04, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x04, 0x04, 0x04, 0x04, 0x04,
					 0x04, 0x04, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xe0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x04, 0x04, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xf0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
					 0xff, 0xff, 0xff, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x00, 0x00, 0x25, 0x09, 0x0b, 0x26,
					 0x26, 0x01, 0x25, 0x25);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x25, 0x0c, 0x0a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x26, 0x26, 0x02, 0x25, 0x25, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x00, 0x00, 0x25, 0x0a, 0x0c, 0x26,
					 0x25, 0x02, 0x26, 0x25);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x25, 0x0b, 0x09);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x26, 0x25, 0x01, 0x26, 0x25, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0x87, 0x01, 0x00, 0x86, 0x01, 0x00,
					 0x0f, 0x00, 0x00, 0x0f, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0xf0, 0x00, 0x00, 0xf0, 0x00, 0x00,
					 0xf0, 0x00, 0x00, 0xf0, 0x00, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0x18, 0x05, 0x83, 0xc2, 0x86, 0x11,
					 0x00, 0x18, 0x06, 0x83, 0xc4, 0x88,
					 0x11, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0x18, 0x03, 0x83, 0xc3, 0x86, 0x11,
					 0x00, 0x18, 0x04, 0x83, 0xc5, 0x88,
					 0x11, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0xf0, 0x00, 0x00, 0x10, 0x00, 0x00,
					 0x00, 0xf0, 0x00, 0x00, 0x10, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0xf0, 0x00, 0x00, 0x10, 0x00, 0x00,
					 0x00, 0xf0, 0x00, 0x00, 0x10, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf,
					 0x02, 0x02, 0x20, 0x20, 0x00, 0x00,
					 0x01, 0x01, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb4);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x50, 0x48);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x94);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x55, 0x55);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf,
					 0xf0, 0x00, 0x00, 0x10, 0x00, 0x00,
					 0x00, 0xf0, 0x00, 0x00, 0x10, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf,
					 0xf0, 0x00, 0x00, 0x10, 0x00, 0x00,
					 0x00, 0xf0, 0x00, 0x00, 0x10, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf,
					 0xf0, 0x00, 0x00, 0x10, 0x00, 0x00,
					 0x00, 0xf0, 0x00, 0x00, 0x10, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf,
					 0xf0, 0x00, 0x00, 0x10, 0x00, 0x00,
					 0x00, 0xf0, 0x00, 0x00, 0x10, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x84);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x86);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x00);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 20);

	return dsi_ctx.accum_err;
}

static int boeotm9605a_off(struct boeotm9605a *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 50);

	return dsi_ctx.accum_err;
}

static int boeotm9605a_prepare(struct drm_panel *panel)
{
	struct boeotm9605a *ctx = to_boeotm9605a(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(boeotm9605a_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	boeotm9605a_reset(ctx);

	ret = boeotm9605a_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(boeotm9605a_supplies), ctx->supplies);
		return ret;
	}

	return 0;
}

static int boeotm9605a_unprepare(struct drm_panel *panel)
{
	struct boeotm9605a *ctx = to_boeotm9605a(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = boeotm9605a_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(boeotm9605a_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode boeotm9605a_mode = {
	.clock = (540 + 15 + 8 + 80) * (960 + 15 + 1 + 16) * 60 / 1000,
	.hdisplay = 540,
	.hsync_start = 540 + 15,
	.hsync_end = 540 + 15 + 8,
	.htotal = 540 + 15 + 8 + 80,
	.vdisplay = 960,
	.vsync_start = 960 + 15,
	.vsync_end = 960 + 15 + 1,
	.vtotal = 960 + 15 + 1 + 16,
	.width_mm = 62,
	.height_mm = 110,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int boeotm9605a_get_modes(struct drm_panel *panel,
				 struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &boeotm9605a_mode);
}

static const struct drm_panel_funcs boeotm9605a_panel_funcs = {
	.prepare = boeotm9605a_prepare,
	.unprepare = boeotm9605a_unprepare,
	.get_modes = boeotm9605a_get_modes,
};

static int boeotm9605a_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct boeotm9605a *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct boeotm9605a, panel,
				   &boeotm9605a_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(boeotm9605a_supplies),
					    boeotm9605a_supplies,
					    &ctx->supplies);
	if (ret < 0)
		return ret;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 2;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_MODE_VIDEO_HSE | MIPI_DSI_MODE_NO_EOT_PACKET |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS |
			  MIPI_DSI_MODE_VIDEO_NO_HBP;

	ctx->panel.prepare_prev_first = true;

	ret = drm_panel_of_backlight(&ctx->panel);
	if (ret)
		return dev_err_probe(dev, ret, "Failed to get backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void boeotm9605a_remove(struct mipi_dsi_device *dsi)
{
	struct boeotm9605a *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id boeotm9605a_of_match[] = {
	{ .compatible = "mdss,boeotm9605a" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, boeotm9605a_of_match);

static struct mipi_dsi_driver boeotm9605a_driver = {
	.probe = boeotm9605a_probe,
	.remove = boeotm9605a_remove,
	.driver = {
		.name = "panel-boeotm9605a",
		.of_match_table = boeotm9605a_of_match,
	},
};
module_mipi_dsi_driver(boeotm9605a_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for boeotm9605a qHD video mode dsi panel");
MODULE_LICENSE("GPL");
