#include "App1.h"
#include "gpio.h"
#include "Systick.h"

GPIO gpio;
extern SystemTick systick;

void App1::Init()
{
	for (int i = 0; i < 8; i++)
		gpio.SetDirection(2, i, 1);
	stat = 0;
	TimeCount = 0;
}

void App1::Run()
{
	if (TimeCount > 3)
	{
		gpio.Toggle(2, stat);
		TimeCount = 0;
		stat++;
		if (stat > 7)
			stat = 0;
	}
}