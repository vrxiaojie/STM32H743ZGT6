#ifndef _FATFS_USER_H
#define _FATFS_USER_H

#include "ff.h"
#include "string.h"

void FATFS_FLASH_Test(void);
uint8_t scan_files(char *path);

#endif
