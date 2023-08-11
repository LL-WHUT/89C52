/**
 * 进行 I2C 通信
 * 起始信号、停止信号、应答和非应答信号
 * help URL https://zhuanlan.zhihu.com/p/137568249
 */
// tip:当SCL为低电平时，SDA的数据无效，一般在这个时候SDA进行电平切换，为下一次表示数据做好准备

#ifndef _IIC_H_
#define _IIC_H_

#include <reg52.h>
#include <delay.h>

// 定义EEPROM控制脚
#define IIC_SCL P21
#define IIC_SDA P20

/**
 * IIC总线产生起始信号
 */
void iic_start(void)
{
    IIC_SDA = 1; // 如果把该条语句放在SCL后面，第二次读写会出现问题。因为开始信号：SCL为高电平时，SDA由高电平向低电平跳变，开始传送数据，数据传输过程中只有在SCL线为低电平期间，SDA上的电平允许变化。
    delay_10us(1);
    IIC_SCL = 1;
    delay_10us(1);
    IIC_SDA = 0; // 当SCL为高电平时，SDA才能由高变低
    delay_10us(1);
    IIC_SCL = 0; // 钳住I2C总线，准备发送或接收数据
    delay_10us(1);
}

/**
 * IIC总线产生停止信号
 */
void iic_stop(void)
{
    IIC_SDA = 0; // 如果把该条语句放在SCL后面，第二次读写会出现问题。因为开始信号：SCL为高电平时，SDA由高电平向低电平跳变，开始传送数据，数据传输过程中只有在SCL线为低电平期间，SDA上的电平允许变化。
    delay_10us(1);
    IIC_SCL = 1; // 当SCL为高电平时，SDA由低变为高
    delay_10us(1);
    IIC_SDA = 1;
    delay_10us(1);
}

/**
 * 产生ACK应答
 */
void iic_ack(void)
{
    IIC_SCL = 0;
    IIC_SDA = 0; // SDA为低电平
    delay_10us(1);
    IIC_SCL = 1;
    delay_10us(1);
    IIC_SCL = 0;
}

/**
 * 产生非ACK应答
 */
void iic_nack(void)
{
    IIC_SCL = 0;
    IIC_SDA = 1; // SDA为高电平
    delay_10us(1);
    IIC_SCL = 1;
    delay_10us(1);
    IIC_SCL = 0;
}

/**
 * 功能：等待应答信号到来
 * 返回值：1 --> 接收应答失败
 *        0 --> 接收应答成功
 */
u8 iic_wait_ack(void)
{
    u8 time_temp = 0;
    IIC_SCL      = 1; //?
    delay_10us(1);
    while (IIC_SDA) {
        time_temp++;
        if (time_temp > 100) // 超时未应答
        {
            iic_stop();
            return 1;
        }
    }
    IIC_SCL = 0;
    return 0;
}

/**
 * 功能：IIC发送一个字节
 * 输入：一个字节
 */
void iic_write_byte(u8 dat)
{
    u8 i    = 0;
    IIC_SCL = 0;            //?
    for (i = 0; i < 8; i++) // 先传高位
    {
        if ((dat & 0x80) > 0) {
            IIC_SDA = 1;
        } else {
            IIC_SDA = 0;
        }
        dat <<= 1;
        delay_10us(1);
        IIC_SCL = 1;
        delay_10us(1);
        IIC_SCL = 0;
        delay_10us(1);
    }
}

/**
 * 功能：IIC读一个字节
 * 输入：0 --> 发送ACK应答
 *      1 --> 发送nACK
 * 输出：一个字节
*/
u8 iic_read_data(u8 ack)
{
    u8 i       = 0;
    u8 receive = 0;
    for (i = 0; i < 8; i++) // 先读高位再传低位
    {
        IIC_SCL = 0;
        delay_10us(1);
        IIC_SCL = 1;
        receive <<= 1;
        if (IIC_SDA) receive++;
        delay_10us(1);
    }
    if (!ack) {
        iic_ack();
    } else {
        iic_nack();
    }
    return receive;
}

#endif // _IIC_H_