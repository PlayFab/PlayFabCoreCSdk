#pragma once

#include <playfab/cpp/PFCatalogDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Catalog
{

// Catalog Classes
class CatalogAlternateId : public Wrappers::PFCatalogCatalogAlternateIdWrapper<Allocator>, public InputModel, public OutputModel<PFCatalogCatalogAlternateId>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogCatalogAlternateIdWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogCatalogAlternateId& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogCatalogAlternateId const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogCatalogAlternateId& model);
    static HRESULT Copy(const PFCatalogCatalogAlternateId& input, PFCatalogCatalogAlternateId& output, ModelBuffer& buffer);
};

class Content : public Wrappers::PFCatalogContentWrapper<Allocator>, public InputModel, public OutputModel<PFCatalogContent>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogContentWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogContent& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogContent const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogContent& model);
    static HRESULT Copy(const PFCatalogContent& input, PFCatalogContent& output, ModelBuffer& buffer);
};

class Image : public Wrappers::PFCatalogImageWrapper<Allocator>, public InputModel, public OutputModel<PFCatalogImage>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogImageWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogImage& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogImage const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogImage& model);
    static HRESULT Copy(const PFCatalogImage& input, PFCatalogImage& output, ModelBuffer& buffer);
};

class KeywordSet : public Wrappers::PFCatalogKeywordSetWrapper<Allocator>, public InputModel, public OutputModel<PFCatalogKeywordSet>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogKeywordSetWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogKeywordSet& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogKeywordSet const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogKeywordSet& model);
    static HRESULT Copy(const PFCatalogKeywordSet& input, PFCatalogKeywordSet& output, ModelBuffer& buffer);
};

class ModerationState : public Wrappers::PFCatalogModerationStateWrapper<Allocator>, public InputModel, public OutputModel<PFCatalogModerationState>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogModerationStateWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogModerationState& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogModerationState const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogModerationState& model);
    static HRESULT Copy(const PFCatalogModerationState& input, PFCatalogModerationState& output, ModelBuffer& buffer);
};

class Rating : public Wrappers::PFCatalogRatingWrapper<Allocator>, public InputModel, public OutputModel<PFCatalogRating>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogRatingWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogRating& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogRating const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogRating& model);
    static HRESULT Copy(const PFCatalogRating& input, PFCatalogRating& output, ModelBuffer& buffer);
};

class CatalogItem : public Wrappers::PFCatalogCatalogItemWrapper<Allocator>, public InputModel, public OutputModel<PFCatalogCatalogItem>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogCatalogItemWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogCatalogItem& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogCatalogItem const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogCatalogItem& model);
    static HRESULT Copy(const PFCatalogCatalogItem& input, PFCatalogCatalogItem& output, ModelBuffer& buffer);
};

class CreateDraftItemRequest : public Wrappers::PFCatalogCreateDraftItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogCreateDraftItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogCreateDraftItemRequest& input);

};

class CreateDraftItemResponse : public Wrappers::PFCatalogCreateDraftItemResponseWrapper<Allocator>, public OutputModel<PFCatalogCreateDraftItemResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogCreateDraftItemResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogCreateDraftItemResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogCreateDraftItemResponse& model);
    static HRESULT Copy(const PFCatalogCreateDraftItemResponse& input, PFCatalogCreateDraftItemResponse& output, ModelBuffer& buffer);
};

class UploadInfo : public Wrappers::PFCatalogUploadInfoWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogUploadInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogUploadInfo& input);

};

class CreateUploadUrlsRequest : public Wrappers::PFCatalogCreateUploadUrlsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogCreateUploadUrlsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogCreateUploadUrlsRequest& input);

};

class UploadUrlMetadata : public Wrappers::PFCatalogUploadUrlMetadataWrapper<Allocator>, public OutputModel<PFCatalogUploadUrlMetadata>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogUploadUrlMetadataWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogUploadUrlMetadata const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogUploadUrlMetadata& model);
    static HRESULT Copy(const PFCatalogUploadUrlMetadata& input, PFCatalogUploadUrlMetadata& output, ModelBuffer& buffer);
};

class CreateUploadUrlsResponse : public Wrappers::PFCatalogCreateUploadUrlsResponseWrapper<Allocator>, public OutputModel<PFCatalogCreateUploadUrlsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogCreateUploadUrlsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogCreateUploadUrlsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogCreateUploadUrlsResponse& model);
    static HRESULT Copy(const PFCatalogCreateUploadUrlsResponse& input, PFCatalogCreateUploadUrlsResponse& output, ModelBuffer& buffer);
};

class DeleteEntityItemReviewsRequest : public Wrappers::PFCatalogDeleteEntityItemReviewsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogDeleteEntityItemReviewsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogDeleteEntityItemReviewsRequest& input);

};

class DeleteItemRequest : public Wrappers::PFCatalogDeleteItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogDeleteItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogDeleteItemRequest& input);

};

class GetCatalogConfigRequest : public Wrappers::PFCatalogGetCatalogConfigRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetCatalogConfigRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogGetCatalogConfigRequest& input);

};

class DisplayPropertyIndexInfo : public Wrappers::PFCatalogDisplayPropertyIndexInfoWrapper<Allocator>, public InputModel, public OutputModel<PFCatalogDisplayPropertyIndexInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogDisplayPropertyIndexInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogDisplayPropertyIndexInfo& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogDisplayPropertyIndexInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogDisplayPropertyIndexInfo& model);
    static HRESULT Copy(const PFCatalogDisplayPropertyIndexInfo& input, PFCatalogDisplayPropertyIndexInfo& output, ModelBuffer& buffer);
};

class UserGeneratedContentSpecificConfig : public Wrappers::PFCatalogUserGeneratedContentSpecificConfigWrapper<Allocator>, public InputModel, public OutputModel<PFCatalogUserGeneratedContentSpecificConfig>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogUserGeneratedContentSpecificConfigWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogUserGeneratedContentSpecificConfig& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogUserGeneratedContentSpecificConfig const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogUserGeneratedContentSpecificConfig& model);
    static HRESULT Copy(const PFCatalogUserGeneratedContentSpecificConfig& input, PFCatalogUserGeneratedContentSpecificConfig& output, ModelBuffer& buffer);
};

class CatalogConfig : public Wrappers::PFCatalogCatalogConfigWrapper<Allocator>, public InputModel, public OutputModel<PFCatalogCatalogConfig>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogCatalogConfigWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogCatalogConfig& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogCatalogConfig const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogCatalogConfig& model);
    static HRESULT Copy(const PFCatalogCatalogConfig& input, PFCatalogCatalogConfig& output, ModelBuffer& buffer);
};

class GetCatalogConfigResponse : public Wrappers::PFCatalogGetCatalogConfigResponseWrapper<Allocator>, public OutputModel<PFCatalogGetCatalogConfigResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetCatalogConfigResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogGetCatalogConfigResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogGetCatalogConfigResponse& model);
    static HRESULT Copy(const PFCatalogGetCatalogConfigResponse& input, PFCatalogGetCatalogConfigResponse& output, ModelBuffer& buffer);
};

class GetDraftItemRequest : public Wrappers::PFCatalogGetDraftItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetDraftItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogGetDraftItemRequest& input);

};

class GetDraftItemResponse : public Wrappers::PFCatalogGetDraftItemResponseWrapper<Allocator>, public OutputModel<PFCatalogGetDraftItemResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetDraftItemResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogGetDraftItemResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogGetDraftItemResponse& model);
    static HRESULT Copy(const PFCatalogGetDraftItemResponse& input, PFCatalogGetDraftItemResponse& output, ModelBuffer& buffer);
};

class GetDraftItemsRequest : public Wrappers::PFCatalogGetDraftItemsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetDraftItemsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogGetDraftItemsRequest& input);

};

class GetDraftItemsResponse : public Wrappers::PFCatalogGetDraftItemsResponseWrapper<Allocator>, public OutputModel<PFCatalogGetDraftItemsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetDraftItemsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogGetDraftItemsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogGetDraftItemsResponse& model);
    static HRESULT Copy(const PFCatalogGetDraftItemsResponse& input, PFCatalogGetDraftItemsResponse& output, ModelBuffer& buffer);
};

class GetEntityDraftItemsRequest : public Wrappers::PFCatalogGetEntityDraftItemsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetEntityDraftItemsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogGetEntityDraftItemsRequest& input);

};

class GetEntityDraftItemsResponse : public Wrappers::PFCatalogGetEntityDraftItemsResponseWrapper<Allocator>, public OutputModel<PFCatalogGetEntityDraftItemsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetEntityDraftItemsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogGetEntityDraftItemsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogGetEntityDraftItemsResponse& model);
    static HRESULT Copy(const PFCatalogGetEntityDraftItemsResponse& input, PFCatalogGetEntityDraftItemsResponse& output, ModelBuffer& buffer);
};

class GetEntityItemReviewRequest : public Wrappers::PFCatalogGetEntityItemReviewRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetEntityItemReviewRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogGetEntityItemReviewRequest& input);

};

class Review : public Wrappers::PFCatalogReviewWrapper<Allocator>, public InputModel, public OutputModel<PFCatalogReview>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogReviewWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogReview& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogReview const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogReview& model);
    static HRESULT Copy(const PFCatalogReview& input, PFCatalogReview& output, ModelBuffer& buffer);
};

class GetEntityItemReviewResponse : public Wrappers::PFCatalogGetEntityItemReviewResponseWrapper<Allocator>, public OutputModel<PFCatalogGetEntityItemReviewResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetEntityItemReviewResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogGetEntityItemReviewResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogGetEntityItemReviewResponse& model);
    static HRESULT Copy(const PFCatalogGetEntityItemReviewResponse& input, PFCatalogGetEntityItemReviewResponse& output, ModelBuffer& buffer);
};

class GetItemRequest : public Wrappers::PFCatalogGetItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogGetItemRequest& input);

};

class GetItemResponse : public Wrappers::PFCatalogGetItemResponseWrapper<Allocator>, public OutputModel<PFCatalogGetItemResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetItemResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogGetItemResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogGetItemResponse& model);
    static HRESULT Copy(const PFCatalogGetItemResponse& input, PFCatalogGetItemResponse& output, ModelBuffer& buffer);
};

class GetItemModerationStateRequest : public Wrappers::PFCatalogGetItemModerationStateRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetItemModerationStateRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogGetItemModerationStateRequest& input);

};

class GetItemModerationStateResponse : public Wrappers::PFCatalogGetItemModerationStateResponseWrapper<Allocator>, public OutputModel<PFCatalogGetItemModerationStateResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetItemModerationStateResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogGetItemModerationStateResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogGetItemModerationStateResponse& model);
    static HRESULT Copy(const PFCatalogGetItemModerationStateResponse& input, PFCatalogGetItemModerationStateResponse& output, ModelBuffer& buffer);
};

class GetItemPublishStatusRequest : public Wrappers::PFCatalogGetItemPublishStatusRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetItemPublishStatusRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogGetItemPublishStatusRequest& input);

};

class ScanResult : public Wrappers::PFCatalogScanResultWrapper<Allocator>, public OutputModel<PFCatalogScanResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogScanResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogScanResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogScanResult& model);
    static HRESULT Copy(const PFCatalogScanResult& input, PFCatalogScanResult& output, ModelBuffer& buffer);
};

class GetItemPublishStatusResponse : public Wrappers::PFCatalogGetItemPublishStatusResponseWrapper<Allocator>, public OutputModel<PFCatalogGetItemPublishStatusResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetItemPublishStatusResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogGetItemPublishStatusResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogGetItemPublishStatusResponse& model);
    static HRESULT Copy(const PFCatalogGetItemPublishStatusResponse& input, PFCatalogGetItemPublishStatusResponse& output, ModelBuffer& buffer);
};

class GetItemReviewsRequest : public Wrappers::PFCatalogGetItemReviewsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetItemReviewsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogGetItemReviewsRequest& input);

};

class GetItemReviewsResponse : public Wrappers::PFCatalogGetItemReviewsResponseWrapper<Allocator>, public OutputModel<PFCatalogGetItemReviewsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetItemReviewsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogGetItemReviewsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogGetItemReviewsResponse& model);
    static HRESULT Copy(const PFCatalogGetItemReviewsResponse& input, PFCatalogGetItemReviewsResponse& output, ModelBuffer& buffer);
};

class GetItemReviewSummaryRequest : public Wrappers::PFCatalogGetItemReviewSummaryRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetItemReviewSummaryRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogGetItemReviewSummaryRequest& input);

};

class GetItemReviewSummaryResponse : public Wrappers::PFCatalogGetItemReviewSummaryResponseWrapper<Allocator>, public OutputModel<PFCatalogGetItemReviewSummaryResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogGetItemReviewSummaryResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogGetItemReviewSummaryResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogGetItemReviewSummaryResponse& model);
    static HRESULT Copy(const PFCatalogGetItemReviewSummaryResponse& input, PFCatalogGetItemReviewSummaryResponse& output, ModelBuffer& buffer);
};

class PublishDraftItemRequest : public Wrappers::PFCatalogPublishDraftItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogPublishDraftItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogPublishDraftItemRequest& input);

};

class ReportItemRequest : public Wrappers::PFCatalogReportItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogReportItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogReportItemRequest& input);

};

class ReportItemReviewRequest : public Wrappers::PFCatalogReportItemReviewRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogReportItemReviewRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogReportItemReviewRequest& input);

};

class ReviewItemRequest : public Wrappers::PFCatalogReviewItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogReviewItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogReviewItemRequest& input);

};

class SearchItemsRequest : public Wrappers::PFCatalogSearchItemsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogSearchItemsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogSearchItemsRequest& input);

};

class SearchItemsResponse : public Wrappers::PFCatalogSearchItemsResponseWrapper<Allocator>, public OutputModel<PFCatalogSearchItemsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogSearchItemsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogSearchItemsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogSearchItemsResponse& model);
    static HRESULT Copy(const PFCatalogSearchItemsResponse& input, PFCatalogSearchItemsResponse& output, ModelBuffer& buffer);
};

class SetItemModerationStateRequest : public Wrappers::PFCatalogSetItemModerationStateRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogSetItemModerationStateRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogSetItemModerationStateRequest& input);

};

class SubmitItemReviewVoteRequest : public Wrappers::PFCatalogSubmitItemReviewVoteRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogSubmitItemReviewVoteRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogSubmitItemReviewVoteRequest& input);

};

class ReviewTakedown : public Wrappers::PFCatalogReviewTakedownWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogReviewTakedownWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogReviewTakedown& input);

};

class TakedownItemReviewsRequest : public Wrappers::PFCatalogTakedownItemReviewsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogTakedownItemReviewsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogTakedownItemReviewsRequest& input);

};

class UpdateCatalogConfigRequest : public Wrappers::PFCatalogUpdateCatalogConfigRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogUpdateCatalogConfigRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogUpdateCatalogConfigRequest& input);

};

class UpdateDraftItemRequest : public Wrappers::PFCatalogUpdateDraftItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogUpdateDraftItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCatalogUpdateDraftItemRequest& input);

};

class UpdateDraftItemResponse : public Wrappers::PFCatalogUpdateDraftItemResponseWrapper<Allocator>, public OutputModel<PFCatalogUpdateDraftItemResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFCatalogUpdateDraftItemResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCatalogUpdateDraftItemResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCatalogUpdateDraftItemResponse& model);
    static HRESULT Copy(const PFCatalogUpdateDraftItemResponse& input, PFCatalogUpdateDraftItemResponse& output, ModelBuffer& buffer);
};

} // namespace Catalog
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
