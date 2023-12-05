# STM_playground

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

## Just to remember

Here I describe how things work just to not forget.

### `clangd` C/C++ completion

The problem here was connected with two CMake targets. Source files are build for firmware 
and unit tests. Also, testcases for unit tests are only build once for ut target.

I have resolved it with a help from `CMake Tools` VS Code extension. I used
`"cmake.copyCompileCommands": "${workspaceFolder}/compile_commands.json"` option to copy
both `compile_commands.json` to the same place, so the will override themselves. This way
just by switching CMake preset I can decide for which target C/C++ completion is turned on.

### Fakes in Unit Tests

I have used `fff` free functions mocking framework to be able to fake or mock interface 
functions. Each module which is a dependency of another module used in unit testing, adds
fake implementation library which is than linked in a replacement if a real implementation.

This way I should be able to test even modules which depends on modules that are using 
hardware specific things.

### Debugging

Unfortunatelly USB devices do not work out of the box in WSL (which I am using right not,
but probably I will switch to Linux). Right now I am building firmware and unit tests in
Docker with VS Code connected to this Docker container, so there will be no problem with
code completion. Debugging will be done on other instance of VS Code run on Windows host.
