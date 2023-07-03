#ifndef _DS18B20_H_
#define _DS18B20_H_

#include <reg52.h>
#include <delay.h>

#define DS18B20_PORT P37

void ds18b20_reset(void)//ds18b20复位函数
{
    DS18B20_PORT=0;
    delay_10us(75);
    DS18B20_PORT=1;
    delay_10us(2);
}

u8 ds18b20_check(void)//检测ds18b20是否正常工作,返回0正常工作，返回1不正常
{
    u8 time_temp=0;
    while (DS18B20_PORT&&time_temp<20)  //等待DQ拉低低电平
    {
        time_temp++;
        delay_10us(1);
    }
    if(time_temp>=20) return 1;//没有拉低电平
    else time_temp=0;
    while ((!DS18B20_PORT)&&time_temp<20)
    {
        time_temp++;
        delay_10us(1);
    }
    if(time_temp>=20) return 1;//拉低电平后没有释放
    return 0;
}

u8 ds18b20_read_bit(void)//读取一个位
{
    u8 dat=0;
    DS18B20_PORT=0;
    _nop_();_nop_();
    DS18B20_PORT=1;
    _nop_();_nop_();
    if(DS18B20_PORT) dat=1;
    else dat=0;
    delay_10us(5);
    return dat;
}

u8 ds18b20_read_byte(void)//读取一个字节
{
    u8 i=0;
    u8 dat=0;
    u8 temp=0;
    for(i=0;i<8;i++)
    {
        temp=ds18b20_read_bit();
        dat=(temp<<7)|(dat>>1);//先读的是低位，需要镜像翻转
    }
    return dat;
}

void ds18b20_write_byte(u8 dat)//写入一个字节
{
    u8 i=0;
    u8 temp=0;

    for(i=0;i<8;i++)
    {
        temp=dat&0x01;
        dat>>=1;
        if(temp)//写1
        {
            DS18B20_PORT=0;
            _nop_();_nop_();
            DS18B20_PORT=1;
            delay_10us(6);
        }
        else//写0
        {
            DS18B20_PORT=0;
            delay_10us(6);
            DS18B20_PORT=1;
            _nop_();_nop_();
        }
    }
}

void ds18b20_start(void)//初始化并开始温度转换
{
    ds18b20_reset();
    ds18b20_check();
    ds18b20_write_byte(0xcc);//Skip ROM
    ds18b20_write_byte(0x44);//温度转换
}

u8 ds18b20_init(void)//初始化
{
    ds18b20_reset();
    return ds18b20_check();
}

float ds18b20_read_temperture(void)
{
    float temp;
    u8 dath=0;//高八位
    u8 datl=0;//低八位
    u16 value=0;//由高八位和低八位转换成的

    ds18b20_start();
    ds18b20_reset();
    ds18b20_check();
    ds18b20_write_byte(0xcc);//Skip ROM
    ds18b20_write_byte(0xbe);//读存储器命令

    datl=ds18b20_read_byte();
    dath=ds18b20_read_byte();
    value=(dath<<8)+datl;//合并为16位数据

    if((value&0xf800)==0xf800)//负温度
    {
        value=(~value)+1;//负数的补码
        temp=value*(-0.0625);
    }
    else//正温度
    {
        temp=value*0.0625;
    }
    return temp;
}

#endif // _DS18B20_H_