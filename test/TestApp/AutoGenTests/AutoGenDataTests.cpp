#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenDataTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenDataTests::DataTestData AutoGenDataTests::testData;

void AutoGenDataTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenDataTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenDataTests::AddTests()
{
    // Generated tests 
    AddTest("TestDataAbortFileUploadsPrerequisiteInitiateFileUploads", &AutoGenDataTests::TestDataAbortFileUploadsPrerequisiteInitiateFileUploads);
    AddTest("TestDataAbortFileUploads", &AutoGenDataTests::TestDataAbortFileUploads);

    AddTest("TestDataDeleteFilesPrerequisiteInitiateFileUploads", &AutoGenDataTests::TestDataDeleteFilesPrerequisiteInitiateFileUploads);
    AddTest("TestDataDeleteFilesPrerequisiteFinalizeFileUploads", &AutoGenDataTests::TestDataDeleteFilesPrerequisiteFinalizeFileUploads);
    AddTest("TestDataDeleteFiles", &AutoGenDataTests::TestDataDeleteFiles);

    AddTest("TestDataFinalizeFileUploadsPrerequisiteInitiateFileUploads", &AutoGenDataTests::TestDataFinalizeFileUploadsPrerequisiteInitiateFileUploads);
    AddTest("TestDataFinalizeFileUploads", &AutoGenDataTests::TestDataFinalizeFileUploads);
    AddTest("TestDataFinalizeFileUploadsCleanupDeleteFiles", &AutoGenDataTests::TestDataFinalizeFileUploadsCleanupDeleteFiles);

    AddTest("TestDataGetFiles", &AutoGenDataTests::TestDataGetFiles);

    AddTest("TestDataGetObjects", &AutoGenDataTests::TestDataGetObjects);

    AddTest("TestDataInitiateFileUploads", &AutoGenDataTests::TestDataInitiateFileUploads);
    AddTest("TestDataInitiateFileUploadsCleanupAbortFileUploads", &AutoGenDataTests::TestDataInitiateFileUploadsCleanupAbortFileUploads);

    AddTest("TestDataSetObjectsPrerequisiteSetObjects", &AutoGenDataTests::TestDataSetObjectsPrerequisiteSetObjects);
    AddTest("TestDataSetObjects", &AutoGenDataTests::TestDataSetObjects);
}

void AutoGenDataTests::ClassSetUp()
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

void AutoGenDataTests::ClassTearDown()
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

void AutoGenDataTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AbortFileUploads

void AutoGenDataTests::TestDataAbortFileUploadsPrerequisiteInitiateFileUploads(TestContext& testContext)
{
    struct InitiateFileUploadsResultHolderStruct : public InitiateFileUploadsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataInitiateFileUploadsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataInitiateFileUploadsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreAbortFileUploadsPrerequisiteInitiateFileUploadsResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<InitiateFileUploadsResultHolderStruct>>(testContext);

    PFDataInitiateFileUploadsRequestWrapper<> request;
    FillAbortFileUploadsPrerequisiteInitiateFileUploadsRequest(request);
    HRESULT hr = PFDataInitiateFileUploadsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataAbortFileUploadsPrerequisiteInitiateFileUploadsAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenDataTests::TestDataAbortFileUploads(TestContext& testContext)
{
    struct AbortFileUploadsResultHolderStruct : public AbortFileUploadsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataAbortFileUploadsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataAbortFileUploadsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAbortFileUploadsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAbortFileUploadsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AbortFileUploadsResultHolderStruct>>(testContext);

    PFDataAbortFileUploadsRequestWrapper<> request;
    FillAbortFileUploadsRequest(request);
    LogAbortFileUploadsRequest(&request.Model(), "TestDataAbortFileUploads");
    HRESULT hr = PFDataAbortFileUploadsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataAbortFileUploadsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region DeleteFiles

void AutoGenDataTests::TestDataDeleteFilesPrerequisiteInitiateFileUploads(TestContext& testContext)
{
    struct InitiateFileUploadsResultHolderStruct : public InitiateFileUploadsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataInitiateFileUploadsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataInitiateFileUploadsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreDeleteFilesPrerequisiteInitiateFileUploadsResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<InitiateFileUploadsResultHolderStruct>>(testContext);

    PFDataInitiateFileUploadsRequestWrapper<> request;
    FillDeleteFilesPrerequisiteInitiateFileUploadsRequest(request);
    HRESULT hr = PFDataInitiateFileUploadsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataDeleteFilesPrerequisiteInitiateFileUploadsAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenDataTests::TestDataDeleteFilesPrerequisiteFinalizeFileUploads(TestContext& testContext)
{
    struct FinalizeFileUploadsResultHolderStruct : public FinalizeFileUploadsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataFinalizeFileUploadsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataFinalizeFileUploadsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreDeleteFilesPrerequisiteFinalizeFileUploadsResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<FinalizeFileUploadsResultHolderStruct>>(testContext);

    PFDataFinalizeFileUploadsRequestWrapper<> request;
    FillDeleteFilesPrerequisiteFinalizeFileUploadsRequest(request);
    HRESULT hr = PFDataFinalizeFileUploadsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataDeleteFilesPrerequisiteFinalizeFileUploadsAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenDataTests::TestDataDeleteFiles(TestContext& testContext)
{
    struct DeleteFilesResultHolderStruct : public DeleteFilesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataDeleteFilesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataDeleteFilesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogDeleteFilesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateDeleteFilesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<DeleteFilesResultHolderStruct>>(testContext);

    PFDataDeleteFilesRequestWrapper<> request;
    FillDeleteFilesRequest(request);
    LogDeleteFilesRequest(&request.Model(), "TestDataDeleteFiles");
    HRESULT hr = PFDataDeleteFilesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataDeleteFilesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region FinalizeFileUploads

void AutoGenDataTests::TestDataFinalizeFileUploadsPrerequisiteInitiateFileUploads(TestContext& testContext)
{
    struct InitiateFileUploadsResultHolderStruct : public InitiateFileUploadsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataInitiateFileUploadsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataInitiateFileUploadsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreFinalizeFileUploadsPrerequisiteInitiateFileUploadsResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<InitiateFileUploadsResultHolderStruct>>(testContext);

    PFDataInitiateFileUploadsRequestWrapper<> request;
    FillFinalizeFileUploadsPrerequisiteInitiateFileUploadsRequest(request);
    HRESULT hr = PFDataInitiateFileUploadsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataFinalizeFileUploadsPrerequisiteInitiateFileUploadsAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenDataTests::TestDataFinalizeFileUploads(TestContext& testContext)
{
    struct FinalizeFileUploadsResultHolderStruct : public FinalizeFileUploadsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataFinalizeFileUploadsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataFinalizeFileUploadsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogFinalizeFileUploadsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateFinalizeFileUploadsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<FinalizeFileUploadsResultHolderStruct>>(testContext);

    PFDataFinalizeFileUploadsRequestWrapper<> request;
    FillFinalizeFileUploadsRequest(request);
    LogFinalizeFileUploadsRequest(&request.Model(), "TestDataFinalizeFileUploads");
    HRESULT hr = PFDataFinalizeFileUploadsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataFinalizeFileUploadsAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenDataTests::TestDataFinalizeFileUploadsCleanupDeleteFiles(TestContext& testContext)
{
    struct DeleteFilesResultHolderStruct : public DeleteFilesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataDeleteFilesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataDeleteFilesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreFinalizeFileUploadsCleanupDeleteFilesResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<DeleteFilesResultHolderStruct>>(testContext);

    PFDataDeleteFilesRequestWrapper<> request;
    FillFinalizeFileUploadsCleanupDeleteFilesRequest(request);
    HRESULT hr = PFDataDeleteFilesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataFinalizeFileUploadsCleanupDeleteFilesAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region GetFiles

void AutoGenDataTests::TestDataGetFiles(TestContext& testContext)
{
    struct GetFilesResultHolderStruct : public GetFilesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataGetFilesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataGetFilesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetFilesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetFilesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetFilesResultHolderStruct>>(testContext);

    PFDataGetFilesRequestWrapper<> request;
    FillGetFilesRequest(request);
    LogGetFilesRequest(&request.Model(), "TestDataGetFiles");
    HRESULT hr = PFDataGetFilesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataGetFilesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetObjects

void AutoGenDataTests::TestDataGetObjects(TestContext& testContext)
{
    struct GetObjectsResultHolderStruct : public GetObjectsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataGetObjectsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataGetObjectsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetObjectsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetObjectsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetObjectsResultHolderStruct>>(testContext);

    PFDataGetObjectsRequestWrapper<> request;
    FillGetObjectsRequest(request);
    LogGetObjectsRequest(&request.Model(), "TestDataGetObjects");
    HRESULT hr = PFDataGetObjectsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataGetObjectsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region InitiateFileUploads

void AutoGenDataTests::TestDataInitiateFileUploads(TestContext& testContext)
{
    struct InitiateFileUploadsResultHolderStruct : public InitiateFileUploadsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataInitiateFileUploadsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataInitiateFileUploadsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogInitiateFileUploadsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateInitiateFileUploadsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<InitiateFileUploadsResultHolderStruct>>(testContext);

    PFDataInitiateFileUploadsRequestWrapper<> request;
    FillInitiateFileUploadsRequest(request);
    LogInitiateFileUploadsRequest(&request.Model(), "TestDataInitiateFileUploads");
    HRESULT hr = PFDataInitiateFileUploadsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataInitiateFileUploadsAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenDataTests::TestDataInitiateFileUploadsCleanupAbortFileUploads(TestContext& testContext)
{
    struct AbortFileUploadsResultHolderStruct : public AbortFileUploadsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataAbortFileUploadsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataAbortFileUploadsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreInitiateFileUploadsCleanupAbortFileUploadsResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<AbortFileUploadsResultHolderStruct>>(testContext);

    PFDataAbortFileUploadsRequestWrapper<> request;
    FillInitiateFileUploadsCleanupAbortFileUploadsRequest(request);
    HRESULT hr = PFDataAbortFileUploadsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataInitiateFileUploadsCleanupAbortFileUploadsAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region SetObjects

void AutoGenDataTests::TestDataSetObjectsPrerequisiteSetObjects(TestContext& testContext)
{
    struct SetObjectsResultHolderStruct : public SetObjectsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataSetObjectsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataSetObjectsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreSetObjectsPrerequisiteSetObjectsResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<SetObjectsResultHolderStruct>>(testContext);

    PFDataSetObjectsRequestWrapper<> request;
    FillSetObjectsPrerequisiteSetObjectsRequest(request);
    HRESULT hr = PFDataSetObjectsAsync(entityHandle2, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataSetObjectsPrerequisiteSetObjectsAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenDataTests::TestDataSetObjects(TestContext& testContext)
{
    struct SetObjectsResultHolderStruct : public SetObjectsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFDataSetObjectsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFDataSetObjectsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogSetObjectsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateSetObjectsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<SetObjectsResultHolderStruct>>(testContext);

    PFDataSetObjectsRequestWrapper<> request;
    FillSetObjectsRequest(request);
    LogSetObjectsRequest(&request.Model(), "TestDataSetObjects");
    HRESULT hr = PFDataSetObjectsAsync(entityHandle2, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFDataDataSetObjectsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
