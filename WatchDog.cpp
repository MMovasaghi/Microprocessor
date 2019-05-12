#include "WatchDog.h"
#include "lpc17xx.h"

void WatchDog::Init()
{
	LPC_WDT->WDCLKSEL = 0x80000001;
	LPC_WDT->WDTC = 0x0FFFFFF;
	LPC_WDT->WDMOD = 3;
	Feed();
}

void WatchDog::Feed()
{
	LPC_WDT->WDFEED = 0xAA;
	LPC_WDT->WDFEED = 0x55;
}

void WatchDog::InterruptHandler()
{
}

extern "C"
{
	void WDT_IRQHandler()
	{
	}
}