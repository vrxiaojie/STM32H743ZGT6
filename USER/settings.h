#ifndef __SETTINGS_H
#define __SETTINGS_H

#include "main.h"

#define CONFIG_SAVE_BASE 50 
typedef struct{
	uint8_t brightness;
	uint8_t auto_brightness;
} setting_struct;

extern setting_struct settings;

void read_settings(void);
void write_settings(void);
#endif