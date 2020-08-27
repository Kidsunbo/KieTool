//
// Created by sunbo on 2020/8/21.
//

#include "handler.h"
#include "../client/tool_client.h"
#include "../util/util.h"
#include <nlohmann/json.hpp>
#include <fmt/format.h>
#include <spdlog/spdlog.h>

namespace handler {

    void shardingKeyHandler(cinatra::request &req, cinatra::response &resp) {
        SPDLOG_INFO("request from ip={}",util::getClientIp(req));
        auto id = req.get_query_value("id");
        KieShop::tool::ShardingKeyResponse response;
        KieShop::tool::ShardingKeyRequest request;
        util::wrapBase(request.base);
        request.id=id;
        toolServiceClient.getShardingKey(response,request);
        if(response.baseResp.statusCode==base::StatusCode::Fail){
            resp.set_status_and_content(cinatra::status_type::ok,"something wrong, please contact Kie",cinatra::req_content_type::json);
            return;
        }

        //When I use C++23, there will be reflection which can help me do this elegantly
        nlohmann::json j;
        j["order_id_sharding_key"]=response.orderId.shardingKey;
        j["shop_id_sharding_key"]=response.shopId.shardingKey;
        j["user_id_sharding_key"]=response.userId.shardingKey;
        j["select_order_id"]=fmt::format("SELECT * FROM t_order_base WHERE order_id={} and sharding_key={} LIMIT 1;",id,response.orderId.shardingKey);
        resp.set_status_and_content(cinatra::status_type::ok,j.dump(),cinatra::req_content_type::json);
    }


}