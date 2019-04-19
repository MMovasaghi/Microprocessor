#include "lpc17xx.h"
#include "MyBlinkLED2.h"
#include "Utility.h"

void BlinkLED2::Init()
{
	LEDBlinkDir = true;
	//gpio.SetDirection(2, 12, 0);
	gpio.SetInterrupt(2, 12, BothEdge);
	for (int i = 0; i < 8; i++)
		gpio.SetDirection(2, i, 1);
}

void BlinkLED2::Run()
{
	while(true)
	{
//		if (gpio.getValue(2, 11) == false)
//			LEDBlinkDir = !LEDBlinkDir;
		
		if (LEDBlinkDir == true)
		{
			for (int i = 0; i < 8; i++)
			{
				gpio.Set(2, i);
				Utility::Delay(0x00fffff);
				gpio.Reset(2, i);
				Utility::Delay(0x00fffff);
			}
		}
		else
		{
			for (int i = 8; i >=0; i--)
			{
				gpio.Set(2, i);
				Utility::Delay(0x00fffff);
				gpio.Reset(2, i);
				Utility::Delay(0x00fffff);
			}
		}
				
	}
}

void BlinkLED2::InterruptHandler()
{
	if (LPC_GPIOINT->IO2IntStatF & (1 << 12))
			LEDBlinkDir = !LEDBlinkDir;
	if (LPC_GPIOINT->IO2IntStatR & (1 << 12))
			LEDBlinkDir = !LEDBlinkDir;
}