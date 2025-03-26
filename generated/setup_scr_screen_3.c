/*
* Copyright 2025 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_3(lv_ui *ui)
{
	//Write codes screen_3
	ui->screen_3 = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_3, 240, 280);
	lv_obj_set_scrollbar_mode(ui->screen_3, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_3, 226, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_3_cont_1
	ui->screen_3_cont_1 = lv_obj_create(ui->screen_3);
	lv_obj_set_pos(ui->screen_3_cont_1, 0, 0);
	lv_obj_set_size(ui->screen_3_cont_1, 240, 220);
	lv_obj_set_scrollbar_mode(ui->screen_3_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_3_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_3_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_3_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_3_cont_1, lv_color_hex(0xb0b0b0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_3_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_3_cont_1, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_3_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_3_cont_1, lv_color_hex(0xb3b3b3), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_3_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_3_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_3_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_3_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_3_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_3_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_3_list_1
	ui->screen_3_list_1 = lv_list_create(ui->screen_3_cont_1);
	ui->screen_3_list_1_item0 = lv_list_add_btn(ui->screen_3_list_1, LV_SYMBOL_EDIT, "wang");
	ui->screen_3_list_1_item1 = lv_list_add_btn(ui->screen_3_list_1, LV_SYMBOL_CALL, "114514");
	ui->screen_3_list_1_item2 = lv_list_add_btn(ui->screen_3_list_1, LV_SYMBOL_WIFI, "Mr.Wang");
	lv_obj_set_pos(ui->screen_3_list_1, 27, 105);
	lv_obj_set_size(ui->screen_3_list_1, 183, 106);
	lv_obj_set_scrollbar_mode(ui->screen_3_list_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for &style_screen_3_list_1_main_main_default
	static lv_style_t style_screen_3_list_1_main_main_default;
	ui_init_style(&style_screen_3_list_1_main_main_default);
	
	lv_style_set_pad_top(&style_screen_3_list_1_main_main_default, 13);
	lv_style_set_pad_left(&style_screen_3_list_1_main_main_default, 34);
	lv_style_set_pad_right(&style_screen_3_list_1_main_main_default, 25);
	lv_style_set_pad_bottom(&style_screen_3_list_1_main_main_default, 11);
	lv_style_set_bg_opa(&style_screen_3_list_1_main_main_default, 242);
	lv_style_set_bg_color(&style_screen_3_list_1_main_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_dither_mode(&style_screen_3_list_1_main_main_default, LV_DITHER_ORDERED);
	lv_style_set_bg_grad_dir(&style_screen_3_list_1_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_grad_color(&style_screen_3_list_1_main_main_default, lv_color_hex(0x00b6ff));
	lv_style_set_bg_main_stop(&style_screen_3_list_1_main_main_default, 0);
	lv_style_set_bg_grad_stop(&style_screen_3_list_1_main_main_default, 255);
	lv_style_set_border_width(&style_screen_3_list_1_main_main_default, 1);
	lv_style_set_border_opa(&style_screen_3_list_1_main_main_default, 255);
	lv_style_set_border_color(&style_screen_3_list_1_main_main_default, lv_color_hex(0x0077ff));
	lv_style_set_border_side(&style_screen_3_list_1_main_main_default, LV_BORDER_SIDE_NONE);
	lv_style_set_radius(&style_screen_3_list_1_main_main_default, 35);
	lv_style_set_shadow_width(&style_screen_3_list_1_main_main_default, 1);
	lv_style_set_shadow_color(&style_screen_3_list_1_main_main_default, lv_color_hex(0x558cba));
	lv_style_set_shadow_opa(&style_screen_3_list_1_main_main_default, 99);
	lv_style_set_shadow_spread(&style_screen_3_list_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_screen_3_list_1_main_main_default, 10);
	lv_style_set_shadow_ofs_y(&style_screen_3_list_1_main_main_default, 6);
	lv_obj_add_style(ui->screen_3_list_1, &style_screen_3_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_3_list_1_main_scrollbar_default
	static lv_style_t style_screen_3_list_1_main_scrollbar_default;
	ui_init_style(&style_screen_3_list_1_main_scrollbar_default);
	
	lv_style_set_radius(&style_screen_3_list_1_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_3_list_1_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_3_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_3_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->screen_3_list_1, &style_screen_3_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_3_list_1_extra_btns_main_default
	static lv_style_t style_screen_3_list_1_extra_btns_main_default;
	ui_init_style(&style_screen_3_list_1_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_screen_3_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_left(&style_screen_3_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_right(&style_screen_3_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_bottom(&style_screen_3_list_1_extra_btns_main_default, 5);
	lv_style_set_border_width(&style_screen_3_list_1_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_screen_3_list_1_extra_btns_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_3_list_1_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_screen_3_list_1_extra_btns_main_default, 255);
	lv_style_set_radius(&style_screen_3_list_1_extra_btns_main_default, 3);
	lv_style_set_bg_opa(&style_screen_3_list_1_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_3_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_3_list_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->screen_3_list_1_item2, &style_screen_3_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_3_list_1_item1, &style_screen_3_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_3_list_1_item0, &style_screen_3_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_3_list_1_extra_texts_main_default
	static lv_style_t style_screen_3_list_1_extra_texts_main_default;
	ui_init_style(&style_screen_3_list_1_extra_texts_main_default);
	
	lv_style_set_pad_top(&style_screen_3_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_left(&style_screen_3_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_right(&style_screen_3_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_bottom(&style_screen_3_list_1_extra_texts_main_default, 5);
	lv_style_set_border_width(&style_screen_3_list_1_extra_texts_main_default, 0);
	lv_style_set_text_color(&style_screen_3_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_3_list_1_extra_texts_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_screen_3_list_1_extra_texts_main_default, 255);
	lv_style_set_radius(&style_screen_3_list_1_extra_texts_main_default, 3);
	lv_style_set_bg_opa(&style_screen_3_list_1_extra_texts_main_default, 255);
	lv_style_set_bg_color(&style_screen_3_list_1_extra_texts_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_3_list_1_extra_texts_main_default, LV_GRAD_DIR_NONE);

	//Write codes screen_3_bar_2
	ui->screen_3_bar_2 = lv_bar_create(ui->screen_3_cont_1);
	lv_obj_set_style_anim_time(ui->screen_3_bar_2, 1000, 0);
	lv_bar_set_mode(ui->screen_3_bar_2, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->screen_3_bar_2, 0, 100);
	lv_bar_set_value(ui->screen_3_bar_2, 25, LV_ANIM_ON);
	lv_obj_set_pos(ui->screen_3_bar_2, 24, 28);
	lv_obj_set_size(ui->screen_3_bar_2, 125, 20);

	//Write style for screen_3_bar_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_3_bar_2, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_3_bar_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_3_bar_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_3_bar_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_3_bar_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_3_bar_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_3_bar_2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_3_bar_2, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_3_bar_2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_3_bar_2, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_3_bar_1
	ui->screen_3_bar_1 = lv_bar_create(ui->screen_3_cont_1);
	lv_obj_set_style_anim_time(ui->screen_3_bar_1, 1000, 0);
	lv_bar_set_mode(ui->screen_3_bar_1, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->screen_3_bar_1, 0, 330);
	lv_bar_set_value(ui->screen_3_bar_1, 0, LV_ANIM_ON);
	lv_obj_set_pos(ui->screen_3_bar_1, 24, 54);
	lv_obj_set_size(ui->screen_3_bar_1, 125, 20);

	//Write style for screen_3_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_3_bar_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_3_bar_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_3_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_3_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_3_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_3_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_3_bar_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_3_bar_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_3_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_3_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_3_label_2
	ui->screen_3_label_2 = lv_label_create(ui->screen_3_cont_1);
	lv_label_set_text(ui->screen_3_label_2, "temp");
	lv_label_set_long_mode(ui->screen_3_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_3_label_2, 55, 7);
	lv_obj_set_size(ui->screen_3_label_2, 58, 15);

	//Write style for screen_3_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_3_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_3_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_3_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_3_label_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_3_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_3_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_3_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_3_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_3_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_3_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_3_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_3_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_3_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_3_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_3_label_1
	ui->screen_3_label_1 = lv_label_create(ui->screen_3_cont_1);
	lv_label_set_text(ui->screen_3_label_1, "voltage\n");
	lv_label_set_long_mode(ui->screen_3_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_3_label_1, 32, 80);
	lv_obj_set_size(ui->screen_3_label_1, 108, 15);

	//Write style for screen_3_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_3_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_3_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_3_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_3_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_3_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_3_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_3_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_3_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_3_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_3_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_3_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_3_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_3_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_3_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_3_temp
	ui->screen_3_temp = lv_label_create(ui->screen_3_cont_1);
	lv_label_set_text(ui->screen_3_temp, "25 C");
	lv_label_set_long_mode(ui->screen_3_temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_3_temp, 156, 30);
	lv_obj_set_size(ui->screen_3_temp, 66, 16);

	//Write style for screen_3_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_3_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_3_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_3_temp, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_3_temp, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_3_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_3_temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_3_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_3_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_3_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_3_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_3_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_3_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_3_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_3_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_3_voltage
	ui->screen_3_voltage = lv_label_create(ui->screen_3_cont_1);
	lv_label_set_text(ui->screen_3_voltage, "0 V");
	lv_label_set_long_mode(ui->screen_3_voltage, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_3_voltage, 156, 56);
	lv_obj_set_size(ui->screen_3_voltage, 66, 16);

	//Write style for screen_3_voltage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_3_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_3_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_3_voltage, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_3_voltage, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_3_voltage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_3_voltage, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_3_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_3_voltage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_3_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_3_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_3_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_3_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_3_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_3_voltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_3_btn_1
	ui->screen_3_btn_1 = lv_btn_create(ui->screen_3);
	ui->screen_3_btn_1_label = lv_label_create(ui->screen_3_btn_1);
	lv_label_set_text(ui->screen_3_btn_1_label, "Next\n");
	lv_label_set_long_mode(ui->screen_3_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_3_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_3_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_3_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_3_btn_1, 18, 230);
	lv_obj_set_size(ui->screen_3_btn_1, 204, 41);

	//Write style for screen_3_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_3_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_3_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_3_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_3_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_3_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_3_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_3_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_3_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_3_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_3_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen_3.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_3);

	//Init events for screen.
	events_init_screen_3(ui);
}
