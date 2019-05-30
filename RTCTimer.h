#ifndef RTCTIMER_H
#define RTCTIMER_H

class RTCTimer
{
	public:
		void Init();
		void Start();
		void Stop();
		void SetTime();
		void InterruptHandler();
};

#endif