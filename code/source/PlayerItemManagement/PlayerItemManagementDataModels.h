#pragma once

#include <playfab/cpp/PFPlayerItemManagementDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace PlayerItemManagement
{

// PlayerItemManagement Classes
class AdminAddUserVirtualCurrencyRequest : public Wrappers::PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest& input);

};

class ModifyUserVirtualCurrencyResult : public Wrappers::PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementModifyUserVirtualCurrencyResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementModifyUserVirtualCurrencyResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementModifyUserVirtualCurrencyResult& model);
    static HRESULT Copy(const PFPlayerItemManagementModifyUserVirtualCurrencyResult& input, PFPlayerItemManagementModifyUserVirtualCurrencyResult& output, ModelBuffer& buffer);
};

class CheckLimitedEditionItemAvailabilityRequest : public Wrappers::PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest& input);

};

class CheckLimitedEditionItemAvailabilityResult : public Wrappers::PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult& model);
    static HRESULT Copy(const PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult& input, PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult& output, ModelBuffer& buffer);
};

class AdminGetUserInventoryRequest : public Wrappers::PFPlayerItemManagementAdminGetUserInventoryRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementAdminGetUserInventoryRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementAdminGetUserInventoryRequest& input);

};

class AdminGetUserInventoryResult : public Wrappers::PFPlayerItemManagementAdminGetUserInventoryResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementAdminGetUserInventoryResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementAdminGetUserInventoryResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementAdminGetUserInventoryResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementAdminGetUserInventoryResult& model);
    static HRESULT Copy(const PFPlayerItemManagementAdminGetUserInventoryResult& input, PFPlayerItemManagementAdminGetUserInventoryResult& output, ModelBuffer& buffer);
};

class ItemGrant : public Wrappers::PFPlayerItemManagementItemGrantWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementItemGrantWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementItemGrant& input);

};

class GrantItemsToUsersRequest : public Wrappers::PFPlayerItemManagementGrantItemsToUsersRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGrantItemsToUsersRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementGrantItemsToUsersRequest& input);

};

class GrantedItemInstance : public Wrappers::PFPlayerItemManagementGrantedItemInstanceWrapper<Allocator>, public OutputModel<PFPlayerItemManagementGrantedItemInstance>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGrantedItemInstanceWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementGrantedItemInstance const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementGrantedItemInstance& model);
    static HRESULT Copy(const PFPlayerItemManagementGrantedItemInstance& input, PFPlayerItemManagementGrantedItemInstance& output, ModelBuffer& buffer);
};

class GrantItemsToUsersResult : public Wrappers::PFPlayerItemManagementGrantItemsToUsersResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementGrantItemsToUsersResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGrantItemsToUsersResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementGrantItemsToUsersResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementGrantItemsToUsersResult& model);
    static HRESULT Copy(const PFPlayerItemManagementGrantItemsToUsersResult& input, PFPlayerItemManagementGrantItemsToUsersResult& output, ModelBuffer& buffer);
};

class IncrementLimitedEditionItemAvailabilityRequest : public Wrappers::PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest& input);

};

class RevokeInventoryItemRequest : public Wrappers::PFPlayerItemManagementRevokeInventoryItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementRevokeInventoryItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementRevokeInventoryItemRequest& input);

};

class RevokeInventoryItem : public Wrappers::PFPlayerItemManagementRevokeInventoryItemWrapper<Allocator>, public InputModel, public OutputModel<PFPlayerItemManagementRevokeInventoryItem>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementRevokeInventoryItemWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementRevokeInventoryItem& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementRevokeInventoryItem const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementRevokeInventoryItem& model);
    static HRESULT Copy(const PFPlayerItemManagementRevokeInventoryItem& input, PFPlayerItemManagementRevokeInventoryItem& output, ModelBuffer& buffer);
};

class RevokeInventoryItemsRequest : public Wrappers::PFPlayerItemManagementRevokeInventoryItemsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementRevokeInventoryItemsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementRevokeInventoryItemsRequest& input);

};

class RevokeItemError : public Wrappers::PFPlayerItemManagementRevokeItemErrorWrapper<Allocator>, public OutputModel<PFPlayerItemManagementRevokeItemError>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementRevokeItemErrorWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementRevokeItemError const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementRevokeItemError& model);
    static HRESULT Copy(const PFPlayerItemManagementRevokeItemError& input, PFPlayerItemManagementRevokeItemError& output, ModelBuffer& buffer);
};

class RevokeInventoryItemsResult : public Wrappers::PFPlayerItemManagementRevokeInventoryItemsResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementRevokeInventoryItemsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementRevokeInventoryItemsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementRevokeInventoryItemsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementRevokeInventoryItemsResult& model);
    static HRESULT Copy(const PFPlayerItemManagementRevokeInventoryItemsResult& input, PFPlayerItemManagementRevokeInventoryItemsResult& output, ModelBuffer& buffer);
};

class AdminSubtractUserVirtualCurrencyRequest : public Wrappers::PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest& input);

};

class ClientAddUserVirtualCurrencyRequest : public Wrappers::PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementClientAddUserVirtualCurrencyRequest& input);

};

class ConfirmPurchaseRequest : public Wrappers::PFPlayerItemManagementConfirmPurchaseRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementConfirmPurchaseRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementConfirmPurchaseRequest& input);

};

class ConfirmPurchaseResult : public Wrappers::PFPlayerItemManagementConfirmPurchaseResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementConfirmPurchaseResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementConfirmPurchaseResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementConfirmPurchaseResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementConfirmPurchaseResult& model);
    static HRESULT Copy(const PFPlayerItemManagementConfirmPurchaseResult& input, PFPlayerItemManagementConfirmPurchaseResult& output, ModelBuffer& buffer);
};

class ClientConsumeItemRequest : public Wrappers::PFPlayerItemManagementClientConsumeItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementClientConsumeItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementClientConsumeItemRequest& input);

};

class ConsumeItemResult : public Wrappers::PFPlayerItemManagementConsumeItemResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementConsumeItemResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementConsumeItemResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementConsumeItemResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementConsumeItemResult& model);
    static HRESULT Copy(const PFPlayerItemManagementConsumeItemResult& input, PFPlayerItemManagementConsumeItemResult& output, ModelBuffer& buffer);
};

class ClientGetCharacterInventoryRequest : public Wrappers::PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementClientGetCharacterInventoryRequest& input);

};

class ClientGetCharacterInventoryResult : public Wrappers::PFPlayerItemManagementClientGetCharacterInventoryResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementClientGetCharacterInventoryResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementClientGetCharacterInventoryResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementClientGetCharacterInventoryResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementClientGetCharacterInventoryResult& model);
    static HRESULT Copy(const PFPlayerItemManagementClientGetCharacterInventoryResult& input, PFPlayerItemManagementClientGetCharacterInventoryResult& output, ModelBuffer& buffer);
};

class GetPaymentTokenRequest : public Wrappers::PFPlayerItemManagementGetPaymentTokenRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGetPaymentTokenRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementGetPaymentTokenRequest& input);

};

class GetPaymentTokenResult : public Wrappers::PFPlayerItemManagementGetPaymentTokenResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementGetPaymentTokenResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGetPaymentTokenResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementGetPaymentTokenResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementGetPaymentTokenResult& model);
    static HRESULT Copy(const PFPlayerItemManagementGetPaymentTokenResult& input, PFPlayerItemManagementGetPaymentTokenResult& output, ModelBuffer& buffer);
};

class GetPurchaseRequest : public Wrappers::PFPlayerItemManagementGetPurchaseRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGetPurchaseRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementGetPurchaseRequest& input);

};

class GetPurchaseResult : public Wrappers::PFPlayerItemManagementGetPurchaseResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementGetPurchaseResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGetPurchaseResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementGetPurchaseResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementGetPurchaseResult& model);
    static HRESULT Copy(const PFPlayerItemManagementGetPurchaseResult& input, PFPlayerItemManagementGetPurchaseResult& output, ModelBuffer& buffer);
};

class ClientGetUserInventoryRequest : public Wrappers::PFPlayerItemManagementClientGetUserInventoryRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementClientGetUserInventoryRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementClientGetUserInventoryRequest& input);

};

class ClientGetUserInventoryResult : public Wrappers::PFPlayerItemManagementClientGetUserInventoryResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementClientGetUserInventoryResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementClientGetUserInventoryResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementClientGetUserInventoryResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementClientGetUserInventoryResult& model);
    static HRESULT Copy(const PFPlayerItemManagementClientGetUserInventoryResult& input, PFPlayerItemManagementClientGetUserInventoryResult& output, ModelBuffer& buffer);
};

class PayForPurchaseRequest : public Wrappers::PFPlayerItemManagementPayForPurchaseRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementPayForPurchaseRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementPayForPurchaseRequest& input);

};

class PayForPurchaseResult : public Wrappers::PFPlayerItemManagementPayForPurchaseResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementPayForPurchaseResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementPayForPurchaseResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementPayForPurchaseResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementPayForPurchaseResult& model);
    static HRESULT Copy(const PFPlayerItemManagementPayForPurchaseResult& input, PFPlayerItemManagementPayForPurchaseResult& output, ModelBuffer& buffer);
};

class PurchaseItemRequest : public Wrappers::PFPlayerItemManagementPurchaseItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementPurchaseItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementPurchaseItemRequest& input);

};

class PurchaseItemResult : public Wrappers::PFPlayerItemManagementPurchaseItemResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementPurchaseItemResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementPurchaseItemResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementPurchaseItemResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementPurchaseItemResult& model);
    static HRESULT Copy(const PFPlayerItemManagementPurchaseItemResult& input, PFPlayerItemManagementPurchaseItemResult& output, ModelBuffer& buffer);
};

class ClientRedeemCouponRequest : public Wrappers::PFPlayerItemManagementClientRedeemCouponRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementClientRedeemCouponRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementClientRedeemCouponRequest& input);

};

class RedeemCouponResult : public Wrappers::PFPlayerItemManagementRedeemCouponResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementRedeemCouponResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementRedeemCouponResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementRedeemCouponResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementRedeemCouponResult& model);
    static HRESULT Copy(const PFPlayerItemManagementRedeemCouponResult& input, PFPlayerItemManagementRedeemCouponResult& output, ModelBuffer& buffer);
};

class ItemPurchaseRequest : public Wrappers::PFPlayerItemManagementItemPurchaseRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementItemPurchaseRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementItemPurchaseRequest& input);

};

class StartPurchaseRequest : public Wrappers::PFPlayerItemManagementStartPurchaseRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementStartPurchaseRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementStartPurchaseRequest& input);

};

class CartItem : public Wrappers::PFPlayerItemManagementCartItemWrapper<Allocator>, public OutputModel<PFPlayerItemManagementCartItem>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementCartItemWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementCartItem const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementCartItem& model);
    static HRESULT Copy(const PFPlayerItemManagementCartItem& input, PFPlayerItemManagementCartItem& output, ModelBuffer& buffer);
};

class PaymentOption : public Wrappers::PFPlayerItemManagementPaymentOptionWrapper<Allocator>, public OutputModel<PFPlayerItemManagementPaymentOption>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementPaymentOptionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementPaymentOption const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementPaymentOption& model);
    static HRESULT Copy(const PFPlayerItemManagementPaymentOption& input, PFPlayerItemManagementPaymentOption& output, ModelBuffer& buffer);
};

class StartPurchaseResult : public Wrappers::PFPlayerItemManagementStartPurchaseResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementStartPurchaseResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementStartPurchaseResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementStartPurchaseResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementStartPurchaseResult& model);
    static HRESULT Copy(const PFPlayerItemManagementStartPurchaseResult& input, PFPlayerItemManagementStartPurchaseResult& output, ModelBuffer& buffer);
};

class ClientSubtractUserVirtualCurrencyRequest : public Wrappers::PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest& input);

};

class ClientUnlockContainerInstanceRequest : public Wrappers::PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementClientUnlockContainerInstanceRequest& input);

};

class UnlockContainerItemResult : public Wrappers::PFPlayerItemManagementUnlockContainerItemResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementUnlockContainerItemResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementUnlockContainerItemResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementUnlockContainerItemResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementUnlockContainerItemResult& model);
    static HRESULT Copy(const PFPlayerItemManagementUnlockContainerItemResult& input, PFPlayerItemManagementUnlockContainerItemResult& output, ModelBuffer& buffer);
};

class ClientUnlockContainerItemRequest : public Wrappers::PFPlayerItemManagementClientUnlockContainerItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementClientUnlockContainerItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementClientUnlockContainerItemRequest& input);

};

class AddCharacterVirtualCurrencyRequest : public Wrappers::PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementAddCharacterVirtualCurrencyRequest& input);

};

class ModifyCharacterVirtualCurrencyResult : public Wrappers::PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementModifyCharacterVirtualCurrencyResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementModifyCharacterVirtualCurrencyResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementModifyCharacterVirtualCurrencyResult& model);
    static HRESULT Copy(const PFPlayerItemManagementModifyCharacterVirtualCurrencyResult& input, PFPlayerItemManagementModifyCharacterVirtualCurrencyResult& output, ModelBuffer& buffer);
};

class ServerAddUserVirtualCurrencyRequest : public Wrappers::PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementServerAddUserVirtualCurrencyRequest& input);

};

class ServerConsumeItemRequest : public Wrappers::PFPlayerItemManagementServerConsumeItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementServerConsumeItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementServerConsumeItemRequest& input);

};

class EvaluateRandomResultTableRequest : public Wrappers::PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementEvaluateRandomResultTableRequest& input);

};

class EvaluateRandomResultTableResult : public Wrappers::PFPlayerItemManagementEvaluateRandomResultTableResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementEvaluateRandomResultTableResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementEvaluateRandomResultTableResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementEvaluateRandomResultTableResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementEvaluateRandomResultTableResult& model);
    static HRESULT Copy(const PFPlayerItemManagementEvaluateRandomResultTableResult& input, PFPlayerItemManagementEvaluateRandomResultTableResult& output, ModelBuffer& buffer);
};

class ServerGetCharacterInventoryRequest : public Wrappers::PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementServerGetCharacterInventoryRequest& input);

};

class ServerGetCharacterInventoryResult : public Wrappers::PFPlayerItemManagementServerGetCharacterInventoryResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementServerGetCharacterInventoryResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementServerGetCharacterInventoryResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementServerGetCharacterInventoryResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementServerGetCharacterInventoryResult& model);
    static HRESULT Copy(const PFPlayerItemManagementServerGetCharacterInventoryResult& input, PFPlayerItemManagementServerGetCharacterInventoryResult& output, ModelBuffer& buffer);
};

class GetRandomResultTablesRequest : public Wrappers::PFPlayerItemManagementGetRandomResultTablesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGetRandomResultTablesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementGetRandomResultTablesRequest& input);

};

class ServerGetUserInventoryRequest : public Wrappers::PFPlayerItemManagementServerGetUserInventoryRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementServerGetUserInventoryRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementServerGetUserInventoryRequest& input);

};

class ServerGetUserInventoryResult : public Wrappers::PFPlayerItemManagementServerGetUserInventoryResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementServerGetUserInventoryResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementServerGetUserInventoryResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementServerGetUserInventoryResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementServerGetUserInventoryResult& model);
    static HRESULT Copy(const PFPlayerItemManagementServerGetUserInventoryResult& input, PFPlayerItemManagementServerGetUserInventoryResult& output, ModelBuffer& buffer);
};

class GrantItemsToCharacterRequest : public Wrappers::PFPlayerItemManagementGrantItemsToCharacterRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGrantItemsToCharacterRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementGrantItemsToCharacterRequest& input);

};

class GrantItemsToCharacterResult : public Wrappers::PFPlayerItemManagementGrantItemsToCharacterResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementGrantItemsToCharacterResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGrantItemsToCharacterResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementGrantItemsToCharacterResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementGrantItemsToCharacterResult& model);
    static HRESULT Copy(const PFPlayerItemManagementGrantItemsToCharacterResult& input, PFPlayerItemManagementGrantItemsToCharacterResult& output, ModelBuffer& buffer);
};

class GrantItemsToUserRequest : public Wrappers::PFPlayerItemManagementGrantItemsToUserRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGrantItemsToUserRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementGrantItemsToUserRequest& input);

};

class GrantItemsToUserResult : public Wrappers::PFPlayerItemManagementGrantItemsToUserResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementGrantItemsToUserResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementGrantItemsToUserResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementGrantItemsToUserResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementGrantItemsToUserResult& model);
    static HRESULT Copy(const PFPlayerItemManagementGrantItemsToUserResult& input, PFPlayerItemManagementGrantItemsToUserResult& output, ModelBuffer& buffer);
};

class ModifyItemUsesRequest : public Wrappers::PFPlayerItemManagementModifyItemUsesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementModifyItemUsesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementModifyItemUsesRequest& input);

};

class ModifyItemUsesResult : public Wrappers::PFPlayerItemManagementModifyItemUsesResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementModifyItemUsesResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementModifyItemUsesResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementModifyItemUsesResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementModifyItemUsesResult& model);
    static HRESULT Copy(const PFPlayerItemManagementModifyItemUsesResult& input, PFPlayerItemManagementModifyItemUsesResult& output, ModelBuffer& buffer);
};

class MoveItemToCharacterFromCharacterRequest : public Wrappers::PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest& input);

};

class MoveItemToCharacterFromUserRequest : public Wrappers::PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementMoveItemToCharacterFromUserRequest& input);

};

class MoveItemToUserFromCharacterRequest : public Wrappers::PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementMoveItemToUserFromCharacterRequest& input);

};

class ServerRedeemCouponRequest : public Wrappers::PFPlayerItemManagementServerRedeemCouponRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementServerRedeemCouponRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementServerRedeemCouponRequest& input);

};

class ReportPlayerServerRequest : public Wrappers::PFPlayerItemManagementReportPlayerServerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementReportPlayerServerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementReportPlayerServerRequest& input);

};

class ReportPlayerServerResult : public Wrappers::PFPlayerItemManagementReportPlayerServerResultWrapper<Allocator>, public OutputModel<PFPlayerItemManagementReportPlayerServerResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementReportPlayerServerResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerItemManagementReportPlayerServerResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerItemManagementReportPlayerServerResult& model);
    static HRESULT Copy(const PFPlayerItemManagementReportPlayerServerResult& input, PFPlayerItemManagementReportPlayerServerResult& output, ModelBuffer& buffer);
};

class SubtractCharacterVirtualCurrencyRequest : public Wrappers::PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest& input);

};

class ServerSubtractUserVirtualCurrencyRequest : public Wrappers::PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest& input);

};

class ServerUnlockContainerInstanceRequest : public Wrappers::PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementServerUnlockContainerInstanceRequest& input);

};

class ServerUnlockContainerItemRequest : public Wrappers::PFPlayerItemManagementServerUnlockContainerItemRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementServerUnlockContainerItemRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementServerUnlockContainerItemRequest& input);

};

class UpdateUserInventoryItemDataRequest : public Wrappers::PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerItemManagementUpdateUserInventoryItemDataRequest& input);

};

} // namespace PlayerItemManagement
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
