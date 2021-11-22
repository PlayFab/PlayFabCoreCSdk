#pragma once

#include <playfab/cpp/PFSharedGroupsDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace SharedGroups
{

// SharedGroups Classes
class AddSharedGroupMembersRequest : public Wrappers::PFSharedGroupsAddSharedGroupMembersRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFSharedGroupsAddSharedGroupMembersRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSharedGroupsAddSharedGroupMembersRequest& input);

};

class CreateSharedGroupRequest : public Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSharedGroupsCreateSharedGroupRequest& input);

};

class CreateSharedGroupResult : public Wrappers::PFSharedGroupsCreateSharedGroupResultWrapper<Allocator>, public OutputModel<PFSharedGroupsCreateSharedGroupResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFSharedGroupsCreateSharedGroupResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSharedGroupsCreateSharedGroupResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSharedGroupsCreateSharedGroupResult& model);
    static HRESULT Copy(const PFSharedGroupsCreateSharedGroupResult& input, PFSharedGroupsCreateSharedGroupResult& output, ModelBuffer& buffer);
};

class GetSharedGroupDataRequest : public Wrappers::PFSharedGroupsGetSharedGroupDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFSharedGroupsGetSharedGroupDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSharedGroupsGetSharedGroupDataRequest& input);

};

class SharedGroupDataRecord : public Wrappers::PFSharedGroupsSharedGroupDataRecordWrapper<Allocator>, public OutputModel<PFSharedGroupsSharedGroupDataRecord>
{
public:
    using ModelWrapperType = typename Wrappers::PFSharedGroupsSharedGroupDataRecordWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSharedGroupsSharedGroupDataRecord const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSharedGroupsSharedGroupDataRecord& model);
    static HRESULT Copy(const PFSharedGroupsSharedGroupDataRecord& input, PFSharedGroupsSharedGroupDataRecord& output, ModelBuffer& buffer);
};

class GetSharedGroupDataResult : public Wrappers::PFSharedGroupsGetSharedGroupDataResultWrapper<Allocator>, public OutputModel<PFSharedGroupsGetSharedGroupDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFSharedGroupsGetSharedGroupDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSharedGroupsGetSharedGroupDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSharedGroupsGetSharedGroupDataResult& model);
    static HRESULT Copy(const PFSharedGroupsGetSharedGroupDataResult& input, PFSharedGroupsGetSharedGroupDataResult& output, ModelBuffer& buffer);
};

class RemoveSharedGroupMembersRequest : public Wrappers::PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSharedGroupsRemoveSharedGroupMembersRequest& input);

};

class UpdateSharedGroupDataRequest : public Wrappers::PFSharedGroupsUpdateSharedGroupDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFSharedGroupsUpdateSharedGroupDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSharedGroupsUpdateSharedGroupDataRequest& input);

};

class DeleteSharedGroupRequest : public Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSharedGroupsDeleteSharedGroupRequest& input);

};

} // namespace SharedGroups
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
