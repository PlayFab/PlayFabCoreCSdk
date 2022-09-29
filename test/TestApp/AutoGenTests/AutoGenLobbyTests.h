#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFLobbyDataModelWrappers.h>
#include "AutoGenLobbyResultHolders.h"

namespace PlayFabUnit
{

class AutoGenLobbyTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestLobbyCreateLobby(TestContext& testContext);

    void TestLobbyDeleteLobby(TestContext& testContext);

    void TestLobbyFindFriendLobbies(TestContext& testContext);

    void TestLobbyFindLobbies(TestContext& testContext);

    void TestLobbyGetLobby(TestContext& testContext);

    void TestLobbyInviteToLobby(TestContext& testContext);

    void TestLobbyJoinArrangedLobby(TestContext& testContext);

    void TestLobbyJoinLobby(TestContext& testContext);

    void TestLobbyLeaveLobby(TestContext& testContext);

    void TestLobbyRemoveMember(TestContext& testContext);

    void TestLobbySubscribeToLobbyResource(TestContext& testContext);

    void TestLobbyUnsubscribeFromLobbyResource(TestContext& testContext);

    void TestLobbyUpdateLobby(TestContext& testContext);


protected:
    void AddTests();

    static void LogCreateLobbyRequest(PFLobbyCreateLobbyRequest const* request, const char* testName);
    static HRESULT LogCreateLobbyResult(PFLobbyCreateLobbyResult const* result);
    static void LogDeleteLobbyRequest(PFLobbyDeleteLobbyRequest const* request, const char* testName);
    static void LogFindFriendLobbiesRequest(PFLobbyFindFriendLobbiesRequest const* request, const char* testName);
    static HRESULT LogFindFriendLobbiesResult(PFLobbyFindFriendLobbiesResult const* result);
    static void LogFindLobbiesRequest(PFLobbyFindLobbiesRequest const* request, const char* testName);
    static HRESULT LogFindLobbiesResult(PFLobbyFindLobbiesResult const* result);
    static void LogGetLobbyRequest(PFLobbyGetLobbyRequest const* request, const char* testName);
    static HRESULT LogGetLobbyResult(PFLobbyGetLobbyResult const* result);
    static void LogInviteToLobbyRequest(PFLobbyInviteToLobbyRequest const* request, const char* testName);
    static void LogJoinArrangedLobbyRequest(PFLobbyJoinArrangedLobbyRequest const* request, const char* testName);
    static HRESULT LogJoinLobbyResult(PFLobbyJoinLobbyResult const* result);
    static void LogJoinLobbyRequest(PFLobbyJoinLobbyRequest const* request, const char* testName);
    static void LogLeaveLobbyRequest(PFLobbyLeaveLobbyRequest const* request, const char* testName);
    static void LogRemoveMemberFromLobbyRequest(PFLobbyRemoveMemberFromLobbyRequest const* request, const char* testName);
    static void LogSubscribeToLobbyResourceRequest(PFLobbySubscribeToLobbyResourceRequest const* request, const char* testName);
    static HRESULT LogSubscribeToLobbyResourceResult(PFLobbySubscribeToLobbyResourceResult const* result);
    static void LogUnsubscribeFromLobbyResourceRequest(PFLobbyUnsubscribeFromLobbyResourceRequest const* request, const char* testName);
    static void LogUpdateLobbyRequest(PFLobbyUpdateLobbyRequest const* request, const char* testName);

    void FillCreateLobbyRequest(PlayFab::Wrappers::PFLobbyCreateLobbyRequestWrapper<>& request);
    static HRESULT ValidateCreateLobbyResponse(PFLobbyCreateLobbyResult* result);

    void FillDeleteLobbyRequest(PlayFab::Wrappers::PFLobbyDeleteLobbyRequestWrapper<>& request);

    void FillFindFriendLobbiesRequest(PlayFab::Wrappers::PFLobbyFindFriendLobbiesRequestWrapper<>& request);
    static HRESULT ValidateFindFriendLobbiesResponse(PFLobbyFindFriendLobbiesResult* result);

    void FillFindLobbiesRequest(PlayFab::Wrappers::PFLobbyFindLobbiesRequestWrapper<>& request);
    static HRESULT ValidateFindLobbiesResponse(PFLobbyFindLobbiesResult* result);

    void FillGetLobbyRequest(PlayFab::Wrappers::PFLobbyGetLobbyRequestWrapper<>& request);
    static HRESULT ValidateGetLobbyResponse(PFLobbyGetLobbyResult* result);

    void FillInviteToLobbyRequest(PlayFab::Wrappers::PFLobbyInviteToLobbyRequestWrapper<>& request);

    void FillJoinArrangedLobbyRequest(PlayFab::Wrappers::PFLobbyJoinArrangedLobbyRequestWrapper<>& request);
    static HRESULT ValidateJoinArrangedLobbyResponse(PFLobbyJoinLobbyResult* result);

    void FillJoinLobbyRequest(PlayFab::Wrappers::PFLobbyJoinLobbyRequestWrapper<>& request);
    static HRESULT ValidateJoinLobbyResponse(PFLobbyJoinLobbyResult* result);

    void FillLeaveLobbyRequest(PlayFab::Wrappers::PFLobbyLeaveLobbyRequestWrapper<>& request);

    void FillRemoveMemberRequest(PlayFab::Wrappers::PFLobbyRemoveMemberFromLobbyRequestWrapper<>& request);

    void FillSubscribeToLobbyResourceRequest(PlayFab::Wrappers::PFLobbySubscribeToLobbyResourceRequestWrapper<>& request);
    static HRESULT ValidateSubscribeToLobbyResourceResponse(PFLobbySubscribeToLobbyResourceResult* result);

    void FillUnsubscribeFromLobbyResourceRequest(PlayFab::Wrappers::PFLobbyUnsubscribeFromLobbyResourceRequestWrapper<>& request);

    void FillUpdateLobbyRequest(PlayFab::Wrappers::PFLobbyUpdateLobbyRequestWrapper<>& request);

    struct LobbyTestData
    {
        ~LobbyTestData() = default;

    };

    static LobbyTestData testData;

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
