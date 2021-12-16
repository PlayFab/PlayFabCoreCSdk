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
    static void FillAddServerBuildRequest(PlayFab::Wrappers::PFGameServerAddServerBuildRequestWrapper<>& request);
    static HRESULT LogPFGameServerAddServerBuildResult(PFGameServerAddServerBuildResult const* result);
    static HRESULT ValidatePFGameServerAddServerBuildResult(PFGameServerAddServerBuildResult* result);

    static void LogGetServerBuildInfoRequest(PFGameServerGetServerBuildInfoRequest const* request, const char* testName);
    static void FillGetServerBuildInfoRequest(PlayFab::Wrappers::PFGameServerGetServerBuildInfoRequestWrapper<>& request);
    static HRESULT LogPFGameServerGetServerBuildInfoResult(PFGameServerGetServerBuildInfoResult const* result);
    static HRESULT ValidatePFGameServerGetServerBuildInfoResult(PFGameServerGetServerBuildInfoResult* result);

    static void LogGetServerBuildUploadURLRequest(PFGameServerGetServerBuildUploadURLRequest const* request, const char* testName);
    static void FillGetServerBuildUploadURLRequest(PlayFab::Wrappers::PFGameServerGetServerBuildUploadURLRequestWrapper<>& request);
    static HRESULT LogPFGameServerGetServerBuildUploadURLResult(PFGameServerGetServerBuildUploadURLResult const* result);
    static HRESULT ValidatePFGameServerGetServerBuildUploadURLResult(PFGameServerGetServerBuildUploadURLResult* result);

    static HRESULT LogPFGameServerListBuildsResult(PFGameServerListBuildsResult const* result);
    static HRESULT ValidatePFGameServerListBuildsResult(PFGameServerListBuildsResult* result);

    static void LogModifyServerBuildRequest(PFGameServerModifyServerBuildRequest const* request, const char* testName);
    static void FillModifyServerBuildRequest(PlayFab::Wrappers::PFGameServerModifyServerBuildRequestWrapper<>& request);
    static HRESULT LogPFGameServerModifyServerBuildResult(PFGameServerModifyServerBuildResult const* result);
    static HRESULT ValidatePFGameServerModifyServerBuildResult(PFGameServerModifyServerBuildResult* result);

    static void LogRemoveServerBuildRequest(PFGameServerRemoveServerBuildRequest const* request, const char* testName);
    static void FillRemoveServerBuildRequest(PlayFab::Wrappers::PFGameServerRemoveServerBuildRequestWrapper<>& request);

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
