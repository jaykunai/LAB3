/*
 * global.h
 *
 *  Created on: Oct 29, 2022
 *      Author: Acer
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "traffic.h"
#include "input_processing.h"
#include "input_reading.h"

extern int timeRed;
extern int timeGreen;
extern int timeYellow;

#define INIT 1
#define AUTO_RED_GREEN 2
#define AUTO_RED_YELLOW 3
#define AUTO_GREEN_RED 4
#define AUTO_YELLOW_RED 5

#define MAN_MODE1 11
#define MAN_MODE2 12
#define MAN_MODE3 13
#define MAN_MODE4 14


extern int status;


#endif /* INC_GLOBAL_H_ */
