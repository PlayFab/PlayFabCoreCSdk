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

    void TestCharacterAdminResetCharacterStatistics(TestContext& testContext);

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

    void TestCharacterServerDeleteCharacterFromUser(TestContext& testContext);

    void TestCharacterServerGetAllUsersCharacters(TestContext& testContext);

    void TestCharacterServerGetCharacterData(TestContext& testContext);

    void TestCharacterServerGetCharacterInternalData(TestContext& testContext);

    void TestCharacterServerGetCharacterLeaderboard(TestContext& testContext);

    void TestCharacterServerGetCharacterReadOnlyData(TestContext& testContext);

    void TestCharacterServerGetCharacterStatistics(TestContext& testContext);

    void TestCharacterServerGetLeaderboardAroundCharacter(TestContext& testContext);

    void TestCharacterServerGetLeaderboardForUserCharacters(TestContext& testContext);

    void TestCharacterServerGrantCharacterToUser(TestContext& testContext);

    void TestCharacterServerUpdateCharacterData(TestContext& testContext);

    void TestCharacterServerUpdateCharacterInternalData(TestContext& testContext);

    void TestCharacterServerUpdateCharacterReadOnlyData(TestContext& testContext);

    void TestCharacterServerUpdateCharacterStatistics(TestContext& testContext);


protected:
    void AddTests();

    static void LogResetCharacterStatisticsRequest(PFCharacterResetCharacterStatisticsRequest const* request, const char* testName);
    static void FillResetCharacterStatisticsRequest(PlayFab::Wrappers::PFCharacterResetCharacterStatisticsRequestWrapper<>& request);

    static void LogListUsersCharactersRequest(PFCharacterListUsersCharactersRequest const* request, const char* testName);
    static void FillListUsersCharactersRequest(PlayFab::Wrappers::PFCharacterListUsersCharactersRequestWrapper<>& request);
    static HRESULT LogPFCharacterListUsersCharactersResult(PFCharacterListUsersCharactersResult const* result);
    static HRESULT ValidatePFCharacterListUsersCharactersResult(PFCharacterListUsersCharactersResult* result);

    static void LogGetCharacterDataRequest(PFCharacterGetCharacterDataRequest const* request, const char* testName);
    static void FillGetCharacterDataRequest(PlayFab::Wrappers::PFCharacterGetCharacterDataRequestWrapper<>& request);
    static HRESULT LogPFCharacterClientGetCharacterDataResult(PFCharacterClientGetCharacterDataResult const* result);
    static HRESULT ValidatePFCharacterClientGetCharacterDataResult(PFCharacterClientGetCharacterDataResult* result);

    static void LogGetCharacterLeaderboardRequest(PFCharacterGetCharacterLeaderboardRequest const* request, const char* testName);
    static void FillGetCharacterLeaderboardRequest(PlayFab::Wrappers::PFCharacterGetCharacterLeaderboardRequestWrapper<>& request);
    static HRESULT LogPFCharacterGetCharacterLeaderboardResult(PFCharacterGetCharacterLeaderboardResult const* result);
    static HRESULT ValidatePFCharacterGetCharacterLeaderboardResult(PFCharacterGetCharacterLeaderboardResult* result);


    static void LogClientGetCharacterStatisticsRequest(PFCharacterClientGetCharacterStatisticsRequest const* request, const char* testName);
    static void FillClientGetCharacterStatisticsRequest(PlayFab::Wrappers::PFCharacterClientGetCharacterStatisticsRequestWrapper<>& request);
    static HRESULT LogPFCharacterClientGetCharacterStatisticsResult(PFCharacterClientGetCharacterStatisticsResult const* result);
    static HRESULT ValidatePFCharacterClientGetCharacterStatisticsResult(PFCharacterClientGetCharacterStatisticsResult* result);

    static void LogClientGetLeaderboardAroundCharacterRequest(PFCharacterClientGetLeaderboardAroundCharacterRequest const* request, const char* testName);
    static void FillClientGetLeaderboardAroundCharacterRequest(PlayFab::Wrappers::PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper<>& request);
    static HRESULT LogPFCharacterGetLeaderboardAroundCharacterResult(PFCharacterGetLeaderboardAroundCharacterResult const* result);
    static HRESULT ValidatePFCharacterGetLeaderboardAroundCharacterResult(PFCharacterGetLeaderboardAroundCharacterResult* result);

    static void LogClientGetLeaderboardForUsersCharactersRequest(PFCharacterClientGetLeaderboardForUsersCharactersRequest const* request, const char* testName);
    static void FillClientGetLeaderboardForUsersCharactersRequest(PlayFab::Wrappers::PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper<>& request);
    static HRESULT LogPFCharacterGetLeaderboardForUsersCharactersResult(PFCharacterGetLeaderboardForUsersCharactersResult const* result);
    static HRESULT ValidatePFCharacterGetLeaderboardForUsersCharactersResult(PFCharacterGetLeaderboardForUsersCharactersResult* result);

    static void LogClientGrantCharacterToUserRequest(PFCharacterClientGrantCharacterToUserRequest const* request, const char* testName);
    static void FillClientGrantCharacterToUserRequest(PlayFab::Wrappers::PFCharacterClientGrantCharacterToUserRequestWrapper<>& request);
    static HRESULT LogPFCharacterClientGrantCharacterToUserResult(PFCharacterClientGrantCharacterToUserResult const* result);
    static HRESULT ValidatePFCharacterClientGrantCharacterToUserResult(PFCharacterClientGrantCharacterToUserResult* result);

    static void LogClientUpdateCharacterDataRequest(PFCharacterClientUpdateCharacterDataRequest const* request, const char* testName);
    static void FillClientUpdateCharacterDataRequest(PlayFab::Wrappers::PFCharacterClientUpdateCharacterDataRequestWrapper<>& request);
    static HRESULT LogPFCharacterUpdateCharacterDataResult(PFCharacterUpdateCharacterDataResult const* result);
    static HRESULT ValidatePFCharacterUpdateCharacterDataResult(PFCharacterUpdateCharacterDataResult* result);

    static void LogClientUpdateCharacterStatisticsRequest(PFCharacterClientUpdateCharacterStatisticsRequest const* request, const char* testName);
    static void FillClientUpdateCharacterStatisticsRequest(PlayFab::Wrappers::PFCharacterClientUpdateCharacterStatisticsRequestWrapper<>& request);

    static void LogDeleteCharacterFromUserRequest(PFCharacterDeleteCharacterFromUserRequest const* request, const char* testName);
    static void FillDeleteCharacterFromUserRequest(PlayFab::Wrappers::PFCharacterDeleteCharacterFromUserRequestWrapper<>& request);


    static HRESULT LogPFCharacterServerGetCharacterDataResult(PFCharacterServerGetCharacterDataResult const* result);
    static HRESULT ValidatePFCharacterServerGetCharacterDataResult(PFCharacterServerGetCharacterDataResult* result);




    static void LogServerGetCharacterStatisticsRequest(PFCharacterServerGetCharacterStatisticsRequest const* request, const char* testName);
    static void FillServerGetCharacterStatisticsRequest(PlayFab::Wrappers::PFCharacterServerGetCharacterStatisticsRequestWrapper<>& request);
    static HRESULT LogPFCharacterServerGetCharacterStatisticsResult(PFCharacterServerGetCharacterStatisticsResult const* result);
    static HRESULT ValidatePFCharacterServerGetCharacterStatisticsResult(PFCharacterServerGetCharacterStatisticsResult* result);

    static void LogServerGetLeaderboardAroundCharacterRequest(PFCharacterServerGetLeaderboardAroundCharacterRequest const* request, const char* testName);
    static void FillServerGetLeaderboardAroundCharacterRequest(PlayFab::Wrappers::PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper<>& request);

    static void LogServerGetLeaderboardForUsersCharactersRequest(PFCharacterServerGetLeaderboardForUsersCharactersRequest const* request, const char* testName);
    static void FillServerGetLeaderboardForUsersCharactersRequest(PlayFab::Wrappers::PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper<>& request);

    static void LogServerGrantCharacterToUserRequest(PFCharacterServerGrantCharacterToUserRequest const* request, const char* testName);
    static void FillServerGrantCharacterToUserRequest(PlayFab::Wrappers::PFCharacterServerGrantCharacterToUserRequestWrapper<>& request);
    static HRESULT LogPFCharacterServerGrantCharacterToUserResult(PFCharacterServerGrantCharacterToUserResult const* result);
    static HRESULT ValidatePFCharacterServerGrantCharacterToUserResult(PFCharacterServerGrantCharacterToUserResult* result);

    static void LogServerUpdateCharacterDataRequest(PFCharacterServerUpdateCharacterDataRequest const* request, const char* testName);
    static void FillServerUpdateCharacterDataRequest(PlayFab::Wrappers::PFCharacterServerUpdateCharacterDataRequestWrapper<>& request);



    static void LogServerUpdateCharacterStatisticsRequest(PFCharacterServerUpdateCharacterStatisticsRequest const* request, const char* testName);
    static void FillServerUpdateCharacterStatisticsRequest(PlayFab::Wrappers::PFCharacterServerUpdateCharacterStatisticsRequestWrapper<>& request);

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
