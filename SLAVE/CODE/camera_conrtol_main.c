#include "headfile.h"
//-------------------------------------------------------------------------------------------------------------------
//  @brief      参数清零
//  @since      v1.0
//  Sample usage:             clearDelPar();
//-------------------------------------------------------------------------------------------------------------------
void clearDelPar()
{
    lost_already=0;
    maxBline_diff=0;
    Shi_zi_flag=0;
    times=0;
    valid_line=0;

    ring_size=0;
    ring_left_flag=0;
    ring_right_flag=0;

}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      图像总体控制
//  @since      v1.0
//  Sample usage:             ctrl_main();
//-------------------------------------------------------------------------------------------------------------------
void ctrl_main()
{
    int line;
    //图像采集部分，找到两条边线
    clearDelPar();//清零处理参数
    for(line=0;line<P_H;line++)//存放边线中线数组清零
    {
        leftline[line]=0;
        rightline[line]=P_W-1;
        Deal_flag[line]=0;//处理标志清零i
        left_pos[line]=0;
        right_pos[line]=P_W-1;
        center_pos[line]=0;
    }
    data_collection(P_W,P_H);
    for(line=START_Y+2;line<P_H;line++) //提取各行中心点并处理意外
    {

        //收集环路所需要的坐标
        left_pos[line]=leftline[line];//保存左边的坐标
        right_pos[line]=rightline[line];//保存右边的坐标
//有效行判断
        if((leftfindflag[line]==0)||(rightfindflag[line]==0))
          {
              if((leftfindflag[line-1]==0)||(rightfindflag[line-1]==0))
                  lost_b_count++;
          }
          if(line<50)
          {
              if(maxBline_diff<fiv_width[line])
                  maxBline_diff=fiv_width[line];
          }
          if(lost_already==0)
          {
              if((lost_b_count>3||(leftline[line]<5)||(rightline[line]>(P_W-5)))&&valid_line==0)
              {
                  lost_already=1;
                  valid_line=line-3;
              }
          }
        if(line==P_H-1&&valid_line==0)
        {
            valid_line=P_H-1-lost_b_count;
        }
     }
}

