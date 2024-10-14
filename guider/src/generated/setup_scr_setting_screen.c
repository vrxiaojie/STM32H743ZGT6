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



void setup_scr_setting_screen(lv_ui *ui)
{
    //Write codes setting_screen
    ui->setting_screen = lv_obj_create(NULL);
    ui->g_kb_setting_screen = lv_keyboard_create(ui->setting_screen);
    lv_obj_add_event_cb(ui->g_kb_setting_screen, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_setting_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_setting_screen, &lv_font_CN_xiaobiaosong_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->setting_screen, 320, 240);
    lv_obj_set_scrollbar_mode(ui->setting_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for setting_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_screen_tabview_1
    ui->setting_screen_tabview_1 = lv_tabview_create(ui->setting_screen, LV_DIR_TOP, 36);
    lv_obj_set_pos(ui->setting_screen_tabview_1, 0, 0);
    lv_obj_set_size(ui->setting_screen_tabview_1, 320, 240);
    lv_obj_set_scrollbar_mode(ui->setting_screen_tabview_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for setting_screen_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_screen_tabview_1, lv_color_hex(0x304B66), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_screen_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_screen_tabview_1, &lv_font_CN_xiaobiaosong_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_screen_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_screen_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_screen_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_setting_screen_tabview_1_extra_btnm_main_default
    static lv_style_t style_setting_screen_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_setting_screen_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_setting_screen_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_setting_screen_tabview_1_extra_btnm_main_default, lv_color_hex(0x304B66));
    lv_style_set_bg_grad_dir(&style_setting_screen_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_setting_screen_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_setting_screen_tabview_1_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->setting_screen_tabview_1), &style_setting_screen_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_setting_screen_tabview_1_extra_btnm_items_default
    static lv_style_t style_setting_screen_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_setting_screen_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_setting_screen_tabview_1_extra_btnm_items_default, lv_color_hex(0x2F92DA));
    lv_style_set_text_font(&style_setting_screen_tabview_1_extra_btnm_items_default, &lv_font_CN_xiaobiaosong_14);
    lv_style_set_text_opa(&style_setting_screen_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->setting_screen_tabview_1), &style_setting_screen_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_setting_screen_tabview_1_extra_btnm_items_checked
    static lv_style_t style_setting_screen_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_setting_screen_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_setting_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x2195f6));
    lv_style_set_text_font(&style_setting_screen_tabview_1_extra_btnm_items_checked, &lv_font_CN_xiaobiaosong_12);
    lv_style_set_text_opa(&style_setting_screen_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_setting_screen_tabview_1_extra_btnm_items_checked, 4);
    lv_style_set_border_opa(&style_setting_screen_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_color(&style_setting_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x2195f6));
    lv_style_set_border_side(&style_setting_screen_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
    lv_style_set_radius(&style_setting_screen_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_setting_screen_tabview_1_extra_btnm_items_checked, 60);
    lv_style_set_bg_color(&style_setting_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_setting_screen_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->setting_screen_tabview_1), &style_setting_screen_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes 统计图表
    ui->setting_screen_tabview_1_tab_1 = lv_tabview_add_tab(ui->setting_screen_tabview_1,"统计图表");
    lv_obj_t * setting_screen_tabview_1_tab_1_label = lv_label_create(ui->setting_screen_tabview_1_tab_1);
    lv_label_set_text(setting_screen_tabview_1_tab_1_label, "");

    //Write codes setting_screen_chart_1
    ui->setting_screen_chart_1 = lv_chart_create(ui->setting_screen_tabview_1_tab_1);
    lv_chart_set_type(ui->setting_screen_chart_1, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(ui->setting_screen_chart_1, 3, 5);
    lv_chart_set_point_count(ui->setting_screen_chart_1, 5);
    lv_chart_set_range(ui->setting_screen_chart_1, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
    lv_chart_set_range(ui->setting_screen_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
    lv_chart_set_zoom_x(ui->setting_screen_chart_1, 256);
    lv_chart_set_zoom_y(ui->setting_screen_chart_1, 256);
    ui->setting_screen_chart_1_0 = lv_chart_add_series(ui->setting_screen_chart_1, lv_color_hex(0x000000), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->setting_screen_chart_1, ui->setting_screen_chart_1_0, 1);
    lv_chart_set_next_value(ui->setting_screen_chart_1, ui->setting_screen_chart_1_0, 20);
    lv_chart_set_next_value(ui->setting_screen_chart_1, ui->setting_screen_chart_1_0, 30);
    lv_chart_set_next_value(ui->setting_screen_chart_1, ui->setting_screen_chart_1_0, 40);
    lv_chart_set_next_value(ui->setting_screen_chart_1, ui->setting_screen_chart_1_0, 5);
#endif
    lv_obj_set_pos(ui->setting_screen_chart_1, 6, 41);
    lv_obj_set_size(ui->setting_screen_chart_1, 268, 111);
    lv_obj_set_scrollbar_mode(ui->setting_screen_chart_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for setting_screen_chart_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen_chart_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_screen_chart_1, lv_color_hex(0x098D6B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_chart_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_screen_chart_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->setting_screen_chart_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->setting_screen_chart_1, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->setting_screen_chart_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_chart_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->setting_screen_chart_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->setting_screen_chart_1, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->setting_screen_chart_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_chart_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for setting_screen_chart_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->setting_screen_chart_1, lv_color_hex(0x151212), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_screen_chart_1, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_screen_chart_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->setting_screen_chart_1, 2, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->setting_screen_chart_1, lv_color_hex(0xe8e8e8), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->setting_screen_chart_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write codes CPU使用率
    ui->setting_screen_tabview_1_tab_2 = lv_tabview_add_tab(ui->setting_screen_tabview_1,"CPU使用率");
    lv_obj_t * setting_screen_tabview_1_tab_2_label = lv_label_create(ui->setting_screen_tabview_1_tab_2);
    lv_label_set_text(setting_screen_tabview_1_tab_2_label, "");

    //Write codes setting_screen_meter_cpu_usage
    ui->setting_screen_meter_cpu_usage = lv_meter_create(ui->setting_screen_tabview_1_tab_2);
    // add scale ui->setting_screen_meter_cpu_usage_scale_0
    ui->setting_screen_meter_cpu_usage_scale_0 = lv_meter_add_scale(ui->setting_screen_meter_cpu_usage);
    lv_meter_set_scale_ticks(ui->setting_screen_meter_cpu_usage, ui->setting_screen_meter_cpu_usage_scale_0, 41, 2, 10, lv_color_hex(0x2FDAAE));
    lv_meter_set_scale_major_ticks(ui->setting_screen_meter_cpu_usage, ui->setting_screen_meter_cpu_usage_scale_0, 8, 5, 15, lv_color_hex(0xffffff), 10);

    // add arc for ui->setting_screen_meter_cpu_usage_scale_0
    ui->setting_screen_meter_cpu_usage_scale_0_arc_0 = lv_meter_add_arc(ui->setting_screen_meter_cpu_usage, ui->setting_screen_meter_cpu_usage_scale_0, 10, lv_color_hex(0x29ff00), 0);
    lv_meter_set_indicator_start_value(ui->setting_screen_meter_cpu_usage, ui->setting_screen_meter_cpu_usage_scale_0_arc_0, 0);
    lv_meter_set_indicator_end_value(ui->setting_screen_meter_cpu_usage, ui->setting_screen_meter_cpu_usage_scale_0_arc_0, 50);

    // add arc for ui->setting_screen_meter_cpu_usage_scale_0
    ui->setting_screen_meter_cpu_usage_scale_0_arc_1 = lv_meter_add_arc(ui->setting_screen_meter_cpu_usage, ui->setting_screen_meter_cpu_usage_scale_0, 10, lv_color_hex(0xff6500), 0);
    lv_meter_set_indicator_start_value(ui->setting_screen_meter_cpu_usage, ui->setting_screen_meter_cpu_usage_scale_0_arc_1, 50);
    lv_meter_set_indicator_end_value(ui->setting_screen_meter_cpu_usage, ui->setting_screen_meter_cpu_usage_scale_0_arc_1, 100);

    // add needle line for ui->setting_screen_meter_cpu_usage_scale_0.
    ui->setting_screen_meter_cpu_usage_scale_0_ndline_0 = lv_meter_add_needle_line(ui->setting_screen_meter_cpu_usage, ui->setting_screen_meter_cpu_usage_scale_0, 3, lv_color_hex(0x000000), -25);
    lv_meter_set_indicator_value(ui->setting_screen_meter_cpu_usage, ui->setting_screen_meter_cpu_usage_scale_0_ndline_0, 0);
    lv_obj_set_pos(ui->setting_screen_meter_cpu_usage, 37, -17);
    lv_obj_set_size(ui->setting_screen_meter_cpu_usage, 200, 200);

    //Write style for setting_screen_meter_cpu_usage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen_meter_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_meter_cpu_usage, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_screen_meter_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_screen_meter_cpu_usage, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_screen_meter_cpu_usage, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_screen_meter_cpu_usage, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_screen_meter_cpu_usage, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_meter_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for setting_screen_meter_cpu_usage, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->setting_screen_meter_cpu_usage, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_screen_meter_cpu_usage, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_screen_meter_cpu_usage, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write style for setting_screen_meter_cpu_usage, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen_meter_cpu_usage, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_screen_meter_cpu_usage, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_meter_cpu_usage, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes setting_screen_label_cpu_freq_value
    ui->setting_screen_label_cpu_freq_value = lv_label_create(ui->setting_screen_tabview_1_tab_2);
    lv_label_set_text(ui->setting_screen_label_cpu_freq_value, "0");
    lv_label_set_long_mode(ui->setting_screen_label_cpu_freq_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_screen_label_cpu_freq_value, 116, 115);
    lv_obj_set_size(ui->setting_screen_label_cpu_freq_value, 47, 32);

    //Write style for setting_screen_label_cpu_freq_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_screen_label_cpu_freq_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_label_cpu_freq_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_screen_label_cpu_freq_value, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_screen_label_cpu_freq_value, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_screen_label_cpu_freq_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_screen_label_cpu_freq_value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_screen_label_cpu_freq_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_screen_label_cpu_freq_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_screen_label_cpu_freq_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_screen_label_cpu_freq_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_screen_label_cpu_freq_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_screen_label_cpu_freq_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_screen_label_cpu_freq_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_label_cpu_freq_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_screen_label_cpu
    ui->setting_screen_label_cpu = lv_label_create(ui->setting_screen_tabview_1_tab_2);
    lv_label_set_text(ui->setting_screen_label_cpu, "CPU");
    lv_label_set_long_mode(ui->setting_screen_label_cpu, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_screen_label_cpu, 87, 48);
    lv_obj_set_size(ui->setting_screen_label_cpu, 100, 32);

    //Write style for setting_screen_label_cpu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_screen_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_screen_label_cpu, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_screen_label_cpu, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_screen_label_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_screen_label_cpu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_screen_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_screen_label_cpu, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_screen_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_screen_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_screen_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_screen_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_screen_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes 系统信息
    ui->setting_screen_tabview_1_tab_3 = lv_tabview_add_tab(ui->setting_screen_tabview_1,"系统信息");
    lv_obj_t * setting_screen_tabview_1_tab_3_label = lv_label_create(ui->setting_screen_tabview_1_tab_3);
    lv_label_set_text(setting_screen_tabview_1_tab_3_label, " ");

    //Write codes setting_screen_table_sys_info
    ui->setting_screen_table_sys_info = lv_table_create(ui->setting_screen_tabview_1_tab_3);
    lv_table_set_col_cnt(ui->setting_screen_table_sys_info,2);
    lv_table_set_row_cnt(ui->setting_screen_table_sys_info,3);
    lv_table_set_cell_value(ui->setting_screen_table_sys_info,0,0,"CPU主频");
    lv_table_set_cell_value(ui->setting_screen_table_sys_info,1,0,"已使用RAM");
    lv_table_set_cell_value(ui->setting_screen_table_sys_info,2,0,"已分配RAM");
    lv_table_set_cell_value(ui->setting_screen_table_sys_info,0,1,"");
    lv_table_set_cell_value(ui->setting_screen_table_sys_info,1,1,"");
    lv_table_set_cell_value(ui->setting_screen_table_sys_info,2,1,"");
    lv_obj_set_pos(ui->setting_screen_table_sys_info, 4, 27);
    lv_obj_set_scrollbar_mode(ui->setting_screen_table_sys_info, LV_SCROLLBAR_MODE_OFF);

    //Write style for setting_screen_table_sys_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->setting_screen_table_sys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_screen_table_sys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_screen_table_sys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_screen_table_sys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_screen_table_sys_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_screen_table_sys_info, lv_color_hex(0x445362), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_table_sys_info, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_screen_table_sys_info, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->setting_screen_table_sys_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->setting_screen_table_sys_info, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->setting_screen_table_sys_info, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_table_sys_info, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_table_sys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for setting_screen_table_sys_info, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->setting_screen_table_sys_info, lv_color_hex(0x2FDAAE), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_screen_table_sys_info, &lv_font_CN_xiaobiaosong_14, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_screen_table_sys_info, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_screen_table_sys_info, LV_TEXT_ALIGN_CENTER, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_screen_table_sys_info, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_screen_table_sys_info, 3, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->setting_screen_table_sys_info, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->setting_screen_table_sys_info, lv_color_hex(0x2F92DA), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->setting_screen_table_sys_info, LV_BORDER_SIDE_FULL, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_screen_table_sys_info, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_screen_table_sys_info, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_screen_table_sys_info, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_screen_table_sys_info, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes 屏幕相关
    ui->setting_screen_tabview_1_tab_4 = lv_tabview_add_tab(ui->setting_screen_tabview_1,"屏幕相关");
    lv_obj_t * setting_screen_tabview_1_tab_4_label = lv_label_create(ui->setting_screen_tabview_1_tab_4);
    lv_label_set_text(setting_screen_tabview_1_tab_4_label, "");

    //Write codes setting_screen_slider_brightness
    ui->setting_screen_slider_brightness = lv_slider_create(ui->setting_screen_tabview_1_tab_4);
    lv_slider_set_range(ui->setting_screen_slider_brightness, 10, 100);
    lv_slider_set_mode(ui->setting_screen_slider_brightness, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->setting_screen_slider_brightness, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->setting_screen_slider_brightness, 47, 57);
    lv_obj_set_size(ui->setting_screen_slider_brightness, 208, 20);

    //Write style for setting_screen_slider_brightness, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen_slider_brightness, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_screen_slider_brightness, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_slider_brightness, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_slider_brightness, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->setting_screen_slider_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_slider_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for setting_screen_slider_brightness, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen_slider_brightness, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_screen_slider_brightness, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_slider_brightness, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_slider_brightness, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for setting_screen_slider_brightness, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen_slider_brightness, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_screen_slider_brightness, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_slider_brightness, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_slider_brightness, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes setting_screen_label_brightness
    ui->setting_screen_label_brightness = lv_label_create(ui->setting_screen_tabview_1_tab_4);
    lv_label_set_text(ui->setting_screen_label_brightness, "亮度");
    lv_label_set_long_mode(ui->setting_screen_label_brightness, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_screen_label_brightness, 64, 14);
    lv_obj_set_size(ui->setting_screen_label_brightness, 100, 32);

    //Write style for setting_screen_label_brightness, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_screen_label_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_label_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_screen_label_brightness, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_screen_label_brightness, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_screen_label_brightness, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_screen_label_brightness, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_screen_label_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_screen_label_brightness, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_screen_label_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_screen_label_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_screen_label_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_screen_label_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_screen_label_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_label_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_screen_label_brightness_value
    ui->setting_screen_label_brightness_value = lv_label_create(ui->setting_screen_tabview_1_tab_4);
    lv_label_set_text(ui->setting_screen_label_brightness_value, "50%");
    lv_label_set_long_mode(ui->setting_screen_label_brightness_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_screen_label_brightness_value, 122, 14);
    lv_obj_set_size(ui->setting_screen_label_brightness_value, 100, 32);

    //Write style for setting_screen_label_brightness_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_screen_label_brightness_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_label_brightness_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_screen_label_brightness_value, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_screen_label_brightness_value, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_screen_label_brightness_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_screen_label_brightness_value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_screen_label_brightness_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_screen_label_brightness_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_screen_label_brightness_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_screen_label_brightness_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_screen_label_brightness_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_screen_label_brightness_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_screen_label_brightness_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_label_brightness_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_screen_label_auto_brightness
    ui->setting_screen_label_auto_brightness = lv_label_create(ui->setting_screen_tabview_1_tab_4);
    lv_label_set_text(ui->setting_screen_label_auto_brightness, "自动亮度");
    lv_label_set_long_mode(ui->setting_screen_label_auto_brightness, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_screen_label_auto_brightness, 3, 108);
    lv_obj_set_size(ui->setting_screen_label_auto_brightness, 100, 32);

    //Write style for setting_screen_label_auto_brightness, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_screen_label_auto_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_label_auto_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_screen_label_auto_brightness, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_screen_label_auto_brightness, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_screen_label_auto_brightness, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_screen_label_auto_brightness, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_screen_label_auto_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_screen_label_auto_brightness, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_screen_label_auto_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_screen_label_auto_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_screen_label_auto_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_screen_label_auto_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_screen_label_auto_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_label_auto_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_screen_sw_auto_brightness
    ui->setting_screen_sw_auto_brightness = lv_switch_create(ui->setting_screen_tabview_1_tab_4);
    lv_obj_set_pos(ui->setting_screen_sw_auto_brightness, 98, 106);
    lv_obj_set_size(ui->setting_screen_sw_auto_brightness, 40, 20);

    //Write style for setting_screen_sw_auto_brightness, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen_sw_auto_brightness, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_screen_sw_auto_brightness, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_sw_auto_brightness, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_screen_sw_auto_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_sw_auto_brightness, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_sw_auto_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for setting_screen_sw_auto_brightness, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->setting_screen_sw_auto_brightness, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->setting_screen_sw_auto_brightness, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_sw_auto_brightness, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->setting_screen_sw_auto_brightness, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for setting_screen_sw_auto_brightness, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen_sw_auto_brightness, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_screen_sw_auto_brightness, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_sw_auto_brightness, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_screen_sw_auto_brightness, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_sw_auto_brightness, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes setting_screen_btn_touch_adjust
    ui->setting_screen_btn_touch_adjust = lv_btn_create(ui->setting_screen_tabview_1_tab_4);
    ui->setting_screen_btn_touch_adjust_label = lv_label_create(ui->setting_screen_btn_touch_adjust);
    lv_label_set_text(ui->setting_screen_btn_touch_adjust_label, "触摸校准");
    lv_label_set_long_mode(ui->setting_screen_btn_touch_adjust_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->setting_screen_btn_touch_adjust_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->setting_screen_btn_touch_adjust, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->setting_screen_btn_touch_adjust_label, LV_PCT(100));
    lv_obj_set_pos(ui->setting_screen_btn_touch_adjust, 179, 100);
    lv_obj_set_size(ui->setting_screen_btn_touch_adjust, 101, 32);

    //Write style for setting_screen_btn_touch_adjust, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen_btn_touch_adjust, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_screen_btn_touch_adjust, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_btn_touch_adjust, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_screen_btn_touch_adjust, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_btn_touch_adjust, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_btn_touch_adjust, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_screen_btn_touch_adjust, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_screen_btn_touch_adjust, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_screen_btn_touch_adjust, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_screen_btn_touch_adjust, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_screen_btn_BackToMain
    ui->setting_screen_btn_BackToMain = lv_btn_create(ui->setting_screen);
    ui->setting_screen_btn_BackToMain_label = lv_label_create(ui->setting_screen_btn_BackToMain);
    lv_label_set_text(ui->setting_screen_btn_BackToMain_label, "←");
    lv_label_set_long_mode(ui->setting_screen_btn_BackToMain_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->setting_screen_btn_BackToMain_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->setting_screen_btn_BackToMain, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->setting_screen_btn_BackToMain_label, LV_PCT(100));
    lv_obj_set_pos(ui->setting_screen_btn_BackToMain, 8, 43);
    lv_obj_set_size(ui->setting_screen_btn_BackToMain, 33, 22);

    //Write style for setting_screen_btn_BackToMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_screen_btn_BackToMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_screen_btn_BackToMain, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_screen_btn_BackToMain, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_screen_btn_BackToMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_screen_btn_BackToMain, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_screen_btn_BackToMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_screen_btn_BackToMain, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_screen_btn_BackToMain, &lv_font_CN_xiaobiaosong_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_screen_btn_BackToMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_screen_btn_BackToMain, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of setting_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->setting_screen);

    //Init events for screen.
    events_init_setting_screen(ui);
}
