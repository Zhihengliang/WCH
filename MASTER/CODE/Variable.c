#include "Variable.h"
//标志位
unsigned char car_mod = 1;                      //模式1直走2横向
unsigned char display_mod = 0;                  //屏幕显示
unsigned char adjust_speed = 0;                 //调参速度
unsigned char test_time = 0;                    //测试时间
unsigned int time_count = 0;                    //计时参数
char txt[32];                                   //用于sprintf的公用字符串
unsigned char times_palstance=0;                //角速度环计数参数

unsigned short limit_pwm = 9999;                //限幅
unsigned short limit_palstance = 3000;           //角速度限幅!!!
int dx = 0;
int dy = 0;
int dz = 0;
//ICM积分
int X_inte=0;                                   //前后速度
int Y_inte=0;                                   //左右速度
int W_inte=0;                                   //角

short Left_front_speed = 0;                     //左前轮速度
short Right_front_speed = 0;                    //右前轮速度
short Left_rear_speed = 0;                      //左后轮速度
short Right_rear_speed = 0;                     //右后轮速度
short Left_front_goalspeed = 0;                 //左前轮目标速度
short Right_front_goalspeed = 0;                //右前轮目标速度
short Left_rear_goalspeed = 0;                  //左后轮目标速度
short Right_rear_goalspeed = 0;                 //右后轮目标速度
//PID_V
short P_V = 15;                                  //速度环的PID
short I_V = 2;
short D_V = 0;
//PID_W
short P_W = 2;                                  //角度环的PID
short I_W = 1;                                  //实际效果为I_W/16 !!!
short D_W = 0;
//PID结构体
PID pid_left_front;
PID pid_right_front;
PID pid_left_rear;
PID pid_right_rear;
PID pid_palstance;                              //角速度
//开关状态变量
uint8 key1_status = 1;
uint8 key2_status = 1;
uint8 key3_status = 1;
uint8 key4_status = 1;
//上一次开关状态变量
uint8 key1_last_status;
uint8 key2_last_status;
uint8 key3_last_status;
uint8 key4_last_status;
//开关标志位
uint8 key1_flag;
uint8 key2_flag;
uint8 key3_flag;
uint8 key4_flag;
//目标速度与角速度
short target_Vx=0;//120
short target_Vy=0;//120
short target_Wz=0;//900
//结算后速度数组
short actual_velocity[3]={0};

//查看变量
short viewvariable1=0;

//摄像头
uint8 *pic;             //储存图像的数组
uint8 image_threshold;  //图像阈值
//串口调参循环标志位
int flag_j=0;
int flag_uart[4];
//从核目标速度
int16 slave_target_Vx = 0;                                //目标 Vx
int16 slave_target_Vy = 0;                                //目标 Vy
int16 slave_target_Wz = 0;                                //目标 Wz
