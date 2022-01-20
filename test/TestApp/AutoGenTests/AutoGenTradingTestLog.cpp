#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenTradingTests.h"
#include "XAsyncHelper.h"

uint32_t g_TradingTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenTradingTests::LogAcceptTradeRequest(PFTradingAcceptTradeRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TradingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTradingAcceptTradeRequest struct:
    // request->acceptedInventoryInstanceIds: const char* const*
    // request->acceptedInventoryInstanceIdsCount: uint32_t    
    ss << "  acceptedInventoryInstanceIdsCount " << request->acceptedInventoryInstanceIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->acceptedInventoryInstanceIdsCount; i++)
    {
            ss << "  request->acceptedInventoryInstanceIds[" << i << "]:" << request->acceptedInventoryInstanceIds[i]; Log(ss); // const char*
    } 
    if (request->offeringPlayerId) { ss << "  offeringPlayerId " << request->offeringPlayerId; Log(ss); } else { ss << "  offeringPlayerId = nullptr"; Log(ss); } // Class: const char* 
    if (request->tradeId) { ss << "  tradeId " << request->tradeId; Log(ss); } else { ss << "  tradeId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenTradingTests::LogAcceptTradeResponse(PFTradingAcceptTradeResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTradingAcceptTradeResponse    
    ss << "  trade " << result->trade; Log(ss); // Class: PFTradingTradeInfo 
    return S_OK;
}

void AutoGenTradingTests::LogCancelTradeRequest(PFTradingCancelTradeRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TradingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTradingCancelTradeRequest struct:
    // request->tradeId: const char*
    if (request->tradeId) { ss << "  tradeId " << request->tradeId; Log(ss); } else { ss << "  tradeId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenTradingTests::LogCancelTradeResponse(PFTradingCancelTradeResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTradingCancelTradeResponse    
    ss << "  trade " << result->trade; Log(ss); // Class: PFTradingTradeInfo 
    return S_OK;
}

void AutoGenTradingTests::LogGetPlayerTradesRequest(PFTradingGetPlayerTradesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TradingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTradingGetPlayerTradesRequest struct:
    // request->statusFilter: PFTradingTradeStatus const*
    ss << "  statusFilter " << request->statusFilter; Log(ss); // Class: PFTradingTradeStatus 

}

HRESULT AutoGenTradingTests::LogGetPlayerTradesResponse(PFTradingGetPlayerTradesResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTradingGetPlayerTradesResponse        
    ss << "  acceptedTradesCount " << result->acceptedTradesCount; Log(ss);

    // PFTradingTradeInfo
    for (uint32_t i=0; i<result->acceptedTradesCount; i++)
    {
            ss << "  result->acceptedTrades[" << i << "]:" << result->acceptedTrades[i]; Log(ss); // PFTradingTradeInfo
    }         
    ss << "  openedTradesCount " << result->openedTradesCount; Log(ss);

    // PFTradingTradeInfo
    for (uint32_t i=0; i<result->openedTradesCount; i++)
    {
            ss << "  result->openedTrades[" << i << "]:" << result->openedTrades[i]; Log(ss); // PFTradingTradeInfo
    } 
    return S_OK;
}

void AutoGenTradingTests::LogGetTradeStatusRequest(PFTradingGetTradeStatusRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TradingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTradingGetTradeStatusRequest struct:
    // request->offeringPlayerId: const char*
    if (request->offeringPlayerId) { ss << "  offeringPlayerId " << request->offeringPlayerId; Log(ss); } else { ss << "  offeringPlayerId = nullptr"; Log(ss); } // Class: const char* 
    if (request->tradeId) { ss << "  tradeId " << request->tradeId; Log(ss); } else { ss << "  tradeId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenTradingTests::LogGetTradeStatusResponse(PFTradingGetTradeStatusResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTradingGetTradeStatusResponse    
    ss << "  trade " << result->trade; Log(ss); // Class: PFTradingTradeInfo 
    return S_OK;
}

void AutoGenTradingTests::LogOpenTradeRequest(PFTradingOpenTradeRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TradingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTradingOpenTradeRequest struct:
    // request->allowedPlayerIds: const char* const*
    // request->allowedPlayerIdsCount: uint32_t    
    ss << "  allowedPlayerIdsCount " << request->allowedPlayerIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->allowedPlayerIdsCount; i++)
    {
            ss << "  request->allowedPlayerIds[" << i << "]:" << request->allowedPlayerIds[i]; Log(ss); // const char*
    }     
    ss << "  offeredInventoryInstanceIdsCount " << request->offeredInventoryInstanceIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->offeredInventoryInstanceIdsCount; i++)
    {
            ss << "  request->offeredInventoryInstanceIds[" << i << "]:" << request->offeredInventoryInstanceIds[i]; Log(ss); // const char*
    }     
    ss << "  requestedCatalogItemIdsCount " << request->requestedCatalogItemIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->requestedCatalogItemIdsCount; i++)
    {
            ss << "  request->requestedCatalogItemIds[" << i << "]:" << request->requestedCatalogItemIds[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenTradingTests::LogOpenTradeResponse(PFTradingOpenTradeResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTradingOpenTradeResponse    
    ss << "  trade " << result->trade; Log(ss); // Class: PFTradingTradeInfo 
    return S_OK;
}

 

}
