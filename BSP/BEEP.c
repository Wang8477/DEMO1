/*********************************************************
*   非常炫酷的无源蜂鸣器放歌驱动                                         
*   基于STM32F411ret6
*********************************************************
*   定时器2设置
*   htim2.Instance = TIM2;
*  	htim2.Init.Prescaler = 3816;						//psc:主要调频率的
* 	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
*  	htim2.Init.Period = 72;									//arr：设为72
* 	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
* 	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;                                          
  	 
*********************************************************
*   接线：                                             
*   tim2ch2  ---> PA1                                       
*********************************************************
更新日志：
2023.4.21 第一版
*/ 

/********************************************************/
#include "BEEP.h"
#include <stdio.h>
#include "main.h"
#include "cmsis_os.h"//freeRTOS中可用，不用freeRTOS，此引用可被注释
#include "tim.h"

int tones[22]={0,3817,3401,3030,2865,2551,2272,2024,1912,1703,1517,1432,1275,1136,1012,956,851,758,715,637,568,5067};
//             0  1    2    3    4    5    6    7    8    9    10   11   12   13   14  15  16  17  18  19  20  21
////                                                                                    .   .   .   .   .   .   .                                                
////			    低音1    2    3    4    5    6    7中音1    2    3    4    5    6    7高音1   2   3   4   5   6   7
////              '    '    '    '    '    '    '
/************************************************************曲库*********************************************************************************/
/***********************************************曲库信息包含音调和每个音的持续时间****************************************************************/
/*****************************0为休止符，8分音符相对持续时间为2，4分音符相对持续时间为4，以此类推*************************************************/
/*************************************************我使用了空格来区分每个小节**********************************************************************/
uint16_t 	dabeizhou_tone[]={8,9,9,9,9,9,10,10,12,10,10,10,9,8,8,10,9,9,9,9,8,6,6,9,9,9,9,10,10,10,12,10,9,8,8,8,8,10,9,9,9,9,9,8,6,6,6,6,9,9,9,9,9,9,10,10,12,10,9,8};
uint16_t  dabeizhou_time[]={250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,};
//第0首大悲咒

uint16_t	molihua_tone[]=	   {10,2,10,12,13,12,15,13  ,12,10,12,13  ,15,16,17,16,15,13,15  ,12  ,12,10,12,13  ,15,16,17,16,13,12  ,12,9,10,12,10,9  ,8,6,8  ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint16_t  molihua_time[]=	   {1,1,1,1,1,1,1,1         ,1,1,4,2      ,2,1,1,1,1,1,1         ,8   ,1,1,4,2      ,2,1,1,1,1,2        ,2,2,1,1,1,1      ,1,1,6  ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//第1首茉莉花
	
uint16_t	lanhuacao_tone[]=	   {6,10,10,10  ,10,9  ,8,9,8,7  ,6  ,13,13,13,13  ,13,12  ,10,12,12,11  ,10  ,10,13,13,12  ,10,9  ,8,9,8,7  ,6,3  ,3,8,8,7  ,6,10  ,9,8,7,5  ,6  ,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint16_t  lanhuacao_time[]=	   {2,2,2,2     ,6,2   ,3,1,2,2  ,8  ,2,2,2,2      ,6,2    ,2,2,2,2      ,8   ,2,2,2,2      ,6,1   ,3,1,2,2  ,4,4  ,2,2,2,2  ,6,2   ,2,2,2,2  ,8  ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//第2首兰花草
	
	
	typedef struct//结构体定义一首歌的两个数组 
{
	uint16_t tone[60];
	uint16_t time[60];
}BEEP_typedef;

#define MUSICn 8 //定义曲库数量，可增删

static BEEP_typedef Musics[MUSICn] = {0};

void Music_Def(void)//将曲库数据导入每首歌的音调和时间数组，可以通过乘以不同的时间来调整每首歌的节奏快慢
{
	int i;
	for(i=0;i<60;i++)
	{
		Musics[MUSIC0].tone[i] = dabeizhou_tone[i];
		Musics[MUSIC0].time[i] = dabeizhou_time[i];
	}
	
	for(i=0;i<60;i++)
	{
		Musics[MUSIC1].tone[i] = molihua_tone[i];
		Musics[MUSIC1].time[i] = molihua_time[i]*250;
	}
	
	for(i=0;i<60;i++)
	{
		Musics[MUSIC2].tone[i] = lanhuacao_tone[i];
		Musics[MUSIC2].time[i] = lanhuacao_time[i]*125;
	}
	

}

void BEEP_Init(void)//蜂鸣器初始化
{
	__HAL_TIM_SET_PRESCALER(&htim2,0);
	__HAL_TIM_SET_AUTORELOAD(&htim2,72);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	Music_Def();
}

void BEEP_voice(int tone,uint8_t volume,uint16_t time)//响一次（音调；音量；持续时间）例：BEEP_voice(4,36,200);
{
		__HAL_TIM_SET_PRESCALER(&htim2,tones[tone]-1);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,volume);
		HAL_Delay(time);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
}

void BEEP_os_voice(int tone,uint8_t volume,uint16_t time)//freeRTOS中可用，不用freeRTOS，此函数可被注释
{
		__HAL_TIM_SET_PRESCALER(&htim2,tones[tone]-1);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,volume);
		osDelay(time);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
}


void BEEP_music(MUSIC_INDEX num,uint8_t volume)//播放音乐（音乐曲目，音量）例： BEEP_music(MUSIC2,36);
{

	int i;
	for(i=0;i<60;i++)
	{	if (Musics[num].tone[i] == 0 )
		{
			HAL_Delay(Musics[num].time[i]);
		}
		else
		{
		BEEP_voice( Musics[num].tone[i],volume,Musics[num].time[i]);
		HAL_Delay(100);
		}
	}
}
void BEEP_os_music(MUSIC_INDEX num,uint8_t volume)
{

	int i;
	for(i=0;i<60;i++)
	{	if (Musics[num].tone[i] == 0 )
		{
			osDelay(Musics[num].time[i]);
		}
		else
		{
		BEEP_voice( Musics[num].tone[i],volume,Musics[num].time[i]);
		osDelay(100);
		}
	}
}
