// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFSharedDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFItemInstanceWrapper : public ModelWrapper<PFItemInstance, Alloc>
{
public:
    using ModelType = typename PFItemInstance;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFItemInstanceWrapper() = default;

    PFItemInstanceWrapper(const PFItemInstance& model) :
        ModelWrapper<PFItemInstance, Alloc>{ model },
        m_annotation{ SafeString(model.annotation) },
        m_bundleContents{ model.bundleContents, model.bundleContents + model.bundleContentsCount },
        m_bundleParent{ SafeString(model.bundleParent) },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customData{ model.customData, model.customData + model.customDataCount },
        m_displayName{ SafeString(model.displayName) },
        m_expiration{ model.expiration ? StdExtra::optional<time_t>{ *model.expiration } : StdExtra::nullopt },
        m_itemClass{ SafeString(model.itemClass) },
        m_itemId{ SafeString(model.itemId) },
        m_itemInstanceId{ SafeString(model.itemInstanceId) },
        m_purchaseDate{ model.purchaseDate ? StdExtra::optional<time_t>{ *model.purchaseDate } : StdExtra::nullopt },
        m_remainingUses{ model.remainingUses ? StdExtra::optional<int32_t>{ *model.remainingUses } : StdExtra::nullopt },
        m_unitCurrency{ SafeString(model.unitCurrency) },
        m_usesIncrementedBy{ model.usesIncrementedBy ? StdExtra::optional<int32_t>{ *model.usesIncrementedBy } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFItemInstanceWrapper(const PFItemInstanceWrapper& src) :
        PFItemInstanceWrapper{ src.Model() }
    {
    }

    PFItemInstanceWrapper(PFItemInstanceWrapper&& src) :
        PFItemInstanceWrapper{}
    {
        swap(*this, src);
    }

    PFItemInstanceWrapper& operator=(PFItemInstanceWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFItemInstanceWrapper() = default;

    friend void swap(PFItemInstanceWrapper& lhs, PFItemInstanceWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_annotation, rhs.m_annotation);
        swap(lhs.m_bundleContents, rhs.m_bundleContents);
        swap(lhs.m_bundleParent, rhs.m_bundleParent);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customData, rhs.m_customData);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_expiration, rhs.m_expiration);
        swap(lhs.m_itemClass, rhs.m_itemClass);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        swap(lhs.m_purchaseDate, rhs.m_purchaseDate);
        swap(lhs.m_remainingUses, rhs.m_remainingUses);
        swap(lhs.m_unitCurrency, rhs.m_unitCurrency);
        swap(lhs.m_usesIncrementedBy, rhs.m_usesIncrementedBy);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAnnotation(String value)
    {
        m_annotation = std::move(value);
        this->m_model.annotation =  m_annotation.empty() ? nullptr : m_annotation.data();
    }

    void SetBundleContents(CStringVector<Alloc> value)
    {
        m_bundleContents = std::move(value);
        this->m_model.bundleContents =  m_bundleContents.empty() ? nullptr : m_bundleContents.data();
        this->m_model.bundleContentsCount =  static_cast<uint32_t>(m_bundleContents.size());
    }

    void SetBundleParent(String value)
    {
        m_bundleParent = std::move(value);
        this->m_model.bundleParent =  m_bundleParent.empty() ? nullptr : m_bundleParent.data();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCustomData(StringDictionaryEntryVector<Alloc> value)
    {
        m_customData = std::move(value);
        this->m_model.customData =  m_customData.empty() ? nullptr : m_customData.data();
        this->m_model.customDataCount =  static_cast<uint32_t>(m_customData.size());
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

    void SetExpiration(StdExtra::optional<time_t> value)
    {
        m_expiration = std::move(value);
        this->m_model.expiration = m_expiration ? m_expiration.operator->() : nullptr;
    }

    void SetItemClass(String value)
    {
        m_itemClass = std::move(value);
        this->m_model.itemClass =  m_itemClass.empty() ? nullptr : m_itemClass.data();
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetPurchaseDate(StdExtra::optional<time_t> value)
    {
        m_purchaseDate = std::move(value);
        this->m_model.purchaseDate = m_purchaseDate ? m_purchaseDate.operator->() : nullptr;
    }

    void SetRemainingUses(StdExtra::optional<int32_t> value)
    {
        m_remainingUses = std::move(value);
        this->m_model.remainingUses = m_remainingUses ? m_remainingUses.operator->() : nullptr;
    }

    void SetUnitCurrency(String value)
    {
        m_unitCurrency = std::move(value);
        this->m_model.unitCurrency =  m_unitCurrency.empty() ? nullptr : m_unitCurrency.data();
    }

    void SetUnitPrice(uint32_t value)
    {
        this->m_model.unitPrice = value;
    }

    void SetUsesIncrementedBy(StdExtra::optional<int32_t> value)
    {
        m_usesIncrementedBy = std::move(value);
        this->m_model.usesIncrementedBy = m_usesIncrementedBy ? m_usesIncrementedBy.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.annotation = m_annotation.empty() ? nullptr : m_annotation.data();
        this->m_model.bundleContents = m_bundleContents.empty() ? nullptr : m_bundleContents.data();
        this->m_model.bundleParent = m_bundleParent.empty() ? nullptr : m_bundleParent.data();
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customData = m_customData.empty() ? nullptr : m_customData.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.expiration = m_expiration ? m_expiration.operator->() : nullptr;
        this->m_model.itemClass = m_itemClass.empty() ? nullptr : m_itemClass.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
        this->m_model.purchaseDate = m_purchaseDate ? m_purchaseDate.operator->() : nullptr;
        this->m_model.remainingUses = m_remainingUses ? m_remainingUses.operator->() : nullptr;
        this->m_model.unitCurrency = m_unitCurrency.empty() ? nullptr : m_unitCurrency.data();
        this->m_model.usesIncrementedBy = m_usesIncrementedBy ? m_usesIncrementedBy.operator->() : nullptr;
    }

    String m_annotation;
    CStringVector<Alloc> m_bundleContents;
    String m_bundleParent;
    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customData;
    String m_displayName;
    StdExtra::optional<time_t> m_expiration;
    String m_itemClass;
    String m_itemId;
    String m_itemInstanceId;
    StdExtra::optional<time_t> m_purchaseDate;
    StdExtra::optional<int32_t> m_remainingUses;
    String m_unitCurrency;
    StdExtra::optional<int32_t> m_usesIncrementedBy;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScriptExecutionErrorWrapper : public ModelWrapper<PFScriptExecutionError, Alloc>
{
public:
    using ModelType = typename PFScriptExecutionError;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScriptExecutionErrorWrapper() = default;

    PFScriptExecutionErrorWrapper(const PFScriptExecutionError& model) :
        ModelWrapper<PFScriptExecutionError, Alloc>{ model },
        m_error{ SafeString(model.error) },
        m_message{ SafeString(model.message) },
        m_stackTrace{ SafeString(model.stackTrace) }
    {
        SetModelPointers();
    }

    PFScriptExecutionErrorWrapper(const PFScriptExecutionErrorWrapper& src) :
        PFScriptExecutionErrorWrapper{ src.Model() }
    {
    }

    PFScriptExecutionErrorWrapper(PFScriptExecutionErrorWrapper&& src) :
        PFScriptExecutionErrorWrapper{}
    {
        swap(*this, src);
    }

    PFScriptExecutionErrorWrapper& operator=(PFScriptExecutionErrorWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScriptExecutionErrorWrapper() = default;

    friend void swap(PFScriptExecutionErrorWrapper& lhs, PFScriptExecutionErrorWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_error, rhs.m_error);
        swap(lhs.m_message, rhs.m_message);
        swap(lhs.m_stackTrace, rhs.m_stackTrace);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetError(String value)
    {
        m_error = std::move(value);
        this->m_model.error =  m_error.empty() ? nullptr : m_error.data();
    }

    void SetMessage(String value)
    {
        m_message = std::move(value);
        this->m_model.message =  m_message.empty() ? nullptr : m_message.data();
    }

    void SetStackTrace(String value)
    {
        m_stackTrace = std::move(value);
        this->m_model.stackTrace =  m_stackTrace.empty() ? nullptr : m_stackTrace.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.error = m_error.empty() ? nullptr : m_error.data();
        this->m_model.message = m_message.empty() ? nullptr : m_message.data();
        this->m_model.stackTrace = m_stackTrace.empty() ? nullptr : m_stackTrace.data();
    }

    String m_error;
    String m_message;
    String m_stackTrace;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLogStatementWrapper : public ModelWrapper<PFLogStatement, Alloc>
{
public:
    using ModelType = typename PFLogStatement;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLogStatementWrapper() = default;

    PFLogStatementWrapper(const PFLogStatement& model) :
        ModelWrapper<PFLogStatement, Alloc>{ model },
        m_data{ model.data },
        m_level{ SafeString(model.level) },
        m_message{ SafeString(model.message) }
    {
        SetModelPointers();
    }

    PFLogStatementWrapper(const PFLogStatementWrapper& src) :
        PFLogStatementWrapper{ src.Model() }
    {
    }

    PFLogStatementWrapper(PFLogStatementWrapper&& src) :
        PFLogStatementWrapper{}
    {
        swap(*this, src);
    }

    PFLogStatementWrapper& operator=(PFLogStatementWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLogStatementWrapper() = default;

    friend void swap(PFLogStatementWrapper& lhs, PFLogStatementWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_level, rhs.m_level);
        swap(lhs.m_message, rhs.m_message);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(JsonObject<Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data.stringValue = m_data.stringValue.empty() ? nullptr : m_data.stringValue.data();
    }

    void SetLevel(String value)
    {
        m_level = std::move(value);
        this->m_model.level =  m_level.empty() ? nullptr : m_level.data();
    }

    void SetMessage(String value)
    {
        m_message = std::move(value);
        this->m_model.message =  m_message.empty() ? nullptr : m_message.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.data.stringValue = m_data.stringValue.empty() ? nullptr : m_data.stringValue.data();
        this->m_model.level = m_level.empty() ? nullptr : m_level.data();
        this->m_model.message = m_message.empty() ? nullptr : m_message.data();
    }

    JsonObject<Alloc> m_data;
    String m_level;
    String m_message;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExecuteCloudScriptResultWrapper : public ModelWrapper<PFExecuteCloudScriptResult, Alloc>
{
public:
    using ModelType = typename PFExecuteCloudScriptResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExecuteCloudScriptResultWrapper() = default;

    PFExecuteCloudScriptResultWrapper(const PFExecuteCloudScriptResult& model) :
        ModelWrapper<PFExecuteCloudScriptResult, Alloc>{ model },
        m_error{ model.error ? StdExtra::optional<PFScriptExecutionErrorWrapper<Alloc>>{ *model.error } : StdExtra::nullopt },
        m_functionName{ SafeString(model.functionName) },
        m_functionResult{ model.functionResult },
        m_functionResultTooLarge{ model.functionResultTooLarge ? StdExtra::optional<bool>{ *model.functionResultTooLarge } : StdExtra::nullopt },
        m_logs{ model.logs, model.logs + model.logsCount },
        m_logsTooLarge{ model.logsTooLarge ? StdExtra::optional<bool>{ *model.logsTooLarge } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFExecuteCloudScriptResultWrapper(const PFExecuteCloudScriptResultWrapper& src) :
        PFExecuteCloudScriptResultWrapper{ src.Model() }
    {
    }

    PFExecuteCloudScriptResultWrapper(PFExecuteCloudScriptResultWrapper&& src) :
        PFExecuteCloudScriptResultWrapper{}
    {
        swap(*this, src);
    }

    PFExecuteCloudScriptResultWrapper& operator=(PFExecuteCloudScriptResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExecuteCloudScriptResultWrapper() = default;

    friend void swap(PFExecuteCloudScriptResultWrapper& lhs, PFExecuteCloudScriptResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_error, rhs.m_error);
        swap(lhs.m_functionName, rhs.m_functionName);
        swap(lhs.m_functionResult, rhs.m_functionResult);
        swap(lhs.m_functionResultTooLarge, rhs.m_functionResultTooLarge);
        swap(lhs.m_logs, rhs.m_logs);
        swap(lhs.m_logsTooLarge, rhs.m_logsTooLarge);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAPIRequestsIssued(int32_t value)
    {
        this->m_model.aPIRequestsIssued = value;
    }

    void SetError(StdExtra::optional<PFScriptExecutionErrorWrapper<Alloc>> value)
    {
        m_error = std::move(value);
        this->m_model.error = m_error ? &m_error->Model() : nullptr;
    }

    void SetExecutionTimeSeconds(double value)
    {
        this->m_model.executionTimeSeconds = value;
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

    void SetFunctionResult(JsonObject<Alloc> value)
    {
        m_functionResult = std::move(value);
        this->m_model.functionResult.stringValue = m_functionResult.stringValue.empty() ? nullptr : m_functionResult.stringValue.data();
    }

    void SetFunctionResultTooLarge(StdExtra::optional<bool> value)
    {
        m_functionResultTooLarge = std::move(value);
        this->m_model.functionResultTooLarge = m_functionResultTooLarge ? m_functionResultTooLarge.operator->() : nullptr;
    }

    void SetHttpRequestsIssued(int32_t value)
    {
        this->m_model.httpRequestsIssued = value;
    }

    void SetLogs(ModelVector<PFLogStatementWrapper<Alloc>, Alloc> value)
    {
        m_logs = std::move(value);
        this->m_model.logs =  m_logs.empty() ? nullptr : m_logs.data();
        this->m_model.logsCount =  static_cast<uint32_t>(m_logs.size());
    }

    void SetLogsTooLarge(StdExtra::optional<bool> value)
    {
        m_logsTooLarge = std::move(value);
        this->m_model.logsTooLarge = m_logsTooLarge ? m_logsTooLarge.operator->() : nullptr;
    }

    void SetMemoryConsumedBytes(uint32_t value)
    {
        this->m_model.memoryConsumedBytes = value;
    }

    void SetProcessorTimeSeconds(double value)
    {
        this->m_model.processorTimeSeconds = value;
    }

    void SetRevision(int32_t value)
    {
        this->m_model.revision = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.error = m_error ?  &m_error->Model() : nullptr;
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
        this->m_model.functionResult.stringValue = m_functionResult.stringValue.empty() ? nullptr : m_functionResult.stringValue.data();
        this->m_model.functionResultTooLarge = m_functionResultTooLarge ? m_functionResultTooLarge.operator->() : nullptr;
        this->m_model.logs = m_logs.empty() ? nullptr : m_logs.data();
        this->m_model.logsTooLarge = m_logsTooLarge ? m_logsTooLarge.operator->() : nullptr;
    }

    StdExtra::optional<PFScriptExecutionErrorWrapper<Alloc>> m_error;
    String m_functionName;
    JsonObject<Alloc> m_functionResult;
    StdExtra::optional<bool> m_functionResultTooLarge;
    ModelVector<PFLogStatementWrapper<Alloc>, Alloc> m_logs;
    StdExtra::optional<bool> m_logsTooLarge;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFNameIdentifierWrapper : public ModelWrapper<PFNameIdentifier, Alloc>
{
public:
    using ModelType = typename PFNameIdentifier;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFNameIdentifierWrapper() = default;

    PFNameIdentifierWrapper(const PFNameIdentifier& model) :
        ModelWrapper<PFNameIdentifier, Alloc>{ model },
        m_id{ SafeString(model.id) },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFNameIdentifierWrapper(const PFNameIdentifierWrapper& src) :
        PFNameIdentifierWrapper{ src.Model() }
    {
    }

    PFNameIdentifierWrapper(PFNameIdentifierWrapper&& src) :
        PFNameIdentifierWrapper{}
    {
        swap(*this, src);
    }

    PFNameIdentifierWrapper& operator=(PFNameIdentifierWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFNameIdentifierWrapper() = default;

    friend void swap(PFNameIdentifierWrapper& lhs, PFNameIdentifierWrapper& rhs)
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
class PFUserDataRecordWrapper : public ModelWrapper<PFUserDataRecord, Alloc>
{
public:
    using ModelType = typename PFUserDataRecord;
    using DictionaryEntryType = typename PFUserDataRecordDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserDataRecordWrapper() = default;

    PFUserDataRecordWrapper(const PFUserDataRecord& model) :
        ModelWrapper<PFUserDataRecord, Alloc>{ model },
        m_permission{ model.permission ? StdExtra::optional<PFUserDataPermission>{ *model.permission } : StdExtra::nullopt },
        m_value{ SafeString(model.value) }
    {
        SetModelPointers();
    }

    PFUserDataRecordWrapper(const PFUserDataRecordWrapper& src) :
        PFUserDataRecordWrapper{ src.Model() }
    {
    }

    PFUserDataRecordWrapper(PFUserDataRecordWrapper&& src) :
        PFUserDataRecordWrapper{}
    {
        swap(*this, src);
    }

    PFUserDataRecordWrapper& operator=(PFUserDataRecordWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserDataRecordWrapper() = default;

    friend void swap(PFUserDataRecordWrapper& lhs, PFUserDataRecordWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_permission, rhs.m_permission);
        swap(lhs.m_value, rhs.m_value);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLastUpdated(time_t value)
    {
        this->m_model.lastUpdated = value;
    }

    void SetPermission(StdExtra::optional<PFUserDataPermission> value)
    {
        m_permission = std::move(value);
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
    }

    void SetValue(String value)
    {
        m_value = std::move(value);
        this->m_model.value =  m_value.empty() ? nullptr : m_value.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
        this->m_model.value = m_value.empty() ? nullptr : m_value.data();
    }

    StdExtra::optional<PFUserDataPermission> m_permission;
    String m_value;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerProfileViewConstraintsWrapper : public ModelWrapper<PFPlayerProfileViewConstraints, Alloc>
{
public:
    using ModelType = typename PFPlayerProfileViewConstraints;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFPlayerProfileViewConstraints, Alloc>::ModelWrapper;

    void SetShowAvatarUrl(bool value)
    {
        this->m_model.showAvatarUrl = value;
    }

    void SetShowBannedUntil(bool value)
    {
        this->m_model.showBannedUntil = value;
    }

    void SetShowCampaignAttributions(bool value)
    {
        this->m_model.showCampaignAttributions = value;
    }

    void SetShowContactEmailAddresses(bool value)
    {
        this->m_model.showContactEmailAddresses = value;
    }

    void SetShowCreated(bool value)
    {
        this->m_model.showCreated = value;
    }

    void SetShowDisplayName(bool value)
    {
        this->m_model.showDisplayName = value;
    }

    void SetShowExperimentVariants(bool value)
    {
        this->m_model.showExperimentVariants = value;
    }

    void SetShowLastLogin(bool value)
    {
        this->m_model.showLastLogin = value;
    }

    void SetShowLinkedAccounts(bool value)
    {
        this->m_model.showLinkedAccounts = value;
    }

    void SetShowLocations(bool value)
    {
        this->m_model.showLocations = value;
    }

    void SetShowMemberships(bool value)
    {
        this->m_model.showMemberships = value;
    }

    void SetShowOrigination(bool value)
    {
        this->m_model.showOrigination = value;
    }

    void SetShowPushNotificationRegistrations(bool value)
    {
        this->m_model.showPushNotificationRegistrations = value;
    }

    void SetShowStatistics(bool value)
    {
        this->m_model.showStatistics = value;
    }

    void SetShowTags(bool value)
    {
        this->m_model.showTags = value;
    }

    void SetShowTotalValueToDateInUsd(bool value)
    {
        this->m_model.showTotalValueToDateInUsd = value;
    }

    void SetShowValuesToDate(bool value)
    {
        this->m_model.showValuesToDate = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAdCampaignAttributionModelWrapper : public ModelWrapper<PFAdCampaignAttributionModel, Alloc>
{
public:
    using ModelType = typename PFAdCampaignAttributionModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAdCampaignAttributionModelWrapper() = default;

    PFAdCampaignAttributionModelWrapper(const PFAdCampaignAttributionModel& model) :
        ModelWrapper<PFAdCampaignAttributionModel, Alloc>{ model },
        m_campaignId{ SafeString(model.campaignId) },
        m_platform{ SafeString(model.platform) }
    {
        SetModelPointers();
    }

    PFAdCampaignAttributionModelWrapper(const PFAdCampaignAttributionModelWrapper& src) :
        PFAdCampaignAttributionModelWrapper{ src.Model() }
    {
    }

    PFAdCampaignAttributionModelWrapper(PFAdCampaignAttributionModelWrapper&& src) :
        PFAdCampaignAttributionModelWrapper{}
    {
        swap(*this, src);
    }

    PFAdCampaignAttributionModelWrapper& operator=(PFAdCampaignAttributionModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAdCampaignAttributionModelWrapper() = default;

    friend void swap(PFAdCampaignAttributionModelWrapper& lhs, PFAdCampaignAttributionModelWrapper& rhs)
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
class PFContactEmailInfoModelWrapper : public ModelWrapper<PFContactEmailInfoModel, Alloc>
{
public:
    using ModelType = typename PFContactEmailInfoModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFContactEmailInfoModelWrapper() = default;

    PFContactEmailInfoModelWrapper(const PFContactEmailInfoModel& model) :
        ModelWrapper<PFContactEmailInfoModel, Alloc>{ model },
        m_emailAddress{ SafeString(model.emailAddress) },
        m_name{ SafeString(model.name) },
        m_verificationStatus{ model.verificationStatus ? StdExtra::optional<PFEmailVerificationStatus>{ *model.verificationStatus } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFContactEmailInfoModelWrapper(const PFContactEmailInfoModelWrapper& src) :
        PFContactEmailInfoModelWrapper{ src.Model() }
    {
    }

    PFContactEmailInfoModelWrapper(PFContactEmailInfoModelWrapper&& src) :
        PFContactEmailInfoModelWrapper{}
    {
        swap(*this, src);
    }

    PFContactEmailInfoModelWrapper& operator=(PFContactEmailInfoModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFContactEmailInfoModelWrapper() = default;

    friend void swap(PFContactEmailInfoModelWrapper& lhs, PFContactEmailInfoModelWrapper& rhs)
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
class PFLinkedPlatformAccountModelWrapper : public ModelWrapper<PFLinkedPlatformAccountModel, Alloc>
{
public:
    using ModelType = typename PFLinkedPlatformAccountModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLinkedPlatformAccountModelWrapper() = default;

    PFLinkedPlatformAccountModelWrapper(const PFLinkedPlatformAccountModel& model) :
        ModelWrapper<PFLinkedPlatformAccountModel, Alloc>{ model },
        m_email{ SafeString(model.email) },
        m_platform{ model.platform ? StdExtra::optional<PFLoginIdentityProvider>{ *model.platform } : StdExtra::nullopt },
        m_platformUserId{ SafeString(model.platformUserId) },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFLinkedPlatformAccountModelWrapper(const PFLinkedPlatformAccountModelWrapper& src) :
        PFLinkedPlatformAccountModelWrapper{ src.Model() }
    {
    }

    PFLinkedPlatformAccountModelWrapper(PFLinkedPlatformAccountModelWrapper&& src) :
        PFLinkedPlatformAccountModelWrapper{}
    {
        swap(*this, src);
    }

    PFLinkedPlatformAccountModelWrapper& operator=(PFLinkedPlatformAccountModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLinkedPlatformAccountModelWrapper() = default;

    friend void swap(PFLinkedPlatformAccountModelWrapper& lhs, PFLinkedPlatformAccountModelWrapper& rhs)
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
class PFLocationModelWrapper : public ModelWrapper<PFLocationModel, Alloc>
{
public:
    using ModelType = typename PFLocationModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLocationModelWrapper() = default;

    PFLocationModelWrapper(const PFLocationModel& model) :
        ModelWrapper<PFLocationModel, Alloc>{ model },
        m_city{ SafeString(model.city) },
        m_continentCode{ model.continentCode ? StdExtra::optional<PFContinentCode>{ *model.continentCode } : StdExtra::nullopt },
        m_countryCode{ model.countryCode ? StdExtra::optional<PFCountryCode>{ *model.countryCode } : StdExtra::nullopt },
        m_latitude{ model.latitude ? StdExtra::optional<double>{ *model.latitude } : StdExtra::nullopt },
        m_longitude{ model.longitude ? StdExtra::optional<double>{ *model.longitude } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLocationModelWrapper(const PFLocationModelWrapper& src) :
        PFLocationModelWrapper{ src.Model() }
    {
    }

    PFLocationModelWrapper(PFLocationModelWrapper&& src) :
        PFLocationModelWrapper{}
    {
        swap(*this, src);
    }

    PFLocationModelWrapper& operator=(PFLocationModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLocationModelWrapper() = default;

    friend void swap(PFLocationModelWrapper& lhs, PFLocationModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_city, rhs.m_city);
        swap(lhs.m_continentCode, rhs.m_continentCode);
        swap(lhs.m_countryCode, rhs.m_countryCode);
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

    void SetContinentCode(StdExtra::optional<PFContinentCode> value)
    {
        m_continentCode = std::move(value);
        this->m_model.continentCode = m_continentCode ? m_continentCode.operator->() : nullptr;
    }

    void SetCountryCode(StdExtra::optional<PFCountryCode> value)
    {
        m_countryCode = std::move(value);
        this->m_model.countryCode = m_countryCode ? m_countryCode.operator->() : nullptr;
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
        this->m_model.continentCode = m_continentCode ? m_continentCode.operator->() : nullptr;
        this->m_model.countryCode = m_countryCode ? m_countryCode.operator->() : nullptr;
        this->m_model.latitude = m_latitude ? m_latitude.operator->() : nullptr;
        this->m_model.longitude = m_longitude ? m_longitude.operator->() : nullptr;
    }

    String m_city;
    StdExtra::optional<PFContinentCode> m_continentCode;
    StdExtra::optional<PFCountryCode> m_countryCode;
    StdExtra::optional<double> m_latitude;
    StdExtra::optional<double> m_longitude;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSubscriptionModelWrapper : public ModelWrapper<PFSubscriptionModel, Alloc>
{
public:
    using ModelType = typename PFSubscriptionModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSubscriptionModelWrapper() = default;

    PFSubscriptionModelWrapper(const PFSubscriptionModel& model) :
        ModelWrapper<PFSubscriptionModel, Alloc>{ model },
        m_status{ model.status ? StdExtra::optional<PFSubscriptionProviderStatus>{ *model.status } : StdExtra::nullopt },
        m_subscriptionId{ SafeString(model.subscriptionId) },
        m_subscriptionItemId{ SafeString(model.subscriptionItemId) },
        m_subscriptionProvider{ SafeString(model.subscriptionProvider) }
    {
        SetModelPointers();
    }

    PFSubscriptionModelWrapper(const PFSubscriptionModelWrapper& src) :
        PFSubscriptionModelWrapper{ src.Model() }
    {
    }

    PFSubscriptionModelWrapper(PFSubscriptionModelWrapper&& src) :
        PFSubscriptionModelWrapper{}
    {
        swap(*this, src);
    }

    PFSubscriptionModelWrapper& operator=(PFSubscriptionModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSubscriptionModelWrapper() = default;

    friend void swap(PFSubscriptionModelWrapper& lhs, PFSubscriptionModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_subscriptionId, rhs.m_subscriptionId);
        swap(lhs.m_subscriptionItemId, rhs.m_subscriptionItemId);
        swap(lhs.m_subscriptionProvider, rhs.m_subscriptionProvider);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetExpiration(time_t value)
    {
        this->m_model.expiration = value;
    }

    void SetInitialSubscriptionTime(time_t value)
    {
        this->m_model.initialSubscriptionTime = value;
    }

    void SetIsActive(bool value)
    {
        this->m_model.isActive = value;
    }

    void SetStatus(StdExtra::optional<PFSubscriptionProviderStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    void SetSubscriptionId(String value)
    {
        m_subscriptionId = std::move(value);
        this->m_model.subscriptionId =  m_subscriptionId.empty() ? nullptr : m_subscriptionId.data();
    }

    void SetSubscriptionItemId(String value)
    {
        m_subscriptionItemId = std::move(value);
        this->m_model.subscriptionItemId =  m_subscriptionItemId.empty() ? nullptr : m_subscriptionItemId.data();
    }

    void SetSubscriptionProvider(String value)
    {
        m_subscriptionProvider = std::move(value);
        this->m_model.subscriptionProvider =  m_subscriptionProvider.empty() ? nullptr : m_subscriptionProvider.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
        this->m_model.subscriptionId = m_subscriptionId.empty() ? nullptr : m_subscriptionId.data();
        this->m_model.subscriptionItemId = m_subscriptionItemId.empty() ? nullptr : m_subscriptionItemId.data();
        this->m_model.subscriptionProvider = m_subscriptionProvider.empty() ? nullptr : m_subscriptionProvider.data();
    }

    StdExtra::optional<PFSubscriptionProviderStatus> m_status;
    String m_subscriptionId;
    String m_subscriptionItemId;
    String m_subscriptionProvider;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMembershipModelWrapper : public ModelWrapper<PFMembershipModel, Alloc>
{
public:
    using ModelType = typename PFMembershipModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMembershipModelWrapper() = default;

    PFMembershipModelWrapper(const PFMembershipModel& model) :
        ModelWrapper<PFMembershipModel, Alloc>{ model },
        m_membershipId{ SafeString(model.membershipId) },
        m_overrideExpiration{ model.overrideExpiration ? StdExtra::optional<time_t>{ *model.overrideExpiration } : StdExtra::nullopt },
        m_subscriptions{ model.subscriptions, model.subscriptions + model.subscriptionsCount }
    {
        SetModelPointers();
    }

    PFMembershipModelWrapper(const PFMembershipModelWrapper& src) :
        PFMembershipModelWrapper{ src.Model() }
    {
    }

    PFMembershipModelWrapper(PFMembershipModelWrapper&& src) :
        PFMembershipModelWrapper{}
    {
        swap(*this, src);
    }

    PFMembershipModelWrapper& operator=(PFMembershipModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMembershipModelWrapper() = default;

    friend void swap(PFMembershipModelWrapper& lhs, PFMembershipModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_membershipId, rhs.m_membershipId);
        swap(lhs.m_overrideExpiration, rhs.m_overrideExpiration);
        swap(lhs.m_subscriptions, rhs.m_subscriptions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIsActive(bool value)
    {
        this->m_model.isActive = value;
    }

    void SetMembershipExpiration(time_t value)
    {
        this->m_model.membershipExpiration = value;
    }

    void SetMembershipId(String value)
    {
        m_membershipId = std::move(value);
        this->m_model.membershipId =  m_membershipId.empty() ? nullptr : m_membershipId.data();
    }

    void SetOverrideExpiration(StdExtra::optional<time_t> value)
    {
        m_overrideExpiration = std::move(value);
        this->m_model.overrideExpiration = m_overrideExpiration ? m_overrideExpiration.operator->() : nullptr;
    }

    void SetSubscriptions(ModelVector<PFSubscriptionModelWrapper<Alloc>, Alloc> value)
    {
        m_subscriptions = std::move(value);
        this->m_model.subscriptions =  m_subscriptions.empty() ? nullptr : m_subscriptions.data();
        this->m_model.subscriptionsCount =  static_cast<uint32_t>(m_subscriptions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.membershipId = m_membershipId.empty() ? nullptr : m_membershipId.data();
        this->m_model.overrideExpiration = m_overrideExpiration ? m_overrideExpiration.operator->() : nullptr;
        this->m_model.subscriptions = m_subscriptions.empty() ? nullptr : m_subscriptions.data();
    }

    String m_membershipId;
    StdExtra::optional<time_t> m_overrideExpiration;
    ModelVector<PFSubscriptionModelWrapper<Alloc>, Alloc> m_subscriptions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPushNotificationRegistrationModelWrapper : public ModelWrapper<PFPushNotificationRegistrationModel, Alloc>
{
public:
    using ModelType = typename PFPushNotificationRegistrationModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPushNotificationRegistrationModelWrapper() = default;

    PFPushNotificationRegistrationModelWrapper(const PFPushNotificationRegistrationModel& model) :
        ModelWrapper<PFPushNotificationRegistrationModel, Alloc>{ model },
        m_notificationEndpointARN{ SafeString(model.notificationEndpointARN) },
        m_platform{ model.platform ? StdExtra::optional<PFPushNotificationPlatform>{ *model.platform } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPushNotificationRegistrationModelWrapper(const PFPushNotificationRegistrationModelWrapper& src) :
        PFPushNotificationRegistrationModelWrapper{ src.Model() }
    {
    }

    PFPushNotificationRegistrationModelWrapper(PFPushNotificationRegistrationModelWrapper&& src) :
        PFPushNotificationRegistrationModelWrapper{}
    {
        swap(*this, src);
    }

    PFPushNotificationRegistrationModelWrapper& operator=(PFPushNotificationRegistrationModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPushNotificationRegistrationModelWrapper() = default;

    friend void swap(PFPushNotificationRegistrationModelWrapper& lhs, PFPushNotificationRegistrationModelWrapper& rhs)
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
class PFStatisticModelWrapper : public ModelWrapper<PFStatisticModel, Alloc>
{
public:
    using ModelType = typename PFStatisticModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFStatisticModelWrapper() = default;

    PFStatisticModelWrapper(const PFStatisticModel& model) :
        ModelWrapper<PFStatisticModel, Alloc>{ model },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFStatisticModelWrapper(const PFStatisticModelWrapper& src) :
        PFStatisticModelWrapper{ src.Model() }
    {
    }

    PFStatisticModelWrapper(PFStatisticModelWrapper&& src) :
        PFStatisticModelWrapper{}
    {
        swap(*this, src);
    }

    PFStatisticModelWrapper& operator=(PFStatisticModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFStatisticModelWrapper() = default;

    friend void swap(PFStatisticModelWrapper& lhs, PFStatisticModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetValue(int32_t value)
    {
        this->m_model.value = value;
    }

    void SetVersion(int32_t value)
    {
        this->m_model.version = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTagModelWrapper : public ModelWrapper<PFTagModel, Alloc>
{
public:
    using ModelType = typename PFTagModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTagModelWrapper() = default;

    PFTagModelWrapper(const PFTagModel& model) :
        ModelWrapper<PFTagModel, Alloc>{ model },
        m_tagValue{ SafeString(model.tagValue) }
    {
        SetModelPointers();
    }

    PFTagModelWrapper(const PFTagModelWrapper& src) :
        PFTagModelWrapper{ src.Model() }
    {
    }

    PFTagModelWrapper(PFTagModelWrapper&& src) :
        PFTagModelWrapper{}
    {
        swap(*this, src);
    }

    PFTagModelWrapper& operator=(PFTagModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTagModelWrapper() = default;

    friend void swap(PFTagModelWrapper& lhs, PFTagModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_tagValue, rhs.m_tagValue);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTagValue(String value)
    {
        m_tagValue = std::move(value);
        this->m_model.tagValue =  m_tagValue.empty() ? nullptr : m_tagValue.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.tagValue = m_tagValue.empty() ? nullptr : m_tagValue.data();
    }

    String m_tagValue;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFValueToDateModelWrapper : public ModelWrapper<PFValueToDateModel, Alloc>
{
public:
    using ModelType = typename PFValueToDateModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFValueToDateModelWrapper() = default;

    PFValueToDateModelWrapper(const PFValueToDateModel& model) :
        ModelWrapper<PFValueToDateModel, Alloc>{ model },
        m_currency{ SafeString(model.currency) },
        m_totalValueAsDecimal{ SafeString(model.totalValueAsDecimal) }
    {
        SetModelPointers();
    }

    PFValueToDateModelWrapper(const PFValueToDateModelWrapper& src) :
        PFValueToDateModelWrapper{ src.Model() }
    {
    }

    PFValueToDateModelWrapper(PFValueToDateModelWrapper&& src) :
        PFValueToDateModelWrapper{}
    {
        swap(*this, src);
    }

    PFValueToDateModelWrapper& operator=(PFValueToDateModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFValueToDateModelWrapper() = default;

    friend void swap(PFValueToDateModelWrapper& lhs, PFValueToDateModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_currency, rhs.m_currency);
        swap(lhs.m_totalValueAsDecimal, rhs.m_totalValueAsDecimal);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCurrency(String value)
    {
        m_currency = std::move(value);
        this->m_model.currency =  m_currency.empty() ? nullptr : m_currency.data();
    }

    void SetTotalValue(uint32_t value)
    {
        this->m_model.totalValue = value;
    }

    void SetTotalValueAsDecimal(String value)
    {
        m_totalValueAsDecimal = std::move(value);
        this->m_model.totalValueAsDecimal =  m_totalValueAsDecimal.empty() ? nullptr : m_totalValueAsDecimal.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.currency = m_currency.empty() ? nullptr : m_currency.data();
        this->m_model.totalValueAsDecimal = m_totalValueAsDecimal.empty() ? nullptr : m_totalValueAsDecimal.data();
    }

    String m_currency;
    String m_totalValueAsDecimal;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerProfileModelWrapper : public ModelWrapper<PFPlayerProfileModel, Alloc>
{
public:
    using ModelType = typename PFPlayerProfileModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerProfileModelWrapper() = default;

    PFPlayerProfileModelWrapper(const PFPlayerProfileModel& model) :
        ModelWrapper<PFPlayerProfileModel, Alloc>{ model },
        m_adCampaignAttributions{ model.adCampaignAttributions, model.adCampaignAttributions + model.adCampaignAttributionsCount },
        m_avatarUrl{ SafeString(model.avatarUrl) },
        m_bannedUntil{ model.bannedUntil ? StdExtra::optional<time_t>{ *model.bannedUntil } : StdExtra::nullopt },
        m_contactEmailAddresses{ model.contactEmailAddresses, model.contactEmailAddresses + model.contactEmailAddressesCount },
        m_created{ model.created ? StdExtra::optional<time_t>{ *model.created } : StdExtra::nullopt },
        m_displayName{ SafeString(model.displayName) },
        m_experimentVariants{ model.experimentVariants, model.experimentVariants + model.experimentVariantsCount },
        m_lastLogin{ model.lastLogin ? StdExtra::optional<time_t>{ *model.lastLogin } : StdExtra::nullopt },
        m_linkedAccounts{ model.linkedAccounts, model.linkedAccounts + model.linkedAccountsCount },
        m_locations{ model.locations, model.locations + model.locationsCount },
        m_memberships{ model.memberships, model.memberships + model.membershipsCount },
        m_origination{ model.origination ? StdExtra::optional<PFLoginIdentityProvider>{ *model.origination } : StdExtra::nullopt },
        m_playerId{ SafeString(model.playerId) },
        m_publisherId{ SafeString(model.publisherId) },
        m_pushNotificationRegistrations{ model.pushNotificationRegistrations, model.pushNotificationRegistrations + model.pushNotificationRegistrationsCount },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount },
        m_tags{ model.tags, model.tags + model.tagsCount },
        m_titleId{ SafeString(model.titleId) },
        m_totalValueToDateInUSD{ model.totalValueToDateInUSD ? StdExtra::optional<uint32_t>{ *model.totalValueToDateInUSD } : StdExtra::nullopt },
        m_valuesToDate{ model.valuesToDate, model.valuesToDate + model.valuesToDateCount }
    {
        SetModelPointers();
    }

    PFPlayerProfileModelWrapper(const PFPlayerProfileModelWrapper& src) :
        PFPlayerProfileModelWrapper{ src.Model() }
    {
    }

    PFPlayerProfileModelWrapper(PFPlayerProfileModelWrapper&& src) :
        PFPlayerProfileModelWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerProfileModelWrapper& operator=(PFPlayerProfileModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerProfileModelWrapper() = default;

    friend void swap(PFPlayerProfileModelWrapper& lhs, PFPlayerProfileModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_adCampaignAttributions, rhs.m_adCampaignAttributions);
        swap(lhs.m_avatarUrl, rhs.m_avatarUrl);
        swap(lhs.m_bannedUntil, rhs.m_bannedUntil);
        swap(lhs.m_contactEmailAddresses, rhs.m_contactEmailAddresses);
        swap(lhs.m_created, rhs.m_created);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_experimentVariants, rhs.m_experimentVariants);
        swap(lhs.m_lastLogin, rhs.m_lastLogin);
        swap(lhs.m_linkedAccounts, rhs.m_linkedAccounts);
        swap(lhs.m_locations, rhs.m_locations);
        swap(lhs.m_memberships, rhs.m_memberships);
        swap(lhs.m_origination, rhs.m_origination);
        swap(lhs.m_playerId, rhs.m_playerId);
        swap(lhs.m_publisherId, rhs.m_publisherId);
        swap(lhs.m_pushNotificationRegistrations, rhs.m_pushNotificationRegistrations);
        swap(lhs.m_statistics, rhs.m_statistics);
        swap(lhs.m_tags, rhs.m_tags);
        swap(lhs.m_titleId, rhs.m_titleId);
        swap(lhs.m_totalValueToDateInUSD, rhs.m_totalValueToDateInUSD);
        swap(lhs.m_valuesToDate, rhs.m_valuesToDate);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAdCampaignAttributions(ModelVector<PFAdCampaignAttributionModelWrapper<Alloc>, Alloc> value)
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

    void SetContactEmailAddresses(ModelVector<PFContactEmailInfoModelWrapper<Alloc>, Alloc> value)
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

    void SetExperimentVariants(CStringVector<Alloc> value)
    {
        m_experimentVariants = std::move(value);
        this->m_model.experimentVariants =  m_experimentVariants.empty() ? nullptr : m_experimentVariants.data();
        this->m_model.experimentVariantsCount =  static_cast<uint32_t>(m_experimentVariants.size());
    }

    void SetLastLogin(StdExtra::optional<time_t> value)
    {
        m_lastLogin = std::move(value);
        this->m_model.lastLogin = m_lastLogin ? m_lastLogin.operator->() : nullptr;
    }

    void SetLinkedAccounts(ModelVector<PFLinkedPlatformAccountModelWrapper<Alloc>, Alloc> value)
    {
        m_linkedAccounts = std::move(value);
        this->m_model.linkedAccounts =  m_linkedAccounts.empty() ? nullptr : m_linkedAccounts.data();
        this->m_model.linkedAccountsCount =  static_cast<uint32_t>(m_linkedAccounts.size());
    }

    void SetLocations(ModelVector<PFLocationModelWrapper<Alloc>, Alloc> value)
    {
        m_locations = std::move(value);
        this->m_model.locations =  m_locations.empty() ? nullptr : m_locations.data();
        this->m_model.locationsCount =  static_cast<uint32_t>(m_locations.size());
    }

    void SetMemberships(ModelVector<PFMembershipModelWrapper<Alloc>, Alloc> value)
    {
        m_memberships = std::move(value);
        this->m_model.memberships =  m_memberships.empty() ? nullptr : m_memberships.data();
        this->m_model.membershipsCount =  static_cast<uint32_t>(m_memberships.size());
    }

    void SetOrigination(StdExtra::optional<PFLoginIdentityProvider> value)
    {
        m_origination = std::move(value);
        this->m_model.origination = m_origination ? m_origination.operator->() : nullptr;
    }

    void SetPlayerId(String value)
    {
        m_playerId = std::move(value);
        this->m_model.playerId =  m_playerId.empty() ? nullptr : m_playerId.data();
    }

    void SetPublisherId(String value)
    {
        m_publisherId = std::move(value);
        this->m_model.publisherId =  m_publisherId.empty() ? nullptr : m_publisherId.data();
    }

    void SetPushNotificationRegistrations(ModelVector<PFPushNotificationRegistrationModelWrapper<Alloc>, Alloc> value)
    {
        m_pushNotificationRegistrations = std::move(value);
        this->m_model.pushNotificationRegistrations =  m_pushNotificationRegistrations.empty() ? nullptr : m_pushNotificationRegistrations.data();
        this->m_model.pushNotificationRegistrationsCount =  static_cast<uint32_t>(m_pushNotificationRegistrations.size());
    }

    void SetStatistics(ModelVector<PFStatisticModelWrapper<Alloc>, Alloc> value)
    {
        m_statistics = std::move(value);
        this->m_model.statistics =  m_statistics.empty() ? nullptr : m_statistics.data();
        this->m_model.statisticsCount =  static_cast<uint32_t>(m_statistics.size());
    }

    void SetTags(ModelVector<PFTagModelWrapper<Alloc>, Alloc> value)
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

    void SetValuesToDate(ModelVector<PFValueToDateModelWrapper<Alloc>, Alloc> value)
    {
        m_valuesToDate = std::move(value);
        this->m_model.valuesToDate =  m_valuesToDate.empty() ? nullptr : m_valuesToDate.data();
        this->m_model.valuesToDateCount =  static_cast<uint32_t>(m_valuesToDate.size());
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
        this->m_model.experimentVariants = m_experimentVariants.empty() ? nullptr : m_experimentVariants.data();
        this->m_model.lastLogin = m_lastLogin ? m_lastLogin.operator->() : nullptr;
        this->m_model.linkedAccounts = m_linkedAccounts.empty() ? nullptr : m_linkedAccounts.data();
        this->m_model.locations = m_locations.empty() ? nullptr : m_locations.data();
        this->m_model.memberships = m_memberships.empty() ? nullptr : m_memberships.data();
        this->m_model.origination = m_origination ? m_origination.operator->() : nullptr;
        this->m_model.playerId = m_playerId.empty() ? nullptr : m_playerId.data();
        this->m_model.publisherId = m_publisherId.empty() ? nullptr : m_publisherId.data();
        this->m_model.pushNotificationRegistrations = m_pushNotificationRegistrations.empty() ? nullptr : m_pushNotificationRegistrations.data();
        this->m_model.statistics = m_statistics.empty() ? nullptr : m_statistics.data();
        this->m_model.tags = m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
        this->m_model.totalValueToDateInUSD = m_totalValueToDateInUSD ? m_totalValueToDateInUSD.operator->() : nullptr;
        this->m_model.valuesToDate = m_valuesToDate.empty() ? nullptr : m_valuesToDate.data();
    }

    ModelVector<PFAdCampaignAttributionModelWrapper<Alloc>, Alloc> m_adCampaignAttributions;
    String m_avatarUrl;
    StdExtra::optional<time_t> m_bannedUntil;
    ModelVector<PFContactEmailInfoModelWrapper<Alloc>, Alloc> m_contactEmailAddresses;
    StdExtra::optional<time_t> m_created;
    String m_displayName;
    CStringVector<Alloc> m_experimentVariants;
    StdExtra::optional<time_t> m_lastLogin;
    ModelVector<PFLinkedPlatformAccountModelWrapper<Alloc>, Alloc> m_linkedAccounts;
    ModelVector<PFLocationModelWrapper<Alloc>, Alloc> m_locations;
    ModelVector<PFMembershipModelWrapper<Alloc>, Alloc> m_memberships;
    StdExtra::optional<PFLoginIdentityProvider> m_origination;
    String m_playerId;
    String m_publisherId;
    ModelVector<PFPushNotificationRegistrationModelWrapper<Alloc>, Alloc> m_pushNotificationRegistrations;
    ModelVector<PFStatisticModelWrapper<Alloc>, Alloc> m_statistics;
    ModelVector<PFTagModelWrapper<Alloc>, Alloc> m_tags;
    String m_titleId;
    StdExtra::optional<uint32_t> m_totalValueToDateInUSD;
    ModelVector<PFValueToDateModelWrapper<Alloc>, Alloc> m_valuesToDate;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserFacebookInfoWrapper : public ModelWrapper<PFUserFacebookInfo, Alloc>
{
public:
    using ModelType = typename PFUserFacebookInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserFacebookInfoWrapper() = default;

    PFUserFacebookInfoWrapper(const PFUserFacebookInfo& model) :
        ModelWrapper<PFUserFacebookInfo, Alloc>{ model },
        m_facebookId{ SafeString(model.facebookId) },
        m_fullName{ SafeString(model.fullName) }
    {
        SetModelPointers();
    }

    PFUserFacebookInfoWrapper(const PFUserFacebookInfoWrapper& src) :
        PFUserFacebookInfoWrapper{ src.Model() }
    {
    }

    PFUserFacebookInfoWrapper(PFUserFacebookInfoWrapper&& src) :
        PFUserFacebookInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserFacebookInfoWrapper& operator=(PFUserFacebookInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserFacebookInfoWrapper() = default;

    friend void swap(PFUserFacebookInfoWrapper& lhs, PFUserFacebookInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_facebookId, rhs.m_facebookId);
        swap(lhs.m_fullName, rhs.m_fullName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFacebookId(String value)
    {
        m_facebookId = std::move(value);
        this->m_model.facebookId =  m_facebookId.empty() ? nullptr : m_facebookId.data();
    }

    void SetFullName(String value)
    {
        m_fullName = std::move(value);
        this->m_model.fullName =  m_fullName.empty() ? nullptr : m_fullName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.facebookId = m_facebookId.empty() ? nullptr : m_facebookId.data();
        this->m_model.fullName = m_fullName.empty() ? nullptr : m_fullName.data();
    }

    String m_facebookId;
    String m_fullName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserGameCenterInfoWrapper : public ModelWrapper<PFUserGameCenterInfo, Alloc>
{
public:
    using ModelType = typename PFUserGameCenterInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserGameCenterInfoWrapper() = default;

    PFUserGameCenterInfoWrapper(const PFUserGameCenterInfo& model) :
        ModelWrapper<PFUserGameCenterInfo, Alloc>{ model },
        m_gameCenterId{ SafeString(model.gameCenterId) }
    {
        SetModelPointers();
    }

    PFUserGameCenterInfoWrapper(const PFUserGameCenterInfoWrapper& src) :
        PFUserGameCenterInfoWrapper{ src.Model() }
    {
    }

    PFUserGameCenterInfoWrapper(PFUserGameCenterInfoWrapper&& src) :
        PFUserGameCenterInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserGameCenterInfoWrapper& operator=(PFUserGameCenterInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserGameCenterInfoWrapper() = default;

    friend void swap(PFUserGameCenterInfoWrapper& lhs, PFUserGameCenterInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_gameCenterId, rhs.m_gameCenterId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGameCenterId(String value)
    {
        m_gameCenterId = std::move(value);
        this->m_model.gameCenterId =  m_gameCenterId.empty() ? nullptr : m_gameCenterId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.gameCenterId = m_gameCenterId.empty() ? nullptr : m_gameCenterId.data();
    }

    String m_gameCenterId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserPsnInfoWrapper : public ModelWrapper<PFUserPsnInfo, Alloc>
{
public:
    using ModelType = typename PFUserPsnInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserPsnInfoWrapper() = default;

    PFUserPsnInfoWrapper(const PFUserPsnInfo& model) :
        ModelWrapper<PFUserPsnInfo, Alloc>{ model },
        m_psnAccountId{ SafeString(model.psnAccountId) },
        m_psnOnlineId{ SafeString(model.psnOnlineId) }
    {
        SetModelPointers();
    }

    PFUserPsnInfoWrapper(const PFUserPsnInfoWrapper& src) :
        PFUserPsnInfoWrapper{ src.Model() }
    {
    }

    PFUserPsnInfoWrapper(PFUserPsnInfoWrapper&& src) :
        PFUserPsnInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserPsnInfoWrapper& operator=(PFUserPsnInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserPsnInfoWrapper() = default;

    friend void swap(PFUserPsnInfoWrapper& lhs, PFUserPsnInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_psnAccountId, rhs.m_psnAccountId);
        swap(lhs.m_psnOnlineId, rhs.m_psnOnlineId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPsnAccountId(String value)
    {
        m_psnAccountId = std::move(value);
        this->m_model.psnAccountId =  m_psnAccountId.empty() ? nullptr : m_psnAccountId.data();
    }

    void SetPsnOnlineId(String value)
    {
        m_psnOnlineId = std::move(value);
        this->m_model.psnOnlineId =  m_psnOnlineId.empty() ? nullptr : m_psnOnlineId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.psnAccountId = m_psnAccountId.empty() ? nullptr : m_psnAccountId.data();
        this->m_model.psnOnlineId = m_psnOnlineId.empty() ? nullptr : m_psnOnlineId.data();
    }

    String m_psnAccountId;
    String m_psnOnlineId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserSteamInfoWrapper : public ModelWrapper<PFUserSteamInfo, Alloc>
{
public:
    using ModelType = typename PFUserSteamInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserSteamInfoWrapper() = default;

    PFUserSteamInfoWrapper(const PFUserSteamInfo& model) :
        ModelWrapper<PFUserSteamInfo, Alloc>{ model },
        m_steamActivationStatus{ model.steamActivationStatus ? StdExtra::optional<PFTitleActivationStatus>{ *model.steamActivationStatus } : StdExtra::nullopt },
        m_steamCountry{ SafeString(model.steamCountry) },
        m_steamCurrency{ model.steamCurrency ? StdExtra::optional<PFCurrency>{ *model.steamCurrency } : StdExtra::nullopt },
        m_steamId{ SafeString(model.steamId) },
        m_steamName{ SafeString(model.steamName) }
    {
        SetModelPointers();
    }

    PFUserSteamInfoWrapper(const PFUserSteamInfoWrapper& src) :
        PFUserSteamInfoWrapper{ src.Model() }
    {
    }

    PFUserSteamInfoWrapper(PFUserSteamInfoWrapper&& src) :
        PFUserSteamInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserSteamInfoWrapper& operator=(PFUserSteamInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserSteamInfoWrapper() = default;

    friend void swap(PFUserSteamInfoWrapper& lhs, PFUserSteamInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_steamActivationStatus, rhs.m_steamActivationStatus);
        swap(lhs.m_steamCountry, rhs.m_steamCountry);
        swap(lhs.m_steamCurrency, rhs.m_steamCurrency);
        swap(lhs.m_steamId, rhs.m_steamId);
        swap(lhs.m_steamName, rhs.m_steamName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSteamActivationStatus(StdExtra::optional<PFTitleActivationStatus> value)
    {
        m_steamActivationStatus = std::move(value);
        this->m_model.steamActivationStatus = m_steamActivationStatus ? m_steamActivationStatus.operator->() : nullptr;
    }

    void SetSteamCountry(String value)
    {
        m_steamCountry = std::move(value);
        this->m_model.steamCountry =  m_steamCountry.empty() ? nullptr : m_steamCountry.data();
    }

    void SetSteamCurrency(StdExtra::optional<PFCurrency> value)
    {
        m_steamCurrency = std::move(value);
        this->m_model.steamCurrency = m_steamCurrency ? m_steamCurrency.operator->() : nullptr;
    }

    void SetSteamId(String value)
    {
        m_steamId = std::move(value);
        this->m_model.steamId =  m_steamId.empty() ? nullptr : m_steamId.data();
    }

    void SetSteamName(String value)
    {
        m_steamName = std::move(value);
        this->m_model.steamName =  m_steamName.empty() ? nullptr : m_steamName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.steamActivationStatus = m_steamActivationStatus ? m_steamActivationStatus.operator->() : nullptr;
        this->m_model.steamCountry = m_steamCountry.empty() ? nullptr : m_steamCountry.data();
        this->m_model.steamCurrency = m_steamCurrency ? m_steamCurrency.operator->() : nullptr;
        this->m_model.steamId = m_steamId.empty() ? nullptr : m_steamId.data();
        this->m_model.steamName = m_steamName.empty() ? nullptr : m_steamName.data();
    }

    StdExtra::optional<PFTitleActivationStatus> m_steamActivationStatus;
    String m_steamCountry;
    StdExtra::optional<PFCurrency> m_steamCurrency;
    String m_steamId;
    String m_steamName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserXboxInfoWrapper : public ModelWrapper<PFUserXboxInfo, Alloc>
{
public:
    using ModelType = typename PFUserXboxInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserXboxInfoWrapper() = default;

    PFUserXboxInfoWrapper(const PFUserXboxInfo& model) :
        ModelWrapper<PFUserXboxInfo, Alloc>{ model },
        m_xboxUserId{ SafeString(model.xboxUserId) }
    {
        SetModelPointers();
    }

    PFUserXboxInfoWrapper(const PFUserXboxInfoWrapper& src) :
        PFUserXboxInfoWrapper{ src.Model() }
    {
    }

    PFUserXboxInfoWrapper(PFUserXboxInfoWrapper&& src) :
        PFUserXboxInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserXboxInfoWrapper& operator=(PFUserXboxInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserXboxInfoWrapper() = default;

    friend void swap(PFUserXboxInfoWrapper& lhs, PFUserXboxInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_xboxUserId, rhs.m_xboxUserId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetXboxUserId(String value)
    {
        m_xboxUserId = std::move(value);
        this->m_model.xboxUserId =  m_xboxUserId.empty() ? nullptr : m_xboxUserId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.xboxUserId = m_xboxUserId.empty() ? nullptr : m_xboxUserId.data();
    }

    String m_xboxUserId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterResultWrapper : public ModelWrapper<PFCharacterResult, Alloc>
{
public:
    using ModelType = typename PFCharacterResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterResultWrapper() = default;

    PFCharacterResultWrapper(const PFCharacterResult& model) :
        ModelWrapper<PFCharacterResult, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_characterName{ SafeString(model.characterName) },
        m_characterType{ SafeString(model.characterType) }
    {
        SetModelPointers();
    }

    PFCharacterResultWrapper(const PFCharacterResultWrapper& src) :
        PFCharacterResultWrapper{ src.Model() }
    {
    }

    PFCharacterResultWrapper(PFCharacterResultWrapper&& src) :
        PFCharacterResultWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterResultWrapper& operator=(PFCharacterResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterResultWrapper() = default;

    friend void swap(PFCharacterResultWrapper& lhs, PFCharacterResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_characterName, rhs.m_characterName);
        swap(lhs.m_characterType, rhs.m_characterType);
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

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.characterName = m_characterName.empty() ? nullptr : m_characterName.data();
        this->m_model.characterType = m_characterType.empty() ? nullptr : m_characterType.data();
    }

    String m_characterId;
    String m_characterName;
    String m_characterType;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFVirtualCurrencyRechargeTimeWrapper : public ModelWrapper<PFVirtualCurrencyRechargeTime, Alloc>
{
public:
    using ModelType = typename PFVirtualCurrencyRechargeTime;
    using DictionaryEntryType = typename PFVirtualCurrencyRechargeTimeDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFVirtualCurrencyRechargeTime, Alloc>::ModelWrapper;

    void SetRechargeMax(int32_t value)
    {
        this->m_model.rechargeMax = value;
    }

    void SetRechargeTime(time_t value)
    {
        this->m_model.rechargeTime = value;
    }

    void SetSecondsToRecharge(int32_t value)
    {
        this->m_model.secondsToRecharge = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFStatisticValueWrapper : public ModelWrapper<PFStatisticValue, Alloc>
{
public:
    using ModelType = typename PFStatisticValue;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFStatisticValueWrapper() = default;

    PFStatisticValueWrapper(const PFStatisticValue& model) :
        ModelWrapper<PFStatisticValue, Alloc>{ model },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFStatisticValueWrapper(const PFStatisticValueWrapper& src) :
        PFStatisticValueWrapper{ src.Model() }
    {
    }

    PFStatisticValueWrapper(PFStatisticValueWrapper&& src) :
        PFStatisticValueWrapper{}
    {
        swap(*this, src);
    }

    PFStatisticValueWrapper& operator=(PFStatisticValueWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFStatisticValueWrapper() = default;

    friend void swap(PFStatisticValueWrapper& lhs, PFStatisticValueWrapper& rhs)
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

    void SetValue(int32_t value)
    {
        this->m_model.value = value;
    }

    void SetVersion(uint32_t value)
    {
        this->m_model.version = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    String m_statisticName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGetPlayerCombinedInfoRequestParamsWrapper : public ModelWrapper<PFGetPlayerCombinedInfoRequestParams, Alloc>
{
public:
    using ModelType = typename PFGetPlayerCombinedInfoRequestParams;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGetPlayerCombinedInfoRequestParamsWrapper() = default;

    PFGetPlayerCombinedInfoRequestParamsWrapper(const PFGetPlayerCombinedInfoRequestParams& model) :
        ModelWrapper<PFGetPlayerCombinedInfoRequestParams, Alloc>{ model },
        m_playerStatisticNames{ model.playerStatisticNames, model.playerStatisticNames + model.playerStatisticNamesCount },
        m_profileConstraints{ model.profileConstraints ? StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>>{ *model.profileConstraints } : StdExtra::nullopt },
        m_titleDataKeys{ model.titleDataKeys, model.titleDataKeys + model.titleDataKeysCount },
        m_userDataKeys{ model.userDataKeys, model.userDataKeys + model.userDataKeysCount },
        m_userReadOnlyDataKeys{ model.userReadOnlyDataKeys, model.userReadOnlyDataKeys + model.userReadOnlyDataKeysCount }
    {
        SetModelPointers();
    }

    PFGetPlayerCombinedInfoRequestParamsWrapper(const PFGetPlayerCombinedInfoRequestParamsWrapper& src) :
        PFGetPlayerCombinedInfoRequestParamsWrapper{ src.Model() }
    {
    }

    PFGetPlayerCombinedInfoRequestParamsWrapper(PFGetPlayerCombinedInfoRequestParamsWrapper&& src) :
        PFGetPlayerCombinedInfoRequestParamsWrapper{}
    {
        swap(*this, src);
    }

    PFGetPlayerCombinedInfoRequestParamsWrapper& operator=(PFGetPlayerCombinedInfoRequestParamsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGetPlayerCombinedInfoRequestParamsWrapper() = default;

    friend void swap(PFGetPlayerCombinedInfoRequestParamsWrapper& lhs, PFGetPlayerCombinedInfoRequestParamsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playerStatisticNames, rhs.m_playerStatisticNames);
        swap(lhs.m_profileConstraints, rhs.m_profileConstraints);
        swap(lhs.m_titleDataKeys, rhs.m_titleDataKeys);
        swap(lhs.m_userDataKeys, rhs.m_userDataKeys);
        swap(lhs.m_userReadOnlyDataKeys, rhs.m_userReadOnlyDataKeys);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGetCharacterInventories(bool value)
    {
        this->m_model.getCharacterInventories = value;
    }

    void SetGetCharacterList(bool value)
    {
        this->m_model.getCharacterList = value;
    }

    void SetGetPlayerProfile(bool value)
    {
        this->m_model.getPlayerProfile = value;
    }

    void SetGetPlayerStatistics(bool value)
    {
        this->m_model.getPlayerStatistics = value;
    }

    void SetGetTitleData(bool value)
    {
        this->m_model.getTitleData = value;
    }

    void SetGetUserAccountInfo(bool value)
    {
        this->m_model.getUserAccountInfo = value;
    }

    void SetGetUserData(bool value)
    {
        this->m_model.getUserData = value;
    }

    void SetGetUserInventory(bool value)
    {
        this->m_model.getUserInventory = value;
    }

    void SetGetUserReadOnlyData(bool value)
    {
        this->m_model.getUserReadOnlyData = value;
    }

    void SetGetUserVirtualCurrency(bool value)
    {
        this->m_model.getUserVirtualCurrency = value;
    }

    void SetPlayerStatisticNames(CStringVector<Alloc> value)
    {
        m_playerStatisticNames = std::move(value);
        this->m_model.playerStatisticNames =  m_playerStatisticNames.empty() ? nullptr : m_playerStatisticNames.data();
        this->m_model.playerStatisticNamesCount =  static_cast<uint32_t>(m_playerStatisticNames.size());
    }

    void SetProfileConstraints(StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> value)
    {
        m_profileConstraints = std::move(value);
        this->m_model.profileConstraints = m_profileConstraints ? &m_profileConstraints->Model() : nullptr;
    }

    void SetTitleDataKeys(CStringVector<Alloc> value)
    {
        m_titleDataKeys = std::move(value);
        this->m_model.titleDataKeys =  m_titleDataKeys.empty() ? nullptr : m_titleDataKeys.data();
        this->m_model.titleDataKeysCount =  static_cast<uint32_t>(m_titleDataKeys.size());
    }

    void SetUserDataKeys(CStringVector<Alloc> value)
    {
        m_userDataKeys = std::move(value);
        this->m_model.userDataKeys =  m_userDataKeys.empty() ? nullptr : m_userDataKeys.data();
        this->m_model.userDataKeysCount =  static_cast<uint32_t>(m_userDataKeys.size());
    }

    void SetUserReadOnlyDataKeys(CStringVector<Alloc> value)
    {
        m_userReadOnlyDataKeys = std::move(value);
        this->m_model.userReadOnlyDataKeys =  m_userReadOnlyDataKeys.empty() ? nullptr : m_userReadOnlyDataKeys.data();
        this->m_model.userReadOnlyDataKeysCount =  static_cast<uint32_t>(m_userReadOnlyDataKeys.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.playerStatisticNames = m_playerStatisticNames.empty() ? nullptr : m_playerStatisticNames.data();
        this->m_model.profileConstraints = m_profileConstraints ?  &m_profileConstraints->Model() : nullptr;
        this->m_model.titleDataKeys = m_titleDataKeys.empty() ? nullptr : m_titleDataKeys.data();
        this->m_model.userDataKeys = m_userDataKeys.empty() ? nullptr : m_userDataKeys.data();
        this->m_model.userReadOnlyDataKeys = m_userReadOnlyDataKeys.empty() ? nullptr : m_userReadOnlyDataKeys.data();
    }

    CStringVector<Alloc> m_playerStatisticNames;
    StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> m_profileConstraints;
    CStringVector<Alloc> m_titleDataKeys;
    CStringVector<Alloc> m_userDataKeys;
    CStringVector<Alloc> m_userReadOnlyDataKeys;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFEntityKeyWrapper : public ModelWrapper<PFEntityKey, Alloc>
{
public:
    using ModelType = typename PFEntityKey;
    using DictionaryEntryType = typename PFEntityKeyDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEntityKeyWrapper() = default;

    PFEntityKeyWrapper(const PFEntityKey& model) :
        ModelWrapper<PFEntityKey, Alloc>{ model },
        m_id{ SafeString(model.id) },
        m_type{ SafeString(model.type) }
    {
        SetModelPointers();
    }

    PFEntityKeyWrapper(const PFEntityKeyWrapper& src) :
        PFEntityKeyWrapper{ src.Model() }
    {
    }

    PFEntityKeyWrapper(PFEntityKeyWrapper&& src) :
        PFEntityKeyWrapper{}
    {
        swap(*this, src);
    }

    PFEntityKeyWrapper& operator=(PFEntityKeyWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEntityKeyWrapper() = default;

    friend void swap(PFEntityKeyWrapper& lhs, PFEntityKeyWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_type, rhs.m_type);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetType(String value)
    {
        m_type = std::move(value);
        this->m_model.type =  m_type.empty() ? nullptr : m_type.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.type = m_type.empty() ? nullptr : m_type.data();
    }

    String m_id;
    String m_type;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserAndroidDeviceInfoWrapper : public ModelWrapper<PFUserAndroidDeviceInfo, Alloc>
{
public:
    using ModelType = typename PFUserAndroidDeviceInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserAndroidDeviceInfoWrapper() = default;

    PFUserAndroidDeviceInfoWrapper(const PFUserAndroidDeviceInfo& model) :
        ModelWrapper<PFUserAndroidDeviceInfo, Alloc>{ model },
        m_androidDeviceId{ SafeString(model.androidDeviceId) }
    {
        SetModelPointers();
    }

    PFUserAndroidDeviceInfoWrapper(const PFUserAndroidDeviceInfoWrapper& src) :
        PFUserAndroidDeviceInfoWrapper{ src.Model() }
    {
    }

    PFUserAndroidDeviceInfoWrapper(PFUserAndroidDeviceInfoWrapper&& src) :
        PFUserAndroidDeviceInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserAndroidDeviceInfoWrapper& operator=(PFUserAndroidDeviceInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserAndroidDeviceInfoWrapper() = default;

    friend void swap(PFUserAndroidDeviceInfoWrapper& lhs, PFUserAndroidDeviceInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_androidDeviceId, rhs.m_androidDeviceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAndroidDeviceId(String value)
    {
        m_androidDeviceId = std::move(value);
        this->m_model.androidDeviceId =  m_androidDeviceId.empty() ? nullptr : m_androidDeviceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.androidDeviceId = m_androidDeviceId.empty() ? nullptr : m_androidDeviceId.data();
    }

    String m_androidDeviceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserAppleIdInfoWrapper : public ModelWrapper<PFUserAppleIdInfo, Alloc>
{
public:
    using ModelType = typename PFUserAppleIdInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserAppleIdInfoWrapper() = default;

    PFUserAppleIdInfoWrapper(const PFUserAppleIdInfo& model) :
        ModelWrapper<PFUserAppleIdInfo, Alloc>{ model },
        m_appleSubjectId{ SafeString(model.appleSubjectId) }
    {
        SetModelPointers();
    }

    PFUserAppleIdInfoWrapper(const PFUserAppleIdInfoWrapper& src) :
        PFUserAppleIdInfoWrapper{ src.Model() }
    {
    }

    PFUserAppleIdInfoWrapper(PFUserAppleIdInfoWrapper&& src) :
        PFUserAppleIdInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserAppleIdInfoWrapper& operator=(PFUserAppleIdInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserAppleIdInfoWrapper() = default;

    friend void swap(PFUserAppleIdInfoWrapper& lhs, PFUserAppleIdInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_appleSubjectId, rhs.m_appleSubjectId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAppleSubjectId(String value)
    {
        m_appleSubjectId = std::move(value);
        this->m_model.appleSubjectId =  m_appleSubjectId.empty() ? nullptr : m_appleSubjectId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.appleSubjectId = m_appleSubjectId.empty() ? nullptr : m_appleSubjectId.data();
    }

    String m_appleSubjectId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserCustomIdInfoWrapper : public ModelWrapper<PFUserCustomIdInfo, Alloc>
{
public:
    using ModelType = typename PFUserCustomIdInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserCustomIdInfoWrapper() = default;

    PFUserCustomIdInfoWrapper(const PFUserCustomIdInfo& model) :
        ModelWrapper<PFUserCustomIdInfo, Alloc>{ model },
        m_customId{ SafeString(model.customId) }
    {
        SetModelPointers();
    }

    PFUserCustomIdInfoWrapper(const PFUserCustomIdInfoWrapper& src) :
        PFUserCustomIdInfoWrapper{ src.Model() }
    {
    }

    PFUserCustomIdInfoWrapper(PFUserCustomIdInfoWrapper&& src) :
        PFUserCustomIdInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserCustomIdInfoWrapper& operator=(PFUserCustomIdInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserCustomIdInfoWrapper() = default;

    friend void swap(PFUserCustomIdInfoWrapper& lhs, PFUserCustomIdInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customId, rhs.m_customId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomId(String value)
    {
        m_customId = std::move(value);
        this->m_model.customId =  m_customId.empty() ? nullptr : m_customId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customId = m_customId.empty() ? nullptr : m_customId.data();
    }

    String m_customId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserFacebookInstantGamesIdInfoWrapper : public ModelWrapper<PFUserFacebookInstantGamesIdInfo, Alloc>
{
public:
    using ModelType = typename PFUserFacebookInstantGamesIdInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserFacebookInstantGamesIdInfoWrapper() = default;

    PFUserFacebookInstantGamesIdInfoWrapper(const PFUserFacebookInstantGamesIdInfo& model) :
        ModelWrapper<PFUserFacebookInstantGamesIdInfo, Alloc>{ model },
        m_facebookInstantGamesId{ SafeString(model.facebookInstantGamesId) }
    {
        SetModelPointers();
    }

    PFUserFacebookInstantGamesIdInfoWrapper(const PFUserFacebookInstantGamesIdInfoWrapper& src) :
        PFUserFacebookInstantGamesIdInfoWrapper{ src.Model() }
    {
    }

    PFUserFacebookInstantGamesIdInfoWrapper(PFUserFacebookInstantGamesIdInfoWrapper&& src) :
        PFUserFacebookInstantGamesIdInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserFacebookInstantGamesIdInfoWrapper& operator=(PFUserFacebookInstantGamesIdInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserFacebookInstantGamesIdInfoWrapper() = default;

    friend void swap(PFUserFacebookInstantGamesIdInfoWrapper& lhs, PFUserFacebookInstantGamesIdInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_facebookInstantGamesId, rhs.m_facebookInstantGamesId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFacebookInstantGamesId(String value)
    {
        m_facebookInstantGamesId = std::move(value);
        this->m_model.facebookInstantGamesId =  m_facebookInstantGamesId.empty() ? nullptr : m_facebookInstantGamesId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.facebookInstantGamesId = m_facebookInstantGamesId.empty() ? nullptr : m_facebookInstantGamesId.data();
    }

    String m_facebookInstantGamesId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserGoogleInfoWrapper : public ModelWrapper<PFUserGoogleInfo, Alloc>
{
public:
    using ModelType = typename PFUserGoogleInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserGoogleInfoWrapper() = default;

    PFUserGoogleInfoWrapper(const PFUserGoogleInfo& model) :
        ModelWrapper<PFUserGoogleInfo, Alloc>{ model },
        m_googleEmail{ SafeString(model.googleEmail) },
        m_googleGender{ SafeString(model.googleGender) },
        m_googleId{ SafeString(model.googleId) },
        m_googleLocale{ SafeString(model.googleLocale) },
        m_googleName{ SafeString(model.googleName) }
    {
        SetModelPointers();
    }

    PFUserGoogleInfoWrapper(const PFUserGoogleInfoWrapper& src) :
        PFUserGoogleInfoWrapper{ src.Model() }
    {
    }

    PFUserGoogleInfoWrapper(PFUserGoogleInfoWrapper&& src) :
        PFUserGoogleInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserGoogleInfoWrapper& operator=(PFUserGoogleInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserGoogleInfoWrapper() = default;

    friend void swap(PFUserGoogleInfoWrapper& lhs, PFUserGoogleInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_googleEmail, rhs.m_googleEmail);
        swap(lhs.m_googleGender, rhs.m_googleGender);
        swap(lhs.m_googleId, rhs.m_googleId);
        swap(lhs.m_googleLocale, rhs.m_googleLocale);
        swap(lhs.m_googleName, rhs.m_googleName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGoogleEmail(String value)
    {
        m_googleEmail = std::move(value);
        this->m_model.googleEmail =  m_googleEmail.empty() ? nullptr : m_googleEmail.data();
    }

    void SetGoogleGender(String value)
    {
        m_googleGender = std::move(value);
        this->m_model.googleGender =  m_googleGender.empty() ? nullptr : m_googleGender.data();
    }

    void SetGoogleId(String value)
    {
        m_googleId = std::move(value);
        this->m_model.googleId =  m_googleId.empty() ? nullptr : m_googleId.data();
    }

    void SetGoogleLocale(String value)
    {
        m_googleLocale = std::move(value);
        this->m_model.googleLocale =  m_googleLocale.empty() ? nullptr : m_googleLocale.data();
    }

    void SetGoogleName(String value)
    {
        m_googleName = std::move(value);
        this->m_model.googleName =  m_googleName.empty() ? nullptr : m_googleName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.googleEmail = m_googleEmail.empty() ? nullptr : m_googleEmail.data();
        this->m_model.googleGender = m_googleGender.empty() ? nullptr : m_googleGender.data();
        this->m_model.googleId = m_googleId.empty() ? nullptr : m_googleId.data();
        this->m_model.googleLocale = m_googleLocale.empty() ? nullptr : m_googleLocale.data();
        this->m_model.googleName = m_googleName.empty() ? nullptr : m_googleName.data();
    }

    String m_googleEmail;
    String m_googleGender;
    String m_googleId;
    String m_googleLocale;
    String m_googleName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserIosDeviceInfoWrapper : public ModelWrapper<PFUserIosDeviceInfo, Alloc>
{
public:
    using ModelType = typename PFUserIosDeviceInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserIosDeviceInfoWrapper() = default;

    PFUserIosDeviceInfoWrapper(const PFUserIosDeviceInfo& model) :
        ModelWrapper<PFUserIosDeviceInfo, Alloc>{ model },
        m_iosDeviceId{ SafeString(model.iosDeviceId) }
    {
        SetModelPointers();
    }

    PFUserIosDeviceInfoWrapper(const PFUserIosDeviceInfoWrapper& src) :
        PFUserIosDeviceInfoWrapper{ src.Model() }
    {
    }

    PFUserIosDeviceInfoWrapper(PFUserIosDeviceInfoWrapper&& src) :
        PFUserIosDeviceInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserIosDeviceInfoWrapper& operator=(PFUserIosDeviceInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserIosDeviceInfoWrapper() = default;

    friend void swap(PFUserIosDeviceInfoWrapper& lhs, PFUserIosDeviceInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_iosDeviceId, rhs.m_iosDeviceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIosDeviceId(String value)
    {
        m_iosDeviceId = std::move(value);
        this->m_model.iosDeviceId =  m_iosDeviceId.empty() ? nullptr : m_iosDeviceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.iosDeviceId = m_iosDeviceId.empty() ? nullptr : m_iosDeviceId.data();
    }

    String m_iosDeviceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserKongregateInfoWrapper : public ModelWrapper<PFUserKongregateInfo, Alloc>
{
public:
    using ModelType = typename PFUserKongregateInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserKongregateInfoWrapper() = default;

    PFUserKongregateInfoWrapper(const PFUserKongregateInfo& model) :
        ModelWrapper<PFUserKongregateInfo, Alloc>{ model },
        m_kongregateId{ SafeString(model.kongregateId) },
        m_kongregateName{ SafeString(model.kongregateName) }
    {
        SetModelPointers();
    }

    PFUserKongregateInfoWrapper(const PFUserKongregateInfoWrapper& src) :
        PFUserKongregateInfoWrapper{ src.Model() }
    {
    }

    PFUserKongregateInfoWrapper(PFUserKongregateInfoWrapper&& src) :
        PFUserKongregateInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserKongregateInfoWrapper& operator=(PFUserKongregateInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserKongregateInfoWrapper() = default;

    friend void swap(PFUserKongregateInfoWrapper& lhs, PFUserKongregateInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_kongregateId, rhs.m_kongregateId);
        swap(lhs.m_kongregateName, rhs.m_kongregateName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetKongregateId(String value)
    {
        m_kongregateId = std::move(value);
        this->m_model.kongregateId =  m_kongregateId.empty() ? nullptr : m_kongregateId.data();
    }

    void SetKongregateName(String value)
    {
        m_kongregateName = std::move(value);
        this->m_model.kongregateName =  m_kongregateName.empty() ? nullptr : m_kongregateName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.kongregateId = m_kongregateId.empty() ? nullptr : m_kongregateId.data();
        this->m_model.kongregateName = m_kongregateName.empty() ? nullptr : m_kongregateName.data();
    }

    String m_kongregateId;
    String m_kongregateName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserNintendoSwitchAccountIdInfoWrapper : public ModelWrapper<PFUserNintendoSwitchAccountIdInfo, Alloc>
{
public:
    using ModelType = typename PFUserNintendoSwitchAccountIdInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserNintendoSwitchAccountIdInfoWrapper() = default;

    PFUserNintendoSwitchAccountIdInfoWrapper(const PFUserNintendoSwitchAccountIdInfo& model) :
        ModelWrapper<PFUserNintendoSwitchAccountIdInfo, Alloc>{ model },
        m_nintendoSwitchAccountSubjectId{ SafeString(model.nintendoSwitchAccountSubjectId) }
    {
        SetModelPointers();
    }

    PFUserNintendoSwitchAccountIdInfoWrapper(const PFUserNintendoSwitchAccountIdInfoWrapper& src) :
        PFUserNintendoSwitchAccountIdInfoWrapper{ src.Model() }
    {
    }

    PFUserNintendoSwitchAccountIdInfoWrapper(PFUserNintendoSwitchAccountIdInfoWrapper&& src) :
        PFUserNintendoSwitchAccountIdInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserNintendoSwitchAccountIdInfoWrapper& operator=(PFUserNintendoSwitchAccountIdInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserNintendoSwitchAccountIdInfoWrapper() = default;

    friend void swap(PFUserNintendoSwitchAccountIdInfoWrapper& lhs, PFUserNintendoSwitchAccountIdInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_nintendoSwitchAccountSubjectId, rhs.m_nintendoSwitchAccountSubjectId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetNintendoSwitchAccountSubjectId(String value)
    {
        m_nintendoSwitchAccountSubjectId = std::move(value);
        this->m_model.nintendoSwitchAccountSubjectId =  m_nintendoSwitchAccountSubjectId.empty() ? nullptr : m_nintendoSwitchAccountSubjectId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.nintendoSwitchAccountSubjectId = m_nintendoSwitchAccountSubjectId.empty() ? nullptr : m_nintendoSwitchAccountSubjectId.data();
    }

    String m_nintendoSwitchAccountSubjectId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserNintendoSwitchDeviceIdInfoWrapper : public ModelWrapper<PFUserNintendoSwitchDeviceIdInfo, Alloc>
{
public:
    using ModelType = typename PFUserNintendoSwitchDeviceIdInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserNintendoSwitchDeviceIdInfoWrapper() = default;

    PFUserNintendoSwitchDeviceIdInfoWrapper(const PFUserNintendoSwitchDeviceIdInfo& model) :
        ModelWrapper<PFUserNintendoSwitchDeviceIdInfo, Alloc>{ model },
        m_nintendoSwitchDeviceId{ SafeString(model.nintendoSwitchDeviceId) }
    {
        SetModelPointers();
    }

    PFUserNintendoSwitchDeviceIdInfoWrapper(const PFUserNintendoSwitchDeviceIdInfoWrapper& src) :
        PFUserNintendoSwitchDeviceIdInfoWrapper{ src.Model() }
    {
    }

    PFUserNintendoSwitchDeviceIdInfoWrapper(PFUserNintendoSwitchDeviceIdInfoWrapper&& src) :
        PFUserNintendoSwitchDeviceIdInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserNintendoSwitchDeviceIdInfoWrapper& operator=(PFUserNintendoSwitchDeviceIdInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserNintendoSwitchDeviceIdInfoWrapper() = default;

    friend void swap(PFUserNintendoSwitchDeviceIdInfoWrapper& lhs, PFUserNintendoSwitchDeviceIdInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_nintendoSwitchDeviceId, rhs.m_nintendoSwitchDeviceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetNintendoSwitchDeviceId(String value)
    {
        m_nintendoSwitchDeviceId = std::move(value);
        this->m_model.nintendoSwitchDeviceId =  m_nintendoSwitchDeviceId.empty() ? nullptr : m_nintendoSwitchDeviceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.nintendoSwitchDeviceId = m_nintendoSwitchDeviceId.empty() ? nullptr : m_nintendoSwitchDeviceId.data();
    }

    String m_nintendoSwitchDeviceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserOpenIdInfoWrapper : public ModelWrapper<PFUserOpenIdInfo, Alloc>
{
public:
    using ModelType = typename PFUserOpenIdInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserOpenIdInfoWrapper() = default;

    PFUserOpenIdInfoWrapper(const PFUserOpenIdInfo& model) :
        ModelWrapper<PFUserOpenIdInfo, Alloc>{ model },
        m_connectionId{ SafeString(model.connectionId) },
        m_issuer{ SafeString(model.issuer) },
        m_subject{ SafeString(model.subject) }
    {
        SetModelPointers();
    }

    PFUserOpenIdInfoWrapper(const PFUserOpenIdInfoWrapper& src) :
        PFUserOpenIdInfoWrapper{ src.Model() }
    {
    }

    PFUserOpenIdInfoWrapper(PFUserOpenIdInfoWrapper&& src) :
        PFUserOpenIdInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserOpenIdInfoWrapper& operator=(PFUserOpenIdInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserOpenIdInfoWrapper() = default;

    friend void swap(PFUserOpenIdInfoWrapper& lhs, PFUserOpenIdInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionId, rhs.m_connectionId);
        swap(lhs.m_issuer, rhs.m_issuer);
        swap(lhs.m_subject, rhs.m_subject);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionId(String value)
    {
        m_connectionId = std::move(value);
        this->m_model.connectionId =  m_connectionId.empty() ? nullptr : m_connectionId.data();
    }

    void SetIssuer(String value)
    {
        m_issuer = std::move(value);
        this->m_model.issuer =  m_issuer.empty() ? nullptr : m_issuer.data();
    }

    void SetSubject(String value)
    {
        m_subject = std::move(value);
        this->m_model.subject =  m_subject.empty() ? nullptr : m_subject.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionId = m_connectionId.empty() ? nullptr : m_connectionId.data();
        this->m_model.issuer = m_issuer.empty() ? nullptr : m_issuer.data();
        this->m_model.subject = m_subject.empty() ? nullptr : m_subject.data();
    }

    String m_connectionId;
    String m_issuer;
    String m_subject;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserPrivateAccountInfoWrapper : public ModelWrapper<PFUserPrivateAccountInfo, Alloc>
{
public:
    using ModelType = typename PFUserPrivateAccountInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserPrivateAccountInfoWrapper() = default;

    PFUserPrivateAccountInfoWrapper(const PFUserPrivateAccountInfo& model) :
        ModelWrapper<PFUserPrivateAccountInfo, Alloc>{ model },
        m_email{ SafeString(model.email) }
    {
        SetModelPointers();
    }

    PFUserPrivateAccountInfoWrapper(const PFUserPrivateAccountInfoWrapper& src) :
        PFUserPrivateAccountInfoWrapper{ src.Model() }
    {
    }

    PFUserPrivateAccountInfoWrapper(PFUserPrivateAccountInfoWrapper&& src) :
        PFUserPrivateAccountInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserPrivateAccountInfoWrapper& operator=(PFUserPrivateAccountInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserPrivateAccountInfoWrapper() = default;

    friend void swap(PFUserPrivateAccountInfoWrapper& lhs, PFUserPrivateAccountInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_email, rhs.m_email);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEmail(String value)
    {
        m_email = std::move(value);
        this->m_model.email =  m_email.empty() ? nullptr : m_email.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.email = m_email.empty() ? nullptr : m_email.data();
    }

    String m_email;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserTitleInfoWrapper : public ModelWrapper<PFUserTitleInfo, Alloc>
{
public:
    using ModelType = typename PFUserTitleInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserTitleInfoWrapper() = default;

    PFUserTitleInfoWrapper(const PFUserTitleInfo& model) :
        ModelWrapper<PFUserTitleInfo, Alloc>{ model },
        m_avatarUrl{ SafeString(model.avatarUrl) },
        m_displayName{ SafeString(model.displayName) },
        m_firstLogin{ model.firstLogin ? StdExtra::optional<time_t>{ *model.firstLogin } : StdExtra::nullopt },
        m_isBanned{ model.isBanned ? StdExtra::optional<bool>{ *model.isBanned } : StdExtra::nullopt },
        m_lastLogin{ model.lastLogin ? StdExtra::optional<time_t>{ *model.lastLogin } : StdExtra::nullopt },
        m_origination{ model.origination ? StdExtra::optional<PFUserOrigination>{ *model.origination } : StdExtra::nullopt },
        m_titlePlayerAccount{ model.titlePlayerAccount ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.titlePlayerAccount } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFUserTitleInfoWrapper(const PFUserTitleInfoWrapper& src) :
        PFUserTitleInfoWrapper{ src.Model() }
    {
    }

    PFUserTitleInfoWrapper(PFUserTitleInfoWrapper&& src) :
        PFUserTitleInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserTitleInfoWrapper& operator=(PFUserTitleInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserTitleInfoWrapper() = default;

    friend void swap(PFUserTitleInfoWrapper& lhs, PFUserTitleInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_avatarUrl, rhs.m_avatarUrl);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_firstLogin, rhs.m_firstLogin);
        swap(lhs.m_isBanned, rhs.m_isBanned);
        swap(lhs.m_lastLogin, rhs.m_lastLogin);
        swap(lhs.m_origination, rhs.m_origination);
        swap(lhs.m_titlePlayerAccount, rhs.m_titlePlayerAccount);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAvatarUrl(String value)
    {
        m_avatarUrl = std::move(value);
        this->m_model.avatarUrl =  m_avatarUrl.empty() ? nullptr : m_avatarUrl.data();
    }

    void SetCreated(time_t value)
    {
        this->m_model.created = value;
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

    void SetFirstLogin(StdExtra::optional<time_t> value)
    {
        m_firstLogin = std::move(value);
        this->m_model.firstLogin = m_firstLogin ? m_firstLogin.operator->() : nullptr;
    }

    void SetisBanned(StdExtra::optional<bool> value)
    {
        m_isBanned = std::move(value);
        this->m_model.isBanned = m_isBanned ? m_isBanned.operator->() : nullptr;
    }

    void SetLastLogin(StdExtra::optional<time_t> value)
    {
        m_lastLogin = std::move(value);
        this->m_model.lastLogin = m_lastLogin ? m_lastLogin.operator->() : nullptr;
    }

    void SetOrigination(StdExtra::optional<PFUserOrigination> value)
    {
        m_origination = std::move(value);
        this->m_model.origination = m_origination ? m_origination.operator->() : nullptr;
    }

    void SetTitlePlayerAccount(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_titlePlayerAccount = std::move(value);
        this->m_model.titlePlayerAccount = m_titlePlayerAccount ? &m_titlePlayerAccount->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.avatarUrl = m_avatarUrl.empty() ? nullptr : m_avatarUrl.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.firstLogin = m_firstLogin ? m_firstLogin.operator->() : nullptr;
        this->m_model.isBanned = m_isBanned ? m_isBanned.operator->() : nullptr;
        this->m_model.lastLogin = m_lastLogin ? m_lastLogin.operator->() : nullptr;
        this->m_model.origination = m_origination ? m_origination.operator->() : nullptr;
        this->m_model.titlePlayerAccount = m_titlePlayerAccount ?  &m_titlePlayerAccount->Model() : nullptr;
    }

    String m_avatarUrl;
    String m_displayName;
    StdExtra::optional<time_t> m_firstLogin;
    StdExtra::optional<bool> m_isBanned;
    StdExtra::optional<time_t> m_lastLogin;
    StdExtra::optional<PFUserOrigination> m_origination;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_titlePlayerAccount;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserTwitchInfoWrapper : public ModelWrapper<PFUserTwitchInfo, Alloc>
{
public:
    using ModelType = typename PFUserTwitchInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserTwitchInfoWrapper() = default;

    PFUserTwitchInfoWrapper(const PFUserTwitchInfo& model) :
        ModelWrapper<PFUserTwitchInfo, Alloc>{ model },
        m_twitchId{ SafeString(model.twitchId) },
        m_twitchUserName{ SafeString(model.twitchUserName) }
    {
        SetModelPointers();
    }

    PFUserTwitchInfoWrapper(const PFUserTwitchInfoWrapper& src) :
        PFUserTwitchInfoWrapper{ src.Model() }
    {
    }

    PFUserTwitchInfoWrapper(PFUserTwitchInfoWrapper&& src) :
        PFUserTwitchInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserTwitchInfoWrapper& operator=(PFUserTwitchInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserTwitchInfoWrapper() = default;

    friend void swap(PFUserTwitchInfoWrapper& lhs, PFUserTwitchInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_twitchId, rhs.m_twitchId);
        swap(lhs.m_twitchUserName, rhs.m_twitchUserName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTwitchId(String value)
    {
        m_twitchId = std::move(value);
        this->m_model.twitchId =  m_twitchId.empty() ? nullptr : m_twitchId.data();
    }

    void SetTwitchUserName(String value)
    {
        m_twitchUserName = std::move(value);
        this->m_model.twitchUserName =  m_twitchUserName.empty() ? nullptr : m_twitchUserName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.twitchId = m_twitchId.empty() ? nullptr : m_twitchId.data();
        this->m_model.twitchUserName = m_twitchUserName.empty() ? nullptr : m_twitchUserName.data();
    }

    String m_twitchId;
    String m_twitchUserName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFUserAccountInfoWrapper : public ModelWrapper<PFUserAccountInfo, Alloc>
{
public:
    using ModelType = typename PFUserAccountInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFUserAccountInfoWrapper() = default;

    PFUserAccountInfoWrapper(const PFUserAccountInfo& model) :
        ModelWrapper<PFUserAccountInfo, Alloc>{ model },
        m_androidDeviceInfo{ model.androidDeviceInfo ? StdExtra::optional<PFUserAndroidDeviceInfoWrapper<Alloc>>{ *model.androidDeviceInfo } : StdExtra::nullopt },
        m_appleAccountInfo{ model.appleAccountInfo ? StdExtra::optional<PFUserAppleIdInfoWrapper<Alloc>>{ *model.appleAccountInfo } : StdExtra::nullopt },
        m_customIdInfo{ model.customIdInfo ? StdExtra::optional<PFUserCustomIdInfoWrapper<Alloc>>{ *model.customIdInfo } : StdExtra::nullopt },
        m_facebookInfo{ model.facebookInfo ? StdExtra::optional<PFUserFacebookInfoWrapper<Alloc>>{ *model.facebookInfo } : StdExtra::nullopt },
        m_facebookInstantGamesIdInfo{ model.facebookInstantGamesIdInfo ? StdExtra::optional<PFUserFacebookInstantGamesIdInfoWrapper<Alloc>>{ *model.facebookInstantGamesIdInfo } : StdExtra::nullopt },
        m_gameCenterInfo{ model.gameCenterInfo ? StdExtra::optional<PFUserGameCenterInfoWrapper<Alloc>>{ *model.gameCenterInfo } : StdExtra::nullopt },
        m_googleInfo{ model.googleInfo ? StdExtra::optional<PFUserGoogleInfoWrapper<Alloc>>{ *model.googleInfo } : StdExtra::nullopt },
        m_iosDeviceInfo{ model.iosDeviceInfo ? StdExtra::optional<PFUserIosDeviceInfoWrapper<Alloc>>{ *model.iosDeviceInfo } : StdExtra::nullopt },
        m_kongregateInfo{ model.kongregateInfo ? StdExtra::optional<PFUserKongregateInfoWrapper<Alloc>>{ *model.kongregateInfo } : StdExtra::nullopt },
        m_nintendoSwitchAccountInfo{ model.nintendoSwitchAccountInfo ? StdExtra::optional<PFUserNintendoSwitchAccountIdInfoWrapper<Alloc>>{ *model.nintendoSwitchAccountInfo } : StdExtra::nullopt },
        m_nintendoSwitchDeviceIdInfo{ model.nintendoSwitchDeviceIdInfo ? StdExtra::optional<PFUserNintendoSwitchDeviceIdInfoWrapper<Alloc>>{ *model.nintendoSwitchDeviceIdInfo } : StdExtra::nullopt },
        m_openIdInfo{ model.openIdInfo, model.openIdInfo + model.openIdInfoCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_privateInfo{ model.privateInfo ? StdExtra::optional<PFUserPrivateAccountInfoWrapper<Alloc>>{ *model.privateInfo } : StdExtra::nullopt },
        m_psnInfo{ model.psnInfo ? StdExtra::optional<PFUserPsnInfoWrapper<Alloc>>{ *model.psnInfo } : StdExtra::nullopt },
        m_steamInfo{ model.steamInfo ? StdExtra::optional<PFUserSteamInfoWrapper<Alloc>>{ *model.steamInfo } : StdExtra::nullopt },
        m_titleInfo{ model.titleInfo ? StdExtra::optional<PFUserTitleInfoWrapper<Alloc>>{ *model.titleInfo } : StdExtra::nullopt },
        m_twitchInfo{ model.twitchInfo ? StdExtra::optional<PFUserTwitchInfoWrapper<Alloc>>{ *model.twitchInfo } : StdExtra::nullopt },
        m_username{ SafeString(model.username) },
        m_xboxInfo{ model.xboxInfo ? StdExtra::optional<PFUserXboxInfoWrapper<Alloc>>{ *model.xboxInfo } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFUserAccountInfoWrapper(const PFUserAccountInfoWrapper& src) :
        PFUserAccountInfoWrapper{ src.Model() }
    {
    }

    PFUserAccountInfoWrapper(PFUserAccountInfoWrapper&& src) :
        PFUserAccountInfoWrapper{}
    {
        swap(*this, src);
    }

    PFUserAccountInfoWrapper& operator=(PFUserAccountInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFUserAccountInfoWrapper() = default;

    friend void swap(PFUserAccountInfoWrapper& lhs, PFUserAccountInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_androidDeviceInfo, rhs.m_androidDeviceInfo);
        swap(lhs.m_appleAccountInfo, rhs.m_appleAccountInfo);
        swap(lhs.m_customIdInfo, rhs.m_customIdInfo);
        swap(lhs.m_facebookInfo, rhs.m_facebookInfo);
        swap(lhs.m_facebookInstantGamesIdInfo, rhs.m_facebookInstantGamesIdInfo);
        swap(lhs.m_gameCenterInfo, rhs.m_gameCenterInfo);
        swap(lhs.m_googleInfo, rhs.m_googleInfo);
        swap(lhs.m_iosDeviceInfo, rhs.m_iosDeviceInfo);
        swap(lhs.m_kongregateInfo, rhs.m_kongregateInfo);
        swap(lhs.m_nintendoSwitchAccountInfo, rhs.m_nintendoSwitchAccountInfo);
        swap(lhs.m_nintendoSwitchDeviceIdInfo, rhs.m_nintendoSwitchDeviceIdInfo);
        swap(lhs.m_openIdInfo, rhs.m_openIdInfo);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_privateInfo, rhs.m_privateInfo);
        swap(lhs.m_psnInfo, rhs.m_psnInfo);
        swap(lhs.m_steamInfo, rhs.m_steamInfo);
        swap(lhs.m_titleInfo, rhs.m_titleInfo);
        swap(lhs.m_twitchInfo, rhs.m_twitchInfo);
        swap(lhs.m_username, rhs.m_username);
        swap(lhs.m_xboxInfo, rhs.m_xboxInfo);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAndroidDeviceInfo(StdExtra::optional<PFUserAndroidDeviceInfoWrapper<Alloc>> value)
    {
        m_androidDeviceInfo = std::move(value);
        this->m_model.androidDeviceInfo = m_androidDeviceInfo ? &m_androidDeviceInfo->Model() : nullptr;
    }

    void SetAppleAccountInfo(StdExtra::optional<PFUserAppleIdInfoWrapper<Alloc>> value)
    {
        m_appleAccountInfo = std::move(value);
        this->m_model.appleAccountInfo = m_appleAccountInfo ? &m_appleAccountInfo->Model() : nullptr;
    }

    void SetCreated(time_t value)
    {
        this->m_model.created = value;
    }

    void SetCustomIdInfo(StdExtra::optional<PFUserCustomIdInfoWrapper<Alloc>> value)
    {
        m_customIdInfo = std::move(value);
        this->m_model.customIdInfo = m_customIdInfo ? &m_customIdInfo->Model() : nullptr;
    }

    void SetFacebookInfo(StdExtra::optional<PFUserFacebookInfoWrapper<Alloc>> value)
    {
        m_facebookInfo = std::move(value);
        this->m_model.facebookInfo = m_facebookInfo ? &m_facebookInfo->Model() : nullptr;
    }

    void SetFacebookInstantGamesIdInfo(StdExtra::optional<PFUserFacebookInstantGamesIdInfoWrapper<Alloc>> value)
    {
        m_facebookInstantGamesIdInfo = std::move(value);
        this->m_model.facebookInstantGamesIdInfo = m_facebookInstantGamesIdInfo ? &m_facebookInstantGamesIdInfo->Model() : nullptr;
    }

    void SetGameCenterInfo(StdExtra::optional<PFUserGameCenterInfoWrapper<Alloc>> value)
    {
        m_gameCenterInfo = std::move(value);
        this->m_model.gameCenterInfo = m_gameCenterInfo ? &m_gameCenterInfo->Model() : nullptr;
    }

    void SetGoogleInfo(StdExtra::optional<PFUserGoogleInfoWrapper<Alloc>> value)
    {
        m_googleInfo = std::move(value);
        this->m_model.googleInfo = m_googleInfo ? &m_googleInfo->Model() : nullptr;
    }

    void SetIosDeviceInfo(StdExtra::optional<PFUserIosDeviceInfoWrapper<Alloc>> value)
    {
        m_iosDeviceInfo = std::move(value);
        this->m_model.iosDeviceInfo = m_iosDeviceInfo ? &m_iosDeviceInfo->Model() : nullptr;
    }

    void SetKongregateInfo(StdExtra::optional<PFUserKongregateInfoWrapper<Alloc>> value)
    {
        m_kongregateInfo = std::move(value);
        this->m_model.kongregateInfo = m_kongregateInfo ? &m_kongregateInfo->Model() : nullptr;
    }

    void SetNintendoSwitchAccountInfo(StdExtra::optional<PFUserNintendoSwitchAccountIdInfoWrapper<Alloc>> value)
    {
        m_nintendoSwitchAccountInfo = std::move(value);
        this->m_model.nintendoSwitchAccountInfo = m_nintendoSwitchAccountInfo ? &m_nintendoSwitchAccountInfo->Model() : nullptr;
    }

    void SetNintendoSwitchDeviceIdInfo(StdExtra::optional<PFUserNintendoSwitchDeviceIdInfoWrapper<Alloc>> value)
    {
        m_nintendoSwitchDeviceIdInfo = std::move(value);
        this->m_model.nintendoSwitchDeviceIdInfo = m_nintendoSwitchDeviceIdInfo ? &m_nintendoSwitchDeviceIdInfo->Model() : nullptr;
    }

    void SetOpenIdInfo(ModelVector<PFUserOpenIdInfoWrapper<Alloc>, Alloc> value)
    {
        m_openIdInfo = std::move(value);
        this->m_model.openIdInfo =  m_openIdInfo.empty() ? nullptr : m_openIdInfo.data();
        this->m_model.openIdInfoCount =  static_cast<uint32_t>(m_openIdInfo.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetPrivateInfo(StdExtra::optional<PFUserPrivateAccountInfoWrapper<Alloc>> value)
    {
        m_privateInfo = std::move(value);
        this->m_model.privateInfo = m_privateInfo ? &m_privateInfo->Model() : nullptr;
    }

    void SetPsnInfo(StdExtra::optional<PFUserPsnInfoWrapper<Alloc>> value)
    {
        m_psnInfo = std::move(value);
        this->m_model.psnInfo = m_psnInfo ? &m_psnInfo->Model() : nullptr;
    }

    void SetSteamInfo(StdExtra::optional<PFUserSteamInfoWrapper<Alloc>> value)
    {
        m_steamInfo = std::move(value);
        this->m_model.steamInfo = m_steamInfo ? &m_steamInfo->Model() : nullptr;
    }

    void SetTitleInfo(StdExtra::optional<PFUserTitleInfoWrapper<Alloc>> value)
    {
        m_titleInfo = std::move(value);
        this->m_model.titleInfo = m_titleInfo ? &m_titleInfo->Model() : nullptr;
    }

    void SetTwitchInfo(StdExtra::optional<PFUserTwitchInfoWrapper<Alloc>> value)
    {
        m_twitchInfo = std::move(value);
        this->m_model.twitchInfo = m_twitchInfo ? &m_twitchInfo->Model() : nullptr;
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

    void SetXboxInfo(StdExtra::optional<PFUserXboxInfoWrapper<Alloc>> value)
    {
        m_xboxInfo = std::move(value);
        this->m_model.xboxInfo = m_xboxInfo ? &m_xboxInfo->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.androidDeviceInfo = m_androidDeviceInfo ?  &m_androidDeviceInfo->Model() : nullptr;
        this->m_model.appleAccountInfo = m_appleAccountInfo ?  &m_appleAccountInfo->Model() : nullptr;
        this->m_model.customIdInfo = m_customIdInfo ?  &m_customIdInfo->Model() : nullptr;
        this->m_model.facebookInfo = m_facebookInfo ?  &m_facebookInfo->Model() : nullptr;
        this->m_model.facebookInstantGamesIdInfo = m_facebookInstantGamesIdInfo ?  &m_facebookInstantGamesIdInfo->Model() : nullptr;
        this->m_model.gameCenterInfo = m_gameCenterInfo ?  &m_gameCenterInfo->Model() : nullptr;
        this->m_model.googleInfo = m_googleInfo ?  &m_googleInfo->Model() : nullptr;
        this->m_model.iosDeviceInfo = m_iosDeviceInfo ?  &m_iosDeviceInfo->Model() : nullptr;
        this->m_model.kongregateInfo = m_kongregateInfo ?  &m_kongregateInfo->Model() : nullptr;
        this->m_model.nintendoSwitchAccountInfo = m_nintendoSwitchAccountInfo ?  &m_nintendoSwitchAccountInfo->Model() : nullptr;
        this->m_model.nintendoSwitchDeviceIdInfo = m_nintendoSwitchDeviceIdInfo ?  &m_nintendoSwitchDeviceIdInfo->Model() : nullptr;
        this->m_model.openIdInfo = m_openIdInfo.empty() ? nullptr : m_openIdInfo.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.privateInfo = m_privateInfo ?  &m_privateInfo->Model() : nullptr;
        this->m_model.psnInfo = m_psnInfo ?  &m_psnInfo->Model() : nullptr;
        this->m_model.steamInfo = m_steamInfo ?  &m_steamInfo->Model() : nullptr;
        this->m_model.titleInfo = m_titleInfo ?  &m_titleInfo->Model() : nullptr;
        this->m_model.twitchInfo = m_twitchInfo ?  &m_twitchInfo->Model() : nullptr;
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
        this->m_model.xboxInfo = m_xboxInfo ?  &m_xboxInfo->Model() : nullptr;
    }

    StdExtra::optional<PFUserAndroidDeviceInfoWrapper<Alloc>> m_androidDeviceInfo;
    StdExtra::optional<PFUserAppleIdInfoWrapper<Alloc>> m_appleAccountInfo;
    StdExtra::optional<PFUserCustomIdInfoWrapper<Alloc>> m_customIdInfo;
    StdExtra::optional<PFUserFacebookInfoWrapper<Alloc>> m_facebookInfo;
    StdExtra::optional<PFUserFacebookInstantGamesIdInfoWrapper<Alloc>> m_facebookInstantGamesIdInfo;
    StdExtra::optional<PFUserGameCenterInfoWrapper<Alloc>> m_gameCenterInfo;
    StdExtra::optional<PFUserGoogleInfoWrapper<Alloc>> m_googleInfo;
    StdExtra::optional<PFUserIosDeviceInfoWrapper<Alloc>> m_iosDeviceInfo;
    StdExtra::optional<PFUserKongregateInfoWrapper<Alloc>> m_kongregateInfo;
    StdExtra::optional<PFUserNintendoSwitchAccountIdInfoWrapper<Alloc>> m_nintendoSwitchAccountInfo;
    StdExtra::optional<PFUserNintendoSwitchDeviceIdInfoWrapper<Alloc>> m_nintendoSwitchDeviceIdInfo;
    ModelVector<PFUserOpenIdInfoWrapper<Alloc>, Alloc> m_openIdInfo;
    String m_playFabId;
    StdExtra::optional<PFUserPrivateAccountInfoWrapper<Alloc>> m_privateInfo;
    StdExtra::optional<PFUserPsnInfoWrapper<Alloc>> m_psnInfo;
    StdExtra::optional<PFUserSteamInfoWrapper<Alloc>> m_steamInfo;
    StdExtra::optional<PFUserTitleInfoWrapper<Alloc>> m_titleInfo;
    StdExtra::optional<PFUserTwitchInfoWrapper<Alloc>> m_twitchInfo;
    String m_username;
    StdExtra::optional<PFUserXboxInfoWrapper<Alloc>> m_xboxInfo;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCharacterInventoryWrapper : public ModelWrapper<PFCharacterInventory, Alloc>
{
public:
    using ModelType = typename PFCharacterInventory;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCharacterInventoryWrapper() = default;

    PFCharacterInventoryWrapper(const PFCharacterInventory& model) :
        ModelWrapper<PFCharacterInventory, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_inventory{ model.inventory, model.inventory + model.inventoryCount }
    {
        SetModelPointers();
    }

    PFCharacterInventoryWrapper(const PFCharacterInventoryWrapper& src) :
        PFCharacterInventoryWrapper{ src.Model() }
    {
    }

    PFCharacterInventoryWrapper(PFCharacterInventoryWrapper&& src) :
        PFCharacterInventoryWrapper{}
    {
        swap(*this, src);
    }

    PFCharacterInventoryWrapper& operator=(PFCharacterInventoryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCharacterInventoryWrapper() = default;

    friend void swap(PFCharacterInventoryWrapper& lhs, PFCharacterInventoryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_inventory, rhs.m_inventory);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetInventory(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_inventory = std::move(value);
        this->m_model.inventory =  m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.inventoryCount =  static_cast<uint32_t>(m_inventory.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.inventory = m_inventory.empty() ? nullptr : m_inventory.data();
    }

    String m_characterId;
    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_inventory;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGetPlayerCombinedInfoResultPayloadWrapper : public ModelWrapper<PFGetPlayerCombinedInfoResultPayload, Alloc>
{
public:
    using ModelType = typename PFGetPlayerCombinedInfoResultPayload;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGetPlayerCombinedInfoResultPayloadWrapper() = default;

    PFGetPlayerCombinedInfoResultPayloadWrapper(const PFGetPlayerCombinedInfoResultPayload& model) :
        ModelWrapper<PFGetPlayerCombinedInfoResultPayload, Alloc>{ model },
        m_accountInfo{ model.accountInfo ? StdExtra::optional<PFUserAccountInfoWrapper<Alloc>>{ *model.accountInfo } : StdExtra::nullopt },
        m_characterInventories{ model.characterInventories, model.characterInventories + model.characterInventoriesCount },
        m_characterList{ model.characterList, model.characterList + model.characterListCount },
        m_playerProfile{ model.playerProfile ? StdExtra::optional<PFPlayerProfileModelWrapper<Alloc>>{ *model.playerProfile } : StdExtra::nullopt },
        m_playerStatistics{ model.playerStatistics, model.playerStatistics + model.playerStatisticsCount },
        m_titleData{ model.titleData, model.titleData + model.titleDataCount },
        m_userData{ model.userData, model.userData + model.userDataCount },
        m_userInventory{ model.userInventory, model.userInventory + model.userInventoryCount },
        m_userReadOnlyData{ model.userReadOnlyData, model.userReadOnlyData + model.userReadOnlyDataCount },
        m_userVirtualCurrency{ model.userVirtualCurrency, model.userVirtualCurrency + model.userVirtualCurrencyCount },
        m_userVirtualCurrencyRechargeTimes{ model.userVirtualCurrencyRechargeTimes, model.userVirtualCurrencyRechargeTimes + model.userVirtualCurrencyRechargeTimesCount }
    {
        SetModelPointers();
    }

    PFGetPlayerCombinedInfoResultPayloadWrapper(const PFGetPlayerCombinedInfoResultPayloadWrapper& src) :
        PFGetPlayerCombinedInfoResultPayloadWrapper{ src.Model() }
    {
    }

    PFGetPlayerCombinedInfoResultPayloadWrapper(PFGetPlayerCombinedInfoResultPayloadWrapper&& src) :
        PFGetPlayerCombinedInfoResultPayloadWrapper{}
    {
        swap(*this, src);
    }

    PFGetPlayerCombinedInfoResultPayloadWrapper& operator=(PFGetPlayerCombinedInfoResultPayloadWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGetPlayerCombinedInfoResultPayloadWrapper() = default;

    friend void swap(PFGetPlayerCombinedInfoResultPayloadWrapper& lhs, PFGetPlayerCombinedInfoResultPayloadWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_accountInfo, rhs.m_accountInfo);
        swap(lhs.m_characterInventories, rhs.m_characterInventories);
        swap(lhs.m_characterList, rhs.m_characterList);
        swap(lhs.m_playerProfile, rhs.m_playerProfile);
        swap(lhs.m_playerStatistics, rhs.m_playerStatistics);
        swap(lhs.m_titleData, rhs.m_titleData);
        swap(lhs.m_userData, rhs.m_userData);
        swap(lhs.m_userInventory, rhs.m_userInventory);
        swap(lhs.m_userReadOnlyData, rhs.m_userReadOnlyData);
        swap(lhs.m_userVirtualCurrency, rhs.m_userVirtualCurrency);
        swap(lhs.m_userVirtualCurrencyRechargeTimes, rhs.m_userVirtualCurrencyRechargeTimes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAccountInfo(StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> value)
    {
        m_accountInfo = std::move(value);
        this->m_model.accountInfo = m_accountInfo ? &m_accountInfo->Model() : nullptr;
    }

    void SetCharacterInventories(ModelVector<PFCharacterInventoryWrapper<Alloc>, Alloc> value)
    {
        m_characterInventories = std::move(value);
        this->m_model.characterInventories =  m_characterInventories.empty() ? nullptr : m_characterInventories.data();
        this->m_model.characterInventoriesCount =  static_cast<uint32_t>(m_characterInventories.size());
    }

    void SetCharacterList(ModelVector<PFCharacterResultWrapper<Alloc>, Alloc> value)
    {
        m_characterList = std::move(value);
        this->m_model.characterList =  m_characterList.empty() ? nullptr : m_characterList.data();
        this->m_model.characterListCount =  static_cast<uint32_t>(m_characterList.size());
    }

    void SetPlayerProfile(StdExtra::optional<PFPlayerProfileModelWrapper<Alloc>> value)
    {
        m_playerProfile = std::move(value);
        this->m_model.playerProfile = m_playerProfile ? &m_playerProfile->Model() : nullptr;
    }

    void SetPlayerStatistics(ModelVector<PFStatisticValueWrapper<Alloc>, Alloc> value)
    {
        m_playerStatistics = std::move(value);
        this->m_model.playerStatistics =  m_playerStatistics.empty() ? nullptr : m_playerStatistics.data();
        this->m_model.playerStatisticsCount =  static_cast<uint32_t>(m_playerStatistics.size());
    }

    void SetTitleData(StringDictionaryEntryVector<Alloc> value)
    {
        m_titleData = std::move(value);
        this->m_model.titleData =  m_titleData.empty() ? nullptr : m_titleData.data();
        this->m_model.titleDataCount =  static_cast<uint32_t>(m_titleData.size());
    }

    void SetUserData(ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> value)
    {
        m_userData = std::move(value);
        this->m_model.userData =  m_userData.empty() ? nullptr : m_userData.data();
        this->m_model.userDataCount =  static_cast<uint32_t>(m_userData.size());
    }

    void SetUserDataVersion(uint32_t value)
    {
        this->m_model.userDataVersion = value;
    }

    void SetUserInventory(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_userInventory = std::move(value);
        this->m_model.userInventory =  m_userInventory.empty() ? nullptr : m_userInventory.data();
        this->m_model.userInventoryCount =  static_cast<uint32_t>(m_userInventory.size());
    }

    void SetUserReadOnlyData(ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> value)
    {
        m_userReadOnlyData = std::move(value);
        this->m_model.userReadOnlyData =  m_userReadOnlyData.empty() ? nullptr : m_userReadOnlyData.data();
        this->m_model.userReadOnlyDataCount =  static_cast<uint32_t>(m_userReadOnlyData.size());
    }

    void SetUserReadOnlyDataVersion(uint32_t value)
    {
        this->m_model.userReadOnlyDataVersion = value;
    }

    void SetUserVirtualCurrency(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_userVirtualCurrency = std::move(value);
        this->m_model.userVirtualCurrency =  m_userVirtualCurrency.empty() ? nullptr : m_userVirtualCurrency.data();
        this->m_model.userVirtualCurrencyCount =  static_cast<uint32_t>(m_userVirtualCurrency.size());
    }

    void SetUserVirtualCurrencyRechargeTimes(ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> value)
    {
        m_userVirtualCurrencyRechargeTimes = std::move(value);
        this->m_model.userVirtualCurrencyRechargeTimes =  m_userVirtualCurrencyRechargeTimes.empty() ? nullptr : m_userVirtualCurrencyRechargeTimes.data();
        this->m_model.userVirtualCurrencyRechargeTimesCount =  static_cast<uint32_t>(m_userVirtualCurrencyRechargeTimes.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.accountInfo = m_accountInfo ?  &m_accountInfo->Model() : nullptr;
        this->m_model.characterInventories = m_characterInventories.empty() ? nullptr : m_characterInventories.data();
        this->m_model.characterList = m_characterList.empty() ? nullptr : m_characterList.data();
        this->m_model.playerProfile = m_playerProfile ?  &m_playerProfile->Model() : nullptr;
        this->m_model.playerStatistics = m_playerStatistics.empty() ? nullptr : m_playerStatistics.data();
        this->m_model.titleData = m_titleData.empty() ? nullptr : m_titleData.data();
        this->m_model.userData = m_userData.empty() ? nullptr : m_userData.data();
        this->m_model.userInventory = m_userInventory.empty() ? nullptr : m_userInventory.data();
        this->m_model.userReadOnlyData = m_userReadOnlyData.empty() ? nullptr : m_userReadOnlyData.data();
        this->m_model.userVirtualCurrency = m_userVirtualCurrency.empty() ? nullptr : m_userVirtualCurrency.data();
        this->m_model.userVirtualCurrencyRechargeTimes = m_userVirtualCurrencyRechargeTimes.empty() ? nullptr : m_userVirtualCurrencyRechargeTimes.data();
    }

    StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> m_accountInfo;
    ModelVector<PFCharacterInventoryWrapper<Alloc>, Alloc> m_characterInventories;
    ModelVector<PFCharacterResultWrapper<Alloc>, Alloc> m_characterList;
    StdExtra::optional<PFPlayerProfileModelWrapper<Alloc>> m_playerProfile;
    ModelVector<PFStatisticValueWrapper<Alloc>, Alloc> m_playerStatistics;
    StringDictionaryEntryVector<Alloc> m_titleData;
    ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> m_userData;
    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_userInventory;
    ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> m_userReadOnlyData;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_userVirtualCurrency;
    ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> m_userVirtualCurrencyRechargeTimes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGetPlayerCombinedInfoRequestWrapper : public ModelWrapper<PFGetPlayerCombinedInfoRequest, Alloc>
{
public:
    using ModelType = typename PFGetPlayerCombinedInfoRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGetPlayerCombinedInfoRequestWrapper() = default;

    PFGetPlayerCombinedInfoRequestWrapper(const PFGetPlayerCombinedInfoRequest& model) :
        ModelWrapper<PFGetPlayerCombinedInfoRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? *model.infoRequestParameters : decltype(*model.infoRequestParameters){} },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFGetPlayerCombinedInfoRequestWrapper(const PFGetPlayerCombinedInfoRequestWrapper& src) :
        PFGetPlayerCombinedInfoRequestWrapper{ src.Model() }
    {
    }

    PFGetPlayerCombinedInfoRequestWrapper(PFGetPlayerCombinedInfoRequestWrapper&& src) :
        PFGetPlayerCombinedInfoRequestWrapper{}
    {
        swap(*this, src);
    }

    PFGetPlayerCombinedInfoRequestWrapper& operator=(PFGetPlayerCombinedInfoRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGetPlayerCombinedInfoRequestWrapper() = default;

    friend void swap(PFGetPlayerCombinedInfoRequestWrapper& lhs, PFGetPlayerCombinedInfoRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
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

    void SetInfoRequestParameters(PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = &m_infoRequestParameters.Model();
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
        this->m_model.infoRequestParameters = &m_infoRequestParameters.Model();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc> m_infoRequestParameters;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGetPlayerCombinedInfoResultWrapper : public ModelWrapper<PFGetPlayerCombinedInfoResult, Alloc>
{
public:
    using ModelType = typename PFGetPlayerCombinedInfoResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGetPlayerCombinedInfoResultWrapper() = default;

    PFGetPlayerCombinedInfoResultWrapper(const PFGetPlayerCombinedInfoResult& model) :
        ModelWrapper<PFGetPlayerCombinedInfoResult, Alloc>{ model },
        m_infoResultPayload{ model.infoResultPayload ? StdExtra::optional<PFGetPlayerCombinedInfoResultPayloadWrapper<Alloc>>{ *model.infoResultPayload } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFGetPlayerCombinedInfoResultWrapper(const PFGetPlayerCombinedInfoResultWrapper& src) :
        PFGetPlayerCombinedInfoResultWrapper{ src.Model() }
    {
    }

    PFGetPlayerCombinedInfoResultWrapper(PFGetPlayerCombinedInfoResultWrapper&& src) :
        PFGetPlayerCombinedInfoResultWrapper{}
    {
        swap(*this, src);
    }

    PFGetPlayerCombinedInfoResultWrapper& operator=(PFGetPlayerCombinedInfoResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGetPlayerCombinedInfoResultWrapper() = default;

    friend void swap(PFGetPlayerCombinedInfoResultWrapper& lhs, PFGetPlayerCombinedInfoResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_infoResultPayload, rhs.m_infoResultPayload);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetInfoResultPayload(StdExtra::optional<PFGetPlayerCombinedInfoResultPayloadWrapper<Alloc>> value)
    {
        m_infoResultPayload = std::move(value);
        this->m_model.infoResultPayload = m_infoResultPayload ? &m_infoResultPayload->Model() : nullptr;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.infoResultPayload = m_infoResultPayload ?  &m_infoResultPayload->Model() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StdExtra::optional<PFGetPlayerCombinedInfoResultPayloadWrapper<Alloc>> m_infoResultPayload;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFResultTableNodeWrapper : public ModelWrapper<PFResultTableNode, Alloc>
{
public:
    using ModelType = typename PFResultTableNode;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFResultTableNodeWrapper() = default;

    PFResultTableNodeWrapper(const PFResultTableNode& model) :
        ModelWrapper<PFResultTableNode, Alloc>{ model },
        m_resultItem{ SafeString(model.resultItem) }
    {
        SetModelPointers();
    }

    PFResultTableNodeWrapper(const PFResultTableNodeWrapper& src) :
        PFResultTableNodeWrapper{ src.Model() }
    {
    }

    PFResultTableNodeWrapper(PFResultTableNodeWrapper&& src) :
        PFResultTableNodeWrapper{}
    {
        swap(*this, src);
    }

    PFResultTableNodeWrapper& operator=(PFResultTableNodeWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFResultTableNodeWrapper() = default;

    friend void swap(PFResultTableNodeWrapper& lhs, PFResultTableNodeWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_resultItem, rhs.m_resultItem);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetResultItem(String value)
    {
        m_resultItem = std::move(value);
        this->m_model.resultItem =  m_resultItem.empty() ? nullptr : m_resultItem.data();
    }

    void SetResultItemType(PFResultTableNodeType value)
    {
        this->m_model.resultItemType = value;
    }

    void SetWeight(int32_t value)
    {
        this->m_model.weight = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.resultItem = m_resultItem.empty() ? nullptr : m_resultItem.data();
    }

    String m_resultItem;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFRandomResultTableListingWrapper : public ModelWrapper<PFRandomResultTableListing, Alloc>
{
public:
    using ModelType = typename PFRandomResultTableListing;
    using DictionaryEntryType = typename PFRandomResultTableListingDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFRandomResultTableListingWrapper() = default;

    PFRandomResultTableListingWrapper(const PFRandomResultTableListing& model) :
        ModelWrapper<PFRandomResultTableListing, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_nodes{ model.nodes, model.nodes + model.nodesCount },
        m_tableId{ SafeString(model.tableId) }
    {
        SetModelPointers();
    }

    PFRandomResultTableListingWrapper(const PFRandomResultTableListingWrapper& src) :
        PFRandomResultTableListingWrapper{ src.Model() }
    {
    }

    PFRandomResultTableListingWrapper(PFRandomResultTableListingWrapper&& src) :
        PFRandomResultTableListingWrapper{}
    {
        swap(*this, src);
    }

    PFRandomResultTableListingWrapper& operator=(PFRandomResultTableListingWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFRandomResultTableListingWrapper() = default;

    friend void swap(PFRandomResultTableListingWrapper& lhs, PFRandomResultTableListingWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_nodes, rhs.m_nodes);
        swap(lhs.m_tableId, rhs.m_tableId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetNodes(ModelVector<PFResultTableNodeWrapper<Alloc>, Alloc> value)
    {
        m_nodes = std::move(value);
        this->m_model.nodes =  m_nodes.empty() ? nullptr : m_nodes.data();
        this->m_model.nodesCount =  static_cast<uint32_t>(m_nodes.size());
    }

    void SetTableId(String value)
    {
        m_tableId = std::move(value);
        this->m_model.tableId =  m_tableId.empty() ? nullptr : m_tableId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.nodes = m_nodes.empty() ? nullptr : m_nodes.data();
        this->m_model.tableId = m_tableId.empty() ? nullptr : m_tableId.data();
    }

    String m_catalogVersion;
    ModelVector<PFResultTableNodeWrapper<Alloc>, Alloc> m_nodes;
    String m_tableId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGetRandomResultTablesResultWrapper : public ModelWrapper<PFGetRandomResultTablesResult, Alloc>
{
public:
    using ModelType = typename PFGetRandomResultTablesResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGetRandomResultTablesResultWrapper() = default;

    PFGetRandomResultTablesResultWrapper(const PFGetRandomResultTablesResult& model) :
        ModelWrapper<PFGetRandomResultTablesResult, Alloc>{ model },
        m_tables{ model.tables, model.tables + model.tablesCount }
    {
        SetModelPointers();
    }

    PFGetRandomResultTablesResultWrapper(const PFGetRandomResultTablesResultWrapper& src) :
        PFGetRandomResultTablesResultWrapper{ src.Model() }
    {
    }

    PFGetRandomResultTablesResultWrapper(PFGetRandomResultTablesResultWrapper&& src) :
        PFGetRandomResultTablesResultWrapper{}
    {
        swap(*this, src);
    }

    PFGetRandomResultTablesResultWrapper& operator=(PFGetRandomResultTablesResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGetRandomResultTablesResultWrapper() = default;

    friend void swap(PFGetRandomResultTablesResultWrapper& lhs, PFGetRandomResultTablesResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_tables, rhs.m_tables);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTables(ModelDictionaryEntryVector<PFRandomResultTableListingWrapper<Alloc>, Alloc> value)
    {
        m_tables = std::move(value);
        this->m_model.tables =  m_tables.empty() ? nullptr : m_tables.data();
        this->m_model.tablesCount =  static_cast<uint32_t>(m_tables.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.tables = m_tables.empty() ? nullptr : m_tables.data();
    }

    ModelDictionaryEntryVector<PFRandomResultTableListingWrapper<Alloc>, Alloc> m_tables;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAzureResourceSystemDataWrapper : public ModelWrapper<PFAzureResourceSystemData, Alloc>
{
public:
    using ModelType = typename PFAzureResourceSystemData;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAzureResourceSystemDataWrapper() = default;

    PFAzureResourceSystemDataWrapper(const PFAzureResourceSystemData& model) :
        ModelWrapper<PFAzureResourceSystemData, Alloc>{ model },
        m_createdAt{ model.createdAt ? StdExtra::optional<time_t>{ *model.createdAt } : StdExtra::nullopt },
        m_createdBy{ SafeString(model.createdBy) },
        m_createdByType{ SafeString(model.createdByType) },
        m_lastModifiedAt{ model.lastModifiedAt ? StdExtra::optional<time_t>{ *model.lastModifiedAt } : StdExtra::nullopt },
        m_lastModifiedBy{ SafeString(model.lastModifiedBy) },
        m_lastModifiedByType{ SafeString(model.lastModifiedByType) }
    {
        SetModelPointers();
    }

    PFAzureResourceSystemDataWrapper(const PFAzureResourceSystemDataWrapper& src) :
        PFAzureResourceSystemDataWrapper{ src.Model() }
    {
    }

    PFAzureResourceSystemDataWrapper(PFAzureResourceSystemDataWrapper&& src) :
        PFAzureResourceSystemDataWrapper{}
    {
        swap(*this, src);
    }

    PFAzureResourceSystemDataWrapper& operator=(PFAzureResourceSystemDataWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAzureResourceSystemDataWrapper() = default;

    friend void swap(PFAzureResourceSystemDataWrapper& lhs, PFAzureResourceSystemDataWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_createdAt, rhs.m_createdAt);
        swap(lhs.m_createdBy, rhs.m_createdBy);
        swap(lhs.m_createdByType, rhs.m_createdByType);
        swap(lhs.m_lastModifiedAt, rhs.m_lastModifiedAt);
        swap(lhs.m_lastModifiedBy, rhs.m_lastModifiedBy);
        swap(lhs.m_lastModifiedByType, rhs.m_lastModifiedByType);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreatedAt(StdExtra::optional<time_t> value)
    {
        m_createdAt = std::move(value);
        this->m_model.createdAt = m_createdAt ? m_createdAt.operator->() : nullptr;
    }

    void SetCreatedBy(String value)
    {
        m_createdBy = std::move(value);
        this->m_model.createdBy =  m_createdBy.empty() ? nullptr : m_createdBy.data();
    }

    void SetCreatedByType(String value)
    {
        m_createdByType = std::move(value);
        this->m_model.createdByType =  m_createdByType.empty() ? nullptr : m_createdByType.data();
    }

    void SetLastModifiedAt(StdExtra::optional<time_t> value)
    {
        m_lastModifiedAt = std::move(value);
        this->m_model.lastModifiedAt = m_lastModifiedAt ? m_lastModifiedAt.operator->() : nullptr;
    }

    void SetLastModifiedBy(String value)
    {
        m_lastModifiedBy = std::move(value);
        this->m_model.lastModifiedBy =  m_lastModifiedBy.empty() ? nullptr : m_lastModifiedBy.data();
    }

    void SetLastModifiedByType(String value)
    {
        m_lastModifiedByType = std::move(value);
        this->m_model.lastModifiedByType =  m_lastModifiedByType.empty() ? nullptr : m_lastModifiedByType.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.createdAt = m_createdAt ? m_createdAt.operator->() : nullptr;
        this->m_model.createdBy = m_createdBy.empty() ? nullptr : m_createdBy.data();
        this->m_model.createdByType = m_createdByType.empty() ? nullptr : m_createdByType.data();
        this->m_model.lastModifiedAt = m_lastModifiedAt ? m_lastModifiedAt.operator->() : nullptr;
        this->m_model.lastModifiedBy = m_lastModifiedBy.empty() ? nullptr : m_lastModifiedBy.data();
        this->m_model.lastModifiedByType = m_lastModifiedByType.empty() ? nullptr : m_lastModifiedByType.data();
    }

    StdExtra::optional<time_t> m_createdAt;
    String m_createdBy;
    String m_createdByType;
    StdExtra::optional<time_t> m_lastModifiedAt;
    String m_lastModifiedBy;
    String m_lastModifiedByType;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFVariableWrapper : public ModelWrapper<PFVariable, Alloc>
{
public:
    using ModelType = typename PFVariable;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFVariableWrapper() = default;

    PFVariableWrapper(const PFVariable& model) :
        ModelWrapper<PFVariable, Alloc>{ model },
        m_name{ SafeString(model.name) },
        m_value{ SafeString(model.value) }
    {
        SetModelPointers();
    }

    PFVariableWrapper(const PFVariableWrapper& src) :
        PFVariableWrapper{ src.Model() }
    {
    }

    PFVariableWrapper(PFVariableWrapper&& src) :
        PFVariableWrapper{}
    {
        swap(*this, src);
    }

    PFVariableWrapper& operator=(PFVariableWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFVariableWrapper() = default;

    friend void swap(PFVariableWrapper& lhs, PFVariableWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_value, rhs.m_value);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetValue(String value)
    {
        m_value = std::move(value);
        this->m_model.value =  m_value.empty() ? nullptr : m_value.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.value = m_value.empty() ? nullptr : m_value.data();
    }

    String m_name;
    String m_value;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTreatmentAssignmentWrapper : public ModelWrapper<PFTreatmentAssignment, Alloc>
{
public:
    using ModelType = typename PFTreatmentAssignment;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTreatmentAssignmentWrapper() = default;

    PFTreatmentAssignmentWrapper(const PFTreatmentAssignment& model) :
        ModelWrapper<PFTreatmentAssignment, Alloc>{ model },
        m_variables{ model.variables, model.variables + model.variablesCount },
        m_variants{ model.variants, model.variants + model.variantsCount }
    {
        SetModelPointers();
    }

    PFTreatmentAssignmentWrapper(const PFTreatmentAssignmentWrapper& src) :
        PFTreatmentAssignmentWrapper{ src.Model() }
    {
    }

    PFTreatmentAssignmentWrapper(PFTreatmentAssignmentWrapper&& src) :
        PFTreatmentAssignmentWrapper{}
    {
        swap(*this, src);
    }

    PFTreatmentAssignmentWrapper& operator=(PFTreatmentAssignmentWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTreatmentAssignmentWrapper() = default;

    friend void swap(PFTreatmentAssignmentWrapper& lhs, PFTreatmentAssignmentWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_variables, rhs.m_variables);
        swap(lhs.m_variants, rhs.m_variants);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetVariables(ModelVector<PFVariableWrapper<Alloc>, Alloc> value)
    {
        m_variables = std::move(value);
        this->m_model.variables =  m_variables.empty() ? nullptr : m_variables.data();
        this->m_model.variablesCount =  static_cast<uint32_t>(m_variables.size());
    }

    void SetVariants(CStringVector<Alloc> value)
    {
        m_variants = std::move(value);
        this->m_model.variants =  m_variants.empty() ? nullptr : m_variants.data();
        this->m_model.variantsCount =  static_cast<uint32_t>(m_variants.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.variables = m_variables.empty() ? nullptr : m_variables.data();
        this->m_model.variants = m_variants.empty() ? nullptr : m_variants.data();
    }

    ModelVector<PFVariableWrapper<Alloc>, Alloc> m_variables;
    CStringVector<Alloc> m_variants;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPortWrapper : public ModelWrapper<PFPort, Alloc>
{
public:
    using ModelType = typename PFPort;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPortWrapper() = default;

    PFPortWrapper(const PFPort& model) :
        ModelWrapper<PFPort, Alloc>{ model },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFPortWrapper(const PFPortWrapper& src) :
        PFPortWrapper{ src.Model() }
    {
    }

    PFPortWrapper(PFPortWrapper&& src) :
        PFPortWrapper{}
    {
        swap(*this, src);
    }

    PFPortWrapper& operator=(PFPortWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPortWrapper() = default;

    friend void swap(PFPortWrapper& lhs, PFPortWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetNum(int32_t value)
    {
        this->m_model.num = value;
    }

    void SetProtocol(PFProtocolType value)
    {
        this->m_model.protocol = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFEntityLineageWrapper : public ModelWrapper<PFEntityLineage, Alloc>
{
public:
    using ModelType = typename PFEntityLineage;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEntityLineageWrapper() = default;

    PFEntityLineageWrapper(const PFEntityLineage& model) :
        ModelWrapper<PFEntityLineage, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_groupId{ SafeString(model.groupId) },
        m_masterPlayerAccountId{ SafeString(model.masterPlayerAccountId) },
        m_namespaceId{ SafeString(model.namespaceId) },
        m_titleId{ SafeString(model.titleId) },
        m_titlePlayerAccountId{ SafeString(model.titlePlayerAccountId) }
    {
        SetModelPointers();
    }

    PFEntityLineageWrapper(const PFEntityLineageWrapper& src) :
        PFEntityLineageWrapper{ src.Model() }
    {
    }

    PFEntityLineageWrapper(PFEntityLineageWrapper&& src) :
        PFEntityLineageWrapper{}
    {
        swap(*this, src);
    }

    PFEntityLineageWrapper& operator=(PFEntityLineageWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEntityLineageWrapper() = default;

    friend void swap(PFEntityLineageWrapper& lhs, PFEntityLineageWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_groupId, rhs.m_groupId);
        swap(lhs.m_masterPlayerAccountId, rhs.m_masterPlayerAccountId);
        swap(lhs.m_namespaceId, rhs.m_namespaceId);
        swap(lhs.m_titleId, rhs.m_titleId);
        swap(lhs.m_titlePlayerAccountId, rhs.m_titlePlayerAccountId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetGroupId(String value)
    {
        m_groupId = std::move(value);
        this->m_model.groupId =  m_groupId.empty() ? nullptr : m_groupId.data();
    }

    void SetMasterPlayerAccountId(String value)
    {
        m_masterPlayerAccountId = std::move(value);
        this->m_model.masterPlayerAccountId =  m_masterPlayerAccountId.empty() ? nullptr : m_masterPlayerAccountId.data();
    }

    void SetNamespaceId(String value)
    {
        m_namespaceId = std::move(value);
        this->m_model.namespaceId =  m_namespaceId.empty() ? nullptr : m_namespaceId.data();
    }

    void SetTitleId(String value)
    {
        m_titleId = std::move(value);
        this->m_model.titleId =  m_titleId.empty() ? nullptr : m_titleId.data();
    }

    void SetTitlePlayerAccountId(String value)
    {
        m_titlePlayerAccountId = std::move(value);
        this->m_model.titlePlayerAccountId =  m_titlePlayerAccountId.empty() ? nullptr : m_titlePlayerAccountId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.groupId = m_groupId.empty() ? nullptr : m_groupId.data();
        this->m_model.masterPlayerAccountId = m_masterPlayerAccountId.empty() ? nullptr : m_masterPlayerAccountId.data();
        this->m_model.namespaceId = m_namespaceId.empty() ? nullptr : m_namespaceId.data();
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
        this->m_model.titlePlayerAccountId = m_titlePlayerAccountId.empty() ? nullptr : m_titlePlayerAccountId.data();
    }

    String m_characterId;
    String m_groupId;
    String m_masterPlayerAccountId;
    String m_namespaceId;
    String m_titleId;
    String m_titlePlayerAccountId;
};

} // namespace Wrappers
} // namespace PlayFab
