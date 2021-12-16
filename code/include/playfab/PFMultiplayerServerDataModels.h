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
/// ContainerFlavor enum.
/// </summary>
enum class PFMultiplayerServerContainerFlavor : uint32_t
{
    ManagedWindowsServerCore,
    CustomLinux,
    ManagedWindowsServerCorePreview,
    Invalid
};

/// <summary>
/// AzureVmSize enum.
/// </summary>
enum class PFMultiplayerServerAzureVmSize : uint32_t
{
    Standard_A1,
    Standard_A2,
    Standard_A3,
    Standard_A4,
    Standard_A1_v2,
    Standard_A2_v2,
    Standard_A4_v2,
    Standard_A8_v2,
    Standard_D1_v2,
    Standard_D2_v2,
    Standard_D3_v2,
    Standard_D4_v2,
    Standard_D5_v2,
    Standard_D2_v3,
    Standard_D4_v3,
    Standard_D8_v3,
    Standard_D16_v3,
    Standard_F1,
    Standard_F2,
    Standard_F4,
    Standard_F8,
    Standard_F16,
    Standard_F2s_v2,
    Standard_F4s_v2,
    Standard_F8s_v2,
    Standard_F16s_v2,
    Standard_D2as_v4,
    Standard_D4as_v4,
    Standard_D8as_v4,
    Standard_D16as_v4,
    Standard_D2a_v4,
    Standard_D4a_v4,
    Standard_D8a_v4,
    Standard_D16a_v4,
    Standard_E2a_v4,
    Standard_E4a_v4,
    Standard_E8a_v4,
    Standard_E16a_v4,
    Standard_E2as_v4,
    Standard_E4as_v4,
    Standard_E8as_v4,
    Standard_E16as_v4,
    Standard_D2s_v3,
    Standard_D4s_v3,
    Standard_D8s_v3,
    Standard_D16s_v3,
    Standard_DS1_v2,
    Standard_DS2_v2,
    Standard_DS3_v2,
    Standard_DS4_v2,
    Standard_DS5_v2,
    Standard_NC4as_T4_v3,
    Standard_D2d_v4,
    Standard_D4d_v4,
    Standard_D8d_v4,
    Standard_D16d_v4,
    Standard_D2ds_v4,
    Standard_D4ds_v4,
    Standard_D8ds_v4,
    Standard_D16ds_v4,
    Standard_HB120_16rs_v3,
    Standard_HB120_32rs_v3,
    Standard_HB120_64rs_v3,
    Standard_HB120_96rs_v3,
    Standard_HB120rs_v3
};

/// <summary>
/// AzureVmFamily enum.
/// </summary>
enum class PFMultiplayerServerAzureVmFamily : uint32_t
{
    A,
    Av2,
    Dv2,
    Dv3,
    F,
    Fsv2,
    Dasv4,
    Dav4,
    Eav4,
    Easv4,
    Ev4,
    Esv4,
    Dsv3,
    Dsv2,
    NCasT4_v3,
    Ddv4,
    Ddsv4,
    HBv3
};

/// <summary>
/// TitleMultiplayerServerEnabledStatus enum.
/// </summary>
enum class PFMultiplayerServerTitleMultiplayerServerEnabledStatus : uint32_t
{
    Initializing,
    Enabled,
    Disabled
};

/// <summary>
/// PFMultiplayerServerBuildSelectionCriterion data model.
/// </summary>
typedef struct PFMultiplayerServerBuildSelectionCriterion
{
    /// <summary>
    /// (Optional) Dictionary of build ids and their respective weights for distribution of allocation
    /// requests.
    /// </summary>
    _Maybenull_ _Field_size_(buildWeightDistributionCount) struct PFUint32DictionaryEntry const* buildWeightDistribution;

    /// <summary>
    /// Count of buildWeightDistribution
    /// </summary>
    uint32_t buildWeightDistributionCount;

} PFMultiplayerServerBuildSelectionCriterion;

/// <summary>
/// PFMultiplayerServerCreateBuildAliasRequest data model. Creates a multiplayer server build alias and
/// returns the created alias.
/// </summary>
typedef struct PFMultiplayerServerCreateBuildAliasRequest
{
    /// <summary>
    /// The alias name.
    /// </summary>
    _Null_terminated_ const char* aliasName;

    /// <summary>
    /// (Optional) Array of build selection criteria.
    /// </summary>
    _Maybenull_ _Field_size_(buildSelectionCriteriaCount) PFMultiplayerServerBuildSelectionCriterion const* const* buildSelectionCriteria;

    /// <summary>
    /// Count of buildSelectionCriteria
    /// </summary>
    uint32_t buildSelectionCriteriaCount;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFMultiplayerServerCreateBuildAliasRequest;

/// <summary>
/// PFMultiplayerServerBuildAliasDetailsResponse data model.
/// </summary>
typedef struct PFMultiplayerServerBuildAliasDetailsResponse
{
    /// <summary>
    /// (Optional) The guid string alias Id of the alias to be created or updated.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* aliasId;

    /// <summary>
    /// (Optional) The alias name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* aliasName;

    /// <summary>
    /// (Optional) Array of build selection criteria.
    /// </summary>
    _Maybenull_ _Field_size_(buildSelectionCriteriaCount) PFMultiplayerServerBuildSelectionCriterion const* const* buildSelectionCriteria;

    /// <summary>
    /// Count of buildSelectionCriteria
    /// </summary>
    uint32_t buildSelectionCriteriaCount;

} PFMultiplayerServerBuildAliasDetailsResponse;

/// <summary>
/// PFMultiplayerServerContainerImageReference data model.
/// </summary>
typedef struct PFMultiplayerServerContainerImageReference
{
    /// <summary>
    /// The container image name.
    /// </summary>
    _Null_terminated_ const char* imageName;

    /// <summary>
    /// (Optional) The container tag.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* tag;

} PFMultiplayerServerContainerImageReference;

/// <summary>
/// PFMultiplayerServerAssetReferenceParams data model.
/// </summary>
typedef struct PFMultiplayerServerAssetReferenceParams
{
    /// <summary>
    /// The asset's file name.
    /// </summary>
    _Null_terminated_ const char* fileName;

    /// <summary>
    /// (Optional) The asset's mount path.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* mountPath;

} PFMultiplayerServerAssetReferenceParams;

/// <summary>
/// PFMultiplayerServerGameCertificateReferenceParams data model.
/// </summary>
typedef struct PFMultiplayerServerGameCertificateReferenceParams
{
    /// <summary>
    /// An alias for the game certificate. The game server will reference this alias via GSDK config
    /// to retrieve the game certificate. This alias is used as an identifier in game server code to allow
    /// a new certificate with different Name field to be uploaded without the need to change any game
    /// server code to reference the new Name.
    /// </summary>
    _Null_terminated_ const char* gsdkAlias;

    /// <summary>
    /// The name of the game certificate. This name should match the name of a certificate that was previously
    /// uploaded to this title.
    /// </summary>
    _Null_terminated_ const char* name;

} PFMultiplayerServerGameCertificateReferenceParams;

/// <summary>
/// PFMultiplayerServerLinuxInstrumentationConfiguration data model.
/// </summary>
typedef struct PFMultiplayerServerLinuxInstrumentationConfiguration
{
    /// <summary>
    /// Designates whether Linux instrumentation configuration will be enabled for this Build.
    /// </summary>
    bool isEnabled;

} PFMultiplayerServerLinuxInstrumentationConfiguration;

/// <summary>
/// PFMultiplayerServerMonitoringApplicationConfigurationParams data model.
/// </summary>
typedef struct PFMultiplayerServerMonitoringApplicationConfigurationParams
{
    /// <summary>
    /// Asset which contains the monitoring application files and scripts.
    /// </summary>
    PFMultiplayerServerAssetReferenceParams const* assetReference;

    /// <summary>
    /// Execution script name, this will be the main executable for the monitoring application.
    /// </summary>
    _Null_terminated_ const char* executionScriptName;

    /// <summary>
    /// (Optional) Installation script name, this will be run before the ExecutionScript.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* installationScriptName;

    /// <summary>
    /// (Optional) Timespan the monitoring application will be kept alive when running from the start
    /// of the VM.
    /// </summary>
    _Maybenull_ double const* onStartRuntimeInMinutes;

} PFMultiplayerServerMonitoringApplicationConfigurationParams;

/// <summary>
/// PFMultiplayerServerDynamicStandbyThreshold data model.
/// </summary>
typedef struct PFMultiplayerServerDynamicStandbyThreshold
{
    /// <summary>
    /// When the trigger threshold is reached, multiply by this value.
    /// </summary>
    double multiplier;

    /// <summary>
    /// The multiplier will be applied when the actual standby divided by target standby floor is less
    /// than this value.
    /// </summary>
    double triggerThresholdPercentage;

} PFMultiplayerServerDynamicStandbyThreshold;

/// <summary>
/// PFMultiplayerServerDynamicStandbySettings data model.
/// </summary>
typedef struct PFMultiplayerServerDynamicStandbySettings
{
    /// <summary>
    /// (Optional) List of auto standing by trigger values and corresponding standing by multiplier.
    /// Defaults to 1.5X at 50%, 3X at 25%, and 4X at 5%.
    /// </summary>
    _Maybenull_ _Field_size_(dynamicFloorMultiplierThresholdsCount) PFMultiplayerServerDynamicStandbyThreshold const* const* dynamicFloorMultiplierThresholds;

    /// <summary>
    /// Count of dynamicFloorMultiplierThresholds
    /// </summary>
    uint32_t dynamicFloorMultiplierThresholdsCount;

    /// <summary>
    /// When true, dynamic standby will be enabled.
    /// </summary>
    bool isEnabled;

    /// <summary>
    /// (Optional) The time it takes to reduce target standing by to configured floor value after an
    /// increase. Defaults to 30 minutes.
    /// </summary>
    _Maybenull_ int32_t const* rampDownSeconds;

} PFMultiplayerServerDynamicStandbySettings;

/// <summary>
/// PFMultiplayerServerSchedule data model.
/// </summary>
typedef struct PFMultiplayerServerSchedule
{
    /// <summary>
    /// (Optional) A short description about this schedule. For example, "Game launch on July 15th".
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// The date and time in UTC at which the schedule ends. If IsRecurringWeekly is true, this schedule
    /// will keep renewing for future weeks until disabled or removed.
    /// </summary>
    time_t endTime;

    /// <summary>
    /// Disables the schedule.
    /// </summary>
    bool isDisabled;

    /// <summary>
    /// If true, the StartTime and EndTime will get renewed every week.
    /// </summary>
    bool isRecurringWeekly;

    /// <summary>
    /// The date and time in UTC at which the schedule starts.
    /// </summary>
    time_t startTime;

    /// <summary>
    /// The standby target to maintain for the duration of the schedule.
    /// </summary>
    int32_t targetStandby;

} PFMultiplayerServerSchedule;

/// <summary>
/// PFMultiplayerServerScheduledStandbySettings data model.
/// </summary>
typedef struct PFMultiplayerServerScheduledStandbySettings
{
    /// <summary>
    /// When true, scheduled standby will be enabled.
    /// </summary>
    bool isEnabled;

    /// <summary>
    /// (Optional) A list of non-overlapping schedules.
    /// </summary>
    _Maybenull_ _Field_size_(scheduleListCount) PFMultiplayerServerSchedule const* const* scheduleList;

    /// <summary>
    /// Count of scheduleList
    /// </summary>
    uint32_t scheduleListCount;

} PFMultiplayerServerScheduledStandbySettings;

/// <summary>
/// PFMultiplayerServerBuildRegionParams data model.
/// </summary>
typedef struct PFMultiplayerServerBuildRegionParams
{
    /// <summary>
    /// (Optional) Optional settings to control dynamic adjustment of standby target. If not specified,
    /// dynamic standby is disabled.
    /// </summary>
    _Maybenull_ PFMultiplayerServerDynamicStandbySettings const* dynamicStandbySettings;

    /// <summary>
    /// The maximum number of multiplayer servers for the region.
    /// </summary>
    int32_t maxServers;

    /// <summary>
    /// (Optional) Regional override for the number of multiplayer servers to host on a single VM of
    /// the build.
    /// </summary>
    _Maybenull_ int32_t const* multiplayerServerCountPerVm;

    /// <summary>
    /// The build region.
    /// </summary>
    _Null_terminated_ const char* region;

    /// <summary>
    /// (Optional) Optional settings to set the standby target to specified values during the supplied
    /// schedules.
    /// </summary>
    _Maybenull_ PFMultiplayerServerScheduledStandbySettings const* scheduledStandbySettings;

    /// <summary>
    /// The number of standby multiplayer servers for the region.
    /// </summary>
    int32_t standbyServers;

    /// <summary>
    /// (Optional) Regional override for the VM size the build was created on.
    /// </summary>
    _Maybenull_ PFMultiplayerServerAzureVmSize const* vmSize;

} PFMultiplayerServerBuildRegionParams;

/// <summary>
/// PFMultiplayerServerCreateBuildWithCustomContainerRequest data model. Creates a multiplayer server
/// build with a custom container and returns information about the build creation request.
/// </summary>
typedef struct PFMultiplayerServerCreateBuildWithCustomContainerRequest
{
    /// <summary>
    /// (Optional) When true, assets will not be copied for each server inside the VM. All serverswill
    /// run from the same set of assets, or will have the same assets mounted in the container.
    /// </summary>
    _Maybenull_ bool const* areAssetsReadonly;

    /// <summary>
    /// The build name.
    /// </summary>
    _Null_terminated_ const char* buildName;

    /// <summary>
    /// (Optional) The flavor of container to create a build from.
    /// </summary>
    _Maybenull_ PFMultiplayerServerContainerFlavor const* containerFlavor;

    /// <summary>
    /// (Optional) The container reference, consisting of the image name and tag.
    /// </summary>
    _Maybenull_ PFMultiplayerServerContainerImageReference const* containerImageReference;

    /// <summary>
    /// (Optional) The container command to run when the multiplayer server has been allocated, including
    /// any arguments.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* containerRunCommand;

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
    /// (Optional) The list of game assets related to the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameAssetReferencesCount) PFMultiplayerServerAssetReferenceParams const* const* gameAssetReferences;

    /// <summary>
    /// Count of gameAssetReferences
    /// </summary>
    uint32_t gameAssetReferencesCount;

    /// <summary>
    /// (Optional) The game certificates for the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameCertificateReferencesCount) PFMultiplayerServerGameCertificateReferenceParams const* const* gameCertificateReferences;

    /// <summary>
    /// Count of gameCertificateReferences
    /// </summary>
    uint32_t gameCertificateReferencesCount;

    /// <summary>
    /// (Optional) The Linux instrumentation configuration for the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerLinuxInstrumentationConfiguration const* linuxInstrumentationConfiguration;

    /// <summary>
    /// (Optional) Metadata to tag the build. The keys are case insensitive. The build metadata is made
    /// available to the server through Game Server SDK (GSDK).Constraints: Maximum number of keys: 30,
    /// Maximum key length: 50, Maximum value length: 100.
    /// </summary>
    _Maybenull_ _Field_size_(metadataCount) struct PFStringDictionaryEntry const* metadata;

    /// <summary>
    /// Count of metadata
    /// </summary>
    uint32_t metadataCount;

    /// <summary>
    /// (Optional) The configuration for the monitoring application on the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerMonitoringApplicationConfigurationParams const* monitoringApplicationConfiguration;

    /// <summary>
    /// The number of multiplayer servers to host on a single VM.
    /// </summary>
    int32_t multiplayerServerCountPerVm;

    /// <summary>
    /// The ports to map the build on.
    /// </summary>
    _Field_size_(portsCount) PFPort const* const* ports;

    /// <summary>
    /// Count of ports
    /// </summary>
    uint32_t portsCount;

    /// <summary>
    /// The region configurations for the build.
    /// </summary>
    _Field_size_(regionConfigurationsCount) PFMultiplayerServerBuildRegionParams const* const* regionConfigurations;

    /// <summary>
    /// Count of regionConfigurations
    /// </summary>
    uint32_t regionConfigurationsCount;

    /// <summary>
    /// (Optional) When true, assets will be downloaded and uncompressed in memory, without the compressedversion
    /// being written first to disc.
    /// </summary>
    _Maybenull_ bool const* useStreamingForAssetDownloads;

    /// <summary>
    /// (Optional) The VM size to create the build on.
    /// </summary>
    _Maybenull_ PFMultiplayerServerAzureVmSize const* vmSize;

} PFMultiplayerServerCreateBuildWithCustomContainerRequest;

/// <summary>
/// PFMultiplayerServerAssetReference data model.
/// </summary>
typedef struct PFMultiplayerServerAssetReference
{
    /// <summary>
    /// (Optional) The asset's file name. This is a filename with the .zip, .tar, or .tar.gz extension.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* fileName;

    /// <summary>
    /// (Optional) The asset's mount path.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* mountPath;

} PFMultiplayerServerAssetReference;

/// <summary>
/// PFMultiplayerServerGameCertificateReference data model.
/// </summary>
typedef struct PFMultiplayerServerGameCertificateReference
{
    /// <summary>
    /// (Optional) An alias for the game certificate. The game server will reference this alias via GSDK
    /// config to retrieve the game certificate. This alias is used as an identifier in game server code
    /// to allow a new certificate with different Name field to be uploaded without the need to change
    /// any game server code to reference the new Name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* gsdkAlias;

    /// <summary>
    /// (Optional) The name of the game certificate. This name should match the name of a certificate
    /// that was previously uploaded to this title.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* name;

} PFMultiplayerServerGameCertificateReference;

/// <summary>
/// PFMultiplayerServerMonitoringApplicationConfiguration data model.
/// </summary>
typedef struct PFMultiplayerServerMonitoringApplicationConfiguration
{
    /// <summary>
    /// Asset which contains the monitoring application files and scripts.
    /// </summary>
    PFMultiplayerServerAssetReference const* assetReference;

    /// <summary>
    /// Execution script name, this will be the main executable for the monitoring application.
    /// </summary>
    _Null_terminated_ const char* executionScriptName;

    /// <summary>
    /// (Optional) Installation script name, this will be run before the ExecutionScript.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* installationScriptName;

    /// <summary>
    /// (Optional) Timespan the monitoring application will be kept alive when running from the start
    /// of the VM.
    /// </summary>
    _Maybenull_ double const* onStartRuntimeInMinutes;

} PFMultiplayerServerMonitoringApplicationConfiguration;

/// <summary>
/// PFMultiplayerServerCurrentServerStats data model.
/// </summary>
typedef struct PFMultiplayerServerCurrentServerStats
{
    /// <summary>
    /// The number of active multiplayer servers.
    /// </summary>
    int32_t active;

    /// <summary>
    /// The number of multiplayer servers still downloading game resources (such as assets).
    /// </summary>
    int32_t propping;

    /// <summary>
    /// The number of standingby multiplayer servers.
    /// </summary>
    int32_t standingBy;

    /// <summary>
    /// The total number of multiplayer servers.
    /// </summary>
    int32_t total;

} PFMultiplayerServerCurrentServerStats;

/// <summary>
/// PFMultiplayerServerBuildRegion data model.
/// </summary>
typedef struct PFMultiplayerServerBuildRegion
{
    /// <summary>
    /// (Optional) The current multiplayer server stats for the region.
    /// </summary>
    _Maybenull_ PFMultiplayerServerCurrentServerStats const* currentServerStats;

    /// <summary>
    /// (Optional) Optional settings to control dynamic adjustment of standby target.
    /// </summary>
    _Maybenull_ PFMultiplayerServerDynamicStandbySettings const* dynamicStandbySettings;

    /// <summary>
    /// The maximum number of multiplayer servers for the region.
    /// </summary>
    int32_t maxServers;

    /// <summary>
    /// (Optional) Regional override for the number of multiplayer servers to host on a single VM of
    /// the build.
    /// </summary>
    _Maybenull_ int32_t const* multiplayerServerCountPerVm;

    /// <summary>
    /// (Optional) The build region.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* region;

    /// <summary>
    /// (Optional) Optional settings to set the standby target to specified values during the supplied
    /// schedules.
    /// </summary>
    _Maybenull_ PFMultiplayerServerScheduledStandbySettings const* scheduledStandbySettings;

    /// <summary>
    /// The target number of standby multiplayer servers for the region.
    /// </summary>
    int32_t standbyServers;

    /// <summary>
    /// (Optional) The status of multiplayer servers in the build region. Valid values are - Unknown,
    /// Initialized, Deploying, Deployed, Unhealthy, Deleting, Deleted.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* status;

    /// <summary>
    /// (Optional) Regional override for the VM size the build was created on.
    /// </summary>
    _Maybenull_ PFMultiplayerServerAzureVmSize const* vmSize;

} PFMultiplayerServerBuildRegion;

/// <summary>
/// PFMultiplayerServerCreateBuildWithCustomContainerResponse data model.
/// </summary>
typedef struct PFMultiplayerServerCreateBuildWithCustomContainerResponse
{
    /// <summary>
    /// (Optional) When true, assets will not be copied for each server inside the VM. All serverswill
    /// run from the same set of assets, or will have the same assets mounted in the container.
    /// </summary>
    _Maybenull_ bool const* areAssetsReadonly;

    /// <summary>
    /// (Optional) The guid string build ID. Must be unique for every build.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildId;

    /// <summary>
    /// (Optional) The build name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildName;

    /// <summary>
    /// (Optional) The flavor of container of the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerContainerFlavor const* containerFlavor;

    /// <summary>
    /// (Optional) The container command to run when the multiplayer server has been allocated, including
    /// any arguments.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* containerRunCommand;

    /// <summary>
    /// (Optional) The time the build was created in UTC.
    /// </summary>
    _Maybenull_ time_t const* creationTime;

    /// <summary>
    /// (Optional) The custom game container image reference information.
    /// </summary>
    _Maybenull_ PFMultiplayerServerContainerImageReference const* customGameContainerImage;

    /// <summary>
    /// (Optional) The game assets for the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameAssetReferencesCount) PFMultiplayerServerAssetReference const* const* gameAssetReferences;

    /// <summary>
    /// Count of gameAssetReferences
    /// </summary>
    uint32_t gameAssetReferencesCount;

    /// <summary>
    /// (Optional) The game certificates for the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameCertificateReferencesCount) PFMultiplayerServerGameCertificateReference const* const* gameCertificateReferences;

    /// <summary>
    /// Count of gameCertificateReferences
    /// </summary>
    uint32_t gameCertificateReferencesCount;

    /// <summary>
    /// (Optional) The Linux instrumentation configuration for this build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerLinuxInstrumentationConfiguration const* linuxInstrumentationConfiguration;

    /// <summary>
    /// (Optional) The metadata of the build.
    /// </summary>
    _Maybenull_ _Field_size_(metadataCount) struct PFStringDictionaryEntry const* metadata;

    /// <summary>
    /// Count of metadata
    /// </summary>
    uint32_t metadataCount;

    /// <summary>
    /// (Optional) The configuration for the monitoring application for the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerMonitoringApplicationConfiguration const* monitoringApplicationConfiguration;

    /// <summary>
    /// The number of multiplayer servers to host on a single VM of the build.
    /// </summary>
    int32_t multiplayerServerCountPerVm;

    /// <summary>
    /// (Optional) The OS platform used for running the game process.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* osPlatform;

    /// <summary>
    /// (Optional) The ports the build is mapped on.
    /// </summary>
    _Maybenull_ _Field_size_(portsCount) PFPort const* const* ports;

    /// <summary>
    /// Count of ports
    /// </summary>
    uint32_t portsCount;

    /// <summary>
    /// (Optional) The region configuration for the build.
    /// </summary>
    _Maybenull_ _Field_size_(regionConfigurationsCount) PFMultiplayerServerBuildRegion const* const* regionConfigurations;

    /// <summary>
    /// Count of regionConfigurations
    /// </summary>
    uint32_t regionConfigurationsCount;

    /// <summary>
    /// (Optional) The type of game server being hosted.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverType;

    /// <summary>
    /// (Optional) When true, assets will be downloaded and uncompressed in memory, without the compressedversion
    /// being written first to disc.
    /// </summary>
    _Maybenull_ bool const* useStreamingForAssetDownloads;

    /// <summary>
    /// (Optional) The VM size the build was created on.
    /// </summary>
    _Maybenull_ PFMultiplayerServerAzureVmSize const* vmSize;

} PFMultiplayerServerCreateBuildWithCustomContainerResponse;

/// <summary>
/// PFMultiplayerServerInstrumentationConfiguration data model.
/// </summary>
typedef struct PFMultiplayerServerInstrumentationConfiguration
{
    /// <summary>
    /// (Optional) Designates whether windows instrumentation configuration will be enabled for this
    /// Build.
    /// </summary>
    _Maybenull_ bool const* isEnabled;

    /// <summary>
    /// (Optional) This property is deprecated, use IsEnabled. The list of processes to be monitored
    /// on a VM for this build. Providing processes will turn on performance metrics collection for this
    /// build. Process names should not include extensions. If the game server process is: GameServer.exe;
    /// then, ProcessesToMonitor = [ GameServer ] .
    /// </summary>
    _Maybenull_ _Field_size_(processesToMonitorCount) const char* const* processesToMonitor;

    /// <summary>
    /// Count of processesToMonitor
    /// </summary>
    uint32_t processesToMonitorCount;

} PFMultiplayerServerInstrumentationConfiguration;

/// <summary>
/// PFMultiplayerServerCreateBuildWithManagedContainerRequest data model. Creates a multiplayer server
/// build with a managed container and returns information about the build creation request.
/// </summary>
typedef struct PFMultiplayerServerCreateBuildWithManagedContainerRequest
{
    /// <summary>
    /// (Optional) When true, assets will not be copied for each server inside the VM. All serverswill
    /// run from the same set of assets, or will have the same assets mounted in the container.
    /// </summary>
    _Maybenull_ bool const* areAssetsReadonly;

    /// <summary>
    /// The build name.
    /// </summary>
    _Null_terminated_ const char* buildName;

    /// <summary>
    /// (Optional) The flavor of container to create a build from.
    /// </summary>
    _Maybenull_ PFMultiplayerServerContainerFlavor const* containerFlavor;

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
    /// The list of game assets related to the build.
    /// </summary>
    _Field_size_(gameAssetReferencesCount) PFMultiplayerServerAssetReferenceParams const* const* gameAssetReferences;

    /// <summary>
    /// Count of gameAssetReferences
    /// </summary>
    uint32_t gameAssetReferencesCount;

    /// <summary>
    /// (Optional) The game certificates for the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameCertificateReferencesCount) PFMultiplayerServerGameCertificateReferenceParams const* const* gameCertificateReferences;

    /// <summary>
    /// Count of gameCertificateReferences
    /// </summary>
    uint32_t gameCertificateReferencesCount;

    /// <summary>
    /// (Optional) The directory containing the game executable. This would be the start path of the
    /// game assets that contain the main game server executable. If not provided, a best effort will
    /// be made to extract it from the start game command.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* gameWorkingDirectory;

    /// <summary>
    /// (Optional) The instrumentation configuration for the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerInstrumentationConfiguration const* instrumentationConfiguration;

    /// <summary>
    /// (Optional) Metadata to tag the build. The keys are case insensitive. The build metadata is made
    /// available to the server through Game Server SDK (GSDK).Constraints: Maximum number of keys: 30,
    /// Maximum key length: 50, Maximum value length: 100.
    /// </summary>
    _Maybenull_ _Field_size_(metadataCount) struct PFStringDictionaryEntry const* metadata;

    /// <summary>
    /// Count of metadata
    /// </summary>
    uint32_t metadataCount;

    /// <summary>
    /// (Optional) The configuration for the monitoring application on the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerMonitoringApplicationConfigurationParams const* monitoringApplicationConfiguration;

    /// <summary>
    /// The number of multiplayer servers to host on a single VM.
    /// </summary>
    int32_t multiplayerServerCountPerVm;

    /// <summary>
    /// The ports to map the build on.
    /// </summary>
    _Field_size_(portsCount) PFPort const* const* ports;

    /// <summary>
    /// Count of ports
    /// </summary>
    uint32_t portsCount;

    /// <summary>
    /// The region configurations for the build.
    /// </summary>
    _Field_size_(regionConfigurationsCount) PFMultiplayerServerBuildRegionParams const* const* regionConfigurations;

    /// <summary>
    /// Count of regionConfigurations
    /// </summary>
    uint32_t regionConfigurationsCount;

    /// <summary>
    /// The command to run when the multiplayer server is started, including any arguments.
    /// </summary>
    _Null_terminated_ const char* startMultiplayerServerCommand;

    /// <summary>
    /// (Optional) When true, assets will be downloaded and uncompressed in memory, without the compressedversion
    /// being written first to disc.
    /// </summary>
    _Maybenull_ bool const* useStreamingForAssetDownloads;

    /// <summary>
    /// (Optional) The VM size to create the build on.
    /// </summary>
    _Maybenull_ PFMultiplayerServerAzureVmSize const* vmSize;

} PFMultiplayerServerCreateBuildWithManagedContainerRequest;

/// <summary>
/// PFMultiplayerServerCreateBuildWithManagedContainerResponse data model.
/// </summary>
typedef struct PFMultiplayerServerCreateBuildWithManagedContainerResponse
{
    /// <summary>
    /// (Optional) When true, assets will not be copied for each server inside the VM. All serverswill
    /// run from the same set of assets, or will have the same assets mounted in the container.
    /// </summary>
    _Maybenull_ bool const* areAssetsReadonly;

    /// <summary>
    /// (Optional) The guid string build ID. Must be unique for every build.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildId;

    /// <summary>
    /// (Optional) The build name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildName;

    /// <summary>
    /// (Optional) The flavor of container of the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerContainerFlavor const* containerFlavor;

    /// <summary>
    /// (Optional) The time the build was created in UTC.
    /// </summary>
    _Maybenull_ time_t const* creationTime;

    /// <summary>
    /// (Optional) The game assets for the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameAssetReferencesCount) PFMultiplayerServerAssetReference const* const* gameAssetReferences;

    /// <summary>
    /// Count of gameAssetReferences
    /// </summary>
    uint32_t gameAssetReferencesCount;

    /// <summary>
    /// (Optional) The game certificates for the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameCertificateReferencesCount) PFMultiplayerServerGameCertificateReference const* const* gameCertificateReferences;

    /// <summary>
    /// Count of gameCertificateReferences
    /// </summary>
    uint32_t gameCertificateReferencesCount;

    /// <summary>
    /// (Optional) The directory containing the game executable. This would be the start path of the
    /// game assets that contain the main game server executable. If not provided, a best effort will
    /// be made to extract it from the start game command.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* gameWorkingDirectory;

    /// <summary>
    /// (Optional) The instrumentation configuration for this build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerInstrumentationConfiguration const* instrumentationConfiguration;

    /// <summary>
    /// (Optional) The metadata of the build.
    /// </summary>
    _Maybenull_ _Field_size_(metadataCount) struct PFStringDictionaryEntry const* metadata;

    /// <summary>
    /// Count of metadata
    /// </summary>
    uint32_t metadataCount;

    /// <summary>
    /// (Optional) The configuration for the monitoring application for the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerMonitoringApplicationConfiguration const* monitoringApplicationConfiguration;

    /// <summary>
    /// The number of multiplayer servers to host on a single VM of the build.
    /// </summary>
    int32_t multiplayerServerCountPerVm;

    /// <summary>
    /// (Optional) The OS platform used for running the game process.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* osPlatform;

    /// <summary>
    /// (Optional) The ports the build is mapped on.
    /// </summary>
    _Maybenull_ _Field_size_(portsCount) PFPort const* const* ports;

    /// <summary>
    /// Count of ports
    /// </summary>
    uint32_t portsCount;

    /// <summary>
    /// (Optional) The region configuration for the build.
    /// </summary>
    _Maybenull_ _Field_size_(regionConfigurationsCount) PFMultiplayerServerBuildRegion const* const* regionConfigurations;

    /// <summary>
    /// Count of regionConfigurations
    /// </summary>
    uint32_t regionConfigurationsCount;

    /// <summary>
    /// (Optional) The type of game server being hosted.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverType;

    /// <summary>
    /// (Optional) The command to run when the multiplayer server has been allocated, including any arguments.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* startMultiplayerServerCommand;

    /// <summary>
    /// (Optional) When true, assets will be downloaded and uncompressed in memory, without the compressedversion
    /// being written first to disc.
    /// </summary>
    _Maybenull_ bool const* useStreamingForAssetDownloads;

    /// <summary>
    /// (Optional) The VM size the build was created on.
    /// </summary>
    _Maybenull_ PFMultiplayerServerAzureVmSize const* vmSize;

} PFMultiplayerServerCreateBuildWithManagedContainerResponse;

/// <summary>
/// PFMultiplayerServerCreateBuildWithProcessBasedServerRequest data model. Creates a multiplayer server
/// build with the game server running as a process and returns information about the build creation request.
/// </summary>
typedef struct PFMultiplayerServerCreateBuildWithProcessBasedServerRequest
{
    /// <summary>
    /// (Optional) When true, assets will not be copied for each server inside the VM. All serverswill
    /// run from the same set of assets, or will have the same assets mounted in the container.
    /// </summary>
    _Maybenull_ bool const* areAssetsReadonly;

    /// <summary>
    /// The build name.
    /// </summary>
    _Null_terminated_ const char* buildName;

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
    /// The list of game assets related to the build.
    /// </summary>
    _Field_size_(gameAssetReferencesCount) PFMultiplayerServerAssetReferenceParams const* const* gameAssetReferences;

    /// <summary>
    /// Count of gameAssetReferences
    /// </summary>
    uint32_t gameAssetReferencesCount;

    /// <summary>
    /// (Optional) The game certificates for the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameCertificateReferencesCount) PFMultiplayerServerGameCertificateReferenceParams const* const* gameCertificateReferences;

    /// <summary>
    /// Count of gameCertificateReferences
    /// </summary>
    uint32_t gameCertificateReferencesCount;

    /// <summary>
    /// (Optional) The working directory for the game process. If this is not provided, the working directory
    /// will be set based on the mount path of the game server executable.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* gameWorkingDirectory;

    /// <summary>
    /// (Optional) The instrumentation configuration for the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerInstrumentationConfiguration const* instrumentationConfiguration;

    /// <summary>
    /// (Optional) Indicates whether this build will be created using the OS Preview versionPreview OS
    /// is recommended for dev builds to detect any breaking changes before they are released to retail.
    /// Retail builds should set this value to false.
    /// </summary>
    _Maybenull_ bool const* isOSPreview;

    /// <summary>
    /// (Optional) Metadata to tag the build. The keys are case insensitive. The build metadata is made
    /// available to the server through Game Server SDK (GSDK).Constraints: Maximum number of keys: 30,
    /// Maximum key length: 50, Maximum value length: 100.
    /// </summary>
    _Maybenull_ _Field_size_(metadataCount) struct PFStringDictionaryEntry const* metadata;

    /// <summary>
    /// Count of metadata
    /// </summary>
    uint32_t metadataCount;

    /// <summary>
    /// (Optional) The configuration for the monitoring application on the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerMonitoringApplicationConfigurationParams const* monitoringApplicationConfiguration;

    /// <summary>
    /// The number of multiplayer servers to host on a single VM.
    /// </summary>
    int32_t multiplayerServerCountPerVm;

    /// <summary>
    /// (Optional) The OS platform used for running the game process.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* osPlatform;

    /// <summary>
    /// The ports to map the build on.
    /// </summary>
    _Field_size_(portsCount) PFPort const* const* ports;

    /// <summary>
    /// Count of ports
    /// </summary>
    uint32_t portsCount;

    /// <summary>
    /// The region configurations for the build.
    /// </summary>
    _Field_size_(regionConfigurationsCount) PFMultiplayerServerBuildRegionParams const* const* regionConfigurations;

    /// <summary>
    /// Count of regionConfigurations
    /// </summary>
    uint32_t regionConfigurationsCount;

    /// <summary>
    /// The command to run when the multiplayer server is started, including any arguments. The path
    /// to any executable should be relative to the root asset folder when unzipped.
    /// </summary>
    _Null_terminated_ const char* startMultiplayerServerCommand;

    /// <summary>
    /// (Optional) When true, assets will be downloaded and uncompressed in memory, without the compressedversion
    /// being written first to disc.
    /// </summary>
    _Maybenull_ bool const* useStreamingForAssetDownloads;

    /// <summary>
    /// (Optional) The VM size to create the build on.
    /// </summary>
    _Maybenull_ PFMultiplayerServerAzureVmSize const* vmSize;

} PFMultiplayerServerCreateBuildWithProcessBasedServerRequest;

/// <summary>
/// PFMultiplayerServerCreateBuildWithProcessBasedServerResponse data model.
/// </summary>
typedef struct PFMultiplayerServerCreateBuildWithProcessBasedServerResponse
{
    /// <summary>
    /// (Optional) When true, assets will not be copied for each server inside the VM. All serverswill
    /// run from the same set of assets, or will have the same assets mounted in the container.
    /// </summary>
    _Maybenull_ bool const* areAssetsReadonly;

    /// <summary>
    /// (Optional) The guid string build ID. Must be unique for every build.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildId;

    /// <summary>
    /// (Optional) The build name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildName;

    /// <summary>
    /// (Optional) The flavor of container of the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerContainerFlavor const* containerFlavor;

    /// <summary>
    /// (Optional) The time the build was created in UTC.
    /// </summary>
    _Maybenull_ time_t const* creationTime;

    /// <summary>
    /// (Optional) The game assets for the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameAssetReferencesCount) PFMultiplayerServerAssetReference const* const* gameAssetReferences;

    /// <summary>
    /// Count of gameAssetReferences
    /// </summary>
    uint32_t gameAssetReferencesCount;

    /// <summary>
    /// (Optional) The game certificates for the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameCertificateReferencesCount) PFMultiplayerServerGameCertificateReference const* const* gameCertificateReferences;

    /// <summary>
    /// Count of gameCertificateReferences
    /// </summary>
    uint32_t gameCertificateReferencesCount;

    /// <summary>
    /// (Optional) The working directory for the game process. If this is not provided, the working directory
    /// will be set based on the mount path of the game server executable.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* gameWorkingDirectory;

    /// <summary>
    /// (Optional) The instrumentation configuration for this build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerInstrumentationConfiguration const* instrumentationConfiguration;

    /// <summary>
    /// (Optional) Indicates whether this build will be created using the OS Preview versionPreview OS
    /// is recommended for dev builds to detect any breaking changes before they are released to retail.
    /// Retail builds should set this value to false.
    /// </summary>
    _Maybenull_ bool const* isOSPreview;

    /// <summary>
    /// (Optional) The metadata of the build.
    /// </summary>
    _Maybenull_ _Field_size_(metadataCount) struct PFStringDictionaryEntry const* metadata;

    /// <summary>
    /// Count of metadata
    /// </summary>
    uint32_t metadataCount;

    /// <summary>
    /// (Optional) The configuration for the monitoring application for the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerMonitoringApplicationConfiguration const* monitoringApplicationConfiguration;

    /// <summary>
    /// The number of multiplayer servers to host on a single VM of the build.
    /// </summary>
    int32_t multiplayerServerCountPerVm;

    /// <summary>
    /// (Optional) The OS platform used for running the game process.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* osPlatform;

    /// <summary>
    /// (Optional) The ports the build is mapped on.
    /// </summary>
    _Maybenull_ _Field_size_(portsCount) PFPort const* const* ports;

    /// <summary>
    /// Count of ports
    /// </summary>
    uint32_t portsCount;

    /// <summary>
    /// (Optional) The region configuration for the build.
    /// </summary>
    _Maybenull_ _Field_size_(regionConfigurationsCount) PFMultiplayerServerBuildRegion const* const* regionConfigurations;

    /// <summary>
    /// Count of regionConfigurations
    /// </summary>
    uint32_t regionConfigurationsCount;

    /// <summary>
    /// (Optional) The type of game server being hosted.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverType;

    /// <summary>
    /// (Optional) The command to run when the multiplayer server is started, including any arguments.
    /// The path to any executable is relative to the root asset folder when unzipped.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* startMultiplayerServerCommand;

    /// <summary>
    /// (Optional) When true, assets will be downloaded and uncompressed in memory, without the compressedversion
    /// being written first to disc.
    /// </summary>
    _Maybenull_ bool const* useStreamingForAssetDownloads;

    /// <summary>
    /// (Optional) The VM size the build was created on.
    /// </summary>
    _Maybenull_ PFMultiplayerServerAzureVmSize const* vmSize;

} PFMultiplayerServerCreateBuildWithProcessBasedServerResponse;

/// <summary>
/// PFMultiplayerServerCreateRemoteUserRequest data model. Creates a remote user to log on to a VM for
/// a multiplayer server build in a specific region. Returns user credential information necessary to
/// log on.
/// </summary>
typedef struct PFMultiplayerServerCreateRemoteUserRequest
{
    /// <summary>
    /// The guid string build ID of to create the remote user for.
    /// </summary>
    _Null_terminated_ const char* buildId;

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
    /// (Optional) The expiration time for the remote user created. Defaults to expiring in one day if
    /// not specified.
    /// </summary>
    _Maybenull_ time_t const* expirationTime;

    /// <summary>
    /// The region of virtual machine to create the remote user for.
    /// </summary>
    _Null_terminated_ const char* region;

    /// <summary>
    /// The username to create the remote user with.
    /// </summary>
    _Null_terminated_ const char* username;

    /// <summary>
    /// The virtual machine ID the multiplayer server is located on.
    /// </summary>
    _Null_terminated_ const char* vmId;

} PFMultiplayerServerCreateRemoteUserRequest;

/// <summary>
/// PFMultiplayerServerCreateRemoteUserResponse data model.
/// </summary>
typedef struct PFMultiplayerServerCreateRemoteUserResponse
{
    /// <summary>
    /// (Optional) The expiration time for the remote user created.
    /// </summary>
    _Maybenull_ time_t const* expirationTime;

    /// <summary>
    /// (Optional) The generated password for the remote user that was created.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* password;

    /// <summary>
    /// (Optional) The username for the remote user that was created.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* username;

} PFMultiplayerServerCreateRemoteUserResponse;

/// <summary>
/// PFMultiplayerServerCoreCapacityChange data model.
/// </summary>
typedef struct PFMultiplayerServerCoreCapacityChange
{
    /// <summary>
    /// New quota core limit for the given vm family/region.
    /// </summary>
    int32_t newCoreLimit;

    /// <summary>
    /// Region to change.
    /// </summary>
    _Null_terminated_ const char* region;

    /// <summary>
    /// Virtual machine family to change.
    /// </summary>
    PFMultiplayerServerAzureVmFamily vmFamily;

} PFMultiplayerServerCoreCapacityChange;

/// <summary>
/// PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest data model. Creates a request
/// to change a title's multiplayer server quotas.
/// </summary>
typedef struct PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest
{
    /// <summary>
    /// (Optional) A brief description of the requested changes.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* changeDescription;

    /// <summary>
    /// Changes to make to the titles cores quota.
    /// </summary>
    _Field_size_(changesCount) PFMultiplayerServerCoreCapacityChange const* const* changes;

    /// <summary>
    /// Count of changes
    /// </summary>
    uint32_t changesCount;

    /// <summary>
    /// (Optional) Email to be contacted by our team about this request. Only required when a request
    /// is not approved.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* contactEmail;

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
    /// (Optional) Additional information about this request that our team can use to better understand
    /// the requirements.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* notes;

    /// <summary>
    /// (Optional) When these changes would need to be in effect. Only required when a request is not
    /// approved.
    /// </summary>
    _Maybenull_ time_t const* startDate;

} PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest;

/// <summary>
/// PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse data model.
/// </summary>
typedef struct PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse
{
    /// <summary>
    /// (Optional) Id of the change request that was created.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* requestId;

    /// <summary>
    /// Determines if the request was approved or not. When false, our team is reviewing and may respond
    /// within 2 business days.
    /// </summary>
    bool wasApproved;

} PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse;

/// <summary>
/// PFMultiplayerServerDeleteAssetRequest data model. Deletes a multiplayer server game asset for a title.
/// </summary>
typedef struct PFMultiplayerServerDeleteAssetRequest
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
    /// The filename of the asset to delete.
    /// </summary>
    _Null_terminated_ const char* fileName;

} PFMultiplayerServerDeleteAssetRequest;

/// <summary>
/// PFMultiplayerServerDeleteBuildRequest data model. Deletes a multiplayer server build.
/// </summary>
typedef struct PFMultiplayerServerDeleteBuildRequest
{
    /// <summary>
    /// The guid string build ID of the build to delete.
    /// </summary>
    _Null_terminated_ const char* buildId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFMultiplayerServerDeleteBuildRequest;

/// <summary>
/// PFMultiplayerServerDeleteBuildAliasRequest data model. Deletes a multiplayer server build alias.
/// </summary>
typedef struct PFMultiplayerServerDeleteBuildAliasRequest
{
    /// <summary>
    /// The guid string alias ID of the alias to perform the action on.
    /// </summary>
    _Null_terminated_ const char* aliasId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFMultiplayerServerDeleteBuildAliasRequest;

/// <summary>
/// PFMultiplayerServerDeleteBuildRegionRequest data model. Removes a multiplayer server build's region.
/// </summary>
typedef struct PFMultiplayerServerDeleteBuildRegionRequest
{
    /// <summary>
    /// The guid string ID of the build we want to update regions for.
    /// </summary>
    _Null_terminated_ const char* buildId;

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
    /// The build region to delete.
    /// </summary>
    _Null_terminated_ const char* region;

} PFMultiplayerServerDeleteBuildRegionRequest;

/// <summary>
/// PFMultiplayerServerDeleteCertificateRequest data model. Deletes a multiplayer server game certificate.
/// </summary>
typedef struct PFMultiplayerServerDeleteCertificateRequest
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
    /// The name of the certificate.
    /// </summary>
    _Null_terminated_ const char* name;

} PFMultiplayerServerDeleteCertificateRequest;

/// <summary>
/// PFMultiplayerServerDeleteContainerImageRequest data model. Removes the specified container image
/// repository. After this operation, a 'docker pull' will fail for all the tags of the specified image.
/// Morever, ListContainerImages will not return the specified image.
/// </summary>
typedef struct PFMultiplayerServerDeleteContainerImageRequest
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
    /// (Optional) The container image repository we want to delete.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* imageName;

} PFMultiplayerServerDeleteContainerImageRequest;

/// <summary>
/// PFMultiplayerServerDeleteRemoteUserRequest data model. Deletes a remote user to log on to a VM for
/// a multiplayer server build in a specific region. Returns user credential information necessary to
/// log on.
/// </summary>
typedef struct PFMultiplayerServerDeleteRemoteUserRequest
{
    /// <summary>
    /// The guid string build ID of the multiplayer server where the remote user is to delete.
    /// </summary>
    _Null_terminated_ const char* buildId;

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
    /// The region of the multiplayer server where the remote user is to delete.
    /// </summary>
    _Null_terminated_ const char* region;

    /// <summary>
    /// The username of the remote user to delete.
    /// </summary>
    _Null_terminated_ const char* username;

    /// <summary>
    /// The virtual machine ID the multiplayer server is located on.
    /// </summary>
    _Null_terminated_ const char* vmId;

} PFMultiplayerServerDeleteRemoteUserRequest;

/// <summary>
/// PFMultiplayerServerEnableMultiplayerServersForTitleRequest data model. Enables the multiplayer server
/// feature for a title and returns the enabled status. The enabled status can be Initializing, Enabled,
/// and Disabled. It can up to 20 minutes or more for the title to be enabled for the feature. On average,
/// it can take up to 20 minutes for the title to be enabled for the feature.
/// </summary>
typedef struct PFMultiplayerServerEnableMultiplayerServersForTitleRequest
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

} PFMultiplayerServerEnableMultiplayerServersForTitleRequest;

/// <summary>
/// PFMultiplayerServerEnableMultiplayerServersForTitleResponse data model.
/// </summary>
typedef struct PFMultiplayerServerEnableMultiplayerServersForTitleResponse
{
    /// <summary>
    /// (Optional) The enabled status for the multiplayer server features for the title.
    /// </summary>
    _Maybenull_ PFMultiplayerServerTitleMultiplayerServerEnabledStatus const* status;

} PFMultiplayerServerEnableMultiplayerServersForTitleResponse;

/// <summary>
/// PFMultiplayerServerGetAssetDownloadUrlRequest data model. Gets a URL that can be used to download
/// the specified asset.
/// </summary>
typedef struct PFMultiplayerServerGetAssetDownloadUrlRequest
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
    /// The asset's file name to get the download URL for.
    /// </summary>
    _Null_terminated_ const char* fileName;

} PFMultiplayerServerGetAssetDownloadUrlRequest;

/// <summary>
/// PFMultiplayerServerGetAssetDownloadUrlResponse data model.
/// </summary>
typedef struct PFMultiplayerServerGetAssetDownloadUrlResponse
{
    /// <summary>
    /// (Optional) The asset's download URL.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* assetDownloadUrl;

    /// <summary>
    /// (Optional) The asset's file name to get the download URL for.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* fileName;

} PFMultiplayerServerGetAssetDownloadUrlResponse;

/// <summary>
/// PFMultiplayerServerGetAssetUploadUrlRequest data model. Gets the URL to upload assets to.
/// </summary>
typedef struct PFMultiplayerServerGetAssetUploadUrlRequest
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
    /// The asset's file name to get the upload URL for.
    /// </summary>
    _Null_terminated_ const char* fileName;

} PFMultiplayerServerGetAssetUploadUrlRequest;

/// <summary>
/// PFMultiplayerServerGetAssetUploadUrlResponse data model.
/// </summary>
typedef struct PFMultiplayerServerGetAssetUploadUrlResponse
{
    /// <summary>
    /// (Optional) The asset's upload URL.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* assetUploadUrl;

    /// <summary>
    /// (Optional) The asset's file name to get the upload URL for.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* fileName;

} PFMultiplayerServerGetAssetUploadUrlResponse;

/// <summary>
/// PFMultiplayerServerGetBuildRequest data model. Returns the details about a multiplayer server build.
/// </summary>
typedef struct PFMultiplayerServerGetBuildRequest
{
    /// <summary>
    /// The guid string build ID of the build to get.
    /// </summary>
    _Null_terminated_ const char* buildId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFMultiplayerServerGetBuildRequest;

/// <summary>
/// PFMultiplayerServerGetBuildResponse data model.
/// </summary>
typedef struct PFMultiplayerServerGetBuildResponse
{
    /// <summary>
    /// (Optional) When true, assets will not be copied for each server inside the VM. All serverswill
    /// run from the same set of assets, or will have the same assets mounted in the container.
    /// </summary>
    _Maybenull_ bool const* areAssetsReadonly;

    /// <summary>
    /// (Optional) The guid string build ID of the build.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildId;

    /// <summary>
    /// (Optional) The build name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildName;

    /// <summary>
    /// (Optional) The current build status. Valid values are - Deploying, Deployed, DeletingRegion,
    /// Unhealthy.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildStatus;

    /// <summary>
    /// (Optional) The flavor of container of he build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerContainerFlavor const* containerFlavor;

    /// <summary>
    /// (Optional) The container command to run when the multiplayer server has been allocated, including
    /// any arguments. This only applies to custom builds. If the build is a managed build, this field
    /// will be null.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* containerRunCommand;

    /// <summary>
    /// (Optional) The time the build was created in UTC.
    /// </summary>
    _Maybenull_ time_t const* creationTime;

    /// <summary>
    /// (Optional) The custom game container image for a custom build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerContainerImageReference const* customGameContainerImage;

    /// <summary>
    /// (Optional) The game assets for the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameAssetReferencesCount) PFMultiplayerServerAssetReference const* const* gameAssetReferences;

    /// <summary>
    /// Count of gameAssetReferences
    /// </summary>
    uint32_t gameAssetReferencesCount;

    /// <summary>
    /// (Optional) The game certificates for the build.
    /// </summary>
    _Maybenull_ _Field_size_(gameCertificateReferencesCount) PFMultiplayerServerGameCertificateReference const* const* gameCertificateReferences;

    /// <summary>
    /// Count of gameCertificateReferences
    /// </summary>
    uint32_t gameCertificateReferencesCount;

    /// <summary>
    /// (Optional) The instrumentation configuration of the build.
    /// </summary>
    _Maybenull_ PFMultiplayerServerInstrumentationConfiguration const* instrumentationConfiguration;

    /// <summary>
    /// (Optional) Metadata of the build. The keys are case insensitive. The build metadata is made available
    /// to the server through Game Server SDK (GSDK).
    /// </summary>
    _Maybenull_ _Field_size_(metadataCount) struct PFStringDictionaryEntry const* metadata;

    /// <summary>
    /// Count of metadata
    /// </summary>
    uint32_t metadataCount;

    /// <summary>
    /// The number of multiplayer servers to hosted on a single VM of the build.
    /// </summary>
    int32_t multiplayerServerCountPerVm;

    /// <summary>
    /// (Optional) The OS platform used for running the game process.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* osPlatform;

    /// <summary>
    /// (Optional) The ports the build is mapped on.
    /// </summary>
    _Maybenull_ _Field_size_(portsCount) PFPort const* const* ports;

    /// <summary>
    /// Count of ports
    /// </summary>
    uint32_t portsCount;

    /// <summary>
    /// (Optional) The region configuration for the build.
    /// </summary>
    _Maybenull_ _Field_size_(regionConfigurationsCount) PFMultiplayerServerBuildRegion const* const* regionConfigurations;

    /// <summary>
    /// Count of regionConfigurations
    /// </summary>
    uint32_t regionConfigurationsCount;

    /// <summary>
    /// (Optional) The type of game server being hosted.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverType;

    /// <summary>
    /// (Optional) The command to run when the multiplayer server has been allocated, including any arguments.
    /// This only applies to managed builds. If the build is a custom build, this field will be null.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* startMultiplayerServerCommand;

    /// <summary>
    /// (Optional) When true, assets will be downloaded and uncompressed in memory, without the compressedversion
    /// being written first to disc.
    /// </summary>
    _Maybenull_ bool const* useStreamingForAssetDownloads;

    /// <summary>
    /// (Optional) The VM size the build was created on.
    /// </summary>
    _Maybenull_ PFMultiplayerServerAzureVmSize const* vmSize;

} PFMultiplayerServerGetBuildResponse;

/// <summary>
/// PFMultiplayerServerGetBuildAliasRequest data model. Returns the details about a multiplayer server
/// build alias.
/// </summary>
typedef struct PFMultiplayerServerGetBuildAliasRequest
{
    /// <summary>
    /// The guid string alias ID of the alias to perform the action on.
    /// </summary>
    _Null_terminated_ const char* aliasId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFMultiplayerServerGetBuildAliasRequest;

/// <summary>
/// PFMultiplayerServerGetContainerRegistryCredentialsRequest data model. Gets credentials to the container
/// registry where game developers can upload custom container images to before creating a new build.
/// </summary>
typedef struct PFMultiplayerServerGetContainerRegistryCredentialsRequest
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

} PFMultiplayerServerGetContainerRegistryCredentialsRequest;

/// <summary>
/// PFMultiplayerServerGetContainerRegistryCredentialsResponse data model.
/// </summary>
typedef struct PFMultiplayerServerGetContainerRegistryCredentialsResponse
{
    /// <summary>
    /// (Optional) The url of the container registry.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* dnsName;

    /// <summary>
    /// (Optional) The password for accessing the container registry.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* password;

    /// <summary>
    /// (Optional) The username for accessing the container registry.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* username;

} PFMultiplayerServerGetContainerRegistryCredentialsResponse;

/// <summary>
/// PFMultiplayerServerGetMultiplayerServerDetailsRequest data model. Gets multiplayer server session
/// details for a build in a specific region.
/// </summary>
typedef struct PFMultiplayerServerGetMultiplayerServerDetailsRequest
{
    /// <summary>
    /// The guid string build ID of the multiplayer server to get details for.
    /// </summary>
    _Null_terminated_ const char* buildId;

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
    /// The region the multiplayer server is located in to get details for.
    /// </summary>
    _Null_terminated_ const char* region;

    /// <summary>
    /// The title generated guid string session ID of the multiplayer server to get details for. This
    /// is to keep track of multiplayer server sessions.
    /// </summary>
    _Null_terminated_ const char* sessionId;

} PFMultiplayerServerGetMultiplayerServerDetailsRequest;

/// <summary>
/// PFMultiplayerServerConnectedPlayer data model.
/// </summary>
typedef struct PFMultiplayerServerConnectedPlayer
{
    /// <summary>
    /// (Optional) The player ID of the player connected to the multiplayer server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playerId;

} PFMultiplayerServerConnectedPlayer;

/// <summary>
/// PFMultiplayerServerGetMultiplayerServerDetailsResponse data model.
/// </summary>
typedef struct PFMultiplayerServerGetMultiplayerServerDetailsResponse
{
    /// <summary>
    /// (Optional) The identity of the build in which the server was allocated.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildId;

    /// <summary>
    /// (Optional) The connected players in the multiplayer server.
    /// </summary>
    _Maybenull_ _Field_size_(connectedPlayersCount) PFMultiplayerServerConnectedPlayer const* const* connectedPlayers;

    /// <summary>
    /// Count of connectedPlayers
    /// </summary>
    uint32_t connectedPlayersCount;

    /// <summary>
    /// (Optional) The fully qualified domain name of the virtual machine that is hosting this multiplayer
    /// server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* fQDN;

    /// <summary>
    /// (Optional) The IPv4 address of the virtual machine that is hosting this multiplayer server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* iPV4Address;

    /// <summary>
    /// (Optional) The time (UTC) at which a change in the multiplayer server state was observed.
    /// </summary>
    _Maybenull_ time_t const* lastStateTransitionTime;

    /// <summary>
    /// (Optional) The ports the multiplayer server uses.
    /// </summary>
    _Maybenull_ _Field_size_(portsCount) PFPort const* const* ports;

    /// <summary>
    /// Count of ports
    /// </summary>
    uint32_t portsCount;

    /// <summary>
    /// (Optional) The region the multiplayer server is located in.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* region;

    /// <summary>
    /// (Optional) The string server ID of the multiplayer server generated by PlayFab.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverId;

    /// <summary>
    /// (Optional) The guid string session ID of the multiplayer server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* sessionId;

    /// <summary>
    /// (Optional) The state of the multiplayer server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* state;

    /// <summary>
    /// (Optional) The virtual machine ID that the multiplayer server is located on.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* vmId;

} PFMultiplayerServerGetMultiplayerServerDetailsResponse;

/// <summary>
/// PFMultiplayerServerGetMultiplayerServerLogsRequest data model. Gets multiplayer server logs for a
/// specific server id in a region. The logs are available only after a server has terminated.
/// </summary>
typedef struct PFMultiplayerServerGetMultiplayerServerLogsRequest
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
    /// The server ID of multiplayer server to get logs for.
    /// </summary>
    _Null_terminated_ const char* serverId;

} PFMultiplayerServerGetMultiplayerServerLogsRequest;

/// <summary>
/// PFMultiplayerServerGetMultiplayerServerLogsResponse data model.
/// </summary>
typedef struct PFMultiplayerServerGetMultiplayerServerLogsResponse
{
    /// <summary>
    /// (Optional) URL for logs download.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* logDownloadUrl;

} PFMultiplayerServerGetMultiplayerServerLogsResponse;

/// <summary>
/// PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest data model. Gets multiplayer server
/// logs for a specific server id in a region. The logs are available only after a server has terminated.
/// </summary>
typedef struct PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest
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
    /// The server ID of multiplayer server to get logs for.
    /// </summary>
    _Null_terminated_ const char* sessionId;

} PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest;

/// <summary>
/// PFMultiplayerServerGetRemoteLoginEndpointRequest data model. Gets a remote login endpoint to a VM
/// that is hosting a multiplayer server build in a specific region.
/// </summary>
typedef struct PFMultiplayerServerGetRemoteLoginEndpointRequest
{
    /// <summary>
    /// The guid string build ID of the multiplayer server to get remote login information for.
    /// </summary>
    _Null_terminated_ const char* buildId;

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
    /// The region of the multiplayer server to get remote login information for.
    /// </summary>
    _Null_terminated_ const char* region;

    /// <summary>
    /// The virtual machine ID the multiplayer server is located on.
    /// </summary>
    _Null_terminated_ const char* vmId;

} PFMultiplayerServerGetRemoteLoginEndpointRequest;

/// <summary>
/// PFMultiplayerServerGetRemoteLoginEndpointResponse data model.
/// </summary>
typedef struct PFMultiplayerServerGetRemoteLoginEndpointResponse
{
    /// <summary>
    /// (Optional) The remote login IPV4 address of multiplayer server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* iPV4Address;

    /// <summary>
    /// The remote login port of multiplayer server.
    /// </summary>
    int32_t port;

} PFMultiplayerServerGetRemoteLoginEndpointResponse;

/// <summary>
/// PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest data model. Gets the status
/// of whether a title is enabled for the multiplayer server feature. The enabled status can be Initializing,
/// Enabled, and Disabled.
/// </summary>
typedef struct PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest
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

} PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest;

/// <summary>
/// PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse data model.
/// </summary>
typedef struct PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse
{
    /// <summary>
    /// (Optional) The enabled status for the multiplayer server features for the title.
    /// </summary>
    _Maybenull_ PFMultiplayerServerTitleMultiplayerServerEnabledStatus const* status;

} PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse;

/// <summary>
/// PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest data model. Gets a title's server
/// quota change request.
/// </summary>
typedef struct PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest
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
    /// Id of the change request to get.
    /// </summary>
    _Null_terminated_ const char* requestId;

} PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest;

/// <summary>
/// PFMultiplayerServerQuotaChange data model.
/// </summary>
typedef struct PFMultiplayerServerQuotaChange
{
    /// <summary>
    /// (Optional) A brief description of the requested changes.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* changeDescription;

    /// <summary>
    /// (Optional) Requested changes to make to the titles cores quota.
    /// </summary>
    _Maybenull_ _Field_size_(changesCount) PFMultiplayerServerCoreCapacityChange const* const* changes;

    /// <summary>
    /// Count of changes
    /// </summary>
    uint32_t changesCount;

    /// <summary>
    /// Whether or not this request is pending a review.
    /// </summary>
    bool isPendingReview;

    /// <summary>
    /// (Optional) Additional information about this request that our team can use to better understand
    /// the requirements.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* notes;

    /// <summary>
    /// (Optional) Id of the change request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* requestId;

    /// <summary>
    /// (Optional) Comments by our team when a request is reviewed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reviewComments;

    /// <summary>
    /// Whether or not this request was approved.
    /// </summary>
    bool wasApproved;

} PFMultiplayerServerQuotaChange;

/// <summary>
/// PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse data model.
/// </summary>
typedef struct PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse
{
    /// <summary>
    /// (Optional) The change request for this title.
    /// </summary>
    _Maybenull_ PFMultiplayerServerQuotaChange const* change;

} PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse;

/// <summary>
/// PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest data model. Gets the quotas for a title
/// in relation to multiplayer servers.
/// </summary>
typedef struct PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest
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

} PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest;

/// <summary>
/// PFMultiplayerServerCoreCapacity data model.
/// </summary>
typedef struct PFMultiplayerServerCoreCapacity
{
    /// <summary>
    /// The available core capacity for the (Region, VmFamily).
    /// </summary>
    int32_t available;

    /// <summary>
    /// (Optional) The AzureRegion.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* region;

    /// <summary>
    /// The total core capacity for the (Region, VmFamily).
    /// </summary>
    int32_t total;

    /// <summary>
    /// (Optional) The AzureVmFamily.
    /// </summary>
    _Maybenull_ PFMultiplayerServerAzureVmFamily const* vmFamily;

} PFMultiplayerServerCoreCapacity;

/// <summary>
/// PFMultiplayerServerTitleMultiplayerServersQuotas data model.
/// </summary>
typedef struct PFMultiplayerServerTitleMultiplayerServersQuotas
{
    /// <summary>
    /// (Optional) The core capacity for the various regions and VM Family.
    /// </summary>
    _Maybenull_ _Field_size_(coreCapacitiesCount) PFMultiplayerServerCoreCapacity const* const* coreCapacities;

    /// <summary>
    /// Count of coreCapacities
    /// </summary>
    uint32_t coreCapacitiesCount;

} PFMultiplayerServerTitleMultiplayerServersQuotas;

/// <summary>
/// PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse data model.
/// </summary>
typedef struct PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse
{
    /// <summary>
    /// (Optional) The various quotas for multiplayer servers for the title.
    /// </summary>
    _Maybenull_ PFMultiplayerServerTitleMultiplayerServersQuotas const* quotas;

} PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse;

/// <summary>
/// PFMultiplayerServerListMultiplayerServersRequest data model. Returns a list of multiplayer servers
/// for a build in a specific region.
/// </summary>
typedef struct PFMultiplayerServerListMultiplayerServersRequest
{
    /// <summary>
    /// The guid string build ID of the multiplayer servers to list.
    /// </summary>
    _Null_terminated_ const char* buildId;

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
    /// (Optional) The page size for the request.
    /// </summary>
    _Maybenull_ int32_t const* pageSize;

    /// <summary>
    /// The region the multiplayer servers to list.
    /// </summary>
    _Null_terminated_ const char* region;

    /// <summary>
    /// (Optional) The skip token for the paged request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListMultiplayerServersRequest;

/// <summary>
/// PFMultiplayerServerMultiplayerServerSummary data model.
/// </summary>
typedef struct PFMultiplayerServerMultiplayerServerSummary
{
    /// <summary>
    /// (Optional) The connected players in the multiplayer server.
    /// </summary>
    _Maybenull_ _Field_size_(connectedPlayersCount) PFMultiplayerServerConnectedPlayer const* const* connectedPlayers;

    /// <summary>
    /// Count of connectedPlayers
    /// </summary>
    uint32_t connectedPlayersCount;

    /// <summary>
    /// (Optional) The time (UTC) at which a change in the multiplayer server state was observed.
    /// </summary>
    _Maybenull_ time_t const* lastStateTransitionTime;

    /// <summary>
    /// (Optional) The region the multiplayer server is located in.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* region;

    /// <summary>
    /// (Optional) The string server ID of the multiplayer server generated by PlayFab.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverId;

    /// <summary>
    /// (Optional) The title generated guid string session ID of the multiplayer server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* sessionId;

    /// <summary>
    /// (Optional) The state of the multiplayer server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* state;

    /// <summary>
    /// (Optional) The virtual machine ID that the multiplayer server is located on.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* vmId;

} PFMultiplayerServerMultiplayerServerSummary;

/// <summary>
/// PFMultiplayerServerListMultiplayerServersResponse data model.
/// </summary>
typedef struct PFMultiplayerServerListMultiplayerServersResponse
{
    /// <summary>
    /// (Optional) The list of multiplayer server summary details.
    /// </summary>
    _Maybenull_ _Field_size_(multiplayerServerSummariesCount) PFMultiplayerServerMultiplayerServerSummary const* const* multiplayerServerSummaries;

    /// <summary>
    /// Count of multiplayerServerSummaries
    /// </summary>
    uint32_t multiplayerServerSummariesCount;

    /// <summary>
    /// The page size on the response.
    /// </summary>
    int32_t pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged response.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListMultiplayerServersResponse;

/// <summary>
/// PFMultiplayerServerListAssetSummariesRequest data model. Returns a list of multiplayer server game
/// asset summaries for a title.
/// </summary>
typedef struct PFMultiplayerServerListAssetSummariesRequest
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
    /// (Optional) The page size for the request.
    /// </summary>
    _Maybenull_ int32_t const* pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListAssetSummariesRequest;

/// <summary>
/// PFMultiplayerServerAssetSummary data model.
/// </summary>
typedef struct PFMultiplayerServerAssetSummary
{
    /// <summary>
    /// (Optional) The asset's file name. This is a filename with the .zip, .tar, or .tar.gz extension.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* fileName;

    /// <summary>
    /// (Optional) The metadata associated with the asset.
    /// </summary>
    _Maybenull_ _Field_size_(metadataCount) struct PFStringDictionaryEntry const* metadata;

    /// <summary>
    /// Count of metadata
    /// </summary>
    uint32_t metadataCount;

} PFMultiplayerServerAssetSummary;

/// <summary>
/// PFMultiplayerServerListAssetSummariesResponse data model.
/// </summary>
typedef struct PFMultiplayerServerListAssetSummariesResponse
{
    /// <summary>
    /// (Optional) The list of asset summaries.
    /// </summary>
    _Maybenull_ _Field_size_(assetSummariesCount) PFMultiplayerServerAssetSummary const* const* assetSummaries;

    /// <summary>
    /// Count of assetSummaries
    /// </summary>
    uint32_t assetSummariesCount;

    /// <summary>
    /// The page size on the response.
    /// </summary>
    int32_t pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged response.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListAssetSummariesResponse;

/// <summary>
/// PFMultiplayerServerListBuildAliasesRequest data model. Returns a list of summarized details of all
/// multiplayer server builds for a title.
/// </summary>
typedef struct PFMultiplayerServerListBuildAliasesRequest
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
    /// (Optional) The page size for the request.
    /// </summary>
    _Maybenull_ int32_t const* pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListBuildAliasesRequest;

/// <summary>
/// PFMultiplayerServerListBuildAliasesResponse data model.
/// </summary>
typedef struct PFMultiplayerServerListBuildAliasesResponse
{
    /// <summary>
    /// (Optional) The list of build aliases for the title.
    /// </summary>
    _Maybenull_ _Field_size_(buildAliasesCount) PFMultiplayerServerBuildAliasDetailsResponse const* const* buildAliases;

    /// <summary>
    /// Count of buildAliases
    /// </summary>
    uint32_t buildAliasesCount;

    /// <summary>
    /// The page size on the response.
    /// </summary>
    int32_t pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged response.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListBuildAliasesResponse;

/// <summary>
/// PFMultiplayerServerListBuildSummariesRequest data model. Returns a list of summarized details of
/// all multiplayer server builds for a title.
/// </summary>
typedef struct PFMultiplayerServerListBuildSummariesRequest
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
    /// (Optional) The page size for the request.
    /// </summary>
    _Maybenull_ int32_t const* pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListBuildSummariesRequest;

/// <summary>
/// PFMultiplayerServerBuildSummary data model.
/// </summary>
typedef struct PFMultiplayerServerBuildSummary
{
    /// <summary>
    /// (Optional) The guid string build ID of the build.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildId;

    /// <summary>
    /// (Optional) The build name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildName;

    /// <summary>
    /// (Optional) The time the build was created in UTC.
    /// </summary>
    _Maybenull_ time_t const* creationTime;

    /// <summary>
    /// (Optional) The metadata of the build.
    /// </summary>
    _Maybenull_ _Field_size_(metadataCount) struct PFStringDictionaryEntry const* metadata;

    /// <summary>
    /// Count of metadata
    /// </summary>
    uint32_t metadataCount;

    /// <summary>
    /// (Optional) The configuration and status for each region in the build.
    /// </summary>
    _Maybenull_ _Field_size_(regionConfigurationsCount) PFMultiplayerServerBuildRegion const* const* regionConfigurations;

    /// <summary>
    /// Count of regionConfigurations
    /// </summary>
    uint32_t regionConfigurationsCount;

} PFMultiplayerServerBuildSummary;

/// <summary>
/// PFMultiplayerServerListBuildSummariesResponse data model.
/// </summary>
typedef struct PFMultiplayerServerListBuildSummariesResponse
{
    /// <summary>
    /// (Optional) The list of build summaries for a title.
    /// </summary>
    _Maybenull_ _Field_size_(buildSummariesCount) PFMultiplayerServerBuildSummary const* const* buildSummaries;

    /// <summary>
    /// Count of buildSummaries
    /// </summary>
    uint32_t buildSummariesCount;

    /// <summary>
    /// The page size on the response.
    /// </summary>
    int32_t pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged response.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListBuildSummariesResponse;

/// <summary>
/// PFMultiplayerServerListCertificateSummariesRequest data model. Returns a list of multiplayer server
/// game certificates for a title.
/// </summary>
typedef struct PFMultiplayerServerListCertificateSummariesRequest
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
    /// (Optional) The page size for the request.
    /// </summary>
    _Maybenull_ int32_t const* pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListCertificateSummariesRequest;

/// <summary>
/// PFMultiplayerServerCertificateSummary data model.
/// </summary>
typedef struct PFMultiplayerServerCertificateSummary
{
    /// <summary>
    /// (Optional) The name of the certificate.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) The thumbprint for the certificate.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* thumbprint;

} PFMultiplayerServerCertificateSummary;

/// <summary>
/// PFMultiplayerServerListCertificateSummariesResponse data model.
/// </summary>
typedef struct PFMultiplayerServerListCertificateSummariesResponse
{
    /// <summary>
    /// (Optional) The list of game certificates.
    /// </summary>
    _Maybenull_ _Field_size_(certificateSummariesCount) PFMultiplayerServerCertificateSummary const* const* certificateSummaries;

    /// <summary>
    /// Count of certificateSummaries
    /// </summary>
    uint32_t certificateSummariesCount;

    /// <summary>
    /// The page size on the response.
    /// </summary>
    int32_t pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged response.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListCertificateSummariesResponse;

/// <summary>
/// PFMultiplayerServerListContainerImagesRequest data model. Returns a list of the container images
/// that have been uploaded to the container registry for a title.
/// </summary>
typedef struct PFMultiplayerServerListContainerImagesRequest
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
    /// (Optional) The page size for the request.
    /// </summary>
    _Maybenull_ int32_t const* pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListContainerImagesRequest;

/// <summary>
/// PFMultiplayerServerListContainerImagesResponse data model.
/// </summary>
typedef struct PFMultiplayerServerListContainerImagesResponse
{
    /// <summary>
    /// (Optional) The list of container images.
    /// </summary>
    _Maybenull_ _Field_size_(imagesCount) const char* const* images;

    /// <summary>
    /// Count of images
    /// </summary>
    uint32_t imagesCount;

    /// <summary>
    /// The page size on the response.
    /// </summary>
    int32_t pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged response.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListContainerImagesResponse;

/// <summary>
/// PFMultiplayerServerListContainerImageTagsRequest data model. Returns a list of the tags for a particular
/// container image that exists in the container registry for a title.
/// </summary>
typedef struct PFMultiplayerServerListContainerImageTagsRequest
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
    /// (Optional) The container images we want to list tags for.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* imageName;

} PFMultiplayerServerListContainerImageTagsRequest;

/// <summary>
/// PFMultiplayerServerListContainerImageTagsResponse data model.
/// </summary>
typedef struct PFMultiplayerServerListContainerImageTagsResponse
{
    /// <summary>
    /// (Optional) The list of tags for a particular container image.
    /// </summary>
    _Maybenull_ _Field_size_(tagsCount) const char* const* tags;

    /// <summary>
    /// Count of tags
    /// </summary>
    uint32_t tagsCount;

} PFMultiplayerServerListContainerImageTagsResponse;

/// <summary>
/// PFMultiplayerServerListPartyQosServersRequest data model. Returns a list of quality of service servers
/// for party.
/// </summary>
typedef struct PFMultiplayerServerListPartyQosServersRequest
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

} PFMultiplayerServerListPartyQosServersRequest;

/// <summary>
/// PFMultiplayerServerQosServer data model.
/// </summary>
typedef struct PFMultiplayerServerQosServer
{
    /// <summary>
    /// (Optional) The region the QoS server is located in.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* region;

    /// <summary>
    /// (Optional) The QoS server URL.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverUrl;

} PFMultiplayerServerQosServer;

/// <summary>
/// PFMultiplayerServerListPartyQosServersResponse data model.
/// </summary>
typedef struct PFMultiplayerServerListPartyQosServersResponse
{
    /// <summary>
    /// The page size on the response.
    /// </summary>
    int32_t pageSize;

    /// <summary>
    /// (Optional) The list of QoS servers.
    /// </summary>
    _Maybenull_ _Field_size_(qosServersCount) PFMultiplayerServerQosServer const* const* qosServers;

    /// <summary>
    /// Count of qosServers
    /// </summary>
    uint32_t qosServersCount;

    /// <summary>
    /// (Optional) The skip token for the paged response.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListPartyQosServersResponse;

/// <summary>
/// PFMultiplayerServerListQosServersForTitleRequest data model. Returns a list of quality of service
/// servers for a title.
/// </summary>
typedef struct PFMultiplayerServerListQosServersForTitleRequest
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
    /// (Optional) Indicates that the response should contain Qos servers for all regions, including
    /// those where there are no builds deployed for the title.
    /// </summary>
    _Maybenull_ bool const* includeAllRegions;

} PFMultiplayerServerListQosServersForTitleRequest;

/// <summary>
/// PFMultiplayerServerListQosServersForTitleResponse data model.
/// </summary>
typedef struct PFMultiplayerServerListQosServersForTitleResponse
{
    /// <summary>
    /// The page size on the response.
    /// </summary>
    int32_t pageSize;

    /// <summary>
    /// (Optional) The list of QoS servers.
    /// </summary>
    _Maybenull_ _Field_size_(qosServersCount) PFMultiplayerServerQosServer const* const* qosServers;

    /// <summary>
    /// Count of qosServers
    /// </summary>
    uint32_t qosServersCount;

    /// <summary>
    /// (Optional) The skip token for the paged response.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListQosServersForTitleResponse;

/// <summary>
/// PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest data model. List all server quota
/// change requests for a title.
/// </summary>
typedef struct PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest
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

} PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest;

/// <summary>
/// PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse data model.
/// </summary>
typedef struct PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse
{
    /// <summary>
    /// (Optional) All change requests for this title.
    /// </summary>
    _Maybenull_ _Field_size_(changesCount) PFMultiplayerServerQuotaChange const* const* changes;

    /// <summary>
    /// Count of changes
    /// </summary>
    uint32_t changesCount;

} PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse;

/// <summary>
/// PFMultiplayerServerListVirtualMachineSummariesRequest data model. Returns a list of virtual machines
/// for a title.
/// </summary>
typedef struct PFMultiplayerServerListVirtualMachineSummariesRequest
{
    /// <summary>
    /// The guid string build ID of the virtual machines to list.
    /// </summary>
    _Null_terminated_ const char* buildId;

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
    /// (Optional) The page size for the request.
    /// </summary>
    _Maybenull_ int32_t const* pageSize;

    /// <summary>
    /// The region of the virtual machines to list.
    /// </summary>
    _Null_terminated_ const char* region;

    /// <summary>
    /// (Optional) The skip token for the paged request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

} PFMultiplayerServerListVirtualMachineSummariesRequest;

/// <summary>
/// PFMultiplayerServerVirtualMachineSummary data model.
/// </summary>
typedef struct PFMultiplayerServerVirtualMachineSummary
{
    /// <summary>
    /// (Optional) The virtual machine health status.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* healthStatus;

    /// <summary>
    /// (Optional) The virtual machine state.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* state;

    /// <summary>
    /// (Optional) The virtual machine ID.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* vmId;

} PFMultiplayerServerVirtualMachineSummary;

/// <summary>
/// PFMultiplayerServerListVirtualMachineSummariesResponse data model.
/// </summary>
typedef struct PFMultiplayerServerListVirtualMachineSummariesResponse
{
    /// <summary>
    /// The page size on the response.
    /// </summary>
    int32_t pageSize;

    /// <summary>
    /// (Optional) The skip token for the paged response.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* skipToken;

    /// <summary>
    /// (Optional) The list of virtual machine summaries.
    /// </summary>
    _Maybenull_ _Field_size_(virtualMachinesCount) PFMultiplayerServerVirtualMachineSummary const* const* virtualMachines;

    /// <summary>
    /// Count of virtualMachines
    /// </summary>
    uint32_t virtualMachinesCount;

} PFMultiplayerServerListVirtualMachineSummariesResponse;

/// <summary>
/// PFMultiplayerServerBuildAliasParams data model.
/// </summary>
typedef struct PFMultiplayerServerBuildAliasParams
{
    /// <summary>
    /// The guid string alias ID to use for the request.
    /// </summary>
    _Null_terminated_ const char* aliasId;

} PFMultiplayerServerBuildAliasParams;

/// <summary>
/// PFMultiplayerServerRequestMultiplayerServerRequest data model. Requests a multiplayer server session
/// from a particular build in any of the given preferred regions.
/// </summary>
typedef struct PFMultiplayerServerRequestMultiplayerServerRequest
{
    /// <summary>
    /// (Optional) The identifiers of the build alias to use for the request.
    /// </summary>
    _Maybenull_ PFMultiplayerServerBuildAliasParams const* buildAliasParams;

    /// <summary>
    /// (Optional) The guid string build ID of the multiplayer server to request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildId;

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
    /// (Optional) Initial list of players (potentially matchmade) allowed to connect to the game. This
    /// list is passed to the game server when requested (via GSDK) and can be used to validate players
    /// connecting to it.
    /// </summary>
    _Maybenull_ _Field_size_(initialPlayersCount) const char* const* initialPlayers;

    /// <summary>
    /// Count of initialPlayers
    /// </summary>
    uint32_t initialPlayersCount;

    /// <summary>
    /// The preferred regions to request a multiplayer server from. The Multiplayer Service will iterate
    /// through the regions in the specified order and allocate a server from the first one that has servers
    /// available.
    /// </summary>
    _Field_size_(preferredRegionsCount) const char* const* preferredRegions;

    /// <summary>
    /// Count of preferredRegions
    /// </summary>
    uint32_t preferredRegionsCount;

    /// <summary>
    /// (Optional) Data encoded as a string that is passed to the game server when requested. This can
    /// be used to to communicate information such as game mode or map through the request flow.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* sessionCookie;

    /// <summary>
    /// A guid string session ID created track the multiplayer server session over its life.
    /// </summary>
    _Null_terminated_ const char* sessionId;

} PFMultiplayerServerRequestMultiplayerServerRequest;

/// <summary>
/// PFMultiplayerServerRequestMultiplayerServerResponse data model.
/// </summary>
typedef struct PFMultiplayerServerRequestMultiplayerServerResponse
{
    /// <summary>
    /// (Optional) The identity of the build in which the server was allocated.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildId;

    /// <summary>
    /// (Optional) The connected players in the multiplayer server.
    /// </summary>
    _Maybenull_ _Field_size_(connectedPlayersCount) PFMultiplayerServerConnectedPlayer const* const* connectedPlayers;

    /// <summary>
    /// Count of connectedPlayers
    /// </summary>
    uint32_t connectedPlayersCount;

    /// <summary>
    /// (Optional) The fully qualified domain name of the virtual machine that is hosting this multiplayer
    /// server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* fQDN;

    /// <summary>
    /// (Optional) The IPv4 address of the virtual machine that is hosting this multiplayer server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* iPV4Address;

    /// <summary>
    /// (Optional) The time (UTC) at which a change in the multiplayer server state was observed.
    /// </summary>
    _Maybenull_ time_t const* lastStateTransitionTime;

    /// <summary>
    /// (Optional) The ports the multiplayer server uses.
    /// </summary>
    _Maybenull_ _Field_size_(portsCount) PFPort const* const* ports;

    /// <summary>
    /// Count of ports
    /// </summary>
    uint32_t portsCount;

    /// <summary>
    /// (Optional) The region the multiplayer server is located in.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* region;

    /// <summary>
    /// (Optional) The string server ID of the multiplayer server generated by PlayFab.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverId;

    /// <summary>
    /// (Optional) The guid string session ID of the multiplayer server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* sessionId;

    /// <summary>
    /// (Optional) The state of the multiplayer server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* state;

    /// <summary>
    /// (Optional) The virtual machine ID that the multiplayer server is located on.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* vmId;

} PFMultiplayerServerRequestMultiplayerServerResponse;

/// <summary>
/// PFMultiplayerServerRolloverContainerRegistryCredentialsRequest data model. Gets new credentials to
/// the container registry where game developers can upload custom container images to before creating
/// a new build.
/// </summary>
typedef struct PFMultiplayerServerRolloverContainerRegistryCredentialsRequest
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

} PFMultiplayerServerRolloverContainerRegistryCredentialsRequest;

/// <summary>
/// PFMultiplayerServerRolloverContainerRegistryCredentialsResponse data model.
/// </summary>
typedef struct PFMultiplayerServerRolloverContainerRegistryCredentialsResponse
{
    /// <summary>
    /// (Optional) The url of the container registry.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* dnsName;

    /// <summary>
    /// (Optional) The password for accessing the container registry.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* password;

    /// <summary>
    /// (Optional) The username for accessing the container registry.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* username;

} PFMultiplayerServerRolloverContainerRegistryCredentialsResponse;

/// <summary>
/// PFMultiplayerServerShutdownMultiplayerServerRequest data model. Executes the shutdown callback from
/// the GSDK and terminates the multiplayer server session. The callback in the GSDK will allow for graceful
/// shutdown with a 15 minute timeoutIf graceful shutdown has not been completed before 15 minutes have
/// elapsed, the multiplayer server session will be forcefully terminated on it's own.
/// </summary>
typedef struct PFMultiplayerServerShutdownMultiplayerServerRequest
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
    /// A guid string session ID of the multiplayer server to shut down.
    /// </summary>
    _Null_terminated_ const char* sessionId;

} PFMultiplayerServerShutdownMultiplayerServerRequest;

/// <summary>
/// PFMultiplayerServerUntagContainerImageRequest data model. Removes the specified tag from the image.
/// After this operation, a 'docker pull' will fail for the specified image and tag combination. Morever,
/// ListContainerImageTags will not return the specified tag.
/// </summary>
typedef struct PFMultiplayerServerUntagContainerImageRequest
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
    /// (Optional) The container image which tag we want to remove.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* imageName;

    /// <summary>
    /// (Optional) The tag we want to remove.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* tag;

} PFMultiplayerServerUntagContainerImageRequest;

/// <summary>
/// PFMultiplayerServerUpdateBuildAliasRequest data model. Creates a multiplayer server build alias and
/// returns the created alias.
/// </summary>
typedef struct PFMultiplayerServerUpdateBuildAliasRequest
{
    /// <summary>
    /// The guid string alias Id of the alias to be updated.
    /// </summary>
    _Null_terminated_ const char* aliasId;

    /// <summary>
    /// (Optional) The alias name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* aliasName;

    /// <summary>
    /// (Optional) Array of build selection criteria.
    /// </summary>
    _Maybenull_ _Field_size_(buildSelectionCriteriaCount) PFMultiplayerServerBuildSelectionCriterion const* const* buildSelectionCriteria;

    /// <summary>
    /// Count of buildSelectionCriteria
    /// </summary>
    uint32_t buildSelectionCriteriaCount;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFMultiplayerServerUpdateBuildAliasRequest;

/// <summary>
/// PFMultiplayerServerUpdateBuildNameRequest data model. Updates a multiplayer server build's name.
/// </summary>
typedef struct PFMultiplayerServerUpdateBuildNameRequest
{
    /// <summary>
    /// The guid string ID of the build we want to update the name of.
    /// </summary>
    _Null_terminated_ const char* buildId;

    /// <summary>
    /// The build name.
    /// </summary>
    _Null_terminated_ const char* buildName;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFMultiplayerServerUpdateBuildNameRequest;

/// <summary>
/// PFMultiplayerServerUpdateBuildRegionRequest data model. Updates a multiplayer server build's region.
/// </summary>
typedef struct PFMultiplayerServerUpdateBuildRegionRequest
{
    /// <summary>
    /// The guid string ID of the build we want to update regions for.
    /// </summary>
    _Null_terminated_ const char* buildId;

    /// <summary>
    /// The updated region configuration that should be applied to the specified build.
    /// </summary>
    PFMultiplayerServerBuildRegionParams const* buildRegion;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFMultiplayerServerUpdateBuildRegionRequest;

/// <summary>
/// PFMultiplayerServerUpdateBuildRegionsRequest data model. Updates a multiplayer server build's regions.
/// </summary>
typedef struct PFMultiplayerServerUpdateBuildRegionsRequest
{
    /// <summary>
    /// The guid string ID of the build we want to update regions for.
    /// </summary>
    _Null_terminated_ const char* buildId;

    /// <summary>
    /// The updated region configuration that should be applied to the specified build.
    /// </summary>
    _Field_size_(buildRegionsCount) PFMultiplayerServerBuildRegionParams const* const* buildRegions;

    /// <summary>
    /// Count of buildRegions
    /// </summary>
    uint32_t buildRegionsCount;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFMultiplayerServerUpdateBuildRegionsRequest;

/// <summary>
/// PFMultiplayerServerCertificate data model.
/// </summary>
typedef struct PFMultiplayerServerCertificate
{
    /// <summary>
    /// Base64 encoded string contents of the certificate.
    /// </summary>
    _Null_terminated_ const char* base64EncodedValue;

    /// <summary>
    /// A name for the certificate. This is used to reference certificates in build configurations.
    /// </summary>
    _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) If required for your PFX certificate, use this field to provide a password that will
    /// be used to install the certificate on the container.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* password;

} PFMultiplayerServerCertificate;

/// <summary>
/// PFMultiplayerServerUploadCertificateRequest data model. Uploads a multiplayer server game certificate.
/// </summary>
typedef struct PFMultiplayerServerUploadCertificateRequest
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
    /// The game certificate to upload.
    /// </summary>
    PFMultiplayerServerCertificate const* gameCertificate;

} PFMultiplayerServerUploadCertificateRequest;

#pragma pop_macro("IN")

}
