#include "headfile.h"
//-------------------------------------------------------------------------------------------------------------------
//  @brief      数据采集
//  @param      PIC_W 采集范围的宽
//  @param      PIC_H 采集范围的高
//    1、左线值：lefetline
//    2、右线值：rightline
//    3、中线值：centerline
//    4、每行赛道宽度：fiv_width
//    5、每行左线点是否扫到：leftfindflag
//    6、每行右线点是否扫到：rightfindflag
//    7、中线断开的目标行：break_hangshu
//    8、P_H以内两边都扫到的次数：flag_s
//    9、P_H以内两边全丢的次数：times
//    10、20行以上左线突然性断裂的目标行：leftline_duan_dian
//    11、20行以上右线突然性断裂的目标行：rightline_duan_dian
//  @since      v1.0
//  Sample usage:             data_collection(PIC_W,PIC_H);
//-------------------------------------------------------------------------------------------------------------------
int old=P_W/2;
void data_collection(int PIC_W, int PIC_H)
{
    int i=0;
    int j=0;

    for (j = 0; j < PIC_H; j++)//???
    {
     for (i = old; i >= 0 && i < PIC_W-1; i--)
     {
         fiv_width[j]++;
         if (Pixels[PIC_H-j-1][ i + 1] < color_yu && Pixels[PIC_H-j-1][ i] < color_yu)
         {
             leftfindflag[j] = 1;
             leftline[j] = (i + 1);
             break;
         }

     }
     for (i = old; i <= PIC_W && i > 1; i++)
     {
         fiv_width[j]++;
         if (Pixels[PIC_H-j-1][ i - 1] < color_yu && Pixels[PIC_H-j-1][ i] < color_yu)//？？？
         {
             rightfindflag[j]  = 1;
             rightline[j] = (i - 1);
             break;
         }
     }
     if (j <= P_H&& leftfindflag[j] == 1 && rightfindflag[j] == 1) flag_s++;
     if (j <= P_H&& leftfindflag[j] == 0 && rightfindflag[j] == 0) times++;
     if (j >= 20 && (leftline[j] - leftline[j - 1]) >= 20) leftline_duan_dian = j;
     if (j >= 20 && (rightline[j] - rightline[j - 1]) <= -20) rightline_duan_dian = j;
     centerline[j] = ((leftline[j] + rightline[j]) / 2);
     if ((Pixels[PIC_H-j-1][ centerline[j]]) < color_yu && (Pixels[PIC_H-j-2][ centerline[j]]) < color_yu)//???
     {
         break_hangshu = j;
         //printf("%d",break_hangshu);
         //last_break_hangshu = break_hangshu;
         //也就是说二十行一下是不会break的
         if (break_hangshu >= 20)    //防止在一开始就break
         {
             //printf("%d",break_hangshu);
             break;
         }
     }
     old = centerline[j];
    }
    old = centerline[5];    //初次扫线完毕，将old重新赋值


}
