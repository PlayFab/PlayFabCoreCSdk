#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFAdvertisingDataModelWrappers.h>
#include "AutoGenAdvertisingResultHolders.h"

namespace PlayFabUnit
{

class AutoGenAdvertisingTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAdvertisingClientAttributeInstall(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAdvertisingClientGetAdPlacements(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAdvertisingClientReportAdActivity(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAdvertisingClientRewardAdActivity(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogAttributeInstallRequest(PFAdvertisingAttributeInstallRequest const* request, const char* testName);
    static void FillAttributeInstallRequest(PlayFab::Wrappers::PFAdvertisingAttributeInstallRequestWrapper<>& request);

    static void LogGetAdPlacementsRequest(PFAdvertisingGetAdPlacementsRequest const* request, const char* testName);
    static void FillGetAdPlacementsRequest(PlayFab::Wrappers::PFAdvertisingGetAdPlacementsRequestWrapper<>& request);
    static HRESULT LogPFAdvertisingGetAdPlacementsResult(PFAdvertisingGetAdPlacementsResult const* result);
    static HRESULT ValidatePFAdvertisingGetAdPlacementsResult(PFAdvertisingGetAdPlacementsResult* result);

    static void LogReportAdActivityRequest(PFAdvertisingReportAdActivityRequest const* request, const char* testName);
    static void FillReportAdActivityRequest(PlayFab::Wrappers::PFAdvertisingReportAdActivityRequestWrapper<>& request);

    static void LogRewardAdActivityRequest(PFAdvertisingRewardAdActivityRequest const* request, const char* testName);
    static void FillRewardAdActivityRequest(PlayFab::Wrappers::PFAdvertisingRewardAdActivityRequestWrapper<>& request);
    static HRESULT LogPFAdvertisingRewardAdActivityResult(PFAdvertisingRewardAdActivityResult const* result);
    static HRESULT ValidatePFAdvertisingRewardAdActivityResult(PFAdvertisingRewardAdActivityResult* result);

    struct AdvertisingTestData
    {
        ~AdvertisingTestData() = default;

    };

    static AdvertisingTestData testData;

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
