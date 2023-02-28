#include "bmp.h"
#include "bg.h"


int color[] ={0x00000000/*黑色*/,0x00ffffff/*白色*/};
/**
 * 函数名：lcd_draw_qipan
 * 功能：绘制游戏棋盘
 **/
int x,y;
int x_qizi = 0,y_qizi = 0;
void lcd_draw_qipan()
{
    int x1,y1;
    display_bmp("./bg0.bmp",0,0);
    for(y1=0;y1<480;y1++)
    {
       for(x1=160;x1<640;x1++) 
       {
		   if((x1-401)*(x1-401)+(y1-241)*(y1-241)<=25)
            {
                lcd_draw_point(x1,y1,color[0]);
            }
       }
    }
    //外框
    lcd_draw_line(160,640,0,5,color[0]);//上边框
    lcd_draw_line(160,640,475,480,color[0]);//下边框
    lcd_draw_line(160,165,0,480,color[0]);//左边框
    lcd_draw_line(635,640,0,480,color[0]);//右边框

	//内框
	lcd_draw_line(190,610,30,35,color[0]);//上边框
    lcd_draw_line(190,610,445,450,color[0]);//下边框
    lcd_draw_line(190,195,30,450,color[0]);//左边框
    lcd_draw_line(605,610,30,450,color[0]);//右边框

	//像素点坐标左上(190,30),右下(610,450),棋盘大小15*15标准棋盘,间隔28个像素点,分辨率为420*420
	for(int i = 30;i<450;i = i+30)
	{
		for(int j = 190;j<610;j = j+30)
		{
			lcd_draw_line(j,j+3,30,450,color[0]);
			lcd_draw_line(190,610,i,i+3,color[0]);
		}
	}
}

/***
 *函数名：lcd_draw_qizi
 *功能：绘制棋子,flag = 1画白子，flag = 0,画黑子
 ***/
int lcd_draw_qizi(int flag)
{
    int i,j;

    //画棋子
    if(x>=188&&x<=612&&y>=28&&y<=452)
    {
        for(j=y-15;j<y+15;j++)
        {
            for(i=x-15;i<x+15;i++)
            {
                if((i-x)*(i-x)+(j-y)*(j-y)<=12*12)
                {
                    lcd_draw_point(i,j,color[flag]);   
                }
            }
        }
    }
    return -1;
}
/**
  *函数名：cross_point
 *功能：获取触摸位置的中心点
 */ 
void cross_point(int x0,int y0)
{
    int i,j;
    x = x0;
    y = y0;

    i = (x0-190)/30;
    j = (y0-30)/30;
    /**将画棋子的坐标定位到距离最近的一个交叉点**/
    if((x0-190)%30<15)
    {
        x = 190+30*i+1;
    }
    else
    {
        x = 190+30*(i+1)+1;
    }
    if((y0-30)%30<15)
    {
        y = 30+30*j+1;
    }
    else 
    {
        y = 30+30*(j+1)+1;
    }
}


