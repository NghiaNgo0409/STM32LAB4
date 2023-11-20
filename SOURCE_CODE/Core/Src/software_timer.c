/*
 * software_timer.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Nghia
 */

#include "software_timer.h"

int timer_counter[10] = {0};
int timer_flag[10] = {0};

void setTimer(int duration, int timerID) {
	timer_counter[timerID] = duration;
	timer_flag[timerID] = 0;
}

void timerRun(int timerID) {
	if (timer_counter[timerID] > 0) {
		timer_counter[timerID]--;
		if (timer_counter[timerID] <= 0) {
			timer_flag[timerID] = 1;
		}
	}
}

