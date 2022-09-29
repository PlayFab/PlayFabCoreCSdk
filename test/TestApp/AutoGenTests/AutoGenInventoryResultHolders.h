#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct AddInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<AddInventoryItemsResponseHolder>
{
    AddInventoryItemsResponseHolder() = default;
    AddInventoryItemsResponseHolder(const AddInventoryItemsResponseHolder&) = delete;
    AddInventoryItemsResponseHolder(AddInventoryItemsResponseHolder&&) = default;
    AddInventoryItemsResponseHolder& operator=(const AddInventoryItemsResponseHolder&) = delete;
    AddInventoryItemsResponseHolder& operator=(AddInventoryItemsResponseHolder&&) = default;
    ~AddInventoryItemsResponseHolder() = default;

    PFInventoryAddInventoryItemsResponse* result{ nullptr };
};

struct DeleteInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<DeleteInventoryItemsResponseHolder>
{
    DeleteInventoryItemsResponseHolder() = default;
    DeleteInventoryItemsResponseHolder(const DeleteInventoryItemsResponseHolder&) = delete;
    DeleteInventoryItemsResponseHolder(DeleteInventoryItemsResponseHolder&&) = default;
    DeleteInventoryItemsResponseHolder& operator=(const DeleteInventoryItemsResponseHolder&) = delete;
    DeleteInventoryItemsResponseHolder& operator=(DeleteInventoryItemsResponseHolder&&) = default;
    ~DeleteInventoryItemsResponseHolder() = default;

    PFInventoryDeleteInventoryItemsResponse* result{ nullptr };
};

struct ExecuteInventoryOperationsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ExecuteInventoryOperationsResponseHolder>
{
    ExecuteInventoryOperationsResponseHolder() = default;
    ExecuteInventoryOperationsResponseHolder(const ExecuteInventoryOperationsResponseHolder&) = delete;
    ExecuteInventoryOperationsResponseHolder(ExecuteInventoryOperationsResponseHolder&&) = default;
    ExecuteInventoryOperationsResponseHolder& operator=(const ExecuteInventoryOperationsResponseHolder&) = delete;
    ExecuteInventoryOperationsResponseHolder& operator=(ExecuteInventoryOperationsResponseHolder&&) = default;
    ~ExecuteInventoryOperationsResponseHolder() = default;

    PFInventoryExecuteInventoryOperationsResponse* result{ nullptr };
};

struct GetInventoryCollectionIdsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetInventoryCollectionIdsResponseHolder>
{
    GetInventoryCollectionIdsResponseHolder() = default;
    GetInventoryCollectionIdsResponseHolder(const GetInventoryCollectionIdsResponseHolder&) = delete;
    GetInventoryCollectionIdsResponseHolder(GetInventoryCollectionIdsResponseHolder&&) = default;
    GetInventoryCollectionIdsResponseHolder& operator=(const GetInventoryCollectionIdsResponseHolder&) = delete;
    GetInventoryCollectionIdsResponseHolder& operator=(GetInventoryCollectionIdsResponseHolder&&) = default;
    ~GetInventoryCollectionIdsResponseHolder() = default;

    PFInventoryGetInventoryCollectionIdsResponse* result{ nullptr };
};

struct GetInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetInventoryItemsResponseHolder>
{
    GetInventoryItemsResponseHolder() = default;
    GetInventoryItemsResponseHolder(const GetInventoryItemsResponseHolder&) = delete;
    GetInventoryItemsResponseHolder(GetInventoryItemsResponseHolder&&) = default;
    GetInventoryItemsResponseHolder& operator=(const GetInventoryItemsResponseHolder&) = delete;
    GetInventoryItemsResponseHolder& operator=(GetInventoryItemsResponseHolder&&) = default;
    ~GetInventoryItemsResponseHolder() = default;

    PFInventoryGetInventoryItemsResponse* result{ nullptr };
};

struct GetMicrosoftStoreAccessTokensResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetMicrosoftStoreAccessTokensResponseHolder>
{
    GetMicrosoftStoreAccessTokensResponseHolder() = default;
    GetMicrosoftStoreAccessTokensResponseHolder(const GetMicrosoftStoreAccessTokensResponseHolder&) = delete;
    GetMicrosoftStoreAccessTokensResponseHolder(GetMicrosoftStoreAccessTokensResponseHolder&&) = default;
    GetMicrosoftStoreAccessTokensResponseHolder& operator=(const GetMicrosoftStoreAccessTokensResponseHolder&) = delete;
    GetMicrosoftStoreAccessTokensResponseHolder& operator=(GetMicrosoftStoreAccessTokensResponseHolder&&) = default;
    ~GetMicrosoftStoreAccessTokensResponseHolder() = default;

    PFInventoryGetMicrosoftStoreAccessTokensResponse* result{ nullptr };
};

struct PurchaseInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<PurchaseInventoryItemsResponseHolder>
{
    PurchaseInventoryItemsResponseHolder() = default;
    PurchaseInventoryItemsResponseHolder(const PurchaseInventoryItemsResponseHolder&) = delete;
    PurchaseInventoryItemsResponseHolder(PurchaseInventoryItemsResponseHolder&&) = default;
    PurchaseInventoryItemsResponseHolder& operator=(const PurchaseInventoryItemsResponseHolder&) = delete;
    PurchaseInventoryItemsResponseHolder& operator=(PurchaseInventoryItemsResponseHolder&&) = default;
    ~PurchaseInventoryItemsResponseHolder() = default;

    PFInventoryPurchaseInventoryItemsResponse* result{ nullptr };
};

struct RedeemAppleAppStoreInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<RedeemAppleAppStoreInventoryItemsResponseHolder>
{
    RedeemAppleAppStoreInventoryItemsResponseHolder() = default;
    RedeemAppleAppStoreInventoryItemsResponseHolder(const RedeemAppleAppStoreInventoryItemsResponseHolder&) = delete;
    RedeemAppleAppStoreInventoryItemsResponseHolder(RedeemAppleAppStoreInventoryItemsResponseHolder&&) = default;
    RedeemAppleAppStoreInventoryItemsResponseHolder& operator=(const RedeemAppleAppStoreInventoryItemsResponseHolder&) = delete;
    RedeemAppleAppStoreInventoryItemsResponseHolder& operator=(RedeemAppleAppStoreInventoryItemsResponseHolder&&) = default;
    ~RedeemAppleAppStoreInventoryItemsResponseHolder() = default;

    PFInventoryRedeemAppleAppStoreInventoryItemsResponse* result{ nullptr };
};

struct RedeemGooglePlayInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<RedeemGooglePlayInventoryItemsResponseHolder>
{
    RedeemGooglePlayInventoryItemsResponseHolder() = default;
    RedeemGooglePlayInventoryItemsResponseHolder(const RedeemGooglePlayInventoryItemsResponseHolder&) = delete;
    RedeemGooglePlayInventoryItemsResponseHolder(RedeemGooglePlayInventoryItemsResponseHolder&&) = default;
    RedeemGooglePlayInventoryItemsResponseHolder& operator=(const RedeemGooglePlayInventoryItemsResponseHolder&) = delete;
    RedeemGooglePlayInventoryItemsResponseHolder& operator=(RedeemGooglePlayInventoryItemsResponseHolder&&) = default;
    ~RedeemGooglePlayInventoryItemsResponseHolder() = default;

    PFInventoryRedeemGooglePlayInventoryItemsResponse* result{ nullptr };
};

struct RedeemMicrosoftStoreInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<RedeemMicrosoftStoreInventoryItemsResponseHolder>
{
    RedeemMicrosoftStoreInventoryItemsResponseHolder() = default;
    RedeemMicrosoftStoreInventoryItemsResponseHolder(const RedeemMicrosoftStoreInventoryItemsResponseHolder&) = delete;
    RedeemMicrosoftStoreInventoryItemsResponseHolder(RedeemMicrosoftStoreInventoryItemsResponseHolder&&) = default;
    RedeemMicrosoftStoreInventoryItemsResponseHolder& operator=(const RedeemMicrosoftStoreInventoryItemsResponseHolder&) = delete;
    RedeemMicrosoftStoreInventoryItemsResponseHolder& operator=(RedeemMicrosoftStoreInventoryItemsResponseHolder&&) = default;
    ~RedeemMicrosoftStoreInventoryItemsResponseHolder() = default;

    PFInventoryRedeemMicrosoftStoreInventoryItemsResponse* result{ nullptr };
};

struct RedeemNintendoEShopInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<RedeemNintendoEShopInventoryItemsResponseHolder>
{
    RedeemNintendoEShopInventoryItemsResponseHolder() = default;
    RedeemNintendoEShopInventoryItemsResponseHolder(const RedeemNintendoEShopInventoryItemsResponseHolder&) = delete;
    RedeemNintendoEShopInventoryItemsResponseHolder(RedeemNintendoEShopInventoryItemsResponseHolder&&) = default;
    RedeemNintendoEShopInventoryItemsResponseHolder& operator=(const RedeemNintendoEShopInventoryItemsResponseHolder&) = delete;
    RedeemNintendoEShopInventoryItemsResponseHolder& operator=(RedeemNintendoEShopInventoryItemsResponseHolder&&) = default;
    ~RedeemNintendoEShopInventoryItemsResponseHolder() = default;

    PFInventoryRedeemNintendoEShopInventoryItemsResponse* result{ nullptr };
};

struct RedeemPlayStationStoreInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<RedeemPlayStationStoreInventoryItemsResponseHolder>
{
    RedeemPlayStationStoreInventoryItemsResponseHolder() = default;
    RedeemPlayStationStoreInventoryItemsResponseHolder(const RedeemPlayStationStoreInventoryItemsResponseHolder&) = delete;
    RedeemPlayStationStoreInventoryItemsResponseHolder(RedeemPlayStationStoreInventoryItemsResponseHolder&&) = default;
    RedeemPlayStationStoreInventoryItemsResponseHolder& operator=(const RedeemPlayStationStoreInventoryItemsResponseHolder&) = delete;
    RedeemPlayStationStoreInventoryItemsResponseHolder& operator=(RedeemPlayStationStoreInventoryItemsResponseHolder&&) = default;
    ~RedeemPlayStationStoreInventoryItemsResponseHolder() = default;

    PFInventoryRedeemPlayStationStoreInventoryItemsResponse* result{ nullptr };
};

struct RedeemSteamInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<RedeemSteamInventoryItemsResponseHolder>
{
    RedeemSteamInventoryItemsResponseHolder() = default;
    RedeemSteamInventoryItemsResponseHolder(const RedeemSteamInventoryItemsResponseHolder&) = delete;
    RedeemSteamInventoryItemsResponseHolder(RedeemSteamInventoryItemsResponseHolder&&) = default;
    RedeemSteamInventoryItemsResponseHolder& operator=(const RedeemSteamInventoryItemsResponseHolder&) = delete;
    RedeemSteamInventoryItemsResponseHolder& operator=(RedeemSteamInventoryItemsResponseHolder&&) = default;
    ~RedeemSteamInventoryItemsResponseHolder() = default;

    PFInventoryRedeemSteamInventoryItemsResponse* result{ nullptr };
};

struct SubtractInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<SubtractInventoryItemsResponseHolder>
{
    SubtractInventoryItemsResponseHolder() = default;
    SubtractInventoryItemsResponseHolder(const SubtractInventoryItemsResponseHolder&) = delete;
    SubtractInventoryItemsResponseHolder(SubtractInventoryItemsResponseHolder&&) = default;
    SubtractInventoryItemsResponseHolder& operator=(const SubtractInventoryItemsResponseHolder&) = delete;
    SubtractInventoryItemsResponseHolder& operator=(SubtractInventoryItemsResponseHolder&&) = default;
    ~SubtractInventoryItemsResponseHolder() = default;

    PFInventorySubtractInventoryItemsResponse* result{ nullptr };
};

struct TransferInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<TransferInventoryItemsResponseHolder>
{
    TransferInventoryItemsResponseHolder() = default;
    TransferInventoryItemsResponseHolder(const TransferInventoryItemsResponseHolder&) = delete;
    TransferInventoryItemsResponseHolder(TransferInventoryItemsResponseHolder&&) = default;
    TransferInventoryItemsResponseHolder& operator=(const TransferInventoryItemsResponseHolder&) = delete;
    TransferInventoryItemsResponseHolder& operator=(TransferInventoryItemsResponseHolder&&) = default;
    ~TransferInventoryItemsResponseHolder() = default;

    PFInventoryTransferInventoryItemsResponse* result{ nullptr };
};

struct UpdateInventoryItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<UpdateInventoryItemsResponseHolder>
{
    UpdateInventoryItemsResponseHolder() = default;
    UpdateInventoryItemsResponseHolder(const UpdateInventoryItemsResponseHolder&) = delete;
    UpdateInventoryItemsResponseHolder(UpdateInventoryItemsResponseHolder&&) = default;
    UpdateInventoryItemsResponseHolder& operator=(const UpdateInventoryItemsResponseHolder&) = delete;
    UpdateInventoryItemsResponseHolder& operator=(UpdateInventoryItemsResponseHolder&&) = default;
    ~UpdateInventoryItemsResponseHolder() = default;

    PFInventoryUpdateInventoryItemsResponse* result{ nullptr };
};


}
