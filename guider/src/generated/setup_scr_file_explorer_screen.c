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



void setup_scr_file_explorer_screen(lv_ui *ui)
{
    //Write codes file_explorer_screen
    ui->file_explorer_screen = lv_obj_create(NULL);
    ui->g_kb_file_explorer_screen = lv_keyboard_create(ui->file_explorer_screen);
    lv_obj_add_event_cb(ui->g_kb_file_explorer_screen, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_file_explorer_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_file_explorer_screen, &lv_font_CN_xiaobiaosong_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->file_explorer_screen, 320, 240);
    lv_obj_set_scrollbar_mode(ui->file_explorer_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for file_explorer_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->file_explorer_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_explorer_screen_cont_1
    ui->file_explorer_screen_cont_1 = lv_obj_create(ui->file_explorer_screen);
    lv_obj_set_pos(ui->file_explorer_screen_cont_1, 0, 0);
    lv_obj_set_size(ui->file_explorer_screen_cont_1, 320, 240);
    lv_obj_set_scrollbar_mode(ui->file_explorer_screen_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for file_explorer_screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->file_explorer_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->file_explorer_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->file_explorer_screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->file_explorer_screen_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->file_explorer_screen_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->file_explorer_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->file_explorer_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->file_explorer_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->file_explorer_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->file_explorer_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_explorer_screen_explorer
    ui->file_explorer_screen_explorer = lv_table_create(ui->file_explorer_screen_cont_1);
    lv_table_set_col_cnt(ui->file_explorer_screen_explorer,1);
    lv_table_set_row_cnt(ui->file_explorer_screen_explorer,1);
    lv_table_set_cell_value(ui->file_explorer_screen_explorer,0,0,"");
    lv_obj_set_pos(ui->file_explorer_screen_explorer, 0, -1);
    lv_obj_set_scrollbar_mode(ui->file_explorer_screen_explorer, LV_SCROLLBAR_MODE_ON);

    //Write style for file_explorer_screen_explorer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->file_explorer_screen_explorer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->file_explorer_screen_explorer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->file_explorer_screen_explorer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->file_explorer_screen_explorer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->file_explorer_screen_explorer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->file_explorer_screen_explorer, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->file_explorer_screen_explorer, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->file_explorer_screen_explorer, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->file_explorer_screen_explorer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->file_explorer_screen_explorer, lv_color_hex(0xd5dee6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->file_explorer_screen_explorer, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->file_explorer_screen_explorer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->file_explorer_screen_explorer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for file_explorer_screen_explorer, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->file_explorer_screen_explorer, lv_color_hex(0x393c41), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->file_explorer_screen_explorer, &lv_font_CN_xiaobiaosong_12, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->file_explorer_screen_explorer, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->file_explorer_screen_explorer, LV_TEXT_ALIGN_LEFT, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->file_explorer_screen_explorer, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->file_explorer_screen_explorer, 3, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->file_explorer_screen_explorer, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->file_explorer_screen_explorer, lv_color_hex(0xd5dee6), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->file_explorer_screen_explorer, LV_BORDER_SIDE_BOTTOM, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->file_explorer_screen_explorer, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->file_explorer_screen_explorer, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->file_explorer_screen_explorer, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->file_explorer_screen_explorer, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes file_explorer_screen_list_1
    ui->file_explorer_screen_list_1 = lv_list_create(ui->file_explorer_screen_cont_1);
    ui->file_explorer_screen_list_1_item0 = lv_list_add_btn(ui->file_explorer_screen_list_1, LV_SYMBOL_LEFT, "主页");
    lv_obj_set_pos(ui->file_explorer_screen_list_1, 240, 0);
    lv_obj_set_size(ui->file_explorer_screen_list_1, 80, 131);
    lv_obj_set_scrollbar_mode(ui->file_explorer_screen_list_1, LV_SCROLLBAR_MODE_OFF);

    //Write style state: LV_STATE_DEFAULT for &style_file_explorer_screen_list_1_main_main_default
    static lv_style_t style_file_explorer_screen_list_1_main_main_default;
    ui_init_style(&style_file_explorer_screen_list_1_main_main_default);

    lv_style_set_pad_top(&style_file_explorer_screen_list_1_main_main_default, 5);
    lv_style_set_pad_left(&style_file_explorer_screen_list_1_main_main_default, 5);
    lv_style_set_pad_right(&style_file_explorer_screen_list_1_main_main_default, 5);
    lv_style_set_pad_bottom(&style_file_explorer_screen_list_1_main_main_default, 5);
    lv_style_set_bg_opa(&style_file_explorer_screen_list_1_main_main_default, 255);
    lv_style_set_bg_color(&style_file_explorer_screen_list_1_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_file_explorer_screen_list_1_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_file_explorer_screen_list_1_main_main_default, 1);
    lv_style_set_border_opa(&style_file_explorer_screen_list_1_main_main_default, 255);
    lv_style_set_border_color(&style_file_explorer_screen_list_1_main_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_file_explorer_screen_list_1_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_file_explorer_screen_list_1_main_main_default, 3);
    lv_style_set_shadow_width(&style_file_explorer_screen_list_1_main_main_default, 0);
    lv_obj_add_style(ui->file_explorer_screen_list_1, &style_file_explorer_screen_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_file_explorer_screen_list_1_main_scrollbar_default
    static lv_style_t style_file_explorer_screen_list_1_main_scrollbar_default;
    ui_init_style(&style_file_explorer_screen_list_1_main_scrollbar_default);

    lv_style_set_radius(&style_file_explorer_screen_list_1_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_file_explorer_screen_list_1_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_file_explorer_screen_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_file_explorer_screen_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->file_explorer_screen_list_1, &style_file_explorer_screen_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_file_explorer_screen_list_1_extra_btns_main_default
    static lv_style_t style_file_explorer_screen_list_1_extra_btns_main_default;
    ui_init_style(&style_file_explorer_screen_list_1_extra_btns_main_default);

    lv_style_set_pad_top(&style_file_explorer_screen_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_file_explorer_screen_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_file_explorer_screen_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_file_explorer_screen_list_1_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_file_explorer_screen_list_1_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_file_explorer_screen_list_1_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_file_explorer_screen_list_1_extra_btns_main_default, &lv_font_CN_xiaobiaosong_12);
    lv_style_set_text_opa(&style_file_explorer_screen_list_1_extra_btns_main_default, 255);
    lv_style_set_radius(&style_file_explorer_screen_list_1_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_file_explorer_screen_list_1_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_file_explorer_screen_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_file_explorer_screen_list_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->file_explorer_screen_list_1_item0, &style_file_explorer_screen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_file_explorer_screen_list_1_extra_texts_main_default
    static lv_style_t style_file_explorer_screen_list_1_extra_texts_main_default;
    ui_init_style(&style_file_explorer_screen_list_1_extra_texts_main_default);

    lv_style_set_pad_top(&style_file_explorer_screen_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_file_explorer_screen_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_file_explorer_screen_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_file_explorer_screen_list_1_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_file_explorer_screen_list_1_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_file_explorer_screen_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_file_explorer_screen_list_1_extra_texts_main_default, &lv_font_CN_xiaobiaosong_12);
    lv_style_set_text_opa(&style_file_explorer_screen_list_1_extra_texts_main_default, 255);
    lv_style_set_radius(&style_file_explorer_screen_list_1_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_file_explorer_screen_list_1_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_file_explorer_screen_list_1_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_file_explorer_screen_list_1_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_file_explorer_screen_list_1_extra_texts_main_default, LV_GRAD_DIR_NONE);

    //The custom code of file_explorer_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->file_explorer_screen);

    //Init events for screen.
    events_init_file_explorer_screen(ui);
}
