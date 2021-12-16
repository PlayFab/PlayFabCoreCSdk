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
    static void FillGetMatchmakerGameInfoRequest(PlayFab::Wrappers::PFMatchmakingGetMatchmakerGameInfoRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingGetMatchmakerGameInfoResult(PFMatchmakingGetMatchmakerGameInfoResult const* result);
    static HRESULT ValidatePFMatchmakingGetMatchmakerGameInfoResult(PFMatchmakingGetMatchmakerGameInfoResult* result);

    static void LogGetMatchmakerGameModesRequest(PFMatchmakingGetMatchmakerGameModesRequest const* request, const char* testName);
    static void FillGetMatchmakerGameModesRequest(PlayFab::Wrappers::PFMatchmakingGetMatchmakerGameModesRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingGetMatchmakerGameModesResult(PFMatchmakingGetMatchmakerGameModesResult const* result);
    static HRESULT ValidatePFMatchmakingGetMatchmakerGameModesResult(PFMatchmakingGetMatchmakerGameModesResult* result);

    static void LogModifyMatchmakerGameModesRequest(PFMatchmakingModifyMatchmakerGameModesRequest const* request, const char* testName);
    static void FillModifyMatchmakerGameModesRequest(PlayFab::Wrappers::PFMatchmakingModifyMatchmakerGameModesRequestWrapper<>& request);

    static void LogCurrentGamesRequest(PFMatchmakingCurrentGamesRequest const* request, const char* testName);
    static void FillCurrentGamesRequest(PlayFab::Wrappers::PFMatchmakingCurrentGamesRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingCurrentGamesResult(PFMatchmakingCurrentGamesResult const* result);
    static HRESULT ValidatePFMatchmakingCurrentGamesResult(PFMatchmakingCurrentGamesResult* result);

    static void LogGameServerRegionsRequest(PFMatchmakingGameServerRegionsRequest const* request, const char* testName);
    static void FillGameServerRegionsRequest(PlayFab::Wrappers::PFMatchmakingGameServerRegionsRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingGameServerRegionsResult(PFMatchmakingGameServerRegionsResult const* result);
    static HRESULT ValidatePFMatchmakingGameServerRegionsResult(PFMatchmakingGameServerRegionsResult* result);

    static void LogMatchmakeRequest(PFMatchmakingMatchmakeRequest const* request, const char* testName);
    static void FillMatchmakeRequest(PlayFab::Wrappers::PFMatchmakingMatchmakeRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingMatchmakeResult(PFMatchmakingMatchmakeResult const* result);
    static HRESULT ValidatePFMatchmakingMatchmakeResult(PFMatchmakingMatchmakeResult* result);

    static void LogClientStartGameRequest(PFMatchmakingClientStartGameRequest const* request, const char* testName);
    static void FillClientStartGameRequest(PlayFab::Wrappers::PFMatchmakingClientStartGameRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingStartGameResult(PFMatchmakingStartGameResult const* result);
    static HRESULT ValidatePFMatchmakingStartGameResult(PFMatchmakingStartGameResult* result);

    static void LogAuthUserRequest(PFMatchmakingAuthUserRequest const* request, const char* testName);
    static void FillAuthUserRequest(PlayFab::Wrappers::PFMatchmakingAuthUserRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingAuthUserResponse(PFMatchmakingAuthUserResponse const* result);
    static HRESULT ValidatePFMatchmakingAuthUserResponse(PFMatchmakingAuthUserResponse* result);

    static void LogPlayerJoinedRequest(PFMatchmakingPlayerJoinedRequest const* request, const char* testName);
    static void FillPlayerJoinedRequest(PlayFab::Wrappers::PFMatchmakingPlayerJoinedRequestWrapper<>& request);

    static void LogPlayerLeftRequest(PFMatchmakingPlayerLeftRequest const* request, const char* testName);
    static void FillPlayerLeftRequest(PlayFab::Wrappers::PFMatchmakingPlayerLeftRequestWrapper<>& request);

    static void LogMatchmakerStartGameRequest(PFMatchmakingMatchmakerStartGameRequest const* request, const char* testName);
    static void FillMatchmakerStartGameRequest(PlayFab::Wrappers::PFMatchmakingMatchmakerStartGameRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingStartGameResponse(PFMatchmakingStartGameResponse const* result);
    static HRESULT ValidatePFMatchmakingStartGameResponse(PFMatchmakingStartGameResponse* result);

    static void LogUserInfoRequest(PFMatchmakingUserInfoRequest const* request, const char* testName);
    static void FillUserInfoRequest(PlayFab::Wrappers::PFMatchmakingUserInfoRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingUserInfoResponse(PFMatchmakingUserInfoResponse const* result);
    static HRESULT ValidatePFMatchmakingUserInfoResponse(PFMatchmakingUserInfoResponse* result);

    static void LogDeregisterGameRequest(PFMatchmakingDeregisterGameRequest const* request, const char* testName);
    static void FillDeregisterGameRequest(PlayFab::Wrappers::PFMatchmakingDeregisterGameRequestWrapper<>& request);

    static void LogNotifyMatchmakerPlayerLeftRequest(PFMatchmakingNotifyMatchmakerPlayerLeftRequest const* request, const char* testName);
    static void FillNotifyMatchmakerPlayerLeftRequest(PlayFab::Wrappers::PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingNotifyMatchmakerPlayerLeftResult(PFMatchmakingNotifyMatchmakerPlayerLeftResult const* result);
    static HRESULT ValidatePFMatchmakingNotifyMatchmakerPlayerLeftResult(PFMatchmakingNotifyMatchmakerPlayerLeftResult* result);

    static void LogRedeemMatchmakerTicketRequest(PFMatchmakingRedeemMatchmakerTicketRequest const* request, const char* testName);
    static void FillRedeemMatchmakerTicketRequest(PlayFab::Wrappers::PFMatchmakingRedeemMatchmakerTicketRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingRedeemMatchmakerTicketResult(PFMatchmakingRedeemMatchmakerTicketResult const* result);
    static HRESULT ValidatePFMatchmakingRedeemMatchmakerTicketResult(PFMatchmakingRedeemMatchmakerTicketResult* result);

    static void LogRefreshGameServerInstanceHeartbeatRequest(PFMatchmakingRefreshGameServerInstanceHeartbeatRequest const* request, const char* testName);
    static void FillRefreshGameServerInstanceHeartbeatRequest(PlayFab::Wrappers::PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper<>& request);

    static void LogRegisterGameRequest(PFMatchmakingRegisterGameRequest const* request, const char* testName);
    static void FillRegisterGameRequest(PlayFab::Wrappers::PFMatchmakingRegisterGameRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingRegisterGameResponse(PFMatchmakingRegisterGameResponse const* result);
    static HRESULT ValidatePFMatchmakingRegisterGameResponse(PFMatchmakingRegisterGameResponse* result);

    static void LogSetGameServerInstanceDataRequest(PFMatchmakingSetGameServerInstanceDataRequest const* request, const char* testName);
    static void FillSetGameServerInstanceDataRequest(PlayFab::Wrappers::PFMatchmakingSetGameServerInstanceDataRequestWrapper<>& request);

    static void LogSetGameServerInstanceStateRequest(PFMatchmakingSetGameServerInstanceStateRequest const* request, const char* testName);
    static void FillSetGameServerInstanceStateRequest(PlayFab::Wrappers::PFMatchmakingSetGameServerInstanceStateRequestWrapper<>& request);

    static void LogSetGameServerInstanceTagsRequest(PFMatchmakingSetGameServerInstanceTagsRequest const* request, const char* testName);
    static void FillSetGameServerInstanceTagsRequest(PlayFab::Wrappers::PFMatchmakingSetGameServerInstanceTagsRequestWrapper<>& request);

    static void LogCancelAllMatchmakingTicketsForPlayerRequest(PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest const* request, const char* testName);
    static void FillCancelAllMatchmakingTicketsForPlayerRequest(PlayFab::Wrappers::PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper<>& request);

    static void LogCancelAllServerBackfillTicketsForPlayerRequest(PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest const* request, const char* testName);
    static void FillCancelAllServerBackfillTicketsForPlayerRequest(PlayFab::Wrappers::PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper<>& request);

    static void LogCancelMatchmakingTicketRequest(PFMatchmakingCancelMatchmakingTicketRequest const* request, const char* testName);
    static void FillCancelMatchmakingTicketRequest(PlayFab::Wrappers::PFMatchmakingCancelMatchmakingTicketRequestWrapper<>& request);

    static void LogCancelServerBackfillTicketRequest(PFMatchmakingCancelServerBackfillTicketRequest const* request, const char* testName);
    static void FillCancelServerBackfillTicketRequest(PlayFab::Wrappers::PFMatchmakingCancelServerBackfillTicketRequestWrapper<>& request);

    static void LogCreateMatchmakingTicketRequest(PFMatchmakingCreateMatchmakingTicketRequest const* request, const char* testName);
    static void FillCreateMatchmakingTicketRequest(PlayFab::Wrappers::PFMatchmakingCreateMatchmakingTicketRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingCreateMatchmakingTicketResult(PFMatchmakingCreateMatchmakingTicketResult const* result);
    static HRESULT ValidatePFMatchmakingCreateMatchmakingTicketResult(PFMatchmakingCreateMatchmakingTicketResult* result);

    static void LogCreateServerBackfillTicketRequest(PFMatchmakingCreateServerBackfillTicketRequest const* request, const char* testName);
    static void FillCreateServerBackfillTicketRequest(PlayFab::Wrappers::PFMatchmakingCreateServerBackfillTicketRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingCreateServerBackfillTicketResult(PFMatchmakingCreateServerBackfillTicketResult const* result);
    static HRESULT ValidatePFMatchmakingCreateServerBackfillTicketResult(PFMatchmakingCreateServerBackfillTicketResult* result);

    static void LogCreateServerMatchmakingTicketRequest(PFMatchmakingCreateServerMatchmakingTicketRequest const* request, const char* testName);
    static void FillCreateServerMatchmakingTicketRequest(PlayFab::Wrappers::PFMatchmakingCreateServerMatchmakingTicketRequestWrapper<>& request);

    static void LogGetMatchRequest(PFMatchmakingGetMatchRequest const* request, const char* testName);
    static void FillGetMatchRequest(PlayFab::Wrappers::PFMatchmakingGetMatchRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingGetMatchResult(PFMatchmakingGetMatchResult const* result);
    static HRESULT ValidatePFMatchmakingGetMatchResult(PFMatchmakingGetMatchResult* result);

    static void LogGetMatchmakingTicketRequest(PFMatchmakingGetMatchmakingTicketRequest const* request, const char* testName);
    static void FillGetMatchmakingTicketRequest(PlayFab::Wrappers::PFMatchmakingGetMatchmakingTicketRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingGetMatchmakingTicketResult(PFMatchmakingGetMatchmakingTicketResult const* result);
    static HRESULT ValidatePFMatchmakingGetMatchmakingTicketResult(PFMatchmakingGetMatchmakingTicketResult* result);

    static void LogGetQueueStatisticsRequest(PFMatchmakingGetQueueStatisticsRequest const* request, const char* testName);
    static void FillGetQueueStatisticsRequest(PlayFab::Wrappers::PFMatchmakingGetQueueStatisticsRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingGetQueueStatisticsResult(PFMatchmakingGetQueueStatisticsResult const* result);
    static HRESULT ValidatePFMatchmakingGetQueueStatisticsResult(PFMatchmakingGetQueueStatisticsResult* result);

    static void LogGetServerBackfillTicketRequest(PFMatchmakingGetServerBackfillTicketRequest const* request, const char* testName);
    static void FillGetServerBackfillTicketRequest(PlayFab::Wrappers::PFMatchmakingGetServerBackfillTicketRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingGetServerBackfillTicketResult(PFMatchmakingGetServerBackfillTicketResult const* result);
    static HRESULT ValidatePFMatchmakingGetServerBackfillTicketResult(PFMatchmakingGetServerBackfillTicketResult* result);

    static void LogJoinMatchmakingTicketRequest(PFMatchmakingJoinMatchmakingTicketRequest const* request, const char* testName);
    static void FillJoinMatchmakingTicketRequest(PlayFab::Wrappers::PFMatchmakingJoinMatchmakingTicketRequestWrapper<>& request);

    static void LogListMatchmakingTicketsForPlayerRequest(PFMatchmakingListMatchmakingTicketsForPlayerRequest const* request, const char* testName);
    static void FillListMatchmakingTicketsForPlayerRequest(PlayFab::Wrappers::PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingListMatchmakingTicketsForPlayerResult(PFMatchmakingListMatchmakingTicketsForPlayerResult const* result);
    static HRESULT ValidatePFMatchmakingListMatchmakingTicketsForPlayerResult(PFMatchmakingListMatchmakingTicketsForPlayerResult* result);

    static void LogListServerBackfillTicketsForPlayerRequest(PFMatchmakingListServerBackfillTicketsForPlayerRequest const* request, const char* testName);
    static void FillListServerBackfillTicketsForPlayerRequest(PlayFab::Wrappers::PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper<>& request);
    static HRESULT LogPFMatchmakingListServerBackfillTicketsForPlayerResult(PFMatchmakingListServerBackfillTicketsForPlayerResult const* result);
    static HRESULT ValidatePFMatchmakingListServerBackfillTicketsForPlayerResult(PFMatchmakingListServerBackfillTicketsForPlayerResult* result);

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
