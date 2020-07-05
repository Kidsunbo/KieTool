//
// Created by sunbo on 2020/7/5.
//

#ifndef HANDLER_H
#define HANDLER_H

#include <thrift/server/TThreadPoolServer.h>

//Wait for C++20's module
namespace DB2ES {

    class RPC{
        using Server = apache::thrift::server::TThreadPoolServer;
        static std::shared_ptr<Server> server;
    public:
        static void init();
        static void run();
    };
}

#endif //HANDLER_H
