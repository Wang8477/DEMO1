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
  char localBuffer[32];
  char timeBuffer[32];
  char dateBuffer[32];
  RTC_TimeTypeDef sTime;
 RTC_DateTypeDef sDate;
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
//   osDelay(100);
//   ST7789_Init();
//   ST7789_Fill_Color(BLACK); // 
//   // ���ڼ��仯�ı���
//   double last_temp = -100.0;
//   float last_voltage = -1.0;
//   uint8_t last_second = 0xFF;
//   uint8_t last_minute = 0xFF;
//   uint8_t last_hour = 0xFF;
//   uint8_t last_day = 0;
//   uint8_t last_month = 0;
//   uint8_t last_year = 0;
   
   // ����ʾһ�ι̶�����
//   sprintf(localBuffer, "Temperature:      C");
//   ST7789_WriteString(5, 10, localBuffer, Font_11x18, WHITE, BLACK);
//   
//   sprintf(localBuffer, "Voltage:      V");
//   ST7789_WriteString(5, 40, localBuffer, Font_11x18, YELLOW, BLACK);
//   
//   ST7789_WriteString(5, 70, "Time:         ", Font_11x18, WHITE, BLACK);
//   ST7789_WriteString(5, 100, "Date:         ", Font_11x18, WHITE, BLACK);


  lv_init();	
  lv_port_disp_init();
  
  lv_obj_t * led1  = lv_led_create(lv_scr_act());
    lv_obj_align(led1, LV_ALIGN_CENTER, -80, 0);
    lv_led_off(led1);
 
    /*Copy the previous LED and set a brightness*/
    lv_obj_t * led2  = lv_led_create(lv_scr_act());
    lv_obj_align(led2, LV_ALIGN_CENTER, 0, 0);
    lv_led_set_brightness(led2, 150);
    lv_led_set_color(led2, lv_palette_main(LV_PALETTE_RED));
 
    /*Copy the previous LED and switch it ON*/
    lv_obj_t * led3  = lv_led_create(lv_scr_act());
    lv_obj_align(led3, LV_ALIGN_CENTER, 80, 0);
    lv_led_on(led3);
  /* Infinite loop */
  for(;;)
  {
    
//    //ST7789_DrawFilledRectangle(192, 10, 224, 40, BLACK);
    osMutexWait(myMutexHandle, osWaitForever);
	lv_task_handler();
//    
//    if(last_temp != temperature) {
//      sprintf(localBuffer, "%.2f", temperature);
//      ST7789_WriteString(141, 10, localBuffer, Font_11x18, WHITE, BLACK);
//      last_temp = temperature;
//    }
//    
//    // ֻˢ�µ�ѹ��ֵ����
//    if(last_voltage != voltage) {
//      sprintf(localBuffer, "%.2f", voltage);
//      ST7789_WriteString(101, 40, localBuffer, Font_11x18, YELLOW, BLACK);
//      last_voltage = voltage;
//    }
//    
//    // ��ȡʱ�������?
//    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
//    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
//    
//    // ֻ�����?ʱˢ��ʱ��
//    if(last_second != sTime.Seconds || last_minute != sTime.Minutes || last_hour != sTime.Hours) {
//      sprintf(timeBuffer, "%02d:%02d:%02d", sTime.Hours, sTime.Minutes, sTime.Seconds);
//      ST7789_WriteString(60, 70, timeBuffer, Font_11x18, WHITE, BLACK);
//      last_second = sTime.Seconds;
//      last_minute = sTime.Minutes;
//      last_hour = sTime.Hours;
//    }
//    
//    // ֻ�����ڱ仯ʱˢ������
//    if(last_day != sDate.Date || last_month != sDate.Month || last_year != sDate.Year) {
//      sprintf(dateBuffer, "%02d-%02d-%04d", sDate.Date, sDate.Month, 2000 + sDate.Year);
//      ST7789_WriteString(60, 100, dateBuffer, Font_11x18, WHITE, BLACK);
//      last_day = sDate.Date;
//      last_month = sDate.Month;
//      last_year = sDate.Year;
//    }
//    
//    // ��С�ӳ������Ӧ��?
//    osDelay(10);
   osMutexRelease(myMutexHandle);
   osDelay(10);
  }
  /* USER CODE END StartLCDTask */
}
 void StartADCTask(void const * argument)
{
  /* USER CODE BEGIN StartADCTask */
	//hadc1.Instance->CR2 |= ADC_CR2_DDS;
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adcValue, 1);
  /* Infinite loop */
  for(;;)
  {
     // ADCֵ
	
     voltage = (float)adcValue * 3.3f / 4095.0f;
    
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
  /* Infinite loop */
  for(;;)
  {
	temperature = LM75AD_GetTemp();
    osDelay(500);
  }
  /* USER CODE END StartLM75Task */
}

void StartRTCTask(void const * argument)
{
  /* USER CODE BEGIN StartRTCTask */
 
  /* Infinite loop */
  for(;;)
  {

    
    osDelay(1000);
  }
  /* USER CODE END StartRTCTask */
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  if(hadc->Instance == ADC1) {
        
        HAL_ADC_Stop_DMA(&hadc1);
        HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adcValue, 1);
  
  }
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
