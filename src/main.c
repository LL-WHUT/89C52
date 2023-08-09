#include <reg52.h>

void uart_init(u8 baud)
{
    TMOD |= 0x20; // 设置计数器的各种方式为2，工作方式 2 特别适合于用作较精确的脉冲信号发生器
    SCON = 0x50;  // 设置串口工作方式1
    PCON = 0x80;  // 波特率加倍
    TH1  = baud;
    TL1  = baud;
    ES   = 1; // 串行口中断允许
    EA   = 1; // 总中断
    TR1  = 1; // 打开计数器
}

void uart() interrupt 4 // 串口通信函数
{
    u8 rec_data;
    RI       = 0;        // 清除接收中断标志位
    rec_data = SBUF;     // 存储收到的数据
    SBUF     = rec_data; // 将接收到的数据放入到发送寄存器
    while (!TI);   // 等待发送数据完成
    TI = 0; // 清除发送完成标志位
}

void main()
{
    uart_init(0xfa); // 设置波特率为9600
    while (1) {
        ;
    }
}