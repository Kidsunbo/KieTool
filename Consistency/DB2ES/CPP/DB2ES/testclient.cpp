//
// Created by sunbo on 2020/7/5.
//

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TSocket.h>
#include "gen-cpp/DB2ES.h"

using namespace apache::thrift;
int main(){

    auto socket = std::make_shared<transport::TSocket>("localhost",12139);
    auto trans = std::make_shared<transport::TBufferedTransport>(socket);
    auto proto = std::make_shared<protocol::TBinaryProtocol>(trans);
    trans->open();
    DB2ES::DB2ESClient client(proto);
    DB2ES::Db2EsInfoResponse res;
    base::Context ctx;
    DB2ES::Db2EsInfoRequest req;
    client.info(res,ctx,req);

    return 0;
}