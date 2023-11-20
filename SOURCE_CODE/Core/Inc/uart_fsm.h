/*
 * uart_fsm.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Nghia
 */

#ifndef INC_UART_FSM_H_
#define INC_UART_FSM_H_

#include "global.h"

extern ADC_HandleTypeDef hadc1;

extern UART_HandleTypeDef huart2;

#define MAX_BUFFER_SIZE 30

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;


void command_parser_fsm();
void uart_communication_fsm();

#endif /* INC_UART_FSM_H_ */
