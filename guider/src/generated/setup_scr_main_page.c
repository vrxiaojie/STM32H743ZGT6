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



void setup_scr_main_page(lv_ui *ui)
{
    //Write codes main_page
    ui->main_page = lv_obj_create(NULL);
    ui->g_kb_main_page = lv_keyboard_create(ui->main_page);
    lv_obj_add_event_cb(ui->g_kb_main_page, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_main_page, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_main_page, &lv_font_CN_xiaobiaosong_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->main_page, 320, 240);
    lv_obj_set_scrollbar_mode(ui->main_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for main_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_page, lv_color_hex(0x304B66), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_cont_1
    ui->main_page_cont_1 = lv_obj_create(ui->main_page);
    lv_obj_set_pos(ui->main_page_cont_1, 9, 26);
    lv_obj_set_size(ui->main_page_cont_1, 143, 100);
    lv_obj_set_scrollbar_mode(ui->main_page_cont_1, LV_SCROLLBAR_MODE_AUTO);

    //Write style for main_page_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_page_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_page_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_page_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_page_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_cont_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_page_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_page_cont_1, lv_color_hex(0x445362), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_page_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_page_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_img_app
    ui->main_page_img_app = lv_img_create(ui->main_page_cont_1);
    lv_obj_add_flag(ui->main_page_img_app, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_page_img_app, &_applications_alpha_80x80);
    lv_img_set_pivot(ui->main_page_img_app, 50,50);
    lv_img_set_angle(ui->main_page_img_app, 0);
    lv_obj_set_pos(ui->main_page_img_app, 27, 10);
    lv_obj_set_size(ui->main_page_img_app, 80, 80);

    //Write style for main_page_img_app, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_page_img_app, 242, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->main_page_img_app, lv_color_hex(0x07a4eb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_page_img_app, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_img_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_page_img_app, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_cont_2
    ui->main_page_cont_2 = lv_obj_create(ui->main_page);
    lv_obj_set_pos(ui->main_page_cont_2, 164, 26);
    lv_obj_set_size(ui->main_page_cont_2, 143, 100);
    lv_obj_set_scrollbar_mode(ui->main_page_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for main_page_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_page_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_page_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_page_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_page_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_cont_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_page_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_page_cont_2, lv_color_hex(0x445362), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_page_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_page_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_img_calender
    ui->main_page_img_calender = lv_img_create(ui->main_page_cont_2);
    lv_obj_add_flag(ui->main_page_img_calender, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_page_img_calender, &_calendar_alpha_80x80);
    lv_img_set_pivot(ui->main_page_img_calender, 50,50);
    lv_img_set_angle(ui->main_page_img_calender, 0);
    lv_obj_set_pos(ui->main_page_img_calender, 28, 10);
    lv_obj_set_size(ui->main_page_img_calender, 80, 80);

    //Write style for main_page_img_calender, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_page_img_calender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_page_img_calender, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_img_calender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_page_img_calender, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_cont_3
    ui->main_page_cont_3 = lv_obj_create(ui->main_page);
    lv_obj_set_pos(ui->main_page_cont_3, 9, 134);
    lv_obj_set_size(ui->main_page_cont_3, 143, 100);
    lv_obj_set_scrollbar_mode(ui->main_page_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for main_page_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_page_cont_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_page_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_page_cont_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_page_cont_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_cont_3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_page_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_page_cont_3, lv_color_hex(0x445362), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_page_cont_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_page_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_img_serial
    ui->main_page_img_serial = lv_img_create(ui->main_page_cont_3);
    lv_obj_add_flag(ui->main_page_img_serial, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_page_img_serial, &_serial_alpha_80x80);
    lv_img_set_pivot(ui->main_page_img_serial, 50,50);
    lv_img_set_angle(ui->main_page_img_serial, 0);
    lv_obj_set_pos(ui->main_page_img_serial, 27, 8);
    lv_obj_set_size(ui->main_page_img_serial, 80, 80);

    //Write style for main_page_img_serial, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_page_img_serial, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->main_page_img_serial, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_page_img_serial, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_img_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_page_img_serial, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_cont_4
    ui->main_page_cont_4 = lv_obj_create(ui->main_page);
    lv_obj_set_pos(ui->main_page_cont_4, 164, 134);
    lv_obj_set_size(ui->main_page_cont_4, 143, 100);
    lv_obj_set_scrollbar_mode(ui->main_page_cont_4, LV_SCROLLBAR_MODE_OFF);

    //Write style for main_page_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_page_cont_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_page_cont_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_page_cont_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_page_cont_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_cont_4, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_page_cont_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_page_cont_4, lv_color_hex(0x445362), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_page_cont_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_page_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_img_1
    ui->main_page_img_1 = lv_img_create(ui->main_page_cont_4);
    lv_obj_add_flag(ui->main_page_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_page_img_1, &_setting_alpha_80x80);
    lv_img_set_pivot(ui->main_page_img_1, 50,50);
    lv_img_set_angle(ui->main_page_img_1, 0);
    lv_obj_set_pos(ui->main_page_img_1, 32, 8);
    lv_obj_set_size(ui->main_page_img_1, 80, 80);

    //Write style for main_page_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_page_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->main_page_img_1, lv_color_hex(0x30c4a6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_page_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_page_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_label_battery
    ui->main_page_label_battery = lv_label_create(ui->main_page);
    lv_label_set_text(ui->main_page_label_battery, "" LV_SYMBOL_BATTERY_FULL " ");
    lv_label_set_long_mode(ui->main_page_label_battery, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->main_page_label_battery, 258, 2);
    lv_obj_set_size(ui->main_page_label_battery, 100, 32);

    //Write style for main_page_label_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_page_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_page_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_page_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_page_label_battery, lv_color_hex(0x08fe09), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_page_label_battery, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_page_label_battery, 223, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->main_page_label_battery, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->main_page_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_page_label_battery, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_datetext_1
    ui->main_page_datetext_1 = lv_label_create(ui->main_page);
    lv_label_set_text(ui->main_page_datetext_1, "2024/10/09");
    lv_obj_set_style_text_align(ui->main_page_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->main_page_datetext_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->main_page_datetext_1, main_page_datetext_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->main_page_datetext_1, -5, -5);
    lv_obj_set_size(ui->main_page_datetext_1, 130, 36);

    //Write style for main_page_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_page_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_page_datetext_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_page_datetext_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_page_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->main_page_datetext_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_page_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_page_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_cont_5
    ui->main_page_cont_5 = lv_obj_create(ui->main_page);
    lv_obj_set_pos(ui->main_page_cont_5, 9, 242);
    lv_obj_set_size(ui->main_page_cont_5, 143, 100);
    lv_obj_set_scrollbar_mode(ui->main_page_cont_5, LV_SCROLLBAR_MODE_AUTO);

    //Write style for main_page_cont_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_page_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_page_cont_5, lv_color_hex(0x445362), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_page_cont_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->main_page_cont_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_page_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_page_cont_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_page_cont_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_cont_5, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_page_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_img_file_explorer
    ui->main_page_img_file_explorer = lv_img_create(ui->main_page_cont_5);
    lv_obj_add_flag(ui->main_page_img_file_explorer, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_page_img_file_explorer, &_file_explorer_alpha_80x80);
    lv_img_set_pivot(ui->main_page_img_file_explorer, 50,50);
    lv_img_set_angle(ui->main_page_img_file_explorer, 0);
    lv_obj_set_pos(ui->main_page_img_file_explorer, 27, 7);
    lv_obj_set_size(ui->main_page_img_file_explorer, 80, 80);

    //Write style for main_page_img_file_explorer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_page_img_file_explorer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_page_img_file_explorer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_img_file_explorer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_page_img_file_explorer, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_page_cont_6
    ui->main_page_cont_6 = lv_obj_create(ui->main_page);
    lv_obj_set_pos(ui->main_page_cont_6, 164, 242);
    lv_obj_set_size(ui->main_page_cont_6, 143, 100);
    lv_obj_set_scrollbar_mode(ui->main_page_cont_6, LV_SCROLLBAR_MODE_AUTO);

    //Write style for main_page_cont_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_page_cont_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_page_cont_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_page_cont_6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_page_cont_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_cont_6, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_page_cont_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_page_cont_6, lv_color_hex(0x445362), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_page_cont_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_page_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of main_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->main_page);

    //Init events for screen.
    events_init_main_page(ui);
}
