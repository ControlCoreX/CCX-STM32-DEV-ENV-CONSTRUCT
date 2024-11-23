# I/O Retarget example project

This project prints "Hello World" and a counter value via the UART output. It is configured for Arm Virtual Hardware, but other target hardware that provides a CMSIS Driver:USART can be easily added.

## Prerequisites

### Tools

 - [CMSIS-Toolbox 2.1.0](https://github.com/Open-CMSIS-Pack/devtools/releases) or higher
 - [Arm Compiler for Embedded](https://developer.arm.com/downloads/view/ACOMPE), or
 - [GCC Compiler for Arm bare-metal](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) or
 - [Clang Compiler](https://github.com/ARM-software/LLVM-embedded-toolchain-for-Arm) or
 - [IAR Build Tools for Arm](https://www.iar.com/products/architectures/arm/iar-build-tools-for-arm/)
 - [Arm Virtual Hardware](https://developer.arm.com/Tools%20and%20Software/Arm%20Virtual%20Hardware) for local execution

### Packs

 - Required packs are listed in the file `retarget.csolution.yml`

## Project Structure

The project is generated using the [CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/build-overview.md) and is defined in [`csolution`](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/YML-Input-Format.md) format:

 - `retarget.csolution.yml` lists the required packs and defines the hardware target and build-types (along with the compiler).
 - `retarget.cproject.yml` defines the source files and the software components.

## Build Project

Use the `cbuild` command to build the Debug configuration for VHT_CM3 target defined in `retarget.csolution.yml` solution file.

```bash
cbuild retarget.csolution.yml -p -r --update-rte -c retarget.Debug+VHT_CM3
```

> **Note**
> - During the build process required packs may be downloaded (`-p` flag).

By default the project is compiled using GCC as set in `cdefault.yml` file.
One can build the project by specifying the toolchain - AC6, GCC, CLANG and IAR are supported.

### To build with Arm Compiler 6:

```bash
cbuild retarget.csolution.yml -p -r --update-rte --toolchain AC6 -c retarget.Debug+VHT_CM3
```

## Execute Project

The project is configured for execution on Arm Virtual Hardware which removes the requirement for a physical hardware board.

To execute application image on Arm Virtual Hardware use below command:
```bash
FVP_MPS2_Cortex-M3 -f fvp-config.txt out/retarget/VHT_CM3/Debug/retarget.elf
```
> **Note**
> - For Arm Compiler 6, the application image file has extension `.axf`
