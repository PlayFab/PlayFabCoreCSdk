#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFMatchmakingDataModelWrappers.h>
#include "AutoGenMatchmakingResultHolders.h"

namespace PlayFabUnit
{

class AutoGenMatchmakingTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingAdminGetMatchmakerGameInfo(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingAdminGetMatchmakerGameModes(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingAdminModifyMatchmakerGameModes(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingClientGetCurrentGames(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingClientGetGameServerRegions(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingClientMatchmake(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingClientStartGame(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingAuthUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingPlayerJoined(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingPlayerLeft(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingStartGame(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingUserInfo(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingServerDeregisterGame(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingServerNotifyMatchmakerPlayerLeft(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingServerRedeemMatchmakerTicket(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingServerRefreshGameServerInstanceHeartbeat(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingServerRegisterGame(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingServerSetGameServerInstanceData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingServerSetGameServerInstanceState(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingServerSetGameServerInstanceTags(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingCancelAllMatchmakingTicketsForPlayer(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingCancelAllServerBackfillTicketsForPlayer(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingCancelMatchmakingTicket(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingCancelServerBackfillTicket(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingCreateMatchmakingTicket(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingCreateServerBackfillTicket(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingCreateServerMatchmakingTicket(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingGetMatch(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingGetMatchmakingTicket(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingGetQueueStatistics(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingGetServerBackfillTicket(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingJoinMatchmakingTicket(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingListMatchmakingTicketsForPlayer(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMatchmakingListServerBackfillTicketsForPlayer(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogGetMatchmakerGameInfoRequest(PFMatchmakingGetMatchmakerGameInfoRequest const* request, const char* testName);
    static HRESULT LogGetMatchmakerGameInfoResult(PFMatchmakingGetMatchmakerGameInfoResult const* result);
    static void LogGetMatchmakerGameModesRequest(PFMatchmakingGetMatchmakerGameModesRequest const* request, const char* testName);
    static HRESULT LogGetMatchmakerGameModesResult(PFMatchmakingGetMatchmakerGameModesResult const* result);
    static void LogModifyMatchmakerGameModesRequest(PFMatchmakingModifyMatchmakerGameModesRequest const* request, const char* testName);
    static void LogCurrentGamesRequest(PFMatchmakingCurrentGamesRequest const* request, const char* testName);
    static HRESULT LogCurrentGamesResult(PFMatchmakingCurrentGamesResult const* result);
    static void LogGameServerRegionsRequest(PFMatchmakingGameServerRegionsRequest const* request, const char* testName);
    static HRESULT LogGameServerRegionsResult(PFMatchmakingGameServerRegionsResult const* result);
    static void LogMatchmakeRequest(PFMatchmakingMatchmakeRequest const* request, const char* testName);
    static HRESULT LogMatchmakeResult(PFMatchmakingMatchmakeResult const* result);
    static void LogClientStartGameRequest(PFMatchmakingClientStartGameRequest const* request, const char* testName);
    static HRESULT LogStartGameResult(PFMatchmakingStartGameResult const* result);
    static void LogAuthUserRequest(PFMatchmakingAuthUserRequest const* request, const char* testName);
    static HRESULT LogAuthUserResponse(PFMatchmakingAuthUserResponse const* result);
    static void LogPlayerJoinedRequest(PFMatchmakingPlayerJoinedRequest const* request, const char* testName);
    static void LogPlayerLeftRequest(PFMatchmakingPlayerLeftRequest const* request, const char* testName);
    static void LogMatchmakerStartGameRequest(PFMatchmakingMatchmakerStartGameRequest const* request, const char* testName);
    static HRESULT LogStartGameResponse(PFMatchmakingStartGameResponse const* result);
    static void LogUserInfoRequest(PFMatchmakingUserInfoRequest const* request, const char* testName);
    static HRESULT LogUserInfoResponse(PFMatchmakingUserInfoResponse const* result);
    static void LogDeregisterGameRequest(PFMatchmakingDeregisterGameRequest const* request, const char* testName);
    static void LogNotifyMatchmakerPlayerLeftRequest(PFMatchmakingNotifyMatchmakerPlayerLeftRequest const* request, const char* testName);
    static HRESULT LogNotifyMatchmakerPlayerLeftResult(PFMatchmakingNotifyMatchmakerPlayerLeftResult const* result);
    static void LogRedeemMatchmakerTicketRequest(PFMatchmakingRedeemMatchmakerTicketRequest const* request, const char* testName);
    static HRESULT LogRedeemMatchmakerTicketResult(PFMatchmakingRedeemMatchmakerTicketResult const* result);
    static void LogRefreshGameServerInstanceHeartbeatRequest(PFMatchmakingRefreshGameServerInstanceHeartbeatRequest const* request, const char* testName);
    static void LogRegisterGameRequest(PFMatchmakingRegisterGameRequest const* request, const char* testName);
    static HRESULT LogRegisterGameResponse(PFMatchmakingRegisterGameResponse const* result);
    static void LogSetGameServerInstanceDataRequest(PFMatchmakingSetGameServerInstanceDataRequest const* request, const char* testName);
    static void LogSetGameServerInstanceStateRequest(PFMatchmakingSetGameServerInstanceStateRequest const* request, const char* testName);
    static void LogSetGameServerInstanceTagsRequest(PFMatchmakingSetGameServerInstanceTagsRequest const* request, const char* testName);
    static void LogCancelAllMatchmakingTicketsForPlayerRequest(PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest const* request, const char* testName);
    static void LogCancelAllServerBackfillTicketsForPlayerRequest(PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest const* request, const char* testName);
    static void LogCancelMatchmakingTicketRequest(PFMatchmakingCancelMatchmakingTicketRequest const* request, const char* testName);
    static void LogCancelServerBackfillTicketRequest(PFMatchmakingCancelServerBackfillTicketRequest const* request, const char* testName);
    static void LogCreateMatchmakingTicketRequest(PFMatchmakingCreateMatchmakingTicketRequest const* request, const char* testName);
    static HRESULT LogCreateMatchmakingTicketResult(PFMatchmakingCreateMatchmakingTicketResult const* result);
    static void LogCreateServerBackfillTicketRequest(PFMatchmakingCreateServerBackfillTicketRequest const* request, const char* testName);
    static HRESULT LogCreateServerBackfillTicketResult(PFMatchmakingCreateServerBackfillTicketResult const* result);
    static void LogCreateServerMatchmakingTicketRequest(PFMatchmakingCreateServerMatchmakingTicketRequest const* request, const char* testName);
    static void LogGetMatchRequest(PFMatchmakingGetMatchRequest const* request, const char* testName);
    static HRESULT LogGetMatchResult(PFMatchmakingGetMatchResult const* result);
    static void LogGetMatchmakingTicketRequest(PFMatchmakingGetMatchmakingTicketRequest const* request, const char* testName);
    static HRESULT LogGetMatchmakingTicketResult(PFMatchmakingGetMatchmakingTicketResult const* result);
    static void LogGetQueueStatisticsRequest(PFMatchmakingGetQueueStatisticsRequest const* request, const char* testName);
    static HRESULT LogGetQueueStatisticsResult(PFMatchmakingGetQueueStatisticsResult const* result);
    static void LogGetServerBackfillTicketRequest(PFMatchmakingGetServerBackfillTicketRequest const* request, const char* testName);
    static HRESULT LogGetServerBackfillTicketResult(PFMatchmakingGetServerBackfillTicketResult const* result);
    static void LogJoinMatchmakingTicketRequest(PFMatchmakingJoinMatchmakingTicketRequest const* request, const char* testName);
    static void LogListMatchmakingTicketsForPlayerRequest(PFMatchmakingListMatchmakingTicketsForPlayerRequest const* request, const char* testName);
    static HRESULT LogListMatchmakingTicketsForPlayerResult(PFMatchmakingListMatchmakingTicketsForPlayerResult const* result);
    static void LogListServerBackfillTicketsForPlayerRequest(PFMatchmakingListServerBackfillTicketsForPlayerRequest const* request, const char* testName);
    static HRESULT LogListServerBackfillTicketsForPlayerResult(PFMatchmakingListServerBackfillTicketsForPlayerResult const* result);

    static void FillAdminGetMatchmakerGameInfoRequest(PlayFab::Wrappers::PFMatchmakingGetMatchmakerGameInfoRequestWrapper<>& request);
    static HRESULT ValidateAdminGetMatchmakerGameInfoResponse(PFMatchmakingGetMatchmakerGameInfoResult* result);

    static void FillAdminGetMatchmakerGameModesRequest(PlayFab::Wrappers::PFMatchmakingGetMatchmakerGameModesRequestWrapper<>& request);
    static HRESULT ValidateAdminGetMatchmakerGameModesResponse(PFMatchmakingGetMatchmakerGameModesResult* result);

    static void FillAdminModifyMatchmakerGameModesRequest(PlayFab::Wrappers::PFMatchmakingModifyMatchmakerGameModesRequestWrapper<>& request);

    static void FillClientGetCurrentGamesRequest(PlayFab::Wrappers::PFMatchmakingCurrentGamesRequestWrapper<>& request);
    static HRESULT ValidateClientGetCurrentGamesResponse(PFMatchmakingCurrentGamesResult* result);

    static void FillClientGetGameServerRegionsRequest(PlayFab::Wrappers::PFMatchmakingGameServerRegionsRequestWrapper<>& request);
    static HRESULT ValidateClientGetGameServerRegionsResponse(PFMatchmakingGameServerRegionsResult* result);

    static void FillClientMatchmakeRequest(PlayFab::Wrappers::PFMatchmakingMatchmakeRequestWrapper<>& request);
    static HRESULT ValidateClientMatchmakeResponse(PFMatchmakingMatchmakeResult* result);

    static void FillClientStartGameRequest(PlayFab::Wrappers::PFMatchmakingClientStartGameRequestWrapper<>& request);
    static HRESULT ValidateClientStartGameResponse(PFMatchmakingStartGameResult* result);

    static void FillAuthUserRequest(PlayFab::Wrappers::PFMatchmakingAuthUserRequestWrapper<>& request);
    static HRESULT ValidateAuthUserResponse(PFMatchmakingAuthUserResponse* result);

    static void FillPlayerJoinedRequest(PlayFab::Wrappers::PFMatchmakingPlayerJoinedRequestWrapper<>& request);

    static void FillPlayerLeftRequest(PlayFab::Wrappers::PFMatchmakingPlayerLeftRequestWrapper<>& request);

    static void FillStartGameRequest(PlayFab::Wrappers::PFMatchmakingMatchmakerStartGameRequestWrapper<>& request);
    static HRESULT ValidateStartGameResponse(PFMatchmakingStartGameResponse* result);

    static void FillUserInfoRequest(PlayFab::Wrappers::PFMatchmakingUserInfoRequestWrapper<>& request);
    static HRESULT ValidateUserInfoResponse(PFMatchmakingUserInfoResponse* result);

    static void FillServerDeregisterGameRequest(PlayFab::Wrappers::PFMatchmakingDeregisterGameRequestWrapper<>& request);

    static void FillServerNotifyMatchmakerPlayerLeftRequest(PlayFab::Wrappers::PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper<>& request);
    static HRESULT ValidateServerNotifyMatchmakerPlayerLeftResponse(PFMatchmakingNotifyMatchmakerPlayerLeftResult* result);

    static void FillServerRedeemMatchmakerTicketRequest(PlayFab::Wrappers::PFMatchmakingRedeemMatchmakerTicketRequestWrapper<>& request);
    static HRESULT ValidateServerRedeemMatchmakerTicketResponse(PFMatchmakingRedeemMatchmakerTicketResult* result);

    static void FillServerRefreshGameServerInstanceHeartbeatRequest(PlayFab::Wrappers::PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper<>& request);

    static void FillServerRegisterGameRequest(PlayFab::Wrappers::PFMatchmakingRegisterGameRequestWrapper<>& request);
    static HRESULT ValidateServerRegisterGameResponse(PFMatchmakingRegisterGameResponse* result);

    static void FillServerSetGameServerInstanceDataRequest(PlayFab::Wrappers::PFMatchmakingSetGameServerInstanceDataRequestWrapper<>& request);

    static void FillServerSetGameServerInstanceStateRequest(PlayFab::Wrappers::PFMatchmakingSetGameServerInstanceStateRequestWrapper<>& request);

    static void FillServerSetGameServerInstanceTagsRequest(PlayFab::Wrappers::PFMatchmakingSetGameServerInstanceTagsRequestWrapper<>& request);

    static void FillCancelAllMatchmakingTicketsForPlayerRequest(PlayFab::Wrappers::PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper<>& request);

    static void FillCancelAllServerBackfillTicketsForPlayerRequest(PlayFab::Wrappers::PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper<>& request);

    static void FillCancelMatchmakingTicketRequest(PlayFab::Wrappers::PFMatchmakingCancelMatchmakingTicketRequestWrapper<>& request);

    static void FillCancelServerBackfillTicketRequest(PlayFab::Wrappers::PFMatchmakingCancelServerBackfillTicketRequestWrapper<>& request);

    static void FillCreateMatchmakingTicketRequest(PlayFab::Wrappers::PFMatchmakingCreateMatchmakingTicketRequestWrapper<>& request);
    static HRESULT ValidateCreateMatchmakingTicketResponse(PFMatchmakingCreateMatchmakingTicketResult* result);

    static void FillCreateServerBackfillTicketRequest(PlayFab::Wrappers::PFMatchmakingCreateServerBackfillTicketRequestWrapper<>& request);
    static HRESULT ValidateCreateServerBackfillTicketResponse(PFMatchmakingCreateServerBackfillTicketResult* result);

    static void FillCreateServerMatchmakingTicketRequest(PlayFab::Wrappers::PFMatchmakingCreateServerMatchmakingTicketRequestWrapper<>& request);
    static HRESULT ValidateCreateServerMatchmakingTicketResponse(PFMatchmakingCreateMatchmakingTicketResult* result);

    static void FillGetMatchRequest(PlayFab::Wrappers::PFMatchmakingGetMatchRequestWrapper<>& request);
    static HRESULT ValidateGetMatchResponse(PFMatchmakingGetMatchResult* result);

    static void FillGetMatchmakingTicketRequest(PlayFab::Wrappers::PFMatchmakingGetMatchmakingTicketRequestWrapper<>& request);
    static HRESULT ValidateGetMatchmakingTicketResponse(PFMatchmakingGetMatchmakingTicketResult* result);

    static void FillGetQueueStatisticsRequest(PlayFab::Wrappers::PFMatchmakingGetQueueStatisticsRequestWrapper<>& request);
    static HRESULT ValidateGetQueueStatisticsResponse(PFMatchmakingGetQueueStatisticsResult* result);

    static void FillGetServerBackfillTicketRequest(PlayFab::Wrappers::PFMatchmakingGetServerBackfillTicketRequestWrapper<>& request);
    static HRESULT ValidateGetServerBackfillTicketResponse(PFMatchmakingGetServerBackfillTicketResult* result);

    static void FillJoinMatchmakingTicketRequest(PlayFab::Wrappers::PFMatchmakingJoinMatchmakingTicketRequestWrapper<>& request);

    static void FillListMatchmakingTicketsForPlayerRequest(PlayFab::Wrappers::PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper<>& request);
    static HRESULT ValidateListMatchmakingTicketsForPlayerResponse(PFMatchmakingListMatchmakingTicketsForPlayerResult* result);

    static void FillListServerBackfillTicketsForPlayerRequest(PlayFab::Wrappers::PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper<>& request);
    static HRESULT ValidateListServerBackfillTicketsForPlayerResponse(PFMatchmakingListServerBackfillTicketsForPlayerResult* result);

    struct MatchmakingTestData
    {
        ~MatchmakingTestData() = default;

    };

    static MatchmakingTestData testData;

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
