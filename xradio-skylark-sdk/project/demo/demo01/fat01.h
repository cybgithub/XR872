#include "fs/fatfs/ff.h"
#include "common/framework/platform_init.h"
#include "common/framework/fs_ctrl.h"
#include "fs/fatfs/diskio.h"
#include <stdio.h>
#include <string.h>
/**
 *
 * @return
 */
int F_INIT();
/**
 *
 * @return
 */
FRESULT open();
/**
 *
 * @param names
 * @return
 */
FRESULT write(const char *names);
/**
 *
 * @return
 */
FRESULT get();
/**
 *
 * @return
 */
FRESULT close();
/**
 *
 * @param path
 * @return
 */
int fs_scan_files(char *path);