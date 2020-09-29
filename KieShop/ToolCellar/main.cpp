#include <iostream>
#include "handler.h"
#include "defined/constant.h"
#include "database/tool_basic.h"

void runServer(){

    int port = 9090;
    shared_ptr<ToolCellarHandler> handler(new ToolCellarHandler());
    shared_ptr<TProcessor> processor(new ToolCellarProcessor(handler));
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());

    // using thread pool with maximum 15 threads to handle incoming requests
    shared_ptr<ThreadManager> threadManager
            = ThreadManager::newSimpleThreadManager(15);
    shared_ptr<ThreadFactory> threadFactory
            = shared_ptr<ThreadFactory>(new ThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();

    TThreadPoolServer server{processor,serverTransport,transportFactory,protocolFactory,threadManager};

    SPDLOG_INFO("'{}' rpc server starts",PSM);

    server.serve();

}

int main() {
    ToolBasic::getInstance(); //init database

    runServer();
    return 0;
}
