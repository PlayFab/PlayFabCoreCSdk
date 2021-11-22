#pragma once

#include <playfab/cpp/PFMultiplayerServerDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace MultiplayerServer
{

// MultiplayerServer Classes
class BuildSelectionCriterion : public Wrappers::PFMultiplayerServerBuildSelectionCriterionWrapper<Allocator>, public InputModel, public OutputModel<PFMultiplayerServerBuildSelectionCriterion>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerBuildSelectionCriterionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerBuildSelectionCriterion& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerBuildSelectionCriterion const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerBuildSelectionCriterion& model);
    static HRESULT Copy(const PFMultiplayerServerBuildSelectionCriterion& input, PFMultiplayerServerBuildSelectionCriterion& output, ModelBuffer& buffer);
};

class CreateBuildAliasRequest : public Wrappers::PFMultiplayerServerCreateBuildAliasRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCreateBuildAliasRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerCreateBuildAliasRequest& input);

};

class BuildAliasDetailsResponse : public Wrappers::PFMultiplayerServerBuildAliasDetailsResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerBuildAliasDetailsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerBuildAliasDetailsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerBuildAliasDetailsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerBuildAliasDetailsResponse& model);
    static HRESULT Copy(const PFMultiplayerServerBuildAliasDetailsResponse& input, PFMultiplayerServerBuildAliasDetailsResponse& output, ModelBuffer& buffer);
};

class ContainerImageReference : public Wrappers::PFMultiplayerServerContainerImageReferenceWrapper<Allocator>, public InputModel, public OutputModel<PFMultiplayerServerContainerImageReference>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerContainerImageReferenceWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerContainerImageReference& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerContainerImageReference const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerContainerImageReference& model);
    static HRESULT Copy(const PFMultiplayerServerContainerImageReference& input, PFMultiplayerServerContainerImageReference& output, ModelBuffer& buffer);
};

class AssetReferenceParams : public Wrappers::PFMultiplayerServerAssetReferenceParamsWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerAssetReferenceParamsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerAssetReferenceParams& input);

};

class GameCertificateReferenceParams : public Wrappers::PFMultiplayerServerGameCertificateReferenceParamsWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGameCertificateReferenceParamsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGameCertificateReferenceParams& input);

};

class LinuxInstrumentationConfiguration : public Wrappers::PFMultiplayerServerLinuxInstrumentationConfigurationWrapper<Allocator>, public InputModel, public OutputModel<PFMultiplayerServerLinuxInstrumentationConfiguration>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerLinuxInstrumentationConfigurationWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerLinuxInstrumentationConfiguration& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerLinuxInstrumentationConfiguration const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerLinuxInstrumentationConfiguration& model);
    static HRESULT Copy(const PFMultiplayerServerLinuxInstrumentationConfiguration& input, PFMultiplayerServerLinuxInstrumentationConfiguration& output, ModelBuffer& buffer);
};

class DynamicStandbyThreshold : public Wrappers::PFMultiplayerServerDynamicStandbyThresholdWrapper<Allocator>, public InputModel, public OutputModel<PFMultiplayerServerDynamicStandbyThreshold>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerDynamicStandbyThresholdWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerDynamicStandbyThreshold& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerDynamicStandbyThreshold const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerDynamicStandbyThreshold& model);
    static HRESULT Copy(const PFMultiplayerServerDynamicStandbyThreshold& input, PFMultiplayerServerDynamicStandbyThreshold& output, ModelBuffer& buffer);
};

class DynamicStandbySettings : public Wrappers::PFMultiplayerServerDynamicStandbySettingsWrapper<Allocator>, public InputModel, public OutputModel<PFMultiplayerServerDynamicStandbySettings>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerDynamicStandbySettingsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerDynamicStandbySettings& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerDynamicStandbySettings const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerDynamicStandbySettings& model);
    static HRESULT Copy(const PFMultiplayerServerDynamicStandbySettings& input, PFMultiplayerServerDynamicStandbySettings& output, ModelBuffer& buffer);
};

class Schedule : public Wrappers::PFMultiplayerServerScheduleWrapper<Allocator>, public InputModel, public OutputModel<PFMultiplayerServerSchedule>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerScheduleWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerSchedule& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerSchedule const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerSchedule& model);
    static HRESULT Copy(const PFMultiplayerServerSchedule& input, PFMultiplayerServerSchedule& output, ModelBuffer& buffer);
};

class ScheduledStandbySettings : public Wrappers::PFMultiplayerServerScheduledStandbySettingsWrapper<Allocator>, public InputModel, public OutputModel<PFMultiplayerServerScheduledStandbySettings>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerScheduledStandbySettingsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerScheduledStandbySettings& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerScheduledStandbySettings const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerScheduledStandbySettings& model);
    static HRESULT Copy(const PFMultiplayerServerScheduledStandbySettings& input, PFMultiplayerServerScheduledStandbySettings& output, ModelBuffer& buffer);
};

class BuildRegionParams : public Wrappers::PFMultiplayerServerBuildRegionParamsWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerBuildRegionParamsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerBuildRegionParams& input);

};

class CreateBuildWithCustomContainerRequest : public Wrappers::PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerCreateBuildWithCustomContainerRequest& input);

};

class AssetReference : public Wrappers::PFMultiplayerServerAssetReferenceWrapper<Allocator>, public OutputModel<PFMultiplayerServerAssetReference>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerAssetReferenceWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerAssetReference const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerAssetReference& model);
    static HRESULT Copy(const PFMultiplayerServerAssetReference& input, PFMultiplayerServerAssetReference& output, ModelBuffer& buffer);
};

class GameCertificateReference : public Wrappers::PFMultiplayerServerGameCertificateReferenceWrapper<Allocator>, public OutputModel<PFMultiplayerServerGameCertificateReference>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGameCertificateReferenceWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerGameCertificateReference const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerGameCertificateReference& model);
    static HRESULT Copy(const PFMultiplayerServerGameCertificateReference& input, PFMultiplayerServerGameCertificateReference& output, ModelBuffer& buffer);
};

class CurrentServerStats : public Wrappers::PFMultiplayerServerCurrentServerStatsWrapper<Allocator>, public OutputModel<PFMultiplayerServerCurrentServerStats>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCurrentServerStatsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerCurrentServerStats const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerCurrentServerStats& model);
    static HRESULT Copy(const PFMultiplayerServerCurrentServerStats& input, PFMultiplayerServerCurrentServerStats& output, ModelBuffer& buffer);
};

class BuildRegion : public Wrappers::PFMultiplayerServerBuildRegionWrapper<Allocator>, public OutputModel<PFMultiplayerServerBuildRegion>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerBuildRegionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerBuildRegion const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerBuildRegion& model);
    static HRESULT Copy(const PFMultiplayerServerBuildRegion& input, PFMultiplayerServerBuildRegion& output, ModelBuffer& buffer);
};

class CreateBuildWithCustomContainerResponse : public Wrappers::PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerCreateBuildWithCustomContainerResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerCreateBuildWithCustomContainerResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerCreateBuildWithCustomContainerResponse& model);
    static HRESULT Copy(const PFMultiplayerServerCreateBuildWithCustomContainerResponse& input, PFMultiplayerServerCreateBuildWithCustomContainerResponse& output, ModelBuffer& buffer);
};

class InstrumentationConfiguration : public Wrappers::PFMultiplayerServerInstrumentationConfigurationWrapper<Allocator>, public InputModel, public OutputModel<PFMultiplayerServerInstrumentationConfiguration>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerInstrumentationConfigurationWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerInstrumentationConfiguration& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerInstrumentationConfiguration const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerInstrumentationConfiguration& model);
    static HRESULT Copy(const PFMultiplayerServerInstrumentationConfiguration& input, PFMultiplayerServerInstrumentationConfiguration& output, ModelBuffer& buffer);
};

class CreateBuildWithManagedContainerRequest : public Wrappers::PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerCreateBuildWithManagedContainerRequest& input);

};

class CreateBuildWithManagedContainerResponse : public Wrappers::PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerCreateBuildWithManagedContainerResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerCreateBuildWithManagedContainerResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerCreateBuildWithManagedContainerResponse& model);
    static HRESULT Copy(const PFMultiplayerServerCreateBuildWithManagedContainerResponse& input, PFMultiplayerServerCreateBuildWithManagedContainerResponse& output, ModelBuffer& buffer);
};

class CreateBuildWithProcessBasedServerRequest : public Wrappers::PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerCreateBuildWithProcessBasedServerRequest& input);

};

class CreateBuildWithProcessBasedServerResponse : public Wrappers::PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerCreateBuildWithProcessBasedServerResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerCreateBuildWithProcessBasedServerResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerCreateBuildWithProcessBasedServerResponse& model);
    static HRESULT Copy(const PFMultiplayerServerCreateBuildWithProcessBasedServerResponse& input, PFMultiplayerServerCreateBuildWithProcessBasedServerResponse& output, ModelBuffer& buffer);
};

class CreateRemoteUserRequest : public Wrappers::PFMultiplayerServerCreateRemoteUserRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCreateRemoteUserRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerCreateRemoteUserRequest& input);

};

class CreateRemoteUserResponse : public Wrappers::PFMultiplayerServerCreateRemoteUserResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerCreateRemoteUserResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCreateRemoteUserResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerCreateRemoteUserResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerCreateRemoteUserResponse& model);
    static HRESULT Copy(const PFMultiplayerServerCreateRemoteUserResponse& input, PFMultiplayerServerCreateRemoteUserResponse& output, ModelBuffer& buffer);
};

class CoreCapacityChange : public Wrappers::PFMultiplayerServerCoreCapacityChangeWrapper<Allocator>, public InputModel, public OutputModel<PFMultiplayerServerCoreCapacityChange>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCoreCapacityChangeWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerCoreCapacityChange& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerCoreCapacityChange const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerCoreCapacityChange& model);
    static HRESULT Copy(const PFMultiplayerServerCoreCapacityChange& input, PFMultiplayerServerCoreCapacityChange& output, ModelBuffer& buffer);
};

class CreateTitleMultiplayerServersQuotaChangeRequest : public Wrappers::PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest& input);

};

class CreateTitleMultiplayerServersQuotaChangeResponse : public Wrappers::PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse& model);
    static HRESULT Copy(const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse& input, PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse& output, ModelBuffer& buffer);
};

class DeleteAssetRequest : public Wrappers::PFMultiplayerServerDeleteAssetRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerDeleteAssetRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerDeleteAssetRequest& input);

};

class DeleteBuildRequest : public Wrappers::PFMultiplayerServerDeleteBuildRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerDeleteBuildRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerDeleteBuildRequest& input);

};

class DeleteBuildAliasRequest : public Wrappers::PFMultiplayerServerDeleteBuildAliasRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerDeleteBuildAliasRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerDeleteBuildAliasRequest& input);

};

class DeleteBuildRegionRequest : public Wrappers::PFMultiplayerServerDeleteBuildRegionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerDeleteBuildRegionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerDeleteBuildRegionRequest& input);

};

class DeleteCertificateRequest : public Wrappers::PFMultiplayerServerDeleteCertificateRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerDeleteCertificateRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerDeleteCertificateRequest& input);

};

class DeleteContainerImageRequest : public Wrappers::PFMultiplayerServerDeleteContainerImageRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerDeleteContainerImageRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerDeleteContainerImageRequest& input);

};

class DeleteRemoteUserRequest : public Wrappers::PFMultiplayerServerDeleteRemoteUserRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerDeleteRemoteUserRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerDeleteRemoteUserRequest& input);

};

class EnableMultiplayerServersForTitleRequest : public Wrappers::PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerEnableMultiplayerServersForTitleRequest& input);

};

class EnableMultiplayerServersForTitleResponse : public Wrappers::PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerEnableMultiplayerServersForTitleResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerEnableMultiplayerServersForTitleResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerEnableMultiplayerServersForTitleResponse& model);
    static HRESULT Copy(const PFMultiplayerServerEnableMultiplayerServersForTitleResponse& input, PFMultiplayerServerEnableMultiplayerServersForTitleResponse& output, ModelBuffer& buffer);
};

class GetAssetDownloadUrlRequest : public Wrappers::PFMultiplayerServerGetAssetDownloadUrlRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetAssetDownloadUrlRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetAssetDownloadUrlRequest& input);

};

class GetAssetDownloadUrlResponse : public Wrappers::PFMultiplayerServerGetAssetDownloadUrlResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerGetAssetDownloadUrlResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetAssetDownloadUrlResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerGetAssetDownloadUrlResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerGetAssetDownloadUrlResponse& model);
    static HRESULT Copy(const PFMultiplayerServerGetAssetDownloadUrlResponse& input, PFMultiplayerServerGetAssetDownloadUrlResponse& output, ModelBuffer& buffer);
};

class GetAssetUploadUrlRequest : public Wrappers::PFMultiplayerServerGetAssetUploadUrlRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetAssetUploadUrlRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetAssetUploadUrlRequest& input);

};

class GetAssetUploadUrlResponse : public Wrappers::PFMultiplayerServerGetAssetUploadUrlResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerGetAssetUploadUrlResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetAssetUploadUrlResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerGetAssetUploadUrlResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerGetAssetUploadUrlResponse& model);
    static HRESULT Copy(const PFMultiplayerServerGetAssetUploadUrlResponse& input, PFMultiplayerServerGetAssetUploadUrlResponse& output, ModelBuffer& buffer);
};

class GetBuildRequest : public Wrappers::PFMultiplayerServerGetBuildRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetBuildRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetBuildRequest& input);

};

class GetBuildResponse : public Wrappers::PFMultiplayerServerGetBuildResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerGetBuildResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetBuildResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerGetBuildResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerGetBuildResponse& model);
    static HRESULT Copy(const PFMultiplayerServerGetBuildResponse& input, PFMultiplayerServerGetBuildResponse& output, ModelBuffer& buffer);
};

class GetBuildAliasRequest : public Wrappers::PFMultiplayerServerGetBuildAliasRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetBuildAliasRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetBuildAliasRequest& input);

};

class GetContainerRegistryCredentialsRequest : public Wrappers::PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetContainerRegistryCredentialsRequest& input);

};

class GetContainerRegistryCredentialsResponse : public Wrappers::PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerGetContainerRegistryCredentialsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerGetContainerRegistryCredentialsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerGetContainerRegistryCredentialsResponse& model);
    static HRESULT Copy(const PFMultiplayerServerGetContainerRegistryCredentialsResponse& input, PFMultiplayerServerGetContainerRegistryCredentialsResponse& output, ModelBuffer& buffer);
};

class GetMultiplayerServerDetailsRequest : public Wrappers::PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetMultiplayerServerDetailsRequest& input);

};

class ConnectedPlayer : public Wrappers::PFMultiplayerServerConnectedPlayerWrapper<Allocator>, public OutputModel<PFMultiplayerServerConnectedPlayer>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerConnectedPlayerWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerConnectedPlayer const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerConnectedPlayer& model);
    static HRESULT Copy(const PFMultiplayerServerConnectedPlayer& input, PFMultiplayerServerConnectedPlayer& output, ModelBuffer& buffer);
};

class GetMultiplayerServerDetailsResponse : public Wrappers::PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerGetMultiplayerServerDetailsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerGetMultiplayerServerDetailsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerGetMultiplayerServerDetailsResponse& model);
    static HRESULT Copy(const PFMultiplayerServerGetMultiplayerServerDetailsResponse& input, PFMultiplayerServerGetMultiplayerServerDetailsResponse& output, ModelBuffer& buffer);
};

class GetMultiplayerServerLogsRequest : public Wrappers::PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetMultiplayerServerLogsRequest& input);

};

class GetMultiplayerServerLogsResponse : public Wrappers::PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerGetMultiplayerServerLogsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerGetMultiplayerServerLogsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerGetMultiplayerServerLogsResponse& model);
    static HRESULT Copy(const PFMultiplayerServerGetMultiplayerServerLogsResponse& input, PFMultiplayerServerGetMultiplayerServerLogsResponse& output, ModelBuffer& buffer);
};

class GetMultiplayerSessionLogsBySessionIdRequest : public Wrappers::PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest& input);

};

class GetRemoteLoginEndpointRequest : public Wrappers::PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetRemoteLoginEndpointRequest& input);

};

class GetRemoteLoginEndpointResponse : public Wrappers::PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerGetRemoteLoginEndpointResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerGetRemoteLoginEndpointResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerGetRemoteLoginEndpointResponse& model);
    static HRESULT Copy(const PFMultiplayerServerGetRemoteLoginEndpointResponse& input, PFMultiplayerServerGetRemoteLoginEndpointResponse& output, ModelBuffer& buffer);
};

class GetTitleEnabledForMultiplayerServersStatusRequest : public Wrappers::PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest& input);

};

class GetTitleEnabledForMultiplayerServersStatusResponse : public Wrappers::PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse& model);
    static HRESULT Copy(const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse& input, PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse& output, ModelBuffer& buffer);
};

class GetTitleMultiplayerServersQuotaChangeRequest : public Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest& input);

};

class QuotaChange : public Wrappers::PFMultiplayerServerQuotaChangeWrapper<Allocator>, public OutputModel<PFMultiplayerServerQuotaChange>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerQuotaChangeWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerQuotaChange const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerQuotaChange& model);
    static HRESULT Copy(const PFMultiplayerServerQuotaChange& input, PFMultiplayerServerQuotaChange& output, ModelBuffer& buffer);
};

class GetTitleMultiplayerServersQuotaChangeResponse : public Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse& model);
    static HRESULT Copy(const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse& input, PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse& output, ModelBuffer& buffer);
};

class GetTitleMultiplayerServersQuotasRequest : public Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest& input);

};

class CoreCapacity : public Wrappers::PFMultiplayerServerCoreCapacityWrapper<Allocator>, public OutputModel<PFMultiplayerServerCoreCapacity>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCoreCapacityWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerCoreCapacity const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerCoreCapacity& model);
    static HRESULT Copy(const PFMultiplayerServerCoreCapacity& input, PFMultiplayerServerCoreCapacity& output, ModelBuffer& buffer);
};

class TitleMultiplayerServersQuotas : public Wrappers::PFMultiplayerServerTitleMultiplayerServersQuotasWrapper<Allocator>, public OutputModel<PFMultiplayerServerTitleMultiplayerServersQuotas>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerTitleMultiplayerServersQuotasWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerTitleMultiplayerServersQuotas const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerTitleMultiplayerServersQuotas& model);
    static HRESULT Copy(const PFMultiplayerServerTitleMultiplayerServersQuotas& input, PFMultiplayerServerTitleMultiplayerServersQuotas& output, ModelBuffer& buffer);
};

class GetTitleMultiplayerServersQuotasResponse : public Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse& model);
    static HRESULT Copy(const PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse& input, PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse& output, ModelBuffer& buffer);
};

class ListMultiplayerServersRequest : public Wrappers::PFMultiplayerServerListMultiplayerServersRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListMultiplayerServersRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerListMultiplayerServersRequest& input);

};

class MultiplayerServerSummary : public Wrappers::PFMultiplayerServerMultiplayerServerSummaryWrapper<Allocator>, public OutputModel<PFMultiplayerServerMultiplayerServerSummary>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerMultiplayerServerSummaryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerMultiplayerServerSummary const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerMultiplayerServerSummary& model);
    static HRESULT Copy(const PFMultiplayerServerMultiplayerServerSummary& input, PFMultiplayerServerMultiplayerServerSummary& output, ModelBuffer& buffer);
};

class ListMultiplayerServersResponse : public Wrappers::PFMultiplayerServerListMultiplayerServersResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerListMultiplayerServersResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListMultiplayerServersResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerListMultiplayerServersResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerListMultiplayerServersResponse& model);
    static HRESULT Copy(const PFMultiplayerServerListMultiplayerServersResponse& input, PFMultiplayerServerListMultiplayerServersResponse& output, ModelBuffer& buffer);
};

class ListAssetSummariesRequest : public Wrappers::PFMultiplayerServerListAssetSummariesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListAssetSummariesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerListAssetSummariesRequest& input);

};

class AssetSummary : public Wrappers::PFMultiplayerServerAssetSummaryWrapper<Allocator>, public OutputModel<PFMultiplayerServerAssetSummary>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerAssetSummaryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerAssetSummary const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerAssetSummary& model);
    static HRESULT Copy(const PFMultiplayerServerAssetSummary& input, PFMultiplayerServerAssetSummary& output, ModelBuffer& buffer);
};

class ListAssetSummariesResponse : public Wrappers::PFMultiplayerServerListAssetSummariesResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerListAssetSummariesResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListAssetSummariesResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerListAssetSummariesResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerListAssetSummariesResponse& model);
    static HRESULT Copy(const PFMultiplayerServerListAssetSummariesResponse& input, PFMultiplayerServerListAssetSummariesResponse& output, ModelBuffer& buffer);
};

class ListBuildAliasesRequest : public Wrappers::PFMultiplayerServerListBuildAliasesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListBuildAliasesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerListBuildAliasesRequest& input);

};

class ListBuildAliasesResponse : public Wrappers::PFMultiplayerServerListBuildAliasesResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerListBuildAliasesResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListBuildAliasesResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerListBuildAliasesResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerListBuildAliasesResponse& model);
    static HRESULT Copy(const PFMultiplayerServerListBuildAliasesResponse& input, PFMultiplayerServerListBuildAliasesResponse& output, ModelBuffer& buffer);
};

class ListBuildSummariesRequest : public Wrappers::PFMultiplayerServerListBuildSummariesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListBuildSummariesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerListBuildSummariesRequest& input);

};

class BuildSummary : public Wrappers::PFMultiplayerServerBuildSummaryWrapper<Allocator>, public OutputModel<PFMultiplayerServerBuildSummary>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerBuildSummaryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerBuildSummary const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerBuildSummary& model);
    static HRESULT Copy(const PFMultiplayerServerBuildSummary& input, PFMultiplayerServerBuildSummary& output, ModelBuffer& buffer);
};

class ListBuildSummariesResponse : public Wrappers::PFMultiplayerServerListBuildSummariesResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerListBuildSummariesResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListBuildSummariesResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerListBuildSummariesResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerListBuildSummariesResponse& model);
    static HRESULT Copy(const PFMultiplayerServerListBuildSummariesResponse& input, PFMultiplayerServerListBuildSummariesResponse& output, ModelBuffer& buffer);
};

class ListCertificateSummariesRequest : public Wrappers::PFMultiplayerServerListCertificateSummariesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListCertificateSummariesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerListCertificateSummariesRequest& input);

};

class CertificateSummary : public Wrappers::PFMultiplayerServerCertificateSummaryWrapper<Allocator>, public OutputModel<PFMultiplayerServerCertificateSummary>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCertificateSummaryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerCertificateSummary const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerCertificateSummary& model);
    static HRESULT Copy(const PFMultiplayerServerCertificateSummary& input, PFMultiplayerServerCertificateSummary& output, ModelBuffer& buffer);
};

class ListCertificateSummariesResponse : public Wrappers::PFMultiplayerServerListCertificateSummariesResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerListCertificateSummariesResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListCertificateSummariesResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerListCertificateSummariesResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerListCertificateSummariesResponse& model);
    static HRESULT Copy(const PFMultiplayerServerListCertificateSummariesResponse& input, PFMultiplayerServerListCertificateSummariesResponse& output, ModelBuffer& buffer);
};

class ListContainerImagesRequest : public Wrappers::PFMultiplayerServerListContainerImagesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListContainerImagesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerListContainerImagesRequest& input);

};

class ListContainerImagesResponse : public Wrappers::PFMultiplayerServerListContainerImagesResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerListContainerImagesResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListContainerImagesResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerListContainerImagesResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerListContainerImagesResponse& model);
    static HRESULT Copy(const PFMultiplayerServerListContainerImagesResponse& input, PFMultiplayerServerListContainerImagesResponse& output, ModelBuffer& buffer);
};

class ListContainerImageTagsRequest : public Wrappers::PFMultiplayerServerListContainerImageTagsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListContainerImageTagsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerListContainerImageTagsRequest& input);

};

class ListContainerImageTagsResponse : public Wrappers::PFMultiplayerServerListContainerImageTagsResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerListContainerImageTagsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListContainerImageTagsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerListContainerImageTagsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerListContainerImageTagsResponse& model);
    static HRESULT Copy(const PFMultiplayerServerListContainerImageTagsResponse& input, PFMultiplayerServerListContainerImageTagsResponse& output, ModelBuffer& buffer);
};

class ListPartyQosServersRequest : public Wrappers::PFMultiplayerServerListPartyQosServersRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListPartyQosServersRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerListPartyQosServersRequest& input);

};

class QosServer : public Wrappers::PFMultiplayerServerQosServerWrapper<Allocator>, public OutputModel<PFMultiplayerServerQosServer>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerQosServerWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerQosServer const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerQosServer& model);
    static HRESULT Copy(const PFMultiplayerServerQosServer& input, PFMultiplayerServerQosServer& output, ModelBuffer& buffer);
};

class ListPartyQosServersResponse : public Wrappers::PFMultiplayerServerListPartyQosServersResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerListPartyQosServersResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListPartyQosServersResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerListPartyQosServersResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerListPartyQosServersResponse& model);
    static HRESULT Copy(const PFMultiplayerServerListPartyQosServersResponse& input, PFMultiplayerServerListPartyQosServersResponse& output, ModelBuffer& buffer);
};

class ListQosServersForTitleRequest : public Wrappers::PFMultiplayerServerListQosServersForTitleRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListQosServersForTitleRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerListQosServersForTitleRequest& input);

};

class ListQosServersForTitleResponse : public Wrappers::PFMultiplayerServerListQosServersForTitleResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerListQosServersForTitleResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListQosServersForTitleResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerListQosServersForTitleResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerListQosServersForTitleResponse& model);
    static HRESULT Copy(const PFMultiplayerServerListQosServersForTitleResponse& input, PFMultiplayerServerListQosServersForTitleResponse& output, ModelBuffer& buffer);
};

class ListTitleMultiplayerServersQuotaChangesRequest : public Wrappers::PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest& input);

};

class ListTitleMultiplayerServersQuotaChangesResponse : public Wrappers::PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse& model);
    static HRESULT Copy(const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse& input, PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse& output, ModelBuffer& buffer);
};

class ListVirtualMachineSummariesRequest : public Wrappers::PFMultiplayerServerListVirtualMachineSummariesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListVirtualMachineSummariesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerListVirtualMachineSummariesRequest& input);

};

class VirtualMachineSummary : public Wrappers::PFMultiplayerServerVirtualMachineSummaryWrapper<Allocator>, public OutputModel<PFMultiplayerServerVirtualMachineSummary>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerVirtualMachineSummaryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerVirtualMachineSummary const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerVirtualMachineSummary& model);
    static HRESULT Copy(const PFMultiplayerServerVirtualMachineSummary& input, PFMultiplayerServerVirtualMachineSummary& output, ModelBuffer& buffer);
};

class ListVirtualMachineSummariesResponse : public Wrappers::PFMultiplayerServerListVirtualMachineSummariesResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerListVirtualMachineSummariesResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerListVirtualMachineSummariesResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerListVirtualMachineSummariesResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerListVirtualMachineSummariesResponse& model);
    static HRESULT Copy(const PFMultiplayerServerListVirtualMachineSummariesResponse& input, PFMultiplayerServerListVirtualMachineSummariesResponse& output, ModelBuffer& buffer);
};

class BuildAliasParams : public Wrappers::PFMultiplayerServerBuildAliasParamsWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerBuildAliasParamsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerBuildAliasParams& input);

};

class RequestMultiplayerServerRequest : public Wrappers::PFMultiplayerServerRequestMultiplayerServerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerRequestMultiplayerServerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerRequestMultiplayerServerRequest& input);

};

class RequestMultiplayerServerResponse : public Wrappers::PFMultiplayerServerRequestMultiplayerServerResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerRequestMultiplayerServerResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerRequestMultiplayerServerResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerRequestMultiplayerServerResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerRequestMultiplayerServerResponse& model);
    static HRESULT Copy(const PFMultiplayerServerRequestMultiplayerServerResponse& input, PFMultiplayerServerRequestMultiplayerServerResponse& output, ModelBuffer& buffer);
};

class RolloverContainerRegistryCredentialsRequest : public Wrappers::PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerRolloverContainerRegistryCredentialsRequest& input);

};

class RolloverContainerRegistryCredentialsResponse : public Wrappers::PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper<Allocator>, public OutputModel<PFMultiplayerServerRolloverContainerRegistryCredentialsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMultiplayerServerRolloverContainerRegistryCredentialsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMultiplayerServerRolloverContainerRegistryCredentialsResponse& model);
    static HRESULT Copy(const PFMultiplayerServerRolloverContainerRegistryCredentialsResponse& input, PFMultiplayerServerRolloverContainerRegistryCredentialsResponse& output, ModelBuffer& buffer);
};

class ShutdownMultiplayerServerRequest : public Wrappers::PFMultiplayerServerShutdownMultiplayerServerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerShutdownMultiplayerServerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerShutdownMultiplayerServerRequest& input);

};

class UntagContainerImageRequest : public Wrappers::PFMultiplayerServerUntagContainerImageRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerUntagContainerImageRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerUntagContainerImageRequest& input);

};

class UpdateBuildAliasRequest : public Wrappers::PFMultiplayerServerUpdateBuildAliasRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerUpdateBuildAliasRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerUpdateBuildAliasRequest& input);

};

class UpdateBuildNameRequest : public Wrappers::PFMultiplayerServerUpdateBuildNameRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerUpdateBuildNameRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerUpdateBuildNameRequest& input);

};

class UpdateBuildRegionRequest : public Wrappers::PFMultiplayerServerUpdateBuildRegionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerUpdateBuildRegionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerUpdateBuildRegionRequest& input);

};

class UpdateBuildRegionsRequest : public Wrappers::PFMultiplayerServerUpdateBuildRegionsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerUpdateBuildRegionsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerUpdateBuildRegionsRequest& input);

};

class Certificate : public Wrappers::PFMultiplayerServerCertificateWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerCertificateWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerCertificate& input);

};

class UploadCertificateRequest : public Wrappers::PFMultiplayerServerUploadCertificateRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMultiplayerServerUploadCertificateRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMultiplayerServerUploadCertificateRequest& input);

};

} // namespace MultiplayerServer
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
