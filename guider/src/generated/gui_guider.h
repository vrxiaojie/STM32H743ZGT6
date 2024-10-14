/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *main_page;
	bool main_page_del;
	lv_obj_t *g_kb_main_page;
	lv_obj_t *main_page_cont_1;
	lv_obj_t *main_page_img_app;
	lv_obj_t *main_page_cont_2;
	lv_obj_t *main_page_img_calender;
	lv_obj_t *main_page_cont_3;
	lv_obj_t *main_page_img_serial;
	lv_obj_t *main_page_cont_4;
	lv_obj_t *main_page_img_1;
	lv_obj_t *main_page_label_battery;
	lv_obj_t *main_page_datetext_1;
	lv_obj_t *main_page_cont_5;
	lv_obj_t *main_page_img_file_explorer;
	lv_obj_t *main_page_cont_6;
	lv_obj_t *setting_screen;
	bool setting_screen_del;
	lv_obj_t *g_kb_setting_screen;
	lv_obj_t *setting_screen_tabview_1;
	lv_obj_t *setting_screen_tabview_1_tab_1;
	lv_obj_t *setting_screen_tabview_1_tab_2;
	lv_obj_t *setting_screen_tabview_1_tab_3;
	lv_obj_t *setting_screen_tabview_1_tab_4;
	lv_obj_t *setting_screen_chart_1;
	lv_chart_series_t *setting_screen_chart_1_0;
	lv_obj_t *setting_screen_meter_cpu_usage;
	lv_meter_scale_t *setting_screen_meter_cpu_usage_scale_0;
	lv_meter_indicator_t *setting_screen_meter_cpu_usage_scale_0_ndline_0;
	lv_meter_indicator_t *setting_screen_meter_cpu_usage_scale_0_arc_0;
	lv_meter_indicator_t *setting_screen_meter_cpu_usage_scale_0_arc_1;
	lv_obj_t *setting_screen_label_cpu_freq_value;
	lv_obj_t *setting_screen_label_cpu;
	lv_obj_t *setting_screen_table_sys_info;
	lv_obj_t *setting_screen_slider_brightness;
	lv_obj_t *setting_screen_label_brightness;
	lv_obj_t *setting_screen_label_brightness_value;
	lv_obj_t *setting_screen_label_auto_brightness;
	lv_obj_t *setting_screen_sw_auto_brightness;
	lv_obj_t *setting_screen_btn_touch_adjust;
	lv_obj_t *setting_screen_btn_touch_adjust_label;
	lv_obj_t *setting_screen_btn_BackToMain;
	lv_obj_t *setting_screen_btn_BackToMain_label;
	lv_obj_t *calender_screen;
	bool calender_screen_del;
	lv_obj_t *g_kb_calender_screen;
	lv_obj_t *calender_screen_cont_1;
	lv_obj_t *calender_screen_calendar_1;
	lv_obj_t *calender_screen_btn_BackToMain;
	lv_obj_t *calender_screen_btn_BackToMain_label;
	lv_obj_t *calender_screen_label_1;
	lv_obj_t *app_screen;
	bool app_screen_del;
	lv_obj_t *g_kb_app_screen;
	lv_obj_t *app_screen_cont_1;
	lv_obj_t *app_screen_sw_gps;
	lv_obj_t *app_screen_label_1;
	lv_obj_t *app_screen_table_gps;
	lv_obj_t *app_screen_btn_BackToMain;
	lv_obj_t *app_screen_btn_BackToMain_label;
	lv_obj_t *serial_assistant_screen;
	bool serial_assistant_screen_del;
	lv_obj_t *g_kb_serial_assistant_screen;
	lv_obj_t *serial_assistant_screen_cont_1;
	lv_obj_t *serial_assistant_screen_ddlist_1;
	lv_obj_t *serial_assistant_screen_label_2;
	lv_obj_t *serial_assistant_screen_label_1;
	lv_obj_t *serial_assistant_screen_btn_1;
	lv_obj_t *serial_assistant_screen_btn_1_label;
	lv_obj_t *serial_assistant_screen_btn_2;
	lv_obj_t *serial_assistant_screen_btn_2_label;
	lv_obj_t *serial_assistant_screen_win_serial_1;
	lv_obj_t *serial_assistant_screen_win_serial_1_item0;
	lv_obj_t *serial_assistant_screen_win_serial_1_item1;
	lv_obj_t *file_explorer_screen;
	bool file_explorer_screen_del;
	lv_obj_t *g_kb_file_explorer_screen;
	lv_obj_t *file_explorer_screen_cont_1;
	lv_obj_t *file_explorer_screen_explorer;
	lv_obj_t *file_explorer_screen_list_1;
	lv_obj_t *file_explorer_screen_list_1_item0;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_main_page(lv_ui *ui);
void setup_scr_setting_screen(lv_ui *ui);
void setup_scr_calender_screen(lv_ui *ui);
void setup_scr_app_screen(lv_ui *ui);
void setup_scr_serial_assistant_screen(lv_ui *ui);
void setup_scr_file_explorer_screen(lv_ui *ui);
LV_IMG_DECLARE(_applications_alpha_80x80);
LV_IMG_DECLARE(_calendar_alpha_80x80);
LV_IMG_DECLARE(_serial_alpha_80x80);
LV_IMG_DECLARE(_setting_alpha_80x80);
LV_IMG_DECLARE(_file_explorer_alpha_80x80);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_CN_xiaobiaosong_12)
LV_FONT_DECLARE(lv_font_CN_xiaobiaosong_14)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_CN_xiaobiaosong_16)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_CN_xiaobiaosong_18)


#ifdef __cplusplus
}
#endif
#endif
