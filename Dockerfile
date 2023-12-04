FROM ubuntu:22.04

ARG STM32CUBEF4_URL=https://github.com/STMicroelectronics/STM32CubeF4.git
ARG STM32_CMAKE_URL=https://github.com/ObKo/stm32-cmake.git
ARG ARMTOOLCHAIN_URL=https://developer.arm.com/-/media/Files/downloads/gnu/13.2.rel1/binrel/arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz
ARG ARMTOOLCHAIN_DOWNLOAD_NAME=arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz

# CMake PPA setup requirements
RUN apt update && apt upgrade -y && apt install -y \
    ca-certificates \
    gpg \
    wget

# Add PPA for newer CMake
RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null \
    | gpg --dearmor - | tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null && \
    echo 'deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ jammy main' \
    | tee /etc/apt/sources.list.d/kitware.list >/dev/null

RUN apt update && apt install -y \
    gcc \
    g++ \
    ninja-build \
    cmake \
    git \
    xz-utils \
    clangd \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /opt

RUN git clone ${STM32CUBEF4_URL} && \
    cd STM32CubeF4 && \
    git switch --detach v1.27.1
RUN git clone ${STM32_CMAKE_URL}
RUN wget ${ARMTOOLCHAIN_URL} && \
    tar -xf arm-gnu-toolchain*.tar.xz && \
    mv `ls -d */ | grep arm-gnu-toolchain` arm-gnu-toolchain && \
    rm ${ARMTOOLCHAIN_DOWNLOAD_NAME}

ENV PATH="/opt/arm-gnu-toolchain/bin:$PATH"

WORKDIR /src
