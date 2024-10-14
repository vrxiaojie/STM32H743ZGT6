#include "fatfs_user.h"

void FATFS_FLASH_Test(void)
{
    FATFS fs;                    /* FatFs文件系统对象 */
    FIL fnew;                    /* 文件对象 */
    FRESULT res_flash;           /* 文件操作结果 */
    UINT fnum;                   /* 文件成功读写数量 */
    BYTE ReadBuffer[1024] = {0}; /* 读缓冲区 */
    BYTE WriteBuffer[] =         /* 写缓冲区*/
        "~~~ 今天是个好日子2024.10.6，新建文件系统测试文件~~~\r\n";
    BYTE work[4096] = {0};
    printf("****** 这是一个SPI FLASH 文件系统实验 ******\r\n");

    // 在外部SPI Flash挂载文件系统，文件系统挂载时会对SPI设备初始化
    // 初始化函数调用流程如下
    // f_mount()->find_volume()->disk_initialize->SPI_FLASH_Init()
    res_flash = f_mount(&fs, "0:", 1);
    /*----------------------- 格式化测试 -----------------*/
    /* 如果没有文件系统就格式化创建创建文件系统 */
    if (res_flash == FR_NO_FILESYSTEM)
    {
        printf("》FLASH还没有文件系统，即将进行格式化...\r\n");
        /* 格式化 */
        res_flash = f_mkfs("0:", FM_ANY, 0, work, 4096);
        if (res_flash == FR_OK)
        {
            printf("》FLASH已成功格式化文件系统。\r\n");
            /* 格式化后，先取消挂载 */
            res_flash = f_mount(NULL, "0:", 1);
            /* 重新挂载 */
            res_flash = f_mount(&fs, "0:", 1);
        }
        else
        {

            printf("《《格式化失败。》》\r\n");
            while (1)
                ;
        }
    }
    else if (res_flash != FR_OK)
    {
        printf("！！外部Flash挂载文件系统失败。(%d)\r\n", res_flash);
        printf("！！可能原因：SPI Flash初始化不成功。\r\n");
        while (1)
            ;
    }
    else
    {
        printf("》文件系统挂载成功，可以进行读写测试\r\n");
    }

    /*----------------------- 文件系统测试：写测试 -------------------*/
    /* 打开文件，每次都以新的形式打开，属性为可写 */
    printf("\r\n****** 即将进行文件写入测试... ******\r\n");
    res_flash = f_open(&fnew, "0:/test111.txt",
                       FA_CREATE_ALWAYS | FA_WRITE);
    if (res_flash == FR_OK)
    {
        printf("》打开/创建FatFs读写测试文件.txt文件成功，向文件写入数据。\r\n");
        /* 将指定存储区内容写入到文件内 */
        res_flash = f_write(&fnew, WriteBuffer, sizeof(WriteBuffer), &fnum);
        if (res_flash == FR_OK)
        {
            printf("》文件写入成功，写入字节数据：%d\n", fnum);
            printf("》向文件写入的数据为：\r\n%s\r\n", WriteBuffer);
        }
        else
        {
            printf("！！文件写入失败：(%d)\n", res_flash);
        }
        /* 不再读写，关闭文件 */
        f_close(&fnew);
    }
    else
    {

        printf("！！打开/创建文件失败。\r\n");
    }

    /*------------------- 文件系统测试：读测试 --------------------------*/
    printf("****** 即将进行文件读取测试... ******\r\n");
    res_flash = f_open(&fnew, "0:/test111.txt",
                       FA_OPEN_EXISTING | FA_READ);
    if (res_flash == FR_OK)
    {
        printf("》打开文件成功。\r\n");
        res_flash = f_read(&fnew, ReadBuffer, sizeof(ReadBuffer), &fnum);
        if (res_flash == FR_OK)
        {
            printf("》文件读取成功,读到字节数据：%d\r\n", fnum);
            printf("》读取得的文件数据为：\r\n%s \r\n", ReadBuffer);
        }
        else
        {
            printf("！！文件读取失败：(%d)\n", res_flash);
        }
    }
    else
    {

        printf("！！打开文件失败。\r\n");
    }
    /* 不再读写，关闭文件 */
    f_close(&fnew);

    // 读取总空间及剩余空间
    DWORD fre_clust;
    FATFS *fs_temp = &fs;
    f_getfree("0:", &fre_clust, &fs_temp);
    DWORD tot_sect = (fs_temp->n_fatent - 2) * fs_temp->csize;
    DWORD fre_sect = fre_clust * fs_temp->csize;
#if _MAX_SS != 512 // 扇区大小不是512字节,则转换为512字节
    tot_sect *= fs_temp->ssize / 512;
    fre_sect *= fs_temp->ssize / 512;
#endif
    printf("%10lu KB total drive space.\n%10lu KB available.\n", tot_sect >> 1, fre_sect >> 1);
    // 当前目录下的文件
    char buff[256];
    strcpy(buff, "0:/");
    scan_files(buff);

    /* 不再使用文件系统，取消挂载文件系统 */
    f_mount(NULL, "0:/", 1);
}

uint8_t scan_files(
    char *path /* Start node to be scanned (***also used as work area***) */
)
{
    SCB_CleanInvalidateDCache(); // 清理DCache缓存保证数据一致性
    FRESULT res;
    DIR dir;
    UINT i;
    char filenames[100];
    uint16_t j = 0;
    static FILINFO fno;

    res = f_opendir(&dir, path); /* Open the directory */
    if (res == FR_OK)
    {
        for (;;)
        {
            res = f_readdir(&dir, &fno); /* Read a directory item */
            if (res != FR_OK || fno.fname[0] == 0)
                break; /* Break on error or end of dir */
            if (fno.fattrib & AM_DIR)
            { /* It is a directory */
                i = strlen(path);
                sprintf(&path[i], "/%s", fno.fname);
                res = scan_files(path); /* Enter the directory */
                if (res != FR_OK)
                    break;
                path[i] = 0;
            }
            else
            {                                                            /* It is a file. */
                printf("%s/%s -- %10u B\n", path, fno.fname, fno.fsize); // 文件名--大小
                sprintf(filenames, "%s", fno.fname);
                lv_table_set_cell_value(guider_ui.file_explorer_screen_explorer, j++, 0, filenames);
            }
        }
        f_closedir(&dir);
    }

    return res;
}
