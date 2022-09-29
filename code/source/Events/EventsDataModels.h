#pragma once

#include <playfab/cpp/PFEventsDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Events
{

// Events Classes
class AddPlayerTagRequest : public Wrappers::PFEventsAddPlayerTagRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsAddPlayerTagRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEventsAddPlayerTagRequest& input);

};

class GetPlayerTagsRequest : public Wrappers::PFEventsGetPlayerTagsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsGetPlayerTagsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEventsGetPlayerTagsRequest& input);

};

class GetPlayerTagsResult : public Wrappers::PFEventsGetPlayerTagsResultWrapper<Allocator>, public OutputModel<PFEventsGetPlayerTagsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsGetPlayerTagsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFEventsGetPlayerTagsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFEventsGetPlayerTagsResult& model);
    static HRESULT Copy(const PFEventsGetPlayerTagsResult& input, PFEventsGetPlayerTagsResult& output, ModelBuffer& buffer);
};

class RemovePlayerTagRequest : public Wrappers::PFEventsRemovePlayerTagRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsRemovePlayerTagRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEventsRemovePlayerTagRequest& input);

};

class WriteClientCharacterEventRequest : public Wrappers::PFEventsWriteClientCharacterEventRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsWriteClientCharacterEventRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEventsWriteClientCharacterEventRequest& input);

};

class WriteEventResponse : public Wrappers::PFEventsWriteEventResponseWrapper<Allocator>, public OutputModel<PFEventsWriteEventResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsWriteEventResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFEventsWriteEventResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFEventsWriteEventResponse& model);
    static HRESULT Copy(const PFEventsWriteEventResponse& input, PFEventsWriteEventResponse& output, ModelBuffer& buffer);
};

class WriteClientPlayerEventRequest : public Wrappers::PFEventsWriteClientPlayerEventRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsWriteClientPlayerEventRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEventsWriteClientPlayerEventRequest& input);

};

class WriteTitleEventRequest : public Wrappers::PFEventsWriteTitleEventRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsWriteTitleEventRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEventsWriteTitleEventRequest& input);

};

class WriteServerCharacterEventRequest : public Wrappers::PFEventsWriteServerCharacterEventRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsWriteServerCharacterEventRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEventsWriteServerCharacterEventRequest& input);

};

class WriteServerPlayerEventRequest : public Wrappers::PFEventsWriteServerPlayerEventRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsWriteServerPlayerEventRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEventsWriteServerPlayerEventRequest& input);

};

class EventContents : public Wrappers::PFEventsEventContentsWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsEventContentsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEventsEventContents& input);

};

class WriteEventsRequest : public Wrappers::PFEventsWriteEventsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsWriteEventsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEventsWriteEventsRequest& input);

};

class WriteEventsResponse : public Wrappers::PFEventsWriteEventsResponseWrapper<Allocator>, public OutputModel<PFEventsWriteEventsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFEventsWriteEventsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFEventsWriteEventsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFEventsWriteEventsResponse& model);
    static HRESULT Copy(const PFEventsWriteEventsResponse& input, PFEventsWriteEventsResponse& output, ModelBuffer& buffer);
};

} // namespace Events
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
