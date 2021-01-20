#include "headfile.h"
//-------------------------------------------------------------------------------------------------------------------
//  @brief      测试子程序运行时间
//  @param      stmn            选择使用的模块
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               time_count(void)//运用0通道
//-------------------------------------------------------------------------------------------------------------------
void time_count_test(void){
    int use_time = 0;
    systick_start();//开始计时
    //填写运行的子程序

    //填写运行的子程序
    use_time = systick_getval();         //获取计时时间
    sprintf(txt, "time : %05d; ", use_time);    //显示计算时长
    lcd_showstr(0, 0, txt);
}
