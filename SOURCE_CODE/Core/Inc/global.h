/*
 * global.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Nghia
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include <string.h>
#include <stdio.h>

#define IDLE 1
#define PARSING 2

#define WAITING_COMMAND 3
#define TRANSMITTING_DATA 4
#define WAITING_TIMEOUT 5

void initial_program();

#endif /* INC_GLOBAL_H_ */
