/*
 * uart_fsm.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Nghia
 */

#include "uart_fsm.h"

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t data[MAX_BUFFER_SIZE];
uint8_t str[MAX_BUFFER_SIZE];
uint32_t ADC_value = 0;
uint8_t size_str;

int cmd_parser_state = IDLE;
int uart_state = WAITING_COMMAND;

uint8_t end_str[] = "\rEND\r";
uint8_t help_str[] = "\rPlease start the command with ! and end with #: ";

void command_parser_fsm() {
	switch(cmd_parser_state) {
		case IDLE:
			if (index_buffer == 0) {
				memset(buffer, 0, MAX_BUFFER_SIZE);
			}
			if (temp == '!') {
				cmd_parser_state = PARSING;
			}
			else {
				index_buffer = 0;
				HAL_UART_Transmit(&huart2, help_str, sizeof(help_str), 1000);
			}
			break;
		case PARSING:
			if (temp == '#') {
				index_buffer = 0;
				cmd_parser_state = IDLE;
				memcpy(data, buffer, MAX_BUFFER_SIZE);
			}
			else {
				buffer[index_buffer++] = temp;
			}
		default:
			break;
	}
}

void uart_communication_fsm() {
	switch(uart_state) {
		case WAITING_COMMAND:
			if (strcmp((char *)data, "RST") == 0) {
				uart_state = TRANSMITTING_DATA;
				HAL_ADC_Start(&hadc1);
				ADC_value = HAL_ADC_GetValue(&hadc1);
				size_str = sprintf((char*)str, "\r!ADC=%d#\r", (int)ADC_value);
				HAL_ADC_Stop(&hadc1);
			}
			break;
		case TRANSMITTING_DATA:
			HAL_UART_Transmit(&huart2, str, sizeof(str), 1000);
			uart_state = WAITING_TIMEOUT;
			setTimer(300, 0);
			break;
		case WAITING_TIMEOUT:
			if (strcmp((char *)data, "OK") == 0) {
				uart_state = WAITING_COMMAND;
				HAL_UART_Transmit(&huart2, end_str, sizeof(end_str), 1000);
				initial_program();
				memset(data, 0, MAX_BUFFER_SIZE);
			}
			if (timer_flag[0] == 1) {
				uart_state = TRANSMITTING_DATA;
			}
			break;
		default:
			break;
	}
}
