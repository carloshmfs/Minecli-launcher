cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 23)

set(PROJECT_NAME minecli)
set(SRC_DIR ${PROJECT_NAME})

project(${PROJECT_NAME})

set(
    SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/ArgsParser.cpp
)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall")
add_executable(${PROJECT_NAME} ${SOURCES})
