#ifndef ___VARIABLE_H_
#define ___VARIABLE_H_


#include "headfile.h"

extern unsigned char car_mod;        //模式1直走2横向
extern unsigned char display_mod;
extern unsigned char adjust_speed;
extern unsigned char test_time;
extern unsigned int time_count;
extern char txt[32];
//extern unsigned char times_palstance;

#define left 0
#define right 1
#define front 2


#define P_W MT9V03X_W
#define P_H MT9V03X_H
#define Pixels mt9v03x_image
#define MAX_CENTER_POINT_COUNT 25 //最大的中心线点数
#define MAX_LINE_POINT_COUNT   60 //一条线最大的点数
#define MIN_LINE_POINT_COUNT   5 //一条线最小的点数
#define BREAKPOINT             40 //近处的道和远处的道路分界点

#define RATE_COUNT         8  //找拐点时候比较的点数

#define JUDGE_DIFF 10   //判断黑线是否有效斜率判断差值
#define INVALID_LINE 3  //左或右丢线
#define DEAL_LEFT_LOST 1  //左边丢线
#define DEAL_RIGHT_LOST 2  //右边丢线
#define VALID_LINE 0  //没丢线

//下边是用于梯形矫正的公式及常量的宏
//把车放在直道上，数出最下边的白色点数给 DOWN_EDGE 赋值
//改变 UP_EDGE 的值，是彩屏上显示的还原的线接近平行，说明矫正成功
#define DOWN_EDGE 150   //图像下边沿的像素点个数
#define UP_EDGE   150   //在与图像下边沿所表示的等长的距离在图形上边沿所占的像素点个数

#define START_Y  5

#define FILL_LEN 70 //用于补全丢失的线
//速度相关数据
//extern unsigned short limit_pwm;
//extern unsigned short limit_palstance;
//
//extern short pre_speed;
//extern short line_speed;
//extern short near_speed;
//extern short avoid_xspeed;
//
//extern int dx;
//extern int dy;
//extern int dz;
//
//extern int X_inte;
//extern int Y_inte;
//extern int W_inte;

//extern short Left_front_speed;
//extern short Right_front_speed;
extern short Left_rear_speed;
extern short Right_rear_speed;

//extern short Left_front_goalspeed;
//extern short Right_front_goalspeed;
//extern short Left_rear_goalspeed;
//extern short Right_rear_goalspeed;
////PID_V
//extern short P_V;
//extern short I_V;
//extern short D_V;
////PID_W
//extern short P_W;
//extern short I_W;
//extern short D_W;
////PID结构体
//extern PID pid_left_front;
//extern PID pid_right_front;
//extern PID pid_left_rear;
//extern PID pid_right_rear;
//extern PID pid_palstance;
//开关状态变量
extern uint8 key1_status;
extern uint8 key2_status;
extern uint8 key3_status;
//extern uint8 key4_status;
//上一次开关状态变量
extern uint8 key1_last_status;
extern uint8 key2_last_status;
extern uint8 key3_last_status;
//extern uint8 key4_last_status;
//开关标志位
extern uint8 key1_flag;
extern uint8 key2_flag;
extern uint8 key3_flag;
//extern uint8 key4_flag;
//目标速度与角速度
extern short target_Vx;
extern short target_Vy;
extern short target_Wz;
////结算后速度数组
//extern short actual_velocity[3];
//查看变量
extern short viewvariable1;
//摄像头
extern uint8 *pic;
extern uint8 image_threshold;
extern int flag_j;
extern int flag_uart[4];



extern int intercept_C;
extern int intercept_L;
extern int intercept_R;
extern int slope_C;
extern int slope_L;
extern int slope_R;

//    1、左线值：lefetline
//    2、右线值：rightline
//    3、中线值：centerline
//    4、每行赛道宽度：fiv_width
//    5、每行左线点是否扫到：leftfindflag
//    6、每行右线点是否扫到：rightfindflag
//    7、中线断开的目标行：break_hangshu
//    8、50行以内两边都扫到的次数：flag_s
//    9、25行以内两边全丢的次数：times
//    10、20行以上左线突然性断裂的目标行：leftline_duan_dian
//    11、20行以上右线突然性断裂的目标行：rightline_duan_dian
//    12、保存左线位置：left_pos
//    13、保存右线位置：right_pos
//    14、这次与上一次都没扫到判定为丢线：lost_b_count
extern int leftline[P_H];
extern int forecast_leftline[P_H];
extern int rightline[P_H];
extern int forecast_rightline[P_H];
extern int centerline[P_H];
extern int fiv_width[P_H];
extern int leftfindflag[P_H];
extern int rightfindflag[P_H];
extern int break_hangshu;
extern int flag_s;
extern int times;
extern int leftline_duan_dian;
extern int rightline_duan_dian;
extern int left_pos[P_H];    //左边线存放数组
extern int right_pos[P_H];   //右边线存放数组
extern int center_pos[P_H];  //中心线存放数组
extern int lost_b_count;
extern int Deal_flag[P_H];//处理数据是否有效标志数组
//    lostleft_times;前n行左线未扫到的次数
//    lostright_times;前n行右线未扫到的次数
//    l_start;在l_start以下的左线全是未扫到
//    r_start;在r_start以下的右线线全是未扫到
extern int lostleft_times;
extern int lostright_times;
extern int l_start;
extern int r_start;


extern int rou_of_right;
extern int rou_of_left;

extern char Shi_zi_flag;                //十字标志位
extern int valid_line;                 //最大有效行
extern int maxBline_diff;              //最大宽度
extern int lost_already;               //已丢线

extern int ring_size;
extern int ring_left_flag;
extern int ring_right_flag;
extern int ring_hang_pos;
extern int ring_lie_pos;
extern int black_point_start;
extern char line_lose_flag;

extern char left_flag;
extern char right_flag;
extern char nomal_flag;
extern short pit_times ;
#endif/* ___VARIABLE_H_ */
