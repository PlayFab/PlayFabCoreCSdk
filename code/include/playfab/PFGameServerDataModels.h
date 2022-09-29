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
/// GameBuildStatus enum.
/// </summary>
enum class PFGameServerGameBuildStatus : uint32_t
{
    Available,
    Validating,
    InvalidBuildPackage,
    Processing,
    FailedToProcess
};

/// <summary>
/// PFGameServerModifyServerBuildRequest data model.
/// </summary>
typedef struct PFGameServerModifyServerBuildRequest
{
    /// <summary>
    /// (Optional) Array of regions where this build can used, when it is active.
    /// </summary>
    _Maybenull_ _Field_size_(activeRegionsCount) PFRegion const* activeRegions;

    /// <summary>
    /// Count of activeRegions
    /// </summary>
    uint32_t activeRegionsCount;

    /// <summary>
    /// Unique identifier of the previously uploaded build executable to be updated.
    /// </summary>
    _Null_terminated_ const char* buildId;

    /// <summary>
    /// (Optional) Appended to the end of the command line when starting game servers.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* commandLineTemplate;

    /// <summary>
    /// (Optional) Developer comment(s) for this build.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* comment;

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
    /// (Optional) Path to the game server executable. Defaults to gameserver.exe.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* executablePath;

    /// <summary>
    /// Maximum number of game server instances that can run on a single host machine.
    /// </summary>
    int32_t maxGamesPerHost;

    /// <summary>
    /// Minimum capacity of additional game server instances that can be started before the autoscaling
    /// service starts new host machines (given the number of current running host machines and game server
    /// instances).
    /// </summary>
    int32_t minFreeGameSlots;

    /// <summary>
    /// (Optional) New timestamp.
    /// </summary>
    _Maybenull_ time_t const* timestamp;

} PFGameServerModifyServerBuildRequest;

/// <summary>
/// PFGameServerModifyServerBuildResult data model.
/// </summary>
typedef struct PFGameServerModifyServerBuildResult
{
    /// <summary>
    /// (Optional) Array of regions where this build can used, when it is active.
    /// </summary>
    _Maybenull_ _Field_size_(activeRegionsCount) PFRegion const* activeRegions;

    /// <summary>
    /// Count of activeRegions
    /// </summary>
    uint32_t activeRegionsCount;

    /// <summary>
    /// (Optional) Unique identifier for this build executable.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildId;

    /// <summary>
    /// (Optional) Appended to the end of the command line when starting game servers.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* commandLineTemplate;

    /// <summary>
    /// (Optional) Developer comment(s) for this build.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* comment;

    /// <summary>
    /// (Optional) Path to the game server executable. Defaults to gameserver.exe.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* executablePath;

    /// <summary>
    /// Maximum number of game server instances that can run on a single host machine.
    /// </summary>
    int32_t maxGamesPerHost;

    /// <summary>
    /// Minimum capacity of additional game server instances that can be started before the autoscaling
    /// service starts new host machines (given the number of current running host machines and game server
    /// instances).
    /// </summary>
    int32_t minFreeGameSlots;

    /// <summary>
    /// (Optional) The current status of the build validation and processing steps.
    /// </summary>
    _Maybenull_ PFGameServerGameBuildStatus const* status;

    /// <summary>
    /// Time this build was last modified (or uploaded, if this build has never been modified).
    /// </summary>
    time_t timestamp;

    /// <summary>
    /// (Optional) Unique identifier for the title, found in the Settings > Game Properties section of
    /// the PlayFab developer site when a title has been selected.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* titleId;

} PFGameServerModifyServerBuildResult;

#pragma pop_macro("IN")

}
