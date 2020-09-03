//
// Created by sunbo on 2020/8/17.
//

#include "handler.h"
#include "../dto/value.h"
#include <memory>
#include <boost/uuid/detail/sha1.hpp>
#include <arpa/inet.h>
#include <spdlog/spdlog.h>
#include "../util/string_util.h"

#ifdef __linux__
#include <cstring>
#endif

using namespace KieShop::tool;
using namespace std;

/**
 * Get the hash32 value with sha1 algorithm
 * @param seed The value that being hashed
 * @return The hash value
 */
auto hash32(int64 seed){
#ifdef __linux__
    seed = htobe64(seed);
#elif __APPLE__
    seed=htonll(seed);
#endif
    boost::uuids::detail::sha1 sha1;
    char bytes[sizeof(seed)]={0};
    memcpy(bytes,&seed,sizeof(seed));
    sha1.process_bytes(bytes,sizeof(bytes));
    boost::uuids::detail::sha1::digest_type buf;
    sha1.get_digest(buf);
    unsigned int sum = 0;
    memcpy(&sum,buf,sizeof(sum));
    return sum;
}

/**
 * Parse the order id and return the pointer of sharding information
 * @param orderId The orderId
 * @return The information of sharding key
 */
auto parseOrderId(int64 orderId){
    auto o = make_unique<OrderId>();
    o->shard_key=static_cast<uint32>(static_cast<uint64>(orderId) & static_cast<uint64>(shardKeyMask));
    o->server_id=static_cast<uint32>(static_cast<uint64>(orderId) >> (shardKeyLen + 1) & static_cast<uint64>((1ull << serverIdLength) - 1));
    o->counter = static_cast<uint32>(static_cast<uint64>(orderId) >> (shardKeyLen + 1 + serverIdLength) & static_cast<uint64>((1ull << counterLength) - 1));
    o->timestamp=static_cast<uint32>(static_cast<uint64>(orderId) >> (shardKeyLen + 1 + serverIdLength + counterLength) & static_cast<uint64>((1ull << timestampLength) - 1));
    if((static_cast<uint64>(orderId) & idGeneratorMask) == idGeneratorMask){
        o->is_new=true;
    }else{
        o->is_new=false;
    }
    return o;
}

/**
 * Parse the shop id and return the pointer of sharding information
 * @param shopId The id of the shop
 * @return The sharding information
 */
auto parseShopId(int64 shopId){
    auto o = make_unique<OrderId>();
    auto sum=hash32(shopId);
    o->shard_key=sum%ShardingCountShopID;
    return o;
}


/**
 * Parse the user id and return the pointer of sharding information
 * @param userId The user id
 * @return The sharding information
 */
auto parseUserId(int64 userId){
    auto o=make_unique<OrderId>();
    auto sum=hash32(userId);
    o->shard_key=(sum&shardKeyMask)%ShardingCountShopID|64u;
    return o;
}


ShardingKeyResponse getShardingKey(const ShardingKeyRequest& sk){
    SPDLOG_INFO("logId={} func={} sk={}",sk.base.logId,__FUNCTION__ ,string_util::toString(sk));
    ShardingKeyResponse resp;
    try {
        //Order Id
        auto id = std::stoll(sk.id);
        auto o = parseOrderId(id);
        resp.orderId.shardingKey = o->shard_key;
        resp.orderId.counter=o->counter;
        resp.orderId.timestamp=o->timestamp;
        resp.orderId.serverId=o->server_id;
        resp.orderId.isNew=o->is_new;

        //TODO Shop Id
        o=parseShopId(id);
        resp.shopId.shardingKey=o->shard_key;
        //TODO User Id
        o=parseUserId(id);
        resp.userId.shardingKey=o->shard_key;

    } catch (std::exception& e) {
        SPDLOG_INFO("logId={} func={} err={}",sk.base.logId,__FUNCTION__ ,e.what());
        resp.baseResp.statusCode=base::StatusCode::Fail;
        resp.baseResp.statusMessage=e.what();
    }
    SPDLOG_INFO("logId={} func={} return successfully",sk.base.logId,__FUNCTION__);
    return resp;
}
