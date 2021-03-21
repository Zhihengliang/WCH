/*
 * show_somthing.c
 *
 *  Created on: 2021年3月19日
 *      Author: HP
 */
#include"show_somthing.h"

//全局变量
int8 now_show_page = 1 ;//当前页面
int8 clear_page_flag = 0 ;//清屏标志位

void show_page_1()//第一页
{
    lcd_showint16(0, 0, pit_times);
    lcd_showint16(0, 1, target_Vx);
    lcd_showint16(0, 2, target_Vy);
    lcd_showint16(0, 3, target_Wz);
}

void show_page_2()//第二页
{
    lcd_showint16(80, 1, centerline[5]);
    lcd_showint16(80, 2, centerline[6]);
    lcd_showint16(80, 3, centerline[7]);
    lcd_showint16(80, 4, centerline[8]);
    lcd_showint16(80, 5, centerline[9]);
}


void show_page_3()//第三页
{
    for(int i=0;i<MT9V03X_H;i++)
    {
        for(int j=0;j<MT9V03X_W;j++)
            {
                if(mt9v03x_image[i][j]>color_yu)
                {
                    lcd_drawpoint(j*TFT_X_MAX/MT9V03X_W,i,WHITE);
                }
                else {
                    lcd_drawpoint(j*TFT_X_MAX/MT9V03X_W,i,BLACK);
                }
            }
    }

}

void show_page_4()//第四页
{
    lcd_displayimage032(mt9v03x_image[0],MT9V03X_W,MT9V03X_H);
}
void show_page_5()//第五页
{
    for(int i=0;i<MT9V03X_H;i++)
        {

            for(int j=0;j<MT9V03X_W;j++)
                {
                    if(mt9v03x_image[i][j]>color_yu)
                    {
                        lcd_drawpoint(j*TFT_X_MAX/MT9V03X_W,i,WHITE);
                    }
                    else {
                        lcd_drawpoint(j*TFT_X_MAX/MT9V03X_W,i,BLACK);
                    }
                }
            lcd_drawpoint(centerline[MT9V03X_H-i-1]*TFT_X_MAX/MT9V03X_W,i,RED);
            lcd_drawpoint(leftline[MT9V03X_H-i-1]*TFT_X_MAX/MT9V03X_W,i,GREEN);
            lcd_drawpoint(rightline[MT9V03X_H-i-1]*TFT_X_MAX/MT9V03X_W,i,BLUE);
        }
}
void show_page_6()//第六页
{

}



void show_page()
{
    switch (now_show_page) {
        case 1:
            show_page_1();

            break;
        case 2:
            show_page_2();
            break;
        case 3:
            show_page_3();

            break;
        case 4:
            show_page_4();

            break;
        case 5:
            show_page_5();

            break;
        case 6:
            show_page_6();

            break;
        default:
            now_show_page=1;
            break;
    }
    lcd_showstr(0,7,"page");
    lcd_showint8(35,7,now_show_page);
}

void page_up()
{
    if(now_show_page < max_show_page )
        now_show_page++;
}

void page_down()
{
    if(now_show_page > 1 )
            now_show_page--;
}
void clear_lcd_page()
{
    if(clear_page_flag)
    {
    lcd_clear(WHITE);
    clear_page_flag=0;
    }
}






