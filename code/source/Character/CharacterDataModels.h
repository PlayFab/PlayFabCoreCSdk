#pragma once

#include <playfab/cpp/PFCharacterDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Character
{

// Character Classes
class ResetCharacterStatisticsRequest : public Wrappers::PFCharacterResetCharacterStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterResetCharacterStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterResetCharacterStatisticsRequest& input);

};

class ListUsersCharactersRequest : public Wrappers::PFCharacterListUsersCharactersRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterListUsersCharactersRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterListUsersCharactersRequest& input);

};

class ListUsersCharactersResult : public Wrappers::PFCharacterListUsersCharactersResultWrapper<Allocator>, public OutputModel<PFCharacterListUsersCharactersResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterListUsersCharactersResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterListUsersCharactersResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterListUsersCharactersResult& model);
    static HRESULT Copy(const PFCharacterListUsersCharactersResult& input, PFCharacterListUsersCharactersResult& output, ModelBuffer& buffer);
};

class GetCharacterDataRequest : public Wrappers::PFCharacterGetCharacterDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterGetCharacterDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterGetCharacterDataRequest& input);

};

class ClientGetCharacterDataResult : public Wrappers::PFCharacterClientGetCharacterDataResultWrapper<Allocator>, public OutputModel<PFCharacterClientGetCharacterDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterClientGetCharacterDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterClientGetCharacterDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterClientGetCharacterDataResult& model);
    static HRESULT Copy(const PFCharacterClientGetCharacterDataResult& input, PFCharacterClientGetCharacterDataResult& output, ModelBuffer& buffer);
};

class GetCharacterLeaderboardRequest : public Wrappers::PFCharacterGetCharacterLeaderboardRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterGetCharacterLeaderboardRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterGetCharacterLeaderboardRequest& input);

};

class CharacterLeaderboardEntry : public Wrappers::PFCharacterCharacterLeaderboardEntryWrapper<Allocator>, public OutputModel<PFCharacterCharacterLeaderboardEntry>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterCharacterLeaderboardEntryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterCharacterLeaderboardEntry const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterCharacterLeaderboardEntry& model);
    static HRESULT Copy(const PFCharacterCharacterLeaderboardEntry& input, PFCharacterCharacterLeaderboardEntry& output, ModelBuffer& buffer);
};

class GetCharacterLeaderboardResult : public Wrappers::PFCharacterGetCharacterLeaderboardResultWrapper<Allocator>, public OutputModel<PFCharacterGetCharacterLeaderboardResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterGetCharacterLeaderboardResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterGetCharacterLeaderboardResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterGetCharacterLeaderboardResult& model);
    static HRESULT Copy(const PFCharacterGetCharacterLeaderboardResult& input, PFCharacterGetCharacterLeaderboardResult& output, ModelBuffer& buffer);
};

class ClientGetCharacterStatisticsRequest : public Wrappers::PFCharacterClientGetCharacterStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterClientGetCharacterStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterClientGetCharacterStatisticsRequest& input);

};

class ClientGetCharacterStatisticsResult : public Wrappers::PFCharacterClientGetCharacterStatisticsResultWrapper<Allocator>, public OutputModel<PFCharacterClientGetCharacterStatisticsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterClientGetCharacterStatisticsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterClientGetCharacterStatisticsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterClientGetCharacterStatisticsResult& model);
    static HRESULT Copy(const PFCharacterClientGetCharacterStatisticsResult& input, PFCharacterClientGetCharacterStatisticsResult& output, ModelBuffer& buffer);
};

class ClientGetLeaderboardAroundCharacterRequest : public Wrappers::PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterClientGetLeaderboardAroundCharacterRequest& input);

};

class GetLeaderboardAroundCharacterResult : public Wrappers::PFCharacterGetLeaderboardAroundCharacterResultWrapper<Allocator>, public OutputModel<PFCharacterGetLeaderboardAroundCharacterResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterGetLeaderboardAroundCharacterResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterGetLeaderboardAroundCharacterResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterGetLeaderboardAroundCharacterResult& model);
    static HRESULT Copy(const PFCharacterGetLeaderboardAroundCharacterResult& input, PFCharacterGetLeaderboardAroundCharacterResult& output, ModelBuffer& buffer);
};

class ClientGetLeaderboardForUsersCharactersRequest : public Wrappers::PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterClientGetLeaderboardForUsersCharactersRequest& input);

};

class GetLeaderboardForUsersCharactersResult : public Wrappers::PFCharacterGetLeaderboardForUsersCharactersResultWrapper<Allocator>, public OutputModel<PFCharacterGetLeaderboardForUsersCharactersResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterGetLeaderboardForUsersCharactersResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterGetLeaderboardForUsersCharactersResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterGetLeaderboardForUsersCharactersResult& model);
    static HRESULT Copy(const PFCharacterGetLeaderboardForUsersCharactersResult& input, PFCharacterGetLeaderboardForUsersCharactersResult& output, ModelBuffer& buffer);
};

class ClientGrantCharacterToUserRequest : public Wrappers::PFCharacterClientGrantCharacterToUserRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterClientGrantCharacterToUserRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterClientGrantCharacterToUserRequest& input);

};

class ClientGrantCharacterToUserResult : public Wrappers::PFCharacterClientGrantCharacterToUserResultWrapper<Allocator>, public OutputModel<PFCharacterClientGrantCharacterToUserResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterClientGrantCharacterToUserResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterClientGrantCharacterToUserResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterClientGrantCharacterToUserResult& model);
    static HRESULT Copy(const PFCharacterClientGrantCharacterToUserResult& input, PFCharacterClientGrantCharacterToUserResult& output, ModelBuffer& buffer);
};

class ClientUpdateCharacterDataRequest : public Wrappers::PFCharacterClientUpdateCharacterDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterClientUpdateCharacterDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterClientUpdateCharacterDataRequest& input);

};

class UpdateCharacterDataResult : public Wrappers::PFCharacterUpdateCharacterDataResultWrapper<Allocator>, public OutputModel<PFCharacterUpdateCharacterDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterUpdateCharacterDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterUpdateCharacterDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterUpdateCharacterDataResult& model);
    static HRESULT Copy(const PFCharacterUpdateCharacterDataResult& input, PFCharacterUpdateCharacterDataResult& output, ModelBuffer& buffer);
};

class ClientUpdateCharacterStatisticsRequest : public Wrappers::PFCharacterClientUpdateCharacterStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterClientUpdateCharacterStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterClientUpdateCharacterStatisticsRequest& input);

};

class DeleteCharacterFromUserRequest : public Wrappers::PFCharacterDeleteCharacterFromUserRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterDeleteCharacterFromUserRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterDeleteCharacterFromUserRequest& input);

};

class ServerGetCharacterDataResult : public Wrappers::PFCharacterServerGetCharacterDataResultWrapper<Allocator>, public OutputModel<PFCharacterServerGetCharacterDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterServerGetCharacterDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterServerGetCharacterDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterServerGetCharacterDataResult& model);
    static HRESULT Copy(const PFCharacterServerGetCharacterDataResult& input, PFCharacterServerGetCharacterDataResult& output, ModelBuffer& buffer);
};

class ServerGetCharacterStatisticsRequest : public Wrappers::PFCharacterServerGetCharacterStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterServerGetCharacterStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterServerGetCharacterStatisticsRequest& input);

};

class ServerGetCharacterStatisticsResult : public Wrappers::PFCharacterServerGetCharacterStatisticsResultWrapper<Allocator>, public OutputModel<PFCharacterServerGetCharacterStatisticsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterServerGetCharacterStatisticsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterServerGetCharacterStatisticsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterServerGetCharacterStatisticsResult& model);
    static HRESULT Copy(const PFCharacterServerGetCharacterStatisticsResult& input, PFCharacterServerGetCharacterStatisticsResult& output, ModelBuffer& buffer);
};

class ServerGetLeaderboardAroundCharacterRequest : public Wrappers::PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterServerGetLeaderboardAroundCharacterRequest& input);

};

class ServerGetLeaderboardForUsersCharactersRequest : public Wrappers::PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterServerGetLeaderboardForUsersCharactersRequest& input);

};

class ServerGrantCharacterToUserRequest : public Wrappers::PFCharacterServerGrantCharacterToUserRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterServerGrantCharacterToUserRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterServerGrantCharacterToUserRequest& input);

};

class ServerGrantCharacterToUserResult : public Wrappers::PFCharacterServerGrantCharacterToUserResultWrapper<Allocator>, public OutputModel<PFCharacterServerGrantCharacterToUserResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterServerGrantCharacterToUserResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCharacterServerGrantCharacterToUserResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCharacterServerGrantCharacterToUserResult& model);
    static HRESULT Copy(const PFCharacterServerGrantCharacterToUserResult& input, PFCharacterServerGrantCharacterToUserResult& output, ModelBuffer& buffer);
};

class ServerUpdateCharacterDataRequest : public Wrappers::PFCharacterServerUpdateCharacterDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterServerUpdateCharacterDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterServerUpdateCharacterDataRequest& input);

};

class ServerUpdateCharacterStatisticsRequest : public Wrappers::PFCharacterServerUpdateCharacterStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCharacterServerUpdateCharacterStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCharacterServerUpdateCharacterStatisticsRequest& input);

};

} // namespace Character
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
