#include "mmap.h"
#include "init.h"

int *plcd = NULL;
extern int fd_lcd;

void open_mmap()
{
	plcd = mmap(NULL,480*800*4,PROT_READ|PROT_WRITE|PROT_EXEC,MAP_SHARED,fd_lcd,0);
}
void close_mmap()
{

	munmap(plcd,480*800*4);
}
