#include "OutOperator.h"
#include "lpc17xx.h"

OutOperator& OutOperator::operator << (char d)
{
	send(d);
	return *this;
}

OutOperator& OutOperator::operator << (int d)
{
	char buf[10];
	char r = 0;
	if (d < 0)
	{
		send('-');
		d = -d;
	}
	while(d)
	{
		buf[r++] = (d % 10) + 48;
		d /= 10;
	}
	if (r == 0)
		send('0');
	for (signed char i = r - 1; i >= 0; i--)
		send(buf[i]);
	return *this;
}

OutOperator& OutOperator::operator << (char* str)
{
	while (*str)
		*this << *str++;
		//send(*str++);
	return *this;
}

OutOperator& OutOperator::operator<< (RTCTimer& rtc)
{
	*this << LPC_RTC->YEAR << "/" << 
					LPC_RTC->MONTH << "/" << 
					LPC_RTC->DOM << " " << 
					LPC_RTC->HOUR << ":" << 
					LPC_RTC->MIN << ":" << 
					LPC_RTC->SEC << "\r\n";
	return *this;
}
