/*
 * timer.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Nghia
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[10];

void setTimer(int duration, int timerID);
void timerRun(int timerID);

#endif /* INC_SOFTWARE_TIMER_H_ */
