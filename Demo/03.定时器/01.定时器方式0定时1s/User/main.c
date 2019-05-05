#include "reg52.h"
#include "main.h"
#include "bsp_delay.h"

#define Segment P0
#define Digital P2

/* 数码管段选码、位选码 */
u8 SegCode[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};      // 段选低电平有效
u8 DigCode[4] = {0xfe, 0xfd, 0xfb, 0xf7};                                           // 位选低电平有效

/* 数码管显示的值 */
int value[4] = {1, 2, 3, 4};

int main(void)
{
    int i = 0;

    while(1)
    {
        for(i = 0; i < 4; i++)
        {
            Digital = DigCode[i];
            Segment = SegCode[value[i]];
            delay_ms(1);
        }
    }
}
