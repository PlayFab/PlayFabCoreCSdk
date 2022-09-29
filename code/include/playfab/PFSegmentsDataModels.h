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
/// SegmentFilterComparison enum.
/// </summary>
enum class PFSegmentsSegmentFilterComparison : uint32_t
{
    GreaterThan,
    LessThan,
    EqualTo,
    NotEqualTo,
    GreaterThanOrEqual,
    LessThanOrEqual,
    Exists,
    Contains,
    NotContains
};

/// <summary>
/// SegmentLoginIdentityProvider enum.
/// </summary>
enum class PFSegmentsSegmentLoginIdentityProvider : uint32_t
{
    Unknown,
    PlayFab,
    Custom,
    GameCenter,
    GooglePlay,
    Steam,
    XBoxLive,
    PSN,
    Kongregate,
    Facebook,
    IOSDevice,
    AndroidDevice,
    Twitch,
    WindowsHello,
    GameServer,
    CustomServer,
    NintendoSwitch,
    FacebookInstantGames,
    OpenIdConnect,
    Apple,
    NintendoSwitchAccount
};

/// <summary>
/// SegmentCountryCode enum.
/// </summary>
enum class PFSegmentsSegmentCountryCode : uint32_t
{
    AF,
    AX,
    AL,
    DZ,
    AS,
    AD,
    AO,
    AI,
    AQ,
    AG,
    AR,
    AM,
    AW,
    AU,
    AT,
    AZ,
    BS,
    BH,
    BD,
    BB,
    BY,
    BE,
    BZ,
    BJ,
    BM,
    BT,
    BO,
    BQ,
    BA,
    BW,
    BV,
    BR,
    IO,
    BN,
    BG,
    BF,
    BI,
    KH,
    CM,
    CA,
    CV,
    KY,
    CF,
    TD,
    CL,
    CN,
    CX,
    CC,
    CO,
    KM,
    CG,
    CD,
    CK,
    CR,
    CI,
    HR,
    CU,
    CW,
    CY,
    CZ,
    DK,
    DJ,
    DM,
    DO,
    EC,
    EG,
    SV,
    GQ,
    ER,
    EE,
    ET,
    FK,
    FO,
    FJ,
    FI,
    FR,
    GF,
    PF,
    TF,
    GA,
    GM,
    GE,
    DE,
    GH,
    GI,
    GR,
    GL,
    GD,
    GP,
    GU,
    GT,
    GG,
    GN,
    GW,
    GY,
    HT,
    HM,
    VA,
    HN,
    HK,
    HU,
    IS,
    IN,
    ID,
    IR,
    IQ,
    IE,
    IM,
    IL,
    IT,
    JM,
    JP,
    JE,
    JO,
    KZ,
    KE,
    KI,
    KP,
    KR,
    KW,
    KG,
    LA,
    LV,
    LB,
    LS,
    LR,
    LY,
    LI,
    LT,
    LU,
    MO,
    MK,
    MG,
    MW,
    MY,
    MV,
    ML,
    MT,
    MH,
    MQ,
    MR,
    MU,
    YT,
    MX,
    FM,
    MD,
    MC,
    MN,
    ME,
    MS,
    MA,
    MZ,
    MM,
    NA,
    NR,
    NP,
    NL,
    NC,
    NZ,
    NI,
    NE,
    NG,
    NU,
    NF,
    MP,
    NO,
    OM,
    PK,
    PW,
    PS,
    PA,
    PG,
    PY,
    PE,
    PH,
    PN,
    PL,
    PT,
    PR,
    QA,
    RE,
    RO,
    RU,
    RW,
    BL,
    SH,
    KN,
    LC,
    MF,
    PM,
    VC,
    WS,
    SM,
    ST,
    SA,
    SN,
    RS,
    SC,
    SL,
    SG,
    SX,
    SK,
    SI,
    SB,
    SO,
    ZA,
    GS,
    SS,
    ES,
    LK,
    SD,
    SR,
    SJ,
    SZ,
    SE,
    CH,
    SY,
    TW,
    TJ,
    TZ,
    TH,
    TL,
    TG,
    TK,
    TO,
    TT,
    TN,
    TR,
    TM,
    TC,
    TV,
    UG,
    UA,
    AE,
    GB,
    US,
    UM,
    UY,
    UZ,
    VU,
    VE,
    VN,
    VG,
    VI,
    WF,
    EH,
    YE,
    ZM,
    ZW
};

/// <summary>
/// ChurnRiskLevel enum.
/// </summary>
enum class PFSegmentsChurnRiskLevel : uint32_t
{
    NoData,
    LowRisk,
    MediumRisk,
    HighRisk
};

/// <summary>
/// SegmentPushNotificationDevicePlatform enum.
/// </summary>
enum class PFSegmentsSegmentPushNotificationDevicePlatform : uint32_t
{
    ApplePushNotificationService,
    GoogleCloudMessaging
};

/// <summary>
/// SegmentCurrency enum.
/// </summary>
enum class PFSegmentsSegmentCurrency : uint32_t
{
    AED,
    AFN,
    ALL,
    AMD,
    ANG,
    AOA,
    ARS,
    AUD,
    AWG,
    AZN,
    BAM,
    BBD,
    BDT,
    BGN,
    BHD,
    BIF,
    BMD,
    BND,
    BOB,
    BRL,
    BSD,
    BTN,
    BWP,
    BYR,
    BZD,
    CAD,
    CDF,
    CHF,
    CLP,
    CNY,
    COP,
    CRC,
    CUC,
    CUP,
    CVE,
    CZK,
    DJF,
    DKK,
    DOP,
    DZD,
    EGP,
    ERN,
    ETB,
    EUR,
    FJD,
    FKP,
    GBP,
    GEL,
    GGP,
    GHS,
    GIP,
    GMD,
    GNF,
    GTQ,
    GYD,
    HKD,
    HNL,
    HRK,
    HTG,
    HUF,
    IDR,
    ILS,
    IMP,
    INR,
    IQD,
    IRR,
    ISK,
    JEP,
    JMD,
    JOD,
    JPY,
    KES,
    KGS,
    KHR,
    KMF,
    KPW,
    KRW,
    KWD,
    KYD,
    KZT,
    LAK,
    LBP,
    LKR,
    LRD,
    LSL,
    LYD,
    MAD,
    MDL,
    MGA,
    MKD,
    MMK,
    MNT,
    MOP,
    MRO,
    MUR,
    MVR,
    MWK,
    MXN,
    MYR,
    MZN,
    NAD,
    NGN,
    NIO,
    NOK,
    NPR,
    NZD,
    OMR,
    PAB,
    PEN,
    PGK,
    PHP,
    PKR,
    PLN,
    PYG,
    QAR,
    RON,
    RSD,
    RUB,
    RWF,
    SAR,
    SBD,
    SCR,
    SDG,
    SEK,
    SGD,
    SHP,
    SLL,
    SOS,
    SPL,
    SRD,
    STD,
    SVC,
    SYP,
    SZL,
    THB,
    TJS,
    TMT,
    TND,
    TOP,
    TRY,
    TTD,
    TVD,
    TWD,
    TZS,
    UAH,
    UGX,
    USD,
    UYU,
    UZS,
    VEF,
    VND,
    VUV,
    WST,
    XAF,
    XCD,
    XDR,
    XOF,
    XPF,
    YER,
    ZAR,
    ZMW,
    ZWD
};

/// <summary>
/// PFSegmentsBanPlayerSegmentAction data model.
/// </summary>
typedef struct PFSegmentsBanPlayerSegmentAction
{
    /// <summary>
    /// (Optional) Ban hours duration.
    /// </summary>
    _Maybenull_ uint32_t const* banHours;

    /// <summary>
    /// (Optional) Reason for ban.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reasonForBan;

} PFSegmentsBanPlayerSegmentAction;

/// <summary>
/// PFSegmentsDeletePlayerStatisticSegmentAction data model.
/// </summary>
typedef struct PFSegmentsDeletePlayerStatisticSegmentAction
{
    /// <summary>
    /// (Optional) Statistic name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* statisticName;

} PFSegmentsDeletePlayerStatisticSegmentAction;

/// <summary>
/// PFSegmentsEmailNotificationSegmentAction data model.
/// </summary>
typedef struct PFSegmentsEmailNotificationSegmentAction
{
    /// <summary>
    /// (Optional) Email template id.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* emailTemplateId;

    /// <summary>
    /// (Optional) Email template name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* emailTemplateName;

} PFSegmentsEmailNotificationSegmentAction;

/// <summary>
/// PFSegmentsExecuteAzureFunctionSegmentAction data model.
/// </summary>
typedef struct PFSegmentsExecuteAzureFunctionSegmentAction
{
    /// <summary>
    /// (Optional) Azure function.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* azureFunction;

    /// <summary>
    /// (Optional) Azure function parameter.
    /// </summary>
    PFJsonObject functionParameter;

    /// <summary>
    /// Generate play stream event.
    /// </summary>
    bool generateFunctionExecutedEvents;

} PFSegmentsExecuteAzureFunctionSegmentAction;

/// <summary>
/// PFSegmentsExecuteCloudScriptSegmentAction data model.
/// </summary>
typedef struct PFSegmentsExecuteCloudScriptSegmentAction
{
    /// <summary>
    /// (Optional) Cloud script function.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* cloudScriptFunction;

    /// <summary>
    /// Generate play stream event.
    /// </summary>
    bool cloudScriptPublishResultsToPlayStream;

    /// <summary>
    /// (Optional) Cloud script function parameter.
    /// </summary>
    PFJsonObject functionParameter;

    /// <summary>
    /// (Optional) Cloud script function parameter json text.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* functionParameterJson;

} PFSegmentsExecuteCloudScriptSegmentAction;

/// <summary>
/// PFSegmentsGrantItemSegmentAction data model.
/// </summary>
typedef struct PFSegmentsGrantItemSegmentAction
{
    /// <summary>
    /// (Optional) Item catalog id.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catelogId;

    /// <summary>
    /// (Optional) Item id.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemId;

    /// <summary>
    /// Item quantity.
    /// </summary>
    uint32_t quantity;

} PFSegmentsGrantItemSegmentAction;

/// <summary>
/// PFSegmentsGrantVirtualCurrencySegmentAction data model.
/// </summary>
typedef struct PFSegmentsGrantVirtualCurrencySegmentAction
{
    /// <summary>
    /// Virtual currency amount.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// (Optional) Virtual currency code.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* currencyCode;

} PFSegmentsGrantVirtualCurrencySegmentAction;

/// <summary>
/// PFSegmentsIncrementPlayerStatisticSegmentAction data model.
/// </summary>
typedef struct PFSegmentsIncrementPlayerStatisticSegmentAction
{
    /// <summary>
    /// Increment value.
    /// </summary>
    int32_t incrementValue;

    /// <summary>
    /// (Optional) Statistic name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* statisticName;

} PFSegmentsIncrementPlayerStatisticSegmentAction;

/// <summary>
/// PFSegmentsPushNotificationSegmentAction data model.
/// </summary>
typedef struct PFSegmentsPushNotificationSegmentAction
{
    /// <summary>
    /// (Optional) Push notification template id.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* pushNotificationTemplateId;

} PFSegmentsPushNotificationSegmentAction;

/// <summary>
/// PFSegmentsSegmentTrigger data model.
/// </summary>
typedef struct PFSegmentsSegmentTrigger
{
    /// <summary>
    /// (Optional) Ban player segment trigger action.
    /// </summary>
    _Maybenull_ PFSegmentsBanPlayerSegmentAction const* banPlayerAction;

    /// <summary>
    /// (Optional) Delete player statistic segment trigger action.
    /// </summary>
    _Maybenull_ PFSegmentsDeletePlayerStatisticSegmentAction const* deletePlayerStatisticAction;

    /// <summary>
    /// (Optional) Email notification segment trigger action.
    /// </summary>
    _Maybenull_ PFSegmentsEmailNotificationSegmentAction const* emailNotificationAction;

    /// <summary>
    /// (Optional) Execute azure function segment trigger action.
    /// </summary>
    _Maybenull_ PFSegmentsExecuteAzureFunctionSegmentAction const* executeAzureFunctionAction;

    /// <summary>
    /// (Optional) Execute cloud script segment trigger action.
    /// </summary>
    _Maybenull_ PFSegmentsExecuteCloudScriptSegmentAction const* executeCloudScriptAction;

    /// <summary>
    /// (Optional) Grant item segment trigger action.
    /// </summary>
    _Maybenull_ PFSegmentsGrantItemSegmentAction const* grantItemAction;

    /// <summary>
    /// (Optional) Grant virtual currency segment trigger action.
    /// </summary>
    _Maybenull_ PFSegmentsGrantVirtualCurrencySegmentAction const* grantVirtualCurrencyAction;

    /// <summary>
    /// (Optional) Increment player statistic segment trigger action.
    /// </summary>
    _Maybenull_ PFSegmentsIncrementPlayerStatisticSegmentAction const* incrementPlayerStatisticAction;

    /// <summary>
    /// (Optional) Push notification segment trigger action.
    /// </summary>
    _Maybenull_ PFSegmentsPushNotificationSegmentAction const* pushNotificationAction;

} PFSegmentsSegmentTrigger;

/// <summary>
/// PFSegmentsAdCampaignSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsAdCampaignSegmentFilter
{
    /// <summary>
    /// (Optional) Campaign id.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* campaignId;

    /// <summary>
    /// (Optional) Campaign source.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* campaignSource;

    /// <summary>
    /// (Optional) Campaign comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

} PFSegmentsAdCampaignSegmentFilter;

/// <summary>
/// PFSegmentsFirstLoginDateSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsFirstLoginDateSegmentFilter
{
    /// <summary>
    /// (Optional) First player login date comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// First player login date.
    /// </summary>
    time_t logInDate;

} PFSegmentsFirstLoginDateSegmentFilter;

/// <summary>
/// PFSegmentsFirstLoginTimespanSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsFirstLoginTimespanSegmentFilter
{
    /// <summary>
    /// (Optional) First player login duration comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// First player login duration.
    /// </summary>
    double durationInMinutes;

} PFSegmentsFirstLoginTimespanSegmentFilter;

/// <summary>
/// PFSegmentsLastLoginDateSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsLastLoginDateSegmentFilter
{
    /// <summary>
    /// (Optional) Last player login date comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// Last player login date.
    /// </summary>
    time_t logInDate;

} PFSegmentsLastLoginDateSegmentFilter;

/// <summary>
/// PFSegmentsLastLoginTimespanSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsLastLoginTimespanSegmentFilter
{
    /// <summary>
    /// (Optional) Last player login duration comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// Last player login duration.
    /// </summary>
    double durationInMinutes;

} PFSegmentsLastLoginTimespanSegmentFilter;

/// <summary>
/// PFSegmentsLinkedUserAccountSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsLinkedUserAccountSegmentFilter
{
    /// <summary>
    /// (Optional) Login provider.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentLoginIdentityProvider const* loginProvider;

} PFSegmentsLinkedUserAccountSegmentFilter;

/// <summary>
/// PFSegmentsLinkedUserAccountHasEmailSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsLinkedUserAccountHasEmailSegmentFilter
{
    /// <summary>
    /// (Optional) Login provider comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// (Optional) Login provider.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentLoginIdentityProvider const* loginProvider;

} PFSegmentsLinkedUserAccountHasEmailSegmentFilter;

/// <summary>
/// PFSegmentsLocationSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsLocationSegmentFilter
{
    /// <summary>
    /// (Optional) Segment country code.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentCountryCode const* countryCode;

} PFSegmentsLocationSegmentFilter;

/// <summary>
/// PFSegmentsPlayerChurnPredictionSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsPlayerChurnPredictionSegmentFilter
{
    /// <summary>
    /// (Optional) Comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// (Optional) RiskLevel.
    /// </summary>
    _Maybenull_ PFSegmentsChurnRiskLevel const* riskLevel;

} PFSegmentsPlayerChurnPredictionSegmentFilter;

/// <summary>
/// PFSegmentsPlayerChurnPredictionTimeSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsPlayerChurnPredictionTimeSegmentFilter
{
    /// <summary>
    /// (Optional) Comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// DurationInDays.
    /// </summary>
    double durationInDays;

} PFSegmentsPlayerChurnPredictionTimeSegmentFilter;

/// <summary>
/// PFSegmentsPlayerChurnPreviousPredictionSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsPlayerChurnPreviousPredictionSegmentFilter
{
    /// <summary>
    /// (Optional) Comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// (Optional) RiskLevel.
    /// </summary>
    _Maybenull_ PFSegmentsChurnRiskLevel const* riskLevel;

} PFSegmentsPlayerChurnPreviousPredictionSegmentFilter;

/// <summary>
/// PFSegmentsPushNotificationSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsPushNotificationSegmentFilter
{
    /// <summary>
    /// (Optional) Push notification device platform.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentPushNotificationDevicePlatform const* pushNotificationDevicePlatform;

} PFSegmentsPushNotificationSegmentFilter;

/// <summary>
/// PFSegmentsStatisticSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsStatisticSegmentFilter
{
    /// <summary>
    /// (Optional) Statistic filter comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// (Optional) Statistic filter value.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* filterValue;

    /// <summary>
    /// (Optional) Statistic name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) Use current version of statistic?.
    /// </summary>
    _Maybenull_ bool const* useCurrentVersion;

    /// <summary>
    /// (Optional) Statistic version.
    /// </summary>
    _Maybenull_ int32_t const* version;

} PFSegmentsStatisticSegmentFilter;

/// <summary>
/// PFSegmentsTagSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsTagSegmentFilter
{
    /// <summary>
    /// (Optional) Tag comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// (Optional) Tag value.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* tagValue;

} PFSegmentsTagSegmentFilter;

/// <summary>
/// PFSegmentsTotalValueToDateInUSDSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsTotalValueToDateInUSDSegmentFilter
{
    /// <summary>
    /// (Optional) Total value to date USD amount.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* amount;

    /// <summary>
    /// (Optional) Total value to date USD comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

} PFSegmentsTotalValueToDateInUSDSegmentFilter;

/// <summary>
/// PFSegmentsUserOriginationSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsUserOriginationSegmentFilter
{
    /// <summary>
    /// (Optional) User login provider.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentLoginIdentityProvider const* loginProvider;

} PFSegmentsUserOriginationSegmentFilter;

/// <summary>
/// PFSegmentsValueToDateSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsValueToDateSegmentFilter
{
    /// <summary>
    /// (Optional) Value to date amount.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* amount;

    /// <summary>
    /// (Optional) Value to date comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// (Optional) Currency using for filter.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentCurrency const* currency;

} PFSegmentsValueToDateSegmentFilter;

/// <summary>
/// PFSegmentsVirtualCurrencyBalanceSegmentFilter data model.
/// </summary>
typedef struct PFSegmentsVirtualCurrencyBalanceSegmentFilter
{
    /// <summary>
    /// Total amount.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// (Optional) Amount comparison.
    /// </summary>
    _Maybenull_ PFSegmentsSegmentFilterComparison const* comparison;

    /// <summary>
    /// (Optional) Currency code.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* currencyCode;

} PFSegmentsVirtualCurrencyBalanceSegmentFilter;

/// <summary>
/// PFSegmentsSegmentAndDefinition data model.
/// </summary>
typedef struct PFSegmentsSegmentAndDefinition
{
    /// <summary>
    /// (Optional) Filter property for ad campaign filter.
    /// </summary>
    _Maybenull_ PFSegmentsAdCampaignSegmentFilter const* adCampaignFilter;

    /// <summary>
    /// (Optional) Filter property for first login date.
    /// </summary>
    _Maybenull_ PFSegmentsFirstLoginDateSegmentFilter const* firstLoginDateFilter;

    /// <summary>
    /// (Optional) Filter property for first login timespan.
    /// </summary>
    _Maybenull_ PFSegmentsFirstLoginTimespanSegmentFilter const* firstLoginFilter;

    /// <summary>
    /// (Optional) Filter property for last login date.
    /// </summary>
    _Maybenull_ PFSegmentsLastLoginDateSegmentFilter const* lastLoginDateFilter;

    /// <summary>
    /// (Optional) Filter property for last login timespan.
    /// </summary>
    _Maybenull_ PFSegmentsLastLoginTimespanSegmentFilter const* lastLoginFilter;

    /// <summary>
    /// (Optional) Filter property for linked in user account.
    /// </summary>
    _Maybenull_ PFSegmentsLinkedUserAccountSegmentFilter const* linkedUserAccountFilter;

    /// <summary>
    /// (Optional) Filter property for linked in user account has email.
    /// </summary>
    _Maybenull_ PFSegmentsLinkedUserAccountHasEmailSegmentFilter const* linkedUserAccountHasEmailFilter;

    /// <summary>
    /// (Optional) Filter property for location.
    /// </summary>
    _Maybenull_ PFSegmentsLocationSegmentFilter const* locationFilter;

    /// <summary>
    /// (Optional) Filter property for current player churn value.
    /// </summary>
    _Maybenull_ PFSegmentsPlayerChurnPredictionSegmentFilter const* playerChurnPredictionFilter;

    /// <summary>
    /// (Optional) Filter property for player churn timespan.
    /// </summary>
    _Maybenull_ PFSegmentsPlayerChurnPredictionTimeSegmentFilter const* playerChurnPredictionTimeFilter;

    /// <summary>
    /// (Optional) Filter property for previous player churn value.
    /// </summary>
    _Maybenull_ PFSegmentsPlayerChurnPreviousPredictionSegmentFilter const* playerChurnPreviousPredictionFilter;

    /// <summary>
    /// (Optional) Filter property for push notification.
    /// </summary>
    _Maybenull_ PFSegmentsPushNotificationSegmentFilter const* pushNotificationFilter;

    /// <summary>
    /// (Optional) Filter property for statistics.
    /// </summary>
    _Maybenull_ PFSegmentsStatisticSegmentFilter const* statisticFilter;

    /// <summary>
    /// (Optional) Filter property for tags.
    /// </summary>
    _Maybenull_ PFSegmentsTagSegmentFilter const* tagFilter;

    /// <summary>
    /// (Optional) Filter property for total value to date in USD.
    /// </summary>
    _Maybenull_ PFSegmentsTotalValueToDateInUSDSegmentFilter const* totalValueToDateInUSDFilter;

    /// <summary>
    /// (Optional) Filter property for user origination.
    /// </summary>
    _Maybenull_ PFSegmentsUserOriginationSegmentFilter const* userOriginationFilter;

    /// <summary>
    /// (Optional) Filter property for value to date.
    /// </summary>
    _Maybenull_ PFSegmentsValueToDateSegmentFilter const* valueToDateFilter;

    /// <summary>
    /// (Optional) Filter property for virtual currency.
    /// </summary>
    _Maybenull_ PFSegmentsVirtualCurrencyBalanceSegmentFilter const* virtualCurrencyBalanceFilter;

} PFSegmentsSegmentAndDefinition;

/// <summary>
/// PFSegmentsSegmentOrDefinition data model.
/// </summary>
typedef struct PFSegmentsSegmentOrDefinition
{
    /// <summary>
    /// (Optional) List of segment and definitions.
    /// </summary>
    _Maybenull_ _Field_size_(segmentAndDefinitionsCount) PFSegmentsSegmentAndDefinition const* const* segmentAndDefinitions;

    /// <summary>
    /// Count of segmentAndDefinitions
    /// </summary>
    uint32_t segmentAndDefinitionsCount;

} PFSegmentsSegmentOrDefinition;

/// <summary>
/// PFSegmentsSegmentModel data model.
/// </summary>
typedef struct PFSegmentsSegmentModel
{
    /// <summary>
    /// (Optional) Segment description.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// (Optional) Segment actions for current entered segment players.
    /// </summary>
    _Maybenull_ _Field_size_(enteredSegmentActionsCount) PFSegmentsSegmentTrigger const* const* enteredSegmentActions;

    /// <summary>
    /// Count of enteredSegmentActions
    /// </summary>
    uint32_t enteredSegmentActionsCount;

    /// <summary>
    /// Segment last updated date time.
    /// </summary>
    time_t lastUpdateTime;

    /// <summary>
    /// (Optional) Segment actions for current left segment players.
    /// </summary>
    _Maybenull_ _Field_size_(leftSegmentActionsCount) PFSegmentsSegmentTrigger const* const* leftSegmentActions;

    /// <summary>
    /// Count of leftSegmentActions
    /// </summary>
    uint32_t leftSegmentActionsCount;

    /// <summary>
    /// (Optional) Segment name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) Segment id in hex.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* segmentId;

    /// <summary>
    /// (Optional) Segment or definitions. This includes segment and definitions and filters.
    /// </summary>
    _Maybenull_ _Field_size_(segmentOrDefinitionsCount) PFSegmentsSegmentOrDefinition const* const* segmentOrDefinitions;

    /// <summary>
    /// Count of segmentOrDefinitions
    /// </summary>
    uint32_t segmentOrDefinitionsCount;

} PFSegmentsSegmentModel;

/// <summary>
/// PFSegmentsCreateSegmentRequest data model. Send all the segment details part of CreateSegmentRequest.
/// </summary>
typedef struct PFSegmentsCreateSegmentRequest
{
    /// <summary>
    /// Segment model with all of the segment properties data.
    /// </summary>
    PFSegmentsSegmentModel const* segmentModel;

} PFSegmentsCreateSegmentRequest;

/// <summary>
/// PFSegmentsCreateSegmentResponse data model.
/// </summary>
typedef struct PFSegmentsCreateSegmentResponse
{
    /// <summary>
    /// (Optional) Error message.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* errorMessage;

    /// <summary>
    /// (Optional) Segment id.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* segmentId;

} PFSegmentsCreateSegmentResponse;

/// <summary>
/// PFSegmentsDeleteSegmentRequest data model. Send segment id planning to delete part of DeleteSegmentRequest
/// object.
/// </summary>
typedef struct PFSegmentsDeleteSegmentRequest
{
    /// <summary>
    /// Segment id.
    /// </summary>
    _Null_terminated_ const char* segmentId;

} PFSegmentsDeleteSegmentRequest;

/// <summary>
/// PFSegmentsDeleteSegmentsResponse data model.
/// </summary>
typedef struct PFSegmentsDeleteSegmentsResponse
{
    /// <summary>
    /// (Optional) Error message.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* errorMessage;

} PFSegmentsDeleteSegmentsResponse;

/// <summary>
/// PFSegmentsGetSegmentsRequest data model. Given input segment ids, return list of segments.
/// </summary>
typedef struct PFSegmentsGetSegmentsRequest
{
    /// <summary>
    /// Segment ids to filter title segments.
    /// </summary>
    _Field_size_(segmentIdsCount) const char* const* segmentIds;

    /// <summary>
    /// Count of segmentIds
    /// </summary>
    uint32_t segmentIdsCount;

} PFSegmentsGetSegmentsRequest;

/// <summary>
/// PFSegmentsGetSegmentsResponse data model.
/// </summary>
typedef struct PFSegmentsGetSegmentsResponse
{
    /// <summary>
    /// (Optional) Error message.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* errorMessage;

    /// <summary>
    /// (Optional) List of title segments.
    /// </summary>
    _Maybenull_ _Field_size_(segmentsCount) PFSegmentsSegmentModel const* const* segments;

    /// <summary>
    /// Count of segments
    /// </summary>
    uint32_t segmentsCount;

} PFSegmentsGetSegmentsResponse;

/// <summary>
/// PFSegmentsUpdateSegmentRequest data model. Update segment properties data which are planning to update.
/// </summary>
typedef struct PFSegmentsUpdateSegmentRequest
{
    /// <summary>
    /// Segment model with all of the segment properties data.
    /// </summary>
    PFSegmentsSegmentModel const* segmentModel;

} PFSegmentsUpdateSegmentRequest;

/// <summary>
/// PFSegmentsUpdateSegmentResponse data model.
/// </summary>
typedef struct PFSegmentsUpdateSegmentResponse
{
    /// <summary>
    /// (Optional) Error message.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* errorMessage;

    /// <summary>
    /// (Optional) Segment id.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* segmentId;

} PFSegmentsUpdateSegmentResponse;

#pragma pop_macro("IN")

}
