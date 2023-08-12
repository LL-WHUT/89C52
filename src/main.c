#include <reg52.h>
#include <keyscan.h>
#include <iic.h>
#include <at24c02.h>
#include <smg_display.h>

#define EEPROM_ADDRESS 0 // 定义数据存入EEPROM的起始地址

void main()
{
    u8 dat='0';
    u8 temp='0';
    while (1)
    {
        if(key_scan(1))
        {
            dat++;
        }
        at24c02_write_one_data(EEPROM_ADDRESS,dat);
        temp=at24c02_read_one_data(EEPROM_ADDRESS);
        Smg_display(&temp,100);//数码管显示有点毛病，不过验证AT24C02足够了
        if(dat=='9')
        {
            dat='0';
        }
    }
    
}
