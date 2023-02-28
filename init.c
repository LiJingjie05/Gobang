#include "init.h"

int fd_lcd = 0;
void open_lcd()
{
    fd_lcd = open("/dev/fb0",O_RDWR);
    if(fd_lcd == -1)
    {
        printf("打开文件失败！\n");
        return ;
    }
    printf("屏幕打开成功\n");
}


void close_lcd()
{
    close(fd_lcd);
}