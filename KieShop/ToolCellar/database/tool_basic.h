//
// Created by sunbo on 2020/9/29.
//

#ifndef KIESHOP_TOOL_CELLAR_TOOL_BASIC_H
#define KIESHOP_TOOL_CELLAR_TOOL_BASIC_H

#include <mysqlx/xdevapi.h>
#include <memory>
class ToolBasic {
    static std::shared_ptr<ToolBasic> inst;

    mysqlx::Session session; //reserve this session otherwise the connection will break.
    mysqlx::Schema db;

    ToolBasic(std::string ip, int port, std::string username, std::string password);

public:

    static mysqlx::Schema& getInstance();
};


#endif //KIESHOP_TOOL_CELLAR_TOOL_BASIC_H
