#include "RTCTimer.h"
#include "lpc17xx.h"
#include "uart.h"

#define ILR_RTCCIF	0x01
#define ILR_RTCALF	0x02

#define CCR_CLKEN	0x01
#define CCR_CTCRST	0x02
#define CCR_CLKSRC	0x10

void RTCTimer::Init()
{
	LPC_SC->PCONP |= (1 << 9);
	/* If RTC is stopped, clear STOP bit. */
	if ( LPC_RTC->RTC_AUX & (0x1<<4) )
		LPC_RTC->RTC_AUX |= (0x1<<4);	
	/*--- Initialize registers ---*/    
	LPC_RTC->AMR = 0xFF;
	LPC_RTC->CIIR = 0;
	LPC_RTC->CCR = 0;
	LPC_RTC->CALIBRATION = 0x00;
	LPC_RTC->ILR = 2;
	//NVIC_EnableIRQ(RTC_IRQn);
	Start();
}

void RTCTimer::Start()
{
	LPC_RTC->CCR |= CCR_CLKEN;
  LPC_RTC->ILR = ILR_RTCCIF;
}

void RTCTimer::Stop()
{
	LPC_RTC->CCR &= ~CCR_CLKEN;
}

void RTCTimer::SetTime()
{
	LPC_RTC->YEAR = 2020;
	LPC_RTC->MONTH = 5;
	LPC_RTC->DOM = 21;
	LPC_RTC->HOUR = 15;
	LPC_RTC->MIN = 48;
	LPC_RTC->SEC = 50;
}

void RTCTimer::InterruptHandler()
{
	LPC_RTC->ILR |= 1;		/* clear interrupt flag */
}

extern "C"
{
void RTC_IRQHandler()
{
}
}