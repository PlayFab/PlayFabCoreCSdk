#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFPlayerDataManagementDataModelWrappers.h>
#include "AutoGenPlayerDataManagementResultHolders.h"

namespace PlayFabUnit
{

class AutoGenPlayerDataManagementTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestPlayerDataManagementAdminCreatePlayerStatisticDefinition(TestContext& testContext);

    void TestPlayerDataManagementAdminGetDataReport(TestContext& testContext);

    void TestPlayerDataManagementAdminGetPlayerStatisticDefinitions(TestContext& testContext);

    void TestPlayerDataManagementAdminGetPlayerStatisticVersions(TestContext& testContext);

    void TestPlayerDataManagementAdminGetUserData(TestContext& testContext);

    void TestPlayerDataManagementAdminGetUserInternalData(TestContext& testContext);

    void TestPlayerDataManagementAdminGetUserPublisherData(TestContext& testContext);

    void TestPlayerDataManagementAdminGetUserPublisherInternalData(TestContext& testContext);

    void TestPlayerDataManagementAdminGetUserPublisherReadOnlyData(TestContext& testContext);

    void TestPlayerDataManagementAdminGetUserReadOnlyData(TestContext& testContext);

    void TestPlayerDataManagementAdminIncrementPlayerStatisticVersion(TestContext& testContext);

    void TestPlayerDataManagementAdminRefundPurchase(TestContext& testContext);

    void TestPlayerDataManagementAdminResetUserStatistics(TestContext& testContext);

    void TestPlayerDataManagementAdminResolvePurchaseDispute(TestContext& testContext);

    void TestPlayerDataManagementAdminUpdatePlayerStatisticDefinition(TestContext& testContext);

    void TestPlayerDataManagementAdminUpdateUserData(TestContext& testContext);

    void TestPlayerDataManagementAdminUpdateUserInternalData(TestContext& testContext);

    void TestPlayerDataManagementAdminUpdateUserPublisherData(TestContext& testContext);

    void TestPlayerDataManagementAdminUpdateUserPublisherInternalData(TestContext& testContext);

    void TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData(TestContext& testContext);

    void TestPlayerDataManagementAdminUpdateUserReadOnlyData(TestContext& testContext);

    void TestPlayerDataManagementClientGetFriendLeaderboard(TestContext& testContext);

    void TestPlayerDataManagementClientGetFriendLeaderboardAroundPlayer(TestContext& testContext);

    void TestPlayerDataManagementClientGetLeaderboard(TestContext& testContext);

    void TestPlayerDataManagementClientGetLeaderboardAroundPlayer(TestContext& testContext);

    void TestPlayerDataManagementClientGetPlayerStatistics(TestContext& testContext);

    void TestPlayerDataManagementClientGetPlayerStatisticVersions(TestContext& testContext);

    void TestPlayerDataManagementClientGetUserData(TestContext& testContext);

    void TestPlayerDataManagementClientGetUserPublisherData(TestContext& testContext);

    void TestPlayerDataManagementClientGetUserPublisherReadOnlyData(TestContext& testContext);

    void TestPlayerDataManagementClientGetUserReadOnlyData(TestContext& testContext);

    void TestPlayerDataManagementClientUpdatePlayerStatistics(TestContext& testContext);

    void TestPlayerDataManagementClientUpdateUserData(TestContext& testContext);

    void TestPlayerDataManagementClientUpdateUserPublisherData(TestContext& testContext);

    void TestPlayerDataManagementServerGetFriendLeaderboard(TestContext& testContext);

    void TestPlayerDataManagementServerGetLeaderboard(TestContext& testContext);

    void TestPlayerDataManagementServerGetLeaderboardAroundUser(TestContext& testContext);

    void TestPlayerDataManagementServerGetPlayerCombinedInfo(TestContext& testContext);

    void TestPlayerDataManagementServerGetPlayerStatistics(TestContext& testContext);

    void TestPlayerDataManagementServerGetPlayerStatisticVersions(TestContext& testContext);

    void TestPlayerDataManagementServerGetUserData(TestContext& testContext);

    void TestPlayerDataManagementServerGetUserInternalData(TestContext& testContext);

    void TestPlayerDataManagementServerGetUserPublisherData(TestContext& testContext);

    void TestPlayerDataManagementServerGetUserPublisherInternalData(TestContext& testContext);

    void TestPlayerDataManagementServerGetUserPublisherReadOnlyData(TestContext& testContext);

    void TestPlayerDataManagementServerGetUserReadOnlyData(TestContext& testContext);

    void TestPlayerDataManagementServerUpdatePlayerStatistics(TestContext& testContext);

    void TestPlayerDataManagementServerUpdateUserData(TestContext& testContext);

    void TestPlayerDataManagementServerUpdateUserInternalData(TestContext& testContext);

    void TestPlayerDataManagementServerUpdateUserPublisherData(TestContext& testContext);

    void TestPlayerDataManagementServerUpdateUserPublisherInternalData(TestContext& testContext);

    void TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData(TestContext& testContext);

    void TestPlayerDataManagementServerUpdateUserReadOnlyData(TestContext& testContext);


protected:
    void AddTests();

    static void LogCreatePlayerStatisticDefinitionRequest(PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest const* request, const char* testName);
    static void FillCreatePlayerStatisticDefinitionRequest(PlayFab::Wrappers::PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementCreatePlayerStatisticDefinitionResult(PFPlayerDataManagementCreatePlayerStatisticDefinitionResult const* result);
    static HRESULT ValidatePFPlayerDataManagementCreatePlayerStatisticDefinitionResult(PFPlayerDataManagementCreatePlayerStatisticDefinitionResult* result);

    static void LogGetDataReportRequest(PFPlayerDataManagementGetDataReportRequest const* request, const char* testName);
    static void FillGetDataReportRequest(PlayFab::Wrappers::PFPlayerDataManagementGetDataReportRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementGetDataReportResult(PFPlayerDataManagementGetDataReportResult const* result);
    static HRESULT ValidatePFPlayerDataManagementGetDataReportResult(PFPlayerDataManagementGetDataReportResult* result);

    static HRESULT LogPFPlayerDataManagementGetPlayerStatisticDefinitionsResult(PFPlayerDataManagementGetPlayerStatisticDefinitionsResult const* result);
    static HRESULT ValidatePFPlayerDataManagementGetPlayerStatisticDefinitionsResult(PFPlayerDataManagementGetPlayerStatisticDefinitionsResult* result);

    static void LogGetPlayerStatisticVersionsRequest(PFPlayerDataManagementGetPlayerStatisticVersionsRequest const* request, const char* testName);
    static void FillGetPlayerStatisticVersionsRequest(PlayFab::Wrappers::PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementGetPlayerStatisticVersionsResult(PFPlayerDataManagementGetPlayerStatisticVersionsResult const* result);
    static HRESULT ValidatePFPlayerDataManagementGetPlayerStatisticVersionsResult(PFPlayerDataManagementGetPlayerStatisticVersionsResult* result);

    static void LogGetUserDataRequest(PFPlayerDataManagementGetUserDataRequest const* request, const char* testName);
    static void FillGetUserDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementAdminGetUserDataResult(PFPlayerDataManagementAdminGetUserDataResult const* result);
    static HRESULT ValidatePFPlayerDataManagementAdminGetUserDataResult(PFPlayerDataManagementAdminGetUserDataResult* result);






    static void LogIncrementPlayerStatisticVersionRequest(PFPlayerDataManagementIncrementPlayerStatisticVersionRequest const* request, const char* testName);
    static void FillIncrementPlayerStatisticVersionRequest(PlayFab::Wrappers::PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementIncrementPlayerStatisticVersionResult(PFPlayerDataManagementIncrementPlayerStatisticVersionResult const* result);
    static HRESULT ValidatePFPlayerDataManagementIncrementPlayerStatisticVersionResult(PFPlayerDataManagementIncrementPlayerStatisticVersionResult* result);

    static void LogRefundPurchaseRequest(PFPlayerDataManagementRefundPurchaseRequest const* request, const char* testName);
    static void FillRefundPurchaseRequest(PlayFab::Wrappers::PFPlayerDataManagementRefundPurchaseRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementRefundPurchaseResponse(PFPlayerDataManagementRefundPurchaseResponse const* result);
    static HRESULT ValidatePFPlayerDataManagementRefundPurchaseResponse(PFPlayerDataManagementRefundPurchaseResponse* result);

    static void LogResetUserStatisticsRequest(PFPlayerDataManagementResetUserStatisticsRequest const* request, const char* testName);
    static void FillResetUserStatisticsRequest(PlayFab::Wrappers::PFPlayerDataManagementResetUserStatisticsRequestWrapper<>& request);

    static void LogResolvePurchaseDisputeRequest(PFPlayerDataManagementResolvePurchaseDisputeRequest const* request, const char* testName);
    static void FillResolvePurchaseDisputeRequest(PlayFab::Wrappers::PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementResolvePurchaseDisputeResponse(PFPlayerDataManagementResolvePurchaseDisputeResponse const* result);
    static HRESULT ValidatePFPlayerDataManagementResolvePurchaseDisputeResponse(PFPlayerDataManagementResolvePurchaseDisputeResponse* result);

    static void LogUpdatePlayerStatisticDefinitionRequest(PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest const* request, const char* testName);
    static void FillUpdatePlayerStatisticDefinitionRequest(PlayFab::Wrappers::PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementUpdatePlayerStatisticDefinitionResult(PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult const* result);
    static HRESULT ValidatePFPlayerDataManagementUpdatePlayerStatisticDefinitionResult(PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult* result);

    static void LogAdminUpdateUserDataRequest(PFPlayerDataManagementAdminUpdateUserDataRequest const* request, const char* testName);
    static void FillAdminUpdateUserDataRequest(PlayFab::Wrappers::PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementUpdateUserDataResult(PFPlayerDataManagementUpdateUserDataResult const* result);
    static HRESULT ValidatePFPlayerDataManagementUpdateUserDataResult(PFPlayerDataManagementUpdateUserDataResult* result);

    static void LogUpdateUserInternalDataRequest(PFPlayerDataManagementUpdateUserInternalDataRequest const* request, const char* testName);
    static void FillUpdateUserInternalDataRequest(PlayFab::Wrappers::PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<>& request);





    static void LogClientGetFriendLeaderboardRequest(PFPlayerDataManagementClientGetFriendLeaderboardRequest const* request, const char* testName);
    static void FillClientGetFriendLeaderboardRequest(PlayFab::Wrappers::PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementGetLeaderboardResult(PFPlayerDataManagementGetLeaderboardResult const* result);
    static HRESULT ValidatePFPlayerDataManagementGetLeaderboardResult(PFPlayerDataManagementGetLeaderboardResult* result);

    static void LogGetFriendLeaderboardAroundPlayerRequest(PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest const* request, const char* testName);
    static void FillGetFriendLeaderboardAroundPlayerRequest(PlayFab::Wrappers::PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult(PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult const* result);
    static HRESULT ValidatePFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult(PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult* result);

    static void LogGetLeaderboardRequest(PFPlayerDataManagementGetLeaderboardRequest const* request, const char* testName);
    static void FillGetLeaderboardRequest(PlayFab::Wrappers::PFPlayerDataManagementGetLeaderboardRequestWrapper<>& request);

    static void LogGetLeaderboardAroundPlayerRequest(PFPlayerDataManagementGetLeaderboardAroundPlayerRequest const* request, const char* testName);
    static void FillGetLeaderboardAroundPlayerRequest(PlayFab::Wrappers::PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementGetLeaderboardAroundPlayerResult(PFPlayerDataManagementGetLeaderboardAroundPlayerResult const* result);
    static HRESULT ValidatePFPlayerDataManagementGetLeaderboardAroundPlayerResult(PFPlayerDataManagementGetLeaderboardAroundPlayerResult* result);

    static void LogClientGetPlayerStatisticsRequest(PFPlayerDataManagementClientGetPlayerStatisticsRequest const* request, const char* testName);
    static void FillClientGetPlayerStatisticsRequest(PlayFab::Wrappers::PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementClientGetPlayerStatisticsResult(PFPlayerDataManagementClientGetPlayerStatisticsResult const* result);
    static HRESULT ValidatePFPlayerDataManagementClientGetPlayerStatisticsResult(PFPlayerDataManagementClientGetPlayerStatisticsResult* result);


    static HRESULT LogPFPlayerDataManagementClientGetUserDataResult(PFPlayerDataManagementClientGetUserDataResult const* result);
    static HRESULT ValidatePFPlayerDataManagementClientGetUserDataResult(PFPlayerDataManagementClientGetUserDataResult* result);




    static void LogClientUpdatePlayerStatisticsRequest(PFPlayerDataManagementClientUpdatePlayerStatisticsRequest const* request, const char* testName);
    static void FillClientUpdatePlayerStatisticsRequest(PlayFab::Wrappers::PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper<>& request);

    static void LogClientUpdateUserDataRequest(PFPlayerDataManagementClientUpdateUserDataRequest const* request, const char* testName);
    static void FillClientUpdateUserDataRequest(PlayFab::Wrappers::PFPlayerDataManagementClientUpdateUserDataRequestWrapper<>& request);


    static void LogServerGetFriendLeaderboardRequest(PFPlayerDataManagementServerGetFriendLeaderboardRequest const* request, const char* testName);
    static void FillServerGetFriendLeaderboardRequest(PlayFab::Wrappers::PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper<>& request);


    static void LogGetLeaderboardAroundUserRequest(PFPlayerDataManagementGetLeaderboardAroundUserRequest const* request, const char* testName);
    static void FillGetLeaderboardAroundUserRequest(PlayFab::Wrappers::PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementGetLeaderboardAroundUserResult(PFPlayerDataManagementGetLeaderboardAroundUserResult const* result);
    static HRESULT ValidatePFPlayerDataManagementGetLeaderboardAroundUserResult(PFPlayerDataManagementGetLeaderboardAroundUserResult* result);

    static void LogGetPlayerCombinedInfoRequest(PFGetPlayerCombinedInfoRequest const* request, const char* testName);
    static void FillGetPlayerCombinedInfoRequest(PlayFab::Wrappers::PFGetPlayerCombinedInfoRequestWrapper<>& request);
    static HRESULT LogPFGetPlayerCombinedInfoResult(PFGetPlayerCombinedInfoResult const* result);
    static HRESULT ValidatePFGetPlayerCombinedInfoResult(PFGetPlayerCombinedInfoResult* result);

    static void LogServerGetPlayerStatisticsRequest(PFPlayerDataManagementServerGetPlayerStatisticsRequest const* request, const char* testName);
    static void FillServerGetPlayerStatisticsRequest(PlayFab::Wrappers::PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper<>& request);
    static HRESULT LogPFPlayerDataManagementServerGetPlayerStatisticsResult(PFPlayerDataManagementServerGetPlayerStatisticsResult const* result);
    static HRESULT ValidatePFPlayerDataManagementServerGetPlayerStatisticsResult(PFPlayerDataManagementServerGetPlayerStatisticsResult* result);


    static HRESULT LogPFPlayerDataManagementServerGetUserDataResult(PFPlayerDataManagementServerGetUserDataResult const* result);
    static HRESULT ValidatePFPlayerDataManagementServerGetUserDataResult(PFPlayerDataManagementServerGetUserDataResult* result);






    static void LogServerUpdatePlayerStatisticsRequest(PFPlayerDataManagementServerUpdatePlayerStatisticsRequest const* request, const char* testName);
    static void FillServerUpdatePlayerStatisticsRequest(PlayFab::Wrappers::PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper<>& request);

    static void LogServerUpdateUserDataRequest(PFPlayerDataManagementServerUpdateUserDataRequest const* request, const char* testName);
    static void FillServerUpdateUserDataRequest(PlayFab::Wrappers::PFPlayerDataManagementServerUpdateUserDataRequestWrapper<>& request);






    struct PlayerDataManagementTestData
    {
        ~PlayerDataManagementTestData() = default;

    };

    static PlayerDataManagementTestData testData;

public:
    PFStateHandle stateHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle{ nullptr };
    PFEntityHandle entityHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle2{ nullptr };
    PFEntityHandle entityHandle2{ nullptr };
    PFEntityHandle titleEntityHandle{ nullptr };

    void ClassSetUp() override;
    void ClassTearDown() override;
    void SetUp(TestContext& testContext) override;

    void Tick(TestContext&) override {}
};

}
