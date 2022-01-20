#include "stdafx.h"
#include "EconomyDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Economy
{

JsonValue RefundPurchaseRequest::ToJson() const
{
    return RefundPurchaseRequest::ToJson(this->Model());
}

JsonValue RefundPurchaseRequest::ToJson(const PFEconomyRefundPurchaseRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "OrderId", input.orderId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "Reason", input.reason);
    return output;
}

void RefundPurchaseResponse::FromJson(const JsonValue& input)
{
    String purchaseStatus{};
    JsonUtils::ObjectGetMember(input, "PurchaseStatus", purchaseStatus);
    this->SetPurchaseStatus(std::move(purchaseStatus));
}

size_t RefundPurchaseResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFEconomyRefundPurchaseResponse const*> RefundPurchaseResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RefundPurchaseResponse>(&this->Model());
}

size_t RefundPurchaseResponse::RequiredBufferSize(const PFEconomyRefundPurchaseResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.purchaseStatus)
    {
        requiredSize += (std::strlen(model.purchaseStatus) + 1);
    }
    return requiredSize;
}

HRESULT RefundPurchaseResponse::Copy(const PFEconomyRefundPurchaseResponse& input, PFEconomyRefundPurchaseResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.purchaseStatus); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.purchaseStatus = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ResolvePurchaseDisputeRequest::ToJson() const
{
    return ResolvePurchaseDisputeRequest::ToJson(this->Model());
}

JsonValue ResolvePurchaseDisputeRequest::ToJson(const PFEconomyResolvePurchaseDisputeRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "OrderId", input.orderId);
    JsonUtils::ObjectAddMember(output, "Outcome", input.outcome);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "Reason", input.reason);
    return output;
}

void ResolvePurchaseDisputeResponse::FromJson(const JsonValue& input)
{
    String purchaseStatus{};
    JsonUtils::ObjectGetMember(input, "PurchaseStatus", purchaseStatus);
    this->SetPurchaseStatus(std::move(purchaseStatus));
}

size_t ResolvePurchaseDisputeResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFEconomyResolvePurchaseDisputeResponse const*> ResolvePurchaseDisputeResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ResolvePurchaseDisputeResponse>(&this->Model());
}

size_t ResolvePurchaseDisputeResponse::RequiredBufferSize(const PFEconomyResolvePurchaseDisputeResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.purchaseStatus)
    {
        requiredSize += (std::strlen(model.purchaseStatus) + 1);
    }
    return requiredSize;
}

HRESULT ResolvePurchaseDisputeResponse::Copy(const PFEconomyResolvePurchaseDisputeResponse& input, PFEconomyResolvePurchaseDisputeResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.purchaseStatus); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.purchaseStatus = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace Economy
} // namespace PlayFab
