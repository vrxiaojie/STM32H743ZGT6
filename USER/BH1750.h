/*
*************************************************
BH1750

光照数据计算（LUX）
LUX = 读取数据/1.2
例如：
读取值为0x56,0x78
LUX = 0X5678 / 1.2 = 22136/1.2 = 18447

*************************************************
*/

#ifndef __BH1750_H
#define __BH1750_H

#include "main.h"

#define BH1750_PORT hi2c3	/*使用端口*/

#define BH1750_ADDRESS 0x46		/*ADDRESS引脚接地时地址为0x46，接电源时地址为0xB8*/

#define BH1750_POW_OFF				0X00
#define BH1750_POW_ON				0X01
#define BH1750_POW_RST				0X07
#define BH1750_CONT_HI_RSLT_1		0X10	/*连续测量，1lx精度开始测量，周期120ms*/
#define BH1750_CONT_HI_RSLT_2		0X11	/*连续测量，0.5lx精度开始测量，周期120ms*/
#define BH1750_CONT_LOW_RSLT		0X13	/*连续测量，4lx精度开始测量，周期16ms*/
#define BH1750_ONE_HI_RSLT_1		0X20	/*一次测量，1lx精度开始测量，周期120ms，测量完后自动进入POWER DOWN*/
#define BH1750_ONE_HI_RSLT_2		0X21	/*一次测量，0.5lx精度开始测量，周期120ms，测量完后自动进入POWER DOWN*/
#define BH1750_ONE_LOW_RSLT			0X23	/*一次测量，4lx精度开始测量，周期16ms，测量完后自动进入POWER DOWN*/


HAL_StatusTypeDef BH1750_Init(void);

HAL_StatusTypeDef BH1750_WriteOpecode(uint8_t* pData, uint16_t size);
HAL_StatusTypeDef BH1750_ReadData(uint8_t* pData, uint16_t size);

extern uint16_t Lux;
#endif

