#include "headfile.h"
//-------------------------------------------------------------------------------------------------------------------
//  @brief      速度PID
//  @param      *pid     PID结构体
//  @param      actual   当前速度
//  @param      set      设定速度
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               speed_pid(pid_left_front, actual, set);//左前轮当前速度actual设定速度set的PID
//-------------------------------------------------------------------------------------------------------------------
void speed_pid(PID *pid, short actual, short set ) {
	int p = 0, i = 0, d = 0;
	pid->err = set - actual;
	p = pid->err - pid->last_err;
	i = pid->err;
	d = pid->err - 2 * pid->last_err + pid->last_last_err;
	pid->result += pid->kp * p + pid->ki * i + pid->kd * d;
	//输出限幅
	if (pid->result > limit_pwm)
		pid->result = limit_pwm;
	else if (pid->result < -limit_pwm)
		pid->result = -limit_pwm;
	pid->last_last_err = pid->last_err;
	pid->last_err = pid->err;
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      角速度PID
//  @param      *pid     PID结构体
//  @param      actual   当前角速度
//  @param      set      设定角速度
//  @return     void
//  @since      v1.0
//  @autor      SWG
//  Sample usage:               palstance_pid(&pid_palstance, icm_gyro_z - 8, set);//左前轮当前速度actual设定速度set的PID
//-------------------------------------------------------------------------------------------------------------------
void palstance_pid(PID *pid, short actual, short set ) {
    if(0!=set)
    {
        if(times_palstance<=0)
        {
            times_palstance=2;
            int p = 0, i = 0, d = 0;
            pid->err = set - actual;
            p = pid->err - pid->last_err;
            i = (pid->err)>>4;//除16
            d = pid->err - 2 * pid->last_err + pid->last_last_err;
            pid->result += pid->kp * p + pid->ki * i + pid->kd * d;//角速度环结果
            if (pid->result > limit_palstance)
                pid->result = limit_palstance;
            else if (pid->result < -limit_palstance)
                pid->result = -limit_palstance;
            pid->last_last_err = pid->last_err;
            pid->last_err = pid->err;
        }
        else times_palstance--;
    }
    else
    {
        pid->result = 0;
        pid->err=0;
        pid->last_err=0;
        pid->last_last_err=0;
    }
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      速度解算
//  @param      Vx       前后速度
//  @param      Vy       横向速度
//  @param      Vz       旋转速度
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               speed_conversion(1, 1, 1);//前进，向右，逆时针旋转速度都为1
//-------------------------------------------------------------------------------------------------------------------
void speed_conversion(double Vx, double Vy, int Vz) {
	Left_rear_goalspeed = (int)(-Vx + Vy - Vz * 0.18);
	Left_front_goalspeed = (int)(+Vx + Vy - Vz * 0.18);
	Right_front_goalspeed = (int)(-Vx + Vy + Vz * 0.18);
	Right_rear_goalspeed = (int)(+Vx + Vy + Vz * 0.18);
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      PID初始化
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang and SWG
//  Sample usage:               Pid_Init();
//-------------------------------------------------------------------------------------------------------------------
void Pid_Init(void)
{
  pid_left_front.kp=P_V;
  pid_left_front.ki=I_V;
  pid_left_front.kd=D_V;

  pid_right_front.kp=P_V;
  pid_right_front.ki=I_V;
  pid_right_front.kd=D_V;

  pid_left_rear.kp=P_V;
  pid_left_rear.ki=I_V;
  pid_left_rear.kd=D_V;

  pid_right_rear.kp=P_V;
  pid_right_rear.ki=I_V;
  pid_right_rear.kd=D_V;

  pid_palstance.kp=P_W;
  pid_palstance.ki=I_W;
  pid_palstance.kd=D_W;

  pid_left_front.err=0;
  pid_left_front.last_err=0;
  pid_left_front.last_last_err=0;
  pid_left_front.result=0;

  pid_right_front.err=0;
  pid_right_front.last_err=0;
  pid_right_front.last_last_err=0;
  pid_right_front.result=0;


  pid_left_rear.err=0;
  pid_left_rear.last_err=0;
  pid_left_rear.last_last_err=0;
  pid_left_rear.result=0;

  pid_right_rear.err=0;
  pid_right_rear.last_err=0;
  pid_right_rear.last_last_err=0;
  pid_right_rear.result=0;

  pid_palstance.err=0;
  pid_palstance.last_err=0;
  pid_palstance.last_last_err=0;
  pid_palstance.result=0;


}
