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

    void TestProfilesGetGlobalPolicy(TestContext& testContext);

    void TestProfilesGetProfile(TestContext& testContext);

    void TestProfilesGetProfiles(TestContext& testContext);

    void TestProfilesGetTitlePlayersFromMasterPlayerAccountIds(TestContext& testContext);

    void TestProfilesSetGlobalPolicy(TestContext& testContext);

    void TestProfilesSetProfileLanguage(TestContext& testContext);

    void TestProfilesSetProfilePolicy(TestContext& testContext);


protected:
    void AddTests();

    static void LogGetGlobalPolicyRequest(PFProfilesGetGlobalPolicyRequest const* request, const char* testName);
    static void FillGetGlobalPolicyRequest(PlayFab::Wrappers::PFProfilesGetGlobalPolicyRequestWrapper<>& request);
    static HRESULT LogPFProfilesGetGlobalPolicyResponse(PFProfilesGetGlobalPolicyResponse const* result);
    static HRESULT ValidatePFProfilesGetGlobalPolicyResponse(PFProfilesGetGlobalPolicyResponse* result);

    static void LogGetEntityProfileRequest(PFProfilesGetEntityProfileRequest const* request, const char* testName);
    static void FillGetEntityProfileRequest(PlayFab::Wrappers::PFProfilesGetEntityProfileRequestWrapper<>& request);
    static HRESULT LogPFProfilesGetEntityProfileResponse(PFProfilesGetEntityProfileResponse const* result);
    static HRESULT ValidatePFProfilesGetEntityProfileResponse(PFProfilesGetEntityProfileResponse* result);

    static void LogGetEntityProfilesRequest(PFProfilesGetEntityProfilesRequest const* request, const char* testName);
    static void FillGetEntityProfilesRequest(PlayFab::Wrappers::PFProfilesGetEntityProfilesRequestWrapper<>& request);
    static HRESULT LogPFProfilesGetEntityProfilesResponse(PFProfilesGetEntityProfilesResponse const* result);
    static HRESULT ValidatePFProfilesGetEntityProfilesResponse(PFProfilesGetEntityProfilesResponse* result);

    static void LogGetTitlePlayersFromMasterPlayerAccountIdsRequest(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest const* request, const char* testName);
    static void FillGetTitlePlayersFromMasterPlayerAccountIdsRequest(PlayFab::Wrappers::PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper<>& request);
    static HRESULT LogPFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse const* result);
    static HRESULT ValidatePFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse* result);

    static void LogSetGlobalPolicyRequest(PFProfilesSetGlobalPolicyRequest const* request, const char* testName);
    static void FillSetGlobalPolicyRequest(PlayFab::Wrappers::PFProfilesSetGlobalPolicyRequestWrapper<>& request);

    static void LogSetProfileLanguageRequest(PFProfilesSetProfileLanguageRequest const* request, const char* testName);
    static void FillSetProfileLanguageRequest(PlayFab::Wrappers::PFProfilesSetProfileLanguageRequestWrapper<>& request);
    static HRESULT LogPFProfilesSetProfileLanguageResponse(PFProfilesSetProfileLanguageResponse const* result);
    static HRESULT ValidatePFProfilesSetProfileLanguageResponse(PFProfilesSetProfileLanguageResponse* result);

    static void LogSetEntityProfilePolicyRequest(PFProfilesSetEntityProfilePolicyRequest const* request, const char* testName);
    static void FillSetEntityProfilePolicyRequest(PlayFab::Wrappers::PFProfilesSetEntityProfilePolicyRequestWrapper<>& request);
    static HRESULT LogPFProfilesSetEntityProfilePolicyResponse(PFProfilesSetEntityProfilePolicyResponse const* result);
    static HRESULT ValidatePFProfilesSetEntityProfilePolicyResponse(PFProfilesSetEntityProfilePolicyResponse* result);

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
