/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif
#define USE_U1 0
#define USE_U5 1

#include "gui_guider.h"

void custom_init(lv_ui *ui);
void update_cpu_usage(lv_timer_t * timer);
void update_sys_info(void);
void update_brightness(lv_timer_t * timer);
void clear_uart_content(void);
void update_uart_content(lv_timer_t * timer);
void update_gps_info(lv_timer_t * timer);

extern lv_timer_t * cpu_usage_timer;
extern lv_timer_t * brightness_update_timer;
extern lv_timer_t * update_u1_timer;
extern lv_timer_t * update_gps_timer;
extern lv_obj_t *serial_assistant_screen_win_serial_1_label;
extern uint8_t uart_port;
extern char u1_data[4050];
extern char u5_data[1050];
#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
