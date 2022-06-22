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
