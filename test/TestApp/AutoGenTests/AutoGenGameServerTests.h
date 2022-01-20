#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFGameServerDataModelWrappers.h>
#include "AutoGenGameServerResultHolders.h"

namespace PlayFabUnit
{

class AutoGenGameServerTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestGameServerAdminAddServerBuild(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestGameServerAdminGetServerBuildInfo(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestGameServerAdminGetServerBuildUploadUrl(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestGameServerAdminListServerBuilds(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestGameServerAdminModifyServerBuild(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestGameServerAdminRemoveServerBuild(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogAddServerBuildRequest(PFGameServerAddServerBuildRequest const* request, const char* testName);
    static HRESULT LogAddServerBuildResult(PFGameServerAddServerBuildResult const* result);
    static void LogGetServerBuildInfoRequest(PFGameServerGetServerBuildInfoRequest const* request, const char* testName);
    static HRESULT LogGetServerBuildInfoResult(PFGameServerGetServerBuildInfoResult const* result);
    static void LogGetServerBuildUploadURLRequest(PFGameServerGetServerBuildUploadURLRequest const* request, const char* testName);
    static HRESULT LogGetServerBuildUploadURLResult(PFGameServerGetServerBuildUploadURLResult const* result);
    static HRESULT LogListBuildsResult(PFGameServerListBuildsResult const* result);
    static void LogModifyServerBuildRequest(PFGameServerModifyServerBuildRequest const* request, const char* testName);
    static HRESULT LogModifyServerBuildResult(PFGameServerModifyServerBuildResult const* result);
    static void LogRemoveServerBuildRequest(PFGameServerRemoveServerBuildRequest const* request, const char* testName);

    static void FillAdminAddServerBuildRequest(PlayFab::Wrappers::PFGameServerAddServerBuildRequestWrapper<>& request);
    static HRESULT ValidateAdminAddServerBuildResponse(PFGameServerAddServerBuildResult* result);

    static void FillAdminGetServerBuildInfoRequest(PlayFab::Wrappers::PFGameServerGetServerBuildInfoRequestWrapper<>& request);
    static HRESULT ValidateAdminGetServerBuildInfoResponse(PFGameServerGetServerBuildInfoResult* result);

    static void FillAdminGetServerBuildUploadUrlRequest(PlayFab::Wrappers::PFGameServerGetServerBuildUploadURLRequestWrapper<>& request);
    static HRESULT ValidateAdminGetServerBuildUploadUrlResponse(PFGameServerGetServerBuildUploadURLResult* result);

    static HRESULT ValidateAdminListServerBuildsResponse(PFGameServerListBuildsResult* result);

    static void FillAdminModifyServerBuildRequest(PlayFab::Wrappers::PFGameServerModifyServerBuildRequestWrapper<>& request);
    static HRESULT ValidateAdminModifyServerBuildResponse(PFGameServerModifyServerBuildResult* result);

    static void FillAdminRemoveServerBuildRequest(PlayFab::Wrappers::PFGameServerRemoveServerBuildRequestWrapper<>& request);

    struct GameServerTestData
    {
        ~GameServerTestData() = default;

    };

    static GameServerTestData testData;

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
