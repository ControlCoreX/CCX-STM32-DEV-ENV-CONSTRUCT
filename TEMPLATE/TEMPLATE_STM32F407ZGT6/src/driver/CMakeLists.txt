target_compile_definitions(${PROJECT_NAME} PRIVATE STM32F407xx)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/public"
)

target_sources(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/sdk_init.c"
    "${CMAKE_CURRENT_LIST_DIR}/startup_stm32f407zgt6.c"
    "${CMAKE_CURRENT_LIST_DIR}/system_stm32f4xx.c"
)
