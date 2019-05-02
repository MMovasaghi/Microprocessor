#include "watchdog.h"

watchdog::watchdog()
{
    LPC_WDT->WDMOD |= 3; // WDEN = 1 : Enable the watchdog & WDRESET = 1 :  watchdog time-out will cause a chip reset        
}
void watchdog::Set_OverloadTime(int cnt)
{
    LPC_WDT->WDTC = cnt; // set the timer content
}
void watchdog::RELOAD()
{
    LPC_WDT->WDFEED = 0xAA; 
    LPC_WDT->WDFEED = 0x55;
}
int getCounterValue()
{
    return LPC_WDT->WDTV;
}