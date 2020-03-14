cmake_minimum_required(VERSION 3.6)
project(tf_gtest)
set(EXECUTABLE_OUTPUT_PATH ${LITE_DIR}/out/build)

include_directories(
    ../../ 
    tools/make/downloads/googletest/googletest/include
    tools/make/downloads/googletest/googlemock/include
)

set(graph_info_test_src ../../graph_info_test.cc)
set(memory_management_test_src ../../delegates/gpu/common/memory_management_test.cc)


add_executable(tf_gtest ${graph_info_test_src} ${memory_management_test_src})
target_link_libraries(tf_gtest tensorflow-lite gtest memory_management)

add_executable(arena_planner_test ../../arena_planner_test.cc)
target_link_libraries(arena_planner_test tensorflow-lite gtest)