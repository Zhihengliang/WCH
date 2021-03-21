#include "Variable.h"
//标志位
unsigned char car_mod = 1;                      //模式1直走2横向
unsigned char display_mod = 0;                  //屏幕显示
unsigned char adjust_speed = 0;                 //调参速度
unsigned char test_time = 0;                    //测试时间
unsigned int time_count = 0;                    //计时参数
char txt[32];                                   //用于sprintf的公用字符串
//unsigned char times_palstance=0;                //角速度环计数参数

//unsigned short limit_pwm = 9999;                //限幅
//unsigned short limit_palstance = 1000;           //角速度限幅!!!
//int dx = 0;
//int dy = 0;
//int dz = 0;
////ICM积分
//int X_inte=0;                                   //前后速度
//int Y_inte=0;                                   //左右速度
//int W_inte=0;                                   //角

//short Left_front_speed = 0;                     //左前轮速度
//short Right_front_speed = 0;                    //右前轮速度
short Left_rear_speed = 0;                      //左后轮速度
short Right_rear_speed = 0;                     //右后轮速度
//short Left_front_goalspeed = 0;                 //左前轮目标速度
//short Right_front_goalspeed = 0;                //右前轮目标速度
//short Left_rear_goalspeed = 0;                  //左后轮目标速度
//short Right_rear_goalspeed = 0;                 //右后轮目标速度
////PID_V
//short P_V = 6;                                  //速度环的PID
//short I_V = 1;
//short D_V = 4;
////PID_W
//short P_W = 2;                                  //角度环的PID
//short I_W = 1;                                  //实际效果为I_W/16 !!!
//short D_W = 0;
////PID结构体
//PID pid_left_front;
//PID pid_right_front;
//PID pid_left_rear;
//PID pid_right_rear;
//PID pid_palstance;                              //角速度
//开关状态变量
uint8 key1_status = 1;
uint8 key2_status = 1;
uint8 key3_status = 1;
//uint8 key4_status = 1;
//上一次开关状态变量
uint8 key1_last_status;
uint8 key2_last_status;
uint8 key3_last_status;
//uint8 key4_last_status;
//开关标志位
uint8 key1_flag;
uint8 key2_flag;
uint8 key3_flag;
//uint8 key4_flag;
//目标速度与角速度
short target_Vx;
short target_Vy;
short target_Wz;
////结算后速度数组
//short actual_velocity[3]={0};

//查看变量
short viewvariable1=0;

//摄像头
uint8 *pic;             //储存图像的数组
uint8 image_threshold;  //图像阈值
//串口调参循环标志位
int flag_j=0;
int flag_uart[4];


int intercept_C;
int intercept_L;
int intercept_R;
int slope_C;
int slope_L;
int slope_R;

int Pixels[P_H][P_W];
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
int leftline[P_H];
int forecast_leftline[P_H];
int rightline[P_H];
int forecast_rightline[P_H];
int centerline[P_H];
int fiv_width[P_H];


int leftfindflag[P_H];
int rightfindflag[P_H];
int break_hangshu;
int flag_s;
int times;
int leftline_duan_dian;
int rightline_duan_dian;
int left_pos[P_H];
int right_pos[P_H];
int center_pos[P_H];
int lost_b_count;
int Deal_flag[P_H];//处理数据是否有效标志数组
//    lostleft_times;前n行左线未扫到的次数
//    lostright_times;前n行右线未扫到的次数
//    l_start;在l_start以下的左线全是未扫到
//    r_start;在r_start以下的右线线全是未扫到
int lostleft_times;
int lostright_times;
int l_start;
int r_start;

int rou_of_right;
int rou_of_left;

char Shi_zi_flag;                //十字标志位
int valid_line=0;               //最大有效行
int maxBline_diff;              //最大宽度
int lost_already;               //已丢线

int ring_size=0;
int ring_left_flag=0;
int ring_right_flag=0;
int ring_hang_pos=0;
int ring_lie_pos=0;
int black_point_start;
char line_lose_flag;

char left_flag=0;
char right_flag=0;
char nomal_flag=0;
