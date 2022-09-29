#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFEconomyDataModelWrappers.h>
#include "AutoGenEconomyResultHolders.h"

namespace PlayFabUnit
{

class AutoGenEconomyTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestEconomyAdminRefundPurchase(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestEconomyAdminResolvePurchaseDispute(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogRefundPurchaseRequest(PFEconomyRefundPurchaseRequest const* request, const char* testName);
    static HRESULT LogRefundPurchaseResponse(PFEconomyRefundPurchaseResponse const* result);
    static void LogResolvePurchaseDisputeRequest(PFEconomyResolvePurchaseDisputeRequest const* request, const char* testName);
    static HRESULT LogResolvePurchaseDisputeResponse(PFEconomyResolvePurchaseDisputeResponse const* result);

    void FillAdminRefundPurchaseRequest(PlayFab::Wrappers::PFEconomyRefundPurchaseRequestWrapper<>& request);
    static HRESULT ValidateAdminRefundPurchaseResponse(PFEconomyRefundPurchaseResponse* result);

    void FillAdminResolvePurchaseDisputeRequest(PlayFab::Wrappers::PFEconomyResolvePurchaseDisputeRequestWrapper<>& request);
    static HRESULT ValidateAdminResolvePurchaseDisputeResponse(PFEconomyResolvePurchaseDisputeResponse* result);

    struct EconomyTestData
    {
        ~EconomyTestData() = default;

    };

    static EconomyTestData testData;

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
