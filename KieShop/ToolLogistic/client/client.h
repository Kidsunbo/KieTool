//
// Created by sunbo on 2020/8/21.
//

#ifndef TOOLLOGISTIC_CLIENT_H
#define TOOLLOGISTIC_CLIENT_H

#include <functional>

void initClient();

void registerClient(const std::function<void()>& function);


#endif //TOOLLOGISTIC_CLIENT_H
