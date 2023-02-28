#include "qizi.h"
#include "bmp.h"

int a[15][15] = {0};//用记住黑棋和白棋
int b[15][15] = {0};//用于记住步数
int count = 1;
int sum = 1;
int real = 0;
extern int x;
extern int y;
int k,l;

int pd()//黑棋先手,可以写个判断
{
    //printf("%d\n",y);
    //printf("%d\n",x);
    k=(y-31)/30;
    l=(x-191)/30;
    //printf("%d\n",k);
    //printf("%d\n",l);
    if(a[k][l] == 0)
    {
        if(count == 1)
        {
            a[k][l] = 1;
            count = 2;
            b[k][l] = sum;
            sum++;
            
        }
        else if(count == 2)
        {
            a[k][l] = 2;
            count = 1;
            b[k][l] = sum;
            sum++;
        }
        return 1;
    }    
    else 
    {
        printf(" chess!!!\n");
        return -1;
    }
}
/**
 *函数名：pd_win
 *功能：判断是否连成五颗
*/ 
int pd_win()
{
    //printf("a\n");
    for (int i = 0; i < 5; i++)//在竖直方向上寻找
    {
        if(a[k+i][l] ==  a[k][l])
        {
            real++;
            if(real == 5)
            {
                real = 0;
                return a[k][l];
                break;
            }
        }
        else 
        {
            break;
        }
    }
    for (int i = 1; i < 5; i++)
    {
        if(a[k-i][l] ==  a[k][l])
        {
            real++;
            if(real == 5)
            {
                real = 0;
                return a[k][l];
                break;
            }
        }
        else 
        {
            break;
        }
    }
    real = 0;

    for (int i = 0; i < 5; i++)//在水平方向上寻找
    {
        if(a[k][l+i] ==  a[k][l])
        {
            real++;
            if(real == 5)
            {
                real = 0;
                return a[k][l];
                break;
            }
        }
        else 
        {
            break;
        }
    }
    for (int i = 1; i < 5; i++)
    {
        if(a[k][l-i] ==  a[k][l])
        {
            real++;
            if(real == 5)
            {
                real = 0;
                return a[k][l];
                break;
            }
        }
        else 
        {
            break;
        }
    }
    real = 0;

     for (int i = 0; i < 5; i++)//在二四象限找
    {
        if(a[k+i][l+i] ==  a[k][l])
        {
            real++;
            if(real == 5)
            {
                real = 0;
                return a[k][l];
                break;
            }
        }
        else 
        {
            break;
        }
    }
    for (int i = 1; i < 5; i++)
    {
        if(a[k-i][l-i] ==  a[k][l])
        {
            real++;
            if(real == 5)
            {
                real = 0;
                return a[k][l];
                break;
            }
        }
        else 
        {
            break;
        }
    }
    real = 0;

    for (int i = 0; i < 5; i++)//在一三象限找
    {
        if(a[k-i][l+i] ==  a[k][l])
        {
            real++;
            if(real == 5)
            {
                real = 0;
                return a[k][l];
                break;
            }
        }
        else 
        {
            break;
        }
    }

    for(int i = 1; i < 5; i++)
    {    if(a[k+i][l-i] ==  a[k][l])
        {
            real++;
            if(real == 5)
            {
                real = 0;
                return a[k][l];
                break;
            }
            
        }
        else 
        {
            break;
        }
    }
    real = 0;
}

void hq()
{
    a[k][l] = 0;
    b[k][l] = 0;
    sum--;
    if(count == 1)
    {
        count = 2;
    }
    else if(count == 2)
    {
        count = 1;
    }
}

int win(int p)
{
    //printf("b\n");
    if(p == 2)
    {
        printf("whilte win!!!\n");
        sleep(1);
        display_bmp("vic1.bmp",0,0);
        return -1;
    }
    else if(p == 1)
    {
        printf("balck win!!!\n");
        sleep(1);
        display_bmp("vic0.bmp",0,0);
        return -1;
    }
}

