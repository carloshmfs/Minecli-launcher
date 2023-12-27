cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 23)
set(PROJECT_NAME minecli)

project(${PROJECT_NAME} CXX)

include(FetchContent)

FetchContent_Declare(json GIT_REPOSITORY https://github.com/nlohmann/json.git)
FetchContent_MakeAvailable(json)

set(SOURCES_DIR ${PROJECT_NAME})
file(GLOB SOURCES "${SOURCES_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)