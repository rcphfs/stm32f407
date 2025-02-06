#include "stm32f4xx_hal.h"
#include "clock_config.h"
#include "gpio_config.h"

void PlatformInit(void) {
    HAL_Init();
    ClockConfigInit();
    GpioClockEnable();
}
