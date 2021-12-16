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
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenMultiplayerServerTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerCreateBuildAlias", &AutoGenMultiplayerServerTests::TestMultiplayerServerCreateBuildAlias);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerCreateBuildWithCustomContainer", &AutoGenMultiplayerServerTests::TestMultiplayerServerCreateBuildWithCustomContainer);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerCreateBuildWithManagedContainer", &AutoGenMultiplayerServerTests::TestMultiplayerServerCreateBuildWithManagedContainer);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerCreateBuildWithProcessBasedServer", &AutoGenMultiplayerServerTests::TestMultiplayerServerCreateBuildWithProcessBasedServer);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerCreateRemoteUser", &AutoGenMultiplayerServerTests::TestMultiplayerServerCreateRemoteUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerCreateTitleMultiplayerServersQuotaChange", &AutoGenMultiplayerServerTests::TestMultiplayerServerCreateTitleMultiplayerServersQuotaChange);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerDeleteAsset", &AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteAsset);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerDeleteBuild", &AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteBuild);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerDeleteBuildAlias", &AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteBuildAlias);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerDeleteBuildRegion", &AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteBuildRegion);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerDeleteCertificate", &AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteCertificate);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerDeleteContainerImageRepository", &AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteContainerImageRepository);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerDeleteRemoteUser", &AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteRemoteUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerEnableMultiplayerServersForTitle", &AutoGenMultiplayerServerTests::TestMultiplayerServerEnableMultiplayerServersForTitle);
#endif

    AddTest("TestMultiplayerServerGetAssetDownloadUrl", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetAssetDownloadUrl);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerGetAssetUploadUrl", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetAssetUploadUrl);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerGetBuild", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetBuild);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerGetBuildAlias", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetBuildAlias);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerGetContainerRegistryCredentials", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetContainerRegistryCredentials);
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
    AddTest("TestMultiplayerServerGetTitleEnabledForMultiplayerServersStatus", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetTitleEnabledForMultiplayerServersStatus);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerGetTitleMultiplayerServersQuotaChange", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetTitleMultiplayerServersQuotaChange);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerGetTitleMultiplayerServersQuotas", &AutoGenMultiplayerServerTests::TestMultiplayerServerGetTitleMultiplayerServersQuotas);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListArchivedMultiplayerServers", &AutoGenMultiplayerServerTests::TestMultiplayerServerListArchivedMultiplayerServers);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListAssetSummaries", &AutoGenMultiplayerServerTests::TestMultiplayerServerListAssetSummaries);
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
    AddTest("TestMultiplayerServerListContainerImages", &AutoGenMultiplayerServerTests::TestMultiplayerServerListContainerImages);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListContainerImageTags", &AutoGenMultiplayerServerTests::TestMultiplayerServerListContainerImageTags);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListMultiplayerServers", &AutoGenMultiplayerServerTests::TestMultiplayerServerListMultiplayerServers);
#endif

    AddTest("TestMultiplayerServerListPartyQosServers", &AutoGenMultiplayerServerTests::TestMultiplayerServerListPartyQosServers);

    AddTest("TestMultiplayerServerListQosServersForTitle", &AutoGenMultiplayerServerTests::TestMultiplayerServerListQosServersForTitle);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListTitleMultiplayerServersQuotaChanges", &AutoGenMultiplayerServerTests::TestMultiplayerServerListTitleMultiplayerServersQuotaChanges);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerListVirtualMachineSummaries", &AutoGenMultiplayerServerTests::TestMultiplayerServerListVirtualMachineSummaries);
#endif

    AddTest("TestMultiplayerServerRequestMultiplayerServer", &AutoGenMultiplayerServerTests::TestMultiplayerServerRequestMultiplayerServer);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerRolloverContainerRegistryCredentials", &AutoGenMultiplayerServerTests::TestMultiplayerServerRolloverContainerRegistryCredentials);
#endif

    AddTest("TestMultiplayerServerShutdownMultiplayerServer", &AutoGenMultiplayerServerTests::TestMultiplayerServerShutdownMultiplayerServer);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerUntagContainerImage", &AutoGenMultiplayerServerTests::TestMultiplayerServerUntagContainerImage);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerUpdateBuildAlias", &AutoGenMultiplayerServerTests::TestMultiplayerServerUpdateBuildAlias);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerUpdateBuildName", &AutoGenMultiplayerServerTests::TestMultiplayerServerUpdateBuildName);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerUpdateBuildRegion", &AutoGenMultiplayerServerTests::TestMultiplayerServerUpdateBuildRegion);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerUpdateBuildRegions", &AutoGenMultiplayerServerTests::TestMultiplayerServerUpdateBuildRegions);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMultiplayerServerUploadCertificate", &AutoGenMultiplayerServerTests::TestMultiplayerServerUploadCertificate);
#endif
}

void AutoGenMultiplayerServerTests::ClassSetUp()
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

#pragma region CreateBuildAlias

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerCreateBuildAlias(TestContext& testContext)
{
    struct CreateBuildAliasResultHolderStruct : public BuildAliasDetailsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateBuildAliasGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateBuildAliasGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerBuildAliasDetailsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerBuildAliasDetailsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateBuildAliasResultHolderStruct>>(testContext);

    PFMultiplayerServerCreateBuildAliasRequestWrapper<> request;
    FillCreateBuildAliasRequest(request);
    LogCreateBuildAliasRequest(&request.Model(), "TestMultiplayerServerCreateBuildAlias");
    HRESULT hr = PFMultiplayerServerCreateBuildAliasAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerCreateBuildAliasAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region CreateBuildWithCustomContainer

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerCreateBuildWithCustomContainer(TestContext& testContext)
{
    struct CreateBuildWithCustomContainerResultHolderStruct : public CreateBuildWithCustomContainerResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateBuildWithCustomContainerGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateBuildWithCustomContainerGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerCreateBuildWithCustomContainerResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerCreateBuildWithCustomContainerResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateBuildWithCustomContainerResultHolderStruct>>(testContext);

    PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper<> request;
    FillCreateBuildWithCustomContainerRequest(request);
    LogCreateBuildWithCustomContainerRequest(&request.Model(), "TestMultiplayerServerCreateBuildWithCustomContainer");
    HRESULT hr = PFMultiplayerServerCreateBuildWithCustomContainerAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerCreateBuildWithCustomContainerAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region CreateBuildWithManagedContainer

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerCreateBuildWithManagedContainer(TestContext& testContext)
{
    struct CreateBuildWithManagedContainerResultHolderStruct : public CreateBuildWithManagedContainerResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateBuildWithManagedContainerGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateBuildWithManagedContainerGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerCreateBuildWithManagedContainerResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerCreateBuildWithManagedContainerResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateBuildWithManagedContainerResultHolderStruct>>(testContext);

    PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper<> request;
    FillCreateBuildWithManagedContainerRequest(request);
    LogCreateBuildWithManagedContainerRequest(&request.Model(), "TestMultiplayerServerCreateBuildWithManagedContainer");
    HRESULT hr = PFMultiplayerServerCreateBuildWithManagedContainerAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerCreateBuildWithManagedContainerAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region CreateBuildWithProcessBasedServer

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerCreateBuildWithProcessBasedServer(TestContext& testContext)
{
    struct CreateBuildWithProcessBasedServerResultHolderStruct : public CreateBuildWithProcessBasedServerResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateBuildWithProcessBasedServerGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateBuildWithProcessBasedServerGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerCreateBuildWithProcessBasedServerResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerCreateBuildWithProcessBasedServerResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateBuildWithProcessBasedServerResultHolderStruct>>(testContext);

    PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper<> request;
    FillCreateBuildWithProcessBasedServerRequest(request);
    LogCreateBuildWithProcessBasedServerRequest(&request.Model(), "TestMultiplayerServerCreateBuildWithProcessBasedServer");
    HRESULT hr = PFMultiplayerServerCreateBuildWithProcessBasedServerAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerCreateBuildWithProcessBasedServerAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

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
            
            LogPFMultiplayerServerCreateRemoteUserResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerCreateRemoteUserResponse(result);
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

#pragma region CreateTitleMultiplayerServersQuotaChange

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerCreateTitleMultiplayerServersQuotaChange(TestContext& testContext)
{
    struct CreateTitleMultiplayerServersQuotaChangeResultHolderStruct : public CreateTitleMultiplayerServersQuotaChangeResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateTitleMultiplayerServersQuotaChangeResultHolderStruct>>(testContext);

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper<> request;
    FillCreateTitleMultiplayerServersQuotaChangeRequest(request);
    LogCreateTitleMultiplayerServersQuotaChangeRequest(&request.Model(), "TestMultiplayerServerCreateTitleMultiplayerServersQuotaChange");
    HRESULT hr = PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerCreateTitleMultiplayerServersQuotaChangeAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region DeleteAsset

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteAsset(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerDeleteAssetRequestWrapper<> request;
    FillDeleteAssetRequest(request);
    LogDeleteAssetRequest(&request.Model(), "TestMultiplayerServerDeleteAsset");
    HRESULT hr = PFMultiplayerServerDeleteAssetAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerDeleteAssetAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region DeleteBuild

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteBuild(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerDeleteBuildRequestWrapper<> request;
    FillDeleteBuildRequest(request);
    LogDeleteBuildRequest(&request.Model(), "TestMultiplayerServerDeleteBuild");
    HRESULT hr = PFMultiplayerServerDeleteBuildAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerDeleteBuildAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region DeleteBuildAlias

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteBuildAlias(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerDeleteBuildAliasRequestWrapper<> request;
    FillDeleteBuildAliasRequest(request);
    LogDeleteBuildAliasRequest(&request.Model(), "TestMultiplayerServerDeleteBuildAlias");
    HRESULT hr = PFMultiplayerServerDeleteBuildAliasAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerDeleteBuildAliasAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region DeleteBuildRegion

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteBuildRegion(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerDeleteBuildRegionRequestWrapper<> request;
    FillDeleteBuildRegionRequest(request);
    LogDeleteBuildRegionRequest(&request.Model(), "TestMultiplayerServerDeleteBuildRegion");
    HRESULT hr = PFMultiplayerServerDeleteBuildRegionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerDeleteBuildRegionAsync", hr);
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

#pragma region DeleteContainerImageRepository

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerDeleteContainerImageRepository(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerDeleteContainerImageRequestWrapper<> request;
    FillDeleteContainerImageRequest(request);
    LogDeleteContainerImageRequest(&request.Model(), "TestMultiplayerServerDeleteContainerImageRepository");
    HRESULT hr = PFMultiplayerServerDeleteContainerImageRepositoryAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerDeleteContainerImageRepositoryAsync", hr);
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

#pragma region EnableMultiplayerServersForTitle

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerEnableMultiplayerServersForTitle(TestContext& testContext)
{
    struct EnableMultiplayerServersForTitleResultHolderStruct : public EnableMultiplayerServersForTitleResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerEnableMultiplayerServersForTitleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerEnableMultiplayerServersForTitleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerEnableMultiplayerServersForTitleResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerEnableMultiplayerServersForTitleResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<EnableMultiplayerServersForTitleResultHolderStruct>>(testContext);

    PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper<> request;
    FillEnableMultiplayerServersForTitleRequest(request);
    LogEnableMultiplayerServersForTitleRequest(&request.Model(), "TestMultiplayerServerEnableMultiplayerServersForTitle");
    HRESULT hr = PFMultiplayerServerEnableMultiplayerServersForTitleAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerEnableMultiplayerServersForTitleAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetAssetDownloadUrl

void AutoGenMultiplayerServerTests::TestMultiplayerServerGetAssetDownloadUrl(TestContext& testContext)
{
    struct GetAssetDownloadUrlResultHolderStruct : public GetAssetDownloadUrlResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetAssetDownloadUrlGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetAssetDownloadUrlGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerGetAssetDownloadUrlResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerGetAssetDownloadUrlResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetAssetDownloadUrlResultHolderStruct>>(testContext);

    PFMultiplayerServerGetAssetDownloadUrlRequestWrapper<> request;
    FillGetAssetDownloadUrlRequest(request);
    LogGetAssetDownloadUrlRequest(&request.Model(), "TestMultiplayerServerGetAssetDownloadUrl");
    HRESULT hr = PFMultiplayerServerGetAssetDownloadUrlAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetAssetDownloadUrlAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetAssetUploadUrl

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerGetAssetUploadUrl(TestContext& testContext)
{
    struct GetAssetUploadUrlResultHolderStruct : public GetAssetUploadUrlResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetAssetUploadUrlGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetAssetUploadUrlGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerGetAssetUploadUrlResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerGetAssetUploadUrlResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetAssetUploadUrlResultHolderStruct>>(testContext);

    PFMultiplayerServerGetAssetUploadUrlRequestWrapper<> request;
    FillGetAssetUploadUrlRequest(request);
    LogGetAssetUploadUrlRequest(&request.Model(), "TestMultiplayerServerGetAssetUploadUrl");
    HRESULT hr = PFMultiplayerServerGetAssetUploadUrlAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetAssetUploadUrlAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetBuild

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerGetBuild(TestContext& testContext)
{
    struct GetBuildResultHolderStruct : public GetBuildResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetBuildGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetBuildGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerGetBuildResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerGetBuildResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetBuildResultHolderStruct>>(testContext);

    PFMultiplayerServerGetBuildRequestWrapper<> request;
    FillGetBuildRequest(request);
    LogGetBuildRequest(&request.Model(), "TestMultiplayerServerGetBuild");
    HRESULT hr = PFMultiplayerServerGetBuildAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetBuildAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetBuildAlias

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerGetBuildAlias(TestContext& testContext)
{
    struct GetBuildAliasResultHolderStruct : public BuildAliasDetailsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetBuildAliasGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetBuildAliasGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerBuildAliasDetailsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerBuildAliasDetailsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetBuildAliasResultHolderStruct>>(testContext);

    PFMultiplayerServerGetBuildAliasRequestWrapper<> request;
    FillGetBuildAliasRequest(request);
    LogGetBuildAliasRequest(&request.Model(), "TestMultiplayerServerGetBuildAlias");
    HRESULT hr = PFMultiplayerServerGetBuildAliasAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetBuildAliasAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetContainerRegistryCredentials

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerGetContainerRegistryCredentials(TestContext& testContext)
{
    struct GetContainerRegistryCredentialsResultHolderStruct : public GetContainerRegistryCredentialsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetContainerRegistryCredentialsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetContainerRegistryCredentialsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerGetContainerRegistryCredentialsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerGetContainerRegistryCredentialsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetContainerRegistryCredentialsResultHolderStruct>>(testContext);

    PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper<> request;
    FillGetContainerRegistryCredentialsRequest(request);
    LogGetContainerRegistryCredentialsRequest(&request.Model(), "TestMultiplayerServerGetContainerRegistryCredentials");
    HRESULT hr = PFMultiplayerServerGetContainerRegistryCredentialsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetContainerRegistryCredentialsAsync", hr);
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
            
            LogPFMultiplayerServerGetMultiplayerServerDetailsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerGetMultiplayerServerDetailsResponse(result);
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
            
            LogPFMultiplayerServerGetMultiplayerServerLogsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerGetMultiplayerServerLogsResponse(result);
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
            
            LogPFMultiplayerServerGetMultiplayerServerLogsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerGetMultiplayerServerLogsResponse(result);
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
            
            LogPFMultiplayerServerGetRemoteLoginEndpointResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerGetRemoteLoginEndpointResponse(result);
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

#pragma region GetTitleEnabledForMultiplayerServersStatus

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerGetTitleEnabledForMultiplayerServersStatus(TestContext& testContext)
{
    struct GetTitleEnabledForMultiplayerServersStatusResultHolderStruct : public GetTitleEnabledForMultiplayerServersStatusResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetTitleEnabledForMultiplayerServersStatusResultHolderStruct>>(testContext);

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper<> request;
    FillGetTitleEnabledForMultiplayerServersStatusRequest(request);
    LogGetTitleEnabledForMultiplayerServersStatusRequest(&request.Model(), "TestMultiplayerServerGetTitleEnabledForMultiplayerServersStatus");
    HRESULT hr = PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetTitleEnabledForMultiplayerServersStatusAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetTitleMultiplayerServersQuotaChange

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerGetTitleMultiplayerServersQuotaChange(TestContext& testContext)
{
    struct GetTitleMultiplayerServersQuotaChangeResultHolderStruct : public GetTitleMultiplayerServersQuotaChangeResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetTitleMultiplayerServersQuotaChangeResultHolderStruct>>(testContext);

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper<> request;
    FillGetTitleMultiplayerServersQuotaChangeRequest(request);
    LogGetTitleMultiplayerServersQuotaChangeRequest(&request.Model(), "TestMultiplayerServerGetTitleMultiplayerServersQuotaChange");
    HRESULT hr = PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetTitleMultiplayerServersQuotaChangeAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetTitleMultiplayerServersQuotas

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerGetTitleMultiplayerServersQuotas(TestContext& testContext)
{
    struct GetTitleMultiplayerServersQuotasResultHolderStruct : public GetTitleMultiplayerServersQuotasResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetTitleMultiplayerServersQuotasGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerGetTitleMultiplayerServersQuotasGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerGetTitleMultiplayerServersQuotasResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerGetTitleMultiplayerServersQuotasResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetTitleMultiplayerServersQuotasResultHolderStruct>>(testContext);

    PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper<> request;
    FillGetTitleMultiplayerServersQuotasRequest(request);
    LogGetTitleMultiplayerServersQuotasRequest(&request.Model(), "TestMultiplayerServerGetTitleMultiplayerServersQuotas");
    HRESULT hr = PFMultiplayerServerGetTitleMultiplayerServersQuotasAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerGetTitleMultiplayerServersQuotasAsync", hr);
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
            
            LogPFMultiplayerServerListMultiplayerServersResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListMultiplayerServersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListArchivedMultiplayerServersResultHolderStruct>>(testContext);

    PFMultiplayerServerListMultiplayerServersRequestWrapper<> request;
    FillListMultiplayerServersRequest(request);
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

#pragma region ListAssetSummaries

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerListAssetSummaries(TestContext& testContext)
{
    struct ListAssetSummariesResultHolderStruct : public ListAssetSummariesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListAssetSummariesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListAssetSummariesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerListAssetSummariesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListAssetSummariesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListAssetSummariesResultHolderStruct>>(testContext);

    PFMultiplayerServerListAssetSummariesRequestWrapper<> request;
    FillListAssetSummariesRequest(request);
    LogListAssetSummariesRequest(&request.Model(), "TestMultiplayerServerListAssetSummaries");
    HRESULT hr = PFMultiplayerServerListAssetSummariesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListAssetSummariesAsync", hr);
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
            
            LogPFMultiplayerServerListBuildAliasesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListBuildAliasesResponse(result);
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
            
            LogPFMultiplayerServerListBuildSummariesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListBuildSummariesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListBuildSummariesV2ResultHolderStruct>>(testContext);

    PFMultiplayerServerListBuildSummariesRequestWrapper<> request;
    FillListBuildSummariesRequest(request);
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
            
            LogPFMultiplayerServerListCertificateSummariesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListCertificateSummariesResponse(result);
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

#pragma region ListContainerImages

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerListContainerImages(TestContext& testContext)
{
    struct ListContainerImagesResultHolderStruct : public ListContainerImagesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListContainerImagesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListContainerImagesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerListContainerImagesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListContainerImagesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListContainerImagesResultHolderStruct>>(testContext);

    PFMultiplayerServerListContainerImagesRequestWrapper<> request;
    FillListContainerImagesRequest(request);
    LogListContainerImagesRequest(&request.Model(), "TestMultiplayerServerListContainerImages");
    HRESULT hr = PFMultiplayerServerListContainerImagesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListContainerImagesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ListContainerImageTags

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerListContainerImageTags(TestContext& testContext)
{
    struct ListContainerImageTagsResultHolderStruct : public ListContainerImageTagsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListContainerImageTagsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListContainerImageTagsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerListContainerImageTagsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListContainerImageTagsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListContainerImageTagsResultHolderStruct>>(testContext);

    PFMultiplayerServerListContainerImageTagsRequestWrapper<> request;
    FillListContainerImageTagsRequest(request);
    LogListContainerImageTagsRequest(&request.Model(), "TestMultiplayerServerListContainerImageTags");
    HRESULT hr = PFMultiplayerServerListContainerImageTagsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListContainerImageTagsAsync", hr);
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
            
            LogPFMultiplayerServerListMultiplayerServersResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListMultiplayerServersResponse(result);
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
            
            LogPFMultiplayerServerListPartyQosServersResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListPartyQosServersResponse(result);
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
            
            LogPFMultiplayerServerListQosServersForTitleResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListQosServersForTitleResponse(result);
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

#pragma region ListTitleMultiplayerServersQuotaChanges

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerListTitleMultiplayerServersQuotaChanges(TestContext& testContext)
{
    struct ListTitleMultiplayerServersQuotaChangesResultHolderStruct : public ListTitleMultiplayerServersQuotaChangesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListTitleMultiplayerServersQuotaChangesResultHolderStruct>>(testContext);

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper<> request;
    FillListTitleMultiplayerServersQuotaChangesRequest(request);
    LogListTitleMultiplayerServersQuotaChangesRequest(&request.Model(), "TestMultiplayerServerListTitleMultiplayerServersQuotaChanges");
    HRESULT hr = PFMultiplayerServerListTitleMultiplayerServersQuotaChangesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerListTitleMultiplayerServersQuotaChangesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

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
            
            LogPFMultiplayerServerListVirtualMachineSummariesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerListVirtualMachineSummariesResponse(result);
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
            
            LogPFMultiplayerServerRequestMultiplayerServerResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerRequestMultiplayerServerResponse(result);
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

#pragma region RolloverContainerRegistryCredentials

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerRolloverContainerRegistryCredentials(TestContext& testContext)
{
    struct RolloverContainerRegistryCredentialsResultHolderStruct : public RolloverContainerRegistryCredentialsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerRolloverContainerRegistryCredentialsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerRolloverContainerRegistryCredentialsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerRolloverContainerRegistryCredentialsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerRolloverContainerRegistryCredentialsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<RolloverContainerRegistryCredentialsResultHolderStruct>>(testContext);

    PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper<> request;
    FillRolloverContainerRegistryCredentialsRequest(request);
    LogRolloverContainerRegistryCredentialsRequest(&request.Model(), "TestMultiplayerServerRolloverContainerRegistryCredentials");
    HRESULT hr = PFMultiplayerServerRolloverContainerRegistryCredentialsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerRolloverContainerRegistryCredentialsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

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

#pragma region UntagContainerImage

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerUntagContainerImage(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerUntagContainerImageRequestWrapper<> request;
    FillUntagContainerImageRequest(request);
    LogUntagContainerImageRequest(&request.Model(), "TestMultiplayerServerUntagContainerImage");
    HRESULT hr = PFMultiplayerServerUntagContainerImageAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerUntagContainerImageAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region UpdateBuildAlias

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerUpdateBuildAlias(TestContext& testContext)
{
    struct UpdateBuildAliasResultHolderStruct : public BuildAliasDetailsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerUpdateBuildAliasGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMultiplayerServerUpdateBuildAliasGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFMultiplayerServerBuildAliasDetailsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFMultiplayerServerBuildAliasDetailsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<UpdateBuildAliasResultHolderStruct>>(testContext);

    PFMultiplayerServerUpdateBuildAliasRequestWrapper<> request;
    FillUpdateBuildAliasRequest(request);
    LogUpdateBuildAliasRequest(&request.Model(), "TestMultiplayerServerUpdateBuildAlias");
    HRESULT hr = PFMultiplayerServerUpdateBuildAliasAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerUpdateBuildAliasAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region UpdateBuildName

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerUpdateBuildName(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerUpdateBuildNameRequestWrapper<> request;
    FillUpdateBuildNameRequest(request);
    LogUpdateBuildNameRequest(&request.Model(), "TestMultiplayerServerUpdateBuildName");
    HRESULT hr = PFMultiplayerServerUpdateBuildNameAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerUpdateBuildNameAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region UpdateBuildRegion

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerUpdateBuildRegion(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerUpdateBuildRegionRequestWrapper<> request;
    FillUpdateBuildRegionRequest(request);
    LogUpdateBuildRegionRequest(&request.Model(), "TestMultiplayerServerUpdateBuildRegion");
    HRESULT hr = PFMultiplayerServerUpdateBuildRegionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerUpdateBuildRegionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region UpdateBuildRegions

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMultiplayerServerTests::TestMultiplayerServerUpdateBuildRegions(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMultiplayerServerUpdateBuildRegionsRequestWrapper<> request;
    FillUpdateBuildRegionsRequest(request);
    LogUpdateBuildRegionsRequest(&request.Model(), "TestMultiplayerServerUpdateBuildRegions");
    HRESULT hr = PFMultiplayerServerUpdateBuildRegionsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMultiplayerServerMultiplayerServerUpdateBuildRegionsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

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
