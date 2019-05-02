#include <LPC17xx.h>    
#include "systick.h"

void set_systick()
{
    systick stick;
    stick.Init();
    stick.Set_Intrrupt();
}


int main (void) 
{
    SystemInit();
    set_systick();    
    while(1)
    {
        //the program
    }
}

