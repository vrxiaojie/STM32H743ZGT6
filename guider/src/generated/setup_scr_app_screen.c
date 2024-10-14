/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_app_screen(lv_ui *ui)
{
    //Write codes app_screen
    ui->app_screen = lv_obj_create(NULL);
    ui->g_kb_app_screen = lv_keyboard_create(ui->app_screen);
    lv_obj_add_event_cb(ui->g_kb_app_screen, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_app_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_app_screen, &lv_font_CN_xiaobiaosong_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->app_screen, 320, 240);
    lv_obj_set_scrollbar_mode(ui->app_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for app_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->app_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes app_screen_cont_1
    ui->app_screen_cont_1 = lv_obj_create(ui->app_screen);
    lv_obj_set_pos(ui->app_screen_cont_1, 1, 0);
    lv_obj_set_size(ui->app_screen_cont_1, 320, 240);
    lv_obj_set_scrollbar_mode(ui->app_screen_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for app_screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->app_screen_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->app_screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->app_screen_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->app_screen_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->app_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->app_screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->app_screen_cont_1, lv_color_hex(0x304B66), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->app_screen_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->app_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->app_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->app_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->app_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->app_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes app_screen_sw_gps
    ui->app_screen_sw_gps = lv_switch_create(ui->app_screen_cont_1);
    lv_obj_set_pos(ui->app_screen_sw_gps, 176, 13);
    lv_obj_set_size(ui->app_screen_sw_gps, 40, 20);

    //Write style for app_screen_sw_gps, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->app_screen_sw_gps, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->app_screen_sw_gps, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->app_screen_sw_gps, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->app_screen_sw_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->app_screen_sw_gps, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->app_screen_sw_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for app_screen_sw_gps, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->app_screen_sw_gps, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->app_screen_sw_gps, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->app_screen_sw_gps, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->app_screen_sw_gps, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for app_screen_sw_gps, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->app_screen_sw_gps, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->app_screen_sw_gps, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->app_screen_sw_gps, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->app_screen_sw_gps, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->app_screen_sw_gps, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes app_screen_label_1
    ui->app_screen_label_1 = lv_label_create(ui->app_screen_cont_1);
    lv_label_set_text(ui->app_screen_label_1, "GPS");
    lv_label_set_long_mode(ui->app_screen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->app_screen_label_1, 72, 14);
    lv_obj_set_size(ui->app_screen_label_1, 100, 32);

    //Write style for app_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->app_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->app_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->app_screen_label_1, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->app_screen_label_1, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->app_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->app_screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->app_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->app_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->app_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->app_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->app_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->app_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->app_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->app_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes app_screen_table_gps
    ui->app_screen_table_gps = lv_table_create(ui->app_screen_cont_1);
    lv_table_set_col_cnt(ui->app_screen_table_gps,2);
    lv_table_set_row_cnt(ui->app_screen_table_gps,5);
    lv_table_set_cell_value(ui->app_screen_table_gps,0,0,"状态");
    lv_table_set_cell_value(ui->app_screen_table_gps,1,0,"纬度");
    lv_table_set_cell_value(ui->app_screen_table_gps,2,0,"经度");
    lv_table_set_cell_value(ui->app_screen_table_gps,3,0,"UTC+8");
    lv_table_set_cell_value(ui->app_screen_table_gps,4,0,"速度");
    lv_table_set_cell_value(ui->app_screen_table_gps,0,1,"");
    lv_table_set_cell_value(ui->app_screen_table_gps,1,1,"");
    lv_table_set_cell_value(ui->app_screen_table_gps,2,1,"");
    lv_table_set_cell_value(ui->app_screen_table_gps,3,1,"");
    lv_table_set_cell_value(ui->app_screen_table_gps,4,1,"");
    lv_obj_set_pos(ui->app_screen_table_gps, 22, 44);
    lv_obj_set_scrollbar_mode(ui->app_screen_table_gps, LV_SCROLLBAR_MODE_OFF);

    //Write style for app_screen_table_gps, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->app_screen_table_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->app_screen_table_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->app_screen_table_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->app_screen_table_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->app_screen_table_gps, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->app_screen_table_gps, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->app_screen_table_gps, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->app_screen_table_gps, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->app_screen_table_gps, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->app_screen_table_gps, lv_color_hex(0xd5dee6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->app_screen_table_gps, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->app_screen_table_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->app_screen_table_gps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for app_screen_table_gps, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->app_screen_table_gps, lv_color_hex(0x393c41), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->app_screen_table_gps, &lv_font_CN_xiaobiaosong_14, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->app_screen_table_gps, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->app_screen_table_gps, LV_TEXT_ALIGN_CENTER, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->app_screen_table_gps, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->app_screen_table_gps, 3, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->app_screen_table_gps, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->app_screen_table_gps, lv_color_hex(0xd5dee6), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->app_screen_table_gps, LV_BORDER_SIDE_FULL, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->app_screen_table_gps, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->app_screen_table_gps, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->app_screen_table_gps, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->app_screen_table_gps, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes app_screen_btn_BackToMain
    ui->app_screen_btn_BackToMain = lv_btn_create(ui->app_screen);
    ui->app_screen_btn_BackToMain_label = lv_label_create(ui->app_screen_btn_BackToMain);
    lv_label_set_text(ui->app_screen_btn_BackToMain_label, "←");
    lv_label_set_long_mode(ui->app_screen_btn_BackToMain_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->app_screen_btn_BackToMain_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->app_screen_btn_BackToMain, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->app_screen_btn_BackToMain_label, LV_PCT(100));
    lv_obj_set_pos(ui->app_screen_btn_BackToMain, 13, 7);
    lv_obj_set_size(ui->app_screen_btn_BackToMain, 39, 26);

    //Write style for app_screen_btn_BackToMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->app_screen_btn_BackToMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->app_screen_btn_BackToMain, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->app_screen_btn_BackToMain, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->app_screen_btn_BackToMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->app_screen_btn_BackToMain, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->app_screen_btn_BackToMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->app_screen_btn_BackToMain, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->app_screen_btn_BackToMain, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->app_screen_btn_BackToMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->app_screen_btn_BackToMain, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of app_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->app_screen);

    //Init events for screen.
    events_init_app_screen(ui);
}
