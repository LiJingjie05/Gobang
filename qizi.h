#ifndef __QIZI_H__
#define __QIZI_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <linux/input.h>

extern int pd();
extern void hq();
extern void restart();
extern int win();
extern int pd_win();
//extern void restart_qz();

#endif