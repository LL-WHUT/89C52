/**
 * 数据存储芯片AT24C02的读写操作
 */

#ifndef _AT24C02_H_
#define _AT24C02_H_

#include <iic.h>

/**
 * 功能：写一个字节到AT24C02特定的位置
 * 输入：addr --> 写入数据的目的地址
 *       dat --> 要写入的数据(一个字节)
 */
void at24c02_write_one_data(u8 addr, u8 dat)
{
    iic_start();
    iic_write_byte(0XA0); // 发送写命令
    iic_wait_ack();
    iic_write_byte(addr); // 发送写地址
    iic_wait_ack();
    iic_write_byte(dat); // 发送字节
    iic_wait_ack();
    iic_stop();
    delay_ms(10);
}

/**
 * 功能：再AT24C02指定位置读出一个字节
 * 输入：读取数据的地址(一个字节)
 * 输出：读到的数据(一个字节)
 */
u8 at24c02_read_one_data(u8 addr)
{
    u8 temp = 0;
    iic_start();
    iic_write_byte(0XA0); // 发送写命令
    iic_wait_ack();
    iic_write_byte(addr); // 发送写地址
    iic_wait_ack();
    iic_start();
    iic_write_byte(0XA1); // 进入接收模式
    iic_wait_ack();
    temp = iic_read_data(0);
    iic_stop();
    return temp;
}

#endif // _AT24C02_H_