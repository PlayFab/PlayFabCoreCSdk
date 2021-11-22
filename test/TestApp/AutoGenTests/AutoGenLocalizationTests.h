#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFLocalizationDataModelWrappers.h>
#include "AutoGenLocalizationResultHolders.h"

namespace PlayFabUnit
{

class AutoGenLocalizationTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestLocalizationGetLanguageList(TestContext& testContext);


protected:
    void AddTests();

    static void LogGetLanguageListRequest(PFLocalizationGetLanguageListRequest const* request, const char* testName);
    static void FillGetLanguageListRequest(PlayFab::Wrappers::PFLocalizationGetLanguageListRequestWrapper<>& request);
    static HRESULT LogPFLocalizationGetLanguageListResponse(PFLocalizationGetLanguageListResponse const* result);
    static HRESULT ValidatePFLocalizationGetLanguageListResponse(PFLocalizationGetLanguageListResponse* result);

    struct LocalizationTestData
    {
        ~LocalizationTestData() = default;

    };

    static LocalizationTestData testData;

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
