#include "GPIO.h"
#include "LPC17xx.h"
#include "MyBlinkLED2.h"

GPIO::GPIO()
{
	GPIOs[0] = LPC_GPIO0;
	GPIOs[1] = LPC_GPIO1;
	GPIOs[2] = LPC_GPIO2;
	GPIOs[3] = LPC_GPIO3;
	GPIOs[4] = LPC_GPIO4;
}

void GPIO::SetInterrupt(int port, int pin, Edge edge)
{
	SetDirection(port, pin, 0);
	NVIC_EnableIRQ(EINT3_IRQn);
	if (port == 2)
	{
		if ((edge == FallingEdge) || (edge == BothEdge))
		{
			LPC_GPIOINT->IO2IntEnF &= ~(1 << pin);
			LPC_GPIOINT->IO2IntEnF |= 1 << pin;
		}
		if ((edge == RisingEdge) || (edge == BothEdge))
		{
			LPC_GPIOINT->IO2IntEnR &= ~(1 << pin);
			LPC_GPIOINT->IO2IntEnR |= 1 << pin;
		}
	}
}

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
	//GPIOs[port]->FIOSET = 1 << pin;
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
		//LPC_GPIO4->FIOPIN = LPC_GPIO4->FIOPIN & ~(1 << pin);
		LPC_GPIO4->FIOPIN &= ~(1 << pin);
		LPC_GPIO4->FIOPIN |= value << pin;
	}
}

bool GPIO::getValue(int port, int pin)
{
	if (port == 0)
		return LPC_GPIO0->FIOPIN & (1 << pin);
	else if (port == 1)
		return LPC_GPIO1->FIOPIN & (1 << pin);
	else if (port == 2)
		return LPC_GPIO2->FIOPIN & (1 << pin);
	else if (port == 3)
		return LPC_GPIO3->FIOPIN & (1 << pin);
	else if (port == 4)
		return LPC_GPIO4->FIOPIN & (1 << pin);
}

extern "C"
{
	extern BlinkLED2 leds2;
	void EINT3_IRQHandler()
	{
		leds2.InterruptHandler();
		
		LPC_GPIOINT->IO0IntClr = 0xFFFFFFFF;
		LPC_GPIOINT->IO2IntClr = 0xFFFFFFFF;
	}
}