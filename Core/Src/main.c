/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "fatfs.h"
#include "i2c.h"
#include "mdma.h"
#include "memorymap.h"
#include "quadspi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
lv_ui guider_ui;
GPS_Data gps;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void delay_us(uint32_t udelay)
{
  uint32_t startval, tickn, delays, wait;

  startval = SysTick->VAL;
  tickn = HAL_GetTick();
  delays = udelay * 480; // sysc / 1000 * udelay;
  if (delays > startval)
  {
    while (HAL_GetTick() == tickn)
    {
    }
    wait = 480000 + startval - delays;
    while (wait < SysTick->VAL)
    {
    }
  }
  else
  {
    wait = startval - delays;
    while (wait < SysTick->VAL && HAL_GetTick() == tickn)
    {
    }
  }
}

// printf重定向
#pragma import(__use_no_semihosting)
// 标准库需要的支持函数
struct __FILE
{
  int handle;
};

FILE __stdout;
// 定义_sys_exit()以避免使用半主机模式
void _sys_exit(int x)
{
  x = x;
}
void _ttywrch(int ch)
{
  ch = ch;
}

// 重定义fputc函数
int fputc(int ch, FILE *f)
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0x200); // 根据使用的库重定向
  return ch;
}

// LVGL FS test
lv_fs_file_t lv_file;
void lvgl_fs_test()
{

  lv_fs_res_t lv_res;
  uint8_t ReadBuffer[1024] = {0};
  uint32_t fnum;
  lv_res = lv_fs_open(&lv_file, "0:test111.txt", LV_FS_MODE_RD);
  if (lv_res != LV_FS_RES_OK)
  {
    printf("LVGL FS open error. (%d)\n", lv_res);
  }
  else
  {
    printf("LVGL FS open Ok\n");
    lv_res = lv_fs_read(&lv_file, ReadBuffer, sizeof(ReadBuffer), &fnum);
    if (lv_res != LV_FS_RES_OK)
    {
      printf("LVGL FS read error. (%d)\n", lv_res);
      return;
    }
    else{
      printf("LVGL FS read Ok\n");
		printf("%s\n",ReadBuffer);
	}
    lv_fs_close(&lv_file);
  }
  
  
//  lv_res = lv_fs_open(&lv_file, "0:serial.bmp", LV_FS_MODE_WR);
//  if (lv_res != LV_FS_RES_OK)
//  {
//    printf("LVGL FS open error. (%d)\n", lv_res);
//  }
//  else
//  {
//    printf("LVGL FS open Ok\n");
//	  uint8_t tempc[] = "hello,test";
//	  uint32_t wb;
//	  lv_res = lv_fs_write(&lv_file,tempc,sizeof(tempc),&wb);
//	  printf("wb=%d",wb);
//    //lv_res = lv_fs_write(&lv_file,_serial_alpha_80x80.data,_serial_alpha_80x80.data_size,NULL);
//    if (lv_res != LV_FS_RES_OK)
//    {
//      printf("LVGL FS write error. (%d)\n", lv_res);
//      return;
//    }
//    else{
//      printf("LVGL FS write Ok\n");
//	}
//    lv_fs_close(&lv_file);
//  }
//  // 读取总空间及剩余空间
//    DWORD fre_clust;
//    FATFS *fs_temp;
//    f_getfree("0:", &fre_clust, &fs_temp);
//    DWORD tot_sect = (fs_temp->n_fatent - 2) * fs_temp->csize;
//    DWORD fre_sect = fre_clust * fs_temp->csize;
//#if _MAX_SS != 512 // 扇区大小不是512字节,则转换为512字节
//    tot_sect *= fs_temp->ssize / 512;
//    fre_sect *= fs_temp->ssize / 512;
//#endif
//    printf("%10lu KB total drive space.\n%10lu KB available.\n", tot_sect >> 1, fre_sect >> 1);
//    // 当前目录下的文件
//    char buff[256];
//    strcpy(buff, "0:/");
//    scan_files(buff);
}

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MPU Configuration--------------------------------------------------------*/
  MPU_Config();

  /* Enable the CPU Cache */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_MDMA_Init();
  MX_FMC_Init();
  MX_I2C3_Init();
  MX_QUADSPI_Init();
  MX_UART5_Init();
  MX_USART1_UART_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_FATFS_Init();
  /* USER CODE BEGIN 2 */
  // 使能TIM3定时器中断
  HAL_TIM_Base_Start_IT(&htim3);
  // 注册DMA回调函数
  HAL_DMA_RegisterCallback(&hdma_memtomem_dma2_stream0, HAL_DMA_XFER_CPLT_CB_ID, LVGL_LCD_FSMC_DMA_pCallback);
  // 初始化LCD屏幕
  LCD_Init();
  // 设置PWM调光
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
  read_settings();
  __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4, 500);
  // 初始化LVGL
  lv_init();
  lv_port_disp_init();
  lv_port_indev_init();
  lv_port_fs_init();
  // 初始化UI及事件
  setup_ui(&guider_ui);
  events_init(&guider_ui);
  // 给BH1750发送命令，连续获取光照
  uint8_t opeCode = BH1750_CONT_HI_RSLT_1;
  BH1750_WriteOpecode(&opeCode, 1);
  // 默认关闭GPS
  HAL_GPIO_WritePin(GPS_CTRL_GPIO_Port, GPS_CTRL_Pin, GPIO_PIN_RESET);
  // 首次烧录若未校准触摸屏幕，则先校准
  if (!TP_Get_Adjdata())
  {
    tp_dev.adjust();
  }
  // 测试外部flash读写速度
  //  sfWriteTest();
  //  sfTestReadSpeed();
  // 初始化QSPI Flash
  BSP_QSPI_Init();
  // 文件系统测试
  //  FATFS_FLASH_Test();
  //  scan_files("0:");

 // lvgl_fs_test();
 
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    // 扫描屏幕是否按下
    tp_dev.scan(0);
    lv_task_handler();
  }
  /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
   */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
   */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY))
  {
  }

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY))
  {
  }

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 13;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_D3PCLK1 | RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* MPU Configuration */

void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct = {0};

  /* Disables the MPU */
  HAL_MPU_Disable();

  /** Initializes and configures the Region and the memory to be protected
   */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.BaseAddress = 0x60000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_256MB;
  MPU_InitStruct.SubRegionDisable = 0x0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /** Initializes and configures the Region and the memory to be protected
   */
  MPU_InitStruct.Number = MPU_REGION_NUMBER1;
  MPU_InitStruct.BaseAddress = 0xC0000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_32MB;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /** Initializes and configures the Region and the memory to be protected
   */
  MPU_InitStruct.Number = MPU_REGION_NUMBER2;
  MPU_InitStruct.BaseAddress = 0x24000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_512KB;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /* Enables the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
