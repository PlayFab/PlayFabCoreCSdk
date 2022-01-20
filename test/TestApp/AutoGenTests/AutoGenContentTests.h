#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFContentDataModelWrappers.h>
#include "AutoGenContentResultHolders.h"

namespace PlayFabUnit
{

class AutoGenContentTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestContentAdminDeleteContent(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestContentAdminGetContentList(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestContentAdminGetContentUploadUrl(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestContentClientGetContentDownloadUrl(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestContentServerGetContentDownloadUrl(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogDeleteContentRequest(PFContentDeleteContentRequest const* request, const char* testName);
    static void LogGetContentListRequest(PFContentGetContentListRequest const* request, const char* testName);
    static HRESULT LogGetContentListResult(PFContentGetContentListResult const* result);
    static void LogGetContentUploadUrlRequest(PFContentGetContentUploadUrlRequest const* request, const char* testName);
    static HRESULT LogGetContentUploadUrlResult(PFContentGetContentUploadUrlResult const* result);
    static void LogGetContentDownloadUrlRequest(PFContentGetContentDownloadUrlRequest const* request, const char* testName);
    static HRESULT LogGetContentDownloadUrlResult(PFContentGetContentDownloadUrlResult const* result);

    static void FillAdminDeleteContentRequest(PlayFab::Wrappers::PFContentDeleteContentRequestWrapper<>& request);

    static void FillAdminGetContentListRequest(PlayFab::Wrappers::PFContentGetContentListRequestWrapper<>& request);
    static HRESULT ValidateAdminGetContentListResponse(PFContentGetContentListResult* result);

    static void FillAdminGetContentUploadUrlRequest(PlayFab::Wrappers::PFContentGetContentUploadUrlRequestWrapper<>& request);
    static HRESULT ValidateAdminGetContentUploadUrlResponse(PFContentGetContentUploadUrlResult* result);

    static void FillClientGetContentDownloadUrlRequest(PlayFab::Wrappers::PFContentGetContentDownloadUrlRequestWrapper<>& request);
    static HRESULT ValidateClientGetContentDownloadUrlResponse(PFContentGetContentDownloadUrlResult* result);

    static void FillServerGetContentDownloadUrlRequest(PlayFab::Wrappers::PFContentGetContentDownloadUrlRequestWrapper<>& request);
    static HRESULT ValidateServerGetContentDownloadUrlResponse(PFContentGetContentDownloadUrlResult* result);

    struct ContentTestData
    {
        ~ContentTestData() = default;

    };

    static ContentTestData testData;

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
