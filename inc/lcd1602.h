#ifndef _LCD1602_H_
#define _LCD1602_H_

#include <reg52.h>
#include <delay.h>
// sbit EN      = P27;
// sbit RS      = P26;
// sbit RW      = P25;
// sfr DATAPORT = P0;
#define EN P27
#define RS P26
#define RW P25
#define DATAPORT P0

void lcd1602_write_cmd(u8 cmd) // lcd1602写指令函数
{
    RS=0; // 切换到命令模式
    RW=0; // 切换到写数据模式
    EN=0;
    DATAPORT = cmd; // 写命令
    delay_ms(1);
    EN = 1;
    delay_ms(1);
    EN = 0; // EN下降沿示意执行指令
}

void lcd1602_write_data(u8 dat)//写数据函数
{
    RS=1;//输入数据模式
    RW=0;//切换到写数据模式
    EN=0;
    DATAPORT=dat;
    delay_ms(1);
    EN=1;
    delay_ms(1);
    EN=0;
}

void lcd1602_init(void) // lcd1602初始化函数
{
    lcd1602_write_cmd(0x38); // 数据总线 8 位， 显示 2 行， 5*7 点阵/字符
    lcd1602_write_cmd(0x0c); // 显示功能开， 无光标， 光标闪烁
    lcd1602_write_cmd(0x06); // 写入新数据后光标右移， 显示屏不移动
    lcd1602_write_cmd(0x01); // 清屏
}

//LCD1602液晶显示
void lcd1602_clear(void)
{
    lcd1602_write_cmd(0x01);
}

void lcd1602_show_string(u8 x, u8 y, u8 *str) // lcd1602显示函数，x,y分别是第一个字符的横纵坐标-1
{
    u8 i = 0; // i就是一行已经显示了的字符数量
    if (x > 15 || y > 1) 
    {
        return; // 如果输入的坐标不合法，强制退出
    }
    if (y < 1)//第一行显示
    {
        while ((*str) != '\0') 
        {
            if (i < 16 - x) // 第一行能装下
            {
                lcd1602_write_cmd(0x80 + i + x); // 第一行显示地址设置
            } else                               // 第一行装不下的时候，在第二行继续显示
            {
                lcd1602_write_cmd(0x40 + 0x80 + i + x - 16); // 第二行显示地址设置
            }
            lcd1602_write_data(*str);
            str++; // 指针位置后移
            i++;
        }
    }
    else
    //第二行显示,即y=1
    {
        while((*str)!='\0')
        {
            if(i<16-x)//第二行满了就在第一行重写
            {
                lcd1602_write_cmd(0x80+0x40+i+x);//第二行
            }
            else
            {
                lcd1602_write_cmd(0x80+i+x-16);//第一行
            }
            lcd1602_write_data(*str);
            str++;
            i++;
        }
    }
}

#endif // _LCD1602_H_