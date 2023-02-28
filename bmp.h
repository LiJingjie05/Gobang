#ifndef __BMP_H__
#define __BMP_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

extern void lcd_draw_point(int x,int y,int color);
extern int display_bmp(char*bmpname,int x0,int y0);
extern void close_bmp();
extern void lcd_draw_line(int x,int x1,int y,int y1,int color);

#endif