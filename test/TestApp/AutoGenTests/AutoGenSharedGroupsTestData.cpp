#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenSharedGroupsTests.h"
#include "XAsyncHelper.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

#pragma region ClientAddSharedGroupMembers

void AutoGenSharedGroupsTests::FillClientAddSharedGroupMembersPrerequisiteClientCreateSharedGroupRequest(PFSharedGroupsCreateSharedGroupRequestWrapper<>& request)
{
    // Example request: "{ \"SharedGroupId\": \"Clan Data\"}"
    request.SetSharedGroupId("AddSharedGroupMembers");
}

HRESULT AutoGenSharedGroupsTests::StoreClientAddSharedGroupMembersPrerequisiteClientCreateSharedGroupResponse(std::shared_ptr<CreateSharedGroupResultHolder> result)
{
    testData.m_CreateSharedGroupResult = result;
    return S_OK;
}

void AutoGenSharedGroupsTests::FillClientAddSharedGroupMembersRequest(PFSharedGroupsAddSharedGroupMembersRequestWrapper<>& request)
{
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\", \"PlayFabIds\": [ \"D984A64B832\", \"F74A523E1562\" ]}"
    request.SetSharedGroupId("AddSharedGroupMembers");
    request.SetPlayFabIds({ "6842934CB46C0834" });
}

void AutoGenSharedGroupsTests::FillClientAddSharedGroupMembersCleanupClientRemoveSharedGroupMembersRequest(PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<>& request)
{
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\", \"PlayFabIds\": [ \"D984A64B832\", \"F74A523E1562\" ]}"
    request.SetSharedGroupId("AddSharedGroupMembers");
    request.SetPlayFabIds({ "6842934CB46C0834" });
}

#pragma endregion

#pragma region ClientCreateSharedGroup

void AutoGenSharedGroupsTests::FillClientCreateSharedGroupRequest(PFSharedGroupsCreateSharedGroupRequestWrapper<>& request)
{
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\"}"
    request.SetSharedGroupId("CreateSharedGroup");
}

HRESULT AutoGenSharedGroupsTests::ValidateClientCreateSharedGroupResponse(PFSharedGroupsCreateSharedGroupResult* result)
{
    // result.sharedGroupId = const char*;

    UNREFERENCED_PARAMETER(result);
    return S_OK;
}

#pragma endregion

#pragma region ClientGetSharedGroupData

void AutoGenSharedGroupsTests::FillClientGetSharedGroupDataPrerequisiteClientCreateSharedGroupRequest(PFSharedGroupsCreateSharedGroupRequestWrapper<>& request)
{
    // Example request: "{ \"SharedGroupId\": \"Clan Data\"}"
    request.SetSharedGroupId("GetSharedGroupData");
}

HRESULT AutoGenSharedGroupsTests::StoreClientGetSharedGroupDataPrerequisiteClientCreateSharedGroupResponse(std::shared_ptr<CreateSharedGroupResultHolder> result)
{
    testData.m_CreateSharedGroupResult = result;
    return S_OK;
}

void AutoGenSharedGroupsTests::FillClientGetSharedGroupDataPrerequisiteClientUpdateSharedGroupDataRequest(PFSharedGroupsUpdateSharedGroupDataRequestWrapper<>& request)
{
    // Example request: "{ \"SharedGroupId\": \"Clan Data\", \"Data\": { \"ClanKills\": \"34\", \"LastClanUpdate\": \"2014-10-03T09:21:14Z\" }, \"Permission\": \"Public\"}"
    request.SetSharedGroupId("GetSharedGroupData");
    StringDictionaryEntryVector<> data{};
    data.insert_or_assign("test client key", "test client value");
    request.SetData(data);
}

void AutoGenSharedGroupsTests::FillClientGetSharedGroupDataRequest(PFSharedGroupsGetSharedGroupDataRequestWrapper<>& request)
{
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\", \"Keys\": [ \"ClanKills\", \"LastClanUpdate\" ], \"GetMembers\": true}"
    request.SetSharedGroupId("GetSharedGroupData");
    request.SetGetMembers(true);
}

HRESULT AutoGenSharedGroupsTests::ValidateClientGetSharedGroupDataResponse(PFSharedGroupsGetSharedGroupDataResult* result)
{
    // result.data = struct PFSharedGroupsSharedGroupDataRecordDictionaryEntry const*;
    // result.dataCount = uint32_t;
    // result.members = const char* const*;
    // result.membersCount = uint32_t;

    UNREFERENCED_PARAMETER(result);
    return S_OK;
}

#pragma endregion

#pragma region ClientRemoveSharedGroupMembers

void AutoGenSharedGroupsTests::FillClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroupRequest(PFSharedGroupsCreateSharedGroupRequestWrapper<>& request)
{
    // Example request: "{ \"SharedGroupId\": \"Clan Data\"}"
    request.SetSharedGroupId("RemoveSharedGroupMembers");
}

HRESULT AutoGenSharedGroupsTests::StoreClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroupResponse(std::shared_ptr<CreateSharedGroupResultHolder> result)
{
    testData.m_CreateSharedGroupResult = result;
    return S_OK;
}

void AutoGenSharedGroupsTests::FillClientRemoveSharedGroupMembersPrerequisiteClientAddSharedGroupMembersRequest(PFSharedGroupsAddSharedGroupMembersRequestWrapper<>& request)
{
    // Example request: "{ \"SharedGroupId\": \"Clan Data\", \"PlayFabIds\": [ \"D984A64B832\", \"F74A523E1562\" ]}"
    request.SetSharedGroupId("RemoveSharedGroupMembers");
    request.SetPlayFabIds({ "6842934CB46C0834" });
}

void AutoGenSharedGroupsTests::FillClientRemoveSharedGroupMembersRequest(PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<>& request)
{
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\", \"PlayFabIds\": [ \"D984A64B832\", \"F74A523E1562\" ]}"
    request.SetSharedGroupId("RemoveSharedGroupMembers");
    request.SetPlayFabIds({ "6842934CB46C0834" });
}

#pragma endregion

#pragma region ClientUpdateSharedGroupData

void AutoGenSharedGroupsTests::FillClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroupRequest(PFSharedGroupsCreateSharedGroupRequestWrapper<>& request)
{
    // Example request: "{ \"SharedGroupId\": \"Clan Data\"}"
    request.SetSharedGroupId("UpdateSharedGroupData");
}

HRESULT AutoGenSharedGroupsTests::StoreClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroupResponse(std::shared_ptr<CreateSharedGroupResultHolder> result)
{
    testData.m_CreateSharedGroupResult = result;
    return S_OK;
}

void AutoGenSharedGroupsTests::FillClientUpdateSharedGroupDataRequest(PFSharedGroupsUpdateSharedGroupDataRequestWrapper<>& request)
{
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\", \"Data\": { \"ClanKills\": \"34\", \"LastClanUpdate\": \"2014-10-03T09:21:14Z\" }, \"Permission\": \"Public\"}"
    request.SetSharedGroupId("UpdateSharedGroupData");
    StringDictionaryEntryVector<> data{};
    data.insert_or_assign("test update key", "test update value");
    request.SetData(data);
}

#pragma endregion

#pragma region ServerAddSharedGroupMembers

void AutoGenSharedGroupsTests::FillServerAddSharedGroupMembersRequest(PFSharedGroupsAddSharedGroupMembersRequestWrapper<>& request)
{
    // TODO: debug Failing test
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\", \"PlayFabIds\": [ \"D984A64B832\", \"F74A523E1562\" ]}"
    UNREFERENCED_PARAMETER(request); // TODO
}

#pragma endregion

#pragma region ServerCreateSharedGroup

void AutoGenSharedGroupsTests::FillServerCreateSharedGroupRequest(PFSharedGroupsCreateSharedGroupRequestWrapper<>& request)
{
    // TODO: debug Failing test
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\"}"
    UNREFERENCED_PARAMETER(request); // TODO
}

HRESULT AutoGenSharedGroupsTests::ValidateServerCreateSharedGroupResponse(PFSharedGroupsCreateSharedGroupResult* result)
{
    // result.sharedGroupId = const char*;

    UNREFERENCED_PARAMETER(result);
    return S_OK;
}

#pragma endregion

#pragma region ServerDeleteSharedGroup

void AutoGenSharedGroupsTests::FillServerDeleteSharedGroupRequest(PFSharedGroupsDeleteSharedGroupRequestWrapper<>& request)
{
    // TODO: debug Failing test
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\"}"
    UNREFERENCED_PARAMETER(request); // TODO
}

#pragma endregion

#pragma region ServerGetSharedGroupData

void AutoGenSharedGroupsTests::FillServerGetSharedGroupDataRequest(PFSharedGroupsGetSharedGroupDataRequestWrapper<>& request)
{
    // TODO: debug Failing test
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\", \"Keys\": [ \"ClanKills\", \"LastClanUpdate\" ], \"GetMembers\": true}"
    UNREFERENCED_PARAMETER(request); // TODO
}

HRESULT AutoGenSharedGroupsTests::ValidateServerGetSharedGroupDataResponse(PFSharedGroupsGetSharedGroupDataResult* result)
{
    // result.data = struct PFSharedGroupsSharedGroupDataRecordDictionaryEntry const*;
    // result.dataCount = uint32_t;
    // result.members = const char* const*;
    // result.membersCount = uint32_t;

    UNREFERENCED_PARAMETER(result);
    return S_OK;
}

#pragma endregion

#pragma region ServerRemoveSharedGroupMembers

void AutoGenSharedGroupsTests::FillServerRemoveSharedGroupMembersRequest(PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<>& request)
{
    // TODO: debug Failing test
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\", \"PlayFabIds\": [ \"D984A64B832\", \"F74A523E1562\" ]}"
    UNREFERENCED_PARAMETER(request); // TODO
}

#pragma endregion

#pragma region ServerUpdateSharedGroupData

void AutoGenSharedGroupsTests::FillServerUpdateSharedGroupDataRequest(PFSharedGroupsUpdateSharedGroupDataRequestWrapper<>& request)
{
    // TODO: debug Failing test
    // Example Request: "{ \"SharedGroupId\": \"Clan Data\", \"Data\": { \"ClanKills\": \"34\", \"LastClanUpdate\": \"2014-10-03T09:21:14Z\" }, \"Permission\": \"Public\"}"
    UNREFERENCED_PARAMETER(request); // TODO
}

#pragma endregion
 

}
