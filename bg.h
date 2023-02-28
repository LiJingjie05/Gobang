#ifndef __BG_H__
#define __BG_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

extern void lcd_draw_qipan();
extern int lcd_draw_qizi(int flag);
extern void cross_point(int x0,int y0);

#endif
