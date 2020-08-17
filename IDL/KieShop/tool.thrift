namespace cpp KieShop.tool
namespace go KieShop.tool
namespace java KieShop.tool
namespace py KieShop.tool

include "../base.thrift"

struct ShardingKeyRequest{
  1: string orderId
  2: optional bool isOrderId
  3: optional bool isShopId
  4: optional bool isUserId

  255: base.Base base
}

struct ShardingKeyResponse{
  1: i32 shardingKey
  2: bool isNew
  3: i32 serverId
  4: i32 timestamp
  5: i32 counter

  255: base.BaseResp baseResp
}