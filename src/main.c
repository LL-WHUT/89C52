#include <reg52.h>
#include <keyscan.h>
#include <iic.h>
#include <at24c02.h>
void main()
{
    while (1) {
        if (key_scan(0)) {
            P20 = !P20;
            delay_ms(500);
        }
    }
}