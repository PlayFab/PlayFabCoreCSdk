#pragma once

#include <playfab/cpp/PFPlayStreamDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace PlayStream
{

// PlayStream Classes
class AddPlayerTagRequest : public Wrappers::PFPlayStreamAddPlayerTagRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamAddPlayerTagRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayStreamAddPlayerTagRequest& input);

};

class GetSegmentResult : public Wrappers::PFPlayStreamGetSegmentResultWrapper<Allocator>, public OutputModel<PFPlayStreamGetSegmentResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamGetSegmentResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamGetSegmentResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamGetSegmentResult& model);
    static HRESULT Copy(const PFPlayStreamGetSegmentResult& input, PFPlayStreamGetSegmentResult& output, ModelBuffer& buffer);
};

class GetAllSegmentsResult : public Wrappers::PFPlayStreamGetAllSegmentsResultWrapper<Allocator>, public OutputModel<PFPlayStreamGetAllSegmentsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamGetAllSegmentsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamGetAllSegmentsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamGetAllSegmentsResult& model);
    static HRESULT Copy(const PFPlayStreamGetAllSegmentsResult& input, PFPlayStreamGetAllSegmentsResult& output, ModelBuffer& buffer);
};

class GetPlayersSegmentsRequest : public Wrappers::PFPlayStreamGetPlayersSegmentsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamGetPlayersSegmentsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayStreamGetPlayersSegmentsRequest& input);

};

class GetPlayerSegmentsResult : public Wrappers::PFPlayStreamGetPlayerSegmentsResultWrapper<Allocator>, public OutputModel<PFPlayStreamGetPlayerSegmentsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamGetPlayerSegmentsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamGetPlayerSegmentsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamGetPlayerSegmentsResult& model);
    static HRESULT Copy(const PFPlayStreamGetPlayerSegmentsResult& input, PFPlayStreamGetPlayerSegmentsResult& output, ModelBuffer& buffer);
};

class GetPlayersInSegmentRequest : public Wrappers::PFPlayStreamGetPlayersInSegmentRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamGetPlayersInSegmentRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayStreamGetPlayersInSegmentRequest& input);

};

class AdCampaignAttribution : public Wrappers::PFPlayStreamAdCampaignAttributionWrapper<Allocator>, public OutputModel<PFPlayStreamAdCampaignAttribution>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamAdCampaignAttributionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamAdCampaignAttribution const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamAdCampaignAttribution& model);
    static HRESULT Copy(const PFPlayStreamAdCampaignAttribution& input, PFPlayStreamAdCampaignAttribution& output, ModelBuffer& buffer);
};

class ContactEmailInfo : public Wrappers::PFPlayStreamContactEmailInfoWrapper<Allocator>, public OutputModel<PFPlayStreamContactEmailInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamContactEmailInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamContactEmailInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamContactEmailInfo& model);
    static HRESULT Copy(const PFPlayStreamContactEmailInfo& input, PFPlayStreamContactEmailInfo& output, ModelBuffer& buffer);
};

class PlayerLinkedAccount : public Wrappers::PFPlayStreamPlayerLinkedAccountWrapper<Allocator>, public OutputModel<PFPlayStreamPlayerLinkedAccount>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamPlayerLinkedAccountWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamPlayerLinkedAccount const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamPlayerLinkedAccount& model);
    static HRESULT Copy(const PFPlayStreamPlayerLinkedAccount& input, PFPlayStreamPlayerLinkedAccount& output, ModelBuffer& buffer);
};

class PlayerLocation : public Wrappers::PFPlayStreamPlayerLocationWrapper<Allocator>, public OutputModel<PFPlayStreamPlayerLocation>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamPlayerLocationWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamPlayerLocation const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamPlayerLocation& model);
    static HRESULT Copy(const PFPlayStreamPlayerLocation& input, PFPlayStreamPlayerLocation& output, ModelBuffer& buffer);
};

class PlayerStatistic : public Wrappers::PFPlayStreamPlayerStatisticWrapper<Allocator>, public OutputModel<PFPlayStreamPlayerStatistic>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamPlayerStatisticWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamPlayerStatistic const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamPlayerStatistic& model);
    static HRESULT Copy(const PFPlayStreamPlayerStatistic& input, PFPlayStreamPlayerStatistic& output, ModelBuffer& buffer);
};

class PushNotificationRegistration : public Wrappers::PFPlayStreamPushNotificationRegistrationWrapper<Allocator>, public OutputModel<PFPlayStreamPushNotificationRegistration>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamPushNotificationRegistrationWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamPushNotificationRegistration const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamPushNotificationRegistration& model);
    static HRESULT Copy(const PFPlayStreamPushNotificationRegistration& input, PFPlayStreamPushNotificationRegistration& output, ModelBuffer& buffer);
};

class PlayerProfile : public Wrappers::PFPlayStreamPlayerProfileWrapper<Allocator>, public OutputModel<PFPlayStreamPlayerProfile>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamPlayerProfileWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamPlayerProfile const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamPlayerProfile& model);
    static HRESULT Copy(const PFPlayStreamPlayerProfile& input, PFPlayStreamPlayerProfile& output, ModelBuffer& buffer);
};

class GetPlayersInSegmentResult : public Wrappers::PFPlayStreamGetPlayersInSegmentResultWrapper<Allocator>, public OutputModel<PFPlayStreamGetPlayersInSegmentResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamGetPlayersInSegmentResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamGetPlayersInSegmentResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamGetPlayersInSegmentResult& model);
    static HRESULT Copy(const PFPlayStreamGetPlayersInSegmentResult& input, PFPlayStreamGetPlayersInSegmentResult& output, ModelBuffer& buffer);
};

class GetPlayerTagsRequest : public Wrappers::PFPlayStreamGetPlayerTagsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamGetPlayerTagsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayStreamGetPlayerTagsRequest& input);

};

class GetPlayerTagsResult : public Wrappers::PFPlayStreamGetPlayerTagsResultWrapper<Allocator>, public OutputModel<PFPlayStreamGetPlayerTagsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamGetPlayerTagsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamGetPlayerTagsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamGetPlayerTagsResult& model);
    static HRESULT Copy(const PFPlayStreamGetPlayerTagsResult& input, PFPlayStreamGetPlayerTagsResult& output, ModelBuffer& buffer);
};

class RemovePlayerTagRequest : public Wrappers::PFPlayStreamRemovePlayerTagRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamRemovePlayerTagRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayStreamRemovePlayerTagRequest& input);

};

class EventContents : public Wrappers::PFPlayStreamEventContentsWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamEventContentsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayStreamEventContents& input);

};

class WriteEventsRequest : public Wrappers::PFPlayStreamWriteEventsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamWriteEventsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayStreamWriteEventsRequest& input);

};

class WriteEventsResponse : public Wrappers::PFPlayStreamWriteEventsResponseWrapper<Allocator>, public OutputModel<PFPlayStreamWriteEventsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayStreamWriteEventsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayStreamWriteEventsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayStreamWriteEventsResponse& model);
    static HRESULT Copy(const PFPlayStreamWriteEventsResponse& input, PFPlayStreamWriteEventsResponse& output, ModelBuffer& buffer);
};

} // namespace PlayStream
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
