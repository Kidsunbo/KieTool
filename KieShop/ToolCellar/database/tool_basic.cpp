//
// Created by sunbo on 2020/9/29.
//

#include "tool_basic.h"

#include <utility>

std::shared_ptr<ToolBasic> ToolBasic::inst = nullptr;

mysqlx::Schema& ToolBasic::getInstance() {
    if(inst== nullptr){
        inst = std::shared_ptr<ToolBasic>(new ToolBasic("10.227.24.176", 33060, "root", "root"));
    }
    return inst->db;
}


ToolBasic::ToolBasic(std::string ip, int port, std::string username, std::string password):session(std::move(ip),port,std::move(username),std::move(password)),
db(session.getSchema("tool_basic")) {
}




