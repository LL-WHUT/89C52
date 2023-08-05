#include <reg52.h>

void time0_init(void)
{
    TMOD |= 0x01;//选择定时器0，工作模式1
    TH0 = 0xfc;TL0 = 0x18;//给定时器赋初值1ms
    ET0 = 1;//打开定时器0中断允许
    EA  = 1;//打开总中断
    TR0 = 1;//打开定时器0
}

void time0() interrupt 1
{
    static u16 i;
    TH0=0xfc;
    TL0=0x18;
    i++;
    if(i==1000)
    {
        i=0;
        P20=!P20;
    }
}

void main()
{
    time0_init();
    while (1)
    {
        ;
    }
    
}