#include "HelloWorld.h"
#include "UART.h"
#include "Utility.h"
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

void HelloWorld::Run4()
{
	while(true)
	{
		Utility::Delay(999999999);
	}
}