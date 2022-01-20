#pragma once

#include <playfab/cpp/PFPlayerDataManagementDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace PlayerDataManagement
{

// PlayerDataManagement Classes
class GetDataReportRequest : public Wrappers::PFPlayerDataManagementGetDataReportRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetDataReportRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementGetDataReportRequest& input);

};

class GetDataReportResult : public Wrappers::PFPlayerDataManagementGetDataReportResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementGetDataReportResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetDataReportResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementGetDataReportResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementGetDataReportResult& model);
    static HRESULT Copy(const PFPlayerDataManagementGetDataReportResult& input, PFPlayerDataManagementGetDataReportResult& output, ModelBuffer& buffer);
};

class GetUserDataRequest : public Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementGetUserDataRequest& input);

};

class AdminGetUserDataResult : public Wrappers::PFPlayerDataManagementAdminGetUserDataResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementAdminGetUserDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementAdminGetUserDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementAdminGetUserDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementAdminGetUserDataResult& model);
    static HRESULT Copy(const PFPlayerDataManagementAdminGetUserDataResult& input, PFPlayerDataManagementAdminGetUserDataResult& output, ModelBuffer& buffer);
};

class AdminUpdateUserDataRequest : public Wrappers::PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementAdminUpdateUserDataRequest& input);

};

class UpdateUserDataResult : public Wrappers::PFPlayerDataManagementUpdateUserDataResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementUpdateUserDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementUpdateUserDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementUpdateUserDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementUpdateUserDataResult& model);
    static HRESULT Copy(const PFPlayerDataManagementUpdateUserDataResult& input, PFPlayerDataManagementUpdateUserDataResult& output, ModelBuffer& buffer);
};

class UpdateUserInternalDataRequest : public Wrappers::PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementUpdateUserInternalDataRequest& input);

};

class ClientGetUserDataResult : public Wrappers::PFPlayerDataManagementClientGetUserDataResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementClientGetUserDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementClientGetUserDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementClientGetUserDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementClientGetUserDataResult& model);
    static HRESULT Copy(const PFPlayerDataManagementClientGetUserDataResult& input, PFPlayerDataManagementClientGetUserDataResult& output, ModelBuffer& buffer);
};

class ClientUpdateUserDataRequest : public Wrappers::PFPlayerDataManagementClientUpdateUserDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementClientUpdateUserDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementClientUpdateUserDataRequest& input);

};

class ServerGetUserDataResult : public Wrappers::PFPlayerDataManagementServerGetUserDataResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementServerGetUserDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementServerGetUserDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementServerGetUserDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementServerGetUserDataResult& model);
    static HRESULT Copy(const PFPlayerDataManagementServerGetUserDataResult& input, PFPlayerDataManagementServerGetUserDataResult& output, ModelBuffer& buffer);
};

class ServerUpdateUserDataRequest : public Wrappers::PFPlayerDataManagementServerUpdateUserDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementServerUpdateUserDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementServerUpdateUserDataRequest& input);

};

} // namespace PlayerDataManagement
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
