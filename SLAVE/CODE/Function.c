#include "headfile.h"
//-------------------------------------------------------------------------------------------------------------------
//  @brief      TFT、测速、PWM、串口、PID、PIT初始化，按键
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               init();//初始化
//-------------------------------------------------------------------------------------------------------------------
void init(void) {
	//TFT初始化
	lcd_init();
	//摄像头初始化
	mt9v03x_init();
	//按钮中断初始化
	gpio_interrupt_init(C9, FALLING, GPIO_INT_CONFIG);
	gpio_interrupt_init(C8, FALLING, GPIO_INT_CONFIG);
	nvic_init(EXTI9_5_IRQn, 0, 1, ENABLE);                //EXTI9_5_IRQn优先级配置，抢占优先级0，次优先级1

	//测速初始化
//	timer_quad_init(LEFT_FRONT_GPT, LEFT_FRONT_GPT_P, LEFT_FRONT_GPT_N);
//	timer_quad_init(RIGHT_FRONT_GPT, RIGHT_FRONT_GPT_P, RIGHT_FRONT_GPT_N);
	timer_quad_init(LEFT_REAR_GPT, LEFT_REAR_GPT_P, LEFT_REAR_GPT_N);
	timer_quad_init(RIGHT_REAR_GPT, RIGHT_REAR_GPT_P, RIGHT_REAR_GPT_N);
//	//PWM方向初始化
//	gpio_init(LEFT_FRONT_DIR, GPO, 0, GPIO_PIN_CONFIG);
//    gpio_init(RIGHT_FRONT_DIR, GPO, 0, GPIO_PIN_CONFIG);
//    gpio_init(LEFT_REAR_DIR, GPO, 0, GPIO_PIN_CONFIG);
//    gpio_init(RIGHT_REAR_DIR, GPO, 0, GPIO_PIN_CONFIG);
////    gpio_init(LEFT_FRONT_DIR, GPO, 1, PUSHPULL);
////    gpio_init(RIGHT_FRONT_DIR, GPO, 1, PUSHPULL);
////    gpio_init(LEFT_REAR_DIR, GPO, 1, PUSHPULL);
////    gpio_init(RIGHT_REAR_DIR, GPO, 1, PUSHPULL);
//	//PWM初始化
//    pwm_init(LEFT_FRONT_PWM, 12500, 0);
//    pwm_init(RIGHT_FRONT_PWM, 12500, 0);
//    pwm_init(LEFT_REAR_PWM, 12500, 0);
//    pwm_init(RIGHT_REAR_PWM, 12500, 0);

//	//adc初始化
//    ind_init();

//	//ICM20602初始化
//	icm20602_init_spi();

	//串口初始化
	uart_init(UART_1,115200,UART1_TX_A9,UART1_RX_A10);
    //主机——>从机
    uart_init(UART_3,115200,UART3_TX_B10,UART3_RX_B11);

	//摄像头初始化
//	mt9v03x_init();

	//PID参数初始化
//	Pid_Init();

	//PIT初始化（定时器1）
//	timer_pit_interrupt_ms(TIMER_1, 50);
//	pit_interrupt_ms(CCU6_0, PIT_CH0, 10);

    //按键初始化(暂时关闭)
    /*
    gpio_init(KEY1, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(KEY2, GPO, 0, GPIO_PIN_CONFIG);
    gpio_init(KEY3, GPO, 0, GPIO_PIN_CONFIG);
    */
//    gpio_init(KEY1,GPI,0,PULLUP);
//    gpio_init(KEY2,GPI,0,PULLUP);
//    gpio_init(KEY3,GPI,0,PULLUP);
//    gpio_init(KEY4,GPI,0,PULLUP);


}
////-------------------------------------------------------------------------------------------------------------------
////  @brief      显示速度
////  @return     void
////  @since      v1.0
////  @autor      Zhiheng Liang
////  Sample usage:               display_speed();//屏幕显示速度
////-------------------------------------------------------------------------------------------------------------------
//void display_speed(void) {
//
//	sprintf(txt, "LF: %05d; ", Left_front_speed);
//	lcd_showstr(0, 0, txt);
//
//	sprintf(txt, "RF: %05d; ", Right_front_speed);
//	lcd_showstr(0, 1, txt);
//
//	sprintf(txt, "LR: %05d; ", Left_rear_speed);
//	lcd_showstr(0, 2, txt);
//
//	sprintf(txt, "RR: %05d;", Right_rear_speed);
//	lcd_showstr(0, 3, txt);
//
//}
////-------------------------------------------------------------------------------------------------------------------
////  @brief      显示角速度、加速度
////  @return     void
////  @since      v1.0
////  @autor      Zhiheng Liang
////  Sample usage:               display_icm();//屏幕显示角速度、加速度
////-------------------------------------------------------------------------------------------------------------------
//void display_icm(void) {
//
//    sprintf(txt, "AX: %05d; ", icm_acc_x);
//    lcd_showstr(0, 0, txt);
//
//    sprintf(txt, "AY: %05d; ", icm_acc_y);
//    lcd_showstr(0, 1, txt);
//
//    sprintf(txt, "WZ: %05d; ", icm_gyro_z);
//    lcd_showstr(0, 2, txt);
//
//    sprintf(txt, "AZ: %05d; ", icm_acc_z);
//    lcd_showstr(0, 3, txt);
//
//    sprintf(txt, "WX: %05d; ", icm_gyro_x);
//    lcd_showstr(0, 4, txt);
//
//    sprintf(txt, "WY: %05d; ", icm_gyro_y);
//    lcd_showstr(0, 5, txt);
//}
////-------------------------------------------------------------------------------------------------------------------
////  @brief      显示角速度、加速度积分
////  @return     void
////  @since      v1.0
////  @autor      Zhiheng Liang
////  Sample usage:               display_icm_inte();//屏幕显示角速度、加速度积分
////-------------------------------------------------------------------------------------------------------------------
//void display_icm_inte(void) {
//
//    sprintf(txt, "AX: %05d; ", X_inte);
//    lcd_showstr(0, 0, txt);
//
//    sprintf(txt, "AY: %05d; ", Y_inte);
//    lcd_showstr(0, 1, txt);
//
//    sprintf(txt, "WV: %05d; ", W_inte);
//    lcd_showstr(0, 2, txt);
//}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      显示哪一部分
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               display();//屏幕显示1模式
//-------------------------------------------------------------------------------------------------------------------
void display(void) {
    if(display_mod == 1){
//        display_speed();                                 //屏幕显示速度
    }else if(display_mod == 2){
//        display_icm();                                   //屏幕显示角速度、加速度
    }else if(display_mod == 3){
//        display_icm_inte();                              //屏幕显示角速度、加速度积分
    }
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      数组逆序
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               void nixu(int a,int b,int R[]) ;
//-------------------------------------------------------------------------------------------------------------------
//将一个数组从下标a到b逆序排列,以交换数据得以实现
void nixu(int a,int b,int R[]) {
	int k,t = (a + b)/2;
	for (int i = a,j = 0; i <= t; i++,j++) {
		k = R[i];
		R[i] = R[b - j];
		R[b - j] = k;
	}
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      开平方根
//  @param      x
//  @since      v1.0
//  Sample usage:             my_sqrt(x);
//-------------------------------------------------------------------------------------------------------------------
unsigned int my_sqrt(unsigned int x)
{
    unsigned char ans=0,p=0x80;
    while(p!=0)
    {
        ans+=p;
        if(ans*ans>x)
        {
            ans-=p;
        }
        p=(unsigned char)(p/2);
    }
    return(ans);
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      两个无符号数相减的绝对值
//  @param      diff1,diff2
//  @since      1.0
//  Sample usage:             abs_sub(x);
//-------------------------------------------------------------------------------------------------------------------

unsigned int abs_sub(unsigned int diff1,unsigned int diff2)
{
    unsigned int temp;
    if(diff1>diff2)
    {
        temp=diff1-diff2;
    }
    else
    {
        temp=diff2-diff1;
    }
    return temp;
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      曲率计算
//  @param      x
//  @param      y
//  @return     float K 曲率
//  @since      v1.0
//  Sample usage:             process_curvity(x1, y1, x2, y2, x3,y3);
//-------------------------------------------------------------------------------------------------------------------
float process_curvity(short x1, short y1, short x2, short y2, short x3, short y3)
{
    float K;
   //曲率
    int S_of_ABC = ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2;
    //面积的符号表示方向
    short q1 = (short)((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    short AB = my_sqrt(q1);
    q1 = (short)((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    short BC = my_sqrt(q1);
    q1 = (short)((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    short AC = my_sqrt(q1);
    if (AB * BC * AC == 0)
    {
        K = 0;
    }
    else
        K = (float)4 * S_of_ABC / (AB * BC * AC);
    return K;
}
