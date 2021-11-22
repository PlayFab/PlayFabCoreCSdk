// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFPlayStreamDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamAddPlayerTagRequestWrapper : public ModelWrapper<PFPlayStreamAddPlayerTagRequest, Alloc>
{
public:
    using ModelType = typename PFPlayStreamAddPlayerTagRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamAddPlayerTagRequestWrapper() = default;

    PFPlayStreamAddPlayerTagRequestWrapper(const PFPlayStreamAddPlayerTagRequest& model) :
        ModelWrapper<PFPlayStreamAddPlayerTagRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_tagName{ SafeString(model.tagName) }
    {
        SetModelPointers();
    }

    PFPlayStreamAddPlayerTagRequestWrapper(const PFPlayStreamAddPlayerTagRequestWrapper& src) :
        PFPlayStreamAddPlayerTagRequestWrapper{ src.Model() }
    {
    }

    PFPlayStreamAddPlayerTagRequestWrapper(PFPlayStreamAddPlayerTagRequestWrapper&& src) :
        PFPlayStreamAddPlayerTagRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamAddPlayerTagRequestWrapper& operator=(PFPlayStreamAddPlayerTagRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamAddPlayerTagRequestWrapper() = default;

    friend void swap(PFPlayStreamAddPlayerTagRequestWrapper& lhs, PFPlayStreamAddPlayerTagRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_tagName, rhs.m_tagName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetTagName(String value)
    {
        m_tagName = std::move(value);
        this->m_model.tagName =  m_tagName.empty() ? nullptr : m_tagName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.tagName = m_tagName.empty() ? nullptr : m_tagName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_tagName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamGetSegmentResultWrapper : public ModelWrapper<PFPlayStreamGetSegmentResult, Alloc>
{
public:
    using ModelType = typename PFPlayStreamGetSegmentResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamGetSegmentResultWrapper() = default;

    PFPlayStreamGetSegmentResultWrapper(const PFPlayStreamGetSegmentResult& model) :
        ModelWrapper<PFPlayStreamGetSegmentResult, Alloc>{ model },
        m_aBTestParent{ SafeString(model.aBTestParent) },
        m_id{ SafeString(model.id) },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFPlayStreamGetSegmentResultWrapper(const PFPlayStreamGetSegmentResultWrapper& src) :
        PFPlayStreamGetSegmentResultWrapper{ src.Model() }
    {
    }

    PFPlayStreamGetSegmentResultWrapper(PFPlayStreamGetSegmentResultWrapper&& src) :
        PFPlayStreamGetSegmentResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamGetSegmentResultWrapper& operator=(PFPlayStreamGetSegmentResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamGetSegmentResultWrapper() = default;

    friend void swap(PFPlayStreamGetSegmentResultWrapper& lhs, PFPlayStreamGetSegmentResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aBTestParent, rhs.m_aBTestParent);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetABTestParent(String value)
    {
        m_aBTestParent = std::move(value);
        this->m_model.aBTestParent =  m_aBTestParent.empty() ? nullptr : m_aBTestParent.data();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.aBTestParent = m_aBTestParent.empty() ? nullptr : m_aBTestParent.data();
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    String m_aBTestParent;
    String m_id;
    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamGetAllSegmentsResultWrapper : public ModelWrapper<PFPlayStreamGetAllSegmentsResult, Alloc>
{
public:
    using ModelType = typename PFPlayStreamGetAllSegmentsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamGetAllSegmentsResultWrapper() = default;

    PFPlayStreamGetAllSegmentsResultWrapper(const PFPlayStreamGetAllSegmentsResult& model) :
        ModelWrapper<PFPlayStreamGetAllSegmentsResult, Alloc>{ model },
        m_segments{ model.segments, model.segments + model.segmentsCount }
    {
        SetModelPointers();
    }

    PFPlayStreamGetAllSegmentsResultWrapper(const PFPlayStreamGetAllSegmentsResultWrapper& src) :
        PFPlayStreamGetAllSegmentsResultWrapper{ src.Model() }
    {
    }

    PFPlayStreamGetAllSegmentsResultWrapper(PFPlayStreamGetAllSegmentsResultWrapper&& src) :
        PFPlayStreamGetAllSegmentsResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamGetAllSegmentsResultWrapper& operator=(PFPlayStreamGetAllSegmentsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamGetAllSegmentsResultWrapper() = default;

    friend void swap(PFPlayStreamGetAllSegmentsResultWrapper& lhs, PFPlayStreamGetAllSegmentsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_segments, rhs.m_segments);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSegments(ModelVector<PFPlayStreamGetSegmentResultWrapper<Alloc>, Alloc> value)
    {
        m_segments = std::move(value);
        this->m_model.segments =  m_segments.empty() ? nullptr : m_segments.data();
        this->m_model.segmentsCount =  static_cast<uint32_t>(m_segments.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.segments = m_segments.empty() ? nullptr : m_segments.data();
    }

    ModelVector<PFPlayStreamGetSegmentResultWrapper<Alloc>, Alloc> m_segments;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamGetPlayersSegmentsRequestWrapper : public ModelWrapper<PFPlayStreamGetPlayersSegmentsRequest, Alloc>
{
public:
    using ModelType = typename PFPlayStreamGetPlayersSegmentsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamGetPlayersSegmentsRequestWrapper() = default;

    PFPlayStreamGetPlayersSegmentsRequestWrapper(const PFPlayStreamGetPlayersSegmentsRequest& model) :
        ModelWrapper<PFPlayStreamGetPlayersSegmentsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayStreamGetPlayersSegmentsRequestWrapper(const PFPlayStreamGetPlayersSegmentsRequestWrapper& src) :
        PFPlayStreamGetPlayersSegmentsRequestWrapper{ src.Model() }
    {
    }

    PFPlayStreamGetPlayersSegmentsRequestWrapper(PFPlayStreamGetPlayersSegmentsRequestWrapper&& src) :
        PFPlayStreamGetPlayersSegmentsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamGetPlayersSegmentsRequestWrapper& operator=(PFPlayStreamGetPlayersSegmentsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamGetPlayersSegmentsRequestWrapper() = default;

    friend void swap(PFPlayStreamGetPlayersSegmentsRequestWrapper& lhs, PFPlayStreamGetPlayersSegmentsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamGetPlayerSegmentsResultWrapper : public ModelWrapper<PFPlayStreamGetPlayerSegmentsResult, Alloc>
{
public:
    using ModelType = typename PFPlayStreamGetPlayerSegmentsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamGetPlayerSegmentsResultWrapper() = default;

    PFPlayStreamGetPlayerSegmentsResultWrapper(const PFPlayStreamGetPlayerSegmentsResult& model) :
        ModelWrapper<PFPlayStreamGetPlayerSegmentsResult, Alloc>{ model },
        m_segments{ model.segments, model.segments + model.segmentsCount }
    {
        SetModelPointers();
    }

    PFPlayStreamGetPlayerSegmentsResultWrapper(const PFPlayStreamGetPlayerSegmentsResultWrapper& src) :
        PFPlayStreamGetPlayerSegmentsResultWrapper{ src.Model() }
    {
    }

    PFPlayStreamGetPlayerSegmentsResultWrapper(PFPlayStreamGetPlayerSegmentsResultWrapper&& src) :
        PFPlayStreamGetPlayerSegmentsResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamGetPlayerSegmentsResultWrapper& operator=(PFPlayStreamGetPlayerSegmentsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamGetPlayerSegmentsResultWrapper() = default;

    friend void swap(PFPlayStreamGetPlayerSegmentsResultWrapper& lhs, PFPlayStreamGetPlayerSegmentsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_segments, rhs.m_segments);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSegments(ModelVector<PFPlayStreamGetSegmentResultWrapper<Alloc>, Alloc> value)
    {
        m_segments = std::move(value);
        this->m_model.segments =  m_segments.empty() ? nullptr : m_segments.data();
        this->m_model.segmentsCount =  static_cast<uint32_t>(m_segments.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.segments = m_segments.empty() ? nullptr : m_segments.data();
    }

    ModelVector<PFPlayStreamGetSegmentResultWrapper<Alloc>, Alloc> m_segments;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamGetPlayersInSegmentRequestWrapper : public ModelWrapper<PFPlayStreamGetPlayersInSegmentRequest, Alloc>
{
public:
    using ModelType = typename PFPlayStreamGetPlayersInSegmentRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamGetPlayersInSegmentRequestWrapper() = default;

    PFPlayStreamGetPlayersInSegmentRequestWrapper(const PFPlayStreamGetPlayersInSegmentRequest& model) :
        ModelWrapper<PFPlayStreamGetPlayersInSegmentRequest, Alloc>{ model },
        m_continuationToken{ SafeString(model.continuationToken) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_maxBatchSize{ model.maxBatchSize ? StdExtra::optional<uint32_t>{ *model.maxBatchSize } : StdExtra::nullopt },
        m_secondsToLive{ model.secondsToLive ? StdExtra::optional<uint32_t>{ *model.secondsToLive } : StdExtra::nullopt },
        m_segmentId{ SafeString(model.segmentId) }
    {
        SetModelPointers();
    }

    PFPlayStreamGetPlayersInSegmentRequestWrapper(const PFPlayStreamGetPlayersInSegmentRequestWrapper& src) :
        PFPlayStreamGetPlayersInSegmentRequestWrapper{ src.Model() }
    {
    }

    PFPlayStreamGetPlayersInSegmentRequestWrapper(PFPlayStreamGetPlayersInSegmentRequestWrapper&& src) :
        PFPlayStreamGetPlayersInSegmentRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamGetPlayersInSegmentRequestWrapper& operator=(PFPlayStreamGetPlayersInSegmentRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamGetPlayersInSegmentRequestWrapper() = default;

    friend void swap(PFPlayStreamGetPlayersInSegmentRequestWrapper& lhs, PFPlayStreamGetPlayersInSegmentRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_continuationToken, rhs.m_continuationToken);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_maxBatchSize, rhs.m_maxBatchSize);
        swap(lhs.m_secondsToLive, rhs.m_secondsToLive);
        swap(lhs.m_segmentId, rhs.m_segmentId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContinuationToken(String value)
    {
        m_continuationToken = std::move(value);
        this->m_model.continuationToken =  m_continuationToken.empty() ? nullptr : m_continuationToken.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMaxBatchSize(StdExtra::optional<uint32_t> value)
    {
        m_maxBatchSize = std::move(value);
        this->m_model.maxBatchSize = m_maxBatchSize ? m_maxBatchSize.operator->() : nullptr;
    }

    void SetSecondsToLive(StdExtra::optional<uint32_t> value)
    {
        m_secondsToLive = std::move(value);
        this->m_model.secondsToLive = m_secondsToLive ? m_secondsToLive.operator->() : nullptr;
    }

    void SetSegmentId(String value)
    {
        m_segmentId = std::move(value);
        this->m_model.segmentId =  m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.continuationToken = m_continuationToken.empty() ? nullptr : m_continuationToken.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.maxBatchSize = m_maxBatchSize ? m_maxBatchSize.operator->() : nullptr;
        this->m_model.secondsToLive = m_secondsToLive ? m_secondsToLive.operator->() : nullptr;
        this->m_model.segmentId = m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

    String m_continuationToken;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<uint32_t> m_maxBatchSize;
    StdExtra::optional<uint32_t> m_secondsToLive;
    String m_segmentId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamAdCampaignAttributionWrapper : public ModelWrapper<PFPlayStreamAdCampaignAttribution, Alloc>
{
public:
    using ModelType = typename PFPlayStreamAdCampaignAttribution;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamAdCampaignAttributionWrapper() = default;

    PFPlayStreamAdCampaignAttributionWrapper(const PFPlayStreamAdCampaignAttribution& model) :
        ModelWrapper<PFPlayStreamAdCampaignAttribution, Alloc>{ model },
        m_campaignId{ SafeString(model.campaignId) },
        m_platform{ SafeString(model.platform) }
    {
        SetModelPointers();
    }

    PFPlayStreamAdCampaignAttributionWrapper(const PFPlayStreamAdCampaignAttributionWrapper& src) :
        PFPlayStreamAdCampaignAttributionWrapper{ src.Model() }
    {
    }

    PFPlayStreamAdCampaignAttributionWrapper(PFPlayStreamAdCampaignAttributionWrapper&& src) :
        PFPlayStreamAdCampaignAttributionWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamAdCampaignAttributionWrapper& operator=(PFPlayStreamAdCampaignAttributionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamAdCampaignAttributionWrapper() = default;

    friend void swap(PFPlayStreamAdCampaignAttributionWrapper& lhs, PFPlayStreamAdCampaignAttributionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_campaignId, rhs.m_campaignId);
        swap(lhs.m_platform, rhs.m_platform);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAttributedAt(time_t value)
    {
        this->m_model.attributedAt = value;
    }

    void SetCampaignId(String value)
    {
        m_campaignId = std::move(value);
        this->m_model.campaignId =  m_campaignId.empty() ? nullptr : m_campaignId.data();
    }

    void SetPlatform(String value)
    {
        m_platform = std::move(value);
        this->m_model.platform =  m_platform.empty() ? nullptr : m_platform.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.campaignId = m_campaignId.empty() ? nullptr : m_campaignId.data();
        this->m_model.platform = m_platform.empty() ? nullptr : m_platform.data();
    }

    String m_campaignId;
    String m_platform;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamContactEmailInfoWrapper : public ModelWrapper<PFPlayStreamContactEmailInfo, Alloc>
{
public:
    using ModelType = typename PFPlayStreamContactEmailInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamContactEmailInfoWrapper() = default;

    PFPlayStreamContactEmailInfoWrapper(const PFPlayStreamContactEmailInfo& model) :
        ModelWrapper<PFPlayStreamContactEmailInfo, Alloc>{ model },
        m_emailAddress{ SafeString(model.emailAddress) },
        m_name{ SafeString(model.name) },
        m_verificationStatus{ model.verificationStatus ? StdExtra::optional<PFEmailVerificationStatus>{ *model.verificationStatus } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayStreamContactEmailInfoWrapper(const PFPlayStreamContactEmailInfoWrapper& src) :
        PFPlayStreamContactEmailInfoWrapper{ src.Model() }
    {
    }

    PFPlayStreamContactEmailInfoWrapper(PFPlayStreamContactEmailInfoWrapper&& src) :
        PFPlayStreamContactEmailInfoWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamContactEmailInfoWrapper& operator=(PFPlayStreamContactEmailInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamContactEmailInfoWrapper() = default;

    friend void swap(PFPlayStreamContactEmailInfoWrapper& lhs, PFPlayStreamContactEmailInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_emailAddress, rhs.m_emailAddress);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_verificationStatus, rhs.m_verificationStatus);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEmailAddress(String value)
    {
        m_emailAddress = std::move(value);
        this->m_model.emailAddress =  m_emailAddress.empty() ? nullptr : m_emailAddress.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetVerificationStatus(StdExtra::optional<PFEmailVerificationStatus> value)
    {
        m_verificationStatus = std::move(value);
        this->m_model.verificationStatus = m_verificationStatus ? m_verificationStatus.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.emailAddress = m_emailAddress.empty() ? nullptr : m_emailAddress.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.verificationStatus = m_verificationStatus ? m_verificationStatus.operator->() : nullptr;
    }

    String m_emailAddress;
    String m_name;
    StdExtra::optional<PFEmailVerificationStatus> m_verificationStatus;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamPlayerLinkedAccountWrapper : public ModelWrapper<PFPlayStreamPlayerLinkedAccount, Alloc>
{
public:
    using ModelType = typename PFPlayStreamPlayerLinkedAccount;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamPlayerLinkedAccountWrapper() = default;

    PFPlayStreamPlayerLinkedAccountWrapper(const PFPlayStreamPlayerLinkedAccount& model) :
        ModelWrapper<PFPlayStreamPlayerLinkedAccount, Alloc>{ model },
        m_email{ SafeString(model.email) },
        m_platform{ model.platform ? StdExtra::optional<PFLoginIdentityProvider>{ *model.platform } : StdExtra::nullopt },
        m_platformUserId{ SafeString(model.platformUserId) },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFPlayStreamPlayerLinkedAccountWrapper(const PFPlayStreamPlayerLinkedAccountWrapper& src) :
        PFPlayStreamPlayerLinkedAccountWrapper{ src.Model() }
    {
    }

    PFPlayStreamPlayerLinkedAccountWrapper(PFPlayStreamPlayerLinkedAccountWrapper&& src) :
        PFPlayStreamPlayerLinkedAccountWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamPlayerLinkedAccountWrapper& operator=(PFPlayStreamPlayerLinkedAccountWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamPlayerLinkedAccountWrapper() = default;

    friend void swap(PFPlayStreamPlayerLinkedAccountWrapper& lhs, PFPlayStreamPlayerLinkedAccountWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_email, rhs.m_email);
        swap(lhs.m_platform, rhs.m_platform);
        swap(lhs.m_platformUserId, rhs.m_platformUserId);
        swap(lhs.m_username, rhs.m_username);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEmail(String value)
    {
        m_email = std::move(value);
        this->m_model.email =  m_email.empty() ? nullptr : m_email.data();
    }

    void SetPlatform(StdExtra::optional<PFLoginIdentityProvider> value)
    {
        m_platform = std::move(value);
        this->m_model.platform = m_platform ? m_platform.operator->() : nullptr;
    }

    void SetPlatformUserId(String value)
    {
        m_platformUserId = std::move(value);
        this->m_model.platformUserId =  m_platformUserId.empty() ? nullptr : m_platformUserId.data();
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.email = m_email.empty() ? nullptr : m_email.data();
        this->m_model.platform = m_platform ? m_platform.operator->() : nullptr;
        this->m_model.platformUserId = m_platformUserId.empty() ? nullptr : m_platformUserId.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
    }

    String m_email;
    StdExtra::optional<PFLoginIdentityProvider> m_platform;
    String m_platformUserId;
    String m_username;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamPlayerLocationWrapper : public ModelWrapper<PFPlayStreamPlayerLocation, Alloc>
{
public:
    using ModelType = typename PFPlayStreamPlayerLocation;
    using DictionaryEntryType = typename PFPlayStreamPlayerLocationDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamPlayerLocationWrapper() = default;

    PFPlayStreamPlayerLocationWrapper(const PFPlayStreamPlayerLocation& model) :
        ModelWrapper<PFPlayStreamPlayerLocation, Alloc>{ model },
        m_city{ SafeString(model.city) },
        m_latitude{ model.latitude ? StdExtra::optional<double>{ *model.latitude } : StdExtra::nullopt },
        m_longitude{ model.longitude ? StdExtra::optional<double>{ *model.longitude } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayStreamPlayerLocationWrapper(const PFPlayStreamPlayerLocationWrapper& src) :
        PFPlayStreamPlayerLocationWrapper{ src.Model() }
    {
    }

    PFPlayStreamPlayerLocationWrapper(PFPlayStreamPlayerLocationWrapper&& src) :
        PFPlayStreamPlayerLocationWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamPlayerLocationWrapper& operator=(PFPlayStreamPlayerLocationWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamPlayerLocationWrapper() = default;

    friend void swap(PFPlayStreamPlayerLocationWrapper& lhs, PFPlayStreamPlayerLocationWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_city, rhs.m_city);
        swap(lhs.m_latitude, rhs.m_latitude);
        swap(lhs.m_longitude, rhs.m_longitude);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCity(String value)
    {
        m_city = std::move(value);
        this->m_model.city =  m_city.empty() ? nullptr : m_city.data();
    }

    void SetContinentCode(PFContinentCode value)
    {
        this->m_model.continentCode = value;
    }

    void SetCountryCode(PFCountryCode value)
    {
        this->m_model.countryCode = value;
    }

    void SetLatitude(StdExtra::optional<double> value)
    {
        m_latitude = std::move(value);
        this->m_model.latitude = m_latitude ? m_latitude.operator->() : nullptr;
    }

    void SetLongitude(StdExtra::optional<double> value)
    {
        m_longitude = std::move(value);
        this->m_model.longitude = m_longitude ? m_longitude.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.city = m_city.empty() ? nullptr : m_city.data();
        this->m_model.latitude = m_latitude ? m_latitude.operator->() : nullptr;
        this->m_model.longitude = m_longitude ? m_longitude.operator->() : nullptr;
    }

    String m_city;
    StdExtra::optional<double> m_latitude;
    StdExtra::optional<double> m_longitude;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamPlayerStatisticWrapper : public ModelWrapper<PFPlayStreamPlayerStatistic, Alloc>
{
public:
    using ModelType = typename PFPlayStreamPlayerStatistic;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamPlayerStatisticWrapper() = default;

    PFPlayStreamPlayerStatisticWrapper(const PFPlayStreamPlayerStatistic& model) :
        ModelWrapper<PFPlayStreamPlayerStatistic, Alloc>{ model },
        m_id{ SafeString(model.id) },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFPlayStreamPlayerStatisticWrapper(const PFPlayStreamPlayerStatisticWrapper& src) :
        PFPlayStreamPlayerStatisticWrapper{ src.Model() }
    {
    }

    PFPlayStreamPlayerStatisticWrapper(PFPlayStreamPlayerStatisticWrapper&& src) :
        PFPlayStreamPlayerStatisticWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamPlayerStatisticWrapper& operator=(PFPlayStreamPlayerStatisticWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamPlayerStatisticWrapper() = default;

    friend void swap(PFPlayStreamPlayerStatisticWrapper& lhs, PFPlayStreamPlayerStatisticWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetStatisticValue(int32_t value)
    {
        this->m_model.statisticValue = value;
    }

    void SetStatisticVersion(int32_t value)
    {
        this->m_model.statisticVersion = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    String m_id;
    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamPushNotificationRegistrationWrapper : public ModelWrapper<PFPlayStreamPushNotificationRegistration, Alloc>
{
public:
    using ModelType = typename PFPlayStreamPushNotificationRegistration;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamPushNotificationRegistrationWrapper() = default;

    PFPlayStreamPushNotificationRegistrationWrapper(const PFPlayStreamPushNotificationRegistration& model) :
        ModelWrapper<PFPlayStreamPushNotificationRegistration, Alloc>{ model },
        m_notificationEndpointARN{ SafeString(model.notificationEndpointARN) },
        m_platform{ model.platform ? StdExtra::optional<PFPushNotificationPlatform>{ *model.platform } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayStreamPushNotificationRegistrationWrapper(const PFPlayStreamPushNotificationRegistrationWrapper& src) :
        PFPlayStreamPushNotificationRegistrationWrapper{ src.Model() }
    {
    }

    PFPlayStreamPushNotificationRegistrationWrapper(PFPlayStreamPushNotificationRegistrationWrapper&& src) :
        PFPlayStreamPushNotificationRegistrationWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamPushNotificationRegistrationWrapper& operator=(PFPlayStreamPushNotificationRegistrationWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamPushNotificationRegistrationWrapper() = default;

    friend void swap(PFPlayStreamPushNotificationRegistrationWrapper& lhs, PFPlayStreamPushNotificationRegistrationWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_notificationEndpointARN, rhs.m_notificationEndpointARN);
        swap(lhs.m_platform, rhs.m_platform);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetNotificationEndpointARN(String value)
    {
        m_notificationEndpointARN = std::move(value);
        this->m_model.notificationEndpointARN =  m_notificationEndpointARN.empty() ? nullptr : m_notificationEndpointARN.data();
    }

    void SetPlatform(StdExtra::optional<PFPushNotificationPlatform> value)
    {
        m_platform = std::move(value);
        this->m_model.platform = m_platform ? m_platform.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.notificationEndpointARN = m_notificationEndpointARN.empty() ? nullptr : m_notificationEndpointARN.data();
        this->m_model.platform = m_platform ? m_platform.operator->() : nullptr;
    }

    String m_notificationEndpointARN;
    StdExtra::optional<PFPushNotificationPlatform> m_platform;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamPlayerProfileWrapper : public ModelWrapper<PFPlayStreamPlayerProfile, Alloc>
{
public:
    using ModelType = typename PFPlayStreamPlayerProfile;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamPlayerProfileWrapper() = default;

    PFPlayStreamPlayerProfileWrapper(const PFPlayStreamPlayerProfile& model) :
        ModelWrapper<PFPlayStreamPlayerProfile, Alloc>{ model },
        m_adCampaignAttributions{ model.adCampaignAttributions, model.adCampaignAttributions + model.adCampaignAttributionsCount },
        m_avatarUrl{ SafeString(model.avatarUrl) },
        m_bannedUntil{ model.bannedUntil ? StdExtra::optional<time_t>{ *model.bannedUntil } : StdExtra::nullopt },
        m_contactEmailAddresses{ model.contactEmailAddresses, model.contactEmailAddresses + model.contactEmailAddressesCount },
        m_created{ model.created ? StdExtra::optional<time_t>{ *model.created } : StdExtra::nullopt },
        m_displayName{ SafeString(model.displayName) },
        m_lastLogin{ model.lastLogin ? StdExtra::optional<time_t>{ *model.lastLogin } : StdExtra::nullopt },
        m_linkedAccounts{ model.linkedAccounts, model.linkedAccounts + model.linkedAccountsCount },
        m_locations{ model.locations, model.locations + model.locationsCount },
        m_origination{ model.origination ? StdExtra::optional<PFLoginIdentityProvider>{ *model.origination } : StdExtra::nullopt },
        m_playerExperimentVariants{ model.playerExperimentVariants, model.playerExperimentVariants + model.playerExperimentVariantsCount },
        m_playerId{ SafeString(model.playerId) },
        m_playerStatistics{ model.playerStatistics, model.playerStatistics + model.playerStatisticsCount },
        m_publisherId{ SafeString(model.publisherId) },
        m_pushNotificationRegistrations{ model.pushNotificationRegistrations, model.pushNotificationRegistrations + model.pushNotificationRegistrationsCount },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount },
        m_tags{ model.tags, model.tags + model.tagsCount },
        m_titleId{ SafeString(model.titleId) },
        m_totalValueToDateInUSD{ model.totalValueToDateInUSD ? StdExtra::optional<uint32_t>{ *model.totalValueToDateInUSD } : StdExtra::nullopt },
        m_valuesToDate{ model.valuesToDate, model.valuesToDate + model.valuesToDateCount },
        m_virtualCurrencyBalances{ model.virtualCurrencyBalances, model.virtualCurrencyBalances + model.virtualCurrencyBalancesCount }
    {
        SetModelPointers();
    }

    PFPlayStreamPlayerProfileWrapper(const PFPlayStreamPlayerProfileWrapper& src) :
        PFPlayStreamPlayerProfileWrapper{ src.Model() }
    {
    }

    PFPlayStreamPlayerProfileWrapper(PFPlayStreamPlayerProfileWrapper&& src) :
        PFPlayStreamPlayerProfileWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamPlayerProfileWrapper& operator=(PFPlayStreamPlayerProfileWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamPlayerProfileWrapper() = default;

    friend void swap(PFPlayStreamPlayerProfileWrapper& lhs, PFPlayStreamPlayerProfileWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_adCampaignAttributions, rhs.m_adCampaignAttributions);
        swap(lhs.m_avatarUrl, rhs.m_avatarUrl);
        swap(lhs.m_bannedUntil, rhs.m_bannedUntil);
        swap(lhs.m_contactEmailAddresses, rhs.m_contactEmailAddresses);
        swap(lhs.m_created, rhs.m_created);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_lastLogin, rhs.m_lastLogin);
        swap(lhs.m_linkedAccounts, rhs.m_linkedAccounts);
        swap(lhs.m_locations, rhs.m_locations);
        swap(lhs.m_origination, rhs.m_origination);
        swap(lhs.m_playerExperimentVariants, rhs.m_playerExperimentVariants);
        swap(lhs.m_playerId, rhs.m_playerId);
        swap(lhs.m_playerStatistics, rhs.m_playerStatistics);
        swap(lhs.m_publisherId, rhs.m_publisherId);
        swap(lhs.m_pushNotificationRegistrations, rhs.m_pushNotificationRegistrations);
        swap(lhs.m_statistics, rhs.m_statistics);
        swap(lhs.m_tags, rhs.m_tags);
        swap(lhs.m_titleId, rhs.m_titleId);
        swap(lhs.m_totalValueToDateInUSD, rhs.m_totalValueToDateInUSD);
        swap(lhs.m_valuesToDate, rhs.m_valuesToDate);
        swap(lhs.m_virtualCurrencyBalances, rhs.m_virtualCurrencyBalances);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAdCampaignAttributions(ModelVector<PFPlayStreamAdCampaignAttributionWrapper<Alloc>, Alloc> value)
    {
        m_adCampaignAttributions = std::move(value);
        this->m_model.adCampaignAttributions =  m_adCampaignAttributions.empty() ? nullptr : m_adCampaignAttributions.data();
        this->m_model.adCampaignAttributionsCount =  static_cast<uint32_t>(m_adCampaignAttributions.size());
    }

    void SetAvatarUrl(String value)
    {
        m_avatarUrl = std::move(value);
        this->m_model.avatarUrl =  m_avatarUrl.empty() ? nullptr : m_avatarUrl.data();
    }

    void SetBannedUntil(StdExtra::optional<time_t> value)
    {
        m_bannedUntil = std::move(value);
        this->m_model.bannedUntil = m_bannedUntil ? m_bannedUntil.operator->() : nullptr;
    }

    void SetContactEmailAddresses(ModelVector<PFPlayStreamContactEmailInfoWrapper<Alloc>, Alloc> value)
    {
        m_contactEmailAddresses = std::move(value);
        this->m_model.contactEmailAddresses =  m_contactEmailAddresses.empty() ? nullptr : m_contactEmailAddresses.data();
        this->m_model.contactEmailAddressesCount =  static_cast<uint32_t>(m_contactEmailAddresses.size());
    }

    void SetCreated(StdExtra::optional<time_t> value)
    {
        m_created = std::move(value);
        this->m_model.created = m_created ? m_created.operator->() : nullptr;
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

    void SetLastLogin(StdExtra::optional<time_t> value)
    {
        m_lastLogin = std::move(value);
        this->m_model.lastLogin = m_lastLogin ? m_lastLogin.operator->() : nullptr;
    }

    void SetLinkedAccounts(ModelVector<PFPlayStreamPlayerLinkedAccountWrapper<Alloc>, Alloc> value)
    {
        m_linkedAccounts = std::move(value);
        this->m_model.linkedAccounts =  m_linkedAccounts.empty() ? nullptr : m_linkedAccounts.data();
        this->m_model.linkedAccountsCount =  static_cast<uint32_t>(m_linkedAccounts.size());
    }

    void SetLocations(ModelDictionaryEntryVector<PFPlayStreamPlayerLocationWrapper<Alloc>, Alloc> value)
    {
        m_locations = std::move(value);
        this->m_model.locations =  m_locations.empty() ? nullptr : m_locations.data();
        this->m_model.locationsCount =  static_cast<uint32_t>(m_locations.size());
    }

    void SetOrigination(StdExtra::optional<PFLoginIdentityProvider> value)
    {
        m_origination = std::move(value);
        this->m_model.origination = m_origination ? m_origination.operator->() : nullptr;
    }

    void SetPlayerExperimentVariants(CStringVector<Alloc> value)
    {
        m_playerExperimentVariants = std::move(value);
        this->m_model.playerExperimentVariants =  m_playerExperimentVariants.empty() ? nullptr : m_playerExperimentVariants.data();
        this->m_model.playerExperimentVariantsCount =  static_cast<uint32_t>(m_playerExperimentVariants.size());
    }

    void SetPlayerId(String value)
    {
        m_playerId = std::move(value);
        this->m_model.playerId =  m_playerId.empty() ? nullptr : m_playerId.data();
    }

    void SetPlayerStatistics(ModelVector<PFPlayStreamPlayerStatisticWrapper<Alloc>, Alloc> value)
    {
        m_playerStatistics = std::move(value);
        this->m_model.playerStatistics =  m_playerStatistics.empty() ? nullptr : m_playerStatistics.data();
        this->m_model.playerStatisticsCount =  static_cast<uint32_t>(m_playerStatistics.size());
    }

    void SetPublisherId(String value)
    {
        m_publisherId = std::move(value);
        this->m_model.publisherId =  m_publisherId.empty() ? nullptr : m_publisherId.data();
    }

    void SetPushNotificationRegistrations(ModelVector<PFPlayStreamPushNotificationRegistrationWrapper<Alloc>, Alloc> value)
    {
        m_pushNotificationRegistrations = std::move(value);
        this->m_model.pushNotificationRegistrations =  m_pushNotificationRegistrations.empty() ? nullptr : m_pushNotificationRegistrations.data();
        this->m_model.pushNotificationRegistrationsCount =  static_cast<uint32_t>(m_pushNotificationRegistrations.size());
    }

    void SetStatistics(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_statistics = std::move(value);
        this->m_model.statistics =  m_statistics.empty() ? nullptr : m_statistics.data();
        this->m_model.statisticsCount =  static_cast<uint32_t>(m_statistics.size());
    }

    void SetTags(CStringVector<Alloc> value)
    {
        m_tags = std::move(value);
        this->m_model.tags =  m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.tagsCount =  static_cast<uint32_t>(m_tags.size());
    }

    void SetTitleId(String value)
    {
        m_titleId = std::move(value);
        this->m_model.titleId =  m_titleId.empty() ? nullptr : m_titleId.data();
    }

    void SetTotalValueToDateInUSD(StdExtra::optional<uint32_t> value)
    {
        m_totalValueToDateInUSD = std::move(value);
        this->m_model.totalValueToDateInUSD = m_totalValueToDateInUSD ? m_totalValueToDateInUSD.operator->() : nullptr;
    }

    void SetValuesToDate(DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> value)
    {
        m_valuesToDate = std::move(value);
        this->m_model.valuesToDate =  m_valuesToDate.empty() ? nullptr : m_valuesToDate.data();
        this->m_model.valuesToDateCount =  static_cast<uint32_t>(m_valuesToDate.size());
    }

    void SetVirtualCurrencyBalances(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrencyBalances = std::move(value);
        this->m_model.virtualCurrencyBalances =  m_virtualCurrencyBalances.empty() ? nullptr : m_virtualCurrencyBalances.data();
        this->m_model.virtualCurrencyBalancesCount =  static_cast<uint32_t>(m_virtualCurrencyBalances.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.adCampaignAttributions = m_adCampaignAttributions.empty() ? nullptr : m_adCampaignAttributions.data();
        this->m_model.avatarUrl = m_avatarUrl.empty() ? nullptr : m_avatarUrl.data();
        this->m_model.bannedUntil = m_bannedUntil ? m_bannedUntil.operator->() : nullptr;
        this->m_model.contactEmailAddresses = m_contactEmailAddresses.empty() ? nullptr : m_contactEmailAddresses.data();
        this->m_model.created = m_created ? m_created.operator->() : nullptr;
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.lastLogin = m_lastLogin ? m_lastLogin.operator->() : nullptr;
        this->m_model.linkedAccounts = m_linkedAccounts.empty() ? nullptr : m_linkedAccounts.data();
        this->m_model.locations = m_locations.empty() ? nullptr : m_locations.data();
        this->m_model.origination = m_origination ? m_origination.operator->() : nullptr;
        this->m_model.playerExperimentVariants = m_playerExperimentVariants.empty() ? nullptr : m_playerExperimentVariants.data();
        this->m_model.playerId = m_playerId.empty() ? nullptr : m_playerId.data();
        this->m_model.playerStatistics = m_playerStatistics.empty() ? nullptr : m_playerStatistics.data();
        this->m_model.publisherId = m_publisherId.empty() ? nullptr : m_publisherId.data();
        this->m_model.pushNotificationRegistrations = m_pushNotificationRegistrations.empty() ? nullptr : m_pushNotificationRegistrations.data();
        this->m_model.statistics = m_statistics.empty() ? nullptr : m_statistics.data();
        this->m_model.tags = m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
        this->m_model.totalValueToDateInUSD = m_totalValueToDateInUSD ? m_totalValueToDateInUSD.operator->() : nullptr;
        this->m_model.valuesToDate = m_valuesToDate.empty() ? nullptr : m_valuesToDate.data();
        this->m_model.virtualCurrencyBalances = m_virtualCurrencyBalances.empty() ? nullptr : m_virtualCurrencyBalances.data();
    }

    ModelVector<PFPlayStreamAdCampaignAttributionWrapper<Alloc>, Alloc> m_adCampaignAttributions;
    String m_avatarUrl;
    StdExtra::optional<time_t> m_bannedUntil;
    ModelVector<PFPlayStreamContactEmailInfoWrapper<Alloc>, Alloc> m_contactEmailAddresses;
    StdExtra::optional<time_t> m_created;
    String m_displayName;
    StdExtra::optional<time_t> m_lastLogin;
    ModelVector<PFPlayStreamPlayerLinkedAccountWrapper<Alloc>, Alloc> m_linkedAccounts;
    ModelDictionaryEntryVector<PFPlayStreamPlayerLocationWrapper<Alloc>, Alloc> m_locations;
    StdExtra::optional<PFLoginIdentityProvider> m_origination;
    CStringVector<Alloc> m_playerExperimentVariants;
    String m_playerId;
    ModelVector<PFPlayStreamPlayerStatisticWrapper<Alloc>, Alloc> m_playerStatistics;
    String m_publisherId;
    ModelVector<PFPlayStreamPushNotificationRegistrationWrapper<Alloc>, Alloc> m_pushNotificationRegistrations;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_statistics;
    CStringVector<Alloc> m_tags;
    String m_titleId;
    StdExtra::optional<uint32_t> m_totalValueToDateInUSD;
    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_valuesToDate;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_virtualCurrencyBalances;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamGetPlayersInSegmentResultWrapper : public ModelWrapper<PFPlayStreamGetPlayersInSegmentResult, Alloc>
{
public:
    using ModelType = typename PFPlayStreamGetPlayersInSegmentResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamGetPlayersInSegmentResultWrapper() = default;

    PFPlayStreamGetPlayersInSegmentResultWrapper(const PFPlayStreamGetPlayersInSegmentResult& model) :
        ModelWrapper<PFPlayStreamGetPlayersInSegmentResult, Alloc>{ model },
        m_continuationToken{ SafeString(model.continuationToken) },
        m_playerProfiles{ model.playerProfiles, model.playerProfiles + model.playerProfilesCount }
    {
        SetModelPointers();
    }

    PFPlayStreamGetPlayersInSegmentResultWrapper(const PFPlayStreamGetPlayersInSegmentResultWrapper& src) :
        PFPlayStreamGetPlayersInSegmentResultWrapper{ src.Model() }
    {
    }

    PFPlayStreamGetPlayersInSegmentResultWrapper(PFPlayStreamGetPlayersInSegmentResultWrapper&& src) :
        PFPlayStreamGetPlayersInSegmentResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamGetPlayersInSegmentResultWrapper& operator=(PFPlayStreamGetPlayersInSegmentResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamGetPlayersInSegmentResultWrapper() = default;

    friend void swap(PFPlayStreamGetPlayersInSegmentResultWrapper& lhs, PFPlayStreamGetPlayersInSegmentResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_continuationToken, rhs.m_continuationToken);
        swap(lhs.m_playerProfiles, rhs.m_playerProfiles);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContinuationToken(String value)
    {
        m_continuationToken = std::move(value);
        this->m_model.continuationToken =  m_continuationToken.empty() ? nullptr : m_continuationToken.data();
    }

    void SetPlayerProfiles(ModelVector<PFPlayStreamPlayerProfileWrapper<Alloc>, Alloc> value)
    {
        m_playerProfiles = std::move(value);
        this->m_model.playerProfiles =  m_playerProfiles.empty() ? nullptr : m_playerProfiles.data();
        this->m_model.playerProfilesCount =  static_cast<uint32_t>(m_playerProfiles.size());
    }

    void SetProfilesInSegment(int32_t value)
    {
        this->m_model.profilesInSegment = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.continuationToken = m_continuationToken.empty() ? nullptr : m_continuationToken.data();
        this->m_model.playerProfiles = m_playerProfiles.empty() ? nullptr : m_playerProfiles.data();
    }

    String m_continuationToken;
    ModelVector<PFPlayStreamPlayerProfileWrapper<Alloc>, Alloc> m_playerProfiles;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamGetPlayerTagsRequestWrapper : public ModelWrapper<PFPlayStreamGetPlayerTagsRequest, Alloc>
{
public:
    using ModelType = typename PFPlayStreamGetPlayerTagsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamGetPlayerTagsRequestWrapper() = default;

    PFPlayStreamGetPlayerTagsRequestWrapper(const PFPlayStreamGetPlayerTagsRequest& model) :
        ModelWrapper<PFPlayStreamGetPlayerTagsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playfabNamespace{ SafeString(model.playfabNamespace) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayStreamGetPlayerTagsRequestWrapper(const PFPlayStreamGetPlayerTagsRequestWrapper& src) :
        PFPlayStreamGetPlayerTagsRequestWrapper{ src.Model() }
    {
    }

    PFPlayStreamGetPlayerTagsRequestWrapper(PFPlayStreamGetPlayerTagsRequestWrapper&& src) :
        PFPlayStreamGetPlayerTagsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamGetPlayerTagsRequestWrapper& operator=(PFPlayStreamGetPlayerTagsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamGetPlayerTagsRequestWrapper() = default;

    friend void swap(PFPlayStreamGetPlayerTagsRequestWrapper& lhs, PFPlayStreamGetPlayerTagsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playfabNamespace, rhs.m_playfabNamespace);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetplayfabNamespace(String value)
    {
        m_playfabNamespace = std::move(value);
        this->m_model.playfabNamespace =  m_playfabNamespace.empty() ? nullptr : m_playfabNamespace.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playfabNamespace = m_playfabNamespace.empty() ? nullptr : m_playfabNamespace.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playfabNamespace;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamGetPlayerTagsResultWrapper : public ModelWrapper<PFPlayStreamGetPlayerTagsResult, Alloc>
{
public:
    using ModelType = typename PFPlayStreamGetPlayerTagsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamGetPlayerTagsResultWrapper() = default;

    PFPlayStreamGetPlayerTagsResultWrapper(const PFPlayStreamGetPlayerTagsResult& model) :
        ModelWrapper<PFPlayStreamGetPlayerTagsResult, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) },
        m_tags{ model.tags, model.tags + model.tagsCount }
    {
        SetModelPointers();
    }

    PFPlayStreamGetPlayerTagsResultWrapper(const PFPlayStreamGetPlayerTagsResultWrapper& src) :
        PFPlayStreamGetPlayerTagsResultWrapper{ src.Model() }
    {
    }

    PFPlayStreamGetPlayerTagsResultWrapper(PFPlayStreamGetPlayerTagsResultWrapper&& src) :
        PFPlayStreamGetPlayerTagsResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamGetPlayerTagsResultWrapper& operator=(PFPlayStreamGetPlayerTagsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamGetPlayerTagsResultWrapper() = default;

    friend void swap(PFPlayStreamGetPlayerTagsResultWrapper& lhs, PFPlayStreamGetPlayerTagsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_tags, rhs.m_tags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetTags(CStringVector<Alloc> value)
    {
        m_tags = std::move(value);
        this->m_model.tags =  m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.tagsCount =  static_cast<uint32_t>(m_tags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.tags = m_tags.empty() ? nullptr : m_tags.data();
    }

    String m_playFabId;
    CStringVector<Alloc> m_tags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamRemovePlayerTagRequestWrapper : public ModelWrapper<PFPlayStreamRemovePlayerTagRequest, Alloc>
{
public:
    using ModelType = typename PFPlayStreamRemovePlayerTagRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamRemovePlayerTagRequestWrapper() = default;

    PFPlayStreamRemovePlayerTagRequestWrapper(const PFPlayStreamRemovePlayerTagRequest& model) :
        ModelWrapper<PFPlayStreamRemovePlayerTagRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_tagName{ SafeString(model.tagName) }
    {
        SetModelPointers();
    }

    PFPlayStreamRemovePlayerTagRequestWrapper(const PFPlayStreamRemovePlayerTagRequestWrapper& src) :
        PFPlayStreamRemovePlayerTagRequestWrapper{ src.Model() }
    {
    }

    PFPlayStreamRemovePlayerTagRequestWrapper(PFPlayStreamRemovePlayerTagRequestWrapper&& src) :
        PFPlayStreamRemovePlayerTagRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamRemovePlayerTagRequestWrapper& operator=(PFPlayStreamRemovePlayerTagRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamRemovePlayerTagRequestWrapper() = default;

    friend void swap(PFPlayStreamRemovePlayerTagRequestWrapper& lhs, PFPlayStreamRemovePlayerTagRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_tagName, rhs.m_tagName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetTagName(String value)
    {
        m_tagName = std::move(value);
        this->m_model.tagName =  m_tagName.empty() ? nullptr : m_tagName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.tagName = m_tagName.empty() ? nullptr : m_tagName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_tagName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamEventContentsWrapper : public ModelWrapper<PFPlayStreamEventContents, Alloc>
{
public:
    using ModelType = typename PFPlayStreamEventContents;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamEventContentsWrapper() = default;

    PFPlayStreamEventContentsWrapper(const PFPlayStreamEventContents& model) :
        ModelWrapper<PFPlayStreamEventContents, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_eventNamespace{ SafeString(model.eventNamespace) },
        m_name{ SafeString(model.name) },
        m_originalId{ SafeString(model.originalId) },
        m_originalTimestamp{ model.originalTimestamp ? StdExtra::optional<time_t>{ *model.originalTimestamp } : StdExtra::nullopt },
        m_payload{ model.payload },
        m_payloadJSON{ SafeString(model.payloadJSON) }
    {
        SetModelPointers();
    }

    PFPlayStreamEventContentsWrapper(const PFPlayStreamEventContentsWrapper& src) :
        PFPlayStreamEventContentsWrapper{ src.Model() }
    {
    }

    PFPlayStreamEventContentsWrapper(PFPlayStreamEventContentsWrapper&& src) :
        PFPlayStreamEventContentsWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamEventContentsWrapper& operator=(PFPlayStreamEventContentsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamEventContentsWrapper() = default;

    friend void swap(PFPlayStreamEventContentsWrapper& lhs, PFPlayStreamEventContentsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_eventNamespace, rhs.m_eventNamespace);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_originalId, rhs.m_originalId);
        swap(lhs.m_originalTimestamp, rhs.m_originalTimestamp);
        swap(lhs.m_payload, rhs.m_payload);
        swap(lhs.m_payloadJSON, rhs.m_payloadJSON);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetEventNamespace(String value)
    {
        m_eventNamespace = std::move(value);
        this->m_model.eventNamespace =  m_eventNamespace.empty() ? nullptr : m_eventNamespace.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetOriginalId(String value)
    {
        m_originalId = std::move(value);
        this->m_model.originalId =  m_originalId.empty() ? nullptr : m_originalId.data();
    }

    void SetOriginalTimestamp(StdExtra::optional<time_t> value)
    {
        m_originalTimestamp = std::move(value);
        this->m_model.originalTimestamp = m_originalTimestamp ? m_originalTimestamp.operator->() : nullptr;
    }

    void SetPayload(JsonObject<Alloc> value)
    {
        m_payload = std::move(value);
        this->m_model.payload.stringValue = m_payload.stringValue.empty() ? nullptr : m_payload.stringValue.data();
    }

    void SetPayloadJSON(String value)
    {
        m_payloadJSON = std::move(value);
        this->m_model.payloadJSON =  m_payloadJSON.empty() ? nullptr : m_payloadJSON.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.eventNamespace = m_eventNamespace.empty() ? nullptr : m_eventNamespace.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.originalId = m_originalId.empty() ? nullptr : m_originalId.data();
        this->m_model.originalTimestamp = m_originalTimestamp ? m_originalTimestamp.operator->() : nullptr;
        this->m_model.payload.stringValue = m_payload.stringValue.empty() ? nullptr : m_payload.stringValue.data();
        this->m_model.payloadJSON = m_payloadJSON.empty() ? nullptr : m_payloadJSON.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_eventNamespace;
    String m_name;
    String m_originalId;
    StdExtra::optional<time_t> m_originalTimestamp;
    JsonObject<Alloc> m_payload;
    String m_payloadJSON;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamWriteEventsRequestWrapper : public ModelWrapper<PFPlayStreamWriteEventsRequest, Alloc>
{
public:
    using ModelType = typename PFPlayStreamWriteEventsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamWriteEventsRequestWrapper() = default;

    PFPlayStreamWriteEventsRequestWrapper(const PFPlayStreamWriteEventsRequest& model) :
        ModelWrapper<PFPlayStreamWriteEventsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_events{ model.events, model.events + model.eventsCount }
    {
        SetModelPointers();
    }

    PFPlayStreamWriteEventsRequestWrapper(const PFPlayStreamWriteEventsRequestWrapper& src) :
        PFPlayStreamWriteEventsRequestWrapper{ src.Model() }
    {
    }

    PFPlayStreamWriteEventsRequestWrapper(PFPlayStreamWriteEventsRequestWrapper&& src) :
        PFPlayStreamWriteEventsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamWriteEventsRequestWrapper& operator=(PFPlayStreamWriteEventsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamWriteEventsRequestWrapper() = default;

    friend void swap(PFPlayStreamWriteEventsRequestWrapper& lhs, PFPlayStreamWriteEventsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_events, rhs.m_events);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEvents(ModelVector<PFPlayStreamEventContentsWrapper<Alloc>, Alloc> value)
    {
        m_events = std::move(value);
        this->m_model.events =  m_events.empty() ? nullptr : m_events.data();
        this->m_model.eventsCount =  static_cast<uint32_t>(m_events.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.events = m_events.empty() ? nullptr : m_events.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFPlayStreamEventContentsWrapper<Alloc>, Alloc> m_events;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayStreamWriteEventsResponseWrapper : public ModelWrapper<PFPlayStreamWriteEventsResponse, Alloc>
{
public:
    using ModelType = typename PFPlayStreamWriteEventsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayStreamWriteEventsResponseWrapper() = default;

    PFPlayStreamWriteEventsResponseWrapper(const PFPlayStreamWriteEventsResponse& model) :
        ModelWrapper<PFPlayStreamWriteEventsResponse, Alloc>{ model },
        m_assignedEventIds{ model.assignedEventIds, model.assignedEventIds + model.assignedEventIdsCount }
    {
        SetModelPointers();
    }

    PFPlayStreamWriteEventsResponseWrapper(const PFPlayStreamWriteEventsResponseWrapper& src) :
        PFPlayStreamWriteEventsResponseWrapper{ src.Model() }
    {
    }

    PFPlayStreamWriteEventsResponseWrapper(PFPlayStreamWriteEventsResponseWrapper&& src) :
        PFPlayStreamWriteEventsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFPlayStreamWriteEventsResponseWrapper& operator=(PFPlayStreamWriteEventsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayStreamWriteEventsResponseWrapper() = default;

    friend void swap(PFPlayStreamWriteEventsResponseWrapper& lhs, PFPlayStreamWriteEventsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_assignedEventIds, rhs.m_assignedEventIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAssignedEventIds(CStringVector<Alloc> value)
    {
        m_assignedEventIds = std::move(value);
        this->m_model.assignedEventIds =  m_assignedEventIds.empty() ? nullptr : m_assignedEventIds.data();
        this->m_model.assignedEventIdsCount =  static_cast<uint32_t>(m_assignedEventIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.assignedEventIds = m_assignedEventIds.empty() ? nullptr : m_assignedEventIds.data();
    }

    CStringVector<Alloc> m_assignedEventIds;
};

} // namespace Wrappers
} // namespace PlayFab
