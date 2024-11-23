#include "stm32f407xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"

void led_init()
{
    __HAL_RCC_GPIOC_CLK_ENABLE();

    GPIO_InitTypeDef cfg = {};
    cfg.Pin = GPIO_PIN_13;
    cfg.Mode = GPIO_MODE_OUTPUT_PP;
    cfg.Pull = GPIO_NOPULL;
    cfg.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(GPIOC, &cfg);
}


int main()
{
    led_init();

    for ( ; ; )
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
        HAL_Delay(300);
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
        HAL_Delay(300);
    }
}

void SysTick_Handler(void)
{
    HAL_IncTick();

}
