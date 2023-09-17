set(SRCS Main.cpp Vanilla.cpp Parser.cpp)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -g -O2")

add_executable(minecli ${SRCS})
