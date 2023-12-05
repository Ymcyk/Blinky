# Blinky

Playground project for my STM32F446RE learning purposes

## Prerequisites 

 - Docker - building firmware and unit tests
 - OpenOCD  - flashing and debugging

## Building 

### Preparing Docker container

Build docker image from Dockerfile (from project's root):

```bash
docker build -t stm32f4_tools .
```

Create container and bind source files (from project's root):

```bash
docker container run -it --name stm -v .:/src stm_dev
```

### Building inside Docker container

Configure cmake:

```bash
cmake --preset ut # for unit tests
cmake --preset firmware # for unit firmware
```

Build:

```bash
cmake --build --preset ut
cmake --build --preset firmware
```

## Flashing and debugging

__TBD__
