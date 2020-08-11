//
// Created by sunbo on 2020/7/5.
//

#include "../gen-cpp/DB2ES.h"

#ifndef DB2ES_HANDLER_H
#define DB2ES_HANDLER_H

/**
 * Place the handler implementation here
 */
namespace Handler{

    DB2ES::Db2EsSyncResponse sync(const base::Context& ctx,const DB2ES::Db2EsSyncRequest& req);
    DB2ES::Db2EsInfoResponse info(const base::Context& ctx,const DB2ES::Db2EsInfoRequest& req);

}

#endif //DB2ES_HANDLER_H
