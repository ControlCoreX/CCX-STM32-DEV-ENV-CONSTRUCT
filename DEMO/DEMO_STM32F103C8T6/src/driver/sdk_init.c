/**
*********************************************************************************************************
* @file   : sdk_init.h
* @author : tuwenbo
* @date   : 13 Nov 2024
* @brief  :
*
*********************************************************************************************************
*/

#include "stm32f1xx_hal.h"

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
