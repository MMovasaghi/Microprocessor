#include "lpc17xx.h"
#include "MyBlinkLED.h"
#include "MyBlinkLED2.h"
#include "HelloWorld.h"
#include "uart.h"
#include "Watchdog.h"
#include "Systick.h"
#include "RTCTimer.h"
#include "Timer.h"
#include "Utility.h"

#include "App1.h"
#include "App2.h"
#include "App3.h"

BlinkLED leds;
BlinkLED2 leds2;
HelloWorld hw;
UART uart;
WatchDog watchdog;
SystemTick systick;
RTCTimer rtc;
Timer timer;


void BlinkLEDTest()
{
	leds.Init();
	leds.Run();
}

void BlinkLED2Test()
{
	leds2.Init();
	leds2.Run();
}

void HelloWorldTest()
{
	hw.Init();
	hw.Run5();
}

void RTCTest()
{
	uart.InitInterrupt(2, Data_8Bits, Stop_1Bit, Parity_Non, 9600);
	uart.Send2(2, "\r\n**********System is started **********\r\n");
	//while(true);
	rtc.Init();
	//rtc.SetTime();
	while (true)
	{
		rtc.Print();
		Utility::Delay(9999999);
		watchdog.Feed();
	}
}

void TimerTest()
{
	uart.InitInterrupt(2, Data_8Bits, Stop_1Bit, Parity_Non, 9600);
	uart.Send2(2, "\r\n**********System is started **********\r\n");
	timer.Init();
	rtc.Init();
	rtc.SetTime();
	while(true)
	{
		rtc.Print();
		Utility::DelayMicroSecond(1000000);
		watchdog.Feed();
	}
}

App1 app1;
App2 app2;
App3 app3;
void ReadTimes()
{
	unsigned int Diff;
	if (systick.LastTime != systick.TimerCounter)
	{
		Diff = systick.TimerCounter - systick.LastTime;
		systick.LastTime = systick.TimerCounter;
		app1.TimeCount += Diff;
		app2.TimeCount += Diff;
		app3.TimeCount += Diff;
	}
}

void RunApps()
{
	uart.InitInterrupt(2, Data_8Bits, Stop_1Bit, Parity_Non, 9600);
	uart.Send2(2, "\r\n**********System is started **********\r\n");
	systick.Init(40);
	rtc.Init();
	rtc.SetTime();
	
	app1.Init();
	app2.Init();
	app3.Init();
	
	while (true)
	{
		ReadTimes();
		app1.Run();
		app2.Run();
		app3.Run();
		
		watchdog.Feed();
	}
}

int main (void) 
{
	SystemInit();
	watchdog.Init();
	RunApps();
}

