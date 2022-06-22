#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenMultiplayerServerTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenMultiplayerServerTests::MultiplayerServerTestData AutoGenMultiplayerServerTests::testData;

void AutoGenMultiplayerServerTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenMultiplayerServerTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenMultiplayerServerTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerCreateRemoteUser", &AutoGenMultiplayerServerTests::TestMultiplayerServerCreateRemoteUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerDeleteCertificate", &AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteCertificate);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerDeleteRemoteUser", &AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteRemoteUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerGetMultiplayerServerDetails", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetMultiplayerServerDetails);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerGetMultiplayerServerLogs", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetMultiplayerServerLogs);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerGetMultiplayerSessionLogsBySessionId", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetMultiplayerSessionLogsBySessionId);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerGetRemoteLoginEndpoint", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetRemoteLoginEndpoint);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListArchivedMultiplayerServers", &AutoGenMultiplayerServerTests::TestMultiplayerServerListArchivedMultiplayerServers);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListBuildAliases", &AutoGenMultiplayerServerTests::TestMultiplayerServerListBuildAliases);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListBuildSummariesV2", &AutoGenMultiplayerServerTests::TestMultiplayerServerListBuildSummariesV2);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListCertificateSummaries", &AutoGenMultiplayerServerTests::TestMultiplayerServerListCertificateSummaries);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListMultiplayerServers", &AutoGenMultiplayerServerTests::TestMultiplayerServerListMultiplayerServers);
#endif

    AddTest("TestMultiplayerServerListPartyQosServers", &AutoGenMultiplayerServerTests::TestMultiplayerServerListPartyQosServers);

    AddTest("TestMultiplayerServerListQosServersForTitle", &AutoGenMultiplayerServerTests::TestMultiplayerServerListQosServersForTitle);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListVirtualMachineSummaries", &AutoGenMultiplayerServerTests::TestMultiplayerServerListVirtualMachineSummaries);
#endif

    AddTest("TestMultiplayerServerRequestMultiplayerServer", &AutoGenMultiplayerServerTests::TestMultiplayerServerRequestMultiplayerServer);

    AddTest("TestMultiplayerServerShutdownMultiplayerServer", &AutoGenMultiplayerServerTests::TestMultiplayerServerShutdownMultiplayerServer);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerUploadCertificate", &AutoGenMultiplayerServerTests::TestMultiplayerServerUploadCertificate);
#endif
}

void AutoGenMultiplayerServerTests::ClassSetUp()
{
    HRESULT hr = PFAdminInitialize(testTitleData.titleId.data(), testTitleData.developerSecretKey.data(), testTitleData.connectionString.data(), nullptr, &stateHandle);
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

void AutoGenMultiplayerServerTests::ClassTearDown()
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

void AutoGenMultiplayerServerTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region CreateRemoteUser

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerCreateRemoteUser(TestContext& testContext)
{
    struct CreateRemoteUserResultHolderStruct : public CreateRemoteUserResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateRemoteUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateRemoteUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogCreateRemoteUserResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateCreateRemoteUserResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateRemoteUserResultHolderStruct>>(testContext);

    PFMultiplayerServerCreateRemoteUserRequestWrapper<> request;
    FillCreateRemoteUserRequest(request);
    LogCreateRemoteUserRequest(&request.Model(), "TestMultiplayerServerCreateRemoteUser");
    HRESULT hr = PFMultiplayerServerCreateRemoteUserAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerCreateRemoteUserAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region DeleteCertificate

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteCertificate(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerDeleteCertificateRequestWrapper<> request;
    FillDeleteCertificateRequest(request);
    LogDeleteCertificateRequest(&request.Model(), "TestMultiplayerServerDeleteCertificate");
    HRESULT hr = PFMultiplayerServerDeleteCertificateAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerDeleteCertificateAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region DeleteRemoteUser

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteRemoteUser(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerDeleteRemoteUserRequestWrapper<> request;
    FillDeleteRemoteUserRequest(request);
    LogDeleteRemoteUserRequest(&request.Model(), "TestMultiplayerServerDeleteRemoteUser");
    HRESULT hr = PFMultiplayerServerDeleteRemoteUserAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerDeleteRemoteUserAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetMultiplayerServerDetails

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerGetMultiplayerServerDetails(TestContext& testContext)
{
    struct GetMultiplayerServerDetailsResultHolderStruct : public GetMultiplayerServerDetailsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetMultiplayerServerDetailsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetMultiplayerServerDetailsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetMultiplayerServerDetailsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetMultiplayerServerDetailsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetMultiplayerServerDetailsResultHolderStruct>>(testContext);

    PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper<> request;
    FillGetMultiplayerServerDetailsRequest(request);
    LogGetMultiplayerServerDetailsRequest(&request.Model(), "TestMultiplayerServerGetMultiplayerServerDetails");
    HRESULT hr = PFMultiplayerServerGetMultiplayerServerDetailsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetMultiplayerServerDetailsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetMultiplayerServerLogs

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerGetMultiplayerServerLogs(TestContext& testContext)
{
    struct GetMultiplayerServerLogsResultHolderStruct : public GetMultiplayerServerLogsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetMultiplayerServerLogsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetMultiplayerServerLogsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetMultiplayerServerLogsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetMultiplayerServerLogsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetMultiplayerServerLogsResultHolderStruct>>(testContext);

    PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper<> request;
    FillGetMultiplayerServerLogsRequest(request);
    LogGetMultiplayerServerLogsRequest(&request.Model(), "TestMultiplayerServerGetMultiplayerServerLogs");
    HRESULT hr = PFMultiplayerServerGetMultiplayerServerLogsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetMultiplayerServerLogsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetMultiplayerSessionLogsBySessionId

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerGetMultiplayerSessionLogsBySessionId(TestContext& testContext)
{
    struct GetMultiplayerSessionLogsBySessionIdResultHolderStruct : public GetMultiplayerServerLogsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetMultiplayerServerLogsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetMultiplayerSessionLogsBySessionIdResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetMultiplayerSessionLogsBySessionIdResultHolderStruct>>(testContext);

    PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper<> request;
    FillGetMultiplayerSessionLogsBySessionIdRequest(request);
    LogGetMultiplayerSessionLogsBySessionIdRequest(&request.Model(), "TestMultiplayerServerGetMultiplayerSessionLogsBySessionId");
    HRESULT hr = PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetMultiplayerSessionLogsBySessionIdAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetRemoteLoginEndpoint

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerGetRemoteLoginEndpoint(TestContext& testContext)
{
    struct GetRemoteLoginEndpointResultHolderStruct : public GetRemoteLoginEndpointResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetRemoteLoginEndpointGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetRemoteLoginEndpointGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetRemoteLoginEndpointResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetRemoteLoginEndpointResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetRemoteLoginEndpointResultHolderStruct>>(testContext);

    PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper<> request;
    FillGetRemoteLoginEndpointRequest(request);
    LogGetRemoteLoginEndpointRequest(&request.Model(), "TestMultiplayerServerGetRemoteLoginEndpoint");
    HRESULT hr = PFMultiplayerServerGetRemoteLoginEndpointAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetRemoteLoginEndpointAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ListArchivedMultiplayerServers

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerListArchivedMultiplayerServers(TestContext& testContext)
{
    struct ListArchivedMultiplayerServersResultHolderStruct : public ListMultiplayerServersResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListArchivedMultiplayerServersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListArchivedMultiplayerServersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListMultiplayerServersResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListArchivedMultiplayerServersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListArchivedMultiplayerServersResultHolderStruct>>(testContext);

    PFMultiplayerServerListMultiplayerServersRequestWrapper<> request;
    FillListArchivedMultiplayerServersRequest(request);
    LogListMultiplayerServersRequest(&request.Model(), "TestMultiplayerServerListArchivedMultiplayerServers");
    HRESULT hr = PFMultiplayerServerListArchivedMultiplayerServersAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListArchivedMultiplayerServersAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ListBuildAliases

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerListBuildAliases(TestContext& testContext)
{
    struct ListBuildAliasesResultHolderStruct : public ListBuildAliasesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListBuildAliasesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListBuildAliasesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListBuildAliasesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListBuildAliasesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListBuildAliasesResultHolderStruct>>(testContext);

    PFMultiplayerServerListBuildAliasesRequestWrapper<> request;
    FillListBuildAliasesRequest(request);
    LogListBuildAliasesRequest(&request.Model(), "TestMultiplayerServerListBuildAliases");
    HRESULT hr = PFMultiplayerServerListBuildAliasesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListBuildAliasesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ListBuildSummariesV2

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerListBuildSummariesV2(TestContext& testContext)
{
    struct ListBuildSummariesV2ResultHolderStruct : public ListBuildSummariesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListBuildSummariesV2GetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListBuildSummariesV2GetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListBuildSummariesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListBuildSummariesV2Response(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListBuildSummariesV2ResultHolderStruct>>(testContext);

    PFMultiplayerServerListBuildSummariesRequestWrapper<> request;
    FillListBuildSummariesV2Request(request);
    LogListBuildSummariesRequest(&request.Model(), "TestMultiplayerServerListBuildSummariesV2");
    HRESULT hr = PFMultiplayerServerListBuildSummariesV2Async(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListBuildSummariesV2Async", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ListCertificateSummaries

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerListCertificateSummaries(TestContext& testContext)
{
    struct ListCertificateSummariesResultHolderStruct : public ListCertificateSummariesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListCertificateSummariesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListCertificateSummariesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListCertificateSummariesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListCertificateSummariesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListCertificateSummariesResultHolderStruct>>(testContext);

    PFMultiplayerServerListCertificateSummariesRequestWrapper<> request;
    FillListCertificateSummariesRequest(request);
    LogListCertificateSummariesRequest(&request.Model(), "TestMultiplayerServerListCertificateSummaries");
    HRESULT hr = PFMultiplayerServerListCertificateSummariesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListCertificateSummariesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ListMultiplayerServers

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerListMultiplayerServers(TestContext& testContext)
{
    struct ListMultiplayerServersResultHolderStruct : public ListMultiplayerServersResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListMultiplayerServersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListMultiplayerServersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListMultiplayerServersResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListMultiplayerServersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListMultiplayerServersResultHolderStruct>>(testContext);

    PFMultiplayerServerListMultiplayerServersRequestWrapper<> request;
    FillListMultiplayerServersRequest(request);
    LogListMultiplayerServersRequest(&request.Model(), "TestMultiplayerServerListMultiplayerServers");
    HRESULT hr = PFMultiplayerServerListMultiplayerServersAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListMultiplayerServersAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ListPartyQosServers

void AutoGenMultiplayerServerTests::TestMultiplayerServerListPartyQosServers(TestContext& testContext)
{
    struct ListPartyQosServersResultHolderStruct : public ListPartyQosServersResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListPartyQosServersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListPartyQosServersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListPartyQosServersResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListPartyQosServersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListPartyQosServersResultHolderStruct>>(testContext);

    PFMultiplayerServerListPartyQosServersRequestWrapper<> request;
    FillListPartyQosServersRequest(request);
    LogListPartyQosServersRequest(&request.Model(), "TestMultiplayerServerListPartyQosServers");
    HRESULT hr = PFMultiplayerServerListPartyQosServersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListPartyQosServersAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListQosServersForTitle

void AutoGenMultiplayerServerTests::TestMultiplayerServerListQosServersForTitle(TestContext& testContext)
{
    struct ListQosServersForTitleResultHolderStruct : public ListQosServersForTitleResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListQosServersForTitleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListQosServersForTitleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListQosServersForTitleResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListQosServersForTitleResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListQosServersForTitleResultHolderStruct>>(testContext);

    PFMultiplayerServerListQosServersForTitleRequestWrapper<> request;
    FillListQosServersForTitleRequest(request);
    LogListQosServersForTitleRequest(&request.Model(), "TestMultiplayerServerListQosServersForTitle");
    HRESULT hr = PFMultiplayerServerListQosServersForTitleAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListQosServersForTitleAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListVirtualMachineSummaries

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerListVirtualMachineSummaries(TestContext& testContext)
{
    struct ListVirtualMachineSummariesResultHolderStruct : public ListVirtualMachineSummariesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListVirtualMachineSummariesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListVirtualMachineSummariesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListVirtualMachineSummariesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListVirtualMachineSummariesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListVirtualMachineSummariesResultHolderStruct>>(testContext);

    PFMultiplayerServerListVirtualMachineSummariesRequestWrapper<> request;
    FillListVirtualMachineSummariesRequest(request);
    LogListVirtualMachineSummariesRequest(&request.Model(), "TestMultiplayerServerListVirtualMachineSummaries");
    HRESULT hr = PFMultiplayerServerListVirtualMachineSummariesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListVirtualMachineSummariesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region RequestMultiplayerServer

void AutoGenMultiplayerServerTests::TestMultiplayerServerRequestMultiplayerServer(TestContext& testContext)
{
    struct RequestMultiplayerServerResultHolderStruct : public RequestMultiplayerServerResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerRequestMultiplayerServerGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerRequestMultiplayerServerGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRequestMultiplayerServerResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateRequestMultiplayerServerResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<RequestMultiplayerServerResultHolderStruct>>(testContext);

    PFMultiplayerServerRequestMultiplayerServerRequestWrapper<> request;
    FillRequestMultiplayerServerRequest(request);
    LogRequestMultiplayerServerRequest(&request.Model(), "TestMultiplayerServerRequestMultiplayerServer");
    HRESULT hr = PFMultiplayerServerRequestMultiplayerServerAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerRequestMultiplayerServerAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ShutdownMultiplayerServer

void AutoGenMultiplayerServerTests::TestMultiplayerServerShutdownMultiplayerServer(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerShutdownMultiplayerServerRequestWrapper<> request;
    FillShutdownMultiplayerServerRequest(request);
    LogShutdownMultiplayerServerRequest(&request.Model(), "TestMultiplayerServerShutdownMultiplayerServer");
    HRESULT hr = PFMultiplayerServerShutdownMultiplayerServerAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerShutdownMultiplayerServerAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UploadCertificate

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerUploadCertificate(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerUploadCertificateRequestWrapper<> request;
    FillUploadCertificateRequest(request);
    LogUploadCertificateRequest(&request.Model(), "TestMultiplayerServerUploadCertificate");
    HRESULT hr = PFMultiplayerServerUploadCertificateAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerUploadCertificateAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
