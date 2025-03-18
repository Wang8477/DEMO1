#ifndef CUSTOM_H
#define CUSTOM_H

#include "gui_guider.h"

// ������ر�������
extern int alarm_hour;
extern int alarm_minute;
extern bool alarm_setting_mode;
extern bool is_setting_hour; // true��ʾ��������Сʱ��false��ʾ�������÷���

// ���ӹ��ܺ�������
void init_alarm_clock(void);
void update_alarm_display(lv_ui *ui);
void toggle_alarm_setting_mode(lv_ui *ui);
void increase_alarm_time(lv_ui *ui);
void decrease_alarm_time(lv_ui *ui);

#endif // CUSTOM_H
