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
//  Sample usage:             Diff_center();
//-------------------------------------------------------------------------------------------------------------------
int Diff_center()
{
    int line;
    int last_line=10;
    int Diff_cen=0;
    for(line=START_Y+1;line<=last_line;line++)
    {
        Diff_cen=Diff_cen+centerline[line]-P_W/2;
    }
    Diff_cen=Diff_cen/(last_line-(START_Y+1));
    return Diff_cen;
}
