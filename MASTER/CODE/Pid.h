#ifndef __PID_H_
#define __PID_H_
#include "headfile.h"

//定义结构体
typedef struct
{
	int err;
	int last_err;
	int last_last_err;
	int kp,ki,kd;
	int result;
}PID;

void speed_pid(PID *pid, short actual, short set);
void palstance_pid(PID *pid, short actual, short set);
void speed_conversion(double Vx, double Vy, int Vz);
void Pid_Init(void);
#endif /* __PID_H_ */
