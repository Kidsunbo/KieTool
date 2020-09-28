namespace cpp KieShop.tool_logistic
namespace go KieShop.tool_logistic
namespace java KieShop.tool_logistic
namespace py KieShop.tool_logistic

include "../base.thrift"

/**********************Sharding Key********************/
struct ShardingKeyRequest{
  1: string id #The ID that to be parsed

  255: base.Base base
}

struct ShardingKeyItem{
  1: i32 shardingKey
  2: bool isNew
  3: i32 serverId
  4: i32 timestamp
  5: i32 counter
}

struct ShardingKeyResponse{
  1: ShardingKeyItem orderId
  2: ShardingKeyItem userId
  3: ShardingKeyItem shopId

  255: base.BaseResp baseResp
}
/**********************End Sharding Key*****************s*/

/**********************Snow Flake********************/
struct SnowFlakeRequest{

  255: base.Base base
}

struct SnowFlakeResponse{
  1: i64 id

  255: base.BaseResp baseResp
}
/**********************End Snow Flake********************/

service ToolLogistic{
   ShardingKeyResponse getShardingKey(1: ShardingKeyRequest req)
   SnowFlakeResponse getSnowFlake(1: SnowFlakeRequest req)
}