/*
 * software_timer.h
 *
 *  Created on: Oct 29, 2022
 *      Author: Acer
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "input_reading.h"

extern int timer1_flag;

void setTimer1(int);

void timer_run(void);

#endif /* INC_TIMER_H_ */
