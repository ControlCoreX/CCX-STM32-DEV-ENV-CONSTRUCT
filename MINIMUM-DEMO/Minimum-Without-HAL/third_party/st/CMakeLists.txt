# Date  : 2024-12-03
# Author: tuwenbo

target_compile_definitions(${PROJECT_NAME} PRIVATE STM32F407xx)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/cmsis-device-f4/Include"
)

target_sources(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/cmsis-device-f4/Source/Templates/system_stm32f4xx.c"
)
