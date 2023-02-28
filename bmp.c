#include "bmp.h"
#include "init.h"
#include "mmap.h"

int bmp_fd;
extern int *plcd;

void lcd_draw_point(int x,int y,int color)
 {
	if(x>=0&&x<800&&y>=0&&y<480)
	{
		*(plcd+800*y+x)=color;
	}	
 }

 void lcd_draw_line(int x,int x1,int y,int y1,int color)
 {
	if(x>=0&&x<800&&y>=0&&y<480)
	{
        int i,j;
        for(j=y;j<y1;j++)
        {
	        for(i=x;i<x1;i++)
	        {    
                *(plcd+800*j+i)=color;

	        }
        }
		
	}	
 }

int display_bmp(char * bmp,int x0,int y0)
{
    bmp_fd = open(bmp,O_RDWR);
    int width = 0;
    lseek(bmp_fd,0x12,SEEK_SET);
    int ret0 = read(bmp_fd,&width,4);
    if(ret0 == -1)
    {
        printf("读取宽失败\n");
        return 0;
    }
    printf("%d\n",width);

    int high = 0;
    lseek(bmp_fd,0x16,SEEK_SET);
    int ret1 = read(bmp_fd,&high,4);
    if(ret1 == -1)
    {
        printf("读取高失败\n");
        return 0;
    }
    printf("%d\n",high);

    int depth = 0; //一定要记得给0
    lseek(bmp_fd,0x1c,SEEK_SET);
    int ret2 = read(bmp_fd,&depth,2);
    if(ret2 == -1)
    {
        printf("读取色深失败\n");
        return 0;
    }
    const int shuzu = abs(width)*abs(high)*abs(depth/8);
    char p[shuzu];
    read(bmp_fd,p,abs(width)*abs(high)*(depth/8));

    unsigned char a,r,g,b;
	int color;
	int x,y;//从哪个显示位置
	int i = 0;
	//int x0,y0;//初始位置
	// x0 =0;
	// y0 = 0;
	for(y=0;y<abs(high);y++)
	{
		for(x=0;x<abs(width);x++)
		{
			b=p[i++];
			g=p[i++];
			r=p[i++];
			if(depth == 32)
			{
				a=p[i++];
			}
			else
			{
				a=0;
			}
			color = (a<<24)|(r<<16)|(g<<8)|(b);
			lcd_draw_point(width>0?x+x0:x0+abs(width)-1-x,high>0?high-1-y+y0:y0+y,color);	
		}
	} 
}

void close_bmp()
{
	close(bmp_fd);
}