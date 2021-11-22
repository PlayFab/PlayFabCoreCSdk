#pragma once

#include "ProfilesDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Profiles
{

class ProfilesAPI
{
public:
    ProfilesAPI() = delete;
    ProfilesAPI(const ProfilesAPI& source) = delete;
    ProfilesAPI& operator=(const ProfilesAPI& source) = delete;
    ~ProfilesAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<GetGlobalPolicyResponse> GetGlobalPolicy(SharedPtr<Entity> entity, const GetGlobalPolicyRequest& request, const TaskQueue& queue);
    static AsyncOp<GetEntityProfileResponse> GetProfile(SharedPtr<Entity> entity, const GetEntityProfileRequest& request, const TaskQueue& queue);
    static AsyncOp<GetEntityProfilesResponse> GetProfiles(SharedPtr<Entity> entity, const GetEntityProfilesRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTitlePlayersFromMasterPlayerAccountIdsResponse> GetTitlePlayersFromMasterPlayerAccountIds(SharedPtr<Entity> entity, const GetTitlePlayersFromMasterPlayerAccountIdsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> SetGlobalPolicy(SharedPtr<Entity> entity, const SetGlobalPolicyRequest& request, const TaskQueue& queue);
    static AsyncOp<SetProfileLanguageResponse> SetProfileLanguage(SharedPtr<Entity> entity, const SetProfileLanguageRequest& request, const TaskQueue& queue);
    static AsyncOp<SetEntityProfilePolicyResponse> SetProfilePolicy(SharedPtr<Entity> entity, const SetEntityProfilePolicyRequest& request, const TaskQueue& queue);
};

} // namespace Profiles
} // namespace PlayFab
