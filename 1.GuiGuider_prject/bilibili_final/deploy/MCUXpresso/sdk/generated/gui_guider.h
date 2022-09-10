/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	lv_obj_t *screen_img_mouth;
	lv_obj_t *screen_btnm_right;
	lv_obj_t *screen_btnm_left;
	lv_obj_t *screen_label_left_eye;
	lv_obj_t *screen_label_right_eye;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_blue_mouth_120x40);

#ifdef __cplusplus
}
#endif
#endif