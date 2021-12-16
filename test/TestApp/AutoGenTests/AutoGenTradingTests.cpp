#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenTradingTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenTradingTests::TradingTestData AutoGenTradingTests::testData;

void AutoGenTradingTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenTradingTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenTradingTests::AddTests()
{
    // Generated tests 
    AddTest("TestTradingClientAcceptTrade", &AutoGenTradingTests::TestTradingClientAcceptTrade);

    AddTest("TestTradingClientCancelTrade", &AutoGenTradingTests::TestTradingClientCancelTrade);

    AddTest("TestTradingClientGetPlayerTrades", &AutoGenTradingTests::TestTradingClientGetPlayerTrades);

    AddTest("TestTradingClientGetTradeStatus", &AutoGenTradingTests::TestTradingClientGetTradeStatus);

    AddTest("TestTradingClientOpenTrade", &AutoGenTradingTests::TestTradingClientOpenTrade);
}

void AutoGenTradingTests::ClassSetUp()
{
    HRESULT hr = PFAdminInitialize(testTitleData.titleId.data(), testTitleData.developerSecretKey.data(), nullptr, &stateHandle);
    assert(SUCCEEDED(hr));
    if (SUCCEEDED(hr))
    {
        PFAuthenticationLoginWithCustomIDRequest request{};
        request.customId = "CustomId";
        request.createAccount = true;

        PFGetPlayerCombinedInfoRequestParams combinedInfoRequestParams{};
        combinedInfoRequestParams.getCharacterInventories = true;
        combinedInfoRequestParams.getCharacterList = true;
        combinedInfoRequestParams.getPlayerProfile = true;
        combinedInfoRequestParams.getPlayerStatistics = true;
        combinedInfoRequestParams.getTitleData = true;
        combinedInfoRequestParams.getUserAccountInfo = true;
        combinedInfoRequestParams.getUserData = true;
        combinedInfoRequestParams.getUserInventory = true;
        combinedInfoRequestParams.getUserReadOnlyData = true;
        combinedInfoRequestParams.getUserVirtualCurrency = true;
        request.infoRequestParameters = &combinedInfoRequestParams;

        XAsyncBlock async{};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle);
                assert(SUCCEEDED(hr) && titlePlayerHandle);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle, &entityHandle);
                assert(SUCCEEDED(hr) && entityHandle);
            }
        }

        request.customId = "CustomId2";
        async = {};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously what for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle2);
                assert(SUCCEEDED(hr) && titlePlayerHandle2);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle2, &entityHandle2);
                assert(SUCCEEDED(hr) && entityHandle2);
            }
        }

        PFAuthenticationGetEntityTokenRequest titleTokenRequest{};
        async = {};
        hr = PFAuthenticationGetEntityTokenAsync(stateHandle, &titleTokenRequest, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationGetEntityTokenGetResult(&async, &titleEntityHandle);
                assert(SUCCEEDED(hr));
            }
        }
    }
}

void AutoGenTradingTests::ClassTearDown()
{
    PFTitlePlayerCloseHandle(titlePlayerHandle);
    PFEntityCloseHandle(entityHandle);
    PFEntityCloseHandle(titleEntityHandle);

    XAsyncBlock async{};
    HRESULT hr = PFUninitializeAsync(stateHandle, &async);
    assert(SUCCEEDED(hr));

    hr = XAsyncGetStatus(&async, true);
    assert(SUCCEEDED(hr));

    UNREFERENCED_PARAMETER(hr);
}

void AutoGenTradingTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region ClientAcceptTrade

void AutoGenTradingTests::TestTradingClientAcceptTrade(TestContext& testContext)
{
    struct ClientAcceptTradeResultHolderStruct : public AcceptTradeResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTradingClientAcceptTradeGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTradingClientAcceptTradeGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTradingAcceptTradeResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTradingAcceptTradeResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientAcceptTradeResultHolderStruct>>(testContext);

    PFTradingAcceptTradeRequestWrapper<> request;
    FillAcceptTradeRequest(request);
    LogAcceptTradeRequest(&request.Model(), "TestTradingClientAcceptTrade");
    HRESULT hr = PFTradingClientAcceptTradeAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTradingTradingClientAcceptTradeAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientCancelTrade

void AutoGenTradingTests::TestTradingClientCancelTrade(TestContext& testContext)
{
    struct ClientCancelTradeResultHolderStruct : public CancelTradeResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTradingClientCancelTradeGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTradingClientCancelTradeGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTradingCancelTradeResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTradingCancelTradeResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientCancelTradeResultHolderStruct>>(testContext);

    PFTradingCancelTradeRequestWrapper<> request;
    FillCancelTradeRequest(request);
    LogCancelTradeRequest(&request.Model(), "TestTradingClientCancelTrade");
    HRESULT hr = PFTradingClientCancelTradeAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTradingTradingClientCancelTradeAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayerTrades

void AutoGenTradingTests::TestTradingClientGetPlayerTrades(TestContext& testContext)
{
    struct ClientGetPlayerTradesResultHolderStruct : public GetPlayerTradesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTradingClientGetPlayerTradesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTradingClientGetPlayerTradesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTradingGetPlayerTradesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTradingGetPlayerTradesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerTradesResultHolderStruct>>(testContext);

    PFTradingGetPlayerTradesRequestWrapper<> request;
    FillGetPlayerTradesRequest(request);
    LogGetPlayerTradesRequest(&request.Model(), "TestTradingClientGetPlayerTrades");
    HRESULT hr = PFTradingClientGetPlayerTradesAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTradingTradingClientGetPlayerTradesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetTradeStatus

void AutoGenTradingTests::TestTradingClientGetTradeStatus(TestContext& testContext)
{
    struct ClientGetTradeStatusResultHolderStruct : public GetTradeStatusResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTradingClientGetTradeStatusGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTradingClientGetTradeStatusGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTradingGetTradeStatusResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTradingGetTradeStatusResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetTradeStatusResultHolderStruct>>(testContext);

    PFTradingGetTradeStatusRequestWrapper<> request;
    FillGetTradeStatusRequest(request);
    LogGetTradeStatusRequest(&request.Model(), "TestTradingClientGetTradeStatus");
    HRESULT hr = PFTradingClientGetTradeStatusAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTradingTradingClientGetTradeStatusAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientOpenTrade

void AutoGenTradingTests::TestTradingClientOpenTrade(TestContext& testContext)
{
    struct ClientOpenTradeResultHolderStruct : public OpenTradeResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTradingClientOpenTradeGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTradingClientOpenTradeGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTradingOpenTradeResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTradingOpenTradeResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientOpenTradeResultHolderStruct>>(testContext);

    PFTradingOpenTradeRequestWrapper<> request;
    FillOpenTradeRequest(request);
    LogOpenTradeRequest(&request.Model(), "TestTradingClientOpenTrade");
    HRESULT hr = PFTradingClientOpenTradeAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTradingTradingClientOpenTradeAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
