#ifndef GPIO_HEADER
#define GPIO_HEADER

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "freertos/event_groups.h"
#include "driver/uart.h"
#include "esp_log.h"

#define PUERTA GPIO_NUM_3
#define PUERTA_SEL GPIO_SEL_3
#define ESP_INTR_FLAG_DEFAULT 0
#define THIEF (1<<0)
#define BUF_SIZE (1024)
#define PIN_TX GPIO_NUM_1
#define PIN_RX GPIO_NUM_16

EventGroupHandle_t secure_events;

void init_gpios();
#endif
