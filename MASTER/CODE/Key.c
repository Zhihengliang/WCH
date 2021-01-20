#include "headfile.h"

//-------------------------------------------------------------------------------------------------------------------
//  @brief      按键
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               Key();//按键控制屏幕显示
//-------------------------------------------------------------------------------------------------------------------
void Key(void)
{
        //保存按键状态
        key1_last_status = key1_status;
        key2_last_status = key2_status;
        key3_last_status = key3_status;
//        key4_last_status = key4_status;
        //读取当前按键状态
        key1_status = gpio_get(KEY1);
        key2_status = gpio_get(KEY2);
        key3_status = gpio_get(KEY3);
//        key4_status = gpio_get(KEY4);

        //检测到按键按下之后  并放开置位标志位
        if(key1_status && !key1_last_status)    key1_flag = 1;
        if(key2_status && !key2_last_status)    key2_flag = 1;
        if(key3_status && !key3_last_status)    key3_flag = 1;
//        if(key4_status && !key4_last_status)    key4_flag = 1;

        //标志位置位之后，可以使用标志位执行自己想要做的事件
        if(key1_flag)
        {
            key1_flag = 0;//使用按键之后，应该清除标志位
            display_mod=1;
        }

        if(key2_flag)
        {
            key2_flag = 0;//使用按键之后，应该清除标志位
            display_mod=2;
        }

        if(key3_flag)
        {
            key3_flag = 0;//使用按键之后，应该清除标志位
            display_mod=3;
        }

//        if(key4_flag)
//        {
//            key4_flag = 0;//使用按键之后，应该清除标志位
//            lcd_clear(WHITE);
//        }
        //延时，按键程序应该保证调用时间不小于10ms
}

