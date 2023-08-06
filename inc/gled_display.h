//矩阵LED显示
#ifndef _GLED_DISPLAY_H_
#define _GLED_DISPLAY_H_

#include<reg52.h>
void hc595_write_data(u8 dat)
{
    u8 i = 0;

    for (i = 0; i < 8; i++) // 循环8次即可将一个字节写入寄存器中
    {
        P34 = dat >> 7; // 优先传输一个字节中的高位
        dat <<= 1;       // 将低位移动到高位
        P36 = 0;
        _nop_();
        P36 = 1;
        _nop_(); // 移位寄存器时钟上升沿将端口数据送入寄存器中
    }
    P35 = 0;
    _nop_();
    P35 = 1; // 存储寄存器时钟上升沿将前面写入到寄存器的数据输出
}

void gled_display(u8 *gled_row, u16 xms)//输入的是纵向取模和持续时间
{
    int j;
    u8 row = 0;
    u8 gled_col[8] = {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe};
    for (j = 0; j < (xms / 3 + 1); ++j)
    {
        for (row = 0; row < 8; row++)
        {
            P0 = gled_col[row];
            hc595_write_data(gled_row[row]);
            _nop_();
            hc595_write_data(0x00);
        }
    }
}

#endif // _GLED_DISPLAY_H_