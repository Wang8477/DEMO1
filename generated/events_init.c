/*
* Copyright 2025 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

extern int screen_analog_clock_1_hour_value ;
extern int screen_analog_clock_1_min_value ;
extern int screen_analog_clock_1_sec_value;
extern volatile bool need_ui_update;
static bool set_flag=false;

unsigned short int alarm_min=0;
unsigned short int alarm_hour=0;
static char buf[4];
static unsigned short int month=3,day=16,hour=4,min=0,date_month=3,date_day=16;
static unsigned short int set_clock_flag=0;
static unsigned short int set_clock=0;
static void screen_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}
static void screen_btn_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_3, guider_ui.screen_3_del, &guider_ui.screen_del, setup_scr_screen_3, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}
void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_btn_1, screen_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_btn_2, screen_btn_2_event_handler, LV_EVENT_ALL, ui);
}
static void screen_1_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_2, guider_ui.screen_2_del, &guider_ui.screen_1_del, setup_scr_screen_2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}
static void screen_1_btn_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui = lv_event_get_user_data(e);
	  set_flag=!set_flag;
	  switch(set_flag)
	  {
	    case true :
	      lv_obj_set_style_text_color(ui->screen_1_alarm_min, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	      lv_obj_set_style_border_width(ui->screen_1_alarm_min, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	      lv_obj_set_style_text_color(ui->screen_1_alarm_hour, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	      lv_obj_set_style_border_width(ui->screen_1_alarm_hour, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	      lv_obj_set_style_border_color(ui->screen_1_alarm_hour, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	      break;
	    case false :
	    lv_obj_set_style_text_color(ui->screen_1_alarm_hour, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_border_width(ui->screen_1_alarm_hour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_text_color(ui->screen_1_alarm_min, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_border_width(ui->screen_1_alarm_min, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_border_color(ui->screen_1_alarm_min, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	    break;
	    default:break;
	  }
	
		break;
	}
	default:
		break;
	}
}
static void screen_1_btn_3_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		
	lv_ui *ui = lv_event_get_user_data(e);
	if(set_flag==false)
	{
	if(alarm_min<59)alarm_min++;
	else alarm_min=0;
	lv_roller_set_selected(ui->screen_1_roller_2, alarm_min, LV_ANIM_ON);
	sprintf(buf,"%02d",alarm_min);
	lv_label_set_text(ui->screen_1_alarm_min, buf);
	// 更新对应的滚动选择器
		}
	if(set_flag==true)
	{
	if(alarm_hour<11)alarm_hour++;
	else alarm_hour=0;
	lv_roller_set_selected(ui->screen_1_roller_1, alarm_hour, LV_ANIM_ON);

	sprintf(buf,"%02d",alarm_hour);
	lv_label_set_text(ui->screen_1_alarm_hour, buf);
	// 更新对应的滚动选择器
		}
		break;
	}
	default:
		break;
	}
}
static void screen_1_btn_4_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_ui *ui = lv_event_get_user_data(e);
	if(set_flag==false)
	{
	if(alarm_min>0)alarm_min--;
	else alarm_min=59;
	lv_roller_set_selected(ui->screen_1_roller_2, alarm_min, LV_ANIM_ON);

	sprintf(buf,"%02d",alarm_min);
	lv_label_set_text(ui->screen_1_alarm_min, buf);
	// 更新对应的滚动选择器
		}
	else{
	if(alarm_hour>0)alarm_hour--;
	else alarm_hour=11;
	lv_roller_set_selected(ui->screen_1_roller_1, alarm_hour, LV_ANIM_ON);

	sprintf(buf,"%02d",alarm_hour);
	lv_label_set_text(ui->screen_1_alarm_hour, buf);
	// 更新对应的滚动选择器
		}
		break;
	}
	default:
		break;
	}
}
void events_init_screen_1(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_1_btn_1, screen_1_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_1_btn_2, screen_1_btn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_1_btn_3, screen_1_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_1_btn_4, screen_1_btn_4_event_handler, LV_EVENT_ALL, ui);
}
static void screen_2_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_3, guider_ui.screen_3_del, &guider_ui.screen_2_del, setup_scr_screen_3, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}
static void screen_2_btn_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		if(set_clock==1)
	{
	  set_clock_flag++;
	  if(set_clock_flag==4)set_clock_flag=0;
		switch(set_clock_flag)
		{
		  case 0:
		    lv_obj_set_style_text_color(guider_ui.screen_2_month, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    lv_obj_set_style_text_color(guider_ui.screen_2_day, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    lv_obj_set_style_text_color(guider_ui.screen_2_hour, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    lv_obj_set_style_text_color(guider_ui.screen_2_min, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    break;
		  case 1:
		    lv_obj_set_style_text_color(guider_ui.screen_2_month, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    lv_obj_set_style_text_color(guider_ui.screen_2_day, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    lv_obj_set_style_text_color(guider_ui.screen_2_hour, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    lv_obj_set_style_text_color(guider_ui.screen_2_min, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    break;
		  case 2:
		    lv_obj_set_style_text_color(guider_ui.screen_2_month, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    lv_obj_set_style_text_color(guider_ui.screen_2_day, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    lv_obj_set_style_text_color(guider_ui.screen_2_hour, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    lv_obj_set_style_text_color(guider_ui.screen_2_min, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		    break;
		  case 3:
		  lv_obj_set_style_text_color(guider_ui.screen_2_month, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		  lv_obj_set_style_text_color(guider_ui.screen_2_day, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		  lv_obj_set_style_text_color(guider_ui.screen_2_hour, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		  lv_obj_set_style_text_color(guider_ui.screen_2_min, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);	}
		break;
	}
	default:
		break;
	}
	}
}
static void screen_2_btn_3_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		if(set_clock_flag==0&&set_clock==1)
		{
	  	month=(1+month)%13;
	  	sprintf(buf,"%02d",month);
	  	lv_label_set_text(guider_ui.screen_2_month, buf);
		}
		if(set_clock_flag==1&&set_clock==1)
		{
	  	day=(1+day)%31;
	  	sprintf(buf,"%02d",day);
	  	lv_label_set_text(guider_ui.screen_2_day, buf);
		}
		if(set_clock_flag==2&&set_clock==1)
		{
	  	hour=(1+hour)%12;
	  	sprintf(buf,"%02d",hour);
	  	lv_label_set_text(guider_ui.screen_2_hour, buf);
		}
		if(set_clock_flag==3&&set_clock==1)
		{
	  	min=(1+min)%60;
	  	sprintf(buf,"%02d",min);
	  	lv_label_set_text(guider_ui.screen_2_min, buf);
		}
		break;
	}
	default:
		break;
	}
}
static void screen_2_btn_4_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		set_clock=1+set_clock%3;
		lv_obj_set_style_text_color(guider_ui.screen_2_month, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_text_color(guider_ui.screen_2_day, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_text_color(guider_ui.screen_2_hour, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_text_color(guider_ui.screen_2_min, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		if(set_clock==2)
		{
			date_month = month;
			date_day = day;
			screen_analog_clock_1_hour_value = hour;
            screen_analog_clock_1_min_value = min;
            screen_analog_clock_1_sec_value = 0;  // 秒钟重置为0
			set_clock_flag=0;
			lv_obj_set_style_text_color(guider_ui.screen_2_month, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(guider_ui.screen_2_day, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(guider_ui.screen_2_hour, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(guider_ui.screen_2_min, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
		}
		break;
	}
	default:
		break;
	}
}
void events_init_screen_2(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_2_btn_1, screen_2_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_2_btn_2, screen_2_btn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_2_btn_3, screen_2_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_2_btn_4, screen_2_btn_4_event_handler, LV_EVENT_ALL, ui);
}
static void screen_3_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.screen_3_del, setup_scr_screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, true, true);
		break;
	}
	default:
		break;
	}
}
static void screen_3_temp_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		
		break;
	}
	default:
		break;
	}
}
static void screen_3_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
    	need_ui_update = false; // 阻止UI更新
		ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.screen_3_del, setup_scr_screen, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, true, true);
		char date_buf[20];
        sprintf(date_buf, "2025/%02d/%02d", date_month, date_day);
        lv_label_set_text(guider_ui.screen_datetext_1, date_buf);
		break;
	}
	default:
		break;
	}
}
void events_init_screen_3(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_3, screen_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_3_temp, screen_3_temp_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_3_btn_1, screen_3_btn_1_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
