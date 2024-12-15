#include "cmsis_compiler.h"

typedef void (*VectorType)(void);

extern uint32_t __INITIAL_SP;
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
void TAMP_STAMP_IRQHandler()            __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler()                   __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void ADC_IRQHandler()                   __attribute__((weak, alias("Default_Handler")));
void CAN1_TX_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void CAN1_RX0_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler()    __attribute__((weak, alias("Default_Handler")));
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
void OTG_FS_WKUP_IRQHandler()           __attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler()        __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler()    __attribute__((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void FMC_IRQHandler()                   __attribute__((weak, alias("Default_Handler")));
void SDIO_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler()                 __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void TIM7_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void ETH_IRQHandler()                   __attribute__((weak, alias("Default_Handler")));
void ETH_WKUP_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void CAN2_TX_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void CAN2_RX0_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void CAN2_RX1_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void CAN2_SCE_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler()                __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler()          __attribute__((weak, alias("Default_Handler")));
void USART6_IRQHandler()                __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler()               __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler()        __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler()         __attribute__((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler()           __attribute__((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler()                __attribute__((weak, alias("Default_Handler")));
void DCMI_IRQHandler()                  __attribute__((weak, alias("Default_Handler")));
void HASH_RNG_IRQHandler()              __attribute__((weak, alias("Default_Handler")));
void FPU_IRQHandler()                   __attribute__((weak, alias("Default_Handler")));

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
    TAMP_STAMP_IRQHandler,
    RTC_WKUP_IRQHandler,
    FLASH_IRQHandler,
    RCC_IRQHandler,
    EXTI0_IRQHandler,
    EXTI1_IRQHandler,
    EXTI2_IRQHandler,
    EXTI3_IRQHandler,
    EXTI4_IRQHandler,
    DMA1_Stream0_IRQHandler,
    DMA1_Stream1_IRQHandler,
    DMA1_Stream2_IRQHandler,
    DMA1_Stream3_IRQHandler,
    DMA1_Stream4_IRQHandler,
    DMA1_Stream5_IRQHandler,
    DMA1_Stream6_IRQHandler,
    ADC_IRQHandler,
    CAN1_TX_IRQHandler,
    CAN1_RX0_IRQHandler,
    CAN1_RX1_IRQHandler,
    CAN1_SCE_IRQHandler,
    EXTI9_5_IRQHandler,
    TIM1_BRK_TIM9_IRQHandler,
    TIM1_UP_TIM10_IRQHandler,
    TIM1_TRG_COM_TIM11_IRQHandler,
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
    OTG_FS_WKUP_IRQHandler,
    TIM8_BRK_TIM12_IRQHandler,
    TIM8_UP_TIM13_IRQHandler,
    TIM8_TRG_COM_TIM14_IRQHandler,
    TIM8_CC_IRQHandler,
    DMA1_Stream7_IRQHandler,
    FMC_IRQHandler,
    SDIO_IRQHandler,
    TIM5_IRQHandler,
    SPI3_IRQHandler,
    UART4_IRQHandler,
    UART5_IRQHandler,
    TIM6_DAC_IRQHandler,
    TIM7_IRQHandler,
    DMA2_Stream0_IRQHandler,
    DMA2_Stream1_IRQHandler,
    DMA2_Stream2_IRQHandler,
    DMA2_Stream3_IRQHandler,
    DMA2_Stream4_IRQHandler,
    ETH_IRQHandler,
    ETH_WKUP_IRQHandler,
    CAN2_TX_IRQHandler,
    CAN2_RX0_IRQHandler,
    CAN2_RX1_IRQHandler,
    CAN2_SCE_IRQHandler,
    OTG_FS_IRQHandler,
    DMA2_Stream5_IRQHandler,
    DMA2_Stream6_IRQHandler,
    DMA2_Stream7_IRQHandler,
    USART6_IRQHandler,
    I2C3_EV_IRQHandler,
    I2C3_ER_IRQHandler,
    OTG_HS_EP1_OUT_IRQHandler,
    OTG_HS_EP1_IN_IRQHandler,
    OTG_HS_WKUP_IRQHandler,
    OTG_HS_IRQHandler,
    DCMI_IRQHandler,
    0,
    HASH_RNG_IRQHandler,
    FPU_IRQHandler
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
