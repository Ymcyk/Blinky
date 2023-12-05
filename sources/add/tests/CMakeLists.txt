project(add_ut)

set(SOURCES
    ../sources/add.c
    
    add_ut.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain fff)
target_include_directories(${PROJECT_NAME} PRIVATE ../include)

set(FAKES
    ../fakes/add_fake.c)

add_library(add_fake ${FAKES})

target_link_libraries(add_fake PRIVATE fff)
target_include_directories(add_fake PUBLIC ../include)
