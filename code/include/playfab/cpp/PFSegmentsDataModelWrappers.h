// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFSegmentsDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsBanPlayerSegmentActionWrapper : public ModelWrapper<PFSegmentsBanPlayerSegmentAction, Alloc>
{
public:
    using ModelType = typename PFSegmentsBanPlayerSegmentAction;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsBanPlayerSegmentActionWrapper() = default;

    PFSegmentsBanPlayerSegmentActionWrapper(const PFSegmentsBanPlayerSegmentAction& model) :
        ModelWrapper<PFSegmentsBanPlayerSegmentAction, Alloc>{ model },
        m_banHours{ model.banHours ? StdExtra::optional<uint32_t>{ *model.banHours } : StdExtra::nullopt },
        m_reasonForBan{ SafeString(model.reasonForBan) }
    {
        SetModelPointers();
    }

    PFSegmentsBanPlayerSegmentActionWrapper(const PFSegmentsBanPlayerSegmentActionWrapper& src) :
        PFSegmentsBanPlayerSegmentActionWrapper{ src.Model() }
    {
    }

    PFSegmentsBanPlayerSegmentActionWrapper(PFSegmentsBanPlayerSegmentActionWrapper&& src) :
        PFSegmentsBanPlayerSegmentActionWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsBanPlayerSegmentActionWrapper& operator=(PFSegmentsBanPlayerSegmentActionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsBanPlayerSegmentActionWrapper() = default;

    friend void swap(PFSegmentsBanPlayerSegmentActionWrapper& lhs, PFSegmentsBanPlayerSegmentActionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_banHours, rhs.m_banHours);
        swap(lhs.m_reasonForBan, rhs.m_reasonForBan);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBanHours(StdExtra::optional<uint32_t> value)
    {
        m_banHours = std::move(value);
        this->m_model.banHours = m_banHours ? m_banHours.operator->() : nullptr;
    }

    void SetReasonForBan(String value)
    {
        m_reasonForBan = std::move(value);
        this->m_model.reasonForBan =  m_reasonForBan.empty() ? nullptr : m_reasonForBan.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.banHours = m_banHours ? m_banHours.operator->() : nullptr;
        this->m_model.reasonForBan = m_reasonForBan.empty() ? nullptr : m_reasonForBan.data();
    }

    StdExtra::optional<uint32_t> m_banHours;
    String m_reasonForBan;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsDeletePlayerStatisticSegmentActionWrapper : public ModelWrapper<PFSegmentsDeletePlayerStatisticSegmentAction, Alloc>
{
public:
    using ModelType = typename PFSegmentsDeletePlayerStatisticSegmentAction;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsDeletePlayerStatisticSegmentActionWrapper() = default;

    PFSegmentsDeletePlayerStatisticSegmentActionWrapper(const PFSegmentsDeletePlayerStatisticSegmentAction& model) :
        ModelWrapper<PFSegmentsDeletePlayerStatisticSegmentAction, Alloc>{ model },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFSegmentsDeletePlayerStatisticSegmentActionWrapper(const PFSegmentsDeletePlayerStatisticSegmentActionWrapper& src) :
        PFSegmentsDeletePlayerStatisticSegmentActionWrapper{ src.Model() }
    {
    }

    PFSegmentsDeletePlayerStatisticSegmentActionWrapper(PFSegmentsDeletePlayerStatisticSegmentActionWrapper&& src) :
        PFSegmentsDeletePlayerStatisticSegmentActionWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsDeletePlayerStatisticSegmentActionWrapper& operator=(PFSegmentsDeletePlayerStatisticSegmentActionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsDeletePlayerStatisticSegmentActionWrapper() = default;

    friend void swap(PFSegmentsDeletePlayerStatisticSegmentActionWrapper& lhs, PFSegmentsDeletePlayerStatisticSegmentActionWrapper& rhs)
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
class PFSegmentsEmailNotificationSegmentActionWrapper : public ModelWrapper<PFSegmentsEmailNotificationSegmentAction, Alloc>
{
public:
    using ModelType = typename PFSegmentsEmailNotificationSegmentAction;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsEmailNotificationSegmentActionWrapper() = default;

    PFSegmentsEmailNotificationSegmentActionWrapper(const PFSegmentsEmailNotificationSegmentAction& model) :
        ModelWrapper<PFSegmentsEmailNotificationSegmentAction, Alloc>{ model },
        m_emailTemplateId{ SafeString(model.emailTemplateId) },
        m_emailTemplateName{ SafeString(model.emailTemplateName) }
    {
        SetModelPointers();
    }

    PFSegmentsEmailNotificationSegmentActionWrapper(const PFSegmentsEmailNotificationSegmentActionWrapper& src) :
        PFSegmentsEmailNotificationSegmentActionWrapper{ src.Model() }
    {
    }

    PFSegmentsEmailNotificationSegmentActionWrapper(PFSegmentsEmailNotificationSegmentActionWrapper&& src) :
        PFSegmentsEmailNotificationSegmentActionWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsEmailNotificationSegmentActionWrapper& operator=(PFSegmentsEmailNotificationSegmentActionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsEmailNotificationSegmentActionWrapper() = default;

    friend void swap(PFSegmentsEmailNotificationSegmentActionWrapper& lhs, PFSegmentsEmailNotificationSegmentActionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_emailTemplateId, rhs.m_emailTemplateId);
        swap(lhs.m_emailTemplateName, rhs.m_emailTemplateName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEmailTemplateId(String value)
    {
        m_emailTemplateId = std::move(value);
        this->m_model.emailTemplateId =  m_emailTemplateId.empty() ? nullptr : m_emailTemplateId.data();
    }

    void SetEmailTemplateName(String value)
    {
        m_emailTemplateName = std::move(value);
        this->m_model.emailTemplateName =  m_emailTemplateName.empty() ? nullptr : m_emailTemplateName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.emailTemplateId = m_emailTemplateId.empty() ? nullptr : m_emailTemplateId.data();
        this->m_model.emailTemplateName = m_emailTemplateName.empty() ? nullptr : m_emailTemplateName.data();
    }

    String m_emailTemplateId;
    String m_emailTemplateName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsExecuteAzureFunctionSegmentActionWrapper : public ModelWrapper<PFSegmentsExecuteAzureFunctionSegmentAction, Alloc>
{
public:
    using ModelType = typename PFSegmentsExecuteAzureFunctionSegmentAction;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsExecuteAzureFunctionSegmentActionWrapper() = default;

    PFSegmentsExecuteAzureFunctionSegmentActionWrapper(const PFSegmentsExecuteAzureFunctionSegmentAction& model) :
        ModelWrapper<PFSegmentsExecuteAzureFunctionSegmentAction, Alloc>{ model },
        m_azureFunction{ SafeString(model.azureFunction) },
        m_functionParameter{ model.functionParameter }
    {
        SetModelPointers();
    }

    PFSegmentsExecuteAzureFunctionSegmentActionWrapper(const PFSegmentsExecuteAzureFunctionSegmentActionWrapper& src) :
        PFSegmentsExecuteAzureFunctionSegmentActionWrapper{ src.Model() }
    {
    }

    PFSegmentsExecuteAzureFunctionSegmentActionWrapper(PFSegmentsExecuteAzureFunctionSegmentActionWrapper&& src) :
        PFSegmentsExecuteAzureFunctionSegmentActionWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsExecuteAzureFunctionSegmentActionWrapper& operator=(PFSegmentsExecuteAzureFunctionSegmentActionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsExecuteAzureFunctionSegmentActionWrapper() = default;

    friend void swap(PFSegmentsExecuteAzureFunctionSegmentActionWrapper& lhs, PFSegmentsExecuteAzureFunctionSegmentActionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_azureFunction, rhs.m_azureFunction);
        swap(lhs.m_functionParameter, rhs.m_functionParameter);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAzureFunction(String value)
    {
        m_azureFunction = std::move(value);
        this->m_model.azureFunction =  m_azureFunction.empty() ? nullptr : m_azureFunction.data();
    }

    void SetFunctionParameter(JsonObject<Alloc> value)
    {
        m_functionParameter = std::move(value);
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
    }

    void SetGenerateFunctionExecutedEvents(bool value)
    {
        this->m_model.generateFunctionExecutedEvents = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.azureFunction = m_azureFunction.empty() ? nullptr : m_azureFunction.data();
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
    }

    String m_azureFunction;
    JsonObject<Alloc> m_functionParameter;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsExecuteCloudScriptSegmentActionWrapper : public ModelWrapper<PFSegmentsExecuteCloudScriptSegmentAction, Alloc>
{
public:
    using ModelType = typename PFSegmentsExecuteCloudScriptSegmentAction;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsExecuteCloudScriptSegmentActionWrapper() = default;

    PFSegmentsExecuteCloudScriptSegmentActionWrapper(const PFSegmentsExecuteCloudScriptSegmentAction& model) :
        ModelWrapper<PFSegmentsExecuteCloudScriptSegmentAction, Alloc>{ model },
        m_cloudScriptFunction{ SafeString(model.cloudScriptFunction) },
        m_functionParameter{ model.functionParameter },
        m_functionParameterJson{ SafeString(model.functionParameterJson) }
    {
        SetModelPointers();
    }

    PFSegmentsExecuteCloudScriptSegmentActionWrapper(const PFSegmentsExecuteCloudScriptSegmentActionWrapper& src) :
        PFSegmentsExecuteCloudScriptSegmentActionWrapper{ src.Model() }
    {
    }

    PFSegmentsExecuteCloudScriptSegmentActionWrapper(PFSegmentsExecuteCloudScriptSegmentActionWrapper&& src) :
        PFSegmentsExecuteCloudScriptSegmentActionWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsExecuteCloudScriptSegmentActionWrapper& operator=(PFSegmentsExecuteCloudScriptSegmentActionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsExecuteCloudScriptSegmentActionWrapper() = default;

    friend void swap(PFSegmentsExecuteCloudScriptSegmentActionWrapper& lhs, PFSegmentsExecuteCloudScriptSegmentActionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_cloudScriptFunction, rhs.m_cloudScriptFunction);
        swap(lhs.m_functionParameter, rhs.m_functionParameter);
        swap(lhs.m_functionParameterJson, rhs.m_functionParameterJson);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCloudScriptFunction(String value)
    {
        m_cloudScriptFunction = std::move(value);
        this->m_model.cloudScriptFunction =  m_cloudScriptFunction.empty() ? nullptr : m_cloudScriptFunction.data();
    }

    void SetCloudScriptPublishResultsToPlayStream(bool value)
    {
        this->m_model.cloudScriptPublishResultsToPlayStream = value;
    }

    void SetFunctionParameter(JsonObject<Alloc> value)
    {
        m_functionParameter = std::move(value);
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
    }

    void SetFunctionParameterJson(String value)
    {
        m_functionParameterJson = std::move(value);
        this->m_model.functionParameterJson =  m_functionParameterJson.empty() ? nullptr : m_functionParameterJson.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.cloudScriptFunction = m_cloudScriptFunction.empty() ? nullptr : m_cloudScriptFunction.data();
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
        this->m_model.functionParameterJson = m_functionParameterJson.empty() ? nullptr : m_functionParameterJson.data();
    }

    String m_cloudScriptFunction;
    JsonObject<Alloc> m_functionParameter;
    String m_functionParameterJson;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsGrantItemSegmentActionWrapper : public ModelWrapper<PFSegmentsGrantItemSegmentAction, Alloc>
{
public:
    using ModelType = typename PFSegmentsGrantItemSegmentAction;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsGrantItemSegmentActionWrapper() = default;

    PFSegmentsGrantItemSegmentActionWrapper(const PFSegmentsGrantItemSegmentAction& model) :
        ModelWrapper<PFSegmentsGrantItemSegmentAction, Alloc>{ model },
        m_catelogId{ SafeString(model.catelogId) },
        m_itemId{ SafeString(model.itemId) }
    {
        SetModelPointers();
    }

    PFSegmentsGrantItemSegmentActionWrapper(const PFSegmentsGrantItemSegmentActionWrapper& src) :
        PFSegmentsGrantItemSegmentActionWrapper{ src.Model() }
    {
    }

    PFSegmentsGrantItemSegmentActionWrapper(PFSegmentsGrantItemSegmentActionWrapper&& src) :
        PFSegmentsGrantItemSegmentActionWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsGrantItemSegmentActionWrapper& operator=(PFSegmentsGrantItemSegmentActionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsGrantItemSegmentActionWrapper() = default;

    friend void swap(PFSegmentsGrantItemSegmentActionWrapper& lhs, PFSegmentsGrantItemSegmentActionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catelogId, rhs.m_catelogId);
        swap(lhs.m_itemId, rhs.m_itemId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatelogId(String value)
    {
        m_catelogId = std::move(value);
        this->m_model.catelogId =  m_catelogId.empty() ? nullptr : m_catelogId.data();
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetQuantity(uint32_t value)
    {
        this->m_model.quantity = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.catelogId = m_catelogId.empty() ? nullptr : m_catelogId.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
    }

    String m_catelogId;
    String m_itemId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsGrantVirtualCurrencySegmentActionWrapper : public ModelWrapper<PFSegmentsGrantVirtualCurrencySegmentAction, Alloc>
{
public:
    using ModelType = typename PFSegmentsGrantVirtualCurrencySegmentAction;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsGrantVirtualCurrencySegmentActionWrapper() = default;

    PFSegmentsGrantVirtualCurrencySegmentActionWrapper(const PFSegmentsGrantVirtualCurrencySegmentAction& model) :
        ModelWrapper<PFSegmentsGrantVirtualCurrencySegmentAction, Alloc>{ model },
        m_currencyCode{ SafeString(model.currencyCode) }
    {
        SetModelPointers();
    }

    PFSegmentsGrantVirtualCurrencySegmentActionWrapper(const PFSegmentsGrantVirtualCurrencySegmentActionWrapper& src) :
        PFSegmentsGrantVirtualCurrencySegmentActionWrapper{ src.Model() }
    {
    }

    PFSegmentsGrantVirtualCurrencySegmentActionWrapper(PFSegmentsGrantVirtualCurrencySegmentActionWrapper&& src) :
        PFSegmentsGrantVirtualCurrencySegmentActionWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsGrantVirtualCurrencySegmentActionWrapper& operator=(PFSegmentsGrantVirtualCurrencySegmentActionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsGrantVirtualCurrencySegmentActionWrapper() = default;

    friend void swap(PFSegmentsGrantVirtualCurrencySegmentActionWrapper& lhs, PFSegmentsGrantVirtualCurrencySegmentActionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_currencyCode, rhs.m_currencyCode);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
    }

    void SetCurrencyCode(String value)
    {
        m_currencyCode = std::move(value);
        this->m_model.currencyCode =  m_currencyCode.empty() ? nullptr : m_currencyCode.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.currencyCode = m_currencyCode.empty() ? nullptr : m_currencyCode.data();
    }

    String m_currencyCode;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsIncrementPlayerStatisticSegmentActionWrapper : public ModelWrapper<PFSegmentsIncrementPlayerStatisticSegmentAction, Alloc>
{
public:
    using ModelType = typename PFSegmentsIncrementPlayerStatisticSegmentAction;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsIncrementPlayerStatisticSegmentActionWrapper() = default;

    PFSegmentsIncrementPlayerStatisticSegmentActionWrapper(const PFSegmentsIncrementPlayerStatisticSegmentAction& model) :
        ModelWrapper<PFSegmentsIncrementPlayerStatisticSegmentAction, Alloc>{ model },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFSegmentsIncrementPlayerStatisticSegmentActionWrapper(const PFSegmentsIncrementPlayerStatisticSegmentActionWrapper& src) :
        PFSegmentsIncrementPlayerStatisticSegmentActionWrapper{ src.Model() }
    {
    }

    PFSegmentsIncrementPlayerStatisticSegmentActionWrapper(PFSegmentsIncrementPlayerStatisticSegmentActionWrapper&& src) :
        PFSegmentsIncrementPlayerStatisticSegmentActionWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsIncrementPlayerStatisticSegmentActionWrapper& operator=(PFSegmentsIncrementPlayerStatisticSegmentActionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsIncrementPlayerStatisticSegmentActionWrapper() = default;

    friend void swap(PFSegmentsIncrementPlayerStatisticSegmentActionWrapper& lhs, PFSegmentsIncrementPlayerStatisticSegmentActionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIncrementValue(int32_t value)
    {
        this->m_model.incrementValue = value;
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
class PFSegmentsPushNotificationSegmentActionWrapper : public ModelWrapper<PFSegmentsPushNotificationSegmentAction, Alloc>
{
public:
    using ModelType = typename PFSegmentsPushNotificationSegmentAction;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsPushNotificationSegmentActionWrapper() = default;

    PFSegmentsPushNotificationSegmentActionWrapper(const PFSegmentsPushNotificationSegmentAction& model) :
        ModelWrapper<PFSegmentsPushNotificationSegmentAction, Alloc>{ model },
        m_pushNotificationTemplateId{ SafeString(model.pushNotificationTemplateId) }
    {
        SetModelPointers();
    }

    PFSegmentsPushNotificationSegmentActionWrapper(const PFSegmentsPushNotificationSegmentActionWrapper& src) :
        PFSegmentsPushNotificationSegmentActionWrapper{ src.Model() }
    {
    }

    PFSegmentsPushNotificationSegmentActionWrapper(PFSegmentsPushNotificationSegmentActionWrapper&& src) :
        PFSegmentsPushNotificationSegmentActionWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsPushNotificationSegmentActionWrapper& operator=(PFSegmentsPushNotificationSegmentActionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsPushNotificationSegmentActionWrapper() = default;

    friend void swap(PFSegmentsPushNotificationSegmentActionWrapper& lhs, PFSegmentsPushNotificationSegmentActionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_pushNotificationTemplateId, rhs.m_pushNotificationTemplateId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPushNotificationTemplateId(String value)
    {
        m_pushNotificationTemplateId = std::move(value);
        this->m_model.pushNotificationTemplateId =  m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.pushNotificationTemplateId = m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

    String m_pushNotificationTemplateId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsSegmentTriggerWrapper : public ModelWrapper<PFSegmentsSegmentTrigger, Alloc>
{
public:
    using ModelType = typename PFSegmentsSegmentTrigger;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsSegmentTriggerWrapper() = default;

    PFSegmentsSegmentTriggerWrapper(const PFSegmentsSegmentTrigger& model) :
        ModelWrapper<PFSegmentsSegmentTrigger, Alloc>{ model },
        m_banPlayerAction{ model.banPlayerAction ? StdExtra::optional<PFSegmentsBanPlayerSegmentActionWrapper<Alloc>>{ *model.banPlayerAction } : StdExtra::nullopt },
        m_deletePlayerStatisticAction{ model.deletePlayerStatisticAction ? StdExtra::optional<PFSegmentsDeletePlayerStatisticSegmentActionWrapper<Alloc>>{ *model.deletePlayerStatisticAction } : StdExtra::nullopt },
        m_emailNotificationAction{ model.emailNotificationAction ? StdExtra::optional<PFSegmentsEmailNotificationSegmentActionWrapper<Alloc>>{ *model.emailNotificationAction } : StdExtra::nullopt },
        m_executeAzureFunctionAction{ model.executeAzureFunctionAction ? StdExtra::optional<PFSegmentsExecuteAzureFunctionSegmentActionWrapper<Alloc>>{ *model.executeAzureFunctionAction } : StdExtra::nullopt },
        m_executeCloudScriptAction{ model.executeCloudScriptAction ? StdExtra::optional<PFSegmentsExecuteCloudScriptSegmentActionWrapper<Alloc>>{ *model.executeCloudScriptAction } : StdExtra::nullopt },
        m_grantItemAction{ model.grantItemAction ? StdExtra::optional<PFSegmentsGrantItemSegmentActionWrapper<Alloc>>{ *model.grantItemAction } : StdExtra::nullopt },
        m_grantVirtualCurrencyAction{ model.grantVirtualCurrencyAction ? StdExtra::optional<PFSegmentsGrantVirtualCurrencySegmentActionWrapper<Alloc>>{ *model.grantVirtualCurrencyAction } : StdExtra::nullopt },
        m_incrementPlayerStatisticAction{ model.incrementPlayerStatisticAction ? StdExtra::optional<PFSegmentsIncrementPlayerStatisticSegmentActionWrapper<Alloc>>{ *model.incrementPlayerStatisticAction } : StdExtra::nullopt },
        m_pushNotificationAction{ model.pushNotificationAction ? StdExtra::optional<PFSegmentsPushNotificationSegmentActionWrapper<Alloc>>{ *model.pushNotificationAction } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsSegmentTriggerWrapper(const PFSegmentsSegmentTriggerWrapper& src) :
        PFSegmentsSegmentTriggerWrapper{ src.Model() }
    {
    }

    PFSegmentsSegmentTriggerWrapper(PFSegmentsSegmentTriggerWrapper&& src) :
        PFSegmentsSegmentTriggerWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsSegmentTriggerWrapper& operator=(PFSegmentsSegmentTriggerWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsSegmentTriggerWrapper() = default;

    friend void swap(PFSegmentsSegmentTriggerWrapper& lhs, PFSegmentsSegmentTriggerWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_banPlayerAction, rhs.m_banPlayerAction);
        swap(lhs.m_deletePlayerStatisticAction, rhs.m_deletePlayerStatisticAction);
        swap(lhs.m_emailNotificationAction, rhs.m_emailNotificationAction);
        swap(lhs.m_executeAzureFunctionAction, rhs.m_executeAzureFunctionAction);
        swap(lhs.m_executeCloudScriptAction, rhs.m_executeCloudScriptAction);
        swap(lhs.m_grantItemAction, rhs.m_grantItemAction);
        swap(lhs.m_grantVirtualCurrencyAction, rhs.m_grantVirtualCurrencyAction);
        swap(lhs.m_incrementPlayerStatisticAction, rhs.m_incrementPlayerStatisticAction);
        swap(lhs.m_pushNotificationAction, rhs.m_pushNotificationAction);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBanPlayerAction(StdExtra::optional<PFSegmentsBanPlayerSegmentActionWrapper<Alloc>> value)
    {
        m_banPlayerAction = std::move(value);
        this->m_model.banPlayerAction = m_banPlayerAction ? &m_banPlayerAction->Model() : nullptr;
    }

    void SetDeletePlayerStatisticAction(StdExtra::optional<PFSegmentsDeletePlayerStatisticSegmentActionWrapper<Alloc>> value)
    {
        m_deletePlayerStatisticAction = std::move(value);
        this->m_model.deletePlayerStatisticAction = m_deletePlayerStatisticAction ? &m_deletePlayerStatisticAction->Model() : nullptr;
    }

    void SetEmailNotificationAction(StdExtra::optional<PFSegmentsEmailNotificationSegmentActionWrapper<Alloc>> value)
    {
        m_emailNotificationAction = std::move(value);
        this->m_model.emailNotificationAction = m_emailNotificationAction ? &m_emailNotificationAction->Model() : nullptr;
    }

    void SetExecuteAzureFunctionAction(StdExtra::optional<PFSegmentsExecuteAzureFunctionSegmentActionWrapper<Alloc>> value)
    {
        m_executeAzureFunctionAction = std::move(value);
        this->m_model.executeAzureFunctionAction = m_executeAzureFunctionAction ? &m_executeAzureFunctionAction->Model() : nullptr;
    }

    void SetExecuteCloudScriptAction(StdExtra::optional<PFSegmentsExecuteCloudScriptSegmentActionWrapper<Alloc>> value)
    {
        m_executeCloudScriptAction = std::move(value);
        this->m_model.executeCloudScriptAction = m_executeCloudScriptAction ? &m_executeCloudScriptAction->Model() : nullptr;
    }

    void SetGrantItemAction(StdExtra::optional<PFSegmentsGrantItemSegmentActionWrapper<Alloc>> value)
    {
        m_grantItemAction = std::move(value);
        this->m_model.grantItemAction = m_grantItemAction ? &m_grantItemAction->Model() : nullptr;
    }

    void SetGrantVirtualCurrencyAction(StdExtra::optional<PFSegmentsGrantVirtualCurrencySegmentActionWrapper<Alloc>> value)
    {
        m_grantVirtualCurrencyAction = std::move(value);
        this->m_model.grantVirtualCurrencyAction = m_grantVirtualCurrencyAction ? &m_grantVirtualCurrencyAction->Model() : nullptr;
    }

    void SetIncrementPlayerStatisticAction(StdExtra::optional<PFSegmentsIncrementPlayerStatisticSegmentActionWrapper<Alloc>> value)
    {
        m_incrementPlayerStatisticAction = std::move(value);
        this->m_model.incrementPlayerStatisticAction = m_incrementPlayerStatisticAction ? &m_incrementPlayerStatisticAction->Model() : nullptr;
    }

    void SetPushNotificationAction(StdExtra::optional<PFSegmentsPushNotificationSegmentActionWrapper<Alloc>> value)
    {
        m_pushNotificationAction = std::move(value);
        this->m_model.pushNotificationAction = m_pushNotificationAction ? &m_pushNotificationAction->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.banPlayerAction = m_banPlayerAction ?  &m_banPlayerAction->Model() : nullptr;
        this->m_model.deletePlayerStatisticAction = m_deletePlayerStatisticAction ?  &m_deletePlayerStatisticAction->Model() : nullptr;
        this->m_model.emailNotificationAction = m_emailNotificationAction ?  &m_emailNotificationAction->Model() : nullptr;
        this->m_model.executeAzureFunctionAction = m_executeAzureFunctionAction ?  &m_executeAzureFunctionAction->Model() : nullptr;
        this->m_model.executeCloudScriptAction = m_executeCloudScriptAction ?  &m_executeCloudScriptAction->Model() : nullptr;
        this->m_model.grantItemAction = m_grantItemAction ?  &m_grantItemAction->Model() : nullptr;
        this->m_model.grantVirtualCurrencyAction = m_grantVirtualCurrencyAction ?  &m_grantVirtualCurrencyAction->Model() : nullptr;
        this->m_model.incrementPlayerStatisticAction = m_incrementPlayerStatisticAction ?  &m_incrementPlayerStatisticAction->Model() : nullptr;
        this->m_model.pushNotificationAction = m_pushNotificationAction ?  &m_pushNotificationAction->Model() : nullptr;
    }

    StdExtra::optional<PFSegmentsBanPlayerSegmentActionWrapper<Alloc>> m_banPlayerAction;
    StdExtra::optional<PFSegmentsDeletePlayerStatisticSegmentActionWrapper<Alloc>> m_deletePlayerStatisticAction;
    StdExtra::optional<PFSegmentsEmailNotificationSegmentActionWrapper<Alloc>> m_emailNotificationAction;
    StdExtra::optional<PFSegmentsExecuteAzureFunctionSegmentActionWrapper<Alloc>> m_executeAzureFunctionAction;
    StdExtra::optional<PFSegmentsExecuteCloudScriptSegmentActionWrapper<Alloc>> m_executeCloudScriptAction;
    StdExtra::optional<PFSegmentsGrantItemSegmentActionWrapper<Alloc>> m_grantItemAction;
    StdExtra::optional<PFSegmentsGrantVirtualCurrencySegmentActionWrapper<Alloc>> m_grantVirtualCurrencyAction;
    StdExtra::optional<PFSegmentsIncrementPlayerStatisticSegmentActionWrapper<Alloc>> m_incrementPlayerStatisticAction;
    StdExtra::optional<PFSegmentsPushNotificationSegmentActionWrapper<Alloc>> m_pushNotificationAction;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsAdCampaignSegmentFilterWrapper : public ModelWrapper<PFSegmentsAdCampaignSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsAdCampaignSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsAdCampaignSegmentFilterWrapper() = default;

    PFSegmentsAdCampaignSegmentFilterWrapper(const PFSegmentsAdCampaignSegmentFilter& model) :
        ModelWrapper<PFSegmentsAdCampaignSegmentFilter, Alloc>{ model },
        m_campaignId{ SafeString(model.campaignId) },
        m_campaignSource{ SafeString(model.campaignSource) },
        m_comparison{ model.comparison ? StdExtra::optional<PFSegmentsSegmentFilterComparison>{ *model.comparison } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsAdCampaignSegmentFilterWrapper(const PFSegmentsAdCampaignSegmentFilterWrapper& src) :
        PFSegmentsAdCampaignSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsAdCampaignSegmentFilterWrapper(PFSegmentsAdCampaignSegmentFilterWrapper&& src) :
        PFSegmentsAdCampaignSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsAdCampaignSegmentFilterWrapper& operator=(PFSegmentsAdCampaignSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsAdCampaignSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsAdCampaignSegmentFilterWrapper& lhs, PFSegmentsAdCampaignSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_campaignId, rhs.m_campaignId);
        swap(lhs.m_campaignSource, rhs.m_campaignSource);
        swap(lhs.m_comparison, rhs.m_comparison);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCampaignId(String value)
    {
        m_campaignId = std::move(value);
        this->m_model.campaignId =  m_campaignId.empty() ? nullptr : m_campaignId.data();
    }

    void SetCampaignSource(String value)
    {
        m_campaignSource = std::move(value);
        this->m_model.campaignSource =  m_campaignSource.empty() ? nullptr : m_campaignSource.data();
    }

    void SetComparison(StdExtra::optional<PFSegmentsSegmentFilterComparison> value)
    {
        m_comparison = std::move(value);
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.campaignId = m_campaignId.empty() ? nullptr : m_campaignId.data();
        this->m_model.campaignSource = m_campaignSource.empty() ? nullptr : m_campaignSource.data();
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    String m_campaignId;
    String m_campaignSource;
    StdExtra::optional<PFSegmentsSegmentFilterComparison> m_comparison;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsFirstLoginDateSegmentFilterWrapper : public ModelWrapper<PFSegmentsFirstLoginDateSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsFirstLoginDateSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsFirstLoginDateSegmentFilterWrapper() = default;

    PFSegmentsFirstLoginDateSegmentFilterWrapper(const PFSegmentsFirstLoginDateSegmentFilter& model) :
        ModelWrapper<PFSegmentsFirstLoginDateSegmentFilter, Alloc>{ model },
        m_comparison{ model.comparison ? StdExtra::optional<PFSegmentsSegmentFilterComparison>{ *model.comparison } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsFirstLoginDateSegmentFilterWrapper(const PFSegmentsFirstLoginDateSegmentFilterWrapper& src) :
        PFSegmentsFirstLoginDateSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsFirstLoginDateSegmentFilterWrapper(PFSegmentsFirstLoginDateSegmentFilterWrapper&& src) :
        PFSegmentsFirstLoginDateSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsFirstLoginDateSegmentFilterWrapper& operator=(PFSegmentsFirstLoginDateSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsFirstLoginDateSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsFirstLoginDateSegmentFilterWrapper& lhs, PFSegmentsFirstLoginDateSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_comparison, rhs.m_comparison);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetComparison(StdExtra::optional<PFSegmentsSegmentFilterComparison> value)
    {
        m_comparison = std::move(value);
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    void SetLogInDate(time_t value)
    {
        this->m_model.logInDate = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    StdExtra::optional<PFSegmentsSegmentFilterComparison> m_comparison;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsFirstLoginTimespanSegmentFilterWrapper : public ModelWrapper<PFSegmentsFirstLoginTimespanSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsFirstLoginTimespanSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsFirstLoginTimespanSegmentFilterWrapper() = default;

    PFSegmentsFirstLoginTimespanSegmentFilterWrapper(const PFSegmentsFirstLoginTimespanSegmentFilter& model) :
        ModelWrapper<PFSegmentsFirstLoginTimespanSegmentFilter, Alloc>{ model },
        m_comparison{ model.comparison ? StdExtra::optional<PFSegmentsSegmentFilterComparison>{ *model.comparison } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsFirstLoginTimespanSegmentFilterWrapper(const PFSegmentsFirstLoginTimespanSegmentFilterWrapper& src) :
        PFSegmentsFirstLoginTimespanSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsFirstLoginTimespanSegmentFilterWrapper(PFSegmentsFirstLoginTimespanSegmentFilterWrapper&& src) :
        PFSegmentsFirstLoginTimespanSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsFirstLoginTimespanSegmentFilterWrapper& operator=(PFSegmentsFirstLoginTimespanSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsFirstLoginTimespanSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsFirstLoginTimespanSegmentFilterWrapper& lhs, PFSegmentsFirstLoginTimespanSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_comparison, rhs.m_comparison);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetComparison(StdExtra::optional<PFSegmentsSegmentFilterComparison> value)
    {
        m_comparison = std::move(value);
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    void SetDurationInMinutes(double value)
    {
        this->m_model.durationInMinutes = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    StdExtra::optional<PFSegmentsSegmentFilterComparison> m_comparison;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsLastLoginDateSegmentFilterWrapper : public ModelWrapper<PFSegmentsLastLoginDateSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsLastLoginDateSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsLastLoginDateSegmentFilterWrapper() = default;

    PFSegmentsLastLoginDateSegmentFilterWrapper(const PFSegmentsLastLoginDateSegmentFilter& model) :
        ModelWrapper<PFSegmentsLastLoginDateSegmentFilter, Alloc>{ model },
        m_comparison{ model.comparison ? StdExtra::optional<PFSegmentsSegmentFilterComparison>{ *model.comparison } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsLastLoginDateSegmentFilterWrapper(const PFSegmentsLastLoginDateSegmentFilterWrapper& src) :
        PFSegmentsLastLoginDateSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsLastLoginDateSegmentFilterWrapper(PFSegmentsLastLoginDateSegmentFilterWrapper&& src) :
        PFSegmentsLastLoginDateSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsLastLoginDateSegmentFilterWrapper& operator=(PFSegmentsLastLoginDateSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsLastLoginDateSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsLastLoginDateSegmentFilterWrapper& lhs, PFSegmentsLastLoginDateSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_comparison, rhs.m_comparison);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetComparison(StdExtra::optional<PFSegmentsSegmentFilterComparison> value)
    {
        m_comparison = std::move(value);
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    void SetLogInDate(time_t value)
    {
        this->m_model.logInDate = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    StdExtra::optional<PFSegmentsSegmentFilterComparison> m_comparison;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsLastLoginTimespanSegmentFilterWrapper : public ModelWrapper<PFSegmentsLastLoginTimespanSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsLastLoginTimespanSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsLastLoginTimespanSegmentFilterWrapper() = default;

    PFSegmentsLastLoginTimespanSegmentFilterWrapper(const PFSegmentsLastLoginTimespanSegmentFilter& model) :
        ModelWrapper<PFSegmentsLastLoginTimespanSegmentFilter, Alloc>{ model },
        m_comparison{ model.comparison ? StdExtra::optional<PFSegmentsSegmentFilterComparison>{ *model.comparison } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsLastLoginTimespanSegmentFilterWrapper(const PFSegmentsLastLoginTimespanSegmentFilterWrapper& src) :
        PFSegmentsLastLoginTimespanSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsLastLoginTimespanSegmentFilterWrapper(PFSegmentsLastLoginTimespanSegmentFilterWrapper&& src) :
        PFSegmentsLastLoginTimespanSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsLastLoginTimespanSegmentFilterWrapper& operator=(PFSegmentsLastLoginTimespanSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsLastLoginTimespanSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsLastLoginTimespanSegmentFilterWrapper& lhs, PFSegmentsLastLoginTimespanSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_comparison, rhs.m_comparison);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetComparison(StdExtra::optional<PFSegmentsSegmentFilterComparison> value)
    {
        m_comparison = std::move(value);
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    void SetDurationInMinutes(double value)
    {
        this->m_model.durationInMinutes = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    StdExtra::optional<PFSegmentsSegmentFilterComparison> m_comparison;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsLinkedUserAccountSegmentFilterWrapper : public ModelWrapper<PFSegmentsLinkedUserAccountSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsLinkedUserAccountSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsLinkedUserAccountSegmentFilterWrapper() = default;

    PFSegmentsLinkedUserAccountSegmentFilterWrapper(const PFSegmentsLinkedUserAccountSegmentFilter& model) :
        ModelWrapper<PFSegmentsLinkedUserAccountSegmentFilter, Alloc>{ model },
        m_loginProvider{ model.loginProvider ? StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider>{ *model.loginProvider } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsLinkedUserAccountSegmentFilterWrapper(const PFSegmentsLinkedUserAccountSegmentFilterWrapper& src) :
        PFSegmentsLinkedUserAccountSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsLinkedUserAccountSegmentFilterWrapper(PFSegmentsLinkedUserAccountSegmentFilterWrapper&& src) :
        PFSegmentsLinkedUserAccountSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsLinkedUserAccountSegmentFilterWrapper& operator=(PFSegmentsLinkedUserAccountSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsLinkedUserAccountSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsLinkedUserAccountSegmentFilterWrapper& lhs, PFSegmentsLinkedUserAccountSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_loginProvider, rhs.m_loginProvider);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLoginProvider(StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider> value)
    {
        m_loginProvider = std::move(value);
        this->m_model.loginProvider = m_loginProvider ? m_loginProvider.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.loginProvider = m_loginProvider ? m_loginProvider.operator->() : nullptr;
    }

    StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider> m_loginProvider;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper : public ModelWrapper<PFSegmentsLinkedUserAccountHasEmailSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsLinkedUserAccountHasEmailSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper() = default;

    PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper(const PFSegmentsLinkedUserAccountHasEmailSegmentFilter& model) :
        ModelWrapper<PFSegmentsLinkedUserAccountHasEmailSegmentFilter, Alloc>{ model },
        m_comparison{ model.comparison ? StdExtra::optional<PFSegmentsSegmentFilterComparison>{ *model.comparison } : StdExtra::nullopt },
        m_loginProvider{ model.loginProvider ? StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider>{ *model.loginProvider } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper(const PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper& src) :
        PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper(PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper&& src) :
        PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper& operator=(PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper& lhs, PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_comparison, rhs.m_comparison);
        swap(lhs.m_loginProvider, rhs.m_loginProvider);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetComparison(StdExtra::optional<PFSegmentsSegmentFilterComparison> value)
    {
        m_comparison = std::move(value);
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    void SetLoginProvider(StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider> value)
    {
        m_loginProvider = std::move(value);
        this->m_model.loginProvider = m_loginProvider ? m_loginProvider.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
        this->m_model.loginProvider = m_loginProvider ? m_loginProvider.operator->() : nullptr;
    }

    StdExtra::optional<PFSegmentsSegmentFilterComparison> m_comparison;
    StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider> m_loginProvider;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsLocationSegmentFilterWrapper : public ModelWrapper<PFSegmentsLocationSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsLocationSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsLocationSegmentFilterWrapper() = default;

    PFSegmentsLocationSegmentFilterWrapper(const PFSegmentsLocationSegmentFilter& model) :
        ModelWrapper<PFSegmentsLocationSegmentFilter, Alloc>{ model },
        m_countryCode{ model.countryCode ? StdExtra::optional<PFSegmentsSegmentCountryCode>{ *model.countryCode } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsLocationSegmentFilterWrapper(const PFSegmentsLocationSegmentFilterWrapper& src) :
        PFSegmentsLocationSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsLocationSegmentFilterWrapper(PFSegmentsLocationSegmentFilterWrapper&& src) :
        PFSegmentsLocationSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsLocationSegmentFilterWrapper& operator=(PFSegmentsLocationSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsLocationSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsLocationSegmentFilterWrapper& lhs, PFSegmentsLocationSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_countryCode, rhs.m_countryCode);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCountryCode(StdExtra::optional<PFSegmentsSegmentCountryCode> value)
    {
        m_countryCode = std::move(value);
        this->m_model.countryCode = m_countryCode ? m_countryCode.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.countryCode = m_countryCode ? m_countryCode.operator->() : nullptr;
    }

    StdExtra::optional<PFSegmentsSegmentCountryCode> m_countryCode;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsPushNotificationSegmentFilterWrapper : public ModelWrapper<PFSegmentsPushNotificationSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsPushNotificationSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsPushNotificationSegmentFilterWrapper() = default;

    PFSegmentsPushNotificationSegmentFilterWrapper(const PFSegmentsPushNotificationSegmentFilter& model) :
        ModelWrapper<PFSegmentsPushNotificationSegmentFilter, Alloc>{ model },
        m_pushNotificationDevicePlatform{ model.pushNotificationDevicePlatform ? StdExtra::optional<PFSegmentsSegmentPushNotificationDevicePlatform>{ *model.pushNotificationDevicePlatform } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsPushNotificationSegmentFilterWrapper(const PFSegmentsPushNotificationSegmentFilterWrapper& src) :
        PFSegmentsPushNotificationSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsPushNotificationSegmentFilterWrapper(PFSegmentsPushNotificationSegmentFilterWrapper&& src) :
        PFSegmentsPushNotificationSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsPushNotificationSegmentFilterWrapper& operator=(PFSegmentsPushNotificationSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsPushNotificationSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsPushNotificationSegmentFilterWrapper& lhs, PFSegmentsPushNotificationSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_pushNotificationDevicePlatform, rhs.m_pushNotificationDevicePlatform);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPushNotificationDevicePlatform(StdExtra::optional<PFSegmentsSegmentPushNotificationDevicePlatform> value)
    {
        m_pushNotificationDevicePlatform = std::move(value);
        this->m_model.pushNotificationDevicePlatform = m_pushNotificationDevicePlatform ? m_pushNotificationDevicePlatform.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.pushNotificationDevicePlatform = m_pushNotificationDevicePlatform ? m_pushNotificationDevicePlatform.operator->() : nullptr;
    }

    StdExtra::optional<PFSegmentsSegmentPushNotificationDevicePlatform> m_pushNotificationDevicePlatform;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsStatisticSegmentFilterWrapper : public ModelWrapper<PFSegmentsStatisticSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsStatisticSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsStatisticSegmentFilterWrapper() = default;

    PFSegmentsStatisticSegmentFilterWrapper(const PFSegmentsStatisticSegmentFilter& model) :
        ModelWrapper<PFSegmentsStatisticSegmentFilter, Alloc>{ model },
        m_comparison{ model.comparison ? StdExtra::optional<PFSegmentsSegmentFilterComparison>{ *model.comparison } : StdExtra::nullopt },
        m_filterValue{ SafeString(model.filterValue) },
        m_name{ SafeString(model.name) },
        m_useCurrentVersion{ model.useCurrentVersion ? StdExtra::optional<bool>{ *model.useCurrentVersion } : StdExtra::nullopt },
        m_version{ model.version ? StdExtra::optional<int32_t>{ *model.version } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsStatisticSegmentFilterWrapper(const PFSegmentsStatisticSegmentFilterWrapper& src) :
        PFSegmentsStatisticSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsStatisticSegmentFilterWrapper(PFSegmentsStatisticSegmentFilterWrapper&& src) :
        PFSegmentsStatisticSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsStatisticSegmentFilterWrapper& operator=(PFSegmentsStatisticSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsStatisticSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsStatisticSegmentFilterWrapper& lhs, PFSegmentsStatisticSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_comparison, rhs.m_comparison);
        swap(lhs.m_filterValue, rhs.m_filterValue);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_useCurrentVersion, rhs.m_useCurrentVersion);
        swap(lhs.m_version, rhs.m_version);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetComparison(StdExtra::optional<PFSegmentsSegmentFilterComparison> value)
    {
        m_comparison = std::move(value);
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    void SetFilterValue(String value)
    {
        m_filterValue = std::move(value);
        this->m_model.filterValue =  m_filterValue.empty() ? nullptr : m_filterValue.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetUseCurrentVersion(StdExtra::optional<bool> value)
    {
        m_useCurrentVersion = std::move(value);
        this->m_model.useCurrentVersion = m_useCurrentVersion ? m_useCurrentVersion.operator->() : nullptr;
    }

    void SetVersion(StdExtra::optional<int32_t> value)
    {
        m_version = std::move(value);
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
        this->m_model.filterValue = m_filterValue.empty() ? nullptr : m_filterValue.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.useCurrentVersion = m_useCurrentVersion ? m_useCurrentVersion.operator->() : nullptr;
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

    StdExtra::optional<PFSegmentsSegmentFilterComparison> m_comparison;
    String m_filterValue;
    String m_name;
    StdExtra::optional<bool> m_useCurrentVersion;
    StdExtra::optional<int32_t> m_version;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsTagSegmentFilterWrapper : public ModelWrapper<PFSegmentsTagSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsTagSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsTagSegmentFilterWrapper() = default;

    PFSegmentsTagSegmentFilterWrapper(const PFSegmentsTagSegmentFilter& model) :
        ModelWrapper<PFSegmentsTagSegmentFilter, Alloc>{ model },
        m_comparison{ model.comparison ? StdExtra::optional<PFSegmentsSegmentFilterComparison>{ *model.comparison } : StdExtra::nullopt },
        m_tagValue{ SafeString(model.tagValue) }
    {
        SetModelPointers();
    }

    PFSegmentsTagSegmentFilterWrapper(const PFSegmentsTagSegmentFilterWrapper& src) :
        PFSegmentsTagSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsTagSegmentFilterWrapper(PFSegmentsTagSegmentFilterWrapper&& src) :
        PFSegmentsTagSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsTagSegmentFilterWrapper& operator=(PFSegmentsTagSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsTagSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsTagSegmentFilterWrapper& lhs, PFSegmentsTagSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_comparison, rhs.m_comparison);
        swap(lhs.m_tagValue, rhs.m_tagValue);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetComparison(StdExtra::optional<PFSegmentsSegmentFilterComparison> value)
    {
        m_comparison = std::move(value);
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    void SetTagValue(String value)
    {
        m_tagValue = std::move(value);
        this->m_model.tagValue =  m_tagValue.empty() ? nullptr : m_tagValue.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
        this->m_model.tagValue = m_tagValue.empty() ? nullptr : m_tagValue.data();
    }

    StdExtra::optional<PFSegmentsSegmentFilterComparison> m_comparison;
    String m_tagValue;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper : public ModelWrapper<PFSegmentsTotalValueToDateInUSDSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsTotalValueToDateInUSDSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper() = default;

    PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper(const PFSegmentsTotalValueToDateInUSDSegmentFilter& model) :
        ModelWrapper<PFSegmentsTotalValueToDateInUSDSegmentFilter, Alloc>{ model },
        m_amount{ SafeString(model.amount) },
        m_comparison{ model.comparison ? StdExtra::optional<PFSegmentsSegmentFilterComparison>{ *model.comparison } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper(const PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper& src) :
        PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper(PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper&& src) :
        PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper& operator=(PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper& lhs, PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_amount, rhs.m_amount);
        swap(lhs.m_comparison, rhs.m_comparison);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(String value)
    {
        m_amount = std::move(value);
        this->m_model.amount =  m_amount.empty() ? nullptr : m_amount.data();
    }

    void SetComparison(StdExtra::optional<PFSegmentsSegmentFilterComparison> value)
    {
        m_comparison = std::move(value);
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.amount = m_amount.empty() ? nullptr : m_amount.data();
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    String m_amount;
    StdExtra::optional<PFSegmentsSegmentFilterComparison> m_comparison;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsUserOriginationSegmentFilterWrapper : public ModelWrapper<PFSegmentsUserOriginationSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsUserOriginationSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsUserOriginationSegmentFilterWrapper() = default;

    PFSegmentsUserOriginationSegmentFilterWrapper(const PFSegmentsUserOriginationSegmentFilter& model) :
        ModelWrapper<PFSegmentsUserOriginationSegmentFilter, Alloc>{ model },
        m_loginProvider{ model.loginProvider ? StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider>{ *model.loginProvider } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsUserOriginationSegmentFilterWrapper(const PFSegmentsUserOriginationSegmentFilterWrapper& src) :
        PFSegmentsUserOriginationSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsUserOriginationSegmentFilterWrapper(PFSegmentsUserOriginationSegmentFilterWrapper&& src) :
        PFSegmentsUserOriginationSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsUserOriginationSegmentFilterWrapper& operator=(PFSegmentsUserOriginationSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsUserOriginationSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsUserOriginationSegmentFilterWrapper& lhs, PFSegmentsUserOriginationSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_loginProvider, rhs.m_loginProvider);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLoginProvider(StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider> value)
    {
        m_loginProvider = std::move(value);
        this->m_model.loginProvider = m_loginProvider ? m_loginProvider.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.loginProvider = m_loginProvider ? m_loginProvider.operator->() : nullptr;
    }

    StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider> m_loginProvider;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsValueToDateSegmentFilterWrapper : public ModelWrapper<PFSegmentsValueToDateSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsValueToDateSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsValueToDateSegmentFilterWrapper() = default;

    PFSegmentsValueToDateSegmentFilterWrapper(const PFSegmentsValueToDateSegmentFilter& model) :
        ModelWrapper<PFSegmentsValueToDateSegmentFilter, Alloc>{ model },
        m_amount{ SafeString(model.amount) },
        m_comparison{ model.comparison ? StdExtra::optional<PFSegmentsSegmentFilterComparison>{ *model.comparison } : StdExtra::nullopt },
        m_currency{ model.currency ? StdExtra::optional<PFSegmentsSegmentCurrency>{ *model.currency } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsValueToDateSegmentFilterWrapper(const PFSegmentsValueToDateSegmentFilterWrapper& src) :
        PFSegmentsValueToDateSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsValueToDateSegmentFilterWrapper(PFSegmentsValueToDateSegmentFilterWrapper&& src) :
        PFSegmentsValueToDateSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsValueToDateSegmentFilterWrapper& operator=(PFSegmentsValueToDateSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsValueToDateSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsValueToDateSegmentFilterWrapper& lhs, PFSegmentsValueToDateSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_amount, rhs.m_amount);
        swap(lhs.m_comparison, rhs.m_comparison);
        swap(lhs.m_currency, rhs.m_currency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(String value)
    {
        m_amount = std::move(value);
        this->m_model.amount =  m_amount.empty() ? nullptr : m_amount.data();
    }

    void SetComparison(StdExtra::optional<PFSegmentsSegmentFilterComparison> value)
    {
        m_comparison = std::move(value);
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    void SetCurrency(StdExtra::optional<PFSegmentsSegmentCurrency> value)
    {
        m_currency = std::move(value);
        this->m_model.currency = m_currency ? m_currency.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.amount = m_amount.empty() ? nullptr : m_amount.data();
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
        this->m_model.currency = m_currency ? m_currency.operator->() : nullptr;
    }

    String m_amount;
    StdExtra::optional<PFSegmentsSegmentFilterComparison> m_comparison;
    StdExtra::optional<PFSegmentsSegmentCurrency> m_currency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper : public ModelWrapper<PFSegmentsVirtualCurrencyBalanceSegmentFilter, Alloc>
{
public:
    using ModelType = typename PFSegmentsVirtualCurrencyBalanceSegmentFilter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper() = default;

    PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper(const PFSegmentsVirtualCurrencyBalanceSegmentFilter& model) :
        ModelWrapper<PFSegmentsVirtualCurrencyBalanceSegmentFilter, Alloc>{ model },
        m_comparison{ model.comparison ? StdExtra::optional<PFSegmentsSegmentFilterComparison>{ *model.comparison } : StdExtra::nullopt },
        m_currencyCode{ SafeString(model.currencyCode) }
    {
        SetModelPointers();
    }

    PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper(const PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper& src) :
        PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper{ src.Model() }
    {
    }

    PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper(PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper&& src) :
        PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper& operator=(PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper() = default;

    friend void swap(PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper& lhs, PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_comparison, rhs.m_comparison);
        swap(lhs.m_currencyCode, rhs.m_currencyCode);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
    }

    void SetComparison(StdExtra::optional<PFSegmentsSegmentFilterComparison> value)
    {
        m_comparison = std::move(value);
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
    }

    void SetCurrencyCode(String value)
    {
        m_currencyCode = std::move(value);
        this->m_model.currencyCode =  m_currencyCode.empty() ? nullptr : m_currencyCode.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.comparison = m_comparison ? m_comparison.operator->() : nullptr;
        this->m_model.currencyCode = m_currencyCode.empty() ? nullptr : m_currencyCode.data();
    }

    StdExtra::optional<PFSegmentsSegmentFilterComparison> m_comparison;
    String m_currencyCode;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsSegmentAndDefinitionWrapper : public ModelWrapper<PFSegmentsSegmentAndDefinition, Alloc>
{
public:
    using ModelType = typename PFSegmentsSegmentAndDefinition;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsSegmentAndDefinitionWrapper() = default;

    PFSegmentsSegmentAndDefinitionWrapper(const PFSegmentsSegmentAndDefinition& model) :
        ModelWrapper<PFSegmentsSegmentAndDefinition, Alloc>{ model },
        m_adCampaignFilter{ model.adCampaignFilter ? StdExtra::optional<PFSegmentsAdCampaignSegmentFilterWrapper<Alloc>>{ *model.adCampaignFilter } : StdExtra::nullopt },
        m_firstLoginDateFilter{ model.firstLoginDateFilter ? StdExtra::optional<PFSegmentsFirstLoginDateSegmentFilterWrapper<Alloc>>{ *model.firstLoginDateFilter } : StdExtra::nullopt },
        m_firstLoginFilter{ model.firstLoginFilter ? StdExtra::optional<PFSegmentsFirstLoginTimespanSegmentFilterWrapper<Alloc>>{ *model.firstLoginFilter } : StdExtra::nullopt },
        m_lastLoginDateFilter{ model.lastLoginDateFilter ? StdExtra::optional<PFSegmentsLastLoginDateSegmentFilterWrapper<Alloc>>{ *model.lastLoginDateFilter } : StdExtra::nullopt },
        m_lastLoginFilter{ model.lastLoginFilter ? StdExtra::optional<PFSegmentsLastLoginTimespanSegmentFilterWrapper<Alloc>>{ *model.lastLoginFilter } : StdExtra::nullopt },
        m_linkedUserAccountFilter{ model.linkedUserAccountFilter ? StdExtra::optional<PFSegmentsLinkedUserAccountSegmentFilterWrapper<Alloc>>{ *model.linkedUserAccountFilter } : StdExtra::nullopt },
        m_linkedUserAccountHasEmailFilter{ model.linkedUserAccountHasEmailFilter ? StdExtra::optional<PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper<Alloc>>{ *model.linkedUserAccountHasEmailFilter } : StdExtra::nullopt },
        m_locationFilter{ model.locationFilter ? StdExtra::optional<PFSegmentsLocationSegmentFilterWrapper<Alloc>>{ *model.locationFilter } : StdExtra::nullopt },
        m_pushNotificationFilter{ model.pushNotificationFilter ? StdExtra::optional<PFSegmentsPushNotificationSegmentFilterWrapper<Alloc>>{ *model.pushNotificationFilter } : StdExtra::nullopt },
        m_statisticFilter{ model.statisticFilter ? StdExtra::optional<PFSegmentsStatisticSegmentFilterWrapper<Alloc>>{ *model.statisticFilter } : StdExtra::nullopt },
        m_tagFilter{ model.tagFilter ? StdExtra::optional<PFSegmentsTagSegmentFilterWrapper<Alloc>>{ *model.tagFilter } : StdExtra::nullopt },
        m_totalValueToDateInUSDFilter{ model.totalValueToDateInUSDFilter ? StdExtra::optional<PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper<Alloc>>{ *model.totalValueToDateInUSDFilter } : StdExtra::nullopt },
        m_userOriginationFilter{ model.userOriginationFilter ? StdExtra::optional<PFSegmentsUserOriginationSegmentFilterWrapper<Alloc>>{ *model.userOriginationFilter } : StdExtra::nullopt },
        m_valueToDateFilter{ model.valueToDateFilter ? StdExtra::optional<PFSegmentsValueToDateSegmentFilterWrapper<Alloc>>{ *model.valueToDateFilter } : StdExtra::nullopt },
        m_virtualCurrencyBalanceFilter{ model.virtualCurrencyBalanceFilter ? StdExtra::optional<PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper<Alloc>>{ *model.virtualCurrencyBalanceFilter } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFSegmentsSegmentAndDefinitionWrapper(const PFSegmentsSegmentAndDefinitionWrapper& src) :
        PFSegmentsSegmentAndDefinitionWrapper{ src.Model() }
    {
    }

    PFSegmentsSegmentAndDefinitionWrapper(PFSegmentsSegmentAndDefinitionWrapper&& src) :
        PFSegmentsSegmentAndDefinitionWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsSegmentAndDefinitionWrapper& operator=(PFSegmentsSegmentAndDefinitionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsSegmentAndDefinitionWrapper() = default;

    friend void swap(PFSegmentsSegmentAndDefinitionWrapper& lhs, PFSegmentsSegmentAndDefinitionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_adCampaignFilter, rhs.m_adCampaignFilter);
        swap(lhs.m_firstLoginDateFilter, rhs.m_firstLoginDateFilter);
        swap(lhs.m_firstLoginFilter, rhs.m_firstLoginFilter);
        swap(lhs.m_lastLoginDateFilter, rhs.m_lastLoginDateFilter);
        swap(lhs.m_lastLoginFilter, rhs.m_lastLoginFilter);
        swap(lhs.m_linkedUserAccountFilter, rhs.m_linkedUserAccountFilter);
        swap(lhs.m_linkedUserAccountHasEmailFilter, rhs.m_linkedUserAccountHasEmailFilter);
        swap(lhs.m_locationFilter, rhs.m_locationFilter);
        swap(lhs.m_pushNotificationFilter, rhs.m_pushNotificationFilter);
        swap(lhs.m_statisticFilter, rhs.m_statisticFilter);
        swap(lhs.m_tagFilter, rhs.m_tagFilter);
        swap(lhs.m_totalValueToDateInUSDFilter, rhs.m_totalValueToDateInUSDFilter);
        swap(lhs.m_userOriginationFilter, rhs.m_userOriginationFilter);
        swap(lhs.m_valueToDateFilter, rhs.m_valueToDateFilter);
        swap(lhs.m_virtualCurrencyBalanceFilter, rhs.m_virtualCurrencyBalanceFilter);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAdCampaignFilter(StdExtra::optional<PFSegmentsAdCampaignSegmentFilterWrapper<Alloc>> value)
    {
        m_adCampaignFilter = std::move(value);
        this->m_model.adCampaignFilter = m_adCampaignFilter ? &m_adCampaignFilter->Model() : nullptr;
    }

    void SetFirstLoginDateFilter(StdExtra::optional<PFSegmentsFirstLoginDateSegmentFilterWrapper<Alloc>> value)
    {
        m_firstLoginDateFilter = std::move(value);
        this->m_model.firstLoginDateFilter = m_firstLoginDateFilter ? &m_firstLoginDateFilter->Model() : nullptr;
    }

    void SetFirstLoginFilter(StdExtra::optional<PFSegmentsFirstLoginTimespanSegmentFilterWrapper<Alloc>> value)
    {
        m_firstLoginFilter = std::move(value);
        this->m_model.firstLoginFilter = m_firstLoginFilter ? &m_firstLoginFilter->Model() : nullptr;
    }

    void SetLastLoginDateFilter(StdExtra::optional<PFSegmentsLastLoginDateSegmentFilterWrapper<Alloc>> value)
    {
        m_lastLoginDateFilter = std::move(value);
        this->m_model.lastLoginDateFilter = m_lastLoginDateFilter ? &m_lastLoginDateFilter->Model() : nullptr;
    }

    void SetLastLoginFilter(StdExtra::optional<PFSegmentsLastLoginTimespanSegmentFilterWrapper<Alloc>> value)
    {
        m_lastLoginFilter = std::move(value);
        this->m_model.lastLoginFilter = m_lastLoginFilter ? &m_lastLoginFilter->Model() : nullptr;
    }

    void SetLinkedUserAccountFilter(StdExtra::optional<PFSegmentsLinkedUserAccountSegmentFilterWrapper<Alloc>> value)
    {
        m_linkedUserAccountFilter = std::move(value);
        this->m_model.linkedUserAccountFilter = m_linkedUserAccountFilter ? &m_linkedUserAccountFilter->Model() : nullptr;
    }

    void SetLinkedUserAccountHasEmailFilter(StdExtra::optional<PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper<Alloc>> value)
    {
        m_linkedUserAccountHasEmailFilter = std::move(value);
        this->m_model.linkedUserAccountHasEmailFilter = m_linkedUserAccountHasEmailFilter ? &m_linkedUserAccountHasEmailFilter->Model() : nullptr;
    }

    void SetLocationFilter(StdExtra::optional<PFSegmentsLocationSegmentFilterWrapper<Alloc>> value)
    {
        m_locationFilter = std::move(value);
        this->m_model.locationFilter = m_locationFilter ? &m_locationFilter->Model() : nullptr;
    }

    void SetPushNotificationFilter(StdExtra::optional<PFSegmentsPushNotificationSegmentFilterWrapper<Alloc>> value)
    {
        m_pushNotificationFilter = std::move(value);
        this->m_model.pushNotificationFilter = m_pushNotificationFilter ? &m_pushNotificationFilter->Model() : nullptr;
    }

    void SetStatisticFilter(StdExtra::optional<PFSegmentsStatisticSegmentFilterWrapper<Alloc>> value)
    {
        m_statisticFilter = std::move(value);
        this->m_model.statisticFilter = m_statisticFilter ? &m_statisticFilter->Model() : nullptr;
    }

    void SetTagFilter(StdExtra::optional<PFSegmentsTagSegmentFilterWrapper<Alloc>> value)
    {
        m_tagFilter = std::move(value);
        this->m_model.tagFilter = m_tagFilter ? &m_tagFilter->Model() : nullptr;
    }

    void SetTotalValueToDateInUSDFilter(StdExtra::optional<PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper<Alloc>> value)
    {
        m_totalValueToDateInUSDFilter = std::move(value);
        this->m_model.totalValueToDateInUSDFilter = m_totalValueToDateInUSDFilter ? &m_totalValueToDateInUSDFilter->Model() : nullptr;
    }

    void SetUserOriginationFilter(StdExtra::optional<PFSegmentsUserOriginationSegmentFilterWrapper<Alloc>> value)
    {
        m_userOriginationFilter = std::move(value);
        this->m_model.userOriginationFilter = m_userOriginationFilter ? &m_userOriginationFilter->Model() : nullptr;
    }

    void SetValueToDateFilter(StdExtra::optional<PFSegmentsValueToDateSegmentFilterWrapper<Alloc>> value)
    {
        m_valueToDateFilter = std::move(value);
        this->m_model.valueToDateFilter = m_valueToDateFilter ? &m_valueToDateFilter->Model() : nullptr;
    }

    void SetVirtualCurrencyBalanceFilter(StdExtra::optional<PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper<Alloc>> value)
    {
        m_virtualCurrencyBalanceFilter = std::move(value);
        this->m_model.virtualCurrencyBalanceFilter = m_virtualCurrencyBalanceFilter ? &m_virtualCurrencyBalanceFilter->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.adCampaignFilter = m_adCampaignFilter ?  &m_adCampaignFilter->Model() : nullptr;
        this->m_model.firstLoginDateFilter = m_firstLoginDateFilter ?  &m_firstLoginDateFilter->Model() : nullptr;
        this->m_model.firstLoginFilter = m_firstLoginFilter ?  &m_firstLoginFilter->Model() : nullptr;
        this->m_model.lastLoginDateFilter = m_lastLoginDateFilter ?  &m_lastLoginDateFilter->Model() : nullptr;
        this->m_model.lastLoginFilter = m_lastLoginFilter ?  &m_lastLoginFilter->Model() : nullptr;
        this->m_model.linkedUserAccountFilter = m_linkedUserAccountFilter ?  &m_linkedUserAccountFilter->Model() : nullptr;
        this->m_model.linkedUserAccountHasEmailFilter = m_linkedUserAccountHasEmailFilter ?  &m_linkedUserAccountHasEmailFilter->Model() : nullptr;
        this->m_model.locationFilter = m_locationFilter ?  &m_locationFilter->Model() : nullptr;
        this->m_model.pushNotificationFilter = m_pushNotificationFilter ?  &m_pushNotificationFilter->Model() : nullptr;
        this->m_model.statisticFilter = m_statisticFilter ?  &m_statisticFilter->Model() : nullptr;
        this->m_model.tagFilter = m_tagFilter ?  &m_tagFilter->Model() : nullptr;
        this->m_model.totalValueToDateInUSDFilter = m_totalValueToDateInUSDFilter ?  &m_totalValueToDateInUSDFilter->Model() : nullptr;
        this->m_model.userOriginationFilter = m_userOriginationFilter ?  &m_userOriginationFilter->Model() : nullptr;
        this->m_model.valueToDateFilter = m_valueToDateFilter ?  &m_valueToDateFilter->Model() : nullptr;
        this->m_model.virtualCurrencyBalanceFilter = m_virtualCurrencyBalanceFilter ?  &m_virtualCurrencyBalanceFilter->Model() : nullptr;
    }

    StdExtra::optional<PFSegmentsAdCampaignSegmentFilterWrapper<Alloc>> m_adCampaignFilter;
    StdExtra::optional<PFSegmentsFirstLoginDateSegmentFilterWrapper<Alloc>> m_firstLoginDateFilter;
    StdExtra::optional<PFSegmentsFirstLoginTimespanSegmentFilterWrapper<Alloc>> m_firstLoginFilter;
    StdExtra::optional<PFSegmentsLastLoginDateSegmentFilterWrapper<Alloc>> m_lastLoginDateFilter;
    StdExtra::optional<PFSegmentsLastLoginTimespanSegmentFilterWrapper<Alloc>> m_lastLoginFilter;
    StdExtra::optional<PFSegmentsLinkedUserAccountSegmentFilterWrapper<Alloc>> m_linkedUserAccountFilter;
    StdExtra::optional<PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper<Alloc>> m_linkedUserAccountHasEmailFilter;
    StdExtra::optional<PFSegmentsLocationSegmentFilterWrapper<Alloc>> m_locationFilter;
    StdExtra::optional<PFSegmentsPushNotificationSegmentFilterWrapper<Alloc>> m_pushNotificationFilter;
    StdExtra::optional<PFSegmentsStatisticSegmentFilterWrapper<Alloc>> m_statisticFilter;
    StdExtra::optional<PFSegmentsTagSegmentFilterWrapper<Alloc>> m_tagFilter;
    StdExtra::optional<PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper<Alloc>> m_totalValueToDateInUSDFilter;
    StdExtra::optional<PFSegmentsUserOriginationSegmentFilterWrapper<Alloc>> m_userOriginationFilter;
    StdExtra::optional<PFSegmentsValueToDateSegmentFilterWrapper<Alloc>> m_valueToDateFilter;
    StdExtra::optional<PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper<Alloc>> m_virtualCurrencyBalanceFilter;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsSegmentOrDefinitionWrapper : public ModelWrapper<PFSegmentsSegmentOrDefinition, Alloc>
{
public:
    using ModelType = typename PFSegmentsSegmentOrDefinition;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsSegmentOrDefinitionWrapper() = default;

    PFSegmentsSegmentOrDefinitionWrapper(const PFSegmentsSegmentOrDefinition& model) :
        ModelWrapper<PFSegmentsSegmentOrDefinition, Alloc>{ model },
        m_segmentAndDefinitions{ model.segmentAndDefinitions, model.segmentAndDefinitions + model.segmentAndDefinitionsCount }
    {
        SetModelPointers();
    }

    PFSegmentsSegmentOrDefinitionWrapper(const PFSegmentsSegmentOrDefinitionWrapper& src) :
        PFSegmentsSegmentOrDefinitionWrapper{ src.Model() }
    {
    }

    PFSegmentsSegmentOrDefinitionWrapper(PFSegmentsSegmentOrDefinitionWrapper&& src) :
        PFSegmentsSegmentOrDefinitionWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsSegmentOrDefinitionWrapper& operator=(PFSegmentsSegmentOrDefinitionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsSegmentOrDefinitionWrapper() = default;

    friend void swap(PFSegmentsSegmentOrDefinitionWrapper& lhs, PFSegmentsSegmentOrDefinitionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_segmentAndDefinitions, rhs.m_segmentAndDefinitions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSegmentAndDefinitions(ModelVector<PFSegmentsSegmentAndDefinitionWrapper<Alloc>, Alloc> value)
    {
        m_segmentAndDefinitions = std::move(value);
        this->m_model.segmentAndDefinitions =  m_segmentAndDefinitions.empty() ? nullptr : m_segmentAndDefinitions.data();
        this->m_model.segmentAndDefinitionsCount =  static_cast<uint32_t>(m_segmentAndDefinitions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.segmentAndDefinitions = m_segmentAndDefinitions.empty() ? nullptr : m_segmentAndDefinitions.data();
    }

    ModelVector<PFSegmentsSegmentAndDefinitionWrapper<Alloc>, Alloc> m_segmentAndDefinitions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsSegmentModelWrapper : public ModelWrapper<PFSegmentsSegmentModel, Alloc>
{
public:
    using ModelType = typename PFSegmentsSegmentModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsSegmentModelWrapper() = default;

    PFSegmentsSegmentModelWrapper(const PFSegmentsSegmentModel& model) :
        ModelWrapper<PFSegmentsSegmentModel, Alloc>{ model },
        m_azureResourceId{ SafeString(model.azureResourceId) },
        m_description{ SafeString(model.description) },
        m_enteredSegmentActions{ model.enteredSegmentActions, model.enteredSegmentActions + model.enteredSegmentActionsCount },
        m_leftSegmentActions{ model.leftSegmentActions, model.leftSegmentActions + model.leftSegmentActionsCount },
        m_name{ SafeString(model.name) },
        m_segmentId{ SafeString(model.segmentId) },
        m_segmentOrDefinitions{ model.segmentOrDefinitions, model.segmentOrDefinitions + model.segmentOrDefinitionsCount }
    {
        SetModelPointers();
    }

    PFSegmentsSegmentModelWrapper(const PFSegmentsSegmentModelWrapper& src) :
        PFSegmentsSegmentModelWrapper{ src.Model() }
    {
    }

    PFSegmentsSegmentModelWrapper(PFSegmentsSegmentModelWrapper&& src) :
        PFSegmentsSegmentModelWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsSegmentModelWrapper& operator=(PFSegmentsSegmentModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsSegmentModelWrapper() = default;

    friend void swap(PFSegmentsSegmentModelWrapper& lhs, PFSegmentsSegmentModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_azureResourceId, rhs.m_azureResourceId);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_enteredSegmentActions, rhs.m_enteredSegmentActions);
        swap(lhs.m_leftSegmentActions, rhs.m_leftSegmentActions);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_segmentId, rhs.m_segmentId);
        swap(lhs.m_segmentOrDefinitions, rhs.m_segmentOrDefinitions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAzureResourceId(String value)
    {
        m_azureResourceId = std::move(value);
        this->m_model.azureResourceId =  m_azureResourceId.empty() ? nullptr : m_azureResourceId.data();
    }

    void SetDescription(String value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
    }

    void SetEnteredSegmentActions(ModelVector<PFSegmentsSegmentTriggerWrapper<Alloc>, Alloc> value)
    {
        m_enteredSegmentActions = std::move(value);
        this->m_model.enteredSegmentActions =  m_enteredSegmentActions.empty() ? nullptr : m_enteredSegmentActions.data();
        this->m_model.enteredSegmentActionsCount =  static_cast<uint32_t>(m_enteredSegmentActions.size());
    }

    void SetLastUpdateTime(time_t value)
    {
        this->m_model.lastUpdateTime = value;
    }

    void SetLeftSegmentActions(ModelVector<PFSegmentsSegmentTriggerWrapper<Alloc>, Alloc> value)
    {
        m_leftSegmentActions = std::move(value);
        this->m_model.leftSegmentActions =  m_leftSegmentActions.empty() ? nullptr : m_leftSegmentActions.data();
        this->m_model.leftSegmentActionsCount =  static_cast<uint32_t>(m_leftSegmentActions.size());
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetSegmentId(String value)
    {
        m_segmentId = std::move(value);
        this->m_model.segmentId =  m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

    void SetSegmentOrDefinitions(ModelVector<PFSegmentsSegmentOrDefinitionWrapper<Alloc>, Alloc> value)
    {
        m_segmentOrDefinitions = std::move(value);
        this->m_model.segmentOrDefinitions =  m_segmentOrDefinitions.empty() ? nullptr : m_segmentOrDefinitions.data();
        this->m_model.segmentOrDefinitionsCount =  static_cast<uint32_t>(m_segmentOrDefinitions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.azureResourceId = m_azureResourceId.empty() ? nullptr : m_azureResourceId.data();
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.enteredSegmentActions = m_enteredSegmentActions.empty() ? nullptr : m_enteredSegmentActions.data();
        this->m_model.leftSegmentActions = m_leftSegmentActions.empty() ? nullptr : m_leftSegmentActions.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.segmentId = m_segmentId.empty() ? nullptr : m_segmentId.data();
        this->m_model.segmentOrDefinitions = m_segmentOrDefinitions.empty() ? nullptr : m_segmentOrDefinitions.data();
    }

    String m_azureResourceId;
    String m_description;
    ModelVector<PFSegmentsSegmentTriggerWrapper<Alloc>, Alloc> m_enteredSegmentActions;
    ModelVector<PFSegmentsSegmentTriggerWrapper<Alloc>, Alloc> m_leftSegmentActions;
    String m_name;
    String m_segmentId;
    ModelVector<PFSegmentsSegmentOrDefinitionWrapper<Alloc>, Alloc> m_segmentOrDefinitions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsCreateSegmentRequestWrapper : public ModelWrapper<PFSegmentsCreateSegmentRequest, Alloc>
{
public:
    using ModelType = typename PFSegmentsCreateSegmentRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsCreateSegmentRequestWrapper() = default;

    PFSegmentsCreateSegmentRequestWrapper(const PFSegmentsCreateSegmentRequest& model) :
        ModelWrapper<PFSegmentsCreateSegmentRequest, Alloc>{ model },
        m_segmentModel{ model.segmentModel ? *model.segmentModel : decltype(*model.segmentModel){} }
    {
        SetModelPointers();
    }

    PFSegmentsCreateSegmentRequestWrapper(const PFSegmentsCreateSegmentRequestWrapper& src) :
        PFSegmentsCreateSegmentRequestWrapper{ src.Model() }
    {
    }

    PFSegmentsCreateSegmentRequestWrapper(PFSegmentsCreateSegmentRequestWrapper&& src) :
        PFSegmentsCreateSegmentRequestWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsCreateSegmentRequestWrapper& operator=(PFSegmentsCreateSegmentRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsCreateSegmentRequestWrapper() = default;

    friend void swap(PFSegmentsCreateSegmentRequestWrapper& lhs, PFSegmentsCreateSegmentRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_segmentModel, rhs.m_segmentModel);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSegmentModel(PFSegmentsSegmentModelWrapper<Alloc> value)
    {
        m_segmentModel = std::move(value);
        this->m_model.segmentModel = &m_segmentModel.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.segmentModel = &m_segmentModel.Model();
    }

    PFSegmentsSegmentModelWrapper<Alloc> m_segmentModel;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsCreateSegmentResponseWrapper : public ModelWrapper<PFSegmentsCreateSegmentResponse, Alloc>
{
public:
    using ModelType = typename PFSegmentsCreateSegmentResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsCreateSegmentResponseWrapper() = default;

    PFSegmentsCreateSegmentResponseWrapper(const PFSegmentsCreateSegmentResponse& model) :
        ModelWrapper<PFSegmentsCreateSegmentResponse, Alloc>{ model },
        m_errorMessage{ SafeString(model.errorMessage) },
        m_segmentId{ SafeString(model.segmentId) }
    {
        SetModelPointers();
    }

    PFSegmentsCreateSegmentResponseWrapper(const PFSegmentsCreateSegmentResponseWrapper& src) :
        PFSegmentsCreateSegmentResponseWrapper{ src.Model() }
    {
    }

    PFSegmentsCreateSegmentResponseWrapper(PFSegmentsCreateSegmentResponseWrapper&& src) :
        PFSegmentsCreateSegmentResponseWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsCreateSegmentResponseWrapper& operator=(PFSegmentsCreateSegmentResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsCreateSegmentResponseWrapper() = default;

    friend void swap(PFSegmentsCreateSegmentResponseWrapper& lhs, PFSegmentsCreateSegmentResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_errorMessage, rhs.m_errorMessage);
        swap(lhs.m_segmentId, rhs.m_segmentId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetErrorMessage(String value)
    {
        m_errorMessage = std::move(value);
        this->m_model.errorMessage =  m_errorMessage.empty() ? nullptr : m_errorMessage.data();
    }

    void SetSegmentId(String value)
    {
        m_segmentId = std::move(value);
        this->m_model.segmentId =  m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.errorMessage = m_errorMessage.empty() ? nullptr : m_errorMessage.data();
        this->m_model.segmentId = m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

    String m_errorMessage;
    String m_segmentId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsDeleteSegmentRequestWrapper : public ModelWrapper<PFSegmentsDeleteSegmentRequest, Alloc>
{
public:
    using ModelType = typename PFSegmentsDeleteSegmentRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsDeleteSegmentRequestWrapper() = default;

    PFSegmentsDeleteSegmentRequestWrapper(const PFSegmentsDeleteSegmentRequest& model) :
        ModelWrapper<PFSegmentsDeleteSegmentRequest, Alloc>{ model },
        m_segmentId{ SafeString(model.segmentId) }
    {
        SetModelPointers();
    }

    PFSegmentsDeleteSegmentRequestWrapper(const PFSegmentsDeleteSegmentRequestWrapper& src) :
        PFSegmentsDeleteSegmentRequestWrapper{ src.Model() }
    {
    }

    PFSegmentsDeleteSegmentRequestWrapper(PFSegmentsDeleteSegmentRequestWrapper&& src) :
        PFSegmentsDeleteSegmentRequestWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsDeleteSegmentRequestWrapper& operator=(PFSegmentsDeleteSegmentRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsDeleteSegmentRequestWrapper() = default;

    friend void swap(PFSegmentsDeleteSegmentRequestWrapper& lhs, PFSegmentsDeleteSegmentRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_segmentId, rhs.m_segmentId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSegmentId(String value)
    {
        m_segmentId = std::move(value);
        this->m_model.segmentId =  m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.segmentId = m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

    String m_segmentId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsDeleteSegmentsResponseWrapper : public ModelWrapper<PFSegmentsDeleteSegmentsResponse, Alloc>
{
public:
    using ModelType = typename PFSegmentsDeleteSegmentsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsDeleteSegmentsResponseWrapper() = default;

    PFSegmentsDeleteSegmentsResponseWrapper(const PFSegmentsDeleteSegmentsResponse& model) :
        ModelWrapper<PFSegmentsDeleteSegmentsResponse, Alloc>{ model },
        m_errorMessage{ SafeString(model.errorMessage) }
    {
        SetModelPointers();
    }

    PFSegmentsDeleteSegmentsResponseWrapper(const PFSegmentsDeleteSegmentsResponseWrapper& src) :
        PFSegmentsDeleteSegmentsResponseWrapper{ src.Model() }
    {
    }

    PFSegmentsDeleteSegmentsResponseWrapper(PFSegmentsDeleteSegmentsResponseWrapper&& src) :
        PFSegmentsDeleteSegmentsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsDeleteSegmentsResponseWrapper& operator=(PFSegmentsDeleteSegmentsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsDeleteSegmentsResponseWrapper() = default;

    friend void swap(PFSegmentsDeleteSegmentsResponseWrapper& lhs, PFSegmentsDeleteSegmentsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_errorMessage, rhs.m_errorMessage);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetErrorMessage(String value)
    {
        m_errorMessage = std::move(value);
        this->m_model.errorMessage =  m_errorMessage.empty() ? nullptr : m_errorMessage.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.errorMessage = m_errorMessage.empty() ? nullptr : m_errorMessage.data();
    }

    String m_errorMessage;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsGetSegmentsRequestWrapper : public ModelWrapper<PFSegmentsGetSegmentsRequest, Alloc>
{
public:
    using ModelType = typename PFSegmentsGetSegmentsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsGetSegmentsRequestWrapper() = default;

    PFSegmentsGetSegmentsRequestWrapper(const PFSegmentsGetSegmentsRequest& model) :
        ModelWrapper<PFSegmentsGetSegmentsRequest, Alloc>{ model },
        m_segmentIds{ model.segmentIds, model.segmentIds + model.segmentIdsCount }
    {
        SetModelPointers();
    }

    PFSegmentsGetSegmentsRequestWrapper(const PFSegmentsGetSegmentsRequestWrapper& src) :
        PFSegmentsGetSegmentsRequestWrapper{ src.Model() }
    {
    }

    PFSegmentsGetSegmentsRequestWrapper(PFSegmentsGetSegmentsRequestWrapper&& src) :
        PFSegmentsGetSegmentsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsGetSegmentsRequestWrapper& operator=(PFSegmentsGetSegmentsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsGetSegmentsRequestWrapper() = default;

    friend void swap(PFSegmentsGetSegmentsRequestWrapper& lhs, PFSegmentsGetSegmentsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_segmentIds, rhs.m_segmentIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSegmentIds(CStringVector<Alloc> value)
    {
        m_segmentIds = std::move(value);
        this->m_model.segmentIds =  m_segmentIds.empty() ? nullptr : m_segmentIds.data();
        this->m_model.segmentIdsCount =  static_cast<uint32_t>(m_segmentIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.segmentIds = m_segmentIds.empty() ? nullptr : m_segmentIds.data();
    }

    CStringVector<Alloc> m_segmentIds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsGetSegmentsResponseWrapper : public ModelWrapper<PFSegmentsGetSegmentsResponse, Alloc>
{
public:
    using ModelType = typename PFSegmentsGetSegmentsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsGetSegmentsResponseWrapper() = default;

    PFSegmentsGetSegmentsResponseWrapper(const PFSegmentsGetSegmentsResponse& model) :
        ModelWrapper<PFSegmentsGetSegmentsResponse, Alloc>{ model },
        m_errorMessage{ SafeString(model.errorMessage) },
        m_segments{ model.segments, model.segments + model.segmentsCount }
    {
        SetModelPointers();
    }

    PFSegmentsGetSegmentsResponseWrapper(const PFSegmentsGetSegmentsResponseWrapper& src) :
        PFSegmentsGetSegmentsResponseWrapper{ src.Model() }
    {
    }

    PFSegmentsGetSegmentsResponseWrapper(PFSegmentsGetSegmentsResponseWrapper&& src) :
        PFSegmentsGetSegmentsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsGetSegmentsResponseWrapper& operator=(PFSegmentsGetSegmentsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsGetSegmentsResponseWrapper() = default;

    friend void swap(PFSegmentsGetSegmentsResponseWrapper& lhs, PFSegmentsGetSegmentsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_errorMessage, rhs.m_errorMessage);
        swap(lhs.m_segments, rhs.m_segments);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetErrorMessage(String value)
    {
        m_errorMessage = std::move(value);
        this->m_model.errorMessage =  m_errorMessage.empty() ? nullptr : m_errorMessage.data();
    }

    void SetSegments(ModelVector<PFSegmentsSegmentModelWrapper<Alloc>, Alloc> value)
    {
        m_segments = std::move(value);
        this->m_model.segments =  m_segments.empty() ? nullptr : m_segments.data();
        this->m_model.segmentsCount =  static_cast<uint32_t>(m_segments.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.errorMessage = m_errorMessage.empty() ? nullptr : m_errorMessage.data();
        this->m_model.segments = m_segments.empty() ? nullptr : m_segments.data();
    }

    String m_errorMessage;
    ModelVector<PFSegmentsSegmentModelWrapper<Alloc>, Alloc> m_segments;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsUpdateSegmentRequestWrapper : public ModelWrapper<PFSegmentsUpdateSegmentRequest, Alloc>
{
public:
    using ModelType = typename PFSegmentsUpdateSegmentRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsUpdateSegmentRequestWrapper() = default;

    PFSegmentsUpdateSegmentRequestWrapper(const PFSegmentsUpdateSegmentRequest& model) :
        ModelWrapper<PFSegmentsUpdateSegmentRequest, Alloc>{ model },
        m_segmentModel{ model.segmentModel ? *model.segmentModel : decltype(*model.segmentModel){} }
    {
        SetModelPointers();
    }

    PFSegmentsUpdateSegmentRequestWrapper(const PFSegmentsUpdateSegmentRequestWrapper& src) :
        PFSegmentsUpdateSegmentRequestWrapper{ src.Model() }
    {
    }

    PFSegmentsUpdateSegmentRequestWrapper(PFSegmentsUpdateSegmentRequestWrapper&& src) :
        PFSegmentsUpdateSegmentRequestWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsUpdateSegmentRequestWrapper& operator=(PFSegmentsUpdateSegmentRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsUpdateSegmentRequestWrapper() = default;

    friend void swap(PFSegmentsUpdateSegmentRequestWrapper& lhs, PFSegmentsUpdateSegmentRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_segmentModel, rhs.m_segmentModel);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSegmentModel(PFSegmentsSegmentModelWrapper<Alloc> value)
    {
        m_segmentModel = std::move(value);
        this->m_model.segmentModel = &m_segmentModel.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.segmentModel = &m_segmentModel.Model();
    }

    PFSegmentsSegmentModelWrapper<Alloc> m_segmentModel;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSegmentsUpdateSegmentResponseWrapper : public ModelWrapper<PFSegmentsUpdateSegmentResponse, Alloc>
{
public:
    using ModelType = typename PFSegmentsUpdateSegmentResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSegmentsUpdateSegmentResponseWrapper() = default;

    PFSegmentsUpdateSegmentResponseWrapper(const PFSegmentsUpdateSegmentResponse& model) :
        ModelWrapper<PFSegmentsUpdateSegmentResponse, Alloc>{ model },
        m_errorMessage{ SafeString(model.errorMessage) },
        m_segmentId{ SafeString(model.segmentId) }
    {
        SetModelPointers();
    }

    PFSegmentsUpdateSegmentResponseWrapper(const PFSegmentsUpdateSegmentResponseWrapper& src) :
        PFSegmentsUpdateSegmentResponseWrapper{ src.Model() }
    {
    }

    PFSegmentsUpdateSegmentResponseWrapper(PFSegmentsUpdateSegmentResponseWrapper&& src) :
        PFSegmentsUpdateSegmentResponseWrapper{}
    {
        swap(*this, src);
    }

    PFSegmentsUpdateSegmentResponseWrapper& operator=(PFSegmentsUpdateSegmentResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSegmentsUpdateSegmentResponseWrapper() = default;

    friend void swap(PFSegmentsUpdateSegmentResponseWrapper& lhs, PFSegmentsUpdateSegmentResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_errorMessage, rhs.m_errorMessage);
        swap(lhs.m_segmentId, rhs.m_segmentId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetErrorMessage(String value)
    {
        m_errorMessage = std::move(value);
        this->m_model.errorMessage =  m_errorMessage.empty() ? nullptr : m_errorMessage.data();
    }

    void SetSegmentId(String value)
    {
        m_segmentId = std::move(value);
        this->m_model.segmentId =  m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.errorMessage = m_errorMessage.empty() ? nullptr : m_errorMessage.data();
        this->m_model.segmentId = m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

    String m_errorMessage;
    String m_segmentId;
};

} // namespace Wrappers
} // namespace PlayFab
