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



void setup_scr_serial_assistant_screen(lv_ui *ui)
{
    //Write codes serial_assistant_screen
    ui->serial_assistant_screen = lv_obj_create(NULL);
    ui->g_kb_serial_assistant_screen = lv_keyboard_create(ui->serial_assistant_screen);
    lv_obj_add_event_cb(ui->g_kb_serial_assistant_screen, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_serial_assistant_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_serial_assistant_screen, &lv_font_CN_xiaobiaosong_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->serial_assistant_screen, 320, 240);
    lv_obj_set_scrollbar_mode(ui->serial_assistant_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for serial_assistant_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->serial_assistant_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes serial_assistant_screen_cont_1
    ui->serial_assistant_screen_cont_1 = lv_obj_create(ui->serial_assistant_screen);
    lv_obj_set_pos(ui->serial_assistant_screen_cont_1, 0, 0);
    lv_obj_set_size(ui->serial_assistant_screen_cont_1, 320, 240);
    lv_obj_set_scrollbar_mode(ui->serial_assistant_screen_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for serial_assistant_screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->serial_assistant_screen_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->serial_assistant_screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->serial_assistant_screen_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->serial_assistant_screen_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->serial_assistant_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->serial_assistant_screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->serial_assistant_screen_cont_1, lv_color_hex(0x304B66), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->serial_assistant_screen_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->serial_assistant_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->serial_assistant_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->serial_assistant_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->serial_assistant_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->serial_assistant_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes serial_assistant_screen_ddlist_1
    ui->serial_assistant_screen_ddlist_1 = lv_dropdown_create(ui->serial_assistant_screen_cont_1);
    lv_dropdown_set_options(ui->serial_assistant_screen_ddlist_1, "USART1(调试)\nUART5(定位)");
    lv_obj_set_pos(ui->serial_assistant_screen_ddlist_1, 95, 116);
    lv_obj_set_size(ui->serial_assistant_screen_ddlist_1, 130, 30);

    //Write style for serial_assistant_screen_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->serial_assistant_screen_ddlist_1, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->serial_assistant_screen_ddlist_1, &lv_font_CN_xiaobiaosong_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->serial_assistant_screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->serial_assistant_screen_ddlist_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->serial_assistant_screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->serial_assistant_screen_ddlist_1, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->serial_assistant_screen_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->serial_assistant_screen_ddlist_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->serial_assistant_screen_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->serial_assistant_screen_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->serial_assistant_screen_ddlist_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->serial_assistant_screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->serial_assistant_screen_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->serial_assistant_screen_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->serial_assistant_screen_ddlist_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_serial_assistant_screen_ddlist_1_extra_list_selected_checked
    static lv_style_t style_serial_assistant_screen_ddlist_1_extra_list_selected_checked;
    ui_init_style(&style_serial_assistant_screen_ddlist_1_extra_list_selected_checked);

    lv_style_set_border_width(&style_serial_assistant_screen_ddlist_1_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_serial_assistant_screen_ddlist_1_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_serial_assistant_screen_ddlist_1_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_serial_assistant_screen_ddlist_1_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_serial_assistant_screen_ddlist_1_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_serial_assistant_screen_ddlist_1_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_serial_assistant_screen_ddlist_1_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_serial_assistant_screen_ddlist_1_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->serial_assistant_screen_ddlist_1), &style_serial_assistant_screen_ddlist_1_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_serial_assistant_screen_ddlist_1_extra_list_main_default
    static lv_style_t style_serial_assistant_screen_ddlist_1_extra_list_main_default;
    ui_init_style(&style_serial_assistant_screen_ddlist_1_extra_list_main_default);

    lv_style_set_max_height(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, 90);
    lv_style_set_text_color(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, &lv_font_CN_xiaobiaosong_12);
    lv_style_set_text_opa(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, 255);
    lv_style_set_border_width(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, 255);
    lv_style_set_border_color(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_serial_assistant_screen_ddlist_1_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->serial_assistant_screen_ddlist_1), &style_serial_assistant_screen_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_serial_assistant_screen_ddlist_1_extra_list_scrollbar_default
    static lv_style_t style_serial_assistant_screen_ddlist_1_extra_list_scrollbar_default;
    ui_init_style(&style_serial_assistant_screen_ddlist_1_extra_list_scrollbar_default);

    lv_style_set_radius(&style_serial_assistant_screen_ddlist_1_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_serial_assistant_screen_ddlist_1_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_serial_assistant_screen_ddlist_1_extra_list_scrollbar_default, lv_color_hex(0x2F92DA));
    lv_style_set_bg_grad_dir(&style_serial_assistant_screen_ddlist_1_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->serial_assistant_screen_ddlist_1), &style_serial_assistant_screen_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes serial_assistant_screen_label_2
    ui->serial_assistant_screen_label_2 = lv_label_create(ui->serial_assistant_screen_cont_1);
    lv_label_set_text(ui->serial_assistant_screen_label_2, "串口助手");
    lv_label_set_long_mode(ui->serial_assistant_screen_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->serial_assistant_screen_label_2, 107, 15);
    lv_obj_set_size(ui->serial_assistant_screen_label_2, 100, 32);

    //Write style for serial_assistant_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->serial_assistant_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->serial_assistant_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->serial_assistant_screen_label_2, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->serial_assistant_screen_label_2, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->serial_assistant_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->serial_assistant_screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->serial_assistant_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->serial_assistant_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->serial_assistant_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->serial_assistant_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->serial_assistant_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->serial_assistant_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->serial_assistant_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->serial_assistant_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes serial_assistant_screen_label_1
    ui->serial_assistant_screen_label_1 = lv_label_create(ui->serial_assistant_screen_cont_1);
    lv_label_set_text(ui->serial_assistant_screen_label_1, "选择串口");
    lv_label_set_long_mode(ui->serial_assistant_screen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->serial_assistant_screen_label_1, 0, 121);
    lv_obj_set_size(ui->serial_assistant_screen_label_1, 100, 32);

    //Write style for serial_assistant_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->serial_assistant_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->serial_assistant_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->serial_assistant_screen_label_1, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->serial_assistant_screen_label_1, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->serial_assistant_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->serial_assistant_screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->serial_assistant_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->serial_assistant_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->serial_assistant_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->serial_assistant_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->serial_assistant_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->serial_assistant_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->serial_assistant_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->serial_assistant_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes serial_assistant_screen_btn_1
    ui->serial_assistant_screen_btn_1 = lv_btn_create(ui->serial_assistant_screen_cont_1);
    ui->serial_assistant_screen_btn_1_label = lv_label_create(ui->serial_assistant_screen_btn_1);
    lv_label_set_text(ui->serial_assistant_screen_btn_1_label, "←");
    lv_label_set_long_mode(ui->serial_assistant_screen_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->serial_assistant_screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->serial_assistant_screen_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->serial_assistant_screen_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->serial_assistant_screen_btn_1, 12, 10);
    lv_obj_set_size(ui->serial_assistant_screen_btn_1, 39, 26);

    //Write style for serial_assistant_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->serial_assistant_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->serial_assistant_screen_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->serial_assistant_screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->serial_assistant_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->serial_assistant_screen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->serial_assistant_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->serial_assistant_screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->serial_assistant_screen_btn_1, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->serial_assistant_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->serial_assistant_screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for serial_assistant_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->serial_assistant_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->serial_assistant_screen_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->serial_assistant_screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->serial_assistant_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->serial_assistant_screen_btn_1, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->serial_assistant_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->serial_assistant_screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->serial_assistant_screen_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->serial_assistant_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for serial_assistant_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->serial_assistant_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->serial_assistant_screen_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->serial_assistant_screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->serial_assistant_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->serial_assistant_screen_btn_1, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->serial_assistant_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->serial_assistant_screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->serial_assistant_screen_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->serial_assistant_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes serial_assistant_screen_btn_2
    ui->serial_assistant_screen_btn_2 = lv_btn_create(ui->serial_assistant_screen_cont_1);
    ui->serial_assistant_screen_btn_2_label = lv_label_create(ui->serial_assistant_screen_btn_2);
    lv_label_set_text(ui->serial_assistant_screen_btn_2_label, " " LV_SYMBOL_OK " ");
    lv_label_set_long_mode(ui->serial_assistant_screen_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->serial_assistant_screen_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->serial_assistant_screen_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->serial_assistant_screen_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->serial_assistant_screen_btn_2, 236, 114);
    lv_obj_set_size(ui->serial_assistant_screen_btn_2, 54, 30);

    //Write style for serial_assistant_screen_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->serial_assistant_screen_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->serial_assistant_screen_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->serial_assistant_screen_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->serial_assistant_screen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->serial_assistant_screen_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->serial_assistant_screen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->serial_assistant_screen_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->serial_assistant_screen_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->serial_assistant_screen_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->serial_assistant_screen_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes serial_assistant_screen_win_serial_1
    ui->serial_assistant_screen_win_serial_1 = lv_win_create(ui->serial_assistant_screen, 40);
    lv_obj_t * serial_assistant_screen_win_serial_1_title = lv_win_add_title(ui->serial_assistant_screen_win_serial_1, "串口助手  Serial Helper");
    ui->serial_assistant_screen_win_serial_1_item0 = lv_win_add_btn(ui->serial_assistant_screen_win_serial_1, LV_SYMBOL_TRASH, 50);
    ui->serial_assistant_screen_win_serial_1_item1 = lv_win_add_btn(ui->serial_assistant_screen_win_serial_1, LV_SYMBOL_CLOSE, 50);
    lv_obj_t *serial_assistant_screen_win_serial_1_label = lv_label_create(lv_win_get_content(ui->serial_assistant_screen_win_serial_1));
    lv_label_set_text(serial_assistant_screen_win_serial_1_label, "");
    lv_obj_set_scrollbar_mode(lv_win_get_content(ui->serial_assistant_screen_win_serial_1), LV_SCROLLBAR_MODE_ACTIVE);
    lv_obj_set_pos(ui->serial_assistant_screen_win_serial_1, 412, -79);
    lv_obj_set_size(ui->serial_assistant_screen_win_serial_1, 320, 240);
    lv_obj_set_scrollbar_mode(ui->serial_assistant_screen_win_serial_1, LV_SCROLLBAR_MODE_ACTIVE);
    lv_obj_add_flag(ui->serial_assistant_screen_win_serial_1, LV_OBJ_FLAG_HIDDEN);

    //Write style for serial_assistant_screen_win_serial_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->serial_assistant_screen_win_serial_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->serial_assistant_screen_win_serial_1, lv_color_hex(0x445362), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->serial_assistant_screen_win_serial_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->serial_assistant_screen_win_serial_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->serial_assistant_screen_win_serial_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_serial_assistant_screen_win_serial_1_extra_content_main_default
    static lv_style_t style_serial_assistant_screen_win_serial_1_extra_content_main_default;
    ui_init_style(&style_serial_assistant_screen_win_serial_1_extra_content_main_default);

    lv_style_set_bg_opa(&style_serial_assistant_screen_win_serial_1_extra_content_main_default, 255);
    lv_style_set_bg_color(&style_serial_assistant_screen_win_serial_1_extra_content_main_default, lv_color_hex(0x445362));
    lv_style_set_bg_grad_dir(&style_serial_assistant_screen_win_serial_1_extra_content_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_text_color(&style_serial_assistant_screen_win_serial_1_extra_content_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_serial_assistant_screen_win_serial_1_extra_content_main_default, &lv_font_CN_xiaobiaosong_12);
    lv_style_set_text_opa(&style_serial_assistant_screen_win_serial_1_extra_content_main_default, 255);
    lv_style_set_text_letter_space(&style_serial_assistant_screen_win_serial_1_extra_content_main_default, 0);
    lv_style_set_text_line_space(&style_serial_assistant_screen_win_serial_1_extra_content_main_default, 2);
    lv_obj_add_style(lv_win_get_content(ui->serial_assistant_screen_win_serial_1), &style_serial_assistant_screen_win_serial_1_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_serial_assistant_screen_win_serial_1_extra_header_main_default
    static lv_style_t style_serial_assistant_screen_win_serial_1_extra_header_main_default;
    ui_init_style(&style_serial_assistant_screen_win_serial_1_extra_header_main_default);

    lv_style_set_bg_opa(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, 255);
    lv_style_set_bg_color(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, lv_color_hex(0xe6e6e6));
    lv_style_set_bg_grad_dir(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_text_color(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, lv_color_hex(0x393c41));
    lv_style_set_text_font(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, &lv_font_CN_xiaobiaosong_14);
    lv_style_set_text_opa(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, 255);
    lv_style_set_text_letter_space(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, 0);
    lv_style_set_text_line_space(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, 2);
    lv_style_set_pad_top(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, 5);
    lv_style_set_pad_right(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, 5);
    lv_style_set_pad_bottom(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, 5);
    lv_style_set_pad_left(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, 5);
    lv_style_set_pad_column(&style_serial_assistant_screen_win_serial_1_extra_header_main_default, 5);
    lv_obj_add_style(lv_win_get_header(ui->serial_assistant_screen_win_serial_1), &style_serial_assistant_screen_win_serial_1_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_serial_assistant_screen_win_serial_1_extra_btns_main_default
    static lv_style_t style_serial_assistant_screen_win_serial_1_extra_btns_main_default;
    ui_init_style(&style_serial_assistant_screen_win_serial_1_extra_btns_main_default);

    lv_style_set_radius(&style_serial_assistant_screen_win_serial_1_extra_btns_main_default, 8);
    lv_style_set_border_width(&style_serial_assistant_screen_win_serial_1_extra_btns_main_default, 0);
    lv_style_set_bg_opa(&style_serial_assistant_screen_win_serial_1_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_serial_assistant_screen_win_serial_1_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_serial_assistant_screen_win_serial_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_shadow_width(&style_serial_assistant_screen_win_serial_1_extra_btns_main_default, 0);
    lv_obj_add_style(ui->serial_assistant_screen_win_serial_1_item1, &style_serial_assistant_screen_win_serial_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->serial_assistant_screen_win_serial_1_item0, &style_serial_assistant_screen_win_serial_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of serial_assistant_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->serial_assistant_screen);

    //Init events for screen.
    events_init_serial_assistant_screen(ui);
}
