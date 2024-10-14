/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "custom.h"
#if !LV_USE_GUIDER_SIMULATOR
#include "main.h"
#endif
#include "custom.h"
#if !LV_USE_GUIDER_SIMULATOR
#include "tim.h"
#endif
#if !LV_USE_GUIDER_SIMULATOR
#include "touch.h"
#endif
#if !LV_USE_GUIDER_SIMULATOR
#include "usart.h"
#endif
#if !LV_USE_GUIDER_SIMULATOR
#include "usart.h"
#endif
#if !LV_USE_GUIDER_SIMULATOR
#include "fatfs_user.h"
#endif

static void main_page_img_app_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.app_screen, guider_ui.app_screen_del, &guider_ui.main_page_del, setup_scr_app_screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 300, 50, false, true);
        break;
    }
    default:
        break;
    }
}

static void main_page_img_calender_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.calender_screen, guider_ui.calender_screen_del, &guider_ui.main_page_del, setup_scr_calender_screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 300, 50, false, true);
        break;
    }
    default:
        break;
    }
}

static void main_page_img_serial_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.serial_assistant_screen, guider_ui.serial_assistant_screen_del, &guider_ui.main_page_del, setup_scr_serial_assistant_screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 300, 50, false, true);
        break;
    }
    default:
        break;
    }
}

static void main_page_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.setting_screen, guider_ui.setting_screen_del, &guider_ui.main_page_del, setup_scr_setting_screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 300, 50, false, true);
        break;
    }
    default:
        break;
    }
}

static void main_page_img_file_explorer_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.file_explorer_screen, guider_ui.file_explorer_screen_del, &guider_ui.main_page_del, setup_scr_file_explorer_screen, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 50, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_main_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->main_page_img_app, main_page_img_app_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->main_page_img_calender, main_page_img_calender_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->main_page_img_serial, main_page_img_serial_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->main_page_img_1, main_page_img_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->main_page_img_file_explorer, main_page_img_file_explorer_event_handler, LV_EVENT_ALL, ui);
}

static void setting_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        cpu_usage_timer = lv_timer_create(update_cpu_usage, 500, 0);
        brightness_update_timer = lv_timer_create(update_brightness, 1000, 0);
        update_sys_info();

        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        lv_timer_del(cpu_usage_timer);
        lv_timer_del(brightness_update_timer);
        break;
    }
    default:
        break;
    }
}

static void setting_screen_slider_brightness_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        char t[6];
        uint8_t slider_val = lv_slider_get_value(guider_ui.setting_screen_slider_brightness);
        uint16_t bri = slider_val*10;
        sprintf(t,"%d",slider_val);
        strcat(t,"%");
#if !LV_USE_GUIDER_SIMULATOR
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,bri);
#endif
        lv_label_set_text(guider_ui.setting_screen_label_brightness_value, t);

        break;
    }
    default:
        break;
    }
}

static void setting_screen_sw_auto_brightness_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? 1 : 0;

        switch (status) {
        case (true):
        {

#if !LV_USE_GUIDER_SIMULATOR
            settings.auto_brightness = 1;
            write_settings();
#endif
            lv_obj_add_state(guider_ui.setting_screen_slider_brightness, LV_STATE_DISABLED);
            break;
        }
        case (false):
        {
            lv_obj_clear_state(guider_ui.setting_screen_slider_brightness,LV_STATE_DISABLED);
#if !LV_USE_GUIDER_SIMULATOR
            settings.auto_brightness = 0;
            write_settings();
#endif
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void setting_screen_btn_touch_adjust_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
#if !LV_USE_GUIDER_SIMULATOR
        tp_dev.adjust();
#endif
        break;
    }
    default:
        break;
    }
}

static void setting_screen_btn_BackToMain_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.setting_screen_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_OVER_RIGHT, 300, 50, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_setting_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->setting_screen, setting_screen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->setting_screen_slider_brightness, setting_screen_slider_brightness_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->setting_screen_sw_auto_brightness, setting_screen_sw_auto_brightness_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->setting_screen_btn_touch_adjust, setting_screen_btn_touch_adjust_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->setting_screen_btn_BackToMain, setting_screen_btn_BackToMain_event_handler, LV_EVENT_ALL, ui);
}

static void calender_screen_btn_BackToMain_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.calender_screen_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_OVER_RIGHT, 400, 100, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_calender_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->calender_screen_btn_BackToMain, calender_screen_btn_BackToMain_event_handler, LV_EVENT_ALL, ui);
}

static void app_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
#if !LV_USE_GUIDER_SIMULATOR
        if(HAL_GPIO_ReadPin(GPS_CTRL_GPIO_Port,GPS_CTRL_Pin)==GPIO_PIN_SET) {
            lv_obj_add_state(guider_ui.app_screen_sw_gps,LV_STATE_CHECKED);
            HAL_UART_Receive_IT(&huart5,(uint8_t *)UART5_temp,REC_LENGTH);
            update_gps_timer = lv_timer_create(update_gps_info, 500, 0);
        }

#endif
        break;
    }
    default:
        break;
    }
}

static void app_screen_sw_gps_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? 1 : 0;

        switch (status) {
        case (true):
        {
#if !LV_USE_GUIDER_SIMULATOR
            HAL_GPIO_WritePin(GPS_CTRL_GPIO_Port,GPS_CTRL_Pin,GPIO_PIN_SET);
            HAL_UART_Receive_IT(&huart5,(uint8_t *)UART5_temp,REC_LENGTH);
            update_gps_timer = lv_timer_create(update_gps_info, 500, 0);
#endif
            break;
        }
        case (false):
        {
#if !LV_USE_GUIDER_SIMULATOR
            HAL_GPIO_WritePin(GPS_CTRL_GPIO_Port,GPS_CTRL_Pin,GPIO_PIN_RESET);
            lv_timer_del(update_gps_timer);
#endif
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void app_screen_btn_BackToMain_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.app_screen_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_OVER_RIGHT, 300, 50, false, true);
#if !LV_USE_GUIDER_SIMULATOR
        if(HAL_GPIO_ReadPin(GPS_CTRL_GPIO_Port,GPS_CTRL_Pin)==GPIO_PIN_SET) {
            lv_timer_del(update_gps_timer);
            HAL_UART_Receive_IT(&huart5,(uint8_t *)UART5_temp,REC_LENGTH);
        }
#endif
        break;
    }
    default:
        break;
    }
}

void events_init_app_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->app_screen, app_screen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->app_screen_sw_gps, app_screen_sw_gps_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->app_screen_btn_BackToMain, app_screen_btn_BackToMain_event_handler, LV_EVENT_ALL, ui);
}

static void serial_assistant_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        serial_assistant_screen_win_serial_1_label = lv_label_create(lv_win_get_content(guider_ui.serial_assistant_screen_win_serial_1));

        break;
    }
    default:
        break;
    }
}

static void serial_assistant_screen_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.serial_assistant_screen_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 50, false, true);
        break;
    }
    default:
        break;
    }
}

static void serial_assistant_screen_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        uart_port = lv_dropdown_get_selected(guider_ui.serial_assistant_screen_ddlist_1);

        if(uart_port==USE_U1) {
            lv_label_set_text(serial_assistant_screen_win_serial_1_label, u1_data);
        }
        else if(uart_port==USE_U5) {
            lv_label_set_text(serial_assistant_screen_win_serial_1_label, u5_data);
        }
        update_u1_timer = lv_timer_create(update_uart_content, 5, 0);
#if !LV_USE_GUIDER_SIMULATOR
        if(uart_port==USE_U1) { //USART1
            HAL_UART_Receive_IT(&huart1,(uint8_t *)UART1_temp,REC_LENGTH);
        }
        else if(uart_port==USE_U5) { //UART5
            HAL_UART_Receive_IT(&huart5,(uint8_t *)UART5_temp,REC_LENGTH);
        }
#endif






        lv_obj_clear_flag(guider_ui.serial_assistant_screen_win_serial_1, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_x(guider_ui.serial_assistant_screen_win_serial_1, 0);
        lv_obj_set_y(guider_ui.serial_assistant_screen_win_serial_1, 0);
        break;
    }
    default:
        break;
    }
}

static void serial_assistant_screen_win_serial_1_item0_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        clear_uart_content();
#if !LV_USE_GUIDER_SIMULATOR
        if(uart_port==USE_U1)
            HAL_UART_Receive_IT(&huart1,(uint8_t *)UART1_temp,REC_LENGTH);
        else if(uart_port == USE_U5)
            HAL_UART_Receive_IT(&huart5,(uint8_t *)UART5_temp,REC_LENGTH);
#endif
        break;
    }
    default:
        break;
    }
}

static void serial_assistant_screen_win_serial_1_item1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        clear_uart_content();
        lv_timer_del(update_u1_timer);
        lv_obj_set_x(guider_ui.serial_assistant_screen_win_serial_1, 413);
        lv_obj_add_flag(guider_ui.serial_assistant_screen_win_serial_1, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_y(guider_ui.serial_assistant_screen_win_serial_1, -79);
        break;
    }
    default:
        break;
    }
}

void events_init_serial_assistant_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->serial_assistant_screen, serial_assistant_screen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->serial_assistant_screen_btn_1, serial_assistant_screen_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->serial_assistant_screen_btn_2, serial_assistant_screen_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->serial_assistant_screen_win_serial_1_item0, serial_assistant_screen_win_serial_1_item0_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->serial_assistant_screen_win_serial_1_item1, serial_assistant_screen_win_serial_1_item1_event_handler, LV_EVENT_ALL, ui);
}

static void file_explorer_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_obj_set_size(guider_ui.file_explorer_screen_explorer, 240,240);
        lv_table_set_col_width(guider_ui.file_explorer_screen_explorer, 0, 240);
#if !LV_USE_GUIDER_SIMULATOR
        scan_files("0:/");
#endif
        break;
    }
    default:
        break;
    }
}

static void file_explorer_screen_list_1_item0_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.file_explorer_screen_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 50, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_file_explorer_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->file_explorer_screen, file_explorer_screen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->file_explorer_screen_list_1_item0, file_explorer_screen_list_1_item0_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
