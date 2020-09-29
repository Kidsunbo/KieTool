//
// Created by sunbo on 2020/8/21.
//

#include "tool_client.h"
#include "client.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>


using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

/**
 * bad practice, just for fun
 */
KieShop::tool_cellar::ToolCellarClient toolCellarClient(nullptr);
std::mutex toolCellarMutex;

static void init(){
    std::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
    std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    transport->open();
    toolCellarClient = KieShop::tool_cellar::ToolCellarClient(protocol);
}

static int _ = [](){
    registerClient(init);
    return 0;
}();

