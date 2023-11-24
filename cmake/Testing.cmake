project(blinky CXX)

add_subdirectory(external/Catch2)

add_executable(tests tests/example.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
