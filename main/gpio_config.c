#include "include/gpio_config.h"

static void IRAM_ATTR gpio_isr_handler(void* arg)
{
	BaseType_t xHigherPriorityTaskWoken = pdFALSE, xResult;
    uint32_t gpio_num = (uint32_t) arg;
    xResult = xEventGroupSetBitsFromISR( secure_events, THIEF, &xHigherPriorityTaskWoken);
}

void init_gpios(){
//	uart_config_t uart_config = {
//		.baud_rate = 115200,
//		.data_bits = UART_DATA_8_BITS,
//		.parity    = UART_PARITY_DISABLE,
//		.stop_bits = UART_STOP_BITS_1,
//		.flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
//	};
//	uart_driver_install(UART_NUM_0, BUF_SIZE * 2, 0, 0, NULL, 0);
//	uart_param_config(UART_NUM_0, &uart_config);
//	uart_set_pin(UART_NUM_0, PIN_TX, PIN_RX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

	gpio_config_t gpio_aux ={
			.pin_bit_mask = PUERTA_SEL,
			.mode = GPIO_MODE_INPUT,
			.pull_up_en = GPIO_PULLUP_DISABLE,
			.pull_down_en = GPIO_PULLDOWN_DISABLE,
			.intr_type = GPIO_INTR_LOW_LEVEL
	};
	gpio_config(&gpio_aux);
	gpio_isr_handler_add(PUERTA, gpio_isr_handler, (void*) PUERTA);

}
