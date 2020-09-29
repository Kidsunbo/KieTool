//
// Created by sunbo on 2020/9/29.
//

#include "log_request.h"
#include "tool_basic.h"
#include <iostream>
#include <spdlog/spdlog.h>

int writeToTToolAccess(const std::string& logID,const std::string& ip,int port,const std::string& request,const std::string& response){
    try {
        if (!ToolBasic::getInstance().getTable("t_tool_access").existsInDatabase()) {
            std::cout << ToolBasic::getInstance().getName() << std::endl;

            throw std::runtime_error("database does not exist");
        }
        //It will be easy when C++23 comes out, because of reflection
        auto res = ToolBasic::getInstance().getTable("t_tool_access")
                .insert("log_id", "ip_v4", "port_num", "request_body","response_body")
                .values(logID, ip, port, request, response)
                .execute();
        return res.getAffectedItemsCount();
    } catch (std::exception& e) {
        SPDLOG_ERROR("logID={} func={} err={}",logID,__FUNCTION__,e.what());
        return 0;
    }
}