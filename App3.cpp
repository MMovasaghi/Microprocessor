#include "App3.h"
#include "Systick.h"
#include "UART.h"

extern SystemTick systick;
extern UART uart;

void App3::Init()
{
	stat = 0;
	TimeCount = 0;
	direction = 0;
}

void App3::Run()
{	
	if (stat == 0)
	{
		if (uart.DataAvailable2(2))
		{
			char temp = uart.Get2(2);
			if (temp == 'a')
				direction = 0;
			else if (temp == 'b')
				direction = 1;
			stat = 1;
			TimeCount = 0;
		}
	}
	
	if (TimeCount > 50)
	{
		if (direction == 0)
			switch (stat)
			{
				case 1:
					uart << 'A';
					uart.Send2(2, 'A');
					stat++;
					break;
				case 2:
					uart << 'B';
					uart.Send2(2, 'B');
					stat++;
					break;
				case 3:
					uart << 'C';
					uart.Send2(2, 'C');
					stat = 0;
					break;
			}
		else if (direction == 1)
		switch (stat)
		{
			case 1:
				uart << 'C';
				uart.Send2(2, 'C');
				stat++;
				break;
			case 2:
				uart << 'B';
				uart.Send2(2, 'B');
				stat++;
				break;
			case 3:
				uart << 'A';
				uart.Send2(2, 'A');
				stat = 0;
				break;
		}
		TimeCount = 0;
	}
}