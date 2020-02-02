#Linux 64 bit configurations

set(BOARD_TARGET Linux_x64)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC -pthread -std=c++17 -Wno-ignored-attributes")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fPIC")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -ldl")

add_definitions(-D CL_TARGET_OPENCL_VERSION=220)
add_definitions(-D GEMMLOWP_ALLOW_SLOW_SCALAR_FALLBACK)
add_definitions(-D ABSL_NO_XRAY_ATTRIBUTES=1)
add_definitions(-D BUILD_TESTING=OFF)
add_definitions(-D PLATFORM_POSIX)

set(BUILD_GPU_DELEGATE  off)
set(BUILD_WITH_MMAP     off)
set(BUILD_GTEST         on)
set(BUILD_TOCO on)
if(${BUILD_TOCO} STREQUAL "on")
    set(protobuf_BUILD_TESTS off)
    set(protobuf_BUILD_EXAMPLES off)
    set(RE2_BUILD_TESTING off)
    set(BUILD_TESTING off)
    set(NSYNC_ENABLE_TESTS off)
    set(SNAPPY_BUILD_TESTS off)
    remove_definitions(__cpp_lib_make_unique)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -F,102400")
endif()
