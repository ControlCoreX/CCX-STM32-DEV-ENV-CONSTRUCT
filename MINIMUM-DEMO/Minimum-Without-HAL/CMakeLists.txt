cmake_minimum_required(VERSION 3.20)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m4)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER "D:/Developer_Tools/Toolchain/arm-gnu-toolchain-13.3.1/bin/arm-none-eabi-gcc.exe")
set(CMAKE_OBJCOPY "D:/Developer_Tools/Toolchain/arm-gnu-toolchain-13.3.1/bin/arm-none-eabi-objcopy.exe")

set(CPU_FLAGS "-mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16")
set(COMMON_FLAGS "-ffunction-sections -fdata-sections -Wall -Wdouble-promotion -Wno-sign-compare -Wno-psabi -g3 -ggdb3")
set(SPECS_FLAGS "--specs=nosys.specs --specs=nano.specs")
set(ASM_FLAGS "-x assembler-with-cpp")

set(CMAKE_C_FLAGS "${CPU_FLAGS} ${SPECS_FLAGS} ${COMMON_FLAGS}")
set(CMAKE_ASM_FLAGS "${CPU_FLAGS} ${SPECS_FLAGS} ${ASM_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections,--no-warn-rwx-segments,--print-memory-usage")

project(MINIMUM-WITHOUT-HAL LANGUAGES C ASM)

add_executable(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".elf")

# src
target_sources(${PROJECT_NAME} PRIVATE
    src/main.c
    src/driver/startup_stm32f407zgt6.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
    src/config
)

# cmsis-core
target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/third_party/arm/cmsis-core/Include"
)

# cmsis-compiler
target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/third_party/arm/cmsis-compiler/include"
    "${CMAKE_SOURCE_DIR}/third_party/arm/cmsis-compiler/include/gcc"
)

target_sources(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/third_party/arm/cmsis-compiler/source/gcc/retarget_syscalls.c"
)

# cmsis-device-f4
add_subdirectory(third_party/st)

target_link_options(${PROJECT_NAME} PRIVATE
    -T${CMAKE_SOURCE_DIR}/stm32f407zgt6.ld
    -Wl,-Map=${PROJECT_NAME}.map
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Oihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMAND ${CMAKE_OBJCOPY} -Obinary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
)
