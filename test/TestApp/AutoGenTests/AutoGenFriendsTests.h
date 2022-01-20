#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFFriendsDataModelWrappers.h>
#include "AutoGenFriendsResultHolders.h"

namespace PlayFabUnit
{

class AutoGenFriendsTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestFriendsClientAddFriend(TestContext& testContext);
    void TestFriendsClientAddFriendCleanupClientRemoveFriend(TestContext& testContext);

    void TestFriendsClientGetFriendsList(TestContext& testContext);

    void TestFriendsClientRemoveFriendPrerequisiteClientAddFriend(TestContext& testContext);
    void TestFriendsClientRemoveFriend(TestContext& testContext);

    void TestFriendsClientSetFriendTags(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestFriendsServerAddFriend(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestFriendsServerGetFriendsList(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestFriendsServerRemoveFriend(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestFriendsServerSetFriendTags(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogClientAddFriendRequest(PFFriendsClientAddFriendRequest const* request, const char* testName);
    static HRESULT LogAddFriendResult(PFFriendsAddFriendResult const* result);
    static void LogClientGetFriendsListRequest(PFFriendsClientGetFriendsListRequest const* request, const char* testName);
    static HRESULT LogGetFriendsListResult(PFFriendsGetFriendsListResult const* result);
    static void LogClientRemoveFriendRequest(PFFriendsClientRemoveFriendRequest const* request, const char* testName);
    static void LogClientSetFriendTagsRequest(PFFriendsClientSetFriendTagsRequest const* request, const char* testName);
    static void LogServerAddFriendRequest(PFFriendsServerAddFriendRequest const* request, const char* testName);
    static void LogServerGetFriendsListRequest(PFFriendsServerGetFriendsListRequest const* request, const char* testName);
    static void LogServerRemoveFriendRequest(PFFriendsServerRemoveFriendRequest const* request, const char* testName);
    static void LogServerSetFriendTagsRequest(PFFriendsServerSetFriendTagsRequest const* request, const char* testName);

    static void FillClientAddFriendRequest(PlayFab::Wrappers::PFFriendsClientAddFriendRequestWrapper<>& request);
    static HRESULT ValidateClientAddFriendResponse(PFFriendsAddFriendResult* result);
    static void FillClientAddFriendCleanupClientRemoveFriendRequest(PlayFab::Wrappers::PFFriendsClientRemoveFriendRequestWrapper<>& request);

    static void FillClientGetFriendsListRequest(PlayFab::Wrappers::PFFriendsClientGetFriendsListRequestWrapper<>& request);
    static HRESULT ValidateClientGetFriendsListResponse(PFFriendsGetFriendsListResult* result);

    static void FillClientRemoveFriendPrerequisiteClientAddFriendRequest(PlayFab::Wrappers::PFFriendsClientAddFriendRequestWrapper<>& request);
    static HRESULT StoreClientRemoveFriendPrerequisiteClientAddFriendResponse(std::shared_ptr<AddFriendResultHolder> result);
    static void FillClientRemoveFriendRequest(PlayFab::Wrappers::PFFriendsClientRemoveFriendRequestWrapper<>& request);

    static void FillClientSetFriendTagsRequest(PlayFab::Wrappers::PFFriendsClientSetFriendTagsRequestWrapper<>& request);

    static void FillServerAddFriendRequest(PlayFab::Wrappers::PFFriendsServerAddFriendRequestWrapper<>& request);

    static void FillServerGetFriendsListRequest(PlayFab::Wrappers::PFFriendsServerGetFriendsListRequestWrapper<>& request);
    static HRESULT ValidateServerGetFriendsListResponse(PFFriendsGetFriendsListResult* result);

    static void FillServerRemoveFriendRequest(PlayFab::Wrappers::PFFriendsServerRemoveFriendRequestWrapper<>& request);

    static void FillServerSetFriendTagsRequest(PlayFab::Wrappers::PFFriendsServerSetFriendTagsRequestWrapper<>& request);

    struct FriendsTestData
    {
        ~FriendsTestData() = default;

        std::shared_ptr<AddFriendResultHolder> m_AddFriendResult;
    };

    static FriendsTestData testData;

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
