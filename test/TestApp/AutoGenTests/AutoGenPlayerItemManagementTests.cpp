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
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenPlayerItemManagementTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementAdminAddUserVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminAddUserVirtualCurrency);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementAdminCheckLimitedEditionItemAvailability", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminCheckLimitedEditionItemAvailability);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementAdminGetUserInventory", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminGetUserInventory);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementAdminGrantItemsToUsers", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminGrantItemsToUsers);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementAdminIncrementLimitedEditionItemAvailability", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminIncrementLimitedEditionItemAvailability);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementAdminRevokeInventoryItem", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminRevokeInventoryItem);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementAdminRevokeInventoryItems", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminRevokeInventoryItems);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementAdminSubtractUserVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminSubtractUserVirtualCurrency);
#endif

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

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerAddCharacterVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerAddCharacterVirtualCurrency);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerAddUserVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerAddUserVirtualCurrency);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerConsumeItem", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerConsumeItem);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerEvaluateRandomResultTable", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerEvaluateRandomResultTable);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerGetCharacterInventory", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetCharacterInventory);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerGetRandomResultTables", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetRandomResultTables);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerGetUserInventory", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetUserInventory);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerGrantItemsToCharacter", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToCharacter);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerGrantItemsToUser", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerGrantItemsToUsers", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToUsers);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerModifyItemUses", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerModifyItemUses);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerMoveItemToCharacterFromCharacter", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToCharacterFromCharacter);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerMoveItemToCharacterFromUser", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToCharacterFromUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerMoveItemToUserFromCharacter", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToUserFromCharacter);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerRedeemCoupon", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRedeemCoupon);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerReportPlayer", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerReportPlayer);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerRevokeInventoryItem", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRevokeInventoryItem);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerRevokeInventoryItems", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRevokeInventoryItems);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerSubtractCharacterVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerSubtractCharacterVirtualCurrency);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerSubtractUserVirtualCurrency", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerSubtractUserVirtualCurrency);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerUnlockContainerInstance", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUnlockContainerInstance);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerUnlockContainerItem", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUnlockContainerItem);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerItemManagementServerUpdateUserInventoryItemCustomData", &AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUpdateUserInventoryItemCustomData);
#endif
}

void AutoGenPlayerItemManagementTests::ClassSetUp()
{
    HRESULT hr = PFAdminInitialize(testTitleData.titleId.data(), testTitleData.developerSecretKey.data(), testTitleData.connectionString.data(), nullptr, &stateHandle);
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

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminAddUserVirtualCurrency(TestContext& testContext)
{
    struct AdminAddUserVirtualCurrencyResultHolderStruct : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminAddUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminAddUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminAddUserVirtualCurrencyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminAddUserVirtualCurrencyResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region AdminCheckLimitedEditionItemAvailability

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminCheckLimitedEditionItemAvailability(TestContext& testContext)
{
    struct AdminCheckLimitedEditionItemAvailabilityResultHolderStruct : public CheckLimitedEditionItemAvailabilityResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminCheckLimitedEditionItemAvailabilityGetResult(async, &result)));
            LogCheckLimitedEditionItemAvailabilityResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminCheckLimitedEditionItemAvailabilityResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminCheckLimitedEditionItemAvailabilityResultHolderStruct>>(testContext);

    PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper<> request;
    FillAdminCheckLimitedEditionItemAvailabilityRequest(request);
    LogCheckLimitedEditionItemAvailabilityRequest(&request.Model(), "TestPlayerItemManagementAdminCheckLimitedEditionItemAvailability");
    HRESULT hr = PFPlayerItemManagementAdminCheckLimitedEditionItemAvailabilityAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminCheckLimitedEditionItemAvailabilityAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetUserInventory

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminGetUserInventory(TestContext& testContext)
{
    struct AdminGetUserInventoryResultHolderStruct : public AdminGetUserInventoryResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminGetUserInventoryGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminGetUserInventoryGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAdminGetUserInventoryResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetUserInventoryResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserInventoryResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region AdminGrantItemsToUsers

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminGrantItemsToUsers(TestContext& testContext)
{
    struct AdminGrantItemsToUsersResultHolderStruct : public GrantItemsToUsersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminGrantItemsToUsersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminGrantItemsToUsersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGrantItemsToUsersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGrantItemsToUsersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGrantItemsToUsersResultHolderStruct>>(testContext);

    PFPlayerItemManagementGrantItemsToUsersRequestWrapper<> request;
    FillAdminGrantItemsToUsersRequest(request);
    LogGrantItemsToUsersRequest(&request.Model(), "TestPlayerItemManagementAdminGrantItemsToUsers");
    HRESULT hr = PFPlayerItemManagementAdminGrantItemsToUsersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminGrantItemsToUsersAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminIncrementLimitedEditionItemAvailability

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminIncrementLimitedEditionItemAvailability(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper<> request;
    FillAdminIncrementLimitedEditionItemAvailabilityRequest(request);
    LogIncrementLimitedEditionItemAvailabilityRequest(&request.Model(), "TestPlayerItemManagementAdminIncrementLimitedEditionItemAvailability");
    HRESULT hr = PFPlayerItemManagementAdminIncrementLimitedEditionItemAvailabilityAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminIncrementLimitedEditionItemAvailabilityAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminRevokeInventoryItem

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminRevokeInventoryItem(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementRevokeInventoryItemRequestWrapper<> request;
    FillAdminRevokeInventoryItemRequest(request);
    LogRevokeInventoryItemRequest(&request.Model(), "TestPlayerItemManagementAdminRevokeInventoryItem");
    HRESULT hr = PFPlayerItemManagementAdminRevokeInventoryItemAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminRevokeInventoryItemAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminRevokeInventoryItems

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminRevokeInventoryItems(TestContext& testContext)
{
    struct AdminRevokeInventoryItemsResultHolderStruct : public RevokeInventoryItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminRevokeInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminRevokeInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRevokeInventoryItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminRevokeInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminRevokeInventoryItemsResultHolderStruct>>(testContext);

    PFPlayerItemManagementRevokeInventoryItemsRequestWrapper<> request;
    FillAdminRevokeInventoryItemsRequest(request);
    LogRevokeInventoryItemsRequest(&request.Model(), "TestPlayerItemManagementAdminRevokeInventoryItems");
    HRESULT hr = PFPlayerItemManagementAdminRevokeInventoryItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementAdminRevokeInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSubtractUserVirtualCurrency

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementAdminSubtractUserVirtualCurrency(TestContext& testContext)
{
    struct AdminSubtractUserVirtualCurrencyResultHolderStruct : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminSubtractUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementAdminSubtractUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminSubtractUserVirtualCurrencyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminSubtractUserVirtualCurrencyResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ClientAddUserVirtualCurrency

void AutoGenPlayerItemManagementTests::TestPlayerItemManagementClientAddUserVirtualCurrency(TestContext& testContext)
{
    struct ClientAddUserVirtualCurrencyResultHolderStruct : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientAddUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientAddUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientAddUserVirtualCurrencyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientAddUserVirtualCurrencyResultHolderStruct>>(testContext);

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
    struct ClientConfirmPurchaseResultHolderStruct : public ConfirmPurchaseResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientConfirmPurchaseGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientConfirmPurchaseGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogConfirmPurchaseResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientConfirmPurchaseResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientConfirmPurchaseResultHolderStruct>>(testContext);

    PFPlayerItemManagementConfirmPurchaseRequestWrapper<> request;
    FillClientConfirmPurchaseRequest(request);
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
    struct ClientConsumeItemResultHolderStruct : public ConsumeItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientConsumeItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientConsumeItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogConsumeItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientConsumeItemResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientConsumeItemResultHolderStruct>>(testContext);

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
    struct ClientGetCharacterInventoryResultHolderStruct : public ClientGetCharacterInventoryResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetCharacterInventoryGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetCharacterInventoryGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogClientGetCharacterInventoryResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetCharacterInventoryResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCharacterInventoryResultHolderStruct>>(testContext);

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
    struct ClientGetPaymentTokenResultHolderStruct : public GetPaymentTokenResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetPaymentTokenGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetPaymentTokenGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPaymentTokenResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetPaymentTokenResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPaymentTokenResultHolderStruct>>(testContext);

    PFPlayerItemManagementGetPaymentTokenRequestWrapper<> request;
    FillClientGetPaymentTokenRequest(request);
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
    struct ClientGetPurchaseResultHolderStruct : public GetPurchaseResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetPurchaseGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetPurchaseGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPurchaseResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetPurchaseResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPurchaseResultHolderStruct>>(testContext);

    PFPlayerItemManagementGetPurchaseRequestWrapper<> request;
    FillClientGetPurchaseRequest(request);
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
    struct ClientGetUserInventoryResultHolderStruct : public ClientGetUserInventoryResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetUserInventoryGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientGetUserInventoryGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogClientGetUserInventoryResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetUserInventoryResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetUserInventoryResultHolderStruct>>(testContext);

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
    struct ClientPayForPurchaseResultHolderStruct : public PayForPurchaseResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientPayForPurchaseGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientPayForPurchaseGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPayForPurchaseResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientPayForPurchaseResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientPayForPurchaseResultHolderStruct>>(testContext);

    PFPlayerItemManagementPayForPurchaseRequestWrapper<> request;
    FillClientPayForPurchaseRequest(request);
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
    struct ClientPurchaseItemResultHolderStruct : public PurchaseItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientPurchaseItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientPurchaseItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPurchaseItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientPurchaseItemResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientPurchaseItemResultHolderStruct>>(testContext);

    PFPlayerItemManagementPurchaseItemRequestWrapper<> request;
    FillClientPurchaseItemRequest(request);
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
    struct ClientRedeemCouponResultHolderStruct : public RedeemCouponResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientRedeemCouponGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientRedeemCouponGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRedeemCouponResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientRedeemCouponResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientRedeemCouponResultHolderStruct>>(testContext);

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
    struct ClientStartPurchaseResultHolderStruct : public StartPurchaseResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientStartPurchaseGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientStartPurchaseGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogStartPurchaseResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientStartPurchaseResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientStartPurchaseResultHolderStruct>>(testContext);

    PFPlayerItemManagementStartPurchaseRequestWrapper<> request;
    FillClientStartPurchaseRequest(request);
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
    struct ClientSubtractUserVirtualCurrencyResultHolderStruct : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientSubtractUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientSubtractUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientSubtractUserVirtualCurrencyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientSubtractUserVirtualCurrencyResultHolderStruct>>(testContext);

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
    struct ClientUnlockContainerInstanceResultHolderStruct : public UnlockContainerItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientUnlockContainerInstanceGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientUnlockContainerInstanceGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogUnlockContainerItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientUnlockContainerInstanceResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUnlockContainerInstanceResultHolderStruct>>(testContext);

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
    struct ClientUnlockContainerItemResultHolderStruct : public UnlockContainerItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientUnlockContainerItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementClientUnlockContainerItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogUnlockContainerItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientUnlockContainerItemResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUnlockContainerItemResultHolderStruct>>(testContext);

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

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerAddCharacterVirtualCurrency(TestContext& testContext)
{
    struct ServerAddCharacterVirtualCurrencyResultHolderStruct : public ModifyCharacterVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerAddCharacterVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerAddCharacterVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogModifyCharacterVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerAddCharacterVirtualCurrencyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerAddCharacterVirtualCurrencyResultHolderStruct>>(testContext);

    PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper<> request;
    FillServerAddCharacterVirtualCurrencyRequest(request);
    LogAddCharacterVirtualCurrencyRequest(&request.Model(), "TestPlayerItemManagementServerAddCharacterVirtualCurrency");
    HRESULT hr = PFPlayerItemManagementServerAddCharacterVirtualCurrencyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerAddCharacterVirtualCurrencyAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerAddUserVirtualCurrency

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerAddUserVirtualCurrency(TestContext& testContext)
{
    struct ServerAddUserVirtualCurrencyResultHolderStruct : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerAddUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerAddUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerAddUserVirtualCurrencyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerAddUserVirtualCurrencyResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerConsumeItem

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerConsumeItem(TestContext& testContext)
{
    struct ServerConsumeItemResultHolderStruct : public ConsumeItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerConsumeItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerConsumeItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogConsumeItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerConsumeItemResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerConsumeItemResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerEvaluateRandomResultTable

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerEvaluateRandomResultTable(TestContext& testContext)
{
    struct ServerEvaluateRandomResultTableResultHolderStruct : public EvaluateRandomResultTableResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerEvaluateRandomResultTableGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerEvaluateRandomResultTableGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogEvaluateRandomResultTableResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerEvaluateRandomResultTableResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerEvaluateRandomResultTableResultHolderStruct>>(testContext);

    PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper<> request;
    FillServerEvaluateRandomResultTableRequest(request);
    LogEvaluateRandomResultTableRequest(&request.Model(), "TestPlayerItemManagementServerEvaluateRandomResultTable");
    HRESULT hr = PFPlayerItemManagementServerEvaluateRandomResultTableAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerEvaluateRandomResultTableAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetCharacterInventory

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetCharacterInventory(TestContext& testContext)
{
    struct ServerGetCharacterInventoryResultHolderStruct : public ServerGetCharacterInventoryResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetCharacterInventoryGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetCharacterInventoryGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetCharacterInventoryResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetCharacterInventoryResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterInventoryResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerGetRandomResultTables

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetRandomResultTables(TestContext& testContext)
{
    struct ServerGetRandomResultTablesResultHolderStruct : public GetRandomResultTablesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetRandomResultTablesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetRandomResultTablesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetRandomResultTablesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetRandomResultTablesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetRandomResultTablesResultHolderStruct>>(testContext);

    PFPlayerItemManagementGetRandomResultTablesRequestWrapper<> request;
    FillServerGetRandomResultTablesRequest(request);
    LogGetRandomResultTablesRequest(&request.Model(), "TestPlayerItemManagementServerGetRandomResultTables");
    HRESULT hr = PFPlayerItemManagementServerGetRandomResultTablesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerGetRandomResultTablesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetUserInventory

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGetUserInventory(TestContext& testContext)
{
    struct ServerGetUserInventoryResultHolderStruct : public ServerGetUserInventoryResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetUserInventoryGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGetUserInventoryGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetUserInventoryResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetUserInventoryResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserInventoryResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerGrantItemsToCharacter

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToCharacter(TestContext& testContext)
{
    struct ServerGrantItemsToCharacterResultHolderStruct : public GrantItemsToCharacterResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToCharacterGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToCharacterGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGrantItemsToCharacterResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGrantItemsToCharacterResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGrantItemsToCharacterResultHolderStruct>>(testContext);

    PFPlayerItemManagementGrantItemsToCharacterRequestWrapper<> request;
    FillServerGrantItemsToCharacterRequest(request);
    LogGrantItemsToCharacterRequest(&request.Model(), "TestPlayerItemManagementServerGrantItemsToCharacter");
    HRESULT hr = PFPlayerItemManagementServerGrantItemsToCharacterAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerGrantItemsToCharacterAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGrantItemsToUser

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToUser(TestContext& testContext)
{
    struct ServerGrantItemsToUserResultHolderStruct : public GrantItemsToUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGrantItemsToUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGrantItemsToUserResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGrantItemsToUserResultHolderStruct>>(testContext);

    PFPlayerItemManagementGrantItemsToUserRequestWrapper<> request;
    FillServerGrantItemsToUserRequest(request);
    LogGrantItemsToUserRequest(&request.Model(), "TestPlayerItemManagementServerGrantItemsToUser");
    HRESULT hr = PFPlayerItemManagementServerGrantItemsToUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerGrantItemsToUserAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGrantItemsToUsers

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerGrantItemsToUsers(TestContext& testContext)
{
    struct ServerGrantItemsToUsersResultHolderStruct : public GrantItemsToUsersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToUsersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerGrantItemsToUsersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGrantItemsToUsersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGrantItemsToUsersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGrantItemsToUsersResultHolderStruct>>(testContext);

    PFPlayerItemManagementGrantItemsToUsersRequestWrapper<> request;
    FillServerGrantItemsToUsersRequest(request);
    LogGrantItemsToUsersRequest(&request.Model(), "TestPlayerItemManagementServerGrantItemsToUsers");
    HRESULT hr = PFPlayerItemManagementServerGrantItemsToUsersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerGrantItemsToUsersAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerModifyItemUses

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerModifyItemUses(TestContext& testContext)
{
    struct ServerModifyItemUsesResultHolderStruct : public ModifyItemUsesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerModifyItemUsesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerModifyItemUsesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogModifyItemUsesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerModifyItemUsesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerModifyItemUsesResultHolderStruct>>(testContext);

    PFPlayerItemManagementModifyItemUsesRequestWrapper<> request;
    FillServerModifyItemUsesRequest(request);
    LogModifyItemUsesRequest(&request.Model(), "TestPlayerItemManagementServerModifyItemUses");
    HRESULT hr = PFPlayerItemManagementServerModifyItemUsesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerModifyItemUsesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerMoveItemToCharacterFromCharacter

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToCharacterFromCharacter(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper<> request;
    FillServerMoveItemToCharacterFromCharacterRequest(request);
    LogMoveItemToCharacterFromCharacterRequest(&request.Model(), "TestPlayerItemManagementServerMoveItemToCharacterFromCharacter");
    HRESULT hr = PFPlayerItemManagementServerMoveItemToCharacterFromCharacterAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerMoveItemToCharacterFromCharacterAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerMoveItemToCharacterFromUser

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToCharacterFromUser(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper<> request;
    FillServerMoveItemToCharacterFromUserRequest(request);
    LogMoveItemToCharacterFromUserRequest(&request.Model(), "TestPlayerItemManagementServerMoveItemToCharacterFromUser");
    HRESULT hr = PFPlayerItemManagementServerMoveItemToCharacterFromUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerMoveItemToCharacterFromUserAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerMoveItemToUserFromCharacter

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerMoveItemToUserFromCharacter(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper<> request;
    FillServerMoveItemToUserFromCharacterRequest(request);
    LogMoveItemToUserFromCharacterRequest(&request.Model(), "TestPlayerItemManagementServerMoveItemToUserFromCharacter");
    HRESULT hr = PFPlayerItemManagementServerMoveItemToUserFromCharacterAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerMoveItemToUserFromCharacterAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerRedeemCoupon

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRedeemCoupon(TestContext& testContext)
{
    struct ServerRedeemCouponResultHolderStruct : public RedeemCouponResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerRedeemCouponGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerRedeemCouponGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRedeemCouponResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerRedeemCouponResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerRedeemCouponResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerReportPlayer

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerReportPlayer(TestContext& testContext)
{
    struct ServerReportPlayerResultHolderStruct : public ReportPlayerServerResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerReportPlayerGetResult(async, &result)));
            LogReportPlayerServerResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerReportPlayerResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerReportPlayerResultHolderStruct>>(testContext);

    PFPlayerItemManagementReportPlayerServerRequestWrapper<> request;
    FillServerReportPlayerRequest(request);
    LogReportPlayerServerRequest(&request.Model(), "TestPlayerItemManagementServerReportPlayer");
    HRESULT hr = PFPlayerItemManagementServerReportPlayerAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerReportPlayerAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerRevokeInventoryItem

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRevokeInventoryItem(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementRevokeInventoryItemRequestWrapper<> request;
    FillServerRevokeInventoryItemRequest(request);
    LogRevokeInventoryItemRequest(&request.Model(), "TestPlayerItemManagementServerRevokeInventoryItem");
    HRESULT hr = PFPlayerItemManagementServerRevokeInventoryItemAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerRevokeInventoryItemAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerRevokeInventoryItems

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerRevokeInventoryItems(TestContext& testContext)
{
    struct ServerRevokeInventoryItemsResultHolderStruct : public RevokeInventoryItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerRevokeInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerRevokeInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRevokeInventoryItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerRevokeInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerRevokeInventoryItemsResultHolderStruct>>(testContext);

    PFPlayerItemManagementRevokeInventoryItemsRequestWrapper<> request;
    FillServerRevokeInventoryItemsRequest(request);
    LogRevokeInventoryItemsRequest(&request.Model(), "TestPlayerItemManagementServerRevokeInventoryItems");
    HRESULT hr = PFPlayerItemManagementServerRevokeInventoryItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerRevokeInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSubtractCharacterVirtualCurrency

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerSubtractCharacterVirtualCurrency(TestContext& testContext)
{
    struct ServerSubtractCharacterVirtualCurrencyResultHolderStruct : public ModifyCharacterVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerSubtractCharacterVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerSubtractCharacterVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogModifyCharacterVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerSubtractCharacterVirtualCurrencyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerSubtractCharacterVirtualCurrencyResultHolderStruct>>(testContext);

    PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper<> request;
    FillServerSubtractCharacterVirtualCurrencyRequest(request);
    LogSubtractCharacterVirtualCurrencyRequest(&request.Model(), "TestPlayerItemManagementServerSubtractCharacterVirtualCurrency");
    HRESULT hr = PFPlayerItemManagementServerSubtractCharacterVirtualCurrencyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerSubtractCharacterVirtualCurrencyAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSubtractUserVirtualCurrency

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerSubtractUserVirtualCurrency(TestContext& testContext)
{
    struct ServerSubtractUserVirtualCurrencyResultHolderStruct : public ModifyUserVirtualCurrencyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerSubtractUserVirtualCurrencyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerSubtractUserVirtualCurrencyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogModifyUserVirtualCurrencyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerSubtractUserVirtualCurrencyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerSubtractUserVirtualCurrencyResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerUnlockContainerInstance

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUnlockContainerInstance(TestContext& testContext)
{
    struct ServerUnlockContainerInstanceResultHolderStruct : public UnlockContainerItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerUnlockContainerInstanceGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerUnlockContainerInstanceGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogUnlockContainerItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerUnlockContainerInstanceResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUnlockContainerInstanceResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerUnlockContainerItem

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUnlockContainerItem(TestContext& testContext)
{
    struct ServerUnlockContainerItemResultHolderStruct : public UnlockContainerItemResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerUnlockContainerItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerItemManagementServerUnlockContainerItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogUnlockContainerItemResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerUnlockContainerItemResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUnlockContainerItemResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerUpdateUserInventoryItemCustomData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerItemManagementTests::TestPlayerItemManagementServerUpdateUserInventoryItemCustomData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper<> request;
    FillServerUpdateUserInventoryItemCustomDataRequest(request);
    LogUpdateUserInventoryItemDataRequest(&request.Model(), "TestPlayerItemManagementServerUpdateUserInventoryItemCustomData");
    HRESULT hr = PFPlayerItemManagementServerUpdateUserInventoryItemCustomDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerItemManagementPlayerItemManagementServerUpdateUserInventoryItemCustomDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
