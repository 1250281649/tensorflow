cmake_minimum_required(VERSION 3.6)
project(toco)
set(TOCO_DIR ${PROJECT_SOURCE_DIR})

add_definitions(-D TOCO_SUPPORT_PORTABLE_PROTOS=0)

include_directories(
    ../../../
    ../tools/make/downloads/absl 
    ../../../third_party/jsoncpp
    ../../../third_party/re2
    ../../../third_party/protobuf/src
    ../../../third_party/double-conversion
    ../../../third_party/nsync/public
    ../../../third_party/nsync/internal
    ../../../third_party/sqlite-amalgamation
    ../../../third_party/snappy
    ../../../third_party/giflib
    ../../../third_party/zlib
    ../../../third_party/linenoise
    toco/graph_transformations
    ${TOCO_DIR}/../out/build/zlib
)

file(GLOB TOCO_TOOLING_SRCS
    toco.cc
    allocate_transient_arrays.cc
    args.cc
    dump_graphviz.cc
    export_tensorflow.cc
    import_tensorflow.cc
    model_cmdline_flags.cc
    tensorflow_util.cc
    toco_cmdline_flags.cc
    toco_convert.cc
    toco_graphviz_dump_options.cc
    toco_port.cc
    toco_tooling.cc
    tooling_util.cc
    logging/conversion_log_util.cc
    tensorflow_graph_matching/*.cc
    tflite/*.cc
    ../tools/*.cc
    ../tools/optimize/*.cc
    ../tools/versioning/op_version.cc
    #generated source files
    model_flags.pb.cc
    toco_flags.pb.cc
    types.pb.cc
)

#graph_transformations
file(GLOB GRAPH_SRCS graph_transformations/*.cc)
#tensorflow sources
file(GLOB TF_SRC
    ../../c/checkpoint_reader.cc
    ../../c/tf_status.cc
    ../../core/platform/default/logging.cc
    ../../core/platform/default/env_time.cc
    ../../core/platform/default/mutex.cc
    ../../core/platform/default/env.cc
    ../../core/platform/default/humen_readable_json.cc
    ../../core/platform/default/load_library.cc
    ../../core/platform/default/monitoring.cc
    ../../core/platform/default/net.cc
    ../../core/platform/default/port.cc
    ../../core/platform/default/posix_file_system.cc
    ../../core/platform/default/rocm_rocdl_path.cc
    ../../core/platform/default/stacktrace_handler.cc
    ../../core/platform/default/subprocess.cc
    ../../core/platform/default/tracing.cc
    ../../core/platform/default/unbounded_work_queue.cc
    ../../core/platform/*.cc
    ../../core/protobuf/*.cc
    ../../core/framework/*.cc
    ../../core/common_runtime/*.cc
    ../../core/util/matmul_bcast.cc
    ../../core/util/command_line_flags.cc
    ../../core/graph/*.cc
    ../../core/util/*.cc
    ../../core/util/proto/*.cc
    ../../core/util/ctc/*.cc
    ../../core/util/rpc/*.cc
    ../../core/util/sparse/*.cc
    ../../core/util/tensor_bundle/*.cc
    ../../core/lib/bfloat16/*.cc
    ../../core/lib/bmp/*.cc
    ../../core/lib/core/*.cc
    ../../core/lib/db/*.cc
    ../../core/lib/gif/*.cc
    ../../core/lib/gtl/*.cc
    ../../core/lib/hash/*.cc
    ../../core/lib/histogram/*.cc
    ../../core/lib/io/*.cc
 #   ../../core/lib/jpeg/*.cc
    ../../core/lib/lmdb/*.cc
    ../../core/lib/math/*.cc
    ../../core/lib/monitoring/*.cc
 #   ../../core/lib/png/*.cc
    ../../core/lib/psnr/*.cc
    ../../core/lib/random/*.cc
    ../../core/lib/ssim/*.cc
    ../../core/lib/strings/*.cc
    ../../core/lib/wav/*.cc
    ../../core/profiler/*.cc
    ../../core/profiler/internal/*.cc
    ../../core/profiler/internal/advisor/*.cc
    ../../core/profiler/lib/*.cc
    ../../core/profiler/convert/*.cc
    ../../core/profiler/protobuf/*.cc
    # ../../core/profiler/utils/*.cc
    ../../core/common_runtime/eager/context.cc
  #  ../../core/distributed_runtime/eager/*.cc
    ../delegates/flex/*.cc
    ../../stream_executor/*.cc
    ../../stream_executor/lib/*.cc
    ../../compiler/jit/defs.cc
)

file(GLOB THIRD_PART_SRCS 
    ../../../third_party/sqlite-amalgamation/sqlite3.c
    ../../../third_party/giflib/dgif_lib.c
    ../../../third_party/giflib/egif_lib.c
    ../../../third_party/giflib/gifalloc.c
    ../../../third_party/giflib/gif_err.c
    ../../../third_party/giflib/gif_font.c
    ../../../third_party/giflib/gif_hash.c
    ../../../third_party/giflib/openbsd-reallocarray.c
    ../../../third_party/linenoise/linenoise.c
)

set(TF_SRC ${TF_SRC} ${TOCO_TOOLING_SRCS} ${GRAPH_SRCS} ${ABSL_SRCS} ${THIRD_PART_SRCS})
list(FILTER TF_SRC EXCLUDE REGEX ".*test")
list(FILTER TF_SRC EXCLUDE REGEX ".*main")

set(TF_SRC ${TF_SRC}
    ../../core/util/test_log.pb.cc
)

# foreach(v ${TF_SRC})
#     message(${v})
# endforeach()


remove_definitions(root)
add_executable(${PROJECT_NAME} ${TF_SRC})
#add_library(${PROJECT_NAME} ${TOCO_TOOLING_SRCS} ${GRAPH_SRCS} ${TF_SRC} ${ABSL_SRCS})
target_link_libraries(${PROJECT_NAME} 
    dl
    tensorflow-lite
    re2 
    protobuf 
    double-conversion 
    nsync nsync_cpp
    snappy
    jsoncpp_lib_static
    zlib
)
