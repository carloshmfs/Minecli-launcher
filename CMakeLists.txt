# CMake project setup

cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 23)

# Enable the export of compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(minecli CXX)

include(FetchContent)

FetchContent_Declare(json GIT_REPOSITORY https://github.com/nlohmann/json.git)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8)
FetchContent_MakeAvailable(json cpr)

set(SOURCES_DIR ${CMAKE_PROJECT_NAME})
file(GLOB SOURCES 
    "${SOURCES_DIR}/*.cpp" 
    "${SOURCES_DIR}/*.hpp"
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json cpr::cpr)

set_target_properties(${CMAKE_PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)

