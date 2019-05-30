#ifndef OUTOPERATOR_H
#define OUTOPERATOR_H
#include "RTCTimer.h"

class OutOperator
{
	public:
		virtual void send(char d) = 0;
		OutOperator& operator << (char d);
		OutOperator& operator << (int d);
		//OutOperator& operator << (unsigned int d);
		OutOperator& operator << (char* str);
		OutOperator& operator << (RTCTimer& rtc);
};

#endif