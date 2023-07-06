#include <reg52.h>
#include <stdlib.h>
#include <ds18b20.h>
#include <smg_display.h>
void int0() interrupt 0
{
    delay_10us(1000);
    if (P32 == 0) 
    {
        P20 = !P20;
    }
}
void main()
{
    IT0=1;
    EX0=1;
    EA=1;
    float tm  = 0;
    u16 tmp   = 0;
    u8 str[5] = {'\0'};
    while (1) 
    {
        ds18b20_init();
        tm     = ds18b20_read_temperture();
        tm     = 10 * tm;
        tmp    = tm;
        str[0] = tmp / 100 + '0';
        str[1] = (tmp / 10) % 10 + '0';
        str[2] = '.';
        str[3] = tmp % 10 + '0';
        str[4] = '\0';
        Smg_display(str, 100);
    }
}