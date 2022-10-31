/*
 * displayLed7Seg.c
 *
 *  Created on: Oct 29, 2022
 *      Author: Acer
 */

#include "led_display.h"

uint16_t led_matrix[MAX_MATRIX] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7D, 0x07, 0x7F, 0x6f};

void displayLed7Seg_1(int number){
	uint16_t bit_var = led_matrix[number];
	HAL_GPIO_WritePin(GPIOB, bit_var, RESET);
	HAL_GPIO_WritePin(GPIOB, ~bit_var, SET);
}
