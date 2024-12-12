#ifndef TIMER_H
#define TIMER_H

#include "Common.h"


typedef struct Timer
{
	float current;
	float max;
}Timer;


void InitTimer(Timer* _timer, float _maxValue);
void UpdateTimer(float _dt, Timer* _timer);
sfBool IsFinished(Timer* _timer);

#endif