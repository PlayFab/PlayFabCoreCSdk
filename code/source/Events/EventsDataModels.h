#pragma once

#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Events
{

// Events Classes
class EventContents : public InputModel
{
public:
    // InputModel
    JsonValue ToJson() const override;

    Map<String, String> customTags;
    StdExtra::optional<EntityKey> entity;
    String eventNamespace;
    String name;
    String originalId;
    StdExtra::optional<time_t> originalTimestamp;
    JsonValue payload;
    String payloadJSON;
};

class WriteEventsRequest : public InputModel
{
public:
    // InputModel
    JsonValue ToJson() const override;

    Map<String, String> customTags;
    Vector<EventContents> events;
};

class WriteEventsResponse : public ServiceOutputModel
{
public:
    void FromJson(const JsonValue& input);

    Vector<String> assignedEventIds;
};

} // namespace Events
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
