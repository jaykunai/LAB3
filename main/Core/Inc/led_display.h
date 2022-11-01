/*
 * displayLed7Seg.h
 *
 *  Created on: Oct 29, 2022
 *      Author: Acer
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"
#include "global.h"
#define MAX_MATRIX 10
#define MAX_BUFF 4

void display7SEG(int number);
void updateClockBuffer(int, int);
void scanLed();

#endif /* INC_LED_DISPLAY_H_ */
