#include "include/camera.h"

static char *TAG = "CAM";

static camera_config_t camera_config = {
    .pin_pwdn  = CAM_PIN_PWDN,
    .pin_reset = CAM_PIN_RESET,
    .pin_xclk = CAM_PIN_XCLK,
    .pin_sscb_sda = CAM_PIN_SIOD,
    .pin_sscb_scl = CAM_PIN_SIOC,

    .pin_d7 = CAM_PIN_D7,
    .pin_d6 = CAM_PIN_D6,
    .pin_d5 = CAM_PIN_D5,
    .pin_d4 = CAM_PIN_D4,
    .pin_d3 = CAM_PIN_D3,
    .pin_d2 = CAM_PIN_D2,
    .pin_d1 = CAM_PIN_D1,
    .pin_d0 = CAM_PIN_D0,
    .pin_vsync = CAM_PIN_VSYNC,
    .pin_href = CAM_PIN_HREF,
    .pin_pclk = CAM_PIN_PCLK,

    //XCLK 20MHz or 10MHz for OV2640 double FPS (Experimental)
    .xclk_freq_hz = 20000000,
    .ledc_timer = LEDC_TIMER_0,
    .ledc_channel = LEDC_CHANNEL_0,

    .pixel_format = PIXFORMAT_JPEG,//YUV422,GRAYSCALE,RGB565,JPEG
    .frame_size = FRAMESIZE_UXGA,//QQVGA-QXGA Do not use sizes above QVGA when not JPEG

    .jpeg_quality = 12, //0-63 lower number means higher quality
    .fb_count = 1 //if more than one, i2s runs in continuous mode. Use only with JPEG
};

esp_err_t init_camera(){
	//power up the camera if PWDN pin is defined

	if(CAM_PIN_PWDN != -1){
		gpio_set_direction(CAM_PIN_PWDN, GPIO_MODE_OUTPUT);
		gpio_set_level(CAM_PIN_PWDN, 0);
	}

	//initialize the camera
	esp_err_t err = esp_camera_init(&camera_config);
	if (err != ESP_OK) {
		ESP_LOGE(TAG, "Camera Init Failed");
		return err;
	}

	xTaskCreatePinnedToCore(TaskCatch, "Task Catch", 1024*8, NULL, 6, NULL, 1);

	return ESP_OK;
}

void TaskCatch(void *param){
	ESP_LOGI(TAG, "Task Catch start");
	static uint64_t counter = 0;
	while(1){
		xEventGroupWaitBits( secure_events, THIEF, pdFALSE, pdTRUE, portMAX_DELAY );
		ESP_LOGI(TAG, "Taking picture...");

		camera_fb_t *pic = esp_camera_fb_get();
		counter++;

		char *pic_name = malloc(30 + sizeof(int64_t));
		sprintf(pic_name, MOUNT_POINT"/pic_%lli.jpg", counter);
		FILE *file = fopen(pic_name, "w");

		if (file != NULL)
		{
			fwrite(pic->buf, 1, pic->len, file);
			ESP_LOGI(TAG, "File saved: %s", pic_name);
		}
		else
		{
			ESP_LOGE(TAG, "Could not open file =(");
		}
		fclose(file);
		free(pic_name);
		xEventGroupClearBits( secure_events, THIEF);
	}
	vTaskDelete(NULL);
}
