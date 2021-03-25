/*
 * show_somthing.h
 *
 *  Created on: 2021年3月19日
 *      Author: HP
 */

#ifndef CODE_SHOW_SOMTHING_H_
#define CODE_SHOW_SOMTHING_H_
#include <headfile.h>
#include "camera_findline.h"
#define   MAX_SHOW_PAGE  10/*最大页面数*/

extern int8 now_show_page ;//当前页面
extern int8 clear_page_flag  ;//清屏标志位


extern void show_page();//显示页面
extern void page_up();
extern void page_down();
extern void clear_lcd_page();
#endif /* CODE_SHOW_SOMTHING_H_ */
