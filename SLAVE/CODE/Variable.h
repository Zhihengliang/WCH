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
////目标速度与角速度
//extern short target_Vx;
//extern short target_Vy;
//extern short target_Wz;
////结算后速度数组
//extern short actual_velocity[3];
//查看变量
extern short viewvariable1;
//摄像头
extern uint8 *pic;
extern uint8 image_threshold;
extern int flag_j;
extern int flag_uart[4];
#endif/* ___VARIABLE_H_ */
