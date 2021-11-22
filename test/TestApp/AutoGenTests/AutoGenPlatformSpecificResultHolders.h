#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct ConsumeMicrosoftStoreEntitlementsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ConsumeMicrosoftStoreEntitlementsResponseHolder>
{
    ConsumeMicrosoftStoreEntitlementsResponseHolder() = default;
    ConsumeMicrosoftStoreEntitlementsResponseHolder(const ConsumeMicrosoftStoreEntitlementsResponseHolder&) = delete;
    ConsumeMicrosoftStoreEntitlementsResponseHolder(ConsumeMicrosoftStoreEntitlementsResponseHolder&&) = default;
    ConsumeMicrosoftStoreEntitlementsResponseHolder& operator=(const ConsumeMicrosoftStoreEntitlementsResponseHolder&) = delete;
    ConsumeMicrosoftStoreEntitlementsResponseHolder& operator=(ConsumeMicrosoftStoreEntitlementsResponseHolder&&) = default;
    ~ConsumeMicrosoftStoreEntitlementsResponseHolder() = default;

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse* result{ nullptr };
};

struct ConsumePS5EntitlementsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ConsumePS5EntitlementsResultHolder>
{
    ConsumePS5EntitlementsResultHolder() = default;
    ConsumePS5EntitlementsResultHolder(const ConsumePS5EntitlementsResultHolder&) = delete;
    ConsumePS5EntitlementsResultHolder(ConsumePS5EntitlementsResultHolder&&) = default;
    ConsumePS5EntitlementsResultHolder& operator=(const ConsumePS5EntitlementsResultHolder&) = delete;
    ConsumePS5EntitlementsResultHolder& operator=(ConsumePS5EntitlementsResultHolder&&) = default;
    ~ConsumePS5EntitlementsResultHolder() = default;

    PFPlatformSpecificConsumePS5EntitlementsResult* result{ nullptr };
};

struct ConsumePSNEntitlementsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ConsumePSNEntitlementsResultHolder>
{
    ConsumePSNEntitlementsResultHolder() = default;
    ConsumePSNEntitlementsResultHolder(const ConsumePSNEntitlementsResultHolder&) = delete;
    ConsumePSNEntitlementsResultHolder(ConsumePSNEntitlementsResultHolder&&) = default;
    ConsumePSNEntitlementsResultHolder& operator=(const ConsumePSNEntitlementsResultHolder&) = delete;
    ConsumePSNEntitlementsResultHolder& operator=(ConsumePSNEntitlementsResultHolder&&) = default;
    ~ConsumePSNEntitlementsResultHolder() = default;

    PFPlatformSpecificConsumePSNEntitlementsResult* result{ nullptr };
};

struct ConsumeXboxEntitlementsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ConsumeXboxEntitlementsResultHolder>
{
    ConsumeXboxEntitlementsResultHolder() = default;
    ConsumeXboxEntitlementsResultHolder(const ConsumeXboxEntitlementsResultHolder&) = delete;
    ConsumeXboxEntitlementsResultHolder(ConsumeXboxEntitlementsResultHolder&&) = default;
    ConsumeXboxEntitlementsResultHolder& operator=(const ConsumeXboxEntitlementsResultHolder&) = delete;
    ConsumeXboxEntitlementsResultHolder& operator=(ConsumeXboxEntitlementsResultHolder&&) = default;
    ~ConsumeXboxEntitlementsResultHolder() = default;

    PFPlatformSpecificConsumeXboxEntitlementsResult* result{ nullptr };
};

struct RestoreIOSPurchasesResultHolder : public XAsyncResult, public std::enable_shared_from_this<RestoreIOSPurchasesResultHolder>
{
    RestoreIOSPurchasesResultHolder() = default;
    RestoreIOSPurchasesResultHolder(const RestoreIOSPurchasesResultHolder&) = delete;
    RestoreIOSPurchasesResultHolder(RestoreIOSPurchasesResultHolder&&) = default;
    RestoreIOSPurchasesResultHolder& operator=(const RestoreIOSPurchasesResultHolder&) = delete;
    RestoreIOSPurchasesResultHolder& operator=(RestoreIOSPurchasesResultHolder&&) = default;
    ~RestoreIOSPurchasesResultHolder() = default;

    PFPlatformSpecificRestoreIOSPurchasesResult* result{ nullptr };
};

struct ValidateAmazonReceiptResultHolder : public XAsyncResult, public std::enable_shared_from_this<ValidateAmazonReceiptResultHolder>
{
    ValidateAmazonReceiptResultHolder() = default;
    ValidateAmazonReceiptResultHolder(const ValidateAmazonReceiptResultHolder&) = delete;
    ValidateAmazonReceiptResultHolder(ValidateAmazonReceiptResultHolder&&) = default;
    ValidateAmazonReceiptResultHolder& operator=(const ValidateAmazonReceiptResultHolder&) = delete;
    ValidateAmazonReceiptResultHolder& operator=(ValidateAmazonReceiptResultHolder&&) = default;
    ~ValidateAmazonReceiptResultHolder() = default;

    PFPlatformSpecificValidateAmazonReceiptResult* result{ nullptr };
};

struct ValidateGooglePlayPurchaseResultHolder : public XAsyncResult, public std::enable_shared_from_this<ValidateGooglePlayPurchaseResultHolder>
{
    ValidateGooglePlayPurchaseResultHolder() = default;
    ValidateGooglePlayPurchaseResultHolder(const ValidateGooglePlayPurchaseResultHolder&) = delete;
    ValidateGooglePlayPurchaseResultHolder(ValidateGooglePlayPurchaseResultHolder&&) = default;
    ValidateGooglePlayPurchaseResultHolder& operator=(const ValidateGooglePlayPurchaseResultHolder&) = delete;
    ValidateGooglePlayPurchaseResultHolder& operator=(ValidateGooglePlayPurchaseResultHolder&&) = default;
    ~ValidateGooglePlayPurchaseResultHolder() = default;

    PFPlatformSpecificValidateGooglePlayPurchaseResult* result{ nullptr };
};

struct ValidateIOSReceiptResultHolder : public XAsyncResult, public std::enable_shared_from_this<ValidateIOSReceiptResultHolder>
{
    ValidateIOSReceiptResultHolder() = default;
    ValidateIOSReceiptResultHolder(const ValidateIOSReceiptResultHolder&) = delete;
    ValidateIOSReceiptResultHolder(ValidateIOSReceiptResultHolder&&) = default;
    ValidateIOSReceiptResultHolder& operator=(const ValidateIOSReceiptResultHolder&) = delete;
    ValidateIOSReceiptResultHolder& operator=(ValidateIOSReceiptResultHolder&&) = default;
    ~ValidateIOSReceiptResultHolder() = default;

    PFPlatformSpecificValidateIOSReceiptResult* result{ nullptr };
};

struct ValidateWindowsReceiptResultHolder : public XAsyncResult, public std::enable_shared_from_this<ValidateWindowsReceiptResultHolder>
{
    ValidateWindowsReceiptResultHolder() = default;
    ValidateWindowsReceiptResultHolder(const ValidateWindowsReceiptResultHolder&) = delete;
    ValidateWindowsReceiptResultHolder(ValidateWindowsReceiptResultHolder&&) = default;
    ValidateWindowsReceiptResultHolder& operator=(const ValidateWindowsReceiptResultHolder&) = delete;
    ValidateWindowsReceiptResultHolder& operator=(ValidateWindowsReceiptResultHolder&&) = default;
    ~ValidateWindowsReceiptResultHolder() = default;

    PFPlatformSpecificValidateWindowsReceiptResult* result{ nullptr };
};

struct AwardSteamAchievementResultHolder : public XAsyncResult, public std::enable_shared_from_this<AwardSteamAchievementResultHolder>
{
    AwardSteamAchievementResultHolder() = default;
    AwardSteamAchievementResultHolder(const AwardSteamAchievementResultHolder&) = delete;
    AwardSteamAchievementResultHolder(AwardSteamAchievementResultHolder&&) = default;
    AwardSteamAchievementResultHolder& operator=(const AwardSteamAchievementResultHolder&) = delete;
    AwardSteamAchievementResultHolder& operator=(AwardSteamAchievementResultHolder&&) = default;
    ~AwardSteamAchievementResultHolder() = default;

    PFPlatformSpecificAwardSteamAchievementResult* result{ nullptr };
};


}
