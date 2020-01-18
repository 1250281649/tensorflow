#Linux 64 bit configurations

set(BOARD_TARGET Linux_x64)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC -pthread  -std=c++11")

set(BUILD_GPU_DELEGATE  off)