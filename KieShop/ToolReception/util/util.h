//
// Created by sunbo on 2020/8/26.
//

#ifndef TOOLRECEPTION_UTIL_H
#define TOOLRECEPTION_UTIL_H

#include <string>
#include "../gen-cpp/base_types.h"
#include "cinatra/http_server.hpp"
#include "../dto/wrapper.h"
#include <nlohmann/json.hpp>



namespace util {
    void wrapBase(base::Base& b);

    bool wrapError(dto::Serialization& s,nlohmann::json& j);

    std::string getClientIp(cinatra::request &req);
}

#endif //TOOLRECEPTION_UTIL_H
