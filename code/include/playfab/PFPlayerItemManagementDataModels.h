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
/// GenericErrorCodes enum.
/// </summary>
enum class PFPlayerItemManagementGenericErrorCodes : uint32_t
{
    Success,
    UnkownError,
    InvalidParams,
    AccountNotFound,
    AccountBanned,
    InvalidUsernameOrPassword,
    InvalidTitleId,
    InvalidEmailAddress,
    EmailAddressNotAvailable,
    InvalidUsername,
    InvalidPassword,
    UsernameNotAvailable,
    InvalidSteamTicket,
    AccountAlreadyLinked,
    LinkedAccountAlreadyClaimed,
    InvalidFacebookToken,
    AccountNotLinked,
    FailedByPaymentProvider,
    CouponCodeNotFound,
    InvalidContainerItem,
    ContainerNotOwned,
    KeyNotOwned,
    InvalidItemIdInTable,
    InvalidReceipt,
    ReceiptAlreadyUsed,
    ReceiptCancelled,
    GameNotFound,
    GameModeNotFound,
    InvalidGoogleToken,
    UserIsNotPartOfDeveloper,
    InvalidTitleForDeveloper,
    TitleNameConflicts,
    UserisNotValid,
    ValueAlreadyExists,
    BuildNotFound,
    PlayerNotInGame,
    InvalidTicket,
    InvalidDeveloper,
    InvalidOrderInfo,
    RegistrationIncomplete,
    InvalidPlatform,
    UnknownError,
    SteamApplicationNotOwned,
    WrongSteamAccount,
    TitleNotActivated,
    RegistrationSessionNotFound,
    NoSuchMod,
    FileNotFound,
    DuplicateEmail,
    ItemNotFound,
    ItemNotOwned,
    ItemNotRecycleable,
    ItemNotAffordable,
    InvalidVirtualCurrency,
    WrongVirtualCurrency,
    WrongPrice,
    NonPositiveValue,
    InvalidRegion,
    RegionAtCapacity,
    ServerFailedToStart,
    NameNotAvailable,
    InsufficientFunds,
    InvalidDeviceID,
    InvalidPushNotificationToken,
    NoRemainingUses,
    InvalidPaymentProvider,
    PurchaseInitializationFailure,
    DuplicateUsername,
    InvalidBuyerInfo,
    NoGameModeParamsSet,
    BodyTooLarge,
    ReservedWordInBody,
    InvalidTypeInBody,
    InvalidRequest,
    ReservedEventName,
    InvalidUserStatistics,
    NotAuthenticated,
    StreamAlreadyExists,
    ErrorCreatingStream,
    StreamNotFound,
    InvalidAccount,
    PurchaseDoesNotExist,
    InvalidPurchaseTransactionStatus,
    APINotEnabledForGameClientAccess,
    NoPushNotificationARNForTitle,
    BuildAlreadyExists,
    BuildPackageDoesNotExist,
    CustomAnalyticsEventsNotEnabledForTitle,
    InvalidSharedGroupId,
    NotAuthorized,
    MissingTitleGoogleProperties,
    InvalidItemProperties,
    InvalidPSNAuthCode,
    InvalidItemId,
    PushNotEnabledForAccount,
    PushServiceError,
    ReceiptDoesNotContainInAppItems,
    ReceiptContainsMultipleInAppItems,
    InvalidBundleID,
    JavascriptException,
    InvalidSessionTicket,
    UnableToConnectToDatabase,
    InternalServerError,
    InvalidReportDate,
    ReportNotAvailable,
    DatabaseThroughputExceeded,
    InvalidGameTicket,
    ExpiredGameTicket,
    GameTicketDoesNotMatchLobby,
    LinkedDeviceAlreadyClaimed,
    DeviceAlreadyLinked,
    DeviceNotLinked,
    PartialFailure,
    PublisherNotSet,
    ServiceUnavailable,
    VersionNotFound,
    RevisionNotFound,
    InvalidPublisherId,
    DownstreamServiceUnavailable,
    APINotIncludedInTitleUsageTier,
    DAULimitExceeded,
    APIRequestLimitExceeded,
    InvalidAPIEndpoint,
    BuildNotAvailable,
    ConcurrentEditError,
    ContentNotFound,
    CharacterNotFound,
    CloudScriptNotFound,
    ContentQuotaExceeded,
    InvalidCharacterStatistics,
    PhotonNotEnabledForTitle,
    PhotonApplicationNotFound,
    PhotonApplicationNotAssociatedWithTitle,
    InvalidEmailOrPassword,
    FacebookAPIError,
    InvalidContentType,
    KeyLengthExceeded,
    DataLengthExceeded,
    TooManyKeys,
    FreeTierCannotHaveVirtualCurrency,
    MissingAmazonSharedKey,
    AmazonValidationError,
    InvalidPSNIssuerId,
    PSNInaccessible,
    ExpiredAuthToken,
    FailedToGetEntitlements,
    FailedToConsumeEntitlement,
    TradeAcceptingUserNotAllowed,
    TradeInventoryItemIsAssignedToCharacter,
    TradeInventoryItemIsBundle,
    TradeStatusNotValidForCancelling,
    TradeStatusNotValidForAccepting,
    TradeDoesNotExist,
    TradeCancelled,
    TradeAlreadyFilled,
    TradeWaitForStatusTimeout,
    TradeInventoryItemExpired,
    TradeMissingOfferedAndAcceptedItems,
    TradeAcceptedItemIsBundle,
    TradeAcceptedItemIsStackable,
    TradeInventoryItemInvalidStatus,
    TradeAcceptedCatalogItemInvalid,
    TradeAllowedUsersInvalid,
    TradeInventoryItemDoesNotExist,
    TradeInventoryItemIsConsumed,
    TradeInventoryItemIsStackable,
    TradeAcceptedItemsMismatch,
    InvalidKongregateToken,
    FeatureNotConfiguredForTitle,
    NoMatchingCatalogItemForReceipt,
    InvalidCurrencyCode,
    NoRealMoneyPriceForCatalogItem,
    TradeInventoryItemIsNotTradable,
    TradeAcceptedCatalogItemIsNotTradable,
    UsersAlreadyFriends,
    LinkedIdentifierAlreadyClaimed,
    CustomIdNotLinked,
    TotalDataSizeExceeded,
    DeleteKeyConflict,
    InvalidXboxLiveToken,
    ExpiredXboxLiveToken,
    ResettableStatisticVersionRequired,
    NotAuthorizedByTitle,
    NoPartnerEnabled,
    InvalidPartnerResponse,
    APINotEnabledForGameServerAccess,
    StatisticNotFound,
    StatisticNameConflict,
    StatisticVersionClosedForWrites,
    StatisticVersionInvalid,
    APIClientRequestRateLimitExceeded,
    InvalidJSONContent,
    InvalidDropTable,
    StatisticVersionAlreadyIncrementedForScheduledInterval,
    StatisticCountLimitExceeded,
    StatisticVersionIncrementRateExceeded,
    ContainerKeyInvalid,
    CloudScriptExecutionTimeLimitExceeded,
    NoWritePermissionsForEvent,
    CloudScriptFunctionArgumentSizeExceeded,
    CloudScriptAPIRequestCountExceeded,
    CloudScriptAPIRequestError,
    CloudScriptHTTPRequestError,
    InsufficientGuildRole,
    GuildNotFound,
    OverLimit,
    EventNotFound,
    InvalidEventField,
    InvalidEventName,
    CatalogNotConfigured,
    OperationNotSupportedForPlatform,
    SegmentNotFound,
    StoreNotFound,
    InvalidStatisticName,
    TitleNotQualifiedForLimit,
    InvalidServiceLimitLevel,
    ServiceLimitLevelInTransition,
    CouponAlreadyRedeemed,
    GameServerBuildSizeLimitExceeded,
    GameServerBuildCountLimitExceeded,
    VirtualCurrencyCountLimitExceeded,
    VirtualCurrencyCodeExists,
    TitleNewsItemCountLimitExceeded,
    InvalidTwitchToken,
    TwitchResponseError,
    ProfaneDisplayName,
    UserAlreadyAdded,
    InvalidVirtualCurrencyCode,
    VirtualCurrencyCannotBeDeleted,
    IdentifierAlreadyClaimed,
    IdentifierNotLinked,
    InvalidContinuationToken,
    ExpiredContinuationToken,
    InvalidSegment,
    InvalidSessionId,
    SessionLogNotFound,
    InvalidSearchTerm,
    TwoFactorAuthenticationTokenRequired,
    GameServerHostCountLimitExceeded,
    PlayerTagCountLimitExceeded,
    RequestAlreadyRunning,
    ActionGroupNotFound,
    MaximumSegmentBulkActionJobsRunning,
    NoActionsOnPlayersInSegmentJob,
    DuplicateStatisticName,
    ScheduledTaskNameConflict,
    ScheduledTaskCreateConflict,
    InvalidScheduledTaskName,
    InvalidTaskSchedule,
    SteamNotEnabledForTitle,
    LimitNotAnUpgradeOption,
    NoSecretKeyEnabledForCloudScript,
    TaskNotFound,
    TaskInstanceNotFound,
    InvalidIdentityProviderId,
    MisconfiguredIdentityProvider,
    InvalidScheduledTaskType,
    BillingInformationRequired,
    LimitedEditionItemUnavailable,
    InvalidAdPlacementAndReward,
    AllAdPlacementViewsAlreadyConsumed,
    GoogleOAuthNotConfiguredForTitle,
    GoogleOAuthError,
    UserNotFriend,
    InvalidSignature,
    InvalidPublicKey,
    GoogleOAuthNoIdTokenIncludedInResponse,
    StatisticUpdateInProgress,
    LeaderboardVersionNotAvailable,
    StatisticAlreadyHasPrizeTable,
    PrizeTableHasOverlappingRanks,
    PrizeTableHasMissingRanks,
    PrizeTableRankStartsAtZero,
    InvalidStatistic,
    ExpressionParseFailure,
    ExpressionInvokeFailure,
    ExpressionTooLong,
    DataUpdateRateExceeded,
    RestrictedEmailDomain,
    EncryptionKeyDisabled,
    EncryptionKeyMissing,
    EncryptionKeyBroken,
    NoSharedSecretKeyConfigured,
    SecretKeyNotFound,
    PlayerSecretAlreadyConfigured,
    APIRequestsDisabledForTitle,
    InvalidSharedSecretKey,
    PrizeTableHasNoRanks,
    ProfileDoesNotExist,
    ContentS3OriginBucketNotConfigured,
    InvalidEnvironmentForReceipt,
    EncryptedRequestNotAllowed,
    SignedRequestNotAllowed,
    RequestViewConstraintParamsNotAllowed,
    BadPartnerConfiguration,
    XboxBPCertificateFailure,
    XboxXASSExchangeFailure,
    InvalidEntityId,
    StatisticValueAggregationOverflow,
    EmailMessageFromAddressIsMissing,
    EmailMessageToAddressIsMissing,
    SmtpServerAuthenticationError,
    SmtpServerLimitExceeded,
    SmtpServerInsufficientStorage,
    SmtpServerCommunicationError,
    SmtpServerGeneralFailure,
    EmailClientTimeout,
    EmailClientCanceledTask,
    EmailTemplateMissing,
    InvalidHostForTitleId,
    EmailConfirmationTokenDoesNotExist,
    EmailConfirmationTokenExpired,
    AccountDeleted,
    PlayerSecretNotConfigured,
    InvalidSignatureTime,
    NoContactEmailAddressFound,
    InvalidAuthToken,
    AuthTokenDoesNotExist,
    AuthTokenExpired,
    AuthTokenAlreadyUsedToResetPassword,
    MembershipNameTooLong,
    MembershipNotFound,
    GoogleServiceAccountInvalid,
    GoogleServiceAccountParseFailure,
    EntityTokenMissing,
    EntityTokenInvalid,
    EntityTokenExpired,
    EntityTokenRevoked,
    InvalidProductForSubscription,
    XboxInaccessible,
    SubscriptionAlreadyTaken,
    SmtpAddonNotEnabled,
    APIConcurrentRequestLimitExceeded,
    XboxRejectedXSTSExchangeRequest,
    VariableNotDefined,
    TemplateVersionNotDefined,
    FileTooLarge,
    TitleDeleted,
    TitleContainsUserAccounts,
    TitleDeletionPlayerCleanupFailure,
    EntityFileOperationPending,
    NoEntityFileOperationPending,
    EntityProfileVersionMismatch,
    TemplateVersionTooOld,
    MembershipDefinitionInUse,
    PaymentPageNotConfigured,
    FailedLoginAttemptRateLimitExceeded,
    EntityBlockedByGroup,
    RoleDoesNotExist,
    EntityIsAlreadyMember,
    DuplicateRoleId,
    GroupInvitationNotFound,
    GroupApplicationNotFound,
    OutstandingInvitationAcceptedInstead,
    OutstandingApplicationAcceptedInstead,
    RoleIsGroupDefaultMember,
    RoleIsGroupAdmin,
    RoleNameNotAvailable,
    GroupNameNotAvailable,
    EmailReportAlreadySent,
    EmailReportRecipientBlacklisted,
    EventNamespaceNotAllowed,
    EventEntityNotAllowed,
    InvalidEntityType,
    NullTokenResultFromAad,
    InvalidTokenResultFromAad,
    NoValidCertificateForAad,
    InvalidCertificateForAad,
    DuplicateDropTableId,
    MultiplayerServerError,
    MultiplayerServerTooManyRequests,
    MultiplayerServerNoContent,
    MultiplayerServerBadRequest,
    MultiplayerServerUnauthorized,
    MultiplayerServerForbidden,
    MultiplayerServerNotFound,
    MultiplayerServerConflict,
    MultiplayerServerInternalServerError,
    MultiplayerServerUnavailable,
    ExplicitContentDetected,
    PIIContentDetected,
    InvalidScheduledTaskParameter,
    PerEntityEventRateLimitExceeded,
    TitleDefaultLanguageNotSet,
    EmailTemplateMissingDefaultVersion,
    FacebookInstantGamesIdNotLinked,
    InvalidFacebookInstantGamesSignature,
    FacebookInstantGamesAuthNotConfiguredForTitle,
    EntityProfileConstraintValidationFailed,
    TelemetryIngestionKeyPending,
    TelemetryIngestionKeyNotFound,
    StatisticChildNameInvalid,
    DataIntegrityError,
    VirtualCurrencyCannotBeSetToOlderVersion,
    VirtualCurrencyMustBeWithinIntegerRange,
    EmailTemplateInvalidSyntax,
    EmailTemplateMissingCallback,
    PushNotificationTemplateInvalidPayload,
    InvalidLocalizedPushNotificationLanguage,
    MissingLocalizedPushNotificationMessage,
    PushNotificationTemplateMissingPlatformPayload,
    PushNotificationTemplatePayloadContainsInvalidJson,
    PushNotificationTemplateContainsInvalidIosPayload,
    PushNotificationTemplateContainsInvalidAndroidPayload,
    PushNotificationTemplateIosPayloadMissingNotificationBody,
    PushNotificationTemplateAndroidPayloadMissingNotificationBody,
    PushNotificationTemplateNotFound,
    PushNotificationTemplateMissingDefaultVersion,
    PushNotificationTemplateInvalidSyntax,
    PushNotificationTemplateNoCustomPayloadForV1,
    NoLeaderboardForStatistic,
    TitleNewsMissingDefaultLanguage,
    TitleNewsNotFound,
    TitleNewsDuplicateLanguage,
    TitleNewsMissingTitleOrBody,
    TitleNewsInvalidLanguage,
    EmailRecipientBlacklisted,
    InvalidGameCenterAuthRequest,
    GameCenterAuthenticationFailed,
    CannotEnablePartiesForTitle,
    PartyError,
    PartyRequests,
    PartyNoContent,
    PartyBadRequest,
    PartyUnauthorized,
    PartyForbidden,
    PartyNotFound,
    PartyConflict,
    PartyInternalServerError,
    PartyUnavailable,
    PartyTooManyRequests,
    PushNotificationTemplateMissingName,
    CannotEnableMultiplayerServersForTitle,
    WriteAttemptedDuringExport,
    MultiplayerServerTitleQuotaCoresExceeded,
    AutomationRuleNotFound,
    EntityAPIKeyLimitExceeded,
    EntityAPIKeyNotFound,
    EntityAPIKeyOrSecretInvalid,
    EconomyServiceUnavailable,
    EconomyServiceInternalError,
    QueryRateLimitExceeded,
    EntityAPIKeyCreationDisabledForEntity,
    ForbiddenByEntityPolicy,
    UpdateInventoryRateLimitExceeded,
    StudioCreationRateLimited,
    StudioCreationInProgress,
    DuplicateStudioName,
    StudioNotFound,
    StudioDeleted,
    StudioDeactivated,
    StudioActivated,
    TitleCreationRateLimited,
    TitleCreationInProgress,
    DuplicateTitleName,
    TitleActivationRateLimited,
    TitleActivationInProgress,
    TitleDeactivated,
    TitleActivated,
    CloudScriptAzureFunctionsExecutionTimeLimitExceeded,
    CloudScriptAzureFunctionsArgumentSizeExceeded,
    CloudScriptAzureFunctionsReturnSizeExceeded,
    CloudScriptAzureFunctionsHTTPRequestError,
    VirtualCurrencyBetaGetError,
    VirtualCurrencyBetaCreateError,
    VirtualCurrencyBetaInitialDepositSaveError,
    VirtualCurrencyBetaSaveError,
    VirtualCurrencyBetaDeleteError,
    VirtualCurrencyBetaRestoreError,
    VirtualCurrencyBetaSaveConflict,
    VirtualCurrencyBetaUpdateError,
    InsightsManagementDatabaseNotFound,
    InsightsManagementOperationNotFound,
    InsightsManagementErrorPendingOperationExists,
    InsightsManagementSetPerformanceLevelInvalidParameter,
    InsightsManagementSetStorageRetentionInvalidParameter,
    InsightsManagementGetStorageUsageInvalidParameter,
    InsightsManagementGetOperationStatusInvalidParameter,
    DuplicatePurchaseTransactionId,
    EvaluationModePlayerCountExceeded,
    GetPlayersInSegmentRateLimitExceeded,
    CloudScriptFunctionNameSizeExceeded,
    PaidInsightsFeaturesNotEnabled,
    CloudScriptAzureFunctionsQueueRequestError,
    EvaluationModeTitleCountExceeded,
    InsightsManagementTitleNotInFlight,
    LimitNotFound,
    LimitNotAvailableViaAPI,
    InsightsManagementSetStorageRetentionBelowMinimum,
    InsightsManagementSetStorageRetentionAboveMaximum,
    AppleNotEnabledForTitle,
    InsightsManagementNewActiveEventExportLimitInvalid,
    InsightsManagementSetPerformanceRateLimited,
    PartyRequestsThrottledFromRateLimiter,
    XboxServiceTooManyRequests,
    NintendoSwitchNotEnabledForTitle,
    RequestMultiplayerServersThrottledFromRateLimiter,
    TitleDataOverrideNotFound,
    DuplicateKeys,
    WasNotCreatedWithCloudRoot,
    LegacyMultiplayerServersDeprecated,
    VirtualCurrencyCurrentlyUnavailable,
    SteamUserNotFound,
    ElasticSearchOperationFailed,
    NotImplemented,
    PublisherNotFound,
    PublisherDeleted,
    ApiDisabledForMigration,
    ResourceNameUpdateNotAllowed,
    ApiNotEnabledForTitle,
    DuplicateTitleNameForPublisher,
    AzureTitleCreationInProgress,
    TitleConstraintsPublisherDeletion,
    InvalidPlayerAccountPoolId,
    PlayerAccountPoolNotFound,
    PlayerAccountPoolDeleted,
    TitleCleanupInProgress,
    AzureResourceConcurrentOperationInProgress,
    TitlePublisherUpdateNotAllowed,
    AzureResourceManagerNotSupportedInStamp,
    ApiNotIncludedInAzurePlayFabFeatureSet,
    GoogleServiceAccountFailedAuth,
    GoogleAPIServiceUnavailable,
    GoogleAPIServiceUnknownError,
    MatchmakingEntityInvalid,
    MatchmakingPlayerAttributesInvalid,
    MatchmakingQueueNotFound,
    MatchmakingMatchNotFound,
    MatchmakingTicketNotFound,
    MatchmakingAlreadyJoinedTicket,
    MatchmakingTicketAlreadyCompleted,
    MatchmakingQueueConfigInvalid,
    MatchmakingMemberProfileInvalid,
    NintendoSwitchDeviceIdNotLinked,
    MatchmakingNotEnabled,
    MatchmakingPlayerAttributesTooLarge,
    MatchmakingNumberOfPlayersInTicketTooLarge,
    MatchmakingAttributeInvalid,
    MatchmakingPlayerHasNotJoinedTicket,
    MatchmakingRateLimitExceeded,
    MatchmakingTicketMembershipLimitExceeded,
    MatchmakingUnauthorized,
    MatchmakingQueueLimitExceeded,
    MatchmakingRequestTypeMismatch,
    MatchmakingBadRequest,
    PubSubFeatureNotEnabledForTitle,
    PubSubTooManyRequests,
    PubSubConnectionNotFoundForEntity,
    PubSubConnectionHandleInvalid,
    PubSubSubscriptionLimitExceeded,
    TitleConfigNotFound,
    TitleConfigUpdateConflict,
    TitleConfigSerializationError,
    CatalogApiNotImplemented,
    CatalogEntityInvalid,
    CatalogTitleIdMissing,
    CatalogPlayerIdMissing,
    CatalogClientIdentityInvalid,
    CatalogOneOrMoreFilesInvalid,
    CatalogItemMetadataInvalid,
    CatalogItemIdInvalid,
    CatalogSearchParameterInvalid,
    CatalogFeatureDisabled,
    CatalogConfigInvalid,
    CatalogItemTypeInvalid,
    CatalogBadRequest,
    CatalogTooManyRequests,
    ExportInvalidStatusUpdate,
    ExportInvalidPrefix,
    ExportBlobContainerDoesNotExist,
    ExportNotFound,
    ExportCouldNotUpdate,
    ExportInvalidStorageType,
    ExportAmazonBucketDoesNotExist,
    ExportInvalidBlobStorage,
    ExportKustoException,
    ExportKustoConnectionFailed,
    ExportUnknownError,
    ExportCantEditPendingExport,
    ExportLimitExports,
    ExportLimitEvents,
    ExportInvalidPartitionStatusModification,
    ExportCouldNotCreate,
    ExportNoBackingDatabaseFound,
    ExportCouldNotDelete,
    ExportCannotDetermineEventQuery,
    ExportInvalidQuerySchemaModification,
    ExportQuerySchemaMissingRequiredColumns,
    ExportCannotParseQuery,
    ExportControlCommandsNotAllowed,
    ExportQueryMissingTableReference,
    ExplorerBasicInvalidQueryName,
    ExplorerBasicInvalidQueryDescription,
    ExplorerBasicInvalidQueryConditions,
    ExplorerBasicInvalidQueryStartDate,
    ExplorerBasicInvalidQueryEndDate,
    ExplorerBasicInvalidQueryGroupBy,
    ExplorerBasicInvalidQueryAggregateType,
    ExplorerBasicInvalidQueryAggregateProperty,
    ExplorerBasicLoadQueriesError,
    ExplorerBasicLoadQueryError,
    ExplorerBasicCreateQueryError,
    ExplorerBasicDeleteQueryError,
    ExplorerBasicUpdateQueryError,
    ExplorerBasicSavedQueriesLimit,
    ExplorerBasicSavedQueryNotFound,
    TenantShardMapperShardNotFound,
    TitleNotEnabledForParty,
    PartyVersionNotFound,
    MultiplayerServerBuildReferencedByMatchmakingQueue,
    MultiplayerServerBuildReferencedByBuildAlias,
    ExperimentationExperimentStopped,
    ExperimentationExperimentRunning,
    ExperimentationExperimentNotFound,
    ExperimentationExperimentNeverStarted,
    ExperimentationExperimentDeleted,
    ExperimentationClientTimeout,
    ExperimentationInvalidVariantConfiguration,
    ExperimentationInvalidVariableConfiguration,
    ExperimentInvalidId,
    ExperimentationNoScorecard,
    ExperimentationTreatmentAssignmentFailed,
    ExperimentationTreatmentAssignmentDisabled,
    ExperimentationInvalidDuration,
    ExperimentationMaxExperimentsReached,
    ExperimentationExperimentSchedulingInProgress,
    ExperimentationInvalidEndDate,
    ExperimentationInvalidStartDate,
    ExperimentationMaxDurationExceeded,
    ExperimentationExclusionGroupNotFound,
    ExperimentationExclusionGroupInsufficientCapacity,
    ExperimentationExclusionGroupCannotDelete,
    ExperimentationExclusionGroupInvalidTrafficAllocation,
    ExperimentationExclusionGroupInvalidName,
    MaxActionDepthExceeded,
    TitleNotOnUpdatedPricingPlan,
    SegmentManagementTitleNotInFlight,
    SegmentManagementNoExpressionTree,
    SegmentManagementTriggerActionCountOverLimit,
    SegmentManagementSegmentCountOverLimit,
    SegmentManagementInvalidSegmentId,
    SegmentManagementInvalidInput,
    SegmentManagementInvalidSegmentName,
    DeleteSegmentRateLimitExceeded,
    CreateSegmentRateLimitExceeded,
    UpdateSegmentRateLimitExceeded,
    GetSegmentsRateLimitExceeded,
    AsyncExportNotInFlight,
    AsyncExportNotFound,
    AsyncExportRateLimitExceeded,
    SnapshotNotFound,
    InventoryApiNotImplemented,
    LobbyDoesNotExist,
    LobbyRateLimitExceeded,
    LobbyPlayerAlreadyJoined,
    LobbyNotJoinable,
    LobbyMemberCannotRejoin,
    LobbyCurrentPlayersMoreThanMaxPlayers,
    LobbyPlayerNotPresent,
    LobbyBadRequest,
    LobbyPlayerMaxLobbyLimitExceeded,
    LobbyNewOwnerMustBeConnected,
    LobbyCurrentOwnerStillConnected,
    LobbyMemberIsNotOwner,
    EventSamplingInvalidRatio,
    EventSamplingInvalidEventNamespace,
    EventSamplingInvalidEventName,
    EventSamplingRatioNotFound,
    EventSinkConnectionInvalid,
    EventSinkConnectionUnauthorized,
    EventSinkRegionInvalid,
    OperationCanceled,
    InvalidDisplayNameRandomSuffixLength,
    AllowNonUniquePlayerDisplayNamesDisableNotAllowed
};

/// <summary>
/// TransactionStatus enum.
/// </summary>
enum class PFPlayerItemManagementTransactionStatus : uint32_t
{
    CreateCart,
    Init,
    Approved,
    Succeeded,
    FailedByProvider,
    DisputePending,
    RefundPending,
    Refunded,
    RefundFailed,
    ChargedBack,
    FailedByUber,
    FailedByPlayFab,
    Revoked,
    TradePending,
    Traded,
    Upgraded,
    StackPending,
    Stacked,
    Other,
    Failed
};

/// <summary>
/// PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest
{
    /// <summary>
    /// Amount to be added to the user balance of the specified virtual currency. Maximum VC balance
    /// is Int32 (2,147,483,647). Any increase over this value will be discarded.
    /// </summary>
    int32_t amount;

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
    /// PlayFab unique identifier of the user whose virtual currency balance is to be increased.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Name of the virtual currency which is to be incremented.
    /// </summary>
    _Null_terminated_ const char* virtualCurrency;

} PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest;

/// <summary>
/// PFPlayerItemManagementModifyUserVirtualCurrencyResult data model.
/// </summary>
typedef struct PFPlayerItemManagementModifyUserVirtualCurrencyResult
{
    /// <summary>
    /// Balance of the virtual currency after modification.
    /// </summary>
    int32_t balance;

    /// <summary>
    /// Amount added or subtracted from the user's virtual currency. Maximum VC balance is Int32 (2,147,483,647).
    /// Any increase over this value will be discarded.
    /// </summary>
    int32_t balanceChange;

    /// <summary>
    /// (Optional) User currency was subtracted from.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Name of the virtual currency which was modified.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* virtualCurrency;

} PFPlayerItemManagementModifyUserVirtualCurrencyResult;

/// <summary>
/// PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest data model. This returns the total
/// number of these items available.
/// </summary>
typedef struct PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest
{
    /// <summary>
    /// (Optional) Which catalog is being updated. If null, uses the default catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// The item to check for.
    /// </summary>
    _Null_terminated_ const char* itemId;

} PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest;

/// <summary>
/// PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult data model.
/// </summary>
typedef struct PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult
{
    /// <summary>
    /// The amount of the specified resource remaining.
    /// </summary>
    int32_t amount;

} PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult;

/// <summary>
/// PFPlayerItemManagementAdminGetUserInventoryRequest data model. All items currently in the user inventory
/// will be returned, irrespective of how they were acquired (via purchasing, grants, coupons, etc.).
/// Items that are expired, fully consumed, or are no longer valid are not considered to be in the user's
/// current inventory, and so will not be not included. There can be a delay of up to a half a second
/// for inventory changes to be reflected in the GetUserInventory API response.
/// </summary>
typedef struct PFPlayerItemManagementAdminGetUserInventoryRequest
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
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementAdminGetUserInventoryRequest;

/// <summary>
/// PFPlayerItemManagementAdminGetUserInventoryResult data model.
/// </summary>
typedef struct PFPlayerItemManagementAdminGetUserInventoryResult
{
    /// <summary>
    /// (Optional) Array of inventory items belonging to the user.
    /// </summary>
    _Maybenull_ _Field_size_(inventoryCount) PFItemInstance const* const* inventory;

    /// <summary>
    /// Count of inventory
    /// </summary>
    uint32_t inventoryCount;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Array of virtual currency balance(s) belonging to the user.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyCount) struct PFInt32DictionaryEntry const* virtualCurrency;

    /// <summary>
    /// Count of virtualCurrency
    /// </summary>
    uint32_t virtualCurrencyCount;

    /// <summary>
    /// (Optional) Array of remaining times and timestamps for virtual currencies.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyRechargeTimesCount) struct PFVirtualCurrencyRechargeTimeDictionaryEntry const* virtualCurrencyRechargeTimes;

    /// <summary>
    /// Count of virtualCurrencyRechargeTimes
    /// </summary>
    uint32_t virtualCurrencyRechargeTimesCount;

} PFPlayerItemManagementAdminGetUserInventoryResult;

/// <summary>
/// PFPlayerItemManagementItemGrant data model.
/// </summary>
typedef struct PFPlayerItemManagementItemGrant
{
    /// <summary>
    /// (Optional) String detailing any additional information concerning this operation.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* annotation;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// (Optional) Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace,
    /// are limited in size, and may not begin with a '!' character or be null.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFStringDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

    /// <summary>
    /// Unique identifier of the catalog item to be granted to the user.
    /// </summary>
    _Null_terminated_ const char* itemId;

    /// <summary>
    /// (Optional) Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values
    /// into Data due to language constraints. Use this to delete the keys directly.
    /// </summary>
    _Maybenull_ _Field_size_(keysToRemoveCount) const char* const* keysToRemove;

    /// <summary>
    /// Count of keysToRemove
    /// </summary>
    uint32_t keysToRemoveCount;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementItemGrant;

/// <summary>
/// PFPlayerItemManagementGrantItemsToUsersRequest data model. This function directly adds inventory
/// items to user inventories. As a result of this operations, the user will not be charged any transaction
/// fee, regardless of the inventory item catalog definition. Please note that the processing time for
/// inventory grants and purchases increases fractionally the more items are in the inventory, and the
/// more items are in the grant/purchase operation.
/// </summary>
typedef struct PFPlayerItemManagementGrantItemsToUsersRequest
{
    /// <summary>
    /// (Optional) Catalog version from which items are to be granted.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

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
    /// Array of items to grant and the users to whom the items are to be granted.
    /// </summary>
    _Field_size_(itemGrantsCount) PFPlayerItemManagementItemGrant const* const* itemGrants;

    /// <summary>
    /// Count of itemGrants
    /// </summary>
    uint32_t itemGrantsCount;

} PFPlayerItemManagementGrantItemsToUsersRequest;

/// <summary>
/// PFPlayerItemManagementGrantedItemInstance data model. Result of granting an item to a user. Note,
/// to retrieve additional information for an item such as Tags, Description that are the same across
/// all instances of the item, a call to GetCatalogItems is required. The ItemID of can be matched to
/// a catalog entry, which contains the additional information. Also note that Custom Data is only set
/// when the User's specific instance has updated the CustomData via a call to UpdateUserInventoryItemCustomData.
/// Other fields such as UnitPrice and UnitCurrency are only set when the item was granted via a purchase.
/// </summary>
typedef struct PFPlayerItemManagementGrantedItemInstance
{
    /// <summary>
    /// (Optional) Game specific comment associated with this instance when it was added to the user
    /// inventory.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* annotation;

    /// <summary>
    /// (Optional) Array of unique items that were awarded when this catalog item was purchased.
    /// </summary>
    _Maybenull_ _Field_size_(bundleContentsCount) const char* const* bundleContents;

    /// <summary>
    /// Count of bundleContents
    /// </summary>
    uint32_t bundleContentsCount;

    /// <summary>
    /// (Optional) Unique identifier for the parent inventory item, as defined in the catalog, for object
    /// which were added from a bundle or container.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* bundleParent;

    /// <summary>
    /// (Optional) Catalog version for the inventory item, when this instance was created.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// (Optional) A set of custom key-value pairs on the instance of the inventory item, which is not
    /// to be confused with the catalog item's custom data.
    /// </summary>
    _Maybenull_ _Field_size_(customDataCount) struct PFStringDictionaryEntry const* customData;

    /// <summary>
    /// Count of customData
    /// </summary>
    uint32_t customDataCount;

    /// <summary>
    /// (Optional) CatalogItem.DisplayName at the time this item was purchased.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* displayName;

    /// <summary>
    /// (Optional) Timestamp for when this instance will expire.
    /// </summary>
    _Maybenull_ time_t const* expiration;

    /// <summary>
    /// (Optional) Class name for the inventory item, as defined in the catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemClass;

    /// <summary>
    /// (Optional) Unique identifier for the inventory item, as defined in the catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemId;

    /// <summary>
    /// (Optional) Unique item identifier for this specific instance of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Timestamp for when this instance was purchased.
    /// </summary>
    _Maybenull_ time_t const* purchaseDate;

    /// <summary>
    /// (Optional) Total number of remaining uses, if this is a consumable item.
    /// </summary>
    _Maybenull_ int32_t const* remainingUses;

    /// <summary>
    /// Result of this operation.
    /// </summary>
    bool result;

    /// <summary>
    /// (Optional) Currency type for the cost of the catalog item. Not available when granting items.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* unitCurrency;

    /// <summary>
    /// Cost of the catalog item in the given currency. Not available when granting items.
    /// </summary>
    uint32_t unitPrice;

    /// <summary>
    /// (Optional) The number of uses that were added or removed to this item in this call.
    /// </summary>
    _Maybenull_ int32_t const* usesIncrementedBy;

} PFPlayerItemManagementGrantedItemInstance;

/// <summary>
/// PFPlayerItemManagementGrantItemsToUsersResult data model. Please note that the order of the items
/// in the response may not match the order of items in the request.
/// </summary>
typedef struct PFPlayerItemManagementGrantItemsToUsersResult
{
    /// <summary>
    /// (Optional) Array of items granted to users.
    /// </summary>
    _Maybenull_ _Field_size_(itemGrantResultsCount) PFPlayerItemManagementGrantedItemInstance const* const* itemGrantResults;

    /// <summary>
    /// Count of itemGrantResults
    /// </summary>
    uint32_t itemGrantResultsCount;

} PFPlayerItemManagementGrantItemsToUsersResult;

/// <summary>
/// PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest data model. This operation will
/// increment the global counter for the number of these items available. This number cannot be decremented,
/// except by actual grants.
/// </summary>
typedef struct PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest
{
    /// <summary>
    /// Amount to increase availability by.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// (Optional) Which catalog is being updated. If null, uses the default catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

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
    /// The item which needs more availability.
    /// </summary>
    _Null_terminated_ const char* itemId;

} PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest;

/// <summary>
/// PFPlayerItemManagementRevokeInventoryItemRequest data model. In cases where the inventory item in
/// question is a "crate", and the items it contained have already been dispensed, this will not revoke
/// access or otherwise remove the items which were dispensed.
/// </summary>
typedef struct PFPlayerItemManagementRevokeInventoryItemRequest
{
    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// Unique PlayFab assigned instance identifier of the item.
    /// </summary>
    _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementRevokeInventoryItemRequest;

/// <summary>
/// PFPlayerItemManagementRevokeInventoryItem data model.
/// </summary>
typedef struct PFPlayerItemManagementRevokeInventoryItem
{
    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// Unique PlayFab assigned instance identifier of the item.
    /// </summary>
    _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementRevokeInventoryItem;

/// <summary>
/// PFPlayerItemManagementRevokeInventoryItemsRequest data model. In cases where the inventory item in
/// question is a "crate", and the items it contained have already been dispensed, this will not revoke
/// access or otherwise remove the items which were dispensed.
/// </summary>
typedef struct PFPlayerItemManagementRevokeInventoryItemsRequest
{
    /// <summary>
    /// Array of player items to revoke, between 1 and 25 items.
    /// </summary>
    _Field_size_(itemsCount) PFPlayerItemManagementRevokeInventoryItem const* const* items;

    /// <summary>
    /// Count of items
    /// </summary>
    uint32_t itemsCount;

} PFPlayerItemManagementRevokeInventoryItemsRequest;

/// <summary>
/// PFPlayerItemManagementRevokeItemError data model.
/// </summary>
typedef struct PFPlayerItemManagementRevokeItemError
{
    /// <summary>
    /// (Optional) Specific error that was encountered.
    /// </summary>
    _Maybenull_ PFPlayerItemManagementGenericErrorCodes const* error;

    /// <summary>
    /// (Optional) Item information that failed to be revoked.
    /// </summary>
    _Maybenull_ PFPlayerItemManagementRevokeInventoryItem const* item;

} PFPlayerItemManagementRevokeItemError;

/// <summary>
/// PFPlayerItemManagementRevokeInventoryItemsResult data model.
/// </summary>
typedef struct PFPlayerItemManagementRevokeInventoryItemsResult
{
    /// <summary>
    /// (Optional) Collection of any errors that occurred during processing.
    /// </summary>
    _Maybenull_ _Field_size_(errorsCount) PFPlayerItemManagementRevokeItemError const* const* errors;

    /// <summary>
    /// Count of errors
    /// </summary>
    uint32_t errorsCount;

} PFPlayerItemManagementRevokeInventoryItemsResult;

/// <summary>
/// PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest
{
    /// <summary>
    /// Amount to be subtracted from the user balance of the specified virtual currency.
    /// </summary>
    int32_t amount;

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
    /// PlayFab unique identifier of the user whose virtual currency balance is to be decreased.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Name of the virtual currency which is to be decremented.
    /// </summary>
    _Null_terminated_ const char* virtualCurrency;

} PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest;

/// <summary>
/// PFPlayerItemManagementClientAddUserVirtualCurrencyRequest data model. This API must be enabled for
/// use as an option in the game manager website. It is disabled by default.
/// </summary>
typedef struct PFPlayerItemManagementClientAddUserVirtualCurrencyRequest
{
    /// <summary>
    /// Amount to be added to the user balance of the specified virtual currency.
    /// </summary>
    int32_t amount;

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
    /// Name of the virtual currency which is to be incremented.
    /// </summary>
    _Null_terminated_ const char* virtualCurrency;

} PFPlayerItemManagementClientAddUserVirtualCurrencyRequest;

/// <summary>
/// PFPlayerItemManagementConfirmPurchaseRequest data model. The final step in the purchasing process,
/// this API finalizes the purchase with the payment provider, where applicable, adding virtual goods
/// to the player inventory (including random drop table resolution and recursive addition of bundled
/// items) and adjusting virtual currency balances for funds used or added. Note that this is a pull operation,
/// and should be polled regularly when a purchase is in progress. Please note that the processing time
/// for inventory grants and purchases increases fractionally the more items are in the inventory, and
/// the more items are in the grant/purchase operation.
/// </summary>
typedef struct PFPlayerItemManagementConfirmPurchaseRequest
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
    /// Purchase order identifier returned from StartPurchase.
    /// </summary>
    _Null_terminated_ const char* orderId;

} PFPlayerItemManagementConfirmPurchaseRequest;

/// <summary>
/// PFPlayerItemManagementConfirmPurchaseResult data model. When the FailedByPaymentProvider error is
/// returned, it's important to check the ProviderErrorCode, ProviderErrorMessage, and ProviderErrorDetails
/// to understand the specific reason the payment was rejected, as in some rare cases, this may mean that
/// the provider hasn't completed some operation required to finalize the purchase.
/// </summary>
typedef struct PFPlayerItemManagementConfirmPurchaseResult
{
    /// <summary>
    /// (Optional) Array of items purchased.
    /// </summary>
    _Maybenull_ _Field_size_(itemsCount) PFItemInstance const* const* items;

    /// <summary>
    /// Count of items
    /// </summary>
    uint32_t itemsCount;

    /// <summary>
    /// (Optional) Purchase order identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* orderId;

    /// <summary>
    /// Date and time of the purchase.
    /// </summary>
    time_t purchaseDate;

} PFPlayerItemManagementConfirmPurchaseResult;

/// <summary>
/// PFPlayerItemManagementClientConsumeItemRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementClientConsumeItemRequest
{
    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// Number of uses to consume from the item.
    /// </summary>
    int32_t consumeCount;

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
    /// Unique instance identifier of the item to be consumed.
    /// </summary>
    _Null_terminated_ const char* itemInstanceId;

} PFPlayerItemManagementClientConsumeItemRequest;

/// <summary>
/// PFPlayerItemManagementConsumeItemResult data model.
/// </summary>
typedef struct PFPlayerItemManagementConsumeItemResult
{
    /// <summary>
    /// (Optional) Unique instance identifier of the item with uses consumed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// Number of uses remaining on the item.
    /// </summary>
    int32_t remainingUses;

} PFPlayerItemManagementConsumeItemResult;

/// <summary>
/// PFPlayerItemManagementClientGetCharacterInventoryRequest data model. All items currently in the character
/// inventory will be returned, irrespective of how they were acquired (via purchasing, grants, coupons,
/// etc.). Items that are expired, fully consumed, or are no longer valid are not considered to be in
/// the user's current inventory, and so will not be not included. Also returns their virtual currency
/// balances.
/// </summary>
typedef struct PFPlayerItemManagementClientGetCharacterInventoryRequest
{
    /// <summary>
    /// (Optional) Used to limit results to only those from a specific catalog version.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Null_terminated_ const char* characterId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFPlayerItemManagementClientGetCharacterInventoryRequest;

/// <summary>
/// PFPlayerItemManagementClientGetCharacterInventoryResult data model.
/// </summary>
typedef struct PFPlayerItemManagementClientGetCharacterInventoryResult
{
    /// <summary>
    /// (Optional) Unique identifier of the character for this inventory.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// (Optional) Array of inventory items belonging to the character.
    /// </summary>
    _Maybenull_ _Field_size_(inventoryCount) PFItemInstance const* const* inventory;

    /// <summary>
    /// Count of inventory
    /// </summary>
    uint32_t inventoryCount;

    /// <summary>
    /// (Optional) Array of virtual currency balance(s) belonging to the character.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyCount) struct PFInt32DictionaryEntry const* virtualCurrency;

    /// <summary>
    /// Count of virtualCurrency
    /// </summary>
    uint32_t virtualCurrencyCount;

    /// <summary>
    /// (Optional) Array of remaining times and timestamps for virtual currencies.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyRechargeTimesCount) struct PFVirtualCurrencyRechargeTimeDictionaryEntry const* virtualCurrencyRechargeTimes;

    /// <summary>
    /// Count of virtualCurrencyRechargeTimes
    /// </summary>
    uint32_t virtualCurrencyRechargeTimesCount;

} PFPlayerItemManagementClientGetCharacterInventoryResult;

/// <summary>
/// PFPlayerItemManagementGetPaymentTokenRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementGetPaymentTokenRequest
{
    /// <summary>
    /// The name of service to provide the payment token. Allowed Values are: xsolla.
    /// </summary>
    _Null_terminated_ const char* tokenProvider;

} PFPlayerItemManagementGetPaymentTokenRequest;

/// <summary>
/// PFPlayerItemManagementGetPaymentTokenResult data model.
/// </summary>
typedef struct PFPlayerItemManagementGetPaymentTokenResult
{
    /// <summary>
    /// (Optional) PlayFab's purchase order identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* orderId;

    /// <summary>
    /// (Optional) The token from provider.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* providerToken;

} PFPlayerItemManagementGetPaymentTokenResult;

/// <summary>
/// PFPlayerItemManagementGetPurchaseRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementGetPurchaseRequest
{
    /// <summary>
    /// Purchase order identifier.
    /// </summary>
    _Null_terminated_ const char* orderId;

} PFPlayerItemManagementGetPurchaseRequest;

/// <summary>
/// PFPlayerItemManagementGetPurchaseResult data model.
/// </summary>
typedef struct PFPlayerItemManagementGetPurchaseResult
{
    /// <summary>
    /// (Optional) Purchase order identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* orderId;

    /// <summary>
    /// (Optional) Payment provider used for transaction (If not VC).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* paymentProvider;

    /// <summary>
    /// Date and time of the purchase.
    /// </summary>
    time_t purchaseDate;

    /// <summary>
    /// (Optional) Provider transaction ID (If not VC).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* transactionId;

    /// <summary>
    /// (Optional) PlayFab transaction status.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* transactionStatus;

} PFPlayerItemManagementGetPurchaseResult;

/// <summary>
/// PFPlayerItemManagementClientGetUserInventoryRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementClientGetUserInventoryRequest
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

} PFPlayerItemManagementClientGetUserInventoryRequest;

/// <summary>
/// PFPlayerItemManagementClientGetUserInventoryResult data model. All items currently in the user inventory
/// will be returned, irrespective of how they were acquired (via purchasing, grants, coupons, etc.).
/// Items that are expired, fully consumed, or are no longer valid are not considered to be in the user's
/// current inventory, and so will not be not included.
/// </summary>
typedef struct PFPlayerItemManagementClientGetUserInventoryResult
{
    /// <summary>
    /// (Optional) Array of inventory items belonging to the user.
    /// </summary>
    _Maybenull_ _Field_size_(inventoryCount) PFItemInstance const* const* inventory;

    /// <summary>
    /// Count of inventory
    /// </summary>
    uint32_t inventoryCount;

    /// <summary>
    /// (Optional) Array of virtual currency balance(s) belonging to the user.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyCount) struct PFInt32DictionaryEntry const* virtualCurrency;

    /// <summary>
    /// Count of virtualCurrency
    /// </summary>
    uint32_t virtualCurrencyCount;

    /// <summary>
    /// (Optional) Array of remaining times and timestamps for virtual currencies.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyRechargeTimesCount) struct PFVirtualCurrencyRechargeTimeDictionaryEntry const* virtualCurrencyRechargeTimes;

    /// <summary>
    /// Count of virtualCurrencyRechargeTimes
    /// </summary>
    uint32_t virtualCurrencyRechargeTimesCount;

} PFPlayerItemManagementClientGetUserInventoryResult;

/// <summary>
/// PFPlayerItemManagementPayForPurchaseRequest data model. This is the second step in the purchasing
/// process, initiating the purchase transaction with the payment provider (if applicable). For payment
/// provider scenarios, the title should next present the user with the payment provider'sinterface for
/// payment. Once the player has completed the payment with the provider, the title should call ConfirmPurchase
/// tofinalize the process and add the appropriate items to the player inventory.
/// </summary>
typedef struct PFPlayerItemManagementPayForPurchaseRequest
{
    /// <summary>
    /// Currency to use to fund the purchase.
    /// </summary>
    _Null_terminated_ const char* currency;

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
    /// Purchase order identifier returned from StartPurchase.
    /// </summary>
    _Null_terminated_ const char* orderId;

    /// <summary>
    /// Payment provider to use to fund the purchase.
    /// </summary>
    _Null_terminated_ const char* providerName;

    /// <summary>
    /// (Optional) Payment provider transaction identifier. Required for Facebook Payments.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* providerTransactionId;

} PFPlayerItemManagementPayForPurchaseRequest;

/// <summary>
/// PFPlayerItemManagementPayForPurchaseResult data model. For web-based payment providers, this operation
/// returns the URL to which the user should be directed inorder to approve the purchase. Items added
/// to the user inventory as a result of this operation will be marked as unconfirmed.
/// </summary>
typedef struct PFPlayerItemManagementPayForPurchaseResult
{
    /// <summary>
    /// Local credit applied to the transaction (provider specific).
    /// </summary>
    uint32_t creditApplied;

    /// <summary>
    /// (Optional) Purchase order identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* orderId;

    /// <summary>
    /// (Optional) Provider used for the transaction.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* providerData;

    /// <summary>
    /// (Optional) A token generated by the provider to authenticate the request (provider-specific).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* providerToken;

    /// <summary>
    /// (Optional) URL to the purchase provider page that details the purchase.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* purchaseConfirmationPageURL;

    /// <summary>
    /// (Optional) Currency for the transaction, may be a virtual currency or real money.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* purchaseCurrency;

    /// <summary>
    /// Cost of the transaction.
    /// </summary>
    uint32_t purchasePrice;

    /// <summary>
    /// (Optional) Status of the transaction.
    /// </summary>
    _Maybenull_ PFPlayerItemManagementTransactionStatus const* status;

    /// <summary>
    /// (Optional) Virtual currencies granted by the transaction, if any.
    /// </summary>
    _Maybenull_ _Field_size_(vCAmountCount) struct PFInt32DictionaryEntry const* vCAmount;

    /// <summary>
    /// Count of vCAmount
    /// </summary>
    uint32_t vCAmountCount;

    /// <summary>
    /// (Optional) Current virtual currency balances for the user.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyCount) struct PFInt32DictionaryEntry const* virtualCurrency;

    /// <summary>
    /// Count of virtualCurrency
    /// </summary>
    uint32_t virtualCurrencyCount;

} PFPlayerItemManagementPayForPurchaseResult;

/// <summary>
/// PFPlayerItemManagementPurchaseItemRequest data model. Please note that the processing time for inventory
/// grants and purchases increases fractionally the more items are in the inventory, and the more items
/// are in the grant/purchase operation (with each item in a bundle being a distinct add).
/// </summary>
typedef struct PFPlayerItemManagementPurchaseItemRequest
{
    /// <summary>
    /// (Optional) Catalog version for the items to be purchased (defaults to most recent version.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

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
    /// Unique identifier of the item to purchase.
    /// </summary>
    _Null_terminated_ const char* itemId;

    /// <summary>
    /// Price the client expects to pay for the item (in case a new catalog or store was uploaded, with
    /// new prices).
    /// </summary>
    int32_t price;

    /// <summary>
    /// (Optional) Store to buy this item through. If not set, prices default to those in the catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* storeId;

    /// <summary>
    /// Virtual currency to use to purchase the item.
    /// </summary>
    _Null_terminated_ const char* virtualCurrency;

} PFPlayerItemManagementPurchaseItemRequest;

/// <summary>
/// PFPlayerItemManagementPurchaseItemResult data model.
/// </summary>
typedef struct PFPlayerItemManagementPurchaseItemResult
{
    /// <summary>
    /// (Optional) Details for the items purchased.
    /// </summary>
    _Maybenull_ _Field_size_(itemsCount) PFItemInstance const* const* items;

    /// <summary>
    /// Count of items
    /// </summary>
    uint32_t itemsCount;

} PFPlayerItemManagementPurchaseItemResult;

/// <summary>
/// PFPlayerItemManagementClientRedeemCouponRequest data model. Coupon codes can be created for any item,
/// or set of items, in the catalog for the title. This operation causes the coupon to be consumed, and
/// the specific items to be awarded to the user. Attempting to re-use an already consumed code, or a
/// code which has not yet been created in the service, will result in an error.
/// </summary>
typedef struct PFPlayerItemManagementClientRedeemCouponRequest
{
    /// <summary>
    /// (Optional) Catalog version of the coupon. If null, uses the default catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Optional identifier for the Character that should receive the item. If null, item
    /// is added to the player.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// Generated coupon code to redeem.
    /// </summary>
    _Null_terminated_ const char* couponCode;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFPlayerItemManagementClientRedeemCouponRequest;

/// <summary>
/// PFPlayerItemManagementRedeemCouponResult data model.
/// </summary>
typedef struct PFPlayerItemManagementRedeemCouponResult
{
    /// <summary>
    /// (Optional) Items granted to the player as a result of redeeming the coupon.
    /// </summary>
    _Maybenull_ _Field_size_(grantedItemsCount) PFItemInstance const* const* grantedItems;

    /// <summary>
    /// Count of grantedItems
    /// </summary>
    uint32_t grantedItemsCount;

} PFPlayerItemManagementRedeemCouponResult;

/// <summary>
/// PFPlayerItemManagementItemPurchaseRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementItemPurchaseRequest
{
    /// <summary>
    /// (Optional) Title-specific text concerning this purchase.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* annotation;

    /// <summary>
    /// Unique ItemId of the item to purchase.
    /// </summary>
    _Null_terminated_ const char* itemId;

    /// <summary>
    /// How many of this item to purchase. Min 1, maximum 25.
    /// </summary>
    uint32_t quantity;

    /// <summary>
    /// (Optional) Items to be upgraded as a result of this purchase (upgraded items are hidden, as they
    /// are "replaced" by the new items).
    /// </summary>
    _Maybenull_ _Field_size_(upgradeFromItemsCount) const char* const* upgradeFromItems;

    /// <summary>
    /// Count of upgradeFromItems
    /// </summary>
    uint32_t upgradeFromItemsCount;

} PFPlayerItemManagementItemPurchaseRequest;

/// <summary>
/// PFPlayerItemManagementStartPurchaseRequest data model. This is the first step in the purchasing process.
/// For security purposes, once the order (or "cart") has been created, additional inventory objects may
/// no longer be added. In addition, inventory objects will be locked to the current prices, regardless
/// of any subsequent changes at the catalog level which may occur during the next two steps.
/// </summary>
typedef struct PFPlayerItemManagementStartPurchaseRequest
{
    /// <summary>
    /// (Optional) Catalog version for the items to be purchased. Defaults to most recent catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

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
    /// Array of items to purchase.
    /// </summary>
    _Field_size_(itemsCount) PFPlayerItemManagementItemPurchaseRequest const* const* items;

    /// <summary>
    /// Count of items
    /// </summary>
    uint32_t itemsCount;

    /// <summary>
    /// (Optional) Store through which to purchase items. If not set, prices will be pulled from the
    /// catalog itself.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* storeId;

} PFPlayerItemManagementStartPurchaseRequest;

/// <summary>
/// PFPlayerItemManagementCartItem data model.
/// </summary>
typedef struct PFPlayerItemManagementCartItem
{
    /// <summary>
    /// (Optional) Description of the catalog item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// (Optional) Display name for the catalog item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* displayName;

    /// <summary>
    /// (Optional) Class name to which catalog item belongs.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemClass;

    /// <summary>
    /// (Optional) Unique identifier for the catalog item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemId;

    /// <summary>
    /// (Optional) Unique instance identifier for this catalog item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// (Optional) Cost of the catalog item for each applicable real world currency.
    /// </summary>
    _Maybenull_ _Field_size_(realCurrencyPricesCount) struct PFUint32DictionaryEntry const* realCurrencyPrices;

    /// <summary>
    /// Count of realCurrencyPrices
    /// </summary>
    uint32_t realCurrencyPricesCount;

    /// <summary>
    /// (Optional) Amount of each applicable virtual currency which will be received as a result of purchasing
    /// this catalog item.
    /// </summary>
    _Maybenull_ _Field_size_(vCAmountCount) struct PFUint32DictionaryEntry const* vCAmount;

    /// <summary>
    /// Count of vCAmount
    /// </summary>
    uint32_t vCAmountCount;

    /// <summary>
    /// (Optional) Cost of the catalog item for each applicable virtual currency.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyPricesCount) struct PFUint32DictionaryEntry const* virtualCurrencyPrices;

    /// <summary>
    /// Count of virtualCurrencyPrices
    /// </summary>
    uint32_t virtualCurrencyPricesCount;

} PFPlayerItemManagementCartItem;

/// <summary>
/// PFPlayerItemManagementPaymentOption data model.
/// </summary>
typedef struct PFPlayerItemManagementPaymentOption
{
    /// <summary>
    /// (Optional) Specific currency to use to fund the purchase.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* currency;

    /// <summary>
    /// Amount of the specified currency needed for the purchase.
    /// </summary>
    uint32_t price;

    /// <summary>
    /// (Optional) Name of the purchase provider for this option.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* providerName;

    /// <summary>
    /// Amount of existing credit the user has with the provider.
    /// </summary>
    uint32_t storeCredit;

} PFPlayerItemManagementPaymentOption;

/// <summary>
/// PFPlayerItemManagementStartPurchaseResult data model.
/// </summary>
typedef struct PFPlayerItemManagementStartPurchaseResult
{
    /// <summary>
    /// (Optional) Cart items to be purchased.
    /// </summary>
    _Maybenull_ _Field_size_(contentsCount) PFPlayerItemManagementCartItem const* const* contents;

    /// <summary>
    /// Count of contents
    /// </summary>
    uint32_t contentsCount;

    /// <summary>
    /// (Optional) Purchase order identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* orderId;

    /// <summary>
    /// (Optional) Available methods by which the user can pay.
    /// </summary>
    _Maybenull_ _Field_size_(paymentOptionsCount) PFPlayerItemManagementPaymentOption const* const* paymentOptions;

    /// <summary>
    /// Count of paymentOptions
    /// </summary>
    uint32_t paymentOptionsCount;

    /// <summary>
    /// (Optional) Current virtual currency totals for the user.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyBalancesCount) struct PFInt32DictionaryEntry const* virtualCurrencyBalances;

    /// <summary>
    /// Count of virtualCurrencyBalances
    /// </summary>
    uint32_t virtualCurrencyBalancesCount;

} PFPlayerItemManagementStartPurchaseResult;

/// <summary>
/// PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest data model. This API must be enabled
/// for use as an option in the game manager website. It is disabled by default.
/// </summary>
typedef struct PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest
{
    /// <summary>
    /// Amount to be subtracted from the user balance of the specified virtual currency.
    /// </summary>
    int32_t amount;

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
    /// Name of the virtual currency which is to be decremented.
    /// </summary>
    _Null_terminated_ const char* virtualCurrency;

} PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest;

/// <summary>
/// PFPlayerItemManagementClientUnlockContainerInstanceRequest data model. Specify the container and
/// optionally the catalogVersion for the container to open.
/// </summary>
typedef struct PFPlayerItemManagementClientUnlockContainerInstanceRequest
{
    /// <summary>
    /// (Optional) Specifies the catalog version that should be used to determine container contents.
    /// If unspecified, uses catalog associated with the item instance.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// ItemInstanceId of the container to unlock.
    /// </summary>
    _Null_terminated_ const char* containerItemInstanceId;

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
    /// (Optional) ItemInstanceId of the key that will be consumed by unlocking this container. If the
    /// container requires a key, this parameter is required.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* keyItemInstanceId;

} PFPlayerItemManagementClientUnlockContainerInstanceRequest;

/// <summary>
/// PFPlayerItemManagementUnlockContainerItemResult data model. The items and vc found within the container.
/// These will be added and stacked in the appropriate inventory.
/// </summary>
typedef struct PFPlayerItemManagementUnlockContainerItemResult
{
    /// <summary>
    /// (Optional) Items granted to the player as a result of unlocking the container.
    /// </summary>
    _Maybenull_ _Field_size_(grantedItemsCount) PFItemInstance const* const* grantedItems;

    /// <summary>
    /// Count of grantedItems
    /// </summary>
    uint32_t grantedItemsCount;

    /// <summary>
    /// (Optional) Unique instance identifier of the container unlocked.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* unlockedItemInstanceId;

    /// <summary>
    /// (Optional) Unique instance identifier of the key used to unlock the container, if applicable.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* unlockedWithItemInstanceId;

    /// <summary>
    /// (Optional) Virtual currency granted to the player as a result of unlocking the container.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyCount) struct PFUint32DictionaryEntry const* virtualCurrency;

    /// <summary>
    /// Count of virtualCurrency
    /// </summary>
    uint32_t virtualCurrencyCount;

} PFPlayerItemManagementUnlockContainerItemResult;

/// <summary>
/// PFPlayerItemManagementClientUnlockContainerItemRequest data model. Specify the type of container
/// to open and optionally the catalogVersion for the container to open.
/// </summary>
typedef struct PFPlayerItemManagementClientUnlockContainerItemRequest
{
    /// <summary>
    /// (Optional) Specifies the catalog version that should be used to determine container contents.
    /// If unspecified, uses default/primary catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// Catalog ItemId of the container type to unlock.
    /// </summary>
    _Null_terminated_ const char* containerItemId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFPlayerItemManagementClientUnlockContainerItemRequest;

/// <summary>
/// PFPlayerItemManagementAddCharacterVirtualCurrencyRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementAddCharacterVirtualCurrencyRequest
{
    /// <summary>
    /// Amount to be added to the character balance of the specified virtual currency. Maximum VC balance
    /// is Int32 (2,147,483,647). Any increase over this value will be discarded.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Null_terminated_ const char* characterId;

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
    /// PlayFab unique identifier of the user whose virtual currency balance is to be incremented.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Name of the virtual currency which is to be incremented.
    /// </summary>
    _Null_terminated_ const char* virtualCurrency;

} PFPlayerItemManagementAddCharacterVirtualCurrencyRequest;

/// <summary>
/// PFPlayerItemManagementModifyCharacterVirtualCurrencyResult data model.
/// </summary>
typedef struct PFPlayerItemManagementModifyCharacterVirtualCurrencyResult
{
    /// <summary>
    /// Balance of the virtual currency after modification.
    /// </summary>
    int32_t balance;

    /// <summary>
    /// (Optional) Name of the virtual currency which was modified.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* virtualCurrency;

} PFPlayerItemManagementModifyCharacterVirtualCurrencyResult;

/// <summary>
/// PFPlayerItemManagementServerAddUserVirtualCurrencyRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementServerAddUserVirtualCurrencyRequest
{
    /// <summary>
    /// Amount to be added to the user balance of the specified virtual currency. Maximum VC balance
    /// is Int32 (2,147,483,647). Any increase over this value will be discarded.
    /// </summary>
    int32_t amount;

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
    /// PlayFab unique identifier of the user whose virtual currency balance is to be increased.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Name of the virtual currency which is to be incremented.
    /// </summary>
    _Null_terminated_ const char* virtualCurrency;

} PFPlayerItemManagementServerAddUserVirtualCurrencyRequest;

/// <summary>
/// PFPlayerItemManagementServerConsumeItemRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementServerConsumeItemRequest
{
    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// Number of uses to consume from the item.
    /// </summary>
    int32_t consumeCount;

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
    /// Unique instance identifier of the item to be consumed.
    /// </summary>
    _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementServerConsumeItemRequest;

/// <summary>
/// PFPlayerItemManagementEvaluateRandomResultTableRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementEvaluateRandomResultTableRequest
{
    /// <summary>
    /// (Optional) Specifies the catalog version that should be used to evaluate the Random Result Table.
    /// If unspecified, uses default/primary catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// The unique identifier of the Random Result Table to use.
    /// </summary>
    _Null_terminated_ const char* tableId;

} PFPlayerItemManagementEvaluateRandomResultTableRequest;

/// <summary>
/// PFPlayerItemManagementEvaluateRandomResultTableResult data model. Note that if the Random Result
/// Table contains no entries, or does not exist for the catalog specified (the Primary catalog if one
/// is not specified), an InvalidDropTable error will be returned.
/// </summary>
typedef struct PFPlayerItemManagementEvaluateRandomResultTableResult
{
    /// <summary>
    /// (Optional) Unique identifier for the item returned from the Random Result Table evaluation, for
    /// the given catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* resultItemId;

} PFPlayerItemManagementEvaluateRandomResultTableResult;

/// <summary>
/// PFPlayerItemManagementServerGetCharacterInventoryRequest data model. All items currently in the character
/// inventory will be returned, irrespective of how they were acquired (via purchasing, grants, coupons,
/// etc.). Items that are expired, fully consumed, or are no longer valid are not considered to be in
/// the user's current inventory, and so will not be not included. Also returns their virtual currency
/// balances.
/// </summary>
typedef struct PFPlayerItemManagementServerGetCharacterInventoryRequest
{
    /// <summary>
    /// (Optional) Used to limit results to only those from a specific catalog version.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Null_terminated_ const char* characterId;

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
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementServerGetCharacterInventoryRequest;

/// <summary>
/// PFPlayerItemManagementServerGetCharacterInventoryResult data model.
/// </summary>
typedef struct PFPlayerItemManagementServerGetCharacterInventoryResult
{
    /// <summary>
    /// (Optional) Unique identifier of the character for this inventory.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// (Optional) Array of inventory items belonging to the character.
    /// </summary>
    _Maybenull_ _Field_size_(inventoryCount) PFItemInstance const* const* inventory;

    /// <summary>
    /// Count of inventory
    /// </summary>
    uint32_t inventoryCount;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Array of virtual currency balance(s) belonging to the character.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyCount) struct PFInt32DictionaryEntry const* virtualCurrency;

    /// <summary>
    /// Count of virtualCurrency
    /// </summary>
    uint32_t virtualCurrencyCount;

    /// <summary>
    /// (Optional) Array of remaining times and timestamps for virtual currencies.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyRechargeTimesCount) struct PFVirtualCurrencyRechargeTimeDictionaryEntry const* virtualCurrencyRechargeTimes;

    /// <summary>
    /// Count of virtualCurrencyRechargeTimes
    /// </summary>
    uint32_t virtualCurrencyRechargeTimesCount;

} PFPlayerItemManagementServerGetCharacterInventoryResult;

/// <summary>
/// PFPlayerItemManagementGetRandomResultTablesRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementGetRandomResultTablesRequest
{
    /// <summary>
    /// (Optional) Specifies the catalog version that should be used to retrieve the Random Result Tables.
    /// If unspecified, uses default/primary catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// The unique identifier of the Random Result Table to use.
    /// </summary>
    _Field_size_(tableIDsCount) const char* const* tableIDs;

    /// <summary>
    /// Count of tableIDs
    /// </summary>
    uint32_t tableIDsCount;

} PFPlayerItemManagementGetRandomResultTablesRequest;

/// <summary>
/// PFPlayerItemManagementServerGetUserInventoryRequest data model. All items currently in the user inventory
/// will be returned, irrespective of how they were acquired (via purchasing, grants, coupons, etc.).
/// Items that are expired, fully consumed, or are no longer valid are not considered to be in the user's
/// current inventory, and so will not be not included.
/// </summary>
typedef struct PFPlayerItemManagementServerGetUserInventoryRequest
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
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementServerGetUserInventoryRequest;

/// <summary>
/// PFPlayerItemManagementServerGetUserInventoryResult data model.
/// </summary>
typedef struct PFPlayerItemManagementServerGetUserInventoryResult
{
    /// <summary>
    /// (Optional) Array of inventory items belonging to the user.
    /// </summary>
    _Maybenull_ _Field_size_(inventoryCount) PFItemInstance const* const* inventory;

    /// <summary>
    /// Count of inventory
    /// </summary>
    uint32_t inventoryCount;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Array of virtual currency balance(s) belonging to the user.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyCount) struct PFInt32DictionaryEntry const* virtualCurrency;

    /// <summary>
    /// Count of virtualCurrency
    /// </summary>
    uint32_t virtualCurrencyCount;

    /// <summary>
    /// (Optional) Array of remaining times and timestamps for virtual currencies.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyRechargeTimesCount) struct PFVirtualCurrencyRechargeTimeDictionaryEntry const* virtualCurrencyRechargeTimes;

    /// <summary>
    /// Count of virtualCurrencyRechargeTimes
    /// </summary>
    uint32_t virtualCurrencyRechargeTimesCount;

} PFPlayerItemManagementServerGetUserInventoryResult;

/// <summary>
/// PFPlayerItemManagementGrantItemsToCharacterRequest data model. This function directly adds inventory
/// items to the character's inventories. As a result of this operations, the user will not be charged
/// any transaction fee, regardless of the inventory item catalog definition. Please note that the processing
/// time for inventory grants and purchases increases fractionally the more items are in the inventory,
/// and the more items are in the grant/purchase operation.
/// </summary>
typedef struct PFPlayerItemManagementGrantItemsToCharacterRequest
{
    /// <summary>
    /// (Optional) String detailing any additional information concerning this operation.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* annotation;

    /// <summary>
    /// (Optional) Catalog version from which items are to be granted.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Null_terminated_ const char* characterId;

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
    /// (Optional) Array of itemIds to grant to the user.
    /// </summary>
    _Maybenull_ _Field_size_(itemIdsCount) const char* const* itemIds;

    /// <summary>
    /// Count of itemIds
    /// </summary>
    uint32_t itemIdsCount;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementGrantItemsToCharacterRequest;

/// <summary>
/// PFPlayerItemManagementGrantItemsToCharacterResult data model.
/// </summary>
typedef struct PFPlayerItemManagementGrantItemsToCharacterResult
{
    /// <summary>
    /// (Optional) Array of items granted to users.
    /// </summary>
    _Maybenull_ _Field_size_(itemGrantResultsCount) PFPlayerItemManagementGrantedItemInstance const* const* itemGrantResults;

    /// <summary>
    /// Count of itemGrantResults
    /// </summary>
    uint32_t itemGrantResultsCount;

} PFPlayerItemManagementGrantItemsToCharacterResult;

/// <summary>
/// PFPlayerItemManagementGrantItemsToUserRequest data model. This function directly adds inventory items
/// to the user's inventories. As a result of this operations, the user will not be charged any transaction
/// fee, regardless of the inventory item catalog definition. Please note that the processing time for
/// inventory grants and purchases increases fractionally the more items are in the inventory, and the
/// more items are in the grant/purchase operation.
/// </summary>
typedef struct PFPlayerItemManagementGrantItemsToUserRequest
{
    /// <summary>
    /// (Optional) String detailing any additional information concerning this operation.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* annotation;

    /// <summary>
    /// (Optional) Catalog version from which items are to be granted.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

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
    /// Array of itemIds to grant to the user.
    /// </summary>
    _Field_size_(itemIdsCount) const char* const* itemIds;

    /// <summary>
    /// Count of itemIds
    /// </summary>
    uint32_t itemIdsCount;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementGrantItemsToUserRequest;

/// <summary>
/// PFPlayerItemManagementGrantItemsToUserResult data model. Please note that the order of the items
/// in the response may not match the order of items in the request.
/// </summary>
typedef struct PFPlayerItemManagementGrantItemsToUserResult
{
    /// <summary>
    /// (Optional) Array of items granted to users.
    /// </summary>
    _Maybenull_ _Field_size_(itemGrantResultsCount) PFPlayerItemManagementGrantedItemInstance const* const* itemGrantResults;

    /// <summary>
    /// Count of itemGrantResults
    /// </summary>
    uint32_t itemGrantResultsCount;

} PFPlayerItemManagementGrantItemsToUserResult;

/// <summary>
/// PFPlayerItemManagementModifyItemUsesRequest data model. This function can both add and remove uses
/// of an inventory item. If the number of uses drops below zero, the item will be removed from active
/// inventory.
/// </summary>
typedef struct PFPlayerItemManagementModifyItemUsesRequest
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
    /// Unique instance identifier of the item to be modified.
    /// </summary>
    _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// PlayFab unique identifier of the user whose item is being modified.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Number of uses to add to the item. Can be negative to remove uses.
    /// </summary>
    int32_t usesToAdd;

} PFPlayerItemManagementModifyItemUsesRequest;

/// <summary>
/// PFPlayerItemManagementModifyItemUsesResult data model.
/// </summary>
typedef struct PFPlayerItemManagementModifyItemUsesResult
{
    /// <summary>
    /// (Optional) Unique instance identifier of the item with uses consumed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// Number of uses remaining on the item.
    /// </summary>
    int32_t remainingUses;

} PFPlayerItemManagementModifyItemUsesResult;

/// <summary>
/// PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest data model. Transfers an item from
/// a character to another character that is owned by the same user. This will remove the item from the
/// character's inventory (until and unless it is moved back), and will enable the other character to
/// make use of the item instead.
/// </summary>
typedef struct PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest
{
    /// <summary>
    /// Unique identifier of the character that currently has the item.
    /// </summary>
    _Null_terminated_ const char* givingCharacterId;

    /// <summary>
    /// Unique PlayFab assigned instance identifier of the item.
    /// </summary>
    _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Unique identifier of the character that will be receiving the item.
    /// </summary>
    _Null_terminated_ const char* receivingCharacterId;

} PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest;

/// <summary>
/// PFPlayerItemManagementMoveItemToCharacterFromUserRequest data model. Transfers an item from a user
/// to a character she owns. This will remove the item from the user's inventory (until and unless it
/// is moved back), and will enable the character to make use of the item instead.
/// </summary>
typedef struct PFPlayerItemManagementMoveItemToCharacterFromUserRequest
{
    /// <summary>
    /// Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Null_terminated_ const char* characterId;

    /// <summary>
    /// Unique PlayFab assigned instance identifier of the item.
    /// </summary>
    _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementMoveItemToCharacterFromUserRequest;

/// <summary>
/// PFPlayerItemManagementMoveItemToUserFromCharacterRequest data model. Transfers an item from a character
/// to the owning user. This will remove the item from the character's inventory (until and unless it
/// is moved back), and will enable the user to make use of the item instead.
/// </summary>
typedef struct PFPlayerItemManagementMoveItemToUserFromCharacterRequest
{
    /// <summary>
    /// Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Null_terminated_ const char* characterId;

    /// <summary>
    /// Unique PlayFab assigned instance identifier of the item.
    /// </summary>
    _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementMoveItemToUserFromCharacterRequest;

/// <summary>
/// PFPlayerItemManagementServerRedeemCouponRequest data model. Coupon codes can be created for any item,
/// or set of items, in the catalog for the title. This operation causes the coupon to be consumed, and
/// the specific items to be awarded to the user. Attempting to re-use an already consumed code, or a
/// code which has not yet been created in the service, will result in an error.
/// </summary>
typedef struct PFPlayerItemManagementServerRedeemCouponRequest
{
    /// <summary>
    /// (Optional) Catalog version of the coupon.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Optional identifier for the Character that should receive the item. If null, item
    /// is added to the player.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// Generated coupon code to redeem.
    /// </summary>
    _Null_terminated_ const char* couponCode;

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
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementServerRedeemCouponRequest;

/// <summary>
/// PFPlayerItemManagementReportPlayerServerRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementReportPlayerServerRequest
{
    /// <summary>
    /// (Optional) Optional additional comment by reporting player.
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
    /// Unique PlayFab identifier of the reported player.
    /// </summary>
    _Null_terminated_ const char* reporteeId;

    /// <summary>
    /// PlayFabId of the reporting player.
    /// </summary>
    _Null_terminated_ const char* reporterId;

} PFPlayerItemManagementReportPlayerServerRequest;

/// <summary>
/// PFPlayerItemManagementReportPlayerServerResult data model. Players are currently limited to five
/// reports per day. Attempts by a single user account to submit reports beyond five will result in Updated
/// being returned as false.
/// </summary>
typedef struct PFPlayerItemManagementReportPlayerServerResult
{
    /// <summary>
    /// The number of remaining reports which may be filed today by this reporting player.
    /// </summary>
    int32_t submissionsRemaining;

} PFPlayerItemManagementReportPlayerServerResult;

/// <summary>
/// PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest
{
    /// <summary>
    /// Amount to be subtracted from the user balance of the specified virtual currency.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Null_terminated_ const char* characterId;

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
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Name of the virtual currency which is to be decremented.
    /// </summary>
    _Null_terminated_ const char* virtualCurrency;

} PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest;

/// <summary>
/// PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest data model.
/// </summary>
typedef struct PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest
{
    /// <summary>
    /// Amount to be subtracted from the user balance of the specified virtual currency.
    /// </summary>
    int32_t amount;

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
    /// PlayFab unique identifier of the user whose virtual currency balance is to be decreased.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Name of the virtual currency which is to be decremented.
    /// </summary>
    _Null_terminated_ const char* virtualCurrency;

} PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest;

/// <summary>
/// PFPlayerItemManagementServerUnlockContainerInstanceRequest data model. Specify the container and
/// optionally the catalogVersion for the container to open.
/// </summary>
typedef struct PFPlayerItemManagementServerUnlockContainerInstanceRequest
{
    /// <summary>
    /// (Optional) Specifies the catalog version that should be used to determine container contents.
    /// If unspecified, uses catalog associated with the item instance.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// ItemInstanceId of the container to unlock.
    /// </summary>
    _Null_terminated_ const char* containerItemInstanceId;

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
    /// (Optional) ItemInstanceId of the key that will be consumed by unlocking this container. If the
    /// container requires a key, this parameter is required.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* keyItemInstanceId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementServerUnlockContainerInstanceRequest;

/// <summary>
/// PFPlayerItemManagementServerUnlockContainerItemRequest data model. Specify the type of container
/// to open and optionally the catalogVersion for the container to open.
/// </summary>
typedef struct PFPlayerItemManagementServerUnlockContainerItemRequest
{
    /// <summary>
    /// (Optional) Specifies the catalog version that should be used to determine container contents.
    /// If unspecified, uses default/primary catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

    /// <summary>
    /// Catalog ItemId of the container type to unlock.
    /// </summary>
    _Null_terminated_ const char* containerItemId;

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
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementServerUnlockContainerItemRequest;

/// <summary>
/// PFPlayerItemManagementUpdateUserInventoryItemDataRequest data model. This function performs an additive
/// update of the arbitrary JSON object containing the custom data for the item instance which belongs
/// to the specified user. In updating the custom data object, keys which already exist in the object
/// will have their values overwritten, while keys with null values will be removed. No other key-value
/// pairs will be changed apart from those specified in the call.
/// </summary>
typedef struct PFPlayerItemManagementUpdateUserInventoryItemDataRequest
{
    /// <summary>
    /// (Optional) Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

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
    /// (Optional) Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace,
    /// are limited in size, and may not begin with a '!' character or be null.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFStringDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

    /// <summary>
    /// Unique PlayFab assigned instance identifier of the item.
    /// </summary>
    _Null_terminated_ const char* itemInstanceId;

    /// <summary>
    /// (Optional) Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values
    /// into Data due to language constraints. Use this to delete the keys directly.
    /// </summary>
    _Maybenull_ _Field_size_(keysToRemoveCount) const char* const* keysToRemove;

    /// <summary>
    /// Count of keysToRemove
    /// </summary>
    uint32_t keysToRemoveCount;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerItemManagementUpdateUserInventoryItemDataRequest;

#pragma pop_macro("IN")

}
