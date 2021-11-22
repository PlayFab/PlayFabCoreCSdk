#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct AddNewsResultHolder : public XAsyncResult, public std::enable_shared_from_this<AddNewsResultHolder>
{
    AddNewsResultHolder() = default;
    AddNewsResultHolder(const AddNewsResultHolder&) = delete;
    AddNewsResultHolder(AddNewsResultHolder&&) = default;
    AddNewsResultHolder& operator=(const AddNewsResultHolder&) = delete;
    AddNewsResultHolder& operator=(AddNewsResultHolder&&) = default;
    ~AddNewsResultHolder() = default;

    PFTitleDataManagementAddNewsResult* result{ nullptr };
};

struct GetCatalogItemsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetCatalogItemsResultHolder>
{
    GetCatalogItemsResultHolder() = default;
    GetCatalogItemsResultHolder(const GetCatalogItemsResultHolder&) = delete;
    GetCatalogItemsResultHolder(GetCatalogItemsResultHolder&&) = default;
    GetCatalogItemsResultHolder& operator=(const GetCatalogItemsResultHolder&) = delete;
    GetCatalogItemsResultHolder& operator=(GetCatalogItemsResultHolder&&) = default;
    ~GetCatalogItemsResultHolder() = default;

    PFTitleDataManagementGetCatalogItemsResult* result{ nullptr };
};

struct GetPublisherDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPublisherDataResultHolder>
{
    GetPublisherDataResultHolder() = default;
    GetPublisherDataResultHolder(const GetPublisherDataResultHolder&) = delete;
    GetPublisherDataResultHolder(GetPublisherDataResultHolder&&) = default;
    GetPublisherDataResultHolder& operator=(const GetPublisherDataResultHolder&) = delete;
    GetPublisherDataResultHolder& operator=(GetPublisherDataResultHolder&&) = default;
    ~GetPublisherDataResultHolder() = default;

    PFTitleDataManagementGetPublisherDataResult* result{ nullptr };
};

struct GetStoreItemsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetStoreItemsResultHolder>
{
    GetStoreItemsResultHolder() = default;
    GetStoreItemsResultHolder(const GetStoreItemsResultHolder&) = delete;
    GetStoreItemsResultHolder(GetStoreItemsResultHolder&&) = default;
    GetStoreItemsResultHolder& operator=(const GetStoreItemsResultHolder&) = delete;
    GetStoreItemsResultHolder& operator=(GetStoreItemsResultHolder&&) = default;
    ~GetStoreItemsResultHolder() = default;

    PFTitleDataManagementGetStoreItemsResult* result{ nullptr };
};

struct GetTitleDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetTitleDataResultHolder>
{
    GetTitleDataResultHolder() = default;
    GetTitleDataResultHolder(const GetTitleDataResultHolder&) = delete;
    GetTitleDataResultHolder(GetTitleDataResultHolder&&) = default;
    GetTitleDataResultHolder& operator=(const GetTitleDataResultHolder&) = delete;
    GetTitleDataResultHolder& operator=(GetTitleDataResultHolder&&) = default;
    ~GetTitleDataResultHolder() = default;

    PFTitleDataManagementGetTitleDataResult* result{ nullptr };
};

struct ListVirtualCurrencyTypesResultHolder : public XAsyncResult, public std::enable_shared_from_this<ListVirtualCurrencyTypesResultHolder>
{
    ListVirtualCurrencyTypesResultHolder() = default;
    ListVirtualCurrencyTypesResultHolder(const ListVirtualCurrencyTypesResultHolder&) = delete;
    ListVirtualCurrencyTypesResultHolder(ListVirtualCurrencyTypesResultHolder&&) = default;
    ListVirtualCurrencyTypesResultHolder& operator=(const ListVirtualCurrencyTypesResultHolder&) = delete;
    ListVirtualCurrencyTypesResultHolder& operator=(ListVirtualCurrencyTypesResultHolder&&) = default;
    ~ListVirtualCurrencyTypesResultHolder() = default;

    PFTitleDataManagementListVirtualCurrencyTypesResult* result{ nullptr };
};

struct SetTitleDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<SetTitleDataResultHolder>
{
    SetTitleDataResultHolder() = default;
    SetTitleDataResultHolder(const SetTitleDataResultHolder&) = delete;
    SetTitleDataResultHolder(SetTitleDataResultHolder&&) = default;
    SetTitleDataResultHolder& operator=(const SetTitleDataResultHolder&) = delete;
    SetTitleDataResultHolder& operator=(SetTitleDataResultHolder&&) = default;
    ~SetTitleDataResultHolder() = default;

    PFTitleDataManagementSetTitleDataResult* result{ nullptr };
};

struct SetupPushNotificationResultHolder : public XAsyncResult, public std::enable_shared_from_this<SetupPushNotificationResultHolder>
{
    SetupPushNotificationResultHolder() = default;
    SetupPushNotificationResultHolder(const SetupPushNotificationResultHolder&) = delete;
    SetupPushNotificationResultHolder(SetupPushNotificationResultHolder&&) = default;
    SetupPushNotificationResultHolder& operator=(const SetupPushNotificationResultHolder&) = delete;
    SetupPushNotificationResultHolder& operator=(SetupPushNotificationResultHolder&&) = default;
    ~SetupPushNotificationResultHolder() = default;

    PFTitleDataManagementSetupPushNotificationResult* result{ nullptr };
};

struct GetTimeResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetTimeResultHolder>
{
    GetTimeResultHolder() = default;
    GetTimeResultHolder(const GetTimeResultHolder&) = default;
    GetTimeResultHolder(GetTimeResultHolder&&) = default;
    GetTimeResultHolder& operator=(const GetTimeResultHolder&) = default;
    GetTimeResultHolder& operator=(GetTimeResultHolder&&) = default;
    ~GetTimeResultHolder() = default;

    PFTitleDataManagementGetTimeResult result{};
};

struct GetTitleNewsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetTitleNewsResultHolder>
{
    GetTitleNewsResultHolder() = default;
    GetTitleNewsResultHolder(const GetTitleNewsResultHolder&) = delete;
    GetTitleNewsResultHolder(GetTitleNewsResultHolder&&) = default;
    GetTitleNewsResultHolder& operator=(const GetTitleNewsResultHolder&) = delete;
    GetTitleNewsResultHolder& operator=(GetTitleNewsResultHolder&&) = default;
    ~GetTitleNewsResultHolder() = default;

    PFTitleDataManagementGetTitleNewsResult* result{ nullptr };
};


}
