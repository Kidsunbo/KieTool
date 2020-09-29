//
// Created by sunbo on 2020/8/17.
//

#ifndef _KIE_SHOP_TOOL_LOGISTIC_HANDLER_H
#define _KIE_SHOP_TOOL_LOGISTIC_HANDLER_H

#include "../gen-cpp/tool_logistic_types.h"

/**
 * The handler function that calculates all the sharding key
 * @param request The request body of the rpc function
 * @return The sharding key information
 */
KieShop::tool_logistic::ShardingKeyResponse getShardingKey(const KieShop::tool_logistic::ShardingKeyRequest& request);

KieShop::tool_logistic::SnowFlakeResponse getSnowFlake(const KieShop::tool_logistic::SnowFlakeRequest& request);

#endif //_KIE_SHOP_TOOL_LOGISTIC_HANDLER_H
