#Linux 64 bit configurations

set(BOARD_TARGET Linux_x64)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG -std=c++11 -fno-rtti")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -DNDEBUG")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --stack,1024000")

add_definitions(-D TF_LITE_STATIC_MEMORY)
add_definitions(-D GEMMLOWP_ALLOW_SLOW_SCALAR_FALLBACK)
add_definitions(-D BUILD_TESTING=OFF)