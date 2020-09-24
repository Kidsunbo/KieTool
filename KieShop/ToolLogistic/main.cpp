#include <memory>
#include "handler.h"

#include "dto/value.h"


void runServer(){

    int port = 9090;
    shared_ptr<ToolServiceHandler> handler(new ToolServiceHandler());
    shared_ptr<TProcessor> processor(new ToolServiceProcessor(handler));
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

    SPDLOG_INFO("'{}' rpc server starts. DATA_CENTER_ID={}, MACHINE_ID={}",PSM,DataCenterID,MachineID);

    server.serve();

}

int main() {
    runServer();
}
