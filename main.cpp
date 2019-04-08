#include "lpc17xx.h"
#include "MyBlinkLED.h"
#include "MyBlinkLED2.h"

BlinkLED leds;
BlinkLED2 leds2;

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

int main (void) 
{
	SystemInit();
  
}

