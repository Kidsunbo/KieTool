//
// Created by sunbo on 2020/8/17.
//

#ifndef TOOL_HANDLER_H
#define TOOL_HANDLER_H


#include "gen-cpp/ToolLogistic.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/ThreadManager.h>
#include <spdlog/spdlog.h>
#include "handler/handler.h"
#include "util/string_util.h"


using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;
using namespace std;
using namespace KieShop::tool;

class ToolLogisticHandler: public ToolLogisticIf{
public:
    void getShardingKey(ShardingKeyResponse &_return, const ShardingKeyRequest &req) override{
        _return = ::getShardingKey(req);
        SPDLOG_INFO("logId={} func={}, request={}, response={}",req.base.logId,__FUNCTION__,string_util::toString(req),string_util::toString(_return));
    }

    void getSnowFlake(SnowFlakeResponse &_return, const SnowFlakeRequest &req) override {
        _return = ::getSnowFlake(req);
        SPDLOG_INFO("logId={} func={}, request={}, response={}",req.base.logId,__FUNCTION__,string_util::toString(req),string_util::toString(_return));
    }
};


#endif //TOOL_HANDLER_H
