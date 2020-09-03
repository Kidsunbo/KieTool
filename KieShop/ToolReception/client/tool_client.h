//
// Created by sunbo on 2020/8/21.
//

#ifndef TOOLRECEPTION_TOOL_CLIENT_H
#define TOOLRECEPTION_TOOL_CLIENT_H



#include "../gen-cpp/ToolService.h"
#include <mutex>

extern KieShop::tool::ToolServiceClient toolServiceClient;
extern std::mutex toolServiceMutex;

#endif //TOOLRECEPTION_TOOL_CLIENT_H
