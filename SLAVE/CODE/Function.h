#ifndef __FUNCTION_H_
#define __FUNCTION_H_

#include "headfile.h"

void init(void);
//void display_speed(void);
//void display_icm(void);
//void display_icm_inte(void);
void display(void);
void nixu(int a,int b,int R[]);
unsigned int my_sqrt(unsigned int x);//开平方根
unsigned int abs_sub(unsigned int diff1,unsigned int diff2);//两个无符号数相减的绝对值
float process_curvity(short x1, short y1, short x2, short y2, short x3, short y3);

#endif/* __FUNCTION_H_ */
