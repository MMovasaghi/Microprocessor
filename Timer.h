#ifndef TIMER_H
#define TIMER_H

class Timer
{
	public:
		void Init();
		void SetInterval(char MRNum, unsigned int MicroSeconds);
		void Enable();
		void Disable();
		void Reset(char release);
		void InterruptHandler();
	
	bool Timeout;
};

#endif