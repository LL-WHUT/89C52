#ifndef _DELAY_
#define _DELAY_

#include<reg52.h>
void delay_ms(u16 xms)
{
    int i, j;
    for (i = 0; i < 114; ++i)
    {
        for (j = 0; j < xms; ++j)
        {
            ;
        }
    }
}

void delay_10us(u16 ten_us)
{
    while (ten_us--)
        ;
}

#endif