#include "touch.h"

int x_read =-1;
int y_read =-1;

int ts_read()
{
	//打开触摸屏文件
	//printf("1\n");
	int touch_fd = open("/dev/input/event0",O_RDWR);
	int x = -1,y = -1;
	struct input_event val;
	while(1)
	{
		read(touch_fd,&val,sizeof(val));
		if(val.type == EV_KEY&&val.code == BTN_TOUCH)
		{
			if(val.value == 1)
			{
				printf("press\n");
				return 1;
			}
			if(val.value == 0)
			{
				return 0;
			}

		}
		if(val.type == EV_ABS)
		{
			if(val.code == ABS_X)
			x = val.value*800/1024;
			if(val.code == ABS_Y)
			y = val.value*480/600;
			if(x>=0&&y>=0)
			{
				x_read = x;
				y_read = y;
				printf("(%d,%d)\n",x_read,y_read);
				break;
			}
			//return 1;
		}
	}
	//printf("3\n");
	
}