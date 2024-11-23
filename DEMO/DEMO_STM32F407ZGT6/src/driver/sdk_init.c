#include "stm32f4xx_hal.h"

void sdk_init()
{
    HAL_Init();

}

void sdk_deinit()
{

}

// Newlib hooks.
void hardware_init_hook() {}

void software_init_hook()
{
    sdk_init();

    // OS.
}
