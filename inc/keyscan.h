// 矩阵键盘
#ifndef _KEYSCAN_H_
#define _KEYSCAN_H_

// 定义独立按键引脚
#define KEY1 P31
#define KEY2 P30
#define KEY3 P32
#define KEY4 P33

// 定义独立按键按下的值
#define KEY1_PRESS  1
#define KEY2_PRESS  2
#define KEY3_PRESS  3
#define KEY4_PRESS  4
#define KEY_UNPRESS 0

#include <reg52.h>
#include <delay.h>

u8 matrix_key_scan(void) // 矩阵键盘扫描函数，返回按键的位置(1--16)
{
    u8 key_value = 0;
    P1           = 0x0F;
    if (P1 != 0x0F) {
        delay_ms(20);
        if (P1 != 0x0F) {
            P1 = 0x0F;
            switch (P1) {
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
            switch (P1) {
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
    } else {
        key_value = 0;
    }
    return key_value;
}

/*******************************************************************************
* 函 数 名       : key_scan
* 函数功能		 : 检测独立按键是否按下，按下则返回对应键值
* 输    入       : mode=0：单次扫描按键
                   mode=1：连续扫描按键
* 输    出    	 : KEY1_PRESS：K1按下
                   KEY2_PRESS：K2按下
                   KEY3_PRESS：K3按下
                   KEY4_PRESS：K4按下
                   KEY_UNPRESS：未有按键按下
*******************************************************************************/
u8 key_scan(u8 mode)
{
    static u8 key = 1;
    if (mode) key = 1;
    if (key == 1 && (KEY1 == 0 || KEY2 == 0 || KEY3 == 0 || KEY4 == 0)) // 任意键按下
    {
        delay_10us(1000); // 消抖
        key = 0;
        if (KEY1 == 0) {
            return KEY1_PRESS;
        } else if (KEY2 == 0) {
            return KEY2_PRESS;
        } else if (KEY3 == 0) {
            return KEY3_PRESS;
        } else if (KEY4 == 0) {
            return KEY4_PRESS;
        }
    } else if (KEY1 == 1 && KEY2 == 1 && KEY3 == 1 && KEY4 == 1) // 无按键按下
    {
        key = 1;
    }
    return KEY_UNPRESS;
}

#endif // _KEYSCAN_H_