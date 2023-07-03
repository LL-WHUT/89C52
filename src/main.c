#include <lcd1602.h>

void main()
{
    lcd1602_init();
    lcd1602_show_string(0, 0, "xx-dev.cn");
    lcd1602_show_string(0, 1, "ling");


    while (1) {
    }
}