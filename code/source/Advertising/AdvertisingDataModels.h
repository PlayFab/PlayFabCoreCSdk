#pragma once

#include <playfab/cpp/PFAdvertisingDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Advertising
{

// Advertising Classes
class AttributeInstallRequest : public Wrappers::PFAdvertisingAttributeInstallRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAdvertisingAttributeInstallRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAdvertisingAttributeInstallRequest& input);

};

class GetAdPlacementsRequest : public Wrappers::PFAdvertisingGetAdPlacementsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAdvertisingGetAdPlacementsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAdvertisingGetAdPlacementsRequest& input);

};

class AdPlacementDetails : public Wrappers::PFAdvertisingAdPlacementDetailsWrapper<Allocator>, public OutputModel<PFAdvertisingAdPlacementDetails>
{
public:
    using ModelWrapperType = typename Wrappers::PFAdvertisingAdPlacementDetailsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAdvertisingAdPlacementDetails const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAdvertisingAdPlacementDetails& model);
    static HRESULT Copy(const PFAdvertisingAdPlacementDetails& input, PFAdvertisingAdPlacementDetails& output, ModelBuffer& buffer);
};

class GetAdPlacementsResult : public Wrappers::PFAdvertisingGetAdPlacementsResultWrapper<Allocator>, public OutputModel<PFAdvertisingGetAdPlacementsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFAdvertisingGetAdPlacementsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAdvertisingGetAdPlacementsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAdvertisingGetAdPlacementsResult& model);
    static HRESULT Copy(const PFAdvertisingGetAdPlacementsResult& input, PFAdvertisingGetAdPlacementsResult& output, ModelBuffer& buffer);
};

class ReportAdActivityRequest : public Wrappers::PFAdvertisingReportAdActivityRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAdvertisingReportAdActivityRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAdvertisingReportAdActivityRequest& input);

};

class RewardAdActivityRequest : public Wrappers::PFAdvertisingRewardAdActivityRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAdvertisingRewardAdActivityRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAdvertisingRewardAdActivityRequest& input);

};

class AdRewardItemGranted : public Wrappers::PFAdvertisingAdRewardItemGrantedWrapper<Allocator>, public OutputModel<PFAdvertisingAdRewardItemGranted>
{
public:
    using ModelWrapperType = typename Wrappers::PFAdvertisingAdRewardItemGrantedWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAdvertisingAdRewardItemGranted const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAdvertisingAdRewardItemGranted& model);
    static HRESULT Copy(const PFAdvertisingAdRewardItemGranted& input, PFAdvertisingAdRewardItemGranted& output, ModelBuffer& buffer);
};

class AdRewardResults : public Wrappers::PFAdvertisingAdRewardResultsWrapper<Allocator>, public OutputModel<PFAdvertisingAdRewardResults>
{
public:
    using ModelWrapperType = typename Wrappers::PFAdvertisingAdRewardResultsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAdvertisingAdRewardResults const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAdvertisingAdRewardResults& model);
    static HRESULT Copy(const PFAdvertisingAdRewardResults& input, PFAdvertisingAdRewardResults& output, ModelBuffer& buffer);
};

class RewardAdActivityResult : public Wrappers::PFAdvertisingRewardAdActivityResultWrapper<Allocator>, public OutputModel<PFAdvertisingRewardAdActivityResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFAdvertisingRewardAdActivityResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAdvertisingRewardAdActivityResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAdvertisingRewardAdActivityResult& model);
    static HRESULT Copy(const PFAdvertisingRewardAdActivityResult& input, PFAdvertisingRewardAdActivityResult& output, ModelBuffer& buffer);
};

} // namespace Advertising
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
