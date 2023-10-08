cmake_minimum_required(VERSION 3.16)

project(blinky C ASM)

find_package(CMSIS COMPONENTS STM32F446RE REQUIRED)

set(SOURCES
    sources/main.c
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} CMSIS::STM32::F446RE STM32::NoSys)
stm32_print_size_of_target(${PROJECT_NAME})
