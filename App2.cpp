#include "App2.h"
#include "Systick.h"
#include "RTCTimer.h"
#include "Uart.h"
extern UART uart;
extern RTCTimer rtc;
extern SystemTick systick;

void App2::Init()
{
	TimeCount = 0;
}

void App2::Run()
{	
	if (TimeCount > 125)
	{
		uart << rtc;
		TimeCount = 0;
	}
}