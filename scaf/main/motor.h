#ifndef SCAF_MOTOR_H
#define SCAF_MOTOR_H

#include "globals.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define MOTOR_EN 0
#define MOTOR_STEP 0
#define MOTOR_DIR 0
#define NUM_STEP 200
#define RPM 1
#define PORTION_STEP 33

void motor_init();
void rotate(int);

#endif