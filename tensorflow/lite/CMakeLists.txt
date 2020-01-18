cmake_minimum_required(VERSION 3.5)
project(tensorflow-lite)
set(LITE_DIR ${PROJECT_SOURCE_DIR})

#set(BOARD_TARGET x86)
#set(BOARD_TARGET aarch64)

if (DEFINED BOARD_TARGET AND "${BOARD_TARGET}"  STREQUAL "aarch64")
    message("use aarch64 compile")
    set(CMAKE_SYSTEM_NAME Linux)
    set(TOOLCHAIN_DIR "/usr/local/arm")
    set(CMAKE_CXX_COMPILER /usr/local/arm/bin/aarch64-linux-gnu-g++)
    set(CMAKE_C_COMPILER /usr/local/arm/bin/aarch64-linux-gnu-gcc)
    set(GNU_FLAGS "-fPIC -pthread")
    SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)


    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o0 ${GNU_FLAGS} -std=c++11")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -o0 ${GNU_FLAGS}")
    set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_DIR}
        ${TOOLCHAIN_DIR}/include
        ${TOOLCHAIN_DIR}/lib
        )

    include_directories(${TOOLCHAIN_DIR}/include)
else()
    message("native compile")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -fPIC -pthread  -std=c++11")
endif()

set(CMAKE_CXX_STANDARD 11)

#include files
include_directories(
	./../../ 
	tools/make/downloads/ 
	tools/make/downloads/eigen 
	tools/make/downloads/absl 
	tools/make/downloads/gemmlowp 
	tools/make/downloads/neon_2_sse 
	tools/make/downloads/farmhash/src 
    tools/make/downloads/flatbuffers/include 
    tools/make/downloads/googletest/googletest/include
    tools/make/downloads/googletest/googlemock/include
)

#===========================source files
# Benchmark static library and binary
set(BENCHMARK_LIB_NAME benchmark-lib)
set(BENCHMARK_BINARY_NAME benchmark_model)

# A small example program that shows how to link against the library.
set(MINIMAL_SRCS ${LITE_DIR}/examples/minimal/minimal.cc)

set(PROFILER_SRCS ${LITE_DIR}/profiling/time.cc)
set(PROFILE_SUMMARIZER_SRCS ${LITE_DIR}/profiling/profile_summarizer.cc tensorflow/core/util/stats_calculator.cc)
set(CMD_LINE_TOOLS_SRCS ${LITE_DIR}/tools/command_line_flags.cc)

#find sources
file(GLOB CORE_CC_ALL_SRCS
    ${LITE_DIR}/*.cc
    ${LITE_DIR}/*.c
    ${LITE_DIR}/c/*.c
    ${LITE_DIR}/core/*.cc
    ${LITE_DIR}/core/api/*.cc
    ${LITE_DIR}/experimental/resource_variable/*.cc
    ${LITE_DIR}/experimental/ruy/*.cc
    ${LITE_DIR}/kernels/*.cc
    ${LITE_DIR}/kernels/internal/*.cc
    ${LITE_DIR}/kernels/internal/optimized/*.cc
    ${LITE_DIR}/kernels/internal/reference/*.cc
    ${LITE_DIR}/profiling/memory_info.cc
    ${LITE_DIR}/profiling/time.cc
    ${LITE_DIR}/tools/make/downloads/farmhash/src/farmhash.cc
    ${LITE_DIR}/tools/make/downloads/fft2d/fftsg.c
    ${LITE_DIR}/tools/make/downloads/flatbuffers/src/util.cpp
    ${LITE_DIR}/delegates/nnapi/nnapi_delegate_disabled.cc
    ${LITE_DIR}/nnapi/nnapi_implementation_disabled.cc
)

list(FILTER CORE_CC_ALL_SRCS EXCLUDE REGEX "${LITE_DIR}/.*test")
list(FILTER CORE_CC_ALL_SRCS EXCLUDE REGEX "${LITE_DIR}/.*benchmark")
list(FILTER CORE_CC_ALL_SRCS EXCLUDE REGEX "${LITE_DIR}/.*synchronization")
list(FILTER CORE_CC_ALL_SRCS EXCLUDE REGEX "${LITE_DIR}/.*debugging")
# foreach(v ${CORE_CC_ALL_SRCS})
#     message(${v})
# endforeach()

# remove not used files
list(REMOVE_ITEM CORE_CC_ALL_SRCS "${LITE_DIR}/minimal_logging_android.cc")
list(REMOVE_ITEM CORE_CC_ALL_SRCS "${LITE_DIR}/minimal_logging_ios.cc")
list(REMOVE_ITEM CORE_CC_ALL_SRCS "${LITE_DIR}/mmap_allocation.cc")

set(SRC_LIST ${CORE_CC_ALL_SRCS})

add_library(${PROJECT_NAME} ${SRC_LIST})

# for minimal
add_executable(minimal ${LITE_DIR}/examples/minimal/minimal.cc)
target_link_libraries(minimal ${PROJECT_NAME})