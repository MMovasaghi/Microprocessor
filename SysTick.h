#ifndef SYSTICK_H
#define SYSTICK_H

class SystemTick
{
	public:
		void Init(unsigned int interval);
		void InterruptHandler();
	
	unsigned int TimerCounter;
	unsigned int LastTime;
};

#endif