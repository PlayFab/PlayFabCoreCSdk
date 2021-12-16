#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFEventsDataModelWrappers.h>
#include "AutoGenEventsResultHolders.h"

namespace PlayFabUnit
{

class AutoGenEventsTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestEventsAdminAddPlayerTag(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestEventsAdminGetPlayerTags(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestEventsAdminRemovePlayerTag(TestContext& testContext);
#endif

    void TestEventsClientGetPlayerTags(TestContext& testContext);

    void TestEventsClientWriteCharacterEvent(TestContext& testContext);

    void TestEventsClientWritePlayerEvent(TestContext& testContext);

    void TestEventsClientWriteTitleEvent(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestEventsServerAddPlayerTag(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestEventsServerGetPlayerTags(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestEventsServerRemovePlayerTag(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestEventsServerWriteCharacterEvent(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestEventsServerWritePlayerEvent(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestEventsServerWriteTitleEvent(TestContext& testContext);
#endif

    void TestEventsWriteEvents(TestContext& testContext);

    void TestEventsWriteTelemetryEvents(TestContext& testContext);


protected:
    void AddTests();

    static void LogAddPlayerTagRequest(PFEventsAddPlayerTagRequest const* request, const char* testName);
    static void FillAddPlayerTagRequest(PlayFab::Wrappers::PFEventsAddPlayerTagRequestWrapper<>& request);

    static void LogGetPlayerTagsRequest(PFEventsGetPlayerTagsRequest const* request, const char* testName);
    static void FillGetPlayerTagsRequest(PlayFab::Wrappers::PFEventsGetPlayerTagsRequestWrapper<>& request);
    static HRESULT LogPFEventsGetPlayerTagsResult(PFEventsGetPlayerTagsResult const* result);
    static HRESULT ValidatePFEventsGetPlayerTagsResult(PFEventsGetPlayerTagsResult* result);

    static void LogRemovePlayerTagRequest(PFEventsRemovePlayerTagRequest const* request, const char* testName);
    static void FillRemovePlayerTagRequest(PlayFab::Wrappers::PFEventsRemovePlayerTagRequestWrapper<>& request);


    static void LogWriteClientCharacterEventRequest(PFEventsWriteClientCharacterEventRequest const* request, const char* testName);
    static void FillWriteClientCharacterEventRequest(PlayFab::Wrappers::PFEventsWriteClientCharacterEventRequestWrapper<>& request);
    static HRESULT LogPFEventsWriteEventResponse(PFEventsWriteEventResponse const* result);
    static HRESULT ValidatePFEventsWriteEventResponse(PFEventsWriteEventResponse* result);

    static void LogWriteClientPlayerEventRequest(PFEventsWriteClientPlayerEventRequest const* request, const char* testName);
    static void FillWriteClientPlayerEventRequest(PlayFab::Wrappers::PFEventsWriteClientPlayerEventRequestWrapper<>& request);

    static void LogWriteTitleEventRequest(PFEventsWriteTitleEventRequest const* request, const char* testName);
    static void FillWriteTitleEventRequest(PlayFab::Wrappers::PFEventsWriteTitleEventRequestWrapper<>& request);




    static void LogWriteServerCharacterEventRequest(PFEventsWriteServerCharacterEventRequest const* request, const char* testName);
    static void FillWriteServerCharacterEventRequest(PlayFab::Wrappers::PFEventsWriteServerCharacterEventRequestWrapper<>& request);

    static void LogWriteServerPlayerEventRequest(PFEventsWriteServerPlayerEventRequest const* request, const char* testName);
    static void FillWriteServerPlayerEventRequest(PlayFab::Wrappers::PFEventsWriteServerPlayerEventRequestWrapper<>& request);


    static void LogWriteEventsRequest(PFEventsWriteEventsRequest const* request, const char* testName);
    static void FillWriteEventsRequest(PlayFab::Wrappers::PFEventsWriteEventsRequestWrapper<>& request);
    static HRESULT LogPFEventsWriteEventsResponse(PFEventsWriteEventsResponse const* result);
    static HRESULT ValidatePFEventsWriteEventsResponse(PFEventsWriteEventsResponse* result);


    struct EventsTestData
    {
        ~EventsTestData() = default;

    };

    static EventsTestData testData;

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
