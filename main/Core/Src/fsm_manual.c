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
		setTrafficRed1();
		setTrafficRed();
		if(is_button_pressed(0) == 1){
			status = MAN_MODE3;
			setTimer1(250);
		}
		//linking red led
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			setTimer1(250);
		}
		if(is_button_pressed(1) == 1){
			tempRed++;
		}
		if(is_button_pressed(2) == 1){
			defaultTimeRed = tempRed ;
		}
		updateClockBuffer(1, defaultTimeRed);
		break;
	case MAN_MODE3:
		setTrafficYellow();
		setTrafficYellow1();
		if(is_button_pressed(0) == 1){
			status = MAN_MODE4;
			setTimer1(250);
		}
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			setTimer1(250);
		}
		if(is_button_pressed(1) == 1){
			tempYellow++;
		}
		if(is_button_pressed(2) == 1){
			defaultTimeYellow = tempYellow ;
		}
		updateClockBuffer(3, defaultTimeYellow);
		break;
	case MAN_MODE4:
		if(is_button_pressed(0) == 1){
			setTimer1(defaultTimeGreen*1000);
			setTimer2(1000);
			timeRed = defaultTimeRed;
			timeGreen = defaultTimeGreen;
			updateClockBuffer(timeRed--, timeGreen--);
			status = AUTO_RED_GREEN;
		}
		setTrafficGreen();
		setTrafficGreen1();
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			setTimer1(250);
		}
			if(is_button_pressed(1) == 1){
				tempGreen++;
			}
			if(is_button_pressed(2) == 1){
				defaultTimeGreen = tempGreen ;
			}
		updateClockBuffer(4, defaultTimeGreen);
		break;
	default:
			break;
	}
}
