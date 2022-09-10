// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

static void anim_wait_loop_cb(void* var, int32_t v)
{
    lv_ui* ui = (lv_ui*)var;
    lv_obj_t* lable_left_eye = ui->screen_label_left_eye;
    lv_obj_t* lable_right_eye = ui->screen_label_right_eye;
    lv_obj_align(lable_left_eye,LV_ALIGN_CENTER,-100, -30 + v);
    lv_obj_align(lable_right_eye,LV_ALIGN_CENTER,100, -30 + v);

}


static void anim_wait_loop(lv_ui* ui) {
    lv_anim_t a;
    lv_anim_init(&a);                     
    lv_anim_set_var(&a, ui);                       
    lv_anim_set_values(&a, 0, 10);
    lv_anim_set_time(&a, 1000);                     
    lv_anim_set_exec_cb(&a, anim_wait_loop_cb); 

    lv_anim_set_playback_time(&a, 1000);           
    lv_anim_set_repeat_delay(&a, 100);             
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out); 

    lv_anim_start(&a);
}

static void stop_anim(lv_ui* ui) {
    lv_anim_del(ui, anim_wait_loop_cb);
}



static void btnm_left_event_handle(lv_event_t* e)
{
    printf("enter left handle\n");

    lv_ui* ui = lv_event_get_user_data(e);
    uint32_t id = lv_btnmatrix_get_selected_btn(ui->screen_btnm_left);

    switch (id)
    {
    case 0:
        anim_wait_loop(ui);
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        stop_anim(ui);
        break;
    default:
        break;
    }
}

static void anim_wait_to_work_cb(void* var, int32_t v)
{
    lv_ui* ui = (lv_ui*)var;
    lv_obj_t* lable_left_eye = ui->screen_label_left_eye;
    lv_obj_t* lable_right_eye = ui->screen_label_right_eye;

    lv_coord_t width = lv_obj_get_width(lable_left_eye);
    lv_coord_t height = lv_obj_get_height(lable_left_eye);

    // set height and width
    lv_obj_set_width(lable_left_eye, width - 2 );
    lv_obj_set_width(lable_right_eye, width - 2 );
    lv_obj_set_height(lable_left_eye,height + 2 );
    lv_obj_set_height(lable_right_eye,height + 2 );
    
}

static void anim_wait_to_work(lv_ui* ui) {
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, ui);
    lv_anim_set_values(&a, 0, 70);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_exec_cb(&a, anim_wait_to_work_cb);         

    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out); 

    lv_anim_start(&a);                    
}




//////////////////////////////////////////////////////////////////////////
static void anim_look_at_left_cb(void* var, int32_t v)
{
    lv_ui* ui = (lv_ui*)var;
    lv_obj_t* lable_left_eye = ui->screen_label_left_eye;
    lv_obj_t* lable_right_eye = ui->screen_label_right_eye;

    // set height and width
    lv_obj_set_x(lable_left_eye, -100 - v);
    lv_obj_set_x(lable_right_eye, 100 - v);
}

static void anim_look_at_left(lv_ui* ui) {
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, ui);
    lv_anim_set_values(&a, 0, 20);         
    lv_anim_set_time(&a, 500);                  
    lv_anim_set_exec_cb(&a, anim_look_at_left_cb);         
    lv_anim_set_playback_time(&a, 1000);           
    lv_anim_set_repeat_delay(&a, 100);             

    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out); 

    lv_anim_start(&a);                    
}



///////////////////////////////////////////////////////////////////////////
static void anim_look_at_right_cb(void* var, int32_t v)
{
    lv_ui* ui = (lv_ui*)var;
    lv_obj_t* lable_left_eye = ui->screen_label_left_eye;
    lv_obj_t* lable_right_eye = ui->screen_label_right_eye;

    // set height and width
    lv_obj_set_x(lable_left_eye, -100 + v);
    lv_obj_set_x(lable_right_eye, 100 + v);

}

static void anim_look_at_right(lv_ui* ui) {
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, ui);
    lv_anim_set_values(&a, 0, 20);         
    lv_anim_set_time(&a, 500);                  
    lv_anim_set_exec_cb(&a, anim_look_at_right_cb);         
    lv_anim_set_playback_time(&a, 1000);           
    lv_anim_set_repeat_delay(&a, 100);             

    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out); 

    lv_anim_start(&a);                    
}

///////////////////////////////////////////////////////////////////////
static void btnm_right_event_handle(lv_event_t* e)
{
    printf("enter right handle\n");

    lv_ui* ui = lv_event_get_user_data(e);
    uint32_t id = lv_btnmatrix_get_selected_btn(ui->screen_btnm_right);

    switch (id)
    {
    case 0:
        anim_wait_to_work(ui);
        break;
    case 1:
        anim_look_at_left(ui);
        break;
    case 2:
        anim_look_at_right(ui);
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        printf("stop anim\n");
        stop_anim(ui);
        break;
    default:
        break;
    }
}

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    lv_obj_add_event_cb(ui->screen_btnm_left, btnm_left_event_handle, LV_EVENT_PRESSED, ui);
    lv_obj_add_event_cb(ui->screen_btnm_right, btnm_right_event_handle, LV_EVENT_PRESSED, ui);
}

