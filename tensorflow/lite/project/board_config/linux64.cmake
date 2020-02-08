#Linux 64 bit configurations

set(BOARD_TARGET Linux_x64)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC -pthread -std=c++11 -Wno-ignored-attributes")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fPIC")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -ldl")

add_definitions(-D CL_TARGET_OPENCL_VERSION=220)
add_definitions(-D GEMMLOWP_ALLOW_SLOW_SCALAR_FALLBACK)
add_definitions(-D ABSL_NO_XRAY_ATTRIBUTES=1)
add_definitions(-D BUILD_TESTING=OFF)

set(BUILD_GPU_DELEGATE  off)
set(BUILD_WITH_MMAP     off)
set(BUILD_GTEST         on)