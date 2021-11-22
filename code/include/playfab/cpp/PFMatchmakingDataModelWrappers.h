// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFMatchmakingDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetMatchmakerGameInfoRequestWrapper : public ModelWrapper<PFMatchmakingGetMatchmakerGameInfoRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetMatchmakerGameInfoRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetMatchmakerGameInfoRequestWrapper() = default;

    PFMatchmakingGetMatchmakerGameInfoRequestWrapper(const PFMatchmakingGetMatchmakerGameInfoRequest& model) :
        ModelWrapper<PFMatchmakingGetMatchmakerGameInfoRequest, Alloc>{ model },
        m_lobbyId{ SafeString(model.lobbyId) }
    {
        SetModelPointers();
    }

    PFMatchmakingGetMatchmakerGameInfoRequestWrapper(const PFMatchmakingGetMatchmakerGameInfoRequestWrapper& src) :
        PFMatchmakingGetMatchmakerGameInfoRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetMatchmakerGameInfoRequestWrapper(PFMatchmakingGetMatchmakerGameInfoRequestWrapper&& src) :
        PFMatchmakingGetMatchmakerGameInfoRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetMatchmakerGameInfoRequestWrapper& operator=(PFMatchmakingGetMatchmakerGameInfoRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetMatchmakerGameInfoRequestWrapper() = default;

    friend void swap(PFMatchmakingGetMatchmakerGameInfoRequestWrapper& lhs, PFMatchmakingGetMatchmakerGameInfoRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    String m_lobbyId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetMatchmakerGameInfoResultWrapper : public ModelWrapper<PFMatchmakingGetMatchmakerGameInfoResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetMatchmakerGameInfoResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetMatchmakerGameInfoResultWrapper() = default;

    PFMatchmakingGetMatchmakerGameInfoResultWrapper(const PFMatchmakingGetMatchmakerGameInfoResult& model) :
        ModelWrapper<PFMatchmakingGetMatchmakerGameInfoResult, Alloc>{ model },
        m_buildVersion{ SafeString(model.buildVersion) },
        m_endTime{ model.endTime ? StdExtra::optional<time_t>{ *model.endTime } : StdExtra::nullopt },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_mode{ SafeString(model.mode) },
        m_players{ model.players, model.players + model.playersCount },
        m_region{ model.region ? StdExtra::optional<PFRegion>{ *model.region } : StdExtra::nullopt },
        m_serverIPV4Address{ SafeString(model.serverIPV4Address) },
        m_serverIPV6Address{ SafeString(model.serverIPV6Address) },
        m_serverPublicDNSName{ SafeString(model.serverPublicDNSName) },
        m_titleId{ SafeString(model.titleId) }
    {
        SetModelPointers();
    }

    PFMatchmakingGetMatchmakerGameInfoResultWrapper(const PFMatchmakingGetMatchmakerGameInfoResultWrapper& src) :
        PFMatchmakingGetMatchmakerGameInfoResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetMatchmakerGameInfoResultWrapper(PFMatchmakingGetMatchmakerGameInfoResultWrapper&& src) :
        PFMatchmakingGetMatchmakerGameInfoResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetMatchmakerGameInfoResultWrapper& operator=(PFMatchmakingGetMatchmakerGameInfoResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetMatchmakerGameInfoResultWrapper() = default;

    friend void swap(PFMatchmakingGetMatchmakerGameInfoResultWrapper& lhs, PFMatchmakingGetMatchmakerGameInfoResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildVersion, rhs.m_buildVersion);
        swap(lhs.m_endTime, rhs.m_endTime);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_mode, rhs.m_mode);
        swap(lhs.m_players, rhs.m_players);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_serverIPV4Address, rhs.m_serverIPV4Address);
        swap(lhs.m_serverIPV6Address, rhs.m_serverIPV6Address);
        swap(lhs.m_serverPublicDNSName, rhs.m_serverPublicDNSName);
        swap(lhs.m_titleId, rhs.m_titleId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildVersion(String value)
    {
        m_buildVersion = std::move(value);
        this->m_model.buildVersion =  m_buildVersion.empty() ? nullptr : m_buildVersion.data();
    }

    void SetEndTime(StdExtra::optional<time_t> value)
    {
        m_endTime = std::move(value);
        this->m_model.endTime = m_endTime ? m_endTime.operator->() : nullptr;
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetMode(String value)
    {
        m_mode = std::move(value);
        this->m_model.mode =  m_mode.empty() ? nullptr : m_mode.data();
    }

    void SetPlayers(CStringVector<Alloc> value)
    {
        m_players = std::move(value);
        this->m_model.players =  m_players.empty() ? nullptr : m_players.data();
        this->m_model.playersCount =  static_cast<uint32_t>(m_players.size());
    }

    void SetRegion(StdExtra::optional<PFRegion> value)
    {
        m_region = std::move(value);
        this->m_model.region = m_region ? m_region.operator->() : nullptr;
    }

    void SetServerIPV4Address(String value)
    {
        m_serverIPV4Address = std::move(value);
        this->m_model.serverIPV4Address =  m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
    }

    void SetServerIPV6Address(String value)
    {
        m_serverIPV6Address = std::move(value);
        this->m_model.serverIPV6Address =  m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
    }

    void SetServerPort(uint32_t value)
    {
        this->m_model.serverPort = value;
    }

    void SetServerPublicDNSName(String value)
    {
        m_serverPublicDNSName = std::move(value);
        this->m_model.serverPublicDNSName =  m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
    }

    void SetStartTime(time_t value)
    {
        this->m_model.startTime = value;
    }

    void SetTitleId(String value)
    {
        m_titleId = std::move(value);
        this->m_model.titleId =  m_titleId.empty() ? nullptr : m_titleId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildVersion = m_buildVersion.empty() ? nullptr : m_buildVersion.data();
        this->m_model.endTime = m_endTime ? m_endTime.operator->() : nullptr;
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.mode = m_mode.empty() ? nullptr : m_mode.data();
        this->m_model.players = m_players.empty() ? nullptr : m_players.data();
        this->m_model.region = m_region ? m_region.operator->() : nullptr;
        this->m_model.serverIPV4Address = m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
        this->m_model.serverIPV6Address = m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
        this->m_model.serverPublicDNSName = m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
    }

    String m_buildVersion;
    StdExtra::optional<time_t> m_endTime;
    String m_lobbyId;
    String m_mode;
    CStringVector<Alloc> m_players;
    StdExtra::optional<PFRegion> m_region;
    String m_serverIPV4Address;
    String m_serverIPV6Address;
    String m_serverPublicDNSName;
    String m_titleId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetMatchmakerGameModesRequestWrapper : public ModelWrapper<PFMatchmakingGetMatchmakerGameModesRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetMatchmakerGameModesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetMatchmakerGameModesRequestWrapper() = default;

    PFMatchmakingGetMatchmakerGameModesRequestWrapper(const PFMatchmakingGetMatchmakerGameModesRequest& model) :
        ModelWrapper<PFMatchmakingGetMatchmakerGameModesRequest, Alloc>{ model },
        m_buildVersion{ SafeString(model.buildVersion) }
    {
        SetModelPointers();
    }

    PFMatchmakingGetMatchmakerGameModesRequestWrapper(const PFMatchmakingGetMatchmakerGameModesRequestWrapper& src) :
        PFMatchmakingGetMatchmakerGameModesRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetMatchmakerGameModesRequestWrapper(PFMatchmakingGetMatchmakerGameModesRequestWrapper&& src) :
        PFMatchmakingGetMatchmakerGameModesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetMatchmakerGameModesRequestWrapper& operator=(PFMatchmakingGetMatchmakerGameModesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetMatchmakerGameModesRequestWrapper() = default;

    friend void swap(PFMatchmakingGetMatchmakerGameModesRequestWrapper& lhs, PFMatchmakingGetMatchmakerGameModesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildVersion, rhs.m_buildVersion);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildVersion(String value)
    {
        m_buildVersion = std::move(value);
        this->m_model.buildVersion =  m_buildVersion.empty() ? nullptr : m_buildVersion.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildVersion = m_buildVersion.empty() ? nullptr : m_buildVersion.data();
    }

    String m_buildVersion;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGameModeInfoWrapper : public ModelWrapper<PFMatchmakingGameModeInfo, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGameModeInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGameModeInfoWrapper() = default;

    PFMatchmakingGameModeInfoWrapper(const PFMatchmakingGameModeInfo& model) :
        ModelWrapper<PFMatchmakingGameModeInfo, Alloc>{ model },
        m_gamemode{ SafeString(model.gamemode) },
        m_startOpen{ model.startOpen ? StdExtra::optional<bool>{ *model.startOpen } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMatchmakingGameModeInfoWrapper(const PFMatchmakingGameModeInfoWrapper& src) :
        PFMatchmakingGameModeInfoWrapper{ src.Model() }
    {
    }

    PFMatchmakingGameModeInfoWrapper(PFMatchmakingGameModeInfoWrapper&& src) :
        PFMatchmakingGameModeInfoWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGameModeInfoWrapper& operator=(PFMatchmakingGameModeInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGameModeInfoWrapper() = default;

    friend void swap(PFMatchmakingGameModeInfoWrapper& lhs, PFMatchmakingGameModeInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_gamemode, rhs.m_gamemode);
        swap(lhs.m_startOpen, rhs.m_startOpen);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGamemode(String value)
    {
        m_gamemode = std::move(value);
        this->m_model.gamemode =  m_gamemode.empty() ? nullptr : m_gamemode.data();
    }

    void SetMaxPlayerCount(uint32_t value)
    {
        this->m_model.maxPlayerCount = value;
    }

    void SetMinPlayerCount(uint32_t value)
    {
        this->m_model.minPlayerCount = value;
    }

    void SetStartOpen(StdExtra::optional<bool> value)
    {
        m_startOpen = std::move(value);
        this->m_model.startOpen = m_startOpen ? m_startOpen.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.gamemode = m_gamemode.empty() ? nullptr : m_gamemode.data();
        this->m_model.startOpen = m_startOpen ? m_startOpen.operator->() : nullptr;
    }

    String m_gamemode;
    StdExtra::optional<bool> m_startOpen;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetMatchmakerGameModesResultWrapper : public ModelWrapper<PFMatchmakingGetMatchmakerGameModesResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetMatchmakerGameModesResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetMatchmakerGameModesResultWrapper() = default;

    PFMatchmakingGetMatchmakerGameModesResultWrapper(const PFMatchmakingGetMatchmakerGameModesResult& model) :
        ModelWrapper<PFMatchmakingGetMatchmakerGameModesResult, Alloc>{ model },
        m_gameModes{ model.gameModes, model.gameModes + model.gameModesCount }
    {
        SetModelPointers();
    }

    PFMatchmakingGetMatchmakerGameModesResultWrapper(const PFMatchmakingGetMatchmakerGameModesResultWrapper& src) :
        PFMatchmakingGetMatchmakerGameModesResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetMatchmakerGameModesResultWrapper(PFMatchmakingGetMatchmakerGameModesResultWrapper&& src) :
        PFMatchmakingGetMatchmakerGameModesResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetMatchmakerGameModesResultWrapper& operator=(PFMatchmakingGetMatchmakerGameModesResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetMatchmakerGameModesResultWrapper() = default;

    friend void swap(PFMatchmakingGetMatchmakerGameModesResultWrapper& lhs, PFMatchmakingGetMatchmakerGameModesResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_gameModes, rhs.m_gameModes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGameModes(ModelVector<PFMatchmakingGameModeInfoWrapper<Alloc>, Alloc> value)
    {
        m_gameModes = std::move(value);
        this->m_model.gameModes =  m_gameModes.empty() ? nullptr : m_gameModes.data();
        this->m_model.gameModesCount =  static_cast<uint32_t>(m_gameModes.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.gameModes = m_gameModes.empty() ? nullptr : m_gameModes.data();
    }

    ModelVector<PFMatchmakingGameModeInfoWrapper<Alloc>, Alloc> m_gameModes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingModifyMatchmakerGameModesRequestWrapper : public ModelWrapper<PFMatchmakingModifyMatchmakerGameModesRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingModifyMatchmakerGameModesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingModifyMatchmakerGameModesRequestWrapper() = default;

    PFMatchmakingModifyMatchmakerGameModesRequestWrapper(const PFMatchmakingModifyMatchmakerGameModesRequest& model) :
        ModelWrapper<PFMatchmakingModifyMatchmakerGameModesRequest, Alloc>{ model },
        m_buildVersion{ SafeString(model.buildVersion) },
        m_gameModes{ model.gameModes, model.gameModes + model.gameModesCount }
    {
        SetModelPointers();
    }

    PFMatchmakingModifyMatchmakerGameModesRequestWrapper(const PFMatchmakingModifyMatchmakerGameModesRequestWrapper& src) :
        PFMatchmakingModifyMatchmakerGameModesRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingModifyMatchmakerGameModesRequestWrapper(PFMatchmakingModifyMatchmakerGameModesRequestWrapper&& src) :
        PFMatchmakingModifyMatchmakerGameModesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingModifyMatchmakerGameModesRequestWrapper& operator=(PFMatchmakingModifyMatchmakerGameModesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingModifyMatchmakerGameModesRequestWrapper() = default;

    friend void swap(PFMatchmakingModifyMatchmakerGameModesRequestWrapper& lhs, PFMatchmakingModifyMatchmakerGameModesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildVersion, rhs.m_buildVersion);
        swap(lhs.m_gameModes, rhs.m_gameModes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildVersion(String value)
    {
        m_buildVersion = std::move(value);
        this->m_model.buildVersion =  m_buildVersion.empty() ? nullptr : m_buildVersion.data();
    }

    void SetGameModes(ModelVector<PFMatchmakingGameModeInfoWrapper<Alloc>, Alloc> value)
    {
        m_gameModes = std::move(value);
        this->m_model.gameModes =  m_gameModes.empty() ? nullptr : m_gameModes.data();
        this->m_model.gameModesCount =  static_cast<uint32_t>(m_gameModes.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildVersion = m_buildVersion.empty() ? nullptr : m_buildVersion.data();
        this->m_model.gameModes = m_gameModes.empty() ? nullptr : m_gameModes.data();
    }

    String m_buildVersion;
    ModelVector<PFMatchmakingGameModeInfoWrapper<Alloc>, Alloc> m_gameModes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingContainer_Dictionary_String_StringWrapper : public ModelWrapper<PFMatchmakingContainer_Dictionary_String_String, Alloc>
{
public:
    using ModelType = typename PFMatchmakingContainer_Dictionary_String_String;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingContainer_Dictionary_String_StringWrapper() = default;

    PFMatchmakingContainer_Dictionary_String_StringWrapper(const PFMatchmakingContainer_Dictionary_String_String& model) :
        ModelWrapper<PFMatchmakingContainer_Dictionary_String_String, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFMatchmakingContainer_Dictionary_String_StringWrapper(const PFMatchmakingContainer_Dictionary_String_StringWrapper& src) :
        PFMatchmakingContainer_Dictionary_String_StringWrapper{ src.Model() }
    {
    }

    PFMatchmakingContainer_Dictionary_String_StringWrapper(PFMatchmakingContainer_Dictionary_String_StringWrapper&& src) :
        PFMatchmakingContainer_Dictionary_String_StringWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingContainer_Dictionary_String_StringWrapper& operator=(PFMatchmakingContainer_Dictionary_String_StringWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingContainer_Dictionary_String_StringWrapper() = default;

    friend void swap(PFMatchmakingContainer_Dictionary_String_StringWrapper& lhs, PFMatchmakingContainer_Dictionary_String_StringWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(StringDictionaryEntryVector<Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    StringDictionaryEntryVector<Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCollectionFilterWrapper : public ModelWrapper<PFMatchmakingCollectionFilter, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCollectionFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCollectionFilterWrapper() = default;

    PFMatchmakingCollectionFilterWrapper(const PFMatchmakingCollectionFilter& model) :
        ModelWrapper<PFMatchmakingCollectionFilter, Alloc>{ model },
        m_excludes{ model.excludes, model.excludes + model.excludesCount },
        m_includes{ model.includes, model.includes + model.includesCount }
    {
        SetModelPointers();
    }

    PFMatchmakingCollectionFilterWrapper(const PFMatchmakingCollectionFilterWrapper& src) :
        PFMatchmakingCollectionFilterWrapper{ src.Model() }
    {
    }

    PFMatchmakingCollectionFilterWrapper(PFMatchmakingCollectionFilterWrapper&& src) :
        PFMatchmakingCollectionFilterWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCollectionFilterWrapper& operator=(PFMatchmakingCollectionFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCollectionFilterWrapper() = default;

    friend void swap(PFMatchmakingCollectionFilterWrapper& lhs, PFMatchmakingCollectionFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_excludes, rhs.m_excludes);
        swap(lhs.m_includes, rhs.m_includes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetExcludes(ModelVector<PFMatchmakingContainer_Dictionary_String_StringWrapper<Alloc>, Alloc> value)
    {
        m_excludes = std::move(value);
        this->m_model.excludes =  m_excludes.empty() ? nullptr : m_excludes.data();
        this->m_model.excludesCount =  static_cast<uint32_t>(m_excludes.size());
    }

    void SetIncludes(ModelVector<PFMatchmakingContainer_Dictionary_String_StringWrapper<Alloc>, Alloc> value)
    {
        m_includes = std::move(value);
        this->m_model.includes =  m_includes.empty() ? nullptr : m_includes.data();
        this->m_model.includesCount =  static_cast<uint32_t>(m_includes.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.excludes = m_excludes.empty() ? nullptr : m_excludes.data();
        this->m_model.includes = m_includes.empty() ? nullptr : m_includes.data();
    }

    ModelVector<PFMatchmakingContainer_Dictionary_String_StringWrapper<Alloc>, Alloc> m_excludes;
    ModelVector<PFMatchmakingContainer_Dictionary_String_StringWrapper<Alloc>, Alloc> m_includes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCurrentGamesRequestWrapper : public ModelWrapper<PFMatchmakingCurrentGamesRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCurrentGamesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCurrentGamesRequestWrapper() = default;

    PFMatchmakingCurrentGamesRequestWrapper(const PFMatchmakingCurrentGamesRequest& model) :
        ModelWrapper<PFMatchmakingCurrentGamesRequest, Alloc>{ model },
        m_buildVersion{ SafeString(model.buildVersion) },
        m_gameMode{ SafeString(model.gameMode) },
        m_region{ model.region ? StdExtra::optional<PFRegion>{ *model.region } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_tagFilter{ model.tagFilter ? StdExtra::optional<PFMatchmakingCollectionFilterWrapper<Alloc>>{ *model.tagFilter } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMatchmakingCurrentGamesRequestWrapper(const PFMatchmakingCurrentGamesRequestWrapper& src) :
        PFMatchmakingCurrentGamesRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingCurrentGamesRequestWrapper(PFMatchmakingCurrentGamesRequestWrapper&& src) :
        PFMatchmakingCurrentGamesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCurrentGamesRequestWrapper& operator=(PFMatchmakingCurrentGamesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCurrentGamesRequestWrapper() = default;

    friend void swap(PFMatchmakingCurrentGamesRequestWrapper& lhs, PFMatchmakingCurrentGamesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildVersion, rhs.m_buildVersion);
        swap(lhs.m_gameMode, rhs.m_gameMode);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_tagFilter, rhs.m_tagFilter);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildVersion(String value)
    {
        m_buildVersion = std::move(value);
        this->m_model.buildVersion =  m_buildVersion.empty() ? nullptr : m_buildVersion.data();
    }

    void SetGameMode(String value)
    {
        m_gameMode = std::move(value);
        this->m_model.gameMode =  m_gameMode.empty() ? nullptr : m_gameMode.data();
    }

    void SetRegion(StdExtra::optional<PFRegion> value)
    {
        m_region = std::move(value);
        this->m_model.region = m_region ? m_region.operator->() : nullptr;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetTagFilter(StdExtra::optional<PFMatchmakingCollectionFilterWrapper<Alloc>> value)
    {
        m_tagFilter = std::move(value);
        this->m_model.tagFilter = m_tagFilter ? &m_tagFilter->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildVersion = m_buildVersion.empty() ? nullptr : m_buildVersion.data();
        this->m_model.gameMode = m_gameMode.empty() ? nullptr : m_gameMode.data();
        this->m_model.region = m_region ? m_region.operator->() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.tagFilter = m_tagFilter ?  &m_tagFilter->Model() : nullptr;
    }

    String m_buildVersion;
    String m_gameMode;
    StdExtra::optional<PFRegion> m_region;
    String m_statisticName;
    StdExtra::optional<PFMatchmakingCollectionFilterWrapper<Alloc>> m_tagFilter;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGameInfoWrapper : public ModelWrapper<PFMatchmakingGameInfo, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGameInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGameInfoWrapper() = default;

    PFMatchmakingGameInfoWrapper(const PFMatchmakingGameInfo& model) :
        ModelWrapper<PFMatchmakingGameInfo, Alloc>{ model },
        m_buildVersion{ SafeString(model.buildVersion) },
        m_gameMode{ SafeString(model.gameMode) },
        m_gameServerData{ SafeString(model.gameServerData) },
        m_gameServerStateEnum{ model.gameServerStateEnum ? StdExtra::optional<PFMatchmakingGameInstanceState>{ *model.gameServerStateEnum } : StdExtra::nullopt },
        m_lastHeartbeat{ model.lastHeartbeat ? StdExtra::optional<time_t>{ *model.lastHeartbeat } : StdExtra::nullopt },
        m_lobbyID{ SafeString(model.lobbyID) },
        m_maxPlayers{ model.maxPlayers ? StdExtra::optional<int32_t>{ *model.maxPlayers } : StdExtra::nullopt },
        m_playerUserIds{ model.playerUserIds, model.playerUserIds + model.playerUserIdsCount },
        m_region{ model.region ? StdExtra::optional<PFRegion>{ *model.region } : StdExtra::nullopt },
        m_serverIPV4Address{ SafeString(model.serverIPV4Address) },
        m_serverIPV6Address{ SafeString(model.serverIPV6Address) },
        m_serverPort{ model.serverPort ? StdExtra::optional<int32_t>{ *model.serverPort } : StdExtra::nullopt },
        m_serverPublicDNSName{ SafeString(model.serverPublicDNSName) },
        m_statisticName{ SafeString(model.statisticName) },
        m_tags{ model.tags, model.tags + model.tagsCount }
    {
        SetModelPointers();
    }

    PFMatchmakingGameInfoWrapper(const PFMatchmakingGameInfoWrapper& src) :
        PFMatchmakingGameInfoWrapper{ src.Model() }
    {
    }

    PFMatchmakingGameInfoWrapper(PFMatchmakingGameInfoWrapper&& src) :
        PFMatchmakingGameInfoWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGameInfoWrapper& operator=(PFMatchmakingGameInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGameInfoWrapper() = default;

    friend void swap(PFMatchmakingGameInfoWrapper& lhs, PFMatchmakingGameInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildVersion, rhs.m_buildVersion);
        swap(lhs.m_gameMode, rhs.m_gameMode);
        swap(lhs.m_gameServerData, rhs.m_gameServerData);
        swap(lhs.m_gameServerStateEnum, rhs.m_gameServerStateEnum);
        swap(lhs.m_lastHeartbeat, rhs.m_lastHeartbeat);
        swap(lhs.m_lobbyID, rhs.m_lobbyID);
        swap(lhs.m_maxPlayers, rhs.m_maxPlayers);
        swap(lhs.m_playerUserIds, rhs.m_playerUserIds);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_serverIPV4Address, rhs.m_serverIPV4Address);
        swap(lhs.m_serverIPV6Address, rhs.m_serverIPV6Address);
        swap(lhs.m_serverPort, rhs.m_serverPort);
        swap(lhs.m_serverPublicDNSName, rhs.m_serverPublicDNSName);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_tags, rhs.m_tags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildVersion(String value)
    {
        m_buildVersion = std::move(value);
        this->m_model.buildVersion =  m_buildVersion.empty() ? nullptr : m_buildVersion.data();
    }

    void SetGameMode(String value)
    {
        m_gameMode = std::move(value);
        this->m_model.gameMode =  m_gameMode.empty() ? nullptr : m_gameMode.data();
    }

    void SetGameServerData(String value)
    {
        m_gameServerData = std::move(value);
        this->m_model.gameServerData =  m_gameServerData.empty() ? nullptr : m_gameServerData.data();
    }

    void SetGameServerStateEnum(StdExtra::optional<PFMatchmakingGameInstanceState> value)
    {
        m_gameServerStateEnum = std::move(value);
        this->m_model.gameServerStateEnum = m_gameServerStateEnum ? m_gameServerStateEnum.operator->() : nullptr;
    }

    void SetLastHeartbeat(StdExtra::optional<time_t> value)
    {
        m_lastHeartbeat = std::move(value);
        this->m_model.lastHeartbeat = m_lastHeartbeat ? m_lastHeartbeat.operator->() : nullptr;
    }

    void SetLobbyID(String value)
    {
        m_lobbyID = std::move(value);
        this->m_model.lobbyID =  m_lobbyID.empty() ? nullptr : m_lobbyID.data();
    }

    void SetMaxPlayers(StdExtra::optional<int32_t> value)
    {
        m_maxPlayers = std::move(value);
        this->m_model.maxPlayers = m_maxPlayers ? m_maxPlayers.operator->() : nullptr;
    }

    void SetPlayerUserIds(CStringVector<Alloc> value)
    {
        m_playerUserIds = std::move(value);
        this->m_model.playerUserIds =  m_playerUserIds.empty() ? nullptr : m_playerUserIds.data();
        this->m_model.playerUserIdsCount =  static_cast<uint32_t>(m_playerUserIds.size());
    }

    void SetRegion(StdExtra::optional<PFRegion> value)
    {
        m_region = std::move(value);
        this->m_model.region = m_region ? m_region.operator->() : nullptr;
    }

    void SetRunTime(uint32_t value)
    {
        this->m_model.runTime = value;
    }

    void SetServerIPV4Address(String value)
    {
        m_serverIPV4Address = std::move(value);
        this->m_model.serverIPV4Address =  m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
    }

    void SetServerIPV6Address(String value)
    {
        m_serverIPV6Address = std::move(value);
        this->m_model.serverIPV6Address =  m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
    }

    void SetServerPort(StdExtra::optional<int32_t> value)
    {
        m_serverPort = std::move(value);
        this->m_model.serverPort = m_serverPort ? m_serverPort.operator->() : nullptr;
    }

    void SetServerPublicDNSName(String value)
    {
        m_serverPublicDNSName = std::move(value);
        this->m_model.serverPublicDNSName =  m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_tags = std::move(value);
        this->m_model.tags =  m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.tagsCount =  static_cast<uint32_t>(m_tags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildVersion = m_buildVersion.empty() ? nullptr : m_buildVersion.data();
        this->m_model.gameMode = m_gameMode.empty() ? nullptr : m_gameMode.data();
        this->m_model.gameServerData = m_gameServerData.empty() ? nullptr : m_gameServerData.data();
        this->m_model.gameServerStateEnum = m_gameServerStateEnum ? m_gameServerStateEnum.operator->() : nullptr;
        this->m_model.lastHeartbeat = m_lastHeartbeat ? m_lastHeartbeat.operator->() : nullptr;
        this->m_model.lobbyID = m_lobbyID.empty() ? nullptr : m_lobbyID.data();
        this->m_model.maxPlayers = m_maxPlayers ? m_maxPlayers.operator->() : nullptr;
        this->m_model.playerUserIds = m_playerUserIds.empty() ? nullptr : m_playerUserIds.data();
        this->m_model.region = m_region ? m_region.operator->() : nullptr;
        this->m_model.serverIPV4Address = m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
        this->m_model.serverIPV6Address = m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
        this->m_model.serverPort = m_serverPort ? m_serverPort.operator->() : nullptr;
        this->m_model.serverPublicDNSName = m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.tags = m_tags.empty() ? nullptr : m_tags.data();
    }

    String m_buildVersion;
    String m_gameMode;
    String m_gameServerData;
    StdExtra::optional<PFMatchmakingGameInstanceState> m_gameServerStateEnum;
    StdExtra::optional<time_t> m_lastHeartbeat;
    String m_lobbyID;
    StdExtra::optional<int32_t> m_maxPlayers;
    CStringVector<Alloc> m_playerUserIds;
    StdExtra::optional<PFRegion> m_region;
    String m_serverIPV4Address;
    String m_serverIPV6Address;
    StdExtra::optional<int32_t> m_serverPort;
    String m_serverPublicDNSName;
    String m_statisticName;
    StringDictionaryEntryVector<Alloc> m_tags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCurrentGamesResultWrapper : public ModelWrapper<PFMatchmakingCurrentGamesResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCurrentGamesResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCurrentGamesResultWrapper() = default;

    PFMatchmakingCurrentGamesResultWrapper(const PFMatchmakingCurrentGamesResult& model) :
        ModelWrapper<PFMatchmakingCurrentGamesResult, Alloc>{ model },
        m_games{ model.games, model.games + model.gamesCount }
    {
        SetModelPointers();
    }

    PFMatchmakingCurrentGamesResultWrapper(const PFMatchmakingCurrentGamesResultWrapper& src) :
        PFMatchmakingCurrentGamesResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingCurrentGamesResultWrapper(PFMatchmakingCurrentGamesResultWrapper&& src) :
        PFMatchmakingCurrentGamesResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCurrentGamesResultWrapper& operator=(PFMatchmakingCurrentGamesResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCurrentGamesResultWrapper() = default;

    friend void swap(PFMatchmakingCurrentGamesResultWrapper& lhs, PFMatchmakingCurrentGamesResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_games, rhs.m_games);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGameCount(int32_t value)
    {
        this->m_model.gameCount = value;
    }

    void SetGames(ModelVector<PFMatchmakingGameInfoWrapper<Alloc>, Alloc> value)
    {
        m_games = std::move(value);
        this->m_model.games =  m_games.empty() ? nullptr : m_games.data();
        this->m_model.gamesCount =  static_cast<uint32_t>(m_games.size());
    }

    void SetPlayerCount(int32_t value)
    {
        this->m_model.playerCount = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.games = m_games.empty() ? nullptr : m_games.data();
    }

    ModelVector<PFMatchmakingGameInfoWrapper<Alloc>, Alloc> m_games;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGameServerRegionsRequestWrapper : public ModelWrapper<PFMatchmakingGameServerRegionsRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGameServerRegionsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGameServerRegionsRequestWrapper() = default;

    PFMatchmakingGameServerRegionsRequestWrapper(const PFMatchmakingGameServerRegionsRequest& model) :
        ModelWrapper<PFMatchmakingGameServerRegionsRequest, Alloc>{ model },
        m_buildVersion{ SafeString(model.buildVersion) },
        m_titleId{ SafeString(model.titleId) }
    {
        SetModelPointers();
    }

    PFMatchmakingGameServerRegionsRequestWrapper(const PFMatchmakingGameServerRegionsRequestWrapper& src) :
        PFMatchmakingGameServerRegionsRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingGameServerRegionsRequestWrapper(PFMatchmakingGameServerRegionsRequestWrapper&& src) :
        PFMatchmakingGameServerRegionsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGameServerRegionsRequestWrapper& operator=(PFMatchmakingGameServerRegionsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGameServerRegionsRequestWrapper() = default;

    friend void swap(PFMatchmakingGameServerRegionsRequestWrapper& lhs, PFMatchmakingGameServerRegionsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildVersion, rhs.m_buildVersion);
        swap(lhs.m_titleId, rhs.m_titleId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildVersion(String value)
    {
        m_buildVersion = std::move(value);
        this->m_model.buildVersion =  m_buildVersion.empty() ? nullptr : m_buildVersion.data();
    }

    void SetTitleId(String value)
    {
        m_titleId = std::move(value);
        this->m_model.titleId =  m_titleId.empty() ? nullptr : m_titleId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildVersion = m_buildVersion.empty() ? nullptr : m_buildVersion.data();
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
    }

    String m_buildVersion;
    String m_titleId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingRegionInfoWrapper : public ModelWrapper<PFMatchmakingRegionInfo, Alloc>
{
public:
    using ModelType = typename PFMatchmakingRegionInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingRegionInfoWrapper() = default;

    PFMatchmakingRegionInfoWrapper(const PFMatchmakingRegionInfo& model) :
        ModelWrapper<PFMatchmakingRegionInfo, Alloc>{ model },
        m_name{ SafeString(model.name) },
        m_pingUrl{ SafeString(model.pingUrl) },
        m_region{ model.region ? StdExtra::optional<PFRegion>{ *model.region } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMatchmakingRegionInfoWrapper(const PFMatchmakingRegionInfoWrapper& src) :
        PFMatchmakingRegionInfoWrapper{ src.Model() }
    {
    }

    PFMatchmakingRegionInfoWrapper(PFMatchmakingRegionInfoWrapper&& src) :
        PFMatchmakingRegionInfoWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingRegionInfoWrapper& operator=(PFMatchmakingRegionInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingRegionInfoWrapper() = default;

    friend void swap(PFMatchmakingRegionInfoWrapper& lhs, PFMatchmakingRegionInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_pingUrl, rhs.m_pingUrl);
        swap(lhs.m_region, rhs.m_region);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAvailable(bool value)
    {
        this->m_model.available = value;
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetPingUrl(String value)
    {
        m_pingUrl = std::move(value);
        this->m_model.pingUrl =  m_pingUrl.empty() ? nullptr : m_pingUrl.data();
    }

    void SetRegion(StdExtra::optional<PFRegion> value)
    {
        m_region = std::move(value);
        this->m_model.region = m_region ? m_region.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.pingUrl = m_pingUrl.empty() ? nullptr : m_pingUrl.data();
        this->m_model.region = m_region ? m_region.operator->() : nullptr;
    }

    String m_name;
    String m_pingUrl;
    StdExtra::optional<PFRegion> m_region;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGameServerRegionsResultWrapper : public ModelWrapper<PFMatchmakingGameServerRegionsResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGameServerRegionsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGameServerRegionsResultWrapper() = default;

    PFMatchmakingGameServerRegionsResultWrapper(const PFMatchmakingGameServerRegionsResult& model) :
        ModelWrapper<PFMatchmakingGameServerRegionsResult, Alloc>{ model },
        m_regions{ model.regions, model.regions + model.regionsCount }
    {
        SetModelPointers();
    }

    PFMatchmakingGameServerRegionsResultWrapper(const PFMatchmakingGameServerRegionsResultWrapper& src) :
        PFMatchmakingGameServerRegionsResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingGameServerRegionsResultWrapper(PFMatchmakingGameServerRegionsResultWrapper&& src) :
        PFMatchmakingGameServerRegionsResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGameServerRegionsResultWrapper& operator=(PFMatchmakingGameServerRegionsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGameServerRegionsResultWrapper() = default;

    friend void swap(PFMatchmakingGameServerRegionsResultWrapper& lhs, PFMatchmakingGameServerRegionsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_regions, rhs.m_regions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetRegions(ModelVector<PFMatchmakingRegionInfoWrapper<Alloc>, Alloc> value)
    {
        m_regions = std::move(value);
        this->m_model.regions =  m_regions.empty() ? nullptr : m_regions.data();
        this->m_model.regionsCount =  static_cast<uint32_t>(m_regions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.regions = m_regions.empty() ? nullptr : m_regions.data();
    }

    ModelVector<PFMatchmakingRegionInfoWrapper<Alloc>, Alloc> m_regions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingMatchmakeRequestWrapper : public ModelWrapper<PFMatchmakingMatchmakeRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingMatchmakeRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingMatchmakeRequestWrapper() = default;

    PFMatchmakingMatchmakeRequestWrapper(const PFMatchmakingMatchmakeRequest& model) :
        ModelWrapper<PFMatchmakingMatchmakeRequest, Alloc>{ model },
        m_buildVersion{ SafeString(model.buildVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_gameMode{ SafeString(model.gameMode) },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_region{ model.region ? StdExtra::optional<PFRegion>{ *model.region } : StdExtra::nullopt },
        m_startNewIfNoneFound{ model.startNewIfNoneFound ? StdExtra::optional<bool>{ *model.startNewIfNoneFound } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_tagFilter{ model.tagFilter ? StdExtra::optional<PFMatchmakingCollectionFilterWrapper<Alloc>>{ *model.tagFilter } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMatchmakingMatchmakeRequestWrapper(const PFMatchmakingMatchmakeRequestWrapper& src) :
        PFMatchmakingMatchmakeRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingMatchmakeRequestWrapper(PFMatchmakingMatchmakeRequestWrapper&& src) :
        PFMatchmakingMatchmakeRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingMatchmakeRequestWrapper& operator=(PFMatchmakingMatchmakeRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingMatchmakeRequestWrapper() = default;

    friend void swap(PFMatchmakingMatchmakeRequestWrapper& lhs, PFMatchmakingMatchmakeRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildVersion, rhs.m_buildVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_gameMode, rhs.m_gameMode);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_startNewIfNoneFound, rhs.m_startNewIfNoneFound);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_tagFilter, rhs.m_tagFilter);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildVersion(String value)
    {
        m_buildVersion = std::move(value);
        this->m_model.buildVersion =  m_buildVersion.empty() ? nullptr : m_buildVersion.data();
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

    void SetGameMode(String value)
    {
        m_gameMode = std::move(value);
        this->m_model.gameMode =  m_gameMode.empty() ? nullptr : m_gameMode.data();
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetRegion(StdExtra::optional<PFRegion> value)
    {
        m_region = std::move(value);
        this->m_model.region = m_region ? m_region.operator->() : nullptr;
    }

    void SetStartNewIfNoneFound(StdExtra::optional<bool> value)
    {
        m_startNewIfNoneFound = std::move(value);
        this->m_model.startNewIfNoneFound = m_startNewIfNoneFound ? m_startNewIfNoneFound.operator->() : nullptr;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetTagFilter(StdExtra::optional<PFMatchmakingCollectionFilterWrapper<Alloc>> value)
    {
        m_tagFilter = std::move(value);
        this->m_model.tagFilter = m_tagFilter ? &m_tagFilter->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildVersion = m_buildVersion.empty() ? nullptr : m_buildVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.gameMode = m_gameMode.empty() ? nullptr : m_gameMode.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.region = m_region ? m_region.operator->() : nullptr;
        this->m_model.startNewIfNoneFound = m_startNewIfNoneFound ? m_startNewIfNoneFound.operator->() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.tagFilter = m_tagFilter ?  &m_tagFilter->Model() : nullptr;
    }

    String m_buildVersion;
    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_gameMode;
    String m_lobbyId;
    StdExtra::optional<PFRegion> m_region;
    StdExtra::optional<bool> m_startNewIfNoneFound;
    String m_statisticName;
    StdExtra::optional<PFMatchmakingCollectionFilterWrapper<Alloc>> m_tagFilter;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingMatchmakeResultWrapper : public ModelWrapper<PFMatchmakingMatchmakeResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingMatchmakeResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingMatchmakeResultWrapper() = default;

    PFMatchmakingMatchmakeResultWrapper(const PFMatchmakingMatchmakeResult& model) :
        ModelWrapper<PFMatchmakingMatchmakeResult, Alloc>{ model },
        m_expires{ SafeString(model.expires) },
        m_lobbyID{ SafeString(model.lobbyID) },
        m_pollWaitTimeMS{ model.pollWaitTimeMS ? StdExtra::optional<int32_t>{ *model.pollWaitTimeMS } : StdExtra::nullopt },
        m_serverIPV4Address{ SafeString(model.serverIPV4Address) },
        m_serverIPV6Address{ SafeString(model.serverIPV6Address) },
        m_serverPort{ model.serverPort ? StdExtra::optional<int32_t>{ *model.serverPort } : StdExtra::nullopt },
        m_serverPublicDNSName{ SafeString(model.serverPublicDNSName) },
        m_status{ model.status ? StdExtra::optional<PFMatchmakingMatchmakeStatus>{ *model.status } : StdExtra::nullopt },
        m_ticket{ SafeString(model.ticket) }
    {
        SetModelPointers();
    }

    PFMatchmakingMatchmakeResultWrapper(const PFMatchmakingMatchmakeResultWrapper& src) :
        PFMatchmakingMatchmakeResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingMatchmakeResultWrapper(PFMatchmakingMatchmakeResultWrapper&& src) :
        PFMatchmakingMatchmakeResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingMatchmakeResultWrapper& operator=(PFMatchmakingMatchmakeResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingMatchmakeResultWrapper() = default;

    friend void swap(PFMatchmakingMatchmakeResultWrapper& lhs, PFMatchmakingMatchmakeResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_expires, rhs.m_expires);
        swap(lhs.m_lobbyID, rhs.m_lobbyID);
        swap(lhs.m_pollWaitTimeMS, rhs.m_pollWaitTimeMS);
        swap(lhs.m_serverIPV4Address, rhs.m_serverIPV4Address);
        swap(lhs.m_serverIPV6Address, rhs.m_serverIPV6Address);
        swap(lhs.m_serverPort, rhs.m_serverPort);
        swap(lhs.m_serverPublicDNSName, rhs.m_serverPublicDNSName);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_ticket, rhs.m_ticket);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetExpires(String value)
    {
        m_expires = std::move(value);
        this->m_model.expires =  m_expires.empty() ? nullptr : m_expires.data();
    }

    void SetLobbyID(String value)
    {
        m_lobbyID = std::move(value);
        this->m_model.lobbyID =  m_lobbyID.empty() ? nullptr : m_lobbyID.data();
    }

    void SetPollWaitTimeMS(StdExtra::optional<int32_t> value)
    {
        m_pollWaitTimeMS = std::move(value);
        this->m_model.pollWaitTimeMS = m_pollWaitTimeMS ? m_pollWaitTimeMS.operator->() : nullptr;
    }

    void SetServerIPV4Address(String value)
    {
        m_serverIPV4Address = std::move(value);
        this->m_model.serverIPV4Address =  m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
    }

    void SetServerIPV6Address(String value)
    {
        m_serverIPV6Address = std::move(value);
        this->m_model.serverIPV6Address =  m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
    }

    void SetServerPort(StdExtra::optional<int32_t> value)
    {
        m_serverPort = std::move(value);
        this->m_model.serverPort = m_serverPort ? m_serverPort.operator->() : nullptr;
    }

    void SetServerPublicDNSName(String value)
    {
        m_serverPublicDNSName = std::move(value);
        this->m_model.serverPublicDNSName =  m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
    }

    void SetStatus(StdExtra::optional<PFMatchmakingMatchmakeStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    void SetTicket(String value)
    {
        m_ticket = std::move(value);
        this->m_model.ticket =  m_ticket.empty() ? nullptr : m_ticket.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.expires = m_expires.empty() ? nullptr : m_expires.data();
        this->m_model.lobbyID = m_lobbyID.empty() ? nullptr : m_lobbyID.data();
        this->m_model.pollWaitTimeMS = m_pollWaitTimeMS ? m_pollWaitTimeMS.operator->() : nullptr;
        this->m_model.serverIPV4Address = m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
        this->m_model.serverIPV6Address = m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
        this->m_model.serverPort = m_serverPort ? m_serverPort.operator->() : nullptr;
        this->m_model.serverPublicDNSName = m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
        this->m_model.ticket = m_ticket.empty() ? nullptr : m_ticket.data();
    }

    String m_expires;
    String m_lobbyID;
    StdExtra::optional<int32_t> m_pollWaitTimeMS;
    String m_serverIPV4Address;
    String m_serverIPV6Address;
    StdExtra::optional<int32_t> m_serverPort;
    String m_serverPublicDNSName;
    StdExtra::optional<PFMatchmakingMatchmakeStatus> m_status;
    String m_ticket;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingClientStartGameRequestWrapper : public ModelWrapper<PFMatchmakingClientStartGameRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingClientStartGameRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingClientStartGameRequestWrapper() = default;

    PFMatchmakingClientStartGameRequestWrapper(const PFMatchmakingClientStartGameRequest& model) :
        ModelWrapper<PFMatchmakingClientStartGameRequest, Alloc>{ model },
        m_buildVersion{ SafeString(model.buildVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_customCommandLineData{ SafeString(model.customCommandLineData) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_gameMode{ SafeString(model.gameMode) },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFMatchmakingClientStartGameRequestWrapper(const PFMatchmakingClientStartGameRequestWrapper& src) :
        PFMatchmakingClientStartGameRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingClientStartGameRequestWrapper(PFMatchmakingClientStartGameRequestWrapper&& src) :
        PFMatchmakingClientStartGameRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingClientStartGameRequestWrapper& operator=(PFMatchmakingClientStartGameRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingClientStartGameRequestWrapper() = default;

    friend void swap(PFMatchmakingClientStartGameRequestWrapper& lhs, PFMatchmakingClientStartGameRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildVersion, rhs.m_buildVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customCommandLineData, rhs.m_customCommandLineData);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_gameMode, rhs.m_gameMode);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildVersion(String value)
    {
        m_buildVersion = std::move(value);
        this->m_model.buildVersion =  m_buildVersion.empty() ? nullptr : m_buildVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCustomCommandLineData(String value)
    {
        m_customCommandLineData = std::move(value);
        this->m_model.customCommandLineData =  m_customCommandLineData.empty() ? nullptr : m_customCommandLineData.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetGameMode(String value)
    {
        m_gameMode = std::move(value);
        this->m_model.gameMode =  m_gameMode.empty() ? nullptr : m_gameMode.data();
    }

    void SetRegion(PFRegion value)
    {
        this->m_model.region = value;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildVersion = m_buildVersion.empty() ? nullptr : m_buildVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customCommandLineData = m_customCommandLineData.empty() ? nullptr : m_customCommandLineData.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.gameMode = m_gameMode.empty() ? nullptr : m_gameMode.data();
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    String m_buildVersion;
    String m_characterId;
    String m_customCommandLineData;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_gameMode;
    String m_statisticName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingStartGameResultWrapper : public ModelWrapper<PFMatchmakingStartGameResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingStartGameResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingStartGameResultWrapper() = default;

    PFMatchmakingStartGameResultWrapper(const PFMatchmakingStartGameResult& model) :
        ModelWrapper<PFMatchmakingStartGameResult, Alloc>{ model },
        m_expires{ SafeString(model.expires) },
        m_lobbyID{ SafeString(model.lobbyID) },
        m_password{ SafeString(model.password) },
        m_serverIPV4Address{ SafeString(model.serverIPV4Address) },
        m_serverIPV6Address{ SafeString(model.serverIPV6Address) },
        m_serverPort{ model.serverPort ? StdExtra::optional<int32_t>{ *model.serverPort } : StdExtra::nullopt },
        m_serverPublicDNSName{ SafeString(model.serverPublicDNSName) },
        m_ticket{ SafeString(model.ticket) }
    {
        SetModelPointers();
    }

    PFMatchmakingStartGameResultWrapper(const PFMatchmakingStartGameResultWrapper& src) :
        PFMatchmakingStartGameResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingStartGameResultWrapper(PFMatchmakingStartGameResultWrapper&& src) :
        PFMatchmakingStartGameResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingStartGameResultWrapper& operator=(PFMatchmakingStartGameResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingStartGameResultWrapper() = default;

    friend void swap(PFMatchmakingStartGameResultWrapper& lhs, PFMatchmakingStartGameResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_expires, rhs.m_expires);
        swap(lhs.m_lobbyID, rhs.m_lobbyID);
        swap(lhs.m_password, rhs.m_password);
        swap(lhs.m_serverIPV4Address, rhs.m_serverIPV4Address);
        swap(lhs.m_serverIPV6Address, rhs.m_serverIPV6Address);
        swap(lhs.m_serverPort, rhs.m_serverPort);
        swap(lhs.m_serverPublicDNSName, rhs.m_serverPublicDNSName);
        swap(lhs.m_ticket, rhs.m_ticket);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetExpires(String value)
    {
        m_expires = std::move(value);
        this->m_model.expires =  m_expires.empty() ? nullptr : m_expires.data();
    }

    void SetLobbyID(String value)
    {
        m_lobbyID = std::move(value);
        this->m_model.lobbyID =  m_lobbyID.empty() ? nullptr : m_lobbyID.data();
    }

    void SetPassword(String value)
    {
        m_password = std::move(value);
        this->m_model.password =  m_password.empty() ? nullptr : m_password.data();
    }

    void SetServerIPV4Address(String value)
    {
        m_serverIPV4Address = std::move(value);
        this->m_model.serverIPV4Address =  m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
    }

    void SetServerIPV6Address(String value)
    {
        m_serverIPV6Address = std::move(value);
        this->m_model.serverIPV6Address =  m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
    }

    void SetServerPort(StdExtra::optional<int32_t> value)
    {
        m_serverPort = std::move(value);
        this->m_model.serverPort = m_serverPort ? m_serverPort.operator->() : nullptr;
    }

    void SetServerPublicDNSName(String value)
    {
        m_serverPublicDNSName = std::move(value);
        this->m_model.serverPublicDNSName =  m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
    }

    void SetTicket(String value)
    {
        m_ticket = std::move(value);
        this->m_model.ticket =  m_ticket.empty() ? nullptr : m_ticket.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.expires = m_expires.empty() ? nullptr : m_expires.data();
        this->m_model.lobbyID = m_lobbyID.empty() ? nullptr : m_lobbyID.data();
        this->m_model.password = m_password.empty() ? nullptr : m_password.data();
        this->m_model.serverIPV4Address = m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
        this->m_model.serverIPV6Address = m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
        this->m_model.serverPort = m_serverPort ? m_serverPort.operator->() : nullptr;
        this->m_model.serverPublicDNSName = m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
        this->m_model.ticket = m_ticket.empty() ? nullptr : m_ticket.data();
    }

    String m_expires;
    String m_lobbyID;
    String m_password;
    String m_serverIPV4Address;
    String m_serverIPV6Address;
    StdExtra::optional<int32_t> m_serverPort;
    String m_serverPublicDNSName;
    String m_ticket;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingAuthUserRequestWrapper : public ModelWrapper<PFMatchmakingAuthUserRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingAuthUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingAuthUserRequestWrapper() = default;

    PFMatchmakingAuthUserRequestWrapper(const PFMatchmakingAuthUserRequest& model) :
        ModelWrapper<PFMatchmakingAuthUserRequest, Alloc>{ model },
        m_authorizationTicket{ SafeString(model.authorizationTicket) }
    {
        SetModelPointers();
    }

    PFMatchmakingAuthUserRequestWrapper(const PFMatchmakingAuthUserRequestWrapper& src) :
        PFMatchmakingAuthUserRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingAuthUserRequestWrapper(PFMatchmakingAuthUserRequestWrapper&& src) :
        PFMatchmakingAuthUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingAuthUserRequestWrapper& operator=(PFMatchmakingAuthUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingAuthUserRequestWrapper() = default;

    friend void swap(PFMatchmakingAuthUserRequestWrapper& lhs, PFMatchmakingAuthUserRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_authorizationTicket, rhs.m_authorizationTicket);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAuthorizationTicket(String value)
    {
        m_authorizationTicket = std::move(value);
        this->m_model.authorizationTicket =  m_authorizationTicket.empty() ? nullptr : m_authorizationTicket.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.authorizationTicket = m_authorizationTicket.empty() ? nullptr : m_authorizationTicket.data();
    }

    String m_authorizationTicket;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingAuthUserResponseWrapper : public ModelWrapper<PFMatchmakingAuthUserResponse, Alloc>
{
public:
    using ModelType = typename PFMatchmakingAuthUserResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingAuthUserResponseWrapper() = default;

    PFMatchmakingAuthUserResponseWrapper(const PFMatchmakingAuthUserResponse& model) :
        ModelWrapper<PFMatchmakingAuthUserResponse, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFMatchmakingAuthUserResponseWrapper(const PFMatchmakingAuthUserResponseWrapper& src) :
        PFMatchmakingAuthUserResponseWrapper{ src.Model() }
    {
    }

    PFMatchmakingAuthUserResponseWrapper(PFMatchmakingAuthUserResponseWrapper&& src) :
        PFMatchmakingAuthUserResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingAuthUserResponseWrapper& operator=(PFMatchmakingAuthUserResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingAuthUserResponseWrapper() = default;

    friend void swap(PFMatchmakingAuthUserResponseWrapper& lhs, PFMatchmakingAuthUserResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAuthorized(bool value)
    {
        this->m_model.authorized = value;
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
class PFMatchmakingPlayerJoinedRequestWrapper : public ModelWrapper<PFMatchmakingPlayerJoinedRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingPlayerJoinedRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingPlayerJoinedRequestWrapper() = default;

    PFMatchmakingPlayerJoinedRequestWrapper(const PFMatchmakingPlayerJoinedRequest& model) :
        ModelWrapper<PFMatchmakingPlayerJoinedRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFMatchmakingPlayerJoinedRequestWrapper(const PFMatchmakingPlayerJoinedRequestWrapper& src) :
        PFMatchmakingPlayerJoinedRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingPlayerJoinedRequestWrapper(PFMatchmakingPlayerJoinedRequestWrapper&& src) :
        PFMatchmakingPlayerJoinedRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingPlayerJoinedRequestWrapper& operator=(PFMatchmakingPlayerJoinedRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingPlayerJoinedRequestWrapper() = default;

    friend void swap(PFMatchmakingPlayerJoinedRequestWrapper& lhs, PFMatchmakingPlayerJoinedRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
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

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
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
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_lobbyId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingPlayerLeftRequestWrapper : public ModelWrapper<PFMatchmakingPlayerLeftRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingPlayerLeftRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingPlayerLeftRequestWrapper() = default;

    PFMatchmakingPlayerLeftRequestWrapper(const PFMatchmakingPlayerLeftRequest& model) :
        ModelWrapper<PFMatchmakingPlayerLeftRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFMatchmakingPlayerLeftRequestWrapper(const PFMatchmakingPlayerLeftRequestWrapper& src) :
        PFMatchmakingPlayerLeftRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingPlayerLeftRequestWrapper(PFMatchmakingPlayerLeftRequestWrapper&& src) :
        PFMatchmakingPlayerLeftRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingPlayerLeftRequestWrapper& operator=(PFMatchmakingPlayerLeftRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingPlayerLeftRequestWrapper() = default;

    friend void swap(PFMatchmakingPlayerLeftRequestWrapper& lhs, PFMatchmakingPlayerLeftRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
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

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
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
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_lobbyId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingMatchmakerStartGameRequestWrapper : public ModelWrapper<PFMatchmakingMatchmakerStartGameRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingMatchmakerStartGameRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingMatchmakerStartGameRequestWrapper() = default;

    PFMatchmakingMatchmakerStartGameRequestWrapper(const PFMatchmakingMatchmakerStartGameRequest& model) :
        ModelWrapper<PFMatchmakingMatchmakerStartGameRequest, Alloc>{ model },
        m_build{ SafeString(model.build) },
        m_customCommandLineData{ SafeString(model.customCommandLineData) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_externalMatchmakerEventEndpoint{ SafeString(model.externalMatchmakerEventEndpoint) },
        m_gameMode{ SafeString(model.gameMode) }
    {
        SetModelPointers();
    }

    PFMatchmakingMatchmakerStartGameRequestWrapper(const PFMatchmakingMatchmakerStartGameRequestWrapper& src) :
        PFMatchmakingMatchmakerStartGameRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingMatchmakerStartGameRequestWrapper(PFMatchmakingMatchmakerStartGameRequestWrapper&& src) :
        PFMatchmakingMatchmakerStartGameRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingMatchmakerStartGameRequestWrapper& operator=(PFMatchmakingMatchmakerStartGameRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingMatchmakerStartGameRequestWrapper() = default;

    friend void swap(PFMatchmakingMatchmakerStartGameRequestWrapper& lhs, PFMatchmakingMatchmakerStartGameRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_build, rhs.m_build);
        swap(lhs.m_customCommandLineData, rhs.m_customCommandLineData);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_externalMatchmakerEventEndpoint, rhs.m_externalMatchmakerEventEndpoint);
        swap(lhs.m_gameMode, rhs.m_gameMode);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuild(String value)
    {
        m_build = std::move(value);
        this->m_model.build =  m_build.empty() ? nullptr : m_build.data();
    }

    void SetCustomCommandLineData(String value)
    {
        m_customCommandLineData = std::move(value);
        this->m_model.customCommandLineData =  m_customCommandLineData.empty() ? nullptr : m_customCommandLineData.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetExternalMatchmakerEventEndpoint(String value)
    {
        m_externalMatchmakerEventEndpoint = std::move(value);
        this->m_model.externalMatchmakerEventEndpoint =  m_externalMatchmakerEventEndpoint.empty() ? nullptr : m_externalMatchmakerEventEndpoint.data();
    }

    void SetGameMode(String value)
    {
        m_gameMode = std::move(value);
        this->m_model.gameMode =  m_gameMode.empty() ? nullptr : m_gameMode.data();
    }

    void SetRegion(PFRegion value)
    {
        this->m_model.region = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.build = m_build.empty() ? nullptr : m_build.data();
        this->m_model.customCommandLineData = m_customCommandLineData.empty() ? nullptr : m_customCommandLineData.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.externalMatchmakerEventEndpoint = m_externalMatchmakerEventEndpoint.empty() ? nullptr : m_externalMatchmakerEventEndpoint.data();
        this->m_model.gameMode = m_gameMode.empty() ? nullptr : m_gameMode.data();
    }

    String m_build;
    String m_customCommandLineData;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_externalMatchmakerEventEndpoint;
    String m_gameMode;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingStartGameResponseWrapper : public ModelWrapper<PFMatchmakingStartGameResponse, Alloc>
{
public:
    using ModelType = typename PFMatchmakingStartGameResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingStartGameResponseWrapper() = default;

    PFMatchmakingStartGameResponseWrapper(const PFMatchmakingStartGameResponse& model) :
        ModelWrapper<PFMatchmakingStartGameResponse, Alloc>{ model },
        m_gameID{ SafeString(model.gameID) },
        m_serverIPV4Address{ SafeString(model.serverIPV4Address) },
        m_serverIPV6Address{ SafeString(model.serverIPV6Address) },
        m_serverPublicDNSName{ SafeString(model.serverPublicDNSName) }
    {
        SetModelPointers();
    }

    PFMatchmakingStartGameResponseWrapper(const PFMatchmakingStartGameResponseWrapper& src) :
        PFMatchmakingStartGameResponseWrapper{ src.Model() }
    {
    }

    PFMatchmakingStartGameResponseWrapper(PFMatchmakingStartGameResponseWrapper&& src) :
        PFMatchmakingStartGameResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingStartGameResponseWrapper& operator=(PFMatchmakingStartGameResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingStartGameResponseWrapper() = default;

    friend void swap(PFMatchmakingStartGameResponseWrapper& lhs, PFMatchmakingStartGameResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_gameID, rhs.m_gameID);
        swap(lhs.m_serverIPV4Address, rhs.m_serverIPV4Address);
        swap(lhs.m_serverIPV6Address, rhs.m_serverIPV6Address);
        swap(lhs.m_serverPublicDNSName, rhs.m_serverPublicDNSName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGameID(String value)
    {
        m_gameID = std::move(value);
        this->m_model.gameID =  m_gameID.empty() ? nullptr : m_gameID.data();
    }

    void SetServerIPV4Address(String value)
    {
        m_serverIPV4Address = std::move(value);
        this->m_model.serverIPV4Address =  m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
    }

    void SetServerIPV6Address(String value)
    {
        m_serverIPV6Address = std::move(value);
        this->m_model.serverIPV6Address =  m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
    }

    void SetServerPort(uint32_t value)
    {
        this->m_model.serverPort = value;
    }

    void SetServerPublicDNSName(String value)
    {
        m_serverPublicDNSName = std::move(value);
        this->m_model.serverPublicDNSName =  m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.gameID = m_gameID.empty() ? nullptr : m_gameID.data();
        this->m_model.serverIPV4Address = m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
        this->m_model.serverIPV6Address = m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
        this->m_model.serverPublicDNSName = m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
    }

    String m_gameID;
    String m_serverIPV4Address;
    String m_serverIPV6Address;
    String m_serverPublicDNSName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingUserInfoRequestWrapper : public ModelWrapper<PFMatchmakingUserInfoRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingUserInfoRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingUserInfoRequestWrapper() = default;

    PFMatchmakingUserInfoRequestWrapper(const PFMatchmakingUserInfoRequest& model) :
        ModelWrapper<PFMatchmakingUserInfoRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFMatchmakingUserInfoRequestWrapper(const PFMatchmakingUserInfoRequestWrapper& src) :
        PFMatchmakingUserInfoRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingUserInfoRequestWrapper(PFMatchmakingUserInfoRequestWrapper&& src) :
        PFMatchmakingUserInfoRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingUserInfoRequestWrapper& operator=(PFMatchmakingUserInfoRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingUserInfoRequestWrapper() = default;

    friend void swap(PFMatchmakingUserInfoRequestWrapper& lhs, PFMatchmakingUserInfoRequestWrapper& rhs)
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

    void SetMinCatalogVersion(int32_t value)
    {
        this->m_model.minCatalogVersion = value;
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
class PFMatchmakingUserInfoResponseWrapper : public ModelWrapper<PFMatchmakingUserInfoResponse, Alloc>
{
public:
    using ModelType = typename PFMatchmakingUserInfoResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingUserInfoResponseWrapper() = default;

    PFMatchmakingUserInfoResponseWrapper(const PFMatchmakingUserInfoResponse& model) :
        ModelWrapper<PFMatchmakingUserInfoResponse, Alloc>{ model },
        m_inventory{ model.inventory, model.inventory + model.inventoryCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_steamId{ SafeString(model.steamId) },
        m_titleDisplayName{ SafeString(model.titleDisplayName) },
        m_username{ SafeString(model.username) },
        m_virtualCurrency{ model.virtualCurrency, model.virtualCurrency + model.virtualCurrencyCount },
        m_virtualCurrencyRechargeTimes{ model.virtualCurrencyRechargeTimes, model.virtualCurrencyRechargeTimes + model.virtualCurrencyRechargeTimesCount }
    {
        SetModelPointers();
    }

    PFMatchmakingUserInfoResponseWrapper(const PFMatchmakingUserInfoResponseWrapper& src) :
        PFMatchmakingUserInfoResponseWrapper{ src.Model() }
    {
    }

    PFMatchmakingUserInfoResponseWrapper(PFMatchmakingUserInfoResponseWrapper&& src) :
        PFMatchmakingUserInfoResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingUserInfoResponseWrapper& operator=(PFMatchmakingUserInfoResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingUserInfoResponseWrapper() = default;

    friend void swap(PFMatchmakingUserInfoResponseWrapper& lhs, PFMatchmakingUserInfoResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_inventory, rhs.m_inventory);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_steamId, rhs.m_steamId);
        swap(lhs.m_titleDisplayName, rhs.m_titleDisplayName);
        swap(lhs.m_username, rhs.m_username);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        swap(lhs.m_virtualCurrencyRechargeTimes, rhs.m_virtualCurrencyRechargeTimes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetInventory(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_inventory = std::move(value);
        this->m_model.inventory =  m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.inventoryCount =  static_cast<uint32_t>(m_inventory.size());
    }

    void SetIsDeveloper(bool value)
    {
        this->m_model.isDeveloper = value;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetSteamId(String value)
    {
        m_steamId = std::move(value);
        this->m_model.steamId =  m_steamId.empty() ? nullptr : m_steamId.data();
    }

    void SetTitleDisplayName(String value)
    {
        m_titleDisplayName = std::move(value);
        this->m_model.titleDisplayName =  m_titleDisplayName.empty() ? nullptr : m_titleDisplayName.data();
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

    void SetVirtualCurrency(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyCount =  static_cast<uint32_t>(m_virtualCurrency.size());
    }

    void SetVirtualCurrencyRechargeTimes(ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> value)
    {
        m_virtualCurrencyRechargeTimes = std::move(value);
        this->m_model.virtualCurrencyRechargeTimes =  m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
        this->m_model.virtualCurrencyRechargeTimesCount =  static_cast<uint32_t>(m_virtualCurrencyRechargeTimes.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.inventory = m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.steamId = m_steamId.empty() ? nullptr : m_steamId.data();
        this->m_model.titleDisplayName = m_titleDisplayName.empty() ? nullptr : m_titleDisplayName.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyRechargeTimes = m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_inventory;
    String m_playFabId;
    String m_steamId;
    String m_titleDisplayName;
    String m_username;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_virtualCurrency;
    ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> m_virtualCurrencyRechargeTimes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingDeregisterGameRequestWrapper : public ModelWrapper<PFMatchmakingDeregisterGameRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingDeregisterGameRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingDeregisterGameRequestWrapper() = default;

    PFMatchmakingDeregisterGameRequestWrapper(const PFMatchmakingDeregisterGameRequest& model) :
        ModelWrapper<PFMatchmakingDeregisterGameRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_lobbyId{ SafeString(model.lobbyId) }
    {
        SetModelPointers();
    }

    PFMatchmakingDeregisterGameRequestWrapper(const PFMatchmakingDeregisterGameRequestWrapper& src) :
        PFMatchmakingDeregisterGameRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingDeregisterGameRequestWrapper(PFMatchmakingDeregisterGameRequestWrapper&& src) :
        PFMatchmakingDeregisterGameRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingDeregisterGameRequestWrapper& operator=(PFMatchmakingDeregisterGameRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingDeregisterGameRequestWrapper() = default;

    friend void swap(PFMatchmakingDeregisterGameRequestWrapper& lhs, PFMatchmakingDeregisterGameRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_lobbyId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper : public ModelWrapper<PFMatchmakingNotifyMatchmakerPlayerLeftRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingNotifyMatchmakerPlayerLeftRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper() = default;

    PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper(const PFMatchmakingNotifyMatchmakerPlayerLeftRequest& model) :
        ModelWrapper<PFMatchmakingNotifyMatchmakerPlayerLeftRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper(const PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper& src) :
        PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper(PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper&& src) :
        PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper& operator=(PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper() = default;

    friend void swap(PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper& lhs, PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
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

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
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
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_lobbyId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper : public ModelWrapper<PFMatchmakingNotifyMatchmakerPlayerLeftResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingNotifyMatchmakerPlayerLeftResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper() = default;

    PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper(const PFMatchmakingNotifyMatchmakerPlayerLeftResult& model) :
        ModelWrapper<PFMatchmakingNotifyMatchmakerPlayerLeftResult, Alloc>{ model },
        m_playerState{ model.playerState ? StdExtra::optional<PFMatchmakingPlayerConnectionState>{ *model.playerState } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper(const PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper& src) :
        PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper(PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper&& src) :
        PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper& operator=(PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper() = default;

    friend void swap(PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper& lhs, PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playerState, rhs.m_playerState);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayerState(StdExtra::optional<PFMatchmakingPlayerConnectionState> value)
    {
        m_playerState = std::move(value);
        this->m_model.playerState = m_playerState ? m_playerState.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.playerState = m_playerState ? m_playerState.operator->() : nullptr;
    }

    StdExtra::optional<PFMatchmakingPlayerConnectionState> m_playerState;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingRedeemMatchmakerTicketRequestWrapper : public ModelWrapper<PFMatchmakingRedeemMatchmakerTicketRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingRedeemMatchmakerTicketRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingRedeemMatchmakerTicketRequestWrapper() = default;

    PFMatchmakingRedeemMatchmakerTicketRequestWrapper(const PFMatchmakingRedeemMatchmakerTicketRequest& model) :
        ModelWrapper<PFMatchmakingRedeemMatchmakerTicketRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_ticket{ SafeString(model.ticket) }
    {
        SetModelPointers();
    }

    PFMatchmakingRedeemMatchmakerTicketRequestWrapper(const PFMatchmakingRedeemMatchmakerTicketRequestWrapper& src) :
        PFMatchmakingRedeemMatchmakerTicketRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingRedeemMatchmakerTicketRequestWrapper(PFMatchmakingRedeemMatchmakerTicketRequestWrapper&& src) :
        PFMatchmakingRedeemMatchmakerTicketRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingRedeemMatchmakerTicketRequestWrapper& operator=(PFMatchmakingRedeemMatchmakerTicketRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingRedeemMatchmakerTicketRequestWrapper() = default;

    friend void swap(PFMatchmakingRedeemMatchmakerTicketRequestWrapper& lhs, PFMatchmakingRedeemMatchmakerTicketRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_ticket, rhs.m_ticket);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetTicket(String value)
    {
        m_ticket = std::move(value);
        this->m_model.ticket =  m_ticket.empty() ? nullptr : m_ticket.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.ticket = m_ticket.empty() ? nullptr : m_ticket.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_lobbyId;
    String m_ticket;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingRedeemMatchmakerTicketResultWrapper : public ModelWrapper<PFMatchmakingRedeemMatchmakerTicketResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingRedeemMatchmakerTicketResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingRedeemMatchmakerTicketResultWrapper() = default;

    PFMatchmakingRedeemMatchmakerTicketResultWrapper(const PFMatchmakingRedeemMatchmakerTicketResult& model) :
        ModelWrapper<PFMatchmakingRedeemMatchmakerTicketResult, Alloc>{ model },
        m_error{ SafeString(model.error) },
        m_userInfo{ model.userInfo ? StdExtra::optional<PFUserAccountInfoWrapper<Alloc>>{ *model.userInfo } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMatchmakingRedeemMatchmakerTicketResultWrapper(const PFMatchmakingRedeemMatchmakerTicketResultWrapper& src) :
        PFMatchmakingRedeemMatchmakerTicketResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingRedeemMatchmakerTicketResultWrapper(PFMatchmakingRedeemMatchmakerTicketResultWrapper&& src) :
        PFMatchmakingRedeemMatchmakerTicketResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingRedeemMatchmakerTicketResultWrapper& operator=(PFMatchmakingRedeemMatchmakerTicketResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingRedeemMatchmakerTicketResultWrapper() = default;

    friend void swap(PFMatchmakingRedeemMatchmakerTicketResultWrapper& lhs, PFMatchmakingRedeemMatchmakerTicketResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_error, rhs.m_error);
        swap(lhs.m_userInfo, rhs.m_userInfo);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetError(String value)
    {
        m_error = std::move(value);
        this->m_model.error =  m_error.empty() ? nullptr : m_error.data();
    }

    void SetTicketIsValid(bool value)
    {
        this->m_model.ticketIsValid = value;
    }

    void SetUserInfo(StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> value)
    {
        m_userInfo = std::move(value);
        this->m_model.userInfo = m_userInfo ? &m_userInfo->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.error = m_error.empty() ? nullptr : m_error.data();
        this->m_model.userInfo = m_userInfo ?  &m_userInfo->Model() : nullptr;
    }

    String m_error;
    StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> m_userInfo;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper : public ModelWrapper<PFMatchmakingRefreshGameServerInstanceHeartbeatRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingRefreshGameServerInstanceHeartbeatRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper() = default;

    PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper(const PFMatchmakingRefreshGameServerInstanceHeartbeatRequest& model) :
        ModelWrapper<PFMatchmakingRefreshGameServerInstanceHeartbeatRequest, Alloc>{ model },
        m_lobbyId{ SafeString(model.lobbyId) }
    {
        SetModelPointers();
    }

    PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper(const PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper& src) :
        PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper(PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper&& src) :
        PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper& operator=(PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper() = default;

    friend void swap(PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper& lhs, PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    String m_lobbyId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingRegisterGameRequestWrapper : public ModelWrapper<PFMatchmakingRegisterGameRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingRegisterGameRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingRegisterGameRequestWrapper() = default;

    PFMatchmakingRegisterGameRequestWrapper(const PFMatchmakingRegisterGameRequest& model) :
        ModelWrapper<PFMatchmakingRegisterGameRequest, Alloc>{ model },
        m_build{ SafeString(model.build) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_gameMode{ SafeString(model.gameMode) },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_serverIPV4Address{ SafeString(model.serverIPV4Address) },
        m_serverIPV6Address{ SafeString(model.serverIPV6Address) },
        m_serverPort{ SafeString(model.serverPort) },
        m_serverPublicDNSName{ SafeString(model.serverPublicDNSName) },
        m_tags{ model.tags, model.tags + model.tagsCount }
    {
        SetModelPointers();
    }

    PFMatchmakingRegisterGameRequestWrapper(const PFMatchmakingRegisterGameRequestWrapper& src) :
        PFMatchmakingRegisterGameRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingRegisterGameRequestWrapper(PFMatchmakingRegisterGameRequestWrapper&& src) :
        PFMatchmakingRegisterGameRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingRegisterGameRequestWrapper& operator=(PFMatchmakingRegisterGameRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingRegisterGameRequestWrapper() = default;

    friend void swap(PFMatchmakingRegisterGameRequestWrapper& lhs, PFMatchmakingRegisterGameRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_build, rhs.m_build);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_gameMode, rhs.m_gameMode);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_serverIPV4Address, rhs.m_serverIPV4Address);
        swap(lhs.m_serverIPV6Address, rhs.m_serverIPV6Address);
        swap(lhs.m_serverPort, rhs.m_serverPort);
        swap(lhs.m_serverPublicDNSName, rhs.m_serverPublicDNSName);
        swap(lhs.m_tags, rhs.m_tags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuild(String value)
    {
        m_build = std::move(value);
        this->m_model.build =  m_build.empty() ? nullptr : m_build.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetGameMode(String value)
    {
        m_gameMode = std::move(value);
        this->m_model.gameMode =  m_gameMode.empty() ? nullptr : m_gameMode.data();
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetRegion(PFRegion value)
    {
        this->m_model.region = value;
    }

    void SetServerIPV4Address(String value)
    {
        m_serverIPV4Address = std::move(value);
        this->m_model.serverIPV4Address =  m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
    }

    void SetServerIPV6Address(String value)
    {
        m_serverIPV6Address = std::move(value);
        this->m_model.serverIPV6Address =  m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
    }

    void SetServerPort(String value)
    {
        m_serverPort = std::move(value);
        this->m_model.serverPort =  m_serverPort.empty() ? nullptr : m_serverPort.data();
    }

    void SetServerPublicDNSName(String value)
    {
        m_serverPublicDNSName = std::move(value);
        this->m_model.serverPublicDNSName =  m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
    }

    void SetTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_tags = std::move(value);
        this->m_model.tags =  m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.tagsCount =  static_cast<uint32_t>(m_tags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.build = m_build.empty() ? nullptr : m_build.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.gameMode = m_gameMode.empty() ? nullptr : m_gameMode.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.serverIPV4Address = m_serverIPV4Address.empty() ? nullptr : m_serverIPV4Address.data();
        this->m_model.serverIPV6Address = m_serverIPV6Address.empty() ? nullptr : m_serverIPV6Address.data();
        this->m_model.serverPort = m_serverPort.empty() ? nullptr : m_serverPort.data();
        this->m_model.serverPublicDNSName = m_serverPublicDNSName.empty() ? nullptr : m_serverPublicDNSName.data();
        this->m_model.tags = m_tags.empty() ? nullptr : m_tags.data();
    }

    String m_build;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_gameMode;
    String m_lobbyId;
    String m_serverIPV4Address;
    String m_serverIPV6Address;
    String m_serverPort;
    String m_serverPublicDNSName;
    StringDictionaryEntryVector<Alloc> m_tags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingRegisterGameResponseWrapper : public ModelWrapper<PFMatchmakingRegisterGameResponse, Alloc>
{
public:
    using ModelType = typename PFMatchmakingRegisterGameResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingRegisterGameResponseWrapper() = default;

    PFMatchmakingRegisterGameResponseWrapper(const PFMatchmakingRegisterGameResponse& model) :
        ModelWrapper<PFMatchmakingRegisterGameResponse, Alloc>{ model },
        m_lobbyId{ SafeString(model.lobbyId) }
    {
        SetModelPointers();
    }

    PFMatchmakingRegisterGameResponseWrapper(const PFMatchmakingRegisterGameResponseWrapper& src) :
        PFMatchmakingRegisterGameResponseWrapper{ src.Model() }
    {
    }

    PFMatchmakingRegisterGameResponseWrapper(PFMatchmakingRegisterGameResponseWrapper&& src) :
        PFMatchmakingRegisterGameResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingRegisterGameResponseWrapper& operator=(PFMatchmakingRegisterGameResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingRegisterGameResponseWrapper() = default;

    friend void swap(PFMatchmakingRegisterGameResponseWrapper& lhs, PFMatchmakingRegisterGameResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    String m_lobbyId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingSetGameServerInstanceDataRequestWrapper : public ModelWrapper<PFMatchmakingSetGameServerInstanceDataRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingSetGameServerInstanceDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingSetGameServerInstanceDataRequestWrapper() = default;

    PFMatchmakingSetGameServerInstanceDataRequestWrapper(const PFMatchmakingSetGameServerInstanceDataRequest& model) :
        ModelWrapper<PFMatchmakingSetGameServerInstanceDataRequest, Alloc>{ model },
        m_gameServerData{ SafeString(model.gameServerData) },
        m_lobbyId{ SafeString(model.lobbyId) }
    {
        SetModelPointers();
    }

    PFMatchmakingSetGameServerInstanceDataRequestWrapper(const PFMatchmakingSetGameServerInstanceDataRequestWrapper& src) :
        PFMatchmakingSetGameServerInstanceDataRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingSetGameServerInstanceDataRequestWrapper(PFMatchmakingSetGameServerInstanceDataRequestWrapper&& src) :
        PFMatchmakingSetGameServerInstanceDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingSetGameServerInstanceDataRequestWrapper& operator=(PFMatchmakingSetGameServerInstanceDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingSetGameServerInstanceDataRequestWrapper() = default;

    friend void swap(PFMatchmakingSetGameServerInstanceDataRequestWrapper& lhs, PFMatchmakingSetGameServerInstanceDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_gameServerData, rhs.m_gameServerData);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGameServerData(String value)
    {
        m_gameServerData = std::move(value);
        this->m_model.gameServerData =  m_gameServerData.empty() ? nullptr : m_gameServerData.data();
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.gameServerData = m_gameServerData.empty() ? nullptr : m_gameServerData.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    String m_gameServerData;
    String m_lobbyId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingSetGameServerInstanceStateRequestWrapper : public ModelWrapper<PFMatchmakingSetGameServerInstanceStateRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingSetGameServerInstanceStateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingSetGameServerInstanceStateRequestWrapper() = default;

    PFMatchmakingSetGameServerInstanceStateRequestWrapper(const PFMatchmakingSetGameServerInstanceStateRequest& model) :
        ModelWrapper<PFMatchmakingSetGameServerInstanceStateRequest, Alloc>{ model },
        m_lobbyId{ SafeString(model.lobbyId) }
    {
        SetModelPointers();
    }

    PFMatchmakingSetGameServerInstanceStateRequestWrapper(const PFMatchmakingSetGameServerInstanceStateRequestWrapper& src) :
        PFMatchmakingSetGameServerInstanceStateRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingSetGameServerInstanceStateRequestWrapper(PFMatchmakingSetGameServerInstanceStateRequestWrapper&& src) :
        PFMatchmakingSetGameServerInstanceStateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingSetGameServerInstanceStateRequestWrapper& operator=(PFMatchmakingSetGameServerInstanceStateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingSetGameServerInstanceStateRequestWrapper() = default;

    friend void swap(PFMatchmakingSetGameServerInstanceStateRequestWrapper& lhs, PFMatchmakingSetGameServerInstanceStateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetState(PFMatchmakingGameInstanceState value)
    {
        this->m_model.state = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    String m_lobbyId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingSetGameServerInstanceTagsRequestWrapper : public ModelWrapper<PFMatchmakingSetGameServerInstanceTagsRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingSetGameServerInstanceTagsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingSetGameServerInstanceTagsRequestWrapper() = default;

    PFMatchmakingSetGameServerInstanceTagsRequestWrapper(const PFMatchmakingSetGameServerInstanceTagsRequest& model) :
        ModelWrapper<PFMatchmakingSetGameServerInstanceTagsRequest, Alloc>{ model },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_tags{ model.tags, model.tags + model.tagsCount }
    {
        SetModelPointers();
    }

    PFMatchmakingSetGameServerInstanceTagsRequestWrapper(const PFMatchmakingSetGameServerInstanceTagsRequestWrapper& src) :
        PFMatchmakingSetGameServerInstanceTagsRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingSetGameServerInstanceTagsRequestWrapper(PFMatchmakingSetGameServerInstanceTagsRequestWrapper&& src) :
        PFMatchmakingSetGameServerInstanceTagsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingSetGameServerInstanceTagsRequestWrapper& operator=(PFMatchmakingSetGameServerInstanceTagsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingSetGameServerInstanceTagsRequestWrapper() = default;

    friend void swap(PFMatchmakingSetGameServerInstanceTagsRequestWrapper& lhs, PFMatchmakingSetGameServerInstanceTagsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_tags, rhs.m_tags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_tags = std::move(value);
        this->m_model.tags =  m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.tagsCount =  static_cast<uint32_t>(m_tags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.tags = m_tags.empty() ? nullptr : m_tags.data();
    }

    String m_lobbyId;
    StringDictionaryEntryVector<Alloc> m_tags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper : public ModelWrapper<PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper() = default;

    PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper(const PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest& model) :
        ModelWrapper<PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_queueName{ SafeString(model.queueName) }
    {
        SetModelPointers();
    }

    PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper(const PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper& src) :
        PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper(PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper&& src) :
        PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper& operator=(PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper() = default;

    friend void swap(PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper& lhs, PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_queueName, rhs.m_queueName);
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

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_queueName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper : public ModelWrapper<PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper() = default;

    PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper(const PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest& model) :
        ModelWrapper<PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? *model.entity : decltype(*model.entity){} },
        m_queueName{ SafeString(model.queueName) }
    {
        SetModelPointers();
    }

    PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper(const PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper& src) :
        PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper(PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper&& src) :
        PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper& operator=(PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper() = default;

    friend void swap(PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper& lhs, PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_queueName, rhs.m_queueName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(PFEntityKeyWrapper<Alloc> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = &m_entity.Model();
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = &m_entity.Model();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFEntityKeyWrapper<Alloc> m_entity;
    String m_queueName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCancelMatchmakingTicketRequestWrapper : public ModelWrapper<PFMatchmakingCancelMatchmakingTicketRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCancelMatchmakingTicketRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCancelMatchmakingTicketRequestWrapper() = default;

    PFMatchmakingCancelMatchmakingTicketRequestWrapper(const PFMatchmakingCancelMatchmakingTicketRequest& model) :
        ModelWrapper<PFMatchmakingCancelMatchmakingTicketRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_queueName{ SafeString(model.queueName) },
        m_ticketId{ SafeString(model.ticketId) }
    {
        SetModelPointers();
    }

    PFMatchmakingCancelMatchmakingTicketRequestWrapper(const PFMatchmakingCancelMatchmakingTicketRequestWrapper& src) :
        PFMatchmakingCancelMatchmakingTicketRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingCancelMatchmakingTicketRequestWrapper(PFMatchmakingCancelMatchmakingTicketRequestWrapper&& src) :
        PFMatchmakingCancelMatchmakingTicketRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCancelMatchmakingTicketRequestWrapper& operator=(PFMatchmakingCancelMatchmakingTicketRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCancelMatchmakingTicketRequestWrapper() = default;

    friend void swap(PFMatchmakingCancelMatchmakingTicketRequestWrapper& lhs, PFMatchmakingCancelMatchmakingTicketRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_queueName, rhs.m_queueName);
        swap(lhs.m_ticketId, rhs.m_ticketId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

    void SetTicketId(String value)
    {
        m_ticketId = std::move(value);
        this->m_model.ticketId =  m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
        this->m_model.ticketId = m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_queueName;
    String m_ticketId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCancelServerBackfillTicketRequestWrapper : public ModelWrapper<PFMatchmakingCancelServerBackfillTicketRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCancelServerBackfillTicketRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCancelServerBackfillTicketRequestWrapper() = default;

    PFMatchmakingCancelServerBackfillTicketRequestWrapper(const PFMatchmakingCancelServerBackfillTicketRequest& model) :
        ModelWrapper<PFMatchmakingCancelServerBackfillTicketRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_queueName{ SafeString(model.queueName) },
        m_ticketId{ SafeString(model.ticketId) }
    {
        SetModelPointers();
    }

    PFMatchmakingCancelServerBackfillTicketRequestWrapper(const PFMatchmakingCancelServerBackfillTicketRequestWrapper& src) :
        PFMatchmakingCancelServerBackfillTicketRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingCancelServerBackfillTicketRequestWrapper(PFMatchmakingCancelServerBackfillTicketRequestWrapper&& src) :
        PFMatchmakingCancelServerBackfillTicketRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCancelServerBackfillTicketRequestWrapper& operator=(PFMatchmakingCancelServerBackfillTicketRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCancelServerBackfillTicketRequestWrapper() = default;

    friend void swap(PFMatchmakingCancelServerBackfillTicketRequestWrapper& lhs, PFMatchmakingCancelServerBackfillTicketRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_queueName, rhs.m_queueName);
        swap(lhs.m_ticketId, rhs.m_ticketId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

    void SetTicketId(String value)
    {
        m_ticketId = std::move(value);
        this->m_model.ticketId =  m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
        this->m_model.ticketId = m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_queueName;
    String m_ticketId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingMatchmakingPlayerAttributesWrapper : public ModelWrapper<PFMatchmakingMatchmakingPlayerAttributes, Alloc>
{
public:
    using ModelType = typename PFMatchmakingMatchmakingPlayerAttributes;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingMatchmakingPlayerAttributesWrapper() = default;

    PFMatchmakingMatchmakingPlayerAttributesWrapper(const PFMatchmakingMatchmakingPlayerAttributes& model) :
        ModelWrapper<PFMatchmakingMatchmakingPlayerAttributes, Alloc>{ model },
        m_dataObject{ model.dataObject },
        m_escapedDataObject{ SafeString(model.escapedDataObject) }
    {
        SetModelPointers();
    }

    PFMatchmakingMatchmakingPlayerAttributesWrapper(const PFMatchmakingMatchmakingPlayerAttributesWrapper& src) :
        PFMatchmakingMatchmakingPlayerAttributesWrapper{ src.Model() }
    {
    }

    PFMatchmakingMatchmakingPlayerAttributesWrapper(PFMatchmakingMatchmakingPlayerAttributesWrapper&& src) :
        PFMatchmakingMatchmakingPlayerAttributesWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingMatchmakingPlayerAttributesWrapper& operator=(PFMatchmakingMatchmakingPlayerAttributesWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingMatchmakingPlayerAttributesWrapper() = default;

    friend void swap(PFMatchmakingMatchmakingPlayerAttributesWrapper& lhs, PFMatchmakingMatchmakingPlayerAttributesWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_dataObject, rhs.m_dataObject);
        swap(lhs.m_escapedDataObject, rhs.m_escapedDataObject);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDataObject(JsonObject<Alloc> value)
    {
        m_dataObject = std::move(value);
        this->m_model.dataObject.stringValue = m_dataObject.stringValue.empty() ? nullptr : m_dataObject.stringValue.data();
    }

    void SetEscapedDataObject(String value)
    {
        m_escapedDataObject = std::move(value);
        this->m_model.escapedDataObject =  m_escapedDataObject.empty() ? nullptr : m_escapedDataObject.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.dataObject.stringValue = m_dataObject.stringValue.empty() ? nullptr : m_dataObject.stringValue.data();
        this->m_model.escapedDataObject = m_escapedDataObject.empty() ? nullptr : m_escapedDataObject.data();
    }

    JsonObject<Alloc> m_dataObject;
    String m_escapedDataObject;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingMatchmakingPlayerWrapper : public ModelWrapper<PFMatchmakingMatchmakingPlayer, Alloc>
{
public:
    using ModelType = typename PFMatchmakingMatchmakingPlayer;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingMatchmakingPlayerWrapper() = default;

    PFMatchmakingMatchmakingPlayerWrapper(const PFMatchmakingMatchmakingPlayer& model) :
        ModelWrapper<PFMatchmakingMatchmakingPlayer, Alloc>{ model },
        m_attributes{ model.attributes ? StdExtra::optional<PFMatchmakingMatchmakingPlayerAttributesWrapper<Alloc>>{ *model.attributes } : StdExtra::nullopt },
        m_entity{ model.entity ? *model.entity : decltype(*model.entity){} }
    {
        SetModelPointers();
    }

    PFMatchmakingMatchmakingPlayerWrapper(const PFMatchmakingMatchmakingPlayerWrapper& src) :
        PFMatchmakingMatchmakingPlayerWrapper{ src.Model() }
    {
    }

    PFMatchmakingMatchmakingPlayerWrapper(PFMatchmakingMatchmakingPlayerWrapper&& src) :
        PFMatchmakingMatchmakingPlayerWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingMatchmakingPlayerWrapper& operator=(PFMatchmakingMatchmakingPlayerWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingMatchmakingPlayerWrapper() = default;

    friend void swap(PFMatchmakingMatchmakingPlayerWrapper& lhs, PFMatchmakingMatchmakingPlayerWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_attributes, rhs.m_attributes);
        swap(lhs.m_entity, rhs.m_entity);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAttributes(StdExtra::optional<PFMatchmakingMatchmakingPlayerAttributesWrapper<Alloc>> value)
    {
        m_attributes = std::move(value);
        this->m_model.attributes = m_attributes ? &m_attributes->Model() : nullptr;
    }

    void SetEntity(PFEntityKeyWrapper<Alloc> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = &m_entity.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.attributes = m_attributes ?  &m_attributes->Model() : nullptr;
        this->m_model.entity = &m_entity.Model();
    }

    StdExtra::optional<PFMatchmakingMatchmakingPlayerAttributesWrapper<Alloc>> m_attributes;
    PFEntityKeyWrapper<Alloc> m_entity;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCreateMatchmakingTicketRequestWrapper : public ModelWrapper<PFMatchmakingCreateMatchmakingTicketRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCreateMatchmakingTicketRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCreateMatchmakingTicketRequestWrapper() = default;

    PFMatchmakingCreateMatchmakingTicketRequestWrapper(const PFMatchmakingCreateMatchmakingTicketRequest& model) :
        ModelWrapper<PFMatchmakingCreateMatchmakingTicketRequest, Alloc>{ model },
        m_creator{ model.creator ? *model.creator : decltype(*model.creator){} },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_membersToMatchWith{ model.membersToMatchWith, model.membersToMatchWith + model.membersToMatchWithCount },
        m_queueName{ SafeString(model.queueName) }
    {
        SetModelPointers();
    }

    PFMatchmakingCreateMatchmakingTicketRequestWrapper(const PFMatchmakingCreateMatchmakingTicketRequestWrapper& src) :
        PFMatchmakingCreateMatchmakingTicketRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingCreateMatchmakingTicketRequestWrapper(PFMatchmakingCreateMatchmakingTicketRequestWrapper&& src) :
        PFMatchmakingCreateMatchmakingTicketRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCreateMatchmakingTicketRequestWrapper& operator=(PFMatchmakingCreateMatchmakingTicketRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCreateMatchmakingTicketRequestWrapper() = default;

    friend void swap(PFMatchmakingCreateMatchmakingTicketRequestWrapper& lhs, PFMatchmakingCreateMatchmakingTicketRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_creator, rhs.m_creator);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_membersToMatchWith, rhs.m_membersToMatchWith);
        swap(lhs.m_queueName, rhs.m_queueName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreator(PFMatchmakingMatchmakingPlayerWrapper<Alloc> value)
    {
        m_creator = std::move(value);
        this->m_model.creator = &m_creator.Model();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetGiveUpAfterSeconds(int32_t value)
    {
        this->m_model.giveUpAfterSeconds = value;
    }

    void SetMembersToMatchWith(ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> value)
    {
        m_membersToMatchWith = std::move(value);
        this->m_model.membersToMatchWith =  m_membersToMatchWith.empty() ? nullptr : m_membersToMatchWith.data();
        this->m_model.membersToMatchWithCount =  static_cast<uint32_t>(m_membersToMatchWith.size());
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.creator = &m_creator.Model();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.membersToMatchWith = m_membersToMatchWith.empty() ? nullptr : m_membersToMatchWith.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
    }

    PFMatchmakingMatchmakingPlayerWrapper<Alloc> m_creator;
    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> m_membersToMatchWith;
    String m_queueName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCreateMatchmakingTicketResultWrapper : public ModelWrapper<PFMatchmakingCreateMatchmakingTicketResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCreateMatchmakingTicketResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCreateMatchmakingTicketResultWrapper() = default;

    PFMatchmakingCreateMatchmakingTicketResultWrapper(const PFMatchmakingCreateMatchmakingTicketResult& model) :
        ModelWrapper<PFMatchmakingCreateMatchmakingTicketResult, Alloc>{ model },
        m_ticketId{ SafeString(model.ticketId) }
    {
        SetModelPointers();
    }

    PFMatchmakingCreateMatchmakingTicketResultWrapper(const PFMatchmakingCreateMatchmakingTicketResultWrapper& src) :
        PFMatchmakingCreateMatchmakingTicketResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingCreateMatchmakingTicketResultWrapper(PFMatchmakingCreateMatchmakingTicketResultWrapper&& src) :
        PFMatchmakingCreateMatchmakingTicketResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCreateMatchmakingTicketResultWrapper& operator=(PFMatchmakingCreateMatchmakingTicketResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCreateMatchmakingTicketResultWrapper() = default;

    friend void swap(PFMatchmakingCreateMatchmakingTicketResultWrapper& lhs, PFMatchmakingCreateMatchmakingTicketResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_ticketId, rhs.m_ticketId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTicketId(String value)
    {
        m_ticketId = std::move(value);
        this->m_model.ticketId =  m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.ticketId = m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

    String m_ticketId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper : public ModelWrapper<PFMatchmakingMatchmakingPlayerWithTeamAssignment, Alloc>
{
public:
    using ModelType = typename PFMatchmakingMatchmakingPlayerWithTeamAssignment;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper() = default;

    PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper(const PFMatchmakingMatchmakingPlayerWithTeamAssignment& model) :
        ModelWrapper<PFMatchmakingMatchmakingPlayerWithTeamAssignment, Alloc>{ model },
        m_attributes{ model.attributes ? StdExtra::optional<PFMatchmakingMatchmakingPlayerAttributesWrapper<Alloc>>{ *model.attributes } : StdExtra::nullopt },
        m_entity{ model.entity ? *model.entity : decltype(*model.entity){} },
        m_teamId{ SafeString(model.teamId) }
    {
        SetModelPointers();
    }

    PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper(const PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper& src) :
        PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper{ src.Model() }
    {
    }

    PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper(PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper&& src) :
        PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper& operator=(PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper() = default;

    friend void swap(PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper& lhs, PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_attributes, rhs.m_attributes);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_teamId, rhs.m_teamId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAttributes(StdExtra::optional<PFMatchmakingMatchmakingPlayerAttributesWrapper<Alloc>> value)
    {
        m_attributes = std::move(value);
        this->m_model.attributes = m_attributes ? &m_attributes->Model() : nullptr;
    }

    void SetEntity(PFEntityKeyWrapper<Alloc> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = &m_entity.Model();
    }

    void SetTeamId(String value)
    {
        m_teamId = std::move(value);
        this->m_model.teamId =  m_teamId.empty() ? nullptr : m_teamId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.attributes = m_attributes ?  &m_attributes->Model() : nullptr;
        this->m_model.entity = &m_entity.Model();
        this->m_model.teamId = m_teamId.empty() ? nullptr : m_teamId.data();
    }

    StdExtra::optional<PFMatchmakingMatchmakingPlayerAttributesWrapper<Alloc>> m_attributes;
    PFEntityKeyWrapper<Alloc> m_entity;
    String m_teamId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingServerDetailsWrapper : public ModelWrapper<PFMatchmakingServerDetails, Alloc>
{
public:
    using ModelType = typename PFMatchmakingServerDetails;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingServerDetailsWrapper() = default;

    PFMatchmakingServerDetailsWrapper(const PFMatchmakingServerDetails& model) :
        ModelWrapper<PFMatchmakingServerDetails, Alloc>{ model },
        m_fqdn{ SafeString(model.fqdn) },
        m_iPV4Address{ SafeString(model.iPV4Address) },
        m_ports{ model.ports, model.ports + model.portsCount },
        m_region{ SafeString(model.region) }
    {
        SetModelPointers();
    }

    PFMatchmakingServerDetailsWrapper(const PFMatchmakingServerDetailsWrapper& src) :
        PFMatchmakingServerDetailsWrapper{ src.Model() }
    {
    }

    PFMatchmakingServerDetailsWrapper(PFMatchmakingServerDetailsWrapper&& src) :
        PFMatchmakingServerDetailsWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingServerDetailsWrapper& operator=(PFMatchmakingServerDetailsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingServerDetailsWrapper() = default;

    friend void swap(PFMatchmakingServerDetailsWrapper& lhs, PFMatchmakingServerDetailsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fqdn, rhs.m_fqdn);
        swap(lhs.m_iPV4Address, rhs.m_iPV4Address);
        swap(lhs.m_ports, rhs.m_ports);
        swap(lhs.m_region, rhs.m_region);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFqdn(String value)
    {
        m_fqdn = std::move(value);
        this->m_model.fqdn =  m_fqdn.empty() ? nullptr : m_fqdn.data();
    }

    void SetIPV4Address(String value)
    {
        m_iPV4Address = std::move(value);
        this->m_model.iPV4Address =  m_iPV4Address.empty() ? nullptr : m_iPV4Address.data();
    }

    void SetPorts(ModelVector<PFPortWrapper<Alloc>, Alloc> value)
    {
        m_ports = std::move(value);
        this->m_model.ports =  m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.portsCount =  static_cast<uint32_t>(m_ports.size());
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.fqdn = m_fqdn.empty() ? nullptr : m_fqdn.data();
        this->m_model.iPV4Address = m_iPV4Address.empty() ? nullptr : m_iPV4Address.data();
        this->m_model.ports = m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
    }

    String m_fqdn;
    String m_iPV4Address;
    ModelVector<PFPortWrapper<Alloc>, Alloc> m_ports;
    String m_region;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCreateServerBackfillTicketRequestWrapper : public ModelWrapper<PFMatchmakingCreateServerBackfillTicketRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCreateServerBackfillTicketRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCreateServerBackfillTicketRequestWrapper() = default;

    PFMatchmakingCreateServerBackfillTicketRequestWrapper(const PFMatchmakingCreateServerBackfillTicketRequest& model) :
        ModelWrapper<PFMatchmakingCreateServerBackfillTicketRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_members{ model.members, model.members + model.membersCount },
        m_queueName{ SafeString(model.queueName) },
        m_serverDetails{ model.serverDetails ? StdExtra::optional<PFMatchmakingServerDetailsWrapper<Alloc>>{ *model.serverDetails } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMatchmakingCreateServerBackfillTicketRequestWrapper(const PFMatchmakingCreateServerBackfillTicketRequestWrapper& src) :
        PFMatchmakingCreateServerBackfillTicketRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingCreateServerBackfillTicketRequestWrapper(PFMatchmakingCreateServerBackfillTicketRequestWrapper&& src) :
        PFMatchmakingCreateServerBackfillTicketRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCreateServerBackfillTicketRequestWrapper& operator=(PFMatchmakingCreateServerBackfillTicketRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCreateServerBackfillTicketRequestWrapper() = default;

    friend void swap(PFMatchmakingCreateServerBackfillTicketRequestWrapper& lhs, PFMatchmakingCreateServerBackfillTicketRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_members, rhs.m_members);
        swap(lhs.m_queueName, rhs.m_queueName);
        swap(lhs.m_serverDetails, rhs.m_serverDetails);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetGiveUpAfterSeconds(int32_t value)
    {
        this->m_model.giveUpAfterSeconds = value;
    }

    void SetMembers(ModelVector<PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper<Alloc>, Alloc> value)
    {
        m_members = std::move(value);
        this->m_model.members =  m_members.empty() ? nullptr : m_members.data();
        this->m_model.membersCount =  static_cast<uint32_t>(m_members.size());
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

    void SetServerDetails(StdExtra::optional<PFMatchmakingServerDetailsWrapper<Alloc>> value)
    {
        m_serverDetails = std::move(value);
        this->m_model.serverDetails = m_serverDetails ? &m_serverDetails->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.members = m_members.empty() ? nullptr : m_members.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
        this->m_model.serverDetails = m_serverDetails ?  &m_serverDetails->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper<Alloc>, Alloc> m_members;
    String m_queueName;
    StdExtra::optional<PFMatchmakingServerDetailsWrapper<Alloc>> m_serverDetails;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCreateServerBackfillTicketResultWrapper : public ModelWrapper<PFMatchmakingCreateServerBackfillTicketResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCreateServerBackfillTicketResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCreateServerBackfillTicketResultWrapper() = default;

    PFMatchmakingCreateServerBackfillTicketResultWrapper(const PFMatchmakingCreateServerBackfillTicketResult& model) :
        ModelWrapper<PFMatchmakingCreateServerBackfillTicketResult, Alloc>{ model },
        m_ticketId{ SafeString(model.ticketId) }
    {
        SetModelPointers();
    }

    PFMatchmakingCreateServerBackfillTicketResultWrapper(const PFMatchmakingCreateServerBackfillTicketResultWrapper& src) :
        PFMatchmakingCreateServerBackfillTicketResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingCreateServerBackfillTicketResultWrapper(PFMatchmakingCreateServerBackfillTicketResultWrapper&& src) :
        PFMatchmakingCreateServerBackfillTicketResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCreateServerBackfillTicketResultWrapper& operator=(PFMatchmakingCreateServerBackfillTicketResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCreateServerBackfillTicketResultWrapper() = default;

    friend void swap(PFMatchmakingCreateServerBackfillTicketResultWrapper& lhs, PFMatchmakingCreateServerBackfillTicketResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_ticketId, rhs.m_ticketId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTicketId(String value)
    {
        m_ticketId = std::move(value);
        this->m_model.ticketId =  m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.ticketId = m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

    String m_ticketId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingCreateServerMatchmakingTicketRequestWrapper : public ModelWrapper<PFMatchmakingCreateServerMatchmakingTicketRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingCreateServerMatchmakingTicketRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingCreateServerMatchmakingTicketRequestWrapper() = default;

    PFMatchmakingCreateServerMatchmakingTicketRequestWrapper(const PFMatchmakingCreateServerMatchmakingTicketRequest& model) :
        ModelWrapper<PFMatchmakingCreateServerMatchmakingTicketRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_members{ model.members, model.members + model.membersCount },
        m_queueName{ SafeString(model.queueName) }
    {
        SetModelPointers();
    }

    PFMatchmakingCreateServerMatchmakingTicketRequestWrapper(const PFMatchmakingCreateServerMatchmakingTicketRequestWrapper& src) :
        PFMatchmakingCreateServerMatchmakingTicketRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingCreateServerMatchmakingTicketRequestWrapper(PFMatchmakingCreateServerMatchmakingTicketRequestWrapper&& src) :
        PFMatchmakingCreateServerMatchmakingTicketRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingCreateServerMatchmakingTicketRequestWrapper& operator=(PFMatchmakingCreateServerMatchmakingTicketRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingCreateServerMatchmakingTicketRequestWrapper() = default;

    friend void swap(PFMatchmakingCreateServerMatchmakingTicketRequestWrapper& lhs, PFMatchmakingCreateServerMatchmakingTicketRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_members, rhs.m_members);
        swap(lhs.m_queueName, rhs.m_queueName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetGiveUpAfterSeconds(int32_t value)
    {
        this->m_model.giveUpAfterSeconds = value;
    }

    void SetMembers(ModelVector<PFMatchmakingMatchmakingPlayerWrapper<Alloc>, Alloc> value)
    {
        m_members = std::move(value);
        this->m_model.members =  m_members.empty() ? nullptr : m_members.data();
        this->m_model.membersCount =  static_cast<uint32_t>(m_members.size());
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.members = m_members.empty() ? nullptr : m_members.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFMatchmakingMatchmakingPlayerWrapper<Alloc>, Alloc> m_members;
    String m_queueName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetMatchRequestWrapper : public ModelWrapper<PFMatchmakingGetMatchRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetMatchRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetMatchRequestWrapper() = default;

    PFMatchmakingGetMatchRequestWrapper(const PFMatchmakingGetMatchRequest& model) :
        ModelWrapper<PFMatchmakingGetMatchRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_matchId{ SafeString(model.matchId) },
        m_queueName{ SafeString(model.queueName) }
    {
        SetModelPointers();
    }

    PFMatchmakingGetMatchRequestWrapper(const PFMatchmakingGetMatchRequestWrapper& src) :
        PFMatchmakingGetMatchRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetMatchRequestWrapper(PFMatchmakingGetMatchRequestWrapper&& src) :
        PFMatchmakingGetMatchRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetMatchRequestWrapper& operator=(PFMatchmakingGetMatchRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetMatchRequestWrapper() = default;

    friend void swap(PFMatchmakingGetMatchRequestWrapper& lhs, PFMatchmakingGetMatchRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_matchId, rhs.m_matchId);
        swap(lhs.m_queueName, rhs.m_queueName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEscapeObject(bool value)
    {
        this->m_model.escapeObject = value;
    }

    void SetMatchId(String value)
    {
        m_matchId = std::move(value);
        this->m_model.matchId =  m_matchId.empty() ? nullptr : m_matchId.data();
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

    void SetReturnMemberAttributes(bool value)
    {
        this->m_model.returnMemberAttributes = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.matchId = m_matchId.empty() ? nullptr : m_matchId.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_matchId;
    String m_queueName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetMatchResultWrapper : public ModelWrapper<PFMatchmakingGetMatchResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetMatchResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetMatchResultWrapper() = default;

    PFMatchmakingGetMatchResultWrapper(const PFMatchmakingGetMatchResult& model) :
        ModelWrapper<PFMatchmakingGetMatchResult, Alloc>{ model },
        m_matchId{ SafeString(model.matchId) },
        m_members{ model.members, model.members + model.membersCount },
        m_regionPreferences{ model.regionPreferences, model.regionPreferences + model.regionPreferencesCount },
        m_serverDetails{ model.serverDetails ? StdExtra::optional<PFMatchmakingServerDetailsWrapper<Alloc>>{ *model.serverDetails } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMatchmakingGetMatchResultWrapper(const PFMatchmakingGetMatchResultWrapper& src) :
        PFMatchmakingGetMatchResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetMatchResultWrapper(PFMatchmakingGetMatchResultWrapper&& src) :
        PFMatchmakingGetMatchResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetMatchResultWrapper& operator=(PFMatchmakingGetMatchResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetMatchResultWrapper() = default;

    friend void swap(PFMatchmakingGetMatchResultWrapper& lhs, PFMatchmakingGetMatchResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_matchId, rhs.m_matchId);
        swap(lhs.m_members, rhs.m_members);
        swap(lhs.m_regionPreferences, rhs.m_regionPreferences);
        swap(lhs.m_serverDetails, rhs.m_serverDetails);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetMatchId(String value)
    {
        m_matchId = std::move(value);
        this->m_model.matchId =  m_matchId.empty() ? nullptr : m_matchId.data();
    }

    void SetMembers(ModelVector<PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper<Alloc>, Alloc> value)
    {
        m_members = std::move(value);
        this->m_model.members =  m_members.empty() ? nullptr : m_members.data();
        this->m_model.membersCount =  static_cast<uint32_t>(m_members.size());
    }

    void SetRegionPreferences(CStringVector<Alloc> value)
    {
        m_regionPreferences = std::move(value);
        this->m_model.regionPreferences =  m_regionPreferences.empty() ? nullptr : m_regionPreferences.data();
        this->m_model.regionPreferencesCount =  static_cast<uint32_t>(m_regionPreferences.size());
    }

    void SetServerDetails(StdExtra::optional<PFMatchmakingServerDetailsWrapper<Alloc>> value)
    {
        m_serverDetails = std::move(value);
        this->m_model.serverDetails = m_serverDetails ? &m_serverDetails->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.matchId = m_matchId.empty() ? nullptr : m_matchId.data();
        this->m_model.members = m_members.empty() ? nullptr : m_members.data();
        this->m_model.regionPreferences = m_regionPreferences.empty() ? nullptr : m_regionPreferences.data();
        this->m_model.serverDetails = m_serverDetails ?  &m_serverDetails->Model() : nullptr;
    }

    String m_matchId;
    ModelVector<PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper<Alloc>, Alloc> m_members;
    CStringVector<Alloc> m_regionPreferences;
    StdExtra::optional<PFMatchmakingServerDetailsWrapper<Alloc>> m_serverDetails;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetMatchmakingTicketRequestWrapper : public ModelWrapper<PFMatchmakingGetMatchmakingTicketRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetMatchmakingTicketRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetMatchmakingTicketRequestWrapper() = default;

    PFMatchmakingGetMatchmakingTicketRequestWrapper(const PFMatchmakingGetMatchmakingTicketRequest& model) :
        ModelWrapper<PFMatchmakingGetMatchmakingTicketRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_queueName{ SafeString(model.queueName) },
        m_ticketId{ SafeString(model.ticketId) }
    {
        SetModelPointers();
    }

    PFMatchmakingGetMatchmakingTicketRequestWrapper(const PFMatchmakingGetMatchmakingTicketRequestWrapper& src) :
        PFMatchmakingGetMatchmakingTicketRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetMatchmakingTicketRequestWrapper(PFMatchmakingGetMatchmakingTicketRequestWrapper&& src) :
        PFMatchmakingGetMatchmakingTicketRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetMatchmakingTicketRequestWrapper& operator=(PFMatchmakingGetMatchmakingTicketRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetMatchmakingTicketRequestWrapper() = default;

    friend void swap(PFMatchmakingGetMatchmakingTicketRequestWrapper& lhs, PFMatchmakingGetMatchmakingTicketRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_queueName, rhs.m_queueName);
        swap(lhs.m_ticketId, rhs.m_ticketId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEscapeObject(bool value)
    {
        this->m_model.escapeObject = value;
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

    void SetTicketId(String value)
    {
        m_ticketId = std::move(value);
        this->m_model.ticketId =  m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
        this->m_model.ticketId = m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_queueName;
    String m_ticketId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetMatchmakingTicketResultWrapper : public ModelWrapper<PFMatchmakingGetMatchmakingTicketResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetMatchmakingTicketResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetMatchmakingTicketResultWrapper() = default;

    PFMatchmakingGetMatchmakingTicketResultWrapper(const PFMatchmakingGetMatchmakingTicketResult& model) :
        ModelWrapper<PFMatchmakingGetMatchmakingTicketResult, Alloc>{ model },
        m_cancellationReasonString{ SafeString(model.cancellationReasonString) },
        m_creator{ model.creator ? *model.creator : decltype(*model.creator){} },
        m_matchId{ SafeString(model.matchId) },
        m_members{ model.members, model.members + model.membersCount },
        m_membersToMatchWith{ model.membersToMatchWith, model.membersToMatchWith + model.membersToMatchWithCount },
        m_queueName{ SafeString(model.queueName) },
        m_status{ SafeString(model.status) },
        m_ticketId{ SafeString(model.ticketId) }
    {
        SetModelPointers();
    }

    PFMatchmakingGetMatchmakingTicketResultWrapper(const PFMatchmakingGetMatchmakingTicketResultWrapper& src) :
        PFMatchmakingGetMatchmakingTicketResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetMatchmakingTicketResultWrapper(PFMatchmakingGetMatchmakingTicketResultWrapper&& src) :
        PFMatchmakingGetMatchmakingTicketResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetMatchmakingTicketResultWrapper& operator=(PFMatchmakingGetMatchmakingTicketResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetMatchmakingTicketResultWrapper() = default;

    friend void swap(PFMatchmakingGetMatchmakingTicketResultWrapper& lhs, PFMatchmakingGetMatchmakingTicketResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_cancellationReasonString, rhs.m_cancellationReasonString);
        swap(lhs.m_creator, rhs.m_creator);
        swap(lhs.m_matchId, rhs.m_matchId);
        swap(lhs.m_members, rhs.m_members);
        swap(lhs.m_membersToMatchWith, rhs.m_membersToMatchWith);
        swap(lhs.m_queueName, rhs.m_queueName);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_ticketId, rhs.m_ticketId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCancellationReasonString(String value)
    {
        m_cancellationReasonString = std::move(value);
        this->m_model.cancellationReasonString =  m_cancellationReasonString.empty() ? nullptr : m_cancellationReasonString.data();
    }

    void SetCreated(time_t value)
    {
        this->m_model.created = value;
    }

    void SetCreator(PFEntityKeyWrapper<Alloc> value)
    {
        m_creator = std::move(value);
        this->m_model.creator = &m_creator.Model();
    }

    void SetGiveUpAfterSeconds(int32_t value)
    {
        this->m_model.giveUpAfterSeconds = value;
    }

    void SetMatchId(String value)
    {
        m_matchId = std::move(value);
        this->m_model.matchId =  m_matchId.empty() ? nullptr : m_matchId.data();
    }

    void SetMembers(ModelVector<PFMatchmakingMatchmakingPlayerWrapper<Alloc>, Alloc> value)
    {
        m_members = std::move(value);
        this->m_model.members =  m_members.empty() ? nullptr : m_members.data();
        this->m_model.membersCount =  static_cast<uint32_t>(m_members.size());
    }

    void SetMembersToMatchWith(ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> value)
    {
        m_membersToMatchWith = std::move(value);
        this->m_model.membersToMatchWith =  m_membersToMatchWith.empty() ? nullptr : m_membersToMatchWith.data();
        this->m_model.membersToMatchWithCount =  static_cast<uint32_t>(m_membersToMatchWith.size());
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

    void SetStatus(String value)
    {
        m_status = std::move(value);
        this->m_model.status =  m_status.empty() ? nullptr : m_status.data();
    }

    void SetTicketId(String value)
    {
        m_ticketId = std::move(value);
        this->m_model.ticketId =  m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.cancellationReasonString = m_cancellationReasonString.empty() ? nullptr : m_cancellationReasonString.data();
        this->m_model.creator = &m_creator.Model();
        this->m_model.matchId = m_matchId.empty() ? nullptr : m_matchId.data();
        this->m_model.members = m_members.empty() ? nullptr : m_members.data();
        this->m_model.membersToMatchWith = m_membersToMatchWith.empty() ? nullptr : m_membersToMatchWith.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
        this->m_model.status = m_status.empty() ? nullptr : m_status.data();
        this->m_model.ticketId = m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

    String m_cancellationReasonString;
    PFEntityKeyWrapper<Alloc> m_creator;
    String m_matchId;
    ModelVector<PFMatchmakingMatchmakingPlayerWrapper<Alloc>, Alloc> m_members;
    ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> m_membersToMatchWith;
    String m_queueName;
    String m_status;
    String m_ticketId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetQueueStatisticsRequestWrapper : public ModelWrapper<PFMatchmakingGetQueueStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetQueueStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetQueueStatisticsRequestWrapper() = default;

    PFMatchmakingGetQueueStatisticsRequestWrapper(const PFMatchmakingGetQueueStatisticsRequest& model) :
        ModelWrapper<PFMatchmakingGetQueueStatisticsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_queueName{ SafeString(model.queueName) }
    {
        SetModelPointers();
    }

    PFMatchmakingGetQueueStatisticsRequestWrapper(const PFMatchmakingGetQueueStatisticsRequestWrapper& src) :
        PFMatchmakingGetQueueStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetQueueStatisticsRequestWrapper(PFMatchmakingGetQueueStatisticsRequestWrapper&& src) :
        PFMatchmakingGetQueueStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetQueueStatisticsRequestWrapper& operator=(PFMatchmakingGetQueueStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetQueueStatisticsRequestWrapper() = default;

    friend void swap(PFMatchmakingGetQueueStatisticsRequestWrapper& lhs, PFMatchmakingGetQueueStatisticsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_queueName, rhs.m_queueName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_queueName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingStatisticsWrapper : public ModelWrapper<PFMatchmakingStatistics, Alloc>
{
public:
    using ModelType = typename PFMatchmakingStatistics;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFMatchmakingStatistics, Alloc>::ModelWrapper;

    void SetAverage(double value)
    {
        this->m_model.average = value;
    }

    void SetPercentile50(double value)
    {
        this->m_model.percentile50 = value;
    }

    void SetPercentile90(double value)
    {
        this->m_model.percentile90 = value;
    }

    void SetPercentile99(double value)
    {
        this->m_model.percentile99 = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetQueueStatisticsResultWrapper : public ModelWrapper<PFMatchmakingGetQueueStatisticsResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetQueueStatisticsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetQueueStatisticsResultWrapper() = default;

    PFMatchmakingGetQueueStatisticsResultWrapper(const PFMatchmakingGetQueueStatisticsResult& model) :
        ModelWrapper<PFMatchmakingGetQueueStatisticsResult, Alloc>{ model },
        m_numberOfPlayersMatching{ model.numberOfPlayersMatching ? StdExtra::optional<uint32_t>{ *model.numberOfPlayersMatching } : StdExtra::nullopt },
        m_timeToMatchStatisticsInSeconds{ model.timeToMatchStatisticsInSeconds ? StdExtra::optional<PFMatchmakingStatisticsWrapper<Alloc>>{ *model.timeToMatchStatisticsInSeconds } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMatchmakingGetQueueStatisticsResultWrapper(const PFMatchmakingGetQueueStatisticsResultWrapper& src) :
        PFMatchmakingGetQueueStatisticsResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetQueueStatisticsResultWrapper(PFMatchmakingGetQueueStatisticsResultWrapper&& src) :
        PFMatchmakingGetQueueStatisticsResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetQueueStatisticsResultWrapper& operator=(PFMatchmakingGetQueueStatisticsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetQueueStatisticsResultWrapper() = default;

    friend void swap(PFMatchmakingGetQueueStatisticsResultWrapper& lhs, PFMatchmakingGetQueueStatisticsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_numberOfPlayersMatching, rhs.m_numberOfPlayersMatching);
        swap(lhs.m_timeToMatchStatisticsInSeconds, rhs.m_timeToMatchStatisticsInSeconds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetNumberOfPlayersMatching(StdExtra::optional<uint32_t> value)
    {
        m_numberOfPlayersMatching = std::move(value);
        this->m_model.numberOfPlayersMatching = m_numberOfPlayersMatching ? m_numberOfPlayersMatching.operator->() : nullptr;
    }

    void SetTimeToMatchStatisticsInSeconds(StdExtra::optional<PFMatchmakingStatisticsWrapper<Alloc>> value)
    {
        m_timeToMatchStatisticsInSeconds = std::move(value);
        this->m_model.timeToMatchStatisticsInSeconds = m_timeToMatchStatisticsInSeconds ? &m_timeToMatchStatisticsInSeconds->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.numberOfPlayersMatching = m_numberOfPlayersMatching ? m_numberOfPlayersMatching.operator->() : nullptr;
        this->m_model.timeToMatchStatisticsInSeconds = m_timeToMatchStatisticsInSeconds ?  &m_timeToMatchStatisticsInSeconds->Model() : nullptr;
    }

    StdExtra::optional<uint32_t> m_numberOfPlayersMatching;
    StdExtra::optional<PFMatchmakingStatisticsWrapper<Alloc>> m_timeToMatchStatisticsInSeconds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetServerBackfillTicketRequestWrapper : public ModelWrapper<PFMatchmakingGetServerBackfillTicketRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetServerBackfillTicketRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetServerBackfillTicketRequestWrapper() = default;

    PFMatchmakingGetServerBackfillTicketRequestWrapper(const PFMatchmakingGetServerBackfillTicketRequest& model) :
        ModelWrapper<PFMatchmakingGetServerBackfillTicketRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_queueName{ SafeString(model.queueName) },
        m_ticketId{ SafeString(model.ticketId) }
    {
        SetModelPointers();
    }

    PFMatchmakingGetServerBackfillTicketRequestWrapper(const PFMatchmakingGetServerBackfillTicketRequestWrapper& src) :
        PFMatchmakingGetServerBackfillTicketRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetServerBackfillTicketRequestWrapper(PFMatchmakingGetServerBackfillTicketRequestWrapper&& src) :
        PFMatchmakingGetServerBackfillTicketRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetServerBackfillTicketRequestWrapper& operator=(PFMatchmakingGetServerBackfillTicketRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetServerBackfillTicketRequestWrapper() = default;

    friend void swap(PFMatchmakingGetServerBackfillTicketRequestWrapper& lhs, PFMatchmakingGetServerBackfillTicketRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_queueName, rhs.m_queueName);
        swap(lhs.m_ticketId, rhs.m_ticketId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEscapeObject(bool value)
    {
        this->m_model.escapeObject = value;
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

    void SetTicketId(String value)
    {
        m_ticketId = std::move(value);
        this->m_model.ticketId =  m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
        this->m_model.ticketId = m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_queueName;
    String m_ticketId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingGetServerBackfillTicketResultWrapper : public ModelWrapper<PFMatchmakingGetServerBackfillTicketResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingGetServerBackfillTicketResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingGetServerBackfillTicketResultWrapper() = default;

    PFMatchmakingGetServerBackfillTicketResultWrapper(const PFMatchmakingGetServerBackfillTicketResult& model) :
        ModelWrapper<PFMatchmakingGetServerBackfillTicketResult, Alloc>{ model },
        m_cancellationReasonString{ SafeString(model.cancellationReasonString) },
        m_matchId{ SafeString(model.matchId) },
        m_members{ model.members, model.members + model.membersCount },
        m_queueName{ SafeString(model.queueName) },
        m_serverDetails{ model.serverDetails ? *model.serverDetails : decltype(*model.serverDetails){} },
        m_status{ SafeString(model.status) },
        m_ticketId{ SafeString(model.ticketId) }
    {
        SetModelPointers();
    }

    PFMatchmakingGetServerBackfillTicketResultWrapper(const PFMatchmakingGetServerBackfillTicketResultWrapper& src) :
        PFMatchmakingGetServerBackfillTicketResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingGetServerBackfillTicketResultWrapper(PFMatchmakingGetServerBackfillTicketResultWrapper&& src) :
        PFMatchmakingGetServerBackfillTicketResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingGetServerBackfillTicketResultWrapper& operator=(PFMatchmakingGetServerBackfillTicketResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingGetServerBackfillTicketResultWrapper() = default;

    friend void swap(PFMatchmakingGetServerBackfillTicketResultWrapper& lhs, PFMatchmakingGetServerBackfillTicketResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_cancellationReasonString, rhs.m_cancellationReasonString);
        swap(lhs.m_matchId, rhs.m_matchId);
        swap(lhs.m_members, rhs.m_members);
        swap(lhs.m_queueName, rhs.m_queueName);
        swap(lhs.m_serverDetails, rhs.m_serverDetails);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_ticketId, rhs.m_ticketId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCancellationReasonString(String value)
    {
        m_cancellationReasonString = std::move(value);
        this->m_model.cancellationReasonString =  m_cancellationReasonString.empty() ? nullptr : m_cancellationReasonString.data();
    }

    void SetCreated(time_t value)
    {
        this->m_model.created = value;
    }

    void SetGiveUpAfterSeconds(int32_t value)
    {
        this->m_model.giveUpAfterSeconds = value;
    }

    void SetMatchId(String value)
    {
        m_matchId = std::move(value);
        this->m_model.matchId =  m_matchId.empty() ? nullptr : m_matchId.data();
    }

    void SetMembers(ModelVector<PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper<Alloc>, Alloc> value)
    {
        m_members = std::move(value);
        this->m_model.members =  m_members.empty() ? nullptr : m_members.data();
        this->m_model.membersCount =  static_cast<uint32_t>(m_members.size());
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

    void SetServerDetails(PFMatchmakingServerDetailsWrapper<Alloc> value)
    {
        m_serverDetails = std::move(value);
        this->m_model.serverDetails = &m_serverDetails.Model();
    }

    void SetStatus(String value)
    {
        m_status = std::move(value);
        this->m_model.status =  m_status.empty() ? nullptr : m_status.data();
    }

    void SetTicketId(String value)
    {
        m_ticketId = std::move(value);
        this->m_model.ticketId =  m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.cancellationReasonString = m_cancellationReasonString.empty() ? nullptr : m_cancellationReasonString.data();
        this->m_model.matchId = m_matchId.empty() ? nullptr : m_matchId.data();
        this->m_model.members = m_members.empty() ? nullptr : m_members.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
        this->m_model.serverDetails = &m_serverDetails.Model();
        this->m_model.status = m_status.empty() ? nullptr : m_status.data();
        this->m_model.ticketId = m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

    String m_cancellationReasonString;
    String m_matchId;
    ModelVector<PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper<Alloc>, Alloc> m_members;
    String m_queueName;
    PFMatchmakingServerDetailsWrapper<Alloc> m_serverDetails;
    String m_status;
    String m_ticketId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingJoinMatchmakingTicketRequestWrapper : public ModelWrapper<PFMatchmakingJoinMatchmakingTicketRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingJoinMatchmakingTicketRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingJoinMatchmakingTicketRequestWrapper() = default;

    PFMatchmakingJoinMatchmakingTicketRequestWrapper(const PFMatchmakingJoinMatchmakingTicketRequest& model) :
        ModelWrapper<PFMatchmakingJoinMatchmakingTicketRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_member{ model.member ? *model.member : decltype(*model.member){} },
        m_queueName{ SafeString(model.queueName) },
        m_ticketId{ SafeString(model.ticketId) }
    {
        SetModelPointers();
    }

    PFMatchmakingJoinMatchmakingTicketRequestWrapper(const PFMatchmakingJoinMatchmakingTicketRequestWrapper& src) :
        PFMatchmakingJoinMatchmakingTicketRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingJoinMatchmakingTicketRequestWrapper(PFMatchmakingJoinMatchmakingTicketRequestWrapper&& src) :
        PFMatchmakingJoinMatchmakingTicketRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingJoinMatchmakingTicketRequestWrapper& operator=(PFMatchmakingJoinMatchmakingTicketRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingJoinMatchmakingTicketRequestWrapper() = default;

    friend void swap(PFMatchmakingJoinMatchmakingTicketRequestWrapper& lhs, PFMatchmakingJoinMatchmakingTicketRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_member, rhs.m_member);
        swap(lhs.m_queueName, rhs.m_queueName);
        swap(lhs.m_ticketId, rhs.m_ticketId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMember(PFMatchmakingMatchmakingPlayerWrapper<Alloc> value)
    {
        m_member = std::move(value);
        this->m_model.member = &m_member.Model();
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

    void SetTicketId(String value)
    {
        m_ticketId = std::move(value);
        this->m_model.ticketId =  m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.member = &m_member.Model();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
        this->m_model.ticketId = m_ticketId.empty() ? nullptr : m_ticketId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFMatchmakingMatchmakingPlayerWrapper<Alloc> m_member;
    String m_queueName;
    String m_ticketId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper : public ModelWrapper<PFMatchmakingListMatchmakingTicketsForPlayerRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingListMatchmakingTicketsForPlayerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper() = default;

    PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper(const PFMatchmakingListMatchmakingTicketsForPlayerRequest& model) :
        ModelWrapper<PFMatchmakingListMatchmakingTicketsForPlayerRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_queueName{ SafeString(model.queueName) }
    {
        SetModelPointers();
    }

    PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper(const PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper& src) :
        PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper(PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper&& src) :
        PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper& operator=(PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper() = default;

    friend void swap(PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper& lhs, PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_queueName, rhs.m_queueName);
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

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_queueName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper : public ModelWrapper<PFMatchmakingListMatchmakingTicketsForPlayerResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingListMatchmakingTicketsForPlayerResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper() = default;

    PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper(const PFMatchmakingListMatchmakingTicketsForPlayerResult& model) :
        ModelWrapper<PFMatchmakingListMatchmakingTicketsForPlayerResult, Alloc>{ model },
        m_ticketIds{ model.ticketIds, model.ticketIds + model.ticketIdsCount }
    {
        SetModelPointers();
    }

    PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper(const PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper& src) :
        PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper(PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper&& src) :
        PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper& operator=(PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper() = default;

    friend void swap(PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper& lhs, PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_ticketIds, rhs.m_ticketIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTicketIds(CStringVector<Alloc> value)
    {
        m_ticketIds = std::move(value);
        this->m_model.ticketIds =  m_ticketIds.empty() ? nullptr : m_ticketIds.data();
        this->m_model.ticketIdsCount =  static_cast<uint32_t>(m_ticketIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.ticketIds = m_ticketIds.empty() ? nullptr : m_ticketIds.data();
    }

    CStringVector<Alloc> m_ticketIds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper : public ModelWrapper<PFMatchmakingListServerBackfillTicketsForPlayerRequest, Alloc>
{
public:
    using ModelType = typename PFMatchmakingListServerBackfillTicketsForPlayerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper() = default;

    PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper(const PFMatchmakingListServerBackfillTicketsForPlayerRequest& model) :
        ModelWrapper<PFMatchmakingListServerBackfillTicketsForPlayerRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? *model.entity : decltype(*model.entity){} },
        m_queueName{ SafeString(model.queueName) }
    {
        SetModelPointers();
    }

    PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper(const PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper& src) :
        PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper{ src.Model() }
    {
    }

    PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper(PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper&& src) :
        PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper& operator=(PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper() = default;

    friend void swap(PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper& lhs, PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_queueName, rhs.m_queueName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(PFEntityKeyWrapper<Alloc> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = &m_entity.Model();
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = &m_entity.Model();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFEntityKeyWrapper<Alloc> m_entity;
    String m_queueName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper : public ModelWrapper<PFMatchmakingListServerBackfillTicketsForPlayerResult, Alloc>
{
public:
    using ModelType = typename PFMatchmakingListServerBackfillTicketsForPlayerResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper() = default;

    PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper(const PFMatchmakingListServerBackfillTicketsForPlayerResult& model) :
        ModelWrapper<PFMatchmakingListServerBackfillTicketsForPlayerResult, Alloc>{ model },
        m_ticketIds{ model.ticketIds, model.ticketIds + model.ticketIdsCount }
    {
        SetModelPointers();
    }

    PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper(const PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper& src) :
        PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper{ src.Model() }
    {
    }

    PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper(PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper&& src) :
        PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper{}
    {
        swap(*this, src);
    }

    PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper& operator=(PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper() = default;

    friend void swap(PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper& lhs, PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_ticketIds, rhs.m_ticketIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTicketIds(CStringVector<Alloc> value)
    {
        m_ticketIds = std::move(value);
        this->m_model.ticketIds =  m_ticketIds.empty() ? nullptr : m_ticketIds.data();
        this->m_model.ticketIdsCount =  static_cast<uint32_t>(m_ticketIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.ticketIds = m_ticketIds.empty() ? nullptr : m_ticketIds.data();
    }

    CStringVector<Alloc> m_ticketIds;
};

} // namespace Wrappers
} // namespace PlayFab
