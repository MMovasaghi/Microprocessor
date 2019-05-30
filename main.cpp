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
	while(true)
	{
		uart.Send2(2, "Every one second\r\n");
		Utility::DelayMicroSecond(3000000);
		watchdog.Feed();
	}
}

int main (void) 
{
	SystemInit();
	watchdog.Init();
	TimerTest();
}

