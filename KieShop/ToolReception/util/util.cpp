//
// Created by sunbo on 2020/8/26.
//

#include "util.h"
#include <chrono>
#include <spdlog/spdlog.h>
#include "../define/constant.h"





namespace util{


    inline std::string generateLogId(){
        return std::to_string(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    }

    inline std::string getIp(){
        return "";
    }

    inline auto getClientIPAndPort(cinatra::request &req){
        auto addr = req.get_conn<cinatra::NonSSL>()->remote_ip_port();
        return std::make_tuple(addr.first,addr.second);
    }

    void wrapBase(base::Base& b,cinatra::request& req){
        b.logId=generateLogId();
        b.caller= PSM;
        b.callerIp = getIp();
        auto[ip,port] = getClientIPAndPort(req);
        std::map<std::string,std::string> data;
        data["ip"] = ip;
        data["port"]=port;
        b.__set_data(data);
    }

    bool wrapError(dto::Serialization& s,nlohmann::json& j){
        j["error_number"] = s.errorNo;
        j["error_message"] = s.errorMsg;
        if(s.errorNo!=0){
            return false;
        }
        return true;
    }

    std::string getClientIp(cinatra::request &req){
        return req.get_conn<cinatra::NonSSL>()->remote_address();
    }


}