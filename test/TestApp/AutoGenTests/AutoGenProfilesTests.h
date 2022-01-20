#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFProfilesDataModelWrappers.h>
#include "AutoGenProfilesResultHolders.h"

namespace PlayFabUnit
{

class AutoGenProfilesTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestProfilesGetGlobalPolicy(TestContext& testContext);
#endif

    void TestProfilesGetProfile(TestContext& testContext);

    void TestProfilesGetProfiles(TestContext& testContext);

    void TestProfilesGetTitlePlayersFromMasterPlayerAccountIds(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestProfilesSetGlobalPolicy(TestContext& testContext);
#endif

    void TestProfilesSetProfileLanguage(TestContext& testContext);

    void TestProfilesSetProfilePolicy(TestContext& testContext);


protected:
    void AddTests();

    static void LogGetGlobalPolicyRequest(PFProfilesGetGlobalPolicyRequest const* request, const char* testName);
    static HRESULT LogGetGlobalPolicyResponse(PFProfilesGetGlobalPolicyResponse const* result);
    static void LogGetEntityProfileRequest(PFProfilesGetEntityProfileRequest const* request, const char* testName);
    static HRESULT LogGetEntityProfileResponse(PFProfilesGetEntityProfileResponse const* result);
    static void LogGetEntityProfilesRequest(PFProfilesGetEntityProfilesRequest const* request, const char* testName);
    static HRESULT LogGetEntityProfilesResponse(PFProfilesGetEntityProfilesResponse const* result);
    static void LogGetTitlePlayersFromMasterPlayerAccountIdsRequest(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest const* request, const char* testName);
    static HRESULT LogGetTitlePlayersFromMasterPlayerAccountIdsResponse(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse const* result);
    static void LogSetGlobalPolicyRequest(PFProfilesSetGlobalPolicyRequest const* request, const char* testName);
    static void LogSetProfileLanguageRequest(PFProfilesSetProfileLanguageRequest const* request, const char* testName);
    static HRESULT LogSetProfileLanguageResponse(PFProfilesSetProfileLanguageResponse const* result);
    static void LogSetEntityProfilePolicyRequest(PFProfilesSetEntityProfilePolicyRequest const* request, const char* testName);
    static HRESULT LogSetEntityProfilePolicyResponse(PFProfilesSetEntityProfilePolicyResponse const* result);

    static void FillGetGlobalPolicyRequest(PlayFab::Wrappers::PFProfilesGetGlobalPolicyRequestWrapper<>& request);
    static HRESULT ValidateGetGlobalPolicyResponse(PFProfilesGetGlobalPolicyResponse* result);

    static void FillGetProfileRequest(PlayFab::Wrappers::PFProfilesGetEntityProfileRequestWrapper<>& request);
    static HRESULT ValidateGetProfileResponse(PFProfilesGetEntityProfileResponse* result);

    static void FillGetProfilesRequest(PlayFab::Wrappers::PFProfilesGetEntityProfilesRequestWrapper<>& request);
    static HRESULT ValidateGetProfilesResponse(PFProfilesGetEntityProfilesResponse* result);

    static void FillGetTitlePlayersFromMasterPlayerAccountIdsRequest(PlayFab::Wrappers::PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper<>& request);
    static HRESULT ValidateGetTitlePlayersFromMasterPlayerAccountIdsResponse(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse* result);

    static void FillSetGlobalPolicyRequest(PlayFab::Wrappers::PFProfilesSetGlobalPolicyRequestWrapper<>& request);

    static void FillSetProfileLanguageRequest(PlayFab::Wrappers::PFProfilesSetProfileLanguageRequestWrapper<>& request);
    static HRESULT ValidateSetProfileLanguageResponse(PFProfilesSetProfileLanguageResponse* result);

    static void FillSetProfilePolicyRequest(PlayFab::Wrappers::PFProfilesSetEntityProfilePolicyRequestWrapper<>& request);
    static HRESULT ValidateSetProfilePolicyResponse(PFProfilesSetEntityProfilePolicyResponse* result);

    struct ProfilesTestData
    {
        ~ProfilesTestData() = default;

    };

    static ProfilesTestData testData;

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
