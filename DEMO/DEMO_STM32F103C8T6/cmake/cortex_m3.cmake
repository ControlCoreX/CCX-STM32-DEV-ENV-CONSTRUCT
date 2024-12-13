set(CPU_FLAGS "-mcpu=cortex-m3 -mthumb")

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(COMPILER_SUFFIX "")

if(WIN32)
    set(COMPILER_SUFFIX ".exe")
endif()

find_program(COMPILER_ON_PATH "arm-none-eabi-gcc${COMPILER_SUFFIX}")

if(COMPILER_ON_PATH)
    get_filename_component(ARM_TOOLCHAIN_PATH ${COMPILER_ON_PATH} DIRECTORY)
    message(STATUS "Using ARM GCC from path = ${ARM_TOOLCHAIN_PATH}")
else()
    message(FATAL_ERROR "Unable to find ARM GCC (arm-none-eabi-gcc${COMPILER_SUFFIX}). Add to your PATH")
endif()

set(CMAKE_C_COMPILER ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc${COMPILER_SUFFIX})
set(CMAKE_CXX_COMPILER ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-g++${COMPILER_SUFFIX})
set(CMAKE_ASM_COMPILER ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc${COMPILER_SUFFIX})
set(CMAKE_LINKER ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc${COMPILER_SUFFIX})
set(CMAKE_CPP ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-cpp${COMPILER_SUFFIX})
set(CMAKE_SIZE_UTIL ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-size${COMPILER_SUFFIX})
set(CMAKE_OBJCOPY ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-objcopy${COMPILER_SUFFIX})
set(CMAKE_OBJDUMP ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-objdump${COMPILER_SUFFIX})
set(CMAKE_NM_UTIL ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc-nm${COMPILER_SUFFIX})
set(CMAKE_AR ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc-ar${COMPILER_SUFFIX})
set(CMAKE_RANLIB ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc-ranlib${COMPILER_SUFFIX})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(SPECS_FLAGS "--specs=nosys.specs --specs=nano.specs")
set(COMMON_FLAGS "-O2 -ffunction-sections -fdata-sections -Wall -Wdouble-promotion -Wno-sign-compare -Wno-psabi -g3 -ggdb3")
set(CXX_FLAGS "-fno-rtti -fno-exceptions -fno-threadsafe-statics -Wsuggest-override -Wno-register")
set(ASM_FLAGS "-x assembler-with-cpp")

set(CMAKE_C_FLAGS "${CPU_FLAGS} ${COMMON_FLAGS} ${SPECS_FLAGS} -std=c99")
set(CMAKE_CXX_FLAGS "${CPU_FLAGS} ${COMMON_FLAGS} ${SPECS_FLAGS} ${CXX_FLAGS} -std=c++11")
set(CMAKE_ASM_FLAGS "${CPU_FLAGS} ${SPECS_FLAGS} -x assembler-with-cpp")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections,--no-warn-rwx-segments,--print-memory-usage")

