#ifndef __KEY_H
#define __KEY_H

#include "stdint.h"
#include "main.h"
#include "multi_button.h"



void BTN_Init();
void  BTN1_SINGLE_Click_Handler();
void  BTN2_SINGLE_Click_Handler();
void BTN3_LONG_PRESS_START_Handler();
void  BTN3_SINGLE_Click_Handler();
void  BTN4_SINGLE_Click_Handler();
uint8_t read_button_GPIO(uint8_t button_id);


#endif