cmake_minimum_required(VERSION 3.6)
project(tensorflow-lite)
set(LITE_DIR ${PROJECT_SOURCE_DIR})

option(BOARD_TARGET "Select board type" Linux_x64)

if (${BOARD_TARGET}  STREQUAL "ARM64")
    message("-- use aarch64 compile")
    include(project/board_config/arm64.cmake)
else()
    message("-- native compile")
    include(project/board_config/linux64.cmake)
endif()

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
# A small example program that shows how to link against the library.
set(MINIMAL_SRCS ${LITE_DIR}/examples/minimal/minimal.cc)

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

# remove not used files
list(REMOVE_ITEM CORE_CC_ALL_SRCS "${LITE_DIR}/minimal_logging_android.cc")
list(REMOVE_ITEM CORE_CC_ALL_SRCS "${LITE_DIR}/minimal_logging_ios.cc")
list(REMOVE_ITEM CORE_CC_ALL_SRCS "${LITE_DIR}/mmap_allocation.cc")

set(SRC_LIST ${CORE_CC_ALL_SRCS})

add_library(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} absl::flags absl::hash absl::strings)

# ======================= third party library ============================
add_subdirectory(tools/make/downloads/absl)

# ============================== Tools ===================================
#benchmark
set(BENCHMARK_LIB_SRCS 
    tools/benchmark/benchmark_model.cc
    tools/benchmark/benchmark_params.cc
    tools/benchmark/benchmark_performance_options.cc
    tools/benchmark/benchmark_tflite_model.cc
    tools/benchmark/benchmark_utils.cc
    tools/evaluation/utils.cc
    tools/command_line_flags.cc
    ../core/util/stats_calculator.cc
    profiling/profile_summarizer.cc
    profiling/time.cc
    profiling/profile_summarizer.cc
)
add_library(benchmark-lib ${BENCHMARK_LIB_SRCS})
add_executable(benchmark tools/benchmark/benchmark_main.cc)
target_link_libraries(benchmark benchmark-lib ${PROJECT_NAME})

# ============================= Examples =================================
add_executable(minimal ${LITE_DIR}/examples/minimal/minimal.cc)
target_link_libraries(minimal ${PROJECT_NAME})