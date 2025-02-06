#include "platform.h"
#include "led.h"

void AppInit(void) {
	PlatformInit();
    LedInit();
}

void AppRun(void) {
    while (1) {
        BlinkLeds();
    }
}
