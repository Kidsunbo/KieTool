//
// Created by sunbo on 2020/9/28.
//

#ifndef KIESHOP_TOOL_CELLAR_HANDLER_H
#define KIESHOP_TOOL_CELLAR_HANDLER_H

#include "gen-cpp/ToolCellar.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/ThreadManager.h>
#include <string_util.h>
#include <spdlog/spdlog.h>
#include "handler/handler.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;
using namespace std;
using namespace KieShop::tool_cellar;

class ToolCellarHandler: public ToolCellarIf{
public:

    void logRequest(RequestLoggingResponse &_return, const RequestLoggingRequest &req) override {
        _return = ::logRequest(req);
        SPDLOG_INFO("logId={} func={}, request={}, response={}",req.base.logId,__FUNCTION__,string_util::toString(req),string_util::toString(_return));

    }
};

#endif //KIESHOP_TOOL_CELLAR_HANDLER_H
