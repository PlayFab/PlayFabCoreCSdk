// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFCharacterDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterResetCharacterStatisticsRequestWrapper : public ModelWrapper<PFCharacterResetCharacterStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterResetCharacterStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterResetCharacterStatisticsRequestWrapper() = default;

    PFCharacterResetCharacterStatisticsRequestWrapper(const PFCharacterResetCharacterStatisticsRequest& model) :
        ModelWrapper<PFCharacterResetCharacterStatisticsRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFCharacterResetCharacterStatisticsRequestWrapper(const PFCharacterResetCharacterStatisticsRequestWrapper& src) :
        PFCharacterResetCharacterStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFCharacterResetCharacterStatisticsRequestWrapper(PFCharacterResetCharacterStatisticsRequestWrapper&& src) :
        PFCharacterResetCharacterStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterResetCharacterStatisticsRequestWrapper& operator=(PFCharacterResetCharacterStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterResetCharacterStatisticsRequestWrapper() = default;

    friend void swap(PFCharacterResetCharacterStatisticsRequestWrapper& lhs, PFCharacterResetCharacterStatisticsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
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
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterListUsersCharactersRequestWrapper : public ModelWrapper<PFCharacterListUsersCharactersRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterListUsersCharactersRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterListUsersCharactersRequestWrapper() = default;

    PFCharacterListUsersCharactersRequestWrapper(const PFCharacterListUsersCharactersRequest& model) :
        ModelWrapper<PFCharacterListUsersCharactersRequest, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFCharacterListUsersCharactersRequestWrapper(const PFCharacterListUsersCharactersRequestWrapper& src) :
        PFCharacterListUsersCharactersRequestWrapper{ src.Model() }
    {
    }

    PFCharacterListUsersCharactersRequestWrapper(PFCharacterListUsersCharactersRequestWrapper&& src) :
        PFCharacterListUsersCharactersRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterListUsersCharactersRequestWrapper& operator=(PFCharacterListUsersCharactersRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterListUsersCharactersRequestWrapper() = default;

    friend void swap(PFCharacterListUsersCharactersRequestWrapper& lhs, PFCharacterListUsersCharactersRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterListUsersCharactersResultWrapper : public ModelWrapper<PFCharacterListUsersCharactersResult, Alloc>
{
public:
    using ModelType = typename PFCharacterListUsersCharactersResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterListUsersCharactersResultWrapper() = default;

    PFCharacterListUsersCharactersResultWrapper(const PFCharacterListUsersCharactersResult& model) :
        ModelWrapper<PFCharacterListUsersCharactersResult, Alloc>{ model },
        m_characters{ model.characters, model.characters + model.charactersCount }
    {
        SetModelPointers();
    }

    PFCharacterListUsersCharactersResultWrapper(const PFCharacterListUsersCharactersResultWrapper& src) :
        PFCharacterListUsersCharactersResultWrapper{ src.Model() }
    {
    }

    PFCharacterListUsersCharactersResultWrapper(PFCharacterListUsersCharactersResultWrapper&& src) :
        PFCharacterListUsersCharactersResultWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterListUsersCharactersResultWrapper& operator=(PFCharacterListUsersCharactersResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterListUsersCharactersResultWrapper() = default;

    friend void swap(PFCharacterListUsersCharactersResultWrapper& lhs, PFCharacterListUsersCharactersResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characters, rhs.m_characters);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacters(ModelVector<PFCharacterResultWrapper<Alloc>, Alloc> value)
    {
        m_characters = std::move(value);
        this->m_model.characters =  m_characters.empty() ? nullptr : m_characters.data();
        this->m_model.charactersCount =  static_cast<uint32_t>(m_characters.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.characters = m_characters.empty() ? nullptr : m_characters.data();
    }

    ModelVector<PFCharacterResultWrapper<Alloc>, Alloc> m_characters;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterGetCharacterDataRequestWrapper : public ModelWrapper<PFCharacterGetCharacterDataRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterGetCharacterDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterGetCharacterDataRequestWrapper() = default;

    PFCharacterGetCharacterDataRequestWrapper(const PFCharacterGetCharacterDataRequest& model) :
        ModelWrapper<PFCharacterGetCharacterDataRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_ifChangedFromDataVersion{ model.ifChangedFromDataVersion ? StdExtra::optional<uint32_t>{ *model.ifChangedFromDataVersion } : StdExtra::nullopt },
        m_keys{ model.keys, model.keys + model.keysCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFCharacterGetCharacterDataRequestWrapper(const PFCharacterGetCharacterDataRequestWrapper& src) :
        PFCharacterGetCharacterDataRequestWrapper{ src.Model() }
    {
    }

    PFCharacterGetCharacterDataRequestWrapper(PFCharacterGetCharacterDataRequestWrapper&& src) :
        PFCharacterGetCharacterDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterGetCharacterDataRequestWrapper& operator=(PFCharacterGetCharacterDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterGetCharacterDataRequestWrapper() = default;

    friend void swap(PFCharacterGetCharacterDataRequestWrapper& lhs, PFCharacterGetCharacterDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_ifChangedFromDataVersion, rhs.m_ifChangedFromDataVersion);
        swap(lhs.m_keys, rhs.m_keys);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetIfChangedFromDataVersion(StdExtra::optional<uint32_t> value)
    {
        m_ifChangedFromDataVersion = std::move(value);
        this->m_model.ifChangedFromDataVersion = m_ifChangedFromDataVersion ? m_ifChangedFromDataVersion.operator->() : nullptr;
    }

    void SetKeys(CStringVector<Alloc> value)
    {
        m_keys = std::move(value);
        this->m_model.keys =  m_keys.empty() ? nullptr : m_keys.data();
        this->m_model.keysCount =  static_cast<uint32_t>(m_keys.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.ifChangedFromDataVersion = m_ifChangedFromDataVersion ? m_ifChangedFromDataVersion.operator->() : nullptr;
        this->m_model.keys = m_keys.empty() ? nullptr : m_keys.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    StdExtra::optional<uint32_t> m_ifChangedFromDataVersion;
    CStringVector<Alloc> m_keys;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterClientGetCharacterDataResultWrapper : public ModelWrapper<PFCharacterClientGetCharacterDataResult, Alloc>
{
public:
    using ModelType = typename PFCharacterClientGetCharacterDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterClientGetCharacterDataResultWrapper() = default;

    PFCharacterClientGetCharacterDataResultWrapper(const PFCharacterClientGetCharacterDataResult& model) :
        ModelWrapper<PFCharacterClientGetCharacterDataResult, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFCharacterClientGetCharacterDataResultWrapper(const PFCharacterClientGetCharacterDataResultWrapper& src) :
        PFCharacterClientGetCharacterDataResultWrapper{ src.Model() }
    {
    }

    PFCharacterClientGetCharacterDataResultWrapper(PFCharacterClientGetCharacterDataResultWrapper&& src) :
        PFCharacterClientGetCharacterDataResultWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterClientGetCharacterDataResultWrapper& operator=(PFCharacterClientGetCharacterDataResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterClientGetCharacterDataResultWrapper() = default;

    friend void swap(PFCharacterClientGetCharacterDataResultWrapper& lhs, PFCharacterClientGetCharacterDataResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetData(ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

    void SetDataVersion(uint32_t value)
    {
        this->m_model.dataVersion = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    String m_characterId;
    ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterGetCharacterLeaderboardRequestWrapper : public ModelWrapper<PFCharacterGetCharacterLeaderboardRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterGetCharacterLeaderboardRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterGetCharacterLeaderboardRequestWrapper() = default;

    PFCharacterGetCharacterLeaderboardRequestWrapper(const PFCharacterGetCharacterLeaderboardRequest& model) :
        ModelWrapper<PFCharacterGetCharacterLeaderboardRequest, Alloc>{ model },
        m_characterType{ SafeString(model.characterType) },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFCharacterGetCharacterLeaderboardRequestWrapper(const PFCharacterGetCharacterLeaderboardRequestWrapper& src) :
        PFCharacterGetCharacterLeaderboardRequestWrapper{ src.Model() }
    {
    }

    PFCharacterGetCharacterLeaderboardRequestWrapper(PFCharacterGetCharacterLeaderboardRequestWrapper&& src) :
        PFCharacterGetCharacterLeaderboardRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterGetCharacterLeaderboardRequestWrapper& operator=(PFCharacterGetCharacterLeaderboardRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterGetCharacterLeaderboardRequestWrapper() = default;

    friend void swap(PFCharacterGetCharacterLeaderboardRequestWrapper& lhs, PFCharacterGetCharacterLeaderboardRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterType, rhs.m_characterType);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterType(String value)
    {
        m_characterType = std::move(value);
        this->m_model.characterType =  m_characterType.empty() ? nullptr : m_characterType.data();
    }

    void SetMaxResultsCount(int32_t value)
    {
        this->m_model.maxResultsCount = value;
    }

    void SetStartPosition(int32_t value)
    {
        this->m_model.startPosition = value;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterType = m_characterType.empty() ? nullptr : m_characterType.data();
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    String m_characterType;
    String m_statisticName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterCharacterLeaderboardEntryWrapper : public ModelWrapper<PFCharacterCharacterLeaderboardEntry, Alloc>
{
public:
    using ModelType = typename PFCharacterCharacterLeaderboardEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterCharacterLeaderboardEntryWrapper() = default;

    PFCharacterCharacterLeaderboardEntryWrapper(const PFCharacterCharacterLeaderboardEntry& model) :
        ModelWrapper<PFCharacterCharacterLeaderboardEntry, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_characterName{ SafeString(model.characterName) },
        m_characterType{ SafeString(model.characterType) },
        m_displayName{ SafeString(model.displayName) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFCharacterCharacterLeaderboardEntryWrapper(const PFCharacterCharacterLeaderboardEntryWrapper& src) :
        PFCharacterCharacterLeaderboardEntryWrapper{ src.Model() }
    {
    }

    PFCharacterCharacterLeaderboardEntryWrapper(PFCharacterCharacterLeaderboardEntryWrapper&& src) :
        PFCharacterCharacterLeaderboardEntryWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterCharacterLeaderboardEntryWrapper& operator=(PFCharacterCharacterLeaderboardEntryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterCharacterLeaderboardEntryWrapper() = default;

    friend void swap(PFCharacterCharacterLeaderboardEntryWrapper& lhs, PFCharacterCharacterLeaderboardEntryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_characterName, rhs.m_characterName);
        swap(lhs.m_characterType, rhs.m_characterType);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCharacterName(String value)
    {
        m_characterName = std::move(value);
        this->m_model.characterName =  m_characterName.empty() ? nullptr : m_characterName.data();
    }

    void SetCharacterType(String value)
    {
        m_characterType = std::move(value);
        this->m_model.characterType =  m_characterType.empty() ? nullptr : m_characterType.data();
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetPosition(int32_t value)
    {
        this->m_model.position = value;
    }

    void SetStatValue(int32_t value)
    {
        this->m_model.statValue = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.characterName = m_characterName.empty() ? nullptr : m_characterName.data();
        this->m_model.characterType = m_characterType.empty() ? nullptr : m_characterType.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    String m_characterName;
    String m_characterType;
    String m_displayName;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterGetCharacterLeaderboardResultWrapper : public ModelWrapper<PFCharacterGetCharacterLeaderboardResult, Alloc>
{
public:
    using ModelType = typename PFCharacterGetCharacterLeaderboardResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterGetCharacterLeaderboardResultWrapper() = default;

    PFCharacterGetCharacterLeaderboardResultWrapper(const PFCharacterGetCharacterLeaderboardResult& model) :
        ModelWrapper<PFCharacterGetCharacterLeaderboardResult, Alloc>{ model },
        m_leaderboard{ model.leaderboard, model.leaderboard + model.leaderboardCount }
    {
        SetModelPointers();
    }

    PFCharacterGetCharacterLeaderboardResultWrapper(const PFCharacterGetCharacterLeaderboardResultWrapper& src) :
        PFCharacterGetCharacterLeaderboardResultWrapper{ src.Model() }
    {
    }

    PFCharacterGetCharacterLeaderboardResultWrapper(PFCharacterGetCharacterLeaderboardResultWrapper&& src) :
        PFCharacterGetCharacterLeaderboardResultWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterGetCharacterLeaderboardResultWrapper& operator=(PFCharacterGetCharacterLeaderboardResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterGetCharacterLeaderboardResultWrapper() = default;

    friend void swap(PFCharacterGetCharacterLeaderboardResultWrapper& lhs, PFCharacterGetCharacterLeaderboardResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leaderboard, rhs.m_leaderboard);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeaderboard(ModelVector<PFCharacterCharacterLeaderboardEntryWrapper<Alloc>, Alloc> value)
    {
        m_leaderboard = std::move(value);
        this->m_model.leaderboard =  m_leaderboard.empty() ? nullptr : m_leaderboard.data();
        this->m_model.leaderboardCount =  static_cast<uint32_t>(m_leaderboard.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.leaderboard = m_leaderboard.empty() ? nullptr : m_leaderboard.data();
    }

    ModelVector<PFCharacterCharacterLeaderboardEntryWrapper<Alloc>, Alloc> m_leaderboard;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterClientGetCharacterStatisticsRequestWrapper : public ModelWrapper<PFCharacterClientGetCharacterStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterClientGetCharacterStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterClientGetCharacterStatisticsRequestWrapper() = default;

    PFCharacterClientGetCharacterStatisticsRequestWrapper(const PFCharacterClientGetCharacterStatisticsRequest& model) :
        ModelWrapper<PFCharacterClientGetCharacterStatisticsRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) }
    {
        SetModelPointers();
    }

    PFCharacterClientGetCharacterStatisticsRequestWrapper(const PFCharacterClientGetCharacterStatisticsRequestWrapper& src) :
        PFCharacterClientGetCharacterStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFCharacterClientGetCharacterStatisticsRequestWrapper(PFCharacterClientGetCharacterStatisticsRequestWrapper&& src) :
        PFCharacterClientGetCharacterStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterClientGetCharacterStatisticsRequestWrapper& operator=(PFCharacterClientGetCharacterStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterClientGetCharacterStatisticsRequestWrapper() = default;

    friend void swap(PFCharacterClientGetCharacterStatisticsRequestWrapper& lhs, PFCharacterClientGetCharacterStatisticsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
    }

    String m_characterId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterClientGetCharacterStatisticsResultWrapper : public ModelWrapper<PFCharacterClientGetCharacterStatisticsResult, Alloc>
{
public:
    using ModelType = typename PFCharacterClientGetCharacterStatisticsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterClientGetCharacterStatisticsResultWrapper() = default;

    PFCharacterClientGetCharacterStatisticsResultWrapper(const PFCharacterClientGetCharacterStatisticsResult& model) :
        ModelWrapper<PFCharacterClientGetCharacterStatisticsResult, Alloc>{ model },
        m_characterStatistics{ model.characterStatistics, model.characterStatistics + model.characterStatisticsCount }
    {
        SetModelPointers();
    }

    PFCharacterClientGetCharacterStatisticsResultWrapper(const PFCharacterClientGetCharacterStatisticsResultWrapper& src) :
        PFCharacterClientGetCharacterStatisticsResultWrapper{ src.Model() }
    {
    }

    PFCharacterClientGetCharacterStatisticsResultWrapper(PFCharacterClientGetCharacterStatisticsResultWrapper&& src) :
        PFCharacterClientGetCharacterStatisticsResultWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterClientGetCharacterStatisticsResultWrapper& operator=(PFCharacterClientGetCharacterStatisticsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterClientGetCharacterStatisticsResultWrapper() = default;

    friend void swap(PFCharacterClientGetCharacterStatisticsResultWrapper& lhs, PFCharacterClientGetCharacterStatisticsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterStatistics, rhs.m_characterStatistics);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterStatistics(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_characterStatistics = std::move(value);
        this->m_model.characterStatistics =  m_characterStatistics.empty() ? nullptr : m_characterStatistics.data();
        this->m_model.characterStatisticsCount =  static_cast<uint32_t>(m_characterStatistics.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterStatistics = m_characterStatistics.empty() ? nullptr : m_characterStatistics.data();
    }

    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_characterStatistics;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper : public ModelWrapper<PFCharacterClientGetLeaderboardAroundCharacterRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterClientGetLeaderboardAroundCharacterRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper() = default;

    PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper(const PFCharacterClientGetLeaderboardAroundCharacterRequest& model) :
        ModelWrapper<PFCharacterClientGetLeaderboardAroundCharacterRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_characterType{ SafeString(model.characterType) },
        m_maxResultsCount{ model.maxResultsCount ? StdExtra::optional<int32_t>{ *model.maxResultsCount } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper(const PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper& src) :
        PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper{ src.Model() }
    {
    }

    PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper(PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper&& src) :
        PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper& operator=(PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper() = default;

    friend void swap(PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper& lhs, PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_characterType, rhs.m_characterType);
        swap(lhs.m_maxResultsCount, rhs.m_maxResultsCount);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCharacterType(String value)
    {
        m_characterType = std::move(value);
        this->m_model.characterType =  m_characterType.empty() ? nullptr : m_characterType.data();
    }

    void SetMaxResultsCount(StdExtra::optional<int32_t> value)
    {
        m_maxResultsCount = std::move(value);
        this->m_model.maxResultsCount = m_maxResultsCount ? m_maxResultsCount.operator->() : nullptr;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.characterType = m_characterType.empty() ? nullptr : m_characterType.data();
        this->m_model.maxResultsCount = m_maxResultsCount ? m_maxResultsCount.operator->() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    String m_characterId;
    String m_characterType;
    StdExtra::optional<int32_t> m_maxResultsCount;
    String m_statisticName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterGetLeaderboardAroundCharacterResultWrapper : public ModelWrapper<PFCharacterGetLeaderboardAroundCharacterResult, Alloc>
{
public:
    using ModelType = typename PFCharacterGetLeaderboardAroundCharacterResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterGetLeaderboardAroundCharacterResultWrapper() = default;

    PFCharacterGetLeaderboardAroundCharacterResultWrapper(const PFCharacterGetLeaderboardAroundCharacterResult& model) :
        ModelWrapper<PFCharacterGetLeaderboardAroundCharacterResult, Alloc>{ model },
        m_leaderboard{ model.leaderboard, model.leaderboard + model.leaderboardCount }
    {
        SetModelPointers();
    }

    PFCharacterGetLeaderboardAroundCharacterResultWrapper(const PFCharacterGetLeaderboardAroundCharacterResultWrapper& src) :
        PFCharacterGetLeaderboardAroundCharacterResultWrapper{ src.Model() }
    {
    }

    PFCharacterGetLeaderboardAroundCharacterResultWrapper(PFCharacterGetLeaderboardAroundCharacterResultWrapper&& src) :
        PFCharacterGetLeaderboardAroundCharacterResultWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterGetLeaderboardAroundCharacterResultWrapper& operator=(PFCharacterGetLeaderboardAroundCharacterResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterGetLeaderboardAroundCharacterResultWrapper() = default;

    friend void swap(PFCharacterGetLeaderboardAroundCharacterResultWrapper& lhs, PFCharacterGetLeaderboardAroundCharacterResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leaderboard, rhs.m_leaderboard);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeaderboard(ModelVector<PFCharacterCharacterLeaderboardEntryWrapper<Alloc>, Alloc> value)
    {
        m_leaderboard = std::move(value);
        this->m_model.leaderboard =  m_leaderboard.empty() ? nullptr : m_leaderboard.data();
        this->m_model.leaderboardCount =  static_cast<uint32_t>(m_leaderboard.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.leaderboard = m_leaderboard.empty() ? nullptr : m_leaderboard.data();
    }

    ModelVector<PFCharacterCharacterLeaderboardEntryWrapper<Alloc>, Alloc> m_leaderboard;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper : public ModelWrapper<PFCharacterClientGetLeaderboardForUsersCharactersRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterClientGetLeaderboardForUsersCharactersRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper() = default;

    PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper(const PFCharacterClientGetLeaderboardForUsersCharactersRequest& model) :
        ModelWrapper<PFCharacterClientGetLeaderboardForUsersCharactersRequest, Alloc>{ model },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper(const PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper& src) :
        PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper{ src.Model() }
    {
    }

    PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper(PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper&& src) :
        PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper& operator=(PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper() = default;

    friend void swap(PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper& lhs, PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    String m_statisticName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterGetLeaderboardForUsersCharactersResultWrapper : public ModelWrapper<PFCharacterGetLeaderboardForUsersCharactersResult, Alloc>
{
public:
    using ModelType = typename PFCharacterGetLeaderboardForUsersCharactersResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterGetLeaderboardForUsersCharactersResultWrapper() = default;

    PFCharacterGetLeaderboardForUsersCharactersResultWrapper(const PFCharacterGetLeaderboardForUsersCharactersResult& model) :
        ModelWrapper<PFCharacterGetLeaderboardForUsersCharactersResult, Alloc>{ model },
        m_leaderboard{ model.leaderboard, model.leaderboard + model.leaderboardCount }
    {
        SetModelPointers();
    }

    PFCharacterGetLeaderboardForUsersCharactersResultWrapper(const PFCharacterGetLeaderboardForUsersCharactersResultWrapper& src) :
        PFCharacterGetLeaderboardForUsersCharactersResultWrapper{ src.Model() }
    {
    }

    PFCharacterGetLeaderboardForUsersCharactersResultWrapper(PFCharacterGetLeaderboardForUsersCharactersResultWrapper&& src) :
        PFCharacterGetLeaderboardForUsersCharactersResultWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterGetLeaderboardForUsersCharactersResultWrapper& operator=(PFCharacterGetLeaderboardForUsersCharactersResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterGetLeaderboardForUsersCharactersResultWrapper() = default;

    friend void swap(PFCharacterGetLeaderboardForUsersCharactersResultWrapper& lhs, PFCharacterGetLeaderboardForUsersCharactersResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leaderboard, rhs.m_leaderboard);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeaderboard(ModelVector<PFCharacterCharacterLeaderboardEntryWrapper<Alloc>, Alloc> value)
    {
        m_leaderboard = std::move(value);
        this->m_model.leaderboard =  m_leaderboard.empty() ? nullptr : m_leaderboard.data();
        this->m_model.leaderboardCount =  static_cast<uint32_t>(m_leaderboard.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.leaderboard = m_leaderboard.empty() ? nullptr : m_leaderboard.data();
    }

    ModelVector<PFCharacterCharacterLeaderboardEntryWrapper<Alloc>, Alloc> m_leaderboard;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterClientGrantCharacterToUserRequestWrapper : public ModelWrapper<PFCharacterClientGrantCharacterToUserRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterClientGrantCharacterToUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterClientGrantCharacterToUserRequestWrapper() = default;

    PFCharacterClientGrantCharacterToUserRequestWrapper(const PFCharacterClientGrantCharacterToUserRequest& model) :
        ModelWrapper<PFCharacterClientGrantCharacterToUserRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterName{ SafeString(model.characterName) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_itemId{ SafeString(model.itemId) }
    {
        SetModelPointers();
    }

    PFCharacterClientGrantCharacterToUserRequestWrapper(const PFCharacterClientGrantCharacterToUserRequestWrapper& src) :
        PFCharacterClientGrantCharacterToUserRequestWrapper{ src.Model() }
    {
    }

    PFCharacterClientGrantCharacterToUserRequestWrapper(PFCharacterClientGrantCharacterToUserRequestWrapper&& src) :
        PFCharacterClientGrantCharacterToUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterClientGrantCharacterToUserRequestWrapper& operator=(PFCharacterClientGrantCharacterToUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterClientGrantCharacterToUserRequestWrapper() = default;

    friend void swap(PFCharacterClientGrantCharacterToUserRequestWrapper& lhs, PFCharacterClientGrantCharacterToUserRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterName, rhs.m_characterName);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_itemId, rhs.m_itemId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterName(String value)
    {
        m_characterName = std::move(value);
        this->m_model.characterName =  m_characterName.empty() ? nullptr : m_characterName.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterName = m_characterName.empty() ? nullptr : m_characterName.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
    }

    String m_catalogVersion;
    String m_characterName;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_itemId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterClientGrantCharacterToUserResultWrapper : public ModelWrapper<PFCharacterClientGrantCharacterToUserResult, Alloc>
{
public:
    using ModelType = typename PFCharacterClientGrantCharacterToUserResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterClientGrantCharacterToUserResultWrapper() = default;

    PFCharacterClientGrantCharacterToUserResultWrapper(const PFCharacterClientGrantCharacterToUserResult& model) :
        ModelWrapper<PFCharacterClientGrantCharacterToUserResult, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_characterType{ SafeString(model.characterType) }
    {
        SetModelPointers();
    }

    PFCharacterClientGrantCharacterToUserResultWrapper(const PFCharacterClientGrantCharacterToUserResultWrapper& src) :
        PFCharacterClientGrantCharacterToUserResultWrapper{ src.Model() }
    {
    }

    PFCharacterClientGrantCharacterToUserResultWrapper(PFCharacterClientGrantCharacterToUserResultWrapper&& src) :
        PFCharacterClientGrantCharacterToUserResultWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterClientGrantCharacterToUserResultWrapper& operator=(PFCharacterClientGrantCharacterToUserResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterClientGrantCharacterToUserResultWrapper() = default;

    friend void swap(PFCharacterClientGrantCharacterToUserResultWrapper& lhs, PFCharacterClientGrantCharacterToUserResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_characterType, rhs.m_characterType);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCharacterType(String value)
    {
        m_characterType = std::move(value);
        this->m_model.characterType =  m_characterType.empty() ? nullptr : m_characterType.data();
    }

    void SetResult(bool value)
    {
        this->m_model.result = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.characterType = m_characterType.empty() ? nullptr : m_characterType.data();
    }

    String m_characterId;
    String m_characterType;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterClientUpdateCharacterDataRequestWrapper : public ModelWrapper<PFCharacterClientUpdateCharacterDataRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterClientUpdateCharacterDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterClientUpdateCharacterDataRequestWrapper() = default;

    PFCharacterClientUpdateCharacterDataRequestWrapper(const PFCharacterClientUpdateCharacterDataRequest& model) :
        ModelWrapper<PFCharacterClientUpdateCharacterDataRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_data{ model.data, model.data + model.dataCount },
        m_keysToRemove{ model.keysToRemove, model.keysToRemove + model.keysToRemoveCount },
        m_permission{ model.permission ? StdExtra::optional<PFUserDataPermission>{ *model.permission } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCharacterClientUpdateCharacterDataRequestWrapper(const PFCharacterClientUpdateCharacterDataRequestWrapper& src) :
        PFCharacterClientUpdateCharacterDataRequestWrapper{ src.Model() }
    {
    }

    PFCharacterClientUpdateCharacterDataRequestWrapper(PFCharacterClientUpdateCharacterDataRequestWrapper&& src) :
        PFCharacterClientUpdateCharacterDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterClientUpdateCharacterDataRequestWrapper& operator=(PFCharacterClientUpdateCharacterDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterClientUpdateCharacterDataRequestWrapper() = default;

    friend void swap(PFCharacterClientUpdateCharacterDataRequestWrapper& lhs, PFCharacterClientUpdateCharacterDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_keysToRemove, rhs.m_keysToRemove);
        swap(lhs.m_permission, rhs.m_permission);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetData(StringDictionaryEntryVector<Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

    void SetKeysToRemove(CStringVector<Alloc> value)
    {
        m_keysToRemove = std::move(value);
        this->m_model.keysToRemove =  m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.keysToRemoveCount =  static_cast<uint32_t>(m_keysToRemove.size());
    }

    void SetPermission(StdExtra::optional<PFUserDataPermission> value)
    {
        m_permission = std::move(value);
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.keysToRemove = m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
    }

    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_data;
    CStringVector<Alloc> m_keysToRemove;
    StdExtra::optional<PFUserDataPermission> m_permission;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterUpdateCharacterDataResultWrapper : public ModelWrapper<PFCharacterUpdateCharacterDataResult, Alloc>
{
public:
    using ModelType = typename PFCharacterUpdateCharacterDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFCharacterUpdateCharacterDataResult, Alloc>::ModelWrapper;

    void SetDataVersion(uint32_t value)
    {
        this->m_model.dataVersion = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterClientUpdateCharacterStatisticsRequestWrapper : public ModelWrapper<PFCharacterClientUpdateCharacterStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterClientUpdateCharacterStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterClientUpdateCharacterStatisticsRequestWrapper() = default;

    PFCharacterClientUpdateCharacterStatisticsRequestWrapper(const PFCharacterClientUpdateCharacterStatisticsRequest& model) :
        ModelWrapper<PFCharacterClientUpdateCharacterStatisticsRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_characterStatistics{ model.characterStatistics, model.characterStatistics + model.characterStatisticsCount },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFCharacterClientUpdateCharacterStatisticsRequestWrapper(const PFCharacterClientUpdateCharacterStatisticsRequestWrapper& src) :
        PFCharacterClientUpdateCharacterStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFCharacterClientUpdateCharacterStatisticsRequestWrapper(PFCharacterClientUpdateCharacterStatisticsRequestWrapper&& src) :
        PFCharacterClientUpdateCharacterStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterClientUpdateCharacterStatisticsRequestWrapper& operator=(PFCharacterClientUpdateCharacterStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterClientUpdateCharacterStatisticsRequestWrapper() = default;

    friend void swap(PFCharacterClientUpdateCharacterStatisticsRequestWrapper& lhs, PFCharacterClientUpdateCharacterStatisticsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_characterStatistics, rhs.m_characterStatistics);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCharacterStatistics(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_characterStatistics = std::move(value);
        this->m_model.characterStatistics =  m_characterStatistics.empty() ? nullptr : m_characterStatistics.data();
        this->m_model.characterStatisticsCount =  static_cast<uint32_t>(m_characterStatistics.size());
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.characterStatistics = m_characterStatistics.empty() ? nullptr : m_characterStatistics.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_characterId;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_characterStatistics;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterDeleteCharacterFromUserRequestWrapper : public ModelWrapper<PFCharacterDeleteCharacterFromUserRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterDeleteCharacterFromUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterDeleteCharacterFromUserRequestWrapper() = default;

    PFCharacterDeleteCharacterFromUserRequestWrapper(const PFCharacterDeleteCharacterFromUserRequest& model) :
        ModelWrapper<PFCharacterDeleteCharacterFromUserRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFCharacterDeleteCharacterFromUserRequestWrapper(const PFCharacterDeleteCharacterFromUserRequestWrapper& src) :
        PFCharacterDeleteCharacterFromUserRequestWrapper{ src.Model() }
    {
    }

    PFCharacterDeleteCharacterFromUserRequestWrapper(PFCharacterDeleteCharacterFromUserRequestWrapper&& src) :
        PFCharacterDeleteCharacterFromUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterDeleteCharacterFromUserRequestWrapper& operator=(PFCharacterDeleteCharacterFromUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterDeleteCharacterFromUserRequestWrapper() = default;

    friend void swap(PFCharacterDeleteCharacterFromUserRequestWrapper& lhs, PFCharacterDeleteCharacterFromUserRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
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

    void SetSaveCharacterInventory(bool value)
    {
        this->m_model.saveCharacterInventory = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterServerGetCharacterDataResultWrapper : public ModelWrapper<PFCharacterServerGetCharacterDataResult, Alloc>
{
public:
    using ModelType = typename PFCharacterServerGetCharacterDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterServerGetCharacterDataResultWrapper() = default;

    PFCharacterServerGetCharacterDataResultWrapper(const PFCharacterServerGetCharacterDataResult& model) :
        ModelWrapper<PFCharacterServerGetCharacterDataResult, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_data{ model.data, model.data + model.dataCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFCharacterServerGetCharacterDataResultWrapper(const PFCharacterServerGetCharacterDataResultWrapper& src) :
        PFCharacterServerGetCharacterDataResultWrapper{ src.Model() }
    {
    }

    PFCharacterServerGetCharacterDataResultWrapper(PFCharacterServerGetCharacterDataResultWrapper&& src) :
        PFCharacterServerGetCharacterDataResultWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterServerGetCharacterDataResultWrapper& operator=(PFCharacterServerGetCharacterDataResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterServerGetCharacterDataResultWrapper() = default;

    friend void swap(PFCharacterServerGetCharacterDataResultWrapper& lhs, PFCharacterServerGetCharacterDataResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetData(ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

    void SetDataVersion(uint32_t value)
    {
        this->m_model.dataVersion = value;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> m_data;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterServerGetCharacterStatisticsRequestWrapper : public ModelWrapper<PFCharacterServerGetCharacterStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterServerGetCharacterStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterServerGetCharacterStatisticsRequestWrapper() = default;

    PFCharacterServerGetCharacterStatisticsRequestWrapper(const PFCharacterServerGetCharacterStatisticsRequest& model) :
        ModelWrapper<PFCharacterServerGetCharacterStatisticsRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFCharacterServerGetCharacterStatisticsRequestWrapper(const PFCharacterServerGetCharacterStatisticsRequestWrapper& src) :
        PFCharacterServerGetCharacterStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFCharacterServerGetCharacterStatisticsRequestWrapper(PFCharacterServerGetCharacterStatisticsRequestWrapper&& src) :
        PFCharacterServerGetCharacterStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterServerGetCharacterStatisticsRequestWrapper& operator=(PFCharacterServerGetCharacterStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterServerGetCharacterStatisticsRequestWrapper() = default;

    friend void swap(PFCharacterServerGetCharacterStatisticsRequestWrapper& lhs, PFCharacterServerGetCharacterStatisticsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterServerGetCharacterStatisticsResultWrapper : public ModelWrapper<PFCharacterServerGetCharacterStatisticsResult, Alloc>
{
public:
    using ModelType = typename PFCharacterServerGetCharacterStatisticsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterServerGetCharacterStatisticsResultWrapper() = default;

    PFCharacterServerGetCharacterStatisticsResultWrapper(const PFCharacterServerGetCharacterStatisticsResult& model) :
        ModelWrapper<PFCharacterServerGetCharacterStatisticsResult, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_characterStatistics{ model.characterStatistics, model.characterStatistics + model.characterStatisticsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFCharacterServerGetCharacterStatisticsResultWrapper(const PFCharacterServerGetCharacterStatisticsResultWrapper& src) :
        PFCharacterServerGetCharacterStatisticsResultWrapper{ src.Model() }
    {
    }

    PFCharacterServerGetCharacterStatisticsResultWrapper(PFCharacterServerGetCharacterStatisticsResultWrapper&& src) :
        PFCharacterServerGetCharacterStatisticsResultWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterServerGetCharacterStatisticsResultWrapper& operator=(PFCharacterServerGetCharacterStatisticsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterServerGetCharacterStatisticsResultWrapper() = default;

    friend void swap(PFCharacterServerGetCharacterStatisticsResultWrapper& lhs, PFCharacterServerGetCharacterStatisticsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_characterStatistics, rhs.m_characterStatistics);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCharacterStatistics(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_characterStatistics = std::move(value);
        this->m_model.characterStatistics =  m_characterStatistics.empty() ? nullptr : m_characterStatistics.data();
        this->m_model.characterStatisticsCount =  static_cast<uint32_t>(m_characterStatistics.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.characterStatistics = m_characterStatistics.empty() ? nullptr : m_characterStatistics.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_characterStatistics;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper : public ModelWrapper<PFCharacterServerGetLeaderboardAroundCharacterRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterServerGetLeaderboardAroundCharacterRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper() = default;

    PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper(const PFCharacterServerGetLeaderboardAroundCharacterRequest& model) :
        ModelWrapper<PFCharacterServerGetLeaderboardAroundCharacterRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_characterType{ SafeString(model.characterType) },
        m_playFabId{ SafeString(model.playFabId) },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper(const PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper& src) :
        PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper{ src.Model() }
    {
    }

    PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper(PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper&& src) :
        PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper& operator=(PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper() = default;

    friend void swap(PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper& lhs, PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_characterType, rhs.m_characterType);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCharacterType(String value)
    {
        m_characterType = std::move(value);
        this->m_model.characterType =  m_characterType.empty() ? nullptr : m_characterType.data();
    }

    void SetMaxResultsCount(int32_t value)
    {
        this->m_model.maxResultsCount = value;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.characterType = m_characterType.empty() ? nullptr : m_characterType.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    String m_characterId;
    String m_characterType;
    String m_playFabId;
    String m_statisticName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper : public ModelWrapper<PFCharacterServerGetLeaderboardForUsersCharactersRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterServerGetLeaderboardForUsersCharactersRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper() = default;

    PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper(const PFCharacterServerGetLeaderboardForUsersCharactersRequest& model) :
        ModelWrapper<PFCharacterServerGetLeaderboardForUsersCharactersRequest, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper(const PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper& src) :
        PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper{ src.Model() }
    {
    }

    PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper(PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper&& src) :
        PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper& operator=(PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper() = default;

    friend void swap(PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper& lhs, PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    String m_playFabId;
    String m_statisticName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterServerGrantCharacterToUserRequestWrapper : public ModelWrapper<PFCharacterServerGrantCharacterToUserRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterServerGrantCharacterToUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterServerGrantCharacterToUserRequestWrapper() = default;

    PFCharacterServerGrantCharacterToUserRequestWrapper(const PFCharacterServerGrantCharacterToUserRequest& model) :
        ModelWrapper<PFCharacterServerGrantCharacterToUserRequest, Alloc>{ model },
        m_characterName{ SafeString(model.characterName) },
        m_characterType{ SafeString(model.characterType) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFCharacterServerGrantCharacterToUserRequestWrapper(const PFCharacterServerGrantCharacterToUserRequestWrapper& src) :
        PFCharacterServerGrantCharacterToUserRequestWrapper{ src.Model() }
    {
    }

    PFCharacterServerGrantCharacterToUserRequestWrapper(PFCharacterServerGrantCharacterToUserRequestWrapper&& src) :
        PFCharacterServerGrantCharacterToUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterServerGrantCharacterToUserRequestWrapper& operator=(PFCharacterServerGrantCharacterToUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterServerGrantCharacterToUserRequestWrapper() = default;

    friend void swap(PFCharacterServerGrantCharacterToUserRequestWrapper& lhs, PFCharacterServerGrantCharacterToUserRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterName, rhs.m_characterName);
        swap(lhs.m_characterType, rhs.m_characterType);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterName(String value)
    {
        m_characterName = std::move(value);
        this->m_model.characterName =  m_characterName.empty() ? nullptr : m_characterName.data();
    }

    void SetCharacterType(String value)
    {
        m_characterType = std::move(value);
        this->m_model.characterType =  m_characterType.empty() ? nullptr : m_characterType.data();
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
        this->m_model.characterName = m_characterName.empty() ? nullptr : m_characterName.data();
        this->m_model.characterType = m_characterType.empty() ? nullptr : m_characterType.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterName;
    String m_characterType;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterServerGrantCharacterToUserResultWrapper : public ModelWrapper<PFCharacterServerGrantCharacterToUserResult, Alloc>
{
public:
    using ModelType = typename PFCharacterServerGrantCharacterToUserResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterServerGrantCharacterToUserResultWrapper() = default;

    PFCharacterServerGrantCharacterToUserResultWrapper(const PFCharacterServerGrantCharacterToUserResult& model) :
        ModelWrapper<PFCharacterServerGrantCharacterToUserResult, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) }
    {
        SetModelPointers();
    }

    PFCharacterServerGrantCharacterToUserResultWrapper(const PFCharacterServerGrantCharacterToUserResultWrapper& src) :
        PFCharacterServerGrantCharacterToUserResultWrapper{ src.Model() }
    {
    }

    PFCharacterServerGrantCharacterToUserResultWrapper(PFCharacterServerGrantCharacterToUserResultWrapper&& src) :
        PFCharacterServerGrantCharacterToUserResultWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterServerGrantCharacterToUserResultWrapper& operator=(PFCharacterServerGrantCharacterToUserResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterServerGrantCharacterToUserResultWrapper() = default;

    friend void swap(PFCharacterServerGrantCharacterToUserResultWrapper& lhs, PFCharacterServerGrantCharacterToUserResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
    }

    String m_characterId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterServerUpdateCharacterDataRequestWrapper : public ModelWrapper<PFCharacterServerUpdateCharacterDataRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterServerUpdateCharacterDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterServerUpdateCharacterDataRequestWrapper() = default;

    PFCharacterServerUpdateCharacterDataRequestWrapper(const PFCharacterServerUpdateCharacterDataRequest& model) :
        ModelWrapper<PFCharacterServerUpdateCharacterDataRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_data{ model.data, model.data + model.dataCount },
        m_keysToRemove{ model.keysToRemove, model.keysToRemove + model.keysToRemoveCount },
        m_permission{ model.permission ? StdExtra::optional<PFUserDataPermission>{ *model.permission } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFCharacterServerUpdateCharacterDataRequestWrapper(const PFCharacterServerUpdateCharacterDataRequestWrapper& src) :
        PFCharacterServerUpdateCharacterDataRequestWrapper{ src.Model() }
    {
    }

    PFCharacterServerUpdateCharacterDataRequestWrapper(PFCharacterServerUpdateCharacterDataRequestWrapper&& src) :
        PFCharacterServerUpdateCharacterDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterServerUpdateCharacterDataRequestWrapper& operator=(PFCharacterServerUpdateCharacterDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterServerUpdateCharacterDataRequestWrapper() = default;

    friend void swap(PFCharacterServerUpdateCharacterDataRequestWrapper& lhs, PFCharacterServerUpdateCharacterDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_keysToRemove, rhs.m_keysToRemove);
        swap(lhs.m_permission, rhs.m_permission);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetData(StringDictionaryEntryVector<Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

    void SetKeysToRemove(CStringVector<Alloc> value)
    {
        m_keysToRemove = std::move(value);
        this->m_model.keysToRemove =  m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.keysToRemoveCount =  static_cast<uint32_t>(m_keysToRemove.size());
    }

    void SetPermission(StdExtra::optional<PFUserDataPermission> value)
    {
        m_permission = std::move(value);
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.keysToRemove = m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_data;
    CStringVector<Alloc> m_keysToRemove;
    StdExtra::optional<PFUserDataPermission> m_permission;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterServerUpdateCharacterStatisticsRequestWrapper : public ModelWrapper<PFCharacterServerUpdateCharacterStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFCharacterServerUpdateCharacterStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterServerUpdateCharacterStatisticsRequestWrapper() = default;

    PFCharacterServerUpdateCharacterStatisticsRequestWrapper(const PFCharacterServerUpdateCharacterStatisticsRequest& model) :
        ModelWrapper<PFCharacterServerUpdateCharacterStatisticsRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_characterStatistics{ model.characterStatistics, model.characterStatistics + model.characterStatisticsCount },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFCharacterServerUpdateCharacterStatisticsRequestWrapper(const PFCharacterServerUpdateCharacterStatisticsRequestWrapper& src) :
        PFCharacterServerUpdateCharacterStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFCharacterServerUpdateCharacterStatisticsRequestWrapper(PFCharacterServerUpdateCharacterStatisticsRequestWrapper&& src) :
        PFCharacterServerUpdateCharacterStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterServerUpdateCharacterStatisticsRequestWrapper& operator=(PFCharacterServerUpdateCharacterStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterServerUpdateCharacterStatisticsRequestWrapper() = default;

    friend void swap(PFCharacterServerUpdateCharacterStatisticsRequestWrapper& lhs, PFCharacterServerUpdateCharacterStatisticsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_characterStatistics, rhs.m_characterStatistics);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCharacterStatistics(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_characterStatistics = std::move(value);
        this->m_model.characterStatistics =  m_characterStatistics.empty() ? nullptr : m_characterStatistics.data();
        this->m_model.characterStatisticsCount =  static_cast<uint32_t>(m_characterStatistics.size());
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
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.characterStatistics = m_characterStatistics.empty() ? nullptr : m_characterStatistics.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_characterStatistics;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
};

} // namespace Wrappers
} // namespace PlayFab
