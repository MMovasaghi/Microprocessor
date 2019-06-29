#include "Timer.h"
#include "lpc17xx.h"

void Timer::Init()
{
	LPC_TIM0->MCR = 5;
	NVIC_EnableIRQ(TIMER0_IRQn);
	SetInterval(0, 1000000);
	Timeout = false;
}

void Timer::SetInterval(char MRNum, unsigned int MicroSeconds)
{
	//25*10^6 Hz => 25 Hz : 1 MicroSeconds
	if (MRNum == 0)
		LPC_TIM0->MR0 = 25 * MicroSeconds;
	else if (MRNum == 1)
		LPC_TIM0->MR1 = 25 * MicroSeconds;
}

void Timer::Enable()
{
	LPC_TIM0->TCR |= 1;
}

void Timer::Disable()
{
	LPC_TIM0->TCR &= 2;
}

void Timer::Reset(char reset)
{
	if (reset == 1)
		LPC_TIM0->TCR |= 2;
	else
		LPC_TIM0->TCR &= 1;
}

void Timer::InterruptHandler()
{
	if (LPC_TIM0->IR & 1)
		Timeout = true;
	
	LPC_TIM0->IR = 0x3F;
}

extern Timer timer;
extern "C"
{
	void TIMER0_IRQHandler()
	{
		timer.InterruptHandler();
	}
}