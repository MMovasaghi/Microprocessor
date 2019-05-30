#ifndef RTCTIMER_H
#define RTCTIMER_H

class RTCTimer
{
	public:
		void Init();
		void Start();
		void Stop();
		void SetTime();
		void Print();
		void PrintDecimal(int d, char padding = 2);
		void InterruptHandler();
};

#endif