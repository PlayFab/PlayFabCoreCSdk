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
    void TestSharedGroupsClientAddSharedGroupMembersCleanupServerDeleteSharedGroup(TestContext& testContext);

    void TestSharedGroupsClientCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsClientCreateSharedGroupCleanupServerDeleteSharedGroup(TestContext& testContext);

    void TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientUpdateSharedGroupData(TestContext& testContext);
    void TestSharedGroupsClientGetSharedGroupData(TestContext& testContext);
    void TestSharedGroupsClientGetSharedGroupDataCleanupServerDeleteSharedGroup(TestContext& testContext);

    void TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientAddSharedGroupMembers(TestContext& testContext);
    void TestSharedGroupsClientRemoveSharedGroupMembers(TestContext& testContext);
    void TestSharedGroupsClientRemoveSharedGroupMembersCleanupServerDeleteSharedGroup(TestContext& testContext);

    void TestSharedGroupsClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsClientUpdateSharedGroupData(TestContext& testContext);
    void TestSharedGroupsClientUpdateSharedGroupDataCleanupServerDeleteSharedGroup(TestContext& testContext);

    void TestSharedGroupsServerAddSharedGroupMembersPrerequisiteServerCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsServerAddSharedGroupMembers(TestContext& testContext);
    void TestSharedGroupsServerAddSharedGroupMembersCleanupServerRemoveSharedGroupMembers(TestContext& testContext);
    void TestSharedGroupsServerAddSharedGroupMembersCleanupServerDeleteSharedGroup(TestContext& testContext);

    void TestSharedGroupsServerCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsServerCreateSharedGroupCleanupServerDeleteSharedGroup(TestContext& testContext);

    void TestSharedGroupsServerDeleteSharedGroupPrerequisiteServerCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsServerDeleteSharedGroup(TestContext& testContext);

    void TestSharedGroupsServerGetSharedGroupDataPrerequisiteClientCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsServerGetSharedGroupDataPrerequisiteServerUpdateSharedGroupData(TestContext& testContext);
    void TestSharedGroupsServerGetSharedGroupData(TestContext& testContext);
    void TestSharedGroupsServerGetSharedGroupDataCleanupServerDeleteSharedGroup(TestContext& testContext);

    void TestSharedGroupsServerRemoveSharedGroupMembersPrerequisiteServerCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsServerRemoveSharedGroupMembersPrerequisiteServerAddSharedGroupMembers(TestContext& testContext);
    void TestSharedGroupsServerRemoveSharedGroupMembers(TestContext& testContext);
    void TestSharedGroupsServerRemoveSharedGroupMembersCleanupServerDeleteSharedGroup(TestContext& testContext);

    void TestSharedGroupsServerUpdateSharedGroupDataPrerequisiteServerCreateSharedGroup(TestContext& testContext);
    void TestSharedGroupsServerUpdateSharedGroupData(TestContext& testContext);
    void TestSharedGroupsServerUpdateSharedGroupDataCleanupServerDeleteSharedGroup(TestContext& testContext);


protected:
    void AddTests();

    static void FillClientAddSharedGroupMembersPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientAddSharedGroupMembersPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void LogAddSharedGroupMembersRequest(PFSharedGroupsAddSharedGroupMembersRequest const* request, const char* testName);
    static void FillAddSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsAddSharedGroupMembersRequestWrapper<>& request);
    static void FillClientAddSharedGroupMembersCleanupRemoveSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<>& request);
    static void FillClientAddSharedGroupMembersCleanupDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

    static void LogCreateSharedGroupRequest(PFSharedGroupsCreateSharedGroupRequest const* request, const char* testName);
    static void FillCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT LogPFSharedGroupsCreateSharedGroupResult(PFSharedGroupsCreateSharedGroupResult const* result);
    static HRESULT ValidatePFSharedGroupsCreateSharedGroupResult(PFSharedGroupsCreateSharedGroupResult* result);
    static void FillClientCreateSharedGroupCleanupDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

    static void FillClientGetSharedGroupDataPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientGetSharedGroupDataPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillClientGetSharedGroupDataPrerequisiteUpdateSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsUpdateSharedGroupDataRequestWrapper<>& request);
    static void LogGetSharedGroupDataRequest(PFSharedGroupsGetSharedGroupDataRequest const* request, const char* testName);
    static void FillGetSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsGetSharedGroupDataRequestWrapper<>& request);
    static HRESULT LogPFSharedGroupsGetSharedGroupDataResult(PFSharedGroupsGetSharedGroupDataResult const* result);
    static HRESULT ValidatePFSharedGroupsGetSharedGroupDataResult(PFSharedGroupsGetSharedGroupDataResult* result);
    static void FillClientGetSharedGroupDataCleanupDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

    static void FillClientRemoveSharedGroupMembersPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientRemoveSharedGroupMembersPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillClientRemoveSharedGroupMembersPrerequisiteAddSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsAddSharedGroupMembersRequestWrapper<>& request);
    static void LogRemoveSharedGroupMembersRequest(PFSharedGroupsRemoveSharedGroupMembersRequest const* request, const char* testName);
    static void FillRemoveSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<>& request);
    static void FillClientRemoveSharedGroupMembersCleanupDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

    static void FillClientUpdateSharedGroupDataPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientUpdateSharedGroupDataPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void LogUpdateSharedGroupDataRequest(PFSharedGroupsUpdateSharedGroupDataRequest const* request, const char* testName);
    static void FillUpdateSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsUpdateSharedGroupDataRequestWrapper<>& request);
    static void FillClientUpdateSharedGroupDataCleanupDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

    static void FillServerAddSharedGroupMembersPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreServerAddSharedGroupMembersPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillServerAddSharedGroupMembersCleanupRemoveSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<>& request);
    static void FillServerAddSharedGroupMembersCleanupDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

    static void FillServerCreateSharedGroupCleanupDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

    static void FillServerDeleteSharedGroupPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreServerDeleteSharedGroupPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void LogDeleteSharedGroupRequest(PFSharedGroupsDeleteSharedGroupRequest const* request, const char* testName);
    static void FillDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

    static void FillServerGetSharedGroupDataPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreServerGetSharedGroupDataPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillServerGetSharedGroupDataPrerequisiteUpdateSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsUpdateSharedGroupDataRequestWrapper<>& request);
    static void FillServerGetSharedGroupDataCleanupDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

    static void FillServerRemoveSharedGroupMembersPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreServerRemoveSharedGroupMembersPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillServerRemoveSharedGroupMembersPrerequisiteAddSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsAddSharedGroupMembersRequestWrapper<>& request);
    static void FillServerRemoveSharedGroupMembersCleanupDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

    static void FillServerUpdateSharedGroupDataPrerequisiteCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreServerUpdateSharedGroupDataPrerequisitePFSharedGroupsCreateSharedGroupResult(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillServerUpdateSharedGroupDataCleanupDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

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
