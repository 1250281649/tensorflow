// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/core/profiler/protobuf/hardware_types.proto

#include "tensorflow/core/profiler/protobuf/hardware_types.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace tensorflow {
namespace profiler {
}  // namespace profiler
}  // namespace tensorflow
static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n6tensorflow/core/profiler/protobuf/hard"
  "ware_types.proto\022\023tensorflow.profiler*D\n"
  "\014HardwareType\022\024\n\020UNKNOWN_HARDWARE\020\000\022\014\n\010C"
  "PU_ONLY\020\001\022\007\n\003GPU\020\002\022\007\n\003TPU\020\003b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto_sccs[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto_once;
static bool descriptor_table_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto = {
  &descriptor_table_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto_initialized, descriptor_table_protodef_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto, "tensorflow/core/profiler/protobuf/hardware_types.proto", 155,
  &descriptor_table_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto_once, descriptor_table_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto_sccs, descriptor_table_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto_deps, 0, 0,
  schemas, file_default_instances, TableStruct_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto::offsets,
  file_level_metadata_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto, 0, file_level_enum_descriptors_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto, file_level_service_descriptors_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto), true);
namespace tensorflow {
namespace profiler {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* HardwareType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto);
  return file_level_enum_descriptors_tensorflow_2fcore_2fprofiler_2fprotobuf_2fhardware_5ftypes_2eproto[0];
}
bool HardwareType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace profiler
}  // namespace tensorflow
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>