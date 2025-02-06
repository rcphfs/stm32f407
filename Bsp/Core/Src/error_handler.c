#include "error_handler.h"
#include "stm32f4xx_hal.h"

__attribute__((weak)) void Error_Handler(void) {
    __disable_irq();
    while (1) {}
}


