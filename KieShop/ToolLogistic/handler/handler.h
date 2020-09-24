//
// Created by sunbo on 2020/8/17.
//

#ifndef _TOOL_HANDLER_H
#define _TOOL_HANDLER_H

#include "../gen-cpp/tool_types.h"

/**
 * The handler function that calculates all the sharding key
 * @param request The request body of the rpc function
 * @return The sharding key information
 */
KieShop::tool::ShardingKeyResponse getShardingKey(const KieShop::tool::ShardingKeyRequest& request);

KieShop::tool::SnowFlakeResponse getSnowFlake(const KieShop::tool::SnowFlakeRequest& request);

#endif //_TOOL_HANDLER_H
