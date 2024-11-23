target_compile_definitions(${PROJECT_NAME} PRIVATE STM32F103xB)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/public"
)

target_sources(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/sdk_init.c"
    "${CMAKE_CURRENT_LIST_DIR}/startup_stm32f103c8t6.c"
    "${CMAKE_CURRENT_LIST_DIR}/system_stm32f1xx.c"
)
