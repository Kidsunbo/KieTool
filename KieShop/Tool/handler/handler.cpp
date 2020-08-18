//
// Created by sunbo on 2020/8/17.
//

#include "handler.h"
#include "../dto/value.h"
#include <memory>
using namespace KieShop::tool;
using namespace std;

auto parseOrderId(int64 order_id)->unique_ptr<OrderId>{
    auto o = make_unique<OrderId>();
    o->shard_key=static_cast<uint32>(static_cast<uint64>(order_id) & static_cast<uint64>(shardKeyMask));
    o->server_id=static_cast<uint32>(static_cast<uint64>(order_id)>>(shardKeyLen+1) & static_cast<uint64>((1ull<<serverIdLength)-1));
    o->counter = static_cast<uint32>(static_cast<uint64>(order_id)>>(shardKeyLen+1+serverIdLength) & static_cast<uint64>((1ull<<counterLength)-1));
    o->timestamp=static_cast<uint32>(static_cast<uint64>(order_id)>>(shardKeyLen+1+serverIdLength+counterLength) & static_cast<uint64>((1ull<<timestampLength)-1));
    if((static_cast<uint64>(order_id)&idGeneratorMask)==idGeneratorMask){
        o->is_new=true;
    }else{
        o->is_new=false;
    }
    return o;
}

ShardingKeyResponse getShardingKey(const ShardingKeyRequest& sk){
    ShardingKeyResponse resp;
    try {
        //Order Id
        auto order_id = std::stoll(sk.id);
        auto o = parseOrderId(order_id);
        resp.orderId.shardingKey = o->shard_key;
        resp.orderId.counter=o->counter;
        resp.orderId.timestamp=o->timestamp;
        resp.orderId.serverId=o->server_id;
        resp.orderId.isNew=o->is_new;

        //TODO Shop Id

        //TODO User Id
    } catch (std::exception& e) {
        resp.baseResp.statusCode=base::StatusCode::Fail;
        resp.baseResp.statusMessage=e.what();
    }
    return resp;
}