//
// Created by sunbo on 2020/9/29.
//

#ifndef KIESHOP_TOOL_CELLAR_LOG_REQUEST_H
#define KIESHOP_TOOL_CELLAR_LOG_REQUEST_H

#include <string>

int writeToTToolAccess(const std::string& logID,const std::string& ip,int port,const std::string& request,const std::string& response);

#endif //KIESHOP_TOOL_CELLAR_LOG_REQUEST_H
