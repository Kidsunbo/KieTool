/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "tool_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace KieShop { namespace tool {


ShardingKeyRequest::~ShardingKeyRequest() noexcept {
}


void ShardingKeyRequest::__set_orderId(const std::string& val) {
  this->orderId = val;
}

void ShardingKeyRequest::__set_isOrderId(const bool val) {
  this->isOrderId = val;
__isset.isOrderId = true;
}

void ShardingKeyRequest::__set_isShopId(const bool val) {
  this->isShopId = val;
__isset.isShopId = true;
}

void ShardingKeyRequest::__set_isUserId(const bool val) {
  this->isUserId = val;
__isset.isUserId = true;
}

void ShardingKeyRequest::__set_base(const  ::base::Base& val) {
  this->base = val;
}
std::ostream& operator<<(std::ostream& out, const ShardingKeyRequest& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ShardingKeyRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->orderId);
          this->__isset.orderId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isOrderId);
          this->__isset.isOrderId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isShopId);
          this->__isset.isShopId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isUserId);
          this->__isset.isUserId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 255:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->base.read(iprot);
          this->__isset.base = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ShardingKeyRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ShardingKeyRequest");

  xfer += oprot->writeFieldBegin("orderId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->orderId);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.isOrderId) {
    xfer += oprot->writeFieldBegin("isOrderId", ::apache::thrift::protocol::T_BOOL, 2);
    xfer += oprot->writeBool(this->isOrderId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.isShopId) {
    xfer += oprot->writeFieldBegin("isShopId", ::apache::thrift::protocol::T_BOOL, 3);
    xfer += oprot->writeBool(this->isShopId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.isUserId) {
    xfer += oprot->writeFieldBegin("isUserId", ::apache::thrift::protocol::T_BOOL, 4);
    xfer += oprot->writeBool(this->isUserId);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("base", ::apache::thrift::protocol::T_STRUCT, 255);
  xfer += this->base.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ShardingKeyRequest &a, ShardingKeyRequest &b) {
  using ::std::swap;
  swap(a.orderId, b.orderId);
  swap(a.isOrderId, b.isOrderId);
  swap(a.isShopId, b.isShopId);
  swap(a.isUserId, b.isUserId);
  swap(a.base, b.base);
  swap(a.__isset, b.__isset);
}

ShardingKeyRequest::ShardingKeyRequest(const ShardingKeyRequest& other0) {
  orderId = other0.orderId;
  isOrderId = other0.isOrderId;
  isShopId = other0.isShopId;
  isUserId = other0.isUserId;
  base = other0.base;
  __isset = other0.__isset;
}
ShardingKeyRequest& ShardingKeyRequest::operator=(const ShardingKeyRequest& other1) {
  orderId = other1.orderId;
  isOrderId = other1.isOrderId;
  isShopId = other1.isShopId;
  isUserId = other1.isUserId;
  base = other1.base;
  __isset = other1.__isset;
  return *this;
}
void ShardingKeyRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ShardingKeyRequest(";
  out << "orderId=" << to_string(orderId);
  out << ", " << "isOrderId="; (__isset.isOrderId ? (out << to_string(isOrderId)) : (out << "<null>"));
  out << ", " << "isShopId="; (__isset.isShopId ? (out << to_string(isShopId)) : (out << "<null>"));
  out << ", " << "isUserId="; (__isset.isUserId ? (out << to_string(isUserId)) : (out << "<null>"));
  out << ", " << "base=" << to_string(base);
  out << ")";
}


ShardingKeyResponse::~ShardingKeyResponse() noexcept {
}


void ShardingKeyResponse::__set_shardingKey(const int32_t val) {
  this->shardingKey = val;
}

void ShardingKeyResponse::__set_isNew(const bool val) {
  this->isNew = val;
}

void ShardingKeyResponse::__set_serverId(const int32_t val) {
  this->serverId = val;
}

void ShardingKeyResponse::__set_timestamp(const int32_t val) {
  this->timestamp = val;
}

void ShardingKeyResponse::__set_counter(const int32_t val) {
  this->counter = val;
}

void ShardingKeyResponse::__set_baseResp(const  ::base::BaseResp& val) {
  this->baseResp = val;
}
std::ostream& operator<<(std::ostream& out, const ShardingKeyResponse& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ShardingKeyResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->shardingKey);
          this->__isset.shardingKey = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isNew);
          this->__isset.isNew = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->serverId);
          this->__isset.serverId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->timestamp);
          this->__isset.timestamp = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->counter);
          this->__isset.counter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 255:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->baseResp.read(iprot);
          this->__isset.baseResp = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ShardingKeyResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ShardingKeyResponse");

  xfer += oprot->writeFieldBegin("shardingKey", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->shardingKey);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("isNew", ::apache::thrift::protocol::T_BOOL, 2);
  xfer += oprot->writeBool(this->isNew);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("serverId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->serverId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("timestamp", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->timestamp);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("counter", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32(this->counter);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("baseResp", ::apache::thrift::protocol::T_STRUCT, 255);
  xfer += this->baseResp.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ShardingKeyResponse &a, ShardingKeyResponse &b) {
  using ::std::swap;
  swap(a.shardingKey, b.shardingKey);
  swap(a.isNew, b.isNew);
  swap(a.serverId, b.serverId);
  swap(a.timestamp, b.timestamp);
  swap(a.counter, b.counter);
  swap(a.baseResp, b.baseResp);
  swap(a.__isset, b.__isset);
}

ShardingKeyResponse::ShardingKeyResponse(const ShardingKeyResponse& other2) {
  shardingKey = other2.shardingKey;
  isNew = other2.isNew;
  serverId = other2.serverId;
  timestamp = other2.timestamp;
  counter = other2.counter;
  baseResp = other2.baseResp;
  __isset = other2.__isset;
}
ShardingKeyResponse& ShardingKeyResponse::operator=(const ShardingKeyResponse& other3) {
  shardingKey = other3.shardingKey;
  isNew = other3.isNew;
  serverId = other3.serverId;
  timestamp = other3.timestamp;
  counter = other3.counter;
  baseResp = other3.baseResp;
  __isset = other3.__isset;
  return *this;
}
void ShardingKeyResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ShardingKeyResponse(";
  out << "shardingKey=" << to_string(shardingKey);
  out << ", " << "isNew=" << to_string(isNew);
  out << ", " << "serverId=" << to_string(serverId);
  out << ", " << "timestamp=" << to_string(timestamp);
  out << ", " << "counter=" << to_string(counter);
  out << ", " << "baseResp=" << to_string(baseResp);
  out << ")";
}

}} // namespace
