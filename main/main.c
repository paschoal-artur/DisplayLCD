#include <stdio.h>
#include <driver/i2c.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <sdkconfig.h>
#include "display.h"

#define FLOW_SENSOR_PIN GPIO_NUM_15 // Substitua pelo pino ao qual o sensor está conectado
#define LCD_NUM_ROWS 2
#define LCD_NUM_COLS 16
#define LCD_ADDR 0x27 // check with i2c_tools
#define LCD_SDA GPIO_NUM_21
#define LCD_SCL GPIO_NUM_22

lcd_t configura_lcd(){
    lcd_t lcd = {
        .rows = LCD_NUM_ROWS,
        .cols = LCD_NUM_COLS,
        .addr = LCD_ADDR,
        .sda = LCD_SDA,
        .scl = LCD_SCL,
        .backlightval = LCD_BACKLIGHT,
        .charsize = LCD_5x8DOTS,
    };

    i2c_init(&lcd);
    lcd_begin(&lcd);
    lcd_backlight(&lcd);
    return lcd;
}

void app_main(void)
{
    lcd_t lcd = configura_lcd();
    char buffer[100];
    lcd_set_cursor(&lcd, 0, 0);
    lcd_print(&lcd, "Olá mundo");
    //LCD_init(LCD_ADDR, SDA_PIN, SCL_PIN, LCD_COLS, LCD_ROWS);
    //xTaskCreate(&LCD_DemoTask, "Demo Task", 2048, NULL, 5, NULL);
}
