cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 23)
set(PROJECT_NAME minecli)
set(CPR_USE_SYSTEM_CURL 1)

project(${PROJECT_NAME} CXX)

set(SOURCES_DIR ${PROJECT_NAME})
file(GLOB SOURCES "${SOURCES_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

include(cmake/CPM.cmake)

CPMAddPackage("gh:nlohmann/json@3.10.5")
CPMAddPackage("gh:libcpr/cpr#1.10.5")

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} cpr::cpr)

