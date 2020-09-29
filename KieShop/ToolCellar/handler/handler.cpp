//
// Created by sunbo on 2020/9/28.
//

#include "handler.h"
#include <spdlog/spdlog.h>
#include <string_util.h>
#include "../database/log_request.h"

using namespace KieShop::tool_cellar;

KieShop::tool_cellar::RequestLoggingResponse logRequest(const KieShop::tool_cellar::RequestLoggingRequest& request){
    SPDLOG_INFO("logID={} func=logRequest request = {}",request.base.logId,string_util::toString(request));
    RequestLoggingResponse resp;
    auto IP = request.base.data.find("ip")!=request.base.data.end()?request.base.data.at("ip"):"0.0.0.0";
    auto port = std::stoi(request.base.data.find("port")!=request.base.data.end()?request.base.data.at("port"):"0");
    auto rows = writeToTToolAccess(request.base.logId,IP,port,request.requestBody,request.responseBody);

    SPDLOG_INFO("logID={} func=logRequest response = {}",request.base.logId,rows);

    return resp;
}