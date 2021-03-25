/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file            main
 * @company         成都逐飞科技有限公司
 * @author          逐飞科技(QQ790875685)
 * @version         查看doc内version文件 版本说明
 * @Software        MounRiver Studio V1.3
 * @Target core     CH32V103R8T6
 * @Taobao          https://seekfree.taobao.com/
 * @date            2020-12-04
 ********************************************************************************************************************/
//整套推荐IO查看Projecct文件夹下的TXT文本

//打开新的工程或者工程移动了位置务必执行以下操作
//右键单击工程，选择刷新

#include "headfile.h"

#define LINE_LEN                17              //数据长度
uint8 temp_buff[LINE_LEN];                      //从机向主机发送数据BUFF
int8 show_image_inMain_flage = 0;               //在主函数显示图像标志位
int8 process_image_inMain_flage = 0;               //在主函数图像处理标志位
int8 show_figure_inMain_flage = 0;               //在主函数数据显示标志位


//-------------------------------------------------------------------------------------------------------------------
//  @brief      获取传感器数据
//  @param      void
//  @return     void
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void get_sensor_data(void)
{
    //这里仅仅是提供一个模拟数据
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      根据协议处理数据
//  @param      void
//  @return     void
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void process_data(void)
{
    temp_buff[0] = 0xD8;                         //帧头
    temp_buff[1] = 0xB0;                         //功能字
    temp_buff[2] = Left_rear_speed>>8;        //数据高8位
    temp_buff[3] = Left_rear_speed&0xFF;      //数据低8位

    temp_buff[4] = 0xB1;                         //功能字
    temp_buff[5] = Right_rear_speed>>8;       //数据高8位
    temp_buff[6] = Right_rear_speed&0xFF;     //数据低8位

    temp_buff[7] = 0xB2;                         //功能字
    temp_buff[8] = target_Vx>>8;            //数据高8位
    temp_buff[9] = target_Vx&0xFF;          //数据低8位

    temp_buff[10] = 0xB3;                         //功能字
    temp_buff[11] = target_Vy>>8;            //数据高8位
    temp_buff[12] = target_Vy&0xFF;          //数据低8位

    temp_buff[13] = 0xB4;                         //功能字
    temp_buff[14] = target_Wz>>8;            //数据高8位
    temp_buff[15] = target_Wz&0xFF;          //数据低8位

    temp_buff[16] = 0xEE;                        //帧尾
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      定时器4中断服务函数
//  @param      void
//  @return     void
//  @since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void TIM4_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM4_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
        GPIO_PIN_SET(A0);                           //A0引脚拉高

        //get_sensor_data();
        get_encode();//获取传感器数据。

        process_data();                             //根据协议处理数据，并存入temp_buff中。
        uart_putbuff(UART_3, temp_buff, LINE_LEN);  //通过串口3将数据发送出去。

        GPIO_PIN_RESET(A0);                         //A0引脚拉低
        show_image_inMain_flage =0;//图像显示
        process_image_inMain_flage = 1;//图像处理
        show_figure_inMain_flage=1;//数据显示
        pit_times++;
    }
}

int main(void)
{
    DisableGlobalIRQ();
    board_init();           //务必保留，本函数用于初始化MPU 时钟 调试串口
    init();
    gpio_init(A0, GPO, 0, GPIO_PIN_CONFIG);                 //同步引脚初始化
    uart_init(UART_3, 460800, UART3_TX_B10, UART3_RX_B11);  //串口3初始化，波特率460800
    timer_pit_interrupt_ms(TIMER_4, 20);                     //定时器4初始化
    nvic_init(TIM4_IRQn, 0, 2, ENABLE);
    EnableGlobalIRQ(0);
    while(1)
    {
        if(1 == show_image_inMain_flage)
        {
            lcd_displayimage032(mt9v03x_image[0], MT9V03X_W, MT9V03X_H);
            show_image_inMain_flage=0;
        }

        if(1 == process_image_inMain_flage)
        {
            Mid_corr();
            process_image_inMain_flage=0;
        }
        if(1 == show_figure_inMain_flage)
        {
            clear_lcd_page();
            show_page();

            show_figure_inMain_flage=0;
        }
    }
}



