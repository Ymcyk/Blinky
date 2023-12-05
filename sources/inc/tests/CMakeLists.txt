project(inc_ut)

set(SOURCES
    ../sources/inc.c
    
    inc_ut.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain fff add_fake)
target_include_directories(${PROJECT_NAME} PRIVATE ../include)
