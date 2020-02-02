#!/bin/bash
cd $(dirname $0)

build_dir=../../out/build
mkdir -p ${build_dir}
cd ${build_dir}
cmake ../../ -Dprotobuf_BUILD_TESTS=OFF
make -j3