#ifndef SCAF_IOT_H
#define SCAF_IOT_H

#include "globals.h"

/* Google IoT Paths Definitions */
#define DEVICE_PATH "projects/%s/locations/%s/registries/%s/devices/%s"
#define SUBSCRIBE_TOPIC_COMMAND "/devices/%s/commands/#"
#define SUBSCRIBE_TOPIC_CONFIG "/devices/%s/config"
#define PUBLISH_TOPIC_EVENT "/devices/%s/events"
#define PUBLISH_TOPIC_STATE "/devices/%s/state"
#define WEIGHT_MSG "{weight : %.2f, timestamp : %s}"
#define TEST_MSG "This is a test"

void iotc_init();
void mqtt_task(void *pvParameters);

#endif