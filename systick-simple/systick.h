#ifndef SISTICK_H
#define SISTICK_H

/* Systick Register address, refer datasheet for more info */
#define STCTRL      (*( ( volatile unsigned long *) 0xE000E010 ))
#define STRELOAD    (*( ( volatile unsigned long *) 0xE000E014 ))
#define STCURR      (*( ( volatile unsigned long *) 0xE000E018 ))  

/*******STCTRL bits*******/
enum SBIT 
{
    SBIT_ENABLE,
    SBIT_TICKINT,
    SBIT_CLKSOURCE
}

class systick
{
    public:
        void Init(int Reload_value);
        void Set_Intrrupt();
};

#endif