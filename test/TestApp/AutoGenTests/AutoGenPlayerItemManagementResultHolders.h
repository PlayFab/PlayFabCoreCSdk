#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct ModifyUserVirtualCurrencyResultHolder : public XAsyncResult, public std::enable_shared_from_this<ModifyUserVirtualCurrencyResultHolder>
{
    ModifyUserVirtualCurrencyResultHolder() = default;
    ModifyUserVirtualCurrencyResultHolder(const ModifyUserVirtualCurrencyResultHolder&) = delete;
    ModifyUserVirtualCurrencyResultHolder(ModifyUserVirtualCurrencyResultHolder&&) = default;
    ModifyUserVirtualCurrencyResultHolder& operator=(const ModifyUserVirtualCurrencyResultHolder&) = delete;
    ModifyUserVirtualCurrencyResultHolder& operator=(ModifyUserVirtualCurrencyResultHolder&&) = default;
    ~ModifyUserVirtualCurrencyResultHolder() = default;

    PFPlayerItemManagementModifyUserVirtualCurrencyResult* result{ nullptr };
};

struct CheckLimitedEditionItemAvailabilityResultHolder : public XAsyncResult, public std::enable_shared_from_this<CheckLimitedEditionItemAvailabilityResultHolder>
{
    CheckLimitedEditionItemAvailabilityResultHolder() = default;
    CheckLimitedEditionItemAvailabilityResultHolder(const CheckLimitedEditionItemAvailabilityResultHolder&) = default;
    CheckLimitedEditionItemAvailabilityResultHolder(CheckLimitedEditionItemAvailabilityResultHolder&&) = default;
    CheckLimitedEditionItemAvailabilityResultHolder& operator=(const CheckLimitedEditionItemAvailabilityResultHolder&) = default;
    CheckLimitedEditionItemAvailabilityResultHolder& operator=(CheckLimitedEditionItemAvailabilityResultHolder&&) = default;
    ~CheckLimitedEditionItemAvailabilityResultHolder() = default;

    PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult result{};
};

struct AdminGetUserInventoryResultHolder : public XAsyncResult, public std::enable_shared_from_this<AdminGetUserInventoryResultHolder>
{
    AdminGetUserInventoryResultHolder() = default;
    AdminGetUserInventoryResultHolder(const AdminGetUserInventoryResultHolder&) = delete;
    AdminGetUserInventoryResultHolder(AdminGetUserInventoryResultHolder&&) = default;
    AdminGetUserInventoryResultHolder& operator=(const AdminGetUserInventoryResultHolder&) = delete;
    AdminGetUserInventoryResultHolder& operator=(AdminGetUserInventoryResultHolder&&) = default;
    ~AdminGetUserInventoryResultHolder() = default;

    PFPlayerItemManagementAdminGetUserInventoryResult* result{ nullptr };
};

struct GrantItemsToUsersResultHolder : public XAsyncResult, public std::enable_shared_from_this<GrantItemsToUsersResultHolder>
{
    GrantItemsToUsersResultHolder() = default;
    GrantItemsToUsersResultHolder(const GrantItemsToUsersResultHolder&) = delete;
    GrantItemsToUsersResultHolder(GrantItemsToUsersResultHolder&&) = default;
    GrantItemsToUsersResultHolder& operator=(const GrantItemsToUsersResultHolder&) = delete;
    GrantItemsToUsersResultHolder& operator=(GrantItemsToUsersResultHolder&&) = default;
    ~GrantItemsToUsersResultHolder() = default;

    PFPlayerItemManagementGrantItemsToUsersResult* result{ nullptr };
};

struct RevokeInventoryItemsResultHolder : public XAsyncResult, public std::enable_shared_from_this<RevokeInventoryItemsResultHolder>
{
    RevokeInventoryItemsResultHolder() = default;
    RevokeInventoryItemsResultHolder(const RevokeInventoryItemsResultHolder&) = delete;
    RevokeInventoryItemsResultHolder(RevokeInventoryItemsResultHolder&&) = default;
    RevokeInventoryItemsResultHolder& operator=(const RevokeInventoryItemsResultHolder&) = delete;
    RevokeInventoryItemsResultHolder& operator=(RevokeInventoryItemsResultHolder&&) = default;
    ~RevokeInventoryItemsResultHolder() = default;

    PFPlayerItemManagementRevokeInventoryItemsResult* result{ nullptr };
};

struct ConfirmPurchaseResultHolder : public XAsyncResult, public std::enable_shared_from_this<ConfirmPurchaseResultHolder>
{
    ConfirmPurchaseResultHolder() = default;
    ConfirmPurchaseResultHolder(const ConfirmPurchaseResultHolder&) = delete;
    ConfirmPurchaseResultHolder(ConfirmPurchaseResultHolder&&) = default;
    ConfirmPurchaseResultHolder& operator=(const ConfirmPurchaseResultHolder&) = delete;
    ConfirmPurchaseResultHolder& operator=(ConfirmPurchaseResultHolder&&) = default;
    ~ConfirmPurchaseResultHolder() = default;

    PFPlayerItemManagementConfirmPurchaseResult* result{ nullptr };
};

struct ConsumeItemResultHolder : public XAsyncResult, public std::enable_shared_from_this<ConsumeItemResultHolder>
{
    ConsumeItemResultHolder() = default;
    ConsumeItemResultHolder(const ConsumeItemResultHolder&) = delete;
    ConsumeItemResultHolder(ConsumeItemResultHolder&&) = default;
    ConsumeItemResultHolder& operator=(const ConsumeItemResultHolder&) = delete;
    ConsumeItemResultHolder& operator=(ConsumeItemResultHolder&&) = default;
    ~ConsumeItemResultHolder() = default;

    PFPlayerItemManagementConsumeItemResult* result{ nullptr };
};

struct ClientGetCharacterInventoryResultHolder : public XAsyncResult, public std::enable_shared_from_this<ClientGetCharacterInventoryResultHolder>
{
    ClientGetCharacterInventoryResultHolder() = default;
    ClientGetCharacterInventoryResultHolder(const ClientGetCharacterInventoryResultHolder&) = delete;
    ClientGetCharacterInventoryResultHolder(ClientGetCharacterInventoryResultHolder&&) = default;
    ClientGetCharacterInventoryResultHolder& operator=(const ClientGetCharacterInventoryResultHolder&) = delete;
    ClientGetCharacterInventoryResultHolder& operator=(ClientGetCharacterInventoryResultHolder&&) = default;
    ~ClientGetCharacterInventoryResultHolder() = default;

    PFPlayerItemManagementClientGetCharacterInventoryResult* result{ nullptr };
};

struct GetPaymentTokenResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPaymentTokenResultHolder>
{
    GetPaymentTokenResultHolder() = default;
    GetPaymentTokenResultHolder(const GetPaymentTokenResultHolder&) = delete;
    GetPaymentTokenResultHolder(GetPaymentTokenResultHolder&&) = default;
    GetPaymentTokenResultHolder& operator=(const GetPaymentTokenResultHolder&) = delete;
    GetPaymentTokenResultHolder& operator=(GetPaymentTokenResultHolder&&) = default;
    ~GetPaymentTokenResultHolder() = default;

    PFPlayerItemManagementGetPaymentTokenResult* result{ nullptr };
};

struct GetPurchaseResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPurchaseResultHolder>
{
    GetPurchaseResultHolder() = default;
    GetPurchaseResultHolder(const GetPurchaseResultHolder&) = delete;
    GetPurchaseResultHolder(GetPurchaseResultHolder&&) = default;
    GetPurchaseResultHolder& operator=(const GetPurchaseResultHolder&) = delete;
    GetPurchaseResultHolder& operator=(GetPurchaseResultHolder&&) = default;
    ~GetPurchaseResultHolder() = default;

    PFPlayerItemManagementGetPurchaseResult* result{ nullptr };
};

struct ClientGetUserInventoryResultHolder : public XAsyncResult, public std::enable_shared_from_this<ClientGetUserInventoryResultHolder>
{
    ClientGetUserInventoryResultHolder() = default;
    ClientGetUserInventoryResultHolder(const ClientGetUserInventoryResultHolder&) = delete;
    ClientGetUserInventoryResultHolder(ClientGetUserInventoryResultHolder&&) = default;
    ClientGetUserInventoryResultHolder& operator=(const ClientGetUserInventoryResultHolder&) = delete;
    ClientGetUserInventoryResultHolder& operator=(ClientGetUserInventoryResultHolder&&) = default;
    ~ClientGetUserInventoryResultHolder() = default;

    PFPlayerItemManagementClientGetUserInventoryResult* result{ nullptr };
};

struct PayForPurchaseResultHolder : public XAsyncResult, public std::enable_shared_from_this<PayForPurchaseResultHolder>
{
    PayForPurchaseResultHolder() = default;
    PayForPurchaseResultHolder(const PayForPurchaseResultHolder&) = delete;
    PayForPurchaseResultHolder(PayForPurchaseResultHolder&&) = default;
    PayForPurchaseResultHolder& operator=(const PayForPurchaseResultHolder&) = delete;
    PayForPurchaseResultHolder& operator=(PayForPurchaseResultHolder&&) = default;
    ~PayForPurchaseResultHolder() = default;

    PFPlayerItemManagementPayForPurchaseResult* result{ nullptr };
};

struct PurchaseItemResultHolder : public XAsyncResult, public std::enable_shared_from_this<PurchaseItemResultHolder>
{
    PurchaseItemResultHolder() = default;
    PurchaseItemResultHolder(const PurchaseItemResultHolder&) = delete;
    PurchaseItemResultHolder(PurchaseItemResultHolder&&) = default;
    PurchaseItemResultHolder& operator=(const PurchaseItemResultHolder&) = delete;
    PurchaseItemResultHolder& operator=(PurchaseItemResultHolder&&) = default;
    ~PurchaseItemResultHolder() = default;

    PFPlayerItemManagementPurchaseItemResult* result{ nullptr };
};

struct RedeemCouponResultHolder : public XAsyncResult, public std::enable_shared_from_this<RedeemCouponResultHolder>
{
    RedeemCouponResultHolder() = default;
    RedeemCouponResultHolder(const RedeemCouponResultHolder&) = delete;
    RedeemCouponResultHolder(RedeemCouponResultHolder&&) = default;
    RedeemCouponResultHolder& operator=(const RedeemCouponResultHolder&) = delete;
    RedeemCouponResultHolder& operator=(RedeemCouponResultHolder&&) = default;
    ~RedeemCouponResultHolder() = default;

    PFPlayerItemManagementRedeemCouponResult* result{ nullptr };
};

struct StartPurchaseResultHolder : public XAsyncResult, public std::enable_shared_from_this<StartPurchaseResultHolder>
{
    StartPurchaseResultHolder() = default;
    StartPurchaseResultHolder(const StartPurchaseResultHolder&) = delete;
    StartPurchaseResultHolder(StartPurchaseResultHolder&&) = default;
    StartPurchaseResultHolder& operator=(const StartPurchaseResultHolder&) = delete;
    StartPurchaseResultHolder& operator=(StartPurchaseResultHolder&&) = default;
    ~StartPurchaseResultHolder() = default;

    PFPlayerItemManagementStartPurchaseResult* result{ nullptr };
};

struct UnlockContainerItemResultHolder : public XAsyncResult, public std::enable_shared_from_this<UnlockContainerItemResultHolder>
{
    UnlockContainerItemResultHolder() = default;
    UnlockContainerItemResultHolder(const UnlockContainerItemResultHolder&) = delete;
    UnlockContainerItemResultHolder(UnlockContainerItemResultHolder&&) = default;
    UnlockContainerItemResultHolder& operator=(const UnlockContainerItemResultHolder&) = delete;
    UnlockContainerItemResultHolder& operator=(UnlockContainerItemResultHolder&&) = default;
    ~UnlockContainerItemResultHolder() = default;

    PFPlayerItemManagementUnlockContainerItemResult* result{ nullptr };
};

struct ModifyCharacterVirtualCurrencyResultHolder : public XAsyncResult, public std::enable_shared_from_this<ModifyCharacterVirtualCurrencyResultHolder>
{
    ModifyCharacterVirtualCurrencyResultHolder() = default;
    ModifyCharacterVirtualCurrencyResultHolder(const ModifyCharacterVirtualCurrencyResultHolder&) = delete;
    ModifyCharacterVirtualCurrencyResultHolder(ModifyCharacterVirtualCurrencyResultHolder&&) = default;
    ModifyCharacterVirtualCurrencyResultHolder& operator=(const ModifyCharacterVirtualCurrencyResultHolder&) = delete;
    ModifyCharacterVirtualCurrencyResultHolder& operator=(ModifyCharacterVirtualCurrencyResultHolder&&) = default;
    ~ModifyCharacterVirtualCurrencyResultHolder() = default;

    PFPlayerItemManagementModifyCharacterVirtualCurrencyResult* result{ nullptr };
};

struct EvaluateRandomResultTableResultHolder : public XAsyncResult, public std::enable_shared_from_this<EvaluateRandomResultTableResultHolder>
{
    EvaluateRandomResultTableResultHolder() = default;
    EvaluateRandomResultTableResultHolder(const EvaluateRandomResultTableResultHolder&) = delete;
    EvaluateRandomResultTableResultHolder(EvaluateRandomResultTableResultHolder&&) = default;
    EvaluateRandomResultTableResultHolder& operator=(const EvaluateRandomResultTableResultHolder&) = delete;
    EvaluateRandomResultTableResultHolder& operator=(EvaluateRandomResultTableResultHolder&&) = default;
    ~EvaluateRandomResultTableResultHolder() = default;

    PFPlayerItemManagementEvaluateRandomResultTableResult* result{ nullptr };
};

struct ServerGetCharacterInventoryResultHolder : public XAsyncResult, public std::enable_shared_from_this<ServerGetCharacterInventoryResultHolder>
{
    ServerGetCharacterInventoryResultHolder() = default;
    ServerGetCharacterInventoryResultHolder(const ServerGetCharacterInventoryResultHolder&) = delete;
    ServerGetCharacterInventoryResultHolder(ServerGetCharacterInventoryResultHolder&&) = default;
    ServerGetCharacterInventoryResultHolder& operator=(const ServerGetCharacterInventoryResultHolder&) = delete;
    ServerGetCharacterInventoryResultHolder& operator=(ServerGetCharacterInventoryResultHolder&&) = default;
    ~ServerGetCharacterInventoryResultHolder() = default;

    PFPlayerItemManagementServerGetCharacterInventoryResult* result{ nullptr };
};

struct ServerGetUserInventoryResultHolder : public XAsyncResult, public std::enable_shared_from_this<ServerGetUserInventoryResultHolder>
{
    ServerGetUserInventoryResultHolder() = default;
    ServerGetUserInventoryResultHolder(const ServerGetUserInventoryResultHolder&) = delete;
    ServerGetUserInventoryResultHolder(ServerGetUserInventoryResultHolder&&) = default;
    ServerGetUserInventoryResultHolder& operator=(const ServerGetUserInventoryResultHolder&) = delete;
    ServerGetUserInventoryResultHolder& operator=(ServerGetUserInventoryResultHolder&&) = default;
    ~ServerGetUserInventoryResultHolder() = default;

    PFPlayerItemManagementServerGetUserInventoryResult* result{ nullptr };
};

struct GrantItemsToCharacterResultHolder : public XAsyncResult, public std::enable_shared_from_this<GrantItemsToCharacterResultHolder>
{
    GrantItemsToCharacterResultHolder() = default;
    GrantItemsToCharacterResultHolder(const GrantItemsToCharacterResultHolder&) = delete;
    GrantItemsToCharacterResultHolder(GrantItemsToCharacterResultHolder&&) = default;
    GrantItemsToCharacterResultHolder& operator=(const GrantItemsToCharacterResultHolder&) = delete;
    GrantItemsToCharacterResultHolder& operator=(GrantItemsToCharacterResultHolder&&) = default;
    ~GrantItemsToCharacterResultHolder() = default;

    PFPlayerItemManagementGrantItemsToCharacterResult* result{ nullptr };
};

struct GrantItemsToUserResultHolder : public XAsyncResult, public std::enable_shared_from_this<GrantItemsToUserResultHolder>
{
    GrantItemsToUserResultHolder() = default;
    GrantItemsToUserResultHolder(const GrantItemsToUserResultHolder&) = delete;
    GrantItemsToUserResultHolder(GrantItemsToUserResultHolder&&) = default;
    GrantItemsToUserResultHolder& operator=(const GrantItemsToUserResultHolder&) = delete;
    GrantItemsToUserResultHolder& operator=(GrantItemsToUserResultHolder&&) = default;
    ~GrantItemsToUserResultHolder() = default;

    PFPlayerItemManagementGrantItemsToUserResult* result{ nullptr };
};

struct ModifyItemUsesResultHolder : public XAsyncResult, public std::enable_shared_from_this<ModifyItemUsesResultHolder>
{
    ModifyItemUsesResultHolder() = default;
    ModifyItemUsesResultHolder(const ModifyItemUsesResultHolder&) = delete;
    ModifyItemUsesResultHolder(ModifyItemUsesResultHolder&&) = default;
    ModifyItemUsesResultHolder& operator=(const ModifyItemUsesResultHolder&) = delete;
    ModifyItemUsesResultHolder& operator=(ModifyItemUsesResultHolder&&) = default;
    ~ModifyItemUsesResultHolder() = default;

    PFPlayerItemManagementModifyItemUsesResult* result{ nullptr };
};

struct ReportPlayerServerResultHolder : public XAsyncResult, public std::enable_shared_from_this<ReportPlayerServerResultHolder>
{
    ReportPlayerServerResultHolder() = default;
    ReportPlayerServerResultHolder(const ReportPlayerServerResultHolder&) = default;
    ReportPlayerServerResultHolder(ReportPlayerServerResultHolder&&) = default;
    ReportPlayerServerResultHolder& operator=(const ReportPlayerServerResultHolder&) = default;
    ReportPlayerServerResultHolder& operator=(ReportPlayerServerResultHolder&&) = default;
    ~ReportPlayerServerResultHolder() = default;

    PFPlayerItemManagementReportPlayerServerResult result{};
};


}
