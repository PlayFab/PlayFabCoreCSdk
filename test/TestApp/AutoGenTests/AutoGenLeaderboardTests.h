#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFLeaderboardDataModelWrappers.h>
#include "AutoGenLeaderboardResultHolders.h"

namespace PlayFabUnit
{

class AutoGenLeaderboardTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardAdminCreatePlayerStatisticDefinition(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardAdminGetPlayerStatisticDefinitions(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardAdminGetPlayerStatisticVersions(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardAdminIncrementPlayerStatisticVersion(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardAdminResetUserStatistics(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardAdminUpdatePlayerStatisticDefinition(TestContext& testContext);
#endif

    void TestLeaderboardClientGetFriendLeaderboard(TestContext& testContext);

    void TestLeaderboardClientGetFriendLeaderboardAroundPlayer(TestContext& testContext);

    void TestLeaderboardClientGetLeaderboard(TestContext& testContext);

    void TestLeaderboardClientGetLeaderboardAroundPlayer(TestContext& testContext);

    void TestLeaderboardClientGetPlayerStatistics(TestContext& testContext);

    void TestLeaderboardClientGetPlayerStatisticVersions(TestContext& testContext);

    void TestLeaderboardClientUpdatePlayerStatistics(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardServerGetFriendLeaderboard(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardServerGetLeaderboard(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardServerGetLeaderboardAroundUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardServerGetPlayerStatistics(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardServerGetPlayerStatisticVersions(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestLeaderboardServerUpdatePlayerStatistics(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogCreatePlayerStatisticDefinitionRequest(PFLeaderboardCreatePlayerStatisticDefinitionRequest const* request, const char* testName);
    static HRESULT LogCreatePlayerStatisticDefinitionResult(PFLeaderboardCreatePlayerStatisticDefinitionResult const* result);
    static HRESULT LogGetPlayerStatisticDefinitionsResult(PFLeaderboardGetPlayerStatisticDefinitionsResult const* result);
    static void LogGetPlayerStatisticVersionsRequest(PFLeaderboardGetPlayerStatisticVersionsRequest const* request, const char* testName);
    static HRESULT LogGetPlayerStatisticVersionsResult(PFLeaderboardGetPlayerStatisticVersionsResult const* result);
    static void LogIncrementPlayerStatisticVersionRequest(PFLeaderboardIncrementPlayerStatisticVersionRequest const* request, const char* testName);
    static HRESULT LogIncrementPlayerStatisticVersionResult(PFLeaderboardIncrementPlayerStatisticVersionResult const* result);
    static void LogResetUserStatisticsRequest(PFLeaderboardResetUserStatisticsRequest const* request, const char* testName);
    static void LogUpdatePlayerStatisticDefinitionRequest(PFLeaderboardUpdatePlayerStatisticDefinitionRequest const* request, const char* testName);
    static HRESULT LogUpdatePlayerStatisticDefinitionResult(PFLeaderboardUpdatePlayerStatisticDefinitionResult const* result);
    static void LogClientGetFriendLeaderboardRequest(PFLeaderboardClientGetFriendLeaderboardRequest const* request, const char* testName);
    static HRESULT LogGetLeaderboardResult(PFLeaderboardGetLeaderboardResult const* result);
    static void LogGetFriendLeaderboardAroundPlayerRequest(PFLeaderboardGetFriendLeaderboardAroundPlayerRequest const* request, const char* testName);
    static HRESULT LogGetFriendLeaderboardAroundPlayerResult(PFLeaderboardGetFriendLeaderboardAroundPlayerResult const* result);
    static void LogGetLeaderboardRequest(PFLeaderboardGetLeaderboardRequest const* request, const char* testName);
    static void LogGetLeaderboardAroundPlayerRequest(PFLeaderboardGetLeaderboardAroundPlayerRequest const* request, const char* testName);
    static HRESULT LogGetLeaderboardAroundPlayerResult(PFLeaderboardGetLeaderboardAroundPlayerResult const* result);
    static void LogClientGetPlayerStatisticsRequest(PFLeaderboardClientGetPlayerStatisticsRequest const* request, const char* testName);
    static HRESULT LogClientGetPlayerStatisticsResult(PFLeaderboardClientGetPlayerStatisticsResult const* result);
    static void LogClientUpdatePlayerStatisticsRequest(PFLeaderboardClientUpdatePlayerStatisticsRequest const* request, const char* testName);
    static void LogServerGetFriendLeaderboardRequest(PFLeaderboardServerGetFriendLeaderboardRequest const* request, const char* testName);
    static void LogGetLeaderboardAroundUserRequest(PFLeaderboardGetLeaderboardAroundUserRequest const* request, const char* testName);
    static HRESULT LogGetLeaderboardAroundUserResult(PFLeaderboardGetLeaderboardAroundUserResult const* result);
    static void LogServerGetPlayerStatisticsRequest(PFLeaderboardServerGetPlayerStatisticsRequest const* request, const char* testName);
    static HRESULT LogServerGetPlayerStatisticsResult(PFLeaderboardServerGetPlayerStatisticsResult const* result);
    static void LogServerUpdatePlayerStatisticsRequest(PFLeaderboardServerUpdatePlayerStatisticsRequest const* request, const char* testName);

    static void FillAdminCreatePlayerStatisticDefinitionRequest(PlayFab::Wrappers::PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper<>& request);
    static HRESULT ValidateAdminCreatePlayerStatisticDefinitionResponse(PFLeaderboardCreatePlayerStatisticDefinitionResult* result);

    static HRESULT ValidateAdminGetPlayerStatisticDefinitionsResponse(PFLeaderboardGetPlayerStatisticDefinitionsResult* result);

    static void FillAdminGetPlayerStatisticVersionsRequest(PlayFab::Wrappers::PFLeaderboardGetPlayerStatisticVersionsRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPlayerStatisticVersionsResponse(PFLeaderboardGetPlayerStatisticVersionsResult* result);

    static void FillAdminIncrementPlayerStatisticVersionRequest(PlayFab::Wrappers::PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper<>& request);
    static HRESULT ValidateAdminIncrementPlayerStatisticVersionResponse(PFLeaderboardIncrementPlayerStatisticVersionResult* result);

    static void FillAdminResetUserStatisticsRequest(PlayFab::Wrappers::PFLeaderboardResetUserStatisticsRequestWrapper<>& request);

    static void FillAdminUpdatePlayerStatisticDefinitionRequest(PlayFab::Wrappers::PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdatePlayerStatisticDefinitionResponse(PFLeaderboardUpdatePlayerStatisticDefinitionResult* result);

    static void FillClientGetFriendLeaderboardRequest(PlayFab::Wrappers::PFLeaderboardClientGetFriendLeaderboardRequestWrapper<>& request);
    static HRESULT ValidateClientGetFriendLeaderboardResponse(PFLeaderboardGetLeaderboardResult* result);

    static void FillClientGetFriendLeaderboardAroundPlayerRequest(PlayFab::Wrappers::PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper<>& request);
    static HRESULT ValidateClientGetFriendLeaderboardAroundPlayerResponse(PFLeaderboardGetFriendLeaderboardAroundPlayerResult* result);

    static void FillClientGetLeaderboardRequest(PlayFab::Wrappers::PFLeaderboardGetLeaderboardRequestWrapper<>& request);
    static HRESULT ValidateClientGetLeaderboardResponse(PFLeaderboardGetLeaderboardResult* result);

    static void FillClientGetLeaderboardAroundPlayerRequest(PlayFab::Wrappers::PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper<>& request);
    static HRESULT ValidateClientGetLeaderboardAroundPlayerResponse(PFLeaderboardGetLeaderboardAroundPlayerResult* result);

    static void FillClientGetPlayerStatisticsRequest(PlayFab::Wrappers::PFLeaderboardClientGetPlayerStatisticsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayerStatisticsResponse(PFLeaderboardClientGetPlayerStatisticsResult* result);

    static void FillClientGetPlayerStatisticVersionsRequest(PlayFab::Wrappers::PFLeaderboardGetPlayerStatisticVersionsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayerStatisticVersionsResponse(PFLeaderboardGetPlayerStatisticVersionsResult* result);

    static void FillClientUpdatePlayerStatisticsRequest(PlayFab::Wrappers::PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper<>& request);

    static void FillServerGetFriendLeaderboardRequest(PlayFab::Wrappers::PFLeaderboardServerGetFriendLeaderboardRequestWrapper<>& request);
    static HRESULT ValidateServerGetFriendLeaderboardResponse(PFLeaderboardGetLeaderboardResult* result);

    static void FillServerGetLeaderboardRequest(PlayFab::Wrappers::PFLeaderboardGetLeaderboardRequestWrapper<>& request);
    static HRESULT ValidateServerGetLeaderboardResponse(PFLeaderboardGetLeaderboardResult* result);

    static void FillServerGetLeaderboardAroundUserRequest(PlayFab::Wrappers::PFLeaderboardGetLeaderboardAroundUserRequestWrapper<>& request);
    static HRESULT ValidateServerGetLeaderboardAroundUserResponse(PFLeaderboardGetLeaderboardAroundUserResult* result);

    static void FillServerGetPlayerStatisticsRequest(PlayFab::Wrappers::PFLeaderboardServerGetPlayerStatisticsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayerStatisticsResponse(PFLeaderboardServerGetPlayerStatisticsResult* result);

    static void FillServerGetPlayerStatisticVersionsRequest(PlayFab::Wrappers::PFLeaderboardGetPlayerStatisticVersionsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayerStatisticVersionsResponse(PFLeaderboardGetPlayerStatisticVersionsResult* result);

    static void FillServerUpdatePlayerStatisticsRequest(PlayFab::Wrappers::PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper<>& request);

    struct LeaderboardTestData
    {
        ~LeaderboardTestData() = default;

    };

    static LeaderboardTestData testData;

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
