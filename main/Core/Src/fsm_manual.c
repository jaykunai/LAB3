/*
 * fsm_manual.c
 *
 *  Created on: Oct 29, 2022
 *      Author: Acer
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_MODE2:
		if(is_button_pressed(0)){
			status = MAN_MODE3;
			break;
		}
		setTimer1(250);// 2Hz
		setTrafficGreen();
		setTrafficGreen1();
		if(timer1_flag == 1){ // blinking red led
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
		setTimer1(250);
		}
		int temp = defaultTimeRed;
		//button2 is pressed
		if(is_button_pressed(1)){
			temp++;
		}
		//button3 is pressed
		if(is_button_pressed(2)){
			defaultTimeRed = temp;
		}
		updateClockBuffer(2, defaultTimeRed);
		break;
	case MAN_MODE3:
		if(is_button_pressed(0)){
			status = MAN_MODE4;
			break;
		}
		if(timer1_flag == 1){ // blinking red led
			HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			setTimer1(250);
			}
		    int t = defaultTimeYellow;
			//button2 is pressed
		if(is_button_pressed(1)){
				t++;
		  }
			//button3 is pressed, set defaultTimeYellow value
			if(is_button_pressed(2)){
				defaultTimeYellow = t;
				updateClockBuffer(3, defaultTimeYellow);
			}
		break;
	case MAN_MODE4:
		// if button1 is pressed, come back normal state in INIT status
		if(is_button_pressed(0)){
			status = MAN_MODE1;
			break;
		}
		if(timer1_flag == 1){ // blinking red led
			HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			setTimer1(250);
			}
			int tmp = defaultTimeYellow;
			//button2 is pressed
			if(is_button_pressed(1)){
				tmp++;
			}
			//button3 is pressed
			if(is_button_pressed(2)){
				defaultTimeGreen = tmp;
				updateClockBuffer(4, defaultTimeGreen);
			}
		break;
	}
}
