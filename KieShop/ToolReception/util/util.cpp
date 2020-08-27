//
// Created by sunbo on 2020/8/26.
//

#include "util.h"
#include <chrono>
#include <spdlog/spdlog.h>


#define PSM "kie.shop.tool_reception"



namespace util{


    inline std::string generateLogId(){
        return std::to_string(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    }

    inline std::string getIp(){
        return "";
    }

    void wrapBase(base::Base& b){
        b.logId=generateLogId();
        b.caller= PSM;
        b.callerIp = getIp();
    }

    std::string getClientIp(cinatra::request &req){
        return req.get_conn<cinatra::NonSSL>()->remote_address();
    }
}