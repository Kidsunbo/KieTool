//
// Created by sunbo on 2020/8/21.
//

#ifndef TOOLRECEPTION_CLIENT_H
#define TOOLRECEPTION_CLIENT_H

#include <functional>

void initClient();

void registerClient(const std::function<void()>& function);


#endif //TOOLRECEPTION_CLIENT_H
