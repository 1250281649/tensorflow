#!/bin/bash
cd $(dirname $0)

CXX=aarch64-linux-gnu-g++
CC=aarch64-linux-gnu-gcc

build_dir=../../out/build_arm64
mkdir -p ${build_dir}
cd ${build_dir}
cmake ../../ -DCMAKE_CXX_COMPILER=aarch64-linux-gnu-g++ -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc
make -j4