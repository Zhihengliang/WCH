#include "headfile.h"
//-------------------------------------------------------------------------------------------------------------------
//  @brief      斜率平均值
//  @param      void
//  @since      1.0
//  Sample usage:             Slope_center();
//-------------------------------------------------------------------------------------------------------------------
int Slope_center()
{
    int line;
    int last_line=10;
    int Slope_cen=0;
    for(line=START_Y+1;line<=last_line;line++)
    {
        Slope_cen=Slope_cen+centerline[line]-centerline[line-1];
    }
    Slope_cen=Slope_cen/(last_line-(START_Y+1));
    return Slope_cen;
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      扫描中线与实际中线平均值
//  @param      void
//  @since      1.0
//  Sample usage:             Diff_center(bias_cen);
//-------------------------------------------------------------------------------------------------------------------
int Diff_center(short bias_cen)
{
    int line;
    int last_line=10;
    int Diff_cen=0;
    for(line=START_Y+1;line<=last_line;line++)
    {
        Diff_cen=Diff_cen+bias_cen+centerline[line]-P_W/2;
    }
    Diff_cen=Diff_cen/(last_line-(START_Y+1));
    return Diff_cen;
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      模式识别（伪）
//  @since      v1.0
//  Sample usage:              mode_recogn(10,20,30);
//-------------------------------------------------------------------------------------------------------------------
void mode_recogn(char line_1,char line_2,char line_3)
{
//    char line_1=10;
//    char line_2=20;
//    char line_3=30;
    float curv_l=0;
    float curv_r=0;
    curv_l=process_curvity(line_1, leftline[line_1], line_2, leftline[line_2], line_3, leftline[line_3]);
    curv_r=process_curvity(line_1, rightline[line_1], line_2, rightline[line_2], line_3, rightline[line_3]);
    if(curv_l>0&&curv_r>0)
    {
        left_flag=1;
    }
    else if(curv_l<0&&curv_r<0)
    {
        right_flag=1;
    }
    else if(curv_l==0&&curv_r==0)
    {
        nomal_flag=1;
        right_flag=0;
        left_flag=0;
        Shi_zi_flag=0;
    }
    if(10<=times)
    {
        Shi_zi_flag=1;
        nomal_flag=1;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      中线矫正（增加偏置：常量式）
//  @param      void
//  @since      1.0
//  Sample usage:             Mid_corr();
//-------------------------------------------------------------------------------------------------------------------
void Mid_corr()
{
    ctrl_main();
    mode_recogn(10,20,30);
    if(left_flag==1)
    {
        image_center(60,20);
    }
    else if(right_flag)
    {
        image_center(60,-10);
    }
    else if(nomal_flag)
    {
        image_center(60,10);
        if(Shi_zi_flag)
        {
            target_Wz=0;
        }
    }
}
