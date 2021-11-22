#pragma once

#include "TitleDataManagementDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace TitleDataManagement
{

class TitleDataManagementAPI
{
public:
    TitleDataManagementAPI() = delete;
    TitleDataManagementAPI(const TitleDataManagementAPI& source) = delete;
    TitleDataManagementAPI& operator=(const TitleDataManagementAPI& source) = delete;
    ~TitleDataManagementAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> AdminAddLocalizedNews(SharedPtr<GlobalState const> state, const AddLocalizedNewsRequest& request, const TaskQueue& queue);
    static AsyncOp<AddNewsResult> AdminAddNews(SharedPtr<GlobalState const> state, const AddNewsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminAddVirtualCurrencyTypes(SharedPtr<GlobalState const> state, const AddVirtualCurrencyTypesRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminDeleteStore(SharedPtr<GlobalState const> state, const DeleteStoreRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminDeleteTitleDataOverride(SharedPtr<GlobalState const> state, const DeleteTitleDataOverrideRequest& request, const TaskQueue& queue);
    static AsyncOp<GetCatalogItemsResult> AdminGetCatalogItems(SharedPtr<GlobalState const> state, const GetCatalogItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPublisherDataResult> AdminGetPublisherData(SharedPtr<GlobalState const> state, const GetPublisherDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetRandomResultTablesResult> AdminGetRandomResultTables(SharedPtr<GlobalState const> state, const GetRandomResultTablesRequest& request, const TaskQueue& queue);
    static AsyncOp<GetStoreItemsResult> AdminGetStoreItems(SharedPtr<GlobalState const> state, const GetStoreItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTitleDataResult> AdminGetTitleData(SharedPtr<GlobalState const> state, const GetTitleDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTitleDataResult> AdminGetTitleInternalData(SharedPtr<GlobalState const> state, const GetTitleDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ListVirtualCurrencyTypesResult> AdminListVirtualCurrencyTypes(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<void> AdminRemoveVirtualCurrencyTypes(SharedPtr<GlobalState const> state, const RemoveVirtualCurrencyTypesRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminSetCatalogItems(SharedPtr<GlobalState const> state, const UpdateCatalogItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminSetPublisherData(SharedPtr<GlobalState const> state, const SetPublisherDataRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminSetStoreItems(SharedPtr<GlobalState const> state, const UpdateStoreItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<SetTitleDataResult> AdminSetTitleData(SharedPtr<GlobalState const> state, const SetTitleDataRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminSetTitleDataAndOverrides(SharedPtr<GlobalState const> state, const SetTitleDataAndOverridesRequest& request, const TaskQueue& queue);
    static AsyncOp<SetTitleDataResult> AdminSetTitleInternalData(SharedPtr<GlobalState const> state, const SetTitleDataRequest& request, const TaskQueue& queue);
    static AsyncOp<SetupPushNotificationResult> AdminSetupPushNotification(SharedPtr<GlobalState const> state, const SetupPushNotificationRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminUpdateCatalogItems(SharedPtr<GlobalState const> state, const UpdateCatalogItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminUpdateRandomResultTables(SharedPtr<GlobalState const> state, const UpdateRandomResultTablesRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminUpdateStoreItems(SharedPtr<GlobalState const> state, const UpdateStoreItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetCatalogItemsResult> ClientGetCatalogItems(SharedPtr<TitlePlayer> entity, const GetCatalogItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPublisherDataResult> ClientGetPublisherData(SharedPtr<TitlePlayer> entity, const GetPublisherDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetStoreItemsResult> ClientGetStoreItems(SharedPtr<TitlePlayer> entity, const GetStoreItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTimeResult> ClientGetTime(SharedPtr<TitlePlayer> entity, const TaskQueue& queue);
    static AsyncOp<GetTitleDataResult> ClientGetTitleData(SharedPtr<TitlePlayer> entity, const GetTitleDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTitleNewsResult> ClientGetTitleNews(SharedPtr<TitlePlayer> entity, const GetTitleNewsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetCatalogItemsResult> ServerGetCatalogItems(SharedPtr<GlobalState const> state, const GetCatalogItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPublisherDataResult> ServerGetPublisherData(SharedPtr<GlobalState const> state, const GetPublisherDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetStoreItemsResult> ServerGetStoreItems(SharedPtr<GlobalState const> state, const GetStoreItemsServerRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTimeResult> ServerGetTime(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<GetTitleDataResult> ServerGetTitleData(SharedPtr<GlobalState const> state, const GetTitleDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTitleDataResult> ServerGetTitleInternalData(SharedPtr<GlobalState const> state, const GetTitleDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTitleNewsResult> ServerGetTitleNews(SharedPtr<GlobalState const> state, const GetTitleNewsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSetPublisherData(SharedPtr<GlobalState const> state, const SetPublisherDataRequest& request, const TaskQueue& queue);
    static AsyncOp<SetTitleDataResult> ServerSetTitleData(SharedPtr<GlobalState const> state, const SetTitleDataRequest& request, const TaskQueue& queue);
    static AsyncOp<SetTitleDataResult> ServerSetTitleInternalData(SharedPtr<GlobalState const> state, const SetTitleDataRequest& request, const TaskQueue& queue);
};

} // namespace TitleDataManagement
} // namespace PlayFab
