#ifndef CUSTOM_H
#define CUSTOM_H

#include "gui_guider.h"

// 闹钟相关变量声明
extern int alarm_hour;
extern int alarm_minute;
extern bool alarm_setting_mode;
extern bool is_setting_hour; // true表示正在设置小时，false表示正在设置分钟

// 闹钟功能函数声明
void init_alarm_clock(void);
void update_alarm_display(lv_ui *ui);
void toggle_alarm_setting_mode(lv_ui *ui);
void increase_alarm_time(lv_ui *ui);
void decrease_alarm_time(lv_ui *ui);

#endif // CUSTOM_H
