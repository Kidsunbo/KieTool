//
// Created by sunbo on 2020/8/21.
//

#ifndef TOOLLOGISTIC_TOOL_CELLAR_CLIENT_H
#define TOOLLOGISTIC_TOOL_CELLAR_CLIENT_H



#include "../gen-cpp/ToolCellar.h"
#include <mutex>

extern KieShop::tool_cellar::ToolCellarClient toolCellarClient;
extern std::mutex toolCellarMutex;

#endif //TOOLLOGISTIC_TOOL_CELLAR_CLIENT_H
