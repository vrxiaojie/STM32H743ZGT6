#include "flash_qspi.h"
#include "quadspi.h"
#include <stdio.h>
#include <string.h>

static __IO uint8_t CmdCplt, RxCplt, TxCplt, StatusMatch, TimeOut;

/*
*********************************************************************************************************
*	函 数 名: sfTestReadSpeed
*	功能说明: 测试串行Flash读速度。读取整个串行Flash的数据，最后打印结果
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
ALIGN_32BYTES(uint8_t SpeedTestbuf[16 * 1024]); /* 仅用于读速度测试目的 */
void sfTestReadSpeed(void)
{
    uint32_t i;
    int32_t iTime1, iTime2;
    uint32_t uiAddr;

    iTime1 = HAL_GetTick(); /* 记下开始时间 */
    uiAddr = 0;
    for (i = 0; i < FLASH_SIZE_32MB / (16 * 1024); i++, uiAddr += 16 * 1024)
    {
        BSP_QSPI_Read(SpeedTestbuf, uiAddr, 16 * 1024);
    }
    iTime2 = HAL_GetTick(); /* 记下结束时间 */

    /* 打印读速度 */
    printf("数据长度: %d字节, 读耗时: %dms, 读速度: %d KB/s\r\n", FLASH_SIZE_32MB, iTime2 - iTime1, FLASH_SIZE_32MB / (iTime2 - iTime1));
}

/*
*********************************************************************************************************
*	函 数 名: sfWriteTest
*	功能说明: 写串行Flash测试
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
#define TEST_SIZE 32 * 1024 //  32KB
#define TEST_ADDR 30 * 1024 * 1024
ALIGN_32BYTES(uint8_t buf[TEST_SIZE]);
void sfWriteTest(void)
{
    uint32_t i;
    int32_t iTime1, iTime2;

    /* 填充测试缓冲区 */
    for (i = 0; i < TEST_SIZE; i++)
    {
        buf[i] = i;
    }

    BSP_QSPI_Erase_Block(TEST_ADDR);

    iTime1 = HAL_GetTick(); /* 记下开始时间 */
    for (i = 0; i < TEST_SIZE; i += QSPI_PAGE_SIZE)
    {
        if (BSP_QSPI_Write(buf, TEST_ADDR + i, QSPI_PAGE_SIZE) != QSPI_OK)
        {
            printf("写串行Flash出错！\r\n");
            return;
        }
    }

    iTime2 = HAL_GetTick(); /* 记下结束时间 */
    printf("写串行Flash成功！\r\n");

    /* 打印读速度 */
    printf("数据长度: %d字节, 写耗时: %dms, 写速度: %dB/s\r\n", TEST_SIZE, iTime2 - iTime1, (TEST_SIZE * 1000) / (iTime2 - iTime1));
}

/**
 * @brief  擦除QSPI存储器的指定块
 * @param  BlockAddress: 需要擦除的块地址
 * @retval QSPI存储器状态
 */
uint8_t BSP_QSPI_Erase_Block(uint32_t BlockAddress)
{
    /* 用于命令发送完成标志 */
    CmdCplt = 0;

    QSPI_CommandTypeDef s_command;
    /* 初始化擦除命令 */
    s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    s_command.Instruction = SECTOR_ERASE_CMD;
    s_command.AddressMode = QSPI_ADDRESS_1_LINE;
    s_command.AddressSize = QSPI_ADDRESS_32_BITS;
    s_command.Address = BlockAddress;
    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    s_command.DataMode = QSPI_DATA_NONE;
    s_command.DummyCycles = 0;
    s_command.DdrMode = QSPI_DDR_MODE_DISABLE;
    s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    s_command.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

    /* 启用写操作 */
    if (QSPI_WriteEnable() != QSPI_OK)
    {
        return QSPI_ERROR;
    }

    if (HAL_QSPI_Command_IT(&hqspi, &s_command) != HAL_OK)
    {
        return QSPI_ERROR;
    }

    /* 等待命令发送完毕 */
    while (CmdCplt == 0)
        ;
    CmdCplt = 0;

    /* 等待编程结束 */
    StatusMatch = 0;
    QSPI_AutoPollingMemReady(&hqspi);
    while (StatusMatch == 0)
        ;
    StatusMatch = 0;
    return QSPI_OK;
}

static uint8_t QSPI_ResetMemory()
{
    QSPI_CommandTypeDef s_command;
    /* 初始化复位使能命令 */
    s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    s_command.Instruction = RESET_ENABLE_CMD;
    s_command.AddressMode = QSPI_ADDRESS_NONE;
    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    s_command.DataMode = QSPI_DATA_NONE;
    s_command.DummyCycles = 0;
    s_command.DdrMode = QSPI_DDR_MODE_DISABLE;
    s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    s_command.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

    /* 发送命令 */
    if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return QSPI_ERROR;
    }

    /* 发送复位存储器命令 */
    s_command.Instruction = RESET_MEMORY_CMD;
    if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return QSPI_ERROR;
    }

    StatusMatch = 0;
    QSPI_AutoPollingMemReady(&hqspi);
    while (StatusMatch == 0)
        ;
    StatusMatch = 0;
    return QSPI_OK;
}

/**
 * @brief  读取存储器的SR并等待EOP
 * @param  hqspi: QSPI句柄
 * @param  Timeout 超时
 * @retval 无
 */
static uint8_t QSPI_AutoPollingMemReady(QSPI_HandleTypeDef *hqspi)
{
    QSPI_CommandTypeDef s_command;
    QSPI_AutoPollingTypeDef s_config;
    /* 配置自动轮询模式等待存储器准备就绪 */
    s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    s_command.Instruction = READ_STATUS_REG1_CMD;
    s_command.AddressMode = QSPI_ADDRESS_NONE;
    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    s_command.DataMode = QSPI_DATA_1_LINE;
    s_command.DummyCycles = 0;
    s_command.DdrMode = QSPI_DDR_MODE_DISABLE;
    s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    s_command.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

    s_config.Match = 0x00;
    s_config.Mask = FSR_BUSY;
    s_config.MatchMode = QSPI_MATCH_MODE_AND;
    s_config.StatusBytesSize = 1;
    s_config.Interval = 0x10;
    s_config.AutomaticStop = QSPI_AUTOMATIC_STOP_ENABLE;

    if (HAL_QSPI_AutoPolling_IT(hqspi, &s_command, &s_config) != HAL_OK)
    {
        return QSPI_ERROR;
    }
    // if (HAL_QSPI_AutoPolling(&hqspi, &s_command, &s_config, Timeout) != HAL_OK)
    // {
    //     return QSPI_ERROR;
    // }
    return QSPI_OK;
}

/**
 * @brief  发送写入使能，等待它有效.
 * @param  hqspi: QSPI句柄
 * @retval 无
 */
static uint8_t QSPI_WriteEnable()
{
    QSPI_CommandTypeDef s_command;
    /* 启用写操作 */
    s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    s_command.Instruction = WRITE_ENABLE_CMD;
    s_command.AddressMode = QSPI_ADDRESS_NONE;
    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    s_command.DataMode = QSPI_DATA_NONE;
    s_command.DummyCycles = 0;
    s_command.DdrMode = QSPI_DDR_MODE_DISABLE;
    s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    s_command.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;
    if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return QSPI_ERROR;
    }

    return QSPI_OK;
}

/**
 * @brief  设置QSPI存储器为4字节地址模式。
 * @param  无
 * @retval 无
 */
static uint8_t BSP_QSPI_4BYTE_ADDR_MOD(void)
{
    QSPI_CommandTypeDef s_command;
    /* 初始化复位使能命令 */
    s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    s_command.Instruction = ENTER_4_BYTE_ADDR_MODE_CMD;
    s_command.AddressMode = QSPI_ADDRESS_NONE;
    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    s_command.DataMode = QSPI_DATA_NONE;
    s_command.DummyCycles = 0;
    s_command.DdrMode = QSPI_DDR_MODE_DISABLE;
    s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    s_command.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

    /* 发送命令 */
    if (HAL_QSPI_Command(&hqspi, &s_command,
                         HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return QSPI_ERROR;
    }

    StatusMatch = 0;
    QSPI_AutoPollingMemReady(&hqspi);
    while (StatusMatch == 0)
        ;
    StatusMatch = 0;
    return QSPI_OK;
}

/**
 * @brief  从QSPI存储器中读取大量数据.
 * @param  pData: 指向要读取的数据的指针
 * @param  ReadAddr: 读取起始地址
 * @param  Size: 要读取的数据大小
 * @retval QSPI存储器状态
 */
uint8_t BSP_QSPI_Read(uint8_t *pData, uint32_t ReadAddr, uint32_t Size)
{
    /* 用于等待接收完成标志 */
    RxCplt = 0;

    QSPI_CommandTypeDef s_command;
    /* 初始化读命令 */
    s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    s_command.Instruction = QUAD_OUT_FAST_READ_CMD;
    s_command.AddressMode = QSPI_ADDRESS_1_LINE;
    s_command.AddressSize = QSPI_ADDRESS_32_BITS;
    s_command.Address = ReadAddr;
    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    s_command.DataMode = QSPI_DATA_4_LINES;
    s_command.DummyCycles = 8;
    s_command.NbData = Size;
    s_command.DdrMode = QSPI_DDR_MODE_DISABLE;
    s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    s_command.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

    /* 配置命令 */
    if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return QSPI_ERROR;
    }
	SCB_CleanInvalidateDCache();
    /* MDMA方式读取 */
    if (HAL_QSPI_Receive_DMA(&hqspi, pData) != HAL_OK)
    {
        return QSPI_ERROR;
    }

    /* 等接受完毕 */
    while (RxCplt == 0)
        ;
    RxCplt = 0;
	//SCB_CleanInvalidateDCache();
    return 0;
}

/**
 * @brief  将大量数据写入QSPI存储器 Size最大=256字节
 * @param  pData: 指向要写入数据的指针
 * @param  WriteAddr: 写起始地址
 * @param  Size: 要写入的数据大小
 * @retval QSPI存储器状态
 */
uint8_t BSP_QSPI_Write(uint8_t *pData, uint32_t WriteAddr, uint32_t Size)
{
	SCB_CleanInvalidateDCache();
    /* 用于等待发送完成标志 */
    TxCplt = 0;

    QSPI_WriteEnable();

    QSPI_CommandTypeDef s_command;

    /* 初始化程序命令 */
    /* 基本配置 */
    s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;     /* 1线方式发送指令 */
    s_command.AddressSize = QSPI_ADDRESS_32_BITS;            /* 32位地址 */
    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE; /* 无交替字节 */
    s_command.DdrMode = QSPI_DDR_MODE_DISABLE;               /* W25Q256JV不支持DDR */
    s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;  /* DDR模式，数据输出延迟 */
    s_command.SIOOMode = QSPI_SIOO_INST_ONLY_FIRST_CMD;      /* 仅发送一次命令 */

    /* 写序列配置 */
    s_command.Instruction = QUAD_IN_FAST_PROG_4_BYTE_ADDR_CMD; /* 32bit地址的4线快速写入命令 */
    s_command.DummyCycles = 0;                                 /* 不需要空周期 */
    s_command.AddressMode = QSPI_ADDRESS_1_LINE;               /* 1线地址方式 */
    s_command.DataMode = QSPI_DATA_4_LINES;                    /* 4线数据方式 */
    s_command.NbData = Size;                                   /* 写数据大小 */
    s_command.Address = WriteAddr;                             /* 写入地址 */
    if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return QSPI_ERROR;
    }

    /* 启动MDMA传输 */
    if (HAL_QSPI_Transmit_DMA(&hqspi, pData) != HAL_OK)
    {
        return QSPI_ERROR;
    }

    /* 等待数据发送完毕 */
    while (TxCplt == 0)
        ;
    TxCplt = 0;

    /* 等待Flash页编程完毕 */
    StatusMatch = 0;
    QSPI_AutoPollingMemReady(&hqspi);
    while (StatusMatch == 0)
        ;
    StatusMatch = 0;
    return QSPI_OK;
}

/**
 * @brief  初始化QSPI存储器
 * @retval QSPI存储器状态
 */
uint8_t BSP_QSPI_Init(void)
{
    /* QSPI存储器复位 */
    if (QSPI_ResetMemory() != QSPI_OK)
    {
        return QSPI_NOT_SUPPORTED;
    }

    /* 设置QSPI存储器为4字节地址模式 */
    if (BSP_QSPI_4BYTE_ADDR_MOD() != QSPI_OK)
    {
        return QSPI_ERROR;
    }

    /* 使能写操作 */
    if (QSPI_WriteEnable() != QSPI_OK)
    {
        return QSPI_ERROR;
    }
    return QSPI_OK;
}

/**
 * @brief  读取FLASH ID
 * @param   无
 * @retval FLASH ID
 */
uint32_t QSPI_FLASH_ReadID(void)
{
    QSPI_CommandTypeDef s_command;
    uint32_t Temp = 0;
    uint8_t pData[3];
    /* 读取JEDEC ID */
    s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    s_command.Instruction = READ_JEDEC_ID_CMD;
    s_command.AddressMode = QSPI_ADDRESS_1_LINE;
    s_command.AddressSize = QSPI_ADDRESS_32_BITS;
    s_command.DataMode = QSPI_DATA_1_LINE;
    s_command.AddressMode = QSPI_ADDRESS_NONE;
    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    s_command.DummyCycles = 0;
    s_command.NbData = 3;
    s_command.DdrMode = QSPI_DDR_MODE_DISABLE;
    s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    s_command.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

    if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        printf("something wrong ....\r\n");
        /* 用户可以在这里添加一些代码来处理这个错误 */
        while (1)
        {
        }
    }
    if (HAL_QSPI_Receive(&hqspi, pData, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        printf("something wrong ....\r\n");
        /* 用户可以在这里添加一些代码来处理这个错误 */
        while (1)
        {
        }
    }

    Temp = (pData[2] | pData[1] << 8) | (pData[0] << 16);

    return Temp;
}

/*
*********************************************************************************************************
*	函 数 名: HAL_QSPI_CmdCpltCallback
*	功能说明: QSPI中断的回调函数，Flash擦除函数QSPI_EraseSector要使用
*	形    参: hqspi  QSPI_HandleTypeDef句柄
*	返 回 值: 无
*********************************************************************************************************
*/
void HAL_QSPI_CmdCpltCallback(QSPI_HandleTypeDef *hqspi)
{
    CmdCplt++;
}

/*
*********************************************************************************************************
*	函 数 名: HAL_QSPI_RxCpltCallback
*	功能说明: QSPI中断的回调函数，Flash读函数QSPI_ReadBuffer要使用
*	形    参: hqspi  QSPI_HandleTypeDef句柄
*	返 回 值: 无
*********************************************************************************************************
*/
void HAL_QSPI_RxCpltCallback(QSPI_HandleTypeDef *hqspi)
{
    RxCplt++;
}

/*
*********************************************************************************************************
*	函 数 名: HAL_QSPI_TxCpltCallback
*	功能说明: QSPI中断的回调函数，Flash写函数QSPI_ReadBuffer要使用
*	形    参: hqspi  QSPI_HandleTypeDef句柄
*	返 回 值: 无
*********************************************************************************************************
*/
void HAL_QSPI_TxCpltCallback(QSPI_HandleTypeDef *hqspi)
{
    TxCplt++;
}

/*
*********************************************************************************************************
*	函 数 名: HAL_QSPI_StatusMatchCallback
*	功能说明: QSPI中断的回调函数，Flash状态查询函数QSPI_AutoPollingMemReady使用
*	形    参: hqspi  QSPI_HandleTypeDef句柄
*	返 回 值: 无
*********************************************************************************************************
*/
void HAL_QSPI_StatusMatchCallback(QSPI_HandleTypeDef *hqspi)
{
    StatusMatch++;
}
