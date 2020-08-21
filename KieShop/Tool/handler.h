//
// Created by sunbo on 2020/8/17.
//

#ifndef TOOL_HANDLER_H
#define TOOL_HANDLER_H


#include "gen-cpp/ToolService.h"
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


class ToolServiceHandler: public ToolServiceIf{
public:
    void getShardingKey(ShardingKeyResponse &_return, const ShardingKeyRequest &sk) override{
        _return = ::getShardingKey(sk);
        SPDLOG_INFO("logId={} func {}, request={}, response={}",sk.base.logId,__FUNCTION__,string_util::toString(sk),string_util::toString(_return));
    }

public:
};


#endif //TOOL_HANDLER_H
