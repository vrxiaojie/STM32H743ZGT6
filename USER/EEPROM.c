#include "EEPROM.h"

HAL_StatusTypeDef eeprom_write_data(uint32_t data,uint16_t Address,uint16_t data_len) {
    uint8_t res;
    res = HAL_I2C_IsDeviceReady(&hi2c3, EEPROM_ADDRESS, 5, 1000);
    if(res!=HAL_OK)
        return HAL_ERROR;
    uint8_t temp_data[30]= {0};
    //先存低位
    for(uint8_t i=0; i<data_len; i++) {
        temp_data[i]=(data>>(8*i))&0xFF;
		res = HAL_I2C_Mem_Write(&hi2c3, EEPROM_ADDRESS, Address+i, I2C_MEMADD_SIZE_8BIT, &temp_data[i], 1, 1000);
		if(res!=HAL_OK)
			return HAL_ERROR;
		HAL_Delay(5);//每次写完加适当延迟 否则会写入0XFF
    }
    
    return HAL_OK;
}

HAL_StatusTypeDef eeprom_read_data(uint32_t* data,uint16_t Address,uint16_t data_len) {
    uint8_t res,temp_data[30]= {0};
    *data = 0;
    res = HAL_I2C_IsDeviceReady(&hi2c3, EEPROM_ADDRESS, 5, 1000);
    if(res!=HAL_OK)
        return HAL_ERROR;

    for(uint8_t i=0; i<data_len; i++) {
        res = HAL_I2C_Mem_Read(&hi2c3, EEPROM_ADDRESS, Address+i, I2C_MEMADD_SIZE_8BIT, &temp_data[i], 1, 2000);
        if(res!=HAL_OK)
            return HAL_ERROR;
        *data+=(temp_data[i])<<(8*i);
        HAL_Delay(5);  //每次读完加适当延迟
    }
    return HAL_OK;
}
