cmake_minimum_required(VERSION 3.24)
project(blinky)

if (TESTING_ENABLED)
    # include("cmake/Testing.cmake")
    add_subdirectory(external/Catch2)
    add_subdirectory(external/fff)

    add_executable(tests tests/example.cpp)
    target_link_libraries(tests PRIVATE Catch2::Catch2WithMain fff)
else()
    add_subdirectory(sources)
endif()
