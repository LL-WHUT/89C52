#include <smg_display.h>
#include <ds18b20.h>
void main()
{
    u16 tem=0;
    u8 test[60]={'0','0','.','0','#'};
    ds18b20_init();
    tem=ds18b20_read_temperture()*10;
    test[0]=tem/100+'0';
    test[1]=(tem/10)%10+'0';
    test[3]=tem%10+'0';
    Smg_display(test,1000);
}