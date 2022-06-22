#include "stdafx.h"
#include "EventsDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Events
{

JsonValue EventContents::ToJson() const
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", customTags);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", entity);
    JsonUtils::ObjectAddMember(output, "EventNamespace", eventNamespace);
    JsonUtils::ObjectAddMember(output, "Name", name);
    JsonUtils::ObjectAddMember(output, "OriginalId", originalId);
    JsonUtils::ObjectAddMemberTime(output, "OriginalTimestamp", originalTimestamp);
    JsonUtils::ObjectAddMember(output, "Payload", payload);
    JsonUtils::ObjectAddMember(output, "PayloadJSON", payloadJSON);
    return output;
}

JsonValue WriteEventsRequest::ToJson() const
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", customTags);
    JsonUtils::ObjectAddMemberArray<EventContents>(output, "Events", events);
    return output;
}

void WriteEventsResponse::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "AssignedEventIds", assignedEventIds);}

} // namespace Events
} // namespace PlayFab
