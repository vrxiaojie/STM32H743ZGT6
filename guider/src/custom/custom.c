/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include <string.h>
#if !LV_USE_GUIDER_SIMULATOR
	#include "main.h"
	#include "tim.h"
	#include "usart.h"
#endif
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
lv_timer_t * cpu_usage_timer;
lv_timer_t * brightness_update_timer;
lv_timer_t * update_u1_timer;
lv_timer_t * update_gps_timer;
lv_obj_t *serial_assistant_screen_win_serial_1_label;
uint8_t uart_port=0;
#if !LV_USE_GUIDER_SIMULATOR
char u1_data[4050] SDRAM_AREA_ATTRIBUTE;
char u5_data[1050] SDRAM_AREA_ATTRIBUTE;
#else
char u1_data[4050];
char u5_data[1050];
#endif
/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

void update_gps_info(lv_timer_t * timer){
		#if !LV_USE_GUIDER_SIMULATOR
		HAL_UART_Receive_IT(&huart5,(uint8_t *)UART5_temp,REC_LENGTH);
		char t0[20],t1[20],t2[20],t3[20],t4[20];
    	//检查状态码
    	if(UART5_Rx_flg==1) {
		UART5_Rx_flg = 0;
		if(gps.UsefulFlag=='V')
			strcpy(t0,"Wait...");
		else if(gps.UsefulFlag=='A')
			strcpy(t0,"OK");
		lv_table_set_cell_value(guider_ui.app_screen_table_gps,0,1,t0);//状态

		sprintf(t1,"%.5f",gps.latitude_d);
		if(gps.N_S=='N')
			strcat(t1," N");
		else if(gps.N_S=='S')
			strcat(t1," S");
		lv_table_set_cell_value(guider_ui.app_screen_table_gps,1,1,t1);//纬度

		sprintf(t2,"%.5f",gps.longitude_d);
		if(gps.E_W=='E')
			strcat(t2," E");
		else if(gps.E_W=='W')
			strcat(t2," W");
		lv_table_set_cell_value(guider_ui.app_screen_table_gps,2,1,t2);//经度

		sprintf(t3,"%02d:%02d:%02d",gps.UTCTime_int/10000,gps.UTCTime_int/100%100,gps.UTCTime_int%100);
		lv_table_set_cell_value(guider_ui.app_screen_table_gps,3,1,t3);//UTC

		gps.speed_d = strtod((const char*)gps.speed,NULL);
		sprintf(t4,"%.2f",gps.speed_d*1.852);
		strcat(t4," km/h");
		lv_table_set_cell_value(guider_ui.app_screen_table_gps,4,1,t4);//速度 km/h
		}
	#endif
}

void clear_uart_content(){
	
	if(uart_port==USE_U1){  //USART1
	   	memset(u1_data,'\0',strlen(u1_data));
		#if !LV_USE_GUIDER_SIMULATOR
			UART1_Rx_cnt = 0 ;
		#endif
	}
	else if(uart_port==USE_U5){  //UART5
	    memset(u5_data,'\0',strlen(u5_data));
		#if !LV_USE_GUIDER_SIMULATOR
			UART5_Rx_cnt = 0 ;
		#endif
	}
	lv_label_set_text(serial_assistant_screen_win_serial_1_label, "");
}

void update_uart_content(lv_timer_t * timer){
	#if !LV_USE_GUIDER_SIMULATOR
	
		if(UART1_Rx_flg==1&&uart_port==USE_U1){
			UART1_Rx_flg = 0;
			lv_label_set_text(serial_assistant_screen_win_serial_1_label, u1_data);
		}
		if(UART5_Rx_flg==1&&uart_port==USE_U5){
			UART5_Rx_flg = 0;
			lv_label_set_text(serial_assistant_screen_win_serial_1_label, u5_data);
		}
		
	#endif
}

void update_cpu_usage(lv_timer_t * timer){
	char t[4];
	uint8_t usage = 100 - lv_timer_get_idle();
	sprintf(t,"%d",usage);
	strcat(t,"%");
	lv_label_set_text(guider_ui.setting_screen_label_cpu_freq_value, t);
	lv_meter_set_indicator_value(guider_ui.setting_screen_meter_cpu_usage,
	guider_ui.setting_screen_meter_cpu_usage_scale_0_ndline_0, usage);
}

void update_brightness(lv_timer_t * timer){
	#if !LV_USE_GUIDER_SIMULATOR
		if(settings.auto_brightness){
			char t[6];  
			sprintf(t,"%d",settings.brightness);
			strcat(t,"%");
			lv_label_set_text(guider_ui.setting_screen_label_brightness_value,t);
			lv_slider_set_value(guider_ui.setting_screen_slider_brightness,
			settings.brightness,LV_ANIM_ON);
		}
		
	#endif
}

void update_sys_info(){
	
	char t1 [10],t2 [10];
	#if !LV_USE_GUIDER_SIMULATOR
		char t0[10];
		uint16_t CPU_Freq = HAL_RCC_GetSysClockFreq()/1000000; //MHz
		sprintf(t0,"%d",CPU_Freq);
		strcat(t0,"MHz");
		lv_table_set_cell_value(guider_ui.setting_screen_table_sys_info,0,1,t0);//CPU主频
	#endif

	lv_mem_monitor_t mon;
    lv_mem_monitor(&mon);
    uint32_t used_size = mon.total_size - mon.free_size;
    float used_kb = used_size / 1024.0;
	sprintf(t1,"%.1f",used_kb);
	strcat(t1,"KB");
	sprintf(t2,"%d",mon.total_size/1024);
	strcat(t2,"KB");

	lv_table_set_cell_value(guider_ui.setting_screen_table_sys_info,1,1,t1);//已使用RAM
	lv_table_set_cell_value(guider_ui.setting_screen_table_sys_info,2,1,t2);//已分配RAM

	#if !LV_USE_GUIDER_SIMULATOR
		char t[6];  
		sprintf(t,"%d",settings.brightness);
		strcat(t,"%");
		lv_label_set_text(guider_ui.setting_screen_label_brightness_value,t);
	#endif
}
