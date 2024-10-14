#include "settings.h"

setting_struct settings;

void write_settings(){
	eeprom_write_data(settings.brightness,CONFIG_SAVE_BASE,1);
	eeprom_write_data(settings.auto_brightness,CONFIG_SAVE_BASE+1,1);
}	

void read_settings(){
	uint32_t temp;
	eeprom_read_data(&temp,CONFIG_SAVE_BASE,1);
	settings.brightness = temp;
	eeprom_read_data(&temp,CONFIG_SAVE_BASE+1,1);
	settings.auto_brightness = temp;
}	
