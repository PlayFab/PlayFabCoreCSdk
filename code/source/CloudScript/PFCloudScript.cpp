#include "stdafx.h"
#include <playfab/PFCloudScript.h>
#include "CloudScript.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::CloudScript;

HRESULT PFCloudScriptAdminGetCloudScriptRevisionAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCloudScriptGetCloudScriptRevisionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::AdminGetCloudScriptRevision, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptAdminGetCloudScriptRevisionGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCloudScriptAdminGetCloudScriptRevisionGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptGetCloudScriptRevisionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCloudScriptGetCloudScriptRevisionResult*>(buffer);

    return S_OK;
}

HRESULT PFCloudScriptAdminGetCloudScriptVersionsAsync(
    _In_ PFStateHandle contextHandle,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::AdminGetCloudScriptVersions, contextHandle->state, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptAdminGetCloudScriptVersionsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCloudScriptAdminGetCloudScriptVersionsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptGetCloudScriptVersionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCloudScriptGetCloudScriptVersionsResult*>(buffer);

    return S_OK;
}

HRESULT PFCloudScriptAdminSetPublishedRevisionAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCloudScriptSetPublishedRevisionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::AdminSetPublishedRevision, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptAdminUpdateCloudScriptAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCloudScriptUpdateCloudScriptRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::AdminUpdateCloudScript, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptAdminUpdateCloudScriptGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFCloudScriptUpdateCloudScriptResult* result
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFCloudScriptUpdateCloudScriptResult), result, nullptr);
}

HRESULT PFCloudScriptClientExecuteCloudScriptAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFCloudScriptExecuteCloudScriptRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::ClientExecuteCloudScript, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptClientExecuteCloudScriptGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCloudScriptClientExecuteCloudScriptGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFExecuteCloudScriptResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFExecuteCloudScriptResult*>(buffer);

    return S_OK;
}

HRESULT PFCloudScriptServerExecuteCloudScriptAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFCloudScriptExecuteCloudScriptServerRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::ServerExecuteCloudScript, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptServerExecuteCloudScriptGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCloudScriptServerExecuteCloudScriptGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFExecuteCloudScriptResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFExecuteCloudScriptResult*>(buffer);

    return S_OK;
}

HRESULT PFCloudScriptExecuteEntityCloudScriptAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptExecuteEntityCloudScriptRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::ExecuteEntityCloudScript, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptExecuteEntityCloudScriptGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCloudScriptExecuteEntityCloudScriptGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFExecuteCloudScriptResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFExecuteCloudScriptResult*>(buffer);

    return S_OK;
}

HRESULT PFCloudScriptExecuteFunctionAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptExecuteFunctionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::ExecuteFunction, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptExecuteFunctionGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCloudScriptExecuteFunctionGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptExecuteFunctionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCloudScriptExecuteFunctionResult*>(buffer);

    return S_OK;
}

HRESULT PFCloudScriptGetFunctionAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptGetFunctionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::GetFunction, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptGetFunctionGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCloudScriptGetFunctionGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptGetFunctionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCloudScriptGetFunctionResult*>(buffer);

    return S_OK;
}

HRESULT PFCloudScriptListFunctionsAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptListFunctionsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::ListFunctions, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptListFunctionsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCloudScriptListFunctionsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptListFunctionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCloudScriptListFunctionsResult*>(buffer);

    return S_OK;
}

HRESULT PFCloudScriptListHttpFunctionsAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptListFunctionsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::ListHttpFunctions, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptListHttpFunctionsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCloudScriptListHttpFunctionsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptListHttpFunctionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCloudScriptListHttpFunctionsResult*>(buffer);

    return S_OK;
}

HRESULT PFCloudScriptListQueuedFunctionsAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptListFunctionsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::ListQueuedFunctions, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptListQueuedFunctionsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFCloudScriptListQueuedFunctionsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptListQueuedFunctionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFCloudScriptListQueuedFunctionsResult*>(buffer);

    return S_OK;
}

HRESULT PFCloudScriptPostFunctionResultForEntityTriggeredActionAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::PostFunctionResultForEntityTriggeredAction, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptPostFunctionResultForFunctionExecutionAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptPostFunctionResultForFunctionExecutionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::PostFunctionResultForFunctionExecution, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptPostFunctionResultForPlayerTriggeredActionAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::PostFunctionResultForPlayerTriggeredAction, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptPostFunctionResultForScheduledTaskAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptPostFunctionResultForScheduledTaskRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::PostFunctionResultForScheduledTask, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptRegisterHttpFunctionAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptRegisterHttpFunctionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::RegisterHttpFunction, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptRegisterQueuedFunctionAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptRegisterQueuedFunctionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::RegisterQueuedFunction, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFCloudScriptUnregisterFunctionAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFCloudScriptUnregisterFunctionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&CloudScriptAPI::UnregisterFunction, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

