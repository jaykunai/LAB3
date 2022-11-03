/*
 * fsm_manual.c
 *
 *  Created on: Oct 29, 2022
 *      Author: Acer
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_MODE1:
		status = INIT;
		break;
	case MAN_MODE2:
		if(is_button_pressed(0)){
			status = MAN_MODE3;
			setTimer1(250);
		}
		setTrafficRed1();
		setTrafficRed();
		//linking red led
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			setTimer1(250);
		}
		int temp = defaultTimeRed;
		if(is_button_pressed(1)){
			temp++;
		}
		if(is_button_pressed(2)){
			defaultTimeRed = temp;
		}
		break;
	case MAN_MODE3:
		setTrafficYellow();
		setTrafficYellow1();
		if(is_button_pressed(0)){
			status = MAN_MODE4;
			setTimer1(250);
		}
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			setTimer1(250);
		}
		updateClockBuffer(3, defaultTimeYellow);
		break;
	case MAN_MODE4:
		if(is_button_pressed(0)){
			status = INIT;
		}
		setTrafficGreen();
		setTrafficGreen1();
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			setTimer1(250);
		}
		updateClockBuffer(4, defaultTimeGreen);
		break;
	default:
			break;
	}
}
