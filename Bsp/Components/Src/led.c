#include "led.h"
#include "stm32f4xx_hal.h"

#define LED_PORT  GPIOD

typedef enum {
    kOrange = GPIO_PIN_13,
    kRed = GPIO_PIN_14,
    kBlue = GPIO_PIN_15,
    kGreen = GPIO_PIN_12,
} led_t;

static const uint16_t kLedPins = (GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);

void LedInit(void) {
    GPIO_InitTypeDef init = {
        .Pin   = kLedPins,
        .Mode  = GPIO_MODE_OUTPUT_PP,
        .Pull  = GPIO_NOPULL,
        .Speed = GPIO_SPEED_FREQ_LOW
    };

    HAL_GPIO_WritePin(LED_PORT, kLedPins, GPIO_PIN_RESET);
    HAL_GPIO_Init(LED_PORT, &init);
}

void BlinkLeds(void) {
    HAL_GPIO_WritePin(GPIOD, kOrange, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kRed, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kBlue, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kGreen, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kGreen, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kBlue, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kRed, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kOrange, GPIO_PIN_RESET);
    HAL_Delay(100);
}
