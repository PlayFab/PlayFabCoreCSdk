#pragma once

#include "AuthenticationDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Authentication
{

class AuthenticationAPI
{
public:
    AuthenticationAPI() = delete;
    AuthenticationAPI(const AuthenticationAPI& source) = delete;
    AuthenticationAPI& operator=(const AuthenticationAPI& source) = delete;
    ~AuthenticationAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> AdminCreateOpenIdConnection(SharedPtr<GlobalState const> state, const CreateOpenIdConnectionRequest& request, const TaskQueue& queue);
    static AsyncOp<CreatePlayerSharedSecretResult> AdminCreatePlayerSharedSecret(SharedPtr<GlobalState const> state, const CreatePlayerSharedSecretRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminDeleteOpenIdConnection(SharedPtr<GlobalState const> state, const DeleteOpenIdConnectionRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminDeletePlayerSharedSecret(SharedPtr<GlobalState const> state, const DeletePlayerSharedSecretRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerSharedSecretsResult> AdminGetPlayerSharedSecrets(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<GetPolicyResponse> AdminGetPolicy(SharedPtr<GlobalState const> state, const GetPolicyRequest& request, const TaskQueue& queue);
    static AsyncOp<ListOpenIdConnectionResponse> AdminListOpenIdConnection(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<void> AdminSetPlayerSecret(SharedPtr<GlobalState const> state, const AdminSetPlayerSecretRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminUpdateOpenIdConnection(SharedPtr<GlobalState const> state, const UpdateOpenIdConnectionRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminUpdatePlayerSharedSecret(SharedPtr<GlobalState const> state, const UpdatePlayerSharedSecretRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdatePolicyResponse> AdminUpdatePolicy(SharedPtr<GlobalState const> state, const UpdatePolicyRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPhotonAuthenticationTokenResult> ClientGetPhotonAuthenticationToken(SharedPtr<TitlePlayer> entity, const GetPhotonAuthenticationTokenRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTitlePublicKeyResult> ClientGetTitlePublicKey(SharedPtr<GlobalState const> state, const GetTitlePublicKeyRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithAndroidDeviceID(SharedPtr<GlobalState const> state, const LoginWithAndroidDeviceIDRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithApple(SharedPtr<GlobalState const> state, const LoginWithAppleRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithCustomID(SharedPtr<GlobalState const> state, const LoginWithCustomIDRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithEmailAddress(SharedPtr<GlobalState const> state, const LoginWithEmailAddressRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithFacebook(SharedPtr<GlobalState const> state, const LoginWithFacebookRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithFacebookInstantGamesId(SharedPtr<GlobalState const> state, const LoginWithFacebookInstantGamesIdRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithGameCenter(SharedPtr<GlobalState const> state, const LoginWithGameCenterRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithGoogleAccount(SharedPtr<GlobalState const> state, const LoginWithGoogleAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithIOSDeviceID(SharedPtr<GlobalState const> state, const LoginWithIOSDeviceIDRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithKongregate(SharedPtr<GlobalState const> state, const LoginWithKongregateRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithNintendoServiceAccount(SharedPtr<GlobalState const> state, const LoginWithNintendoServiceAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithNintendoSwitchDeviceId(SharedPtr<GlobalState const> state, const LoginWithNintendoSwitchDeviceIdRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithOpenIdConnect(SharedPtr<GlobalState const> state, const LoginWithOpenIdConnectRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithPlayFab(SharedPtr<GlobalState const> state, const LoginWithPlayFabRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithPSN(SharedPtr<GlobalState const> state, const LoginWithPSNRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithSteam(SharedPtr<GlobalState const> state, const LoginWithSteamRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithTwitch(SharedPtr<GlobalState const> state, const LoginWithTwitchRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ClientLoginWithXbox(SharedPtr<GlobalState const> state, const ClientLoginWithXboxRequest& request, const TaskQueue& queue);
#if HC_PLATFORM == HC_PLATFORM_GDK
    static AsyncOp<SharedPtr<TitlePlayer>> LoginWithXUser(SharedPtr<GlobalState> state, const PFAuthenticationLoginWithXUserRequest& request, const TaskQueue& queue);
#endif
    static AsyncOp<SharedPtr<TitlePlayer>> ClientRegisterPlayFabUser(SharedPtr<GlobalState const> state, const RegisterPlayFabUserRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientSetPlayerSecret(SharedPtr<TitlePlayer> entity, const ClientSetPlayerSecretRequest& request, const TaskQueue& queue);
    static AsyncOp<AuthenticateSessionTicketResult> ServerAuthenticateSessionTicket(SharedPtr<GlobalState const> state, const AuthenticateSessionTicketRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ServerLoginWithServerCustomId(SharedPtr<GlobalState const> state, const LoginWithServerCustomIdRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ServerLoginWithSteamId(SharedPtr<GlobalState const> state, const LoginWithSteamIdRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ServerLoginWithXbox(SharedPtr<GlobalState const> state, const ServerLoginWithXboxRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<TitlePlayer>> ServerLoginWithXboxId(SharedPtr<GlobalState const> state, const LoginWithXboxIdRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSetPlayerSecret(SharedPtr<GlobalState const> state, const ServerSetPlayerSecretRequest& request, const TaskQueue& queue);
    static AsyncOp<SharedPtr<Entity>> GetEntityToken(SharedPtr<GlobalState const> state, const GetEntityTokenRequest& request, const TaskQueue& queue);
    static AsyncOp<ValidateEntityTokenResponse> ValidateEntityToken(SharedPtr<Entity> entity, const ValidateEntityTokenRequest& request, const TaskQueue& queue);
};

} // namespace Authentication
} // namespace PlayFab
