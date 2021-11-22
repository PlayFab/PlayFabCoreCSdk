#include "stdafx.h"
#include <playfab/PFTitlePlayer.h>
#include "TitlePlayer.h"

using namespace PlayFab;

HRESULT PFTitlePlayerDuplicateHandle(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ PFTitlePlayerHandle* duplicatedHandle
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(duplicatedHandle);

    *duplicatedHandle = MakeUnique<PFTitlePlayer>(*titlePlayerHandle).release();
    return S_OK;
}

void PFTitlePlayerCloseHandle(
    _In_ PFTitlePlayerHandle titlePlayerHandle
) noexcept
{
    UniquePtr<PFTitlePlayer>{ titlePlayerHandle };
}

HRESULT PFTitlePlayerGetEntityHandle(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ PFEntityHandle* entityHandle
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(entityHandle);

    *entityHandle = MakeUnique<PFEntity>(titlePlayerHandle->titlePlayer).release();
    return S_OK;
}

HRESULT PFTitlePlayerGetPlayFabIdSize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* playFabIdSize
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(playFabIdSize);

    *playFabIdSize = titlePlayerHandle->titlePlayer->PlayFabId().size() + 1;
    return S_OK;
}

HRESULT PFTitlePlayerGetPlayFabId(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t playFabIdSize,
    _Out_writes_bytes_to_opt_(playFabIdSize, playFabIdUsed) char* playFabIdBuffer,
    _Out_opt_ size_t* playFabIdUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(playFabIdBuffer);

    auto playFabId = titlePlayerHandle->titlePlayer->PlayFabId();
    if (playFabId.size() + 1 > playFabIdSize)
    {
        return E_INVALIDARG;
    }

    std::strcpy(playFabIdBuffer, playFabId.data());
    if (playFabIdUsed)
    {
        *playFabIdUsed = playFabId.size() + 1;
    }

    return S_OK;
}

HRESULT PFTitlePlayerGetCachedSessionTicketSize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* sessionTicketSize
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(sessionTicketSize);

    auto sessionTicket = titlePlayerHandle->titlePlayer->SessionTicket();
    assert(sessionTicket);
    if (!sessionTicket)
    {
        return E_UNEXPECTED;
    }

    *sessionTicketSize = sessionTicket->size() + 1;
    return S_OK;
}

HRESULT PFTitlePlayerGetCachedSessionTicket(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t sessionTicketBufferSize,
    _Out_writes_bytes_to_opt_(sessionTicketSize, *bufferUsed) char* sessionTicketBuffer,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(sessionTicketBuffer);

    auto sessionTicket = titlePlayerHandle->titlePlayer->SessionTicket();
    assert(sessionTicket);
    if (!sessionTicket)
    {
        return E_UNEXPECTED;
    }

    if (sessionTicket->size() + 1 > sessionTicketBufferSize)
    {
        return E_INVALIDARG;
    }

    std::strcpy(sessionTicketBuffer, sessionTicket->data());
    if (bufferUsed)
    {
        *bufferUsed = sessionTicket->size() + 1;
    }
   
    return S_OK;
}

HRESULT PFTitlePlayerGetEntityKeySize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* bufferSize
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);

    PFEntity entity{ titlePlayerHandle->titlePlayer };
    return PFEntityGetEntityKeySize(&entity, bufferSize);
}

HRESULT PFTitlePlayerGetEntityKey(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFEntityKey** entityKey,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);

    PFEntity entity{ titlePlayerHandle->titlePlayer };
    return PFEntityGetEntityKey(&entity, bufferSize, buffer, entityKey, bufferUsed);
}

HRESULT PFTitlePlayerGetCachedEntityTokenSize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* bufferSize
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);

    PFEntity entity{ titlePlayerHandle->titlePlayer };
    return PFEntityGetCachedEntityTokenSize(&entity, bufferSize);
}

HRESULT PFTitlePlayerGetCachedEntityToken(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFEntityToken** entityToken,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);

    PFEntity entity{ titlePlayerHandle->titlePlayer };
    return PFEntityGetCachedEntityToken(&entity, bufferSize, buffer, entityToken, bufferUsed);
}

HRESULT PFTitlePlayerGetPlayerCombinedInfoSize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* bufferSize
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(bufferSize);

    auto& playerCombinedInfo = titlePlayerHandle->titlePlayer->PlayerCombinedInfo();
    if (playerCombinedInfo)
    {
        *bufferSize = playerCombinedInfo->RequiredBufferSize();
    }
    else
    {
        *bufferSize = 0;
    }
    return S_OK;
}

HRESULT PFTitlePlayerGetPlayerCombinedInfo(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFGetPlayerCombinedInfoResultPayload** playerCombinedInfoPtr,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(buffer);
    RETURN_HR_INVALIDARG_IF_NULL(playerCombinedInfoPtr);

    ModelBuffer b{ buffer, bufferSize };
    auto& playerCombinedInfo = titlePlayerHandle->titlePlayer->PlayerCombinedInfo();
    if (playerCombinedInfo)
    {
        auto copyResult = playerCombinedInfo->Copy(b);
        RETURN_IF_FAILED(copyResult.hr);
        *playerCombinedInfoPtr = copyResult.ExtractPayload();
    }
    else
    {
        TRACE_INFORMATION("PFGetPlayerCombinedInfoResultPayload not cached for this TitlePlayer");
        *playerCombinedInfoPtr = nullptr;
    }

    if (bufferUsed)
    {
        *bufferUsed = bufferSize - b.RemainingSpace();
    }

    return S_OK;
}

HRESULT PFTitlePlayerGetLastLoginTime(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ time_t* lastLoginTimePointer
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(lastLoginTimePointer);

    auto lastLoginTime = titlePlayerHandle->titlePlayer->LastLoginTime();
    if (lastLoginTime)
    {
        *lastLoginTimePointer = *lastLoginTime;
    }
    else
    {
        // Set to default per header docs
        *lastLoginTimePointer = time_t{ 0 };
    }

    return S_OK;
}

HRESULT PFTitlePlayerGetUserSettings(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ PFAuthenticationUserSettings* userSettingsPtr
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(userSettingsPtr);

    auto& userSettings = titlePlayerHandle->titlePlayer->UserSettings();
    if (userSettings)
    {
        *userSettingsPtr = titlePlayerHandle->titlePlayer->UserSettings()->Model();
    }
    else
    {
        TRACE_INFORMATION("PFAuthenticationUserSettings not cached for this TitlePlayer");
        *userSettingsPtr = {};
    }
    return S_OK;
}

HRESULT PFTitlePlayerGetTreatmentAssignmentSize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* bufferSize
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(bufferSize);

    auto& treatmentAssignment = titlePlayerHandle->titlePlayer->TreatmentAssignment();
    if (treatmentAssignment)
    {
        *bufferSize = treatmentAssignment->RequiredBufferSize();
    }
    else
    {
        *bufferSize = 0;
    }
    return S_OK;
}

HRESULT PFTitlePlayerGetTreatmentAssignment(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFTreatmentAssignment** treatmentAssignmentPtr,
    _Out_opt_ size_t* bufferUsed
) noexcept 
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(buffer);
    RETURN_HR_INVALIDARG_IF_NULL(treatmentAssignmentPtr);

    ModelBuffer b{ buffer, bufferSize };
    auto& treatmentAssignment = titlePlayerHandle->titlePlayer->TreatmentAssignment();
    if (treatmentAssignment)
    {
        auto copyResult = treatmentAssignment->Copy(b);
        RETURN_IF_FAILED(copyResult.hr);
        *treatmentAssignmentPtr = copyResult.ExtractPayload();
    }
    else
    {
        TRACE_INFORMATION("PFTreatmentAssignment not cached for this TitlePlayer");
        *treatmentAssignmentPtr = nullptr;
    }

    if (bufferUsed)
    {
        *bufferUsed = bufferSize - b.RemainingSpace();
    }

    return S_OK;
}
