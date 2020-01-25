cmake_minimum_required(VERSION 3.6)
project(tensorflow-lite)
set(LITE_DIR ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)

option(BOARD_TARGET "Select board type" Linux_x64)
option(BUILD_GPU_DELEGATE "default" off)
option(BUILD_WITH_MMAP "default" off)
option(BUILD_BENCHMARK "default" off)

if (${BOARD_TARGET}  STREQUAL "ARM64")
    message("-- use aarch64 compile")
    include(project/board_config/arm64.cmake)
elseif(${BOARD_TARGET}  STREQUAL "Android")
    message("-- use Android compile")
    include(project/board_config/android.cmake)
else()
    message("-- native compile")
    include(project/board_config/linux64.cmake)
endif()

#include files
include_directories(
	../../ 
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
)

if(${BUILD_WITH_MMAP} STREQUAL "on")
    set(CORE_CC_ALL_SRCS ${CORE_CC_ALL_SRCS}
        ${LITE_DIR}/delegates/nnapi/nnapi_delegate.cc
        ${LITE_DIR}/delegates/nnapi/quant_lstm_sup.cc
        ${LITE_DIR}/nnapi/nnapi_implementation.cc
        ${LITE_DIR}/nnapi/nnapi_util.cc
    )
else()
    set(CORE_CC_ALL_SRCS ${CORE_CC_ALL_SRCS}
        ${LITE_DIR}/delegates/nnapi/nnapi_delegate_disabled.cc
        ${LITE_DIR}/nnapi/nnapi_implementation_disabled.cc
    )
endif()

list(FILTER CORE_CC_ALL_SRCS EXCLUDE REGEX "${LITE_DIR}/.*test")
list(FILTER CORE_CC_ALL_SRCS EXCLUDE REGEX "${LITE_DIR}/.*benchmark")
list(FILTER CORE_CC_ALL_SRCS EXCLUDE REGEX "${LITE_DIR}/.*synchronization")
list(FILTER CORE_CC_ALL_SRCS EXCLUDE REGEX "${LITE_DIR}/.*debugging")

# remove not used files
list(REMOVE_ITEM CORE_CC_ALL_SRCS "${LITE_DIR}/minimal_logging_android.cc")
list(REMOVE_ITEM CORE_CC_ALL_SRCS "${LITE_DIR}/minimal_logging_ios.cc")
list(REMOVE_ITEM CORE_CC_ALL_SRCS "${LITE_DIR}/mmap_allocation.cc")

#add ABSL library: build into the library
file(GLOB ABSL_SRCS
    ${LITE_DIR}/tools/make/downloads/absl/absl/base/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/base/internal/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/container/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/container/internal/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/debugging/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/flags/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/hash/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/hash/internal/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/numeric/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/strings/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/strings/internal/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/strings/internal/str_format/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/synchronization/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/synchronization/internal/per_thread_sem.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/synchronization/internal/waiter.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/synchronization/internal/create_thread_identity.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/time/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/time/internal/*.cc
    ${LITE_DIR}/tools/make/downloads/absl/absl/types/*.cc
)
list(FILTER ABSL_SRCS EXCLUDE REGEX "${LITE_DIR}/tools/make/downloads/absl/absl/.*test")
list(FILTER ABSL_SRCS EXCLUDE REGEX "${LITE_DIR}/tools/make/downloads/absl/absl/.*benchmark")

set(CORE_CC_ALL_SRCS ${CORE_CC_ALL_SRCS} ${ABSL_SRCS})
set(SRC_LIST ${CORE_CC_ALL_SRCS})

add_library(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME})

# =========================== gpu delegate ===============================
if(${BUILD_GPU_DELEGATE} STREQUAL "on")
#find sources
file(GLOB GPU_SRCS
    ${LITE_DIR}/minimal_logging.cc
    ${LITE_DIR}/c/common.cc
    ${LITE_DIR}/kernel_api.cc
    ${LITE_DIR}/delegates/gpu/delegate.cc
    ${LITE_DIR}/delegates/gpu/api.cc
    ${LITE_DIR}/delegates/gpu/cl/api.cc
    ${LITE_DIR}/delegates/gpu/cl/*.cc
    ${LITE_DIR}/delegates/gpu/cl/kernels/*.cc
    ${LITE_DIR}/delegates/gpu/cl/selectors/*.cc
    ${LITE_DIR}/delegates/gpu/common/*.cc
    ${LITE_DIR}/delegates/gpu/common/transformations/*.cc
    ${LITE_DIR}/delegates/gpu/common/memory_management/*.cc
    ${LITE_DIR}/delegates/gpu/gl/*.cc
    ${LITE_DIR}/delegates/gpu/gl/compiler/*.cc
    ${LITE_DIR}/delegates/gpu/gl/converters/*.cc
    ${LITE_DIR}/delegates/gpu/gl/kernels/*.cc
    ${LITE_DIR}/delegates/gpu/gl/workgroups/*.cc
    ${LITE_DIR}/tools/evaluation/utils.cc
)

list(FILTER GPU_SRCS EXCLUDE REGEX "${LITE_DIR}/.*test")

set(GPU_DELEGATE gpudelegate)
add_library(gpudelegate ${GPU_SRCS})
target_include_directories(
    ${GPU_DELEGATE} PUBLIC
    ${LITE_DIR}/../../
    ${LITE_DIR}/../../third_party/opencl_headers/OpenCL-Headers
    ${LITE_DIR}/../../third_party/FP16/FP16/include
    ${LITE_DIR}/delegates
    ${LITE_DIR}/delegates/gpu
    ${LITE_DIR}/delegates/gpu/cl
    ${LITE_DIR}/delegates/gpu/gl
    ${LITE_DIR}/delegates/gpu/common
)
target_link_libraries(${GPU_DELEGATE} 
    ${PROJECT_NAME}
    -lEGL
    -lGLESv3 
)

endif() #end of gpu delegate

# ======================= third party library ============================


# ============================== Tools ===================================
#benchmark lib
if(${BUILD_BENCHMARK} STREQUAL "on")
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

#benchmark binary
add_executable(benchmark tools/benchmark/benchmark_main.cc)
target_link_libraries(benchmark benchmark-lib ${PROJECT_NAME} ${GPU_DELEGATE})
target_include_directories(
    benchmark PUBLIC
    ${LITE_DIR}/../../
    ${LITE_DIR}/../../third_party/opencl_headers/OpenCL-Headers
    ${LITE_DIR}/../../third_party/FP16/FP16/include
    ${LITE_DIR}/delegates
    ${LITE_DIR}/delegates/gpu
    ${LITE_DIR}/delegates/gpu/cl
    ${LITE_DIR}/delegates/gpu/cl/kernels
    ${LITE_DIR}/delegates/gpu/gl
    ${LITE_DIR}/delegates/gpu/common
)
endif()

# ============================= Examples =================================
# minimal example
add_executable(minimal ${LITE_DIR}/examples/minimal/minimal.cc)
target_link_libraries(minimal ${PROJECT_NAME})

# label_image example
if(${BUILD_GPU_DELEGATE} STREQUAL "on")

add_executable(label_image 
    ${LITE_DIR}/examples/label_image/label_image.cc
    ${LITE_DIR}/examples/label_image/bitmap_helpers.cc
)
target_link_libraries(label_image ${PROJECT_NAME} ${GPU_DELEGATE})

endif()