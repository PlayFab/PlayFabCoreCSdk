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

    void TestEventsWriteEvents(TestContext& testContext);


protected:
    void AddTests();

    static void LogWriteEventsRequest(PFEventsWriteEventsRequest const* request, const char* testName);
    static HRESULT LogWriteEventsResponse(PFEventsWriteEventsResponse const* result);

    static void FillWriteEventsRequest(PlayFab::Wrappers::PFEventsWriteEventsRequestWrapper<>& request);
    static HRESULT ValidateWriteEventsResponse(PFEventsWriteEventsResponse* result);

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
