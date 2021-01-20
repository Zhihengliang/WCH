#include "headfile.h"
//-------------------------------------------------------------------------------------------------------------------
//  @brief      左前轮pwm
//  @param      Left_frontvalue     左前轮pwm值
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               Left_front_pwm_set1(12500);//左前轮PWM12500正转
//-------------------------------------------------------------------------------------------------------------------
void Left_front_pwm_set1(int Left_frontvalue) {
	if (Left_frontvalue <= 0) {
		pwm_duty(LEFT_FRONT_PWM, -Left_frontvalue);
		gpio_set(LEFT_FRONT_DIR, 0);
	} else {
        pwm_duty(LEFT_FRONT_PWM, Left_frontvalue);
        gpio_set(LEFT_FRONT_DIR, 1);
	}
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      右前轮pwm
//  @param      Right_frontvalue     右前轮pwm值
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               Right_front_pwm_set1(12500);//右前轮PWM12500正转
//-------------------------------------------------------------------------------------------------------------------
void Right_front_pwm_set1(int Right_frontvalue) {
	if (Right_frontvalue <= 0) {
		pwm_duty(RIGHT_FRONT_PWM, -Right_frontvalue);
		gpio_set(RIGHT_FRONT_DIR, 1);
	} else {
        pwm_duty(RIGHT_FRONT_PWM, Right_frontvalue);
        gpio_set(RIGHT_FRONT_DIR, 0);
	}
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      左后轮pwm
//  @param      Left_rearvalue     左后轮pwm值
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               Left_rear_pwm_set1(12500);//左后轮PWM12500正转
//-------------------------------------------------------------------------------------------------------------------
void Left_rear_pwm_set1(int Left_rearvalue) {
	if (Left_rearvalue <= 0) {
		pwm_duty(LEFT_REAR_PWM, -Left_rearvalue);
		gpio_set(LEFT_REAR_DIR, 0);
	} else {
        pwm_duty(LEFT_REAR_PWM, Left_rearvalue);
        gpio_set(LEFT_REAR_DIR, 1);
	}
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      右后轮pwm
//  @param      Right_rearvalue     右后轮pwm值
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               Right_rearvalue(12500);//右后轮PWM12500正转
//-------------------------------------------------------------------------------------------------------------------
void Right_rear_pwm_set1(int Right_rearvalue) {
	if (Right_rearvalue <= 0) {
		pwm_duty(RIGHT_REAR_PWM, -Right_rearvalue);
		gpio_set(RIGHT_REAR_DIR, 1);
	} else {
        pwm_duty(RIGHT_REAR_PWM, Right_rearvalue);
        gpio_set(RIGHT_REAR_DIR, 0);
	}
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      测速与PID控制，输出PWM,获取陀螺仪
//  @return     void
//  @since      v1.0
//  @autor      Zhiheng Liang
//  Sample usage:               get_encode();//测速与PID控制，输出PWM,获取陀螺仪
//-------------------------------------------------------------------------------------------------------------------
void get_encode(void){
    //测速
    Left_front_speed = -timer_quad_get(LEFT_FRONT_GPT);
    timer_quad_clear(LEFT_FRONT_GPT);
    Right_front_speed = timer_quad_get(RIGHT_FRONT_GPT);
    timer_quad_clear(RIGHT_FRONT_GPT);
//    Left_rear_speed = -timer_quad_get(LEFT_REAR_GPT);
//    timer_quad_clear(LEFT_REAR_GPT);
//    Right_rear_speed = timer_quad_get(RIGHT_REAR_GPT);
//    timer_quad_clear(RIGHT_REAR_GPT);
    dx += (Right_front_speed-Right_rear_speed)/2;
    dy += (Left_rear_speed+Right_rear_speed+Left_front_speed+Right_front_speed)/4;
    dz += (Right_front_speed+Right_rear_speed-Left_front_speed-Left_rear_speed);

    //获取ICM20602
    get_icm20602_accdata_spi();
    get_icm20602_gyro_spi();
    X_inte = X_inte + icm_acc_x ;
    Y_inte = Y_inte + icm_acc_y ;
    W_inte = W_inte + icm_gyro_z - 9;


    //PID计算
    speed_pid(&pid_left_front, Left_front_speed, Left_front_goalspeed);
    speed_pid(&pid_right_front, Right_front_speed, Right_front_goalspeed);
    speed_pid(&pid_left_rear, Left_rear_speed, Left_rear_goalspeed);
    speed_pid(&pid_right_rear, Right_rear_speed, Right_rear_goalspeed);

    //PID控制
    Left_front_pwm_set1(pid_left_front.result);
    Right_front_pwm_set1(pid_right_front.result);
    Left_rear_pwm_set1(pid_left_rear.result);
    Right_rear_pwm_set1(pid_right_rear.result);
}
