#include "stdafx.h"
#include "GameServerDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace GameServer
{

JsonValue AddServerBuildRequest::ToJson() const
{
    return AddServerBuildRequest::ToJson(this->Model());
}

JsonValue AddServerBuildRequest::ToJson(const PFGameServerAddServerBuildRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "ActiveRegions", input.activeRegions, input.activeRegionsCount);
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMember(output, "CommandLineTemplate", input.commandLineTemplate);
    JsonUtils::ObjectAddMember(output, "Comment", input.comment);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ExecutablePath", input.executablePath);
    JsonUtils::ObjectAddMember(output, "MaxGamesPerHost", input.maxGamesPerHost);
    JsonUtils::ObjectAddMember(output, "MinFreeGameSlots", input.minFreeGameSlots);
    return output;
}

void AddServerBuildResult::FromJson(const JsonValue& input)
{
    Vector<PFRegion> activeRegions{};
    JsonUtils::ObjectGetMember(input, "ActiveRegions", activeRegions);
    this->SetActiveRegions(std::move(activeRegions));

    String buildId{};
    JsonUtils::ObjectGetMember(input, "BuildId", buildId);
    this->SetBuildId(std::move(buildId));

    String commandLineTemplate{};
    JsonUtils::ObjectGetMember(input, "CommandLineTemplate", commandLineTemplate);
    this->SetCommandLineTemplate(std::move(commandLineTemplate));

    String comment{};
    JsonUtils::ObjectGetMember(input, "Comment", comment);
    this->SetComment(std::move(comment));

    String executablePath{};
    JsonUtils::ObjectGetMember(input, "ExecutablePath", executablePath);
    this->SetExecutablePath(std::move(executablePath));

    JsonUtils::ObjectGetMember(input, "MaxGamesPerHost", this->m_model.maxGamesPerHost);

    JsonUtils::ObjectGetMember(input, "MinFreeGameSlots", this->m_model.minFreeGameSlots);

    StdExtra::optional<PFGameServerGameBuildStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    JsonUtils::ObjectGetMemberTime(input, "Timestamp", this->m_model.timestamp);

    String titleId{};
    JsonUtils::ObjectGetMember(input, "TitleId", titleId);
    this->SetTitleId(std::move(titleId));
}

size_t AddServerBuildResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFGameServerAddServerBuildResult const*> AddServerBuildResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AddServerBuildResult>(&this->Model());
}

size_t AddServerBuildResult::RequiredBufferSize(const PFGameServerAddServerBuildResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFRegion) + sizeof(PFRegion) * model.activeRegionsCount);
    if (model.buildId)
    {
        requiredSize += (std::strlen(model.buildId) + 1);
    }
    if (model.commandLineTemplate)
    {
        requiredSize += (std::strlen(model.commandLineTemplate) + 1);
    }
    if (model.comment)
    {
        requiredSize += (std::strlen(model.comment) + 1);
    }
    if (model.executablePath)
    {
        requiredSize += (std::strlen(model.executablePath) + 1);
    }
    if (model.status)
    {
        requiredSize += (alignof(PFGameServerGameBuildStatus) + sizeof(PFGameServerGameBuildStatus));
    }
    if (model.titleId)
    {
        requiredSize += (std::strlen(model.titleId) + 1);
    }
    return requiredSize;
}

HRESULT AddServerBuildResult::Copy(const PFGameServerAddServerBuildResult& input, PFGameServerAddServerBuildResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.activeRegions, input.activeRegionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.activeRegions = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.commandLineTemplate); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.commandLineTemplate = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.comment); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comment = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.executablePath); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.executablePath = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.titleId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titleId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetServerBuildInfoRequest::ToJson() const
{
    return GetServerBuildInfoRequest::ToJson(this->Model());
}

JsonValue GetServerBuildInfoRequest::ToJson(const PFGameServerGetServerBuildInfoRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    return output;
}

void GetServerBuildInfoResult::FromJson(const JsonValue& input)
{
    Vector<PFRegion> activeRegions{};
    JsonUtils::ObjectGetMember(input, "ActiveRegions", activeRegions);
    this->SetActiveRegions(std::move(activeRegions));

    String buildId{};
    JsonUtils::ObjectGetMember(input, "BuildId", buildId);
    this->SetBuildId(std::move(buildId));

    String comment{};
    JsonUtils::ObjectGetMember(input, "Comment", comment);
    this->SetComment(std::move(comment));

    String errorMessage{};
    JsonUtils::ObjectGetMember(input, "ErrorMessage", errorMessage);
    this->SetErrorMessage(std::move(errorMessage));

    JsonUtils::ObjectGetMember(input, "MaxGamesPerHost", this->m_model.maxGamesPerHost);

    JsonUtils::ObjectGetMember(input, "MinFreeGameSlots", this->m_model.minFreeGameSlots);

    StdExtra::optional<PFGameServerGameBuildStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    JsonUtils::ObjectGetMemberTime(input, "Timestamp", this->m_model.timestamp);

    String titleId{};
    JsonUtils::ObjectGetMember(input, "TitleId", titleId);
    this->SetTitleId(std::move(titleId));
}

size_t GetServerBuildInfoResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFGameServerGetServerBuildInfoResult const*> GetServerBuildInfoResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetServerBuildInfoResult>(&this->Model());
}

size_t GetServerBuildInfoResult::RequiredBufferSize(const PFGameServerGetServerBuildInfoResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFRegion) + sizeof(PFRegion) * model.activeRegionsCount);
    if (model.buildId)
    {
        requiredSize += (std::strlen(model.buildId) + 1);
    }
    if (model.comment)
    {
        requiredSize += (std::strlen(model.comment) + 1);
    }
    if (model.errorMessage)
    {
        requiredSize += (std::strlen(model.errorMessage) + 1);
    }
    if (model.status)
    {
        requiredSize += (alignof(PFGameServerGameBuildStatus) + sizeof(PFGameServerGameBuildStatus));
    }
    if (model.titleId)
    {
        requiredSize += (std::strlen(model.titleId) + 1);
    }
    return requiredSize;
}

HRESULT GetServerBuildInfoResult::Copy(const PFGameServerGetServerBuildInfoResult& input, PFGameServerGetServerBuildInfoResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.activeRegions, input.activeRegionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.activeRegions = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.comment); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comment = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.errorMessage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.errorMessage = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.titleId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titleId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetServerBuildUploadURLRequest::ToJson() const
{
    return GetServerBuildUploadURLRequest::ToJson(this->Model());
}

JsonValue GetServerBuildUploadURLRequest::ToJson(const PFGameServerGetServerBuildUploadURLRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    return output;
}

void GetServerBuildUploadURLResult::FromJson(const JsonValue& input)
{
    String URL{};
    JsonUtils::ObjectGetMember(input, "URL", URL);
    this->SetURL(std::move(URL));
}

size_t GetServerBuildUploadURLResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFGameServerGetServerBuildUploadURLResult const*> GetServerBuildUploadURLResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetServerBuildUploadURLResult>(&this->Model());
}

size_t GetServerBuildUploadURLResult::RequiredBufferSize(const PFGameServerGetServerBuildUploadURLResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.URL)
    {
        requiredSize += (std::strlen(model.URL) + 1);
    }
    return requiredSize;
}

HRESULT GetServerBuildUploadURLResult::Copy(const PFGameServerGetServerBuildUploadURLResult& input, PFGameServerGetServerBuildUploadURLResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.URL); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.URL = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ListBuildsResult::FromJson(const JsonValue& input)
{
    ModelVector<GetServerBuildInfoResult> builds{};
    JsonUtils::ObjectGetMember<GetServerBuildInfoResult>(input, "Builds", builds);
    this->SetBuilds(std::move(builds));
}

size_t ListBuildsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFGameServerListBuildsResult const*> ListBuildsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListBuildsResult>(&this->Model());
}

size_t ListBuildsResult::RequiredBufferSize(const PFGameServerListBuildsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFGameServerGetServerBuildInfoResult*) + sizeof(PFGameServerGetServerBuildInfoResult*) * model.buildsCount);
    for (size_t i = 0; i < model.buildsCount; ++i)
    {
        requiredSize += GetServerBuildInfoResult::RequiredBufferSize(*model.builds[i]);
    }
    return requiredSize;
}

HRESULT ListBuildsResult::Copy(const PFGameServerListBuildsResult& input, PFGameServerListBuildsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GetServerBuildInfoResult>(input.builds, input.buildsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.builds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ModifyServerBuildRequest::ToJson() const
{
    return ModifyServerBuildRequest::ToJson(this->Model());
}

JsonValue ModifyServerBuildRequest::ToJson(const PFGameServerModifyServerBuildRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "ActiveRegions", input.activeRegions, input.activeRegionsCount);
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMember(output, "CommandLineTemplate", input.commandLineTemplate);
    JsonUtils::ObjectAddMember(output, "Comment", input.comment);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ExecutablePath", input.executablePath);
    JsonUtils::ObjectAddMember(output, "MaxGamesPerHost", input.maxGamesPerHost);
    JsonUtils::ObjectAddMember(output, "MinFreeGameSlots", input.minFreeGameSlots);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    return output;
}

void ModifyServerBuildResult::FromJson(const JsonValue& input)
{
    Vector<PFRegion> activeRegions{};
    JsonUtils::ObjectGetMember(input, "ActiveRegions", activeRegions);
    this->SetActiveRegions(std::move(activeRegions));

    String buildId{};
    JsonUtils::ObjectGetMember(input, "BuildId", buildId);
    this->SetBuildId(std::move(buildId));

    String commandLineTemplate{};
    JsonUtils::ObjectGetMember(input, "CommandLineTemplate", commandLineTemplate);
    this->SetCommandLineTemplate(std::move(commandLineTemplate));

    String comment{};
    JsonUtils::ObjectGetMember(input, "Comment", comment);
    this->SetComment(std::move(comment));

    String executablePath{};
    JsonUtils::ObjectGetMember(input, "ExecutablePath", executablePath);
    this->SetExecutablePath(std::move(executablePath));

    JsonUtils::ObjectGetMember(input, "MaxGamesPerHost", this->m_model.maxGamesPerHost);

    JsonUtils::ObjectGetMember(input, "MinFreeGameSlots", this->m_model.minFreeGameSlots);

    StdExtra::optional<PFGameServerGameBuildStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    JsonUtils::ObjectGetMemberTime(input, "Timestamp", this->m_model.timestamp);

    String titleId{};
    JsonUtils::ObjectGetMember(input, "TitleId", titleId);
    this->SetTitleId(std::move(titleId));
}

size_t ModifyServerBuildResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFGameServerModifyServerBuildResult const*> ModifyServerBuildResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ModifyServerBuildResult>(&this->Model());
}

size_t ModifyServerBuildResult::RequiredBufferSize(const PFGameServerModifyServerBuildResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFRegion) + sizeof(PFRegion) * model.activeRegionsCount);
    if (model.buildId)
    {
        requiredSize += (std::strlen(model.buildId) + 1);
    }
    if (model.commandLineTemplate)
    {
        requiredSize += (std::strlen(model.commandLineTemplate) + 1);
    }
    if (model.comment)
    {
        requiredSize += (std::strlen(model.comment) + 1);
    }
    if (model.executablePath)
    {
        requiredSize += (std::strlen(model.executablePath) + 1);
    }
    if (model.status)
    {
        requiredSize += (alignof(PFGameServerGameBuildStatus) + sizeof(PFGameServerGameBuildStatus));
    }
    if (model.titleId)
    {
        requiredSize += (std::strlen(model.titleId) + 1);
    }
    return requiredSize;
}

HRESULT ModifyServerBuildResult::Copy(const PFGameServerModifyServerBuildResult& input, PFGameServerModifyServerBuildResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.activeRegions, input.activeRegionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.activeRegions = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.commandLineTemplate); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.commandLineTemplate = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.comment); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comment = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.executablePath); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.executablePath = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.titleId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titleId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RemoveServerBuildRequest::ToJson() const
{
    return RemoveServerBuildRequest::ToJson(this->Model());
}

JsonValue RemoveServerBuildRequest::ToJson(const PFGameServerRemoveServerBuildRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    return output;
}

} // namespace GameServer
} // namespace PlayFab
