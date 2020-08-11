//
// Created by sunbo on 2020/7/5.
//
#include "gen-cpp/DB2ES.h"
#include "handler.h"
#include "handler/handler.h"

#include <thrift/server/TThreadPoolServer.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/ThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TServerSocket.h>

namespace proto = apache::thrift::protocol;
namespace trans = apache::thrift::transport;
namespace concur = apache::thrift::concurrency;
namespace server = apache::thrift::server;


namespace DB2ES {
    std::shared_ptr<RPC::Server> RPC::server = nullptr;
    class DB2ESHandler;
}

void DB2ES::RPC::init() {
    auto handler = std::make_shared<DB2ESHandler>();
    auto processor = std::make_shared<DB2ESProcessor>(handler);
    auto socket = std::make_shared<trans::TServerSocket>(12139);
    auto protocol = std::make_shared<proto::TBinaryProtocolFactory>();
    auto transport = std::make_shared<trans::TBufferedTransportFactory>();

    auto tm = concur::ThreadManager::newSimpleThreadManager(4);
    auto tf = std::make_shared<concur::ThreadFactory>();
    tm->threadFactory(tf);
    tm->start();

    server = std::make_shared<server::TThreadPoolServer>(processor,socket,transport,protocol,tm);

}

void DB2ES::RPC::run() {
    if(server==nullptr){
        throw std::logic_error("No initialization of rpc");
    }
    server->run();
}

namespace DB2ES {

    /**
     * Handler class which accept all the request
     * The main logic is in the handler directory
     */
    class DB2ESHandler : public DB2ESIf {
    public:
        void sync(Db2EsSyncResponse &_return, const base::Context &ctx, const Db2EsSyncRequest &request) override {
            _return = Handler::sync(ctx,request);

        }

        void info(Db2EsInfoResponse &_return, const base::Context &ctx, const Db2EsInfoRequest &request) override {
            _return = Handler::info(ctx,request);

        }

    };
}





