#include "App2.h"
#include "Systick.h"
#include "RTCTimer.h"

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
		rtc.Print();
		TimeCount = 0;
	}
}