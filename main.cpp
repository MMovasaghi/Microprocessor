#include "lpc17xx.h"
#include "MyBlinkLED.h"
#include "MyBlinkLED2.h"
#include "HelloWorld.h"
#include "uart.h"
#include "Watchdog.h"

BlinkLED leds;
BlinkLED2 leds2;
HelloWorld hw;
UART uart;
WatchDog watchdog;

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
	hw.Run4();
}

int main (void) 
{
	SystemInit();
	watchdog.Init();
  HelloWorldTest();
}

