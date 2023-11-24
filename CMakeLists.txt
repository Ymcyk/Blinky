cmake_minimum_required(VERSION 3.24)
project(blinky)

if (TESTING_ENABLED)
    include("cmake/Testing.cmake")
else()
    add_subdirectory(sources)
endif()
