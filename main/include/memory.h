#ifndef MEMORY_HEADER
#define MEMORY_HEADER

#include "gpio_config.h"
#include <stdio.h>
#include <stdlib.h>
#include "driver/sdmmc_host.h"
#include "driver/sdmmc_defs.h"
#include "sdmmc_cmd.h"
#include "esp_vfs_fat.h"
#include "esp_camera.h"

#define MOUNT_POINT "/sdcard"

void init_sdcard();

#endif
