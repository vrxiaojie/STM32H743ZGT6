#include "BH1750.h"
#include "i2c.h"

uint16_t Lux;

HAL_StatusTypeDef BH1750_Init(void) 
{
	
    uint8_t opecode = 0x01;
	return (BH1750_WriteOpecode(&opecode, 1));
}

/*
*************************************************
功能：写BH1750操作码到芯片，控制模式
*************************************************
*/
HAL_StatusTypeDef BH1750_WriteOpecode(uint8_t* pData, uint16_t size) 
{
    HAL_StatusTypeDef status = HAL_OK;
    status = HAL_I2C_Master_Transmit(&BH1750_PORT, BH1750_ADDRESS,pData, size, 1);
    return status;
}
/*
*************************************************
功能：读取BH1750的数据，存放到pData中
*************************************************
*/

HAL_StatusTypeDef BH1750_ReadData(uint8_t* pData, uint16_t size) 
{
    HAL_StatusTypeDef status = HAL_OK;
    status = HAL_I2C_Master_Receive(&BH1750_PORT, BH1750_ADDRESS+1,pData, size, 1);
    return status;
}




