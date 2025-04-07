/*********************************************************
*   �ǳ��ſ����Դ�������Ÿ�����                                         
*   ����STM32F411ret6
*********************************************************
*   ��ʱ��2����
*   htim2.Instance = TIM2;
*  	htim2.Init.Prescaler = 3816;						//psc:��Ҫ��Ƶ�ʵ�
* 	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
*  	htim2.Init.Period = 72;									//arr����Ϊ72
* 	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
* 	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;                                          
  	 
*********************************************************
*   ���ߣ�                                             
*   tim2ch2  ---> PA1                                       
*********************************************************
������־��
2023.4.21 ��һ��
*/ 

/********************************************************/
#include "BEEP.h"
#include <stdio.h>
#include "main.h"
#include "cmsis_os.h"//freeRTOS�п��ã�����freeRTOS�������ÿɱ�ע��
#include "tim.h"

int tones[22]={0,3817,3401,3030,2865,2551,2272,2024,1912,1703,1517,1432,1275,1136,1012,956,851,758,715,637,568,5067};
//             0  1    2    3    4    5    6    7    8    9    10   11   12   13   14  15  16  17  18  19  20  21
////                                                                                    .   .   .   .   .   .   .                                                
////			    ����1    2    3    4    5    6    7����1    2    3    4    5    6    7����1   2   3   4   5   6   7
////              '    '    '    '    '    '    '
/************************************************************����*********************************************************************************/
/***********************************************������Ϣ����������ÿ�����ĳ���ʱ��****************************************************************/
/*****************************0Ϊ��ֹ����8��������Գ���ʱ��Ϊ2��4��������Գ���ʱ��Ϊ4���Դ�����*************************************************/
/*************************************************��ʹ���˿ո�������ÿ��С��**********************************************************************/
uint16_t 	dabeizhou_tone[]={8,9,9,9,9,9,10,10,12,10,10,10,9,8,8,10,9,9,9,9,8,6,6,9,9,9,9,10,10,10,12,10,9,8,8,8,8,10,9,9,9,9,9,8,6,6,6,6,9,9,9,9,9,9,10,10,12,10,9,8};
uint16_t  dabeizhou_time[]={250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,};
//��0�״���

uint16_t	molihua_tone[]=	   {10,2,10,12,13,12,15,13  ,12,10,12,13  ,15,16,17,16,15,13,15  ,12  ,12,10,12,13  ,15,16,17,16,13,12  ,12,9,10,12,10,9  ,8,6,8  ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint16_t  molihua_time[]=	   {1,1,1,1,1,1,1,1         ,1,1,4,2      ,2,1,1,1,1,1,1         ,8   ,1,1,4,2      ,2,1,1,1,1,2        ,2,2,1,1,1,1      ,1,1,6  ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//��1������
	
uint16_t	lanhuacao_tone[]=	   {6,10,10,10  ,10,9  ,8,9,8,7  ,6  ,13,13,13,13  ,13,12  ,10,12,12,11  ,10  ,10,13,13,12  ,10,9  ,8,9,8,7  ,6,3  ,3,8,8,7  ,6,10  ,9,8,7,5  ,6  ,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint16_t  lanhuacao_time[]=	   {2,2,2,2     ,6,2   ,3,1,2,2  ,8  ,2,2,2,2      ,6,2    ,2,2,2,2      ,8   ,2,2,2,2      ,6,1   ,3,1,2,2  ,4,4  ,2,2,2,2  ,6,2   ,2,2,2,2  ,8  ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//��2��������
	
	
	typedef struct//�ṹ�嶨��һ�׸���������� 
{
	uint16_t tone[60];
	uint16_t time[60];
}BEEP_typedef;

#define MUSICn 8 //������������������ɾ

static BEEP_typedef Musics[MUSICn] = {0};

void Music_Def(void)//���������ݵ���ÿ�׸��������ʱ�����飬����ͨ�����Բ�ͬ��ʱ��������ÿ�׸�Ľ������
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

void BEEP_Init(void)//��������ʼ��
{
	__HAL_TIM_SET_PRESCALER(&htim2,0);
	__HAL_TIM_SET_AUTORELOAD(&htim2,72);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	Music_Def();
}

void BEEP_voice(int tone,uint8_t volume,uint16_t time)//��һ�Σ�����������������ʱ�䣩����BEEP_voice(4,36,200);
{
		__HAL_TIM_SET_PRESCALER(&htim2,tones[tone]-1);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,volume);
		HAL_Delay(time);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
}

void BEEP_os_voice(int tone,uint8_t volume,uint16_t time)//freeRTOS�п��ã�����freeRTOS���˺����ɱ�ע��
{
		__HAL_TIM_SET_PRESCALER(&htim2,tones[tone]-1);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,volume);
		osDelay(time);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
}


void BEEP_music(MUSIC_INDEX num,uint8_t volume)//�������֣�������Ŀ������������ BEEP_music(MUSIC2,36);
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
