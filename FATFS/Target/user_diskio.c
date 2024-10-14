/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    user_diskio.c
 * @brief   This file includes a diskio driver skeleton to be completed by the user.
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

#ifdef USE_OBSOLETE_USER_CODE_SECTION_0
/*
 * Warning: the user section 0 is no more in use (starting from CubeMx version 4.16.0)
 * To be suppressed in the future.
 * Kept to ensure backward compatibility with previous CubeMx versions when
 * migrating projects.
 * User code previously added there should be copied in the new user sections before
 * the section contents can be deleted.
 */
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */
#endif

/* USER CODE BEGIN DECL */

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "ff_gen_drv.h"
#include "user_diskio.h"
#include "flash_qspi.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/* Disk status */
static volatile DSTATUS Stat = STA_NOINIT;

/* USER CODE END DECL */

/* Private function prototypes -----------------------------------------------*/
DSTATUS USER_initialize (BYTE pdrv);
DSTATUS USER_status (BYTE pdrv);
DRESULT USER_read (BYTE pdrv, BYTE *buff, DWORD sector, UINT count);
#if _USE_WRITE == 1
  DRESULT USER_write (BYTE pdrv, const BYTE *buff, DWORD sector, UINT count);
#endif /* _USE_WRITE == 1 */
#if _USE_IOCTL == 1
  DRESULT USER_ioctl (BYTE pdrv, BYTE cmd, void *buff);
#endif /* _USE_IOCTL == 1 */

Diskio_drvTypeDef  USER_Driver =
{
  USER_initialize,
  USER_status,
  USER_read,
#if  _USE_WRITE
  USER_write,
#endif  /* _USE_WRITE == 1 */
#if  _USE_IOCTL == 1
  USER_ioctl,
#endif /* _USE_IOCTL == 1 */
};

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes a Drive
  * @param  pdrv: Physical drive number (0..)
  * @retval DSTATUS: Operation status
  */
DSTATUS USER_initialize (
	BYTE pdrv           /* Physical drive nmuber to identify the drive */
)
{
  /* USER CODE BEGIN INIT */
  DSTATUS status;
	if(BSP_QSPI_Init()!=QSPI_OK)
		status = RES_ERROR;
  status = RES_OK;
  return status;
  /* USER CODE END INIT */
}

/**
  * @brief  Gets Disk Status
  * @param  pdrv: Physical drive number (0..)
  * @retval DSTATUS: Operation status
  */
DSTATUS USER_status (
	BYTE pdrv       /* Physical drive number to identify the drive */
)
{
  /* USER CODE BEGIN STATUS */
  DSTATUS status = STA_NOINIT;

  /*读取SPI Flash 设备ID */
  if (sFLASH_ID == QSPI_FLASH_ReadID())
  {
    /* 设备ID读取结果正确 */
    status &= ~STA_NOINIT;
  }
  else
  {
    /* 设备ID读取结果错误 */
    status = STA_NOINIT;
  }

  return status;
  /* USER CODE END STATUS */
}

/**
  * @brief  Reads Sector(s)
  * @param  pdrv: Physical drive number (0..)
  * @param  *buff: Data buffer to store read data
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to read (1..128)
  * @retval DRESULT: Operation result
  */
DRESULT USER_read (
	BYTE pdrv,      /* Physical drive nmuber to identify the drive */
	BYTE *buff,     /* Data buffer to store read data */
	DWORD sector,   /* Sector address in LBA */
	UINT count      /* Number of sectors to read */
)
{
  /* USER CODE BEGIN READ */
  DRESULT status = RES_PARERR;
  if (BSP_QSPI_Read(buff, sector << 12, count << 12) == QSPI_OK)
    status = RES_OK;
  return status;
  /* USER CODE END READ */
}

/**
  * @brief  Writes Sector(s)
  * @param  pdrv: Physical drive number (0..)
  * @param  *buff: Data to be written
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to write (1..128)
  * @retval DRESULT: Operation result
  */
#if _USE_WRITE == 1
DRESULT USER_write (
	BYTE pdrv,          /* Physical drive nmuber to identify the drive */
	const BYTE *buff,   /* Data to be written */
	DWORD sector,       /* Sector address in LBA */
	UINT count          /* Number of sectors to write */
)
{
  /* USER CODE BEGIN WRITE */
  /* USER CODE HERE */
  uint32_t write_addr;
  DRESULT status = RES_PARERR;
  write_addr = sector << 12; // �???4K字节为单�???

  for (uint8_t i = 0; i < count; i++)
  {
    write_addr += i * 4096;
    if (BSP_QSPI_Erase_Block(write_addr) != QSPI_OK) // 写入前先擦除扇区 (4KB)
    {
      status = RES_ERROR;
    }
    // if (BSP_QSPI_Write((uint8_t *)buff, write_addr + i * 4096, 4096) != QSPI_OK) //!!!!数据大小一定是要写4096，不能用sizeof()!!!!
    for (uint32_t j = 0; j < 4096; j += PAGE_SIZE)
    {

      if (BSP_QSPI_Write((uint8_t *)buff, write_addr + j, PAGE_SIZE) != QSPI_OK)
      {
        printf("写串行Flash出错！\r\n");
        return RES_ERROR;
      }
      buff += PAGE_SIZE;
    }
  }

  status = RES_OK;
  return status;
  /* USER CODE END WRITE */
}
#endif /* _USE_WRITE == 1 */

/**
  * @brief  I/O control operation
  * @param  pdrv: Physical drive number (0..)
  * @param  cmd: Control code
  * @param  *buff: Buffer to send/receive control data
  * @retval DRESULT: Operation result
  */
#if _USE_IOCTL == 1
DRESULT USER_ioctl (
	BYTE pdrv,      /* Physical drive nmuber (0..) */
	BYTE cmd,       /* Control code */
	void *buff      /* Buffer to send/receive control data */
)
{
  /* USER CODE BEGIN IOCTL */
  DRESULT status = RES_PARERR;
  switch (cmd)
  {
  /* 扇区数量�???8192*4096/1024/1024=32(MB) */
  case GET_SECTOR_COUNT:
    *(DWORD *)buff = 8192;
    break;
  /* 扇区大小  */
  case GET_SECTOR_SIZE:
    *(WORD *)buff = 4096;
    break;
  /* 同时擦除扇区个数 */
  case GET_BLOCK_SIZE:
    *(DWORD *)buff = 1;
    break;
  }
  status = RES_OK;
  return status;
  /* USER CODE END IOCTL */
}
#endif /* _USE_IOCTL == 1 */

