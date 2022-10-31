/*
 * input_reading.h
 *
 *  Created on: Oct 29, 2022
 *      Author: Acer
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"

void button_reading(void);

unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);

extern int button0_flag;
extern int button1_flag;
extern int button2_flag;

#endif /* INC_INPUT_READING_H_ */
