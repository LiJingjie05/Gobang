
#include <pthread.h>
#include "mmap.h"
#include "init.h"
#include "bmp.h"
#include "touch.h"
#include "bg.h"
#include "qizi.h"

void game();
void begin();
void shezhi();

extern int x_read;
extern int y_read;
extern int a[15][15];
extern int k;
extern int l;

int flag = 1;
int b1 = 1;
//int b2 = 0;
/**
 * 开始游戏
*/
void game()
{
	lcd_draw_qipan();//绘制棋盘
	sleep(1);
	//清空棋盘
	for(int i = 0;i<15;i++)
	{
		for(int j = 0;j<15;j++)
		{
			a[i][j] = 0;
		}
	}
	while(1)
	{
		ts_read();
		cross_point(x_read,y_read);
		int h = pd();//有问题
		if(h>0)
		{
			if(a[k][l]==1)
			{
				lcd_draw_qizi(0);
				//b2 = 1;
			}
			else if(a[k][l]==2)
			{
				lcd_draw_qizi(1);
				//b2 = 1;
			}
			int p =pd_win();//有问题
			if(win(p)<0)
			{
				while(1)
				{
					ts_read();
					if(x_read>=0&&x_read<=240&&y_read>=405&&y_read<=474)
					{
						//sleep(1);
						game();
					}
					else if(x_read>=585&&x_read<=800&&y_read>=402&&y_read<=480)
					{
						//sleep(1);
						begin();
					}
				}
			}
		}
		
	}
}
/**
 * 等待开始游戏
*/
void begin()
{
	display_bmp("begin.bmp",0,0);//显示开始页面
	//system("madplay ./music/*.mp3 -z");
	while(1)
	{
		ts_read();
		if(x_read>=284&&x_read<=544&&y_read>=149&&y_read<=207)
		{

			game();
		}
		else if(x_read>=288&&x_read<=547&&y_read>=228&&y_read<=285)
		{
			while(1)
			{
				shezhi();
			}
			
		}
	}
}

void shezhi()
{
	display_bmp("shezhi.bmp",0,0);
	while(1)
	{
		ts_read();
		if(x_read>=0&&x_read<=169&&y_read>=0&&y_read<=56)
		{
			begin();
		}
		else if(x_read>=277&&x_read<=551&&y_read>=168&&y_read<=234)
		{
			b1 = 2;
			//printf("%d\n",b1);
		}
		else if(x_read>=279&&x_read<=552&&y_read>=288&&y_read<=345)
		{
			b1 = 3;
			//printf("%d\n",b1);
		}
	}
}

void *bgm_music(void *arge)
	{
		while(1)
		{
			if(b1 == 1)
			{
				system("killall -9 madplay");//杀死播放器
				system("madplay ./music/*.mp3 -z &");//播放对应的音乐
				b1 =-1;
			}
			if(b1 == 3)
			{
				printf("%d\n",b1);
				system("killall -9 madplay");//杀死播放器
				b1 =-1;
			}
			if(b1 == 2)
			{
				printf("%d\n",b1);
				//system("killall -CONT madplay &");//杀死播放器
				system("madplay ./music/*.mp3 -z &");
				b1 =-1;
			}
		}	
	}

int main()
{ 
	pthread_t id;
    open_lcd();
    open_mmap();

	
	pthread_create(&id,NULL,bgm_music,NULL);
	begin();

    close_bmp();
    close_mmap();
    close_lcd();
	pthread_join(id,NULL);//阻塞性等待线程死亡，回收资源
    return 0;
}