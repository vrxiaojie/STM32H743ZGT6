/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include "touch.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lv_port_fs.h"
#include "events_init.h"
#include "gui_guider.h"
#include "custom.h"
#include "BH1750.h"
#include "settings.h"
#include "EEPROM.h"
#include "SDRAM.h"
#include "flash_qspi.h"
#include "ff.h"
#include "diskio.h"
#include "fatfs_user.h"
#include "GUI.h"
  /* USER CODE END Includes */

  /* Exported types ------------------------------------------------------------*/
  /* USER CODE BEGIN ET */
  typedef struct
  {
    uint8_t UTCTime[15];
    uint32_t UTCTime_int;
    uint8_t UsefulFlag;
    uint8_t latitude[15];
    float latitude_d;
    char N_S;
    uint8_t longitude[15];
    float longitude_d;
    char E_W;
    uint8_t speed[10];
    float speed_d;
  } GPS_Data;

  /* USER CODE END ET */

  /* Exported constants --------------------------------------------------------*/
  /* USER CODE BEGIN EC */
  extern GPS_Data gps;
  /* USER CODE END EC */

  /* Exported macro ------------------------------------------------------------*/
  /* USER CODE BEGIN EM */

  /* USER CODE END EM */

  /* Exported functions prototypes ---------------------------------------------*/
  void Error_Handler(void);

  /* USER CODE BEGIN EFP */
  void delay_us(uint32_t udelay);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define USER_LED_Pin GPIO_PIN_1
#define USER_LED_GPIO_Port GPIOA
#define LCD_BL_Pin GPIO_PIN_3
#define LCD_BL_GPIO_Port GPIOA
#define PEN_Pin GPIO_PIN_0
#define PEN_GPIO_Port GPIOB
#define T_CS_Pin GPIO_PIN_1
#define T_CS_GPIO_Port GPIOB
#define GPS_CTRL_Pin GPIO_PIN_11
#define GPS_CTRL_GPIO_Port GPIOB
#define OV_SCL_Pin GPIO_PIN_11
#define OV_SCL_GPIO_Port GPIOD
#define OV_SDA_Pin GPIO_PIN_12
#define OV_SDA_GPIO_Port GPIOD
#define NAND_CS_Pin GPIO_PIN_15
#define NAND_CS_GPIO_Port GPIOA
#define CLK_Pin GPIO_PIN_10
#define CLK_GPIO_Port GPIOC
#define MISO_Pin GPIO_PIN_11
#define MISO_GPIO_Port GPIOC
#define MOSI_Pin GPIO_PIN_12
#define MOSI_GPIO_Port GPIOC
#define OV_RST_Pin GPIO_PIN_6
#define OV_RST_GPIO_Port GPIOD
#define OV_PWDN_Pin GPIO_PIN_7
#define OV_PWDN_GPIO_Port GPIOD
#define SDMMC2_CD_Pin GPIO_PIN_10
#define SDMMC2_CD_GPIO_Port GPIOG

  /* USER CODE BEGIN Private defines */

  /* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
