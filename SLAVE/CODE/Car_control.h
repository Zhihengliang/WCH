#ifndef __CAR_CONTROL_H_
#define __CAR_CONTROL_H_
#include "headfile.h"

//#define LEFT_FRONT_PWM     B6
//#define LEFT_FRONT_DIR     C10
//#define RIGHT_FRONT_PWM    B7
//#define RIGHT_FRONT_DIR    C11
//#define LEFT_REAR_PWM      B8
//#define LEFT_REAR_DIR      B12
//#define RIGHT_REAR_PWM     B9
//#define RIGHT_REAR_DIR     A8
//
//#define LEFT_FRONT_GPT     TIMER_2
//#define RIGHT_FRONT_GPT    TIMER_3
#define LEFT_REAR_GPT      TIMER_2
#define RIGHT_REAR_GPT     TIMER_3

//#define LEFT_FRONT_GPT_P   TIMER2_CHA_A15
//#define RIGHT_FRONT_GPT_P  TIMER3_CHA_B4
#define LEFT_REAR_GPT_P    TIMER2_CHA_A15
#define RIGHT_REAR_GPT_P   TIMER3_CHA_B4

//#define LEFT_FRONT_GPT_N   TIMER2_CHB_B3
//#define RIGHT_FRONT_GPT_N  TIMER3_CHB_B5
#define LEFT_REAR_GPT_N    TIMER2_CHB_B3
#define RIGHT_REAR_GPT_N   TIMER3_CHB_B5


//void Left_front_pwm_set1(int Left_frontvalue);
//void Right_front_pwm_set1(int Right_frontvalue);
//void Left_rear_pwm_set1(int Left_rearvalue);
//void Right_rear_pwm_set1(int Right_rearvalue);

extern void get_encode(void);


#endif /* __CAR_CONTROL_H_ */
