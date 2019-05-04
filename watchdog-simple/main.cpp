#include <LPC17xx.h>    
#include "watchdog.h"

int main (void) 
{
    SystemInit();
    watchdog wdog();//to set the time and initial the watchdog    
    while(1)
    {
        wdog.Set_OverloadTime(0xffffffff);
        wdog.RELOAD();

        /*the program
         * ---------------------
         * ---------------------
        */

        wdog.Set_OverloadTime(0xffff);
        wdog.RELOAD();
        
        /*the program
         * ---------------------
         * ---------------------
        */
    }
}

