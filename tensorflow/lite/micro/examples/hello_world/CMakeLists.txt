cmake_minimum_required(VERSION 3.6)
project(micro_hello_world)
set(EXECUTABLE_OUTPUT_PATH ${LITE_DIR}/out/build/micro)

include_directories(
    ../../../../../../
)

set(SRCS 
    main.cc
    constants.cc
    main_functions.cc
    output_handler.cc
    sine_model_data.cc
)


add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} tensorflow-microlite)
