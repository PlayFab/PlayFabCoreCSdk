#include "stdafx.h"
#include "EventsDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Events
{

JsonValue AddPlayerTagRequest::ToJson() const
{
    return AddPlayerTagRequest::ToJson(this->Model());
}

JsonValue AddPlayerTagRequest::ToJson(const PFEventsAddPlayerTagRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "TagName", input.tagName);
    return output;
}

JsonValue GetPlayerTagsRequest::ToJson() const
{
    return GetPlayerTagsRequest::ToJson(this->Model());
}

JsonValue GetPlayerTagsRequest::ToJson(const PFEventsGetPlayerTagsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Namespace", input.playfabNamespace);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void GetPlayerTagsResult::FromJson(const JsonValue& input)
{
    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    CStringVector tags{};
    JsonUtils::ObjectGetMember(input, "Tags", tags);
    this->SetTags(std::move(tags));
}

size_t GetPlayerTagsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFEventsGetPlayerTagsResult const*> GetPlayerTagsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayerTagsResult>(&this->Model());
}

size_t GetPlayerTagsResult::RequiredBufferSize(const PFEventsGetPlayerTagsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.tagsCount);
    for (size_t i = 0; i < model.tagsCount; ++i)
    {
        requiredSize += (std::strlen(model.tags[i]) + 1);
    }
    return requiredSize;
}

HRESULT GetPlayerTagsResult::Copy(const PFEventsGetPlayerTagsResult& input, PFEventsGetPlayerTagsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.tags, input.tagsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tags = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RemovePlayerTagRequest::ToJson() const
{
    return RemovePlayerTagRequest::ToJson(this->Model());
}

JsonValue RemovePlayerTagRequest::ToJson(const PFEventsRemovePlayerTagRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "TagName", input.tagName);
    return output;
}

JsonValue WriteClientCharacterEventRequest::ToJson() const
{
    return WriteClientCharacterEventRequest::ToJson(this->Model());
}

JsonValue WriteClientCharacterEventRequest::ToJson(const PFEventsWriteClientCharacterEventRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EventName", input.eventName);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    return output;
}

void WriteEventResponse::FromJson(const JsonValue& input)
{
    String eventId{};
    JsonUtils::ObjectGetMember(input, "EventId", eventId);
    this->SetEventId(std::move(eventId));
}

size_t WriteEventResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFEventsWriteEventResponse const*> WriteEventResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<WriteEventResponse>(&this->Model());
}

size_t WriteEventResponse::RequiredBufferSize(const PFEventsWriteEventResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.eventId)
    {
        requiredSize += (std::strlen(model.eventId) + 1);
    }
    return requiredSize;
}

HRESULT WriteEventResponse::Copy(const PFEventsWriteEventResponse& input, PFEventsWriteEventResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.eventId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.eventId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue WriteClientPlayerEventRequest::ToJson() const
{
    return WriteClientPlayerEventRequest::ToJson(this->Model());
}

JsonValue WriteClientPlayerEventRequest::ToJson(const PFEventsWriteClientPlayerEventRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EventName", input.eventName);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    return output;
}

JsonValue WriteTitleEventRequest::ToJson() const
{
    return WriteTitleEventRequest::ToJson(this->Model());
}

JsonValue WriteTitleEventRequest::ToJson(const PFEventsWriteTitleEventRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EventName", input.eventName);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    return output;
}

JsonValue WriteServerCharacterEventRequest::ToJson() const
{
    return WriteServerCharacterEventRequest::ToJson(this->Model());
}

JsonValue WriteServerCharacterEventRequest::ToJson(const PFEventsWriteServerCharacterEventRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EventName", input.eventName);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    return output;
}

JsonValue WriteServerPlayerEventRequest::ToJson() const
{
    return WriteServerPlayerEventRequest::ToJson(this->Model());
}

JsonValue WriteServerPlayerEventRequest::ToJson(const PFEventsWriteServerPlayerEventRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EventName", input.eventName);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    return output;
}

JsonValue EventContents::ToJson() const
{
    return EventContents::ToJson(this->Model());
}

JsonValue EventContents::ToJson(const PFEventsEventContents& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "EventNamespace", input.eventNamespace);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "OriginalId", input.originalId);
    JsonUtils::ObjectAddMemberTime(output, "OriginalTimestamp", input.originalTimestamp);
    JsonUtils::ObjectAddMember(output, "Payload", input.payload);
    JsonUtils::ObjectAddMember(output, "PayloadJSON", input.payloadJSON);
    return output;
}

JsonValue WriteEventsRequest::ToJson() const
{
    return WriteEventsRequest::ToJson(this->Model());
}

JsonValue WriteEventsRequest::ToJson(const PFEventsWriteEventsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<EventContents>(output, "Events", input.events, input.eventsCount);
    return output;
}

void WriteEventsResponse::FromJson(const JsonValue& input)
{
    CStringVector assignedEventIds{};
    JsonUtils::ObjectGetMember(input, "AssignedEventIds", assignedEventIds);
    this->SetAssignedEventIds(std::move(assignedEventIds));
}

size_t WriteEventsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFEventsWriteEventsResponse const*> WriteEventsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<WriteEventsResponse>(&this->Model());
}

size_t WriteEventsResponse::RequiredBufferSize(const PFEventsWriteEventsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.assignedEventIdsCount);
    for (size_t i = 0; i < model.assignedEventIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.assignedEventIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT WriteEventsResponse::Copy(const PFEventsWriteEventsResponse& input, PFEventsWriteEventsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.assignedEventIds, input.assignedEventIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.assignedEventIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace Events
} // namespace PlayFab
