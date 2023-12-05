cmake_minimum_required(VERSION 3.24)
project(blinky)

if (TESTING_ENABLED)
    add_subdirectory(external/Catch2)
    add_subdirectory(external/fff)

    set(DIRS
        add
        inc)

    foreach(dir ${DIRS})
        add_subdirectory(sources/${dir}/tests)
    endforeach()
else()
    add_subdirectory(sources)
endif()
