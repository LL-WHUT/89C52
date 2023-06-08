#ifndef _SMG_DIAPLAY_H_
#define _SMG_DIAPLAY_H_

#include<reg52.h>
#include<delay.h>
void Smg_display(u8 *input, int xms)
{
    u8 smg_code[26] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x80, 0x77, 0x39, 0x5E, 0x79, 0x71, 0x76, 0x38, 0x5C, 0x73, 0x3E, 0x7C, 0x58, 0x54, 0x1C, 0x6E};
    u8 i = 0;
    u8 j = 0;
    // u8 t = 0;
    for (; xms != 0; xms--)
    {

        {
            i = 0;
            j = 0;
            while (input[j] != '#')
            {

                {
                    switch (i) // 位选
                    {
                    case 0:
                        P24 = 1;
                        P23 = 1;
                        P22 = 1;
                        break;
                    case 1:
                        P24 = 1;
                        P23 = 1;
                        P22 = 0;
                        break;
                    case 2:
                        P24 = 1;
                        P23 = 0;
                        P22 = 1;
                        break;
                    case 3:
                        P24 = 1;
                        P23 = 0;
                        P22 = 0;
                        break;
                    case 4:
                        P24 = 0;
                        P23 = 1;
                        P22 = 1;
                        break;
                    case 5:
                        P24 = 0;
                        P23 = 1;
                        P22 = 0;
                        break;
                    case 6:
                        P24 = 0;
                        P23 = 0;
                        P22 = 1;
                        break;
                    case 7:
                        P24 = 0;
                        P23 = 0;
                        P22 = 0;
                        break;
                    }
                    switch (input[j])
                    {
                    case '0':
                        P0 = smg_code[0];
                        break;
                    case '1':
                        P0 = smg_code[1];
                        break;
                    case '2':
                        P0 = smg_code[2];
                        break;
                    case '3':
                        P0 = smg_code[3];
                        break;
                    case '4':
                        P0 = smg_code[4];
                        break;
                    case '5':
                        P0 = smg_code[5];
                        break;
                    case '6':
                        P0 = smg_code[6];
                        break;
                    case '7':
                        P0 = smg_code[7];
                        break;
                    case '8':
                        P0 = smg_code[8];
                        break;
                    case '9':
                        P0 = smg_code[9];
                        break;
                    case '.':
                        P0 = smg_code[10];
                        break;
                    case 'A':
                        P0 = smg_code[11];
                        break;
                    case 'C':
                        P0 = smg_code[12];
                        break;
                    case 'd':
                        P0 = smg_code[13];
                        break;
                    case 'E':
                        P0 = smg_code[14];
                        break;
                    case 'F':
                        P0 = smg_code[15];
                        break;
                    case 'H':
                        P0 = smg_code[16];
                        break;
                    case 'L':
                        P0 = smg_code[17];
                        break;
                    case 'o':
                        P0 = smg_code[18];
                        break;
                    case 'P':
                        P0 = smg_code[19];
                        break;
                    case 'U':
                        P0 = smg_code[20];
                        break;
                    case 'b':
                        P0 = smg_code[21];
                        break;
                    case 'c':
                        P0 = smg_code[22];
                        break;
                    case 'n':
                        P0 = smg_code[23];
                        break;
                    case 'u':
                        P0 = smg_code[24];
                        break;
                    case 'y':
                        P0 = smg_code[25];
                        break;
                    default:
                        P0 = 0x00;
                        break;
                    }
                    delay_10us(20);
                    if (input[j + 1] == '.')
                    {
                        P0 = smg_code[10];
                        delay_10us(20);
                        j++;
                    }
                    i++;
                    j++;
                    P0 = 0x00;
                }
            }
        }
    }
}

#endif // _SMG_DIAPLAY_H_