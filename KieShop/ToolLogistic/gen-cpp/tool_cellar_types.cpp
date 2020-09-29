/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "tool_cellar_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace KieShop { namespace tool_cellar {


RequestLoggingRequest::~RequestLoggingRequest() noexcept {
}


void RequestLoggingRequest::__set_requestBody(const std::string& val) {
  this->requestBody = val;
}

void RequestLoggingRequest::__set_responseBody(const std::string& val) {
  this->responseBody = val;
}

void RequestLoggingRequest::__set_base(const  ::base::Base& val) {
  this->base = val;
}
std::ostream& operator<<(std::ostream& out, const RequestLoggingRequest& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t RequestLoggingRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->requestBody);
          this->__isset.requestBody = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->responseBody);
          this->__isset.responseBody = true;
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

uint32_t RequestLoggingRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("RequestLoggingRequest");

  xfer += oprot->writeFieldBegin("requestBody", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->requestBody);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("responseBody", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->responseBody);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("base", ::apache::thrift::protocol::T_STRUCT, 255);
  xfer += this->base.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(RequestLoggingRequest &a, RequestLoggingRequest &b) {
  using ::std::swap;
  swap(a.requestBody, b.requestBody);
  swap(a.responseBody, b.responseBody);
  swap(a.base, b.base);
  swap(a.__isset, b.__isset);
}

RequestLoggingRequest::RequestLoggingRequest(const RequestLoggingRequest& other0) {
  requestBody = other0.requestBody;
  responseBody = other0.responseBody;
  base = other0.base;
  __isset = other0.__isset;
}
RequestLoggingRequest& RequestLoggingRequest::operator=(const RequestLoggingRequest& other1) {
  requestBody = other1.requestBody;
  responseBody = other1.responseBody;
  base = other1.base;
  __isset = other1.__isset;
  return *this;
}
void RequestLoggingRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "RequestLoggingRequest(";
  out << "requestBody=" << to_string(requestBody);
  out << ", " << "responseBody=" << to_string(responseBody);
  out << ", " << "base=" << to_string(base);
  out << ")";
}


RequestLoggingResponse::~RequestLoggingResponse() noexcept {
}


void RequestLoggingResponse::__set_baseResp(const  ::base::BaseResp& val) {
  this->baseResp = val;
}
std::ostream& operator<<(std::ostream& out, const RequestLoggingResponse& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t RequestLoggingResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t RequestLoggingResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("RequestLoggingResponse");

  xfer += oprot->writeFieldBegin("baseResp", ::apache::thrift::protocol::T_STRUCT, 255);
  xfer += this->baseResp.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(RequestLoggingResponse &a, RequestLoggingResponse &b) {
  using ::std::swap;
  swap(a.baseResp, b.baseResp);
  swap(a.__isset, b.__isset);
}

RequestLoggingResponse::RequestLoggingResponse(const RequestLoggingResponse& other2) {
  baseResp = other2.baseResp;
  __isset = other2.__isset;
}
RequestLoggingResponse& RequestLoggingResponse::operator=(const RequestLoggingResponse& other3) {
  baseResp = other3.baseResp;
  __isset = other3.__isset;
  return *this;
}
void RequestLoggingResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "RequestLoggingResponse(";
  out << "baseResp=" << to_string(baseResp);
  out << ")";
}

}} // namespace