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

int is_button_pressed(uint8_t index);
int is_button_pressed_1s(uint8_t index);


#endif /* INC_INPUT_READING_H_ */
