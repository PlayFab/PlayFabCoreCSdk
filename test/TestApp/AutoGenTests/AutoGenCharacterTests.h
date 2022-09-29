#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFCharacterDataModelWrappers.h>
#include "AutoGenCharacterResultHolders.h"

namespace PlayFabUnit
{

class AutoGenCharacterTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterAdminResetCharacterStatistics(TestContext& testContext);
#endif

    void TestCharacterClientGetAllUsersCharacters(TestContext& testContext);

    void TestCharacterClientGetCharacterData(TestContext& testContext);

    void TestCharacterClientGetCharacterLeaderboard(TestContext& testContext);

    void TestCharacterClientGetCharacterReadOnlyData(TestContext& testContext);

    void TestCharacterClientGetCharacterStatistics(TestContext& testContext);

    void TestCharacterClientGetLeaderboardAroundCharacter(TestContext& testContext);

    void TestCharacterClientGetLeaderboardForUserCharacters(TestContext& testContext);

    void TestCharacterClientGrantCharacterToUser(TestContext& testContext);

    void TestCharacterClientUpdateCharacterData(TestContext& testContext);

    void TestCharacterClientUpdateCharacterStatistics(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerDeleteCharacterFromUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerGetAllUsersCharacters(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerGetCharacterData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerGetCharacterInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerGetCharacterLeaderboard(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerGetCharacterReadOnlyData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerGetCharacterStatistics(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerGetLeaderboardAroundCharacter(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerGetLeaderboardForUserCharacters(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerGrantCharacterToUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerUpdateCharacterData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerUpdateCharacterInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerUpdateCharacterReadOnlyData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCharacterServerUpdateCharacterStatistics(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogResetCharacterStatisticsRequest(PFCharacterResetCharacterStatisticsRequest const* request, const char* testName);
    static void LogListUsersCharactersRequest(PFCharacterListUsersCharactersRequest const* request, const char* testName);
    static HRESULT LogListUsersCharactersResult(PFCharacterListUsersCharactersResult const* result);
    static void LogGetCharacterDataRequest(PFCharacterGetCharacterDataRequest const* request, const char* testName);
    static HRESULT LogClientGetCharacterDataResult(PFCharacterClientGetCharacterDataResult const* result);
    static void LogGetCharacterLeaderboardRequest(PFCharacterGetCharacterLeaderboardRequest const* request, const char* testName);
    static HRESULT LogGetCharacterLeaderboardResult(PFCharacterGetCharacterLeaderboardResult const* result);
    static void LogClientGetCharacterStatisticsRequest(PFCharacterClientGetCharacterStatisticsRequest const* request, const char* testName);
    static HRESULT LogClientGetCharacterStatisticsResult(PFCharacterClientGetCharacterStatisticsResult const* result);
    static void LogClientGetLeaderboardAroundCharacterRequest(PFCharacterClientGetLeaderboardAroundCharacterRequest const* request, const char* testName);
    static HRESULT LogGetLeaderboardAroundCharacterResult(PFCharacterGetLeaderboardAroundCharacterResult const* result);
    static void LogClientGetLeaderboardForUsersCharactersRequest(PFCharacterClientGetLeaderboardForUsersCharactersRequest const* request, const char* testName);
    static HRESULT LogGetLeaderboardForUsersCharactersResult(PFCharacterGetLeaderboardForUsersCharactersResult const* result);
    static void LogClientGrantCharacterToUserRequest(PFCharacterClientGrantCharacterToUserRequest const* request, const char* testName);
    static HRESULT LogClientGrantCharacterToUserResult(PFCharacterClientGrantCharacterToUserResult const* result);
    static void LogClientUpdateCharacterDataRequest(PFCharacterClientUpdateCharacterDataRequest const* request, const char* testName);
    static HRESULT LogUpdateCharacterDataResult(PFCharacterUpdateCharacterDataResult const* result);
    static void LogClientUpdateCharacterStatisticsRequest(PFCharacterClientUpdateCharacterStatisticsRequest const* request, const char* testName);
    static void LogDeleteCharacterFromUserRequest(PFCharacterDeleteCharacterFromUserRequest const* request, const char* testName);
    static HRESULT LogServerGetCharacterDataResult(PFCharacterServerGetCharacterDataResult const* result);
    static void LogServerGetCharacterStatisticsRequest(PFCharacterServerGetCharacterStatisticsRequest const* request, const char* testName);
    static HRESULT LogServerGetCharacterStatisticsResult(PFCharacterServerGetCharacterStatisticsResult const* result);
    static void LogServerGetLeaderboardAroundCharacterRequest(PFCharacterServerGetLeaderboardAroundCharacterRequest const* request, const char* testName);
    static void LogServerGetLeaderboardForUsersCharactersRequest(PFCharacterServerGetLeaderboardForUsersCharactersRequest const* request, const char* testName);
    static void LogServerGrantCharacterToUserRequest(PFCharacterServerGrantCharacterToUserRequest const* request, const char* testName);
    static HRESULT LogServerGrantCharacterToUserResult(PFCharacterServerGrantCharacterToUserResult const* result);
    static void LogServerUpdateCharacterDataRequest(PFCharacterServerUpdateCharacterDataRequest const* request, const char* testName);
    static void LogServerUpdateCharacterStatisticsRequest(PFCharacterServerUpdateCharacterStatisticsRequest const* request, const char* testName);

    void FillAdminResetCharacterStatisticsRequest(PlayFab::Wrappers::PFCharacterResetCharacterStatisticsRequestWrapper<>& request);

    void FillClientGetAllUsersCharactersRequest(PlayFab::Wrappers::PFCharacterListUsersCharactersRequestWrapper<>& request);
    static HRESULT ValidateClientGetAllUsersCharactersResponse(PFCharacterListUsersCharactersResult* result);

    void FillClientGetCharacterDataRequest(PlayFab::Wrappers::PFCharacterGetCharacterDataRequestWrapper<>& request);
    static HRESULT ValidateClientGetCharacterDataResponse(PFCharacterClientGetCharacterDataResult* result);

    void FillClientGetCharacterLeaderboardRequest(PlayFab::Wrappers::PFCharacterGetCharacterLeaderboardRequestWrapper<>& request);
    static HRESULT ValidateClientGetCharacterLeaderboardResponse(PFCharacterGetCharacterLeaderboardResult* result);

    void FillClientGetCharacterReadOnlyDataRequest(PlayFab::Wrappers::PFCharacterGetCharacterDataRequestWrapper<>& request);
    static HRESULT ValidateClientGetCharacterReadOnlyDataResponse(PFCharacterClientGetCharacterDataResult* result);

    void FillClientGetCharacterStatisticsRequest(PlayFab::Wrappers::PFCharacterClientGetCharacterStatisticsRequestWrapper<>& request);
    static HRESULT ValidateClientGetCharacterStatisticsResponse(PFCharacterClientGetCharacterStatisticsResult* result);

    void FillClientGetLeaderboardAroundCharacterRequest(PlayFab::Wrappers::PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper<>& request);
    static HRESULT ValidateClientGetLeaderboardAroundCharacterResponse(PFCharacterGetLeaderboardAroundCharacterResult* result);

    void FillClientGetLeaderboardForUserCharactersRequest(PlayFab::Wrappers::PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper<>& request);
    static HRESULT ValidateClientGetLeaderboardForUserCharactersResponse(PFCharacterGetLeaderboardForUsersCharactersResult* result);

    void FillClientGrantCharacterToUserRequest(PlayFab::Wrappers::PFCharacterClientGrantCharacterToUserRequestWrapper<>& request);
    static HRESULT ValidateClientGrantCharacterToUserResponse(PFCharacterClientGrantCharacterToUserResult* result);

    void FillClientUpdateCharacterDataRequest(PlayFab::Wrappers::PFCharacterClientUpdateCharacterDataRequestWrapper<>& request);
    static HRESULT ValidateClientUpdateCharacterDataResponse(PFCharacterUpdateCharacterDataResult* result);

    void FillClientUpdateCharacterStatisticsRequest(PlayFab::Wrappers::PFCharacterClientUpdateCharacterStatisticsRequestWrapper<>& request);

    void FillServerDeleteCharacterFromUserRequest(PlayFab::Wrappers::PFCharacterDeleteCharacterFromUserRequestWrapper<>& request);

    void FillServerGetAllUsersCharactersRequest(PlayFab::Wrappers::PFCharacterListUsersCharactersRequestWrapper<>& request);
    static HRESULT ValidateServerGetAllUsersCharactersResponse(PFCharacterListUsersCharactersResult* result);

    void FillServerGetCharacterDataRequest(PlayFab::Wrappers::PFCharacterGetCharacterDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetCharacterDataResponse(PFCharacterServerGetCharacterDataResult* result);

    void FillServerGetCharacterInternalDataRequest(PlayFab::Wrappers::PFCharacterGetCharacterDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetCharacterInternalDataResponse(PFCharacterServerGetCharacterDataResult* result);

    void FillServerGetCharacterLeaderboardRequest(PlayFab::Wrappers::PFCharacterGetCharacterLeaderboardRequestWrapper<>& request);
    static HRESULT ValidateServerGetCharacterLeaderboardResponse(PFCharacterGetCharacterLeaderboardResult* result);

    void FillServerGetCharacterReadOnlyDataRequest(PlayFab::Wrappers::PFCharacterGetCharacterDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetCharacterReadOnlyDataResponse(PFCharacterServerGetCharacterDataResult* result);

    void FillServerGetCharacterStatisticsRequest(PlayFab::Wrappers::PFCharacterServerGetCharacterStatisticsRequestWrapper<>& request);
    static HRESULT ValidateServerGetCharacterStatisticsResponse(PFCharacterServerGetCharacterStatisticsResult* result);

    void FillServerGetLeaderboardAroundCharacterRequest(PlayFab::Wrappers::PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper<>& request);
    static HRESULT ValidateServerGetLeaderboardAroundCharacterResponse(PFCharacterGetLeaderboardAroundCharacterResult* result);

    void FillServerGetLeaderboardForUserCharactersRequest(PlayFab::Wrappers::PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper<>& request);
    static HRESULT ValidateServerGetLeaderboardForUserCharactersResponse(PFCharacterGetLeaderboardForUsersCharactersResult* result);

    void FillServerGrantCharacterToUserRequest(PlayFab::Wrappers::PFCharacterServerGrantCharacterToUserRequestWrapper<>& request);
    static HRESULT ValidateServerGrantCharacterToUserResponse(PFCharacterServerGrantCharacterToUserResult* result);

    void FillServerUpdateCharacterDataRequest(PlayFab::Wrappers::PFCharacterServerUpdateCharacterDataRequestWrapper<>& request);
    static HRESULT ValidateServerUpdateCharacterDataResponse(PFCharacterUpdateCharacterDataResult* result);

    void FillServerUpdateCharacterInternalDataRequest(PlayFab::Wrappers::PFCharacterServerUpdateCharacterDataRequestWrapper<>& request);
    static HRESULT ValidateServerUpdateCharacterInternalDataResponse(PFCharacterUpdateCharacterDataResult* result);

    void FillServerUpdateCharacterReadOnlyDataRequest(PlayFab::Wrappers::PFCharacterServerUpdateCharacterDataRequestWrapper<>& request);
    static HRESULT ValidateServerUpdateCharacterReadOnlyDataResponse(PFCharacterUpdateCharacterDataResult* result);

    void FillServerUpdateCharacterStatisticsRequest(PlayFab::Wrappers::PFCharacterServerUpdateCharacterStatisticsRequestWrapper<>& request);

    struct CharacterTestData
    {
        ~CharacterTestData() = default;

    };

    static CharacterTestData testData;

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
