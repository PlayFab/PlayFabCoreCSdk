#include "stdafx.h"
#include "GameServerDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace GameServer
{

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

} // namespace GameServer
} // namespace PlayFab
