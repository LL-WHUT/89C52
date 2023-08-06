//矩阵键盘
#ifndef _KEYSCAN_H_
#define _KEYSCAN_H_

#include <reg52.h>
#include <delay.h>
u8 keyscan(void)//矩阵键盘扫描函数，返回按键的位置(1--16)
{
    u8 key_value = 0;
    P1 = 0x0F;
    if (P1 != 0x0F)
    {
        delay_ms(20);
        if (P1 != 0x0F)
        {
            P1 = 0x0F;
            switch (P1)
            {
            case 0x07:
                key_value = 1; // 第一列
                break;
            case 0x0B:
                key_value = 2; // 第二列
                break;
            case 0x0D:
                key_value = 3; // 第三列
                break;
            case 0x0E:
                key_value = 4; // 第四列
            }
            P1 = 0xF0;
            switch (P1)
            {
            case 0x70:
                key_value += 0; // 第一行
                break;
            case 0xB0:
                key_value += 4; // 第二行
                break;
            case 0xD0:
                key_value += 8; // 第三行
                break;
            case 0xE0:
                key_value += 12; // 第四行
                break;
            }
            // while (P1!=0xF0);//等待按键松开
        }
    }
    else
    {
        key_value = 0;
    }
    return key_value;
}

#endif // _KEYSCAN_H_