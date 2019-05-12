#ifndef WATCHDOG_H
#define WATCHDOG_H

class WatchDog
{
	public:
		void Init();
		void Feed();
		void InterruptHandler();
};

#endif