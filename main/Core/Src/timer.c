/*
 * software_timer.c
 *
 *  Created on: Oct 29, 2022
 *      Author: Acer
 */


#include "timer.h"

#define Timer_Cycle 10

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
//	if(htim->Instance == TIM2){
//		button_reading();
//	}
	timer_run();
}

int timer1_flag = 0;
int timer1_counter = 0;

void setTimer1(int duration){
	timer1_counter = duration/Timer_Cycle;
	timer1_flag = 0;
}

void timer_run(){
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter == 0) timer1_flag = 1;
	}
	button_reading();
}
