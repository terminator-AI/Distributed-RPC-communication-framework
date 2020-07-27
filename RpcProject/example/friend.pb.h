// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: friend.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_friend_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_friend_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011000 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_friend_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_friend_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_friend_2eproto;
namespace myfriend {
class FriendRequest;
class FriendRequestDefaultTypeInternal;
extern FriendRequestDefaultTypeInternal _FriendRequest_default_instance_;
class FriendResponse;
class FriendResponseDefaultTypeInternal;
extern FriendResponseDefaultTypeInternal _FriendResponse_default_instance_;
class resultCode;
class resultCodeDefaultTypeInternal;
extern resultCodeDefaultTypeInternal _resultCode_default_instance_;
}  // namespace myfriend
PROTOBUF_NAMESPACE_OPEN
template<> ::myfriend::FriendRequest* Arena::CreateMaybeMessage<::myfriend::FriendRequest>(Arena*);
template<> ::myfriend::FriendResponse* Arena::CreateMaybeMessage<::myfriend::FriendResponse>(Arena*);
template<> ::myfriend::resultCode* Arena::CreateMaybeMessage<::myfriend::resultCode>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace myfriend {

// ===================================================================

class resultCode :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:myfriend.resultCode) */ {
 public:
  resultCode();
  virtual ~resultCode();

  resultCode(const resultCode& from);
  resultCode(resultCode&& from) noexcept
    : resultCode() {
    *this = ::std::move(from);
  }

  inline resultCode& operator=(const resultCode& from) {
    CopyFrom(from);
    return *this;
  }
  inline resultCode& operator=(resultCode&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
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
  static const resultCode& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const resultCode* internal_default_instance() {
    return reinterpret_cast<const resultCode*>(
               &_resultCode_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(resultCode& a, resultCode& b) {
    a.Swap(&b);
  }
  inline void Swap(resultCode* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline resultCode* New() const final {
    return CreateMaybeMessage<resultCode>(nullptr);
  }

  resultCode* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<resultCode>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const resultCode& from);
  void MergeFrom(const resultCode& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(resultCode* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "myfriend.resultCode";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_friend_2eproto);
    return ::descriptor_table_friend_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kErrmsgFieldNumber = 2,
    kErrcodeFieldNumber = 1,
  };
  // bytes errmsg = 2;
  void clear_errmsg();
  const std::string& errmsg() const;
  void set_errmsg(const std::string& value);
  void set_errmsg(std::string&& value);
  void set_errmsg(const char* value);
  void set_errmsg(const void* value, size_t size);
  std::string* mutable_errmsg();
  std::string* release_errmsg();
  void set_allocated_errmsg(std::string* errmsg);
  private:
  const std::string& _internal_errmsg() const;
  void _internal_set_errmsg(const std::string& value);
  std::string* _internal_mutable_errmsg();
  public:

  // int32 errcode = 1;
  void clear_errcode();
  ::PROTOBUF_NAMESPACE_ID::int32 errcode() const;
  void set_errcode(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_errcode() const;
  void _internal_set_errcode(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:myfriend.resultCode)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr errmsg_;
  ::PROTOBUF_NAMESPACE_ID::int32 errcode_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_friend_2eproto;
};
// -------------------------------------------------------------------

class FriendRequest :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:myfriend.FriendRequest) */ {
 public:
  FriendRequest();
  virtual ~FriendRequest();

  FriendRequest(const FriendRequest& from);
  FriendRequest(FriendRequest&& from) noexcept
    : FriendRequest() {
    *this = ::std::move(from);
  }

  inline FriendRequest& operator=(const FriendRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline FriendRequest& operator=(FriendRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
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
  static const FriendRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FriendRequest* internal_default_instance() {
    return reinterpret_cast<const FriendRequest*>(
               &_FriendRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(FriendRequest& a, FriendRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(FriendRequest* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FriendRequest* New() const final {
    return CreateMaybeMessage<FriendRequest>(nullptr);
  }

  FriendRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FriendRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FriendRequest& from);
  void MergeFrom(const FriendRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FriendRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "myfriend.FriendRequest";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_friend_2eproto);
    return ::descriptor_table_friend_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kPwsFieldNumber = 2,
  };
  // bytes name = 1;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const void* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // bytes pws = 2;
  void clear_pws();
  const std::string& pws() const;
  void set_pws(const std::string& value);
  void set_pws(std::string&& value);
  void set_pws(const char* value);
  void set_pws(const void* value, size_t size);
  std::string* mutable_pws();
  std::string* release_pws();
  void set_allocated_pws(std::string* pws);
  private:
  const std::string& _internal_pws() const;
  void _internal_set_pws(const std::string& value);
  std::string* _internal_mutable_pws();
  public:

  // @@protoc_insertion_point(class_scope:myfriend.FriendRequest)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr pws_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_friend_2eproto;
};
// -------------------------------------------------------------------

class FriendResponse :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:myfriend.FriendResponse) */ {
 public:
  FriendResponse();
  virtual ~FriendResponse();

  FriendResponse(const FriendResponse& from);
  FriendResponse(FriendResponse&& from) noexcept
    : FriendResponse() {
    *this = ::std::move(from);
  }

  inline FriendResponse& operator=(const FriendResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline FriendResponse& operator=(FriendResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
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
  static const FriendResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FriendResponse* internal_default_instance() {
    return reinterpret_cast<const FriendResponse*>(
               &_FriendResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(FriendResponse& a, FriendResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(FriendResponse* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FriendResponse* New() const final {
    return CreateMaybeMessage<FriendResponse>(nullptr);
  }

  FriendResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FriendResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FriendResponse& from);
  void MergeFrom(const FriendResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FriendResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "myfriend.FriendResponse";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_friend_2eproto);
    return ::descriptor_table_friend_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFriendsFieldNumber = 2,
    kResultFieldNumber = 1,
  };
  // repeated bytes friends = 2;
  int friends_size() const;
  private:
  int _internal_friends_size() const;
  public:
  void clear_friends();
  const std::string& friends(int index) const;
  std::string* mutable_friends(int index);
  void set_friends(int index, const std::string& value);
  void set_friends(int index, std::string&& value);
  void set_friends(int index, const char* value);
  void set_friends(int index, const void* value, size_t size);
  std::string* add_friends();
  void add_friends(const std::string& value);
  void add_friends(std::string&& value);
  void add_friends(const char* value);
  void add_friends(const void* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& friends() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_friends();
  private:
  const std::string& _internal_friends(int index) const;
  std::string* _internal_add_friends();
  public:

  // .myfriend.resultCode result = 1;
  bool has_result() const;
  private:
  bool _internal_has_result() const;
  public:
  void clear_result();
  const ::myfriend::resultCode& result() const;
  ::myfriend::resultCode* release_result();
  ::myfriend::resultCode* mutable_result();
  void set_allocated_result(::myfriend::resultCode* result);
  private:
  const ::myfriend::resultCode& _internal_result() const;
  ::myfriend::resultCode* _internal_mutable_result();
  public:

  // @@protoc_insertion_point(class_scope:myfriend.FriendResponse)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> friends_;
  ::myfriend::resultCode* result_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_friend_2eproto;
};
// ===================================================================

class FriendServiceRpc_Stub;

class FriendServiceRpc : public ::PROTOBUF_NAMESPACE_ID::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline FriendServiceRpc() {};
 public:
  virtual ~FriendServiceRpc();

  typedef FriendServiceRpc_Stub Stub;

  static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* descriptor();

  virtual void getFriendlist(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::myfriend::FriendRequest* request,
                       ::myfriend::FriendResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                  ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                  const ::PROTOBUF_NAMESPACE_ID::Message* request,
                  ::PROTOBUF_NAMESPACE_ID::Message* response,
                  ::google::protobuf::Closure* done);
  const ::PROTOBUF_NAMESPACE_ID::Message& GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;
  const ::PROTOBUF_NAMESPACE_ID::Message& GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FriendServiceRpc);
};

class FriendServiceRpc_Stub : public FriendServiceRpc {
 public:
  FriendServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel);
  FriendServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
                   ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership);
  ~FriendServiceRpc_Stub();

  inline ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel() { return channel_; }

  // implements FriendServiceRpc ------------------------------------------

  void getFriendlist(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::myfriend::FriendRequest* request,
                       ::myfriend::FriendResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FriendServiceRpc_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// resultCode

// int32 errcode = 1;
inline void resultCode::clear_errcode() {
  errcode_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 resultCode::_internal_errcode() const {
  return errcode_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 resultCode::errcode() const {
  // @@protoc_insertion_point(field_get:myfriend.resultCode.errcode)
  return _internal_errcode();
}
inline void resultCode::_internal_set_errcode(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  errcode_ = value;
}
inline void resultCode::set_errcode(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_errcode(value);
  // @@protoc_insertion_point(field_set:myfriend.resultCode.errcode)
}

// bytes errmsg = 2;
inline void resultCode::clear_errmsg() {
  errmsg_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& resultCode::errmsg() const {
  // @@protoc_insertion_point(field_get:myfriend.resultCode.errmsg)
  return _internal_errmsg();
}
inline void resultCode::set_errmsg(const std::string& value) {
  _internal_set_errmsg(value);
  // @@protoc_insertion_point(field_set:myfriend.resultCode.errmsg)
}
inline std::string* resultCode::mutable_errmsg() {
  // @@protoc_insertion_point(field_mutable:myfriend.resultCode.errmsg)
  return _internal_mutable_errmsg();
}
inline const std::string& resultCode::_internal_errmsg() const {
  return errmsg_.GetNoArena();
}
inline void resultCode::_internal_set_errmsg(const std::string& value) {
  
  errmsg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void resultCode::set_errmsg(std::string&& value) {
  
  errmsg_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:myfriend.resultCode.errmsg)
}
inline void resultCode::set_errmsg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  errmsg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:myfriend.resultCode.errmsg)
}
inline void resultCode::set_errmsg(const void* value, size_t size) {
  
  errmsg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:myfriend.resultCode.errmsg)
}
inline std::string* resultCode::_internal_mutable_errmsg() {
  
  return errmsg_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* resultCode::release_errmsg() {
  // @@protoc_insertion_point(field_release:myfriend.resultCode.errmsg)
  
  return errmsg_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void resultCode::set_allocated_errmsg(std::string* errmsg) {
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), errmsg);
  // @@protoc_insertion_point(field_set_allocated:myfriend.resultCode.errmsg)
}

// -------------------------------------------------------------------

// FriendRequest

// bytes name = 1;
inline void FriendRequest::clear_name() {
  name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& FriendRequest::name() const {
  // @@protoc_insertion_point(field_get:myfriend.FriendRequest.name)
  return _internal_name();
}
inline void FriendRequest::set_name(const std::string& value) {
  _internal_set_name(value);
  // @@protoc_insertion_point(field_set:myfriend.FriendRequest.name)
}
inline std::string* FriendRequest::mutable_name() {
  // @@protoc_insertion_point(field_mutable:myfriend.FriendRequest.name)
  return _internal_mutable_name();
}
inline const std::string& FriendRequest::_internal_name() const {
  return name_.GetNoArena();
}
inline void FriendRequest::_internal_set_name(const std::string& value) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void FriendRequest::set_name(std::string&& value) {
  
  name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:myfriend.FriendRequest.name)
}
inline void FriendRequest::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:myfriend.FriendRequest.name)
}
inline void FriendRequest::set_name(const void* value, size_t size) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:myfriend.FriendRequest.name)
}
inline std::string* FriendRequest::_internal_mutable_name() {
  
  return name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* FriendRequest::release_name() {
  // @@protoc_insertion_point(field_release:myfriend.FriendRequest.name)
  
  return name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void FriendRequest::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:myfriend.FriendRequest.name)
}

// bytes pws = 2;
inline void FriendRequest::clear_pws() {
  pws_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& FriendRequest::pws() const {
  // @@protoc_insertion_point(field_get:myfriend.FriendRequest.pws)
  return _internal_pws();
}
inline void FriendRequest::set_pws(const std::string& value) {
  _internal_set_pws(value);
  // @@protoc_insertion_point(field_set:myfriend.FriendRequest.pws)
}
inline std::string* FriendRequest::mutable_pws() {
  // @@protoc_insertion_point(field_mutable:myfriend.FriendRequest.pws)
  return _internal_mutable_pws();
}
inline const std::string& FriendRequest::_internal_pws() const {
  return pws_.GetNoArena();
}
inline void FriendRequest::_internal_set_pws(const std::string& value) {
  
  pws_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void FriendRequest::set_pws(std::string&& value) {
  
  pws_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:myfriend.FriendRequest.pws)
}
inline void FriendRequest::set_pws(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  pws_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:myfriend.FriendRequest.pws)
}
inline void FriendRequest::set_pws(const void* value, size_t size) {
  
  pws_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:myfriend.FriendRequest.pws)
}
inline std::string* FriendRequest::_internal_mutable_pws() {
  
  return pws_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* FriendRequest::release_pws() {
  // @@protoc_insertion_point(field_release:myfriend.FriendRequest.pws)
  
  return pws_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void FriendRequest::set_allocated_pws(std::string* pws) {
  if (pws != nullptr) {
    
  } else {
    
  }
  pws_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), pws);
  // @@protoc_insertion_point(field_set_allocated:myfriend.FriendRequest.pws)
}

// -------------------------------------------------------------------

// FriendResponse

// .myfriend.resultCode result = 1;
inline bool FriendResponse::_internal_has_result() const {
  return this != internal_default_instance() && result_ != nullptr;
}
inline bool FriendResponse::has_result() const {
  return _internal_has_result();
}
inline void FriendResponse::clear_result() {
  if (GetArenaNoVirtual() == nullptr && result_ != nullptr) {
    delete result_;
  }
  result_ = nullptr;
}
inline const ::myfriend::resultCode& FriendResponse::_internal_result() const {
  const ::myfriend::resultCode* p = result_;
  return p != nullptr ? *p : *reinterpret_cast<const ::myfriend::resultCode*>(
      &::myfriend::_resultCode_default_instance_);
}
inline const ::myfriend::resultCode& FriendResponse::result() const {
  // @@protoc_insertion_point(field_get:myfriend.FriendResponse.result)
  return _internal_result();
}
inline ::myfriend::resultCode* FriendResponse::release_result() {
  // @@protoc_insertion_point(field_release:myfriend.FriendResponse.result)
  
  ::myfriend::resultCode* temp = result_;
  result_ = nullptr;
  return temp;
}
inline ::myfriend::resultCode* FriendResponse::_internal_mutable_result() {
  
  if (result_ == nullptr) {
    auto* p = CreateMaybeMessage<::myfriend::resultCode>(GetArenaNoVirtual());
    result_ = p;
  }
  return result_;
}
inline ::myfriend::resultCode* FriendResponse::mutable_result() {
  // @@protoc_insertion_point(field_mutable:myfriend.FriendResponse.result)
  return _internal_mutable_result();
}
inline void FriendResponse::set_allocated_result(::myfriend::resultCode* result) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete result_;
  }
  if (result) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      result = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, result, submessage_arena);
    }
    
  } else {
    
  }
  result_ = result;
  // @@protoc_insertion_point(field_set_allocated:myfriend.FriendResponse.result)
}

// repeated bytes friends = 2;
inline int FriendResponse::_internal_friends_size() const {
  return friends_.size();
}
inline int FriendResponse::friends_size() const {
  return _internal_friends_size();
}
inline void FriendResponse::clear_friends() {
  friends_.Clear();
}
inline std::string* FriendResponse::add_friends() {
  // @@protoc_insertion_point(field_add_mutable:myfriend.FriendResponse.friends)
  return _internal_add_friends();
}
inline const std::string& FriendResponse::_internal_friends(int index) const {
  return friends_.Get(index);
}
inline const std::string& FriendResponse::friends(int index) const {
  // @@protoc_insertion_point(field_get:myfriend.FriendResponse.friends)
  return _internal_friends(index);
}
inline std::string* FriendResponse::mutable_friends(int index) {
  // @@protoc_insertion_point(field_mutable:myfriend.FriendResponse.friends)
  return friends_.Mutable(index);
}
inline void FriendResponse::set_friends(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:myfriend.FriendResponse.friends)
  friends_.Mutable(index)->assign(value);
}
inline void FriendResponse::set_friends(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:myfriend.FriendResponse.friends)
  friends_.Mutable(index)->assign(std::move(value));
}
inline void FriendResponse::set_friends(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  friends_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:myfriend.FriendResponse.friends)
}
inline void FriendResponse::set_friends(int index, const void* value, size_t size) {
  friends_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:myfriend.FriendResponse.friends)
}
inline std::string* FriendResponse::_internal_add_friends() {
  return friends_.Add();
}
inline void FriendResponse::add_friends(const std::string& value) {
  friends_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:myfriend.FriendResponse.friends)
}
inline void FriendResponse::add_friends(std::string&& value) {
  friends_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:myfriend.FriendResponse.friends)
}
inline void FriendResponse::add_friends(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  friends_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:myfriend.FriendResponse.friends)
}
inline void FriendResponse::add_friends(const void* value, size_t size) {
  friends_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:myfriend.FriendResponse.friends)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
FriendResponse::friends() const {
  // @@protoc_insertion_point(field_list:myfriend.FriendResponse.friends)
  return friends_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
FriendResponse::mutable_friends() {
  // @@protoc_insertion_point(field_mutable_list:myfriend.FriendResponse.friends)
  return &friends_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace myfriend

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_friend_2eproto
