#include "stdafx.h"
#include <playfab/PFMatchmaking.h>
#include "Matchmaking.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::Matchmaking;

HRESULT PFMatchmakingAdminGetMatchmakerGameInfoAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingGetMatchmakerGameInfoRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::AdminGetMatchmakerGameInfo, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingAdminGetMatchmakerGameInfoGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingAdminGetMatchmakerGameInfoGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetMatchmakerGameInfoResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingGetMatchmakerGameInfoResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingAdminGetMatchmakerGameModesAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingGetMatchmakerGameModesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::AdminGetMatchmakerGameModes, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingAdminGetMatchmakerGameModesGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingAdminGetMatchmakerGameModesGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetMatchmakerGameModesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingGetMatchmakerGameModesResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingAdminModifyMatchmakerGameModesAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingModifyMatchmakerGameModesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::AdminModifyMatchmakerGameModes, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingClientGetCurrentGamesAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFMatchmakingCurrentGamesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ClientGetCurrentGames, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingClientGetCurrentGamesGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingClientGetCurrentGamesGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingCurrentGamesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingCurrentGamesResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingClientGetGameServerRegionsAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFMatchmakingGameServerRegionsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ClientGetGameServerRegions, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingClientGetGameServerRegionsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingClientGetGameServerRegionsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGameServerRegionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingGameServerRegionsResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingClientMatchmakeAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFMatchmakingMatchmakeRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ClientMatchmake, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingClientMatchmakeGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingClientMatchmakeGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingMatchmakeResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingMatchmakeResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingClientStartGameAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFMatchmakingClientStartGameRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ClientStartGame, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingClientStartGameGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingClientStartGameGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingStartGameResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingStartGameResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingAuthUserAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingAuthUserRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::AuthUser, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingAuthUserGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingAuthUserGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingAuthUserResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingAuthUserResponse*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingPlayerJoinedAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingPlayerJoinedRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::PlayerJoined, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingPlayerLeftAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingPlayerLeftRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::PlayerLeft, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingStartGameAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingMatchmakerStartGameRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::StartGame, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingStartGameGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingStartGameGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingStartGameResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingStartGameResponse*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingUserInfoAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingUserInfoRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::UserInfo, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingUserInfoGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingUserInfoGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingUserInfoResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingUserInfoResponse*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingServerDeregisterGameAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingDeregisterGameRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ServerDeregisterGame, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingServerNotifyMatchmakerPlayerLeftAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingNotifyMatchmakerPlayerLeftRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ServerNotifyMatchmakerPlayerLeft, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingServerNotifyMatchmakerPlayerLeftGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingServerNotifyMatchmakerPlayerLeftGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingNotifyMatchmakerPlayerLeftResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingNotifyMatchmakerPlayerLeftResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingServerRedeemMatchmakerTicketAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingRedeemMatchmakerTicketRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ServerRedeemMatchmakerTicket, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingServerRedeemMatchmakerTicketGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingServerRedeemMatchmakerTicketGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingRedeemMatchmakerTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingRedeemMatchmakerTicketResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingServerRefreshGameServerInstanceHeartbeatAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingRefreshGameServerInstanceHeartbeatRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ServerRefreshGameServerInstanceHeartbeat, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingServerRegisterGameAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingRegisterGameRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ServerRegisterGame, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingServerRegisterGameGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingServerRegisterGameGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingRegisterGameResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingRegisterGameResponse*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingServerSetGameServerInstanceDataAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingSetGameServerInstanceDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ServerSetGameServerInstanceData, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingServerSetGameServerInstanceStateAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingSetGameServerInstanceStateRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ServerSetGameServerInstanceState, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingServerSetGameServerInstanceTagsAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMatchmakingSetGameServerInstanceTagsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ServerSetGameServerInstanceTags, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingCancelAllMatchmakingTicketsForPlayerAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::CancelAllMatchmakingTicketsForPlayer, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingCancelAllServerBackfillTicketsForPlayerAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::CancelAllServerBackfillTicketsForPlayer, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingCancelMatchmakingTicketAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingCancelMatchmakingTicketRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::CancelMatchmakingTicket, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingCancelServerBackfillTicketAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingCancelServerBackfillTicketRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::CancelServerBackfillTicket, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingCreateMatchmakingTicketAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingCreateMatchmakingTicketRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::CreateMatchmakingTicket, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingCreateMatchmakingTicketGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingCreateMatchmakingTicketGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingCreateMatchmakingTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingCreateMatchmakingTicketResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingCreateServerBackfillTicketAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingCreateServerBackfillTicketRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::CreateServerBackfillTicket, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingCreateServerBackfillTicketGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingCreateServerBackfillTicketGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingCreateServerBackfillTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingCreateServerBackfillTicketResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingCreateServerMatchmakingTicketAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingCreateServerMatchmakingTicketRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::CreateServerMatchmakingTicket, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingCreateServerMatchmakingTicketGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingCreateServerMatchmakingTicketGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingCreateMatchmakingTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingCreateMatchmakingTicketResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingGetMatchAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingGetMatchRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::GetMatch, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingGetMatchGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingGetMatchGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetMatchResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingGetMatchResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingGetMatchmakingTicketAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingGetMatchmakingTicketRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::GetMatchmakingTicket, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingGetMatchmakingTicketGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingGetMatchmakingTicketGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetMatchmakingTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingGetMatchmakingTicketResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingGetQueueStatisticsAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingGetQueueStatisticsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::GetQueueStatistics, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingGetQueueStatisticsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingGetQueueStatisticsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetQueueStatisticsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingGetQueueStatisticsResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingGetServerBackfillTicketAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingGetServerBackfillTicketRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::GetServerBackfillTicket, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingGetServerBackfillTicketGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingGetServerBackfillTicketGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetServerBackfillTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingGetServerBackfillTicketResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingJoinMatchmakingTicketAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingJoinMatchmakingTicketRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::JoinMatchmakingTicket, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingListMatchmakingTicketsForPlayerAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingListMatchmakingTicketsForPlayerRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ListMatchmakingTicketsForPlayer, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingListMatchmakingTicketsForPlayerGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingListMatchmakingTicketsForPlayerGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingListMatchmakingTicketsForPlayerResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingListMatchmakingTicketsForPlayerResult*>(buffer);

    return S_OK;
}

HRESULT PFMatchmakingListServerBackfillTicketsForPlayerAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMatchmakingListServerBackfillTicketsForPlayerRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MatchmakingAPI::ListServerBackfillTicketsForPlayer, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMatchmakingListServerBackfillTicketsForPlayerGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMatchmakingListServerBackfillTicketsForPlayerGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingListServerBackfillTicketsForPlayerResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMatchmakingListServerBackfillTicketsForPlayerResult*>(buffer);

    return S_OK;
}

