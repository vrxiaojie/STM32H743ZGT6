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



lv_calendar_date_t calender_screen_calendar_1_today;
lv_calendar_date_t calender_screen_calendar_1_highlihted_days[1];
void setup_scr_calender_screen(lv_ui *ui)
{
    //Write codes calender_screen
    ui->calender_screen = lv_obj_create(NULL);
    ui->g_kb_calender_screen = lv_keyboard_create(ui->calender_screen);
    lv_obj_add_event_cb(ui->g_kb_calender_screen, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_calender_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_calender_screen, &lv_font_CN_xiaobiaosong_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->calender_screen, 320, 240);
    lv_obj_set_scrollbar_mode(ui->calender_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for calender_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->calender_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes calender_screen_cont_1
    ui->calender_screen_cont_1 = lv_obj_create(ui->calender_screen);
    lv_obj_set_pos(ui->calender_screen_cont_1, 0, 0);
    lv_obj_set_size(ui->calender_screen_cont_1, 320, 240);
    lv_obj_set_scrollbar_mode(ui->calender_screen_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for calender_screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->calender_screen_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->calender_screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->calender_screen_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->calender_screen_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->calender_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->calender_screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->calender_screen_cont_1, lv_color_hex(0x304B66), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->calender_screen_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->calender_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->calender_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->calender_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->calender_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->calender_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes calender_screen_calendar_1
    ui->calender_screen_calendar_1 = lv_calendar_create(ui->calender_screen_cont_1);
    calender_screen_calendar_1_today.year = 2024;
    calender_screen_calendar_1_today.month = 10;
    calender_screen_calendar_1_today.day = 9;
    lv_calendar_set_today_date(ui->calender_screen_calendar_1, calender_screen_calendar_1_today.year, calender_screen_calendar_1_today.month, calender_screen_calendar_1_today.day);
    lv_calendar_set_showed_date(ui->calender_screen_calendar_1, calender_screen_calendar_1_today.year, calender_screen_calendar_1_today.month);
    calender_screen_calendar_1_highlihted_days[0].year = 2024;
    calender_screen_calendar_1_highlihted_days[0].month = 10;
    calender_screen_calendar_1_highlihted_days[0].day = 10;
    lv_calendar_set_highlighted_dates(ui->calender_screen_calendar_1, calender_screen_calendar_1_highlihted_days, 1);
    lv_obj_t *calender_screen_calendar_1_header = lv_calendar_header_arrow_create(ui->calender_screen_calendar_1);
    lv_calendar_t *calender_screen_calendar_1 = (lv_calendar_t *)ui->calender_screen_calendar_1;
    lv_obj_add_event_cb(calender_screen_calendar_1->btnm, calender_screen_calendar_1_draw_part_begin_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
    lv_obj_add_event_cb(ui->calender_screen_calendar_1, calender_screen_calendar_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->calender_screen_calendar_1, 30, 49);
    lv_obj_set_size(ui->calender_screen_calendar_1, 262, 184);

    //Write style state: LV_STATE_DEFAULT for &style_calender_screen_calendar_1_main_main_default
    static lv_style_t style_calender_screen_calendar_1_main_main_default;
    ui_init_style(&style_calender_screen_calendar_1_main_main_default);

    lv_style_set_border_width(&style_calender_screen_calendar_1_main_main_default, 3);
    lv_style_set_border_opa(&style_calender_screen_calendar_1_main_main_default, 255);
    lv_style_set_border_color(&style_calender_screen_calendar_1_main_main_default, lv_color_hex(0xc0c0c0));
    lv_style_set_border_side(&style_calender_screen_calendar_1_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_bg_opa(&style_calender_screen_calendar_1_main_main_default, 255);
    lv_style_set_bg_color(&style_calender_screen_calendar_1_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_calender_screen_calendar_1_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_shadow_width(&style_calender_screen_calendar_1_main_main_default, 0);
    lv_style_set_radius(&style_calender_screen_calendar_1_main_main_default, 6);
    lv_obj_add_style(ui->calender_screen_calendar_1, &style_calender_screen_calendar_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_calender_screen_calendar_1_extra_header_main_default
    static lv_style_t style_calender_screen_calendar_1_extra_header_main_default;
    ui_init_style(&style_calender_screen_calendar_1_extra_header_main_default);

    lv_style_set_text_color(&style_calender_screen_calendar_1_extra_header_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_calender_screen_calendar_1_extra_header_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_calender_screen_calendar_1_extra_header_main_default, 255);
    lv_style_set_bg_opa(&style_calender_screen_calendar_1_extra_header_main_default, 255);
    lv_style_set_bg_color(&style_calender_screen_calendar_1_extra_header_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_calender_screen_calendar_1_extra_header_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(calender_screen_calendar_1_header, &style_calender_screen_calendar_1_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_calender_screen_calendar_1_main_items_default
    static lv_style_t style_calender_screen_calendar_1_main_items_default;
    ui_init_style(&style_calender_screen_calendar_1_main_items_default);

    lv_style_set_bg_opa(&style_calender_screen_calendar_1_main_items_default, 0);
    lv_style_set_border_width(&style_calender_screen_calendar_1_main_items_default, 1);
    lv_style_set_border_opa(&style_calender_screen_calendar_1_main_items_default, 255);
    lv_style_set_border_color(&style_calender_screen_calendar_1_main_items_default, lv_color_hex(0xc0c0c0));
    lv_style_set_border_side(&style_calender_screen_calendar_1_main_items_default, LV_BORDER_SIDE_FULL);
    lv_style_set_text_color(&style_calender_screen_calendar_1_main_items_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_calender_screen_calendar_1_main_items_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_calender_screen_calendar_1_main_items_default, 255);
    lv_obj_add_style(lv_calendar_get_btnmatrix(ui->calender_screen_calendar_1), &style_calender_screen_calendar_1_main_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes calender_screen_btn_BackToMain
    ui->calender_screen_btn_BackToMain = lv_btn_create(ui->calender_screen_cont_1);
    ui->calender_screen_btn_BackToMain_label = lv_label_create(ui->calender_screen_btn_BackToMain);
    lv_label_set_text(ui->calender_screen_btn_BackToMain_label, "←");
    lv_label_set_long_mode(ui->calender_screen_btn_BackToMain_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->calender_screen_btn_BackToMain_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->calender_screen_btn_BackToMain, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->calender_screen_btn_BackToMain_label, LV_PCT(100));
    lv_obj_set_pos(ui->calender_screen_btn_BackToMain, 10, 13);
    lv_obj_set_size(ui->calender_screen_btn_BackToMain, 39, 26);

    //Write style for calender_screen_btn_BackToMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->calender_screen_btn_BackToMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->calender_screen_btn_BackToMain, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->calender_screen_btn_BackToMain, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->calender_screen_btn_BackToMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->calender_screen_btn_BackToMain, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->calender_screen_btn_BackToMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->calender_screen_btn_BackToMain, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->calender_screen_btn_BackToMain, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->calender_screen_btn_BackToMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->calender_screen_btn_BackToMain, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes calender_screen_label_1
    ui->calender_screen_label_1 = lv_label_create(ui->calender_screen);
    lv_label_set_text(ui->calender_screen_label_1, "日历");
    lv_label_set_long_mode(ui->calender_screen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->calender_screen_label_1, 113, 18);
    lv_obj_set_size(ui->calender_screen_label_1, 100, 32);

    //Write style for calender_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->calender_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->calender_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->calender_screen_label_1, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->calender_screen_label_1, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->calender_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->calender_screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->calender_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->calender_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->calender_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->calender_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->calender_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->calender_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->calender_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->calender_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of calender_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->calender_screen);

    //Init events for screen.
    events_init_calender_screen(ui);
}
