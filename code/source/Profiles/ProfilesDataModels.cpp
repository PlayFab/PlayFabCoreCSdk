#include "stdafx.h"
#include "ProfilesDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Profiles
{

JsonValue GetGlobalPolicyRequest::ToJson() const
{
    return GetGlobalPolicyRequest::ToJson(this->Model());
}

JsonValue GetGlobalPolicyRequest::ToJson(const PFProfilesGetGlobalPolicyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    return output;
}

JsonValue EntityPermissionStatement::ToJson() const
{
    return EntityPermissionStatement::ToJson(this->Model());
}

JsonValue EntityPermissionStatement::ToJson(const PFProfilesEntityPermissionStatement& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Action", input.action);
    JsonUtils::ObjectAddMember(output, "Comment", input.comment);
    JsonUtils::ObjectAddMember(output, "Condition", input.condition);
    JsonUtils::ObjectAddMember(output, "Effect", input.effect);
    JsonUtils::ObjectAddMember(output, "Principal", input.principal);
    JsonUtils::ObjectAddMember(output, "Resource", input.resource);
    return output;
}

void EntityPermissionStatement::FromJson(const JsonValue& input)
{
    String action{};
    JsonUtils::ObjectGetMember(input, "Action", action);
    this->SetAction(std::move(action));

    String comment{};
    JsonUtils::ObjectGetMember(input, "Comment", comment);
    this->SetComment(std::move(comment));

    JsonObject condition{};
    JsonUtils::ObjectGetMember(input, "Condition", condition);
    this->SetCondition(std::move(condition));

    JsonUtils::ObjectGetMember(input, "Effect", this->m_model.effect);

    JsonObject principal{};
    JsonUtils::ObjectGetMember(input, "Principal", principal);
    this->SetPrincipal(std::move(principal));

    String resource{};
    JsonUtils::ObjectGetMember(input, "Resource", resource);
    this->SetResource(std::move(resource));
}

size_t EntityPermissionStatement::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesEntityPermissionStatement const*> EntityPermissionStatement::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<EntityPermissionStatement>(&this->Model());
}

size_t EntityPermissionStatement::RequiredBufferSize(const PFProfilesEntityPermissionStatement& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.action)
    {
        requiredSize += (std::strlen(model.action) + 1);
    }
    if (model.comment)
    {
        requiredSize += (std::strlen(model.comment) + 1);
    }
    if (model.condition.stringValue)
    {
    requiredSize += (std::strlen(model.condition.stringValue) + 1);
    }
    if (model.principal.stringValue)
    {
    requiredSize += (std::strlen(model.principal.stringValue) + 1);
    }
    if (model.resource)
    {
        requiredSize += (std::strlen(model.resource) + 1);
    }
    return requiredSize;
}

HRESULT EntityPermissionStatement::Copy(const PFProfilesEntityPermissionStatement& input, PFProfilesEntityPermissionStatement& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.action); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.action = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.comment); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comment = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.condition.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.condition.stringValue = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.principal.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.principal.stringValue = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.resource); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.resource = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetGlobalPolicyResponse::FromJson(const JsonValue& input)
{
    ModelVector<EntityPermissionStatement> permissions{};
    JsonUtils::ObjectGetMember<EntityPermissionStatement>(input, "Permissions", permissions);
    this->SetPermissions(std::move(permissions));
}

size_t GetGlobalPolicyResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesGetGlobalPolicyResponse const*> GetGlobalPolicyResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetGlobalPolicyResponse>(&this->Model());
}

size_t GetGlobalPolicyResponse::RequiredBufferSize(const PFProfilesGetGlobalPolicyResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFProfilesEntityPermissionStatement*) + sizeof(PFProfilesEntityPermissionStatement*) * model.permissionsCount);
    for (size_t i = 0; i < model.permissionsCount; ++i)
    {
        requiredSize += EntityPermissionStatement::RequiredBufferSize(*model.permissions[i]);
    }
    return requiredSize;
}

HRESULT GetGlobalPolicyResponse::Copy(const PFProfilesGetGlobalPolicyResponse& input, PFProfilesGetGlobalPolicyResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<EntityPermissionStatement>(input.permissions, input.permissionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.permissions = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetEntityProfileRequest::ToJson() const
{
    return GetEntityProfileRequest::ToJson(this->Model());
}

JsonValue GetEntityProfileRequest::ToJson(const PFProfilesGetEntityProfileRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "DataAsObject", input.dataAsObject);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    return output;
}

void EntityProfileFileMetadata::FromJson(const JsonValue& input)
{
    String checksum{};
    JsonUtils::ObjectGetMember(input, "Checksum", checksum);
    this->SetChecksum(std::move(checksum));

    String fileName{};
    JsonUtils::ObjectGetMember(input, "FileName", fileName);
    this->SetFileName(std::move(fileName));

    JsonUtils::ObjectGetMemberTime(input, "LastModified", this->m_model.lastModified);

    JsonUtils::ObjectGetMember(input, "Size", this->m_model.size);
}

size_t EntityProfileFileMetadata::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesEntityProfileFileMetadata const*> EntityProfileFileMetadata::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<EntityProfileFileMetadata>(&this->Model());
}

size_t EntityProfileFileMetadata::RequiredBufferSize(const PFProfilesEntityProfileFileMetadata& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.checksum)
    {
        requiredSize += (std::strlen(model.checksum) + 1);
    }
    if (model.fileName)
    {
        requiredSize += (std::strlen(model.fileName) + 1);
    }
    return requiredSize;
}

HRESULT EntityProfileFileMetadata::Copy(const PFProfilesEntityProfileFileMetadata& input, PFProfilesEntityProfileFileMetadata& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.checksum); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.checksum = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.fileName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fileName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void EntityDataObject::FromJson(const JsonValue& input)
{
    JsonObject dataObject{};
    JsonUtils::ObjectGetMember(input, "DataObject", dataObject);
    this->SetDataObject(std::move(dataObject));

    String escapedDataObject{};
    JsonUtils::ObjectGetMember(input, "EscapedDataObject", escapedDataObject);
    this->SetEscapedDataObject(std::move(escapedDataObject));

    String objectName{};
    JsonUtils::ObjectGetMember(input, "ObjectName", objectName);
    this->SetObjectName(std::move(objectName));
}

size_t EntityDataObject::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesEntityDataObject const*> EntityDataObject::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<EntityDataObject>(&this->Model());
}

size_t EntityDataObject::RequiredBufferSize(const PFProfilesEntityDataObject& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.dataObject.stringValue)
    {
    requiredSize += (std::strlen(model.dataObject.stringValue) + 1);
    }
    if (model.escapedDataObject)
    {
        requiredSize += (std::strlen(model.escapedDataObject) + 1);
    }
    if (model.objectName)
    {
        requiredSize += (std::strlen(model.objectName) + 1);
    }
    return requiredSize;
}

HRESULT EntityDataObject::Copy(const PFProfilesEntityDataObject& input, PFProfilesEntityDataObject& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.dataObject.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.dataObject.stringValue = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.escapedDataObject); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.escapedDataObject = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.objectName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.objectName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void EntityStatisticChildValue::FromJson(const JsonValue& input)
{
    String childName{};
    JsonUtils::ObjectGetMember(input, "ChildName", childName);
    this->SetChildName(std::move(childName));

    String metadata{};
    JsonUtils::ObjectGetMember(input, "Metadata", metadata);
    this->SetMetadata(std::move(metadata));

    JsonUtils::ObjectGetMember(input, "Value", this->m_model.value);
}

size_t EntityStatisticChildValue::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesEntityStatisticChildValue const*> EntityStatisticChildValue::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<EntityStatisticChildValue>(&this->Model());
}

size_t EntityStatisticChildValue::RequiredBufferSize(const PFProfilesEntityStatisticChildValue& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.childName)
    {
        requiredSize += (std::strlen(model.childName) + 1);
    }
    if (model.metadata)
    {
        requiredSize += (std::strlen(model.metadata) + 1);
    }
    return requiredSize;
}

HRESULT EntityStatisticChildValue::Copy(const PFProfilesEntityStatisticChildValue& input, PFProfilesEntityStatisticChildValue& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.childName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.childName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.metadata); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.metadata = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void EntityStatisticValue::FromJson(const JsonValue& input)
{
    ModelDictionaryEntryVector<EntityStatisticChildValue> childStatistics{};
    JsonUtils::ObjectGetMember<EntityStatisticChildValue>(input, "ChildStatistics", childStatistics);
    this->SetChildStatistics(std::move(childStatistics));

    String metadata{};
    JsonUtils::ObjectGetMember(input, "Metadata", metadata);
    this->SetMetadata(std::move(metadata));

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    StdExtra::optional<int32_t> value{};
    JsonUtils::ObjectGetMember(input, "Value", value);
    this->SetValue(std::move(value));

    JsonUtils::ObjectGetMember(input, "Version", this->m_model.version);
}

size_t EntityStatisticValue::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesEntityStatisticValue const*> EntityStatisticValue::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<EntityStatisticValue>(&this->Model());
}

size_t EntityStatisticValue::RequiredBufferSize(const PFProfilesEntityStatisticValue& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFProfilesEntityStatisticChildValueDictionaryEntry) + sizeof(PFProfilesEntityStatisticChildValueDictionaryEntry) * model.childStatisticsCount);
    for (size_t i = 0; i < model.childStatisticsCount; ++i)
    {
        requiredSize += (std::strlen(model.childStatistics[i].key) + 1);
        requiredSize += EntityStatisticChildValue::RequiredBufferSize(*model.childStatistics[i].value);
    }
    if (model.metadata)
    {
        requiredSize += (std::strlen(model.metadata) + 1);
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    if (model.value)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    return requiredSize;
}

HRESULT EntityStatisticValue::Copy(const PFProfilesEntityStatisticValue& input, PFProfilesEntityStatisticValue& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary<EntityStatisticChildValue>(input.childStatistics, input.childStatisticsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.childStatistics = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.metadata); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.metadata = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.value); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.value = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void EntityProfileBody::FromJson(const JsonValue& input)
{
    String avatarUrl{};
    JsonUtils::ObjectGetMember(input, "AvatarUrl", avatarUrl);
    this->SetAvatarUrl(std::move(avatarUrl));

    JsonUtils::ObjectGetMemberTime(input, "Created", this->m_model.created);

    String displayName{};
    JsonUtils::ObjectGetMember(input, "DisplayName", displayName);
    this->SetDisplayName(std::move(displayName));

    StdExtra::optional<EntityKey> entity{};
    JsonUtils::ObjectGetMember(input, "Entity", entity);
    if (entity)
    {
        this->SetEntity(std::move(*entity));
    }

    String entityChain{};
    JsonUtils::ObjectGetMember(input, "EntityChain", entityChain);
    this->SetEntityChain(std::move(entityChain));

    CStringVector experimentVariants{};
    JsonUtils::ObjectGetMember(input, "ExperimentVariants", experimentVariants);
    this->SetExperimentVariants(std::move(experimentVariants));

    ModelDictionaryEntryVector<EntityProfileFileMetadata> files{};
    JsonUtils::ObjectGetMember<EntityProfileFileMetadata>(input, "Files", files);
    this->SetFiles(std::move(files));

    String language{};
    JsonUtils::ObjectGetMember(input, "Language", language);
    this->SetLanguage(std::move(language));

    String leaderboardMetadata{};
    JsonUtils::ObjectGetMember(input, "LeaderboardMetadata", leaderboardMetadata);
    this->SetLeaderboardMetadata(std::move(leaderboardMetadata));

    StdExtra::optional<EntityLineage> lineage{};
    JsonUtils::ObjectGetMember(input, "Lineage", lineage);
    if (lineage)
    {
        this->SetLineage(std::move(*lineage));
    }

    ModelDictionaryEntryVector<EntityDataObject> objects{};
    JsonUtils::ObjectGetMember<EntityDataObject>(input, "Objects", objects);
    this->SetObjects(std::move(objects));

    ModelVector<EntityPermissionStatement> permissions{};
    JsonUtils::ObjectGetMember<EntityPermissionStatement>(input, "Permissions", permissions);
    this->SetPermissions(std::move(permissions));

    ModelDictionaryEntryVector<EntityStatisticValue> statistics{};
    JsonUtils::ObjectGetMember<EntityStatisticValue>(input, "Statistics", statistics);
    this->SetStatistics(std::move(statistics));

    JsonUtils::ObjectGetMember(input, "VersionNumber", this->m_model.versionNumber);
}

size_t EntityProfileBody::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesEntityProfileBody const*> EntityProfileBody::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<EntityProfileBody>(&this->Model());
}

size_t EntityProfileBody::RequiredBufferSize(const PFProfilesEntityProfileBody& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.avatarUrl)
    {
        requiredSize += (std::strlen(model.avatarUrl) + 1);
    }
    if (model.displayName)
    {
        requiredSize += (std::strlen(model.displayName) + 1);
    }
    if (model.entity)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.entity);
    }
    if (model.entityChain)
    {
        requiredSize += (std::strlen(model.entityChain) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.experimentVariantsCount);
    for (size_t i = 0; i < model.experimentVariantsCount; ++i)
    {
        requiredSize += (std::strlen(model.experimentVariants[i]) + 1);
    }
    requiredSize += (alignof(PFProfilesEntityProfileFileMetadataDictionaryEntry) + sizeof(PFProfilesEntityProfileFileMetadataDictionaryEntry) * model.filesCount);
    for (size_t i = 0; i < model.filesCount; ++i)
    {
        requiredSize += (std::strlen(model.files[i].key) + 1);
        requiredSize += EntityProfileFileMetadata::RequiredBufferSize(*model.files[i].value);
    }
    if (model.language)
    {
        requiredSize += (std::strlen(model.language) + 1);
    }
    if (model.leaderboardMetadata)
    {
        requiredSize += (std::strlen(model.leaderboardMetadata) + 1);
    }
    if (model.lineage)
    {
        requiredSize += EntityLineage::RequiredBufferSize(*model.lineage);
    }
    requiredSize += (alignof(PFProfilesEntityDataObjectDictionaryEntry) + sizeof(PFProfilesEntityDataObjectDictionaryEntry) * model.objectsCount);
    for (size_t i = 0; i < model.objectsCount; ++i)
    {
        requiredSize += (std::strlen(model.objects[i].key) + 1);
        requiredSize += EntityDataObject::RequiredBufferSize(*model.objects[i].value);
    }
    requiredSize += (alignof(PFProfilesEntityPermissionStatement*) + sizeof(PFProfilesEntityPermissionStatement*) * model.permissionsCount);
    for (size_t i = 0; i < model.permissionsCount; ++i)
    {
        requiredSize += EntityPermissionStatement::RequiredBufferSize(*model.permissions[i]);
    }
    requiredSize += (alignof(PFProfilesEntityStatisticValueDictionaryEntry) + sizeof(PFProfilesEntityStatisticValueDictionaryEntry) * model.statisticsCount);
    for (size_t i = 0; i < model.statisticsCount; ++i)
    {
        requiredSize += (std::strlen(model.statistics[i].key) + 1);
        requiredSize += EntityStatisticValue::RequiredBufferSize(*model.statistics[i].value);
    }
    return requiredSize;
}

HRESULT EntityProfileBody::Copy(const PFProfilesEntityProfileBody& input, PFProfilesEntityProfileBody& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.avatarUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.avatarUrl = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.displayName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EntityKey>(input.entity); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.entity = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.entityChain); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.entityChain = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.experimentVariants, input.experimentVariantsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.experimentVariants = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<EntityProfileFileMetadata>(input.files, input.filesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.files = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.language); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.language = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.leaderboardMetadata); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.leaderboardMetadata = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EntityLineage>(input.lineage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lineage = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<EntityDataObject>(input.objects, input.objectsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.objects = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<EntityPermissionStatement>(input.permissions, input.permissionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.permissions = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<EntityStatisticValue>(input.statistics, input.statisticsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statistics = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetEntityProfileResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<EntityProfileBody> profile{};
    JsonUtils::ObjectGetMember(input, "Profile", profile);
    if (profile)
    {
        this->SetProfile(std::move(*profile));
    }
}

size_t GetEntityProfileResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesGetEntityProfileResponse const*> GetEntityProfileResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetEntityProfileResponse>(&this->Model());
}

size_t GetEntityProfileResponse::RequiredBufferSize(const PFProfilesGetEntityProfileResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.profile)
    {
        requiredSize += EntityProfileBody::RequiredBufferSize(*model.profile);
    }
    return requiredSize;
}

HRESULT GetEntityProfileResponse::Copy(const PFProfilesGetEntityProfileResponse& input, PFProfilesGetEntityProfileResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<EntityProfileBody>(input.profile); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.profile = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetEntityProfilesRequest::ToJson() const
{
    return GetEntityProfilesRequest::ToJson(this->Model());
}

JsonValue GetEntityProfilesRequest::ToJson(const PFProfilesGetEntityProfilesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "DataAsObject", input.dataAsObject);
    JsonUtils::ObjectAddMemberArray<EntityKey>(output, "Entities", input.entities, input.entitiesCount);
    return output;
}

void GetEntityProfilesResponse::FromJson(const JsonValue& input)
{
    ModelVector<EntityProfileBody> profiles{};
    JsonUtils::ObjectGetMember<EntityProfileBody>(input, "Profiles", profiles);
    this->SetProfiles(std::move(profiles));
}

size_t GetEntityProfilesResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesGetEntityProfilesResponse const*> GetEntityProfilesResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetEntityProfilesResponse>(&this->Model());
}

size_t GetEntityProfilesResponse::RequiredBufferSize(const PFProfilesGetEntityProfilesResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFProfilesEntityProfileBody*) + sizeof(PFProfilesEntityProfileBody*) * model.profilesCount);
    for (size_t i = 0; i < model.profilesCount; ++i)
    {
        requiredSize += EntityProfileBody::RequiredBufferSize(*model.profiles[i]);
    }
    return requiredSize;
}

HRESULT GetEntityProfilesResponse::Copy(const PFProfilesGetEntityProfilesResponse& input, PFProfilesGetEntityProfilesResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<EntityProfileBody>(input.profiles, input.profilesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.profiles = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetTitlePlayersFromMasterPlayerAccountIdsRequest::ToJson() const
{
    return GetTitlePlayersFromMasterPlayerAccountIdsRequest::ToJson(this->Model());
}

JsonValue GetTitlePlayersFromMasterPlayerAccountIdsRequest::ToJson(const PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray(output, "MasterPlayerAccountIds", input.masterPlayerAccountIds, input.masterPlayerAccountIdsCount);
    JsonUtils::ObjectAddMember(output, "TitleId", input.titleId);
    return output;
}

void GetTitlePlayersFromMasterPlayerAccountIdsResponse::FromJson(const JsonValue& input)
{
    String titleId{};
    JsonUtils::ObjectGetMember(input, "TitleId", titleId);
    this->SetTitleId(std::move(titleId));

    ModelDictionaryEntryVector<EntityKey> titlePlayerAccounts{};
    JsonUtils::ObjectGetMember<EntityKey>(input, "TitlePlayerAccounts", titlePlayerAccounts);
    this->SetTitlePlayerAccounts(std::move(titlePlayerAccounts));
}

size_t GetTitlePlayersFromMasterPlayerAccountIdsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse const*> GetTitlePlayersFromMasterPlayerAccountIdsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetTitlePlayersFromMasterPlayerAccountIdsResponse>(&this->Model());
}

size_t GetTitlePlayersFromMasterPlayerAccountIdsResponse::RequiredBufferSize(const PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.titleId)
    {
        requiredSize += (std::strlen(model.titleId) + 1);
    }
    requiredSize += (alignof(PFEntityKeyDictionaryEntry) + sizeof(PFEntityKeyDictionaryEntry) * model.titlePlayerAccountsCount);
    for (size_t i = 0; i < model.titlePlayerAccountsCount; ++i)
    {
        requiredSize += (std::strlen(model.titlePlayerAccounts[i].key) + 1);
        requiredSize += EntityKey::RequiredBufferSize(*model.titlePlayerAccounts[i].value);
    }
    return requiredSize;
}

HRESULT GetTitlePlayersFromMasterPlayerAccountIdsResponse::Copy(const PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse& input, PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.titleId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titleId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<EntityKey>(input.titlePlayerAccounts, input.titlePlayerAccountsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titlePlayerAccounts = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue SetGlobalPolicyRequest::ToJson() const
{
    return SetGlobalPolicyRequest::ToJson(this->Model());
}

JsonValue SetGlobalPolicyRequest::ToJson(const PFProfilesSetGlobalPolicyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<EntityPermissionStatement>(output, "Permissions", input.permissions, input.permissionsCount);
    return output;
}

JsonValue SetProfileLanguageRequest::ToJson() const
{
    return SetProfileLanguageRequest::ToJson(this->Model());
}

JsonValue SetProfileLanguageRequest::ToJson(const PFProfilesSetProfileLanguageRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "ExpectedVersion", input.expectedVersion);
    JsonUtils::ObjectAddMember(output, "Language", input.language);
    return output;
}

void SetProfileLanguageResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFOperationTypes> operationResult{};
    JsonUtils::ObjectGetMember(input, "OperationResult", operationResult);
    this->SetOperationResult(std::move(operationResult));

    StdExtra::optional<int32_t> versionNumber{};
    JsonUtils::ObjectGetMember(input, "VersionNumber", versionNumber);
    this->SetVersionNumber(std::move(versionNumber));
}

size_t SetProfileLanguageResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesSetProfileLanguageResponse const*> SetProfileLanguageResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SetProfileLanguageResponse>(&this->Model());
}

size_t SetProfileLanguageResponse::RequiredBufferSize(const PFProfilesSetProfileLanguageResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.operationResult)
    {
        requiredSize += (alignof(PFOperationTypes) + sizeof(PFOperationTypes));
    }
    if (model.versionNumber)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    return requiredSize;
}

HRESULT SetProfileLanguageResponse::Copy(const PFProfilesSetProfileLanguageResponse& input, PFProfilesSetProfileLanguageResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.operationResult); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.operationResult = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.versionNumber); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.versionNumber = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue SetEntityProfilePolicyRequest::ToJson() const
{
    return SetEntityProfilePolicyRequest::ToJson(this->Model());
}

JsonValue SetEntityProfilePolicyRequest::ToJson(const PFProfilesSetEntityProfilePolicyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMemberArray<EntityPermissionStatement>(output, "Statements", input.statements, input.statementsCount);
    return output;
}

void SetEntityProfilePolicyResponse::FromJson(const JsonValue& input)
{
    ModelVector<EntityPermissionStatement> permissions{};
    JsonUtils::ObjectGetMember<EntityPermissionStatement>(input, "Permissions", permissions);
    this->SetPermissions(std::move(permissions));
}

size_t SetEntityProfilePolicyResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFProfilesSetEntityProfilePolicyResponse const*> SetEntityProfilePolicyResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SetEntityProfilePolicyResponse>(&this->Model());
}

size_t SetEntityProfilePolicyResponse::RequiredBufferSize(const PFProfilesSetEntityProfilePolicyResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFProfilesEntityPermissionStatement*) + sizeof(PFProfilesEntityPermissionStatement*) * model.permissionsCount);
    for (size_t i = 0; i < model.permissionsCount; ++i)
    {
        requiredSize += EntityPermissionStatement::RequiredBufferSize(*model.permissions[i]);
    }
    return requiredSize;
}

HRESULT SetEntityProfilePolicyResponse::Copy(const PFProfilesSetEntityProfilePolicyResponse& input, PFProfilesSetEntityProfilePolicyResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<EntityPermissionStatement>(input.permissions, input.permissionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.permissions = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace Profiles
} // namespace PlayFab
