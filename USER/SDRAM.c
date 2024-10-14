#include "SDRAM.h"
#include "fmc.h"
#include <stdio.h>

#define SDRAM_TIMEOUT 1000
void SDRAM_InitSequence(void)
{
    uint32_t tmpr = 0;
	FMC_SDRAM_CommandTypeDef Command;
    /* Step 3 -----------------------------------------------------*/
    /* 配置命令：开启提供给SDRAM的时钟 */
    Command.CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
    Command.AutoRefreshNumber = 1;
    Command.ModeRegisterDefinition = 0;
    /* Send the command */
    HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

    /* Step 2: Insert 100 us minimum delay */
    /* Inserted delay is equal to 1 ms due to systick time base unit (ms)*/

    HAL_Delay(1);
    /* Step 5 ----------------------------------------------------*/
    /* 配置命令：对所有的bank预充电 */
    Command.CommandMode = FMC_SDRAM_CMD_PALL;
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
    Command.AutoRefreshNumber = 1;
    Command.ModeRegisterDefinition = 0;
    /* Send the command */
    HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

    /* Step 6 ------------------------------------------------------*/
    /* 配置命令：自动刷新 */
    Command.CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
    Command.AutoRefreshNumber = 4;
    Command.ModeRegisterDefinition = 0;
    /* Send the command */
    HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

    /* Step 7 ------------------------------------------------------------------*/
    /* 设置sdram寄存器配置 */
    tmpr = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_2          |
        SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
        SDRAM_MODEREG_CAS_LATENCY_3           |
        SDRAM_MODEREG_OPERATING_MODE_STANDARD |
        SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

    /* 配置命令：设置SDRAM寄存器 */
    Command.CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
    Command.AutoRefreshNumber = 1;
    Command.ModeRegisterDefinition = tmpr;
    /* Send the command */
    HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

    /* Step 8 ------------------------------------------------------------------*/

    /* 设置刷新计数器 */
    /* (7.8125 us x Freq) - 20 */
    /* Step 6: Set the refresh rate counter */
    /* Set the device refresh rate */
    HAL_SDRAM_ProgramRefreshRate(&hsdram1, 824);
//  FMC_SetRefreshCount(1386);
//  /* 发送上述命令*/
//  while(FMC_GetFlagStatus(FMC_BANK_SDRAM, FMC_FLAG_Busy) != RESET)
//  {
//  }
}

/*
*********************************************************************************************************
*	函 数 名: WriteSpeedTest
*	功能说明: 写SDRAM速度测试
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void WriteSpeedTest(void)
{
	uint32_t i, j;
	int32_t iTime1, iTime2;
	uint32_t *pBuf;


	/* 设置初始化值并记下开始时间 */
	j = 0;
	pBuf = (uint32_t *)EXT_SDRAM_ADDR;
	iTime1 = HAL_GetTick();	 
	
	/* 以递增的方式写数据到SDRAM所有空间 */
	for (i = 1024*1024/4; i >0 ; i--)
	{
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;	

		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;	

		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;	

		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;
		*pBuf++ = j++;	
	}
	iTime2 = HAL_GetTick();	/* 记下结束时间 */
	
    /* 读取写入的是否出错 */
	j = 0;
	pBuf = (uint32_t *)EXT_SDRAM_ADDR;
	for (i = 0; i < 1024*1024*8; i++)
	{
		if(*pBuf++ != j++)
		{
			printf("写入出错 j=%d\r\n", j);
			break;
		}
	}
		
	/* 打印速度 */
	printf("32MB数据写耗时:%dms, 写速度:%dMB/s\r\n", 
	                  iTime2 - iTime1, (EXT_SDRAM_SIZE / 1024 /1024 * 1000) / (iTime2 - iTime1));
}

/*
*********************************************************************************************************
*	函 数 名: ReadSpeedTest
*	功能说明: 读SDRAM速度测试
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void ReadSpeedTest(void)
{	
	uint32_t i;
	int32_t iTime1, iTime2;
	uint32_t *pBuf;
	__IO  uint32_t ulTemp; /* 设置为__IO类型，防止被MDK优化 */

	/* 设置初始化值并记下开始时间 */
	pBuf = (uint32_t *)EXT_SDRAM_ADDR;
	iTime1 = HAL_GetTick();	
	
	/* 读取SDRAM所有空间数据 */	
	for (i = 1024*1024/4; i >0 ; i--)
	{
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;

		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
		ulTemp = *pBuf++;
	}
	iTime2 = HAL_GetTick();	/* 记下结束时间 */

	/* 打印速度 */
	printf("32MB数据读耗时:%dms, 读速度:%dMB/s\r\n", 
	        iTime2 - iTime1, (EXT_SDRAM_SIZE / 1024 /1024 * 1000) / (iTime2 - iTime1));
}
