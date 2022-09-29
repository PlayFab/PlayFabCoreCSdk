#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFDataDataModelWrappers.h>
#include "AutoGenDataResultHolders.h"

namespace PlayFabUnit
{

class AutoGenDataTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestDataAbortFileUploadsPrerequisiteInitiateFileUploads(TestContext& testContext);
    void TestDataAbortFileUploads(TestContext& testContext);

    void TestDataDeleteFilesPrerequisiteInitiateFileUploads(TestContext& testContext);
    void TestDataDeleteFilesPrerequisiteFinalizeFileUploads(TestContext& testContext);
    void TestDataDeleteFiles(TestContext& testContext);

    void TestDataFinalizeFileUploadsPrerequisiteInitiateFileUploads(TestContext& testContext);
    void TestDataFinalizeFileUploads(TestContext& testContext);
    void TestDataFinalizeFileUploadsCleanupDeleteFiles(TestContext& testContext);

    void TestDataGetFiles(TestContext& testContext);

    void TestDataGetObjects(TestContext& testContext);

    void TestDataInitiateFileUploads(TestContext& testContext);
    void TestDataInitiateFileUploadsCleanupAbortFileUploads(TestContext& testContext);

    void TestDataSetObjectsPrerequisiteSetObjects(TestContext& testContext);
    void TestDataSetObjects(TestContext& testContext);


protected:
    void AddTests();

    static void LogAbortFileUploadsRequest(PFDataAbortFileUploadsRequest const* request, const char* testName);
    static HRESULT LogAbortFileUploadsResponse(PFDataAbortFileUploadsResponse const* result);
    static void LogDeleteFilesRequest(PFDataDeleteFilesRequest const* request, const char* testName);
    static HRESULT LogDeleteFilesResponse(PFDataDeleteFilesResponse const* result);
    static void LogFinalizeFileUploadsRequest(PFDataFinalizeFileUploadsRequest const* request, const char* testName);
    static HRESULT LogFinalizeFileUploadsResponse(PFDataFinalizeFileUploadsResponse const* result);
    static void LogGetFilesRequest(PFDataGetFilesRequest const* request, const char* testName);
    static HRESULT LogGetFilesResponse(PFDataGetFilesResponse const* result);
    static void LogGetObjectsRequest(PFDataGetObjectsRequest const* request, const char* testName);
    static HRESULT LogGetObjectsResponse(PFDataGetObjectsResponse const* result);
    static void LogInitiateFileUploadsRequest(PFDataInitiateFileUploadsRequest const* request, const char* testName);
    static HRESULT LogInitiateFileUploadsResponse(PFDataInitiateFileUploadsResponse const* result);
    static void LogSetObjectsRequest(PFDataSetObjectsRequest const* request, const char* testName);
    static HRESULT LogSetObjectsResponse(PFDataSetObjectsResponse const* result);

    void FillAbortFileUploadsPrerequisiteInitiateFileUploadsRequest(PlayFab::Wrappers::PFDataInitiateFileUploadsRequestWrapper<>& request);
    static HRESULT StoreAbortFileUploadsPrerequisiteInitiateFileUploadsResponse(std::shared_ptr<InitiateFileUploadsResponseHolder> result);
    void FillAbortFileUploadsRequest(PlayFab::Wrappers::PFDataAbortFileUploadsRequestWrapper<>& request);
    static HRESULT ValidateAbortFileUploadsResponse(PFDataAbortFileUploadsResponse* result);

    void FillDeleteFilesPrerequisiteInitiateFileUploadsRequest(PlayFab::Wrappers::PFDataInitiateFileUploadsRequestWrapper<>& request);
    static HRESULT StoreDeleteFilesPrerequisiteInitiateFileUploadsResponse(std::shared_ptr<InitiateFileUploadsResponseHolder> result);
    void FillDeleteFilesPrerequisiteFinalizeFileUploadsRequest(PlayFab::Wrappers::PFDataFinalizeFileUploadsRequestWrapper<>& request);
    static HRESULT StoreDeleteFilesPrerequisiteFinalizeFileUploadsResponse(std::shared_ptr<FinalizeFileUploadsResponseHolder> result);
    void FillDeleteFilesRequest(PlayFab::Wrappers::PFDataDeleteFilesRequestWrapper<>& request);
    static HRESULT ValidateDeleteFilesResponse(PFDataDeleteFilesResponse* result);

    void FillFinalizeFileUploadsPrerequisiteInitiateFileUploadsRequest(PlayFab::Wrappers::PFDataInitiateFileUploadsRequestWrapper<>& request);
    static HRESULT StoreFinalizeFileUploadsPrerequisiteInitiateFileUploadsResponse(std::shared_ptr<InitiateFileUploadsResponseHolder> result);
    void FillFinalizeFileUploadsRequest(PlayFab::Wrappers::PFDataFinalizeFileUploadsRequestWrapper<>& request);
    static HRESULT ValidateFinalizeFileUploadsResponse(PFDataFinalizeFileUploadsResponse* result);
    void FillFinalizeFileUploadsCleanupDeleteFilesRequest(PlayFab::Wrappers::PFDataDeleteFilesRequestWrapper<>& request);
    static HRESULT StoreFinalizeFileUploadsCleanupDeleteFilesResponse(std::shared_ptr<DeleteFilesResponseHolder> result);

    void FillGetFilesRequest(PlayFab::Wrappers::PFDataGetFilesRequestWrapper<>& request);
    static HRESULT ValidateGetFilesResponse(PFDataGetFilesResponse* result);

    void FillGetObjectsRequest(PlayFab::Wrappers::PFDataGetObjectsRequestWrapper<>& request);
    static HRESULT ValidateGetObjectsResponse(PFDataGetObjectsResponse* result);

    void FillInitiateFileUploadsRequest(PlayFab::Wrappers::PFDataInitiateFileUploadsRequestWrapper<>& request);
    static HRESULT ValidateInitiateFileUploadsResponse(PFDataInitiateFileUploadsResponse* result);
    void FillInitiateFileUploadsCleanupAbortFileUploadsRequest(PlayFab::Wrappers::PFDataAbortFileUploadsRequestWrapper<>& request);
    static HRESULT StoreInitiateFileUploadsCleanupAbortFileUploadsResponse(std::shared_ptr<AbortFileUploadsResponseHolder> result);

    void FillSetObjectsPrerequisiteSetObjectsRequest(PlayFab::Wrappers::PFDataSetObjectsRequestWrapper<>& request);
    static HRESULT StoreSetObjectsPrerequisiteSetObjectsResponse(std::shared_ptr<SetObjectsResponseHolder> result);
    void FillSetObjectsRequest(PlayFab::Wrappers::PFDataSetObjectsRequestWrapper<>& request);
    static HRESULT ValidateSetObjectsResponse(PFDataSetObjectsResponse* result);

    struct DataTestData
    {
        ~DataTestData() = default;

        std::shared_ptr<InitiateFileUploadsResponseHolder> m_InitiateFileUploadsResponse;
        std::shared_ptr<FinalizeFileUploadsResponseHolder> m_FinalizeFileUploadsResponse;
        std::shared_ptr<DeleteFilesResponseHolder> m_DeleteFilesResponse;
        std::shared_ptr<AbortFileUploadsResponseHolder> m_AbortFileUploadsResponse;
        std::shared_ptr<SetObjectsResponseHolder> m_SetObjectsResponse;
    };

    static DataTestData testData;

public:
    PFStateHandle stateHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle{ nullptr };
    PFEntityHandle entityHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle2{ nullptr };
    PFEntityHandle entityHandle2{ nullptr };
    PFEntityHandle titleEntityHandle{ nullptr };

    void ClassSetUp() override;
    void ClassTearDown() override;
    void SetUp(TestContext& testContext) override;

    void Tick(TestContext&) override {}
};

}
