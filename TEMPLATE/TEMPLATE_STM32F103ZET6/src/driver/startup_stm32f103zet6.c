/**
*********************************************************************************************************
* @file   : startup_stm32f103zet6.h
* @author : tuwenbo
* @date   : 16 Nov 2024
* @brief  :
*
*********************************************************************************************************
*/

#include "startup_stm32f103zet6.h"
#include "cmsis_gcc.h"

/* This symbol comes from the linker scirpt. */
extern uint32_t __INITIAL_SP;

/* This symbol comes from cmsis_gcc_m.h, wrapped _start() function. */
extern __NO_RETURN void __PROGRAM_START();

__NO_RETURN void Reset_Handler();
void Default_Handler(void);

// Exceptions
void NMI_Handler()                      __attribute__((weak));
void HardFault_Handler()                __attribute__((weak));
void MemManage_Handler()                __attribute__((weak));
void BusFault_Handler()                 __attribute__((weak));
void UsageFault_Handler()               __attribute__((weak));
void SVC_Handler()                      __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler()                 __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler()                   __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler()                  __attribute__((weak, alias("Default_Handler")));
// External Interrupts
void WWDG_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler()                   __attribute__((weak, alias("Default_Handler")));
void TAMPER_IRQHandler()                __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler()                   __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler()                   __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void ADC1_2_IRQHandler()                __attribute__((weak, alias("Default_Handler")));
void USB_HP_CAN1_TX_IRQHandler()        __attribute__((weak, alias("Default_Handler")));
void USB_LP_CAN1_RX0_IRQHandler()       __attribute__((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler()                __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler()                __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler()                __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler()             __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler()             __attribute__((weak, alias("Default_Handler")));
void USBWakeUp_IRQHandler()             __attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void ADC3_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void FSMC_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void SDIO_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void TIM6_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void TIM7_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel1_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel2_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel3_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel4_5_IRQHandler()       __attribute__((weak, alias("Default_Handler")));

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

const VectorType __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
    (VectorType)(&__INITIAL_SP),
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,

    WWDG_IRQHandler,
    PVD_IRQHandler,
    TAMPER_IRQHandler,
    RTC_IRQHandler,
    FLASH_IRQHandler,
    RCC_IRQHandler,
    EXTI0_IRQHandler,
    EXTI1_IRQHandler,
    EXTI2_IRQHandler,
    EXTI3_IRQHandler,
    EXTI4_IRQHandler,
    DMA1_Channel1_IRQHandler,
    DMA1_Channel2_IRQHandler,
    DMA1_Channel3_IRQHandler,
    DMA1_Channel4_IRQHandler,
    DMA1_Channel5_IRQHandler,
    DMA1_Channel6_IRQHandler,
    DMA1_Channel7_IRQHandler,
    ADC1_2_IRQHandler,
    USB_HP_CAN1_TX_IRQHandler,
    USB_LP_CAN1_RX0_IRQHandler,
    CAN1_RX1_IRQHandler,
    CAN1_SCE_IRQHandler,
    EXTI9_5_IRQHandler,
    TIM1_BRK_IRQHandler,
    TIM1_UP_IRQHandler,
    TIM1_TRG_COM_IRQHandler,
    TIM1_CC_IRQHandler,
    TIM2_IRQHandler,
    TIM3_IRQHandler,
    TIM4_IRQHandler,
    I2C1_EV_IRQHandler,
    I2C1_ER_IRQHandler,
    I2C2_EV_IRQHandler,
    I2C2_ER_IRQHandler,
    SPI1_IRQHandler,
    SPI2_IRQHandler,
    USART1_IRQHandler,
    USART2_IRQHandler,
    USART3_IRQHandler,
    EXTI15_10_IRQHandler,
    RTC_Alarm_IRQHandler,
    USBWakeUp_IRQHandler,
    TIM8_BRK_IRQHandler,
    TIM8_UP_IRQHandler,
    TIM8_TRG_COM_IRQHandler,
    TIM8_CC_IRQHandler,
    ADC3_IRQHandler,
    FSMC_IRQHandler,
    SDIO_IRQHandler,
    TIM5_IRQHandler,
    SPI3_IRQHandler,
    UART4_IRQHandler,
    UART5_IRQHandler,
    TIM6_IRQHandler,
    TIM7_IRQHandler,
    DMA2_Channel1_IRQHandler,
    DMA2_Channel2_IRQHandler,
    DMA2_Channel3_IRQHandler,
    DMA2_Channel4_5_IRQHandler
};

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

extern void SystemInit();

__NO_RETURN void Reset_Handler()
{
    SystemInit();

    __PROGRAM_START();
}

void Default_Handler()
{
    for ( ; ; ) {}
}

void NMI_Handler()
{
    for ( ; ; ) {}
}

void HardFault_Handler()
{
    for ( ; ; ) {}
}

void MemManage_Handler()
{
    for ( ; ; ) {}
}

void BusFault_Handler()
{
    for ( ; ; ) {}
}

void UsageFault_Handler()
{
    for ( ; ; ) {}
}
