#include "custom.h"
#include <stdio.h>

// 定义闹钟相关全局变量
int alarm_hour = 0;
int alarm_minute = 0;
bool alarm_setting_mode = false;
bool is_setting_hour = true;

// 初始化闹钟
void init_alarm_clock(void) {
    alarm_hour = 0;
    alarm_minute = 0;
    alarm_setting_mode = false;
    is_setting_hour = true;
}

// 更新闹钟显示
void update_alarm_display(lv_ui *ui) {
    char time_str[10];
    
    // 删除所有span并重新创建
    lv_spangroup_del_all_spans(ui->screen_1_spangroup_2);
    
    // 小时span
    lv_span_t *hour_span = lv_spangroup_new_span(ui->screen_1_spangroup_2);
    snprintf(time_str, sizeof(time_str), "%02d", alarm_hour);
    lv_span_set_text(hour_span, time_str);
    
    // 设置小时文本颜色（设置模式下高亮显示）
    if (alarm_setting_mode && is_setting_hour) {
        lv_style_set_text_color(&hour_span->style, lv_color_hex(0xFF0000)); // 红色
    } else {
        lv_style_set_text_color(&hour_span->style, lv_color_hex(0x000000)); // 黑色
    }
    lv_style_set_text_decor(&hour_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&hour_span->style, &lv_font_montserratMedium_17);
    
    // 冒号span
    lv_span_t *colon_span = lv_spangroup_new_span(ui->screen_1_spangroup_2);
    lv_span_set_text(colon_span, " : ");
    lv_style_set_text_color(&colon_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&colon_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&colon_span->style, &lv_font_montserratMedium_17);
    
    // 分钟span
    lv_span_t *minute_span = lv_spangroup_new_span(ui->screen_1_spangroup_2);
    snprintf(time_str, sizeof(time_str), "%02d", alarm_minute);
    lv_span_set_text(minute_span, time_str);
    
    // 设置分钟文本颜色（设置模式下高亮显示）
    if (alarm_setting_mode && !is_setting_hour) {
        lv_style_set_text_color(&minute_span->style, lv_color_hex(0xFF0000)); // 红色
    } else {
        lv_style_set_text_color(&minute_span->style, lv_color_hex(0x000000)); // 黑色
    }
    lv_style_set_text_decor(&minute_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&minute_span->style, &lv_font_montserratMedium_17);
    
    // 刷新显示
    lv_spangroup_refr_mode(ui->screen_1_spangroup_2);
}

// 切换闹钟设置模式
void toggle_alarm_setting_mode(lv_ui *ui) {
    if (!alarm_setting_mode) {
        // 进入设置模式
        alarm_setting_mode = true;
        is_setting_hour = true; // 先设置小时
    } else {
        // 已经在设置模式中，切换设置小时/分钟
        if (is_setting_hour) {
            is_setting_hour = false; // 切换到设置分钟
        } else {
            // 设置完成，退出设置模式
            alarm_setting_mode = false;
        }
    }
    
    // 更新显示
    update_alarm_display(ui);
}

// 增加闹钟时间
void increase_alarm_time(lv_ui *ui) {
    if (!alarm_setting_mode) return; // 只有在设置模式才能调整
    
    if (is_setting_hour) {
        alarm_hour = (alarm_hour + 1) % 24; // 小时范围：0-23
    } else {
        alarm_minute = (alarm_minute + 1) % 60; // 分钟范围：0-59
    }
    
    update_alarm_display(ui);
}

// 减少闹钟时间
void decrease_alarm_time(lv_ui *ui) {
    if (!alarm_setting_mode) return; // 只有在设置模式才能调整
    
    if (is_setting_hour) {
        alarm_hour = (alarm_hour - 1 + 24) % 24; // 小时范围：0-23
    } else {
        alarm_minute = (alarm_minute - 1 + 60) % 60; // 分钟范围：0-59
    }
    
    update_alarm_display(ui);
}
