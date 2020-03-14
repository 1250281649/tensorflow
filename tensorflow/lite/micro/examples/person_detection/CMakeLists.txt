cmake_minimum_required(VERSION 3.6)
project(person_detection)
set(EXECUTABLE_OUTPUT_PATH ${LITE_DIR}/out/build/micro)
set(CUR_DIR ${PROJECT_SOURCE_DIR})

include_directories(
    ../../../../../../
)

set(SRCS 
    main.cc
    detection_responder.cc
    image_provider.cc
    main_functions.cc
    model_settings.cc
    person_detect_model_data.cc
)

message("current dir:" ${CUR_DIR})
foreach(v ${MICRO_FRONTEND_SRCS})
    message(${v})
endforeach()


add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} tensorflow-microlite)
