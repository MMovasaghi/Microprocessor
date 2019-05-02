#ifndef WATCHDOG_H
#define WATCHDOG_H

class watchdog
{
    public:
        watchdog();
        void RELOAD();
        void Set_OverloadTime(int cnt);
        int getCounterValue();
};

#endif