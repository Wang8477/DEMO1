#include "key.h"


struct Button btn1;           //结构化按键
struct Button btn2;
struct Button btn3;
struct Button btn4;


void BTN_Init()
{
	button_init(&btn1, read_button_GPIO, 0, 0);
	button_init(&btn2, read_button_GPIO, 0, 1);
	button_init(&btn3, read_button_GPIO, 0, 2);
	button_init(&btn4, read_button_GPIO, 0, 3);    //初始化按键
	button_attach(&btn1, SINGLE_CLICK, BTN1_SINGLE_Click_Handler);
	button_attach(&btn2, SINGLE_CLICK, BTN2_SINGLE_Click_Handler);
	button_attach(&btn3, SINGLE_CLICK, BTN3_SINGLE_Click_Handler);
	button_attach(&btn3, LONG_PRESS_START, BTN3_LONG_PRESS_START_Handler);
	button_attach(&btn4, SINGLE_CLICK, BTN4_SINGLE_Click_Handler);
	button_start(&btn1);
	button_start(&btn2);
	button_start(&btn3);
	button_start(&btn4);
}

void  BTN1_SINGLE_Click_Handler()
{
  HAL_GPIO_TogglePin(LED3_GPIO_Port ,LED3_Pin);
	HAL_GPIO_TogglePin(LED2_GPIO_Port ,LED2_Pin);
	HAL_GPIO_TogglePin(LED1_GPIO_Port ,LED1_Pin);
}


void  BTN2_SINGLE_Click_Handler()
{
	  HAL_GPIO_TogglePin(LED3_GPIO_Port ,LED3_Pin);
	HAL_GPIO_TogglePin(LED2_GPIO_Port ,LED2_Pin);
	HAL_GPIO_TogglePin(LED1_GPIO_Port ,LED1_Pin);
}


void BTN3_LONG_PRESS_START_Handler()
{
	  HAL_GPIO_TogglePin(LED3_GPIO_Port ,LED3_Pin);
	HAL_GPIO_TogglePin(LED2_GPIO_Port ,LED2_Pin);
	HAL_GPIO_TogglePin(LED1_GPIO_Port ,LED1_Pin);
}


void  BTN3_SINGLE_Click_Handler()
{
	  HAL_GPIO_TogglePin(LED3_GPIO_Port ,LED3_Pin);
	HAL_GPIO_TogglePin(LED2_GPIO_Port ,LED2_Pin);
	HAL_GPIO_TogglePin(LED1_GPIO_Port ,LED1_Pin);
}


void  BTN4_SINGLE_Click_Handler()
{ 
	  HAL_GPIO_TogglePin(LED3_GPIO_Port ,LED3_Pin);
	HAL_GPIO_TogglePin(LED2_GPIO_Port ,LED2_Pin);
	HAL_GPIO_TogglePin(LED1_GPIO_Port ,LED1_Pin);
}


uint8_t read_button_GPIO(uint8_t button_id)
{
	switch(button_id)
	{
		case 0:
			return HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin);
		case 1:
			return HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin);
		case 2:
			return HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin);
		case 3:
			return HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin);
		default:
			return 0;
	}
}