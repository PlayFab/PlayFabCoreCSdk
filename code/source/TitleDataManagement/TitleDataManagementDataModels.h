#pragma once

#include <playfab/cpp/PFTitleDataManagementDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace TitleDataManagement
{

// TitleDataManagement Classes
class AddLocalizedNewsRequest : public Wrappers::PFTitleDataManagementAddLocalizedNewsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementAddLocalizedNewsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementAddLocalizedNewsRequest& input);

};

class AddNewsRequest : public Wrappers::PFTitleDataManagementAddNewsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementAddNewsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementAddNewsRequest& input);

};

class AddNewsResult : public Wrappers::PFTitleDataManagementAddNewsResultWrapper<Allocator>, public OutputModel<PFTitleDataManagementAddNewsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementAddNewsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementAddNewsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementAddNewsResult& model);
    static HRESULT Copy(const PFTitleDataManagementAddNewsResult& input, PFTitleDataManagementAddNewsResult& output, ModelBuffer& buffer);
};

class VirtualCurrencyData : public Wrappers::PFTitleDataManagementVirtualCurrencyDataWrapper<Allocator>, public InputModel, public OutputModel<PFTitleDataManagementVirtualCurrencyData>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementVirtualCurrencyDataWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementVirtualCurrencyData& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementVirtualCurrencyData const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementVirtualCurrencyData& model);
    static HRESULT Copy(const PFTitleDataManagementVirtualCurrencyData& input, PFTitleDataManagementVirtualCurrencyData& output, ModelBuffer& buffer);
};

class AddVirtualCurrencyTypesRequest : public Wrappers::PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementAddVirtualCurrencyTypesRequest& input);

};

class DeleteStoreRequest : public Wrappers::PFTitleDataManagementDeleteStoreRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementDeleteStoreRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementDeleteStoreRequest& input);

};

class DeleteTitleDataOverrideRequest : public Wrappers::PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementDeleteTitleDataOverrideRequest& input);

};

class GetCatalogItemsRequest : public Wrappers::PFTitleDataManagementGetCatalogItemsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetCatalogItemsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementGetCatalogItemsRequest& input);

};

class CatalogItemBundleInfo : public Wrappers::PFTitleDataManagementCatalogItemBundleInfoWrapper<Allocator>, public InputModel, public OutputModel<PFTitleDataManagementCatalogItemBundleInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementCatalogItemBundleInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementCatalogItemBundleInfo& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementCatalogItemBundleInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementCatalogItemBundleInfo& model);
    static HRESULT Copy(const PFTitleDataManagementCatalogItemBundleInfo& input, PFTitleDataManagementCatalogItemBundleInfo& output, ModelBuffer& buffer);
};

class CatalogItemConsumableInfo : public Wrappers::PFTitleDataManagementCatalogItemConsumableInfoWrapper<Allocator>, public InputModel, public OutputModel<PFTitleDataManagementCatalogItemConsumableInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementCatalogItemConsumableInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementCatalogItemConsumableInfo& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementCatalogItemConsumableInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementCatalogItemConsumableInfo& model);
    static HRESULT Copy(const PFTitleDataManagementCatalogItemConsumableInfo& input, PFTitleDataManagementCatalogItemConsumableInfo& output, ModelBuffer& buffer);
};

class CatalogItemContainerInfo : public Wrappers::PFTitleDataManagementCatalogItemContainerInfoWrapper<Allocator>, public InputModel, public OutputModel<PFTitleDataManagementCatalogItemContainerInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementCatalogItemContainerInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementCatalogItemContainerInfo& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementCatalogItemContainerInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementCatalogItemContainerInfo& model);
    static HRESULT Copy(const PFTitleDataManagementCatalogItemContainerInfo& input, PFTitleDataManagementCatalogItemContainerInfo& output, ModelBuffer& buffer);
};

class CatalogItem : public Wrappers::PFTitleDataManagementCatalogItemWrapper<Allocator>, public InputModel, public OutputModel<PFTitleDataManagementCatalogItem>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementCatalogItemWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementCatalogItem& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementCatalogItem const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementCatalogItem& model);
    static HRESULT Copy(const PFTitleDataManagementCatalogItem& input, PFTitleDataManagementCatalogItem& output, ModelBuffer& buffer);
};

class GetCatalogItemsResult : public Wrappers::PFTitleDataManagementGetCatalogItemsResultWrapper<Allocator>, public OutputModel<PFTitleDataManagementGetCatalogItemsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetCatalogItemsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementGetCatalogItemsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementGetCatalogItemsResult& model);
    static HRESULT Copy(const PFTitleDataManagementGetCatalogItemsResult& input, PFTitleDataManagementGetCatalogItemsResult& output, ModelBuffer& buffer);
};

class GetPublisherDataRequest : public Wrappers::PFTitleDataManagementGetPublisherDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetPublisherDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementGetPublisherDataRequest& input);

};

class GetPublisherDataResult : public Wrappers::PFTitleDataManagementGetPublisherDataResultWrapper<Allocator>, public OutputModel<PFTitleDataManagementGetPublisherDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetPublisherDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementGetPublisherDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementGetPublisherDataResult& model);
    static HRESULT Copy(const PFTitleDataManagementGetPublisherDataResult& input, PFTitleDataManagementGetPublisherDataResult& output, ModelBuffer& buffer);
};

class GetRandomResultTablesRequest : public Wrappers::PFTitleDataManagementGetRandomResultTablesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetRandomResultTablesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementGetRandomResultTablesRequest& input);

};

class GetStoreItemsRequest : public Wrappers::PFTitleDataManagementGetStoreItemsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetStoreItemsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementGetStoreItemsRequest& input);

};

class StoreMarketingModel : public Wrappers::PFTitleDataManagementStoreMarketingModelWrapper<Allocator>, public InputModel, public OutputModel<PFTitleDataManagementStoreMarketingModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementStoreMarketingModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementStoreMarketingModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementStoreMarketingModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementStoreMarketingModel& model);
    static HRESULT Copy(const PFTitleDataManagementStoreMarketingModel& input, PFTitleDataManagementStoreMarketingModel& output, ModelBuffer& buffer);
};

class StoreItem : public Wrappers::PFTitleDataManagementStoreItemWrapper<Allocator>, public InputModel, public OutputModel<PFTitleDataManagementStoreItem>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementStoreItemWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementStoreItem& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementStoreItem const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementStoreItem& model);
    static HRESULT Copy(const PFTitleDataManagementStoreItem& input, PFTitleDataManagementStoreItem& output, ModelBuffer& buffer);
};

class GetStoreItemsResult : public Wrappers::PFTitleDataManagementGetStoreItemsResultWrapper<Allocator>, public OutputModel<PFTitleDataManagementGetStoreItemsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetStoreItemsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementGetStoreItemsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementGetStoreItemsResult& model);
    static HRESULT Copy(const PFTitleDataManagementGetStoreItemsResult& input, PFTitleDataManagementGetStoreItemsResult& output, ModelBuffer& buffer);
};

class GetTitleDataRequest : public Wrappers::PFTitleDataManagementGetTitleDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetTitleDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementGetTitleDataRequest& input);

};

class GetTitleDataResult : public Wrappers::PFTitleDataManagementGetTitleDataResultWrapper<Allocator>, public OutputModel<PFTitleDataManagementGetTitleDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetTitleDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementGetTitleDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementGetTitleDataResult& model);
    static HRESULT Copy(const PFTitleDataManagementGetTitleDataResult& input, PFTitleDataManagementGetTitleDataResult& output, ModelBuffer& buffer);
};

class ListVirtualCurrencyTypesResult : public Wrappers::PFTitleDataManagementListVirtualCurrencyTypesResultWrapper<Allocator>, public OutputModel<PFTitleDataManagementListVirtualCurrencyTypesResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementListVirtualCurrencyTypesResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementListVirtualCurrencyTypesResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementListVirtualCurrencyTypesResult& model);
    static HRESULT Copy(const PFTitleDataManagementListVirtualCurrencyTypesResult& input, PFTitleDataManagementListVirtualCurrencyTypesResult& output, ModelBuffer& buffer);
};

class RemoveVirtualCurrencyTypesRequest : public Wrappers::PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementRemoveVirtualCurrencyTypesRequest& input);

};

class UpdateCatalogItemsRequest : public Wrappers::PFTitleDataManagementUpdateCatalogItemsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementUpdateCatalogItemsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementUpdateCatalogItemsRequest& input);

};

class SetPublisherDataRequest : public Wrappers::PFTitleDataManagementSetPublisherDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementSetPublisherDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementSetPublisherDataRequest& input);

};

class UpdateStoreItemsRequest : public Wrappers::PFTitleDataManagementUpdateStoreItemsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementUpdateStoreItemsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementUpdateStoreItemsRequest& input);

};

class SetTitleDataRequest : public Wrappers::PFTitleDataManagementSetTitleDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementSetTitleDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementSetTitleDataRequest& input);

};

class SetTitleDataResult : public Wrappers::PFTitleDataManagementSetTitleDataResultWrapper<Allocator>, public OutputModel<PFTitleDataManagementSetTitleDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementSetTitleDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementSetTitleDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementSetTitleDataResult& model);
    static HRESULT Copy(const PFTitleDataManagementSetTitleDataResult& input, PFTitleDataManagementSetTitleDataResult& output, ModelBuffer& buffer);
};

class TitleDataKeyValue : public Wrappers::PFTitleDataManagementTitleDataKeyValueWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementTitleDataKeyValueWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementTitleDataKeyValue& input);

};

class SetTitleDataAndOverridesRequest : public Wrappers::PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementSetTitleDataAndOverridesRequest& input);

};

class SetupPushNotificationRequest : public Wrappers::PFTitleDataManagementSetupPushNotificationRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementSetupPushNotificationRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementSetupPushNotificationRequest& input);

};

class SetupPushNotificationResult : public Wrappers::PFTitleDataManagementSetupPushNotificationResultWrapper<Allocator>, public OutputModel<PFTitleDataManagementSetupPushNotificationResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementSetupPushNotificationResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementSetupPushNotificationResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementSetupPushNotificationResult& model);
    static HRESULT Copy(const PFTitleDataManagementSetupPushNotificationResult& input, PFTitleDataManagementSetupPushNotificationResult& output, ModelBuffer& buffer);
};

class RandomResultTable : public Wrappers::PFTitleDataManagementRandomResultTableWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementRandomResultTableWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementRandomResultTable& input);

};

class UpdateRandomResultTablesRequest : public Wrappers::PFTitleDataManagementUpdateRandomResultTablesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementUpdateRandomResultTablesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementUpdateRandomResultTablesRequest& input);

};

class GetTimeResult : public Wrappers::PFTitleDataManagementGetTimeResultWrapper<Allocator>, public OutputModel<PFTitleDataManagementGetTimeResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetTimeResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementGetTimeResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementGetTimeResult& model);
    static HRESULT Copy(const PFTitleDataManagementGetTimeResult& input, PFTitleDataManagementGetTimeResult& output, ModelBuffer& buffer);
};

class GetTitleNewsRequest : public Wrappers::PFTitleDataManagementGetTitleNewsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetTitleNewsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementGetTitleNewsRequest& input);

};

class TitleNewsItem : public Wrappers::PFTitleDataManagementTitleNewsItemWrapper<Allocator>, public OutputModel<PFTitleDataManagementTitleNewsItem>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementTitleNewsItemWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementTitleNewsItem const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementTitleNewsItem& model);
    static HRESULT Copy(const PFTitleDataManagementTitleNewsItem& input, PFTitleDataManagementTitleNewsItem& output, ModelBuffer& buffer);
};

class GetTitleNewsResult : public Wrappers::PFTitleDataManagementGetTitleNewsResultWrapper<Allocator>, public OutputModel<PFTitleDataManagementGetTitleNewsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetTitleNewsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTitleDataManagementGetTitleNewsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTitleDataManagementGetTitleNewsResult& model);
    static HRESULT Copy(const PFTitleDataManagementGetTitleNewsResult& input, PFTitleDataManagementGetTitleNewsResult& output, ModelBuffer& buffer);
};

class GetStoreItemsServerRequest : public Wrappers::PFTitleDataManagementGetStoreItemsServerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTitleDataManagementGetStoreItemsServerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTitleDataManagementGetStoreItemsServerRequest& input);

};

} // namespace TitleDataManagement
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
