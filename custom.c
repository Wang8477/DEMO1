#include "custom.h"
#include <stdio.h>

// �����������ȫ�ֱ���
int alarm_hour = 0;
int alarm_minute = 0;
bool alarm_setting_mode = false;
bool is_setting_hour = true;

// ��ʼ������
void init_alarm_clock(void) {
    alarm_hour = 0;
    alarm_minute = 0;
    alarm_setting_mode = false;
    is_setting_hour = true;
}

// ����������ʾ
void update_alarm_display(lv_ui *ui) {
    char time_str[10];
    
    // ɾ������span�����´���
    lv_spangroup_del_all_spans(ui->screen_1_spangroup_2);
    
    // Сʱspan
    lv_span_t *hour_span = lv_spangroup_new_span(ui->screen_1_spangroup_2);
    snprintf(time_str, sizeof(time_str), "%02d", alarm_hour);
    lv_span_set_text(hour_span, time_str);
    
    // ����Сʱ�ı���ɫ������ģʽ�¸�����ʾ��
    if (alarm_setting_mode && is_setting_hour) {
        lv_style_set_text_color(&hour_span->style, lv_color_hex(0xFF0000)); // ��ɫ
    } else {
        lv_style_set_text_color(&hour_span->style, lv_color_hex(0x000000)); // ��ɫ
    }
    lv_style_set_text_decor(&hour_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&hour_span->style, &lv_font_montserratMedium_17);
    
    // ð��span
    lv_span_t *colon_span = lv_spangroup_new_span(ui->screen_1_spangroup_2);
    lv_span_set_text(colon_span, " : ");
    lv_style_set_text_color(&colon_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&colon_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&colon_span->style, &lv_font_montserratMedium_17);
    
    // ����span
    lv_span_t *minute_span = lv_spangroup_new_span(ui->screen_1_spangroup_2);
    snprintf(time_str, sizeof(time_str), "%02d", alarm_minute);
    lv_span_set_text(minute_span, time_str);
    
    // ���÷����ı���ɫ������ģʽ�¸�����ʾ��
    if (alarm_setting_mode && !is_setting_hour) {
        lv_style_set_text_color(&minute_span->style, lv_color_hex(0xFF0000)); // ��ɫ
    } else {
        lv_style_set_text_color(&minute_span->style, lv_color_hex(0x000000)); // ��ɫ
    }
    lv_style_set_text_decor(&minute_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&minute_span->style, &lv_font_montserratMedium_17);
    
    // ˢ����ʾ
    lv_spangroup_refr_mode(ui->screen_1_spangroup_2);
}

// �л���������ģʽ
void toggle_alarm_setting_mode(lv_ui *ui) {
    if (!alarm_setting_mode) {
        // ��������ģʽ
        alarm_setting_mode = true;
        is_setting_hour = true; // ������Сʱ
    } else {
        // �Ѿ�������ģʽ�У��л�����Сʱ/����
        if (is_setting_hour) {
            is_setting_hour = false; // �л������÷���
        } else {
            // ������ɣ��˳�����ģʽ
            alarm_setting_mode = false;
        }
    }
    
    // ������ʾ
    update_alarm_display(ui);
}

// ��������ʱ��
void increase_alarm_time(lv_ui *ui) {
    if (!alarm_setting_mode) return; // ֻ��������ģʽ���ܵ���
    
    if (is_setting_hour) {
        alarm_hour = (alarm_hour + 1) % 24; // Сʱ��Χ��0-23
    } else {
        alarm_minute = (alarm_minute + 1) % 60; // ���ӷ�Χ��0-59
    }
    
    update_alarm_display(ui);
}

// ��������ʱ��
void decrease_alarm_time(lv_ui *ui) {
    if (!alarm_setting_mode) return; // ֻ��������ģʽ���ܵ���
    
    if (is_setting_hour) {
        alarm_hour = (alarm_hour - 1 + 24) % 24; // Сʱ��Χ��0-23
    } else {
        alarm_minute = (alarm_minute - 1 + 60) % 60; // ���ӷ�Χ��0-59
    }
    
    update_alarm_display(ui);
}
