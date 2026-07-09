#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_RED     GPIO_NUM_5
#define LED_YELLOW  GPIO_NUM_4
#define LED_GREEN   GPIO_NUM_2
#define LED_WHITE   GPIO_NUM_21
#define LED_BLUE    GPIO_NUM_22

void led_task(void *pvParameter)
{
    gpio_num_t led_gpio = (gpio_num_t)pvParameter;
    TickType_t blink_time;

    if (led_gpio == LED_RED)
    {
        blink_time = pdMS_TO_TICKS(5000);
    }
    else if (led_gpio == LED_YELLOW)
    {
        blink_time = pdMS_TO_TICKS(4000);
    }
    else if (led_gpio == LED_GREEN)
    {
        blink_time = pdMS_TO_TICKS(3000);
    }
    else if (led_gpio == LED_WHITE)
    {
        blink_time = pdMS_TO_TICKS(2000);
    }
    else
    {
        blink_time = pdMS_TO_TICKS(1000); // Blue
    }

    gpio_reset_pin(led_gpio);
    gpio_set_direction(led_gpio, GPIO_MODE_OUTPUT);

    while (1)
    {
        gpio_set_level(led_gpio, 1);
        vTaskDelay(blink_time);

        gpio_set_level(led_gpio, 0);
        vTaskDelay(blink_time);
    }
}

void app_main(void)
{
    xTaskCreate(led_task, "RED",    2048, (void *)LED_RED,    5, NULL);
    xTaskCreate(led_task, "YELLOW", 2048, (void *)LED_YELLOW, 5, NULL);
    xTaskCreate(led_task, "GREEN",  2048, (void *)LED_GREEN,  5, NULL);
    xTaskCreate(led_task, "WHITE",  2048, (void *)LED_WHITE,  5, NULL);
    xTaskCreate(led_task, "BLUE",   2048, (void *)LED_BLUE,   5, NULL);
}
