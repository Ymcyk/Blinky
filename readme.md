# Blinky

## Prerequisites 

 - download firmware files in STM32CubeMX
 - clone https://github.com/ObKo/stm32-cmake
 - download SVD file from https://github.com/cmsis-svd/cmsis-svd/tree/main/data/STMicro
 - download and add to path ARM toolchain, CMake and Ninja

## Flashing

For flashing use OpenOCD or STM32CubeProgrammer

TODO: add VS Code task for flashing with OpenOCD

## VS Code configuration

settings.json

```json
{
    "cmake.configureEnvironment": {
        "CMAKE_TOOLCHAIN_FILE": "C:/Utils/stm32-cmake/cmake/stm32_gcc.cmake", // toolchain file from https://github.com/ObKo/stm32-cmake
        "STM32_CUBE_F4_PATH": "C:/Users/pk/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1", // downloaded by CubeMX
        "STM32_TARGET_TRIPLET": "arm-none-eabi",
        "STM32_TOOLCHAIN_PATH": "C:/Utils/Compilers/arm-gnu-toolchain-mingw/bin", // arm toolchain 
        "CMAKE_MODULE_PATH": "C:/Utils/stm32-cmake/cmake" // path to https://github.com/ObKo/stm32-cmake cmake modules
    },
    "cortex-debug.openocdPath": "C:/Utils/OpenOCD/bin/openocd.exe",
    "cortex-debug.armToolchainPath.windows": "C:/Utils/Compilers/arm-gnu-toolchain-mingw/bin",
    "cortex-debug.gdbPath.windows": "C:/Utils/Compilers/arm-gnu-toolchain-mingw/bin/arm-none-eabi-gdb.exe"
}

```

launch.json

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "type": "cortex-debug",
            "request": "launch",
            "servertype": "openocd",
            "cwd": "${workspaceFolder}", // path to repository root
            "executable": "build/blinky.elf", // relative to cwd
            "name": "Debug Blinky",
            "device": "STM32F446RE",
            "svdFile": "C:/Utils/SVD/STM32F446.svd", // downloaded from https://github.com/cmsis-svd/cmsis-svd/tree/main/data/STMicro
            "configFiles": [
                "board/st_nucleo_f4.cfg" // this can be find in OpenOCD\share\openocd\scripts\board
            ],
            "runToEntryPoint": "main"
        }
    ]
}
```