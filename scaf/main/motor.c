#include "motor.h"

void motor_init()
{
    // Select pins as GPIO
    gpio_pad_select_gpio(MOTOR_EN);
    gpio_pad_select_gpio(MOTOR_DIR);
    gpio_pad_select_gpio(MOTOR_STEP);

    // Set pins to output mode
    gpio_set_direction(MOTOR_EN, GPIO_MODE_OUTPUT);
    gpio_set_direction(MOTOR_DIR, GPIO_MODE_OUTPUT);
    gpio_set_direction(MOTOR_STEP, GPIO_MODE_OUTPUT);

    // Initialize logic level
    gpio_set_level(MOTOR_EN, 1);
    gpio_set_level(MOTOR_DIR, 0);
    gpio_set_level(MOTOR_STEP, 0);
}

void rotate(int portion)
{
    // Calculate delay in ms according to desired rotations per min
    int delay = 60 * 1000 / NUM_STEP / RPM / 2;
    // Calculate number of steps to rotate
    int steps = portion * PORTION_STEP;

    // Enable motor
    gpio_set_level(MOTOR_EN, 0);
    vTaskDelay(50 / portTICK_PERIOD_MS);

    while(steps) {
     // Send pulse every delay to rotate motor one step
     gpio_set_level(MOTOR_STEP, 0);
     vTaskDelay(delay / portTICK_PERIOD_MS);
     gpio_set_level(MOTOR_STEP, 0);
     vTaskDelay(delay / portTICK_PERIOD_MS);
     steps--;
    }

    // Disable motor
    gpio_set_level(MOTOR_EN, 1);

}
