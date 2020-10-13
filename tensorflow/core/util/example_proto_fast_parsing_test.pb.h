// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/core/util/example_proto_fast_parsing_test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_tensorflow_2fcore_2futil_2fexample_5fproto_5ffast_5fparsing_5ftest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_tensorflow_2fcore_2futil_2fexample_5fproto_5ffast_5fparsing_5ftest_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3010000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3010001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "tensorflow/core/example/feature.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_tensorflow_2fcore_2futil_2fexample_5fproto_5ffast_5fparsing_5ftest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_tensorflow_2fcore_2futil_2fexample_5fproto_5ffast_5fparsing_5ftest_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_tensorflow_2fcore_2futil_2fexample_5fproto_5ffast_5fparsing_5ftest_2eproto;
namespace tensorflow {
class ExampleWithExtras;
class ExampleWithExtrasDefaultTypeInternal;
extern ExampleWithExtrasDefaultTypeInternal _ExampleWithExtras_default_instance_;
}  // namespace tensorflow
PROTOBUF_NAMESPACE_OPEN
template<> ::tensorflow::ExampleWithExtras* Arena::CreateMaybeMessage<::tensorflow::ExampleWithExtras>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace tensorflow {

// ===================================================================

class ExampleWithExtras :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tensorflow.ExampleWithExtras) */ {
 public:
  ExampleWithExtras();
  virtual ~ExampleWithExtras();

  ExampleWithExtras(const ExampleWithExtras& from);
  ExampleWithExtras(ExampleWithExtras&& from) noexcept
    : ExampleWithExtras() {
    *this = ::std::move(from);
  }

  inline ExampleWithExtras& operator=(const ExampleWithExtras& from) {
    CopyFrom(from);
    return *this;
  }
  inline ExampleWithExtras& operator=(ExampleWithExtras&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArena() const final {
    return GetArenaNoVirtual();
  }
  inline void* GetMaybeArenaPointer() const final {
    return MaybeArenaPtr();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ExampleWithExtras& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ExampleWithExtras* internal_default_instance() {
    return reinterpret_cast<const ExampleWithExtras*>(
               &_ExampleWithExtras_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ExampleWithExtras& a, ExampleWithExtras& b) {
    a.Swap(&b);
  }
  inline void Swap(ExampleWithExtras* other) {
    if (other == this) return;
    if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ExampleWithExtras* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ExampleWithExtras* New() const final {
    return CreateMaybeMessage<ExampleWithExtras>(nullptr);
  }

  ExampleWithExtras* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ExampleWithExtras>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ExampleWithExtras& from);
  void MergeFrom(const ExampleWithExtras& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ExampleWithExtras* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "tensorflow.ExampleWithExtras";
  }
  protected:
  explicit ExampleWithExtras(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_tensorflow_2fcore_2futil_2fexample_5fproto_5ffast_5fparsing_5ftest_2eproto);
    return ::descriptor_table_tensorflow_2fcore_2futil_2fexample_5fproto_5ffast_5fparsing_5ftest_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kExtra6FieldNumber = 1342,
    kExtra1FieldNumber = 1337,
    kFeaturesFieldNumber = 1,
    kExtra7FieldNumber = 1343,
    kExtra3FieldNumber = 1339,
    kExtra2FieldNumber = 1338,
    kExtra4FieldNumber = 1340,
    kExtra5FieldNumber = 1341,
  };
  // repeated float extra6 = 1342;
  int extra6_size() const;
  private:
  int _internal_extra6_size() const;
  public:
  void clear_extra6();
  private:
  float _internal_extra6(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
      _internal_extra6() const;
  void _internal_add_extra6(float value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
      _internal_mutable_extra6();
  public:
  float extra6(int index) const;
  void set_extra6(int index, float value);
  void add_extra6(float value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
      extra6() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
      mutable_extra6();

  // string extra1 = 1337;
  void clear_extra1();
  const std::string& extra1() const;
  void set_extra1(const std::string& value);
  void set_extra1(std::string&& value);
  void set_extra1(const char* value);
  void set_extra1(const char* value, size_t size);
  std::string* mutable_extra1();
  std::string* release_extra1();
  void set_allocated_extra1(std::string* extra1);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_extra1();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_extra1(
      std::string* extra1);
  private:
  const std::string& _internal_extra1() const;
  void _internal_set_extra1(const std::string& value);
  std::string* _internal_mutable_extra1();
  public:

  // .tensorflow.Features features = 1;
  bool has_features() const;
  private:
  bool _internal_has_features() const;
  public:
  void clear_features();
  const ::tensorflow::Features& features() const;
  ::tensorflow::Features* release_features();
  ::tensorflow::Features* mutable_features();
  void set_allocated_features(::tensorflow::Features* features);
  private:
  const ::tensorflow::Features& _internal_features() const;
  ::tensorflow::Features* _internal_mutable_features();
  public:
  void unsafe_arena_set_allocated_features(
      ::tensorflow::Features* features);
  ::tensorflow::Features* unsafe_arena_release_features();

  // .tensorflow.Features extra7 = 1343;
  bool has_extra7() const;
  private:
  bool _internal_has_extra7() const;
  public:
  void clear_extra7();
  const ::tensorflow::Features& extra7() const;
  ::tensorflow::Features* release_extra7();
  ::tensorflow::Features* mutable_extra7();
  void set_allocated_extra7(::tensorflow::Features* extra7);
  private:
  const ::tensorflow::Features& _internal_extra7() const;
  ::tensorflow::Features* _internal_mutable_extra7();
  public:
  void unsafe_arena_set_allocated_extra7(
      ::tensorflow::Features* extra7);
  ::tensorflow::Features* unsafe_arena_release_extra7();

  // fixed32 extra3 = 1339;
  void clear_extra3();
  ::PROTOBUF_NAMESPACE_ID::uint32 extra3() const;
  void set_extra3(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_extra3() const;
  void _internal_set_extra3(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // int64 extra2 = 1338;
  void clear_extra2();
  ::PROTOBUF_NAMESPACE_ID::int64 extra2() const;
  void set_extra2(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_extra2() const;
  void _internal_set_extra2(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // fixed64 extra4 = 1340;
  void clear_extra4();
  ::PROTOBUF_NAMESPACE_ID::uint64 extra4() const;
  void set_extra4(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_extra4() const;
  void _internal_set_extra4(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // double extra5 = 1341;
  void clear_extra5();
  double extra5() const;
  void set_extra5(double value);
  private:
  double _internal_extra5() const;
  void _internal_set_extra5(double value);
  public:

  // @@protoc_insertion_point(class_scope:tensorflow.ExampleWithExtras)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float > extra6_;
  mutable std::atomic<int> _extra6_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr extra1_;
  ::tensorflow::Features* features_;
  ::tensorflow::Features* extra7_;
  ::PROTOBUF_NAMESPACE_ID::uint32 extra3_;
  ::PROTOBUF_NAMESPACE_ID::int64 extra2_;
  ::PROTOBUF_NAMESPACE_ID::uint64 extra4_;
  double extra5_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_tensorflow_2fcore_2futil_2fexample_5fproto_5ffast_5fparsing_5ftest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ExampleWithExtras

// .tensorflow.Features features = 1;
inline bool ExampleWithExtras::_internal_has_features() const {
  return this != internal_default_instance() && features_ != nullptr;
}
inline bool ExampleWithExtras::has_features() const {
  return _internal_has_features();
}
inline const ::tensorflow::Features& ExampleWithExtras::_internal_features() const {
  const ::tensorflow::Features* p = features_;
  return p != nullptr ? *p : *reinterpret_cast<const ::tensorflow::Features*>(
      &::tensorflow::_Features_default_instance_);
}
inline const ::tensorflow::Features& ExampleWithExtras::features() const {
  // @@protoc_insertion_point(field_get:tensorflow.ExampleWithExtras.features)
  return _internal_features();
}
inline ::tensorflow::Features* ExampleWithExtras::release_features() {
  auto temp = unsafe_arena_release_features();
  if (GetArenaNoVirtual() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::tensorflow::Features* ExampleWithExtras::unsafe_arena_release_features() {
  // @@protoc_insertion_point(field_release:tensorflow.ExampleWithExtras.features)
  
  ::tensorflow::Features* temp = features_;
  features_ = nullptr;
  return temp;
}
inline ::tensorflow::Features* ExampleWithExtras::_internal_mutable_features() {
  
  if (features_ == nullptr) {
    auto* p = CreateMaybeMessage<::tensorflow::Features>(GetArenaNoVirtual());
    features_ = p;
  }
  return features_;
}
inline ::tensorflow::Features* ExampleWithExtras::mutable_features() {
  // @@protoc_insertion_point(field_mutable:tensorflow.ExampleWithExtras.features)
  return _internal_mutable_features();
}
inline void ExampleWithExtras::set_allocated_features(::tensorflow::Features* features) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(features_);
  }
  if (features) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(features)->GetArena();
    if (message_arena != submessage_arena) {
      features = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, features, submessage_arena);
    }
    
  } else {
    
  }
  features_ = features;
  // @@protoc_insertion_point(field_set_allocated:tensorflow.ExampleWithExtras.features)
}

// string extra1 = 1337;
inline void ExampleWithExtras::clear_extra1() {
  extra1_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const std::string& ExampleWithExtras::extra1() const {
  // @@protoc_insertion_point(field_get:tensorflow.ExampleWithExtras.extra1)
  return _internal_extra1();
}
inline void ExampleWithExtras::set_extra1(const std::string& value) {
  _internal_set_extra1(value);
  // @@protoc_insertion_point(field_set:tensorflow.ExampleWithExtras.extra1)
}
inline std::string* ExampleWithExtras::mutable_extra1() {
  // @@protoc_insertion_point(field_mutable:tensorflow.ExampleWithExtras.extra1)
  return _internal_mutable_extra1();
}
inline const std::string& ExampleWithExtras::_internal_extra1() const {
  return extra1_.Get();
}
inline void ExampleWithExtras::_internal_set_extra1(const std::string& value) {
  
  extra1_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
}
inline void ExampleWithExtras::set_extra1(std::string&& value) {
  
  extra1_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_rvalue:tensorflow.ExampleWithExtras.extra1)
}
inline void ExampleWithExtras::set_extra1(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  extra1_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:tensorflow.ExampleWithExtras.extra1)
}
inline void ExampleWithExtras::set_extra1(const char* value,
    size_t size) {
  
  extra1_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:tensorflow.ExampleWithExtras.extra1)
}
inline std::string* ExampleWithExtras::_internal_mutable_extra1() {
  
  return extra1_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline std::string* ExampleWithExtras::release_extra1() {
  // @@protoc_insertion_point(field_release:tensorflow.ExampleWithExtras.extra1)
  
  return extra1_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline void ExampleWithExtras::set_allocated_extra1(std::string* extra1) {
  if (extra1 != nullptr) {
    
  } else {
    
  }
  extra1_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), extra1,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:tensorflow.ExampleWithExtras.extra1)
}
inline std::string* ExampleWithExtras::unsafe_arena_release_extra1() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.ExampleWithExtras.extra1)
  GOOGLE_DCHECK(GetArenaNoVirtual() != nullptr);
  
  return extra1_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void ExampleWithExtras::unsafe_arena_set_allocated_extra1(
    std::string* extra1) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != nullptr);
  if (extra1 != nullptr) {
    
  } else {
    
  }
  extra1_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      extra1, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.ExampleWithExtras.extra1)
}

// int64 extra2 = 1338;
inline void ExampleWithExtras::clear_extra2() {
  extra2_ = PROTOBUF_LONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::int64 ExampleWithExtras::_internal_extra2() const {
  return extra2_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 ExampleWithExtras::extra2() const {
  // @@protoc_insertion_point(field_get:tensorflow.ExampleWithExtras.extra2)
  return _internal_extra2();
}
inline void ExampleWithExtras::_internal_set_extra2(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  extra2_ = value;
}
inline void ExampleWithExtras::set_extra2(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_extra2(value);
  // @@protoc_insertion_point(field_set:tensorflow.ExampleWithExtras.extra2)
}

// fixed32 extra3 = 1339;
inline void ExampleWithExtras::clear_extra3() {
  extra3_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ExampleWithExtras::_internal_extra3() const {
  return extra3_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ExampleWithExtras::extra3() const {
  // @@protoc_insertion_point(field_get:tensorflow.ExampleWithExtras.extra3)
  return _internal_extra3();
}
inline void ExampleWithExtras::_internal_set_extra3(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  extra3_ = value;
}
inline void ExampleWithExtras::set_extra3(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_extra3(value);
  // @@protoc_insertion_point(field_set:tensorflow.ExampleWithExtras.extra3)
}

// fixed64 extra4 = 1340;
inline void ExampleWithExtras::clear_extra4() {
  extra4_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 ExampleWithExtras::_internal_extra4() const {
  return extra4_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 ExampleWithExtras::extra4() const {
  // @@protoc_insertion_point(field_get:tensorflow.ExampleWithExtras.extra4)
  return _internal_extra4();
}
inline void ExampleWithExtras::_internal_set_extra4(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  extra4_ = value;
}
inline void ExampleWithExtras::set_extra4(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_extra4(value);
  // @@protoc_insertion_point(field_set:tensorflow.ExampleWithExtras.extra4)
}

// double extra5 = 1341;
inline void ExampleWithExtras::clear_extra5() {
  extra5_ = 0;
}
inline double ExampleWithExtras::_internal_extra5() const {
  return extra5_;
}
inline double ExampleWithExtras::extra5() const {
  // @@protoc_insertion_point(field_get:tensorflow.ExampleWithExtras.extra5)
  return _internal_extra5();
}
inline void ExampleWithExtras::_internal_set_extra5(double value) {
  
  extra5_ = value;
}
inline void ExampleWithExtras::set_extra5(double value) {
  _internal_set_extra5(value);
  // @@protoc_insertion_point(field_set:tensorflow.ExampleWithExtras.extra5)
}

// repeated float extra6 = 1342;
inline int ExampleWithExtras::_internal_extra6_size() const {
  return extra6_.size();
}
inline int ExampleWithExtras::extra6_size() const {
  return _internal_extra6_size();
}
inline void ExampleWithExtras::clear_extra6() {
  extra6_.Clear();
}
inline float ExampleWithExtras::_internal_extra6(int index) const {
  return extra6_.Get(index);
}
inline float ExampleWithExtras::extra6(int index) const {
  // @@protoc_insertion_point(field_get:tensorflow.ExampleWithExtras.extra6)
  return _internal_extra6(index);
}
inline void ExampleWithExtras::set_extra6(int index, float value) {
  extra6_.Set(index, value);
  // @@protoc_insertion_point(field_set:tensorflow.ExampleWithExtras.extra6)
}
inline void ExampleWithExtras::_internal_add_extra6(float value) {
  extra6_.Add(value);
}
inline void ExampleWithExtras::add_extra6(float value) {
  _internal_add_extra6(value);
  // @@protoc_insertion_point(field_add:tensorflow.ExampleWithExtras.extra6)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
ExampleWithExtras::_internal_extra6() const {
  return extra6_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
ExampleWithExtras::extra6() const {
  // @@protoc_insertion_point(field_list:tensorflow.ExampleWithExtras.extra6)
  return _internal_extra6();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
ExampleWithExtras::_internal_mutable_extra6() {
  return &extra6_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
ExampleWithExtras::mutable_extra6() {
  // @@protoc_insertion_point(field_mutable_list:tensorflow.ExampleWithExtras.extra6)
  return _internal_mutable_extra6();
}

// .tensorflow.Features extra7 = 1343;
inline bool ExampleWithExtras::_internal_has_extra7() const {
  return this != internal_default_instance() && extra7_ != nullptr;
}
inline bool ExampleWithExtras::has_extra7() const {
  return _internal_has_extra7();
}
inline const ::tensorflow::Features& ExampleWithExtras::_internal_extra7() const {
  const ::tensorflow::Features* p = extra7_;
  return p != nullptr ? *p : *reinterpret_cast<const ::tensorflow::Features*>(
      &::tensorflow::_Features_default_instance_);
}
inline const ::tensorflow::Features& ExampleWithExtras::extra7() const {
  // @@protoc_insertion_point(field_get:tensorflow.ExampleWithExtras.extra7)
  return _internal_extra7();
}
inline ::tensorflow::Features* ExampleWithExtras::release_extra7() {
  auto temp = unsafe_arena_release_extra7();
  if (GetArenaNoVirtual() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::tensorflow::Features* ExampleWithExtras::unsafe_arena_release_extra7() {
  // @@protoc_insertion_point(field_release:tensorflow.ExampleWithExtras.extra7)
  
  ::tensorflow::Features* temp = extra7_;
  extra7_ = nullptr;
  return temp;
}
inline ::tensorflow::Features* ExampleWithExtras::_internal_mutable_extra7() {
  
  if (extra7_ == nullptr) {
    auto* p = CreateMaybeMessage<::tensorflow::Features>(GetArenaNoVirtual());
    extra7_ = p;
  }
  return extra7_;
}
inline ::tensorflow::Features* ExampleWithExtras::mutable_extra7() {
  // @@protoc_insertion_point(field_mutable:tensorflow.ExampleWithExtras.extra7)
  return _internal_mutable_extra7();
}
inline void ExampleWithExtras::set_allocated_extra7(::tensorflow::Features* extra7) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(extra7_);
  }
  if (extra7) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(extra7)->GetArena();
    if (message_arena != submessage_arena) {
      extra7 = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, extra7, submessage_arena);
    }
    
  } else {
    
  }
  extra7_ = extra7;
  // @@protoc_insertion_point(field_set_allocated:tensorflow.ExampleWithExtras.extra7)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_tensorflow_2fcore_2futil_2fexample_5fproto_5ffast_5fparsing_5ftest_2eproto