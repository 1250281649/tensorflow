#Arm 64 bit configurations

set(BOARD_TARGET ARM64)

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