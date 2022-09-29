#pragma once

#include <playfab/cpp/PFEconomyDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Economy
{

// Economy Classes
class RefundPurchaseRequest : public Wrappers::PFEconomyRefundPurchaseRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEconomyRefundPurchaseRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEconomyRefundPurchaseRequest& input);

};

class RefundPurchaseResponse : public Wrappers::PFEconomyRefundPurchaseResponseWrapper<Allocator>, public OutputModel<PFEconomyRefundPurchaseResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFEconomyRefundPurchaseResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFEconomyRefundPurchaseResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFEconomyRefundPurchaseResponse& model);
    static HRESULT Copy(const PFEconomyRefundPurchaseResponse& input, PFEconomyRefundPurchaseResponse& output, ModelBuffer& buffer);
};

class ResolvePurchaseDisputeRequest : public Wrappers::PFEconomyResolvePurchaseDisputeRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFEconomyResolvePurchaseDisputeRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEconomyResolvePurchaseDisputeRequest& input);

};

class ResolvePurchaseDisputeResponse : public Wrappers::PFEconomyResolvePurchaseDisputeResponseWrapper<Allocator>, public OutputModel<PFEconomyResolvePurchaseDisputeResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFEconomyResolvePurchaseDisputeResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFEconomyResolvePurchaseDisputeResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFEconomyResolvePurchaseDisputeResponse& model);
    static HRESULT Copy(const PFEconomyResolvePurchaseDisputeResponse& input, PFEconomyResolvePurchaseDisputeResponse& output, ModelBuffer& buffer);
};

} // namespace Economy
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
