/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    usart.c
 * @brief   This file provides code for the configuration
 *          of the USART instances.
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
#include "usart.h"

/* USER CODE BEGIN 0 */
#include <stdio.h>
uint8_t UART1_Rx_flg = 0;             // USART1接收完成标志
uint16_t UART1_Rx_cnt = 0;            // USART1接受数据计数�?
uint8_t UART1_temp[REC_LENGTH] = {0}; // USART1接收数据缓存
uint8_t UART5_Rx_flg = 0;             // UART5接收完成标志
uint16_t UART5_Rx_cnt = 0;            // UART5接受数据计数�?
uint8_t UART5_temp[REC_LENGTH] = {0}; // UART5接收数据缓存
char U5_Rec_temp[1000];
/* USER CODE END 0 */

UART_HandleTypeDef huart5;
UART_HandleTypeDef huart1;

/* UART5 init function */
void MX_UART5_Init(void)
{

  /* USER CODE BEGIN UART5_Init 0 */

  /* USER CODE END UART5_Init 0 */

  /* USER CODE BEGIN UART5_Init 1 */

  /* USER CODE END UART5_Init 1 */
  huart5.Instance = UART5;
  huart5.Init.BaudRate = 9600;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  huart5.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart5.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart5.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart5, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart5, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART5_Init 2 */

  /* USER CODE END UART5_Init 2 */
}
/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */
}

void HAL_UART_MspInit(UART_HandleTypeDef *uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if (uartHandle->Instance == UART5)
  {
    /* USER CODE BEGIN UART5_MspInit 0 */

    /* USER CODE END UART5_MspInit 0 */

    /** Initializes the peripherals clock
     */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_UART5;
    PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_D2PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* UART5 clock enable */
    __HAL_RCC_UART5_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**UART5 GPIO Configuration
    PB12     ------> UART5_RX
    PB13     ------> UART5_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF14_UART5;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* UART5 interrupt Init */
    HAL_NVIC_SetPriority(UART5_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(UART5_IRQn);
    /* USER CODE BEGIN UART5_MspInit 1 */

    /* USER CODE END UART5_MspInit 1 */
  }
  else if (uartHandle->Instance == USART1)
  {
    /* USER CODE BEGIN USART1_MspInit 0 */

    /* USER CODE END USART1_MspInit 0 */

    /** Initializes the peripherals clock
     */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    PeriphClkInitStruct.Usart16ClockSelection = RCC_USART16CLKSOURCE_D2PCLK2;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PB6     ------> USART1_TX
    PB7     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
    /* USER CODE BEGIN USART1_MspInit 1 */

    /* USER CODE END USART1_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef *uartHandle)
{

  if (uartHandle->Instance == UART5)
  {
    /* USER CODE BEGIN UART5_MspDeInit 0 */

    /* USER CODE END UART5_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_UART5_CLK_DISABLE();

    /**UART5 GPIO Configuration
    PB12     ------> UART5_RX
    PB13     ------> UART5_TX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_12 | GPIO_PIN_13);

    /* UART5 interrupt Deinit */
    HAL_NVIC_DisableIRQ(UART5_IRQn);
    /* USER CODE BEGIN UART5_MspDeInit 1 */

    /* USER CODE END UART5_MspDeInit 1 */
  }
  else if (uartHandle->Instance == USART1)
  {
    /* USER CODE BEGIN USART1_MspDeInit 0 */

    /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PB6     ------> USART1_TX
    PB7     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6 | GPIO_PIN_7);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
    /* USER CODE BEGIN USART1_MspDeInit 1 */

    /* USER CODE END USART1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void Uart_Rece_Pares(void) // 串口接收内容解析函数
{
  // 注意变量类型
  char *point = 0;     // 逗号的地�?指针
  char *nextPoint = 0; // 下一个�?�号的地�?指针

  // for循环解析接收�?
  // 总共�?要找�?7个�?�号
  for (uint8_t i = 0; i < 8; i++)
  {
    // 第一次循�?
    if (i == 0)
    {
      // 寻找第一个�?�号
      if ((point = strstr(u5_data, ",")) == NULL)
      {
        return;
      }
    }
    else
    {
      point++; // 防止重复找到同一个�?�号

      // 寻找下一个�?�号
      // 注意strstr函数的输入变量，是从上一个�?�号之后�?始找下一个�?�号
      if ((nextPoint = strstr(point, ",")) != NULL)
      {
        // 存储信息
        switch (i)
        {
        case 1: // UTC时间
          memcpy(&gps.UTCTime, point, nextPoint - point);
          break;

        case 2: // 数据有效标识
          memcpy(&gps.UsefulFlag, point, nextPoint - point);
          break;

        case 3: // 纬度
          memcpy(&gps.latitude, point, nextPoint - point);
          break;

        case 4: // 纬度方向
          memcpy(&gps.N_S, point, nextPoint - point);
          break;

        case 5: // 经度
          memcpy(&gps.longitude, point, nextPoint - point);
          break;

        case 6: // 经度方向
          memcpy(&gps.E_W, point, nextPoint - point);
          break;
        case 7:
          memcpy(&gps.speed, point, nextPoint - point);
          break;
        }
        point = nextPoint; // 更新上一个�?�号地址指针
      }
    }
  }
  // 处理数�??
  float latitude = 0;  // 存储纬度信息
  uint16_t temp1 = 0;  // 临时变量1，存储整�?
  float longitude = 0; // 存储经度信息
  uint16_t temp2 = 0;  // 临时变量2，存储整�?

  latitude = strtod((const char *)gps.latitude, NULL);   // 字符串转换成浮点�?
  longitude = strtod((const char *)gps.longitude, NULL); // 字符串转换成浮点�?

  // 纬度信息处理
  // 五位纬度信息
  if ((latitude - 10000.0f) >= 0)
  {
    // 前三位需要单独拿出来组成�?个数
    temp1 = (((uint16_t)latitude / 10000) % 10) * 100 + (((uint16_t)latitude / 1000) % 10) * 10 + ((uint16_t)latitude / 100) % 10;
    latitude = latitude - (float)temp1 * 100;
    latitude = (float)temp1 + latitude / 60;
  }
  else // 四位纬度信息
  {
    // 前两位需要单独拿出来组成�?个数
    temp1 = (((uint16_t)latitude / 1000) % 10) * 10 + ((uint16_t)latitude / 100) % 10;
    latitude = latitude - (float)temp1 * 100;
    latitude = (float)temp1 + latitude / 60;
  }

  // 经度信息处理
  // 五位经度信息
  if ((longitude - 10000.0f) >= 0)
  {
    // 前三位需要单独拿出来组成�?个数
    temp2 = (((uint16_t)longitude / 10000) % 10) * 100 + (((uint16_t)longitude / 1000) % 10) * 10 + ((uint16_t)longitude / 100) % 10;
    longitude = longitude - (float)temp2 * 100;
    longitude = (float)temp2 + longitude / 60;
  }
  else // 四位经度信息
  {
    // 前两位需要单独拿出来组成�?个数
    temp2 = (((uint16_t)longitude / 1000) % 10) * 10 + ((uint16_t)longitude / 100) % 10;
    longitude = longitude - (float)temp2 * 100;
    longitude = (float)temp2 + longitude / 60;
  }
  gps.UTCTime_int = ((uint32_t)strtod((const char *)gps.UTCTime, NULL) + 80000) % 240000;
  gps.latitude_d = latitude;
  gps.longitude_d = longitude;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    if (0x0D == UART1_temp[0])
      UART1_temp[0] = 0x20; // 防止\r在窗口中导致某行显示不出�?
    if (0x0A == UART1_temp[0])
    {
      UART1_Rx_flg = 1;
    }

    u1_data[UART1_Rx_cnt++] = UART1_temp[0];

    if (UART1_Rx_cnt >= MAX_REC_LENGTH)
    {
      UART1_Rx_cnt = 0;
      memset(u1_data, '\0', strlen(u1_data));
    }
    HAL_UART_Receive_IT(&huart1, (uint8_t *)UART1_temp, REC_LENGTH);
  }

  if (huart->Instance == UART5) // 专门接收GPS的数�? 只要$GNRMC这一行的数据
  {
    if (UART5_temp[0] == '$')
    {
      UART5_Rx_cnt = 0;
    }

    if (0x0D == UART5_temp[0])
    {
      UART5_temp[0] = 0x20;
    }
    U5_Rec_temp[UART5_Rx_cnt++] = UART5_temp[0];

    if (U5_Rec_temp[0] == '$' && U5_Rec_temp[4] == 'M' && U5_Rec_temp[5] == 'C' && UART5_temp[0] == 0x0A)
    {
      // 该行接收结束
      UART5_Rx_flg = 1;

      if (strlen(u5_data) + strlen(U5_Rec_temp) > 1000)
        memset(u5_data, '\0', strlen(u5_data));
      strcpy(u5_data, U5_Rec_temp);
      memset(U5_Rec_temp, '\0', strlen(U5_Rec_temp));
      UART5_Rx_cnt = 0;
      Uart_Rece_Pares();
    }
    HAL_UART_Receive_IT(&huart5, (uint8_t *)UART5_temp, REC_LENGTH);
  }
}
/* USER CODE END 1 */
