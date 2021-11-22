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

    void TestContentAdminDeleteContent(TestContext& testContext);

    void TestContentAdminGetContentList(TestContext& testContext);

    void TestContentAdminGetContentUploadUrl(TestContext& testContext);

    void TestContentClientGetContentDownloadUrl(TestContext& testContext);

    void TestContentServerGetContentDownloadUrl(TestContext& testContext);


protected:
    void AddTests();

    static void LogDeleteContentRequest(PFContentDeleteContentRequest const* request, const char* testName);
    static void FillDeleteContentRequest(PlayFab::Wrappers::PFContentDeleteContentRequestWrapper<>& request);

    static void LogGetContentListRequest(PFContentGetContentListRequest const* request, const char* testName);
    static void FillGetContentListRequest(PlayFab::Wrappers::PFContentGetContentListRequestWrapper<>& request);
    static HRESULT LogPFContentGetContentListResult(PFContentGetContentListResult const* result);
    static HRESULT ValidatePFContentGetContentListResult(PFContentGetContentListResult* result);

    static void LogGetContentUploadUrlRequest(PFContentGetContentUploadUrlRequest const* request, const char* testName);
    static void FillGetContentUploadUrlRequest(PlayFab::Wrappers::PFContentGetContentUploadUrlRequestWrapper<>& request);
    static HRESULT LogPFContentGetContentUploadUrlResult(PFContentGetContentUploadUrlResult const* result);
    static HRESULT ValidatePFContentGetContentUploadUrlResult(PFContentGetContentUploadUrlResult* result);

    static void LogGetContentDownloadUrlRequest(PFContentGetContentDownloadUrlRequest const* request, const char* testName);
    static void FillGetContentDownloadUrlRequest(PlayFab::Wrappers::PFContentGetContentDownloadUrlRequestWrapper<>& request);
    static HRESULT LogPFContentGetContentDownloadUrlResult(PFContentGetContentDownloadUrlResult const* result);
    static HRESULT ValidatePFContentGetContentDownloadUrlResult(PFContentGetContentDownloadUrlResult* result);


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
