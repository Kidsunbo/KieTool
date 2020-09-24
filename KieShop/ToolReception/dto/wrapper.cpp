//
// Created by sunbo on 2020/8/28.
//

#include "wrapper.h"
#include <nlohmann/json.hpp>
#include <fmt/color.h>
#include "../util/util.h"

namespace dto{

    std::string ShardingKey::to_json() {
        //When I use C++23, there will be reflection which can help me do this elegantly, such as just to_json(response)

        nlohmann::json j;
        if(util::wrapError(*this,j)) {
            j["order_id_sharding_key"] = orderIdSK;
            j["shop_id_sharding_key"] = shopIdSK;
            j["user_id_sharding_key"] = userIdSK;
            j["select_order_id"] = fmt::format(
                    "SELECT * FROM t_order_base WHERE order_id={} AND sharding_key={} LIMIT 1;", orderId,
                    orderIdSK);
        }
        return j.dump(4);
    }


    std::string SnowFlake::to_json() {
        nlohmann::json j;
        if(util::wrapError(*this,j)){
            j["id"] = id;
        }
        return j.dump(4);
    }
}