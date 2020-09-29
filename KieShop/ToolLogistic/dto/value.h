//
// Created by sunbo on 2020/8/17.
//

#ifndef KIE_SHOP_TOOL_LOGISTIC_VALUE_H
#define KIE_SHOP_TOOL_LOGISTIC_VALUE_H
#include "../defined/constant.h"


struct OrderId{
    bool is_new;
    uint32 timestamp;
    uint32 counter;
    uint32 server_id;
    uint32 shard_key;
};

struct AsyncLog{
    std::string req;
    std::string resp;
    base::Base base;
};

#endif //KIE_SHOP_TOOL_LOGISTIC_VALUE_H
