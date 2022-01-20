#include "stdafx.h"
#include "PlayerDataManagementDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace PlayerDataManagement
{

JsonValue GetDataReportRequest::ToJson() const
{
    return GetDataReportRequest::ToJson(this->Model());
}

JsonValue GetDataReportRequest::ToJson(const PFPlayerDataManagementGetDataReportRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Day", input.day);
    JsonUtils::ObjectAddMember(output, "Month", input.month);
    JsonUtils::ObjectAddMember(output, "ReportName", input.reportName);
    JsonUtils::ObjectAddMember(output, "Year", input.year);
    return output;
}

void GetDataReportResult::FromJson(const JsonValue& input)
{
    String downloadUrl{};
    JsonUtils::ObjectGetMember(input, "DownloadUrl", downloadUrl);
    this->SetDownloadUrl(std::move(downloadUrl));
}

size_t GetDataReportResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementGetDataReportResult const*> GetDataReportResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetDataReportResult>(&this->Model());
}

size_t GetDataReportResult::RequiredBufferSize(const PFPlayerDataManagementGetDataReportResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.downloadUrl)
    {
        requiredSize += (std::strlen(model.downloadUrl) + 1);
    }
    return requiredSize;
}

HRESULT GetDataReportResult::Copy(const PFPlayerDataManagementGetDataReportResult& input, PFPlayerDataManagementGetDataReportResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.downloadUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.downloadUrl = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetUserDataRequest::ToJson() const
{
    return GetUserDataRequest::ToJson(this->Model());
}

JsonValue GetUserDataRequest::ToJson(const PFPlayerDataManagementGetUserDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "IfChangedFromDataVersion", input.ifChangedFromDataVersion);
    JsonUtils::ObjectAddMemberArray(output, "Keys", input.keys, input.keysCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void AdminGetUserDataResult::FromJson(const JsonValue& input)
{
    ModelDictionaryEntryVector<UserDataRecord> data{};
    JsonUtils::ObjectGetMember<UserDataRecord>(input, "Data", data);
    this->SetData(std::move(data));

    JsonUtils::ObjectGetMember(input, "DataVersion", this->m_model.dataVersion);

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t AdminGetUserDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementAdminGetUserDataResult const*> AdminGetUserDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AdminGetUserDataResult>(&this->Model());
}

size_t AdminGetUserDataResult::RequiredBufferSize(const PFPlayerDataManagementAdminGetUserDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFUserDataRecordDictionaryEntry) + sizeof(PFUserDataRecordDictionaryEntry) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += (std::strlen(model.data[i].key) + 1);
        requiredSize += UserDataRecord::RequiredBufferSize(*model.data[i].value);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT AdminGetUserDataResult::Copy(const PFPlayerDataManagementAdminGetUserDataResult& input, PFPlayerDataManagementAdminGetUserDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary<UserDataRecord>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AdminUpdateUserDataRequest::ToJson() const
{
    return AdminUpdateUserDataRequest::ToJson(this->Model());
}

JsonValue AdminUpdateUserDataRequest::ToJson(const PFPlayerDataManagementAdminUpdateUserDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "Permission", input.permission);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void UpdateUserDataResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "DataVersion", this->m_model.dataVersion);
}

size_t UpdateUserDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementUpdateUserDataResult const*> UpdateUserDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UpdateUserDataResult>(&this->Model());
}

size_t UpdateUserDataResult::RequiredBufferSize(const PFPlayerDataManagementUpdateUserDataResult& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT UpdateUserDataResult::Copy(const PFPlayerDataManagementUpdateUserDataResult& input, PFPlayerDataManagementUpdateUserDataResult& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

JsonValue UpdateUserInternalDataRequest::ToJson() const
{
    return UpdateUserInternalDataRequest::ToJson(this->Model());
}

JsonValue UpdateUserInternalDataRequest::ToJson(const PFPlayerDataManagementUpdateUserInternalDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void ClientGetUserDataResult::FromJson(const JsonValue& input)
{
    ModelDictionaryEntryVector<UserDataRecord> data{};
    JsonUtils::ObjectGetMember<UserDataRecord>(input, "Data", data);
    this->SetData(std::move(data));

    JsonUtils::ObjectGetMember(input, "DataVersion", this->m_model.dataVersion);
}

size_t ClientGetUserDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementClientGetUserDataResult const*> ClientGetUserDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ClientGetUserDataResult>(&this->Model());
}

size_t ClientGetUserDataResult::RequiredBufferSize(const PFPlayerDataManagementClientGetUserDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFUserDataRecordDictionaryEntry) + sizeof(PFUserDataRecordDictionaryEntry) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += (std::strlen(model.data[i].key) + 1);
        requiredSize += UserDataRecord::RequiredBufferSize(*model.data[i].value);
    }
    return requiredSize;
}

HRESULT ClientGetUserDataResult::Copy(const PFPlayerDataManagementClientGetUserDataResult& input, PFPlayerDataManagementClientGetUserDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary<UserDataRecord>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientUpdateUserDataRequest::ToJson() const
{
    return ClientUpdateUserDataRequest::ToJson(this->Model());
}

JsonValue ClientUpdateUserDataRequest::ToJson(const PFPlayerDataManagementClientUpdateUserDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "Permission", input.permission);
    return output;
}

void ServerGetUserDataResult::FromJson(const JsonValue& input)
{
    ModelDictionaryEntryVector<UserDataRecord> data{};
    JsonUtils::ObjectGetMember<UserDataRecord>(input, "Data", data);
    this->SetData(std::move(data));

    JsonUtils::ObjectGetMember(input, "DataVersion", this->m_model.dataVersion);

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t ServerGetUserDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementServerGetUserDataResult const*> ServerGetUserDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ServerGetUserDataResult>(&this->Model());
}

size_t ServerGetUserDataResult::RequiredBufferSize(const PFPlayerDataManagementServerGetUserDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFUserDataRecordDictionaryEntry) + sizeof(PFUserDataRecordDictionaryEntry) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += (std::strlen(model.data[i].key) + 1);
        requiredSize += UserDataRecord::RequiredBufferSize(*model.data[i].value);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT ServerGetUserDataResult::Copy(const PFPlayerDataManagementServerGetUserDataResult& input, PFPlayerDataManagementServerGetUserDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary<UserDataRecord>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ServerUpdateUserDataRequest::ToJson() const
{
    return ServerUpdateUserDataRequest::ToJson(this->Model());
}

JsonValue ServerUpdateUserDataRequest::ToJson(const PFPlayerDataManagementServerUpdateUserDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "Permission", input.permission);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

} // namespace PlayerDataManagement
} // namespace PlayFab
