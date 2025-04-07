# 使用STM32F411+Freertos+lvgl实现简易电子时钟  

## 硬件

STM32F411RE-Nucleo64核心板  
st7789LCD(8针SPI,BLK浮空可用)  
外围电路  
![屏幕图片](\pic\schematics_1.png "screen")
![屏幕图片](\pic\schematics_2.png "screen")
## 目前实现功能
页面一：时间表盘显示  
页面二：闹钟设置  
页面三：日期+时间设置  
页面四：显示温度与adc  
按键模拟点击lcd上像素点  
蜂鸣器可简易“唱歌”

![屏幕图片](pic\screen.png "screen")

## 使用库
lvgl8.3.11 https://github.com/lvgl/lvgl.git  
st7789_LCD https://github.com/Floyd-Fish/ST7789-STM32.git  
按键驱动  https://github.com/0x1abin/MultiButton.git  
## 一些问题
key.c中按键回调函数没有用到，可以删除或者增加其他功能

