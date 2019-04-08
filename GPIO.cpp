#include "GPIO.h"
#include "LPC17xx.h"

void GPIO::SetDirection(int port, int pin, int dir)
{
	if (port == 0)
	{
		LPC_GPIO0->FIODIR &= ~(1 << pin);
		LPC_GPIO0->FIODIR |= dir << pin;
	}
	else if (port == 1)
	{
		LPC_GPIO1->FIODIR &= ~(1 << pin);
		LPC_GPIO1->FIODIR |= dir << pin;
	}
	else if (port == 2)
	{
		LPC_GPIO2->FIODIR &= ~(1 << pin);
		LPC_GPIO2->FIODIR |= dir << pin;
	}
	else if (port == 3)
	{
		LPC_GPIO3->FIODIR &= ~(1 << pin);
		LPC_GPIO3->FIODIR |= dir << pin;
	}
	else if (port == 4)
	{
		LPC_GPIO4->FIODIR &= ~(1 << pin);
		LPC_GPIO4->FIODIR |= dir << pin;
	}
}

void GPIO::Set(int port, int pin)
{
	if (port == 0)
		LPC_GPIO0->FIOSET = 1 << pin;
	else if (port == 1)
		LPC_GPIO1->FIOSET = 1 << pin;
	else if (port == 2)
		LPC_GPIO2->FIOSET = 1 << pin;
	else if (port == 3)
		LPC_GPIO3->FIOSET = 1 << pin;
	else if (port == 4)
		LPC_GPIO4->FIOSET = 1 << pin;
}

void GPIO::Reset(int port, int pin)
{
	if (port == 0)
		LPC_GPIO0->FIOCLR = 1 << pin;
	else if (port == 1)
		LPC_GPIO1->FIOCLR = 1 << pin;
	else if (port == 2)
		LPC_GPIO2->FIOCLR = 1 << pin;
	else if (port == 3)
		LPC_GPIO3->FIOCLR = 1 << pin;
	else if (port == 4)
		LPC_GPIO4->FIOCLR = 1 << pin;
}

void GPIO::Toggle(int port, int pin)
{
	if (port == 0)
		LPC_GPIO0->FIOPIN ^= 1 << pin;
	else if (port == 1)
		LPC_GPIO1->FIOPIN ^= 1 << pin;
	else if (port == 2)
		LPC_GPIO2->FIOPIN ^= 1 << pin;
	else if (port == 3)
		LPC_GPIO3->FIOPIN ^= 1 << pin;
	else if (port == 4)
		LPC_GPIO4->FIOPIN ^= 1 << pin;
}

void GPIO::SetValue(int port, int pin, bool value)
{
	if (port == 0)
	{
		LPC_GPIO0->FIOPIN &= ~(1 << pin);
		LPC_GPIO0->FIOPIN |= value << pin;
	}
	else if (port == 1)
	{
		LPC_GPIO1->FIOPIN &= ~(1 << pin);
		LPC_GPIO1->FIOPIN |= value << pin;
	}
	else if (port == 2)
	{
		LPC_GPIO2->FIOPIN &= ~(1 << pin);
		LPC_GPIO2->FIOPIN |= value << pin;
	}
	else if (port == 3)
	{
		LPC_GPIO3->FIOPIN &= ~(1 << pin);
		LPC_GPIO3->FIOPIN |= value << pin;
	}
	else if (port == 4)
	{
		LPC_GPIO4->FIOPIN &= ~(1 << pin);
		LPC_GPIO4->FIOPIN |= value << pin;
	}
}
