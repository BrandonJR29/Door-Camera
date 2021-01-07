#include "include/camera.h"

void app_main(void){
	secure_events = xEventGroupCreate();
	init_camera();
	init_sdcard();
	init_gpios();
}
