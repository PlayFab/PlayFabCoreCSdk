#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenPlayerItemManagementTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenPlayerItemManagementTests::PlayerItemManagementTestData AutoGenPlayerItemManagementTests::testData;

void AutoGenPlayerItemManagementTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenPlayerItemManagementTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenPlayerItemManagementTests::AddTests()
{
    // Generated tests 
    AddTest("TestPlayerItemManagementAdminAddUserVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminAddUserVirtualCurrency);

    AddTest("TestPlayerItemManagementAdminCheckLimitedEditionItemAvailability", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminCheckLimitedEditionItemAvailability);

    AddTest("TestPlayerItemManagementAdminGetUserInventory", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminGetUserInventory);

    AddTest("TestPlayerItemManagementAdminGrantItemsToUsers", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminGrantItemsToUsers);

    AddTest("TestPlayerItemManagementAdminIncrementLimitedEditionItemAvailability", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminIncrementLimitedEditionItemAvailability);

    AddTest("TestPlayerItemManagementAdminRevokeInventoryItem", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminRevokeInventoryItem);

    AddTest("TestPlayerItemManagementAdminRevokeInventoryItems", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminRevokeInventoryItems);

    AddTest("TestPlayerItemManagementAdminSubtractUserVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminSubtractUserVirtualCurrency);

    AddTest("TestPlayerItemManagementClientAddUserVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientAddUserVirtualCurrency);

    AddTest("TestPlayerItemManagementClientConfirmPurchase", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientConfirmPurchase);

    AddTest("TestPlayerItemManagementClientConsumeItem", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientConsumeItem);

    AddTest("TestPlayerItemManagementClientGetCharacterInventory", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientGetCharacterInventory);

    AddTest("TestPlayerItemManagementClientGetPaymentToken", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientGetPaymentToken);

    AddTest("TestPlayerItemManagementClientGetPurchase", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientGetPurchase);

    AddTest("TestPlayerItemManagementClientGetUserInventory", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientGetUserInventory);

    AddTest("TestPlayerItemManagementClientPayForPurchase", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientPayForPurchase);

    AddTest("TestPlayerItemManagementClientPurchaseItem", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientPurchaseItem);

    AddTest("TestPlayerItemManagementClientRedeemCoupon", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientRedeemCoupon);

    AddTest("TestPlayerItemManagementClientStartPurchase", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientStartPurchase);

    AddTest("TestPlayerItemManagementClientSubtractUserVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientSubtractUserVirtualCurrency);

    AddTest("TestPlayerItemManagementClientUnlockContainerInstance", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientUnlockContainerInstance);

    AddTest("TestPlayerItemManagementClientUnlockContainerItem", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientUnlockContainerItem);

    AddTest("TestPlayerItemManagementServerAddCharacterVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerAddCharacterVirtualCurrency);

    AddTest("TestPlayerItemManagementServerAddUserVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerAddUserVirtualCurrency);

    AddTest("TestPlayerItemManagementServerConsumeItem", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerConsumeItem);

    AddTest("TestPlayerItemManagementServerEvaluateRandomResultTable", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerEvaluateRandomResultTable);

    AddTest("TestPlayerItemManagementServerGetCharacterInventory", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetCharacterInventory);

    AddTest("TestPlayerItemManagementServerGetRandomResultTables", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetRandomResultTables);

    AddTest("TestPlayerItemManagementServerGetUserInventory", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetUserInventory);

    AddTest("TestPlayerItemManagementServerGrantItemsToCharacter", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToCharacter);

    AddTest("TestPlayerItemManagementServerGrantItemsToUser", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToUser);

    AddTest("TestPlayerItemManagementServerGrantItemsToUsers", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToUsers);

    AddTest("TestPlayerItemManagementServerModifyItemUses", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerModifyItemUses);

    AddTest("TestPlayerItemManagementServerMoveItemToCharacterFromCharacter", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToCharacterFromCharacter);

    AddTest("TestPlayerItemManagementServerMoveItemToCharacterFromUser", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToCharacterFromUser);

    AddTest("TestPlayerItemManagementServerMoveItemToUserFromCharacter", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToUserFromCharacter);

    AddTest("TestPlayerItemManagementServerRedeemCoupon", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRedeemCoupon);

    AddTest("TestPlayerItemManagementServerReportPlayer", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerReportPlayer);

    AddTest("TestPlayerItemManagementServerRevokeInventoryItem", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRevokeInventoryItem);

    AddTest("TestPlayerItemManagementServerRevokeInventoryItems", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRevokeInventoryItems);

    AddTest("TestPlayerItemManagementServerSubtractCharacterVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerSubtractCharacterVirtualCurrency);

    AddTest("TestPlayerItemManagementServerSubtractUserVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerSubtractUserVirtualCurrency);

    AddTest("TestPlayerItemManagementServerUnlockContainerInstance", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUnlockContainerInstance);

    AddTest("TestPlayerItemManagementServerUnlockContainerItem", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUnlockContainerItem);

    AddTest("TestPlayerItemManagementServerUpdateUserInventoryItemCustomData", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUpdateUserInventoryItemCustomData);
}

void AutoGenPlayerItemManagementTests::ClassSetUp()
{
    HRESULT hr = PFAdminInitialize(testTitleData.titleId.data(), testTitleData.developerSecretKey.data(), nullptr, &stateHandle);
    assert(SUCCEEDED(hr));
    if (SUCCEEDED(hr))
    {
        PFAuthenticationLoginWithCustomIDRequest request{};
        request.customId = "CustomId";
        request.createAccount = true;

        PFGetPlayerCombinedInfoRequestParams combinedInfoRequestParams{};
        combinedInfoRequestParams.getCharacterInventories = true;
        combinedInfoRequestParams.getCharacterList = true;
        combinedInfoRequestParams.getPlayerProfile = true;
        combinedInfoRequestParams.getPlayerStatistics = true;
        combinedInfoRequestParams.getTitleData = true;
        combinedInfoRequestParams.getUserAccountInfo = true;
        combinedInfoRequestParams.getUserData = true;
        combinedInfoRequestParams.getUserInventory = true;
        combinedInfoRequestParams.getUserReadOnlyData = true;
        combinedInfoRequestParams.getUserVirtualCurrency = true;
        request.infoRequestParameters = &combinedInfoRequestParams;

        XAsyncBlock async{};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle);
                assert(SUCCEEDED(hr) && titlePlayerHandle);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle, &entityHandle);
                assert(SUCCEEDED(hr) && entityHandle);
            }
        }

        request.customId = "CustomId2";
        async = {};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously what for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle2);
                assert(SUCCEEDED(hr) && titlePlayerHandle2);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle2, &entityHandle2);
                assert(SUCCEEDED(hr) && entityHandle2);
            }
        }

        PFAuthenticationGetEntityTokenRequest titleTokenRequest{};
        async = {};
        hr = PFAuthenticationGetEntityTokenAsync(stateHandle, &titleTokenRequest, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationGetEntityTokenGetResult(&async, &titleEntityHandle);
                assert(SUCCEEDED(hr));
            }
        }
    }
}

void AutoGenPlayerItemManagementTests::ClassTearDown()
{
    PFTitlePlayerCloseHandle(titlePlayerHandle);
    PFEntityCloseHandle(entityHandle);
    PFEntityCloseHandle(titleEntityHandle);

    XAsyncBlock async{};
    HRESULT hr = PFUninitializeAsync(stateHandle, &async);
    assert(SUCCEEDED(hr));

    hr = XAsyncGetStatus(&async, true);
    assert(SUCCEEDED(hr));

    UNREFERENCED_PARAMETER(hr);
}

void AutoGenPlayerItemManagementTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminAddUserVirtualCurrency

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminAddUserVirtualCurrency(TestContext& testContext)
{
    struct AdminAddUserVirtualCurrencyResultHolder : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminAddUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminAddUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminAddUserVirtualCurrencyResultHolder>>(testContext);

    PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper<> request;
    FillAdminAddUserVirtualCurrencyRequest(request);
    LogAdminAddUserVirtualCurrencyRequest(&request.Model(), "TestPlayerItemManagementAdminAddUserVirtualCurrency");
    HRESULT hr = PFPlayerItemManagementAdminAddUserVirtualCurrencyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminAddUserVirtualCurrencyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminCheckLimitedEditionItemAvailability

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminCheckLimitedEditionItemAvailability(TestContext& testContext)
{
    struct AdminCheckLimitedEditionItemAvailabilityResultHolder : public CheckLimitedEditionItemAvailabilityResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminCheckLimitedEditionItemAvailabilityGetResult(async, &result)));
            LogPFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminCheckLimitedEditionItemAvailabilityResultHolder>>(testContext);

    PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper<> request;
    FillCheckLimitedEditionItemAvailabilityRequest(request);
    LogCheckLimitedEditionItemAvailabilityRequest(&request.Model(), "TestPlayerItemManagementAdminCheckLimitedEditionItemAvailability");
    HRESULT hr = PFPlayerItemManagementAdminCheckLimitedEditionItemAvailabilityAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminCheckLimitedEditionItemAvailabilityAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetUserInventory

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminGetUserInventory(TestContext& testContext)
{
    struct AdminGetUserInventoryResultHolder : public AdminGetUserInventoryResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminGetUserInventoryGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminGetUserInventoryGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementAdminGetUserInventoryResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementAdminGetUserInventoryResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserInventoryResultHolder>>(testContext);

    PFPlayerItemManagementAdminGetUserInventoryRequestWrapper<> request;
    FillAdminGetUserInventoryRequest(request);
    LogAdminGetUserInventoryRequest(&request.Model(), "TestPlayerItemManagementAdminGetUserInventory");
    HRESULT hr = PFPlayerItemManagementAdminGetUserInventoryAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminGetUserInventoryAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGrantItemsToUsers

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminGrantItemsToUsers(TestContext& testContext)
{
    struct AdminGrantItemsToUsersResultHolder : public GrantItemsToUsersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminGrantItemsToUsersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminGrantItemsToUsersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementGrantItemsToUsersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementGrantItemsToUsersResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGrantItemsToUsersResultHolder>>(testContext);

    PFPlayerItemManagementGrantItemsToUsersRequestWrapper<> request;
    FillGrantItemsToUsersRequest(request);
    LogGrantItemsToUsersRequest(&request.Model(), "TestPlayerItemManagementAdminGrantItemsToUsers");
    HRESULT hr = PFPlayerItemManagementAdminGrantItemsToUsersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminGrantItemsToUsersAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminIncrementLimitedEditionItemAvailability

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminIncrementLimitedEditionItemAvailability(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper<> request;
    FillIncrementLimitedEditionItemAvailabilityRequest(request);
    LogIncrementLimitedEditionItemAvailabilityRequest(&request.Model(), "TestPlayerItemManagementAdminIncrementLimitedEditionItemAvailability");
    HRESULT hr = PFPlayerItemManagementAdminIncrementLimitedEditionItemAvailabilityAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminIncrementLimitedEditionItemAvailabilityAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminRevokeInventoryItem

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminRevokeInventoryItem(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementRevokeInventoryItemRequestWrapper<> request;
    FillRevokeInventoryItemRequest(request);
    LogRevokeInventoryItemRequest(&request.Model(), "TestPlayerItemManagementAdminRevokeInventoryItem");
    HRESULT hr = PFPlayerItemManagementAdminRevokeInventoryItemAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminRevokeInventoryItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminRevokeInventoryItems

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminRevokeInventoryItems(TestContext& testContext)
{
    struct AdminRevokeInventoryItemsResultHolder : public RevokeInventoryItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminRevokeInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminRevokeInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementRevokeInventoryItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementRevokeInventoryItemsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminRevokeInventoryItemsResultHolder>>(testContext);

    PFPlayerItemManagementRevokeInventoryItemsRequestWrapper<> request;
    FillRevokeInventoryItemsRequest(request);
    LogRevokeInventoryItemsRequest(&request.Model(), "TestPlayerItemManagementAdminRevokeInventoryItems");
    HRESULT hr = PFPlayerItemManagementAdminRevokeInventoryItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminRevokeInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminSubtractUserVirtualCurrency

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminSubtractUserVirtualCurrency(TestContext& testContext)
{
    struct AdminSubtractUserVirtualCurrencyResultHolder : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminSubtractUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminSubtractUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminSubtractUserVirtualCurrencyResultHolder>>(testContext);

    PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper<> request;
    FillAdminSubtractUserVirtualCurrencyRequest(request);
    LogAdminSubtractUserVirtualCurrencyRequest(&request.Model(), "TestPlayerItemManagementAdminSubtractUserVirtualCurrency");
    HRESULT hr = PFPlayerItemManagementAdminSubtractUserVirtualCurrencyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminSubtractUserVirtualCurrencyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientAddUserVirtualCurrency

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientAddUserVirtualCurrency(TestContext& testContext)
{
    struct ClientAddUserVirtualCurrencyResultHolder : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientAddUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientAddUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientAddUserVirtualCurrencyResultHolder>>(testContext);

    PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper<> request;
    FillClientAddUserVirtualCurrencyRequest(request);
    LogClientAddUserVirtualCurrencyRequest(&request.Model(), "TestPlayerItemManagementClientAddUserVirtualCurrency");
    HRESULT hr = PFPlayerItemManagementClientAddUserVirtualCurrencyAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientAddUserVirtualCurrencyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientConfirmPurchase

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientConfirmPurchase(TestContext& testContext)
{
    struct ClientConfirmPurchaseResultHolder : public ConfirmPurchaseResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientConfirmPurchaseGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientConfirmPurchaseGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementConfirmPurchaseResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementConfirmPurchaseResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientConfirmPurchaseResultHolder>>(testContext);

    PFPlayerItemManagementConfirmPurchaseRequestWrapper<> request;
    FillConfirmPurchaseRequest(request);
    LogConfirmPurchaseRequest(&request.Model(), "TestPlayerItemManagementClientConfirmPurchase");
    HRESULT hr = PFPlayerItemManagementClientConfirmPurchaseAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientConfirmPurchaseAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientConsumeItem

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientConsumeItem(TestContext& testContext)
{
    struct ClientConsumeItemResultHolder : public ConsumeItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientConsumeItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientConsumeItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementConsumeItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementConsumeItemResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientConsumeItemResultHolder>>(testContext);

    PFPlayerItemManagementClientConsumeItemRequestWrapper<> request;
    FillClientConsumeItemRequest(request);
    LogClientConsumeItemRequest(&request.Model(), "TestPlayerItemManagementClientConsumeItem");
    HRESULT hr = PFPlayerItemManagementClientConsumeItemAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientConsumeItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetCharacterInventory

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientGetCharacterInventory(TestContext& testContext)
{
    struct ClientGetCharacterInventoryResultHolder : public ClientGetCharacterInventoryResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetCharacterInventoryGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetCharacterInventoryGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementClientGetCharacterInventoryResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementClientGetCharacterInventoryResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCharacterInventoryResultHolder>>(testContext);

    PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper<> request;
    FillClientGetCharacterInventoryRequest(request);
    LogClientGetCharacterInventoryRequest(&request.Model(), "TestPlayerItemManagementClientGetCharacterInventory");
    HRESULT hr = PFPlayerItemManagementClientGetCharacterInventoryAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientGetCharacterInventoryAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPaymentToken

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientGetPaymentToken(TestContext& testContext)
{
    struct ClientGetPaymentTokenResultHolder : public GetPaymentTokenResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetPaymentTokenGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetPaymentTokenGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementGetPaymentTokenResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementGetPaymentTokenResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPaymentTokenResultHolder>>(testContext);

    PFPlayerItemManagementGetPaymentTokenRequestWrapper<> request;
    FillGetPaymentTokenRequest(request);
    LogGetPaymentTokenRequest(&request.Model(), "TestPlayerItemManagementClientGetPaymentToken");
    HRESULT hr = PFPlayerItemManagementClientGetPaymentTokenAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientGetPaymentTokenAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPurchase

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientGetPurchase(TestContext& testContext)
{
    struct ClientGetPurchaseResultHolder : public GetPurchaseResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetPurchaseGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetPurchaseGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementGetPurchaseResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementGetPurchaseResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPurchaseResultHolder>>(testContext);

    PFPlayerItemManagementGetPurchaseRequestWrapper<> request;
    FillGetPurchaseRequest(request);
    LogGetPurchaseRequest(&request.Model(), "TestPlayerItemManagementClientGetPurchase");
    HRESULT hr = PFPlayerItemManagementClientGetPurchaseAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientGetPurchaseAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetUserInventory

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientGetUserInventory(TestContext& testContext)
{
    struct ClientGetUserInventoryResultHolder : public ClientGetUserInventoryResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetUserInventoryGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetUserInventoryGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementClientGetUserInventoryResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementClientGetUserInventoryResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetUserInventoryResultHolder>>(testContext);

    PFPlayerItemManagementClientGetUserInventoryRequestWrapper<> request;
    FillClientGetUserInventoryRequest(request);
    LogClientGetUserInventoryRequest(&request.Model(), "TestPlayerItemManagementClientGetUserInventory");
    HRESULT hr = PFPlayerItemManagementClientGetUserInventoryAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientGetUserInventoryAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientPayForPurchase

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientPayForPurchase(TestContext& testContext)
{
    struct ClientPayForPurchaseResultHolder : public PayForPurchaseResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientPayForPurchaseGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientPayForPurchaseGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementPayForPurchaseResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementPayForPurchaseResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientPayForPurchaseResultHolder>>(testContext);

    PFPlayerItemManagementPayForPurchaseRequestWrapper<> request;
    FillPayForPurchaseRequest(request);
    LogPayForPurchaseRequest(&request.Model(), "TestPlayerItemManagementClientPayForPurchase");
    HRESULT hr = PFPlayerItemManagementClientPayForPurchaseAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientPayForPurchaseAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientPurchaseItem

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientPurchaseItem(TestContext& testContext)
{
    struct ClientPurchaseItemResultHolder : public PurchaseItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientPurchaseItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientPurchaseItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementPurchaseItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementPurchaseItemResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientPurchaseItemResultHolder>>(testContext);

    PFPlayerItemManagementPurchaseItemRequestWrapper<> request;
    FillPurchaseItemRequest(request);
    LogPurchaseItemRequest(&request.Model(), "TestPlayerItemManagementClientPurchaseItem");
    HRESULT hr = PFPlayerItemManagementClientPurchaseItemAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientPurchaseItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientRedeemCoupon

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientRedeemCoupon(TestContext& testContext)
{
    struct ClientRedeemCouponResultHolder : public RedeemCouponResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientRedeemCouponGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientRedeemCouponGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementRedeemCouponResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementRedeemCouponResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientRedeemCouponResultHolder>>(testContext);

    PFPlayerItemManagementClientRedeemCouponRequestWrapper<> request;
    FillClientRedeemCouponRequest(request);
    LogClientRedeemCouponRequest(&request.Model(), "TestPlayerItemManagementClientRedeemCoupon");
    HRESULT hr = PFPlayerItemManagementClientRedeemCouponAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientRedeemCouponAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientStartPurchase

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientStartPurchase(TestContext& testContext)
{
    struct ClientStartPurchaseResultHolder : public StartPurchaseResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientStartPurchaseGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientStartPurchaseGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementStartPurchaseResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementStartPurchaseResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientStartPurchaseResultHolder>>(testContext);

    PFPlayerItemManagementStartPurchaseRequestWrapper<> request;
    FillStartPurchaseRequest(request);
    LogStartPurchaseRequest(&request.Model(), "TestPlayerItemManagementClientStartPurchase");
    HRESULT hr = PFPlayerItemManagementClientStartPurchaseAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientStartPurchaseAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientSubtractUserVirtualCurrency

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientSubtractUserVirtualCurrency(TestContext& testContext)
{
    struct ClientSubtractUserVirtualCurrencyResultHolder : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientSubtractUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientSubtractUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientSubtractUserVirtualCurrencyResultHolder>>(testContext);

    PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper<> request;
    FillClientSubtractUserVirtualCurrencyRequest(request);
    LogClientSubtractUserVirtualCurrencyRequest(&request.Model(), "TestPlayerItemManagementClientSubtractUserVirtualCurrency");
    HRESULT hr = PFPlayerItemManagementClientSubtractUserVirtualCurrencyAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientSubtractUserVirtualCurrencyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUnlockContainerInstance

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientUnlockContainerInstance(TestContext& testContext)
{
    struct ClientUnlockContainerInstanceResultHolder : public UnlockContainerItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientUnlockContainerInstanceGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientUnlockContainerInstanceGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementUnlockContainerItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementUnlockContainerItemResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUnlockContainerInstanceResultHolder>>(testContext);

    PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper<> request;
    FillClientUnlockContainerInstanceRequest(request);
    LogClientUnlockContainerInstanceRequest(&request.Model(), "TestPlayerItemManagementClientUnlockContainerInstance");
    HRESULT hr = PFPlayerItemManagementClientUnlockContainerInstanceAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientUnlockContainerInstanceAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUnlockContainerItem

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientUnlockContainerItem(TestContext& testContext)
{
    struct ClientUnlockContainerItemResultHolder : public UnlockContainerItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientUnlockContainerItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientUnlockContainerItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementUnlockContainerItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementUnlockContainerItemResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUnlockContainerItemResultHolder>>(testContext);

    PFPlayerItemManagementClientUnlockContainerItemRequestWrapper<> request;
    FillClientUnlockContainerItemRequest(request);
    LogClientUnlockContainerItemRequest(&request.Model(), "TestPlayerItemManagementClientUnlockContainerItem");
    HRESULT hr = PFPlayerItemManagementClientUnlockContainerItemAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementClientUnlockContainerItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerAddCharacterVirtualCurrency

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerAddCharacterVirtualCurrency(TestContext& testContext)
{
    struct ServerAddCharacterVirtualCurrencyResultHolder : public ModifyCharacterVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerAddCharacterVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerAddCharacterVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementModifyCharacterVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementModifyCharacterVirtualCurrencyResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerAddCharacterVirtualCurrencyResultHolder>>(testContext);

    PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper<> request;
    FillAddCharacterVirtualCurrencyRequest(request);
    LogAddCharacterVirtualCurrencyRequest(&request.Model(), "TestPlayerItemManagementServerAddCharacterVirtualCurrency");
    HRESULT hr = PFPlayerItemManagementServerAddCharacterVirtualCurrencyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerAddCharacterVirtualCurrencyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerAddUserVirtualCurrency

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerAddUserVirtualCurrency(TestContext& testContext)
{
    struct ServerAddUserVirtualCurrencyResultHolder : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerAddUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerAddUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerAddUserVirtualCurrencyResultHolder>>(testContext);

    PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper<> request;
    FillServerAddUserVirtualCurrencyRequest(request);
    LogServerAddUserVirtualCurrencyRequest(&request.Model(), "TestPlayerItemManagementServerAddUserVirtualCurrency");
    HRESULT hr = PFPlayerItemManagementServerAddUserVirtualCurrencyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerAddUserVirtualCurrencyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerConsumeItem

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerConsumeItem(TestContext& testContext)
{
    struct ServerConsumeItemResultHolder : public ConsumeItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerConsumeItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerConsumeItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementConsumeItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementConsumeItemResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerConsumeItemResultHolder>>(testContext);

    PFPlayerItemManagementServerConsumeItemRequestWrapper<> request;
    FillServerConsumeItemRequest(request);
    LogServerConsumeItemRequest(&request.Model(), "TestPlayerItemManagementServerConsumeItem");
    HRESULT hr = PFPlayerItemManagementServerConsumeItemAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerConsumeItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerEvaluateRandomResultTable

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerEvaluateRandomResultTable(TestContext& testContext)
{
    struct ServerEvaluateRandomResultTableResultHolder : public EvaluateRandomResultTableResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerEvaluateRandomResultTableGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerEvaluateRandomResultTableGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementEvaluateRandomResultTableResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementEvaluateRandomResultTableResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerEvaluateRandomResultTableResultHolder>>(testContext);

    PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper<> request;
    FillEvaluateRandomResultTableRequest(request);
    LogEvaluateRandomResultTableRequest(&request.Model(), "TestPlayerItemManagementServerEvaluateRandomResultTable");
    HRESULT hr = PFPlayerItemManagementServerEvaluateRandomResultTableAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerEvaluateRandomResultTableAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetCharacterInventory

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetCharacterInventory(TestContext& testContext)
{
    struct ServerGetCharacterInventoryResultHolder : public ServerGetCharacterInventoryResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetCharacterInventoryGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetCharacterInventoryGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementServerGetCharacterInventoryResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementServerGetCharacterInventoryResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterInventoryResultHolder>>(testContext);

    PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper<> request;
    FillServerGetCharacterInventoryRequest(request);
    LogServerGetCharacterInventoryRequest(&request.Model(), "TestPlayerItemManagementServerGetCharacterInventory");
    HRESULT hr = PFPlayerItemManagementServerGetCharacterInventoryAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerGetCharacterInventoryAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetRandomResultTables

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetRandomResultTables(TestContext& testContext)
{
    struct ServerGetRandomResultTablesResultHolder : public GetRandomResultTablesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetRandomResultTablesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetRandomResultTablesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGetRandomResultTablesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGetRandomResultTablesResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetRandomResultTablesResultHolder>>(testContext);

    PFPlayerItemManagementGetRandomResultTablesRequestWrapper<> request;
    FillGetRandomResultTablesRequest(request);
    LogGetRandomResultTablesRequest(&request.Model(), "TestPlayerItemManagementServerGetRandomResultTables");
    HRESULT hr = PFPlayerItemManagementServerGetRandomResultTablesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerGetRandomResultTablesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetUserInventory

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetUserInventory(TestContext& testContext)
{
    struct ServerGetUserInventoryResultHolder : public ServerGetUserInventoryResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetUserInventoryGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetUserInventoryGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementServerGetUserInventoryResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementServerGetUserInventoryResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserInventoryResultHolder>>(testContext);

    PFPlayerItemManagementServerGetUserInventoryRequestWrapper<> request;
    FillServerGetUserInventoryRequest(request);
    LogServerGetUserInventoryRequest(&request.Model(), "TestPlayerItemManagementServerGetUserInventory");
    HRESULT hr = PFPlayerItemManagementServerGetUserInventoryAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerGetUserInventoryAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGrantItemsToCharacter

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToCharacter(TestContext& testContext)
{
    struct ServerGrantItemsToCharacterResultHolder : public GrantItemsToCharacterResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToCharacterGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToCharacterGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementGrantItemsToCharacterResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementGrantItemsToCharacterResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGrantItemsToCharacterResultHolder>>(testContext);

    PFPlayerItemManagementGrantItemsToCharacterRequestWrapper<> request;
    FillGrantItemsToCharacterRequest(request);
    LogGrantItemsToCharacterRequest(&request.Model(), "TestPlayerItemManagementServerGrantItemsToCharacter");
    HRESULT hr = PFPlayerItemManagementServerGrantItemsToCharacterAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerGrantItemsToCharacterAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGrantItemsToUser

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToUser(TestContext& testContext)
{
    struct ServerGrantItemsToUserResultHolder : public GrantItemsToUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementGrantItemsToUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementGrantItemsToUserResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGrantItemsToUserResultHolder>>(testContext);

    PFPlayerItemManagementGrantItemsToUserRequestWrapper<> request;
    FillGrantItemsToUserRequest(request);
    LogGrantItemsToUserRequest(&request.Model(), "TestPlayerItemManagementServerGrantItemsToUser");
    HRESULT hr = PFPlayerItemManagementServerGrantItemsToUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerGrantItemsToUserAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGrantItemsToUsers

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToUsers(TestContext& testContext)
{
    struct ServerGrantItemsToUsersResultHolder : public GrantItemsToUsersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToUsersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToUsersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementGrantItemsToUsersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementGrantItemsToUsersResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGrantItemsToUsersResultHolder>>(testContext);

    PFPlayerItemManagementGrantItemsToUsersRequestWrapper<> request;
    FillGrantItemsToUsersRequest(request);
    LogGrantItemsToUsersRequest(&request.Model(), "TestPlayerItemManagementServerGrantItemsToUsers");
    HRESULT hr = PFPlayerItemManagementServerGrantItemsToUsersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerGrantItemsToUsersAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerModifyItemUses

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerModifyItemUses(TestContext& testContext)
{
    struct ServerModifyItemUsesResultHolder : public ModifyItemUsesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerModifyItemUsesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerModifyItemUsesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementModifyItemUsesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementModifyItemUsesResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerModifyItemUsesResultHolder>>(testContext);

    PFPlayerItemManagementModifyItemUsesRequestWrapper<> request;
    FillModifyItemUsesRequest(request);
    LogModifyItemUsesRequest(&request.Model(), "TestPlayerItemManagementServerModifyItemUses");
    HRESULT hr = PFPlayerItemManagementServerModifyItemUsesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerModifyItemUsesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerMoveItemToCharacterFromCharacter

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToCharacterFromCharacter(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper<> request;
    FillMoveItemToCharacterFromCharacterRequest(request);
    LogMoveItemToCharacterFromCharacterRequest(&request.Model(), "TestPlayerItemManagementServerMoveItemToCharacterFromCharacter");
    HRESULT hr = PFPlayerItemManagementServerMoveItemToCharacterFromCharacterAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerMoveItemToCharacterFromCharacterAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerMoveItemToCharacterFromUser

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToCharacterFromUser(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper<> request;
    FillMoveItemToCharacterFromUserRequest(request);
    LogMoveItemToCharacterFromUserRequest(&request.Model(), "TestPlayerItemManagementServerMoveItemToCharacterFromUser");
    HRESULT hr = PFPlayerItemManagementServerMoveItemToCharacterFromUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerMoveItemToCharacterFromUserAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerMoveItemToUserFromCharacter

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToUserFromCharacter(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper<> request;
    FillMoveItemToUserFromCharacterRequest(request);
    LogMoveItemToUserFromCharacterRequest(&request.Model(), "TestPlayerItemManagementServerMoveItemToUserFromCharacter");
    HRESULT hr = PFPlayerItemManagementServerMoveItemToUserFromCharacterAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerMoveItemToUserFromCharacterAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerRedeemCoupon

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRedeemCoupon(TestContext& testContext)
{
    struct ServerRedeemCouponResultHolder : public RedeemCouponResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerRedeemCouponGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerRedeemCouponGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementRedeemCouponResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementRedeemCouponResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerRedeemCouponResultHolder>>(testContext);

    PFPlayerItemManagementServerRedeemCouponRequestWrapper<> request;
    FillServerRedeemCouponRequest(request);
    LogServerRedeemCouponRequest(&request.Model(), "TestPlayerItemManagementServerRedeemCoupon");
    HRESULT hr = PFPlayerItemManagementServerRedeemCouponAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerRedeemCouponAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerReportPlayer

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerReportPlayer(TestContext& testContext)
{
    struct ServerReportPlayerResultHolder : public ReportPlayerServerResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerReportPlayerGetResult(async, &result)));
            LogPFPlayerItemManagementReportPlayerServerResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementReportPlayerServerResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerReportPlayerResultHolder>>(testContext);

    PFPlayerItemManagementReportPlayerServerRequestWrapper<> request;
    FillReportPlayerServerRequest(request);
    LogReportPlayerServerRequest(&request.Model(), "TestPlayerItemManagementServerReportPlayer");
    HRESULT hr = PFPlayerItemManagementServerReportPlayerAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerReportPlayerAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerRevokeInventoryItem

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRevokeInventoryItem(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementRevokeInventoryItemRequestWrapper<> request;
    FillRevokeInventoryItemRequest(request);
    LogRevokeInventoryItemRequest(&request.Model(), "TestPlayerItemManagementServerRevokeInventoryItem");
    HRESULT hr = PFPlayerItemManagementServerRevokeInventoryItemAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerRevokeInventoryItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerRevokeInventoryItems

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRevokeInventoryItems(TestContext& testContext)
{
    struct ServerRevokeInventoryItemsResultHolder : public RevokeInventoryItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerRevokeInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerRevokeInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementRevokeInventoryItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementRevokeInventoryItemsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerRevokeInventoryItemsResultHolder>>(testContext);

    PFPlayerItemManagementRevokeInventoryItemsRequestWrapper<> request;
    FillRevokeInventoryItemsRequest(request);
    LogRevokeInventoryItemsRequest(&request.Model(), "TestPlayerItemManagementServerRevokeInventoryItems");
    HRESULT hr = PFPlayerItemManagementServerRevokeInventoryItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerRevokeInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerSubtractCharacterVirtualCurrency

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerSubtractCharacterVirtualCurrency(TestContext& testContext)
{
    struct ServerSubtractCharacterVirtualCurrencyResultHolder : public ModifyCharacterVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerSubtractCharacterVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerSubtractCharacterVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementModifyCharacterVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementModifyCharacterVirtualCurrencyResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerSubtractCharacterVirtualCurrencyResultHolder>>(testContext);

    PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper<> request;
    FillSubtractCharacterVirtualCurrencyRequest(request);
    LogSubtractCharacterVirtualCurrencyRequest(&request.Model(), "TestPlayerItemManagementServerSubtractCharacterVirtualCurrency");
    HRESULT hr = PFPlayerItemManagementServerSubtractCharacterVirtualCurrencyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerSubtractCharacterVirtualCurrencyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerSubtractUserVirtualCurrency

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerSubtractUserVirtualCurrency(TestContext& testContext)
{
    struct ServerSubtractUserVirtualCurrencyResultHolder : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerSubtractUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerSubtractUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementModifyUserVirtualCurrencyResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerSubtractUserVirtualCurrencyResultHolder>>(testContext);

    PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper<> request;
    FillServerSubtractUserVirtualCurrencyRequest(request);
    LogServerSubtractUserVirtualCurrencyRequest(&request.Model(), "TestPlayerItemManagementServerSubtractUserVirtualCurrency");
    HRESULT hr = PFPlayerItemManagementServerSubtractUserVirtualCurrencyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerSubtractUserVirtualCurrencyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerUnlockContainerInstance

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUnlockContainerInstance(TestContext& testContext)
{
    struct ServerUnlockContainerInstanceResultHolder : public UnlockContainerItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerUnlockContainerInstanceGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerUnlockContainerInstanceGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementUnlockContainerItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementUnlockContainerItemResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUnlockContainerInstanceResultHolder>>(testContext);

    PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper<> request;
    FillServerUnlockContainerInstanceRequest(request);
    LogServerUnlockContainerInstanceRequest(&request.Model(), "TestPlayerItemManagementServerUnlockContainerInstance");
    HRESULT hr = PFPlayerItemManagementServerUnlockContainerInstanceAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerUnlockContainerInstanceAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerUnlockContainerItem

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUnlockContainerItem(TestContext& testContext)
{
    struct ServerUnlockContainerItemResultHolder : public UnlockContainerItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerUnlockContainerItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerUnlockContainerItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerItemManagementUnlockContainerItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerItemManagementUnlockContainerItemResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUnlockContainerItemResultHolder>>(testContext);

    PFPlayerItemManagementServerUnlockContainerItemRequestWrapper<> request;
    FillServerUnlockContainerItemRequest(request);
    LogServerUnlockContainerItemRequest(&request.Model(), "TestPlayerItemManagementServerUnlockContainerItem");
    HRESULT hr = PFPlayerItemManagementServerUnlockContainerItemAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerUnlockContainerItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerUpdateUserInventoryItemCustomData

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUpdateUserInventoryItemCustomData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper<> request;
    FillUpdateUserInventoryItemDataRequest(request);
    LogUpdateUserInventoryItemDataRequest(&request.Model(), "TestPlayerItemManagementServerUpdateUserInventoryItemCustomData");
    HRESULT hr = PFPlayerItemManagementServerUpdateUserInventoryItemCustomDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerUpdateUserInventoryItemCustomDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
