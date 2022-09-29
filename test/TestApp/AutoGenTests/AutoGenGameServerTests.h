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
    void TestGameServerAdminModifyServerBuild(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogModifyServerBuildRequest(PFGameServerModifyServerBuildRequest const* request, const char* testName);
    static HRESULT LogModifyServerBuildResult(PFGameServerModifyServerBuildResult const* result);

    void FillAdminModifyServerBuildRequest(PlayFab::Wrappers::PFGameServerModifyServerBuildRequestWrapper<>& request);
    static HRESULT ValidateAdminModifyServerBuildResponse(PFGameServerModifyServerBuildResult* result);

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
