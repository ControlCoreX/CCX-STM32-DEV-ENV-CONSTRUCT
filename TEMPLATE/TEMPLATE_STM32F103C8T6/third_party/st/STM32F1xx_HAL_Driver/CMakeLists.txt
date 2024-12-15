# Date  : 2024-11-13
# Author: tuwenbo (ControlCoreX@163.com)

# STM32F1xx_HAL_Driver_V1.8.3

target_compile_definitions(${PROJECT_NAME} PRIVATE
    USE_FULL_LL_DRIVER
    USE_HAL_DRIVER
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/Inc"
    "${CMAKE_CURRENT_LIST_DIR}/Inc/Legacy"
)

target_sources(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/Src/Legacy/stm32f1xx_hal_can.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_adc_ex.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_adc.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_can.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_cec.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_cortex.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_crc.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_dac_ex.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_dac.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_dma.c"
    # "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_eth.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_exti.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_flash_ex.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_flash.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_gpio_ex.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_gpio.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_hcd.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_i2c.c"
    # "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_i2s.c"
    # "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_irda.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_iwdg.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_mmc.c"
    # "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_msp_template.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_nand.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_nor.c"
    # "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_pccard.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_pcd_ex.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_pcd.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_pwr.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_rcc_ex.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_rcc.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_rtc_ex.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_rtc.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_sd.c"
    # "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_smartcard.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_spi.c"
    # "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_sram.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_tim_ex.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_tim.c"
    # "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_timebase_rtc_alarm_template.c"
    # "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_timebase_tim_template.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_uart.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_usart.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal_wwdg.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_hal.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_adc.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_crc.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_dac.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_dma.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_exti.c"
    # "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_fsmc.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_gpio.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_i2c.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_pwr.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_rcc.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_rtc.c"
    # "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_sdmmc.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_spi.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_tim.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_usart.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_usb.c"
    "${CMAKE_CURRENT_LIST_DIR}/Src/stm32f1xx_ll_utils.c"
)
