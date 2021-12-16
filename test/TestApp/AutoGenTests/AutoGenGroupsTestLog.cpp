#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenGroupsTests.h"
#include "XAsyncHelper.h"

uint32_t g_GroupsTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenGroupsTests::LogAcceptGroupApplicationRequest(PFGroupsAcceptGroupApplicationRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsAcceptGroupApplicationRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

void AutoGenGroupsTests::LogAcceptGroupInvitationRequest(PFGroupsAcceptGroupInvitationRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsAcceptGroupInvitationRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

void AutoGenGroupsTests::LogAddMembersRequest(PFGroupsAddMembersRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsAddMembersRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey     
    ss << "  membersCount " << request->membersCount; Log(ss);

    // PFEntityKey
    for( uint32_t i=0; i<request->membersCount; i++ )
    {
            ss << "  request->members[" << i << "]:" << request->members[i]; Log(ss); // PFEntityKey
    } 
    if( request->roleId ) { ss << "  roleId " << request->roleId; Log(ss); } else { ss << "  roleId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenGroupsTests::LogApplyToGroupRequest(PFGroupsApplyToGroupRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsApplyToGroupRequest struct:
    // request->autoAcceptOutstandingInvite: bool const*
    ss << "  autoAcceptOutstandingInvite " << request->autoAcceptOutstandingInvite; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenGroupsTests::LogPFGroupsApplyToGroupResponse(PFGroupsApplyToGroupResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsApplyToGroupResponse    
    ss << "  entity " << result->entity; Log(ss); // Class: PFGroupsEntityWithLineage     
    ss << "  expires " << result->expires; Log(ss); // Class: time_t     
    ss << "  group " << result->group; Log(ss); // Class: PFEntityKey 
    return S_OK;
}

void AutoGenGroupsTests::LogBlockEntityRequest(PFGroupsBlockEntityRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsBlockEntityRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

void AutoGenGroupsTests::LogChangeMemberRoleRequest(PFGroupsChangeMemberRoleRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsChangeMemberRoleRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->destinationRoleId ) { ss << "  destinationRoleId " << request->destinationRoleId; Log(ss); } else { ss << "  destinationRoleId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey     
    ss << "  membersCount " << request->membersCount; Log(ss);

    // PFEntityKey
    for( uint32_t i=0; i<request->membersCount; i++ )
    {
            ss << "  request->members[" << i << "]:" << request->members[i]; Log(ss); // PFEntityKey
    } 
    if( request->originRoleId ) { ss << "  originRoleId " << request->originRoleId; Log(ss); } else { ss << "  originRoleId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenGroupsTests::LogCreateGroupRequest(PFGroupsCreateGroupRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsCreateGroupRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->groupName ) { ss << "  groupName " << request->groupName; Log(ss); } else { ss << "  groupName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenGroupsTests::LogPFGroupsCreateGroupResponse(PFGroupsCreateGroupResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsCreateGroupResponse    
    if( result->adminRoleId ) { ss << "  adminRoleId " << result->adminRoleId; Log(ss); } else { ss << "  adminRoleId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  created " << result->created; Log(ss); // Class: time_t     
    ss << "  group " << result->group; Log(ss); // Class: PFEntityKey     
    if( result->groupName ) { ss << "  groupName " << result->groupName; Log(ss); } else { ss << "  groupName = nullptr"; Log(ss); } // Class: const char*     
    if( result->memberRoleId ) { ss << "  memberRoleId " << result->memberRoleId; Log(ss); } else { ss << "  memberRoleId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  profileVersion " << result->profileVersion; Log(ss); // Class: int32_t         
    ss << "  rolesCount " << result->rolesCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<result->rolesCount; i++ )
    {
            ss << "  result->roles[" << i << "]:" << result->roles[i].key << "=" << result->roles[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenGroupsTests::LogCreateGroupRoleRequest(PFGroupsCreateGroupRoleRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsCreateGroupRoleRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 
    if( request->roleId ) { ss << "  roleId " << request->roleId; Log(ss); } else { ss << "  roleId = nullptr"; Log(ss); } // Class: const char* 
    if( request->roleName ) { ss << "  roleName " << request->roleName; Log(ss); } else { ss << "  roleName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenGroupsTests::LogPFGroupsCreateGroupRoleResponse(PFGroupsCreateGroupRoleResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsCreateGroupRoleResponse    
    ss << "  profileVersion " << result->profileVersion; Log(ss); // Class: int32_t     
    if( result->roleId ) { ss << "  roleId " << result->roleId; Log(ss); } else { ss << "  roleId = nullptr"; Log(ss); } // Class: const char*     
    if( result->roleName ) { ss << "  roleName " << result->roleName; Log(ss); } else { ss << "  roleName = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenGroupsTests::LogDeleteGroupRequest(PFGroupsDeleteGroupRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsDeleteGroupRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

void AutoGenGroupsTests::LogDeleteRoleRequest(PFGroupsDeleteRoleRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsDeleteRoleRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 
    if( request->roleId ) { ss << "  roleId " << request->roleId; Log(ss); } else { ss << "  roleId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenGroupsTests::LogGetGroupRequest(PFGroupsGetGroupRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsGetGroupRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 
    if( request->groupName ) { ss << "  groupName " << request->groupName; Log(ss); } else { ss << "  groupName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenGroupsTests::LogPFGroupsGetGroupResponse(PFGroupsGetGroupResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsGetGroupResponse    
    if( result->adminRoleId ) { ss << "  adminRoleId " << result->adminRoleId; Log(ss); } else { ss << "  adminRoleId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  created " << result->created; Log(ss); // Class: time_t     
    ss << "  group " << result->group; Log(ss); // Class: PFEntityKey     
    if( result->groupName ) { ss << "  groupName " << result->groupName; Log(ss); } else { ss << "  groupName = nullptr"; Log(ss); } // Class: const char*     
    if( result->memberRoleId ) { ss << "  memberRoleId " << result->memberRoleId; Log(ss); } else { ss << "  memberRoleId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  profileVersion " << result->profileVersion; Log(ss); // Class: int32_t         
    ss << "  rolesCount " << result->rolesCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<result->rolesCount; i++ )
    {
            ss << "  result->roles[" << i << "]:" << result->roles[i].key << "=" << result->roles[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenGroupsTests::LogInviteToGroupRequest(PFGroupsInviteToGroupRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsInviteToGroupRequest struct:
    // request->autoAcceptOutstandingApplication: bool const*
    ss << "  autoAcceptOutstandingApplication " << request->autoAcceptOutstandingApplication; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 
    if( request->roleId ) { ss << "  roleId " << request->roleId; Log(ss); } else { ss << "  roleId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenGroupsTests::LogPFGroupsInviteToGroupResponse(PFGroupsInviteToGroupResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsInviteToGroupResponse    
    ss << "  expires " << result->expires; Log(ss); // Class: time_t     
    ss << "  group " << result->group; Log(ss); // Class: PFEntityKey     
    ss << "  invitedByEntity " << result->invitedByEntity; Log(ss); // Class: PFGroupsEntityWithLineage     
    ss << "  invitedEntity " << result->invitedEntity; Log(ss); // Class: PFGroupsEntityWithLineage     
    if( result->roleId ) { ss << "  roleId " << result->roleId; Log(ss); } else { ss << "  roleId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenGroupsTests::LogIsMemberRequest(PFGroupsIsMemberRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsIsMemberRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 
    if( request->roleId ) { ss << "  roleId " << request->roleId; Log(ss); } else { ss << "  roleId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenGroupsTests::LogPFGroupsIsMemberResponse(PFGroupsIsMemberResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsIsMemberResponse    
    ss << "  isMember " << result->isMember; Log(ss); // Class: bool 
    return S_OK;
}

void AutoGenGroupsTests::LogListGroupApplicationsRequest(PFGroupsListGroupApplicationsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsListGroupApplicationsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenGroupsTests::LogPFGroupsListGroupApplicationsResponse(PFGroupsListGroupApplicationsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsListGroupApplicationsResponse        
    ss << "  applicationsCount " << result->applicationsCount; Log(ss);

    // PFGroupsGroupApplication
    for( uint32_t i=0; i<result->applicationsCount; i++ )
    {
            ss << "  result->applications[" << i << "]:" << result->applications[i]; Log(ss); // PFGroupsGroupApplication
    } 
    return S_OK;
}

void AutoGenGroupsTests::LogListGroupBlocksRequest(PFGroupsListGroupBlocksRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsListGroupBlocksRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenGroupsTests::LogPFGroupsListGroupBlocksResponse(PFGroupsListGroupBlocksResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsListGroupBlocksResponse        
    ss << "  blockedEntitiesCount " << result->blockedEntitiesCount; Log(ss);

    // PFGroupsGroupBlock
    for( uint32_t i=0; i<result->blockedEntitiesCount; i++ )
    {
            ss << "  result->blockedEntities[" << i << "]:" << result->blockedEntities[i]; Log(ss); // PFGroupsGroupBlock
    } 
    return S_OK;
}

void AutoGenGroupsTests::LogListGroupInvitationsRequest(PFGroupsListGroupInvitationsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsListGroupInvitationsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenGroupsTests::LogPFGroupsListGroupInvitationsResponse(PFGroupsListGroupInvitationsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsListGroupInvitationsResponse        
    ss << "  invitationsCount " << result->invitationsCount; Log(ss);

    // PFGroupsGroupInvitation
    for( uint32_t i=0; i<result->invitationsCount; i++ )
    {
            ss << "  result->invitations[" << i << "]:" << result->invitations[i]; Log(ss); // PFGroupsGroupInvitation
    } 
    return S_OK;
}

void AutoGenGroupsTests::LogListGroupMembersRequest(PFGroupsListGroupMembersRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsListGroupMembersRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenGroupsTests::LogPFGroupsListGroupMembersResponse(PFGroupsListGroupMembersResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsListGroupMembersResponse        
    ss << "  membersCount " << result->membersCount; Log(ss);

    // PFGroupsEntityMemberRole
    for( uint32_t i=0; i<result->membersCount; i++ )
    {
            ss << "  result->members[" << i << "]:" << result->members[i]; Log(ss); // PFGroupsEntityMemberRole
    } 
    return S_OK;
}

void AutoGenGroupsTests::LogListMembershipRequest(PFGroupsListMembershipRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsListMembershipRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenGroupsTests::LogPFGroupsListMembershipResponse(PFGroupsListMembershipResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsListMembershipResponse        
    ss << "  groupsCount " << result->groupsCount; Log(ss);

    // PFGroupsGroupWithRoles
    for( uint32_t i=0; i<result->groupsCount; i++ )
    {
            ss << "  result->groups[" << i << "]:" << result->groups[i]; Log(ss); // PFGroupsGroupWithRoles
    } 
    return S_OK;
}

void AutoGenGroupsTests::LogListMembershipOpportunitiesRequest(PFGroupsListMembershipOpportunitiesRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsListMembershipOpportunitiesRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenGroupsTests::LogPFGroupsListMembershipOpportunitiesResponse(PFGroupsListMembershipOpportunitiesResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsListMembershipOpportunitiesResponse        
    ss << "  applicationsCount " << result->applicationsCount; Log(ss);

    // PFGroupsGroupApplication
    for( uint32_t i=0; i<result->applicationsCount; i++ )
    {
            ss << "  result->applications[" << i << "]:" << result->applications[i]; Log(ss); // PFGroupsGroupApplication
    }         
    ss << "  invitationsCount " << result->invitationsCount; Log(ss);

    // PFGroupsGroupInvitation
    for( uint32_t i=0; i<result->invitationsCount; i++ )
    {
            ss << "  result->invitations[" << i << "]:" << result->invitations[i]; Log(ss); // PFGroupsGroupInvitation
    } 
    return S_OK;
}

void AutoGenGroupsTests::LogRemoveGroupApplicationRequest(PFGroupsRemoveGroupApplicationRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsRemoveGroupApplicationRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

void AutoGenGroupsTests::LogRemoveGroupInvitationRequest(PFGroupsRemoveGroupInvitationRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsRemoveGroupInvitationRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

void AutoGenGroupsTests::LogRemoveMembersRequest(PFGroupsRemoveMembersRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsRemoveMembersRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey     
    ss << "  membersCount " << request->membersCount; Log(ss);

    // PFEntityKey
    for( uint32_t i=0; i<request->membersCount; i++ )
    {
            ss << "  request->members[" << i << "]:" << request->members[i]; Log(ss); // PFEntityKey
    } 
    if( request->roleId ) { ss << "  roleId " << request->roleId; Log(ss); } else { ss << "  roleId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenGroupsTests::LogUnblockEntityRequest(PFGroupsUnblockEntityRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsUnblockEntityRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 

}

void AutoGenGroupsTests::LogUpdateGroupRequest(PFGroupsUpdateGroupRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsUpdateGroupRequest struct:
    // request->adminRoleId: const char*
    if( request->adminRoleId ) { ss << "  adminRoleId " << request->adminRoleId; Log(ss); } else { ss << "  adminRoleId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  expectedProfileVersion " << request->expectedProfileVersion; Log(ss); // Class: int32_t 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 
    if( request->groupName ) { ss << "  groupName " << request->groupName; Log(ss); } else { ss << "  groupName = nullptr"; Log(ss); } // Class: const char* 
    if( request->memberRoleId ) { ss << "  memberRoleId " << request->memberRoleId; Log(ss); } else { ss << "  memberRoleId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenGroupsTests::LogPFGroupsUpdateGroupResponse(PFGroupsUpdateGroupResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsUpdateGroupResponse    
    if( result->operationReason ) { ss << "  operationReason " << result->operationReason; Log(ss); } else { ss << "  operationReason = nullptr"; Log(ss); } // Class: const char*     
    ss << "  profileVersion " << result->profileVersion; Log(ss); // Class: int32_t     
    ss << "  setResult " << result->setResult; Log(ss); // Class: PFOperationTypes 
    return S_OK;
}

void AutoGenGroupsTests::LogUpdateGroupRoleRequest(PFGroupsUpdateGroupRoleRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGroupsUpdateGroupRoleRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  expectedProfileVersion " << request->expectedProfileVersion; Log(ss); // Class: int32_t 
    ss << "  group " << request->group; Log(ss); // Class: PFEntityKey 
    if( request->roleId ) { ss << "  roleId " << request->roleId; Log(ss); } else { ss << "  roleId = nullptr"; Log(ss); } // Class: const char* 
    if( request->roleName ) { ss << "  roleName " << request->roleName; Log(ss); } else { ss << "  roleName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenGroupsTests::LogPFGroupsUpdateGroupRoleResponse(PFGroupsUpdateGroupRoleResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGroupsUpdateGroupRoleResponse    
    if( result->operationReason ) { ss << "  operationReason " << result->operationReason; Log(ss); } else { ss << "  operationReason = nullptr"; Log(ss); } // Class: const char*     
    ss << "  profileVersion " << result->profileVersion; Log(ss); // Class: int32_t     
    ss << "  setResult " << result->setResult; Log(ss); // Class: PFOperationTypes 
    return S_OK;
}

 

}
