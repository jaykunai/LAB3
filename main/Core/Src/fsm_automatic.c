/*
 * fsm_automatic.c
 *
 *  Created on: Oct 29, 2022
 *      Author: Acer
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		status = AUTO_RED_GREEN;
		setTimer1(timeGreen);
		setTimer3(250);
		setTimer2(1000);
		break;
	case AUTO_RED_GREEN:
		setTrafficRed();
		setTrafficGreen1();
		display();
		if(timer1_flag == 1){
			status = AUTO_RED_YELLOW;
			setTimer1(timeYellow);
		}
		break;
	case AUTO_RED_YELLOW:
		setTrafficRed();
		setTrafficYellow1();
		display();
		if(timer1_flag == 1){
			status = AUTO_GREEN_RED;
			setTimer1(timeGreen);
		}
		break;
	case AUTO_GREEN_RED:
		setTrafficGreen();
		setTrafficRed1();
		display();
		if(timer1_flag == 1){
			status = AUTO_YELLOW_RED;
			setTimer1(timeYellow);
		}
		break;
	case AUTO_YELLOW_RED:
		setTrafficYellow();
		setTrafficRed1();
		display();
		if(timer1_flag == 1){
			status = AUTO_RED_GREEN;
			setTimer1(timeGreen);
		}
		break;
	default:
		break;
	}
}
