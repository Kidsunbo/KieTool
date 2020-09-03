//
// Created by sunbo on 2020/8/21.
//

#include "handler.h"
#include "../client/tool_client.h"
#include "../util/util.h"
#include <nlohmann/json.hpp>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include "../dto/wrapper.h"


namespace handler {
    void shardingKeyHandler(cinatra::request &req, cinatra::response &resp) {
        try {
            SPDLOG_INFO("request from ip={}", util::getClientIp(req));
            auto id = req.get_query_value("id");
            KieShop::tool::ShardingKeyResponse response;
            KieShop::tool::ShardingKeyRequest request;
            util::wrapBase(request.base);
            request.id = id;

            {
                std::lock_guard<std::mutex> lock(toolServiceMutex);
                toolServiceClient.getShardingKey(response, request);
            }
            if (response.baseResp.statusCode == base::StatusCode::Fail) {
                resp.set_status_and_content(cinatra::status_type::ok, "something wrong, please contact Kie",
                                            cinatra::req_content_type::json);
                return;
            }

            dto::ShardingKey sk;
            sk.orderId = id;
            sk.userIdSK = response.userId.shardingKey;
            sk.shopIdSK = response.shopId.shardingKey;
            sk.orderIdSK = response.orderId.shardingKey;
            resp.set_status_and_content(cinatra::status_type::ok, sk.to_json(), cinatra::req_content_type::json);
        } catch (std::exception& e) {
            nlohmann::json j;
            j["error"]=e.what();
            resp.set_status_and_content(cinatra::status_type::ok,j.dump(4),cinatra::req_content_type::json);
        }
    }


}