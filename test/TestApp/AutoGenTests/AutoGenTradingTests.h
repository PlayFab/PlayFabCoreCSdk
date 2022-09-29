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
    static HRESULT LogAcceptTradeResponse(PFTradingAcceptTradeResponse const* result);
    static void LogCancelTradeRequest(PFTradingCancelTradeRequest const* request, const char* testName);
    static HRESULT LogCancelTradeResponse(PFTradingCancelTradeResponse const* result);
    static void LogGetPlayerTradesRequest(PFTradingGetPlayerTradesRequest const* request, const char* testName);
    static HRESULT LogGetPlayerTradesResponse(PFTradingGetPlayerTradesResponse const* result);
    static void LogGetTradeStatusRequest(PFTradingGetTradeStatusRequest const* request, const char* testName);
    static HRESULT LogGetTradeStatusResponse(PFTradingGetTradeStatusResponse const* result);
    static void LogOpenTradeRequest(PFTradingOpenTradeRequest const* request, const char* testName);
    static HRESULT LogOpenTradeResponse(PFTradingOpenTradeResponse const* result);

    void FillClientAcceptTradeRequest(PlayFab::Wrappers::PFTradingAcceptTradeRequestWrapper<>& request);
    static HRESULT ValidateClientAcceptTradeResponse(PFTradingAcceptTradeResponse* result);

    void FillClientCancelTradeRequest(PlayFab::Wrappers::PFTradingCancelTradeRequestWrapper<>& request);
    static HRESULT ValidateClientCancelTradeResponse(PFTradingCancelTradeResponse* result);

    void FillClientGetPlayerTradesRequest(PlayFab::Wrappers::PFTradingGetPlayerTradesRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayerTradesResponse(PFTradingGetPlayerTradesResponse* result);

    void FillClientGetTradeStatusRequest(PlayFab::Wrappers::PFTradingGetTradeStatusRequestWrapper<>& request);
    static HRESULT ValidateClientGetTradeStatusResponse(PFTradingGetTradeStatusResponse* result);

    void FillClientOpenTradeRequest(PlayFab::Wrappers::PFTradingOpenTradeRequestWrapper<>& request);
    static HRESULT ValidateClientOpenTradeResponse(PFTradingOpenTradeResponse* result);

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
