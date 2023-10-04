
#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"

void app_main(void)
{
    esp_chip_info_t chip_info;

    esp_chip_info(&chip_info);
    printf(" ESP32 Chip Name: %s\n", CONFIG_IDF_TARGET);
    printf(" ESP32 vesion:%s\n ", esp_get_idf_version());


    printf("This is ESP32 chip with %d CPU core(s) , WiFi%s%s, model:%d \n ",
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "",
           chip_info.model );

    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    printf("ESP32 revision v%d.%d \n ", major_rev, minor_rev);

    printf("%s flash\n",(chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "Embedded" : "External");

    printf("Minimum free heap size: %ld PRIu32 bytes\n", esp_get_minimum_free_heap_size());

    for (int i = 5; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
