//
// Created by sunbo on 2020/8/21.
//

#include "handler.h"
#include "../client/tool_client.h"
#include <nlohmann/json.hpp>

namespace handler {

    void shardingKeyHandler(cinatra::request &req, cinatra::response &resp) {
        auto id = req.get_query_value("id");
        KieShop::tool::ShardingKeyResponse response;
        KieShop::tool::ShardingKeyRequest request;
        request.base.logId="test123";
        request.id=id;
        toolServiceClient.getShardingKey(response,request);
        if(response.baseResp.statusCode==base::StatusCode::Fail){
            resp.set_status_and_content(cinatra::status_type::ok,"something wrong, please contact Kie",cinatra::req_content_type::json);
            return;
        }
        nlohmann::json j;
        j["order_id_sharding_key"]=response.orderId.shardingKey;
        j["shop_id_sharding_key"]=response.shopId.shardingKey;
        j["user_id_sharding_key"]=response.userId.shardingKey;
        resp.set_status_and_content(cinatra::status_type::ok,j.dump(),cinatra::req_content_type::json);
    }


}