#include "stdafx.h"
#include <playfab/PFAdvertising.h>
#include "Advertising.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::Advertising;

HRESULT PFAdvertisingClientAttributeInstallAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFAdvertisingAttributeInstallRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AdvertisingAPI::ClientAttributeInstall, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAdvertisingClientGetAdPlacementsAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFAdvertisingGetAdPlacementsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AdvertisingAPI::ClientGetAdPlacements, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAdvertisingClientGetAdPlacementsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFAdvertisingClientGetAdPlacementsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAdvertisingGetAdPlacementsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFAdvertisingGetAdPlacementsResult*>(buffer);

    return S_OK;
}

HRESULT PFAdvertisingClientReportAdActivityAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFAdvertisingReportAdActivityRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AdvertisingAPI::ClientReportAdActivity, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAdvertisingClientRewardAdActivityAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFAdvertisingRewardAdActivityRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AdvertisingAPI::ClientRewardAdActivity, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAdvertisingClientRewardAdActivityGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFAdvertisingClientRewardAdActivityGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAdvertisingRewardAdActivityResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFAdvertisingRewardAdActivityResult*>(buffer);

    return S_OK;
}

