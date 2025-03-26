/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "st7789.h"
#include "key.h"
#include "LM75AD.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
double temperature=0;
volatile  float voltage=0;  
char buffer[100];		
volatile uint16_t adcValue = 0; // ADC
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern osMutexId myMutexHandle;
volatile int con=0;

 lv_ui guider_ui;


extern int screen_analog_clock_1_hour_value ;
extern int screen_analog_clock_1_min_value ;
extern int screen_analog_clock_1_sec_value;
extern unsigned short int alarm_min;
extern unsigned short int alarm_hour;

volatile bool need_ui_update = false; // UI更新标志
// 在main.c中添加UI更新函数
void update_ui_if_needed(void)
{
  static uint32_t last_update = 0;
  uint32_t now = HAL_GetTick();
  
  // 检查当前屏幕是否是screen_3
  bool is_screen3_active = (lv_scr_act() == guider_ui.screen_3);
  
  // 添加额外的安全检查，防止在屏幕切换过程中更新UI
  if(need_ui_update && (now - last_update > 200) && is_screen3_active) {
    // 再次检查确认当前屏幕仍然是screen_3
    if(lv_scr_act() != guider_ui.screen_3) {
      return; // 如果屏幕已经改变，立即退出不更新
    }
    
    last_update = now;
    need_ui_update = false;
    
    // 更新前先检查UI元素是否有效
    if(guider_ui.screen_3_temp != NULL && lv_obj_is_valid(guider_ui.screen_3_temp)) {
      char temp_str[20];
      sprintf(temp_str, "%.1f C", temperature);
      lv_label_set_text(guider_ui.screen_3_temp, temp_str);
    }
    
    if(guider_ui.screen_3_bar_2 != NULL && lv_obj_is_valid(guider_ui.screen_3_bar_2)) {
      int temp_value = (int)(temperature);
      if(temp_value < 0) temp_value = 0;
      if(temp_value > 100) temp_value = 100;
      lv_bar_set_value(guider_ui.screen_3_bar_2, temp_value, LV_ANIM_ON);
    }
    
    // 电压显示和进度条同样添加检查
    if(guider_ui.screen_3_voltage != NULL && lv_obj_is_valid(guider_ui.screen_3_voltage)) {
      char volt_str[20];
      sprintf(volt_str, "%.2f V", voltage);
      lv_label_set_text(guider_ui.screen_3_voltage, volt_str);
    }
    
    if(guider_ui.screen_3_bar_1 != NULL && lv_obj_is_valid(guider_ui.screen_3_bar_1)) {
      int volt_value = (int)(voltage * 100);
      lv_bar_set_value(guider_ui.screen_3_bar_1, volt_value, LV_ANIM_ON);
    }
  }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_RTC_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_SPI1_Init();
  MX_TIM10_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Call init function for freertos objects (in cmsis_os2.c) */
  MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void StartLCDTask(void const * argument)
{
  /* USER CODE BEGIN StartLCDTask */

  lv_init();	
  lv_port_disp_init();
  lv_port_indev_init();
  setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);
  

  /* Infinite loop */
  for(;;)
  {
    
//    //ST7789_DrawFilledRectangle(192, 10, 224, 40, BLACK);
    osMutexWait(myMutexHandle, osWaitForever);
	lv_task_handler();
  update_ui_if_needed();
   osMutexRelease(myMutexHandle);
   osDelay(10);
  }
  /* USER CODE END StartLCDTask */
}
 void StartADCTask(void const * argument)
{
  /* USER CODE BEGIN StartADCTask */
  char volt_str[20];
	//hadc1.Instance->CR2 |= ADC_CR2_DDS;
   // HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adcValue, 1);
  /* Infinite loop */
  for(;;)
  {
     // ADC值
     HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1, 50);   //等待转换完成，50为最大等待时间，单位为ms
		if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
		{
		voltage = HAL_ADC_GetValue(&hadc1)*3.3f/4096;   //获取AD值
		}
    need_ui_update = true;  // 设置更新标志
  //   //voltage = (float)adcValue * 3.3f / 4095.0f;
  //  if(osMutexWait(myMutexHandle, 10) == osOK) {
  //    // 更新屏幕显示（如果当前屏幕是screen_3）
  //    if(lv_scr_act() == guider_ui.screen_3) {
  //      // 更新电压文本
  //      sprintf(volt_str, "%.2f V", voltage);
  //      lv_label_set_text(guider_ui.screen_3_voltage, volt_str);
       
  //      // 更新电压进度条（将电压值映射到0-330范围）
  //      int volt_value = (int)(voltage * 100);
  //      lv_bar_set_value(guider_ui.screen_3_bar_1, volt_value, LV_ANIM_ON);
  //    }
  //    // 释放互斥量
  //    osMutexRelease(myMutexHandle);
  //  }
     osDelay(100);
  }
  /* USER CODE END StartADCTask */
}
void StartTask03(void const * argument)
{
  /* USER CODE BEGIN StartTask03 */
	BTN_Init();
  /* Infinite loop */
  for(;;)
  {
	button_ticks();
    osDelay(5);
  }
  /* USER CODE END StartTask03 */
}

void StartLM75Task(void const * argument)
{
  /* USER CODE BEGIN StartLM75Task */
	LM75AD_Init();
  char temp_str[20];
  /* Infinite loop */
  for(;;)
  {
	temperature = LM75AD_GetTemp();
  need_ui_update = true;  // 设置更新标志
  // 获取互斥量
//    if(osMutexWait(myMutexHandle, 10) == osOK) {
//    // 更新屏幕显示（如果当前屏幕是screen_3）
//    if(lv_scr_act() == guider_ui.screen_3) {
//      // 更新温度文本
//      sprintf(temp_str, "%.1f C", temperature);
//      lv_label_set_text(guider_ui.screen_3_temp, temp_str);
     
//      // 更新温度进度条（假设温度范围是0-100）
//      int temp_value = (int)(temperature);
//      if(temp_value < 0) temp_value = 0;
//      if(temp_value > 100) temp_value = 100;
//      lv_bar_set_value(guider_ui.screen_3_bar_2, temp_value, LV_ANIM_ON);
//    }
//    // 释放互斥量
//    osMutexRelease(myMutexHandle);
//  }
    osDelay(500);
  }
  /* USER CODE END StartLM75Task */
}

void StartBEEPTask(void const * argument)
{
  /* USER CODE BEGIN StartRTCTask */
 
  /* Infinite loop */
  for(;;)
  {
    if(alarm_hour==screen_analog_clock_1_hour_value && alarm_min==screen_analog_clock_1_min_value&&screen_analog_clock_1_sec_value==0)
    {
      HAL_GPIO_TogglePin(BEEP_GPIO_Port,BEEP_Pin);
		osDelay(3000);
		HAL_GPIO_TogglePin(BEEP_GPIO_Port,BEEP_Pin);
    } 
    osDelay(500);
  }
  /* USER CODE END StartRTCTask */
}



/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM4 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM4) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
