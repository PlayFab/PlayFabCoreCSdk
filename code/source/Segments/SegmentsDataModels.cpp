#include "stdafx.h"
#include "SegmentsDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Segments
{

JsonValue BanPlayerSegmentAction::ToJson() const
{
    return BanPlayerSegmentAction::ToJson(this->Model());
}

JsonValue BanPlayerSegmentAction::ToJson(const PFSegmentsBanPlayerSegmentAction& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BanHours", input.banHours);
    JsonUtils::ObjectAddMember(output, "ReasonForBan", input.reasonForBan);
    return output;
}

void BanPlayerSegmentAction::FromJson(const JsonValue& input)
{
    StdExtra::optional<uint32_t> banHours{};
    JsonUtils::ObjectGetMember(input, "BanHours", banHours);
    this->SetBanHours(std::move(banHours));

    String reasonForBan{};
    JsonUtils::ObjectGetMember(input, "ReasonForBan", reasonForBan);
    this->SetReasonForBan(std::move(reasonForBan));
}

size_t BanPlayerSegmentAction::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsBanPlayerSegmentAction const*> BanPlayerSegmentAction::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<BanPlayerSegmentAction>(&this->Model());
}

size_t BanPlayerSegmentAction::RequiredBufferSize(const PFSegmentsBanPlayerSegmentAction& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.banHours)
    {
        requiredSize += (alignof(uint32_t) + sizeof(uint32_t));
    }
    if (model.reasonForBan)
    {
        requiredSize += (std::strlen(model.reasonForBan) + 1);
    }
    return requiredSize;
}

HRESULT BanPlayerSegmentAction::Copy(const PFSegmentsBanPlayerSegmentAction& input, PFSegmentsBanPlayerSegmentAction& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.banHours); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.banHours = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.reasonForBan); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.reasonForBan = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue DeletePlayerStatisticSegmentAction::ToJson() const
{
    return DeletePlayerStatisticSegmentAction::ToJson(this->Model());
}

JsonValue DeletePlayerStatisticSegmentAction::ToJson(const PFSegmentsDeletePlayerStatisticSegmentAction& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    return output;
}

void DeletePlayerStatisticSegmentAction::FromJson(const JsonValue& input)
{
    String statisticName{};
    JsonUtils::ObjectGetMember(input, "StatisticName", statisticName);
    this->SetStatisticName(std::move(statisticName));
}

size_t DeletePlayerStatisticSegmentAction::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsDeletePlayerStatisticSegmentAction const*> DeletePlayerStatisticSegmentAction::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<DeletePlayerStatisticSegmentAction>(&this->Model());
}

size_t DeletePlayerStatisticSegmentAction::RequiredBufferSize(const PFSegmentsDeletePlayerStatisticSegmentAction& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.statisticName)
    {
        requiredSize += (std::strlen(model.statisticName) + 1);
    }
    return requiredSize;
}

HRESULT DeletePlayerStatisticSegmentAction::Copy(const PFSegmentsDeletePlayerStatisticSegmentAction& input, PFSegmentsDeletePlayerStatisticSegmentAction& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.statisticName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statisticName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue EmailNotificationSegmentAction::ToJson() const
{
    return EmailNotificationSegmentAction::ToJson(this->Model());
}

JsonValue EmailNotificationSegmentAction::ToJson(const PFSegmentsEmailNotificationSegmentAction& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "EmailTemplateId", input.emailTemplateId);
    JsonUtils::ObjectAddMember(output, "EmailTemplateName", input.emailTemplateName);
    return output;
}

void EmailNotificationSegmentAction::FromJson(const JsonValue& input)
{
    String emailTemplateId{};
    JsonUtils::ObjectGetMember(input, "EmailTemplateId", emailTemplateId);
    this->SetEmailTemplateId(std::move(emailTemplateId));

    String emailTemplateName{};
    JsonUtils::ObjectGetMember(input, "EmailTemplateName", emailTemplateName);
    this->SetEmailTemplateName(std::move(emailTemplateName));
}

size_t EmailNotificationSegmentAction::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsEmailNotificationSegmentAction const*> EmailNotificationSegmentAction::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<EmailNotificationSegmentAction>(&this->Model());
}

size_t EmailNotificationSegmentAction::RequiredBufferSize(const PFSegmentsEmailNotificationSegmentAction& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.emailTemplateId)
    {
        requiredSize += (std::strlen(model.emailTemplateId) + 1);
    }
    if (model.emailTemplateName)
    {
        requiredSize += (std::strlen(model.emailTemplateName) + 1);
    }
    return requiredSize;
}

HRESULT EmailNotificationSegmentAction::Copy(const PFSegmentsEmailNotificationSegmentAction& input, PFSegmentsEmailNotificationSegmentAction& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.emailTemplateId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.emailTemplateId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.emailTemplateName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.emailTemplateName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ExecuteAzureFunctionSegmentAction::ToJson() const
{
    return ExecuteAzureFunctionSegmentAction::ToJson(this->Model());
}

JsonValue ExecuteAzureFunctionSegmentAction::ToJson(const PFSegmentsExecuteAzureFunctionSegmentAction& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AzureFunction", input.azureFunction);
    JsonUtils::ObjectAddMember(output, "FunctionParameter", input.functionParameter);
    JsonUtils::ObjectAddMember(output, "GenerateFunctionExecutedEvents", input.generateFunctionExecutedEvents);
    return output;
}

void ExecuteAzureFunctionSegmentAction::FromJson(const JsonValue& input)
{
    String azureFunction{};
    JsonUtils::ObjectGetMember(input, "AzureFunction", azureFunction);
    this->SetAzureFunction(std::move(azureFunction));

    JsonObject functionParameter{};
    JsonUtils::ObjectGetMember(input, "FunctionParameter", functionParameter);
    this->SetFunctionParameter(std::move(functionParameter));

    JsonUtils::ObjectGetMember(input, "GenerateFunctionExecutedEvents", this->m_model.generateFunctionExecutedEvents);
}

size_t ExecuteAzureFunctionSegmentAction::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsExecuteAzureFunctionSegmentAction const*> ExecuteAzureFunctionSegmentAction::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ExecuteAzureFunctionSegmentAction>(&this->Model());
}

size_t ExecuteAzureFunctionSegmentAction::RequiredBufferSize(const PFSegmentsExecuteAzureFunctionSegmentAction& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.azureFunction)
    {
        requiredSize += (std::strlen(model.azureFunction) + 1);
    }
    if (model.functionParameter.stringValue)
    {
    requiredSize += (std::strlen(model.functionParameter.stringValue) + 1);
    }
    return requiredSize;
}

HRESULT ExecuteAzureFunctionSegmentAction::Copy(const PFSegmentsExecuteAzureFunctionSegmentAction& input, PFSegmentsExecuteAzureFunctionSegmentAction& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.azureFunction); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.azureFunction = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.functionParameter.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.functionParameter.stringValue = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ExecuteCloudScriptSegmentAction::ToJson() const
{
    return ExecuteCloudScriptSegmentAction::ToJson(this->Model());
}

JsonValue ExecuteCloudScriptSegmentAction::ToJson(const PFSegmentsExecuteCloudScriptSegmentAction& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CloudScriptFunction", input.cloudScriptFunction);
    JsonUtils::ObjectAddMember(output, "CloudScriptPublishResultsToPlayStream", input.cloudScriptPublishResultsToPlayStream);
    JsonUtils::ObjectAddMember(output, "FunctionParameter", input.functionParameter);
    JsonUtils::ObjectAddMember(output, "FunctionParameterJson", input.functionParameterJson);
    return output;
}

void ExecuteCloudScriptSegmentAction::FromJson(const JsonValue& input)
{
    String cloudScriptFunction{};
    JsonUtils::ObjectGetMember(input, "CloudScriptFunction", cloudScriptFunction);
    this->SetCloudScriptFunction(std::move(cloudScriptFunction));

    JsonUtils::ObjectGetMember(input, "CloudScriptPublishResultsToPlayStream", this->m_model.cloudScriptPublishResultsToPlayStream);

    JsonObject functionParameter{};
    JsonUtils::ObjectGetMember(input, "FunctionParameter", functionParameter);
    this->SetFunctionParameter(std::move(functionParameter));

    String functionParameterJson{};
    JsonUtils::ObjectGetMember(input, "FunctionParameterJson", functionParameterJson);
    this->SetFunctionParameterJson(std::move(functionParameterJson));
}

size_t ExecuteCloudScriptSegmentAction::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsExecuteCloudScriptSegmentAction const*> ExecuteCloudScriptSegmentAction::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ExecuteCloudScriptSegmentAction>(&this->Model());
}

size_t ExecuteCloudScriptSegmentAction::RequiredBufferSize(const PFSegmentsExecuteCloudScriptSegmentAction& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.cloudScriptFunction)
    {
        requiredSize += (std::strlen(model.cloudScriptFunction) + 1);
    }
    if (model.functionParameter.stringValue)
    {
    requiredSize += (std::strlen(model.functionParameter.stringValue) + 1);
    }
    if (model.functionParameterJson)
    {
        requiredSize += (std::strlen(model.functionParameterJson) + 1);
    }
    return requiredSize;
}

HRESULT ExecuteCloudScriptSegmentAction::Copy(const PFSegmentsExecuteCloudScriptSegmentAction& input, PFSegmentsExecuteCloudScriptSegmentAction& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.cloudScriptFunction); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.cloudScriptFunction = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.functionParameter.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.functionParameter.stringValue = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.functionParameterJson); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.functionParameterJson = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GrantItemSegmentAction::ToJson() const
{
    return GrantItemSegmentAction::ToJson(this->Model());
}

JsonValue GrantItemSegmentAction::ToJson(const PFSegmentsGrantItemSegmentAction& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatelogId", input.catelogId);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    JsonUtils::ObjectAddMember(output, "Quantity", input.quantity);
    return output;
}

void GrantItemSegmentAction::FromJson(const JsonValue& input)
{
    String catelogId{};
    JsonUtils::ObjectGetMember(input, "CatelogId", catelogId);
    this->SetCatelogId(std::move(catelogId));

    String itemId{};
    JsonUtils::ObjectGetMember(input, "ItemId", itemId);
    this->SetItemId(std::move(itemId));

    JsonUtils::ObjectGetMember(input, "Quantity", this->m_model.quantity);
}

size_t GrantItemSegmentAction::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsGrantItemSegmentAction const*> GrantItemSegmentAction::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GrantItemSegmentAction>(&this->Model());
}

size_t GrantItemSegmentAction::RequiredBufferSize(const PFSegmentsGrantItemSegmentAction& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.catelogId)
    {
        requiredSize += (std::strlen(model.catelogId) + 1);
    }
    if (model.itemId)
    {
        requiredSize += (std::strlen(model.itemId) + 1);
    }
    return requiredSize;
}

HRESULT GrantItemSegmentAction::Copy(const PFSegmentsGrantItemSegmentAction& input, PFSegmentsGrantItemSegmentAction& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.catelogId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.catelogId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.itemId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GrantVirtualCurrencySegmentAction::ToJson() const
{
    return GrantVirtualCurrencySegmentAction::ToJson(this->Model());
}

JsonValue GrantVirtualCurrencySegmentAction::ToJson(const PFSegmentsGrantVirtualCurrencySegmentAction& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "CurrencyCode", input.currencyCode);
    return output;
}

void GrantVirtualCurrencySegmentAction::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Amount", this->m_model.amount);

    String currencyCode{};
    JsonUtils::ObjectGetMember(input, "CurrencyCode", currencyCode);
    this->SetCurrencyCode(std::move(currencyCode));
}

size_t GrantVirtualCurrencySegmentAction::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsGrantVirtualCurrencySegmentAction const*> GrantVirtualCurrencySegmentAction::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GrantVirtualCurrencySegmentAction>(&this->Model());
}

size_t GrantVirtualCurrencySegmentAction::RequiredBufferSize(const PFSegmentsGrantVirtualCurrencySegmentAction& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.currencyCode)
    {
        requiredSize += (std::strlen(model.currencyCode) + 1);
    }
    return requiredSize;
}

HRESULT GrantVirtualCurrencySegmentAction::Copy(const PFSegmentsGrantVirtualCurrencySegmentAction& input, PFSegmentsGrantVirtualCurrencySegmentAction& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.currencyCode); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.currencyCode = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue IncrementPlayerStatisticSegmentAction::ToJson() const
{
    return IncrementPlayerStatisticSegmentAction::ToJson(this->Model());
}

JsonValue IncrementPlayerStatisticSegmentAction::ToJson(const PFSegmentsIncrementPlayerStatisticSegmentAction& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "IncrementValue", input.incrementValue);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    return output;
}

void IncrementPlayerStatisticSegmentAction::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "IncrementValue", this->m_model.incrementValue);

    String statisticName{};
    JsonUtils::ObjectGetMember(input, "StatisticName", statisticName);
    this->SetStatisticName(std::move(statisticName));
}

size_t IncrementPlayerStatisticSegmentAction::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsIncrementPlayerStatisticSegmentAction const*> IncrementPlayerStatisticSegmentAction::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<IncrementPlayerStatisticSegmentAction>(&this->Model());
}

size_t IncrementPlayerStatisticSegmentAction::RequiredBufferSize(const PFSegmentsIncrementPlayerStatisticSegmentAction& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.statisticName)
    {
        requiredSize += (std::strlen(model.statisticName) + 1);
    }
    return requiredSize;
}

HRESULT IncrementPlayerStatisticSegmentAction::Copy(const PFSegmentsIncrementPlayerStatisticSegmentAction& input, PFSegmentsIncrementPlayerStatisticSegmentAction& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.statisticName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statisticName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PushNotificationSegmentAction::ToJson() const
{
    return PushNotificationSegmentAction::ToJson(this->Model());
}

JsonValue PushNotificationSegmentAction::ToJson(const PFSegmentsPushNotificationSegmentAction& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PushNotificationTemplateId", input.pushNotificationTemplateId);
    return output;
}

void PushNotificationSegmentAction::FromJson(const JsonValue& input)
{
    String pushNotificationTemplateId{};
    JsonUtils::ObjectGetMember(input, "PushNotificationTemplateId", pushNotificationTemplateId);
    this->SetPushNotificationTemplateId(std::move(pushNotificationTemplateId));
}

size_t PushNotificationSegmentAction::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsPushNotificationSegmentAction const*> PushNotificationSegmentAction::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PushNotificationSegmentAction>(&this->Model());
}

size_t PushNotificationSegmentAction::RequiredBufferSize(const PFSegmentsPushNotificationSegmentAction& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.pushNotificationTemplateId)
    {
        requiredSize += (std::strlen(model.pushNotificationTemplateId) + 1);
    }
    return requiredSize;
}

HRESULT PushNotificationSegmentAction::Copy(const PFSegmentsPushNotificationSegmentAction& input, PFSegmentsPushNotificationSegmentAction& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.pushNotificationTemplateId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pushNotificationTemplateId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue SegmentTrigger::ToJson() const
{
    return SegmentTrigger::ToJson(this->Model());
}

JsonValue SegmentTrigger::ToJson(const PFSegmentsSegmentTrigger& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<BanPlayerSegmentAction>(output, "BanPlayerAction", input.banPlayerAction);
    JsonUtils::ObjectAddMember<DeletePlayerStatisticSegmentAction>(output, "DeletePlayerStatisticAction", input.deletePlayerStatisticAction);
    JsonUtils::ObjectAddMember<EmailNotificationSegmentAction>(output, "EmailNotificationAction", input.emailNotificationAction);
    JsonUtils::ObjectAddMember<ExecuteAzureFunctionSegmentAction>(output, "ExecuteAzureFunctionAction", input.executeAzureFunctionAction);
    JsonUtils::ObjectAddMember<ExecuteCloudScriptSegmentAction>(output, "ExecuteCloudScriptAction", input.executeCloudScriptAction);
    JsonUtils::ObjectAddMember<GrantItemSegmentAction>(output, "GrantItemAction", input.grantItemAction);
    JsonUtils::ObjectAddMember<GrantVirtualCurrencySegmentAction>(output, "GrantVirtualCurrencyAction", input.grantVirtualCurrencyAction);
    JsonUtils::ObjectAddMember<IncrementPlayerStatisticSegmentAction>(output, "IncrementPlayerStatisticAction", input.incrementPlayerStatisticAction);
    JsonUtils::ObjectAddMember<PushNotificationSegmentAction>(output, "PushNotificationAction", input.pushNotificationAction);
    return output;
}

void SegmentTrigger::FromJson(const JsonValue& input)
{
    StdExtra::optional<BanPlayerSegmentAction> banPlayerAction{};
    JsonUtils::ObjectGetMember(input, "BanPlayerAction", banPlayerAction);
    if (banPlayerAction)
    {
        this->SetBanPlayerAction(std::move(*banPlayerAction));
    }

    StdExtra::optional<DeletePlayerStatisticSegmentAction> deletePlayerStatisticAction{};
    JsonUtils::ObjectGetMember(input, "DeletePlayerStatisticAction", deletePlayerStatisticAction);
    if (deletePlayerStatisticAction)
    {
        this->SetDeletePlayerStatisticAction(std::move(*deletePlayerStatisticAction));
    }

    StdExtra::optional<EmailNotificationSegmentAction> emailNotificationAction{};
    JsonUtils::ObjectGetMember(input, "EmailNotificationAction", emailNotificationAction);
    if (emailNotificationAction)
    {
        this->SetEmailNotificationAction(std::move(*emailNotificationAction));
    }

    StdExtra::optional<ExecuteAzureFunctionSegmentAction> executeAzureFunctionAction{};
    JsonUtils::ObjectGetMember(input, "ExecuteAzureFunctionAction", executeAzureFunctionAction);
    if (executeAzureFunctionAction)
    {
        this->SetExecuteAzureFunctionAction(std::move(*executeAzureFunctionAction));
    }

    StdExtra::optional<ExecuteCloudScriptSegmentAction> executeCloudScriptAction{};
    JsonUtils::ObjectGetMember(input, "ExecuteCloudScriptAction", executeCloudScriptAction);
    if (executeCloudScriptAction)
    {
        this->SetExecuteCloudScriptAction(std::move(*executeCloudScriptAction));
    }

    StdExtra::optional<GrantItemSegmentAction> grantItemAction{};
    JsonUtils::ObjectGetMember(input, "GrantItemAction", grantItemAction);
    if (grantItemAction)
    {
        this->SetGrantItemAction(std::move(*grantItemAction));
    }

    StdExtra::optional<GrantVirtualCurrencySegmentAction> grantVirtualCurrencyAction{};
    JsonUtils::ObjectGetMember(input, "GrantVirtualCurrencyAction", grantVirtualCurrencyAction);
    if (grantVirtualCurrencyAction)
    {
        this->SetGrantVirtualCurrencyAction(std::move(*grantVirtualCurrencyAction));
    }

    StdExtra::optional<IncrementPlayerStatisticSegmentAction> incrementPlayerStatisticAction{};
    JsonUtils::ObjectGetMember(input, "IncrementPlayerStatisticAction", incrementPlayerStatisticAction);
    if (incrementPlayerStatisticAction)
    {
        this->SetIncrementPlayerStatisticAction(std::move(*incrementPlayerStatisticAction));
    }

    StdExtra::optional<PushNotificationSegmentAction> pushNotificationAction{};
    JsonUtils::ObjectGetMember(input, "PushNotificationAction", pushNotificationAction);
    if (pushNotificationAction)
    {
        this->SetPushNotificationAction(std::move(*pushNotificationAction));
    }
}

size_t SegmentTrigger::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsSegmentTrigger const*> SegmentTrigger::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SegmentTrigger>(&this->Model());
}

size_t SegmentTrigger::RequiredBufferSize(const PFSegmentsSegmentTrigger& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.banPlayerAction)
    {
        requiredSize += BanPlayerSegmentAction::RequiredBufferSize(*model.banPlayerAction);
    }
    if (model.deletePlayerStatisticAction)
    {
        requiredSize += DeletePlayerStatisticSegmentAction::RequiredBufferSize(*model.deletePlayerStatisticAction);
    }
    if (model.emailNotificationAction)
    {
        requiredSize += EmailNotificationSegmentAction::RequiredBufferSize(*model.emailNotificationAction);
    }
    if (model.executeAzureFunctionAction)
    {
        requiredSize += ExecuteAzureFunctionSegmentAction::RequiredBufferSize(*model.executeAzureFunctionAction);
    }
    if (model.executeCloudScriptAction)
    {
        requiredSize += ExecuteCloudScriptSegmentAction::RequiredBufferSize(*model.executeCloudScriptAction);
    }
    if (model.grantItemAction)
    {
        requiredSize += GrantItemSegmentAction::RequiredBufferSize(*model.grantItemAction);
    }
    if (model.grantVirtualCurrencyAction)
    {
        requiredSize += GrantVirtualCurrencySegmentAction::RequiredBufferSize(*model.grantVirtualCurrencyAction);
    }
    if (model.incrementPlayerStatisticAction)
    {
        requiredSize += IncrementPlayerStatisticSegmentAction::RequiredBufferSize(*model.incrementPlayerStatisticAction);
    }
    if (model.pushNotificationAction)
    {
        requiredSize += PushNotificationSegmentAction::RequiredBufferSize(*model.pushNotificationAction);
    }
    return requiredSize;
}

HRESULT SegmentTrigger::Copy(const PFSegmentsSegmentTrigger& input, PFSegmentsSegmentTrigger& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<BanPlayerSegmentAction>(input.banPlayerAction); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.banPlayerAction = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<DeletePlayerStatisticSegmentAction>(input.deletePlayerStatisticAction); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.deletePlayerStatisticAction = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EmailNotificationSegmentAction>(input.emailNotificationAction); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.emailNotificationAction = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ExecuteAzureFunctionSegmentAction>(input.executeAzureFunctionAction); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.executeAzureFunctionAction = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ExecuteCloudScriptSegmentAction>(input.executeCloudScriptAction); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.executeCloudScriptAction = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<GrantItemSegmentAction>(input.grantItemAction); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.grantItemAction = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<GrantVirtualCurrencySegmentAction>(input.grantVirtualCurrencyAction); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.grantVirtualCurrencyAction = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<IncrementPlayerStatisticSegmentAction>(input.incrementPlayerStatisticAction); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.incrementPlayerStatisticAction = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<PushNotificationSegmentAction>(input.pushNotificationAction); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pushNotificationAction = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AdCampaignSegmentFilter::ToJson() const
{
    return AdCampaignSegmentFilter::ToJson(this->Model());
}

JsonValue AdCampaignSegmentFilter::ToJson(const PFSegmentsAdCampaignSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CampaignId", input.campaignId);
    JsonUtils::ObjectAddMember(output, "CampaignSource", input.campaignSource);
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    return output;
}

void AdCampaignSegmentFilter::FromJson(const JsonValue& input)
{
    String campaignId{};
    JsonUtils::ObjectGetMember(input, "CampaignId", campaignId);
    this->SetCampaignId(std::move(campaignId));

    String campaignSource{};
    JsonUtils::ObjectGetMember(input, "CampaignSource", campaignSource);
    this->SetCampaignSource(std::move(campaignSource));

    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));
}

size_t AdCampaignSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsAdCampaignSegmentFilter const*> AdCampaignSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AdCampaignSegmentFilter>(&this->Model());
}

size_t AdCampaignSegmentFilter::RequiredBufferSize(const PFSegmentsAdCampaignSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.campaignId)
    {
        requiredSize += (std::strlen(model.campaignId) + 1);
    }
    if (model.campaignSource)
    {
        requiredSize += (std::strlen(model.campaignSource) + 1);
    }
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    return requiredSize;
}

HRESULT AdCampaignSegmentFilter::Copy(const PFSegmentsAdCampaignSegmentFilter& input, PFSegmentsAdCampaignSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.campaignId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.campaignId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.campaignSource); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.campaignSource = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue FirstLoginDateSegmentFilter::ToJson() const
{
    return FirstLoginDateSegmentFilter::ToJson(this->Model());
}

JsonValue FirstLoginDateSegmentFilter::ToJson(const PFSegmentsFirstLoginDateSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMemberTime(output, "LogInDate", input.logInDate);
    return output;
}

void FirstLoginDateSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    JsonUtils::ObjectGetMemberTime(input, "LogInDate", this->m_model.logInDate);
}

size_t FirstLoginDateSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsFirstLoginDateSegmentFilter const*> FirstLoginDateSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<FirstLoginDateSegmentFilter>(&this->Model());
}

size_t FirstLoginDateSegmentFilter::RequiredBufferSize(const PFSegmentsFirstLoginDateSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    return requiredSize;
}

HRESULT FirstLoginDateSegmentFilter::Copy(const PFSegmentsFirstLoginDateSegmentFilter& input, PFSegmentsFirstLoginDateSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue FirstLoginTimespanSegmentFilter::ToJson() const
{
    return FirstLoginTimespanSegmentFilter::ToJson(this->Model());
}

JsonValue FirstLoginTimespanSegmentFilter::ToJson(const PFSegmentsFirstLoginTimespanSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMember(output, "DurationInMinutes", input.durationInMinutes);
    return output;
}

void FirstLoginTimespanSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    JsonUtils::ObjectGetMember(input, "DurationInMinutes", this->m_model.durationInMinutes);
}

size_t FirstLoginTimespanSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsFirstLoginTimespanSegmentFilter const*> FirstLoginTimespanSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<FirstLoginTimespanSegmentFilter>(&this->Model());
}

size_t FirstLoginTimespanSegmentFilter::RequiredBufferSize(const PFSegmentsFirstLoginTimespanSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    return requiredSize;
}

HRESULT FirstLoginTimespanSegmentFilter::Copy(const PFSegmentsFirstLoginTimespanSegmentFilter& input, PFSegmentsFirstLoginTimespanSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue LastLoginDateSegmentFilter::ToJson() const
{
    return LastLoginDateSegmentFilter::ToJson(this->Model());
}

JsonValue LastLoginDateSegmentFilter::ToJson(const PFSegmentsLastLoginDateSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMemberTime(output, "LogInDate", input.logInDate);
    return output;
}

void LastLoginDateSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    JsonUtils::ObjectGetMemberTime(input, "LogInDate", this->m_model.logInDate);
}

size_t LastLoginDateSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsLastLoginDateSegmentFilter const*> LastLoginDateSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<LastLoginDateSegmentFilter>(&this->Model());
}

size_t LastLoginDateSegmentFilter::RequiredBufferSize(const PFSegmentsLastLoginDateSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    return requiredSize;
}

HRESULT LastLoginDateSegmentFilter::Copy(const PFSegmentsLastLoginDateSegmentFilter& input, PFSegmentsLastLoginDateSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue LastLoginTimespanSegmentFilter::ToJson() const
{
    return LastLoginTimespanSegmentFilter::ToJson(this->Model());
}

JsonValue LastLoginTimespanSegmentFilter::ToJson(const PFSegmentsLastLoginTimespanSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMember(output, "DurationInMinutes", input.durationInMinutes);
    return output;
}

void LastLoginTimespanSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    JsonUtils::ObjectGetMember(input, "DurationInMinutes", this->m_model.durationInMinutes);
}

size_t LastLoginTimespanSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsLastLoginTimespanSegmentFilter const*> LastLoginTimespanSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<LastLoginTimespanSegmentFilter>(&this->Model());
}

size_t LastLoginTimespanSegmentFilter::RequiredBufferSize(const PFSegmentsLastLoginTimespanSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    return requiredSize;
}

HRESULT LastLoginTimespanSegmentFilter::Copy(const PFSegmentsLastLoginTimespanSegmentFilter& input, PFSegmentsLastLoginTimespanSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue LinkedUserAccountSegmentFilter::ToJson() const
{
    return LinkedUserAccountSegmentFilter::ToJson(this->Model());
}

JsonValue LinkedUserAccountSegmentFilter::ToJson(const PFSegmentsLinkedUserAccountSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "LoginProvider", input.loginProvider);
    return output;
}

void LinkedUserAccountSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider> loginProvider{};
    JsonUtils::ObjectGetMember(input, "LoginProvider", loginProvider);
    this->SetLoginProvider(std::move(loginProvider));
}

size_t LinkedUserAccountSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsLinkedUserAccountSegmentFilter const*> LinkedUserAccountSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<LinkedUserAccountSegmentFilter>(&this->Model());
}

size_t LinkedUserAccountSegmentFilter::RequiredBufferSize(const PFSegmentsLinkedUserAccountSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.loginProvider)
    {
        requiredSize += (alignof(PFSegmentsSegmentLoginIdentityProvider) + sizeof(PFSegmentsSegmentLoginIdentityProvider));
    }
    return requiredSize;
}

HRESULT LinkedUserAccountSegmentFilter::Copy(const PFSegmentsLinkedUserAccountSegmentFilter& input, PFSegmentsLinkedUserAccountSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.loginProvider); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.loginProvider = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue LinkedUserAccountHasEmailSegmentFilter::ToJson() const
{
    return LinkedUserAccountHasEmailSegmentFilter::ToJson(this->Model());
}

JsonValue LinkedUserAccountHasEmailSegmentFilter::ToJson(const PFSegmentsLinkedUserAccountHasEmailSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMember(output, "LoginProvider", input.loginProvider);
    return output;
}

void LinkedUserAccountHasEmailSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider> loginProvider{};
    JsonUtils::ObjectGetMember(input, "LoginProvider", loginProvider);
    this->SetLoginProvider(std::move(loginProvider));
}

size_t LinkedUserAccountHasEmailSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsLinkedUserAccountHasEmailSegmentFilter const*> LinkedUserAccountHasEmailSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<LinkedUserAccountHasEmailSegmentFilter>(&this->Model());
}

size_t LinkedUserAccountHasEmailSegmentFilter::RequiredBufferSize(const PFSegmentsLinkedUserAccountHasEmailSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    if (model.loginProvider)
    {
        requiredSize += (alignof(PFSegmentsSegmentLoginIdentityProvider) + sizeof(PFSegmentsSegmentLoginIdentityProvider));
    }
    return requiredSize;
}

HRESULT LinkedUserAccountHasEmailSegmentFilter::Copy(const PFSegmentsLinkedUserAccountHasEmailSegmentFilter& input, PFSegmentsLinkedUserAccountHasEmailSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.loginProvider); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.loginProvider = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue LocationSegmentFilter::ToJson() const
{
    return LocationSegmentFilter::ToJson(this->Model());
}

JsonValue LocationSegmentFilter::ToJson(const PFSegmentsLocationSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CountryCode", input.countryCode);
    return output;
}

void LocationSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentCountryCode> countryCode{};
    JsonUtils::ObjectGetMember(input, "CountryCode", countryCode);
    this->SetCountryCode(std::move(countryCode));
}

size_t LocationSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsLocationSegmentFilter const*> LocationSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<LocationSegmentFilter>(&this->Model());
}

size_t LocationSegmentFilter::RequiredBufferSize(const PFSegmentsLocationSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.countryCode)
    {
        requiredSize += (alignof(PFSegmentsSegmentCountryCode) + sizeof(PFSegmentsSegmentCountryCode));
    }
    return requiredSize;
}

HRESULT LocationSegmentFilter::Copy(const PFSegmentsLocationSegmentFilter& input, PFSegmentsLocationSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.countryCode); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.countryCode = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PlayerChurnPredictionSegmentFilter::ToJson() const
{
    return PlayerChurnPredictionSegmentFilter::ToJson(this->Model());
}

JsonValue PlayerChurnPredictionSegmentFilter::ToJson(const PFSegmentsPlayerChurnPredictionSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMember(output, "RiskLevel", input.riskLevel);
    return output;
}

void PlayerChurnPredictionSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    StdExtra::optional<PFSegmentsChurnRiskLevel> riskLevel{};
    JsonUtils::ObjectGetMember(input, "RiskLevel", riskLevel);
    this->SetRiskLevel(std::move(riskLevel));
}

size_t PlayerChurnPredictionSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsPlayerChurnPredictionSegmentFilter const*> PlayerChurnPredictionSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerChurnPredictionSegmentFilter>(&this->Model());
}

size_t PlayerChurnPredictionSegmentFilter::RequiredBufferSize(const PFSegmentsPlayerChurnPredictionSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    if (model.riskLevel)
    {
        requiredSize += (alignof(PFSegmentsChurnRiskLevel) + sizeof(PFSegmentsChurnRiskLevel));
    }
    return requiredSize;
}

HRESULT PlayerChurnPredictionSegmentFilter::Copy(const PFSegmentsPlayerChurnPredictionSegmentFilter& input, PFSegmentsPlayerChurnPredictionSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.riskLevel); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.riskLevel = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PlayerChurnPredictionTimeSegmentFilter::ToJson() const
{
    return PlayerChurnPredictionTimeSegmentFilter::ToJson(this->Model());
}

JsonValue PlayerChurnPredictionTimeSegmentFilter::ToJson(const PFSegmentsPlayerChurnPredictionTimeSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMember(output, "DurationInDays", input.durationInDays);
    return output;
}

void PlayerChurnPredictionTimeSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    JsonUtils::ObjectGetMember(input, "DurationInDays", this->m_model.durationInDays);
}

size_t PlayerChurnPredictionTimeSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsPlayerChurnPredictionTimeSegmentFilter const*> PlayerChurnPredictionTimeSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerChurnPredictionTimeSegmentFilter>(&this->Model());
}

size_t PlayerChurnPredictionTimeSegmentFilter::RequiredBufferSize(const PFSegmentsPlayerChurnPredictionTimeSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    return requiredSize;
}

HRESULT PlayerChurnPredictionTimeSegmentFilter::Copy(const PFSegmentsPlayerChurnPredictionTimeSegmentFilter& input, PFSegmentsPlayerChurnPredictionTimeSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PlayerChurnPreviousPredictionSegmentFilter::ToJson() const
{
    return PlayerChurnPreviousPredictionSegmentFilter::ToJson(this->Model());
}

JsonValue PlayerChurnPreviousPredictionSegmentFilter::ToJson(const PFSegmentsPlayerChurnPreviousPredictionSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMember(output, "RiskLevel", input.riskLevel);
    return output;
}

void PlayerChurnPreviousPredictionSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    StdExtra::optional<PFSegmentsChurnRiskLevel> riskLevel{};
    JsonUtils::ObjectGetMember(input, "RiskLevel", riskLevel);
    this->SetRiskLevel(std::move(riskLevel));
}

size_t PlayerChurnPreviousPredictionSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsPlayerChurnPreviousPredictionSegmentFilter const*> PlayerChurnPreviousPredictionSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerChurnPreviousPredictionSegmentFilter>(&this->Model());
}

size_t PlayerChurnPreviousPredictionSegmentFilter::RequiredBufferSize(const PFSegmentsPlayerChurnPreviousPredictionSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    if (model.riskLevel)
    {
        requiredSize += (alignof(PFSegmentsChurnRiskLevel) + sizeof(PFSegmentsChurnRiskLevel));
    }
    return requiredSize;
}

HRESULT PlayerChurnPreviousPredictionSegmentFilter::Copy(const PFSegmentsPlayerChurnPreviousPredictionSegmentFilter& input, PFSegmentsPlayerChurnPreviousPredictionSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.riskLevel); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.riskLevel = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PushNotificationSegmentFilter::ToJson() const
{
    return PushNotificationSegmentFilter::ToJson(this->Model());
}

JsonValue PushNotificationSegmentFilter::ToJson(const PFSegmentsPushNotificationSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PushNotificationDevicePlatform", input.pushNotificationDevicePlatform);
    return output;
}

void PushNotificationSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentPushNotificationDevicePlatform> pushNotificationDevicePlatform{};
    JsonUtils::ObjectGetMember(input, "PushNotificationDevicePlatform", pushNotificationDevicePlatform);
    this->SetPushNotificationDevicePlatform(std::move(pushNotificationDevicePlatform));
}

size_t PushNotificationSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsPushNotificationSegmentFilter const*> PushNotificationSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PushNotificationSegmentFilter>(&this->Model());
}

size_t PushNotificationSegmentFilter::RequiredBufferSize(const PFSegmentsPushNotificationSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.pushNotificationDevicePlatform)
    {
        requiredSize += (alignof(PFSegmentsSegmentPushNotificationDevicePlatform) + sizeof(PFSegmentsSegmentPushNotificationDevicePlatform));
    }
    return requiredSize;
}

HRESULT PushNotificationSegmentFilter::Copy(const PFSegmentsPushNotificationSegmentFilter& input, PFSegmentsPushNotificationSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.pushNotificationDevicePlatform); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pushNotificationDevicePlatform = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue StatisticSegmentFilter::ToJson() const
{
    return StatisticSegmentFilter::ToJson(this->Model());
}

JsonValue StatisticSegmentFilter::ToJson(const PFSegmentsStatisticSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMember(output, "FilterValue", input.filterValue);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "UseCurrentVersion", input.useCurrentVersion);
    JsonUtils::ObjectAddMember(output, "Version", input.version);
    return output;
}

void StatisticSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    String filterValue{};
    JsonUtils::ObjectGetMember(input, "FilterValue", filterValue);
    this->SetFilterValue(std::move(filterValue));

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    StdExtra::optional<bool> useCurrentVersion{};
    JsonUtils::ObjectGetMember(input, "UseCurrentVersion", useCurrentVersion);
    this->SetUseCurrentVersion(std::move(useCurrentVersion));

    StdExtra::optional<int32_t> version{};
    JsonUtils::ObjectGetMember(input, "Version", version);
    this->SetVersion(std::move(version));
}

size_t StatisticSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsStatisticSegmentFilter const*> StatisticSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<StatisticSegmentFilter>(&this->Model());
}

size_t StatisticSegmentFilter::RequiredBufferSize(const PFSegmentsStatisticSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    if (model.filterValue)
    {
        requiredSize += (std::strlen(model.filterValue) + 1);
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    if (model.useCurrentVersion)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    if (model.version)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    return requiredSize;
}

HRESULT StatisticSegmentFilter::Copy(const PFSegmentsStatisticSegmentFilter& input, PFSegmentsStatisticSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.filterValue); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.filterValue = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.useCurrentVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.useCurrentVersion = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.version); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.version = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue TagSegmentFilter::ToJson() const
{
    return TagSegmentFilter::ToJson(this->Model());
}

JsonValue TagSegmentFilter::ToJson(const PFSegmentsTagSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMember(output, "TagValue", input.tagValue);
    return output;
}

void TagSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    String tagValue{};
    JsonUtils::ObjectGetMember(input, "TagValue", tagValue);
    this->SetTagValue(std::move(tagValue));
}

size_t TagSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsTagSegmentFilter const*> TagSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<TagSegmentFilter>(&this->Model());
}

size_t TagSegmentFilter::RequiredBufferSize(const PFSegmentsTagSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    if (model.tagValue)
    {
        requiredSize += (std::strlen(model.tagValue) + 1);
    }
    return requiredSize;
}

HRESULT TagSegmentFilter::Copy(const PFSegmentsTagSegmentFilter& input, PFSegmentsTagSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.tagValue); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tagValue = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue TotalValueToDateInUSDSegmentFilter::ToJson() const
{
    return TotalValueToDateInUSDSegmentFilter::ToJson(this->Model());
}

JsonValue TotalValueToDateInUSDSegmentFilter::ToJson(const PFSegmentsTotalValueToDateInUSDSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    return output;
}

void TotalValueToDateInUSDSegmentFilter::FromJson(const JsonValue& input)
{
    String amount{};
    JsonUtils::ObjectGetMember(input, "Amount", amount);
    this->SetAmount(std::move(amount));

    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));
}

size_t TotalValueToDateInUSDSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsTotalValueToDateInUSDSegmentFilter const*> TotalValueToDateInUSDSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<TotalValueToDateInUSDSegmentFilter>(&this->Model());
}

size_t TotalValueToDateInUSDSegmentFilter::RequiredBufferSize(const PFSegmentsTotalValueToDateInUSDSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.amount)
    {
        requiredSize += (std::strlen(model.amount) + 1);
    }
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    return requiredSize;
}

HRESULT TotalValueToDateInUSDSegmentFilter::Copy(const PFSegmentsTotalValueToDateInUSDSegmentFilter& input, PFSegmentsTotalValueToDateInUSDSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.amount); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.amount = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue UserOriginationSegmentFilter::ToJson() const
{
    return UserOriginationSegmentFilter::ToJson(this->Model());
}

JsonValue UserOriginationSegmentFilter::ToJson(const PFSegmentsUserOriginationSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "LoginProvider", input.loginProvider);
    return output;
}

void UserOriginationSegmentFilter::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFSegmentsSegmentLoginIdentityProvider> loginProvider{};
    JsonUtils::ObjectGetMember(input, "LoginProvider", loginProvider);
    this->SetLoginProvider(std::move(loginProvider));
}

size_t UserOriginationSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsUserOriginationSegmentFilter const*> UserOriginationSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UserOriginationSegmentFilter>(&this->Model());
}

size_t UserOriginationSegmentFilter::RequiredBufferSize(const PFSegmentsUserOriginationSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.loginProvider)
    {
        requiredSize += (alignof(PFSegmentsSegmentLoginIdentityProvider) + sizeof(PFSegmentsSegmentLoginIdentityProvider));
    }
    return requiredSize;
}

HRESULT UserOriginationSegmentFilter::Copy(const PFSegmentsUserOriginationSegmentFilter& input, PFSegmentsUserOriginationSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.loginProvider); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.loginProvider = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ValueToDateSegmentFilter::ToJson() const
{
    return ValueToDateSegmentFilter::ToJson(this->Model());
}

JsonValue ValueToDateSegmentFilter::ToJson(const PFSegmentsValueToDateSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMember(output, "Currency", input.currency);
    return output;
}

void ValueToDateSegmentFilter::FromJson(const JsonValue& input)
{
    String amount{};
    JsonUtils::ObjectGetMember(input, "Amount", amount);
    this->SetAmount(std::move(amount));

    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    StdExtra::optional<PFSegmentsSegmentCurrency> currency{};
    JsonUtils::ObjectGetMember(input, "Currency", currency);
    this->SetCurrency(std::move(currency));
}

size_t ValueToDateSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsValueToDateSegmentFilter const*> ValueToDateSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ValueToDateSegmentFilter>(&this->Model());
}

size_t ValueToDateSegmentFilter::RequiredBufferSize(const PFSegmentsValueToDateSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.amount)
    {
        requiredSize += (std::strlen(model.amount) + 1);
    }
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    if (model.currency)
    {
        requiredSize += (alignof(PFSegmentsSegmentCurrency) + sizeof(PFSegmentsSegmentCurrency));
    }
    return requiredSize;
}

HRESULT ValueToDateSegmentFilter::Copy(const PFSegmentsValueToDateSegmentFilter& input, PFSegmentsValueToDateSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.amount); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.amount = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.currency); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.currency = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue VirtualCurrencyBalanceSegmentFilter::ToJson() const
{
    return VirtualCurrencyBalanceSegmentFilter::ToJson(this->Model());
}

JsonValue VirtualCurrencyBalanceSegmentFilter::ToJson(const PFSegmentsVirtualCurrencyBalanceSegmentFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "Comparison", input.comparison);
    JsonUtils::ObjectAddMember(output, "CurrencyCode", input.currencyCode);
    return output;
}

void VirtualCurrencyBalanceSegmentFilter::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Amount", this->m_model.amount);

    StdExtra::optional<PFSegmentsSegmentFilterComparison> comparison{};
    JsonUtils::ObjectGetMember(input, "Comparison", comparison);
    this->SetComparison(std::move(comparison));

    String currencyCode{};
    JsonUtils::ObjectGetMember(input, "CurrencyCode", currencyCode);
    this->SetCurrencyCode(std::move(currencyCode));
}

size_t VirtualCurrencyBalanceSegmentFilter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsVirtualCurrencyBalanceSegmentFilter const*> VirtualCurrencyBalanceSegmentFilter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<VirtualCurrencyBalanceSegmentFilter>(&this->Model());
}

size_t VirtualCurrencyBalanceSegmentFilter::RequiredBufferSize(const PFSegmentsVirtualCurrencyBalanceSegmentFilter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.comparison)
    {
        requiredSize += (alignof(PFSegmentsSegmentFilterComparison) + sizeof(PFSegmentsSegmentFilterComparison));
    }
    if (model.currencyCode)
    {
        requiredSize += (std::strlen(model.currencyCode) + 1);
    }
    return requiredSize;
}

HRESULT VirtualCurrencyBalanceSegmentFilter::Copy(const PFSegmentsVirtualCurrencyBalanceSegmentFilter& input, PFSegmentsVirtualCurrencyBalanceSegmentFilter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.comparison); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comparison = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.currencyCode); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.currencyCode = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue SegmentAndDefinition::ToJson() const
{
    return SegmentAndDefinition::ToJson(this->Model());
}

JsonValue SegmentAndDefinition::ToJson(const PFSegmentsSegmentAndDefinition& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<AdCampaignSegmentFilter>(output, "AdCampaignFilter", input.adCampaignFilter);
    JsonUtils::ObjectAddMember<FirstLoginDateSegmentFilter>(output, "FirstLoginDateFilter", input.firstLoginDateFilter);
    JsonUtils::ObjectAddMember<FirstLoginTimespanSegmentFilter>(output, "FirstLoginFilter", input.firstLoginFilter);
    JsonUtils::ObjectAddMember<LastLoginDateSegmentFilter>(output, "LastLoginDateFilter", input.lastLoginDateFilter);
    JsonUtils::ObjectAddMember<LastLoginTimespanSegmentFilter>(output, "LastLoginFilter", input.lastLoginFilter);
    JsonUtils::ObjectAddMember<LinkedUserAccountSegmentFilter>(output, "LinkedUserAccountFilter", input.linkedUserAccountFilter);
    JsonUtils::ObjectAddMember<LinkedUserAccountHasEmailSegmentFilter>(output, "LinkedUserAccountHasEmailFilter", input.linkedUserAccountHasEmailFilter);
    JsonUtils::ObjectAddMember<LocationSegmentFilter>(output, "LocationFilter", input.locationFilter);
    JsonUtils::ObjectAddMember<PlayerChurnPredictionSegmentFilter>(output, "PlayerChurnPredictionFilter", input.playerChurnPredictionFilter);
    JsonUtils::ObjectAddMember<PlayerChurnPredictionTimeSegmentFilter>(output, "PlayerChurnPredictionTimeFilter", input.playerChurnPredictionTimeFilter);
    JsonUtils::ObjectAddMember<PlayerChurnPreviousPredictionSegmentFilter>(output, "PlayerChurnPreviousPredictionFilter", input.playerChurnPreviousPredictionFilter);
    JsonUtils::ObjectAddMember<PushNotificationSegmentFilter>(output, "PushNotificationFilter", input.pushNotificationFilter);
    JsonUtils::ObjectAddMember<StatisticSegmentFilter>(output, "StatisticFilter", input.statisticFilter);
    JsonUtils::ObjectAddMember<TagSegmentFilter>(output, "TagFilter", input.tagFilter);
    JsonUtils::ObjectAddMember<TotalValueToDateInUSDSegmentFilter>(output, "TotalValueToDateInUSDFilter", input.totalValueToDateInUSDFilter);
    JsonUtils::ObjectAddMember<UserOriginationSegmentFilter>(output, "UserOriginationFilter", input.userOriginationFilter);
    JsonUtils::ObjectAddMember<ValueToDateSegmentFilter>(output, "ValueToDateFilter", input.valueToDateFilter);
    JsonUtils::ObjectAddMember<VirtualCurrencyBalanceSegmentFilter>(output, "VirtualCurrencyBalanceFilter", input.virtualCurrencyBalanceFilter);
    return output;
}

void SegmentAndDefinition::FromJson(const JsonValue& input)
{
    StdExtra::optional<AdCampaignSegmentFilter> adCampaignFilter{};
    JsonUtils::ObjectGetMember(input, "AdCampaignFilter", adCampaignFilter);
    if (adCampaignFilter)
    {
        this->SetAdCampaignFilter(std::move(*adCampaignFilter));
    }

    StdExtra::optional<FirstLoginDateSegmentFilter> firstLoginDateFilter{};
    JsonUtils::ObjectGetMember(input, "FirstLoginDateFilter", firstLoginDateFilter);
    if (firstLoginDateFilter)
    {
        this->SetFirstLoginDateFilter(std::move(*firstLoginDateFilter));
    }

    StdExtra::optional<FirstLoginTimespanSegmentFilter> firstLoginFilter{};
    JsonUtils::ObjectGetMember(input, "FirstLoginFilter", firstLoginFilter);
    if (firstLoginFilter)
    {
        this->SetFirstLoginFilter(std::move(*firstLoginFilter));
    }

    StdExtra::optional<LastLoginDateSegmentFilter> lastLoginDateFilter{};
    JsonUtils::ObjectGetMember(input, "LastLoginDateFilter", lastLoginDateFilter);
    if (lastLoginDateFilter)
    {
        this->SetLastLoginDateFilter(std::move(*lastLoginDateFilter));
    }

    StdExtra::optional<LastLoginTimespanSegmentFilter> lastLoginFilter{};
    JsonUtils::ObjectGetMember(input, "LastLoginFilter", lastLoginFilter);
    if (lastLoginFilter)
    {
        this->SetLastLoginFilter(std::move(*lastLoginFilter));
    }

    StdExtra::optional<LinkedUserAccountSegmentFilter> linkedUserAccountFilter{};
    JsonUtils::ObjectGetMember(input, "LinkedUserAccountFilter", linkedUserAccountFilter);
    if (linkedUserAccountFilter)
    {
        this->SetLinkedUserAccountFilter(std::move(*linkedUserAccountFilter));
    }

    StdExtra::optional<LinkedUserAccountHasEmailSegmentFilter> linkedUserAccountHasEmailFilter{};
    JsonUtils::ObjectGetMember(input, "LinkedUserAccountHasEmailFilter", linkedUserAccountHasEmailFilter);
    if (linkedUserAccountHasEmailFilter)
    {
        this->SetLinkedUserAccountHasEmailFilter(std::move(*linkedUserAccountHasEmailFilter));
    }

    StdExtra::optional<LocationSegmentFilter> locationFilter{};
    JsonUtils::ObjectGetMember(input, "LocationFilter", locationFilter);
    if (locationFilter)
    {
        this->SetLocationFilter(std::move(*locationFilter));
    }

    StdExtra::optional<PlayerChurnPredictionSegmentFilter> playerChurnPredictionFilter{};
    JsonUtils::ObjectGetMember(input, "PlayerChurnPredictionFilter", playerChurnPredictionFilter);
    if (playerChurnPredictionFilter)
    {
        this->SetPlayerChurnPredictionFilter(std::move(*playerChurnPredictionFilter));
    }

    StdExtra::optional<PlayerChurnPredictionTimeSegmentFilter> playerChurnPredictionTimeFilter{};
    JsonUtils::ObjectGetMember(input, "PlayerChurnPredictionTimeFilter", playerChurnPredictionTimeFilter);
    if (playerChurnPredictionTimeFilter)
    {
        this->SetPlayerChurnPredictionTimeFilter(std::move(*playerChurnPredictionTimeFilter));
    }

    StdExtra::optional<PlayerChurnPreviousPredictionSegmentFilter> playerChurnPreviousPredictionFilter{};
    JsonUtils::ObjectGetMember(input, "PlayerChurnPreviousPredictionFilter", playerChurnPreviousPredictionFilter);
    if (playerChurnPreviousPredictionFilter)
    {
        this->SetPlayerChurnPreviousPredictionFilter(std::move(*playerChurnPreviousPredictionFilter));
    }

    StdExtra::optional<PushNotificationSegmentFilter> pushNotificationFilter{};
    JsonUtils::ObjectGetMember(input, "PushNotificationFilter", pushNotificationFilter);
    if (pushNotificationFilter)
    {
        this->SetPushNotificationFilter(std::move(*pushNotificationFilter));
    }

    StdExtra::optional<StatisticSegmentFilter> statisticFilter{};
    JsonUtils::ObjectGetMember(input, "StatisticFilter", statisticFilter);
    if (statisticFilter)
    {
        this->SetStatisticFilter(std::move(*statisticFilter));
    }

    StdExtra::optional<TagSegmentFilter> tagFilter{};
    JsonUtils::ObjectGetMember(input, "TagFilter", tagFilter);
    if (tagFilter)
    {
        this->SetTagFilter(std::move(*tagFilter));
    }

    StdExtra::optional<TotalValueToDateInUSDSegmentFilter> totalValueToDateInUSDFilter{};
    JsonUtils::ObjectGetMember(input, "TotalValueToDateInUSDFilter", totalValueToDateInUSDFilter);
    if (totalValueToDateInUSDFilter)
    {
        this->SetTotalValueToDateInUSDFilter(std::move(*totalValueToDateInUSDFilter));
    }

    StdExtra::optional<UserOriginationSegmentFilter> userOriginationFilter{};
    JsonUtils::ObjectGetMember(input, "UserOriginationFilter", userOriginationFilter);
    if (userOriginationFilter)
    {
        this->SetUserOriginationFilter(std::move(*userOriginationFilter));
    }

    StdExtra::optional<ValueToDateSegmentFilter> valueToDateFilter{};
    JsonUtils::ObjectGetMember(input, "ValueToDateFilter", valueToDateFilter);
    if (valueToDateFilter)
    {
        this->SetValueToDateFilter(std::move(*valueToDateFilter));
    }

    StdExtra::optional<VirtualCurrencyBalanceSegmentFilter> virtualCurrencyBalanceFilter{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrencyBalanceFilter", virtualCurrencyBalanceFilter);
    if (virtualCurrencyBalanceFilter)
    {
        this->SetVirtualCurrencyBalanceFilter(std::move(*virtualCurrencyBalanceFilter));
    }
}

size_t SegmentAndDefinition::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsSegmentAndDefinition const*> SegmentAndDefinition::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SegmentAndDefinition>(&this->Model());
}

size_t SegmentAndDefinition::RequiredBufferSize(const PFSegmentsSegmentAndDefinition& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.adCampaignFilter)
    {
        requiredSize += AdCampaignSegmentFilter::RequiredBufferSize(*model.adCampaignFilter);
    }
    if (model.firstLoginDateFilter)
    {
        requiredSize += FirstLoginDateSegmentFilter::RequiredBufferSize(*model.firstLoginDateFilter);
    }
    if (model.firstLoginFilter)
    {
        requiredSize += FirstLoginTimespanSegmentFilter::RequiredBufferSize(*model.firstLoginFilter);
    }
    if (model.lastLoginDateFilter)
    {
        requiredSize += LastLoginDateSegmentFilter::RequiredBufferSize(*model.lastLoginDateFilter);
    }
    if (model.lastLoginFilter)
    {
        requiredSize += LastLoginTimespanSegmentFilter::RequiredBufferSize(*model.lastLoginFilter);
    }
    if (model.linkedUserAccountFilter)
    {
        requiredSize += LinkedUserAccountSegmentFilter::RequiredBufferSize(*model.linkedUserAccountFilter);
    }
    if (model.linkedUserAccountHasEmailFilter)
    {
        requiredSize += LinkedUserAccountHasEmailSegmentFilter::RequiredBufferSize(*model.linkedUserAccountHasEmailFilter);
    }
    if (model.locationFilter)
    {
        requiredSize += LocationSegmentFilter::RequiredBufferSize(*model.locationFilter);
    }
    if (model.playerChurnPredictionFilter)
    {
        requiredSize += PlayerChurnPredictionSegmentFilter::RequiredBufferSize(*model.playerChurnPredictionFilter);
    }
    if (model.playerChurnPredictionTimeFilter)
    {
        requiredSize += PlayerChurnPredictionTimeSegmentFilter::RequiredBufferSize(*model.playerChurnPredictionTimeFilter);
    }
    if (model.playerChurnPreviousPredictionFilter)
    {
        requiredSize += PlayerChurnPreviousPredictionSegmentFilter::RequiredBufferSize(*model.playerChurnPreviousPredictionFilter);
    }
    if (model.pushNotificationFilter)
    {
        requiredSize += PushNotificationSegmentFilter::RequiredBufferSize(*model.pushNotificationFilter);
    }
    if (model.statisticFilter)
    {
        requiredSize += StatisticSegmentFilter::RequiredBufferSize(*model.statisticFilter);
    }
    if (model.tagFilter)
    {
        requiredSize += TagSegmentFilter::RequiredBufferSize(*model.tagFilter);
    }
    if (model.totalValueToDateInUSDFilter)
    {
        requiredSize += TotalValueToDateInUSDSegmentFilter::RequiredBufferSize(*model.totalValueToDateInUSDFilter);
    }
    if (model.userOriginationFilter)
    {
        requiredSize += UserOriginationSegmentFilter::RequiredBufferSize(*model.userOriginationFilter);
    }
    if (model.valueToDateFilter)
    {
        requiredSize += ValueToDateSegmentFilter::RequiredBufferSize(*model.valueToDateFilter);
    }
    if (model.virtualCurrencyBalanceFilter)
    {
        requiredSize += VirtualCurrencyBalanceSegmentFilter::RequiredBufferSize(*model.virtualCurrencyBalanceFilter);
    }
    return requiredSize;
}

HRESULT SegmentAndDefinition::Copy(const PFSegmentsSegmentAndDefinition& input, PFSegmentsSegmentAndDefinition& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<AdCampaignSegmentFilter>(input.adCampaignFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.adCampaignFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<FirstLoginDateSegmentFilter>(input.firstLoginDateFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.firstLoginDateFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<FirstLoginTimespanSegmentFilter>(input.firstLoginFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.firstLoginFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<LastLoginDateSegmentFilter>(input.lastLoginDateFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lastLoginDateFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<LastLoginTimespanSegmentFilter>(input.lastLoginFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lastLoginFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<LinkedUserAccountSegmentFilter>(input.linkedUserAccountFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.linkedUserAccountFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<LinkedUserAccountHasEmailSegmentFilter>(input.linkedUserAccountHasEmailFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.linkedUserAccountHasEmailFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<LocationSegmentFilter>(input.locationFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.locationFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<PlayerChurnPredictionSegmentFilter>(input.playerChurnPredictionFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playerChurnPredictionFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<PlayerChurnPredictionTimeSegmentFilter>(input.playerChurnPredictionTimeFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playerChurnPredictionTimeFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<PlayerChurnPreviousPredictionSegmentFilter>(input.playerChurnPreviousPredictionFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playerChurnPreviousPredictionFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<PushNotificationSegmentFilter>(input.pushNotificationFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pushNotificationFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<StatisticSegmentFilter>(input.statisticFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statisticFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<TagSegmentFilter>(input.tagFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tagFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<TotalValueToDateInUSDSegmentFilter>(input.totalValueToDateInUSDFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.totalValueToDateInUSDFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<UserOriginationSegmentFilter>(input.userOriginationFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.userOriginationFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ValueToDateSegmentFilter>(input.valueToDateFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.valueToDateFilter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<VirtualCurrencyBalanceSegmentFilter>(input.virtualCurrencyBalanceFilter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyBalanceFilter = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue SegmentOrDefinition::ToJson() const
{
    return SegmentOrDefinition::ToJson(this->Model());
}

JsonValue SegmentOrDefinition::ToJson(const PFSegmentsSegmentOrDefinition& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<SegmentAndDefinition>(output, "SegmentAndDefinitions", input.segmentAndDefinitions, input.segmentAndDefinitionsCount);
    return output;
}

void SegmentOrDefinition::FromJson(const JsonValue& input)
{
    ModelVector<SegmentAndDefinition> segmentAndDefinitions{};
    JsonUtils::ObjectGetMember<SegmentAndDefinition>(input, "SegmentAndDefinitions", segmentAndDefinitions);
    this->SetSegmentAndDefinitions(std::move(segmentAndDefinitions));
}

size_t SegmentOrDefinition::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsSegmentOrDefinition const*> SegmentOrDefinition::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SegmentOrDefinition>(&this->Model());
}

size_t SegmentOrDefinition::RequiredBufferSize(const PFSegmentsSegmentOrDefinition& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFSegmentsSegmentAndDefinition*) + sizeof(PFSegmentsSegmentAndDefinition*) * model.segmentAndDefinitionsCount);
    for (size_t i = 0; i < model.segmentAndDefinitionsCount; ++i)
    {
        requiredSize += SegmentAndDefinition::RequiredBufferSize(*model.segmentAndDefinitions[i]);
    }
    return requiredSize;
}

HRESULT SegmentOrDefinition::Copy(const PFSegmentsSegmentOrDefinition& input, PFSegmentsSegmentOrDefinition& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<SegmentAndDefinition>(input.segmentAndDefinitions, input.segmentAndDefinitionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.segmentAndDefinitions = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue SegmentModel::ToJson() const
{
    return SegmentModel::ToJson(this->Model());
}

JsonValue SegmentModel::ToJson(const PFSegmentsSegmentModel& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMemberArray<SegmentTrigger>(output, "EnteredSegmentActions", input.enteredSegmentActions, input.enteredSegmentActionsCount);
    JsonUtils::ObjectAddMemberTime(output, "LastUpdateTime", input.lastUpdateTime);
    JsonUtils::ObjectAddMemberArray<SegmentTrigger>(output, "LeftSegmentActions", input.leftSegmentActions, input.leftSegmentActionsCount);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "SegmentId", input.segmentId);
    JsonUtils::ObjectAddMemberArray<SegmentOrDefinition>(output, "SegmentOrDefinitions", input.segmentOrDefinitions, input.segmentOrDefinitionsCount);
    return output;
}

void SegmentModel::FromJson(const JsonValue& input)
{
    String description{};
    JsonUtils::ObjectGetMember(input, "Description", description);
    this->SetDescription(std::move(description));

    ModelVector<SegmentTrigger> enteredSegmentActions{};
    JsonUtils::ObjectGetMember<SegmentTrigger>(input, "EnteredSegmentActions", enteredSegmentActions);
    this->SetEnteredSegmentActions(std::move(enteredSegmentActions));

    JsonUtils::ObjectGetMemberTime(input, "LastUpdateTime", this->m_model.lastUpdateTime);

    ModelVector<SegmentTrigger> leftSegmentActions{};
    JsonUtils::ObjectGetMember<SegmentTrigger>(input, "LeftSegmentActions", leftSegmentActions);
    this->SetLeftSegmentActions(std::move(leftSegmentActions));

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    String segmentId{};
    JsonUtils::ObjectGetMember(input, "SegmentId", segmentId);
    this->SetSegmentId(std::move(segmentId));

    ModelVector<SegmentOrDefinition> segmentOrDefinitions{};
    JsonUtils::ObjectGetMember<SegmentOrDefinition>(input, "SegmentOrDefinitions", segmentOrDefinitions);
    this->SetSegmentOrDefinitions(std::move(segmentOrDefinitions));
}

size_t SegmentModel::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsSegmentModel const*> SegmentModel::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SegmentModel>(&this->Model());
}

size_t SegmentModel::RequiredBufferSize(const PFSegmentsSegmentModel& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.description)
    {
        requiredSize += (std::strlen(model.description) + 1);
    }
    requiredSize += (alignof(PFSegmentsSegmentTrigger*) + sizeof(PFSegmentsSegmentTrigger*) * model.enteredSegmentActionsCount);
    for (size_t i = 0; i < model.enteredSegmentActionsCount; ++i)
    {
        requiredSize += SegmentTrigger::RequiredBufferSize(*model.enteredSegmentActions[i]);
    }
    requiredSize += (alignof(PFSegmentsSegmentTrigger*) + sizeof(PFSegmentsSegmentTrigger*) * model.leftSegmentActionsCount);
    for (size_t i = 0; i < model.leftSegmentActionsCount; ++i)
    {
        requiredSize += SegmentTrigger::RequiredBufferSize(*model.leftSegmentActions[i]);
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    if (model.segmentId)
    {
        requiredSize += (std::strlen(model.segmentId) + 1);
    }
    requiredSize += (alignof(PFSegmentsSegmentOrDefinition*) + sizeof(PFSegmentsSegmentOrDefinition*) * model.segmentOrDefinitionsCount);
    for (size_t i = 0; i < model.segmentOrDefinitionsCount; ++i)
    {
        requiredSize += SegmentOrDefinition::RequiredBufferSize(*model.segmentOrDefinitions[i]);
    }
    return requiredSize;
}

HRESULT SegmentModel::Copy(const PFSegmentsSegmentModel& input, PFSegmentsSegmentModel& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.description); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.description = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<SegmentTrigger>(input.enteredSegmentActions, input.enteredSegmentActionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.enteredSegmentActions = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<SegmentTrigger>(input.leftSegmentActions, input.leftSegmentActionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.leftSegmentActions = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.segmentId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.segmentId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<SegmentOrDefinition>(input.segmentOrDefinitions, input.segmentOrDefinitionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.segmentOrDefinitions = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateSegmentRequest::ToJson() const
{
    return CreateSegmentRequest::ToJson(this->Model());
}

JsonValue CreateSegmentRequest::ToJson(const PFSegmentsCreateSegmentRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<SegmentModel>(output, "SegmentModel", input.segmentModel);
    return output;
}

void CreateSegmentResponse::FromJson(const JsonValue& input)
{
    String errorMessage{};
    JsonUtils::ObjectGetMember(input, "ErrorMessage", errorMessage);
    this->SetErrorMessage(std::move(errorMessage));

    String segmentId{};
    JsonUtils::ObjectGetMember(input, "SegmentId", segmentId);
    this->SetSegmentId(std::move(segmentId));
}

size_t CreateSegmentResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsCreateSegmentResponse const*> CreateSegmentResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateSegmentResponse>(&this->Model());
}

size_t CreateSegmentResponse::RequiredBufferSize(const PFSegmentsCreateSegmentResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.errorMessage)
    {
        requiredSize += (std::strlen(model.errorMessage) + 1);
    }
    if (model.segmentId)
    {
        requiredSize += (std::strlen(model.segmentId) + 1);
    }
    return requiredSize;
}

HRESULT CreateSegmentResponse::Copy(const PFSegmentsCreateSegmentResponse& input, PFSegmentsCreateSegmentResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.errorMessage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.errorMessage = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.segmentId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.segmentId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue DeleteSegmentRequest::ToJson() const
{
    return DeleteSegmentRequest::ToJson(this->Model());
}

JsonValue DeleteSegmentRequest::ToJson(const PFSegmentsDeleteSegmentRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "SegmentId", input.segmentId);
    return output;
}

void DeleteSegmentsResponse::FromJson(const JsonValue& input)
{
    String errorMessage{};
    JsonUtils::ObjectGetMember(input, "ErrorMessage", errorMessage);
    this->SetErrorMessage(std::move(errorMessage));
}

size_t DeleteSegmentsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsDeleteSegmentsResponse const*> DeleteSegmentsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<DeleteSegmentsResponse>(&this->Model());
}

size_t DeleteSegmentsResponse::RequiredBufferSize(const PFSegmentsDeleteSegmentsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.errorMessage)
    {
        requiredSize += (std::strlen(model.errorMessage) + 1);
    }
    return requiredSize;
}

HRESULT DeleteSegmentsResponse::Copy(const PFSegmentsDeleteSegmentsResponse& input, PFSegmentsDeleteSegmentsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.errorMessage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.errorMessage = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetSegmentsRequest::ToJson() const
{
    return GetSegmentsRequest::ToJson(this->Model());
}

JsonValue GetSegmentsRequest::ToJson(const PFSegmentsGetSegmentsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "SegmentIds", input.segmentIds, input.segmentIdsCount);
    return output;
}

void GetSegmentsResponse::FromJson(const JsonValue& input)
{
    String errorMessage{};
    JsonUtils::ObjectGetMember(input, "ErrorMessage", errorMessage);
    this->SetErrorMessage(std::move(errorMessage));

    ModelVector<SegmentModel> segments{};
    JsonUtils::ObjectGetMember<SegmentModel>(input, "Segments", segments);
    this->SetSegments(std::move(segments));
}

size_t GetSegmentsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsGetSegmentsResponse const*> GetSegmentsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetSegmentsResponse>(&this->Model());
}

size_t GetSegmentsResponse::RequiredBufferSize(const PFSegmentsGetSegmentsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.errorMessage)
    {
        requiredSize += (std::strlen(model.errorMessage) + 1);
    }
    requiredSize += (alignof(PFSegmentsSegmentModel*) + sizeof(PFSegmentsSegmentModel*) * model.segmentsCount);
    for (size_t i = 0; i < model.segmentsCount; ++i)
    {
        requiredSize += SegmentModel::RequiredBufferSize(*model.segments[i]);
    }
    return requiredSize;
}

HRESULT GetSegmentsResponse::Copy(const PFSegmentsGetSegmentsResponse& input, PFSegmentsGetSegmentsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.errorMessage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.errorMessage = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<SegmentModel>(input.segments, input.segmentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.segments = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue UpdateSegmentRequest::ToJson() const
{
    return UpdateSegmentRequest::ToJson(this->Model());
}

JsonValue UpdateSegmentRequest::ToJson(const PFSegmentsUpdateSegmentRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<SegmentModel>(output, "SegmentModel", input.segmentModel);
    return output;
}

void UpdateSegmentResponse::FromJson(const JsonValue& input)
{
    String errorMessage{};
    JsonUtils::ObjectGetMember(input, "ErrorMessage", errorMessage);
    this->SetErrorMessage(std::move(errorMessage));

    String segmentId{};
    JsonUtils::ObjectGetMember(input, "SegmentId", segmentId);
    this->SetSegmentId(std::move(segmentId));
}

size_t UpdateSegmentResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFSegmentsUpdateSegmentResponse const*> UpdateSegmentResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UpdateSegmentResponse>(&this->Model());
}

size_t UpdateSegmentResponse::RequiredBufferSize(const PFSegmentsUpdateSegmentResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.errorMessage)
    {
        requiredSize += (std::strlen(model.errorMessage) + 1);
    }
    if (model.segmentId)
    {
        requiredSize += (std::strlen(model.segmentId) + 1);
    }
    return requiredSize;
}

HRESULT UpdateSegmentResponse::Copy(const PFSegmentsUpdateSegmentResponse& input, PFSegmentsUpdateSegmentResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.errorMessage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.errorMessage = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.segmentId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.segmentId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace Segments
} // namespace PlayFab
