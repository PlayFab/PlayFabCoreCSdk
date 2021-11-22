#include "stdafx.h"
#include <playfab/PFCharacter.h>
#include "Character.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::Character;

HRESULT PFCharacterAdminResetCharacterStatisticsAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterResetCharacterStatisticsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::AdminResetCharacterStatistics, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterClientGetAllUsersCharactersAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFCharacterListUsersCharactersRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ClientGetAllUsersCharacters, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterClientGetAllUsersCharactersGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterClientGetAllUsersCharactersGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterListUsersCharactersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterListUsersCharactersResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterClientGetCharacterDataAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFCharacterGetCharacterDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ClientGetCharacterData, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterClientGetCharacterDataGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterClientGetCharacterDataGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterClientGetCharacterDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterClientGetCharacterDataResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterClientGetCharacterLeaderboardAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFCharacterGetCharacterLeaderboardRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ClientGetCharacterLeaderboard, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterClientGetCharacterLeaderboardGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterClientGetCharacterLeaderboardGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetCharacterLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterGetCharacterLeaderboardResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterClientGetCharacterReadOnlyDataAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFCharacterGetCharacterDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ClientGetCharacterReadOnlyData, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterClientGetCharacterReadOnlyDataGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterClientGetCharacterReadOnlyDataGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterClientGetCharacterDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterClientGetCharacterDataResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterClientGetCharacterStatisticsAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFCharacterClientGetCharacterStatisticsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ClientGetCharacterStatistics, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterClientGetCharacterStatisticsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterClientGetCharacterStatisticsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterClientGetCharacterStatisticsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterClientGetCharacterStatisticsResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterClientGetLeaderboardAroundCharacterAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFCharacterClientGetLeaderboardAroundCharacterRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ClientGetLeaderboardAroundCharacter, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterClientGetLeaderboardAroundCharacterGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterClientGetLeaderboardAroundCharacterGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetLeaderboardAroundCharacterResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterGetLeaderboardAroundCharacterResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterClientGetLeaderboardForUserCharactersAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFCharacterClientGetLeaderboardForUsersCharactersRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ClientGetLeaderboardForUserCharacters, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterClientGetLeaderboardForUserCharactersGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterClientGetLeaderboardForUserCharactersGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetLeaderboardForUsersCharactersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterGetLeaderboardForUsersCharactersResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterClientGrantCharacterToUserAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFCharacterClientGrantCharacterToUserRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ClientGrantCharacterToUser, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterClientGrantCharacterToUserGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterClientGrantCharacterToUserGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterClientGrantCharacterToUserResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterClientGrantCharacterToUserResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterClientUpdateCharacterDataAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFCharacterClientUpdateCharacterDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ClientUpdateCharacterData, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterClientUpdateCharacterDataGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFCharacterUpdateCharacterDataResult* result
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFCharacterUpdateCharacterDataResult), result, nullptr);
}

HRESULT PFCharacterClientUpdateCharacterStatisticsAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFCharacterClientUpdateCharacterStatisticsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ClientUpdateCharacterStatistics, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerDeleteCharacterFromUserAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterDeleteCharacterFromUserRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerDeleteCharacterFromUser, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerGetAllUsersCharactersAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterListUsersCharactersRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerGetAllUsersCharacters, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerGetAllUsersCharactersGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterServerGetAllUsersCharactersGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterListUsersCharactersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterListUsersCharactersResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterServerGetCharacterDataAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterGetCharacterDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerGetCharacterData, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerGetCharacterDataGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterServerGetCharacterDataGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterServerGetCharacterDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterServerGetCharacterDataResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterServerGetCharacterInternalDataAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterGetCharacterDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerGetCharacterInternalData, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerGetCharacterInternalDataGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterServerGetCharacterInternalDataGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterServerGetCharacterDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterServerGetCharacterDataResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterServerGetCharacterLeaderboardAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterGetCharacterLeaderboardRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerGetCharacterLeaderboard, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerGetCharacterLeaderboardGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterServerGetCharacterLeaderboardGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetCharacterLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterGetCharacterLeaderboardResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterServerGetCharacterReadOnlyDataAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterGetCharacterDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerGetCharacterReadOnlyData, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerGetCharacterReadOnlyDataGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterServerGetCharacterReadOnlyDataGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterServerGetCharacterDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterServerGetCharacterDataResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterServerGetCharacterStatisticsAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterServerGetCharacterStatisticsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerGetCharacterStatistics, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerGetCharacterStatisticsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterServerGetCharacterStatisticsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterServerGetCharacterStatisticsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterServerGetCharacterStatisticsResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterServerGetLeaderboardAroundCharacterAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterServerGetLeaderboardAroundCharacterRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerGetLeaderboardAroundCharacter, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerGetLeaderboardAroundCharacterGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterServerGetLeaderboardAroundCharacterGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetLeaderboardAroundCharacterResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterGetLeaderboardAroundCharacterResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterServerGetLeaderboardForUserCharactersAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterServerGetLeaderboardForUsersCharactersRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerGetLeaderboardForUserCharacters, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerGetLeaderboardForUserCharactersGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterServerGetLeaderboardForUserCharactersGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetLeaderboardForUsersCharactersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterGetLeaderboardForUsersCharactersResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterServerGrantCharacterToUserAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterServerGrantCharacterToUserRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerGrantCharacterToUser, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerGrantCharacterToUserGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCharacterServerGrantCharacterToUserGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterServerGrantCharacterToUserResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCharacterServerGrantCharacterToUserResult*>(buffer);

    return S_OK;
}

HRESULT PFCharacterServerUpdateCharacterDataAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterServerUpdateCharacterDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerUpdateCharacterData, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerUpdateCharacterDataGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFCharacterUpdateCharacterDataResult* result
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFCharacterUpdateCharacterDataResult), result, nullptr);
}

HRESULT PFCharacterServerUpdateCharacterInternalDataAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterServerUpdateCharacterDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerUpdateCharacterInternalData, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerUpdateCharacterInternalDataGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFCharacterUpdateCharacterDataResult* result
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFCharacterUpdateCharacterDataResult), result, nullptr);
}

HRESULT PFCharacterServerUpdateCharacterReadOnlyDataAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterServerUpdateCharacterDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerUpdateCharacterReadOnlyData, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCharacterServerUpdateCharacterReadOnlyDataGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFCharacterUpdateCharacterDataResult* result
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFCharacterUpdateCharacterDataResult), result, nullptr);
}

HRESULT PFCharacterServerUpdateCharacterStatisticsAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCharacterServerUpdateCharacterStatisticsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CharacterAPI::ServerUpdateCharacterStatistics, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

