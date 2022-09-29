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
    static void LogGetPlayerTagsRequest(PFEventsGetPlayerTagsRequest const* request, const char* testName);
    static HRESULT LogGetPlayerTagsResult(PFEventsGetPlayerTagsResult const* result);
    static void LogRemovePlayerTagRequest(PFEventsRemovePlayerTagRequest const* request, const char* testName);
    static void LogWriteClientCharacterEventRequest(PFEventsWriteClientCharacterEventRequest const* request, const char* testName);
    static HRESULT LogWriteEventResponse(PFEventsWriteEventResponse const* result);
    static void LogWriteClientPlayerEventRequest(PFEventsWriteClientPlayerEventRequest const* request, const char* testName);
    static void LogWriteTitleEventRequest(PFEventsWriteTitleEventRequest const* request, const char* testName);
    static void LogWriteServerCharacterEventRequest(PFEventsWriteServerCharacterEventRequest const* request, const char* testName);
    static void LogWriteServerPlayerEventRequest(PFEventsWriteServerPlayerEventRequest const* request, const char* testName);
    static void LogWriteEventsRequest(PFEventsWriteEventsRequest const* request, const char* testName);
    static HRESULT LogWriteEventsResponse(PFEventsWriteEventsResponse const* result);

    void FillAdminAddPlayerTagRequest(PlayFab::Wrappers::PFEventsAddPlayerTagRequestWrapper<>& request);

    void FillAdminGetPlayerTagsRequest(PlayFab::Wrappers::PFEventsGetPlayerTagsRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPlayerTagsResponse(PFEventsGetPlayerTagsResult* result);

    void FillAdminRemovePlayerTagRequest(PlayFab::Wrappers::PFEventsRemovePlayerTagRequestWrapper<>& request);

    void FillClientGetPlayerTagsRequest(PlayFab::Wrappers::PFEventsGetPlayerTagsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayerTagsResponse(PFEventsGetPlayerTagsResult* result);

    void FillClientWriteCharacterEventRequest(PlayFab::Wrappers::PFEventsWriteClientCharacterEventRequestWrapper<>& request);
    static HRESULT ValidateClientWriteCharacterEventResponse(PFEventsWriteEventResponse* result);

    void FillClientWritePlayerEventRequest(PlayFab::Wrappers::PFEventsWriteClientPlayerEventRequestWrapper<>& request);
    static HRESULT ValidateClientWritePlayerEventResponse(PFEventsWriteEventResponse* result);

    void FillClientWriteTitleEventRequest(PlayFab::Wrappers::PFEventsWriteTitleEventRequestWrapper<>& request);
    static HRESULT ValidateClientWriteTitleEventResponse(PFEventsWriteEventResponse* result);

    void FillServerAddPlayerTagRequest(PlayFab::Wrappers::PFEventsAddPlayerTagRequestWrapper<>& request);

    void FillServerGetPlayerTagsRequest(PlayFab::Wrappers::PFEventsGetPlayerTagsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayerTagsResponse(PFEventsGetPlayerTagsResult* result);

    void FillServerRemovePlayerTagRequest(PlayFab::Wrappers::PFEventsRemovePlayerTagRequestWrapper<>& request);

    void FillServerWriteCharacterEventRequest(PlayFab::Wrappers::PFEventsWriteServerCharacterEventRequestWrapper<>& request);
    static HRESULT ValidateServerWriteCharacterEventResponse(PFEventsWriteEventResponse* result);

    void FillServerWritePlayerEventRequest(PlayFab::Wrappers::PFEventsWriteServerPlayerEventRequestWrapper<>& request);
    static HRESULT ValidateServerWritePlayerEventResponse(PFEventsWriteEventResponse* result);

    void FillServerWriteTitleEventRequest(PlayFab::Wrappers::PFEventsWriteTitleEventRequestWrapper<>& request);
    static HRESULT ValidateServerWriteTitleEventResponse(PFEventsWriteEventResponse* result);

    void FillWriteEventsRequest(PlayFab::Wrappers::PFEventsWriteEventsRequestWrapper<>& request);
    static HRESULT ValidateWriteEventsResponse(PFEventsWriteEventsResponse* result);

    void FillWriteTelemetryEventsRequest(PlayFab::Wrappers::PFEventsWriteEventsRequestWrapper<>& request);
    static HRESULT ValidateWriteTelemetryEventsResponse(PFEventsWriteEventsResponse* result);

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
