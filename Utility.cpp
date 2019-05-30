#include "Utility.h"
#include "Timer.h"
#include "watchdog.h"

void Utility::Delay(unsigned int d)
{
	for (unsigned int i = 0; i < d; i++);
}

extern Timer timer;
extern WatchDog watchdog;
void Utility::DelayMicroSecond(unsigned int d)
{
	timer.Enable();
	timer.Reset(true);
	timer.SetInterval(0, d);
	timer.Timeout = false;
	timer.Reset(false);
	while(timer.Timeout == false)
		watchdog.Feed();
	timer.Disable();
}