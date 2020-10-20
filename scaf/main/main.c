#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "jsmn.h"
#include <time.h>
#include "lwip/apps/sntp.h"
#include "driver/gpio.h"

#include "main.h"

int portion;
struct tm scheduled_time;
double weight;

void misc_init(void)
{
    portion = 0;
    scheduled_time.tm_year = 0;
    scheduled_time.tm_mon = 0;
    scheduled_time.tm_mday = 0;
    scheduled_time.tm_hour = 0;
    scheduled_time.tm_min = 0;
    weight = 0;
}

void main_task( void * pvParameters )
{
    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 60000 / portTICK_PERIOD_MS;
    xLastWakeTime = xTaskGetTickCount();  

    for( ;; )
    {
        time_t now = 0;
        struct tm timeinfo = {0};
        time(&now);
        localtime_r(&now, &timeinfo);
        if (scheduled_time.tm_year == timeinfo.tm_year &&
            scheduled_time.tm_year == timeinfo.tm_year &&
            scheduled_time.tm_year == timeinfo.tm_year &&
            scheduled_time.tm_year == timeinfo.tm_year &&
            scheduled_time.tm_year == timeinfo.tm_year)
        {
            rotate(portion);
        }
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}


void app_main()
{
    /* Initialize nvs */
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    /* Initializations */
    misc_init();
    iotc_init();
    motor_init();
    pir_init();

    /* Tasks */
    xTaskCreate(&mqtt_task, "mqtt_task", 8192, NULL, 5, NULL);
    xTaskCreate(weight_task, "weight_task", configMINIMAL_STACK_SIZE * 5, NULL, 5, NULL);
    vTaskStartScheduler();
    // xTaskCreate(&lcd_task, "lcd_task", configMINIMAL_STACK_SIZE * 5, NULL, 5, NULL);
}
