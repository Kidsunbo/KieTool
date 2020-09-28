//
// Created by sunbo on 2020/8/21.
//

#ifndef TOOLRECEPTION_TOOL_CLIENT_H
#define TOOLRECEPTION_TOOL_CLIENT_H



#include "../gen-cpp/ToolLogistic.h"
#include <mutex>

extern KieShop::tool::ToolLogisticClient toolLogisticClient;
extern std::mutex toolLogisticMutex;

#endif //TOOLRECEPTION_TOOL_CLIENT_H
