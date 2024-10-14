#ifndef _EEPROM_H_
#define _EEPROM_H_
#include "main.h"
#include "i2c.h"

#define EEPROM_ADDRESS 0xA0

HAL_StatusTypeDef eeprom_write_data(uint32_t data,uint16_t Address,uint16_t data_len);
HAL_StatusTypeDef eeprom_read_data(uint32_t* data,uint16_t Address,uint16_t data_len);

#endif
