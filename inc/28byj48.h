#ifndef _28BYJ48_H_
#define _28BYJ48_H_

#include <reg52.h>
#include <delay.h>

#define IN1_A P10
#define IN2_B P11
#define IN3_C P12
#define IN4_D P13

void eight_step(char direction,u8 speed)//行动八步，1是逆时针，0是顺时针
{
    char temp=0;
    for(;temp<8;temp++)
    {
        switch ((7-2*temp)*direction+temp)
        {
            case 0:IN1_A=1;IN2_B=0;IN3_C=0;IN4_D=0;break;
            case 1:IN1_A=1;IN2_B=1;IN3_C=0;IN4_D=0;break;
            case 2:IN1_A=0;IN2_B=1;IN3_C=0;IN4_D=0;break;
            case 3:IN1_A=0;IN2_B=1;IN3_C=1;IN4_D=0;break;
            case 4:IN1_A=0;IN2_B=0;IN3_C=1;IN4_D=0;break;
            case 5:IN1_A=0;IN2_B=0;IN3_C=1;IN4_D=1;break;
            case 6:IN1_A=0;IN2_B=0;IN3_C=0;IN4_D=1;break;
            case 7:IN1_A=1;IN2_B=0;IN3_C=0;IN4_D=1;break;
        }
        delay_10us(50*speed);
    }
}


void step_motor(float angle, u8 speed, u8 dir)//尽支持输入正角度；speed值越大，速度越慢，最大速度speed=1；dir=1逆时针，dir=0顺时针
{
    float tmp=0;
    for(;tmp<(angle/0.703125);tmp++)
    {
        eight_step(dir,speed);
    }
}

#endif // _28BYJ48_H_