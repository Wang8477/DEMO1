
#ifndef __BEEP_H
#define __BEEP_H

#include "stm32f4xx_hal.h"


//结构体定义曲目对应编号
typedef enum
{
    MUSIC0 = 0,
    MUSIC1 = 1,
    MUSIC2 = 2,
    MUSIC3 = 3,
    MUSIC4 = 4,
    MUSIC5 = 5,
    MUSIC6 = 6,
    MUSIC7 = 7,
}MUSIC_INDEX;



extern void BEEP_Init(void);
extern void BEEP_os_voice(int tone,uint8_t volume,uint16_t time);
extern void BEEP_voice(int tone,uint8_t volume,uint16_t time);
extern void BEEP_music(MUSIC_INDEX num,uint8_t volume);
void BEEP_os_music(MUSIC_INDEX num,uint8_t volume);















































#endif