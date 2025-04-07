#目前实现功能  
页面一：时间表盘显示  
页面二：闹钟设置  
页面三：日期+时间设置  
页面四：显示温度与adc  
按键模拟点击lcd上像素点  

#使用库  
lvgl8.3.11 https://github.com/lvgl/lvgl.git  
st7789_LCD https://github.com/Floyd-Fish/ST7789-STM32.git  
按键驱动  https://github.com/0x1abin/MultiButton.git  
#一些问题  
key.c中按键回调函数没有用到，可以删除或者增加其他功能

