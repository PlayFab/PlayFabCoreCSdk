#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFSharedGroupsDataModelWrappers.h>
#include "AutoGenSharedGroupsResultHolders.h"

namespace PlayFabUnit
{

class AutoGenSharedGroupsTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestSharedGroupsClientAddSharedGroupMembersPrerequisiteClientCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsClientAddSharedGroupMembers(TestContext& testContext);
    void TestSharedGroupsClientAddSharedGroupMembersCleanupClientRemoveSharedGroupMembers(TestContext& testContext);

    void TestSharedGroupsClientCreateSharedGroup(TestContext& testContext);

    void TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientUpdateSharedGroupData(TestContext& testContext);
    void TestSharedGroupsClientGetSharedGroupData(TestContext& testContext);

    void TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientAddSharedGroupMembers(TestContext& testContext);
    void TestSharedGroupsClientRemoveSharedGroupMembers(TestContext& testContext);

    void TestSharedGroupsClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsClientUpdateSharedGroupData(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestSharedGroupsServerAddSharedGroupMembers(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestSharedGroupsServerCreateSharedGroup(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestSharedGroupsServerDeleteSharedGroup(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestSharedGroupsServerGetSharedGroupData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestSharedGroupsServerRemoveSharedGroupMembers(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestSharedGroupsServerUpdateSharedGroupData(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void FillClientAddSharedGroupMembersPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientAddSharedGroupMembersPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void LogAddSharedGroupMembersRequest(PFSharedGroupsAddSharedGroupMembersRequest const* request, const char* testName);
    static void FillAddSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsAddSharedGroupMembersRequestWrapper<>& request);
    static void FillClientAddSharedGroupMembersCleanupRemoveSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<>& request);

    static void LogCreateSharedGroupRequest(PFSharedGroupsCreateSharedGroupRequest const* request, const char* testName);
    static void FillCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT LogPFSharedGroupsCreateSharedGroupResult(PFSharedGroupsCreateSharedGroupResult const* result);
    static HRESULT ValidatePFSharedGroupsCreateSharedGroupResult(PFSharedGroupsCreateSharedGroupResult* result);

    static void FillClientGetSharedGroupDataPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientGetSharedGroupDataPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillClientGetSharedGroupDataPrerequisiteUpdateSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsUpdateSharedGroupDataRequestWrapper<>& request);
    static void LogGetSharedGroupDataRequest(PFSharedGroupsGetSharedGroupDataRequest const* request, const char* testName);
    static void FillGetSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsGetSharedGroupDataRequestWrapper<>& request);
    static HRESULT LogPFSharedGroupsGetSharedGroupDataResult(PFSharedGroupsGetSharedGroupDataResult const* result);
    static HRESULT ValidatePFSharedGroupsGetSharedGroupDataResult(PFSharedGroupsGetSharedGroupDataResult* result);

    static void FillClientRemoveSharedGroupMembersPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientRemoveSharedGroupMembersPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillClientRemoveSharedGroupMembersPrerequisiteAddSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsAddSharedGroupMembersRequestWrapper<>& request);
    static void LogRemoveSharedGroupMembersRequest(PFSharedGroupsRemoveSharedGroupMembersRequest const* request, const char* testName);
    static void FillRemoveSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<>& request);

    static void FillClientUpdateSharedGroupDataPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientUpdateSharedGroupDataPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void LogUpdateSharedGroupDataRequest(PFSharedGroupsUpdateSharedGroupDataRequest const* request, const char* testName);
    static void FillUpdateSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsUpdateSharedGroupDataRequestWrapper<>& request);



    static void LogDeleteSharedGroupRequest(PFSharedGroupsDeleteSharedGroupRequest const* request, const char* testName);
    static void FillDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);




    struct SharedGroupsTestData
    {
        ~SharedGroupsTestData() = default;

        std::shared_ptr<CreateSharedGroupResultHolder> m_CreateSharedGroupResult;
    };

    static SharedGroupsTestData testData;

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
