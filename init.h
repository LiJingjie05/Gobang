#ifndef __INIT_H__
#define __INIT_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

extern int fd_lcd;
extern void open_lcd();
extern void close_lcd();

#endif