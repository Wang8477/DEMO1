#ifndef __KEY_H
#define __KEY_H

#include "stdint.h"
#include "main.h"
#include "multi_button.h"


extern bool simulate_touch;
extern lv_coord_t touch_x;
extern lv_coord_t touch_y;
extern bool touch_pressed;


void BTN_Init();
void  BTN1_SINGLE_Click_Handler();
void  BTN2_SINGLE_Click_Handler();
void BTN3_LONG_PRESS_START_Handler();
void  BTN3_SINGLE_Click_Handler();
void  BTN4_SINGLE_Click_Handler();
uint8_t read_button_GPIO(uint8_t button_id);


#endif