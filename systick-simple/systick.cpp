#include "systick.h"

void systick::Init(int Reload_value = 99999) // default is 1ms
{
    STRELOAD = Reload_value;    // Reload value for 1ms tick
}
void systick::Set_Intrrupt()
{
    NVIC_EnableIRQ(SysTick_IRQn);
    /* Enable the Systick, Systick Interrup and select CPU Clock Source */
    STCTRL = (1<<SBIT_ENABLE) | (1<<SBIT_TICKINT) | (1<<SBIT_CLKSOURCE);
}

extern "C"
{
    void SysTick_Handler()
    {
        //What you want to do for each intrrupt
    }
}