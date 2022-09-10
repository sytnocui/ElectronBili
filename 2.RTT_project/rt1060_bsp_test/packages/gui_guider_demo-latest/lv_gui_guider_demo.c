/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

lv_ui guider_ui;

void gui_guider_setup(void)
{
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);
}

