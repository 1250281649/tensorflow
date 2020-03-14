cmake_minimum_required(VERSION 3.6)
project(tensorflow-microlite)
set(MICROLITE_DIR ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)

option(BOARD_TARGET "Select board type" Linux_x64)
option(BUILD_GTEST "default" off)

if (${BOARD_TARGET}  STREQUAL "ARM64")
    message("-- use aarch64 compile")
    #include(project/board_config/arm64.cmake)
else()
    message("-- native compile")
    include(project/board_config/linux64.cmake)
endif()

#include files
include_directories( 
    ${MICROLITE_DIR}/../tools/make/downloads/gemmlowp
    ${MICROLITE_DIR}/../tools/make/downloads/gemmlowp/fixedpoint
    ${MICROLITE_DIR}/../tools/make/downloads/gemmlowp/internal
    ${MICROLITE_DIR}/../tools/make/downloads/flatbuffers/include 
)

include_directories(
    ${MICROLITE_DIR}/kernels
    ${MICROLITE_DIR}/memory_planner
    ${MICROLITE_DIR}/../
    ${MICROLITE_DIR}/../../core/public
    ${MICROLITE_DIR}/../c
    ${MICROLITE_DIR}/../core/api
    ${MICROLITE_DIR}/../kernels
    ${MICROLITE_DIR}/../kernels/internal
    ${MICROLITE_DIR}/../kernels/internal/optimized
    ${MICROLITE_DIR}/../kernels/internal/reference
    ${MICROLITE_DIR}/../schema
)

#===========================source files
#find sources
file(GLOB CORE_CC_ALL_SRCS
    ${MICROLITE_DIR}/*.cc
    ${MICROLITE_DIR}/kernels/*.cc
    ${MICROLITE_DIR}/memory_planner/*.cc
    ${MICROLITE_DIR}/../c/common.c
    ${MICROLITE_DIR}/../core/api/error_reporter.cc
    ${MICROLITE_DIR}/../core/api/flatbuffer_conversions.cc
    ${MICROLITE_DIR}/../core/api/op_resolver.cc
    ${MICROLITE_DIR}/../core/api/tensor_utils.cc
    ${MICROLITE_DIR}/../kernels/internal/quantization_util.cc
    ${MICROLITE_DIR}/../kernels/kernel_util.cc
)

list(FILTER CORE_CC_ALL_SRCS EXCLUDE REGEX "${MICROLITE_DIR}/.*test")

add_library(${PROJECT_NAME} ${CORE_CC_ALL_SRCS})
target_link_libraries(${PROJECT_NAME})


# if(${BUILD_GTEST} STREQUAL "on")
#     add_subdirectory(${MICROLITE_DIR}/tools/make/downloads/googletest)
#     add_subdirectory(${MICROLITE_DIR}/project/gtest)
# endif()

# ============================= Examples =================================
# hello_world example
add_subdirectory(${MICROLITE_DIR}/examples/hello_world)

# micro_speech example
add_subdirectory(${MICROLITE_DIR}/examples/person_detection)

# # label_image example
# if(${BUILD_GPU_DELEGATE} STREQUAL "on")

# add_executable(label_image 
#     ${MICROLITE_DIR}/examples/label_image/label_image.cc
#     ${MICROLITE_DIR}/examples/label_image/bitmap_helpers.cc
# )
# target_link_libraries(label_image ${PROJECT_NAME} ${GPU_DELEGATE})

# endif()