#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFTradingDataModelWrappers.h>
#include "AutoGenTradingResultHolders.h"

namespace PlayFabUnit
{

class AutoGenTradingTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestTradingClientAcceptTrade(TestContext& testContext);

    void TestTradingClientCancelTrade(TestContext& testContext);

    void TestTradingClientGetPlayerTrades(TestContext& testContext);

    void TestTradingClientGetTradeStatus(TestContext& testContext);

    void TestTradingClientOpenTrade(TestContext& testContext);


protected:
    void AddTests();

    static void LogAcceptTradeRequest(PFTradingAcceptTradeRequest const* request, const char* testName);
    static void FillAcceptTradeRequest(PlayFab::Wrappers::PFTradingAcceptTradeRequestWrapper<>& request);
    static HRESULT LogPFTradingAcceptTradeResponse(PFTradingAcceptTradeResponse const* result);
    static HRESULT ValidatePFTradingAcceptTradeResponse(PFTradingAcceptTradeResponse* result);

    static void LogCancelTradeRequest(PFTradingCancelTradeRequest const* request, const char* testName);
    static void FillCancelTradeRequest(PlayFab::Wrappers::PFTradingCancelTradeRequestWrapper<>& request);
    static HRESULT LogPFTradingCancelTradeResponse(PFTradingCancelTradeResponse const* result);
    static HRESULT ValidatePFTradingCancelTradeResponse(PFTradingCancelTradeResponse* result);

    static void LogGetPlayerTradesRequest(PFTradingGetPlayerTradesRequest const* request, const char* testName);
    static void FillGetPlayerTradesRequest(PlayFab::Wrappers::PFTradingGetPlayerTradesRequestWrapper<>& request);
    static HRESULT LogPFTradingGetPlayerTradesResponse(PFTradingGetPlayerTradesResponse const* result);
    static HRESULT ValidatePFTradingGetPlayerTradesResponse(PFTradingGetPlayerTradesResponse* result);

    static void LogGetTradeStatusRequest(PFTradingGetTradeStatusRequest const* request, const char* testName);
    static void FillGetTradeStatusRequest(PlayFab::Wrappers::PFTradingGetTradeStatusRequestWrapper<>& request);
    static HRESULT LogPFTradingGetTradeStatusResponse(PFTradingGetTradeStatusResponse const* result);
    static HRESULT ValidatePFTradingGetTradeStatusResponse(PFTradingGetTradeStatusResponse* result);

    static void LogOpenTradeRequest(PFTradingOpenTradeRequest const* request, const char* testName);
    static void FillOpenTradeRequest(PlayFab::Wrappers::PFTradingOpenTradeRequestWrapper<>& request);
    static HRESULT LogPFTradingOpenTradeResponse(PFTradingOpenTradeResponse const* result);
    static HRESULT ValidatePFTradingOpenTradeResponse(PFTradingOpenTradeResponse* result);

    struct TradingTestData
    {
        ~TradingTestData() = default;

    };

    static TradingTestData testData;

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
