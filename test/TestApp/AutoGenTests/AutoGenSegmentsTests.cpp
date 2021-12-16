#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenSegmentsTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenSegmentsTests::SegmentsTestData AutoGenSegmentsTests::testData;

void AutoGenSegmentsTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenSegmentsTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenSegmentsTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestSegmentsAdminCreateSegment", &AutoGenSegmentsTests::TestSegmentsAdminCreateSegment);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestSegmentsAdminDeleteSegment", &AutoGenSegmentsTests::TestSegmentsAdminDeleteSegment);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestSegmentsAdminGetSegments", &AutoGenSegmentsTests::TestSegmentsAdminGetSegments);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestSegmentsAdminUpdateSegment", &AutoGenSegmentsTests::TestSegmentsAdminUpdateSegment);
#endif
}

void AutoGenSegmentsTests::ClassSetUp()
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

void AutoGenSegmentsTests::ClassTearDown()
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

void AutoGenSegmentsTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminCreateSegment

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenSegmentsTests::TestSegmentsAdminCreateSegment(TestContext& testContext)
{
    struct AdminCreateSegmentResultHolderStruct : public CreateSegmentResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSegmentsAdminCreateSegmentGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSegmentsAdminCreateSegmentGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSegmentsCreateSegmentResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFSegmentsCreateSegmentResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminCreateSegmentResultHolderStruct>>(testContext);

    PFSegmentsCreateSegmentRequestWrapper<> request;
    FillCreateSegmentRequest(request);
    LogCreateSegmentRequest(&request.Model(), "TestSegmentsAdminCreateSegment");
    HRESULT hr = PFSegmentsAdminCreateSegmentAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSegmentsSegmentsAdminCreateSegmentAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminDeleteSegment

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenSegmentsTests::TestSegmentsAdminDeleteSegment(TestContext& testContext)
{
    struct AdminDeleteSegmentResultHolderStruct : public DeleteSegmentsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSegmentsAdminDeleteSegmentGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSegmentsAdminDeleteSegmentGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSegmentsDeleteSegmentsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFSegmentsDeleteSegmentsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminDeleteSegmentResultHolderStruct>>(testContext);

    PFSegmentsDeleteSegmentRequestWrapper<> request;
    FillDeleteSegmentRequest(request);
    LogDeleteSegmentRequest(&request.Model(), "TestSegmentsAdminDeleteSegment");
    HRESULT hr = PFSegmentsAdminDeleteSegmentAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSegmentsSegmentsAdminDeleteSegmentAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetSegments

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenSegmentsTests::TestSegmentsAdminGetSegments(TestContext& testContext)
{
    struct AdminGetSegmentsResultHolderStruct : public GetSegmentsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSegmentsAdminGetSegmentsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSegmentsAdminGetSegmentsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSegmentsGetSegmentsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFSegmentsGetSegmentsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetSegmentsResultHolderStruct>>(testContext);

    PFSegmentsGetSegmentsRequestWrapper<> request;
    FillGetSegmentsRequest(request);
    LogGetSegmentsRequest(&request.Model(), "TestSegmentsAdminGetSegments");
    HRESULT hr = PFSegmentsAdminGetSegmentsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSegmentsSegmentsAdminGetSegmentsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateSegment

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenSegmentsTests::TestSegmentsAdminUpdateSegment(TestContext& testContext)
{
    struct AdminUpdateSegmentResultHolderStruct : public UpdateSegmentResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSegmentsAdminUpdateSegmentGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSegmentsAdminUpdateSegmentGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSegmentsUpdateSegmentResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFSegmentsUpdateSegmentResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateSegmentResultHolderStruct>>(testContext);

    PFSegmentsUpdateSegmentRequestWrapper<> request;
    FillUpdateSegmentRequest(request);
    LogUpdateSegmentRequest(&request.Model(), "TestSegmentsAdminUpdateSegment");
    HRESULT hr = PFSegmentsAdminUpdateSegmentAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSegmentsSegmentsAdminUpdateSegmentAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
