/*
 * Timer.h
 *
 * Created: May04,2017 3:04:46 PM
 *  Author: Marwa
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "common_macros.h"
#include "std_types.h"
#include "micro_config.h"


void TIMER_OVF_Mode(void);

void TIMER_CTC_Mode(uint8 Ticks);

void TIMER_PWM_Mode(uint8 set_duty_cycle);


#endif /* TIMER_H_ */