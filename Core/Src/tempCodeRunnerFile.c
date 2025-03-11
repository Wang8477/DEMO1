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