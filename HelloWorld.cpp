#include "HelloWorld.h"
#include "UART.h"
#include "Utility.h"
#include "WatchDog.h"
#include "Systick.h"
extern UART uart;

void HelloWorld::Init()
{
	uart.InitInterrupt(2, Data_8Bits, Stop_1Bit, Parity_Non, 9600);
}

void HelloWorld::Run()
{
	char d;
	while (true)
	{
		d = uart.Get(1);
		if (d == 'A')
			uart.Send(2, "HELLO WORLD\r\n");
		else if (d == 'B')
			uart.Send(2, "GOODBYE WORLD\r\n");
		//Utility::Delay(9999999);
	}
}

void HelloWorld::Run2()
{
	bool d = true;
	while (true)
	{
		if (uart.DataAvailable(2))
			if (uart.Get(2) == 'T')
				d = !d;
			
		if (d)
			uart.Send(2, "HELLO WORLD\r\n");
		else
			uart.Send(2, "GOODBYE WORLD\r\n");
		Utility::Delay(9999999);
	}
}

void HelloWorld::Run3()
{
	bool d = true;
	while (true)
	{
		if (uart.DataAvailable(2))
			uart.Send(2, uart.Get(2));
			
		//Utility::Delay(9999999);
	}
}
extern WatchDog watchdog;
void HelloWorld::Run4()
{
	int MessageNum = 1;
	char d;
	uart.Send2(2, "\r\n**********System is started **********\r\n");
	while(true)
	{
//		if (uart.DataAvailable2(2))
//		{
//			d = uart.Get2(2);
//			if (d == 'a')
//				MessageNum = 1;
//			else
//				MessageNum = 2;
//		}
		if (MessageNum == 1)
			uart.Send2(2, "Hello World\t");
		else if (MessageNum == 2)
			uart.Send2(2, "Goodbye World\t");
		Utility::Delay(9999999);
		watchdog.Feed();
	}
}

extern SystemTick systick;
void HelloWorld::Run5()
{
	uart.Send2(2, "\r\n**********System is started **********\r\n");
	unsigned int count = 0;
	unsigned int Diff;
	while (true)
	{
		if (systick.LastTime != systick.TimerCounter)
		{
			Diff = systick.TimerCounter - systick.LastTime;
			systick.LastTime = systick.TimerCounter;
			count += Diff;
		}
		if (count == 100)
		{
			uart.Send2(2, "Hello\r\n");
			count = 0;
		}
		watchdog.Feed();
	}
}
