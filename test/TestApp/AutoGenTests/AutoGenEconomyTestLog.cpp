#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenEconomyTests.h"
#include "XAsyncHelper.h"

uint32_t g_EconomyTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenEconomyTests::LogRefundPurchaseRequest(PFEconomyRefundPurchaseRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_EconomyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabEconomyRefundPurchaseRequest struct:
    // request->orderId: const char*
    if (request->orderId) { ss << "  orderId " << request->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->reason) { ss << "  reason " << request->reason; Log(ss); } else { ss << "  reason = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenEconomyTests::LogRefundPurchaseResponse(PFEconomyRefundPurchaseResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabEconomyRefundPurchaseResponse    
    if (result->purchaseStatus) { ss << "  purchaseStatus " << result->purchaseStatus; Log(ss); } else { ss << "  purchaseStatus = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenEconomyTests::LogResolvePurchaseDisputeRequest(PFEconomyResolvePurchaseDisputeRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_EconomyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabEconomyResolvePurchaseDisputeRequest struct:
    // request->orderId: const char*
    if (request->orderId) { ss << "  orderId " << request->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  outcome " << static_cast<uint32_t>(request->outcome); Log(ss); // Class: PFEconomyResolutionOutcome 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->reason) { ss << "  reason " << request->reason; Log(ss); } else { ss << "  reason = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenEconomyTests::LogResolvePurchaseDisputeResponse(PFEconomyResolvePurchaseDisputeResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabEconomyResolvePurchaseDisputeResponse    
    if (result->purchaseStatus) { ss << "  purchaseStatus " << result->purchaseStatus; Log(ss); } else { ss << "  purchaseStatus = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

 

}
