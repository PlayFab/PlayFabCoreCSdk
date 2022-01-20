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

    static void LogAddSharedGroupMembersRequest(PFSharedGroupsAddSharedGroupMembersRequest const* request, const char* testName);
    static void LogCreateSharedGroupRequest(PFSharedGroupsCreateSharedGroupRequest const* request, const char* testName);
    static HRESULT LogCreateSharedGroupResult(PFSharedGroupsCreateSharedGroupResult const* result);
    static void LogGetSharedGroupDataRequest(PFSharedGroupsGetSharedGroupDataRequest const* request, const char* testName);
    static HRESULT LogGetSharedGroupDataResult(PFSharedGroupsGetSharedGroupDataResult const* result);
    static void LogRemoveSharedGroupMembersRequest(PFSharedGroupsRemoveSharedGroupMembersRequest const* request, const char* testName);
    static void LogUpdateSharedGroupDataRequest(PFSharedGroupsUpdateSharedGroupDataRequest const* request, const char* testName);
    static void LogDeleteSharedGroupRequest(PFSharedGroupsDeleteSharedGroupRequest const* request, const char* testName);

    static void FillClientAddSharedGroupMembersPrerequisiteClientCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientAddSharedGroupMembersPrerequisiteClientCreateSharedGroupResponse(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillClientAddSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsAddSharedGroupMembersRequestWrapper<>& request);
    static void FillClientAddSharedGroupMembersCleanupClientRemoveSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<>& request);

    static void FillClientCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT ValidateClientCreateSharedGroupResponse(PFSharedGroupsCreateSharedGroupResult* result);

    static void FillClientGetSharedGroupDataPrerequisiteClientCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientGetSharedGroupDataPrerequisiteClientCreateSharedGroupResponse(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillClientGetSharedGroupDataPrerequisiteClientUpdateSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsUpdateSharedGroupDataRequestWrapper<>& request);
    static void FillClientGetSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsGetSharedGroupDataRequestWrapper<>& request);
    static HRESULT ValidateClientGetSharedGroupDataResponse(PFSharedGroupsGetSharedGroupDataResult* result);

    static void FillClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroupResponse(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillClientRemoveSharedGroupMembersPrerequisiteClientAddSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsAddSharedGroupMembersRequestWrapper<>& request);
    static void FillClientRemoveSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<>& request);

    static void FillClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT StoreClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroupResponse(std::shared_ptr<CreateSharedGroupResultHolder> result);
    static void FillClientUpdateSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsUpdateSharedGroupDataRequestWrapper<>& request);

    static void FillServerAddSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsAddSharedGroupMembersRequestWrapper<>& request);

    static void FillServerCreateSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsCreateSharedGroupRequestWrapper<>& request);
    static HRESULT ValidateServerCreateSharedGroupResponse(PFSharedGroupsCreateSharedGroupResult* result);

    static void FillServerDeleteSharedGroupRequest(PlayFab::Wrappers::PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request);

    static void FillServerGetSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsGetSharedGroupDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetSharedGroupDataResponse(PFSharedGroupsGetSharedGroupDataResult* result);

    static void FillServerRemoveSharedGroupMembersRequest(PlayFab::Wrappers::PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<>& request);

    static void FillServerUpdateSharedGroupDataRequest(PlayFab::Wrappers::PFSharedGroupsUpdateSharedGroupDataRequestWrapper<>& request);

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
