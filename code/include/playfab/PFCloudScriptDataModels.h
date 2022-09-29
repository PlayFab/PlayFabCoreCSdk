// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFSharedDataModels.h>

extern "C"
{

#pragma push_macro("IN")
#undef IN

/// <summary>
/// CloudScriptRevisionOption enum.
/// </summary>
enum class PFCloudScriptCloudScriptRevisionOption : uint32_t
{
    Live,
    Latest,
    Specific
};

/// <summary>
/// PFCloudScriptGetCloudScriptRevisionRequest data model.
/// </summary>
typedef struct PFCloudScriptGetCloudScriptRevisionRequest
{
    /// <summary>
    /// (Optional) Revision number. If left null, defaults to the latest revision.
    /// </summary>
    _Maybenull_ int32_t const* revision;

    /// <summary>
    /// (Optional) Version number. If left null, defaults to the latest version.
    /// </summary>
    _Maybenull_ int32_t const* version;

} PFCloudScriptGetCloudScriptRevisionRequest;

/// <summary>
/// PFCloudScriptCloudScriptFile data model.
/// </summary>
typedef struct PFCloudScriptCloudScriptFile
{
    /// <summary>
    /// Contents of the Cloud Script javascript. Must be string-escaped javascript.
    /// </summary>
    _Null_terminated_ const char* fileContents;

    /// <summary>
    /// Name of the javascript file. These names are not used internally by the server, they are only
    /// for developer organizational purposes.
    /// </summary>
    _Null_terminated_ const char* filename;

} PFCloudScriptCloudScriptFile;

/// <summary>
/// PFCloudScriptGetCloudScriptRevisionResult data model.
/// </summary>
typedef struct PFCloudScriptGetCloudScriptRevisionResult
{
    /// <summary>
    /// Time this revision was created.
    /// </summary>
    time_t createdAt;

    /// <summary>
    /// (Optional) List of Cloud Script files in this revision.
    /// </summary>
    _Maybenull_ _Field_size_(filesCount) PFCloudScriptCloudScriptFile const* const* files;

    /// <summary>
    /// Count of files
    /// </summary>
    uint32_t filesCount;

    /// <summary>
    /// True if this is the currently published revision.
    /// </summary>
    bool isPublished;

    /// <summary>
    /// Revision number.
    /// </summary>
    int32_t revision;

    /// <summary>
    /// Version number.
    /// </summary>
    int32_t version;

} PFCloudScriptGetCloudScriptRevisionResult;

/// <summary>
/// PFCloudScriptCloudScriptVersionStatus data model.
/// </summary>
typedef struct PFCloudScriptCloudScriptVersionStatus
{
    /// <summary>
    /// Most recent revision for this Cloud Script version.
    /// </summary>
    int32_t latestRevision;

    /// <summary>
    /// Published code revision for this Cloud Script version.
    /// </summary>
    int32_t publishedRevision;

    /// <summary>
    /// Version number.
    /// </summary>
    int32_t version;

} PFCloudScriptCloudScriptVersionStatus;

/// <summary>
/// PFCloudScriptGetCloudScriptVersionsResult data model.
/// </summary>
typedef struct PFCloudScriptGetCloudScriptVersionsResult
{
    /// <summary>
    /// (Optional) List of versions.
    /// </summary>
    _Maybenull_ _Field_size_(versionsCount) PFCloudScriptCloudScriptVersionStatus const* const* versions;

    /// <summary>
    /// Count of versions
    /// </summary>
    uint32_t versionsCount;

} PFCloudScriptGetCloudScriptVersionsResult;

/// <summary>
/// PFCloudScriptSetPublishedRevisionRequest data model.
/// </summary>
typedef struct PFCloudScriptSetPublishedRevisionRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Revision to make the current published revision.
    /// </summary>
    int32_t revision;

    /// <summary>
    /// Version number.
    /// </summary>
    int32_t version;

} PFCloudScriptSetPublishedRevisionRequest;

/// <summary>
/// PFCloudScriptUpdateCloudScriptRequest data model.
/// </summary>
typedef struct PFCloudScriptUpdateCloudScriptRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) PlayFab user ID of the developer initiating the request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* developerPlayFabId;

    /// <summary>
    /// List of Cloud Script files to upload to create the new revision. Must have at least one file.
    /// </summary>
    _Field_size_(filesCount) PFCloudScriptCloudScriptFile const* const* files;

    /// <summary>
    /// Count of files
    /// </summary>
    uint32_t filesCount;

    /// <summary>
    /// Immediately publish the new revision.
    /// </summary>
    bool publish;

} PFCloudScriptUpdateCloudScriptRequest;

/// <summary>
/// PFCloudScriptUpdateCloudScriptResult data model.
/// </summary>
typedef struct PFCloudScriptUpdateCloudScriptResult
{
    /// <summary>
    /// New revision number created.
    /// </summary>
    int32_t revision;

    /// <summary>
    /// Cloud Script version updated.
    /// </summary>
    int32_t version;

} PFCloudScriptUpdateCloudScriptResult;

/// <summary>
/// PFCloudScriptExecuteCloudScriptRequest data model.
/// </summary>
typedef struct PFCloudScriptExecuteCloudScriptRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The name of the CloudScript function to execute.
    /// </summary>
    _Null_terminated_ const char* functionName;

    /// <summary>
    /// (Optional) Object that is passed in to the function as the first argument.
    /// </summary>
    PFJsonObject functionParameter;

    /// <summary>
    /// (Optional) Generate a 'player_executed_cloudscript' PlayStream event containing the results of
    /// the function execution and other contextual information. This event will show up in the PlayStream
    /// debugger console for the player in Game Manager.
    /// </summary>
    _Maybenull_ bool const* generatePlayStreamEvent;

    /// <summary>
    /// (Optional) Option for which revision of the CloudScript to execute. 'Latest' executes the most
    /// recently created revision, 'Live' executes the current live, published revision, and 'Specific'
    /// executes the specified revision. The default value is 'Specific', if the SpeificRevision parameter
    /// is specified, otherwise it is 'Live'.
    /// </summary>
    _Maybenull_ PFCloudScriptCloudScriptRevisionOption const* revisionSelection;

    /// <summary>
    /// (Optional) The specivic revision to execute, when RevisionSelection is set to 'Specific'.
    /// </summary>
    _Maybenull_ int32_t const* specificRevision;

} PFCloudScriptExecuteCloudScriptRequest;

/// <summary>
/// PFCloudScriptExecuteCloudScriptServerRequest data model.
/// </summary>
typedef struct PFCloudScriptExecuteCloudScriptServerRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The name of the CloudScript function to execute.
    /// </summary>
    _Null_terminated_ const char* functionName;

    /// <summary>
    /// (Optional) Object that is passed in to the function as the first argument.
    /// </summary>
    PFJsonObject functionParameter;

    /// <summary>
    /// (Optional) Generate a 'player_executed_cloudscript' PlayStream event containing the results of
    /// the function execution and other contextual information. This event will show up in the PlayStream
    /// debugger console for the player in Game Manager.
    /// </summary>
    _Maybenull_ bool const* generatePlayStreamEvent;

    /// <summary>
    /// The unique user identifier for the player on whose behalf the script is being run.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Option for which revision of the CloudScript to execute. 'Latest' executes the most
    /// recently created revision, 'Live' executes the current live, published revision, and 'Specific'
    /// executes the specified revision. The default value is 'Specific', if the SpeificRevision parameter
    /// is specified, otherwise it is 'Live'.
    /// </summary>
    _Maybenull_ PFCloudScriptCloudScriptRevisionOption const* revisionSelection;

    /// <summary>
    /// (Optional) The specivic revision to execute, when RevisionSelection is set to 'Specific'.
    /// </summary>
    _Maybenull_ int32_t const* specificRevision;

} PFCloudScriptExecuteCloudScriptServerRequest;

/// <summary>
/// PFCloudScriptExecuteEntityCloudScriptRequest data model. Executes CloudScript with the entity profile
/// that is defined in the request.
/// </summary>
typedef struct PFCloudScriptExecuteEntityCloudScriptRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The optional entity to perform this action on. Defaults to the currently logged in
    /// entity.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// The name of the CloudScript function to execute.
    /// </summary>
    _Null_terminated_ const char* functionName;

    /// <summary>
    /// (Optional) Object that is passed in to the function as the first argument.
    /// </summary>
    PFJsonObject functionParameter;

    /// <summary>
    /// (Optional) Generate a 'entity_executed_cloudscript' PlayStream event containing the results of
    /// the function execution and other contextual information. This event will show up in the PlayStream
    /// debugger console for the player in Game Manager.
    /// </summary>
    _Maybenull_ bool const* generatePlayStreamEvent;

    /// <summary>
    /// (Optional) Option for which revision of the CloudScript to execute. 'Latest' executes the most
    /// recently created revision, 'Live' executes the current live, published revision, and 'Specific'
    /// executes the specified revision. The default value is 'Specific', if the SpecificRevision parameter
    /// is specified, otherwise it is 'Live'.
    /// </summary>
    _Maybenull_ PFCloudScriptCloudScriptRevisionOption const* revisionSelection;

    /// <summary>
    /// (Optional) The specific revision to execute, when RevisionSelection is set to 'Specific'.
    /// </summary>
    _Maybenull_ int32_t const* specificRevision;

} PFCloudScriptExecuteEntityCloudScriptRequest;

/// <summary>
/// PFCloudScriptExecuteFunctionRequest data model. Executes an Azure Function with the profile of the
/// entity that is defined in the request.
/// </summary>
typedef struct PFCloudScriptExecuteFunctionRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The optional entity to perform this action on. Defaults to the currently logged in
    /// entity.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// The name of the CloudScript function to execute.
    /// </summary>
    _Null_terminated_ const char* functionName;

    /// <summary>
    /// (Optional) Object that is passed in to the function as the FunctionArgument field of the FunctionExecutionContext
    /// data structure.
    /// </summary>
    PFJsonObject functionParameter;

    /// <summary>
    /// (Optional) Generate a 'entity_executed_cloudscript_function' PlayStream event containing the
    /// results of the function execution and other contextual information. This event will show up in
    /// the PlayStream debugger console for the player in Game Manager.
    /// </summary>
    _Maybenull_ bool const* generatePlayStreamEvent;

} PFCloudScriptExecuteFunctionRequest;

/// <summary>
/// PFCloudScriptFunctionExecutionError data model.
/// </summary>
typedef struct PFCloudScriptFunctionExecutionError
{
    /// <summary>
    /// (Optional) Error code, such as CloudScriptAzureFunctionsExecutionTimeLimitExceeded, CloudScriptAzureFunctionsArgumentSizeExceeded,
    /// CloudScriptAzureFunctionsReturnSizeExceeded or CloudScriptAzureFunctionsHTTPRequestError.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* error;

    /// <summary>
    /// (Optional) Details about the error.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* message;

    /// <summary>
    /// (Optional) Point during the execution of the function at which the error occurred, if any.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* stackTrace;

} PFCloudScriptFunctionExecutionError;

/// <summary>
/// PFCloudScriptExecuteFunctionResult data model.
/// </summary>
typedef struct PFCloudScriptExecuteFunctionResult
{
    /// <summary>
    /// (Optional) Error from the CloudScript Azure Function.
    /// </summary>
    _Maybenull_ PFCloudScriptFunctionExecutionError const* error;

    /// <summary>
    /// The amount of time the function took to execute.
    /// </summary>
    int32_t executionTimeMilliseconds;

    /// <summary>
    /// (Optional) The name of the function that executed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* functionName;

    /// <summary>
    /// (Optional) The object returned from the function, if any.
    /// </summary>
    PFJsonObject functionResult;

    /// <summary>
    /// (Optional) Flag indicating if the FunctionResult was too large and was subsequently dropped from
    /// this event.
    /// </summary>
    _Maybenull_ bool const* functionResultTooLarge;

} PFCloudScriptExecuteFunctionResult;

/// <summary>
/// PFCloudScriptGetFunctionRequest data model.
/// </summary>
typedef struct PFCloudScriptGetFunctionRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The name of the function to register.
    /// </summary>
    _Null_terminated_ const char* functionName;

} PFCloudScriptGetFunctionRequest;

/// <summary>
/// PFCloudScriptGetFunctionResult data model.
/// </summary>
typedef struct PFCloudScriptGetFunctionResult
{
    /// <summary>
    /// (Optional) The connection string for the storage account containing the queue for a queue trigger
    /// Azure Function.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* connectionString;

    /// <summary>
    /// (Optional) The URL to be invoked to execute an HTTP triggered function.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* functionUrl;

    /// <summary>
    /// (Optional) The name of the queue for a queue trigger Azure Function.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* queueName;

    /// <summary>
    /// (Optional) The trigger type for the function.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* triggerType;

} PFCloudScriptGetFunctionResult;

/// <summary>
/// PFCloudScriptListFunctionsRequest data model. A title can have many functions, ListHttpFunctions
/// will return a list of all the currently registered HTTP triggered functions for a given title.
/// </summary>
typedef struct PFCloudScriptListFunctionsRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFCloudScriptListFunctionsRequest;

/// <summary>
/// PFCloudScriptFunctionModel data model.
/// </summary>
typedef struct PFCloudScriptFunctionModel
{
    /// <summary>
    /// (Optional) The address of the function.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* functionAddress;

    /// <summary>
    /// (Optional) The name the function was registered under.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* functionName;

    /// <summary>
    /// (Optional) The trigger type for the function.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* triggerType;

} PFCloudScriptFunctionModel;

/// <summary>
/// PFCloudScriptListFunctionsResult data model.
/// </summary>
typedef struct PFCloudScriptListFunctionsResult
{
    /// <summary>
    /// (Optional) The list of functions that are currently registered for the title.
    /// </summary>
    _Maybenull_ _Field_size_(functionsCount) PFCloudScriptFunctionModel const* const* functions;

    /// <summary>
    /// Count of functions
    /// </summary>
    uint32_t functionsCount;

} PFCloudScriptListFunctionsResult;

/// <summary>
/// PFCloudScriptHttpFunctionModel data model.
/// </summary>
typedef struct PFCloudScriptHttpFunctionModel
{
    /// <summary>
    /// (Optional) The name the function was registered under.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* functionName;

    /// <summary>
    /// (Optional) The URL of the function.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* functionUrl;

} PFCloudScriptHttpFunctionModel;

/// <summary>
/// PFCloudScriptListHttpFunctionsResult data model.
/// </summary>
typedef struct PFCloudScriptListHttpFunctionsResult
{
    /// <summary>
    /// (Optional) The list of HTTP triggered functions that are currently registered for the title.
    /// </summary>
    _Maybenull_ _Field_size_(functionsCount) PFCloudScriptHttpFunctionModel const* const* functions;

    /// <summary>
    /// Count of functions
    /// </summary>
    uint32_t functionsCount;

} PFCloudScriptListHttpFunctionsResult;

/// <summary>
/// PFCloudScriptQueuedFunctionModel data model.
/// </summary>
typedef struct PFCloudScriptQueuedFunctionModel
{
    /// <summary>
    /// (Optional) The connection string for the Azure Storage Account that hosts the queue.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* connectionString;

    /// <summary>
    /// (Optional) The name the function was registered under.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* functionName;

    /// <summary>
    /// (Optional) The name of the queue that triggers the Azure Function.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* queueName;

} PFCloudScriptQueuedFunctionModel;

/// <summary>
/// PFCloudScriptListQueuedFunctionsResult data model.
/// </summary>
typedef struct PFCloudScriptListQueuedFunctionsResult
{
    /// <summary>
    /// (Optional) The list of Queue triggered functions that are currently registered for the title.
    /// </summary>
    _Maybenull_ _Field_size_(functionsCount) PFCloudScriptQueuedFunctionModel const* const* functions;

    /// <summary>
    /// Count of functions
    /// </summary>
    uint32_t functionsCount;

} PFCloudScriptListQueuedFunctionsResult;

/// <summary>
/// PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest data model.
/// </summary>
typedef struct PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The entity to perform this action on.
    /// </summary>
    PFEntityKey const* entity;

    /// <summary>
    /// The result of the function execution.
    /// </summary>
    PFCloudScriptExecuteFunctionResult const* functionResult;

} PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest;

/// <summary>
/// PFCloudScriptPostFunctionResultForFunctionExecutionRequest data model.
/// </summary>
typedef struct PFCloudScriptPostFunctionResultForFunctionExecutionRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The entity to perform this action on.
    /// </summary>
    PFEntityKey const* entity;

    /// <summary>
    /// The result of the function execution.
    /// </summary>
    PFCloudScriptExecuteFunctionResult const* functionResult;

} PFCloudScriptPostFunctionResultForFunctionExecutionRequest;

/// <summary>
/// PFCloudScriptPlayStreamEventEnvelopeModel data model.
/// </summary>
typedef struct PFCloudScriptPlayStreamEventEnvelopeModel
{
    /// <summary>
    /// (Optional) The ID of the entity the event is about.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* entityId;

    /// <summary>
    /// (Optional) The type of the entity the event is about.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* entityType;

    /// <summary>
    /// (Optional) Data specific to this event.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* eventData;

    /// <summary>
    /// (Optional) The name of the event.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* eventName;

    /// <summary>
    /// (Optional) The namespace of the event.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* eventNamespace;

    /// <summary>
    /// (Optional) Settings for the event.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* eventSettings;

} PFCloudScriptPlayStreamEventEnvelopeModel;

/// <summary>
/// PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest data model.
/// </summary>
typedef struct PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The optional entity to perform this action on. Defaults to the currently logged in
    /// entity.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// The result of the function execution.
    /// </summary>
    PFCloudScriptExecuteFunctionResult const* functionResult;

    /// <summary>
    /// The player profile the function was invoked with.
    /// </summary>
    PFPlayerProfileModel const* playerProfile;

    /// <summary>
    /// (Optional) The triggering PlayStream event, if any, that caused the function to be invoked.
    /// </summary>
    _Maybenull_ PFCloudScriptPlayStreamEventEnvelopeModel const* playStreamEventEnvelope;

} PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest;

/// <summary>
/// PFCloudScriptPostFunctionResultForScheduledTaskRequest data model.
/// </summary>
typedef struct PFCloudScriptPostFunctionResultForScheduledTaskRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The entity to perform this action on.
    /// </summary>
    PFEntityKey const* entity;

    /// <summary>
    /// The result of the function execution.
    /// </summary>
    PFCloudScriptExecuteFunctionResult const* functionResult;

    /// <summary>
    /// The id of the scheduled task that invoked the function.
    /// </summary>
    PFNameIdentifier const* scheduledTaskId;

} PFCloudScriptPostFunctionResultForScheduledTaskRequest;

/// <summary>
/// PFCloudScriptRegisterHttpFunctionRequest data model.
/// </summary>
typedef struct PFCloudScriptRegisterHttpFunctionRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The name of the function to register.
    /// </summary>
    _Null_terminated_ const char* functionName;

    /// <summary>
    /// Full URL for Azure Function that implements the function.
    /// </summary>
    _Null_terminated_ const char* functionUrl;

} PFCloudScriptRegisterHttpFunctionRequest;

/// <summary>
/// PFCloudScriptRegisterQueuedFunctionRequest data model. A title can have many functions, RegisterQueuedFunction
/// associates a function name with a queue name and connection string.
/// </summary>
typedef struct PFCloudScriptRegisterQueuedFunctionRequest
{
    /// <summary>
    /// A connection string for the storage account that hosts the queue for the Azure Function.
    /// </summary>
    _Null_terminated_ const char* connectionString;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The name of the function to register.
    /// </summary>
    _Null_terminated_ const char* functionName;

    /// <summary>
    /// The name of the queue for the Azure Function.
    /// </summary>
    _Null_terminated_ const char* queueName;

} PFCloudScriptRegisterQueuedFunctionRequest;

/// <summary>
/// PFCloudScriptUnregisterFunctionRequest data model.
/// </summary>
typedef struct PFCloudScriptUnregisterFunctionRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The name of the function to register.
    /// </summary>
    _Null_terminated_ const char* functionName;

} PFCloudScriptUnregisterFunctionRequest;

#pragma pop_macro("IN")

}
