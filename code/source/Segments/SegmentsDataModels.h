#pragma once

#include <playfab/cpp/PFSegmentsDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Segments
{

// Segments Classes
class BanPlayerSegmentAction : public Wrappers::PFSegmentsBanPlayerSegmentActionWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsBanPlayerSegmentAction>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsBanPlayerSegmentActionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsBanPlayerSegmentAction& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsBanPlayerSegmentAction const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsBanPlayerSegmentAction& model);
    static HRESULT Copy(const PFSegmentsBanPlayerSegmentAction& input, PFSegmentsBanPlayerSegmentAction& output, ModelBuffer& buffer);
};

class DeletePlayerStatisticSegmentAction : public Wrappers::PFSegmentsDeletePlayerStatisticSegmentActionWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsDeletePlayerStatisticSegmentAction>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsDeletePlayerStatisticSegmentActionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsDeletePlayerStatisticSegmentAction& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsDeletePlayerStatisticSegmentAction const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsDeletePlayerStatisticSegmentAction& model);
    static HRESULT Copy(const PFSegmentsDeletePlayerStatisticSegmentAction& input, PFSegmentsDeletePlayerStatisticSegmentAction& output, ModelBuffer& buffer);
};

class EmailNotificationSegmentAction : public Wrappers::PFSegmentsEmailNotificationSegmentActionWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsEmailNotificationSegmentAction>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsEmailNotificationSegmentActionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsEmailNotificationSegmentAction& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsEmailNotificationSegmentAction const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsEmailNotificationSegmentAction& model);
    static HRESULT Copy(const PFSegmentsEmailNotificationSegmentAction& input, PFSegmentsEmailNotificationSegmentAction& output, ModelBuffer& buffer);
};

class ExecuteAzureFunctionSegmentAction : public Wrappers::PFSegmentsExecuteAzureFunctionSegmentActionWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsExecuteAzureFunctionSegmentAction>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsExecuteAzureFunctionSegmentActionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsExecuteAzureFunctionSegmentAction& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsExecuteAzureFunctionSegmentAction const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsExecuteAzureFunctionSegmentAction& model);
    static HRESULT Copy(const PFSegmentsExecuteAzureFunctionSegmentAction& input, PFSegmentsExecuteAzureFunctionSegmentAction& output, ModelBuffer& buffer);
};

class ExecuteCloudScriptSegmentAction : public Wrappers::PFSegmentsExecuteCloudScriptSegmentActionWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsExecuteCloudScriptSegmentAction>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsExecuteCloudScriptSegmentActionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsExecuteCloudScriptSegmentAction& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsExecuteCloudScriptSegmentAction const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsExecuteCloudScriptSegmentAction& model);
    static HRESULT Copy(const PFSegmentsExecuteCloudScriptSegmentAction& input, PFSegmentsExecuteCloudScriptSegmentAction& output, ModelBuffer& buffer);
};

class GrantItemSegmentAction : public Wrappers::PFSegmentsGrantItemSegmentActionWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsGrantItemSegmentAction>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsGrantItemSegmentActionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsGrantItemSegmentAction& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsGrantItemSegmentAction const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsGrantItemSegmentAction& model);
    static HRESULT Copy(const PFSegmentsGrantItemSegmentAction& input, PFSegmentsGrantItemSegmentAction& output, ModelBuffer& buffer);
};

class GrantVirtualCurrencySegmentAction : public Wrappers::PFSegmentsGrantVirtualCurrencySegmentActionWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsGrantVirtualCurrencySegmentAction>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsGrantVirtualCurrencySegmentActionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsGrantVirtualCurrencySegmentAction& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsGrantVirtualCurrencySegmentAction const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsGrantVirtualCurrencySegmentAction& model);
    static HRESULT Copy(const PFSegmentsGrantVirtualCurrencySegmentAction& input, PFSegmentsGrantVirtualCurrencySegmentAction& output, ModelBuffer& buffer);
};

class IncrementPlayerStatisticSegmentAction : public Wrappers::PFSegmentsIncrementPlayerStatisticSegmentActionWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsIncrementPlayerStatisticSegmentAction>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsIncrementPlayerStatisticSegmentActionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsIncrementPlayerStatisticSegmentAction& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsIncrementPlayerStatisticSegmentAction const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsIncrementPlayerStatisticSegmentAction& model);
    static HRESULT Copy(const PFSegmentsIncrementPlayerStatisticSegmentAction& input, PFSegmentsIncrementPlayerStatisticSegmentAction& output, ModelBuffer& buffer);
};

class PushNotificationSegmentAction : public Wrappers::PFSegmentsPushNotificationSegmentActionWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsPushNotificationSegmentAction>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsPushNotificationSegmentActionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsPushNotificationSegmentAction& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsPushNotificationSegmentAction const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsPushNotificationSegmentAction& model);
    static HRESULT Copy(const PFSegmentsPushNotificationSegmentAction& input, PFSegmentsPushNotificationSegmentAction& output, ModelBuffer& buffer);
};

class SegmentTrigger : public Wrappers::PFSegmentsSegmentTriggerWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsSegmentTrigger>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsSegmentTriggerWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsSegmentTrigger& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsSegmentTrigger const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsSegmentTrigger& model);
    static HRESULT Copy(const PFSegmentsSegmentTrigger& input, PFSegmentsSegmentTrigger& output, ModelBuffer& buffer);
};

class AdCampaignSegmentFilter : public Wrappers::PFSegmentsAdCampaignSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsAdCampaignSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsAdCampaignSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsAdCampaignSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsAdCampaignSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsAdCampaignSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsAdCampaignSegmentFilter& input, PFSegmentsAdCampaignSegmentFilter& output, ModelBuffer& buffer);
};

class FirstLoginDateSegmentFilter : public Wrappers::PFSegmentsFirstLoginDateSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsFirstLoginDateSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsFirstLoginDateSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsFirstLoginDateSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsFirstLoginDateSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsFirstLoginDateSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsFirstLoginDateSegmentFilter& input, PFSegmentsFirstLoginDateSegmentFilter& output, ModelBuffer& buffer);
};

class FirstLoginTimespanSegmentFilter : public Wrappers::PFSegmentsFirstLoginTimespanSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsFirstLoginTimespanSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsFirstLoginTimespanSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsFirstLoginTimespanSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsFirstLoginTimespanSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsFirstLoginTimespanSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsFirstLoginTimespanSegmentFilter& input, PFSegmentsFirstLoginTimespanSegmentFilter& output, ModelBuffer& buffer);
};

class LastLoginDateSegmentFilter : public Wrappers::PFSegmentsLastLoginDateSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsLastLoginDateSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsLastLoginDateSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsLastLoginDateSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsLastLoginDateSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsLastLoginDateSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsLastLoginDateSegmentFilter& input, PFSegmentsLastLoginDateSegmentFilter& output, ModelBuffer& buffer);
};

class LastLoginTimespanSegmentFilter : public Wrappers::PFSegmentsLastLoginTimespanSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsLastLoginTimespanSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsLastLoginTimespanSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsLastLoginTimespanSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsLastLoginTimespanSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsLastLoginTimespanSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsLastLoginTimespanSegmentFilter& input, PFSegmentsLastLoginTimespanSegmentFilter& output, ModelBuffer& buffer);
};

class LinkedUserAccountSegmentFilter : public Wrappers::PFSegmentsLinkedUserAccountSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsLinkedUserAccountSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsLinkedUserAccountSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsLinkedUserAccountSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsLinkedUserAccountSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsLinkedUserAccountSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsLinkedUserAccountSegmentFilter& input, PFSegmentsLinkedUserAccountSegmentFilter& output, ModelBuffer& buffer);
};

class LinkedUserAccountHasEmailSegmentFilter : public Wrappers::PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsLinkedUserAccountHasEmailSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsLinkedUserAccountHasEmailSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsLinkedUserAccountHasEmailSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsLinkedUserAccountHasEmailSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsLinkedUserAccountHasEmailSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsLinkedUserAccountHasEmailSegmentFilter& input, PFSegmentsLinkedUserAccountHasEmailSegmentFilter& output, ModelBuffer& buffer);
};

class LocationSegmentFilter : public Wrappers::PFSegmentsLocationSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsLocationSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsLocationSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsLocationSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsLocationSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsLocationSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsLocationSegmentFilter& input, PFSegmentsLocationSegmentFilter& output, ModelBuffer& buffer);
};

class PushNotificationSegmentFilter : public Wrappers::PFSegmentsPushNotificationSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsPushNotificationSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsPushNotificationSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsPushNotificationSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsPushNotificationSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsPushNotificationSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsPushNotificationSegmentFilter& input, PFSegmentsPushNotificationSegmentFilter& output, ModelBuffer& buffer);
};

class StatisticSegmentFilter : public Wrappers::PFSegmentsStatisticSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsStatisticSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsStatisticSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsStatisticSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsStatisticSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsStatisticSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsStatisticSegmentFilter& input, PFSegmentsStatisticSegmentFilter& output, ModelBuffer& buffer);
};

class TagSegmentFilter : public Wrappers::PFSegmentsTagSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsTagSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsTagSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsTagSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsTagSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsTagSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsTagSegmentFilter& input, PFSegmentsTagSegmentFilter& output, ModelBuffer& buffer);
};

class TotalValueToDateInUSDSegmentFilter : public Wrappers::PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsTotalValueToDateInUSDSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsTotalValueToDateInUSDSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsTotalValueToDateInUSDSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsTotalValueToDateInUSDSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsTotalValueToDateInUSDSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsTotalValueToDateInUSDSegmentFilter& input, PFSegmentsTotalValueToDateInUSDSegmentFilter& output, ModelBuffer& buffer);
};

class UserOriginationSegmentFilter : public Wrappers::PFSegmentsUserOriginationSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsUserOriginationSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsUserOriginationSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsUserOriginationSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsUserOriginationSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsUserOriginationSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsUserOriginationSegmentFilter& input, PFSegmentsUserOriginationSegmentFilter& output, ModelBuffer& buffer);
};

class ValueToDateSegmentFilter : public Wrappers::PFSegmentsValueToDateSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsValueToDateSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsValueToDateSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsValueToDateSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsValueToDateSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsValueToDateSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsValueToDateSegmentFilter& input, PFSegmentsValueToDateSegmentFilter& output, ModelBuffer& buffer);
};

class VirtualCurrencyBalanceSegmentFilter : public Wrappers::PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsVirtualCurrencyBalanceSegmentFilter>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsVirtualCurrencyBalanceSegmentFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsVirtualCurrencyBalanceSegmentFilter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsVirtualCurrencyBalanceSegmentFilter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsVirtualCurrencyBalanceSegmentFilter& model);
    static HRESULT Copy(const PFSegmentsVirtualCurrencyBalanceSegmentFilter& input, PFSegmentsVirtualCurrencyBalanceSegmentFilter& output, ModelBuffer& buffer);
};

class SegmentAndDefinition : public Wrappers::PFSegmentsSegmentAndDefinitionWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsSegmentAndDefinition>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsSegmentAndDefinitionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsSegmentAndDefinition& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsSegmentAndDefinition const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsSegmentAndDefinition& model);
    static HRESULT Copy(const PFSegmentsSegmentAndDefinition& input, PFSegmentsSegmentAndDefinition& output, ModelBuffer& buffer);
};

class SegmentOrDefinition : public Wrappers::PFSegmentsSegmentOrDefinitionWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsSegmentOrDefinition>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsSegmentOrDefinitionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsSegmentOrDefinition& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsSegmentOrDefinition const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsSegmentOrDefinition& model);
    static HRESULT Copy(const PFSegmentsSegmentOrDefinition& input, PFSegmentsSegmentOrDefinition& output, ModelBuffer& buffer);
};

class SegmentModel : public Wrappers::PFSegmentsSegmentModelWrapper<Allocator>, public InputModel, public OutputModel<PFSegmentsSegmentModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsSegmentModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsSegmentModel& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsSegmentModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsSegmentModel& model);
    static HRESULT Copy(const PFSegmentsSegmentModel& input, PFSegmentsSegmentModel& output, ModelBuffer& buffer);
};

class CreateSegmentRequest : public Wrappers::PFSegmentsCreateSegmentRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsCreateSegmentRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsCreateSegmentRequest& input);

};

class CreateSegmentResponse : public Wrappers::PFSegmentsCreateSegmentResponseWrapper<Allocator>, public OutputModel<PFSegmentsCreateSegmentResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsCreateSegmentResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsCreateSegmentResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsCreateSegmentResponse& model);
    static HRESULT Copy(const PFSegmentsCreateSegmentResponse& input, PFSegmentsCreateSegmentResponse& output, ModelBuffer& buffer);
};

class DeleteSegmentRequest : public Wrappers::PFSegmentsDeleteSegmentRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsDeleteSegmentRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsDeleteSegmentRequest& input);

};

class DeleteSegmentsResponse : public Wrappers::PFSegmentsDeleteSegmentsResponseWrapper<Allocator>, public OutputModel<PFSegmentsDeleteSegmentsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsDeleteSegmentsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsDeleteSegmentsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsDeleteSegmentsResponse& model);
    static HRESULT Copy(const PFSegmentsDeleteSegmentsResponse& input, PFSegmentsDeleteSegmentsResponse& output, ModelBuffer& buffer);
};

class GetSegmentsRequest : public Wrappers::PFSegmentsGetSegmentsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsGetSegmentsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsGetSegmentsRequest& input);

};

class GetSegmentsResponse : public Wrappers::PFSegmentsGetSegmentsResponseWrapper<Allocator>, public OutputModel<PFSegmentsGetSegmentsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsGetSegmentsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsGetSegmentsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsGetSegmentsResponse& model);
    static HRESULT Copy(const PFSegmentsGetSegmentsResponse& input, PFSegmentsGetSegmentsResponse& output, ModelBuffer& buffer);
};

class UpdateSegmentRequest : public Wrappers::PFSegmentsUpdateSegmentRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsUpdateSegmentRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFSegmentsUpdateSegmentRequest& input);

};

class UpdateSegmentResponse : public Wrappers::PFSegmentsUpdateSegmentResponseWrapper<Allocator>, public OutputModel<PFSegmentsUpdateSegmentResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFSegmentsUpdateSegmentResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFSegmentsUpdateSegmentResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFSegmentsUpdateSegmentResponse& model);
    static HRESULT Copy(const PFSegmentsUpdateSegmentResponse& input, PFSegmentsUpdateSegmentResponse& output, ModelBuffer& buffer);
};

} // namespace Segments
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
