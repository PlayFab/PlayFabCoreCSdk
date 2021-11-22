#include "stdafx.h"
#include "SharedGroupsDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace SharedGroups
{

JsonValue AddSharedGroupMembersRequest::ToJson() const
{
    return AddSharedGroupMembersRequest::ToJson(this->Model());
}

JsonValue AddSharedGroupMembersRequest::ToJson(const PFSharedGroupsAddSharedGroupMembersRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "PlayFabIds", input.playFabIds, input.playFabIdsCount);
    JsonUtils::ObjectAddMember(output, "SharedGroupId", input.sharedGroupId);
    return output;
}

JsonValue CreateSharedGroupRequest::ToJson() const
{
    return CreateSharedGroupRequest::ToJson(this->Model());
}

JsonValue CreateSharedGroupRequest::ToJson(const PFSharedGroupsCreateSharedGroupRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "SharedGroupId", input.sharedGroupId);
    return output;
}

void CreateSharedGroupResult::FromJson(const JsonValue& input)
{
    String sharedGroupId{};
    JsonUtils::ObjectGetMember(input, "SharedGroupId", sharedGroupId);
    this->SetSharedGroupId(std::move(sharedGroupId));
}

size_t CreateSharedGroupResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSharedGroupsCreateSharedGroupResult const*> CreateSharedGroupResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateSharedGroupResult>(&this->Model());
}

size_t CreateSharedGroupResult::RequiredBufferSize(const PFSharedGroupsCreateSharedGroupResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.sharedGroupId)
    {
        requiredSize += (std::strlen(model.sharedGroupId) + 1);
    }
    return requiredSize;
}

HRESULT CreateSharedGroupResult::Copy(const PFSharedGroupsCreateSharedGroupResult& input, PFSharedGroupsCreateSharedGroupResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.sharedGroupId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.sharedGroupId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetSharedGroupDataRequest::ToJson() const
{
    return GetSharedGroupDataRequest::ToJson(this->Model());
}

JsonValue GetSharedGroupDataRequest::ToJson(const PFSharedGroupsGetSharedGroupDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "GetMembers", input.getMembers);
    JsonUtils::ObjectAddMemberArray(output, "Keys", input.keys, input.keysCount);
    JsonUtils::ObjectAddMember(output, "SharedGroupId", input.sharedGroupId);
    return output;
}

void SharedGroupDataRecord::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMemberTime(input, "LastUpdated", this->m_model.lastUpdated);

    String lastUpdatedBy{};
    JsonUtils::ObjectGetMember(input, "LastUpdatedBy", lastUpdatedBy);
    this->SetLastUpdatedBy(std::move(lastUpdatedBy));

    StdExtra::optional<PFUserDataPermission> permission{};
    JsonUtils::ObjectGetMember(input, "Permission", permission);
    this->SetPermission(std::move(permission));

    String value{};
    JsonUtils::ObjectGetMember(input, "Value", value);
    this->SetValue(std::move(value));
}

size_t SharedGroupDataRecord::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSharedGroupsSharedGroupDataRecord const*> SharedGroupDataRecord::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SharedGroupDataRecord>(&this->Model());
}

size_t SharedGroupDataRecord::RequiredBufferSize(const PFSharedGroupsSharedGroupDataRecord& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.lastUpdatedBy)
    {
        requiredSize += (std::strlen(model.lastUpdatedBy) + 1);
    }
    if (model.permission)
    {
        requiredSize += (alignof(PFUserDataPermission) + sizeof(PFUserDataPermission));
    }
    if (model.value)
    {
        requiredSize += (std::strlen(model.value) + 1);
    }
    return requiredSize;
}

HRESULT SharedGroupDataRecord::Copy(const PFSharedGroupsSharedGroupDataRecord& input, PFSharedGroupsSharedGroupDataRecord& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.lastUpdatedBy); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lastUpdatedBy = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.permission); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.permission = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.value); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.value = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetSharedGroupDataResult::FromJson(const JsonValue& input)
{
    ModelDictionaryEntryVector<SharedGroupDataRecord> data{};
    JsonUtils::ObjectGetMember<SharedGroupDataRecord>(input, "Data", data);
    this->SetData(std::move(data));

    CStringVector members{};
    JsonUtils::ObjectGetMember(input, "Members", members);
    this->SetMembers(std::move(members));
}

size_t GetSharedGroupDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSharedGroupsGetSharedGroupDataResult const*> GetSharedGroupDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetSharedGroupDataResult>(&this->Model());
}

size_t GetSharedGroupDataResult::RequiredBufferSize(const PFSharedGroupsGetSharedGroupDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFSharedGroupsSharedGroupDataRecordDictionaryEntry) + sizeof(PFSharedGroupsSharedGroupDataRecordDictionaryEntry) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += (std::strlen(model.data[i].key) + 1);
        requiredSize += SharedGroupDataRecord::RequiredBufferSize(*model.data[i].value);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.membersCount);
    for (size_t i = 0; i < model.membersCount; ++i)
    {
        requiredSize += (std::strlen(model.members[i]) + 1);
    }
    return requiredSize;
}

HRESULT GetSharedGroupDataResult::Copy(const PFSharedGroupsGetSharedGroupDataResult& input, PFSharedGroupsGetSharedGroupDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary<SharedGroupDataRecord>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.members, input.membersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.members = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RemoveSharedGroupMembersRequest::ToJson() const
{
    return RemoveSharedGroupMembersRequest::ToJson(this->Model());
}

JsonValue RemoveSharedGroupMembersRequest::ToJson(const PFSharedGroupsRemoveSharedGroupMembersRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "PlayFabIds", input.playFabIds, input.playFabIdsCount);
    JsonUtils::ObjectAddMember(output, "SharedGroupId", input.sharedGroupId);
    return output;
}

JsonValue UpdateSharedGroupDataRequest::ToJson() const
{
    return UpdateSharedGroupDataRequest::ToJson(this->Model());
}

JsonValue UpdateSharedGroupDataRequest::ToJson(const PFSharedGroupsUpdateSharedGroupDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "Permission", input.permission);
    JsonUtils::ObjectAddMember(output, "SharedGroupId", input.sharedGroupId);
    return output;
}

JsonValue DeleteSharedGroupRequest::ToJson() const
{
    return DeleteSharedGroupRequest::ToJson(this->Model());
}

JsonValue DeleteSharedGroupRequest::ToJson(const PFSharedGroupsDeleteSharedGroupRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "SharedGroupId", input.sharedGroupId);
    return output;
}

} // namespace SharedGroups
} // namespace PlayFab
