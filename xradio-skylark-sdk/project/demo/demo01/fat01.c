#include "fs/fatfs/ff.h"
#include "common/framework/platform_init.h"
#include "common/framework/fs_ctrl.h"
#include "fs/fatfs/diskio.h"
#include <stdio.h>
#include <string.h>

FIL f;

int F_INIT()
{
        if (fs_ctrl_mount(FS_MNT_DEV_TYPE_SDCARD, 0) != 0)
        {
                printf("mount fail\n");
                return -1;
        }

        printf("mount success\n");

        return 0;
}

FRESULT open()
{
        FRESULT ret;
        ret = f_open(&f, "print_file.txt", FA_READ | FA_WRITE | FA_OPEN_ALWAYS);
        printf("open result = %d\n", ret);
        return ret;
}

FRESULT write(const char *names)
{
        uint32_t bw;
        FRESULT ret = f_write(&f, names, sizeof(names), &bw);

        printf("write result = %d\n", ret);

        return ret;
}

FRESULT get()
{
        UINT buf[1024];
        UINT read;
        FRESULT ret = f_read(&f, &buf, sizeof(buf), &read);
        printf("get result = %d\n", ret);
        return ret;
}

FRESULT close()
{
        FRESULT ret = f_close(&f);
        printf("close result = %d\n", ret);
        return ret;
}

int fs_scan_files(char *path)
{
        FRESULT res;
        DIR dir;
        UINT i;
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
                                res = fs_scan_files(path); /* Enter the directory */
                                if (res != FR_OK)
                                        break;
                                path[i] = 0;
                        }
                        else
                        { /* It is a file. */
                                printf("%s/%s\n", path, fno.fname);
                        }
                }
                f_closedir(&dir);
        }

        return res;
}