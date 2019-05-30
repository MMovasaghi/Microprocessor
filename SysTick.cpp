#include "Systick.h"
#include "lpc17xx.h"
#define ST_CTRL_ENABLE		((unsigned int)(1<<0))
#define ST_CTRL_TICKINT		((unsigned int)(1<<1))
#define ST_CTRL_CLKSOURCE	((unsigned int)(1<<2))
#define ST_CTRL_COUNTFLAG	((unsigned int)(1<<16))

void SystemTick::Init(unsigned int MS_interval)
{
	//NVIC_EnableIRQ(SysTick_IRQn);
	TimerCounter = 1;
	LastTime = 0;
	SysTick->CTRL = ST_CTRL_CLKSOURCE | ST_CTRL_ENABLE | ST_CTRL_TICKINT;
	SysTick->LOAD = 100000 * MS_interval - 1;
}

void SystemTick::InterruptHandler()
{
	TimerCounter++;
}

extern SystemTick systick;
extern "C"
{
	void SysTick_Handler()
	{
		systick.InterruptHandler();
	}
}